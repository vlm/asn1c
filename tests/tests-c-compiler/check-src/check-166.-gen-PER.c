/*
 * UPER forward compatibility for an extensible ENUMERATED (Solution C,
 * reference-isomorphic lossless relay), exercised end to end through
 * generated code. A value added by a newer version (an unknown extension)
 * must:
 *   - decode successfully (X.680 #6) without derailing subsequent fields;
 *   - be stored as LONG_MAX - extension_index, distinct per index and never
 *     aliasing a known value (even in a sparse enumeration);
 *   - re-encode byte-for-byte identically, so it can be relayed under the
 *     same PER transfer syntax, exactly as the reference toolchain does.
 * Golden bytes cross-checked against the reference toolchain and asn1tools.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include <E.h>
#include <S.h>
#include <N.h>

int main() {
	asn_dec_rval_t rv;
	asn_enc_rval_t er;
	unsigned char buf[8];

	/* Known root value decodes as usual. */
	static const unsigned char enc_ee2[] = { 0x40 };
	long *e = 0;
	rv = uper_decode(0, &asn_DEF_E, (void *)&e, enc_ee2, 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(*e == E_ee2);
	ASN_STRUCT_FREE(asn_DEF_E, e);

	/*
	 * ee4 from a newer version { ee1, ee2, ..., ee3(3), ee4(4) }:
	 * extension bit 1, extension index 1 => 0x81. Must decode (RC_OK)
	 * into LONG_MAX-1 and re-encode byte-identically (relay).
	 */
	static const unsigned char enc_ee4[] = { 0x81 };
	e = 0;
	rv = uper_decode(0, &asn_DEF_E, (void *)&e, enc_ee4, 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(*e == LONG_MAX - 1);
	er = uper_encode_to_buffer(&asn_DEF_E, 0, e, buf, sizeof buf);
	assert(er.encoded == 8);		/* 1 ext bit + 7 nsnnwn bits */
	assert(buf[0] == 0x81);			/* lossless relay */
	ASN_STRUCT_FREE(asn_DEF_E, e);

	/*
	 * ee6 (extension index 3) => 0x83 => LONG_MAX-3 => relay 0x83.
	 * This is the reference toolchain's golden byte (base decodes it to INT_MAX-3 and
	 * re-encodes 0x83); asn1c stores LONG_MAX-3 and does the same.
	 */
	static const unsigned char enc_ee6[] = { 0x83 };
	e = 0;
	rv = uper_decode(0, &asn_DEF_E, (void *)&e, enc_ee6, 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(*e == LONG_MAX - 3);
	er = uper_encode_to_buffer(&asn_DEF_E, 0, e, buf, sizeof buf);
	assert(er.encoded == 8);
	assert(buf[0] == 0x83);
	ASN_STRUCT_FREE(asn_DEF_E, e);

	/*
	 * Sparse enumeration { sp1(0), sp2(2), ... }: an unknown extension
	 * (index 0 => 0x80) must not alias the known sp2(2). Storing
	 * LONG_MAX (not the ordinal 2) keeps it distinct; relay to 0x80.
	 */
	static const unsigned char enc_sp_ext[] = { 0x80 };
	long *s = 0;
	rv = uper_decode(0, &asn_DEF_S, (void *)&s, enc_sp_ext, 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(*s != S_sp2);
	assert(*s == LONG_MAX);
	er = uper_encode_to_buffer(&asn_DEF_S, 0, s, buf, sizeof buf);
	assert(er.encoded == 8);
	assert(buf[0] == 0x80);
	ASN_STRUCT_FREE(asn_DEF_S, s);

	/*
	 * Unknown enum extension nested in SEQUENCE { a 5, en ee4, b 7 } => the
	 * fields around it must be recovered, en stored as LONG_MAX-1, and the
	 * whole PDU must relay byte-for-byte.
	 */
	static const unsigned char nest_ee4[] = { 0x0b, 0x02, 0x1c };
	N_t *n = 0;
	rv = uper_decode(0, &asn_DEF_N, (void *)&n, nest_ee4, 3, 0, 0);
	assert(rv.code == RC_OK);
	assert(n->a == 5);
	assert(n->en == LONG_MAX - 1);
	assert(n->b == 7);
	er = uper_encode_to_buffer(&asn_DEF_N, 0, n, buf, sizeof buf);
	assert(er.encoded == 22);		/* 7 + (1+7) + 7 bits */
	assert(buf[0] == 0x0b && buf[1] == 0x02 && buf[2] == 0x1c);
	ASN_STRUCT_FREE(asn_DEF_N, n);

	/* Sanity: same-version round-trip of a known value. */
	long e0 = E_ee2;
	er = uper_encode_to_buffer(&asn_DEF_E, 0, &e0, buf, sizeof buf);
	assert(er.encoded == 2);
	assert(buf[0] == 0x40);

	printf("Finished OK\n");
	return 0;
}
