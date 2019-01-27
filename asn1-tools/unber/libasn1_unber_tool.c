/*
 * Copyright (c) 2004, 2005, 2006 Lev Walkin <vlm@lionet.info>.
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
 */
#include "asn1_common.h"
#include "libasn1_unber_tool.h"

#define ASN_DISABLE_PER_SUPPORT 1
#define ASN_DISABLE_OER_SUPPORT 1

#include <asn1parser.h> /* For static string tables */

#include <asn_application.h>
#include <constraints.c>
#include <ber_tlv_tag.c>
#include <ber_tlv_length.c>
#include <INTEGER.c>
#include <OBJECT_IDENTIFIER.c>
#include <RELATIVE-OID.c>
#include <asn_codecs_prim.c>
#include <asn1p_integer.c>
#include <asn_internal.c>

static int single_type_decoding = 0;   /* -1 enables that */
static int minimalistic = 0;           /* -m enables that */
static int pretty_printing = 1;        /* -p disables that */
static long skip_bytes = 0;            /* -s controls that */
static char indent_bytes[16] = "    "; /* -i controls that */

void set_minimalistic_output(int v) { minimalistic = v; }
void set_single_type_decoding(int v) { single_type_decoding = v; }
void set_pretty_printing(int v) { pretty_printing = v; }
int set_skip_bytes(long v) { if(v < 0) return -1; skip_bytes = v; return 0; }
int set_indent_size(int indent_size) {
    if(indent_size < 0 || indent_size >= (int)sizeof(indent_bytes)) {
        return -1;
    }
    memset(indent_bytes, ' ', indent_size);
    indent_bytes[indent_size] = '\0';
    return 0;
}

typedef enum pd_code {
    PD_FAILED = -1,
    PD_FINISHED = 0,
    PD_EOF = 1,
} pd_code_e;
static pd_code_e process_deeper(const char *fname, input_stream_t *,
                                output_stream_t *os, int level,
                                ssize_t limit, ber_tlv_len_t *frame_size,
                                ber_tlv_len_t effective_size, int expect_eoc);
static void print_TL(output_stream_t *, int fin, off_t offset, int level,
                     int constr, ssize_t tlen, ber_tlv_tag_t, ber_tlv_len_t,
                     ber_tlv_len_t effective_frame_size);
static int print_V(const char *fname, input_stream_t *, output_stream_t *,
                   ber_tlv_tag_t, ber_tlv_len_t);

static int ibs_getc(input_stream_t *ibs) { return ibs->nextChar(ibs); }
static int __attribute__((format(printf, 2, 3)))
osprintf(output_stream_t *os, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = os->vprintf(os, fmt, ap);
    va_end(ap);
    return ret;
}
static int __attribute__((format(printf, 2, 3)))
osprintfError(output_stream_t *os, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = os->vprintfError(os, fmt, ap);
    va_end(ap);
    return ret;
}

/*
 * Open the file and initiate recursive processing.
 */
int
unber_stream(const char *fname, input_stream_t *ibs, output_stream_t *os) {
    pd_code_e pdc;
    ber_tlv_len_t frame_size = 0; /* Single frame size */

    /*
     * Skip the requested amount of bytes.
     */
    for(size_t offset = 0; offset < (size_t)skip_bytes; offset++) {
        if(ibs_getc(ibs) == -1) {
            osprintfError(os,
                          "%s: input source has less data "
                          "than \"-s %ld\" switch wants to skip\n",
                          fname, skip_bytes);
            return -1;
        }
    }

    /*
     * Fetch out BER-encoded data until EOF or error.
     */
    do {
        pdc = process_deeper(fname, ibs, os, 0, -1, &frame_size, 0, 0);
    } while(pdc == PD_FINISHED && !single_type_decoding);

    if(pdc == PD_FAILED) return -1;
    return 0;
}

/*
 * Process the TLV recursively.
 */
static pd_code_e
process_deeper(const char *fname, input_stream_t *ibs, output_stream_t *os,
               int level, ssize_t limit, ber_tlv_len_t *frame_size,
               ber_tlv_len_t effective_size, int expect_eoc) {
    unsigned char tagbuf[32];
    ssize_t tblen = 0;
    pd_code_e pdc = PD_FINISHED;
    ber_tlv_tag_t tlv_tag;
    ber_tlv_len_t tlv_len;
    ssize_t t_len;
    ssize_t l_len;

    for(;;) {
        ber_tlv_len_t local_esize = 0;
        int constr;
        int ch;

        if(limit == 0) return PD_FINISHED;

        if(limit >= 0 && tblen >= limit) {
            osprintfError(os,
                          "%s: Too long TL sequence (%zd >= %zd) at %lld. "
                          "Broken or maliciously constructed file\n",
                          fname, tblen, limit, (long long)ibs->bytesRead(ibs));
            return PD_FAILED;
        }

        if(tblen >= (ssize_t)sizeof(tagbuf)) {
            osprintfError(os,
                          "%s: Too long TL sequence (%zd bytes) at %lld. "
                          "Broken or maliciously constructed file\n",
                          fname, tblen, (long long)ibs->bytesRead(ibs));
            return PD_FAILED;
        }

        /* Get the next byte from the input stream */
        ch = ibs_getc(ibs);
        if(ch == -1) {
            if(limit > 0 || expect_eoc) {
                osprintfError(os,
                              "%s: Unexpected end of file (TL)"
                              " at %lld\n",
                              fname, (long long)ibs->bytesRead(ibs));
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
            osprintfError(os,
                          "%s: Fatal error decoding tag"
                          " at %lld\n",
                          fname, (long long)ibs->bytesRead(ibs));
            return PD_FAILED;
        case 0:
            /* More data expected */
            continue;
        }

        /*
         * Decode the TLV length.
         */
        constr = BER_TLV_CONSTRUCTED(tagbuf);
        l_len =
            ber_fetch_length(constr, tagbuf + t_len, tblen - t_len, &tlv_len);
        switch(l_len) {
        case -1:
            osprintfError(os,
                          "%s: Fatal error decoding value length"
                          " at %lld\n",
                          fname, (long long)ibs->bytesRead(ibs));
            return PD_FAILED;
        case 0:
            /* More data expected */
            continue;
        }

        /* Make sure the T & L decoders took exactly the whole buffer */
        if((t_len + l_len) != tblen) {
            osprintfError(os,
                          "%s: Outer tag length doesn't match inner tag length"
                          " at %lld\n",
                          fname, (long long)ibs->bytesRead(ibs));
            return PD_FAILED;
        }

        if(!expect_eoc || tagbuf[0] || tagbuf[1])
            print_TL(os, 0, ibs->bytesRead(ibs) - tblen, level, constr, tblen,
                     tlv_tag, tlv_len, effective_size);

        if(limit != -1) {
            /* If limit is set, account for the TL sequence */
            limit -= (t_len + l_len);
            assert(limit >= 0);

            if(tlv_len > limit) {
                osprintfError(os,
                              "%s: Structure advertizes length (%ld) "
                              "greater than of a parent container (%ld)\n",
                              fname, (long)tlv_len, (long)limit);
                return PD_FAILED;
            }
        }

        *frame_size += t_len + l_len;
        effective_size += t_len + l_len;
        local_esize += t_len + l_len;

        if(expect_eoc && !tagbuf[0] && !tagbuf[1]) {
            /* End of content octets */
            print_TL(os, 1, ibs->bytesRead(ibs) - 2, level - 1, 1, 2, 0, -1,
                     effective_size);
            return PD_FINISHED;
        }

        if(constr) {
            ber_tlv_len_t dec = 0;
            /*
             * This is a constructed type. Process recursively.
             */
            osprintf(os, ">\n"); /* Close the opening tag */
            if(tlv_len != -1 && limit != -1) {
                assert(limit >= tlv_len);
            }
            pdc = process_deeper(fname, ibs, os, level + 1,
                                 tlv_len == -1 ? limit : tlv_len, &dec,
                                 t_len + l_len, tlv_len == -1);
            if(pdc == PD_FAILED) return pdc;
            if(limit != -1) {
                assert(limit >= dec);
                limit -= dec;
            }
            *frame_size += dec;
            effective_size += dec;
            local_esize += dec;
            if(tlv_len == -1) {
                tblen = 0;
                if(pdc == PD_FINISHED && limit < 0 && !expect_eoc) return pdc;
                continue;
            }
        } else {
            assert(tlv_len >= 0);
            if(print_V(fname, ibs, os, tlv_tag, tlv_len)) return PD_FAILED;

            if(limit != -1) {
                assert(limit >= tlv_len);
                limit -= tlv_len;
            }
            *frame_size += tlv_len;
            effective_size += tlv_len;
            local_esize += tlv_len;
        }

        print_TL(os, 1, ibs->bytesRead(ibs), level, constr, tblen,
                 tlv_tag, tlv_len, local_esize);

        tblen = 0;

        /* Report success for a single top level TLV */
        if(level == 0 && limit == -1 && !expect_eoc) break;
    } /* for(;;) */

    return pdc;
}

static void
print_TL(output_stream_t *os, int fin, off_t offset, int level, int constr,
         ssize_t tlen, ber_tlv_tag_t tlv_tag, ber_tlv_len_t tlv_len,
         ber_tlv_len_t effective_size) {
    if(fin && !constr) {
        osprintf(os, "</P>\n");
        return;
    }

    while(level-- > 0) osprintf(os, "%s", indent_bytes); /* Print indent */
    osprintf(os, fin ? "</" : "<");

    osprintf(os, constr ? ((tlv_len == -1) ? "I" : "C") : "P");

    /* Print out the offset of this boundary, even if closing tag */
    if(!minimalistic) osprintf(os, " O=\"%lld\"", (long long)offset);

    osprintf(os, " T=\"%s\"", ber_tlv_tag_string(tlv_tag));

    if(!fin || (tlv_len == -1 && !minimalistic))
        osprintf(os, " TL=\"%ld\"", (long)tlen);
    if(!fin) {
        if(tlv_len == -1)
            osprintf(os, " V=\"Indefinite\"");
        else
            osprintf(os, " V=\"%ld\"", (long)tlv_len);
    }

    if(!minimalistic && BER_TAG_CLASS(tlv_tag) == ASN_TAG_CLASS_UNIVERSAL) {
        const char *str;
        ber_tlv_tag_t tvalue = BER_TAG_VALUE(tlv_tag);
        str = ASN_UNIVERSAL_TAG2STR(tvalue);
        if(str) osprintf(os, " A=\"%s\"", str);
    }

    if(fin) {
        if(constr && !minimalistic) {
            osprintf(os, " L=\"%ld\"", (long)effective_size);
        }
        osprintf(os, ">\n");
    }
}

/*
 * Print the value in binary form, or reformat for pretty-printing.
 */
static int
print_V(const char *fname, input_stream_t *ibs, output_stream_t *os,
        ber_tlv_tag_t tlv_tag, ber_tlv_len_t tlv_len) {
    asn_oid_arc_t *arcs = 0; /* Object identifier arcs */
    unsigned char *vbuf = 0;
    asn1p_expr_type_e etype = 0;
    asn1c_integer_t collector = 0;
    int special_format = 0;
    ssize_t i;

    /* Figure out what type is it */
    if(BER_TAG_CLASS(tlv_tag) == ASN_TAG_CLASS_UNIVERSAL && pretty_printing) {
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
        if(tlv_len > 0 && tlv_len < 128 * 1024 /* VERY long OID! */) {
            arcs = MALLOC(sizeof(*arcs) * (tlv_len + 1));
            if(arcs) {
                vbuf = MALLOC(tlv_len + 1);
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
        break; /* Directly compatible with UTF-8 */
    case ASN_STRING_BMPString:
    case ASN_STRING_UniversalString:
        break; /* Not directly compatible with UTF-8 */
    default:
        /* Conditionally compatible with UTF-8 */
        if(((etype & ASN_STRING_MASK) || (etype == ASN_BASIC_OCTET_STRING) ||
            /*
             * AUTOMATIC TAGS or IMPLICIT TAGS in effect,
             * Treat this primitive type as OCTET_STRING.
             */
            (BER_TAG_CLASS(tlv_tag) != ASN_TAG_CLASS_UNIVERSAL
             && pretty_printing))
           && (tlv_len > 0 && tlv_len < 128 * 1024)) {
            vbuf = MALLOC(tlv_len + 1);
            /* Not checking is intentional */
        }
        break;
    }

    /* If collection vbuf is present, defer printing the F flag. */
    if(!vbuf) osprintf(os, special_format ? " F>" : ">");

    /*
     * Print the value in binary or text form,
     * or collect the bytes into vbuf.
     */
    for(i = 0; i < tlv_len; i++) {
        int ch = ibs_getc(ibs);
        if(ch == -1) {
            osprintfError(os, "%s: Unexpected end of file (V)\n", fname);
            if(vbuf) FREEMEM(vbuf);
            if(arcs) FREEMEM(arcs);
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
                if(((etype == ASN_STRING_UTF8String) || !(ch & 0x80))
                   && (ch >= 0x20)) {
                    osprintf(os, "%c", ch);
                    break;
                }
            /* Fall through */
            case 0x3c:
            case 0x3e:
            case 0x26:
                osprintf(os, "&#x%02x;", ch);
            }
            break;
        case ASN_BASIC_BOOLEAN:
            switch(ch) {
            case 0:
                osprintf(os, "<false/>");
                break;
            case 0xff:
                osprintf(os, "<true/>");
                break;
            default:
                osprintf(os, "<true value=\"&#x%02x\"/>", ch);
            }
            break;
        case ASN_BASIC_INTEGER:
        case ASN_BASIC_ENUMERATED:
            if(i)
                collector = collector * 256 + ch;
            else
                collector = (int)(signed char)ch;
            break;
        default:
            if(vbuf) {
                vbuf[i] = ch;
            } else {
                osprintf(os, "&#x%02x;", ch);
            }
        }
    }

    /* Do post-processing */
    switch(etype) {
    case ASN_BASIC_INTEGER:
    case ASN_BASIC_ENUMERATED:
        osprintf(os, "%s", asn1p_itoa(collector));
        break;
    case ASN_BASIC_OBJECT_IDENTIFIER:
        if(vbuf) {
            OBJECT_IDENTIFIER_t oid = {0, 0};
            ssize_t arcno;

            oid.buf = vbuf;
            oid.size = tlv_len;

            arcno = OBJECT_IDENTIFIER_get_arcs(&oid, arcs, tlv_len + 1);
            if(arcno >= 0) {
                assert(arcno <= (tlv_len + 1));
                osprintf(os, " F>");
                for(i = 0; i < arcno; i++) {
                    if(i) osprintf(os, ".");
                    osprintf(os, "%" PRIu32, arcs[i]);
                }
                FREEMEM(vbuf);
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

            arcno = RELATIVE_OID_get_arcs(&oid, arcs, tlv_len);
            if(arcno >= 0) {
                assert(arcno <= tlv_len);
                osprintf(os, " F>");
                for(i = 0; i < arcno; i++) {
                    if(i) osprintf(os, ".");
                    osprintf(os, "%" PRIu32, arcs[i]);
                }
                FREEMEM(vbuf);
                vbuf = 0;
            }
        }
        break;
    default:
        break;
    }

    /*
     * If the buffer was not consumed, print it out.
     * It might be an OCTET STRING or other primitive type,
     * which might actually be printable, but we need to figure it out.
     */
    if(vbuf) {
        int binary;

        /*
         * Check whether the data could be represented as text
         */
        binary = -1 * (tlv_len >> 3); /* Threshold is 12.5% binary */
        for(i = 0; i < tlv_len; i++) {
            switch(vbuf[i]) {
            case 0x1b:
                binary = 1;
                break;
            case 0x09:
            case 0x0a:
            case 0x0d:
                continue;
            default:
                if(vbuf[i] < 0x20 || vbuf[i] >= 0x7f)
                    if(++binary > 0) /* Way too many */
                        break;
                continue;
            }
            break;
        }
        osprintf(os, ">");
        for(i = 0; i < tlv_len; i++) {
            if(binary > 0 || vbuf[i] < 0x20 || vbuf[i] >= 0x7f
               || vbuf[i] == 0x26 /* '&' */
               || vbuf[i] == 0x3c /* '<' */
               || vbuf[i] == 0x3e /* '>' */
               )
                osprintf(os, "&#x%02x;", vbuf[i]);
            else
                osprintf(os, "%c", vbuf[i]);
        }
        FREEMEM(vbuf);
    }

    if(arcs) FREEMEM(arcs);
    return 0;
}

struct file_input_stream {
    input_stream_t istream;
    FILE *fp;
    off_t offset;
};

static int file_input_stream_nextChar(input_stream_t *ibs) {
    struct file_input_stream *fs = (struct file_input_stream *)ibs;
    int ret = fgetc(fs->fp);
    if(ret != -1) {
        fs->offset++;
    }
    return ret;
}

static off_t file_input_stream_bytesRead(input_stream_t *ibs) {
    struct file_input_stream *fs = (struct file_input_stream *)ibs;
    return fs->offset;
}

struct file_output_stream {
    output_stream_t ostream;
    FILE *outputFile;
    FILE *errorFile;
};

static int
file_output_stream_vprintf(output_stream_t *os, const char *fmt, va_list ap) {
    struct file_output_stream *fos = (struct file_output_stream *)os;
    return vfprintf(fos->outputFile, fmt, ap);
}

static int
file_output_stream_vprintfError(output_stream_t *os, const char *fmt, va_list ap) {
    struct file_output_stream *fos = (struct file_output_stream *)os;
    return vfprintf(fos->errorFile, fmt, ap);
}

int
unber_file(const char *fname) {
    FILE *fp;

    if(strcmp(fname, "-")) {
        fp = fopen(fname, "rb");
        if(!fp) {
            perror(fname);
            return -1;
        }
    } else {
        fp = stdin;
    }

    struct file_input_stream ifs;
    ifs.istream.nextChar = file_input_stream_nextChar;
    ifs.istream.bytesRead = file_input_stream_bytesRead;
    ifs.fp = fp;
    ifs.offset = 0;

    struct file_output_stream ofs;
    ofs.ostream.vprintf = file_output_stream_vprintf;
    ofs.ostream.vprintfError = file_output_stream_vprintfError;
    ofs.outputFile = stdout;
    ofs.errorFile = stderr;

    int ret = unber_stream(fname, &ifs.istream, &ofs.ostream);

    if(fp != stdin) fclose(fp);

    return ret;
}

int
decode_tlv_from_hex_string(const char *datastring) {
    unsigned char *data, *dp;
    size_t dsize; /* Data size */
    ssize_t len;
    ber_tlv_tag_t tlv_tag;
    ber_tlv_len_t tlv_len;
    const char *p;
    int half;

    dsize = strlen(datastring) + 1;
    dp = data = CALLOC(1, dsize);
    assert(data);

    for(half = 0, p = datastring; *p; p++) {
        /* clang-format off */
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
        /* clang-format on */
        if(half)
            dp++;
        else
            (*dp) <<= 4;
        half = !half;
    }

    assert((size_t)(dp - data) <= dsize);
    dsize = dp - data;

    printf("BER: ");
    for(dp = data; dp < data + dsize; dp++) printf("%02X", *dp);
    printf("\n");

    len = ber_fetch_tag(data, dsize, &tlv_tag);
    switch(len) {
    case -1:
        fprintf(stderr, "TAG: Fatal error decoding tag\n");
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
        len = ber_fetch_length(BER_TLV_CONSTRUCTED(data), data + len,
                               dsize - len, &tlv_len);
        switch(len) {
        case -1:
            fprintf(stderr, "LEN: Fatal error decoding length\n");
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
asn_dec_rval_t
ber_check_tags(const asn_codec_ctx_t *opt_codec_ctx,
               const asn_TYPE_descriptor_t *td, asn_struct_ctx_t *opt_ctx,
               const void *ptr, size_t size, int tag_mode, int last_tag_form,
               ber_tlv_len_t *last_length, int *opt_tlv_form) {
    asn_dec_rval_t rv = {0, 0};
    (void)opt_codec_ctx;
    (void)td;
    (void)opt_ctx;
    (void)ptr;
    (void)size;
    (void)tag_mode;
    (void)last_tag_form;
    (void)last_length;
    (void)opt_tlv_form;
    return rv;
}

ssize_t
der_write_tags(const asn_TYPE_descriptor_t *td, size_t slen, int tag_mode,
               int last_tag_form, ber_tlv_tag_t tag,
               asn_app_consume_bytes_f *cb, void *app_key) {
    (void)td;
    (void)slen;
    (void)tag_mode;
    (void)last_tag_form;
    (void)tag;
    (void)cb;
    (void)app_key;
    return -1;
}

asn_dec_rval_t
xer_decode_general(const asn_codec_ctx_t *opt_codec_ctx, asn_struct_ctx_t *ctx,
                   void *struct_key, const char *xml_tag, const void *buf_ptr,
                   size_t size,
                   int (*otd)(void *struct_key, const void *chunk_buf,
                              size_t chunk_size),
                   ssize_t (*br)(void *struct_key, const void *chunk_buf,
                                 size_t chunk_size, int have_more)) {
    asn_dec_rval_t rv = {0, 0};
    (void)opt_codec_ctx;
    (void)ctx;
    (void)struct_key;
    (void)xml_tag;
    (void)buf_ptr;
    (void)size;
    (void)otd;
    (void)br;
    return rv;
}

size_t
xer_whitespace_span(const void *chunk_buf, size_t chunk_size) {
    (void)chunk_buf;
    (void)chunk_size;
    return 0;
}

int
OCTET_STRING_compare(const asn_TYPE_descriptor_t *td, const void *a,
                     const void *b) {
    (void)td;
    (void)a;
    (void)b;
    return 0;
}

intmax_t
asn_random_between(intmax_t a, intmax_t b) {
    (void)b;
    return a;
};

