#include <stdio.h>
#include <assert.h>

#include <INTEGER.h>
#include <INTEGER.c>
#include <INTEGER_oer.c>

#define CHECK_DECODE_OK(a, b, c)    check_decode_ok(__LINE__, a, b, c)

void
check_decode_ok(int lineno, intmax_t control, char *buf, size_t size) {

    INTEGER_t *st = NULL;
    asn_dec_rval_t ret;

    ret = asn_DEF_INTEGER.oer_decoder(0, &asn_DEF_INTEGER, 0, (void **)&st, buf, size);
    if(ret.code != RC_OK) {
        /* Basic OER decode does not work */
        fprintf(stderr, "%d: Failed oer_decode(ctl=%" PRIdMAX ", size=%zu)\n",
                lineno, control, size);
        assert(ret.code == RC_OK);
    } else {
        intmax_t outcome;
        if(asn_INTEGER2imax(st, &outcome) != 0) {
            /* Result of decode is structurally incorrect */
            fprintf(stderr, "%d: Failed to convert INTEGER 2 imax\n",
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

int
main() {
	CHECK_DECODE_OK(0, "", 1);
}
