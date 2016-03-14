/*-
 * Copyright (c) 2004, 2006 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Read the NativeReal.h for the explanation wrt. differences between
 * REAL and NativeReal.
 * Basically, both are decoders and encoders of ASN.1 REAL type, but this
 * implementation deals with the standard (machine-specific) representation
 * of them instead of using the platform-independent buffer.
 */
#include <asn_internal.h>
#include <NativeReal.h>
#include <REAL.h>
#include <OCTET_STRING.h>

/*
 * NativeReal basic type description.
 */
static const ber_tlv_tag_t asn_DEF_NativeReal_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (9 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NativeReal = {
	"REAL",			/* The ASN.1 type is still REAL */
	"REAL",
	NativeReal_free,
	NativeReal_print,
	asn_generic_no_constraint,
	NativeReal_decode_ber,
	NativeReal_encode_der,
	NativeReal_decode_xer,
	NativeReal_encode_xer,
	NativeReal_decode_uper,
	NativeReal_encode_uper,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_NativeReal_tags,
	sizeof(asn_DEF_NativeReal_tags) / sizeof(asn_DEF_NativeReal_tags[0]),
	asn_DEF_NativeReal_tags,	/* Same as above */
	sizeof(asn_DEF_NativeReal_tags) / sizeof(asn_DEF_NativeReal_tags[0]),
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Decode REAL type.
 */
asn_dec_rval_t
NativeReal_decode_ber(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td,
	void **dbl_ptr, const void *buf_ptr, size_t size, int tag_mode) {
	double *Dbl = (double *)*dbl_ptr;
	asn_dec_rval_t rval;
	ber_tlv_len_t length;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(Dbl == NULL) {
		*dbl_ptr = CALLOC(1, sizeof(*Dbl));
		Dbl = (double *)*dbl_ptr;
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
	rval = ber_check_tags(opt_codec_ctx, td, 0, buf_ptr, size,
			tag_mode, 0, &length, 0);
	if(rval.code != RC_OK)
		return rval;

	ASN_DEBUG("%s length is %d bytes", td->name, (int)length);

	/*
	 * Make sure we have this length.
	 */
	buf_ptr = ((const char *)buf_ptr) + rval.consumed;
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
		union {
			const void *constbuf;
			void *nonconstbuf;
		} unconst_buf;
		double d;

		unconst_buf.constbuf = buf_ptr;
		tmp.buf = (uint8_t *)unconst_buf.nonconstbuf;
		tmp.size = length;

		if(length < (ber_tlv_len_t)size) {
			int ret;
			uint8_t saved_byte = tmp.buf[tmp.size];
			tmp.buf[tmp.size] = '\0';
			ret = asn_REAL2double(&tmp, &d);
			tmp.buf[tmp.size] = saved_byte;
			if(ret) {
				rval.code = RC_FAIL;
				rval.consumed = 0;
				return rval;
			}
		} else if(length < 48 /* Enough for longish %f value. */) {
			tmp.buf = alloca(length + 1);
			tmp.size = length;
			memcpy(tmp.buf, buf_ptr, length);
			tmp.buf[tmp.size] = '\0';
			if(asn_REAL2double(&tmp, &d)) {
				rval.code = RC_FAIL;
				rval.consumed = 0;
				return rval;
			}
		} else {
			/* This should probably never happen: impractically long value */
			tmp.buf = CALLOC(1, length + 1);
			tmp.size = length;
			if(tmp.buf) memcpy(tmp.buf, buf_ptr, length);
			if(!tmp.buf || asn_REAL2double(&tmp, &d)) {
				FREEMEM(tmp.buf);
				rval.code = RC_FAIL;
				rval.consumed = 0;
				return rval;
			}
			FREEMEM(tmp.buf);
		}

		*Dbl = d;
	}

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s (%f)",
		(long)rval.consumed, (long)length, td->name, *Dbl);

	return rval;
}

/*
 * Encode the NativeReal using the standard REAL type DER encoder.
 */
asn_enc_rval_t
NativeReal_encode_der(asn_TYPE_descriptor_t *td, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	double Dbl = *(const double *)ptr;
	asn_enc_rval_t erval;
	REAL_t tmp;

	/* Prepare a temporary clean structure */
	memset(&tmp, 0, sizeof(tmp));

	if(asn_double2REAL(&tmp, Dbl)) {
		erval.encoded = -1;
		erval.failed_type = td;
		erval.structure_ptr = ptr;
		return erval;
	}
	
	/* Encode a fake REAL */
	erval = der_encode_primitive(td, &tmp, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		assert(erval.structure_ptr == &tmp);
		erval.structure_ptr = ptr;
	}

	/* Free possibly allocated members of the temporary structure */
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);

	return erval;
}

/*
 * Decode REAL type using PER.
 */
asn_dec_rval_t
NativeReal_decode_uper(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td, asn_per_constraints_t *constraints,
		void **dbl_ptr, asn_per_data_t *pd) {
	double *Dbl = (double *)*dbl_ptr;
	asn_dec_rval_t rval;
	REAL_t tmp;
	void *ptmp = &tmp;
	int ret;

	(void)constraints;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(Dbl == NULL) {
		*dbl_ptr = CALLOC(1, sizeof(*Dbl));
		Dbl = (double *)*dbl_ptr;
		if(Dbl == NULL)
			ASN__DECODE_FAILED;
	}

	memset(&tmp, 0, sizeof(tmp));
	rval = OCTET_STRING_decode_uper(opt_codec_ctx, td, NULL,
			&ptmp, pd);
	if(rval.code != RC_OK) {
		ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);
		return rval;
	}

	ret = asn_REAL2double(&tmp, Dbl);
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);
	if(ret) ASN__DECODE_FAILED;

	return rval;
}

/*
 * Encode the NativeReal using the OCTET STRING PER encoder.
 */
asn_enc_rval_t
NativeReal_encode_uper(asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void *sptr, asn_per_outp_t *po) {
	double Dbl = *(const double *)sptr;
	asn_enc_rval_t erval;
	REAL_t tmp;

	(void)constraints;

	/* Prepare a temporary clean structure */
	memset(&tmp, 0, sizeof(tmp));

	if(asn_double2REAL(&tmp, Dbl))
		ASN__ENCODE_FAILED;
	
	/* Encode a DER REAL */
	erval = OCTET_STRING_encode_uper(td, NULL, &tmp, po);
	if(erval.encoded == -1)
		erval.structure_ptr = sptr;

	/* Free possibly allocated members of the temporary structure */
	ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);

	return erval;
}

/*
 * Decode the chunk of XML text encoding REAL.
 */
asn_dec_rval_t
NativeReal_decode_xer(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td, void **sptr, const char *opt_mname,
		const void *buf_ptr, size_t size) {
	asn_dec_rval_t rval;
	REAL_t *st = 0;
	REAL_t **stp = &st;
	double *Dbl = (double *)*sptr;

	if(!Dbl) {
		*sptr = CALLOC(1, sizeof(double));
		Dbl = (double *)*sptr;
		if(!Dbl) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	rval = REAL_decode_xer(opt_codec_ctx, td, (void **)stp, opt_mname,
		buf_ptr, size);
	if(rval.code == RC_OK) {
		if(asn_REAL2double(st, Dbl)) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
		}
	} else {
		rval.consumed = 0;
	}
	ASN_STRUCT_FREE(asn_DEF_REAL, st);
	return rval;
}

asn_enc_rval_t
NativeReal_encode_xer(asn_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const double *Dbl = (const double *)sptr;
	asn_enc_rval_t er;

	(void)ilevel;

	if(!Dbl) ASN__ENCODE_FAILED;

	er.encoded = REAL__dump(*Dbl, flags & XER_F_CANONICAL, cb, app_key);
	if(er.encoded < 0) ASN__ENCODE_FAILED;

	ASN__ENCODED_OK(er);
}

/*
 * REAL specific human-readable output.
 */
int
NativeReal_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const double *Dbl = (const double *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!Dbl) return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;

	return (REAL__dump(*Dbl, 0, cb, app_key) < 0) ? -1 : 0;
}

void
NativeReal_free(asn_TYPE_descriptor_t *td, void *ptr, int contents_only) {

	if(!td || !ptr)
		return;

	ASN_DEBUG("Freeing %s as REAL (%d, %p, Native)",
		td->name, contents_only, ptr);

	if(!contents_only) {
		FREEMEM(ptr);
	}
}

