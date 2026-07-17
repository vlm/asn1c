#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Int5.h>
#include <Str4.h>
#include <Utf8-4.h>
#include <PER-Visible.h>
#include <VisibleIdentifier.h>

static int
check_constraints(const asn_TYPE_descriptor_t *td, const void *sptr) {
	char errbuf[128];
	size_t errlen = sizeof(errbuf);
	int ret = asn_check_constraints(td, sptr, errbuf, &errlen);
	if(ret) {
		fprintf(stderr, "%s: %s\n", td->name, errbuf);
	}
	return ret;
}

int
main(int ac, char **av) {
	/* PER-Visible ::= IA5String (FROM("A".."F")), no SIZE constraint */
	PER_Visible_t st = {0};
	uint8_t empty[1] = {0};
	uint8_t good[] = {'A', 'B', 'F'};
	uint8_t bad[] = {'G'};

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	/*
	 * The empty string is a valid abstract value of a
	 * permitted-alphabet constrained string type without a lower
	 * SIZE bound, and this generated subtype constraint is intended
	 * to accept its buffer-less representation (buf=NULL, size=0).
	 * The constraint checking code must handle it without pointer
	 * arithmetic or ordered comparison on a null pointer
	 * (C17 6.5.6p8, 6.5.8p5).
	 */
	assert(st.buf == NULL);
	assert(st.size == 0);
	assert(check_constraints(&asn_DEF_PER_Visible, &st) == 0);

	/* A buffer-less value with a non-zero size is not a valid
	 * representation and must be rejected. */
	st.buf = NULL;
	st.size = 1;
	assert(check_constraints(&asn_DEF_PER_Visible, &st) != 0);

	/* A non-NULL backing buffer with logical size zero. */
	st.buf = empty;
	st.size = 0;
	assert(check_constraints(&asn_DEF_PER_Visible, &st) == 0);

	/* A value within the permitted alphabet. */
	st.buf = good;
	st.size = sizeof(good);
	assert(check_constraints(&asn_DEF_PER_Visible, &st) == 0);

	/* A value outside the permitted alphabet. */
	st.buf = bad;
	st.size = sizeof(bad);
	assert(check_constraints(&asn_DEF_PER_Visible, &st) != 0);

	return 0;
}
