/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <ObjectDescriptor.h>

/*
 * ObjectDescriptor basic type description.
 */
static ber_tlv_tag_t asn1_DEF_ObjectDescriptor_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (7 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_ObjectDescriptor = {
	"ObjectDescriptor",
	asn_generic_unknown_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_print_ascii,   /* Treat as ASCII subset (it's not) */
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_ObjectDescriptor_tags,
	sizeof(asn1_DEF_ObjectDescriptor_tags)
	  / sizeof(asn1_DEF_ObjectDescriptor_tags[0]),
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

