/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <UTF8String.h>

/*
 * UTF8String basic type description.
 */
static ber_tlv_tag_t asn_DEF_UTF8String_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (12 << 2)),	/* [UNIVERSAL 12] IMPLICIT ...*/
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),	/* ... OCTET STRING */
};
asn_TYPE_descriptor_t asn_DEF_UTF8String = {
	"UTF8String",
	OCTET_STRING_free,
	UTF8String_print,
	UTF8String_constraint,      /* Check for invalid codes, etc. */
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	0,				/* Not implemented yet */
	OCTET_STRING_encode_xer_ascii,	/* Already in UTF-8 format */
	0, /* Use generic outmost tag fetcher */
	asn_DEF_UTF8String_tags,
	sizeof(asn_DEF_UTF8String_tags)
	  / sizeof(asn_DEF_UTF8String_tags[0]) - 1,
	asn_DEF_UTF8String_tags,
	sizeof(asn_DEF_UTF8String_tags)
	  / sizeof(asn_DEF_UTF8String_tags[0]),
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * This is the table of length expectations.
 * The second half of this table is only applicable to the long sequentes.
 */
static int UTF8String_ht[2][16] = {
	{ /* 0x0 ... 0x7 */
	  /* 0000..0111 */
	  1, 1, 1, 1, 1, 1, 1, 1,
	  /* 1000..1011(0), 1100..1101(2), 1110(3), 1111(-1) */
	  0, 0, 0, 0, 2, 2, 3, -1 },
	{ /* 0xF0 .. 0xF7 */
	  /* 11110000..11110111 */
	  4, 4, 4, 4, 4, 4, 4, 4,
	  5, 5, 5, 5, 6, 6, -1, -1 }
};

int
UTF8String_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	ssize_t len;
	len = UTF8String_length((const UTF8String_t *)sptr, td->name,
		app_errlog, app_key);
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
			int w = UTF8String_ht[0][ch >> 4];
			if(want) {	/* Continuation expected */
				if(w) {
					_ASN_ERRLOG(app_errlog, app_key,
						"%s: UTF-8 expectation "
						"failed at byte %d (%s:%d)",
						opt_type_name,
						(buf - st->buf) + 1,
						__FILE__, __LINE__);
					return -1;
				}
				want--;
			} else {
				switch(w) {
				case -1:	/* Long UTF-8 */
					w = UTF8String_ht[1][ch & 0x0F];
					if(w != -1)
						break;
					/* Fall through */
				case 0:	/* But we should want something! */
					_ASN_ERRLOG(app_errlog, app_key,
						"%s: UTF-8 expectation"
						"failed at byte %d (%s:%d)",
						opt_type_name,
						(buf - st->buf) + 1,
						__FILE__, __LINE__);
					return -1;
				}
				want = w - 1;	/* Expect this much */
			}
			if(!want) length++;
		}

		/* If still want something, then something is wrong */
		if(want) {
			_ASN_ERRLOG(app_errlog, app_key,
				"%s: truncated UTF-8 sequence (%s:%d)",
				opt_type_name, __FILE__, __LINE__);
			return -1;
		}

		return length;
	} else {
		_ASN_ERRLOG(app_errlog, app_key,
			"%s: value not given", opt_type_name);
		return -1;
	}
}

int
UTF8String_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const UTF8String_t *st = (const UTF8String_t *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st && st->buf) {
		return (cb(st->buf, st->size, app_key) < 0) ? -1 : 0;
	} else {
		return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;
	}
}
