/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id$
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sysexits.h>		/* for EX_USAGE */
#include <assert.h>
#include <errno.h>

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif

#include <asn1parser.h>		/* For static string tables */

#include <asn_application.h>
#include <constraints.c>
#include <ber_tlv_tag.c>
#include <ber_tlv_length.c>
#include <OBJECT_IDENTIFIER.c>
#include <RELATIVE-OID.c>
#include <ber_codec_prim.c>

static void usage(const char *av0);	/* Print the Usage screen and exit */
static int process(const char *fname);	/* Perform the BER decoding */
static int decode_tlv_from_string(const char *datastring);

#undef	COPYRIGHT
#define	COPYRIGHT	\
	"Copyright (c) 2004 Lev Walkin <vlm@lionet.info>\n"

static int single_type_decoding = 0;	/* -1 enables that */
static int pretty_printing = 1;		/* -p disables that */
static char *indent_buffer = "    ";	/* -i controls that */

int
main(int ac, char **av) {
	int ch;				/* Command line character */
	int i;				/* Index in some loops */

	/*
	 * Process command-line options.
	 */
	while((ch = getopt(ac, av, "1hi:pt:v")) != -1)
	switch(ch) {
	case '1':
		single_type_decoding = 1;
		break;
	case 't':
		if(decode_tlv_from_string(optarg))
			exit(EX_DATAERR);
		exit(0);
	case 'p':
		pretty_printing = 0;
		break;
	case 'i':
		i = atoi(optarg);
		if(i >= 0 && i < 16) {
			indent_buffer = alloca(i + 1);
			memset(indent_buffer, ' ', i);
			indent_buffer[i] = '\0';
		} else {
			fprintf(stderr, "-i %s: Invalid indent value\n",optarg);
			exit(EX_USAGE);
		}
		break;
	case 'v':
		fprintf(stderr, "ASN.1 BER Decoder, v" VERSION "\n" COPYRIGHT);
		exit(0);
		break;
	case 'h':
	default:
		usage(av[0]);
	}

	/*
	 * Ensure that there are some input files present.
	 */
	if(ac > optind) {
		ac -= optind;
		av += optind;
	} else {
		fprintf(stderr, "%s: No input files specified\n", av[0]);
		exit(1);
	}

	setvbuf(stdout, 0, _IOLBF, 0);

	/*
	 * Iterate over input files and parse each.
	 * All syntax trees from all files will be bundled together.
	 */
	for(i = 0; i < ac; i++) {
		if(process(av[i]))
			exit(EX_DATAERR);
	}

	return 0;
}

/*
 * Print the usage screen and exit(EX_USAGE).
 */
static void
usage(const char *av0) {
	fprintf(stderr,
"ASN.1 BER Decoder, v" VERSION "\n" COPYRIGHT
"Usage: %s [options] [-] [file ...]\n"
"Options:\n"
"  -1                 Decode only the first BER structure (otherwise, until EOF)\n"
"  -i <indent>        Amount of spaces for output indentation (default is 4)\n"
"  -p                 Do not attempt pretty-printing of known ASN.1 types\n"
"  -t <data-string>   Decode the given tag[/length] sequence (e.g. -t \"bf20\")\n"
"\n"
"The XML opening tag format is as follows:\n"
"  <tform T=\"tag\" TL=\"tl_len\" V=\"{Indefinite|v_len}\" [A=\"type\"] [F]>\n"
"Where:\n"
"  tform    Which form the value is in: constructed (\"C\", \"I\") or primitive (\"P\")\n"
"  tag      The tag class and value\n"
"  tl_len   The length of the TL (BER Tag and Length) encoding\n"
"  v_len    The length of the value (V, encoded by the L), may be \"Indefinite\"\n"
"  type     Likely name of the underlying ASN.1 type (for [UNIVERSAL n] tags)\n"
"  [F]      Indicates that the value was reformatted (pretty-printed)\n"
"See the manual page for details\n"
	, av0);
	exit(EX_USAGE);
}

typedef enum pd_code {
	PD_FAILED	= -1,
	PD_FINISHED	= 0,
	PD_EOF		= 1,
} pd_code_e;
static pd_code_e process_deeper(const char *fname, FILE *fp, int level, ssize_t limit);
static void print_TL(int fin, int level, int constr, ssize_t tlen, ber_tlv_tag_t, ber_tlv_len_t);
static int print_V(const char *fname, FILE *fp, ber_tlv_tag_t, ber_tlv_len_t);

/*
 * Open the file and initiate recursive processing.
 */
static int
process(const char *fname) {
	FILE *fp;
	pd_code_e pdc;

	if(strcmp(fname, "-")) {
		fp = fopen(fname, "r");
		if(!fp) {
			perror(fname);
			return -1;
		}
	} else {
		fp = stdin;
	}

	/*
	 * Fetch out BER-encoded data until EOF or error.
	 */
	do {
		pdc = process_deeper(fname, fp, 0, -1);
	} while(pdc == PD_FINISHED && !single_type_decoding);

	if(fp != stdin)
		fclose(fp);

	if(pdc == PD_FAILED)
		return -1;
	return 0;
}

/*
 * Process the TLV recursively.
 */
static pd_code_e process_deeper(const char *fname, FILE *fp, int level, ssize_t limit) {
	unsigned char tagbuf[32];
	ssize_t tblen = 0;
	pd_code_e pdc = PD_FINISHED;
	ber_tlv_tag_t tlv_tag;
	ber_tlv_len_t tlv_len;
	ssize_t t_len;
	ssize_t l_len;

	do {
		int constr;
		int ch;

		if(limit == 0)
			return PD_FINISHED;

		if(limit >= 0 && tblen >= limit) {
			fprintf(stderr,
				"%s: Too long TL sequence (%ld >= %ld). "
					"Dangerous file\n",
				fname, (long)tblen, (long)limit);
			return PD_FAILED;
		}

		ch = fgetc(fp);
		if(ch == -1) {
			if(tblen) {
				fprintf(stderr,
					"%s: Unexpected end of file (TL)\n",
					fname);
				return PD_FAILED;
			} else {
				return PD_EOF;
			}
		}

		tagbuf[tblen++] = ch;

		/*
		 * Decode the TLV tag.
		 */
		t_len = ber_fetch_tag(tagbuf, tblen, &tlv_tag);
		switch(t_len) {
		case -1:
			fprintf(stderr, "%s: Fatal error deciphering tag\n",
				fname);
			return PD_FAILED;
		case 0:
			/* More data expected */
			continue;
		}

		/*
		 * Decode the TLV length.
		 */
		constr = BER_TLV_CONSTRUCTED(tagbuf);
		l_len = ber_fetch_length(constr,
				tagbuf + t_len, tblen - t_len, &tlv_len);
		switch(l_len) {
		case -1:
			fprintf(stderr, "%s: Fatal error deciphering length\n",
				fname);
			return PD_FAILED;
		case 0:
			/* More data expected */
			continue;
		}

		if(tagbuf[0] == '\0' && tagbuf[1] == '\0') {
			/* End of content octets */
			return PD_FINISHED;
		}

		/* Make sure the T & L decoders took exactly the whole buffer */
		assert((t_len + l_len) == tblen);

		print_TL(0, level, constr, tblen, tlv_tag, tlv_len);

		if(limit != -1) {
			/* If limit is set, account for the TL sequence */
			limit -= (t_len + l_len);
			assert(limit >= 0);
		}

		if(limit != -1) {
			if(tlv_len > limit) {
				fprintf(stderr,
				"%s: Structure advertizes length (%ld) "
				"greater than of a parent container (%ld)\n",
					fname, (long)tlv_len, (long)limit);
				return PD_FAILED;
			} else if(tlv_len != -1) {
				/* Account for the V */
				limit -= tlv_len;
			}
		}

		if(constr) {
			/*
			 * This is a constructed type. Process recursively.
			 */

			/* Get the new subframe limit from the structure tags */
			if(tlv_len == -1)
				tlv_len = limit;

			printf(">\n");	/* Close the opening tag */
			pdc = process_deeper(fname, fp, level + 1, tlv_len);
			if(pdc == PD_FAILED) return pdc;
		} else {

			assert(tlv_len >= 0);
			if(print_V(fname, fp, tlv_tag, tlv_len))
				return PD_FAILED;
		}

		print_TL(1, level, constr, tblen, tlv_tag, tlv_len);

		tblen = 0;
	} while(1);

	return pdc;
}

static void
print_TL(int fin, int level, int constr, ssize_t tlen, ber_tlv_tag_t tlv_tag, ber_tlv_len_t tlv_len) {

	if(fin && !constr) {
		printf("</P>\n");
		return;
	}

	while(level-- > 0) printf(indent_buffer);  /* Print indent */
	printf(fin ? "</" : "<");

	printf(constr ? ((tlv_len == -1) ? "I" : "C") : "P");

	printf(" T=\"");
	ber_tlv_tag_fwrite(tlv_tag, stdout);
	printf("\"");

	if(!fin) {
		printf(" TL=\"%ld\"", (long)tlen);

		if(tlv_len == -1)
			printf(" V=\"Indefinite\"");
		else
			printf(" V=\"%ld\"", (long)tlv_len);
	}

	if(BER_TAG_CLASS(tlv_tag) == ASN_TAG_CLASS_UNIVERSAL) {
		const char *str;
		ber_tlv_tag_t tvalue = BER_TAG_VALUE(tlv_tag);
		str = ASN_UNIVERSAL_TAG2STR(tvalue);
		if(str) printf(" A=\"%s\"", str);
	}

	if(fin) printf(">\n");
}

/*
 * Print the value in binary form, or reformat for pretty-printing.
 */
static int
print_V(const char *fname, FILE *fp, ber_tlv_tag_t tlv_tag, ber_tlv_len_t tlv_len) {
	asn1_integer_t *arcs = 0;	/* Object identifier arcs */
	unsigned char *vbuf = 0;
	asn1p_expr_type_e etype = 0;
	asn1_integer_t collector = 0;
	int special_format = 0;
	ssize_t i;

	/* Figure out what type is it */
	if(BER_TAG_CLASS(tlv_tag) == ASN_TAG_CLASS_UNIVERSAL
	&& pretty_printing) {
		ber_tlv_tag_t tvalue = BER_TAG_VALUE(tlv_tag);
		etype = ASN_UNIVERSAL_TAG2TYPE(tvalue);
	}

	/*
	 * Determine how to print the value, either in its native binary form,
	 * encoded with &xNN characters, or using pretty-printing.
	 * The basic string types (including "useful types", like UTCTime)
	 * are excempt from this determination logic, because their alphabets
	 * are subsets of the XML's native UTF-8 encoding.
	 */
	switch(etype) {
	case ASN_BASIC_BOOLEAN:
		if(tlv_len == 1)
			special_format = 1;
		else
			etype = 0;
		break;
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		if((size_t)tlv_len <= sizeof(collector))
			special_format = 1;
		else
			etype = 0;
		break;
	case ASN_BASIC_OBJECT_IDENTIFIER:
	case ASN_BASIC_RELATIVE_OID:
		if(tlv_len > 0 && tlv_len < 128*1024 /* VERY long OID! */) {
			arcs = malloc(sizeof(*arcs) * (tlv_len + 1));
			if(arcs) {
				vbuf = malloc(tlv_len + 1);
				/* Not checking is intentional */
			}
		}
	case ASN_BASIC_UTCTime:
	case ASN_BASIC_GeneralizedTime:
	case ASN_STRING_NumericString:
	case ASN_STRING_PrintableString:
	case ASN_STRING_VisibleString:
	case ASN_STRING_IA5String:
	case ASN_STRING_UTF8String:
		break;	/* Directly compatible with UTF-8 */
	case ASN_STRING_BMPString:
	case ASN_STRING_UniversalString:
		break;	/* Not directly compatible with UTF-8 */
	default:
		/* Conditionally compatible with UTF-8 */
		if((
			(etype & ASN_STRING_MASK)
			||
			(etype == ASN_BASIC_OCTET_STRING)
		) && (tlv_len > 0 && tlv_len < 128 * 1024)) {
			vbuf = malloc(tlv_len + 1);
			/* Not checking is intentional */
		}
		break;
	}

	/* If collection vbuf is present, defer printing the F flag. */
	if(!vbuf) printf(special_format ? " F>" : ">");

	/*
	 * Print the value in binary or text form.
	 */
	for(i = 0; i < tlv_len; i++) {
		int ch = fgetc(fp);
		if(ch == -1) {
			fprintf(stderr,
			"%s: Unexpected end of file (V)\n", fname);
			if(vbuf) free(vbuf);
			if(arcs) free(arcs);
			return -1;
		}
		switch(etype) {
		case ASN_BASIC_UTCTime:
		case ASN_BASIC_GeneralizedTime:
		case ASN_STRING_NumericString:
		case ASN_STRING_PrintableString:
		case ASN_STRING_VisibleString:
		case ASN_STRING_IA5String:
		case ASN_STRING_UTF8String:
			switch(ch) {
			default:
				if(((etype == ASN_STRING_UTF8String)
					|| !(ch & 0x80))
				&& (ch >= 0x20)
				) {
					printf("%c", ch);
					break;
				}
				/* Fall through */
			case '<': case '>': case '&':
				printf("&x%02x;", ch);
			}
			break;
		case ASN_BASIC_BOOLEAN:
			switch(ch) {
			case 0: printf("<false/>"); break;
			case 0xff: printf("<true/>"); break;
			default: printf("<true value=\"&x%02x\"/>", ch);
			}
			break;
		case ASN_BASIC_INTEGER:
		case ASN_BASIC_ENUMERATED:
			if(i)	collector = collector * 256 + ch;
			else	collector = (int)(signed char)ch;
			break;
		default:
			if(vbuf) {
				vbuf[i] = ch;
			} else {
				printf("&x%02x;", ch);
			}
		}
	}

	/* Do post-processing */
	switch(etype) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		printf("%" PRIdASN, collector);
		break;
	case ASN_BASIC_OBJECT_IDENTIFIER:
		if(vbuf) {
			OBJECT_IDENTIFIER_t oid;
			int arcno;

			oid.buf = vbuf;
			oid.size = tlv_len;

			arcno = OBJECT_IDENTIFIER_get_arcs(&oid, arcs,
				sizeof(*arcs), tlv_len + 1);
			if(arcno >= 0) {
				assert(arcno <= (tlv_len + 1));
				printf(" F>");
				for(i = 0; i < arcno; i++) {
					if(i) printf(".");
					printf("%" PRIuASN, arcs[i]);
				}
				free(vbuf);
				vbuf = 0;
			}
		}
		break;
	case ASN_BASIC_RELATIVE_OID:
		if(vbuf) {
			RELATIVE_OID_t oid;
			int arcno;

			oid.buf = vbuf;
			oid.size = tlv_len;
	
			arcno = RELATIVE_OID_get_arcs(&oid, arcs,
				sizeof(*arcs), tlv_len);
			if(arcno >= 0) {
				assert(arcno <= (tlv_len + 1));
				printf(" F>");
				for(i = 0; i < arcno; i++) {
					if(i) printf(".");
					printf("%" PRIuASN, arcs[i]);
				}
				free(vbuf);
				vbuf = 0;
			}
		}
		break;
	default: break;
	}

	/*
	 * If the buffer was not consumed, print it out.
	 */
	if(vbuf) {
		int binary;

		/*
		 * Check whether the data could be represented as text
		 */
		binary = -1 * (tlv_len >> 2); /* Threshold is 25% binary */
		for(i = 0; i < tlv_len; i++) {
			switch(vbuf[i]) {
			case 0x1b: binary = 1; break;
			case 0x09: case 0x0a: case 0x0d: continue;
			default:
				if(vbuf[i] < 0x20 || (vbuf[i] & 0x80))
					if(++binary > 0)  /* Way too many */
						break;
				continue;
			}
			break;
		}
		printf(">");
		for(i = 0; i < tlv_len; i++) {
			if(binary > 0 || vbuf[i] < 0x20 || (vbuf[i] & 0x80))
				printf("&x%02x;", vbuf[i]);
			else
				printf("%c", vbuf[i]);
		}
		free(vbuf);
	}

	if(arcs) free(arcs);
	return 0;
}


static int
decode_tlv_from_string(const char *datastring) {
	unsigned char *data, *dp;
	size_t dsize;	/* Data size */
	ssize_t len;
	ber_tlv_tag_t tlv_tag;
	ber_tlv_len_t tlv_len;
	const char *p;
	int half;

	dsize = strlen(datastring) + 1;
	dp = data = calloc(1, dsize);
	assert(data);

	for(half = 0, p = datastring; *p; p++) {
		switch(*p) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			*dp |= *p - '0'; break;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			*dp |= *p - 'A' + 10; break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			*dp |= *p - 'a' + 10; break;
		case ' ': case '\t': case '\r': case '\n':
			continue;
		default:
			fprintf(stderr, "Unexpected symbols in data string:\n");
			fprintf(stderr, "%s\n", datastring);
			for(dp = data; datastring < p; datastring++, dp++)
				*dp = ' ';
			*dp = '\0';
			fprintf(stderr, "%s^ <- here\n", (char *)data);
			return -1;
		}
		if(half) dp++; else (*dp) <<= 4;
		half = !half;
	}

	assert((size_t)(dp - data) <= dsize);
	dsize = dp - data;

	printf("BER: ");
	for(dp = data; dp < data + dsize; dp++)
		printf("%02X", *dp);
	printf("\n");

	len = ber_fetch_tag(data, dsize, &tlv_tag);
	switch(len) {
	case -1:
		fprintf(stderr, "TAG: Fatal error deciphering tag\n");
		return -1;
	case 0:
		fprintf(stderr, "TAG: More data expected\n");
		return -1;
	default:
		printf("TAG: ");
		ber_tlv_tag_fwrite(tlv_tag, stdout);
		if(BER_TLV_CONSTRUCTED(data)) {
			printf(" (constructed)");
		} else if(dsize >= 2 && data[0] == 0 && data[1] == 0) {
			printf(" (end-of-content)");
		} else {
			printf(" (primitive)");
		}
		if(BER_TAG_CLASS(tlv_tag) == ASN_TAG_CLASS_UNIVERSAL) {
			const char *str;
			ber_tlv_tag_t tvalue = BER_TAG_VALUE(tlv_tag);
			str = ASN_UNIVERSAL_TAG2STR(tvalue);
			if(str) printf(" \"%s\"", str);
		}
		printf("\n");
	}

	if(dsize > (size_t)len) {
		len = ber_fetch_length(BER_TLV_CONSTRUCTED(data),
			data + len, dsize - len, &tlv_len);
		switch(len) {
		case -1:
			fprintf(stderr,
				"LEN: Fatal error deciphering length\n");
			return -1;
		case 0:
			fprintf(stderr, "LEN: More data expected\n");
			return -1;
		default:
			if(tlv_len == (ber_tlv_len_t)-1)
				printf("LEN: Indefinite length encoding\n");
			else
				printf("LEN: %ld bytes\n", (long)tlv_len);
		}
	}

	return 0;
}

/*
 * Dummy functions.
 */
ber_dec_rval_t ber_check_tags(asn1_TYPE_descriptor_t *td, ber_dec_ctx_t *opt_ctx, void *ptr, size_t size, int tag_mode, int last_tag_form, ber_tlv_len_t *last_length, int *opt_tlv_form) { ber_dec_rval_t rv; (void)td; (void)opt_ctx; (void)ptr; (void)size; (void)tag_mode; (void)last_tag_form; (void)last_length; (void)opt_tlv_form; return rv; }
ssize_t der_write_tags(asn1_TYPE_descriptor_t *td, size_t slen, int tag_mode, int last_tag_form, ber_tlv_tag_t tag, asn_app_consume_bytes_f *cb, void *app_key) { (void)td; (void)slen; (void)tag_mode; (void)last_tag_form; (void)tag; (void)cb; (void)app_key; return -1; }
