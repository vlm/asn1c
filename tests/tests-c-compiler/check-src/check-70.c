/*
 * Mode of operation:
 * Each of the *.in files is XER-decoded, then converted into DER,
 * then decoded from DER and encoded into XER again. The resulting
 * stream is compared with the corresponding .out file.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>	/* for chdir(2), getcwd(3) */
#include <string.h>
#include <dirent.h>
#include <ctype.h>	/* for isspace(3) */
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

#ifdef ENABLE_LIBFUZZER

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    PDU_t *st = 0;
    asn_dec_rval_t rval;
    rval = asn_decode(0, ATS_BASIC_XER, &asn_DEF_PDU, (void **)&st, Data, Size);
    assert(rval.consumed <= Size);
    ASN_STRUCT_FREE(asn_DEF_PDU, st);
    return 0;
}

#else

enum expectation {
	EXP_OK,		/* Encoding/decoding must succeed */
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
	for(; b < bend; b++)
		fprintf(stderr, "%c", *b);
	fprintf(stderr, "]:%zd\n", size);
	buf_offset += size;
	return 0;
}

static void
save_object_as(PDU_t *st, enum asn_transfer_syntax syntax) {
    asn_enc_rval_t rval; /* Return value */

    buf_offset = 0;

    rval = asn_encode(0, syntax, &asn_DEF_PDU, st, _buf_writer, 0);

    if (rval.encoded == -1) {
		fprintf(stderr,
			"Cannot encode %s: %s\n",
			rval.failed_type->name, strerror(errno));
		assert(rval.encoded != -1);
		return;
    }

    fprintf(stderr, "SAVED OBJECT IN SIZE %d/%zu\n", buf_offset, rval.encoded);

    assert(buf_offset == rval.encoded);
}

static PDU_t *
load_object_from(enum expectation expectation, unsigned char *fbuf, size_t size, enum asn_transfer_syntax syntax) {
	asn_dec_rval_t rval;
	PDU_t *st = 0;
	size_t csize = 1;

	if(getenv("INITIAL_CHUNK_SIZE"))
		csize = atoi(getenv("INITIAL_CHUNK_SIZE"));

	/* Perform multiple iterations with multiple chunks sizes */
	for(; csize < 20; csize += 1) {
		int fbuf_offset = 0;
		int fbuf_left = size;
		int fbuf_chunk = csize;

		fprintf(stderr, "LOADING OBJECT OF SIZE %zd, chunks %zd\n",
			size, csize);

		if(st) ASN_STRUCT_FREE(asn_DEF_PDU, st);
		st = 0;

		do {
			ASN_DEBUG("Decoding bytes %d..%d (left %d)",
				fbuf_offset,
					fbuf_chunk < fbuf_left
						? fbuf_chunk : fbuf_left,
					fbuf_left);
#ifdef  ASN_EMIT_DEBUG
			if(st) {
				fprintf(stderr, "=== currently ===\n");
				asn_fprint(stderr, &asn_DEF_PDU, st);
				fprintf(stderr, "=== end ===\n");
			}
#endif
			rval = asn_decode(0, syntax, &asn_DEF_PDU, (void **)&st,
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
			if(syntax == ATS_BER) {
				assert(fbuf_offset == (ssize_t)size);
			} else {
				assert((fbuf_offset + 1 /* "\n" */  == (ssize_t)size
					&& fbuf[size - 1] == '\n')
				|| (fbuf_offset + 2 /* "\r\n" */  == (ssize_t)size
					&& fbuf[size - 2] == '\r'
					&& fbuf[size - 1] == '\n')
				);
			}
		} else {
			assert(rval.code != RC_OK);
			fprintf(stderr, "Failed, but this was expected\n");
			ASN_STRUCT_FREE(asn_DEF_PDU, st);
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

	st = load_object_from(expectation, fbuf, size, ATS_BASIC_XER);
	if(!st) return;

	/* Save and re-load as DER */
	save_object_as(st, ATS_DER);
	ASN_STRUCT_FREE(asn_DEF_PDU, st);
	st = load_object_from(expectation, buf, buf_offset, ATS_BER);
	assert(st);

	save_object_as(st, ATS_BASIC_XER);
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
	case EXP_OK:
		assert(xer_encoding_equal(fbuf, size, buf, buf_offset));
		break;
	}

	ASN_STRUCT_FREE(asn_DEF_PDU, st);
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
	char *cwd;
	int ret;
	int rd;
	FILE *fp;

	if(ext == 0 || strcmp(ext, ".in"))
		return 0;

	switch(ext[-1]) {
	case 'B':	/* The file is intentionally broken */
		expectation = EXP_BROKEN; break;
	case 'X':
	case 'D':	/* Reconstructing should yield different data */
		expectation = EXP_DIFFERENT; break;
	case 'E':
	default:
		expectation = EXP_OK; break;
	}

	fprintf(stderr, "\nProcessing file [../%s]\n", fname);

	cwd = getcwd(prevdir, sizeof(prevdir));
	assert(cwd != NULL);
	ret = chdir(SRCDIR_S "/data-70");
	assert(ret == 0);
	fp = fopen(fname, "r");
	ret = chdir(prevdir);
	assert(ret == 0);
	assert(fp);

	rd = fread(fbuf, 1, sizeof(fbuf), fp);
	fclose(fp);

	assert(rd > 0 && (size_t)rd < sizeof(fbuf));	/* expect small files */

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
	if(str && strncmp(str, "data-70-", 8) == 0)
		process(str);

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

#endif
