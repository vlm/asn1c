/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <NULL.h>
#include <BOOLEAN.h>	/* Implemented in terms of BOOLEAN type */

/*
 * NULL basic type description.
 */
static ber_tlv_tag_t asn1_DEF_NULL_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (5 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_NULL = {
	"NULL",
	asn_generic_no_constraint,
	BOOLEAN_decode_ber,	/* Implemented in terms of BOOLEAN */
	NULL_encode_der,	/* Special handling of DER encoding */
	NULL_print,
	BOOLEAN_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_NULL_tags,
	sizeof(asn1_DEF_NULL_tags)/sizeof(asn1_DEF_NULL_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};

der_enc_rval_t
NULL_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	der_enc_rval_t erval;

	erval.encoded = der_write_tags(sd, 0, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
	}

	return erval;
}

int
NULL_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(sptr) {
		return cb("<present>", 9, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}
