/*
 * UPER encoding of known-multiplier character strings with an extensible
 * SIZE constraint, for lengths outside the extension root (issue #28).
 *
 * X.691 #30.4: outside the extension root the value is encoded "as if
 * there was no effective size constraint", but "shall have the effective
 * permitted-alphabet constraint" -- so the per-character width (#30.5.2)
 * does not change. The codecs used to reset the width to the canonical
 * 8-bit units (7 -> 8 bits for IA5String), producing byte streams that a
 * conformant peer silently mis-decodes as garbage, while asn1c could not
 * decode a conformant peer's output at all ("Unexpected end of input").
 *
 * A/N/P/T/S carry named extension additions, so every tested
 * extension-region length is a legal value of the type (asserted via
 * asn_check_constraints() before encoding and after decoding). T and S
 * pin the X.691 #30.5.4 translation rules: FROM(" ".."@") (ub = 2^b,
 * canonical-order indexes required) and FROM("A") (b = 0, no bits).
 *
 * X uses a bare extension marker: per X.680 §50.1 NOTE 6 the value set is
 * the union of the root and the AdditionalElementSetSpec (when present),
 * so an extension-region length is not a legal value of X; per §52.1 it
 * must still decode without error -- checked as a forward-decode vector
 * whose decoded value then fails constraint checking.
 *
 * All expected byte streams were produced directly by an independent
 * commercial ASN.1 implementation from the same abstract values and match
 * the X.691 #30.4/#30.5 derivation bit for bit.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <A.h>
#include <N.h>
#include <P.h>
#include <T.h>
#include <S.h>
#include <X.h>
#include <E.h>
#include <EU.h>
#include <W.h>

static void
check_string(const asn_TYPE_descriptor_t *td, const char *value,
             ssize_t expected_bits,
             const unsigned char *expected, size_t expected_len) {
	unsigned char buf[16];
	unsigned char buf2[16];
	char errbuf[128];
	size_t errlen = sizeof(errbuf);
	OCTET_STRING_t enc_value = {0, 0, {0, 0, 0}};
	OCTET_STRING_t *dec_value = 0;
	asn_enc_rval_t er;
	asn_enc_rval_t er2;
	asn_dec_rval_t rv;
	size_t i;

	assert(OCTET_STRING_fromBuf(&enc_value, value, -1) == 0);

	/* Every tested length is legal (root or a named extension addition). */
	assert(asn_check_constraints(td, &enc_value, errbuf, &errlen) == 0);

	/* Encode and compare bit-exactly against the golden bytes. */
	er = uper_encode_to_buffer(td, 0, &enc_value, buf, sizeof(buf));
	assert(er.encoded == expected_bits);
	assert((size_t)(er.encoded + 7) / 8 == expected_len);
	fprintf(stderr, "%s \"%s\" => (%ld bits)", td->name, value,
	        (long)er.encoded);
	for(i = 0; i < expected_len; i++)
		fprintf(stderr, " %02x", buf[i]);
	fprintf(stderr, " (expected");
	for(i = 0; i < expected_len; i++)
		fprintf(stderr, " %02x", expected[i]);
	fprintf(stderr, ")\n");
	assert(memcmp(buf, expected, expected_len) == 0);

	/* Decode the golden bytes back: must recover the original string,
	 * consume exactly the encoded bits, and validate. */
	rv = uper_decode(0, td, (void *)&dec_value, expected, expected_len,
	                 0, (int)(8 * expected_len - expected_bits));
	assert(rv.code == RC_OK);
	assert(rv.consumed == (size_t)expected_bits);
	assert(dec_value->size == (ssize_t)strlen(value));
	assert(memcmp(dec_value->buf, value, dec_value->size) == 0);
	errlen = sizeof(errbuf);
	assert(asn_check_constraints(td, dec_value, errbuf, &errlen) == 0);

	/* Re-encode the decoded value: must be idempotent. */
	er2 = uper_encode_to_buffer(td, 0, dec_value, buf2, sizeof(buf2));
	assert(er2.encoded == er.encoded);
	assert(memcmp(buf2, expected, expected_len) == 0);

	ASN_STRUCT_FREE(*td, dec_value);
	ASN_STRUCT_FREE_CONTENTS_ONLY(*td, &enc_value);
}

/*
 * A string in the extension region nested before another member: the
 * following field must be recovered intact (no bit-cursor corruption).
 */
static void
check_wrapped(const char *value, long trail, ssize_t expected_bits,
              const unsigned char *expected, size_t expected_len) {
	unsigned char buf[16];
	char errbuf[128];
	size_t errlen = sizeof(errbuf);
	W_t enc_value;
	W_t *dec_value = 0;
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	size_t i;

	memset(&enc_value, 0, sizeof(enc_value));
	assert(OCTET_STRING_fromBuf(&enc_value.v, value, -1) == 0);
	enc_value.trail = trail;

	assert(asn_check_constraints(&asn_DEF_W, &enc_value,
	                             errbuf, &errlen) == 0);

	er = uper_encode_to_buffer(&asn_DEF_W, 0, &enc_value,
	                           buf, sizeof(buf));
	assert(er.encoded == expected_bits);
	assert((size_t)(er.encoded + 7) / 8 == expected_len);
	fprintf(stderr, "W {\"%s\", %ld} => (%ld bits)", value, trail,
	        (long)er.encoded);
	for(i = 0; i < expected_len; i++)
		fprintf(stderr, " %02x", buf[i]);
	fprintf(stderr, "\n");
	assert(memcmp(buf, expected, expected_len) == 0);

	rv = uper_decode(0, &asn_DEF_W, (void *)&dec_value, expected,
	                 expected_len, 0,
	                 (int)(8 * expected_len - expected_bits));
	assert(rv.code == RC_OK);
	assert(rv.consumed == (size_t)expected_bits);
	assert(dec_value->v.size == (ssize_t)strlen(value));
	assert(memcmp(dec_value->v.buf, value, dec_value->v.size) == 0);
	assert(dec_value->trail == trail);
	errlen = sizeof(errbuf);
	assert(asn_check_constraints(&asn_DEF_W, dec_value,
	                             errbuf, &errlen) == 0);

	ASN_STRUCT_FREE(asn_DEF_W, dec_value);
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_W, &enc_value);
}

/*
 * Forward-decode of a length outside a bare extension marker's root: with
 * no named additions the value set is just the root (X.680 §50.1 NOTE 6),
 * so the value is not legal for this version, but per §52.1 it must
 * decode without error; the decoded value must then fail constraint
 * checking.
 */
static void
check_forward_decode(const unsigned char *bytes, size_t len,
                     const char *expect_value, size_t expect_bits) {
	char errbuf[128];
	size_t errlen = sizeof(errbuf);
	OCTET_STRING_t *dec_value = 0;
	asn_dec_rval_t rv;

	rv = uper_decode(0, &asn_DEF_X, (void *)&dec_value, bytes, len,
	                 0, (int)(8 * len - expect_bits));
	assert(rv.code == RC_OK);
	assert(rv.consumed == expect_bits);
	assert(dec_value->size == (ssize_t)strlen(expect_value));
	assert(memcmp(dec_value->buf, expect_value, dec_value->size) == 0);
	/* Length is outside the (only) root, so it is not a legal value. */
	assert(asn_check_constraints(&asn_DEF_X, dec_value,
	                             errbuf, &errlen) != 0);
	ASN_STRUCT_FREE(asn_DEF_X, dec_value);
}

int main() {
	/* IA5String (SIZE(1,...,4..9)): 7-bit characters. */
	static const unsigned char a_root[] = { 0x41 };
	static const unsigned char a_ext[] = { 0x82, 0x41, 0x85, 0x0e, 0x20 };
	static const unsigned char a_long[] =
		{ 0x84, 0xc1, 0x85, 0x0e, 0x24, 0x58, 0xd1, 0xe4, 0x49 };

	/* NumericString (SIZE(2,...,3)): 4-bit characters. */
	static const unsigned char n_root[] = { 0x11, 0x80 };
	static const unsigned char n_ext[] = { 0x81, 0x91, 0xa0 };

	/* IA5String (FROM("AB")) (SIZE(1,...,3)): 1-bit characters. */
	static const unsigned char p_root[] = { 0x00 };
	static const unsigned char p_ext[] = { 0x81, 0xa0 };

	/* IA5String (FROM(" ".."@")) (SIZE(1,...,2)): ub = 64 = 2^6, so
	 * characters encode as canonical-order indexes, not raw values. */
	static const unsigned char t_root[] = { 0x40 };
	static const unsigned char t_ext[] = { 0x81, 0x41, 0x00 };

	/* IA5String (FROM("A")) (SIZE(1,...,2)): N = 1, b = 0: characters
	 * occupy no bits; only the extension bit and length are encoded. */
	static const unsigned char s_root[] = { 0x00 };
	static const unsigned char s_ext[] = { 0x81, 0x00 };

	/* W: extension-region string followed by INTEGER (0..255). */
	static const unsigned char w_ext[] =
		{ 0x82, 0x41, 0x85, 0x0e, 0x25, 0x28 };

	/* Forward-decode: "ABCD" (length 4) under bare X ::= (SIZE(1,...)). */
	static const unsigned char x_fwd[] = { 0x82, 0x41, 0x85, 0x0e, 0x20 };

	check_string(&asn_DEF_A, "A", 8, a_root, sizeof(a_root));
	check_string(&asn_DEF_A, "ABCD", 37, a_ext, sizeof(a_ext));
	check_string(&asn_DEF_A, "ABCDEFGHI", 72, a_long, sizeof(a_long));

	check_string(&asn_DEF_N, "12", 9, n_root, sizeof(n_root));
	check_string(&asn_DEF_N, "123", 21, n_ext, sizeof(n_ext));

	check_string(&asn_DEF_P, "A", 2, p_root, sizeof(p_root));
	check_string(&asn_DEF_P, "ABA", 12, p_ext, sizeof(p_ext));

	check_string(&asn_DEF_T, "@", 7, t_root, sizeof(t_root));
	check_string(&asn_DEF_T, "@@", 21, t_ext, sizeof(t_ext));

	check_string(&asn_DEF_S, "A", 1, s_root, sizeof(s_root));
	check_string(&asn_DEF_S, "AA", 9, s_ext, sizeof(s_ext));

	check_wrapped("ABCD", 165, 45, w_ext, sizeof(w_ext));

	check_forward_decode(x_fwd, sizeof(x_fwd), "ABCD", 37);

	/* Negative: a character outside the permitted alphabet must fail to
	 * encode (FROM("A") admits only 'A'). */
	{
		unsigned char buf[8];
		OCTET_STRING_t bad = {0, 0, {0, 0, 0}};
		asn_enc_rval_t er;
		assert(OCTET_STRING_fromBuf(&bad, "B", -1) == 0);
		er = uper_encode_to_buffer(&asn_DEF_S, 0, &bad, buf, sizeof(buf));
		assert(er.encoded == -1);
		ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_S, &bad);
	}

	/* Empty string in the root (E: SIZE(0,...,2)): ext(0) + fixed size 0,
	 * exactly 1 bit; must round-trip without touching a NULL character
	 * buffer (units == 0 path). */
	{
		unsigned char buf[8];
		char errbuf[128];
		size_t errlen = sizeof(errbuf);
		E_t empty = {0, 0, {0, 0, 0}};
		E_t *dec_value = 0;
		asn_enc_rval_t er;
		asn_dec_rval_t rv;
		assert(asn_check_constraints(&asn_DEF_E, &empty,
		                             errbuf, &errlen) == 0);
		er = uper_encode_to_buffer(&asn_DEF_E, 0, &empty,
		                           buf, sizeof(buf));
		assert(er.encoded == 1);
		assert(buf[0] == 0x00);
		rv = uper_decode(0, &asn_DEF_E, (void *)&dec_value, buf, 1, 0, 7);
		assert(rv.code == RC_OK);
		assert(rv.consumed == 1);
		assert(dec_value->size == 0);
		errlen = sizeof(errbuf);
		assert(asn_check_constraints(&asn_DEF_E, dec_value,
		                             errbuf, &errlen) == 0);
		ASN_STRUCT_FREE(asn_DEF_E, dec_value);
	}

	/* Empty string as a named extension addition (EU: SIZE(1,...,0)):
	 * ext(1) + unconstrained length 0 (8 bits) = 9 bits, 80 00. This is
	 * the general (fragmenting) encode loop with buf == NULL, guarding
	 * the may_save == 0 pointer-arithmetic path. */
	{
		unsigned char buf[8];
		unsigned char buf2[8];
		char errbuf[128];
		size_t errlen = sizeof(errbuf);
		static const unsigned char eu_ext[] = { 0x80, 0x00 };
		EU_t empty = {0, 0, {0, 0, 0}};
		EU_t *dec_value = 0;
		asn_enc_rval_t er;
		asn_enc_rval_t er2;
		asn_dec_rval_t rv;
		assert(asn_check_constraints(&asn_DEF_EU, &empty,
		                             errbuf, &errlen) == 0);
		er = uper_encode_to_buffer(&asn_DEF_EU, 0, &empty,
		                           buf, sizeof(buf));
		assert(er.encoded == 9);
		assert(memcmp(buf, eu_ext, sizeof(eu_ext)) == 0);
		rv = uper_decode(0, &asn_DEF_EU, (void *)&dec_value, eu_ext,
		                 sizeof(eu_ext), 0, 7);
		assert(rv.code == RC_OK);
		assert(rv.consumed == 9);
		assert(dec_value->size == 0);
		errlen = sizeof(errbuf);
		assert(asn_check_constraints(&asn_DEF_EU, dec_value,
		                             errbuf, &errlen) == 0);
		er2 = uper_encode_to_buffer(&asn_DEF_EU, 0, dec_value,
		                            buf2, sizeof(buf2));
		assert(er2.encoded == 9);
		assert(memcmp(buf2, eu_ext, sizeof(eu_ext)) == 0);
		ASN_STRUCT_FREE(asn_DEF_EU, dec_value);
	}

	return 0;
}
