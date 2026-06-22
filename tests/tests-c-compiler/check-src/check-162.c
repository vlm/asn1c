#undef NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <T.h>

/*
 * libFuzzer harness for the open type / Information Object Class decoder
 * defects (NULL type descriptor dereference on a typeless discriminant, and
 * out-of-bounds indexing of the open type CHOICE for a later defined row).
 *
 * Unlike the deterministic regression test (check-161), this harness has no
 * knowledge of the triggering input: it simply hands arbitrary bytes to the
 * decoder.  Fuzzing it discovers both defects within seconds on unpatched
 * code, and stays clean once the open type selector / decoders are fixed.
 *
 * It is also why these defects escaped the existing fuzz suite: the randomized
 * round-trip harness (tests-randomized) drives types through random_fill,
 * which is a NULL operation for open types, so an open type can never reach
 * the fuzzing stage there.
 */

static void
decode_once(const uint8_t *Data, size_t Size) {
    T_t *t = NULL;
    (void)ber_decode(0, &asn_DEF_T, (void **)&t, Data, Size);
    ASN_STRUCT_FREE(asn_DEF_T, t);
}

#ifdef ENABLE_LIBFUZZER

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);

int
LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    decode_once(Data, Size);
    return 0;
}

#else /* !ENABLE_LIBFUZZER */

/*
 * Without libFuzzer, replay a tiny built-in corpus through the same entry
 * point.  It includes a value whose discriminant (id 0) selects the typeless
 * row and a value whose discriminant (id 1) selects the later, defined row;
 * both crash unpatched code and decode cleanly once fixed.  No assertion on
 * the decode result is needed: the bug manifests as a crash / sanitizer abort.
 *
 *   30 LL  80 01 ID  a1 LL <inner>      -- SEQUENCE { [0] id, [1] value }
 */
int main(void) {
    /* id 0 -> typeless row: NULL type descriptor dereference. */
    static const uint8_t typeless[] = {
        0x30, 0x07, 0x80, 0x01, 0x00, 0xa1, 0x02, 0x30, 0x00
    };
    /* id 1 -> defined row Payload (BOOLEAN), valid encoding. */
    static const uint8_t defined[] = {
        0x30, 0x08, 0x80, 0x01, 0x01, 0xa1, 0x03, 0x01, 0x01, 0xff
    };
    /*
     * id 1 -> defined row, but the inner value is truncated so its decode
     * fails: the failure-cleanup path used the *variant* type descriptor's
     * (NULL) specifics to size the reset of the open type CHOICE.
     */
    static const uint8_t truncated[] = {
        0x30, 0x80, 0x80, 0x01, 0x01, 0x81
    };

    decode_once(typeless, sizeof(typeless));
    decode_once(defined, sizeof(defined));
    decode_once(truncated, sizeof(truncated));

    printf("OK: open type IOC fuzz seeds decoded without crashing.\n");
    return 0;
}

#endif /* ENABLE_LIBFUZZER */
