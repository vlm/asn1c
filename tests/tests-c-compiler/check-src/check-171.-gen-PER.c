#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>
#include <Flags.h>
#include <U.h>
#include <S.h>
#include <TAlias.h>

/*
 * Regression test for issue #11: the UPER encoder must only strip
 * trailing 0 bits of a BIT STRING when the type has a NamedBitList
 * (X.680 (2015) #22.7). For an ordinary BIT STRING without a
 * NamedBitList, trailing 0 bits are part of the abstract value and
 * must be preserved bit-for-bit; a variable/extensible SIZE
 * constraint must not silently change the encoded length. Likewise,
 * a value shorter than the constraint root's lower bound must not be
 * zero-padded up to it (that also alters the abstract value); it is
 * encoded through the extension addition instead.
 *
 * All expected encodings below are golden bytes produced by a commercial
 * ASN.1 toolchain's (the project's interoperability reference) UPER
 * encoder for the exact same abstract values (issue #11 carries a subset
 * of this table).
 *
 * Before the fix, BIT_STRING_encode_uper() unconditionally
 * compactified (stripped trailing 0 bits from) every BIT STRING,
 * so e.g. T's value '11110000'B (8 significant bits) collapsed to
 * '1111'B (4 bits) purely because of trailing zeros -- a silent,
 * lossy data corruption. Decoding and re-encoding used to produce a
 * *different*, shorter encoding than the original.
 */

static BIT_STRING_t
mk_bs(const uint8_t *bytes, size_t nbytes, int bits_unused) {
	BIT_STRING_t bs;
	memset(&bs, 0, sizeof(bs));
	bs.size = nbytes;
	bs.buf = malloc(nbytes ? nbytes : 1);
	assert(bs.buf || nbytes == 0);
	if(nbytes) memcpy(bs.buf, bytes, nbytes);
	bs.bits_unused = bits_unused;
	return bs;
}

/*
 * Encode "bs" per "td", check the result matches the reference
 * toolchain's golden bytes "expect" exactly, then decode it back and re-encode: the
 * second encoding must be byte-for-byte identical to the first
 * (round-trip idempotency). This is exactly the invariant that was
 * broken for BIT STRING types without a NamedBitList.
 */
static void
check_roundtrip(const asn_TYPE_descriptor_t *td, BIT_STRING_t *bs,
                const uint8_t *expect, size_t expect_len, const char *name) {
	uint8_t buf1[64];
	uint8_t buf2[64];
	asn_enc_rval_t er;
	asn_dec_rval_t dr;
	void *decoded = 0;
	size_t enc_bytes1, enc_bytes2;
	size_t i;

	er = uper_encode_to_buffer(td, 0, bs, buf1, sizeof(buf1));
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

	dr = uper_decode_complete(0, td, &decoded, buf1, enc_bytes1);
	assert(dr.code == RC_OK);

	er = uper_encode_to_buffer(td, 0, decoded, buf2, sizeof(buf2));
	assert(er.encoded >= 0);
	enc_bytes2 = (size_t)((er.encoded + 7) / 8);

	if(enc_bytes2 != enc_bytes1 || memcmp(buf1, buf2, enc_bytes1) != 0) {
		fprintf(stderr, "%s: re-encode is not idempotent "
		        "(trailing 0 bits got stripped?)\n", name);
		assert(0);
	}

	ASN_STRUCT_FREE(*td, decoded);
	FREEMEM(bs->buf);
}

/*
 * Same as check_roundtrip() but for a SEQUENCE value of type S
 * (frees the member buffer, not the sequence itself).
 */
static void
check_seq_roundtrip(S_t *s, const uint8_t *expect, size_t expect_len,
                    const char *name) {
	uint8_t buf1[64];
	uint8_t buf2[64];
	asn_enc_rval_t er;
	asn_dec_rval_t dr;
	void *decoded = 0;
	size_t enc_bytes1, enc_bytes2;
	size_t i;

	er = uper_encode_to_buffer(&asn_DEF_S, 0, s, buf1, sizeof(buf1));
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

	dr = uper_decode_complete(0, &asn_DEF_S, &decoded, buf1, enc_bytes1);
	assert(dr.code == RC_OK);

	er = uper_encode_to_buffer(&asn_DEF_S, 0, decoded, buf2, sizeof(buf2));
	assert(er.encoded >= 0);
	enc_bytes2 = (size_t)((er.encoded + 7) / 8);

	if(enc_bytes2 != enc_bytes1 || memcmp(buf1, buf2, enc_bytes1) != 0) {
		fprintf(stderr, "%s: re-encode is not idempotent\n", name);
		assert(0);
	}

	ASN_STRUCT_FREE(asn_DEF_S, decoded);
	FREEMEM(s->flags.buf);
}

int
main(void) {
	/*
	 * T ::= BIT STRING (SIZE(4,...,8)) -- no NamedBitList.
	 * Extension root is the single size 4; size 8 is an extension
	 * addition, so 8-bit values encode as: extension bit '1' +
	 * 8-bit unconstrained length + data (17 bits -> 3 bytes).
	 * The five 8-bit vectors and their bytes come straight from
	 * issue #11 (reference-toolchain-produced encodings).
	 */
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xF1}; /* '11110001'B, 8 significant bits */
		uint8_t expect[] = {0x84, 0x78, 0x80};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:11110001(8bit)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xFE}; /* '11111110'B, 8 significant bits */
		uint8_t expect[] = {0x84, 0x7f, 0x00};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:11111110(8bit)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xF0}; /* '11110000'B, 8 significant bits */
		uint8_t expect[] = {0x84, 0x78, 0x00};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:11110000(8bit)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0x80}; /* '10000000'B, 8 significant bits */
		uint8_t expect[] = {0x84, 0x40, 0x00};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:10000000(8bit)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xFF}; /* '11111111'B, 8 significant bits */
		uint8_t expect[] = {0x84, 0x7f, 0x80};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:11111111(8bit)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xF0}; /* '1111'B: in the root, fixed 4-bit form */
		uint8_t expect[] = {0x78};
		bs = mk_bs(v, 1, 4);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:1111(4bit,root)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xC0}; /* '110'B: below root lower bound */
		uint8_t expect[] = {0x81, 0xe0};
		bs = mk_bs(v, 1, 5);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:110(3bit,below-root)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0x80}; /* '10'B: below root lower bound */
		uint8_t expect[] = {0x81, 0x40};
		bs = mk_bs(v, 1, 6);
		check_roundtrip(&asn_DEF_T, &bs, expect, sizeof(expect),
		                "T:10(2bit,below-root)");
	}

	/* U ::= BIT STRING, unconstrained, no NamedBitList. */
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xF0}; /* '11110000'B, 8 significant bits */
		uint8_t expect[] = {0x08, 0xf0};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_U, &bs, expect, sizeof(expect),
		                "U:11110000(8bit)");
	}

	/*
	 * Flags ::= BIT STRING {a(0),b(1),c(2)} (SIZE(0..8)) -- has a
	 * NamedBitList, so trailing 0 bits remain insignificant and the
	 * encoder keeps stripping them (the reference toolchain does the same): both the
	 * 3-bit '110'B and the 8-bit '11000000'B canonicalize to the
	 * 2-bit '11'B and encode as 0x2c.
	 */
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xC0}; /* '110'B: a,b set, c clear */
		uint8_t expect[] = {0x2c};
		bs = mk_bs(v, 1, 5);
		check_roundtrip(&asn_DEF_Flags, &bs, expect, sizeof(expect),
		                "Flags:110(3bit,named)");
	}
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xC0}; /* '11000000'B: same with trailing zeros */
		uint8_t expect[] = {0x2c};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_Flags, &bs, expect, sizeof(expect),
		                "Flags:11000000(8bit,named)");
	}
	{
		BIT_STRING_t bs;
		uint8_t expect[] = {0x00};
		bs = mk_bs(0, 0, 0);
		check_roundtrip(&asn_DEF_Flags, &bs, expect, sizeof(expect),
		                "Flags:''(empty,named)");
	}


	/*
	 * S ::= SEQUENCE { flags BIT STRING {x(0),y(1)} (SIZE(0..8)) }:
	 * the inline NamedBitList member must route to its own
	 * specifics (has_named_bits=1) through the member table, so
	 * its trailing 0 bits keep being compacted like the reference toolchain does.
	 */
	{
		S_t s;
		uint8_t v[] = {0xC0}; /* flags = '11000000'B -> '11'B */
		uint8_t expect[] = {0x2c};
		memset(&s, 0, sizeof(s));
		s.flags = mk_bs(v, 1, 0);
		check_seq_roundtrip(&s, expect, sizeof(expect),
		                    "S:flags=11000000(8bit,named)");
	}
	{
		S_t s;
		uint8_t v[] = {0x80}; /* flags = '10000000'B -> '1'B */
		uint8_t expect[] = {0x18};
		memset(&s, 0, sizeof(s));
		s.flags = mk_bs(v, 1, 0);
		check_seq_roundtrip(&s, expect, sizeof(expect),
		                    "S:flags=10000000(8bit,named)");
	}
	{
		S_t s;
		uint8_t v[] = {0xC0}; /* flags = '110'B -> '11'B */
		uint8_t expect[] = {0x2c};
		memset(&s, 0, sizeof(s));
		s.flags = mk_bs(v, 1, 5);
		check_seq_roundtrip(&s, expect, sizeof(expect),
		                    "S:flags=110(3bit,named)");
	}

	/*
	 * TAlias ::= Flags: a top-level alias of a NamedBitList
	 * BIT STRING must inherit the aliased type's specifics
	 * (has_named_bits=1) and keep compacting trailing 0 bits,
	 * byte-identical to Flags and to the reference toolchain.
	 */
	{
		BIT_STRING_t bs;
		uint8_t v[] = {0xC0}; /* '11000000'B */
		uint8_t expect[] = {0x2c};
		bs = mk_bs(v, 1, 0);
		check_roundtrip(&asn_DEF_TAlias, &bs, expect, sizeof(expect),
		                "TAlias:11000000(8bit,named)");
	}

	printf("All BIT STRING UPER compactify regression checks passed.\n");
	return 0;
}
