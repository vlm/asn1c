/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <ENUMERATED.h>
#include <ber_codec_prim.h>

/*
 * ENUMERATED basic type description.
 */
static ber_tlv_tag_t asn_DEF_ENUMERATED_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ENUMERATED = {
	"ENUMERATED",
	ASN__PRIMITIVE_TYPE_free,
	INTEGER_print,			/* Implemented in terms of INTEGER */
	asn_generic_no_constraint,
	ber_decode_primitive,
	INTEGER_encode_der,		/* Implemented in terms of INTEGER */
	0,				/* Not implemented yet */
	INTEGER_encode_xer,		/* Implemented in terms of INTEGER */
	0, /* Use generic outmost tag fetcher */
	asn_DEF_ENUMERATED_tags,
	sizeof(asn_DEF_ENUMERATED_tags) / sizeof(asn_DEF_ENUMERATED_tags[0]),
	asn_DEF_ENUMERATED_tags,	/* Same as above */
	sizeof(asn_DEF_ENUMERATED_tags) / sizeof(asn_DEF_ENUMERATED_tags[0]),
	0, 0,	/* No members */
	0	/* No specifics */
};

