#include <stdio.h>
#include <assert.h>

#include <asn_application.h>
#include <INTEGER.h>

#define CHECK_DECODE(code, a, b, c, d, e, f)    check_decode(__LINE__, code, a, b, c, d, e, f)
#define CHECK_ROUNDTRIP(a, b, c) check_roundtrip(__LINE__, a, b, c);
#define CHECK_ENCODE_OK(a, b, c) check_encode(__LINE__, 0, a, b, c)
#define CHECK_ENCODE_BAD(a, b, c) check_encode(__LINE__, 1, a, b, c);

static asn_oer_constraints_t *
setup_constraints(unsigned width, unsigned positive) {
    static struct asn_oer_constraints_s empty_constraints;
    asn_oer_constraints_t *constraints = &empty_constraints;
    asn_oer_constraint_number_t *ct_value = &constraints->value;

    memset(&empty_constraints, 0, sizeof(empty_constraints));

    /* Setup integer constraints as requested */
    ct_value->width = width;
    ct_value->positive = positive;

    return constraints;
}

static void
check_decode(int lineno, enum asn_dec_rval_code_e code, intmax_t control, const char *buf, size_t size, const char *dummy, unsigned width, unsigned positive) {
    static char *code_s[] = { "RC_OK", "RC_WMORE", "RC_FAIL", "<error>" };

    fprintf(stderr, "\n%d: OER decode (control %" PRIdMAX ")\n", lineno, control);

    INTEGER_t *st = NULL;
    asn_dec_rval_t ret;
    asn_oer_constraints_t *constraints = setup_constraints(width, positive);

    fprintf(stderr, "%d: buf[%zu]={%d, %d, ...}\n", lineno, size,
            size <= 0 ? -1 : ((const uint8_t *)buf)[0],
            size <= 1 ? -1 : ((const uint8_t *)buf)[1]);

    (void)dummy;

    ret = asn_DEF_INTEGER.op->oer_decoder(0, &asn_DEF_INTEGER, constraints,
                                      (void **)&st, buf, size);
    if(ret.code != RC_OK) {
        /* Basic OER decode does not work */
        fprintf(stderr, "%d: Failed oer_decode(ctl=%" PRIdMAX ", size=%zu)\n",
                lineno, control, size);
        if(ret.code == code) {
            fprintf(stderr, "  (That was expected)\n");
            ASN_STRUCT_FREE(asn_DEF_INTEGER, st);
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
    ASN_STRUCT_FREE(asn_DEF_INTEGER, st);
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
        setup_constraints(lower_bound, upper_bound);

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

    ret = asn_DEF_INTEGER.op->oer_decoder(0, &asn_DEF_INTEGER, constraints,
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
check_encode(int lineno, int bad, intmax_t value, unsigned width, unsigned positive) {
    uint8_t tmpbuf[32];

    fprintf(stderr, "\n%d: OER encode value %" PRIdMAX "\n", lineno, value);

    INTEGER_t *stOut = (INTEGER_t *)calloc(1, sizeof(*stOut));
    asn_enc_rval_t er;
    asn_oer_constraints_t *constraints = setup_constraints(width, positive);

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
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", 0, 0);
	CHECK_DECODE(RC_FAIL, 0, "\x00", 1, "bounds=", 0, 0);
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", 1, 0);
	CHECK_DECODE(RC_WMORE, 0, "", 0, "bounds=", 1, 1);
	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", 1, 1);
	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", 1, 0);

	CHECK_DECODE(RC_OK, 0, "\x00", 1, "bounds=", 1, 0);
	CHECK_DECODE(RC_OK, 1, "\x01", 1, "bounds=", 1, 0);
	CHECK_DECODE(RC_OK, -1, "\xff", 1, "bounds=", 1, 0);
	CHECK_DECODE(RC_OK, -1, "\xff", 1, "bounds=", 1, 0);
	CHECK_DECODE(RC_OK, 127, "\x7f", 1, "bounds=", 1, 1);
	CHECK_DECODE(RC_OK, 255, "\xff", 1, "bounds=", 1, 1);
	CHECK_DECODE(RC_OK, 255, "\xff", 1, "bounds=", 1, 1);
	CHECK_DECODE(RC_WMORE, 0, "\xff", 1, "bounds=", 2, 1);
	CHECK_DECODE(RC_OK, 65535, "\xff\xff", 2, "bounds=", 2, 1);

	CHECK_DECODE(RC_OK, 0, "\x01\x00", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, 1, "\x01\x01", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, -1, "\x1\xff", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, 255, "\x1\xff", 2, "bounds=", 0, 1);
	CHECK_DECODE(RC_WMORE, -1, "\x02\x00\xff", 2, "bounds=", 0, 0);
	CHECK_DECODE(RC_OK, 255, "\x02\x00\xff", 3, "bounds=", 0, 0);

    CHECK_ROUNDTRIP(0, 0, 0);
    CHECK_ROUNDTRIP(1, 0, 0);
    CHECK_ROUNDTRIP(-1, 0, 0);
    CHECK_ROUNDTRIP(-65000, 0, 0);
    CHECK_ROUNDTRIP(65000, 0, 0);
    CHECK_ROUNDTRIP(65535, 0, 0);
    CHECK_ROUNDTRIP(-65535, 0, 0);
    CHECK_ROUNDTRIP(-65536, 0, 0);
    CHECK_ROUNDTRIP(65536, 0, 0);
    CHECK_ROUNDTRIP(0, 1, 0);
    CHECK_ROUNDTRIP(1, 1, 0);
    CHECK_ROUNDTRIP(-1, 1, 0);
    CHECK_ROUNDTRIP(-127, 1, 0);
    CHECK_ROUNDTRIP(-128, 1, 0);
    CHECK_ROUNDTRIP(127, 1, 0);
    CHECK_ROUNDTRIP(1, 2, 1);
    CHECK_ROUNDTRIP(32000, 2, 1);
    CHECK_ROUNDTRIP(32000, 2, 0);
    CHECK_ROUNDTRIP(1, 2, 1);
    CHECK_ROUNDTRIP(65535, 2, 1);
    CHECK_ROUNDTRIP(65535, 4, 0);

    CHECK_ENCODE_OK(0, 1, 1);
    CHECK_ENCODE_OK(255, 1, 1);
    CHECK_ENCODE_BAD(256, 1, 1);
    CHECK_ENCODE_OK(0, 1, 0);
    CHECK_ENCODE_OK(127, 1, 0);
    CHECK_ENCODE_OK(-128, 1, 0);
    CHECK_ENCODE_BAD(-129, 1, 0);
    CHECK_ENCODE_BAD(128, 1, 0);
    CHECK_ENCODE_OK(-4900000000, 8, 0);
    CHECK_ENCODE_OK(4900000000, 8, 0);
    CHECK_ENCODE_OK(-2000000000, 8, 0);
    CHECK_ENCODE_OK(-4000000000, 8, 0);
    CHECK_ENCODE_BAD(-4900000000, 4, 1);
    CHECK_ENCODE_BAD(-1, 0, 4000000000);
    CHECK_ENCODE_BAD(4900000000, 4, 1);
    CHECK_ENCODE_OK(4100000000, 4, 1);

    for(size_t i = 0; i < 7 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 1, 1);
        value = -value;
        CHECK_ROUNDTRIP(value, 1, 0);
    }

    for(size_t i = 0; i < 16 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 2, 1);
        value = -value;
        CHECK_ROUNDTRIP(value, 2, 0);
    }

    for(size_t i = 0; i < 32 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 4, 1);
        value = -value;
        CHECK_ROUNDTRIP(value, 4, 0);
    }

    for(size_t i = 0; i < 8 * sizeof(intmax_t) - 1; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 8, 0);
        value = -value;
        CHECK_ROUNDTRIP(value, 8, 0);
    }

    for(size_t i = 0; i < 8 * sizeof(intmax_t) - 1; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value, 0, 0);
        value = -value;
        CHECK_ROUNDTRIP(value, 0, 0);
    }

}
