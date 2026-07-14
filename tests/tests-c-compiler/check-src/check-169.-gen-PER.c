/*
 * Regression for issue #12: asn1c had no PER codec implementation for the
 * SET type (asn_OP_SET's uper_decoder/uper_encoder were null), so a SET
 * nested inside a PER-encoded PDU crashed with SIGSEGV at the unguarded
 * member-level call sites (stage 1 of the fix added the null checks; this
 * test originally asserted the clean RC_FAIL). Stage 2 implements the
 * UPER codec for extension-free SETs per X.691 #20: identical to the
 * SEQUENCE encoding, except that the root components are transmitted in
 * the canonical order of their tags (X.680 #8.6), taken from the
 * statically sorted specs->tag2el map.
 *
 * All the expected byte strings below are golden bytes produced by a
 * commercial ASN.1 toolchain's (the project's interoperability reference)
 * UPER encoder from the same values (and the reference toolchain
 * decodes every asn1c-produced encoding back to the same values); they
 * were additionally cross-checked against asn1tools 0.167 (Python).
 * The single encoder divergence is intentional and covered below: for a
 * DEFAULT member explicitly set to its default value, the reference
 * toolchain (BASIC-PER encoder's choice, X.691 #19.2 NOTE) may encode the member as present
 * (S3: ec 24), while asn1c always applies the CANONICAL-PER elimination
 * (61 20). Both are valid UPER; asn1c must decode both.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <M.h>
#include <S2.h>
#include <S3.h>
#include <S4.h>
#include <EmptyOD.h>
#include <ObjectDescriptor.h>

static void
check_M_roundtrip(void) {
	/*
	 * The original issue #12 reproducer: a SET nested in a SEQUENCE.
	 * M { s { a 1, b TRUE } } = a (8 bits, 00000001) + b (1 bit, 1),
	 * padded: 01 80. Decoding this used to SIGSEGV through the null
	 * uper_decoder slot of asn_OP_SET.
	 */
	static const unsigned char enc[] = { 0x01, 0x80 };
	unsigned char buf[8];
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	M_t *m = 0;
	M_t src;

	rv = uper_decode(0, &asn_DEF_M, (void **)&m, enc, sizeof enc, 0, 0);
	assert(rv.code == RC_OK);
	assert(m->s.a == 1);
	assert(m->s.b == 1);
	ASN_STRUCT_FREE(asn_DEF_M, m);

	memset(&src, 0, sizeof(src));
	src.s.a = 1;
	src.s.b = 1;
	er = uper_encode_to_buffer(&asn_DEF_M, 0, &src, buf, sizeof buf);
	assert(er.encoded == 9);
	assert(buf[0] == 0x01 && buf[1] == 0x80);
}

static void
check_S2_canonical_order(void) {
	/*
	 * S2 declares b [2] BOOLEAN before a [1] INTEGER(0..255), but the
	 * canonical tag order is a [1], then b [2]. { a 1, b TRUE } must
	 * therefore encode exactly like S { a 1, b TRUE }: 01 80. An
	 * encoder that (incorrectly) walked the declaration order would
	 * emit 80 80 instead.
	 */
	static const unsigned char enc[] = { 0x01, 0x80 };
	unsigned char buf[8];
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	S2_t *s2 = 0;
	S2_t src;

	memset(&src, 0, sizeof(src));
	src.a = 1;
	src.b = 1;
	er = uper_encode_to_buffer(&asn_DEF_S2, 0, &src, buf, sizeof buf);
	assert(er.encoded == 9);
	assert(buf[0] == 0x01 && buf[1] == 0x80);

	rv = uper_decode(0, &asn_DEF_S2, (void **)&s2, enc, sizeof enc, 0, 0);
	assert(rv.code == RC_OK);
	assert(s2->a == 1);
	assert(s2->b == 1);

	/* Re-encode what was decoded: must be byte-identical. */
	er = uper_encode_to_buffer(&asn_DEF_S2, 0, s2, buf, sizeof buf);
	assert(er.encoded == 9);
	assert(buf[0] == 0x01 && buf[1] == 0x80);
	ASN_STRUCT_FREE(asn_DEF_S2, s2);
}

static void
check_S3_presence_and_default(void) {
	/*
	 * S3 ::= SET { a INTEGER(0..7) DEFAULT 5, b BOOLEAN OPTIONAL,
	 *              c INTEGER(0..255) }. The preamble is a 2-bit
	 * presence map (a, b in canonical order) followed by the present
	 * members.
	 */
	unsigned char buf[8];
	asn_enc_rval_t er;
	asn_dec_rval_t rv;

	/*
	 * { c 9 }: a and b absent -> presence 00, c = 00001001;
	 * 00 00001001 (10 bits) -> 02 40.
	 */
	{
		static const unsigned char enc[] = { 0x02, 0x40 };
		S3_t *s3 = 0;
		S3_t src;

		memset(&src, 0, sizeof(src));
		src.c = 9;
		er = uper_encode_to_buffer(&asn_DEF_S3, 0, &src, buf, sizeof buf);
		assert(er.encoded == 10);
		assert(buf[0] == 0x02 && buf[1] == 0x40);

		rv = uper_decode(0, &asn_DEF_S3, (void **)&s3, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s3->a && *s3->a == 5);	/* DEFAULT filled in */
		assert(s3->b == 0);		/* OPTIONAL absent */
		assert(s3->c == 9);
		ASN_STRUCT_FREE(asn_DEF_S3, s3);
	}

	/*
	 * { a 5, b TRUE, c 9 } with a *explicitly* equal to its DEFAULT:
	 * canonical elimination reports a as absent -> presence 01,
	 * b = 1, c = 00001001; 01 1 00001001 (11 bits) -> 61 20.
	 */
	{
		static const unsigned char enc[] = { 0x61, 0x20 };
		S3_t *s3 = 0;
		S3_t src;
		long a = 5;
		BOOLEAN_t b = 1;

		memset(&src, 0, sizeof(src));
		src.a = &a;
		src.b = &b;
		src.c = 9;
		er = uper_encode_to_buffer(&asn_DEF_S3, 0, &src, buf, sizeof buf);
		assert(er.encoded == 11);
		assert(buf[0] == 0x61 && buf[1] == 0x20);

		rv = uper_decode(0, &asn_DEF_S3, (void **)&s3, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s3->a && *s3->a == 5);
		assert(s3->b && *s3->b != 0);
		assert(s3->c == 9);
		ASN_STRUCT_FREE(asn_DEF_S3, s3);
	}

	/*
	 * Reference toolchain interop, decode-only: the reference toolchain
	 * (BASIC-PER encoder's choice) may encode a DEFAULT member even when
	 * it carries the default value: presence 11, a = 101 (5), b = 1,
	 * c = 00001001; 11 101 1 00001001 (14 bits) -> ec 24, as produced by
	 * the reference toolchain for { a 5, b TRUE, c 9 }. asn1c must decode
	 * it, and its own re-encoding must collapse to the canonical
	 * form 61 20 checked above.
	 */
	{
		static const unsigned char enc[] = { 0xec, 0x24 };
		S3_t *s3 = 0;

		rv = uper_decode(0, &asn_DEF_S3, (void **)&s3, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s3->a && *s3->a == 5);
		assert(s3->b && *s3->b != 0);
		assert(s3->c == 9);

		er = uper_encode_to_buffer(&asn_DEF_S3, 0, s3, buf, sizeof buf);
		assert(er.encoded == 11);
		assert(buf[0] == 0x61 && buf[1] == 0x20);
		ASN_STRUCT_FREE(asn_DEF_S3, s3);
	}

	/*
	 * { a 3, c 9 }: a non-default (3 bits, 011), b absent ->
	 * presence 10, a = 011, c = 00001001;
	 * 10 011 00001001 (13 bits) -> 98 48.
	 */
	{
		static const unsigned char enc[] = { 0x98, 0x48 };
		S3_t *s3 = 0;
		S3_t src;
		long a = 3;

		memset(&src, 0, sizeof(src));
		src.a = &a;
		src.c = 9;
		er = uper_encode_to_buffer(&asn_DEF_S3, 0, &src, buf, sizeof buf);
		assert(er.encoded == 13);
		assert(buf[0] == 0x98 && buf[1] == 0x48);

		rv = uper_decode(0, &asn_DEF_S3, (void **)&s3, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s3->a && *s3->a == 3);
		assert(s3->b == 0);
		assert(s3->c == 9);
		ASN_STRUCT_FREE(asn_DEF_S3, s3);
	}

	/*
	 * { a 3, b FALSE, c 255 }: everything present ->
	 * presence 11, a = 011, b = 0, c = 11111111;
	 * 11 011 0 11111111 (14 bits) -> db fc.
	 */
	{
		static const unsigned char enc[] = { 0xdb, 0xfc };
		S3_t *s3 = 0;
		S3_t src;
		long a = 3;
		BOOLEAN_t b = 0;

		memset(&src, 0, sizeof(src));
		src.a = &a;
		src.b = &b;
		src.c = 255;
		er = uper_encode_to_buffer(&asn_DEF_S3, 0, &src, buf, sizeof buf);
		assert(er.encoded == 14);
		assert(buf[0] == 0xdb && buf[1] == 0xfc);

		rv = uper_decode(0, &asn_DEF_S3, (void **)&s3, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s3->a && *s3->a == 3);
		assert(s3->b && *s3->b == 0);
		assert(s3->c == 255);
		ASN_STRUCT_FREE(asn_DEF_S3, s3);
	}
}

static void
check_S4_untagged_choice_order(void) {
	/*
	 * S4 ::= SET { n [5] INTEGER(0..255), c CH } with CH an untagged
	 * CHOICE { x [3] ..., y [4] ... }. The tag map carries one entry
	 * per possible CHOICE tag ([3]->c, [4]->c, [5]->n), so the
	 * canonical-order reconstruction must de-duplicate and sort c by
	 * its smallest tag: c is transmitted first although n is
	 * declared first. Golden bytes from the reference toolchain.
	 */
	unsigned char buf[8];
	asn_enc_rval_t er;
	asn_dec_rval_t rv;

	/*
	 * { n 7, c x:1 }: c = CHOICE index 0 (1 bit) + x (8 bits),
	 * n = 00000111; 0 00000001 00000111 (17 bits) -> 00 83 80.
	 */
	{
		static const unsigned char enc[] = { 0x00, 0x83, 0x80 };
		S4_t *s4 = 0;
		S4_t src;

		memset(&src, 0, sizeof(src));
		src.n = 7;
		src.c.present = CH_PR_x;
		src.c.choice.x = 1;
		er = uper_encode_to_buffer(&asn_DEF_S4, 0, &src, buf, sizeof buf);
		assert(er.encoded == 17);
		assert(buf[0] == 0x00 && buf[1] == 0x83 && buf[2] == 0x80);

		rv = uper_decode(0, &asn_DEF_S4, (void **)&s4, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s4->n == 7);
		assert(s4->c.present == CH_PR_x);
		assert(s4->c.choice.x == 1);
		ASN_STRUCT_FREE(asn_DEF_S4, s4);
	}

	/*
	 * { n 7, c y:TRUE }: c = CHOICE index 1 (1 bit) + y (1 bit),
	 * n = 00000111; 1 1 00000111 (10 bits) -> c1 c0.
	 */
	{
		static const unsigned char enc[] = { 0xc1, 0xc0 };
		S4_t *s4 = 0;
		S4_t src;

		memset(&src, 0, sizeof(src));
		src.n = 7;
		src.c.present = CH_PR_y;
		src.c.choice.y = 1;
		er = uper_encode_to_buffer(&asn_DEF_S4, 0, &src, buf, sizeof buf);
		assert(er.encoded == 10);
		assert(buf[0] == 0xc1 && buf[1] == 0xc0);

		rv = uper_decode(0, &asn_DEF_S4, (void **)&s4, enc, sizeof enc,
				 0, 0);
		assert(rv.code == RC_OK);
		assert(s4->n == 7);
		assert(s4->c.present == CH_PR_y);
		assert(s4->c.choice.y != 0);
		ASN_STRUCT_FREE(asn_DEF_S4, s4);
	}
}

static void
check_EmptyOD_null_codec_gating(void) {
	/*
	 * Regression: the null-codec guard in SET_OF_decode_uper()
	 * (shared by SEQUENCE OF via SEQUENCE_OF_decode_uper) must only
	 * fire when there is at least one element to decode. An empty
	 * collection never invokes the element codec, so it must decode
	 * and encode fine (a single zero length determinant, 00) even if
	 * the element type has no UPER codec; only a non-empty one must
	 * fail cleanly.
	 *
	 * Since every generated type now has a UPER codec, the
	 * codec-less element is simulated by pointing the element type's
	 * operation table at a copy with the UPER slots nulled -- which
	 * is exactly the situation a SET member used to be in before the
	 * SET UPER codec existed.
	 */
	asn_TYPE_operation_t op_no_uper;
	asn_TYPE_operation_t *saved_op = asn_DEF_ObjectDescriptor.op;
	unsigned char buf[8];
	asn_enc_rval_t er;
	asn_dec_rval_t rv;

	op_no_uper = *asn_DEF_ObjectDescriptor.op;
	op_no_uper.uper_decoder = 0;
	op_no_uper.uper_encoder = 0;
	asn_DEF_ObjectDescriptor.op = &op_no_uper;

	/* Empty: decode 00 -> RC_OK with zero elements. */
	{
		static const unsigned char enc[] = { 0x00 };
		EmptyOD_t *e = 0;

		rv = uper_decode(0, &asn_DEF_EmptyOD, (void **)&e, enc,
				 sizeof enc, 0, 0);
		assert(rv.code == RC_OK);
		assert(e->list.count == 0);

		/* Empty encode must succeed as well. */
		er = uper_encode_to_buffer(&asn_DEF_EmptyOD, 0, e, buf,
					   sizeof buf);
		assert(er.encoded == 8);
		assert(buf[0] == 0x00);
		ASN_STRUCT_FREE(asn_DEF_EmptyOD, e);
	}

	/* Non-empty: must fail cleanly (RC_FAIL), not crash. */
	{
		static const unsigned char enc[] = { 0x01, 0x00 };
		EmptyOD_t *e = 0;

		rv = uper_decode(0, &asn_DEF_EmptyOD, (void **)&e, enc,
				 sizeof enc, 0, 0);
		assert(rv.code != RC_OK);
		if(e) ASN_STRUCT_FREE(asn_DEF_EmptyOD, e);
	}

	asn_DEF_ObjectDescriptor.op = saved_op;

	/*
	 * With the real ObjectDescriptor codec back in place, an empty
	 * round-trip must (still) work.
	 */
	{
		static const unsigned char enc[] = { 0x00 };
		EmptyOD_t *e = 0;

		rv = uper_decode(0, &asn_DEF_EmptyOD, (void **)&e, enc,
				 sizeof enc, 0, 0);
		assert(rv.code == RC_OK);
		assert(e->list.count == 0);
		ASN_STRUCT_FREE(asn_DEF_EmptyOD, e);
	}
}

int main() {
	check_M_roundtrip();
	check_S2_canonical_order();
	check_S3_presence_and_default();
	check_S4_untagged_choice_order();
	check_EmptyOD_null_codec_gating();

	printf("Finished OK\n");
	return 0;
}
