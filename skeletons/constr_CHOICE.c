/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <constr_CHOICE.h>
#include <netinet/in.h>	/* for ntohl */
#include <assert.h>

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
#define	SIZE_VIOLATION	(ctx->left >= 0 && (size_t)ctx->left <= size)

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

/*
 * Return a standardized complex structure.
 */
#define	RETURN(_code)	do {			\
		rval.code = _code;		\
		rval.consumed = consumed_myself;\
		return rval;			\
	} while(0)

/*
 * See the definitions.
 */
static inline int _fetch_present_idx(const void *struct_ptr, int off, int size);
static inline void _set_present_idx(void *sptr, int offset, int size, int pres);

/*
 * Tags are canonically sorted in the tag to member table.
 */
static int
_search4tag(const void *ap, const void *bp) {
	const asn1_CHOICE_tag2member_t *a = ap;
	const asn1_CHOICE_tag2member_t *b = bp;
	int a_class = BER_TAG_CLASS(a->el_tag);
	int b_class = BER_TAG_CLASS(b->el_tag);

	if(a_class == b_class) {
		ber_tlv_tag_t a_value = BER_TAG_VALUE(a->el_tag);
		ber_tlv_tag_t b_value = BER_TAG_VALUE(b->el_tag);

		if(a_value == b_value)
			return 0;
		else if(a_value < b_value)
			return -1;
		else
			return 1;
	} else if(a_class < b_class) {
		return -1;
	} else {
		return 1;
	}
}

/*
 * The decoder of the CHOICE type.
 */
ber_dec_rval_t
CHOICE_decode_ber(asn1_TYPE_descriptor_t *sd,
	void **struct_ptr, void *ptr, size_t size, int tag_mode) {
	/*
	 * Bring closer parts of structure description.
	 */
	asn1_CHOICE_specifics_t *specs = sd->specifics;
	asn1_CHOICE_element_t *elements = specs->elements;

	/*
	 * Parts of the structure being constructed.
	 */
	void *st = *struct_ptr;	/* Target structure. */
	ber_dec_ctx_t *ctx;	/* Decoder context */

	ber_tlv_tag_t tlv_tag;	/* T from TLV */
	ssize_t tag_len;	/* Length of TLV's T */
	//ber_tlv_len_t tlv_len;	/* L from TLV */
	ber_dec_rval_t rval;	/* Return code from subparsers */

	ssize_t consumed_myself = 0;	/* Consumed bytes from ptr */

	ASN_DEBUG("Decoding %s as CHOICE", sd->name);
	
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

		if(tag_mode || sd->tags_count) {
			rval = ber_check_tags(sd, ctx, ptr, size,
				tag_mode, &ctx->left, 0);
			if(rval.code != RC_OK) {
				ASN_DEBUG("%s tagging check failed: %d",
					sd->name, rval.code);
				consumed_myself += rval.consumed;
				RETURN(rval.code);
			}

			if(ctx->left >= 0) {
				/* ?Substracted below! */
				ctx->left += rval.consumed;
			}
			ADVANCE(rval.consumed);
		} else {
			ctx->left = -1;
		}

		NEXT_PHASE(ctx);

		ASN_DEBUG("Structure consumes %ld bytes, buffer %ld",
			(long)ctx->left, (long)size);

		/* Fall through */
	case 1:
		/*
		 * Fetch the T from TLV.
		 */
		tag_len = ber_fetch_tag(ptr, LEFT, &tlv_tag);
		ASN_DEBUG("In %s CHOICE tag length %d", sd->name, (int)tag_len);
		switch(tag_len) {
		case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
			/* Fall through */
		case -1: RETURN(RC_FAIL);
		}

		do {
			asn1_CHOICE_tag2member_t *t2m;
			asn1_CHOICE_tag2member_t key;

			key.el_tag = tlv_tag;
			t2m = bsearch(&key, specs->tag2el, specs->tag2el_count,
					sizeof(specs->tag2el[0]), _search4tag);
			if(t2m) {
				/*
				 * Found the element corresponding to the tag.
				 */
				NEXT_PHASE(ctx);
				ctx->step = t2m->el_no;
				break;
			} else if(specs->extensible == 0) {
				ASN_DEBUG("Unexpected tag %s "
					"in non-extensible CHOICE %s",
					ber_tlv_tag_string(tlv_tag), sd->name);
				RETURN(RC_FAIL);
			} else {
				/* Skip this tag */
				ssize_t skip;

				ASN_DEBUG("Skipping unknown tag %s",
					ber_tlv_tag_string(tlv_tag));

				skip = ber_skip_length(
					BER_TLV_CONSTRUCTED(ptr),
					ptr + tag_len, LEFT - tag_len);

				switch(skip) {
				case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
					/* Fall through */
				case -1: RETURN(RC_FAIL);
				}

				ADVANCE(skip + tag_len);
				RETURN(RC_OK);
			}
		} while(0);

	case 2:
		/*
		 * PHASE 2.
		 * Read in the element.
		 */
	    do {
		asn1_CHOICE_element_t *elm;	/* CHOICE's element */
		void *memb_ptr;		/* Pointer to the member */
		void *memb_ptr2;	/* Pointer to that pointer */

		elm = &elements[ctx->step];

		/*
		 * Compute the position of the member inside a structure,
		 * and also a type of containment (it may be contained
		 * as pointer or using inline inclusion).
		 */
		if(elm->optional) {
			/* Optional member, hereby, a simple pointer */
			memb_ptr2 = (char *)st + elm->memb_offset;
		} else {
			/*
			 * A pointer to a pointer
			 * holding the start of the structure
			 */
			memb_ptr = (char *)st + elm->memb_offset;
			memb_ptr2 = &memb_ptr;
		}
		/*
		 * Invoke the member fetch routine according to member's type
		 */
		rval = elm->type->ber_decoder(
				(void *)elm->type,
				memb_ptr2, ptr, LEFT,
				elm->tag_mode);
		switch(rval.code) {
		case RC_OK:
			_set_present_idx(st, specs->pres_offset,
				specs->pres_size, ctx->step + 1);
			break;
		case RC_WMORE: /* More data expected */
			if(!SIZE_VIOLATION) {
				ADVANCE(rval.consumed);
				RETURN(RC_WMORE);
			}
			RETURN(RC_FAIL);
		case RC_FAIL: /* Fatal error */
			RETURN(rval.code);
		} /* switch(rval) */
		
		ADVANCE(rval.consumed);
	  } while(0);

		NEXT_PHASE(ctx);

		/* Fall through */
	case 3:
		ASN_DEBUG("CHOICE %s Leftover: %ld, size = %ld, tm=%d, tc=%d",
			sd->name, (long)ctx->left, (long)size,
			tag_mode, sd->tags_count);

		if(ctx->left > 0) {
			/*
			 * The type must be fully decoded
			 * by the CHOICE member-specific decoder.
			 */
			RETURN(RC_FAIL);
		}

		if(ctx->left == -1
		&& !(tag_mode || sd->tags_count)) {
			/*
			 * This is an untagged CHOICE.
			 * It doesn't contain nothing
			 * except for the member itself, including all its tags.
			 * The decoding is completed.
			 */
			NEXT_PHASE(ctx);
			break;
		}

		/*
		 * Read in the "end of data chunks"'s.
		 */
		while(ctx->left < 0) {
			ssize_t tl;

			tl = ber_fetch_tag(ptr, LEFT, &tlv_tag);
			switch(tl) {
			case 0: if(!SIZE_VIOLATION) RETURN(RC_WMORE);
				/* Fall through */
			case -1: RETURN(RC_FAIL);
			}

			/*
			 * Expected <0><0>...
			 */
			if(((uint8_t *)ptr)[0] == 0) {
				if(LEFT < 2) {
					if(SIZE_VIOLATION)
						RETURN(RC_FAIL);
					else
						RETURN(RC_WMORE);
				} else if(((uint8_t *)ptr)[1] == 0) {
					/*
					 * Correctly finished with <0><0>.
					 */
					continue;
				}
			} else {
				ASN_DEBUG("Unexpected continuation in %s",
					sd->name);
				RETURN(RC_FAIL);
			}

			ADVANCE(2);
			ctx->left++;
		}

		NEXT_PHASE(ctx);
	case 4:
		/* No meaningful work here */
		break;
	}
	
	RETURN(RC_OK);
}

der_enc_rval_t
CHOICE_encode_der(asn1_TYPE_descriptor_t *sd,
		void *struct_ptr,
		int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_CHOICE_specifics_t *specs = sd->specifics;
	asn1_CHOICE_element_t *elm;	/* CHOICE element */
	der_enc_rval_t erval;
	void *memb_ptr;
	size_t computed_size = 0;
	int present;

	ASN_DEBUG("%s %s as CHOICE",
		cb?"Encoding":"Estimating", sd->name);

	present = _fetch_present_idx(struct_ptr,
		specs->pres_offset, specs->pres_size);

	/*
	 * If the structure was not initialized, it cannot be encoded:
	 * can't deduce what to encode in the choice type.
	 */
	if(present <= 0 || present > specs->elements_count) {
		if(present == 0 && specs->elements_count == 0) {
			/* The CHOICE is empty?! */
			erval.encoded = 0;
			return erval;
		}
		erval.encoded = -1;
		erval.failed_type = sd;
		erval.structure_ptr = struct_ptr;
		return erval;
	}

	/*
	 * Seek over the present member of the structure.
	 */
	elm = &specs->elements[present-1];
	if(elm->optional) {
		memb_ptr = *(void **)((char *)struct_ptr + elm->memb_offset);
		if(memb_ptr == 0) {
			erval.encoded = 0;
			return erval;
		}
	} else {
		memb_ptr = (void *)((char *)struct_ptr + elm->memb_offset);
	}

	/*
	 * If the CHOICE itself is tagged EXPLICIT:
	 * T ::= [2] EXPLICIT CHOICE { ... }
	 * Then emit the appropriate tags.
	 */
	if(tag_mode == 1 || sd->tags_count) {
		/*
		 * For this, we need to pre-compute the member.
		 */
		ssize_t ret;

		/* Encode member with its tag */
		erval = elm->type->der_encoder(elm->type, memb_ptr,
			elm->tag_mode, elm->tag, 0, 0);
		if(erval.encoded == -1)
			return erval;

		/* Encode CHOICE with parent or my own tag */
		ret = der_write_tags(sd, erval.encoded, tag_mode, tag,
			cb, app_key);
		if(ret == -1) {
			erval.encoded = -1;
			erval.failed_type = sd;
			erval.structure_ptr = struct_ptr;
			return erval;
		}
		computed_size += ret;
	}

	/*
	 * Encode the single underlying member.
	 */
	erval = elm->type->der_encoder(elm->type, memb_ptr,
		elm->tag_mode, elm->tag, cb, app_key);
	if(erval.encoded == -1)
		return erval;

	ASN_DEBUG("Encoded CHOICE member in %ld bytes (+%ld)",
		(long)erval.encoded, (long)computed_size);

	erval.encoded += computed_size;

	return erval;
}

ber_tlv_tag_t
CHOICE_outmost_tag(asn1_TYPE_descriptor_t *td, const void *ptr, int tag_mode, ber_tlv_tag_t tag) {
	asn1_CHOICE_specifics_t *specs = td->specifics;
	int present;

	assert(tag_mode == 0);
	assert(tag == 0);

	/*
	 * Figure out which CHOICE element is encoded.
	 */
	present = _fetch_present_idx(ptr, specs->pres_offset, specs->pres_size);

	if(present > 0 || present <= specs->elements_count) {
		asn1_CHOICE_element_t *elm = &specs->elements[present-1];
		const void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(const void * const *)
					((const char *)ptr + elm->memb_offset);
		} else {
			memb_ptr = (const void *)
					((const char *)ptr + elm->memb_offset);
		}

		return asn1_TYPE_outmost_tag(elm->type, memb_ptr,
			elm->tag_mode, elm->tag);
	} else {
		return -1;
	}
}

int
CHOICE_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	asn1_CHOICE_specifics_t *specs = td->specifics;
	int present;

	if(!sptr) {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	/*
	 * Figure out which CHOICE element is encoded.
	 */
	present = _fetch_present_idx(sptr, specs->pres_offset,specs->pres_size);
	if(present > 0 && present <= specs->elements_count) {
		asn1_CHOICE_element_t *elm = &specs->elements[present-1];
		const void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(const void * const *)((const char *)sptr + elm->memb_offset);
			if(!memb_ptr) return 0;
		} else {
			memb_ptr = (const void *)((const char *)sptr + elm->memb_offset);
		}

		return elm->type->check_constraints(elm->type, memb_ptr,
				app_errlog, app_key);
	} else {
		_ASN_ERRLOG("%s: no CHOICE element given", td->name);
		return -1;
	}
}

int
CHOICE_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	asn1_CHOICE_specifics_t *specs = td->specifics;
	int present;

	if(!sptr) return cb("<absent>", 8, app_key);

	/*
	 * Figure out which CHOICE element is encoded.
	 */
	present = _fetch_present_idx(sptr, specs->pres_offset,specs->pres_size);

	/*
	 * Free that element.
	 */
	if(present > 0 && present <= specs->elements_count) {
		asn1_CHOICE_element_t *elm = &specs->elements[present-1];
		const void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(const void * const *)((const char *)sptr + elm->memb_offset);
			if(!memb_ptr) return cb("<absent>", 8, app_key);
		} else {
			memb_ptr = (const void *)((const char *)sptr + elm->memb_offset);
		}

		/* Print member's name and stuff */
		if(cb(elm->name, strlen(elm->name), app_key)
		|| cb(": ", 2, app_key))
			return -1;

		return elm->type->print_struct(elm->type, memb_ptr, ilevel,
			cb, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}

void
CHOICE_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {
	asn1_CHOICE_specifics_t *specs = td->specifics;
	int present;

	if(!td || !ptr)
		return;

	ASN_DEBUG("Freeing %s as CHOICE", td->name);

	/*
	 * Figure out which CHOICE element is encoded.
	 */
	present = _fetch_present_idx(ptr, specs->pres_offset, specs->pres_size);

	/*
	 * Free that element.
	 */
	if(present > 0 && present <= specs->elements_count) {
		asn1_CHOICE_element_t *elm = &specs->elements[present-1];
		void *memb_ptr;

		if(elm->optional) {
			memb_ptr = *(void **)((char *)ptr + elm->memb_offset);
			if(memb_ptr)
				elm->type->free_struct(elm->type, memb_ptr, 0);
		} else {
			memb_ptr = (void *)((char *)ptr + elm->memb_offset);
			elm->type->free_struct(elm->type, memb_ptr, 1);
		}
	}

	if(!contents_only) {
		FREEMEM(ptr);
	}
}


/*
 * The following functions functions offer protection against -fshort-enums,
 * compatible with little- and big-endian machines.
 * If assertion is triggered, either disable -fshort-enums, or add an entry
 * here with the ->pres_size of your target stracture.
 * Unless the target structure is packed, the ".present" member
 * is guaranteed to be aligned properly. ASN.1 compiler itself does not
 * produce packed code.
 */
static inline int
_fetch_present_idx(const void *struct_ptr, int pres_offset, int pres_size) {
	const void *present_ptr;
	int present;

	present_ptr = ((const char *)struct_ptr) + pres_offset;

	switch(pres_size) {
	case sizeof(int):	present =   *(const int *)present_ptr; break;
	case sizeof(short):	present = *(const short *)present_ptr; break;
	case sizeof(char):	present =  *(const char *)present_ptr; break;
	default:
		/* ANSI C mandates enum to be equivalent to integer */
		assert(pres_size != sizeof(int));
		return 0;	/* If not aborted, pass back safe value */
	}

	return present;
}

static inline void
_set_present_idx(void *struct_ptr, int pres_offset, int pres_size, int present) {
	void *present_ptr;
	present_ptr = ((char *)struct_ptr) + pres_offset;

	switch(pres_size) {
	case sizeof(int):	*(int *)present_ptr   = present; break;
	case sizeof(short):	*(short *)present_ptr = present; break;
	case sizeof(char):	*(char *)present_ptr  = present; break;
	default:
		/* ANSI C mandates enum to be equivalent to integer */
		assert(pres_size != sizeof(int));
	}
}
