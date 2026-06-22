#undef NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <UnsuccessfulOutcome.h>

/*
 * Regression test for the open type decoder crashes reported by
 * Seaver Thorn (NCSU).
 *
 * The information object set behind the "value" open type has a row for
 * procedureCode 0 which does NOT define a type, and a row for procedureCode 1
 * which selects FailureB.  Two distinct defects were triggered:
 *
 *   1. Decoding a message whose procedureCode selects the typeless row made
 *      the generated type selector hand back a NULL type descriptor with a
 *      non-zero presence index; the decoder then dereferenced the NULL
 *      descriptor (reported NULL pointer crash).
 *
 *   2. The open type value is carried by a CHOICE that only contains the rows
 *      which define a type.  The selector returned the raw information object
 *      set row number as the presence index, so selecting the typed row
 *      (procedureCode 1, row index 1) indexed element [1] of a one-element
 *      CHOICE -- an out-of-bounds read on a perfectly valid message.
 *
 * After the fix the selector counts only the typed rows, and the decoders
 * reject a discriminant that resolves to no type.
 *
 * Message layout (AUTOMATIC TAGS):
 *   30 07        -- SEQUENCE, length 7
 *   80 01 NN     -- [0] procedureCode = NN
 *   a1 02        -- [1] value (EXPLICIT), length 2
 *   30 00        --   FailureB ::= SEQUENCE {}
 */

/* procedureCode 1 -> selects FailureB: must decode cleanly. */
static const uint8_t valid_code1[] = {
    0x30, 0x07, 0x80, 0x01, 0x01, 0xa1, 0x02, 0x30, 0x00
};

/* procedureCode 0 -> selects a row that defines no type: must fail, not crash. */
static const uint8_t typeless_code0[] = {
    0x30, 0x07, 0x80, 0x01, 0x00, 0xa1, 0x02, 0x30, 0x00
};

#ifdef ENABLE_LIBFUZZER

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    UnsuccessfulOutcome_t *u = NULL;
    ber_decode(0, &asn_DEF_UnsuccessfulOutcome, (void **)&u, Data, Size);
    ASN_STRUCT_FREE(asn_DEF_UnsuccessfulOutcome, u);
    return 0;
}

#else /* !ENABLE_LIBFUZZER */

int main(void) {
    UnsuccessfulOutcome_t *u = NULL;
    asn_dec_rval_t rv;

    /* A valid message which selects the typed row must round-trip. */
    rv = ber_decode(0, &asn_DEF_UnsuccessfulOutcome, (void **)&u,
                    valid_code1, sizeof(valid_code1));
    fprintf(stderr, "valid procedureCode=1: code=%d consumed=%zu\n",
            (int)rv.code, rv.consumed);
    assert(rv.code == RC_OK);
    assert(rv.consumed == sizeof(valid_code1));
    assert(u != NULL);
    assert(u->procedureCode == 1);
    assert(u->value.present == UnsuccessfulOutcome__value_PR_FailureB);
    ASN_STRUCT_FREE(asn_DEF_UnsuccessfulOutcome, u);
    u = NULL;

    /* A discriminant that resolves to no type must fail without crashing. */
    rv = ber_decode(0, &asn_DEF_UnsuccessfulOutcome, (void **)&u,
                    typeless_code0, sizeof(typeless_code0));
    fprintf(stderr, "typeless procedureCode=0: code=%d consumed=%zu\n",
            (int)rv.code, rv.consumed);
    assert(rv.code == RC_FAIL);
    ASN_STRUCT_FREE(asn_DEF_UnsuccessfulOutcome, u);

    printf("OK: open type typeless-row regression test passed.\n");
    return 0;
}

#endif /* ENABLE_LIBFUZZER */
