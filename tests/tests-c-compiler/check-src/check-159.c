#undef NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <unistd.h>

#include <MySequence.h>
#include <MySet.h>
#include <MySetOf.h>
#include <MyChoice.h>

/*
 * Regression test for CWE-835: BER indefinite-length decoder infinite loop.
 *
 * A malformed end-of-contents pair (0x00 0xNN where NN != 0) was not caught
 * in constr_CHOICE.c, constr_SEQUENCE.c, constr_SET.c, and constr_SET_OF.c.
 * The CHOICE case spins forever; the others fall through to wrong code paths.
 * All four must return RC_FAIL promptly.
 *
 * Trigger input layout (SEQUENCE example):
 *   30 80       -- SEQUENCE, indefinite length
 *   02 01 42    -- INTEGER 66  (satisfies mandatory field 'a')
 *   00 01       -- malformed EOC: first byte 0, second byte non-zero
 */

#ifdef ENABLE_LIBFUZZER

/*
 * Fuzzer harness: feed arbitrary bytes to all four decoders.
 * With the bug present, the CHOICE decoder hangs on the trigger input;
 * libFuzzer's timeout detection catches it.  After the fix, this harness
 * verifies no hang or crash across the full input space.
 */
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    MySequence_t *seq = NULL;
    MySet_t      *set = NULL;
    MySetOf_t    *setof = NULL;
    MyChoice_t   *ch  = NULL;

    ber_decode(0, &asn_DEF_MySequence, (void **)&seq,   Data, Size);
    ber_decode(0, &asn_DEF_MySet,      (void **)&set,   Data, Size);
    ber_decode(0, &asn_DEF_MySetOf,    (void **)&setof, Data, Size);
    ber_decode(0, &asn_DEF_MyChoice,   (void **)&ch,    Data, Size);

    ASN_STRUCT_FREE(asn_DEF_MySequence, seq);
    ASN_STRUCT_FREE(asn_DEF_MySet,      set);
    ASN_STRUCT_FREE(asn_DEF_MySetOf,    setof);
    ASN_STRUCT_FREE(asn_DEF_MyChoice,   ch);
    return 0;
}

#else  /* !ENABLE_LIBFUZZER */

static void alarm_handler(int sig) {
    (void)sig;
    fprintf(stderr, "FAIL: BER indef-length decoder did not terminate (CWE-835)\n");
    _exit(1);
}

static void
check_fails(asn_TYPE_descriptor_t *td, const uint8_t *buf, size_t len) {
    void *ptr = NULL;
    asn_dec_rval_t r;

    signal(SIGALRM, alarm_handler);
    alarm(5);
    r = ber_decode(0, td, &ptr, buf, len);
    alarm(0);

    fprintf(stderr, "%s malformed EOC: code=%d consumed=%zu (expected RC_FAIL)\n",
            td->name, (int)r.code, r.consumed);
    assert(r.code == RC_FAIL);
    ASN_STRUCT_FREE(*td, ptr);
}

static void
check_ok(asn_TYPE_descriptor_t *td, const uint8_t *buf, size_t len) {
    void *ptr = NULL;
    asn_dec_rval_t r = ber_decode(0, td, &ptr, buf, len);

    fprintf(stderr, "%s well-formed: code=%d consumed=%zu (expected RC_OK)\n",
            td->name, (int)r.code, r.consumed);
    assert(r.code == RC_OK);
    assert(r.consumed == len);
    ASN_STRUCT_FREE(*td, ptr);
}

int main(void) {
    /*
     * Well-formed indefinite-length BER (sanity check).
     *
     * SEQUENCE/SET { INTEGER 66 }:   30/31 80  02 01 42  00 00
     * [0] EXPLICIT CHOICE integer:   a0   80  02 01 42  00 00
     */
    static const uint8_t seq_ok[]    = { 0x30,0x80, 0x02,0x01,0x42, 0x00,0x00 };
    static const uint8_t set_ok[]    = { 0x31,0x80, 0x02,0x01,0x42, 0x00,0x00 };
    static const uint8_t setof_ok[]  = { 0x31,0x80, 0x02,0x01,0x42, 0x00,0x00 };
    static const uint8_t choice_ok[] = { 0xa0,0x80, 0x02,0x01,0x42, 0x00,0x00 };

    /*
     * Malformed: 0x00 0x01 instead of 0x00 0x00 as end-of-contents.
     * Each decoder must return RC_FAIL and must not loop indefinitely.
     */
    static const uint8_t seq_bad[]    = { 0x30,0x80, 0x02,0x01,0x42, 0x00,0x01 };
    static const uint8_t set_bad[]    = { 0x31,0x80, 0x02,0x01,0x42, 0x00,0x01 };
    static const uint8_t setof_bad[]  = { 0x31,0x80, 0x02,0x01,0x42, 0x00,0x01 };
    static const uint8_t choice_bad[] = { 0xa0,0x80, 0x02,0x01,0x42, 0x00,0x01 };

    check_ok(&asn_DEF_MySequence, seq_ok,    sizeof(seq_ok));
    check_ok(&asn_DEF_MySet,      set_ok,    sizeof(set_ok));
    check_ok(&asn_DEF_MySetOf,    setof_ok,  sizeof(setof_ok));
    check_ok(&asn_DEF_MyChoice,   choice_ok, sizeof(choice_ok));

    check_fails(&asn_DEF_MySequence, seq_bad,    sizeof(seq_bad));
    check_fails(&asn_DEF_MySet,      set_bad,    sizeof(set_bad));
    check_fails(&asn_DEF_MySetOf,    setof_bad,  sizeof(setof_bad));
    check_fails(&asn_DEF_MyChoice,   choice_bad, sizeof(choice_bad));

    printf("All CWE-835 regression tests passed.\n");
    return 0;
}

#endif /* ENABLE_LIBFUZZER */
