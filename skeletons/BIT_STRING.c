/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <BIT_STRING.h>

/*
 * BIT STRING basic type description.
 */
static ber_tlv_tag_t asn1_DEF_BIT_STRING_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (3 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_BIT_STRING = {
	"BIT STRING",
	BIT_STRING_constraint,
	OCTET_STRING_decode_ber,   /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,   /* Implemented in terms of OCTET STRING */
	BIT_STRING_print,
	OCTET_STRING_free,         /* Implemented in terms of OCTET STRING */
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_BIT_STRING_tags,
	sizeof(asn1_DEF_BIT_STRING_tags)
	  / sizeof(asn1_DEF_BIT_STRING_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	(void *)-1	/* Special indicator that this is a BIT STRING */
};

/*
 * BIT STRING generic constraint.
 */
int
BIT_STRING_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const BIT_STRING_t *st = sptr;

	if(st && st->buf) {
		if(st->size) {
			if(st->size == 1 && st->buf[0] != 0) {
				_ASN_ERRLOG("%s: invalid padding byte",
					td->name);
				return -1;
			}
		} else {
			_ASN_ERRLOG("%s: no padding byte", td->name);
			return -1;
		}
	} else {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	return 0;
}

/*
 * BIT STRING specific contents printer.
 */
int
BIT_STRING_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	static char h2c[16] = "0123456789ABCDEF";
	char scratch[64];
	const BIT_STRING_t *st = sptr;
	uint8_t *buf;
	uint8_t *end;
	char *p = scratch;

	(void)td;	/* Unused argument */

	if(!st || !st->buf) return cb("<absent>", 8, app_key);

	ilevel += 4;
	buf = st->buf;
	end = buf + st->size;

	/*
	 * Hexadecimal dump.
	 */
	for(buf++; buf < end; buf++) {
		if(((buf - st->buf) - 1) % 16 == 0) {
			int i;
			/* Indentation */
			if(cb("\n", 1, app_key)) return -1;
			for(i = 0; i < ilevel; i++) cb(" ", 1, app_key);
			/* Dump the string */
			if(cb(scratch, p - scratch, app_key)) return -1;
			p = scratch;
		}
		*p++ = h2c[*buf >> 4];
		*p++ = h2c[*buf & 0x0F];
		*p++ = 0x20;
	}

	/* Dump the incomplete 16-bytes row */
	return cb(scratch, p - scratch, app_key);
}

