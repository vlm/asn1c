/*
 * Verify OER forward compatibility with extension additions.
 *
 * A decoder built from the v1 module (170-oer-ext-skip-OK.asn1) is fed
 * byte streams produced by v2/v3 peers whose types carry extension
 * additions unknown to v1:
 *
 *   v2:  Inner ::= SEQUENCE { x INTEGER(0..255), ..., y INTEGER(0..255) }
 *   v3:  Inner ::= SEQUENCE { x INTEGER(0..255), ...,
 *                             y INTEGER(0..255), z INTEGER(0..255) }
 *   v2:  C ::= CHOICE { c1 INTEGER(0..255), ..., c2 INTEGER(0..255) }
 *
 * Issue #14: oer_open_type_skip() only skipped the open type length
 * determinant, not the contents, so every unknown extension addition
 * silently shifted all subsequent fields of the enclosing SEQUENCE.
 * Issue #15: an unknown CHOICE extension alternative failed the whole
 * PDU with RC_FAIL instead of being skipped.
 *
 * All golden byte vectors below were produced by a commercial ASN.1
 * toolchain's (the project's interoperability reference) OER codec from
 * the v2/v3 modules, and independently cross-checked with asn1tools
 * (Python); both tools emit identical bytes.  The reference toolchain's
 * v1 decoder gracefully
 * skips every one of these streams (M: a=1 x=2 b=4; MC: pre=1
 * choice=<none> post=4), which is the contract asserted here.
 * The per-byte derivation is documented next to each vector.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <M.h>
#include <MC.h>
#include <C.h>

/*
 * v2 encoding of M {a 1, inner {x 2, y 3}, b 4}:
 *   01           a = 1
 *   80           Inner preamble: extension bit set
 *   02           x = 2
 *   02 07 80     extension presence bitmap: length 2, 7 unused bits,
 *                bit 1 (y) present
 *   01 03        open type: length 1, contents y = 3
 *   04           b = 4
 */
static const uint8_t v2_seq[] = {
    0x01, 0x80, 0x02, 0x02, 0x07, 0x80, 0x01, 0x03, 0x04
};

/*
 * v3 encoding of M {a 1, inner {x 2, y 3, z 5}, b 4}:
 *   01           a = 1
 *   80           Inner preamble: extension bit set
 *   02           x = 2
 *   02 06 C0     extension presence bitmap: length 2, 6 unused bits,
 *                bits 1..2 (y, z) present
 *   01 03        open type: length 1, contents y = 3
 *   01 05        open type: length 1, contents z = 5
 *   04           b = 4
 * Exercises consecutive unknown open types: with #14 unfixed, the first
 * skipped content byte (03) is misread as the next length determinant.
 */
static const uint8_t v3_seq[] = {
    0x01, 0x80, 0x02, 0x02, 0x06, 0xC0, 0x01, 0x03, 0x01, 0x05, 0x04
};

/*
 * v2 encoding of C: c2 5 (extracted from the reference-toolchain-encoded MC below;
 * a lone CHOICE PDU is encoded identically):
 *   81           tag [1] (context class, automatic tag of c2)
 *   01 05        open type: length 1, contents c2 = 5
 */
static const uint8_t v2_choice[] = { 0x81, 0x01, 0x05 };

/*
 * v2 encoding of MC {pre 1, c c2 : 5, post 4}:
 *   01           pre = 1
 *   81 01 05     c (see v2_choice above)
 *   04           post = 4
 */
static const uint8_t v2_mc[] = { 0x01, 0x81, 0x01, 0x05, 0x04 };

/*
 * v1 encodings (root alternatives only), as emitted by the reference
 * toolchain from the very same v1 module this test is compiled from;
 * pins down the encode-side interoperability so the reference toolchain
 * can decode what asn1c emits.
 *   M {a 1, inner {x 2}, b 4}:   01 00 02 04
 *                                (00 = Inner preamble, no extensions)
 *   MC {pre 1, c c1 : 7, post 4}: 01 80 07 04 (80 = tag [0] of c1)
 */
static const uint8_t v1_seq[] = { 0x01, 0x00, 0x02, 0x04 };
static const uint8_t v1_mc[] = { 0x01, 0x80, 0x07, 0x04 };

/*
 * ASN__STACK_OVERFLOW_CHECK() estimates stack depth from the address
 * spread between nested stack frames; under ASan's fake-stack frame
 * allocation that spread can spuriously exceed ASN__DEFAULT_STACK_MAX
 * (30000) after only a couple of calls. Passing a codec context with
 * max_stack_size == 0 disables the check entirely (per its own guard),
 * so the assertions below test the codec logic rather than the
 * environment-dependent stack estimate.
 */
static asn_codec_ctx_t s_no_stack_limit; /* zero-initialized */

static int
consume_bytes_dropper(const void *data, size_t size, void *app_key) {
    (void)data; (void)size; (void)app_key;
    return 0;
}

/* Unknown SEQUENCE extension addition is skipped; b is not shifted. */
static void
check_seq_skip(void) {
    M_t *m = 0;
    asn_dec_rval_t dr =
        oer_decode(&s_no_stack_limit, &asn_DEF_M, (void **)&m, v2_seq, sizeof(v2_seq));

    fprintf(stderr, "SEQ skip: code=%d consumed=%zu\n", dr.code, dr.consumed);
    assert(dr.code == RC_OK);
    fprintf(stderr, "SEQ skip: a=%ld x=%ld b=%ld\n", m->a, m->inner.x, m->b);
    assert(dr.consumed == sizeof(v2_seq));
    assert(m->a == 1);
    assert(m->inner.x == 2);
    assert(m->b == 4);  /* Unfixed #14 misdecodes b as 3 (the y payload) */

    ASN_STRUCT_FREE(asn_DEF_M, m);
}

/* Two consecutive unknown extension additions are both skipped. */
static void
check_seq_skip_two_extensions(void) {
    M_t *m = 0;
    asn_dec_rval_t dr =
        oer_decode(&s_no_stack_limit, &asn_DEF_M, (void **)&m, v3_seq, sizeof(v3_seq));

    fprintf(stderr, "SEQ skip x2: code=%d consumed=%zu\n",
            dr.code, dr.consumed);
    assert(dr.code == RC_OK);
    fprintf(stderr, "SEQ skip x2: a=%ld x=%ld b=%ld\n",
            m->a, m->inner.x, m->b);
    assert(dr.consumed == sizeof(v3_seq));
    assert(m->a == 1);
    assert(m->inner.x == 2);
    assert(m->b == 4);

    ASN_STRUCT_FREE(asn_DEF_M, m);
}

/*
 * Input truncated inside the open type contents must starve (RC_WMORE),
 * never read out of bounds or misdecode trailing fields.
 * The 7-byte prefix of v2_seq ends right after the open type length
 * determinant (01) with the announced content byte missing.
 */
static void
check_seq_truncated(void) {
    size_t cut;

    for(cut = 7; cut < sizeof(v2_seq); cut++) {
        /* Copy into an exactly-sized heap buffer so ASAN/valgrind would
         * catch any read past the truncation point. */
        uint8_t *buf = malloc(cut);
        M_t *m = 0;
        asn_dec_rval_t dr;

        assert(buf);
        memcpy(buf, v2_seq, cut);
        dr = oer_decode(&s_no_stack_limit, &asn_DEF_M, (void **)&m, buf, cut);

        fprintf(stderr, "SEQ truncated at %zu: code=%d consumed=%zu\n",
                cut, dr.code, dr.consumed);
        assert(dr.code == RC_WMORE);
        /* The SEQUENCE decoder reports partial progress on RC_WMORE
         * (its saved context supports resuming mid-PDU), but it must
         * never claim to have consumed more than it was given. */
        assert(dr.consumed <= cut);

        ASN_STRUCT_FREE(asn_DEF_M, m);
        free(buf);
    }
}

/* Unknown CHOICE extension alternative: RC_OK, nothing selected. */
static void
check_choice_skip(void) {
    C_t *c = 0;
    asn_enc_rval_t er;
    asn_dec_rval_t dr =
        oer_decode(&s_no_stack_limit, &asn_DEF_C, (void **)&c, v2_choice, sizeof(v2_choice));

    fprintf(stderr, "CHOICE skip: code=%d consumed=%zu\n",
            dr.code, dr.consumed);
    assert(dr.code == RC_OK);  /* Unfixed #15 returns RC_FAIL */
    fprintf(stderr, "CHOICE skip: present=%d\n", (int)c->present);
    assert(dr.consumed == sizeof(v2_choice));
    assert(c->present == C_PR_NOTHING);

    /* Re-encoding an unknown alternative is unsupported and must fail
     * cleanly (no crash, no bytes emitted as if it were valid). */
    er = oer_encode(&asn_DEF_C, c, consume_bytes_dropper, 0);
    fprintf(stderr, "CHOICE re-encode: encoded=%zd\n", er.encoded);
    assert(er.encoded == -1);

    ASN_STRUCT_FREE(asn_DEF_C, c);
}

/* Fields following an unknown CHOICE alternative are still recovered. */
static void
check_choice_skip_nested(void) {
    MC_t *mc = 0;
    asn_dec_rval_t dr =
        oer_decode(&s_no_stack_limit, &asn_DEF_MC, (void **)&mc, v2_mc, sizeof(v2_mc));

    fprintf(stderr, "MC skip: code=%d consumed=%zu\n", dr.code, dr.consumed);
    assert(dr.code == RC_OK);
    fprintf(stderr, "MC skip: pre=%ld present=%d post=%ld\n",
            mc->pre, (int)mc->c.present, mc->post);
    assert(dr.consumed == sizeof(v2_mc));
    assert(mc->pre == 1);
    assert(mc->c.present == C_PR_NOTHING);
    assert(mc->post == 4);

    ASN_STRUCT_FREE(asn_DEF_MC, mc);
}

/* CHOICE truncated inside the open type contents must starve cleanly. */
static void
check_choice_truncated(void) {
    size_t cut;

    for(cut = 1; cut < sizeof(v2_choice); cut++) {
        uint8_t *buf = malloc(cut);
        C_t *c = 0;
        asn_dec_rval_t dr;

        assert(buf);
        memcpy(buf, v2_choice, cut);
        dr = oer_decode(&s_no_stack_limit, &asn_DEF_C, (void **)&c, buf, cut);

        fprintf(stderr, "CHOICE truncated at %zu: code=%d consumed=%zu\n",
                cut, dr.code, dr.consumed);
        assert(dr.code == RC_WMORE);
        /* The unknown-alternative skip path must not consume anything
         * (not even the tag) before the whole Open Type is available:
         * a retry re-parses the tag from scratch. */
        assert(dr.consumed == 0);

        ASN_STRUCT_FREE(asn_DEF_C, c);
        free(buf);
    }
}

/*
 * Encode-side interop: asn1c's v1 encodings must be byte-identical to
 * the reference toolchain's v1 encodings (it decodes both back to the
 * same values).
 */
static void
check_v1_encode_interop(void) {
    uint8_t buf[16];

    {
        M_t m;
        asn_enc_rval_t er;
        memset(&m, 0, sizeof(m));
        m.a = 1; m.inner.x = 2; m.b = 4;
        er = oer_encode_to_buffer(&asn_DEF_M, 0, &m, buf, sizeof(buf));
        fprintf(stderr, "v1 M encode: encoded=%zd\n", er.encoded);
        assert(er.encoded == (ssize_t)sizeof(v1_seq));
        assert(memcmp(buf, v1_seq, sizeof(v1_seq)) == 0);
    }
    {
        MC_t mc;
        asn_enc_rval_t er;
        memset(&mc, 0, sizeof(mc));
        mc.pre = 1;
        mc.c.present = C_PR_c1;
        mc.c.choice.c1 = 7;
        mc.post = 4;
        er = oer_encode_to_buffer(&asn_DEF_MC, 0, &mc, buf, sizeof(buf));
        fprintf(stderr, "v1 MC encode: encoded=%zd\n", er.encoded);
        assert(er.encoded == (ssize_t)sizeof(v1_mc));
        assert(memcmp(buf, v1_mc, sizeof(v1_mc)) == 0);
    }
}

int main() {
    check_seq_skip();
    check_seq_skip_two_extensions();
    check_seq_truncated();
    check_choice_skip();
    check_choice_skip_nested();
    check_choice_truncated();
    check_v1_encode_interop();
    return 0;
}
