/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <NumericString.h>

/*
 * NumericString basic type description.
 */
static ber_tlv_tag_t asn1_DEF_NumericString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (18 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_NumericString = {
	"NumericString",
	NumericString_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_print_ascii,   /* ASCII subset */
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_NumericString_tags,
	sizeof(asn1_DEF_NumericString_tags)
	  / sizeof(asn1_DEF_NumericString_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

int
NumericString_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const NumericString_t *st = (const NumericString_t *)sptr;

	if(st && st->buf) {
		uint8_t *buf = st->buf;
		uint8_t *end = buf + st->size;

		/*
		 * Check the alphabet of the NumericString.
		 * ASN.1:1984 (X.409)
		 */
		for(; buf < end; buf++) {
			switch(*buf) {
			case 0x20:
			case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
			case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
				continue;
			}
			_ASN_ERRLOG(app_errlog, app_key,
				"%s: value byte %d "
				"not in NumericString alphabet (%d)",
				td->name,
				(buf - st->buf) + 1,
				*buf
			);
			return -1;
		}
	} else {
		_ASN_ERRLOG(app_errlog, app_key,
			"%s: value not given", td->name);
		return -1;
	}

	return 0;
}
