/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <constr_SET_OF.h>
#include <asn_SET_OF.h>

/*
 * Number of bytes left for this structure.
 * (ctx->left) indicates the number of bytes _transferred_ for the structure.
 * (size) contains the number of bytes in the buffer passed.
 */
#define	LEFT	((size<(size_t)ctx->left)?size:ctx->left)

/*
 * If the subprocessor function returns with an indication that it wants
 * more data, it may well be a fatal decoding problem, because the
 * size is constrained by the <TLV>'s L, even if the buffer size allows
 * reading more data.
 * For example, consider the buffer containing the following TLVs:
 * <T:5><L:1><V> <T:6>...
 * The TLV length clearly indicates that one byte is expected in V, but
 * if the V processor returns with "want more data" even if the buffer
 * contains way more data than the V processor have seen.
 */
#define	SIZE_VIOLATION	(ctx->left != -1 && (size_t)ctx->left <= size)

/*
 * This macro "eats" the part of the buffer which is definitely "consumed",
 * i.e. was correctly converted into local representation or rightfully skipped.
 */
#define	ADVANCE(num_bytes)	do {		\
		size_t num = num_bytes;		\
		(char *)ptr += num;		\
		size -= num;			\
		if(ctx->left >= 0)		\
			ctx->left -= num;	\
		consumed_myself += num;		\
	} while(0)

/*
 * Switch to the next phase of parsing.
 */
#define	NEXT_PHASE(ctx)	do {			\
		ctx->phase++;			\
		ctx->step = 0;			\
	} while(0)
#define	PHASE_OUT(ctx)	do { ctx->phase = 10; } while(0)

/*
 * Return a standardized complex structure.
 */
#define	RETURN(_code)	do {			\
		rval.code = _code;		\
		rval.consumed = consumed_myself;\
		return rval;			\
	} while(0)

/*
 * The decoder of the SET OF type.
 */
ber_dec_rval_t
SET_OF_decode_ber(asn1_TYPE_descriptor_t *sd,
	void **struct_ptr, void *ptr, size_t size, int tag_mode) {
	/*
	 * Bring closer parts of structure description.
	 */
	asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)sd->specifics;
	asn1_SET_OF_element_t *element = specs->element;

	/*
	 * Parts of the structure being constructed.
	 */
	void *st = *struct_ptr;	/* Target structure. */
	ber_dec_ctx_t *ctx;	/* Decoder context */

	ber_tlv_tag_t tlv_tag;	/* T from TLV */
	//ber_tlv_len_t tlv_len;	/* L from TLV */
	ber_dec_rval_t rval;	/* Return code from subparsers */

	ssize_t consumed_myself = 0;	/* Consumed bytes from ptr */

	ASN_DEBUG("Decoding %s as SET OF", sd->name);
	
	/*
	 * Create the target structure if it is not present already.
	 */
	if(st == 0) {
		st = *struct_ptr = CALLOC(1, specs->struct_size);
		if(st == 0) {
			RETURN(RC_FAIL);
		}
	}

	/*
	 * Restore parsing context.
	 */
	ctx = (ber_dec_ctx_t *)((char *)st + specs->ctx_offset);
	
	/*
	 * Start to parse where left previously
	 */
	switch(ctx->phase) {
	case 0:
		/*
		 * PHASE 0.
		 * Check that the set of tags associated with given structure
		 * perfectly fits our expectations.
		 */

		rval = ber_check_tags(sd, ctx, ptr, size,
			tag_mode, &ctx->left, 0);
		if(rval.code != RC_OK) {
			ASN_DEBUG("%s tagging check failed: %d",
				sd->name, rval.code);
			consumed_myself += rval.consumed;
			RETURN(rval.code);
		}

		if(ctx->left >= 0)
			ctx->left += rval.consumed; /* ?Substracted below! */
		ADVANCE(rval.consumed);

		ASN_DEBUG("Structure consumes %ld bytes, "
			"buffer %ld", (long)ctx->left, (long)size);

		NEXT_PHASE(ctx);
		/* Fall through */
	case 1:
		/*
		 * PHASE 1.
		 * From the place where we've left it previously,
		 * try to decode the next item.
		 */
	  for(;; ctx->step = 0) {
		ssize_t tag_len;	/* Length of TLV's T */

		if(ctx->step & 1)
			goto microphase2;

		/*
		 * MICROPHASE 1: Synchronize decoding.
		 */

		if(ctx->left == 0) {
			ASN_DEBUG("End of SET OF %s", sd->name);
			/*
			 * No more things to decode.
			 * Exit out of here.
			 */
			PHASE_OUT(ctx);
			RETURN(RC_OK);
		}

		/*
		 * Fetch the T from TLV.
		 */
		tag_len = ber_fetch_tag(ptr, LEFT, &tlv_tag);
		switch(tag_len) {
		case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
			/* Fall through */
		case -1: RETURN(RC_FAIL);
		}

		if(ctx->left < 0 && ((uint8_t *)ptr)[0] == 0) {
			if(LEFT < 2) {
				if(SIZE_VIOLATION)
					RETURN(RC_FAIL);
				else
					RETURN(RC_WMORE);
			} else if(((uint8_t *)ptr)[1] == 0) {
				/*
				 * Found the terminator of the
				 * indefinite length structure.
				 */
				break;
			}
		}

		/* Outmost tag may be unknown and cannot be fetched/compared */
		if(element->tag != (ber_tlv_tag_t)-1) {
		    if(BER_TAGS_EQUAL(tlv_tag, element->tag)) {
			/*
			 * The new list member of expected type has arrived.
			 */
		    } else {
			ASN_DEBUG("Unexpected tag %s fixed SET OF %s",
				ber_tlv_tag_string(tlv_tag), sd->name);
			ASN_DEBUG("%s SET OF has tag %s",
				sd->name, ber_tlv_tag_string(element->tag));
			RETURN(RC_FAIL);
		    }
		}

		/*
		 * MICROPHASE 2: Invoke the member-specific decoder.
		 */
		ctx->step |= 1;		/* Confirm entering next microphase */
	microphase2:
		
		/*
		 * Invoke the member fetch routine according to member's type
		 */
		rval = element->type->ber_decoder(element->type,
				&ctx->ptr, ptr, LEFT, 0);
		ASN_DEBUG("In %s SET OF %s code %d consumed %d",
			sd->name, element->type->name,
			rval.code, (int)rval.consumed);
		switch(rval.code) {
		case RC_OK:
			{
				A_SET_OF(void) *list;
				(void *)list = st;
				if(ASN_SET_ADD(list, ctx->ptr) != 0)
					RETURN(RC_FAIL);
				else
					ctx->ptr = 0;
			}
			break;
		case RC_WMORE: /* More data expected */
			if(!SIZE_VIOLATION) {
				ADVANCE(rval.consumed);
				RETURN(RC_WMORE);
			}
			/* Fall through */
		case RC_FAIL: /* Fatal error */
			RETURN(RC_FAIL);
		} /* switch(rval) */
		
		ADVANCE(rval.consumed);
	  }	/* for(all list members) */

		NEXT_PHASE(ctx);
	case 2:
		/*
		 * Read in all "end of content" TLVs.
		 */
		while(ctx->left < 0) {
			if(LEFT < 2) {
				if(LEFT > 0 && ((char *)ptr)[0] != 0) {
					/* Unexpected tag */
					RETURN(RC_FAIL);
				} else {
					RETURN(RC_WMORE);
				}
			}
			if(((char *)ptr)[0] == 0
			&& ((char *)ptr)[1] == 0) {
				ADVANCE(2);
				ctx->left++;
			} else {
				RETURN(RC_FAIL);
			}
		}

		PHASE_OUT(ctx);
	}
	
	RETURN(RC_OK);
}

/*
 * Internally visible buffer holding a single encoded element.
 */
struct _el_buffer {
	uint8_t *buf;
	size_t length;
	size_t size;
};
/* Append bytes to the above structure */
static int _el_addbytes(const void *buffer, size_t size, void *el_buf_ptr) {
	struct _el_buffer *el_buf = (struct _el_buffer *)el_buf_ptr;

	if(el_buf->length + size > el_buf->size)
		return -1;

	memcpy(el_buf->buf + el_buf->length, buffer, size);

	el_buf->length += size;
	return 0;
}
static int _el_buf_cmp(const void *ap, const void *bp) {
	const struct _el_buffer *a = (const struct _el_buffer *)ap;
	const struct _el_buffer *b = (const struct _el_buffer *)bp;
	int ret;
	size_t common_len;

	if(a->length < b->length)
		common_len = a->length;
	else
		common_len = b->length;

	ret = memcmp(a->buf, b->buf, common_len);
	if(ret == 0) {
		if(a->length < b->length)
			ret = -1;
		else if(a->length > b->length)
			ret = 1;
	}

	return ret;
}

/*
 * The DER encoder of the SET OF type.
 */
der_enc_rval_t
SET_OF_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)sd->specifics;
	asn1_SET_OF_element_t *elm = specs->element;
	asn1_TYPE_descriptor_t *elm_type = elm->type;
	der_type_encoder_f *der_encoder = elm_type->der_encoder;
	A_SET_OF(void) *list;
	size_t computed_size = 0;
	ssize_t encoding_size = 0;
	struct _el_buffer *encoded_els;
	size_t max_encoded_len = 1;
	der_enc_rval_t erval;
	int ret;
	int edx;

	ASN_DEBUG("Estimating size for SET OF %s", sd->name);

	/*
	 * Gather the length of the underlying members sequence.
	 */
	(void *)list = ptr;
	for(edx = 0; edx < list->count; edx++) {
		void *memb_ptr = list->array[edx];
		erval = der_encoder(elm_type, memb_ptr, 0, elm->tag, 0, 0);
		if(erval.encoded == -1)
			return erval;
		computed_size += erval.encoded;

		/* Compute maximum encoding's size */
		if(max_encoded_len < (size_t)erval.encoded)
			max_encoded_len = erval.encoded;
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

	/*
	 * DER mandates dynamic sorting of the SET OF elements
	 * according to their encodings. Build an array of the
	 * encoded elements.
	 */
	(void *)encoded_els = MALLOC(list->count * sizeof(encoded_els[0]));
	if(encoded_els == NULL) {
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
		return erval;
	}

	ASN_DEBUG("Encoding members of %s SET OF", sd->name);

	/*
	 * Encode all members.
	 */
	for(edx = 0; edx < list->count; edx++) {
		void *memb_ptr = list->array[edx];
		struct _el_buffer *encoded_el = &encoded_els[edx];

		/*
		 * Prepare space for encoding.
		 */
		encoded_el->buf = (uint8_t *)MALLOC(max_encoded_len);
		if(encoded_el->buf) {
			encoded_el->length = 0;
			encoded_el->size = max_encoded_len;
		} else {
			for(edx--; edx >= 0; edx--)
				FREEMEM(encoded_els[edx].buf);
			FREEMEM(encoded_els);
			erval.encoded = -1;
			erval.failed_type = sd;
			erval.structure_ptr = ptr;
			return erval;
		}

		/*
		 * Encode the member into the prepared space.
		 */
		erval = der_encoder(elm_type, memb_ptr, 0, elm->tag,
			_el_addbytes, encoded_el);
		if(erval.encoded == -1) {
			for(; edx >= 0; edx--)
				FREEMEM(encoded_els[edx].buf);
			FREEMEM(encoded_els);
			return erval;
		}
		encoding_size += erval.encoded;
	}

	/*
	 * Sort the encoded elements according to their encoding.
	 */
	qsort(encoded_els, list->count, sizeof(encoded_els[0]), _el_buf_cmp);

	/*
	 * Report encoded elements to the application.
	 * Dispose of temporary sorted members table.
	 */
	ret = 0;
	for(edx = 0; edx < list->count; edx++) {
		struct _el_buffer *encoded_el = &encoded_els[edx];
		/* Report encoded chunks to the application */
		if(ret == 0
		&& cb(encoded_el->buf, encoded_el->length, app_key) == -1)
			ret = -1;
		FREEMEM(encoded_el->buf);
	}
	FREEMEM(encoded_els);

	if(ret || computed_size != (size_t)encoding_size) {
		/*
		 * Standard callback failed, or
		 * encoded size is not equal to the computed size.
		 */
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
	} else {
		erval.encoded = computed_size;
	}

	return erval;
}

int
SET_OF_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)td->specifics;
	asn1_SET_OF_element_t *element = specs->element;
	const A_SET_OF(void) *list;
	int ret;
	int i;

	if(!sptr) return cb("<absent>", 8, app_key);

	/* Dump preamble */
	if(cb(td->name, strlen(td->name), app_key)
	|| cb(" ::= {\n", 7, app_key))
		return -1;

	(const void *)list = sptr;
	for(i = 0; i < list->count; i++) {
		const void *memb_ptr = list->array[i];
		if(!memb_ptr) continue;

		/* Indentation */
		for(ret = 0; ret < ilevel; ret++) cb(" ", 1, app_key);

		ret = element->type->print_struct(element->type, memb_ptr,
			ilevel + 4, cb, app_key);
		if(ret) return ret;

		ret = cb("\n", 1, app_key);
		if(ret) return ret;
	}

	/* Indentation */
	for(ret = 0; ret < ilevel - 4; ret++) cb(" ", 1, app_key);

	return cb("}", 1, app_key);
}

void
SET_OF_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {
	if(td && ptr) {
		asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)td->specifics;
		asn1_SET_OF_element_t *element = specs->element;
		A_SET_OF(void) *list;
		int i;

		/*
		 * Could not use set_of_empty() because of (*free)
		 * incompatibility.
		 */
		(void *)list = ptr;
		for(i = 0; i < list->count; i++) {
			void *memb_ptr = list->array[i];
			if(memb_ptr)
			element->type->free_struct(element->type, memb_ptr, 0);
		}
		list->count = 0;	/* No meaningful elements left */

		asn_set_empty(list);	/* Remove (list->array) */

		if(!contents_only) {
			FREEMEM(ptr);
		}
	}
}

int
SET_OF_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	asn1_SET_OF_specifics_t *specs = (asn1_SET_OF_specifics_t *)td->specifics;
	asn1_SET_OF_element_t *element = specs->element;
	const A_SET_OF(void) *list;
	int i;

	if(!sptr) {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	(const void *)list = sptr;

	for(i = 0; i < list->count; i++) {
		const void *memb_ptr = list->array[i];
		if(!memb_ptr) continue;
		return element->type->check_constraints(element->type, memb_ptr,
			app_errlog, app_key);
	}

	return 0;
}
