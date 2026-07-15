/*
 * UPER encoding of values under an extensible SIZE constraint with
 * named extension additions, e.g. BIT STRING (SIZE(2,...,3)).
 * X.691: the PER-visible root is SIZE(2); a size-3 value is encoded
 * as an extension with a general length determinant.  Folding the
 * named extension into the root ([2..3]) produces encodings that are
 * incompatible with other ASN.1 tools (golden bytes below verified
 * against a commercial ASN.1 toolchain, the project's interoperability
 * reference) and corrupts cross-version decoding.
 *
 * This test also pins the companion fix: the generated
 * asn_check_constraints() checker must still accept a value whose size
 * falls in the named extension range (size 3), because that value is a
 * legal member of the (extensible) type.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <T.h>

int main() {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[8];
	uint8_t bits[2];
	T_t t;

	/* The PER-visible size root must be [2..2], extensible. */
	const asn_per_constraint_t *size_ct =
		&asn_DEF_T.encoding_constraints.per_constraints->size;
	assert(size_ct->flags & APC_EXTENSIBLE);
	assert(size_ct->lower_bound == 2);
	assert(size_ct->upper_bound == 2);
	assert(size_ct->effective_bits == 0);

	/*
	 * '11'B is in the root: ext bit 0, no length, 2 bits of value.
	 * Golden encoding (reference toolchain): 0x60.
	 */
	memset(&t, 0, sizeof(t));
	bits[0] = 0xC0;
	t.buf = bits;
	t.size = 1;
	t.bits_unused = 6;
	assert(asn_check_constraints(&asn_DEF_T, &t, 0, 0) == 0);
	er = uper_encode_to_buffer(&asn_DEF_T, 0, &t, buf, sizeof(buf));
	assert(er.encoded == 3);
	assert(buf[0] == 0x60);

	/*
	 * '101'B has the extension size 3: ext bit 1, general length
	 * determinant (8 bits) = 3, then 3 bits of value.
	 * Golden encoding (reference toolchain): 0x81 0xd0.
	 *
	 * A size-3 value is a legal member of the extensible type, so the
	 * generated constraint checker must accept it (regression guard for
	 * the "PER root excludes extension additions" fix leaking into the
	 * runtime constraint checker).
	 */
	memset(&t, 0, sizeof(t));
	bits[0] = 0xA0;
	t.buf = bits;
	t.size = 1;
	t.bits_unused = 5;
	assert(asn_check_constraints(&asn_DEF_T, &t, 0, 0) == 0);
	er = uper_encode_to_buffer(&asn_DEF_T, 0, &t, buf, sizeof(buf));
	assert(er.encoded == 12);
	assert(buf[0] == 0x81);
	assert(buf[1] == 0xd0);

	/* A size-4 value is neither in the root nor a named extension. */
	memset(&t, 0, sizeof(t));
	bits[0] = 0xF0;
	t.buf = bits;
	t.size = 1;
	t.bits_unused = 4;
	assert(asn_check_constraints(&asn_DEF_T, &t, 0, 0) == -1);

	/* And both golden encodings decode back to the original values. */
	T_t *to = 0;
	static const unsigned char enc_root[] = "\x60";
	rv = uper_decode(0, &asn_DEF_T, (void *)&to, enc_root, 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(to->size == 1 && to->bits_unused == 6);
	assert((to->buf[0] & 0xC0) == 0xC0);	/* '11'B */
	ASN_STRUCT_FREE(asn_DEF_T, to);

	to = 0;
	static const unsigned char enc_ext[] = "\x81\xd0";
	rv = uper_decode(0, &asn_DEF_T, (void *)&to, enc_ext, 2, 0, 0);
	assert(rv.code == RC_OK);
	assert(to->size == 1 && to->bits_unused == 5);
	assert((to->buf[0] & 0xE0) == 0xA0);	/* '101'B */
	ASN_STRUCT_FREE(asn_DEF_T, to);

	printf("Finished OK\n");
	return 0;
}
