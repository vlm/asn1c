#include <stdio.h>
#include <assert.h>

#include <asn_codecs.h>
#include <NativeEnumerated.h>

#define CHECK_DECODE(code, a, b, c)    check_decode(__LINE__, code, a, b, c)
#define CHECK_ROUNDTRIP(a) check_roundtrip(__LINE__, a);

static void
check_decode(int lineno, enum asn_dec_rval_code_e code, intmax_t control, const char *buf, size_t size) {
    static char *code_s[] = { "RC_OK", "RC_WMORE", "RC_FAIL", "<error>" };

    fprintf(stderr, "\n%d: OER decode (control %" PRIdMAX ")\n", lineno, control);

    long value;
    long *value_ptr = &value;
    asn_dec_rval_t ret;

    fprintf(stderr, "%d: buf[%zu]={%d, %d, ...}\n", lineno, size,
            size <= 0 ? -1 : ((const uint8_t *)buf)[0],
            size <= 1 ? -1 : ((const uint8_t *)buf)[1]);

    ret = NativeEnumerated_decode_oer(NULL, &asn_DEF_NativeEnumerated, NULL,
                                      (void **)&value_ptr, buf, size);
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
        intmax_t outcome = value;
        if(outcome != control) {
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
check_roundtrip(int lineno, intmax_t control) {
    uint8_t tmpbuf[32];
    size_t tmpbuf_size;

    fprintf(stderr, "\n%d: OER round-trip value %" PRIdMAX "\n", lineno, control);

    asn_enc_rval_t er;
    asn_dec_rval_t ret;

    long value_out = control;
    long value_in = -42;
    long *value_in_ptr = &value_in;

    er = oer_encode_to_buffer(&asn_DEF_NativeEnumerated, NULL,
                              &value_out, tmpbuf, sizeof(tmpbuf));
    if(er.encoded == -1) {
        fprintf(stderr, "%d: OER encode failed for %s\n", lineno,
                er.failed_type ? er.failed_type->name : "<none>");
        assert(er.encoded != -1);
    }
    tmpbuf_size = er.encoded;

    dump_data(lineno, tmpbuf, tmpbuf_size);

    ret = asn_DEF_NativeEnumerated.op->oer_decoder(0, &asn_DEF_NativeEnumerated,
                                                   NULL, (void **)&value_in_ptr,
                                                   tmpbuf, tmpbuf_size);
    if(ret.code != RC_OK) {
        /* Basic OER decode does not work */
        fprintf(stderr, "%d: Failed oer_decode(value=%" PRIdMAX ", size=%zu)\n",
                lineno, control, tmpbuf_size);
        assert(ret.code == 0);
    } else {
        intmax_t outcome = value_in;
        if(outcome != control) {
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

int
main() {
	CHECK_DECODE(RC_WMORE, 0, "", 0);
	CHECK_DECODE(RC_OK, 0, "\x00", 1);
	CHECK_DECODE(RC_FAIL, 0, "\x00", 1);
	CHECK_DECODE(RC_WMORE, 0, "", 0);
	CHECK_DECODE(RC_WMORE, 0, "", 0);
	CHECK_DECODE(RC_OK, 0, "\x00", 1);
	CHECK_DECODE(RC_OK, 0, "\x00", 1);

	CHECK_DECODE(RC_OK, 0, "\x00", 1);
	CHECK_DECODE(RC_OK, 1, "\x01", 1);
	CHECK_DECODE(RC_FAIL, 0, "\xff", 1);
	CHECK_DECODE(RC_FAIL, 0, "\x89", 1);
	CHECK_DECODE(RC_WMORE, 0, "\x84", 1);
	CHECK_DECODE(RC_WMORE, 0, "\x84\x00", 3);
	CHECK_DECODE(RC_WMORE, 0, "\x84\x00\x00", 3);
	CHECK_DECODE(RC_WMORE, 0, "\x84\x00\x00\x00", 4);
	CHECK_DECODE(RC_OK, 0, "\x84\x00\x00\x00\x00", 5);
	CHECK_DECODE(RC_OK, 1, "\x84\x00\x00\x00\x01", 5);
	CHECK_DECODE(RC_OK, 127, "\x7f", 1);
	CHECK_DECODE(RC_OK, 127, "\x81\x7f", 2);
	CHECK_DECODE(RC_OK, 255, "\x82\x00\xff", 3);
	CHECK_DECODE(RC_OK, -1, "\x81\xff", 2);
	CHECK_DECODE(RC_OK, -1, "\x82\xff\xff", 3);

	CHECK_DECODE(RC_OK, 1, "\x01\x00", 2);
	CHECK_DECODE(RC_OK, 1, "\x01\x01", 2);
	CHECK_DECODE(RC_OK, -1, "\x81\xff", 2);
	CHECK_DECODE(RC_WMORE, -1, "\x82\x00\xff", 2);

    CHECK_ROUNDTRIP(0);
    CHECK_ROUNDTRIP(1);
    CHECK_ROUNDTRIP(-1);
    CHECK_ROUNDTRIP(-127);
    CHECK_ROUNDTRIP(-128);
    CHECK_ROUNDTRIP(-129);
    CHECK_ROUNDTRIP(126);
    CHECK_ROUNDTRIP(127);
    CHECK_ROUNDTRIP(128);
    CHECK_ROUNDTRIP(-65000);
    CHECK_ROUNDTRIP(65000);
    CHECK_ROUNDTRIP(65535);
    CHECK_ROUNDTRIP(-65535);
    CHECK_ROUNDTRIP(-65536);
    CHECK_ROUNDTRIP(65536);
    CHECK_ROUNDTRIP(32000);

    for(size_t i = 0; i < 7 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value);
        value = -value;
        CHECK_ROUNDTRIP(value);
    }

    for(size_t i = 0; i < 16 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value);
        value = -value;
        CHECK_ROUNDTRIP(value);
    }

    for(size_t i = 0; i < 32 ; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value);
        value = -value;
        CHECK_ROUNDTRIP(value);
    }

    for(size_t i = 0; i < 8 * sizeof(intmax_t) - 1; i++) {
        intmax_t value = (intmax_t)1 << i;
        CHECK_ROUNDTRIP(value);
        value = -value;
        CHECK_ROUNDTRIP(value);
    }

}
