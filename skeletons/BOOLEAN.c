/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <BOOLEAN.h>

/*
 * BOOLEAN basic type description.
 */
static ber_tlv_tag_t asn1_DEF_BOOLEAN_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (1 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_BOOLEAN = {
	"BOOLEAN",
	asn_generic_no_constraint,
	BOOLEAN_decode_ber,
	BOOLEAN_encode_der,
	BOOLEAN_print,
	BOOLEAN_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_BOOLEAN_tags,
	sizeof(asn1_DEF_BOOLEAN_tags)/sizeof(asn1_DEF_BOOLEAN_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};

/*
 * Decode BOOLEAN type.
 */
ber_dec_rval_t
BOOLEAN_decode_ber(asn1_TYPE_descriptor_t *td,
		void **bool_structure, void *buf_ptr, size_t size,
		int tag_mode) {
	BOOLEAN_t *st = *bool_structure;
	ber_dec_rval_t rval;
	ber_dec_ctx_t ctx = { 0, 0, 0, 0 };
	ber_tlv_len_t length;
	ber_tlv_len_t lidx;

	if(st == NULL) {
		st = *bool_structure = CALLOC(1, sizeof(*st));
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

	(char *)buf_ptr += rval.consumed;
	size -= rval.consumed;
	if(length > (ber_tlv_len_t)size) {
		rval.code = RC_WMORE;
		rval.consumed = 0;
		return rval;
	}

	/*
	 * Compute boolean value.
	 */
	for(st->value = 0, lidx = 0;
		(lidx < length) && st->value == 0; lidx++) {
		/*
		 * Very simple approach: read bytes until the end or
		 * value is already TRUE.
		 * BOOLEAN is not supposed to contain meaningful data anyway.
		 */
		st->value |= ((uint8_t *)buf_ptr)[lidx];
	}

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s, value=%ld",
		(long)rval.consumed, (long)length,
		td->name, (long)st->value);
	
	return rval;
}

der_enc_rval_t
BOOLEAN_encode_der(asn1_TYPE_descriptor_t *td, void *sptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	der_enc_rval_t erval;
	BOOLEAN_t *st = sptr;

	erval.encoded = der_write_tags(td, 1, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		erval.failed_type = td;
		erval.structure_ptr = sptr;
		return erval;
	}

	if(cb) {
		uint8_t bool_value;
		ssize_t ret;

		bool_value = st->value?0xff:0; /* 0xff mandated by DER */
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

int
BOOLEAN_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const BOOLEAN_t *st = sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st) {
		if(st->value)
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

