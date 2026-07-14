/*
 * Regression test for uper_put_nsnnwn()/uper_put_nslength() (per_support.c).
 *
 * X.691 #11.6 requires the long form (value/length >= 64) to begin with
 * an explicit "1" flag bit before the general length determinant. The
 * old uper_put_nsnnwn() emitted a bare byte-count octet plus the value,
 * with no flag bit at all; the old uper_put_nslength() called
 * uper_put_length() directly for length > 64, also skipping the flag
 * bit. Both bugs make the encoder's own output undecodable by
 * uper_get_nsnnwn()/uper_get_nslength() -- values silently come back
 * wrong instead of failing loudly.
 *
 * This test round-trips put -> get for a range of values that span the
 * short/long-form boundary, and additionally pins down the exact bit
 * pattern the long form must produce, derived by hand from the (correct)
 * uper_get_nsnnwn()/uper_get_nslength() decode logic.
 */
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <asn_application.h>
#include <per_support.h>

/* ------------------------------------------------------------------ */
/* uper_put_nsnnwn() / uper_get_nsnnwn() round trip                    */
/* ------------------------------------------------------------------ */

static void
check_nsnnwn_roundtrip(long n, int expect_fail) {
    asn_per_outp_t po;
    asn_per_data_t pd;
    int ret;
    ssize_t got;
    size_t total_bits;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    ret = uper_put_nsnnwn(&po, (int)n);
    fprintf(stderr, "put_nsnnwn(%ld) => %d\n", n, ret);

    if(expect_fail) {
        assert(ret == -1);
        return;
    }
    assert(ret == 0);

    memset(&pd, 0, sizeof(pd));
    pd.buffer = po.tmpspace;
    pd.nboff = 0;
    /* NOTE: pd.nbits is not a fixed "total length" -- asn_get_few_bits()
     * shrinks it in lockstep with pd.buffer as it normalizes past whole
     * consumed octets (mirroring the encoder side). Save the true total
     * up front and compare uper_get_nsnnwn()'s pd.moved against that,
     * not against the (mutated) post-decode pd.nbits. */
    total_bits = 8 * (po.buffer - po.tmpspace) + po.nboff;
    pd.nbits = total_bits;

    got = uper_get_nsnnwn(&pd);
    fprintf(stderr, "  get_nsnnwn() => %zd (moved %zu of %zu total bits)\n",
            got, pd.moved, total_bits);
    assert(got == n);

    /* The value must be the *only* thing encoded: no leftover bits that
     * would silently bleed into a following field. */
    assert(pd.moved == total_bits);
}

/*
 * Bit-exact check for the long form. Verified against uper_get_nsnnwn()'s
 * decode logic by hand:
 *   1 flag bit "1"
 *   + 8-bit length-determinant octet (short form, #11.9.3.6): byte count
 *     of the value (1 or 2 -- uper_get_nsnnwn() rejects byte counts >= 3)
 *   + that many 8-bit octets of the value, big-endian.
 */
static void
check_nsnnwn_bits(long n, const uint8_t *expected, size_t expected_bytes,
                   size_t expected_bits) {
    asn_per_outp_t po;
    int ret;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    ret = uper_put_nsnnwn(&po, (int)n);
    assert(ret == 0);

    size_t produced_bits = 8 * (po.buffer - po.tmpspace) + po.nboff;
    fprintf(stderr, "bits_nsnnwn(%ld): produced %zu bits, expected %zu\n", n,
            produced_bits, expected_bits);
    assert(produced_bits == expected_bits);

    size_t produced_bytes = (produced_bits + 7) / 8;
    assert(produced_bytes == expected_bytes);
    assert(memcmp(po.tmpspace, expected, expected_bytes) == 0);
}

static void
check_nsnnwn_all(void) {
    /* Short form: n <= 63, 7 bits total, top bit implicitly 0. */
    check_nsnnwn_roundtrip(0, 0);
    check_nsnnwn_roundtrip(1, 0);
    check_nsnnwn_roundtrip(63, 0);

    /* Long form boundary and beyond. */
    check_nsnnwn_roundtrip(64, 0);
    check_nsnnwn_roundtrip(65, 0);
    check_nsnnwn_roundtrip(100, 0);
    check_nsnnwn_roundtrip(255, 0);
    check_nsnnwn_roundtrip(256, 0);
    check_nsnnwn_roundtrip(1000, 0);
    check_nsnnwn_roundtrip(65535, 0);

    /* Beyond what uper_get_nsnnwn() can parse back (byte count >= 3):
     * must fail cleanly rather than emit an unreadable stream. */
    check_nsnnwn_roundtrip(65536, 1);
    check_nsnnwn_roundtrip(1000000, 1);

    check_nsnnwn_roundtrip(-1, 1);

    /*
     * Hand-derived (cross-checked with a Python bit-string simulation of
     * uper_get_nsnnwn()'s decode logic) expected bit patterns for the
     * long form. Trailing pad bits emitted by asn_put_few_bits() are 0.
     *
     * n=64:  flag=1, length-octet=00000001 (1 byte), value=01000000
     *        -> bits: 1 00000001 01000000  (17 bits -> padded to 3 bytes)
     *        -> "10000000" "10100000" "0"+7 pad zeros
     *                0x80       0xA0       0x00
     */
    {
        static const uint8_t expected64[] = {0x80, 0xA0, 0x00};
        check_nsnnwn_bits(64, expected64, sizeof(expected64), 17);
    }
    /*
     * n=65:  flag=1, length-octet=00000001, value=01000001
     *        bits: 1 00000001 01000001  (17 bits)
     *        -> "10000000" "10100000" "1"+7 pad zeros
     *                0x80       0xA0       0x80
     */
    {
        static const uint8_t expected65[] = {0x80, 0xA0, 0x80};
        check_nsnnwn_bits(65, expected65, sizeof(expected65), 17);
    }
    /*
     * n=255: flag=1, length-octet=00000001, value=11111111
     *        bits: 1 00000001 11111111  (17 bits)
     *        -> "10000000" "10111111" "1"+7 pad zeros
     *                0x80       0xFF       0x80
     */
    {
        static const uint8_t expected255[] = {0x80, 0xFF, 0x80};
        check_nsnnwn_bits(255, expected255, sizeof(expected255), 17);
    }
    /*
     * n=256: flag=1, length-octet=00000010 (2 bytes), value=0000000100000000
     *        bits: 1 00000010 0000000100000000  (25 bits -> 4 bytes)
     *        -> 0x81 0x00 0x80 0x00
     */
    {
        static const uint8_t expected256[] = {0x81, 0x00, 0x80, 0x00};
        check_nsnnwn_bits(256, expected256, sizeof(expected256), 25);
    }
}

/* ------------------------------------------------------------------ */
/* uper_put_nslength() / uper_get_nslength() round trip                */
/* ------------------------------------------------------------------ */

static void
check_nslength_roundtrip(size_t length, int expect_fail) {
    asn_per_outp_t po;
    asn_per_data_t pd;
    int ret;
    ssize_t got;
    size_t total_bits;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    ret = uper_put_nslength(&po, length);
    fprintf(stderr, "put_nslength(%zu) => %d\n", length, ret);

    if(expect_fail) {
        assert(ret == -1);
        return;
    }
    assert(ret == 0);

    memset(&pd, 0, sizeof(pd));
    pd.buffer = po.tmpspace;
    pd.nboff = 0;
    /* See check_nsnnwn_roundtrip() for why total_bits must be captured
     * separately from pd.nbits, which mutates during decode. */
    total_bits = 8 * (po.buffer - po.tmpspace) + po.nboff;
    pd.nbits = total_bits;

    got = uper_get_nslength(&pd);
    fprintf(stderr, "  get_nslength() => %zd (moved %zu of %zu total bits)\n",
            got, pd.moved, total_bits);
    assert(got == (ssize_t)length);
    assert(pd.moved == total_bits);
}

static void
check_nslength_bits(size_t length, const uint8_t *expected,
                     size_t expected_bytes, size_t expected_bits) {
    asn_per_outp_t po;
    int ret;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    ret = uper_put_nslength(&po, length);
    assert(ret == 0);

    size_t produced_bits = 8 * (po.buffer - po.tmpspace) + po.nboff;
    fprintf(stderr, "bits_nslength(%zu): produced %zu bits, expected %zu\n",
            length, produced_bits, expected_bits);
    assert(produced_bits == expected_bits);

    size_t produced_bytes = (produced_bits + 7) / 8;
    assert(produced_bytes == expected_bytes);
    assert(memcmp(po.tmpspace, expected, expected_bytes) == 0);
}

static void
check_nslength_all(void) {
    /* nslength lower bound is 1; 0 is invalid. */
    check_nslength_roundtrip(0, 1);

    /* Short form: 1 <= length <= 64, 7 bits total ("0" flag + 6-bit
     * (length-1)). */
    check_nslength_roundtrip(1, 0);
    check_nslength_roundtrip(63, 0);
    check_nslength_roundtrip(64, 0);

    /* Long form: length > 64. */
    check_nslength_roundtrip(65, 0);
    check_nslength_roundtrip(100, 0);
    check_nslength_roundtrip(127, 0);
    check_nslength_roundtrip(128, 0);
    check_nslength_roundtrip(1000, 0);
    check_nslength_roundtrip(16383, 0);

    /* length >= 16384 hits a separate, pre-existing limitation of
     * uper_put_length()/uper_put_nslength(): a single call cannot
     * express a length that would require an end-of-message-marker
     * continuation (uper_put_length() only ever emits one 16K block
     * count per call and the caller here never loops for EOM). This is
     * outside the scope of the #11.6 long-form flag-bit fix -- confirm
     * it still fails cleanly rather than emitting an unreadable stream. */
    check_nslength_roundtrip(16384, 1);

    /*
     * Hand-derived expected bit pattern for length=65:
     * flag "1" + short-form length determinant octet (#11.9.3.6) with
     * value 65: 0_1000001
     * bits: 1 01000001  (9 bits)
     * bytes: 1010_0000  1000_0000
     *         0xA0       0x80
     */
    {
        static const uint8_t expected65[] = {0xA0, 0x80};
        check_nslength_bits(65, expected65, sizeof(expected65), 9);
    }
    /*
     * length=64 (short form, no flag bit involved at all):
     * "0" flag + 6-bit(63) = 0 111111 = 0111111
     * bits: 0111111 (7 bits) -> byte 0111_1110 = 0x7E (padded)
     */
    {
        static const uint8_t expected64[] = {0x7E};
        check_nslength_bits(64, expected64, sizeof(expected64), 7);
    }
}

int
main(void) {
    check_nsnnwn_all();
    check_nslength_all();
    return 0;
}
