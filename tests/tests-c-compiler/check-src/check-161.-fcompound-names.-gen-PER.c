#undef NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <UnsuccessfulOutcome.h>

/*
 * uPER counterpart of check-161: the same open type typeless-row defects are
 * reachable through OPEN_TYPE_uper_get / uper_open_type_get.
 *
 *   1. A discriminant selecting the typeless row (procedureCode 0) used to
 *      reach uper_open_type_get() with a NULL type descriptor and dereference
 *      it (td->op->uper_decoder).
 *   2. A discriminant selecting the later, typed row (procedureCode 1) used to
 *      index past the open type CHOICE elements array.
 *
 * Rather than hardcode a bitstream, encode a valid value and decode it back
 * (covering defect 2), then flip the procedureCode octet to 0 and decode that
 * (covering defect 1).
 */

int main(void) {
    UnsuccessfulOutcome_t u;
    UnsuccessfulOutcome_t *d = NULL;
    uint8_t buf[32];
    asn_enc_rval_t er;
    asn_dec_rval_t rv;
    size_t nbytes;

    memset(&u, 0, sizeof(u));
    u.procedureCode = 1;
    u.value.present = UnsuccessfulOutcome__value_PR_FailureB;

    er = uper_encode_to_buffer(&asn_DEF_UnsuccessfulOutcome, 0, &u, buf, sizeof(buf));
    assert(er.encoded > 0);
    nbytes = (er.encoded + 7) / 8;
    fprintf(stderr, "uPER encoded %zd bits (%zu bytes)\n", er.encoded, nbytes);

    /* Defect 2: valid value selecting the typed row must round-trip. */
    rv = uper_decode_complete(0, &asn_DEF_UnsuccessfulOutcome, (void **)&d,
                              buf, nbytes);
    fprintf(stderr, "valid procedureCode=1: code=%d\n", (int)rv.code);
    assert(rv.code == RC_OK);
    assert(d->procedureCode == 1);
    assert(d->value.present == UnsuccessfulOutcome__value_PR_FailureB);
    ASN_STRUCT_FREE(asn_DEF_UnsuccessfulOutcome, d);
    d = NULL;

    /*
     * Defect 1: the procedureCode is an unconstrained INTEGER encoded as
     * length octet (0x01) followed by the value octet; flipping that value
     * octet to 0 selects the typeless row. It must fail, not crash.
     */
    assert(nbytes >= 2);
    assert(buf[0] == 0x01 && buf[1] == 0x01);
    buf[1] = 0x00;
    rv = uper_decode_complete(0, &asn_DEF_UnsuccessfulOutcome, (void **)&d,
                              buf, nbytes);
    fprintf(stderr, "typeless procedureCode=0: code=%d\n", (int)rv.code);
    assert(rv.code == RC_FAIL);
    ASN_STRUCT_FREE(asn_DEF_UnsuccessfulOutcome, d);

    printf("OK: uPER open type typeless-row regression test passed.\n");
    return 0;
}
