/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <UniversalString.h>

/*
 * UniversalString basic type description.
 */
static ber_tlv_tag_t asn1_DEF_UniversalString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (28 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_UniversalString = {
	"UniversalString",
	asn_generic_no_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	UniversalString_print,      /* Convert into UTF8 and print */
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_UniversalString_tags,
	sizeof(asn1_DEF_UniversalString_tags)
	  / sizeof(asn1_DEF_UniversalString_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
};


int
UniversalString_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const UniversalString_t *st = sptr;
	uint32_t *wchar;
	uint32_t *wend;
	char scratch[128];			/* Scratchpad buffer */
	char *p;

	if(!st || !st->buf) return cb("<absent>", 8, app_key);

	wchar = (uint32_t *)st->buf;
	wend = (uint32_t *)(st->buf + st->size);
	for(p = scratch; wchar < wend; wchar++) {
		uint32_t wc =    (((uint8_t *)wchar)[0] << 24)
				| (((uint8_t *)wchar)[1] << 16)
				| (((uint8_t *)wchar)[2] << 8)
				|  ((uint8_t *)wchar)[3];	/* 4 bytes */
		if(sizeof(scratch) - (p - scratch) < 6) {
			if(cb(scratch, p - scratch, app_key))
				return -1;
			p = scratch;
		}
		if(wc < 0x80) {
			*p++ = (char)wc;
		} else if(wc < 0x800) {
			*p++ = 0xc0 | ((wc >> 6));
			*p++ = 0x80 | ((wc & 0x3f));
		} else if(wc < 0x10000) {
			*p++ = 0xe0 | ((wc >> 12));
			*p++ = 0x80 | ((wc >> 6) & 0x3f);
			*p++ = 0x80 | ((wc & 0x3f));
		} else if(wc < 0x200000) {
			*p++ = 0xf0 | ((wc >> 18));
			*p++ = 0x80 | ((wc >> 12) & 0x3f);
			*p++ = 0x80 | ((wc >> 6) & 0x3f);
			*p++ = 0x80 | ((wc & 0x3f));
		} else if(wc < 0x4000000) {
			*p++ = 0xf8 | ((wc >> 24));
			*p++ = 0x80 | ((wc >> 18) & 0x3f);
			*p++ = 0x80 | ((wc >> 12) & 0x3f);
			*p++ = 0x80 | ((wc >> 6) & 0x3f);
			*p++ = 0x80 | ((wc & 0x3f));
		} else {
			*p++ = 0xfc | ((wc >> 30) & 0x1);
			*p++ = 0x80 | ((wc >> 24) & 0x3f);
			*p++ = 0x80 | ((wc >> 18) & 0x3f);
			*p++ = 0x80 | ((wc >> 12) & 0x3f);
			*p++ = 0x80 | ((wc >> 6) & 0x3f);
			*p++ = 0x80 | ((wc & 0x3f));
		}
	}

	return cb(scratch, p - scratch, app_key);
}
