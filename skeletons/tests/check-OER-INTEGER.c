#include <stdio.h>
#include <assert.h>

#include <asn_codecs.h>
#include <INTEGER.h>

#define CHECK_DECODE(code, a, b, c, d, e, f)    check_decode(__LINE__, code, a, b, c, d, e, f)
#define CHECK_ROUNDTRIP(a, b, c) check_roundtrip(__LINE__, a, b, c);
#define CHECK_ENCODE_OK(a, b, c) check_encode(__LINE__, 0, a, b, c)
#define CHECK_ENCODE_BAD(a, b, c) check_encode(__LINE__, 1, a, b, c);

static const intmax_t NoBound = -4200024;

static asn_oer_constraints_t *
setup_constraints(int lineno, const char *process, intmax_t lower_bound,
                  intmax_t upper_bound) {
    static struct asn_oer_constraints_s empty_constraints;
    struct asn_oer_constraints_s *constraints = &empty_constraints;
    struct asn_oer_constraint_s *ct_value = &constraints->value;

    memset(&empty_constraints, 0, sizeof(empty_constraints));

    /* Setup integer constraints as requested */
    if(lower_bound == NoBound && upper_bound == NoBound) {
        fprintf(stderr, "%d: OER %s without constraints\n", lineno,
                process);
        constraints = NULL;
    } else {
        if(lower_bound != NoBound) {
            ct_value->flags |= AOC_HAS_LOWER_BOUND;
            ct_value->lower_bound = lower_bound;
        }
        if(upper_bound != NoBound) {
            ct_value->flags |= AOC_HAS_UPPER_BOUND;
            ct_value->upper_bound = upper_bound;
        }
        if(lower_bound != NoBound && upper_bound != NoBound) {
            fprintf(stderr,
                    "%d: OER %s constraints %" PRIdMAX
                    "..%" PRIdMAX "\n",
                    lineno, process, lower_bound, upper_bound);
        } else if(lower_bound != NoBound) {
            fprintf(stderr,
                    "%d: OER %s constraints %" PRIdMAX
                    "..MAX\n",
                    lineno, process, lower_bound);
        } else if(upper_bound != NoBound) {
            fprintf(stderr,
                    "%d: OER %s constraints MIN..%" PRIdMAX "\n",
                    lineno, process, upper_bound);
        }
    }

    return constraints;
}

static void
check_decode(int lineno, enum asn_dec_rval_code_e code, intmax_t control, const char *buf, size_t size, const char *dummy, intmax_t lower_bound, intmax_t upper_bound) {
    static char *code_s[] = { "RC_OK", "RC_WMORE", "RC_FAIL", "<error>" };

    fprintf(stderr, "\n%d: OER decode (control %" PRIdMAX ")\n", lineno, control);

    INTEGER_t *st = NULL;
    asn_dec_rval_t ret;
    asn_oer_constraints_t *constraints =
        setup_constraints(lineno, "decoding", lower_bound, upper_bound);

    fprintf(stderr, "%d: buf[%zu]={%d, %d, ...}\n", lineno, size,
            ((const uint8_t *)buf)[0],
            ((const uint8_t *)buf)[1]);

    (void)dummy;

    ret = asn_DEF_INTEGER.oer_decoder(0, &asn_DEF_INTEGER, constraints,
                                      (void **)&st, buf, size);
    if(ret.code != RC_OK) {
        /* Basic OER decode does not work */
        fprintf(stderr, "%d: Failed oer_decode(ctl=%" PRIdMAX ", size=%zu)\n",
                lineno, control, size);
        if(ret.code == code) {
            fprintf(stderr, "  (That was expected)\n");
            return;
        } else {
            fprintf(
                stderr, "  Unexpected return code %s (%d) expected %s\n",
                code_s[(unsigned)ret.code <= RC_FAIL ? RC_FAIL : (RC_FAIL + 1)],
                (int)ret.code, code_s[code]);
            assert(ret.code == code);
        }
    } else {
        intmax_t outcome;
        if(asn_INTEGER2imax(st, &outcome) != 0) {
            /* Result of decode is structurally incorrect */
            fprintf(stderr,
                    "%d: Failed to convert INTEGER 2 imax; structurally "
                    "incorrect INTEGER\n",
                    lineno);
            assert(!"Unreachable");
        } else if(outcome != control) {
            /* Decoded value is wrong */
            fprintf(stderr,
                    "%d: Decode result %" PRIdMAX " is not expected %" PRIdMAX
                    "\n",
                    lineno, outcome, control);
            assert(outcome == control);
        }
    }

    fprintf(stderr, "%d: Decode result %" PRIdMAX "\n", lineno, control);
}

static void
dump_data(int lineno, const uint8_t *buf, size_t size) {
    const uint8_t *p = buf;
    const uint8_t *end = buf + size;

    fprintf(stderr, "%d: Encoded: [", lineno);

    for(; p < end; p++) {
        fprintf(stderr, "\\x%02x", *(const unsigned char *)p);
    }
    fprintf(stderr, "] (%zu bytes)\n", size);
}

static void
check_roundtrip(int lineno, intmax_t value, intmax_t lower_bound, intmax_t upper_bound) {
    uint8_t tmpbuf[32];
    size_t tmpbuf_size;

    fprintf(stderr, "\n%d: OER round-trip value %" PRIdMAX "\n", lineno, value);

    INTEGER_t *stOut = (INTEGER_t *)calloc(1, sizeof(*stOut));
    INTEGER_t *stIn = NULL;
    asn_enc_rval_t er;
    asn_dec_rval_t ret;
    asn_oer_constraints_t *constraints =
        setup_constraints(lineno, "encoding", lower_bound, upper_bound);

    if(asn_imax2INTEGER(stOut, value) == -1) {
        assert(!"Unreachable imax2INTEGER failure");
    } else {
        assert(stOut->buf != NULL);
        assert(stOut->size != 0);
    }

    er = oer_encode_to_buffer(&asn_DEF_INTEGER, constraints, stOut, tmpbuf,
                              sizeof(tmpbuf));
    if(er.encoded == -1) {
        fprintf(stderr, "%d: OER encode failed for %s\n", lineno,
                er.failed_type ? er.failed_type->name : "<none>");
        assert(er.encoded != -1);
    }
    tmpbuf_size = er.encoded;
    ASN_STRUCT_FREE(asn_DEF_INTEGER, stOut);

    dump_data(lineno, tmpbuf, tmpbuf_size);

    ret = asn_DEF_INTEGER.oer_decoder(0, &asn_DEF_INTEGER, constraints,
                                      (void **)&stIn, tmpbuf, tmpbuf_size);
    if(ret.code != RC_OK) {
        /* Basic OER decode does not work */
        fprintf(stderr, "%d: Failed oer_decode(value=%" PRIdMAX ", size=%zu)\n",
                lineno, value, tmpbuf_size);
        assert(ret.code == 0);
    } else {
        intmax_t outcome;
        if(asn_INTEGER2imax(stIn, &outcome) != 0) {
            /* Result of decode is structurally incorrect */
            fprintf(stderr,
                    "%d: Failed to convert INTEGER 2 imax; structurally "
                    "incorrect INTEGER\n",
                    lineno);
            assert(!"Unreachable");
        } else if(outcome != value) {
            /* Decoded value is wrong */
            fprintf(stderr,
                    "%d: Decode result %" PRIdMAX " is not expected %" PRIdMAX
                    "\n",
                    lineno, outcome, value);
            assert(outcome == value);
        }
    }

    ASN_STRUCT_FREE(asn_DEF_INTEGER, stIn);
    fprintf(stderr, "%d: Decode result %" PRIdMAX "\n", lineno, value);
}

static void
check_encode(int lineno, int bad, intmax_t value, intmax_t lower_bound, intmax_t upper_bound) {
    uint8_t tmpbuf[32];

    fprintf(stderr, "\n%d: OER encode value %" PRIdMAX "\n", lineno, value);

    INTEGER_t *stOut = (INTEGER_t *)calloc(1, sizeof(*stOut));
    asn_enc_rval_t er;
    asn_oer_constraints_t *constraints =
        setup_constraints(lineno, "encoding", lower_bound, upper_bound);

    if(asn_imax2INTEGER(stOut, value) == -1) {
        assert(!"Unreachable imax2INTEGER failure");
    } else {
        assert(stOut->buf != NULL);
        assert(stOut->size != 0);
    }

    er = oer_encode_to_buffer(&asn_DEF_INTEGER, constraints, stOut, tmpbuf,
                              sizeof(tmpbuf));
    if(er.encoded == -1) {
        fprintf(stderr, "%d: OER encode failed for %s%s\n", lineno,
                er.failed_type ? er.failed_type->name : "<none>",
                bad ? " (expected)" : "");
        if(!bad) {
            assert(er.encoded != -1);
        }
    } else {
        dump_data(lineno, tmpbuf, er.encoded);
        if(bad) {
            assert(er.encoded == -1);
        }
    }
    ASN_STRUCT_FREE(asn_DEF_INTEGER, stOut);
}

int
main() {
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", NoBound, NoBound);
	CHECK_DECODE(RC_FAIL, 0, "\x00", 1, "bounds=", NoBound, NoBound);
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", 0, 0);
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", 0, 1);
	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", 0, 1);
	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", -1, 1);

	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", -1, 1);
	CHECK_DECODE(RC_OK, 1, "\x01", 1, "bounds=", -1, 1);
	CHECK_DECODE(RC_OK, -1, "\xff", 1, "bounds=", -1, 1);
	CHECK_DECODE(RC_OK, -1, "\xff", 1, "bounds=", -1, 1);
	CHECK_DECODE(RC_OK, 127, "\x7f", 1, "bounds=", 0, 127);
	CHECK_DECODE(RC_OK, 255, "\xff", 1, "bounds=", 0, 127);
	CHECK_DECODE(RC_OK, 255, "\xff", 1, "bounds=", 0, 255);
	CHECK_DECODE(RC_WMORE, 0, "\xff", 1, "bounds=", 0, 256);
	CHECK_DECODE(RC_OK, 65535, "\xff\xff", 2, "bounds=", 0, 256);

	CHECK_DECODE(RC_OK, 0, "\x01\x00", 2, "bounds=", NoBound, 1);
	CHECK_DECODE(RC_OK, 1, "\x01\x01", 2, "bounds=", NoBound, 1);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", NoBound, 1);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", NoBound, 1);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", NoBound, 255);
	CHECK_DECODE(RC_WMORE, -1, "\x02\x00\xff", 2, "bounds=", NoBound, 200);
	CHECK_DECODE(RC_OK, 255, "\x02\x00\xff", 3, "bounds=", NoBound, 200);

    CHECK_ROUNDTRIP(0, NoBound, NoBound);
    CHECK_ROUNDTRIP(1, NoBound, NoBound);
    CHECK_ROUNDTRIP(-1, NoBound, NoBound);
    CHECK_ROUNDTRIP(-65000, NoBound, NoBound);
    CHECK_ROUNDTRIP(65000, NoBound, NoBound);
    CHECK_ROUNDTRIP(65535, NoBound, NoBound);
    CHECK_ROUNDTRIP(-65535, NoBound, NoBound);
    CHECK_ROUNDTRIP(-65536, NoBound, NoBound);
    CHECK_ROUNDTRIP(65536, NoBound, NoBound);
    CHECK_ROUNDTRIP(0, -128, 127);
    CHECK_ROUNDTRIP(1, -128, 127);
    CHECK_ROUNDTRIP(-1, -128, 127);
    CHECK_ROUNDTRIP(-127, -128, 127);
    CHECK_ROUNDTRIP(-128, -128, 127);
    CHECK_ROUNDTRIP(127, -128, 127);
    CHECK_ROUNDTRIP(1, 32000, 32000);   /* Sic! */
    CHECK_ROUNDTRIP(32000, 0, 32000);  /* Sic! */
    CHECK_ROUNDTRIP(32000, -32000, 32000);  /* Sic! */
    CHECK_ROUNDTRIP(1, 65000, 65000);   /* Sic! */
    CHECK_ROUNDTRIP(65535, 0, 65000);  /* Sic! */
    CHECK_ROUNDTRIP(65535, -65000, 65000);  /* Sic! */

    CHECK_ENCODE_OK(0, 0, 255);
    CHECK_ENCODE_OK(255, 0, 255);
    CHECK_ENCODE_BAD(256, 0, 255);
    CHECK_ENCODE_OK(0, -128, 127);
    CHECK_ENCODE_OK(127, -128, 127);
    CHECK_ENCODE_OK(-128, -128, 127);
    CHECK_ENCODE_BAD(-129, -128, 127);
    CHECK_ENCODE_BAD(128, -128, 127);
    CHECK_ENCODE_OK(-4900000000, -5000000000, 5000000000);
    CHECK_ENCODE_OK(4900000000, -5000000000, 5000000000);
    CHECK_ENCODE_OK(-2000000000, -4000000000, 0);
    CHECK_ENCODE_OK(-4000000000, -4000000000, 0);
    CHECK_ENCODE_BAD(-4900000000, 0, 4000000000);
    CHECK_ENCODE_BAD(-1, 0, 4000000000);
    CHECK_ENCODE_BAD(4900000000, 0, 4000000000);
    CHECK_ENCODE_OK(4100000000, 0, 4000000000); /* Sic! */

    for(size_t i = 0; i < 7 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 0, 255);
        value = -value;
        CHECK_ROUNDTRIP(value, -128, 127);
    }

    for(size_t i = 0; i < 16 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 0, 65535);
        value = -value;
        CHECK_ROUNDTRIP(value, -32768, 32767);
    }

    for(size_t i = 0; i < 32 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 0, 4294967296UL);
        value = -value;
        CHECK_ROUNDTRIP(value, -2147483648L, 2147483647L);
    }

    for(size_t i = 0; i < 8 * sizeof(intmax_t) ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, NoBound, NoBound);
        value = -value;
        CHECK_ROUNDTRIP(value, NoBound, NoBound);
    }

}
