#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include "E1.h"
#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E5.h"
#include "xer_decoder.h"

/*
 * Regression test for issue #19: automatic numbering of ENUMERATED
 * items after the extension marker "..." must assign the smallest
 * unused non-negative value (X.680 (02/2021) 20.6), not
 * (max value seen so far) + 1.
 *
 * NOTE: this test intentionally does NOT check UPER encodings.
 * Once the auto-numbered extension addition value (e.g. E1_d == 1)
 * ends up smaller than a root value (E1_z == 25), the generated
 * value2enum/enum2value tables become non-monotonic, which triggers
 * a separate, still-open bug (#18: UPER value2enum table ordering)
 * that miscodes even *root* ENUMERATED values in UPER. That is
 * #18's territory; here we only assert on the assigned values
 * themselves and on codecs (XER/DER via NativeEnumerated's generic
 * BER path) that do not depend on the value2enum sort order.
 */

/* Compile-time assertions on the assigned enumerator constants. */
#define STATIC_ASSERT(cond, name) \
	typedef char name[(cond) ? 1 : -1]

STATIC_ASSERT(E1_a == 0, E1_a_is_0);
STATIC_ASSERT(E1_z == 25, E1_z_is_25);
STATIC_ASSERT(E1_d == 1, E1_d_is_1_per_X680_20_6);

STATIC_ASSERT(E2_a == 0, E2_a_is_0);
STATIC_ASSERT(E2_z == 25, E2_z_is_25);
STATIC_ASSERT(E2_d == 1, E2_d_is_1);
STATIC_ASSERT(E2_e == 2, E2_e_is_2);
STATIC_ASSERT(E2_f == 30, E2_f_is_30);
STATIC_ASSERT(E2_g == 31, E2_g_is_31_gt_prev_ext_value);

STATIC_ASSERT(E3_x == 0, E3_x_is_0);
STATIC_ASSERT(E3_y == 1, E3_y_is_1);
STATIC_ASSERT(E3_h == 2, E3_h_is_2_unaffected_by_fix);

/* Automatic value must not preempt an explicit value declared later:
 * in { a(5), b, c(0) }, b skips 0 (owned by c) and gets 1.
 * The reference toolchain agrees (b=1, c=0). */
STATIC_ASSERT(E4_a == 5, E4_a_is_5);
STATIC_ASSERT(E4_b == 1, E4_b_is_1_skips_later_explicit_0);
STATIC_ASSERT(E4_c == 0, E4_c_is_0);

/* Order-independence: { a, d, z(1) } === { a, z(1), d }, so d=2.
 * The reference toolchain agrees (d=2). */
STATIC_ASSERT(E5_a == 0, E5_a_is_0);
STATIC_ASSERT(E5_d == 2, E5_d_is_2_skips_later_explicit_1);
STATIC_ASSERT(E5_z == 1, E5_z_is_1);

static char buf[4096];
static int buf_offset;

static int
buf_writer(const void *buffer, size_t size, void *app_key) {
	(void)app_key;
	assert(buf_offset + size < sizeof(buf));
	memcpy(buf + buf_offset, buffer, size);
	buf_offset += size;
	return 0;
}

#define CHECK_XER(td, type, eval, xer_string) do {			\
	asn_dec_rval_t rv;						\
	char buf2[128];							\
	type *e = 0;							\
	long val;							\
									\
	rv = xer_decode(0, (td), (void **)&e,				\
		(xer_string), strlen(xer_string));			\
	assert(rv.code == RC_OK);					\
	assert(rv.consumed == strlen(xer_string));			\
									\
	val = *e;							\
	printf("%s -> %ld == %d\n", (xer_string), val, (int)(eval));	\
	assert(val == (eval));						\
									\
	buf_offset = 0;							\
	xer_encode((td), e, XER_F_CANONICAL, buf_writer, 0);		\
	buf[buf_offset] = 0;						\
	sprintf(buf2, "<%s>%s</%s>", (td)->name, (xer_string),		\
		(td)->name);						\
	printf("%d -> %s == %s\n", (int)(eval), buf, buf2);		\
	assert(0 == strcmp(buf, buf2));				\
									\
	ASN_STRUCT_FREE(*(td), e);					\
} while(0)

int
main() {
	/* Round-trip the auto-numbered extension additions through XER,
	 * confirming the label <-> value association matches the
	 * expected X.680 20.6 values above. */
	CHECK_XER(&asn_DEF_E1, E1_t, E1_a, "<a/>");
	CHECK_XER(&asn_DEF_E1, E1_t, E1_z, "<z/>");
	CHECK_XER(&asn_DEF_E1, E1_t, E1_d, "<d/>");

	CHECK_XER(&asn_DEF_E2, E2_t, E2_a, "<a/>");
	CHECK_XER(&asn_DEF_E2, E2_t, E2_z, "<z/>");
	CHECK_XER(&asn_DEF_E2, E2_t, E2_d, "<d/>");
	CHECK_XER(&asn_DEF_E2, E2_t, E2_e, "<e/>");
	CHECK_XER(&asn_DEF_E2, E2_t, E2_f, "<f/>");
	CHECK_XER(&asn_DEF_E2, E2_t, E2_g, "<g/>");

	CHECK_XER(&asn_DEF_E3, E3_t, E3_x, "<x/>");
	CHECK_XER(&asn_DEF_E3, E3_t, E3_y, "<y/>");
	CHECK_XER(&asn_DEF_E3, E3_t, E3_h, "<h/>");

	CHECK_XER(&asn_DEF_E4, E4_t, E4_a, "<a/>");
	CHECK_XER(&asn_DEF_E4, E4_t, E4_b, "<b/>");
	CHECK_XER(&asn_DEF_E4, E4_t, E4_c, "<c/>");

	CHECK_XER(&asn_DEF_E5, E5_t, E5_a, "<a/>");
	CHECK_XER(&asn_DEF_E5, E5_t, E5_d, "<d/>");
	CHECK_XER(&asn_DEF_E5, E5_t, E5_z, "<z/>");

	return 0;
}
