/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <asn_codecs_prim.h>
#include <assert.h>
#include <errno.h>

/*
 * Decode an always-primitive type.
 */
asn_dec_rval_t
ber_decode_primitive(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td,
	void **sptr, void *buf_ptr, size_t size, int tag_mode) {
	ASN__PRIMITIVE_TYPE_t *st = (ASN__PRIMITIVE_TYPE_t *)*sptr;
	asn_dec_rval_t rval;
	ber_tlv_len_t length;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(st == NULL) {
		(void *)st = *sptr = CALLOC(1, sizeof(*st));
		if(st == NULL) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	ASN_DEBUG("Decoding %s as plain primitive (tm=%d)",
		td->name, tag_mode);

	/*
	 * Check tags and extract value length.
	 */
	rval = ber_check_tags(opt_codec_ctx, td, 0, buf_ptr, size,
			tag_mode, 0, &length, 0);
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

	st->buf = (uint8_t *)MALLOC(length + 1);
	if(st->buf) {
		st->size = length;
	} else {
		rval.code = RC_FAIL;
		rval.consumed = 0;
		return rval;
	}

	memcpy(st->buf, buf_ptr, length);
	st->buf[length] = '\0';		/* Just in case */

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s",
		(long)rval.consumed,
		(long)length, td->name);

	return rval;
}

/*
 * Encode an always-primitive type using DER.
 */
asn_enc_rval_t
der_encode_primitive(asn_TYPE_descriptor_t *td, void *sptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;
	ASN__PRIMITIVE_TYPE_t *st = (ASN__PRIMITIVE_TYPE_t *)sptr;

	ASN_DEBUG("%s %s as a primitive type (tm=%d)",
		cb?"Encoding":"Estimating", td->name, tag_mode);

	erval.encoded = der_write_tags(td, st->size, tag_mode, 0, tag,
		cb, app_key);
	ASN_DEBUG("%s wrote tags %d", td->name, (int)erval.encoded);
	if(erval.encoded == -1) {
		erval.failed_type = td;
		erval.structure_ptr = sptr;
		return erval;
	}

	if(cb && st->buf) {
		if(cb(st->buf, st->size, app_key) < 0) {
			erval.encoded = -1;
			erval.failed_type = td;
			erval.structure_ptr = sptr;
			return erval;
		}
	} else {
		assert(st->buf || st->size == 0);
	}

	erval.encoded += st->size;

	return erval;
}

void
ASN__PRIMITIVE_TYPE_free(asn_TYPE_descriptor_t *td, void *sptr,
		int contents_only) {
	ASN__PRIMITIVE_TYPE_t *st = (ASN__PRIMITIVE_TYPE_t *)sptr;

	if(!td || !sptr)
		return;

	ASN_DEBUG("Freeing %s as a primitive type", td->name);

	if(st->buf)
		FREEMEM(st->buf);

	if(!contents_only)
		FREEMEM(st);
}


/*
 * Local internal type passed around as an argument.
 */
struct xdp_arg_s {
	ASN__PRIMITIVE_TYPE_t *sptr;
	ssize_t (*prim_body_decode)(ASN__PRIMITIVE_TYPE_t *sptr,
		void *chunk_buf, size_t chunk_size);
	int decoded_something;
	int want_more;
};

static int
xer_decode__unexpected_tag(void *key, void *chunk_buf, size_t chunk_size) {
	struct xdp_arg_s *arg = (struct xdp_arg_s *)key;
	ssize_t decoded;

	if(arg->decoded_something) {
		/*
		 * Decoding was done once already. Prohibit doing it again.
		 */
		return -1;
	}

	decoded = arg->prim_body_decode(arg->sptr, chunk_buf, chunk_size);
	if(decoded < 0) {
		return -1;
	} else {
		/* Tag decoded successfully */
		arg->decoded_something = 1;
		return 0;
	}
}

static ssize_t
xer_decode__body(void *key, void *chunk_buf, size_t chunk_size, int have_more) {
	struct xdp_arg_s *arg = (struct xdp_arg_s *)key;
	ssize_t decoded;

	if(arg->decoded_something) {
		/*
		 * Decoding was done once already. Prohibit doing it again.
		 */
		return -1;
	}

	if(!have_more) {
		/*
		 * If we've received something like "1", we can't really
		 * tell whether it is really `1` or `123`, until we know
		 * that there is no more data coming.
		 * The have_more argument will be set to 1 once something
		 * like this is available to the caller of this callback:
		 * "1<tag_start..."
		 */
		arg->want_more = 1;
		return -1;
	}

	decoded = arg->prim_body_decode(arg->sptr, chunk_buf, chunk_size);
	if(decoded < 0) {
		return -1;
	} else {
		arg->decoded_something = 1;
		return decoded;
	}
}


asn_dec_rval_t
xer_decode_primitive(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td,
	ASN__PRIMITIVE_TYPE_t **sptr,
	const char *opt_mname,
	void *buf_ptr, size_t size,
	ssize_t (*prim_body_decode)(ASN__PRIMITIVE_TYPE_t *sptr,
		void *chunk_buf, size_t chunk_size)
) {
	const char *xml_tag = opt_mname ? opt_mname : td->xml_tag;
	asn_struct_ctx_t s_ctx;
	struct xdp_arg_s s_arg;
	asn_dec_rval_t rc;

	/*
	 * Create the structure if does not exist.
	 */
	if(!*sptr) {
		*sptr = CALLOC(1, sizeof(ASN__PRIMITIVE_TYPE_t));
		if(!*sptr) {
			asn_dec_rval_t rval;
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	memset(&s_ctx, 0, sizeof(s_ctx));
	s_arg.sptr = *sptr;
	s_arg.prim_body_decode = prim_body_decode;
	s_arg.decoded_something = 0;
	s_arg.want_more = 0;

	rc = xer_decode_general(opt_codec_ctx, &s_ctx, &s_arg,
		xml_tag, buf_ptr, size,
		xer_decode__unexpected_tag, xer_decode__body);
	switch(rc.code) {
	case RC_OK:
		if(!s_arg.decoded_something) {
			/* Opportunity has come and gone. Where's the result? */
			rc.code = RC_FAIL;
			rc.consumed = 0;
		}
		break;
	case RC_WMORE:
		/*
		 * Redo the whole thing later.
		 * We don't have a context to save intermediate parsing state.
		 */
		rc.consumed = 0;
		break;
	case RC_FAIL:
		rc.consumed = 0;
		if(s_arg.want_more)
			rc.code = RC_WMORE;
		break;
	}
	return rc;
}

