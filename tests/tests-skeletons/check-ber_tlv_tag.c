#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <asn_internal.h>
#include <ber_tlv_tag.h>

struct tag_control_s {
	int taglen;
	uint8_t tagbuf[8];

	int correctly_decodable;

	int tclass;		/* Tag class */
	ber_tlv_tag_t tvalue;	/* Tag value */
	int constr;		/* Is it constructed? */
} control[] = {
	{ 1, { 0x2 << 6 }, 	1, ASN_TAG_CLASS_CONTEXT, 0, 0 },
	{ 1, { 0x2 << 6 | 32 | 1 }, 1, ASN_TAG_CLASS_CONTEXT, 1, 1 },
	{ 1, { 0x3 << 6 | 30 }, 1, ASN_TAG_CLASS_PRIVATE, 30, 0 },
	{ 1, { 29 }, 		1, ASN_TAG_CLASS_UNIVERSAL, 29, 0 },
	{ 1, { 0xbf, 31 }, 	0, ASN_TAG_CLASS_CONTEXT, 31, 1 },
	{ 2, { 0xbf, 31 }, 	1, ASN_TAG_CLASS_CONTEXT, 31, 1 },
	{ 2, { 0xbf, 83 }, 	1, ASN_TAG_CLASS_CONTEXT, 83, 1 },
	{ 2, { 0xbf, 127 }, 	1, ASN_TAG_CLASS_CONTEXT, 127, 1 },
	{ 2, { 0xbf, 129 }, 	0, ASN_TAG_CLASS_CONTEXT, 127, 1 },
	{ 3, { 0xbf, 129, 0 }, 	1, ASN_TAG_CLASS_CONTEXT, 128, 1 },
	{ 3, { 0xbf, 129, 1 }, 	1, ASN_TAG_CLASS_CONTEXT, 129, 1 },
	{ 3, { 0xbf, 130, 0 }, 	1, ASN_TAG_CLASS_CONTEXT, 256, 1 },
	{ 3, { 0xbf, 130, 1 }, 	1, ASN_TAG_CLASS_CONTEXT, 257, 1 },
	{ 3, { 0xbf, 130, 0x81 }, 	0, 0, 0, 0 },
	{ 4, { 0xbf, 130, 0x81, 2 }, 	1, ASN_TAG_CLASS_CONTEXT, 32898, 1 },
	{ 4, { 0xbf, 130, 0x81, 0x82 }, 0, ASN_TAG_CLASS_CONTEXT, 32898, 1 },
	{ 5, { 0x1f, 130, 0x81, 0x82, 1 }, 1, 0, 4210945, 0 },
	{ 5, { 0x1f, 130, 0x81, 0x82, 2 }, 1, 0, 4210946, 0 },
	{ 5, { 0x1f, 0xff, 0x81, 0x82, 2 }, 1, 0, 266354946, 0 },
	{ 6, { 0x1f, 0xff, 0xff, 0x82, 0x80, 1 }, -1, 0, 266354946, 0 },
	{ 7, { 0x1f, 0x8E, 0x87, 0xAA, 0x95, 0x99, 3}, -1, 0, 4000000000UL, 0 },
};


static void check_decode(struct tag_control_s *ctrl);
static void check_encode(struct tag_control_s *ctrl);

int
main() {
	size_t i;

	for(i = 0; i < sizeof(control) / sizeof(control[0]); i++) {
		check_decode(&control[i]);
		check_encode(&control[i]);
	}

	return 0;
}

static void
check_decode(struct tag_control_s *ctrl) {
	ber_tlv_tag_t tag = 123;
	ber_tlv_tag_t tag1 = 124;
	ber_tlv_tag_t tag2 = 125;
	ssize_t size;

	if(ctrl->correctly_decodable < 1) {
		size = ber_fetch_tag(ctrl->tagbuf, ctrl->taglen, &tag1);
		assert(size == ctrl->correctly_decodable);
		return;
	}

	printf("Expecting ");
	tag = (ctrl->tvalue << 2) | ctrl->tclass;
	ber_tlv_tag_fwrite(tag, stdout);
	printf(", got ");

	size = ber_fetch_tag(ctrl->tagbuf, 0, &tag1);
	assert(size == 0);

	size = ber_fetch_tag(ctrl->tagbuf, ctrl->taglen, &tag1);
	assert(size == ctrl->taglen);

	size = ber_fetch_tag(ctrl->tagbuf, ctrl->taglen + 10, &tag2);
	assert(size == ctrl->taglen);

	ber_tlv_tag_fwrite(tag1, stdout);
	printf("\n");

	assert(tag1 == tag2);
	assert(tag == tag1);

	assert(ctrl->constr == BER_TLV_CONSTRUCTED(ctrl->tagbuf));
}



static void
check_encode(struct tag_control_s *ctrl) {
	uint8_t buf[16];
	ber_tlv_tag_t tag;
	int Filler = 0xDA;
	ssize_t size;
	ssize_t i;

	tag = ctrl->tvalue << 2 | ctrl->tclass;

	/*
	 * Testing buffer overruns.
	 */
	for(i = 0; i < (int)sizeof(buf); i++) {
		int j;

		memset(buf, Filler, sizeof(buf));

		size = ber_tlv_tag_serialize(tag, buf, i);
		assert(size < (int)sizeof(buf));

		if(size <= i) {
			for(j = 0; j < size; j++) assert(buf[j] != Filler);
		} else {
			j = i;
		}
		for(; j < (int)sizeof(buf); j++) assert(buf[j] == Filler);
	}

	memset(buf, Filler, sizeof(buf));

	size = ber_tlv_tag_serialize(tag, buf, sizeof(buf));
	assert(size < (int)sizeof(buf));

	for(i = 0; i < size; i++) assert(buf[i] != Filler);
	for(; i < (int)sizeof(buf); i++) assert(buf[i] == Filler);

	if(ctrl->correctly_decodable == 1) {
		assert(size == ctrl->taglen);
	}
	if(ctrl->constr) *buf |= 0x20;

	ber_tlv_tag_fwrite(tag, stdout);

	printf(":");

	for(i = 0; i < size; i++) {
		printf(" %02x", buf[i]);
		if(ctrl->correctly_decodable == 1) {
			assert(ctrl->tagbuf[i] == buf[i]);
		}
	}
	printf("\n");

}

