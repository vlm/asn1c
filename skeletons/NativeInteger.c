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
#include <NativeInteger.h>
#include <INTEGER.h>
#include <assert.h>

/*
 * NativeInteger basic type description.
 */
static ber_tlv_tag_t asn1_DEF_NativeInteger_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_NativeInteger = {
	"INTEGER",			/* The ASN.1 type is still INTEGER */
	asn_generic_no_constraint,
	NativeInteger_decode_ber,
	NativeInteger_encode_der,
	NativeInteger_print,
	NativeInteger_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_NativeInteger_tags,
	sizeof(asn1_DEF_NativeInteger_tags)/sizeof(asn1_DEF_NativeInteger_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};

/*
 * Decode INTEGER type.
 */
ber_dec_rval_t
NativeInteger_decode_ber(asn1_TYPE_descriptor_t *td,
	void **int_ptr, void *buf_ptr, size_t size, int tag_mode) {
	int *Int = *int_ptr;
	ber_dec_rval_t rval;
	ber_dec_ctx_t ctx = { 0, 0, 0, 0 };
	ber_tlv_len_t length;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(Int == NULL) {
		Int = *int_ptr = CALLOC(1, sizeof(*Int));
		if(Int == NULL) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	ASN_DEBUG("Decoding %s as INTEGER (tm=%d)",
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
	buf_ptr += rval.consumed;
	size -= rval.consumed;
	if(length > (ber_tlv_len_t)size) {
		rval.code = RC_WMORE;
		rval.consumed = 0;
		return rval;
	}

	/*
	 * ASN.1 encoded INTEGER: buf_ptr, length
	 * Fill the Int, at the same time checking for overflow.
	 * If overflow occured, return with RC_FAIL.
	 */
	{
		INTEGER_t tmp;
		long l;
		tmp.buf = buf_ptr;
		tmp.size = length;

		if(asn1_INTEGER2long(&tmp, &l)) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}

		*Int = l;

		/*
		 * Note that int might be shorter than long.
		 * This expression hopefully will be optimized away
		 * by compiler.
		 */
		if(sizeof(int) != sizeof(long) && (*Int != l)) {
			*Int = 0;	/* Safe value */
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s (%d)",
		(long)rval.consumed, (long)length, td->name, *Int);

	return rval;
}

/*
 * Encode the NativeInteger using the standard INTEGER type DER encoder.
 */
der_enc_rval_t
NativeInteger_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	unsigned int Int = *(unsigned int *)ptr;	/* Disable sign ext. */
	der_enc_rval_t erval;
	INTEGER_t tmp;

#ifdef	WORDS_BIGENDIAN		/* Opportunistic optimization */

	tmp.buf = &Int;
	tmp.size = sizeof(Int);

#else	/* Works even if WORDS_BIGENDIAN is not set where should've been */
	uint8_t buf[sizeof(int)];
	uint8_t *p;

	/* Prepare fake INTEGER */
	for(p = buf + sizeof(buf) - 1; p >= buf; p--, Int >>= 8)
		*p = Int & 0xff;

	tmp.buf = buf;
	tmp.size = sizeof(buf);
#endif	/* WORDS_BIGENDIAN */
	
	/* Encode fake INTEGER */
	erval = INTEGER_encode_der(sd, &tmp, tag_mode, tag, cb, app_key);
	if(erval.encoded == -1) {
		assert(erval.structure_ptr == &tmp);
		erval.structure_ptr = ptr;
	}
	return erval;
}

/*
 * INTEGER specific human-readable output.
 */
int
NativeInteger_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const int *Int = sptr;
	char scratch[32];
	int ret;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(Int) {
		ret = snprintf(scratch, sizeof(scratch), "%d", *Int);
		assert(ret > 0 && ret < (int)sizeof(scratch));
		return cb(scratch, ret, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}

void
NativeInteger_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {

	if(!td || !ptr)
		return;

	ASN_DEBUG("Freeing %s as INTEGER (%d, %p, Native)",
		td->name, contents_only, ptr);

	if(!contents_only) {
		FREEMEM(ptr);
	}
}

