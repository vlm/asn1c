/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <constr_SEQUENCE.h>

/*
 * Number of bytes left for this structure.
 * (ctx->left) indicates the number of bytes _transferred_ for the structure.
 * (size) contains the number of bytes in the buffer passed.
 */
#define	LEFT	((size<ctx->left)?size:ctx->left)

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
#define	SIZE_VIOLATION	(ctx->left >= 0 && ctx->left <= size)

/*
 * This macro "eats" the part of the buffer which is definitely "consumed",
 * i.e. was correctly converted into local representation or rightfully skipped.
 */
#define	ADVANCE(num_bytes)	do {		\
		size_t num = num_bytes;		\
		ptr += num;			\
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
 * Check whether we are inside the extensions group.
 */
#define	IN_EXTENSION_GROUP(specs, memb_idx)	\
	( ((memb_idx) > (specs)->ext_after)	\
	&&((memb_idx) < (specs)->ext_before))

/*
 * The decoder of the SEQUENCE type.
 */
ber_dec_rval_t
SEQUENCE_decode_ber(asn1_TYPE_descriptor_t *sd,
	void **struct_ptr, void *ptr, size_t size, int tag_mode) {
	/*
	 * Bring closer parts of structure description.
	 */
	asn1_SEQUENCE_specifics_t *specs = sd->specifics;
	asn1_SEQUENCE_element_t *elements = specs->elements;

	/*
	 * Parts of the structure being constructed.
	 */
	void *st = *struct_ptr;	/* Target structure. */
	ber_dec_ctx_t *ctx;	/* Decoder context */

	ber_tlv_tag_t tlv_tag;	/* T from TLV */
	//ber_tlv_len_t tlv_len;	/* L from TLV */
	ber_dec_rval_t rval;	/* Return code from subparsers */

	ssize_t consumed_myself = 0;	/* Consumed bytes from ptr */
	int edx;			/* SEQUENCE element's index */

	ASN_DEBUG("Decoding %s as SEQUENCE", sd->name);
	
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
	ctx = (st + specs->ctx_offset);
	
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

		NEXT_PHASE(ctx);

		ASN_DEBUG("Structure consumes %ld bytes, buffer %ld",
			(long)ctx->left, (long)size);

		/* Fall through */
	case 1:
		/*
		 * PHASE 1.
		 * From the place where we've left it previously,
		 * try to decode the next member from the list of
		 * this structure's elements.
		 * (ctx->step) stores the member being processed
		 * between invocations and the microphase {0,1} of parsing
		 * that member:
		 * 	step = (<member_number> * 2 + <microphase>).
		 */
	  for(edx = (ctx->step >> 1); edx < specs->elements_count;
			edx++, ctx->step = (ctx->step & ~1) + 2) {
		void *memb_ptr;		/* Pointer to the member */
		void *memb_ptr2;	/* Pointer to that pointer */
		ssize_t tag_len;	/* Length of TLV's T */
		int opt_edx_end;	/* Next non-optional element */
		int n;

		if(ctx->step & 1)
			goto microphase2;

		/*
		 * MICROPHASE 1: Synchronize decoding.
		 */
		ASN_DEBUG("In %s SEQUENCE left %d, edx=%d opt=%d ec=%d",
			sd->name, (int)ctx->left,
			edx, elements[edx].optional, specs->elements_count);

		if(ctx->left == 0	/* No more stuff is expected */
		&& (
			/* Explicit OPTIONAL specification reaches the end */
			(edx + elements[edx].optional == specs->elements_count)
			||
			/* All extensions are optional */
			(IN_EXTENSION_GROUP(specs, edx)
				&& specs->ext_before > specs->elements_count)
		   )
		) {
			ASN_DEBUG("End of SEQUENCE %s", sd->name);
			/*
			 * Found the legitimate end of the structure.
			 */
			PHASE_OUT(ctx);
			RETURN(RC_OK);
		}

		/*
		 * Fetch the T from TLV.
		 */
		tag_len = ber_fetch_tag(ptr, LEFT, &tlv_tag);
		ASN_DEBUG("In %s SEQUENCE for %d %s next tag length %d",
			sd->name, edx, elements[edx].name, (int)tag_len);
		switch(tag_len) {
		case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
			/* Fall through */
		case -1: RETURN(RC_FAIL);
		}

		/*
		 * Find the next available type with this tag.
		 */
		opt_edx_end = edx + elements[edx].optional + 1;
		if(opt_edx_end > specs->elements_count)
			opt_edx_end = specs->elements_count;	/* Cap */
		for(n = edx; n < opt_edx_end; n++) {
			if(BER_TAGS_EQUAL(tlv_tag, elements[n].tag)) {
				/*
				 * Found element corresponding to the tag
				 * being looked at.
				 * Reposition over the right element.
				 */
				edx = n;
				ctx->step = 2 * edx;	/* Remember! */
				break;
			}
		}
		if(n == opt_edx_end) {
			/*
			 * If tag is unknown, it may be either
			 * an unknown (thus, incorrect) tag,
			 * or an extension (...),
			 * or an end of the indefinite-length structure.
			 */

			if(!IN_EXTENSION_GROUP(specs, edx)) {
				ASN_DEBUG("Unexpected tag %s",
					ber_tlv_tag_string(tlv_tag));
				ASN_DEBUG("Expected tag %s%s",
					ber_tlv_tag_string(elements[edx].tag),
					elements[edx].optional
						?" or alternatives":"");
				RETURN(RC_FAIL);
			}

			if(ctx->left < 0
				&& ((uint8_t *)ptr)[0] == 0) {
				if(LEFT < 2) {
					if(SIZE_VIOLATION)
						RETURN(RC_FAIL);
					else
						RETURN(RC_WMORE);
				} else if(((uint8_t *)ptr)[1] == 0) {
					/*
					 * Yeah, baby! Found the terminator
					 * of the indefinite length structure.
					 */
					/*
					 * Proceed to the canonical
					 * finalization function.
					 * No advancing is necessary.
					 */
					goto phase3;
				}
			} else {
				/* Skip this tag */
				ssize_t skip;

				skip = ber_skip_length(
					BER_TLV_CONSTRUCTED(ptr),
					ptr + tag_len, LEFT - tag_len);
				ASN_DEBUG("Skip length %d in %s",
					(int)skip, sd->name);
				switch(skip) {
				case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
					/* Fall through */
				case -1: RETURN(RC_FAIL);
				}

				ADVANCE(skip + tag_len);
				ctx->step -= 2;
				edx--;
				continue;  /* Try again with the next tag */
			}
		}

		/*
		 * MICROPHASE 2: Invoke the member-specific decoder.
		 */
		ctx->step |= 1;		/* Confirm entering next microphase */
	microphase2:
		ASN_DEBUG("Inside SEQUENCE %s MF2", sd->name);
		
		/*
		 * Compute the position of the member inside a structure,
		 * and also a type of containment (it may be contained
		 * as pointer or using inline inclusion).
		 */
		if(elements[edx].optional) {
			/* Optional member, hereby, a simple pointer */
			memb_ptr2 = (char *)st + elements[edx].memb_offset;
		} else {
			/*
			 * A pointer to a pointer
			 * holding the start of the structure
			 */
			memb_ptr = (char *)st + elements[edx].memb_offset;
			memb_ptr2 = &memb_ptr;
		}
		/*
		 * Invoke the member fetch routine according to member's type
		 */
		rval = elements[edx].type->ber_decoder(
				(void *)elements[edx].type,
				memb_ptr2, ptr, LEFT,
				elements[edx].tag_mode);
		ASN_DEBUG("In %s SEQUENCE decoded %d %s in %d bytes code %d",
			sd->name, edx, elements[edx].type->name,
			(int)rval.consumed, rval.code);
		switch(rval.code) {
		case RC_OK:
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
	  }	/* for(all structure members) */

	phase3:
		ctx->phase = 3;
	case 3:	/* 00 and other tags expected */
	case 4:	/* only 00's expected */

		ASN_DEBUG("SEQUENCE %s Leftover: %ld, size = %ld",
			sd->name, (long)ctx->left, (long)size);

		/*
		 * Skip everything until the end of the SEQUENCE.
		 */
		while(ctx->left) {
			ssize_t tl, ll;

			tl = ber_fetch_tag(ptr, LEFT, &tlv_tag);
			switch(tl) {
			case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
				/* Fall through */
			case -1: RETURN(RC_FAIL);
			}

			/*
			 * If expected <0><0>...
			 */
			if(ctx->left < 0
				&& ((uint8_t *)ptr)[0] == 0) {
				if(LEFT < 2) {
					if(SIZE_VIOLATION)
						RETURN(RC_FAIL);
					else
						RETURN(RC_WMORE);
				} else if(((uint8_t *)ptr)[1] == 0) {
					/*
					 * Correctly finished with <0><0>.
					 */
					ADVANCE(2);
					ctx->left++;
					ctx->phase = 4;
					continue;
				}
			}

			if(!IN_EXTENSION_GROUP(specs, specs->elements_count)
			|| ctx->phase == 4) {
				ASN_DEBUG("Unexpected continuation "
					"of a non-extensible type "
					"%s (SEQUENCE): %s",
					sd->name,
					ber_tlv_tag_string(tlv_tag));
				RETURN(RC_FAIL);
			}

			ll = ber_skip_length(
				BER_TLV_CONSTRUCTED(ptr),
				ptr + tl, LEFT - tl);
			switch(ll) {
			case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
				/* Fall through */
			case -1: RETURN(RC_FAIL);
			}

			ADVANCE(tl + ll);
		}

		PHASE_OUT(ctx);
	}
	
	RETURN(RC_OK);
}

/*
 * The DER encoder of the SEQUENCE type.
 */
der_enc_rval_t
SEQUENCE_encode_der(asn1_TYPE_descriptor_t *sd,
	void *ptr, int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_SEQUENCE_specifics_t *specs = sd->specifics;
	size_t computed_size = 0;
	der_enc_rval_t erval;
	ssize_t ret;
	int edx;

	ASN_DEBUG("%s %s as SEQUENCE",
		cb?"Encoding":"Estimating", sd->name);

	/*
	 * Gather the length of the underlying members sequence.
	 */
	for(edx = 0; edx < specs->elements_count; edx++) {
		asn1_SEQUENCE_element_t *elm = &specs->elements[edx];
		void *memb_ptr;
		if(elm->optional) {
			memb_ptr = *(void **)((char *)ptr + elm->memb_offset);
			if(!memb_ptr) continue;
		} else {
			memb_ptr = (void *)((char *)ptr + elm->memb_offset);
		}
		erval = elm->type->der_encoder(elm->type, memb_ptr,
			elm->tag_mode, elm->tag,
			0, 0);
		if(erval.encoded == -1)
			return erval;
		computed_size += erval.encoded;
		ASN_DEBUG("Member %d %s estimated %ld bytes",
			edx, elm->name, (long)erval.encoded);
	}

	/*
	 * Encode the TLV for the sequence itself.
	 */
	ret = der_write_tags(sd, computed_size, tag_mode, tag, cb, app_key);
	ASN_DEBUG("Wrote tags: %ld (+%ld)", (long)ret, (long)computed_size);
	if(ret == -1) {
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
		return erval;
	}
	erval.encoded = computed_size + ret;

	if(!cb) return erval;

	/*
	 * Encode all members.
	 */
	for(edx = 0; edx < specs->elements_count; edx++) {
		asn1_SEQUENCE_element_t *elm = &specs->elements[edx];
		der_enc_rval_t tmperval;
		void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(void **)((char *)ptr + elm->memb_offset);
			if(!memb_ptr) continue;
		} else {
			memb_ptr = (void *)((char *)ptr + elm->memb_offset);
		}
		tmperval = elm->type->der_encoder(elm->type, memb_ptr,
			elm->tag_mode, elm->tag,
			cb, app_key);
		if(tmperval.encoded == -1)
			return tmperval;
		computed_size -= tmperval.encoded;
		ASN_DEBUG("Member %d %s of SEQUENCE %s encoded in %d bytes",
			edx, elm->name, sd->name, tmperval.encoded);
	}

	if(computed_size != 0) {
		/*
		 * Encoded size is not equal to the computed size.
		 */
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
	}

	return erval;
}

int
SEQUENCE_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_SEQUENCE_specifics_t *specs = td->specifics;
	int edx;
	int ret;

	if(!sptr) return cb("<absent>", 8, app_key);

	/* Dump preamble */
	if(cb(td->name, strlen(td->name), app_key)
	|| cb(" ::= {\n", 7, app_key))
		return -1;

	for(edx = 0; edx < specs->elements_count; edx++) {
		asn1_SEQUENCE_element_t *elm = &specs->elements[edx];
		const void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(const void * const *)((const char *)sptr + elm->memb_offset);
			if(!memb_ptr) continue;
		} else {
			memb_ptr = (const void *)((const char *)sptr + elm->memb_offset);
		}

		/* Indentation */
		for(ret = 0; ret < ilevel; ret++) cb(" ", 1, app_key);

		/* Print the member's name and stuff */
		if(cb(elm->name, strlen(elm->name), app_key)
		|| cb(": ", 2, app_key))
			return -1;

		/* Print the member itself */
		ret = elm->type->print_struct(elm->type, memb_ptr, ilevel + 4,
			cb, app_key);
		if(ret) return ret;

		/* Print out the terminator */
		ret = cb("\n", 1, app_key);
		if(ret) return ret;
	}

	/* Indentation */
	for(ret = 0; ret < ilevel - 4; ret++) cb(" ", 1, app_key);

	return cb("}", 1, app_key);
}

void
SEQUENCE_free(asn1_TYPE_descriptor_t *td, void *sptr, int contents_only) {
	asn1_SEQUENCE_specifics_t *specs = td->specifics;
	int edx;

	if(!td || !sptr)
		return;

	ASN_DEBUG("Freeing %s as SEQUENCE", td->name);

	for(edx = 0; edx < specs->elements_count; edx++) {
		asn1_SEQUENCE_element_t *elm = &specs->elements[edx];
		void *memb_ptr;
		if(elm->optional) {
			memb_ptr = *(void **)((char *)sptr + elm->memb_offset);
			if(memb_ptr)
				elm->type->free_struct(elm->type, memb_ptr, 0);
		} else {
			memb_ptr = (void *)((char *)sptr + elm->memb_offset);
			elm->type->free_struct(elm->type, memb_ptr, 1);
		}
	}

	if(!contents_only) {
		FREEMEM(sptr);
	}
}

int
SEQUENCE_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	asn1_SEQUENCE_specifics_t *specs = td->specifics;
	int edx;

	if(!sptr) {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	/*
	 * Iterate over structure members and check their validity.
	 */
	for(edx = 0; edx < specs->elements_count; edx++) {
		asn1_SEQUENCE_element_t *elm = &specs->elements[edx];
		const void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(const void **)((const char *)sptr + elm->memb_offset);
			if(!memb_ptr) continue;
		} else {
			memb_ptr = (const void *)((const char *)sptr + elm->memb_offset);
		}

		return elm->type->check_constraints(elm->type, memb_ptr,
			app_errlog, app_key);
	}

	return 0;
}
