#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <LogLine.h>

uint8_t buf0[] = {
	48,	/* LogLine SEQUENCE */
	24,	/* L */
	22,	/* IA5String */
	4,	/* L */
	/* "zzz\007" */
  122, 122, 122, 7,
	48,	/* varsets SEQUENCE OF VariablePartSet */
	16,	/* L */
	48,	/* VariablePart */
	14,	/* L */
	48,	/* vparts SEQUENCE OF VariablePart */
	7,	/* L */
	49,	/* VariablePart */
	5,
	26,	/* VisibleString */
	3,
	49, 50, 51,	/* 1 2 3 */
	48,	/* ActionItem SEQUENCE */
	3,	/* L */
	10,	/* accept-as ENUMERATED */
	1,	/* L */
	0,
};

uint8_t buf1[] = {
	48,	/* LogLine SEQUENCE */
	19,	/* L */
	22,	/* IA5String */
	6,	/* L */
	/* "static" */
  115, 116, 97, 116, 105, 99,
	48,	/* varsets SEQUENCE OF VariablePartSet */
	9,	/* L */
	48,	/* VariablePart */
	7,	/* L */
	48,	/* vparts SEQUENCE OF VariablePart */
	0,	/* L */
	48,	/* ActionItem SEQUENCE */
	3,	/* L */
	10,	/* accept-as ENUMERATED */
	1,	/* L */
	0,
};

static void
check(LogLine_t *tp, uint8_t *ptr, size_t size, size_t consumed) {
	asn_dec_rval_t rval;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%zd)\n", ptr, size);
	rval = ber_decode(0, &asn_DEF_LogLine, (void **)&tp, ptr, size);
	fprintf(stderr, "Returned code %d, consumed %zd\n",
		(int)rval.code, rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);
	asn_fprint(stderr, &asn_DEF_LogLine, tp);
	asn_DEF_LogLine.free_struct(&asn_DEF_LogLine, tp, 1);
}

uint8_t *buf;
uint8_t buf_size;
uint8_t buf_pos;


static int
buf_fill(const void *buffer, size_t size, void *app_key) {

	(void)app_key;	/* Unused argument */

	assert(buf_pos + size <= buf_size);

	memcpy(buf + buf_pos, buffer, size);
	buf_pos += size;

	return 0;
}

static void
check_serialize() {
	LogLine_t ll;
	VariablePartSet_t vps;
	VariablePart_t vp;
	VisibleString_t vpart;
	asn_enc_rval_t erval;
	int i;

	memset(&ll, 0, sizeof(ll));
	memset(&vps, 0, sizeof(vps));
	memset(&vp, 0, sizeof(vp));
	memset(&vpart, 0, sizeof(vpart));
	vpart.buf = (uint8_t *)"123";
	vpart.size = 3;

	vp.present = VariablePart_PR_vset;
	ASN_SET_ADD(&vp.choice.vset, &vpart);
	vps.resolution.accept_as = accept_as_unknown;
	ASN_SEQUENCE_ADD(&vps.vparts, &vp);
	ASN_SEQUENCE_ADD(&ll.varsets, &vps);
	ll.line_digest.buf = (uint8_t *)"zzz\007";
	ll.line_digest.size = 4;

	asn_fprint(stderr, &asn_DEF_LogLine, &ll);
	buf_size = 128;
	buf = alloca(buf_size);
	erval = der_encode(&asn_DEF_LogLine, &ll, buf_fill, 0);
	assert(erval.encoded > 1);
	fprintf(stderr, "Encoded in %zd bytes\n", erval.encoded);
	fprintf(stderr, "\n");
	for(i = 0; i < buf_pos; i++) {
		fprintf(stderr, "%d ", buf[i]);
	}
	fprintf(stderr, "\n\n");
	assert(erval.encoded == sizeof(buf0));
	assert(memcmp(buf0, buf, sizeof(buf0)) == 0);
}

int
main(int ac, char **av) {
	LogLine_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check_serialize();

	check(&t, buf0, sizeof(buf0), sizeof(buf0));
	check(&t, buf1, sizeof(buf1), sizeof(buf1));

	return 0;
}
