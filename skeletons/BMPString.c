/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <BMPString.h>

/*
 * BMPString basic type description.
 */
static ber_tlv_tag_t asn1_DEF_BMPString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (30 << 2)),	/* [UNIVERSAL 30] IMPLICIT ...*/
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))	/* ... OCTET STRING */
};
asn1_TYPE_descriptor_t asn1_DEF_BMPString = {
	"BMPString",
	asn_generic_no_constraint,  /* No constraint by default */
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	BMPString_print,
	OCTET_STRING_free,          /* -//- */
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_BMPString_tags,
	sizeof(asn1_DEF_BMPString_tags)
	  / sizeof(asn1_DEF_BMPString_tags[0]) - 1,
	asn1_DEF_BMPString_tags,
	sizeof(asn1_DEF_BMPString_tags)
	  / sizeof(asn1_DEF_BMPString_tags[0]),
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * BMPString specific contents printer.
 */
int
BMPString_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const BMPString_t *st = (const BMPString_t *)sptr;
	uint16_t *wchar;
	uint16_t *wend;
	char scratch[128];			/* Scratchpad buffer */
	char *p;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!st || !st->buf) return cb("<absent>", 8, app_key);

	wchar = (uint16_t *)st->buf;
	wend = (uint16_t *)(st->buf + st->size);
	for(p = scratch; wchar < wend; wchar++) {
		uint16_t wc = (((uint8_t *)wchar)[0] << 8)
				| ((uint8_t *)wchar)[1];	/* 2 bytes */
		if(sizeof(scratch) - (p - scratch) < 3) {
			if(cb(scratch, p - scratch, app_key))
				return -1;
			p = scratch;
		}
		if(wc < 0x80) {
			*p++ = (char)wc;
		} else if(wc < 0x800) {
			*p++ = 0xc0 | ((wc >> 6));
			*p++ = 0x80 | ((wc & 0x3f));
		} else {
			*p++ = 0xe0 | ((wc >> 12));
			*p++ = 0x80 | ((wc >> 6) & 0x3f);
			*p++ = 0x80 | ((wc & 0x3f));
		}
	}

	return cb(scratch, p - scratch, app_key);
}
