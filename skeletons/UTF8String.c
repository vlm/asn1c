/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <UTF8String.h>

/*
 * UTF8String basic type description.
 */
static ber_tlv_tag_t asn1_DEF_UTF8String_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (12 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_UTF8String = {
	"UTF8String",
	UTF8String_constraint,      /* Check for invalid codes, etc. */
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	UTF8String_print,
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_UTF8String_tags,
	sizeof(asn1_DEF_UTF8String_tags)
	  / sizeof(asn1_DEF_UTF8String_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
};

static int _UTF8String_h1[16] = {
	1, 1, 1, 1, 1, 1, 1, 1,	/* 0x0 ... 0x7 */
	0, 0, 0, 0, 2, 2, 3, -1
};
static int _UTF8String_h2[16] = {
	4, 4, 4, 4, 4, 4, 4, 4, /* 0xF0 .. 0xF7 */
	5, 5, 5, 5, 6, 6, -1, -1
};

int
UTF8String_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	ssize_t len;
	len = UTF8String_length(sptr, td->name, app_errlog, app_key);
	if(len > 0) len = 0;
	return len;
}

ssize_t
UTF8String_length(const UTF8String_t *st, const char *opt_type_name,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {

	if(st && st->buf) {
		size_t length = 0;
		uint8_t *buf = st->buf;
		uint8_t *end = buf + st->size;
		int want;	/* Number of bytes wanted */

		for(want = 0; buf < end; buf++) {
			uint8_t ch = *buf;
			int w = _UTF8String_h1[ch >> 4];
			if(want) {	/* Continuation expected */
				if(w) {
					_ASN_ERRLOG("%s: UTF-8 expectation "
						"failed at byte %d",
						opt_type_name,
						(buf - st->buf) + 1);
					return -1;
				}
				want--;
			} else {
				switch(w) {
				case -1:	/* Long UTF-8 */
					w = _UTF8String_h2[ch & 0xF0];
					if(w != -1)
						break;
					/* Fall through */
				case 0:
					_ASN_ERRLOG(
						"%s: UTF-8 expectation"
						"failed at byte %d",
						opt_type_name,
						(buf - st->buf) + 1);
					return -1;
				}
				want = w - 1;	/* Expect this much */
			}
			if(!want) length++;
		}

		/* If still want something, then something is wrong */
		if(want) {
			_ASN_ERRLOG("%s: truncated UTF-8 sequence",
				opt_type_name);
			return -1;
		}

		return length;
	} else {
		_ASN_ERRLOG("%s: value not given", opt_type_name);
		return -1;
	}
}

int
UTF8String_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const UTF8String_t *st = sptr;

	if(st && st->buf) {
		return cb(st->buf, st->size, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}
