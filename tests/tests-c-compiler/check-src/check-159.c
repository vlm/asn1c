#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include "T.h"


uint8_t buf1[] = {
	0x28,0x18,
		0x06,0x07,0x00,0x11,0x86,0x05,0x01,0x01,0x01,
		0xa0,0x0d,
			0x60,0x0b,
				0xa1,0x09,
					0x06,0x07,0x04,0x00,0x00,0x01,0x00,0x05,0x03
};


uint8_t buf1_reconstr[] = {
	0x28,0x18,
		0x06,0x07,0x00,0x11,0x86,0x05,0x01,0x01,0x01,
		0xa0,0x0d,
			0x60,0x0b,
				0xa1,0x09,
					0x06,0x07,0x04,0x00,0x00,0x01,0x00,0x05,0x03
};


static void
check(T_t *tp, uint8_t *buf, size_t size, size_t consumed) {
	asn_dec_rval_t rval;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%zd)\n", buf, size);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %zd\n",
		(int)rval.code, rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);

	const uint8_t direct_reference[] = {0x00,0x11,0x86,0x05,0x01,0x01,0x01};
	assert(tp->direct_reference);
	assert(tp->direct_reference->size == sizeof(direct_reference));
	assert(memcmp(tp->direct_reference->buf, direct_reference,
				sizeof(direct_reference)) == 0);

	assert(tp->indirect_reference == NULL);
	assert(tp->data_value_descriptor == NULL);

	const uint8_t single_asn1_type[] = {
		0x60,0x0b,0xa1,0x09,0x06,0x07,0x04,0x00,0x00,0x01,0x00,0x05,0x03};
	assert(tp->encoding.present == encoding_PR_single_ASN1_type);
	assert(tp->encoding.choice.single_ASN1_type.size == sizeof(single_asn1_type));
	assert(memcmp(tp->encoding.choice.single_ASN1_type.buf, single_asn1_type,
				sizeof(single_asn1_type)) == 0);
}

size_t buf_pos;
size_t buf_size;
uint8_t *buf;

static int
buf_fill(const void *buffer, size_t size, void *app_key) {

	(void)app_key;	/* Unused argument */

	if(buf_pos + size > buf_size) {
		fprintf(stderr, "%zd + %zd > %zd\n",
			buf_pos, size, buf_size);
		return -1;
	}

	memcpy(buf + buf_pos, buffer, size);
	buf_pos += size;
	fprintf(stderr, "   written %zd (%zd)\n", size, buf_pos);

	return 0;
}

static void
compare(T_t *tp, uint8_t *cmp_buf, ssize_t cmp_buf_size) {
	asn_enc_rval_t erval;
	int i;

	buf_size = cmp_buf_size + 100;
	buf = alloca(buf_size);
	buf_pos = 0;

	/*
	 * Try to re-create using DER encoding.
	 */
	erval = der_encode(&asn_DEF_T, tp, buf_fill, 0);
	assert(erval.encoded != -1);
	if(erval.encoded != cmp_buf_size) {
		printf("%zd != %zd\n", erval.encoded, cmp_buf_size);
	}
	assert(erval.encoded == cmp_buf_size);
	for(i = 0; i < cmp_buf_size; i++) {
		if(buf[i] != cmp_buf[i]) {
			fprintf(stderr, "Recreated buffer content mismatch:\n");
			fprintf(stderr, "Byte %d, %x != %x (%d != %d)\n",
				i,
				buf[i], cmp_buf[i],
				buf[i], cmp_buf[i]
			);
		}
		assert(buf[i] == cmp_buf[i]);
	}
}

int
main(int ac, char **av) {
	T_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	/* Check exact buf1 */
	check(&t, buf1, sizeof(buf1), sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn_DEF_T, &t);
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_T, &t);

	/* Check slightly more than buf1 */
	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn_DEF_T, &t);
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_T, &t);

	return 0;
}
