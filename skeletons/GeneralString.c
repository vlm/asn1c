/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <GeneralString.h>

/*
 * GeneralString basic type description.
 */
static ber_tlv_tag_t asn1_DEF_GeneralString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (27 << 2)),	/* [UNIVERSAL 27] IMPLICIT ...*/
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))	/* ... OCTET STRING */
};
asn1_TYPE_descriptor_t asn1_DEF_GeneralString = {
	"GeneralString",
	OCTET_STRING_free,
	OCTET_STRING_print,         /* non-ascii string */
	asn_generic_unknown_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	0,				/* Not implemented yet */
	OCTET_STRING_encode_xer,    /* Implemented in terms of OCTET STRING */
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_GeneralString_tags,
	sizeof(asn1_DEF_GeneralString_tags)
	  / sizeof(asn1_DEF_GeneralString_tags[0]) - 1,
	asn1_DEF_GeneralString_tags,
	sizeof(asn1_DEF_GeneralString_tags)
	  / sizeof(asn1_DEF_GeneralString_tags[0]),
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

