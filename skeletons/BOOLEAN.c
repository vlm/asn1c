/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <BOOLEAN.h>

/*
 * BOOLEAN basic type description.
 */
static ber_tlv_tag_t asn1_DEF_BOOLEAN_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (1 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_BOOLEAN = {
	"BOOLEAN",
	BOOLEAN_free,
	BOOLEAN_print,
	asn_generic_no_constraint,
	BOOLEAN_decode_ber,
	BOOLEAN_encode_der,
	0,				/* Not implemented yet */
	BOOLEAN_encode_xer,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_BOOLEAN_tags,
	sizeof(asn1_DEF_BOOLEAN_tags) / sizeof(asn1_DEF_BOOLEAN_tags[0]),
	asn1_DEF_BOOLEAN_tags,	/* Same as above */
	sizeof(asn1_DEF_BOOLEAN_tags) / sizeof(asn1_DEF_BOOLEAN_tags[0]),
	0,	/* Always in primitive form */
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Decode BOOLEAN type.
 */
ber_dec_rval_t
BOOLEAN_decode_ber(asn1_TYPE_descriptor_t *td,
		void **bool_value, void *buf_ptr, size_t size,
		int tag_mode) {
	BOOLEAN_t *st = (BOOLEAN_t *)*bool_value;
	ber_dec_rval_t rval;
	ber_dec_ctx_t ctx = { 0, 0, 0, 0 };
	ber_tlv_len_t length;
	ber_tlv_len_t lidx;

	if(st == NULL) {
		(void *)st = *bool_value = CALLOC(1, sizeof(*st));
		if(st == NULL) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	ASN_DEBUG("Decoding %s as BOOLEAN (tm=%d)",
		td->name, tag_mode);

	/*
	 * Check tags.
	 */
	rval = ber_check_tags(td, &ctx,
		buf_ptr, size, tag_mode, &length, 0);
	if(rval.code != RC_OK)
		return rval;

	ASN_DEBUG("Boolean length is %d bytes", (int)length);

	buf_ptr = ((char *)buf_ptr) + rval.consumed;
	size -= rval.consumed;
	if(length > (ber_tlv_len_t)size) {
		rval.code = RC_WMORE;
		rval.consumed = 0;
		return rval;
	}

	/*
	 * Compute boolean value.
	 */
	for(*st = 0, lidx = 0;
		(lidx < length) && *st == 0; lidx++) {
		/*
		 * Very simple approach: read bytes until the end or
		 * value is already TRUE.
		 * BOOLEAN is not supposed to contain meaningful data anyway.
		 */
		*st |= ((uint8_t *)buf_ptr)[lidx];
	}

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s, value=%d",
		(long)rval.consumed, (long)length,
		td->name, *st);
	
	return rval;
}

asn_enc_rval_t
BOOLEAN_encode_der(asn1_TYPE_descriptor_t *td, void *sptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;
	BOOLEAN_t *st = (BOOLEAN_t *)sptr;

	erval.encoded = der_write_tags(td, 1, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		erval.failed_type = td;
		erval.structure_ptr = sptr;
		return erval;
	}

	if(cb) {
		uint8_t bool_value;
		ssize_t ret;

		bool_value = *st?0xff:0; /* 0xff mandated by DER */
		ret = cb(&bool_value, 1, app_key);
		if(ret == -1) {
			erval.encoded = -1;
			erval.failed_type = td;
			erval.structure_ptr = sptr;
			return erval;
		}
	}

	erval.encoded += 1;

	return erval;
}

asn_enc_rval_t
BOOLEAN_encode_xer(asn1_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const BOOLEAN_t *st = (const BOOLEAN_t *)sptr;
	asn_enc_rval_t er;

	(void)ilevel;
	(void)flags;

	if(!st) _ASN_ENCODE_FAILED;

	if(*st) {
		_ASN_CALLBACK("<true/>", 7);
		er.encoded = 7;
	} else {
		_ASN_CALLBACK("<false/>", 8);
		er.encoded = 8;
	}

	return er;
}

int
BOOLEAN_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const BOOLEAN_t *st = (const BOOLEAN_t *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st) {
		if(*st)
			return cb("TRUE", 4, app_key);
		else
			return cb("FALSE", 5, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}

void
BOOLEAN_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {
	if(td && ptr && !contents_only) {
		FREEMEM(ptr);
	}
}

