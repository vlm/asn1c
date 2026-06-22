#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <T.h>
#include <CombInfo.h>
#include <AckCombInfo.h>

/*
 * AckCombInfo ::= CombInfo  is a plain alias of a CHOICE type.  asn1c
 * generates a PER constraint table for the alias (driven by the terminal
 * type), but historically that table was not linked into the alias'
 * asn_TYPE_descriptor_t.  As a result the CHOICE index was neither encoded
 * nor expected on decode, so uPER encode/decode of the alias was broken:
 * decoding failed outright (no extension marker to fall back on), and the
 * alias encoding differed from the equivalent non-aliased CHOICE.
 */

static void
verify(int testNo, CombInfo_t *ci) {
	asn_enc_rval_t er_alias;
	asn_enc_rval_t er_direct;
	asn_dec_rval_t rv;
	unsigned char buf_alias[8];
	unsigned char buf_direct[8];
	AckCombInfo_t *back = 0;

	/* The alias must encode exactly like the underlying CHOICE. */
	er_alias = uper_encode_to_buffer(&asn_DEF_AckCombInfo, 0, ci,
		buf_alias, sizeof buf_alias);
	er_direct = uper_encode_to_buffer(&asn_DEF_CombInfo, 0, ci,
		buf_direct, sizeof buf_direct);

	fprintf(stderr, "%d present=%d alias=%zd direct=%zd\n",
		testNo, ci->present, er_alias.encoded, er_direct.encoded);

	assert(er_alias.encoded > 0);
	assert(er_direct.encoded > 0);
	assert(er_alias.encoded == er_direct.encoded);
	assert(memcmp(buf_alias, buf_direct,
		(er_alias.encoded + 7) / 8) == 0);

	/* The alias must round-trip through its own descriptor. */
	rv = uper_decode_complete(0, &asn_DEF_AckCombInfo, (void **)&back,
		buf_alias, (er_alias.encoded + 7) / 8);
	assert(rv.code == RC_OK);

	assert(back->present == ci->present);
	if(ci->present == CombInfo_PR_a) {
		assert(back->choice.a == ci->choice.a);
	} else if(ci->present == CombInfo_PR_b) {
		assert(back->choice.b == ci->choice.b);
	}

	ASN_STRUCT_FREE(asn_DEF_AckCombInfo, back);
}

int main() {
	CombInfo_t ci;

	memset(&ci, 0, sizeof(ci));
	ci.present = CombInfo_PR_a;
	ci.choice.a = 2;
	verify(0, &ci);

	memset(&ci, 0, sizeof(ci));
	ci.present = CombInfo_PR_b;
	ci.choice.b = 1;
	verify(1, &ci);

	printf("OK\n");
	return 0;
}
