/*
 * UPER encoding of large ENUMERATED extension indices (X.691 #11.6).
 * The normally small non-negative whole number carrying the extension
 * index switches to the long form at 64, which must start with a "1"
 * flag bit before the general length determinant.  uper_put_nsnnwn()
 * used to omit that flag bit (issue #16), producing byte streams that
 * no compliant decoder -- including asn1c's own uper_get_nsnnwn() --
 * could read back (e.g. add65 encoded as 80 a0 80 and silently decoded
 * as extension index 0).
 *
 * The golden byte streams below were produced by a reference encoder
 * (a commercial ASN.1 toolchain's UPER encoder, the project's
 * interoperability reference) from this same module:
 *   add63 (ext idx 63) -> bf         (short form boundary)
 *   add64 (ext idx 64) -> c0 50 00   (long form threshold)
 *   add65 (ext idx 65) -> c0 50 40
 *   add69 (ext idx 69) -> c0 51 40
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <E.h>

static void
check_vector(long value, const unsigned char *expected, size_t expected_len) {
	unsigned char buf[8];
	E_t enc_value = value;
	E_t *dec_value = 0;
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	size_t i;

	/* Encode and compare byte-for-byte against the reference toolchain's golden bytes. */
	er = uper_encode_to_buffer(&asn_DEF_E, 0, &enc_value,
			buf, sizeof(buf));
	assert(er.encoded >= 0);
	assert((size_t)(er.encoded + 7) / 8 == expected_len);
	fprintf(stderr, "E=%ld =>", value);
	for(i = 0; i < expected_len; i++)
		fprintf(stderr, " %02x", buf[i]);
	fprintf(stderr, " (expected");
	for(i = 0; i < expected_len; i++)
		fprintf(stderr, " %02x", expected[i]);
	fprintf(stderr, ")\n");
	assert(memcmp(buf, expected, expected_len) == 0);

	/* Decode our own bytes back: must recover the original value. */
	rv = uper_decode(0, &asn_DEF_E, (void *)&dec_value,
			buf, expected_len, 0, 0);
	assert(rv.code == RC_OK);
	assert(*dec_value == value);

	/* Re-encode the decoded value: must be idempotent. */
	{
		unsigned char buf2[8];
		asn_enc_rval_t er2 = uper_encode_to_buffer(&asn_DEF_E, 0,
				dec_value, buf2, sizeof(buf2));
		assert(er2.encoded == er.encoded);
		assert(memcmp(buf2, expected, expected_len) == 0);
	}

	ASN_STRUCT_FREE(asn_DEF_E, dec_value);
}

int main() {
	/* Reference toolchain golden bytes (its UPER encoder). */
	static const unsigned char ref_add63[] = { 0xbf };
	static const unsigned char ref_add64[] = { 0xc0, 0x50, 0x00 };
	static const unsigned char ref_add65[] = { 0xc0, 0x50, 0x40 };
	static const unsigned char ref_add69[] = { 0xc0, 0x51, 0x40 };
	static const unsigned char ref_zero[]  = { 0x00 };

	check_vector(E_add63, ref_add63, sizeof(ref_add63));
	check_vector(E_add64, ref_add64, sizeof(ref_add64));
	check_vector(E_add65, ref_add65, sizeof(ref_add65));
	check_vector(E_add69, ref_add69, sizeof(ref_add69));

	/* Root value sanity baseline. */
	check_vector(E_zero, ref_zero, sizeof(ref_zero));

	printf("Finished %s\n", __FILE__);
	return 0;
}
