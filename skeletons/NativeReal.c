/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Please read the NativeReal.h for the explanation wrt. differences between
 * REAL and NativeReal.
 * Basically, both are decoders and encoders of ASN.1 REAL type, but this
 * implementation deals with the standard (machine-specific) representation
 * of them instead of using the platform-independent buffer.
 */
#include <NativeReal.h>
#include <INTEGER.h>
#include <REAL.h>
#include <assert.h>

/*
 * NativeReal basic type description.
 */
static ber_tlv_tag_t asn1_DEF_NativeReal_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (9 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_NativeReal = {
	"REAL",			/* The ASN.1 type is still REAL */
	asn_generic_no_constraint,
	NativeReal_decode_ber,
	NativeReal_encode_der,
	NativeReal_print,
	NativeReal_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_NativeReal_tags,
	sizeof(asn1_DEF_NativeReal_tags) / sizeof(asn1_DEF_NativeReal_tags[0]),
	asn1_DEF_NativeReal_tags,	/* Same as above */
	sizeof(asn1_DEF_NativeReal_tags) / sizeof(asn1_DEF_NativeReal_tags[0]),
	0,	/* Always in primitive form */
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Decode REAL type.
 */
ber_dec_rval_t
NativeReal_decode_ber(asn1_TYPE_descriptor_t *td,
	void **dbl_ptr, void *buf_ptr, size_t size, int tag_mode) {
	double *Dbl = (double *)*dbl_ptr;
	ber_dec_rval_t rval;
	ber_dec_ctx_t ctx = { 0, 0, 0, 0 };
	ber_tlv_len_t length;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(Dbl == NULL) {
		(void *)Dbl = *dbl_ptr = CALLOC(1, sizeof(*Dbl));
		if(Dbl == NULL) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	ASN_DEBUG("Decoding %s as REAL (tm=%d)",
		td->name, tag_mode);

	/*
	 * Check tags.
	 */
	rval = ber_check_tags(td, &ctx,
		buf_ptr, size, tag_mode, &length, 0);
	if(rval.code != RC_OK)
		return rval;

	ASN_DEBUG("%s length is %d bytes", td->name, (int)length);

	/*
	 * Make sure we have this length.
	 */
	buf_ptr = ((char *)buf_ptr) + rval.consumed;
	size -= rval.consumed;
	if(length > (ber_tlv_len_t)size) {
		rval.code = RC_WMORE;
		rval.consumed = 0;
		return rval;
	}

	/*
	 * ASN.1 encoded REAL: buf_ptr, length
	 * Fill the Dbl, at the same time checking for overflow.
	 * If overflow occured, return with RC_FAIL.
	 */
	{
		REAL_t tmp;
		double d;
		tmp.buf = (uint8_t *)buf_ptr;
		tmp.size = length;

		if(asn1_REAL2double(&tmp, &d)) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}

		*Dbl = d;
	}

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s (%d)",
		(long)rval.consumed, (long)length, td->name, *Dbl);

	return rval;
}

/*
 * Encode the NativeReal using the standard REAL type DER encoder.
 */
der_enc_rval_t
NativeReal_encode_der(asn1_TYPE_descriptor_t *td, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	double Dbl = *(const double *)ptr;
	der_enc_rval_t erval;
	REAL_t tmp;

	if(asn1_double2REAL(&tmp, Dbl)) {
		erval.encoded = -1;
		erval.failed_type = td;
		erval.structure_ptr = ptr;
		return erval;
	}
	
	/* Encode fake REAL */
	erval = INTEGER_encode_der(td, &tmp, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		assert(erval.structure_ptr == &tmp);
		erval.structure_ptr = ptr;
	}
	return erval;
}

/*
 * REAL specific human-readable output.
 */
int
NativeReal_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const double *Dbl = (const double *)sptr;
	char scratch[64];
	int ret;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(Dbl) {
		char *p = scratch;
		int buf_size = sizeof(scratch);
	    for(;;) {
		ret = snprintf(p, buf_size, "%f", *Dbl);
		if(ret >= 0 && ret < buf_size) {
			ret = cb(p, ret, app_key);
			if(p != scratch) free(p);
			return ret;
		} else {
			if(p != scratch) free(p);
		}
		if(ret < 0) buf_size <<= 2;	/* Old libc. */
		else buf_size = ret + 1;
		(void *)p = MALLOC(ret);
		if(!p) return -1;
	    }
	} else {
		return cb("<absent>", 8, app_key);
	}
}

void
NativeReal_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {

	if(!td || !ptr)
		return;

	ASN_DEBUG("Freeing %s as REAL (%d, %p, Native)",
		td->name, contents_only, ptr);

	if(!contents_only) {
		FREEMEM(ptr);
	}
}

