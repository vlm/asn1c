/*
 * Generic BER decoder template for any defined ASN.1 type.
 * Copyright (c) 2005 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * 
 * To compile with your own ASN.1 type, please redefine the asn_DEF as shown:
 * 
 * cc -Dasn_DEF=asn_DEF_MyCustomType -o myDecoder.o -c asn-decoder-template.c
 */
#ifdef	HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>	/* for getopt */
#include <string.h>	/* for strerror(3) */
#include <sysexits.h>	/* for EX_* exit codes */
#include <assert.h>	/* for assert(3) */
#include <errno.h>	/* for errno */

#include <asn_application.h>

extern asn_TYPE_descriptor_t asn_DEF;	/* ASN.1 type to be decoded */

/*
 * Open file and parse its contens.
 */
static void *data_decode_from_file(asn_TYPE_descriptor_t *asnTypeOfPDU,
	const char *fname, ssize_t suggested_bufsize);

       int opt_debug;	/* -d */
static int opt_check;	/* -c */
static int opt_stack;	/* -s */
static enum output_method {
	OUT_NONE,	/* No pretty-printing */
	OUT_PRINT,	/* -p flag */
	OUT_XML		/* -x flag */
}          opt_ometh;	/* -p or -x */

#define	DEBUG(fmt, args...)	do {		\
	if(!opt_debug) break;			\
	fprintf(stderr, fmt, ##args);		\
	fprintf(stderr, "\n");			\
} while(0)

int
main(int ac, char **av) {
	ssize_t suggested_bufsize = 8192;  /* close or equal to stdio buffer */
	asn_TYPE_descriptor_t *pduType = &asn_DEF;
	int number_of_iterations = 1;
	int num;
	int ch;

	/*
	 * Pocess the command-line argments.
	 */
	while((ch = getopt(ac, av, "b:cdn:hps:x")) != -1)
	switch(ch) {
	case 'b':
		suggested_bufsize = atoi(optarg);
		if(suggested_bufsize < 1
			|| suggested_bufsize > 16 * 1024 * 1024) {
			fprintf(stderr,
				"-b %s: Improper buffer size (1..16M)\n",
				optarg);
			exit(EX_UNAVAILABLE);
		}
		break;
	case 'c':
		opt_check = 1;
		break;
	case 'd':
		opt_debug++;	/* Double -dd means ASN.1 debug */
		break;
	case 'n':
		number_of_iterations = atoi(optarg);
		if(number_of_iterations < 1) {
			fprintf(stderr,
				"-n %s: Improper iterations count\n", optarg);
			exit(EX_UNAVAILABLE);
		}
		break;
	case 'p':
		opt_ometh = OUT_PRINT;
		break;
	case 's':
		opt_stack = atoi(optarg);
		if(opt_stack <= 0) {
			fprintf(stderr,
				"-s %s: Value greater than 0 expected\n",
				optarg);
			exit(EX_UNAVAILABLE);
		}
		break;
	case 'x':
		opt_ometh = OUT_XML;
		break;
	case 'h':
	default:
		fprintf(stderr,
		"Usage: %s [options] <data.ber> ...\n"
		"Where options are:\n"
		"  -b <size>    Set the i/o buffer size (default is %ld)\n"
		"  -c           Check ASN.1 constraints after decoding\n"
		"  -d           Enable debugging (-dd is even better)\n"
		"  -n <num>     Process files <num> times\n"
		"  -s <size>    Set the stack usage limit\n"
		"  -p           Print out the decoded contents\n"
		"  -x           Print out as XML"
#ifdef	ASN_DECODER_DEFAULT_OUTPUT_XML
		" (default)"
#endif
		"\n"
		, av[0], (long)suggested_bufsize);
		exit(EX_USAGE);
	}

	ac -= optind;
	av += optind;

	if(ac < 1) {
		fprintf(stderr, "Error: missing filename\n");
		exit(EX_USAGE);
	}

#ifdef	ASN_DECODER_DEFAULT_OUTPUT_XML
	if(opt_ometh == OUT_NONE) opt_ometh = OUT_XML;
#endif

	setvbuf(stdout, 0, _IOLBF, 0);

	for(num = 0; num < number_of_iterations; num++) {
	  int ac_i;
	  /*
	   * Process all files in turn.
	   */
	  for(ac_i = 0; ac_i < ac; ac_i++) {
		char *fname = av[ac_i];
		void *structure;

		/*
		 * Decode the encoded structure from file.
		 */
		structure = data_decode_from_file(pduType,
				fname, suggested_bufsize);
		if(!structure) {
			/* Error message is already printed */
			exit(EX_DATAERR);
		}

		switch(opt_ometh) {
		case OUT_NONE:
			fprintf(stderr, "%s: decoded successfully\n", fname);
			break;
		case OUT_PRINT:	/* -p */
			asn_fprint(stdout, pduType, structure);
			break;
		case OUT_XML:	/* -x */
			if(xer_fprint(stdout, pduType, structure)) {
				fprintf(stderr, "%s: Cannot convert into XML\n",
					fname);
				exit(EX_UNAVAILABLE);
			}
			break;
		}

		/* Check ASN.1 constraints */
		if(opt_check) {
			char errbuf[128];
			size_t errlen = sizeof(errbuf);
			if(asn_check_constraints(pduType, structure,
				errbuf, &errlen)) {
				fprintf(stderr, "%s: ASN.1 constraint "
					"check failed: %s\n", fname, errbuf);
				exit(EX_DATAERR);
			}
		}

		pduType->free_struct(pduType, structure, 0);
	  }
	}

	return 0;
}


static char *buffer;
static size_t buf_offset;	/* Offset from the start */
static size_t buf_len;		/* Length of meaningful contents */
static size_t buf_size;	/* Allocated memory */
static off_t buf_shifted;	/* Number of bytes ever shifted */

#define	bufptr	(buffer + buf_offset)
#define	bufend	(buffer + buf_offset + buf_len)

/*
 * Ensure that the buffer contains at least this amoount of free space.
 */
static void buf_extend(size_t bySize) {

	DEBUG("buf_extend(%ld) { o=%ld l=%ld s=%ld }",
		(long)bySize, (long)buf_offset, (long)buf_len, (long)buf_size);

	if(buf_size >= (buf_offset + buf_len + bySize)) {
		return;	/* Nothing to do */
	} else if(bySize <= buf_offset) {
		DEBUG("\tContents shifted by %ld", (long)buf_offset);

		/* Shift the buffer contents */
		memmove(buffer, buffer + buf_offset, buf_len);
		buf_shifted += buf_offset;
		buf_offset = 0;
	} else {
		size_t newsize = (buf_size << 2) + bySize;
		void *p = realloc(buffer, newsize);
		if(p) {
			buffer = (char *)p;
			buf_size = newsize;

			DEBUG("\tBuffer reallocated to %ld", (long)newsize);
		} else {
			perror("realloc()");
			exit(EX_OSERR);
		}
	}
}

static void *data_decode_from_file(asn_TYPE_descriptor_t *pduType, const char *fname, ssize_t suggested_bufsize) {
	static char *fbuf;
	static ssize_t fbuf_size;
	static asn_codec_ctx_t s_codec_ctx;
	asn_codec_ctx_t *opt_codec_ctx = 0;
	void *structure = 0;
	size_t rd;
	FILE *fp;

	if(opt_stack) {
		s_codec_ctx.max_stack_size = opt_stack;
		opt_codec_ctx = &s_codec_ctx;
	}

	DEBUG("Processing file %s", fname);

	fp = fopen(fname, "r");

	if(!fp) {
		fprintf(stderr, "%s: %s\n", fname, strerror(errno));
		return 0;
	}

	/* prepare the file buffer */
	if(fbuf_size != suggested_bufsize) {
		fbuf = (char *)realloc(fbuf, suggested_bufsize);
		if(!fbuf) {
			perror("realloc()");
			exit(EX_OSERR);
		}
		fbuf_size = suggested_bufsize;
	}

	buf_shifted = 0;
	buf_offset = 0;
	buf_len = 0;

	while((rd = fread(fbuf, 1, fbuf_size, fp)) || !feof(fp)) {
		asn_dec_rval_t rval;
		int using_local_buf;

		/*
		 * Copy the data over, or use the original buffer.
		 */
		if(buf_len) {
			/* Append the new data into the intermediate buffer */
			buf_extend(rd);
			memcpy(bufend, fbuf, rd);
			buf_len += rd;

			rval = ber_decode(opt_codec_ctx, pduType,
				(void **)&structure, bufptr, buf_len);
			DEBUG("ber_decode(%ld) consumed %ld, code %d",
				(long)buf_len, (long)rval.consumed, rval.code);

			/*
			 * Adjust position inside the source buffer.
			 */
			assert(rval.consumed <= buf_len);
			buf_offset += rval.consumed;
			buf_len -= rval.consumed;
		} else {
			using_local_buf = 1;

			/* Feed the chunk of data into a decoder routine */
			rval = ber_decode(opt_codec_ctx, pduType,
				(void **)&structure, fbuf, rd);
			DEBUG("ber_decode(%ld) consumed %ld, code %d",
				(long)rd, (long)rval.consumed, rval.code);

			/*
			 * Switch the remainder into the intermediate buffer.
			 */
			if(rval.code != RC_FAIL && rval.consumed < rd) {
				buf_extend(rd - rval.consumed);
				memcpy(bufend,
					fbuf + rval.consumed,
					rd - rval.consumed);
				buf_len = rd - rval.consumed;
			}
		}

		switch(rval.code) {
		case RC_OK:
			DEBUG("RC_OK, finishing up");
			fclose(fp);
			return structure;
		case RC_WMORE:
			DEBUG("RC_WMORE, continuing...");
			continue;
		case RC_FAIL:
			break;
		}
		break;
	}

	fclose(fp);

	/* Clean up partially decoded structure */
	pduType->free_struct(pduType, structure, 0);

	fprintf(stderr, "%s: "
		"Decode failed past %lld byte\n",
		fname, (long long)(buf_shifted + buf_offset));

	return 0;
}

