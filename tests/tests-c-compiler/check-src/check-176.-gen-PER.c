/*
 * Self-contained regression for the extensible BIT STRING SIZE fix,
 * nested inside a SEQUENCE { a, bs, b } (companion to check-165's
 * SEQUENCE/CHOICE extension-skip tests and to check-167/171's
 * same-version BIT STRING extension coverage).
 *
 * W ::= SEQUENCE { a MsgCount, bs BIT STRING (SIZE(2,...)), b MsgCount }
 *
 * This file backs *only* the below-root-lower-bound half of the
 * BIT_STRING_encode_uper() fix, not the compactify-gating half (see
 * check_comp_roundtrip() below for that). bs's constraint is
 * extensible with an EMPTY extension-addition list (bare "..."), so
 * it is not affected by this series' constraint-range (crange)
 * folding fix on its own, and bs has no NamedBitList so compactify is
 * never invoked on it either way (the fix's compactify gate is a
 * no-op for this fixture's values). What *does* change bs's encoding
 * here is the other, independent half of the same commit: before the
 * fix, a value shorter than the root's lower bound (2 bits) was
 * zero-padded up to 2 bits instead of being routed through the
 * extension addition. That changes both the emitted bit length and
 * the abstract value, and corrupts whatever SEQUENCE field follows
 * bs.
 *
 * The golden bytes below are produced from the abstract value
 * { a 5, bs '1'B, b 7 } (bs below the 2-bit root) by a commercial
 * ASN.1 toolchain's UPER encoder (the project's interoperability
 * reference); asn1tools does not implement BIT STRING size extension,
 * so it is not usable as an independent cross-check here.
 *
 * Before the fix in this series, asn1c's own UPER encoder for this
 * exact schema and value emitted 0a 83 80 (bs zero-padded into the
 * root, corrupting the bit alignment of "b") instead of the golden
 * 0b 01 87 -- confirmed against this commit's direct parent
 * (df81efe3, "tests: add regression 167..."), which decodes back to
 * a=5, bs correct, b=7 only because it is a *self*-consistent round
 * trip; the wire bytes it produces are not what a spec-conforming
 * peer emits, so decoding a genuinely conforming peer's bytes (the
 * golden bytes checked here) is the failure mode this test guards
 * against. (The same 0a 83 80 is also produced by the older commit
 * 8a274c3f cited in an earlier version of this comment, but df81efe3
 * -- the actual direct parent of the compactify-gating fix -- is the
 * precise pre-fix baseline for this claim.)
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <W.h>
#include <Comp.h>

static void
check_w_roundtrip(long a, const uint8_t *bs_bytes, size_t bs_nbytes,
                   int bits_unused, long b,
                   const uint8_t *expect, size_t expect_len,
                   const char *name) {
	W_t w;
	uint8_t buf1[64];
	uint8_t buf2[64];
	asn_enc_rval_t er;
	asn_dec_rval_t dr;
	void *decoded = 0;
	size_t enc_bytes1, enc_bytes2;
	size_t i;

	memset(&w, 0, sizeof(w));
	w.a = a;
	w.b = b;
	w.bs.buf = malloc(bs_nbytes ? bs_nbytes : 1);
	assert(w.bs.buf || bs_nbytes == 0);
	if(bs_nbytes) memcpy(w.bs.buf, bs_bytes, bs_nbytes);
	w.bs.size = bs_nbytes;
	w.bs.bits_unused = bits_unused;

	er = uper_encode_to_buffer(&asn_DEF_W, 0, &w, buf1, sizeof(buf1));
	assert(er.encoded >= 0);
	enc_bytes1 = (size_t)((er.encoded + 7) / 8);

	fprintf(stderr, "%s:", name);
	for(i = 0; i < enc_bytes1; i++) fprintf(stderr, " %02x", buf1[i]);
	fprintf(stderr, "\n");

	if(enc_bytes1 != expect_len || memcmp(buf1, expect, expect_len) != 0) {
		fprintf(stderr, "%s: mismatch vs reference golden:", name);
		for(i = 0; i < expect_len; i++)
			fprintf(stderr, " %02x", expect[i]);
		fprintf(stderr, "\n");
		assert(0);
	}

	dr = uper_decode_complete(0, &asn_DEF_W, &decoded, buf1, enc_bytes1);
	assert(dr.code == RC_OK);
	{
		W_t *w2 = decoded;
		assert(w2->a == a);
		assert((long)w2->bs.size == (long)bs_nbytes);
		assert(w2->bs.bits_unused == bits_unused);
		if(bs_nbytes) assert(memcmp(w2->bs.buf, bs_bytes, bs_nbytes) == 0);
		assert(w2->b == b);
	}

	er = uper_encode_to_buffer(&asn_DEF_W, 0, decoded, buf2, sizeof(buf2));
	assert(er.encoded >= 0);
	enc_bytes2 = (size_t)((er.encoded + 7) / 8);
	assert(enc_bytes2 == enc_bytes1 && memcmp(buf1, buf2, enc_bytes1) == 0);

	ASN_STRUCT_FREE(asn_DEF_W, decoded);
	FREEMEM(w.bs.buf);
}

/*
 * Comp ::= BIT STRING (SIZE(4,...,8)), with no NamedBitList: this is
 * issue #11's original reproducer. It backs the compactify-gating
 * half of the fix, independently of the below-root-lower-bound half
 * exercised by check_w_roundtrip() above.
 *
 * For the abstract value '11110000'B (8 significant bits, size in
 * the [4,8] root, so no extension routing is involved either
 * pre- or post-fix), BIT_STRING__compactify() strips the trailing
 * 4 zero bits down to '1111'B (4 bits) whenever it is invoked.
 * Pre-fix, BIT_STRING_encode_uper() called compactify
 * unconditionally, so it silently re-encoded the value as if it
 * were the 4-bit '1111'B: 78 (1 byte, 5 bits: ext-bit 0 + length
 * field + 4 data bits) instead of the golden 84 78 00 (3 bytes, 17
 * bits: ext-bit 0 + length field + all 8 data bits). Post-fix,
 * compactify is only invoked when specs->has_named_bits is set;
 * Comp has no NamedBitList, so it is skipped and the full 8-bit
 * value survives, matching the reference toolchain exactly:
 *
 *   pre-fix  (df81efe3): 78            (decodes back as '1111'B --
 *                                        the value is corrupted, not
 *                                        just re-encoded differently)
 *   post-fix (this fix): 84 78 00      (matches reference toolchain)
 *
 * Both golden bytes were confirmed against the reference toolchain's
 * UPER encoder/decoder for this exact schema and value: it encodes
 * '11110000'B to 84 78 00 and decodes 84 78 00 back to '11110000'B
 * (8 bits); it also decodes the pre-fix bytes 78 to '1111'B (4
 * bits), independently confirming the pre-fix value corruption.
 */
static void
check_comp_roundtrip(const uint8_t *bits, size_t nbits,
                      const uint8_t *expect, size_t expect_len,
                      const char *name) {
	Comp_t c;
	uint8_t buf1[64];
	uint8_t buf2[64];
	asn_enc_rval_t er;
	asn_dec_rval_t dr;
	void *decoded = 0;
	size_t nbytes = (nbits + 7) / 8;
	size_t enc_bytes1, enc_bytes2;
	size_t i;

	memset(&c, 0, sizeof(c));
	c.buf = malloc(nbytes ? nbytes : 1);
	assert(c.buf || nbytes == 0);
	if(nbytes) memcpy(c.buf, bits, nbytes);
	c.size = nbytes;
	c.bits_unused = (int)(8 * nbytes - nbits);

	er = uper_encode_to_buffer(&asn_DEF_Comp, 0, &c, buf1, sizeof(buf1));
	assert(er.encoded >= 0);
	enc_bytes1 = (size_t)((er.encoded + 7) / 8);

	fprintf(stderr, "%s:", name);
	for(i = 0; i < enc_bytes1; i++) fprintf(stderr, " %02x", buf1[i]);
	fprintf(stderr, "\n");

	if(enc_bytes1 != expect_len || memcmp(buf1, expect, expect_len) != 0) {
		fprintf(stderr, "%s: mismatch vs reference golden:", name);
		for(i = 0; i < expect_len; i++)
			fprintf(stderr, " %02x", expect[i]);
		fprintf(stderr, "\n");
		assert(0);
	}

	dr = uper_decode_complete(0, &asn_DEF_Comp, &decoded, buf1, enc_bytes1);
	assert(dr.code == RC_OK);
	{
		Comp_t *c2 = decoded;
		assert((size_t)c2->size == nbytes);
		assert((size_t)(8 * c2->size - c2->bits_unused) == nbits);
		if(nbytes) assert(memcmp(c2->buf, bits, nbytes) == 0);
	}

	er = uper_encode_to_buffer(&asn_DEF_Comp, 0, decoded, buf2, sizeof(buf2));
	assert(er.encoded >= 0);
	enc_bytes2 = (size_t)((er.encoded + 7) / 8);
	assert(enc_bytes2 == enc_bytes1 && memcmp(buf1, buf2, enc_bytes1) == 0);

	ASN_STRUCT_FREE(asn_DEF_Comp, decoded);
	FREEMEM(c.buf);
}

int main() {
	/*
	 * { a 5, bs '1'B (1 bit, below the 2-bit root), b 7 }: bs must be
	 * routed through the extension addition, not zero-padded into
	 * the root, and "b" must be recovered from the correct bit
	 * offset that follows.
	 */
	{
		uint8_t v[] = {0x80};
		uint8_t expect[] = {0x0b, 0x01, 0x87};
		check_w_roundtrip(5, v, 1, 7, 7, expect, sizeof(expect),
		                   "W:a=5,bs=1(below-root),b=7");
	}

	/*
	 * { a 5, bs '11'B (2 bits, in the root), b 7 }: sanity check that
	 * the ordinary in-root case is unaffected.
	 */
	{
		uint8_t v[] = {0xc0};
		uint8_t expect[] = {0x0a, 0xc3, 0x80};
		check_w_roundtrip(5, v, 1, 6, 7, expect, sizeof(expect),
		                   "W:a=5,bs=11(root),b=7");
	}

	/*
	 * Comp '11110000'B (8 bits, no NamedBitList): compactify must
	 * not strip the trailing 0 bits.
	 */
	{
		uint8_t v[] = {0xf0};
		uint8_t expect[] = {0x84, 0x78, 0x00};
		check_comp_roundtrip(v, 8, expect, sizeof(expect),
		                      "Comp:11110000(no-named-bits)");
	}

	printf("Finished OK\n");
	return 0;
}
