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

#ifndef SRCDIR
#define SRCDIR_S ".."
#else
#define STRINGIFY_MACRO2(x) #x
#define STRINGIFY_MACRO(x)  STRINGIFY_MACRO2(x)
#define SRCDIR_S    STRINGIFY_MACRO(SRCDIR)
#endif

static unsigned char buf[4096];
static int buf_offset;

static int
_buf_writer(const void *buffer, size_t size, void *app_key) {
	(void)app_key;
	assert(buf_offset + size < sizeof(buf));
	memcpy(buf + buf_offset, buffer, size);
#ifdef ASN_EMIT_DEBUG
	unsigned char *b, *bend;
	b = buf + buf_offset;
	bend = b + size;
	fprintf(stderr, "=> [");
	for(; b < bend; b++) {
		if(*b >= 32 && *b < 127 && *b != '%')
			fprintf(stderr, "%c", *b);
		else
			fprintf(stderr, "%%%02x", *b);
	}
	fprintf(stderr, "]:%zd\n", size);
#endif
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
		rval = uper_encode(&asn_DEF_PDU, 0, st, _buf_writer, 0);
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
    default:
        assert(!"Unreachable");
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
load_object_from(const char *fname, unsigned char *fbuf, size_t size, enum enctype how, int mustfail) {
	asn_dec_rval_t rval;
	PDU_t *st = 0;
	ssize_t csize = 1;

	if(getenv("INITIAL_CHUNK_SIZE"))
		csize = atoi(getenv("INITIAL_CHUNK_SIZE"));

	/* Perform multiple iterations with multiple chunks sizes */
	for(; csize < 20; csize += 1) {
		int fbuf_offset = 0;
		int fbuf_left = size;
		int fbuf_chunk = csize;

		fprintf(stderr, "LOADING OBJECT OF SIZE %zd FROM [%s] as %s,"
			" chunks %zd\n",
			size, fname, how==AS_PER?"PER":"XER", csize);

		if(st) ASN_STRUCT_FREE(asn_DEF_PDU, st);
		st = 0;

		do {
			ASN_DEBUG("\nDecoding bytes %d..%d (left %d) [%s]",
				fbuf_offset,
					fbuf_chunk < fbuf_left
						? fbuf_chunk : fbuf_left,
					fbuf_left,
				fname);
#ifdef  ASN_EMIT_DEBUG
			if(st) {
				fprintf(stderr, "=== currently ===\n");
				asn_fprint(stderr, &asn_DEF_PDU, st);
				fprintf(stderr, "=== end ===\n");
			}
#endif
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
						fprintf(stderr, "-> PER decode error (%zd bits of %zd bytes (c=%d,l=%d)) \n", rval.consumed, size, fbuf_chunk, fbuf_left);
						rval.code = RC_FAIL;
						rval.consumed += 7;
						rval.consumed /= 8;
						if(mustfail) {
							fprintf(stderr, "-> (this was expected failure)\n");
							ASN_STRUCT_FREE(asn_DEF_PDU, st);
							return 0;
						}
					} else {
						rval.consumed = 0; /* Not restartable */
						ASN_STRUCT_FREE(asn_DEF_PDU, st);
						st = 0;
						ASN_DEBUG("-> PER wants more");
					}
				} else {
					ASN_DEBUG("-> PER ret %d/%zd mf=%d",
						rval.code, rval.consumed, mustfail);
					/* uper_decode() returns _bits_ */
					rval.consumed += 7;
					rval.consumed /= 8;
					if((mustfail?1:0) == (rval.code == RC_FAIL)) {
						if(mustfail) {
							fprintf(stderr, "-> (this was expected failure)\n");
							ASN_STRUCT_FREE(asn_DEF_PDU, st);
							return 0;
						}
					} else {
						fprintf(stderr, "-> (unexpected %s)\n", mustfail ? "success" : "failure");
						rval.code = RC_FAIL;
					}
				}
				break;
            default:
                assert(!"Unreachable");
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
			fprintf(stderr, "[left %d, off %d, size %zd]\n",
				fbuf_left, fbuf_offset, size);
			assert(fbuf_offset == (ssize_t)size);
		} else {
			assert((fbuf_offset + 1 /* "\n" */  == (ssize_t)size
				&& fbuf[size - 1] == '\n')
			|| (fbuf_offset + 2 /* "\r\n" */  == (ssize_t)size
				&& fbuf[size - 2] == '\r'
				&& fbuf[size - 1] == '\n')
			);
		}
	}

	if(st) asn_fprint(stderr, &asn_DEF_PDU, st);
	return st;
}

static int
xer_encoding_equal(void *obufp, size_t osize, void *nbufp, size_t nsize) {
    char *obuf = obufp;
    char *nbuf = nbufp;
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
compare_with_data_out(const char *fname, void *datap, size_t size) {
    char *data = datap;
	char outName[sizeof(SRCDIR_S) + 256];
	unsigned char fbuf[1024];
	size_t rd;
	FILE *f;
	char lastChar;
	int mustfail, compare;
	PDU_t *st;

	sprintf(outName, SRCDIR_S "/data-126/%s", fname);
	strcpy(outName + strlen(outName) - 3, ".out");

	fprintf(stderr, "Comparing PER output with [%s]\n", outName);

	lastChar = outName[strlen(outName)-5];
	mustfail = lastChar == 'P';
	compare = lastChar != 'C';

	if((compare && !mustfail) && getenv("REGENERATE")) {
		f = fopen(outName, "w");
		fwrite(data, 1, size, f);
		fclose(f);
	} else {
		f = fopen(outName, "r");
		assert(f);
		rd = fread(fbuf, 1, sizeof(fbuf), f);
		assert(rd);
		fclose(f);

		fprintf(stderr, "Trying to decode [%s]\n", outName);
		st = load_object_from(outName, fbuf, rd, AS_PER, mustfail);
		ASN_STRUCT_FREE(asn_DEF_PDU, st);
		if(mustfail) return;

		if(compare) {
			assert(rd == (size_t)size);
			assert(memcmp(fbuf, data, rd) == 0);
			fprintf(stderr, "XER->PER recoding .in->.out match.\n");
		} else {
			assert(rd != (size_t)size || memcmp(fbuf, data, rd));
			fprintf(stderr, "XER->PER recoding .in->.out diverge.\n");
		}
	}
}

static void
process_XER_data(const char *fname, unsigned char *fbuf, size_t size) {
	PDU_t *st;

	st = load_object_from(fname, fbuf, size, AS_XER, 0);
	if(!st) return;

	/* Save and re-load as PER */
	save_object_as(st, AS_PER);
	ASN_STRUCT_FREE(asn_DEF_PDU, st);
	compare_with_data_out(fname, buf, buf_offset);
	st = load_object_from("buffer", buf, buf_offset, AS_PER, 0);
	assert(st);

	save_object_as(st, AS_XER);
	fprintf(stderr, "=== original ===\n");
	fwrite(fbuf, 1, size, stderr);
	fprintf(stderr, "=== re-encoded ===\n");
	fwrite(buf, 1, buf_offset, stderr);
	fprintf(stderr, "=== end ===\n");

	if(fname[strlen(fname) - 4] == 'X')
		assert(!xer_encoding_equal((char *)fbuf, size, (char *)buf, buf_offset));
	else
		assert(xer_encoding_equal((char *)fbuf, size, (char *)buf, buf_offset));

	ASN_STRUCT_FREE(asn_DEF_PDU, st);
}

/*
 * Decode the .der files and try to regenerate them.
 */
static int
process(const char *fname) {
	unsigned char fbuf[sizeof(SRCDIR_S) + 4096];
	char *ext = strrchr(fname, '.');
	int rd;
	FILE *fp;

	if(ext == 0 || strcmp(ext, ".in"))
		return 0;

	fprintf(stderr, "\nProcessing file [../%s]\n", fname);

	snprintf((char *)fbuf, sizeof(fbuf), SRCDIR_S "/data-126/%s", fname);
	fp = fopen((char *)fbuf, "r");
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

	dir = opendir(SRCDIR_S "/data-126");
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

