/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <constr_SEQUENCE_OF.h>
#include <asn_SEQUENCE_OF.h>

/*
 * The DER encoder of the SEQUENCE OF type.
 */
der_enc_rval_t
SEQUENCE_OF_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)sd->specifics;
	asn1_SET_OF_element_t *elm = specs->element;
	A_SEQUENCE_OF(void) *list;
	size_t computed_size = 0;
	ssize_t encoding_size = 0;
	der_enc_rval_t erval;
	int edx;

	ASN_DEBUG("Estimating size of SEQUENCE OF %s", sd->name);

	/*
	 * Gather the length of the underlying members sequence.
	 */
	(void *)list = ptr;
	for(edx = 0; edx < list->count; edx++) {
		void *memb_ptr = list->array[edx];
		erval = elm->type->der_encoder(elm->type, memb_ptr,
			0, elm->tag,
			0, 0);
		if(erval.encoded == -1)
			return erval;
		computed_size += erval.encoded;
	}

	/*
	 * Encode the TLV for the sequence itself.
	 */
	encoding_size = der_write_tags(sd, computed_size, tag_mode, tag,
		cb, app_key);
	if(encoding_size == -1) {
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
		return erval;
	}

	computed_size += encoding_size;
	if(!cb) {
		erval.encoded = computed_size;
		return erval;
	}

	ASN_DEBUG("Encoding members of SEQUENCE OF %s", sd->name);

	/*
	 * Encode all members.
	 */
	for(edx = 0; edx < list->count; edx++) {
		void *memb_ptr = list->array[edx];
		erval = elm->type->der_encoder(elm->type, memb_ptr,
			0, elm->tag,
			cb, app_key);
		if(erval.encoded == -1)
			return erval;
		encoding_size += erval.encoded;
	}

	if(computed_size != (size_t)encoding_size) {
		/*
		 * Encoded size is not equal to the computed size.
		 */
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
	} else {
		erval.encoded = computed_size;
	}

	return erval;
}

