/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <IA5String.h>

/*
 * IA5String basic type description.
 */
static ber_tlv_tag_t asn1_DEF_IA5String_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (22 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_IA5String = {
	"IA5String",
	IA5String_constraint,       /* Constraint on the alphabet */
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_print_ascii,  /* ASCII subset */
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_IA5String_tags,
	sizeof(asn1_DEF_IA5String_tags)
	  / sizeof(asn1_DEF_IA5String_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	0	/* No specifics */
};

int
IA5String_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const IA5String_t *st = (const IA5String_t *)sptr;

	if(st && st->buf) {
		uint8_t *buf = st->buf;
		uint8_t *end = buf + st->size;
		/*
		 * IA5String is generally equivalent to 7bit ASCII.
		 * ISO/ITU-T T.50, 1963.
		 */
		for(; buf < end; buf++) {
			if(*buf > 0x7F) {
				_ASN_ERRLOG("%s: value byte %d out of range: "
					"%d > 127",
					td->name,
					(buf - st->buf) + 1,
					*buf
				);
				return -1;
			}
		}
	} else {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	return 0;
}
