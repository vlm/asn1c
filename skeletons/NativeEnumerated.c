/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Please read the NativeInteger.h for the explanation wrt. differences between
 * INTEGER and NativeInteger.
 * Basically, both are decoders and encoders of ASN.1 INTEGER type, but this
 * implementation deals with the standard (machine-specific) representation
 * of them instead of using the platform-independent buffer.
 */
#include <NativeEnumerated.h>

/*
 * NativeEnumerated basic type description.
 */
static ber_tlv_tag_t asn1_DEF_NativeEnumerated_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_NativeEnumerated = {
	"ENUMERATED",			/* The ASN.1 type is still ENUMERATED */
	asn_generic_no_constraint,
	NativeInteger_decode_ber,
	NativeInteger_encode_der,
	NativeInteger_print,
	NativeInteger_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_NativeEnumerated_tags,
	sizeof(asn1_DEF_NativeEnumerated_tags)/sizeof(asn1_DEF_NativeEnumerated_tags[0]),
	0,	/* Always in primitive form */
	0, 0,	/* No members */
	0	/* No specifics */
};

