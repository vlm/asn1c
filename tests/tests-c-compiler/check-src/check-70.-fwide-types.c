/*
 * Mode of operation:
 * Each of the *.in files is XER-decoded, then converted into DER,
 * then decoded from DER and encoded into XER again. The resulting
 * stream is checked against rules specified in ../data-70/README file.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>	/* for chdir(2), getcwd(3) */
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <assert.h>
#include <errno.h>

#include <PDU.h>

#ifndef SRCDIR
#define SRCDIR_S ".."
#else
#define STRINGIFY_MACRO2(x) #x
#define STRINGIFY_MACRO(x)  STRINGIFY_MACRO2(x)
#define SRCDIR_S    STRINGIFY_MACRO(SRCDIR)
#endif

enum expectation {
	EXP_OK,		/* Encoding/decoding must succeed */
	EXP_CXER_EXACT,	/* Encoding/decoding using CXER must be exact */
	EXP_CXER_DIFF,	/* Encoding/decoding using CXER must be different */
	EXP_BROKEN,	/* Decoding must fail */
	EXP_DIFFERENT,	/* Reconstruction will yield different encoding */
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
	fprintf(stderr, "]:%zd\n", size);
	buf_offset += size;
	return 0;
}

enum der_or_xer {
	AS_DER,
	AS_XER,
	AS_CXER,
};

static void
save_object_as(PDU_t *st, enum der_or_xer how) {
	asn_enc_rval_t rval; /* Return value */

	buf_offset = 0;

	/*
	 * Save object using specified method.
	 */
	switch(how) {
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
load_object_from(enum expectation expectation, unsigned char *fbuf, size_t size, enum der_or_xer how) {
	asn_dec_rval_t rval;
	asn_dec_rval_t (*zer_decode)(struct asn_codec_ctx_s *,
		asn_TYPE_descriptor_t *, void **, const void *, size_t);
	PDU_t *st = 0;
	size_t csize = 1;

	if(how == AS_DER)
		zer_decode = ber_decode;
	else
		zer_decode = xer_decode;

	if(getenv("INITIAL_CHUNK_SIZE"))
		csize = atoi(getenv("INITIAL_CHUNK_SIZE"));

	/* Perform multiple iterations with multiple chunks sizes */
	for(; csize < 20; csize += 1) {
		int fbuf_offset = 0;
		int fbuf_left = size;
		int fbuf_chunk = csize;

		fprintf(stderr, "LOADING OBJECT OF SIZE %zd, chunks %zd\n",
			size, csize);

		if(st) asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
		st = 0;

		do {
			ASN_DEBUG("Decoding bytes %d..%d (left %d)",
				fbuf_offset,
					fbuf_chunk < fbuf_left
						? fbuf_chunk : fbuf_left,
					fbuf_left);
#ifdef  EMIT_ASN_DEBUG
			if(st) {
				fprintf(stderr, "=== currently ===\n");
				asn_fprint(stderr, &asn_DEF_PDU, st);
				fprintf(stderr, "=== end ===\n");
			}
#endif
			rval = zer_decode(0, &asn_DEF_PDU, (void **)&st,
				fbuf + fbuf_offset,
					fbuf_chunk < fbuf_left 
					? fbuf_chunk : fbuf_left);
			fbuf_offset += rval.consumed;
			fbuf_left -= rval.consumed;
			if(rval.code == RC_WMORE)
				fbuf_chunk += 1;	/* Give little more */
			else
				fbuf_chunk = csize;	/* Back off */
		} while(fbuf_left && rval.code == RC_WMORE);

		if(expectation != EXP_BROKEN) {
			assert(rval.code == RC_OK);
			if(how == AS_DER) {
				assert(fbuf_offset == (ssize_t)size);
			} else {
				assert(fbuf_offset - size < 2
				|| (fbuf_offset + 1 /* "\n" */  == (ssize_t)size
					&& fbuf[size - 1] == '\n')
				|| (fbuf_offset + 2 /* "\r\n" */  == (ssize_t)size
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
process_XER_data(enum expectation expectation, unsigned char *fbuf, size_t size) {
	PDU_t *st;

	st = load_object_from(expectation, fbuf, size, AS_XER);
	if(!st) return;

	/* Save and re-load as DER */
	save_object_as(st, AS_DER);
	st = load_object_from(expectation, buf, buf_offset, AS_DER);
	assert(st);

	save_object_as(st,
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
		assert(!xer_encoding_equal(fbuf, size, buf, buf_offset));
		break;
	case EXP_BROKEN:
		assert(!xer_encoding_equal(fbuf, size, buf, buf_offset));
		break;
	case EXP_CXER_EXACT:
		buf[buf_offset++] = '\n';
		assert((ssize_t)size == buf_offset);
		assert(memcmp(fbuf, buf, size) == 0);
		break;
	case EXP_CXER_DIFF:
		buf[buf_offset++] = '\n';
		assert((ssize_t)size != buf_offset
			|| memcmp(fbuf, buf, size));
		break;
	case EXP_OK:
		assert(xer_encoding_equal(fbuf, size, buf, buf_offset));
		break;
	}

	asn_DEF_PDU.free_struct(&asn_DEF_PDU, st, 0);
}

/*
 * Decode the .der files and try to regenerate them.
 */
static int
process(const char *fname) {
	char prevdir[256];
	unsigned char fbuf[4096];
	char *ext = strrchr(fname, '.');
	enum expectation expectation;
	int ret;
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
	default:
		expectation = EXP_OK; break;
	}

	fprintf(stderr, "\nProcessing file [../%s]\n", fname);

	getcwd(prevdir, sizeof(prevdir));
	ret = chdir(SRCDIR_S "/data-70");
	assert(ret == 0);
	fp = fopen(fname, "r");
	ret = chdir(prevdir);
	assert(ret == 0);
	assert(fp);

	rd = fread(fbuf, 1, sizeof(fbuf), fp);
	fclose(fp);

	assert(rd < (ssize_t)sizeof(fbuf));	/* expect small files */

	process_XER_data(expectation, fbuf, rd);

	return 1;
}

int
main() {
	DIR *dir;
	struct dirent *dent;
	int processed_files = 0;
	char *str;

	/* Process a specific test file */
	str = getenv("DATA_70_FILE");
	if(str && strncmp(str, "data-70-", 8) == 0) {
		process(str);
		return 0;
	}

	dir = opendir(SRCDIR_S "/data-70");
	assert(dir);

	/*
	 * Process each file in that directory.
	 */
	while((dent = readdir(dir))) {
		if(strncmp(dent->d_name, "data-70-", 8) == 0)
			if(process(dent->d_name))
				processed_files++;
	}

	assert(processed_files);
	closedir(dir);

	return 0;
}

