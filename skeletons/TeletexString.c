/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <TeletexString.h>

/*
 * TeletexString basic type description.
 */
static ber_tlv_tag_t asn1_DEF_TeletexString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (20 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_TeletexString = {
	"TeletexString",
	asn_generic_unknown_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_print,         /* non-ascii string */
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_TeletexString_tags,
	sizeof(asn1_DEF_TeletexString_tags)
	  / sizeof(asn1_DEF_TeletexString_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

