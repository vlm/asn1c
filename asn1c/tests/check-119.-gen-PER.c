/*
 * Mode of operation:
 * Each of the *.in files is XER-decoded, then converted into PER,
 * then decoded back from PER, then encoded into XER again,
 * and finally compared to the original encoding.
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

enum expectation {
	EXP_OK,		/* Encoding/decoding must succeed */
	EXP_CXER_EXACT,	/* Encoding/decoding using CXER must be exact */
	EXP_CXER_DIFF,	/* Encoding/decoding using CXER must be different */
	EXP_BROKEN,	/* Decoding must fail */
	EXP_DIFFERENT,	/* Reconstruction will yield different encoding */
	EXP_PER_NOCOMP,	/* Not PER compatible */
};

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
	AS_CXER,
};

static void
save_object_as(PDU_t *st, enum expectation exp, enum enctype how) {
	asn_enc_rval_t rval; /* Return value */

	buf_offset = 0;

	/*
	 * Save object using specified method.
	 */
	switch(how) {
	case AS_PER:
		rval = uper_encode(&asn_DEF_PDU, st,
			_buf_writer, 0);
		if(exp == EXP_PER_NOCOMP)
			assert(rval.encoded == -1);
		else
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
	case AS_CXER:
		rval = xer_encode(&asn_DEF_PDU, st, XER_F_CANONICAL,
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
load_object_from(const char *fname, enum expectation expectation, char *fbuf, int size, enum enctype how) {
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
			fprintf(stderr, "Decoding bytes %d..%d (left %d)\n",
				fbuf_offset,
					fbuf_chunk < fbuf_left
						? fbuf_chunk : fbuf_left,
					fbuf_left);
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
			case AS_PER:
				rval = uper_decode(0, &asn_DEF_PDU,
					(void **)&st, fbuf + fbuf_offset,
					fbuf_chunk < fbuf_left 
					? fbuf_chunk : fbuf_left, 0, 0);
				if(rval.code == RC_WMORE) {
					rval.consumed = 0; /* Not restartable */
					ASN_STRUCT_FREE(asn_DEF_PDU, st);
					st = 0;
					fprintf(stderr, "-> PER wants more\n");
				} else {
					/* unsigned long long works for size_t in most cases;
					   more portable than %zu (gcc) or %Iu (msvc) */
					fprintf(stderr, "-> PER ret %d/%llu\n",
						rval.code, (unsigned long long)rval.consumed);
					/* uper_decode() returns _bits_ */
					rval.consumed += 7;
					rval.consumed /= 8;
				}
				break;
			case AS_DER:
			case AS_CXER:
				break; /* intentionally not handled */
			}
			fbuf_offset += rval.consumed;
			fbuf_left -= rval.consumed;
			if(rval.code == RC_WMORE)
				fbuf_chunk += 1;	/* Give little more */
			else
				fbuf_chunk = csize;	/* Back off */
		} while(fbuf_left && rval.code == RC_WMORE);

		if(expectation != EXP_BROKEN) {
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
		} else {
			assert(rval.code != RC_OK);
			fprintf(stderr, "Failed, but this was expected\n");
			asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
			st = 0;	/* ignore leak for now */
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
process_XER_data(const char *fname, enum expectation expectation, char *fbuf, int size) {
	PDU_t *st;

	st = load_object_from(fname, expectation, fbuf, size, AS_XER);
	if(!st) return;

	/* Save and re-load as PER */
	save_object_as(st, expectation, AS_PER);
	if(expectation == EXP_PER_NOCOMP)
		return;	/* Already checked */
	st = load_object_from("buffer", expectation, (char*)buf, buf_offset, AS_PER);
	assert(st);

	save_object_as(st,
			expectation,
			(expectation == EXP_CXER_EXACT
			|| expectation == EXP_CXER_DIFF)
			? AS_CXER : AS_XER);
	fprintf(stderr, "=== original ===\n");
	fwrite(fbuf, 1, size, stderr);
	fprintf(stderr, "=== re-encoded ===\n");
	fwrite(buf, 1, buf_offset, stderr);
	fprintf(stderr, "=== end ===\n");

	switch(expectation) {
	case EXP_DIFFERENT:
		assert(!xer_encoding_equal(fbuf, size, (char*)buf, buf_offset));
		break;
	case EXP_BROKEN:
		assert(!xer_encoding_equal(fbuf, size, (char*)buf, buf_offset));
		break;
	case EXP_CXER_EXACT:
		buf[buf_offset++] = '\n';
		assert(size == buf_offset);
		assert(memcmp(fbuf, buf, size) == 0);
		break;
	case EXP_CXER_DIFF:
		buf[buf_offset++] = '\n';
		assert(size != buf_offset
			|| memcmp(fbuf, buf, size));
		break;
	case EXP_OK:
	case EXP_PER_NOCOMP:
		assert(xer_encoding_equal(fbuf, size, (char*)buf, buf_offset));
		break;
	}

	asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
}

/*
 * Decode the .der files and try to regenerate them.
 */
static int
process(const char *fname) {
	char fbuf[4096];
	char *ext = strrchr(fname, '.');
	enum expectation expectation;
	int rd;
	FILE *fp;

	if(ext == 0 || strcmp(ext, ".in"))
		return 0;

	switch(ext[-1]) {
	case 'B':	/* The file is intentionally broken */
		expectation = EXP_BROKEN; break;
	case 'D':	/* Reconstructing should yield different data */
		expectation = EXP_DIFFERENT; break;
	case 'E':	/* Byte to byte exact reconstruction */
		expectation = EXP_CXER_EXACT; break;
	case 'X':	/* Should fail byte-to-byte comparison */
		expectation = EXP_CXER_DIFF; break;
	case 'P':	/* Incompatible with PER */
		expectation = EXP_PER_NOCOMP; break;
	default:
		expectation = EXP_OK; break;
	}

	fprintf(stderr, "\nProcessing file [../%s]\n", fname);

	snprintf(fbuf, sizeof(fbuf), "../data-119/%s", fname);
	fp = fopen(fbuf, "r");
	assert(fp);

	rd = fread(fbuf, 1, sizeof(fbuf), fp);
	fclose(fp);

	assert(rd < sizeof(fbuf));	/* expect small files */

	process_XER_data(fname, expectation, fbuf, rd);

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
	str = getenv("DATA_119_FILE");
	if(str && strncmp(str, "data-119-", 9) == 0) {
		process(str);
		return 0;
	}

	dir = opendir("../data-119");
	assert(dir);

	/*
	 * Process each file in that directory.
	 */
	while((dent = readdir(dir))) {
		if(strncmp(dent->d_name, "data-119-", 9) == 0)
			if(process(dent->d_name))
				processed_files++;
	}

	assert(processed_files);
	closedir(dir);

	return 0;
}

