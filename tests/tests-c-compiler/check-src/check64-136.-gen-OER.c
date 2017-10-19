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
    T_t source;
    T_t *decoded = 0; /* "= 0" is important */

    memset(&source, 0, sizeof(source));

    /* Fill in complex INTEGER */
    asn_long2INTEGER(&source.unsigned33, 0);

    asn_enc_rval_t er =
        oer_encode_to_buffer(&asn_DEF_T, 0, &source, tmpbuf, sizeof(tmpbuf));
    assert(er.encoded != -1);

    asn_dec_rval_t dr =
        oer_decode(0, &asn_DEF_T, (void **)&decoded, tmpbuf, er.encoded);

    assert(dr.code == RC_OK);
    if((ssize_t)dr.consumed != er.encoded) {
        ASN_DEBUG("Consumed %zd, expected %zu", dr.consumed, er.encoded);
        assert((ssize_t)dr.consumed == er.encoded);
    }

    if(XEQ_SUCCESS != xer_equivalent(&asn_DEF_T, &source, decoded, stderr)) {
        return 1;
    }
    ASN_STRUCT_RESET(asn_DEF_T, &source);
    ASN_STRUCT_FREE(asn_DEF_T, decoded);
    return 0;
}

