/*
 * Regression test for issue #18: extensible ENUMERATED with an
 * extension addition value below the root maximum (E, F below).
 * The UPER encoder must select the root/extension segment by the
 * two-segment value2enum layout, not by a whole-array bsearch()
 * (X.691 14.1: the enumeration index of a root value is determined
 * by the root values alone; extension additions are numbered
 * independently, in order of their addition).
 *
 * Golden bytes below are authoritative: produced and cross-verified
 * with a commercial ASN.1 toolchain (the project's interoperability
 * reference) from the same module.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "E.h"
#include "F.h"
#include "G.h"
#include "H.h"

static char xer_buf[128];
static size_t xer_len;

static int
xer_cb(const void *buffer, size_t size, void *app_key) {
	(void)app_key;
	assert(xer_len + size < sizeof(xer_buf));
	memcpy(xer_buf + xer_len, buffer, size);
	xer_len += size;
	return 0;
}

/*
 * Verify one enumeration value against the reference toolchain's golden UPER byte:
 * encode, compare, decode the golden byte back, re-encode, and
 * round-trip through XER (exercises INTEGER_map_value2enum()).
 */
static void
check_value(const asn_TYPE_descriptor_t *td, long value,
		uint8_t expected_byte, const char *xer_body) {
	uint8_t buf[16];
	long *decoded = 0;
	asn_enc_rval_t er;
	asn_dec_rval_t rv;

	/* Encode and compare against the reference toolchain's golden byte. */
	er = uper_encode_to_buffer(td, 0, &value, buf, sizeof(buf));
	assert(er.encoded >= 1);
	assert(er.encoded <= 8);
	printf("%s %ld => %02x (expected %02x)\n",
		td->name, value, buf[0], expected_byte);
	assert(buf[0] == expected_byte);

	/* Decode the golden byte, expect the original value back. */
	rv = uper_decode_complete(0, td, (void **)&decoded,
		&expected_byte, 1);
	assert(rv.code == RC_OK);
	assert(decoded);
	printf("%s %02x => %ld (expected %ld)\n",
		td->name, expected_byte, *decoded, value);
	assert(*decoded == value);

	/* Re-encode the decoded value: must be idempotent. */
	memset(buf, 0xAA, sizeof(buf));
	er = uper_encode_to_buffer(td, 0, decoded, buf, sizeof(buf));
	assert(er.encoded >= 1);
	assert(buf[0] == expected_byte);

	/* XER round-trip: named value must survive both directions. */
	xer_len = 0;
	er = xer_encode(td, &value, XER_F_CANONICAL, xer_cb, 0);
	assert(er.encoded >= 0);
	xer_buf[xer_len] = '\0';
	printf("%s %ld => %s (expected body %s)\n",
		td->name, value, xer_buf, xer_body);
	assert(strstr(xer_buf, xer_body));

	*decoded = -1;
	rv = xer_decode(0, td, (void **)&decoded, xer_buf, xer_len);
	assert(rv.code == RC_OK);
	assert(*decoded == value);

	ASN_STRUCT_FREE(*td, decoded);
}

int
main() {

	/* E ::= ENUMERATED { a, b(3), ..., c(1) } */
	check_value(&asn_DEF_E, 0, 0x00, "<a/>");	/* root #0 */
	check_value(&asn_DEF_E, 3, 0x40, "<b/>");	/* root #1 */
	check_value(&asn_DEF_E, 1, 0x80, "<c/>");	/* extension #0 */

	/* F ::= ENUMERATED { a, z(25), ..., d } -- d(1), X.680 20.6 */
	check_value(&asn_DEF_F, 0, 0x00, "<a/>");	/* root #0 */
	check_value(&asn_DEF_F, 25, 0x40, "<z/>");	/* root #1 */
	check_value(&asn_DEF_F, 1, 0x80, "<d/>");	/* extension #0 */

	/* H ::= ENUMERATED { a, b(3), ..., c(1), d(50) } -- two additions */
	check_value(&asn_DEF_H, 0, 0x00, "<a/>");	/* root #0 */
	check_value(&asn_DEF_H, 3, 0x40, "<b/>");	/* root #1 */
	check_value(&asn_DEF_H, 1, 0x80, "<c/>");	/* extension #0 */
	check_value(&asn_DEF_H, 50, 0x81, "<d/>");	/* extension #1 */

	/* G ::= ENUMERATED { x(5), y(2), w } -- w(0), not extensible */
	check_value(&asn_DEF_G, 0, 0x00, "<w/>");	/* index 0 */
	check_value(&asn_DEF_G, 2, 0x40, "<y/>");	/* index 1 */
	check_value(&asn_DEF_G, 5, 0x80, "<x/>");	/* index 2 */

	printf("Finished checks for issue #18\n");
	return 0;
}
