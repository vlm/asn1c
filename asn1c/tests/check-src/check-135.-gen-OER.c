/*
 * Verify OER with constrained INTEGER code gen.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <T.h>

int main() {
    uint8_t tmpbuf[128];
	T_t empty_t;
	T_t *decoded_t = 0; /* "= 0" is important */

    memset(&empty_t, 0, sizeof(empty_t));

    /* Fill in complex INTEGER */
    asn_long2INTEGER(&empty_t.unsigned33, 0);

    asn_enc_rval_t er =
        oer_encode_to_buffer(&asn_DEF_T, 0, &empty_t, tmpbuf, sizeof(tmpbuf));
    assert(er.encoded != -1);

    asn_dec_rval_t dr =
        oer_decode(0, &asn_DEF_T, (void **)&decoded_t, tmpbuf, er.encoded);

    assert(dr.code == RC_OK);
    if(dr.consumed != er.encoded) {
        ASN_DEBUG("Consumed %zu, expected %zu", dr.consumed, er.encoded);
        assert(dr.consumed == er.encoded);
    }

    fprintf(stderr, "Original:\n");
    xer_fprint(stderr, &asn_DEF_T, &empty_t);
    fprintf(stderr, "Decoded:\n");
    xer_fprint(stderr, &asn_DEF_T, decoded_t);

    return 0;
}

