/*
 * UPER canonical encoding of a DEFAULT-valued SEQUENCE extension addition
 * (X.691 #18.2 / #18.4): when the actual value equals the DEFAULT, the
 * member must not contribute to the extension addition group -- it must
 * not set the extension presence bit, must not be counted towards the
 * extension bit-map length, and must not be emitted as an open type
 * field. asn1c already did this correctly for a DEFAULT member in the
 * SEQUENCE root (see R1 below, used as a control) but, before the fix
 * in SEQUENCE__handle_extensions() (skeletons/constr_SEQUENCE.c), it did
 * not apply the same elimination to a DEFAULT member appearing after the
 * "..." extension marker (R2), producing a non-canonical encoding with a
 * needless extension bit-map and open type field.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <R1.h>
#include <R2.h>

int main() {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[8];

	/*
	 * Control: root-position DEFAULT already omits the member when it
	 * equals the default. R1 { x: 1 } (y defaulted to 5, left unset)
	 * encodes as a presence bit (0) followed by x (4 bits) = 00001,
	 * padded to a single octet 0x08.
	 */
	{
		R1_t r1;
		memset(&r1, 0, sizeof(r1));
		r1.x = 1;
		er = uper_encode_to_buffer(&asn_DEF_R1, 0, &r1, buf, sizeof buf);
		assert(er.encoded == 5);
		assert(er.encoded > 0 && (er.encoded + 7) / 8 == 1);
		assert(buf[0] == 0x08);
	}

	/*
	 * R2 { x: 1 }, y left unset (absent -> defaults to 5 on decode).
	 * Canonical UPER: no extension bit-map is needed at all, since the
	 * only extension addition (y) is absent. Extension bit (0) + x (4
	 * bits) = 00001, padded to 0x08 -- the same bytes as R1 above.
	 */
	{
		R2_t r2;
		memset(&r2, 0, sizeof(r2));
		r2.x = 1;
		er = uper_encode_to_buffer(&asn_DEF_R2, 0, &r2, buf, sizeof buf);
		assert(er.encoded == 5);
		assert(buf[0] == 0x08);
	}

	/*
	 * R2 { x: 1, y: 5 } with y *explicitly* set to the DEFAULT value.
	 * This is the regression this fixture guards: before the fix,
	 * SEQUENCE__handle_extensions() treated any non-NULL extension
	 * pointer as "present" regardless of its value, so this would
	 * encode a spurious extension bit-map and open type field
	 * (0x88 0x08 0x0a 0x80, 29 bits) instead of collapsing to the
	 * same canonical 0x08 as the "y absent" case above.
	 */
	{
		R2_t r2;
		long y = 5;
		memset(&r2, 0, sizeof(r2));
		r2.x = 1;
		r2.y = &y;
		er = uper_encode_to_buffer(&asn_DEF_R2, 0, &r2, buf, sizeof buf);
		assert(er.encoded == 5);
		assert(buf[0] == 0x08);
	}

	/*
	 * R2 { x: 1, y: 7 }, y explicitly non-default. The extension
	 * addition group must still be encoded normally: extension bit
	 * (1) + x (0001) + ext bit-map length (0000000, count-1=0) + ext
	 * presence bit (1) + open type length octet (00000001) + y=7
	 * padded to an octet (01110000) = 29 bits -> 0x88 0x08 0x0b 0x80.
	 * This must be unaffected by the DEFAULT-elimination fix.
	 */
	{
		R2_t r2;
		long y = 7;
		memset(&r2, 0, sizeof(r2));
		r2.x = 1;
		r2.y = &y;
		er = uper_encode_to_buffer(&asn_DEF_R2, 0, &r2, buf, sizeof buf);
		assert(er.encoded == 29);
		assert(buf[0] == 0x88 && buf[1] == 0x08 && buf[2] == 0x0b
		       && buf[3] == 0x80);
	}

	/*
	 * Decode round-trip (guard: decode direction was already correct).
	 * Decoding the canonical 0x08 (extension bit 0) must recover x=1
	 * and y defaulted to 5.
	 */
	{
		static const unsigned char enc[] = { 0x08 };
		R2_t *r2 = 0;
		rv = uper_decode(0, &asn_DEF_R2, (void **)&r2, enc, sizeof enc, 0, 0);
		assert(rv.code == RC_OK);
		assert(r2->x == 1);
		assert(r2->y != 0);
		assert(*r2->y == 5);
		ASN_STRUCT_FREE(asn_DEF_R2, r2);
	}

	/*
	 * Decode round-trip of the non-default extension encoding: must
	 * recover x=1, y=7, and re-encode byte-for-byte identically.
	 */
	{
		static const unsigned char enc[] = { 0x88, 0x08, 0x0b, 0x80 };
		R2_t *r2 = 0;
		rv = uper_decode(0, &asn_DEF_R2, (void **)&r2, enc, sizeof enc, 0, 0);
		assert(rv.code == RC_OK);
		assert(r2->x == 1);
		assert(r2->y != 0);
		assert(*r2->y == 7);
		er = uper_encode_to_buffer(&asn_DEF_R2, 0, r2, buf, sizeof buf);
		assert(er.encoded == 29);
		assert(buf[0] == 0x88 && buf[1] == 0x08 && buf[2] == 0x0b
		       && buf[3] == 0x80);
		ASN_STRUCT_FREE(asn_DEF_R2, r2);
	}

	printf("Finished OK\n");
	return 0;
}
