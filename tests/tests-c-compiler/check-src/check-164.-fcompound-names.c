#undef NDEBUG
#include <stdio.h>
#include <assert.h>

#include <Message.h>

/*
 * Behavioral regression test for CVE-2025-32893.
 *
 * The companion compilation test (163) checks that the *generated code* forks
 * into two distinct information object tables.  This test compiles spec 164
 * and actually *runs* the generated decoder to prove the forked tables are
 * enforced at decode time.
 *
 * Spec 164 defines two information object sets that bind the SAME &id (1) to
 * DIFFERENT types:
 *
 *     SetA: id 1 -> IntPayload (INTEGER)
 *     SetB: id 1 -> StrPayload (IA5String)
 *
 * Message.second is parameterized by SetB, so its open type at id 1 must
 * decode as an IA5String and reject an INTEGER.  Without the fix,
 * asn1f_parameterization_fork() treats the two parameterizations as identical
 * (asn1p_expr_compare() ignored the VALUESET constraint), `second' silently
 * reuses SetA's table, and the acceptance flips: an INTEGER is accepted at
 * id 1 and the IA5String is rejected.  Either assertion below then fires.
 */

/* Message { first {id 1, INTEGER 42}, second {id 1, IA5String "hi"} } */
static const uint8_t msg_setB_ia5[] = {
    0x30, 0x15, 0xa0, 0x08, 0x80, 0x01, 0x01, 0xa1, 0x03, 0x02, 0x01, 0x2a,
    0xa1, 0x09, 0x80, 0x01, 0x01, 0xa1, 0x04, 0x16, 0x02, 0x68, 0x69
};

/* Same, but second's open type carries INTEGER 42 (valid only under SetA). */
static const uint8_t msg_setB_int[] = {
    0x30, 0x14, 0xa0, 0x08, 0x80, 0x01, 0x01, 0xa1, 0x03, 0x02, 0x01, 0x2a,
    0xa1, 0x08, 0x80, 0x01, 0x01, 0xa1, 0x03, 0x02, 0x01, 0x2a
};

static int
decode_code(const uint8_t *buf, size_t size) {
    Message_t *m = NULL;
    asn_dec_rval_t rv = ber_decode(0, &asn_DEF_Message, (void **)&m, buf, size);
    ASN_STRUCT_FREE(asn_DEF_Message, m);
    return rv.code;
}

int main(void) {
    int code;

    /* SetB binds id 1 to IA5String: the IA5String payload must be accepted. */
    code = decode_code(msg_setB_ia5, sizeof(msg_setB_ia5));
    printf("second = IA5String at id 1: ber_decode -> %d\n", code);
    assert(code == RC_OK);

    /* SetB does NOT bind id 1 to INTEGER: the INTEGER payload must be rejected. */
    code = decode_code(msg_setB_int, sizeof(msg_setB_int));
    printf("second = INTEGER  at id 1: ber_decode -> %d\n", code);
    assert(code != RC_OK);

    printf("OK: open type at id 1 is constrained by SetB (IA5String),"
           " not SetA (INTEGER).\n");
    return 0;
}
