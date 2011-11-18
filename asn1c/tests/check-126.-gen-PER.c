/*
 * Mode of operation:
 * Each of the *.in files is XER-decoded, then converted into PER,
 * compared with *.out file, then decoded and compared with the original.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>	/* for chdir(2) */
#include <string.h>
#include <dirent.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <PDU.h>

static unsigned char buf[4096];
static int buf_offset;

static int
_buf_writer(const void *buffer, size_t size, void *app_key) {
	unsigned char *b, *bend;
	(void)app_key;
	assert(buf_offset + size < sizeof(buf));
	memcpy(buf + buf_offset, buffer, size);
	b = buf + buf_offset;
	bend = b + size;
	fprintf(stderr, "=> [");
	for(; b < bend; b++) {
		if(*b >= 32 && *b < 127 && *b != '%')
			fprintf(stderr, "%c", *b);
		else
			fprintf(stderr, "%%%02x", *b);
	}
	fprintf(stderr, "]:%ld\n", (long)size);
	buf_offset += size;
	return 0;
}

enum enctype {
	AS_PER,
	AS_DER,
	AS_XER,
};

static void
save_object_as(PDU_t *st, enum enctype how) {
	asn_enc_rval_t rval; /* Return value */

	buf_offset = 0;

	/*
	 * Save object using specified method.
	 */
	switch(how) {
	case AS_PER:
		rval = uper_encode(&asn_DEF_PDU, st, _buf_writer, 0);
		assert(rval.encoded > 0);
		fprintf(stderr, "SAVED OBJECT IN SIZE %d\n", buf_offset);
		return;
	case AS_DER:
		rval = der_encode(&asn_DEF_PDU, st,
			_buf_writer, 0);
		break;
	case AS_XER:
		rval = xer_encode(&asn_DEF_PDU, st, XER_F_BASIC,
			_buf_writer, 0);
		break;
	}

	if (rval.encoded == -1) {
		fprintf(stderr,
			"Cannot encode %s: %s\n",
			rval.failed_type->name, strerror(errno));
		assert(rval.encoded != -1);
		return;
	}

	fprintf(stderr, "SAVED OBJECT IN SIZE %d\n", buf_offset);
}

static PDU_t *
load_object_from(const char *fname, char *fbuf, int size, enum enctype how, int mustfail) {
	asn_dec_rval_t rval = { RC_OK, 0 };
	PDU_t *st = 0;
	int csize = 1;

	if(getenv("INITIAL_CHUNK_SIZE"))
		csize = atoi(getenv("INITIAL_CHUNK_SIZE"));

	/* Perform multiple iterations with multiple chunks sizes */
	for(; csize < 20; csize += 1) {
		int fbuf_offset = 0;
		int fbuf_left = size;
		int fbuf_chunk = csize;

		fprintf(stderr, "LOADING OBJECT OF SIZE %d FROM [%s] as %s,"
			" chunks %d\n",
			size, fname, how==AS_PER?"PER":"XER", csize);

		if(st) asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
		st = 0;

		do {
			fprintf(stderr, "\nDecoding bytes %d..%d (left %d) [%s]\n",
				fbuf_offset,
					fbuf_chunk < fbuf_left
						? fbuf_chunk : fbuf_left,
					fbuf_left,
				fname);
			if(st) {
				fprintf(stderr, "=== currently ===\n");
				asn_fprint(stderr, &asn_DEF_PDU, st);
				fprintf(stderr, "=== end ===\n");
			}
			switch(how) {
			case AS_XER:
				rval = xer_decode(0, &asn_DEF_PDU, (void **)&st,
					fbuf + fbuf_offset,
					fbuf_chunk < fbuf_left 
					? fbuf_chunk : fbuf_left);
				break;
			case AS_DER:
				assert(0);
				break;
			case AS_PER:
				rval = uper_decode(0, &asn_DEF_PDU,
					(void **)&st, fbuf + fbuf_offset,
					fbuf_chunk < fbuf_left 
					? fbuf_chunk : fbuf_left, 0, 0);
				if(rval.code == RC_WMORE) {
					if(fbuf_chunk == fbuf_left) {
						fprintf(stderr, "-> PER decode error (%llu bits of %d bytes (c=%d,l=%d)) \n", (unsigned long long)rval.consumed, size, fbuf_chunk, fbuf_left);
						rval.code = RC_FAIL;
						rval.consumed += 7;
						rval.consumed /= 8;
						if(mustfail) {
							fprintf(stderr, "-> (this was expected failure)\n");
							return 0;
						}
					} else {
						rval.consumed = 0; /* Not restartable */
						ASN_STRUCT_FREE(asn_DEF_PDU, st);
						st = 0;
						fprintf(stderr, "-> PER wants more\n");
					}
				} else {
					fprintf(stderr, "-> PER ret %d/%llu mf=%d\n",
						rval.code, (unsigned long long)rval.consumed, mustfail);
					/* uper_decode() returns _bits_ */
					rval.consumed += 7;
					rval.consumed /= 8;
					if((mustfail?1:0) == (rval.code == RC_FAIL)) {
						if(mustfail) {
							fprintf(stderr, "-> (this was expected failure)\n");
							return 0;
						}
					} else {
						fprintf(stderr, "-> (unexpected %s)\n", mustfail ? "success" : "failure");
						rval.code = RC_FAIL;
					}
				}
				break;
			}
			fbuf_offset += rval.consumed;
			fbuf_left -= rval.consumed;
			if(rval.code == RC_WMORE)
				fbuf_chunk += 1;	/* Give little more */
			else
				fbuf_chunk = csize;	/* Back off */
		} while(fbuf_left && rval.code == RC_WMORE);

		assert(rval.code == RC_OK);
		if(how == AS_PER) {
			fprintf(stderr, "[left %d, off %d, size %d]\n",
				fbuf_left, fbuf_offset, size);
			assert(fbuf_offset == size);
		} else {
			assert(fbuf_offset - size < 2
			|| (fbuf_offset + 1 /* "\n" */  == size
				&& fbuf[size - 1] == '\n')
			|| (fbuf_offset + 2 /* "\r\n" */  == size
				&& fbuf[size - 2] == '\r'
				&& fbuf[size - 1] == '\n')
			);
		}
	}

	if(st) asn_fprint(stderr, &asn_DEF_PDU, st);
	return st;
}

static int
xer_encoding_equal(char *obuf, size_t osize, char *nbuf, size_t nsize) {
	char *oend = obuf + osize;
	char *nend = nbuf + nsize;

	if((osize && !nsize) || (!osize && nsize))
		return 0;	/* not equal apriori */

	while(1) {
		while(obuf < oend && isspace(*obuf)) obuf++;
		while(nbuf < nend && isspace(*nbuf)) nbuf++;

		if(obuf == oend || nbuf == nend) {
			if(obuf == oend && nbuf == nend)
				break;
			fprintf(stderr, "%s data in reconstructed encoding\n",
				(obuf == oend) ? "More" : "Less");
			return 0;
		}

		if(*obuf != *nbuf) {
			printf("%c%c != %c%c\n",
				obuf[0], obuf[1],
				nbuf[0], nbuf[1]);
			return 0;
		}
		obuf++, nbuf++;
	}

	return 1;
}

static void
compare_with_data_out(const char *fname, char *mybuf, int size) {
	char outName[256];
	char fbuf[1024];
	size_t rd;
	FILE *f;
	char lastChar;
	int mustfail, compare;

	sprintf(outName, "../data-126/%s", fname);
	strcpy(outName + strlen(outName) - 3, ".out");

	fprintf(stderr, "Comparing PER output with [%s]\n", outName);

	lastChar = outName[strlen(outName)-5];
	mustfail = lastChar == 'P';
	compare = lastChar != 'C';

	if((compare && !mustfail) && getenv("REGENERATE")) {
		f = fopen(outName, "w");
		fwrite(mybuf, 1, size, f);
		fclose(f);
	} else {
		f = fopen(outName, "r");
		assert(f);
		rd = fread(fbuf, 1, sizeof(fbuf), f);
		assert(rd);
		fclose(f);

		fprintf(stderr, "Trying to decode [%s]\n", outName);
		load_object_from(outName, fbuf, rd, AS_PER, mustfail);
		if(mustfail) return;

		if(compare) {
			assert(rd == (size_t)size);
			assert(memcmp(fbuf, mybuf, rd) == 0);
			fprintf(stderr, "XER->PER recoding .in->.out match.\n");
		} else {
			assert(rd != (size_t)size || memcmp(fbuf, mybuf, rd));
			fprintf(stderr, "XER->PER recoding .in->.out diverge.\n");
		}
	}
}

static void
process_XER_data(const char *fname, char *fbuf, int size) {
	PDU_t *st;

	st = load_object_from(fname, fbuf, size, AS_XER, 0);
	if(!st) return;

	/* Save and re-load as PER */
	save_object_as(st, AS_PER);
	compare_with_data_out(fname, (char*)buf, buf_offset);
	st = load_object_from("buffer", (char*)buf, buf_offset, AS_PER, 0);
	assert(st);

	save_object_as(st, AS_XER);
	fprintf(stderr, "=== original ===\n");
	fwrite(fbuf, 1, size, stderr);
	fprintf(stderr, "=== re-encoded ===\n");
	fwrite(buf, 1, buf_offset, stderr);
	fprintf(stderr, "=== end ===\n");

	if(fname[strlen(fname) - 4] == 'X')
		assert(!xer_encoding_equal(fbuf, size, (char*)buf, buf_offset));
	else
		assert(xer_encoding_equal(fbuf, size, (char*)buf, buf_offset));

	asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
}

/*
 * Decode the .der files and try to regenerate them.
 */
static int
process(const char *fname) {
	char fbuf[4096];
	char *ext = strrchr(fname, '.');
	int rd;
	FILE *fp;

	if(ext == 0 || strcmp(ext, ".in"))
		return 0;

	fprintf(stderr, "\nProcessing file [../%s]\n", fname);

	snprintf(fbuf, sizeof(fbuf), "../data-126/%s", fname);
	fp = fopen(fbuf, "r");
	assert(fp);

	rd = fread(fbuf, 1, sizeof(fbuf), fp);
	fclose(fp);

	assert((size_t)rd < sizeof(fbuf));	/* expect small files */

	process_XER_data(fname, fbuf, rd);

	fprintf(stderr, "Finished [%s]\n", fname);

	return 1;
}

int
main() {
	DIR *dir;
	struct dirent *dent;
	int processed_files = 0;
	char *str;

	/* Process a specific test file */
	str = getenv("DATA_126_FILE");
	if(str && strncmp(str, "data-126-", 9) == 0) {
		process(str);
		return 0;
	}

	dir = opendir("../data-126");
	assert(dir);

	/*
	 * Process each file in that directory.
	 */
	while((dent = readdir(dir))) {
		if(strncmp(dent->d_name, "data-126-", 9) == 0)
			if(process(dent->d_name))
				processed_files++;
	}

	assert(processed_files);
	closedir(dir);

	return 0;
}

