/*-
 * Copyright (c) 2004-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
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
#include <math.h>

#if defined(__clang__)
/*
 * isnan() is defined using generic selections and won't compile in
 * strict C89 mode because of too fancy system's standard library.
 * However, prior to C11 the math had a perfectly working isnan()
 * in the math library.
 * Disable generic selection warning so we can test C89 mode with newer libc.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions"
static int asn_isnan(double d) {
    return isnan(d);
}
#pragma clang diagnostic pop
#else
#define asn_isnan(v)    isnan(v)
#endif  /* generic selections */

/*
 * NativeReal basic type description.
 */
static const ber_tlv_tag_t asn_DEF_NativeReal_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (9 << 2))
};
asn_TYPE_operation_t asn_OP_NativeReal = {
	NativeReal_free,
	NativeReal_print,
	NativeReal_compare,
	NativeReal_decode_ber,
	NativeReal_encode_der,
	NativeReal_decode_xer,
	NativeReal_encode_xer,
#ifdef	ASN_DISABLE_OER_SUPPORT
	0,
	0,
#else
	NativeReal_decode_oer,
	NativeReal_encode_oer,
#endif  /* ASN_DISABLE_OER_SUPPORT */
#ifdef	ASN_DISABLE_PER_SUPPORT
	0,
	0,
#else
	NativeReal_decode_uper,
	NativeReal_encode_uper,
#endif	/* ASN_DISABLE_PER_SUPPORT */
	NativeReal_random_fill,
	0	/* Use generic outmost tag fetcher */
};
asn_TYPE_descriptor_t asn_DEF_NativeReal = {
	"REAL",			/* The ASN.1 type is still REAL */
	"REAL",
	&asn_OP_NativeReal,
	asn_DEF_NativeReal_tags,
	sizeof(asn_DEF_NativeReal_tags) / sizeof(asn_DEF_NativeReal_tags[0]),
	asn_DEF_NativeReal_tags,	/* Same as above */
	sizeof(asn_DEF_NativeReal_tags) / sizeof(asn_DEF_NativeReal_tags[0]),
	{ 0, 0, asn_generic_no_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Decode REAL type.
 */
asn_dec_rval_t
NativeReal_decode_ber(const asn_codec_ctx_t *opt_codec_ctx,
                      asn_TYPE_descriptor_t *td, void **dbl_ptr,
                      const void *buf_ptr, size_t size, int tag_mode) {
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

    ASN_DEBUG("Decoding %s as REAL (tm=%d)", td->name, tag_mode);

    /*
     * Check tags.
     */
    rval = ber_check_tags(opt_codec_ctx, td, 0, buf_ptr, size, tag_mode, 0,
                          &length, 0);
    if(rval.code != RC_OK) return rval;
    assert(length >= 0);    /* Ensured by ber_check_tags */

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
        uint8_t scratch[24]; /* Longer than %.16f in decimal */
        REAL_t tmp;
        double d;
        int ret;

        if((size_t)length < sizeof(scratch)) {
            tmp.buf = scratch;
            tmp.size = length;
        } else {
            /* This rarely happens: impractically long value */
            tmp.buf = CALLOC(1, length + 1);
            tmp.size = length;
            if(!tmp.buf) {
                rval.code = RC_FAIL;
                rval.consumed = 0;
                return rval;
            }
        }

        memcpy(tmp.buf, buf_ptr, length);
        tmp.buf[length] = '\0';

        ret = asn_REAL2double(&tmp, &d);
        if(tmp.buf != scratch) FREEMEM(tmp.buf);
        if(ret) {
            rval.code = RC_FAIL;
            rval.consumed = 0;
            return rval;
        }

        *Dbl = d;
    }

    rval.code = RC_OK;
    rval.consumed += length;

    ASN_DEBUG("Took %ld/%ld bytes to encode %s (%f)", (long)rval.consumed,
              (long)length, td->name, *Dbl);

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

#ifndef ASN_DISABLE_PER_SUPPORT

/*
 * Decode REAL type using PER.
 */
asn_dec_rval_t
NativeReal_decode_uper(const asn_codec_ctx_t *opt_codec_ctx,
                       asn_TYPE_descriptor_t *td,
                       const asn_per_constraints_t *constraints, void **dbl_ptr,
                       asn_per_data_t *pd) {
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
                       const asn_per_constraints_t *constraints, void *sptr,
                       asn_per_outp_t *po) {
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

#endif /* ASN_DISABLE_PER_SUPPORT */

#ifndef ASN_DISABLE_OER_SUPPORT

/*
 * Encode as Canonical OER.
 */
asn_enc_rval_t
NativeReal_encode_oer(asn_TYPE_descriptor_t *td,
                   const asn_oer_constraints_t *constraints, void *sptr,
                   asn_app_consume_bytes_f *cb, void *app_key) {
    asn_enc_rval_t er = { 0, 0, 0 };
    ssize_t len_len;
    const double *d = sptr;
    REAL_t tmp;

	/* Prepare a temporary clean structure */
	memset(&tmp, 0, sizeof(tmp));

    (void)td;
    (void)constraints;  /* Constraints are unused in OER */

    if(asn_double2REAL(&tmp, *d)) {
        ASN__ENCODE_FAILED;
	}

    /* Encode a fake REAL */
    len_len = oer_serialize_length(tmp.size, cb, app_key);
    if(len_len < 0 || cb(tmp.buf, tmp.size, app_key) < 0) {
        ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);
        ASN__ENCODE_FAILED;
    } else {
        er.encoded = len_len + tmp.size;
        ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_REAL, &tmp);
        ASN__ENCODED_OK(er);
    }
}

asn_dec_rval_t
NativeReal_decode_oer(const asn_codec_ctx_t *opt_codec_ctx,
                        asn_TYPE_descriptor_t *td,
                        const asn_oer_constraints_t *constraints, void **sptr,
                        const void *ptr, size_t size) {
    asn_dec_rval_t ok = {RC_OK, 0};
    double *st;
    double d;
    ssize_t len_len;
    size_t real_body_len;

    (void)opt_codec_ctx;
    (void)td;
    (void)constraints; /* Constraints are unused in OER */

    len_len = oer_fetch_length(ptr, size, &real_body_len);
    if(len_len < 0) ASN__DECODE_FAILED;
    if(len_len == 0) ASN__DECODE_STARVED;

    ptr = (const char *)ptr + len_len;
    size -= len_len;

    if(real_body_len > size) ASN__DECODE_STARVED;

    {
        uint8_t scratch[24]; /* Longer than %.16f in decimal */
        REAL_t tmp;
        int ret;

        if(real_body_len < sizeof(scratch)) {
            tmp.buf = scratch;
            tmp.size = real_body_len;
        } else {
            /* This rarely happens: impractically long value */
            tmp.buf = CALLOC(1, real_body_len + 1);
            tmp.size = real_body_len;
            if(!tmp.buf) {
                ASN__DECODE_FAILED;
            }
        }

        memcpy(tmp.buf, ptr, real_body_len);
        tmp.buf[real_body_len] = '\0';

        ret = asn_REAL2double(&tmp, &d);
        if(tmp.buf != scratch) FREEMEM(tmp.buf);
        if(ret) {
            ASN_DEBUG("REAL decoded in %zu bytes, but can't convert t double",
                      real_body_len);
            ASN__DECODE_FAILED;
        }
    }

    if(!(st = *sptr)) {
        st = (double *)(*sptr = CALLOC(1, sizeof(*st)));
        if(!st) ASN__DECODE_FAILED;
    }

    *st = d;
    ok.consumed = len_len + real_body_len;
    return ok;
}

#endif /* ASN_DISABLE_OER_SUPPORT */

/*
 * Decode the chunk of XML text encoding REAL.
 */
asn_dec_rval_t
NativeReal_decode_xer(const asn_codec_ctx_t *opt_codec_ctx,
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

int
NativeReal_compare(const asn_TYPE_descriptor_t *td, const void *aptr,
                   const void *bptr) {
    const double *a = aptr;
    const double *b = bptr;
    (void)td;

    if(a && b) {
        /* NaN sorted above everything else */
        if(asn_isnan(*a)) {
            if(asn_isnan(*b)) {
                return 0;
            } else {
                return -1;
            }
        } else if(asn_isnan(*b)) {
            return 1;
        }
        /* Value comparison. */
        if(*a < *b) {
            return -1;
        } else if(*a > *b) {
            return 1;
        } else {
            return 0;
        }
    } else if(!a) {
        return -1;
    } else {
        return 1;
    }
}

void
NativeReal_free(const asn_TYPE_descriptor_t *td, void *ptr,
                enum asn_struct_free_method method) {
    if(!td || !ptr)
		return;

	ASN_DEBUG("Freeing %s as REAL (%d, %p, Native)",
		td->name, method, ptr);

    switch(method) {
    case ASFM_FREE_EVERYTHING:
        FREEMEM(ptr);
        break;
    case ASFM_FREE_UNDERLYING:
        break;
    case ASFM_FREE_UNDERLYING_AND_RESET:
        memset(ptr, 0, sizeof(double));
        break;
    }
}


asn_random_fill_result_t
NativeReal_random_fill(const asn_TYPE_descriptor_t *td, void **sptr,
                       const asn_encoding_constraints_t *constraints,
                       size_t max_length) {
    asn_random_fill_result_t result_ok = {ARFILL_OK, sizeof(double)};
    asn_random_fill_result_t result_failed = {ARFILL_FAILED, 0};
    asn_random_fill_result_t result_skipped = {ARFILL_SKIPPED, 0};
    static const double values[] = {
        0, -0.0, -1, 1, -M_E, M_E, -3.14, 3.14, -M_PI, M_PI, -255, 255,
        /* 2^51 */
        -2251799813685248.0, 2251799813685248.0,
        /* 2^52 */
        -4503599627370496.0, 4503599627370496.0,
        /* 2^100 */
        -1267650600228229401496703205376.0, 1267650600228229401496703205376.0,
#if __STDC_VERSION__ >= 199901L
        -MAXFLOAT, MAXFLOAT,
#endif
        INFINITY, -INFINITY, NAN};
    double *st;
    double d;

    (void)td;
    (void)constraints;

    if(max_length == 0) return result_skipped;

    d = values[asn_random_between(0, sizeof(values) / sizeof(values[0]) - 1)];

    if(*sptr) {
        st = *sptr;
    } else {
        st = (double *)(*sptr = CALLOC(1, sizeof(double)));
        if(!st) {
            return result_failed;
        }
    }

    *st = d;

    return result_ok;
}
