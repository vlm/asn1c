/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <ENUMERATED.h>

/*
 * ENUMERATED basic type description.
 */
static ber_tlv_tag_t asn1_DEF_ENUMERATED_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_ENUMERATED = {
	"ENUMERATED",
	asn_generic_no_constraint,
	INTEGER_decode_ber,		/* Implemented in terms of INTEGER */
	INTEGER_encode_der,		/* Implemented in terms of INTEGER */
	INTEGER_print,			/* Implemented in terms of INTEGER */
	INTEGER_free,			/* Implemented in terms of INTEGER */
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_ENUMERATED_tags,
	sizeof(asn1_DEF_ENUMERATED_tags)/sizeof(asn1_DEF_ENUMERATED_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Primitive */
	0, 0,	/* No members */
	0	/* No specifics */
};

