/*
 * Verify OER with constrained and unconstrained strings.
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

    OCTET_STRING_fromBuf(&source.unconstrained.unc_ia5, "foo", 3);
    OCTET_STRING_fromBuf(&source.unconstrained.unc_utf8, "bar-whatever", 12);
    OCTET_STRING_fromBuf(&source.unconstrained.unc_universal,
                         "\0\0\0b\0\0\0a\0\0\0z", 12);

    OCTET_STRING_fromBuf(&source.constrained.con_ia5, "ab", 2);
    OCTET_STRING_fromBuf(&source.constrained.con_utf8, "cd-whatever", 11);
    OCTET_STRING_fromBuf(&source.constrained.con_universal, "\0\0\0e\0\0\0f",
                         8);

    asn_enc_rval_t er =
        oer_encode_to_buffer(&asn_DEF_T, 0, &source, tmpbuf, sizeof(tmpbuf));
    assert(er.encoded != -1);

    asn_dec_rval_t dr =
        oer_decode(0, &asn_DEF_T, (void **)&decoded, tmpbuf, er.encoded);

    assert(dr.code == RC_OK);
    if(dr.consumed != er.encoded) {
        ASN_DEBUG("Consumed %zu, expected %zu", dr.consumed, er.encoded);
        assert(dr.consumed == er.encoded);
    }

    if(XEQ_SUCCESS != xer_equivalent(&asn_DEF_T, &source, decoded, stderr)) {
        return 1;
    }

    return 0;
}

