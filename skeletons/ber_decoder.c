/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <constr_TYPE.h>
#include <assert.h>

#define	ADVANCE(num_bytes)	do {			\
		size_t num = num_bytes;			\
		(char *)ptr += num;			\
		size -= num;				\
		consumed_myself += num;			\
	} while(0)
#define	RETURN(_code)	do {				\
		ber_dec_rval_t rval;			\
		rval.code = _code;			\
		rval.consumed = consumed_myself;	\
		return rval;				\
	} while(0)

/*
 * The BER decoder of any type.
 */
ber_dec_rval_t
ber_decode(asn1_TYPE_descriptor_t *type_descriptor,
	void **struct_ptr, void *ptr, size_t size) {

	/*
	 * Invoke type-specific decoder.
	 */
	return type_descriptor->ber_decoder(type_descriptor,
		struct_ptr,	/* Pointer to the destination structure */
		ptr, size,	/* Buffer and its size */
		0		/* Default tag mode is 0 */
		);
}

/*
 * Check the set of <TL<TL<TL...>>> tags matches the definition.
 */
ber_dec_rval_t
ber_check_tags(asn1_TYPE_descriptor_t *td, ber_dec_ctx_t *ctx,
		void *ptr, size_t size, int tag_mode,
		ber_tlv_len_t *last_length, int *opt_tlv_form) {
	ssize_t consumed_myself = 0;
	ssize_t tag_len;
	ssize_t len_len;
	ber_tlv_tag_t tlv_tag;
	ber_tlv_len_t tlv_len;
	ber_tlv_len_t limit_len = -1;
	int expect_00_terminators = 0;
	int tlv_constr = -1;	/* If CHOICE, opt_tlv_form is not given */
	int tagno;

	/*
	 * So what does all this tags_impl_skip stuff mean?
	 * Imagine two types,
	 * 	A ::= [5] IMPLICIT	T
	 * 	B ::= [2] EXPLICIT	T
	 * Where T is defined as
	 *	T ::= [4] IMPLICIT SEQUENCE { ... }
	 * 
	 * Let's say, we are starting to decode type A, given the
	 * following TLV stream: <5> <0>. What does this mean?
	 * It means that the type A contains type T which is,
	 * in turn, empty.
	 * Remember though, that we are still in A. We cannot
	 * just pass control to the type T decoder. Why? Because
	 * the type T decoder expects <4> <0>, not <5> <0>.
	 * So, we must make sure we are going to receive <5> while
	 * still in A, then pass control to the T decoder, indicating
	 * that the tag <4> was implicitly skipped. The decoder of T
	 * hence will be prepared to treat <4> as valid tag, and decode
	 * it appropriately.
	 */

	/*
	 * We have a list of tags that must occur in the stream:
	 * 	{A,B,C}
	 * However, it may be indicated that the type is
	 * implicitly tagged in the caller, so it really boils down to the
	 *	{I,B,C} or even {I,C}
	 * This is because the implicit tag at above structure may replace 
	 * zero or more (or every) tags which follow it. We don't care
	 * about the precise number, as it is already computed for us
	 * by the ASN.1 compiler and placed into td->tags_impl_skip.
	 * So let's suppose the only tag left after implicit tagging is {I}.
	 * Yet, the table we have is {A,B,C} and td->tags_impl_skip=3.
	 * We need to check at least one tag in the loop, so the loop range
	 * is modified so it will be invoked at least one time.
	 */
	tagno = ctx->step	/* Continuing where left previously */
		+ (tag_mode==-1?(td->tags_impl_skip-1):0)
		+ (tag_mode==1?-1:0)
		;
	ASN_DEBUG("ber_check_tags(%s, size=%ld, tm=%d, step=%d, tagno=%d)",
		td->name, (long)size, tag_mode, ctx->step, tagno);
	//assert(td->tags_count >= 1); ?May not be the case for CHOICE!
	assert(tagno < td->tags_count);	/* At least one loop */
	for((void)tagno; tagno < td->tags_count; tagno++, ctx->step++) {

		/*
		 * Fetch and process T from TLV.
		 */
		tag_len = ber_fetch_tag(ptr, size, &tlv_tag);
			ASN_DEBUG("Fetching tag from {%p,%ld} %02X..%02X: "
				"len %ld, tag %s",
				ptr, (long)size,
				size?*(uint8_t *)ptr:0,
				((size_t)tag_len<size&&tag_len>0)
					?*((uint8_t *)ptr + tag_len):0,
				(long)tag_len,
				ber_tlv_tag_string(tlv_tag));
		switch(tag_len) {
		case -1: RETURN(RC_FAIL);
		case 0: RETURN(RC_WMORE);
		}

		tlv_constr = BER_TLV_CONSTRUCTED(ptr);

		/*
		 * If {I}, don't check anything.
		 * If {I,B,C}, check B and C unless we're at I.
		 */
		if(tag_mode != 0 && ctx->step == 0) {
			/*
			 * We don't expect tag to match here.
			 * It's just because we don't know how the tag
			 * is supposed to look like.
			 */
		} else {
		    assert(tagno >= 0);	/* Guaranteed by the code above */
		    if(tlv_tag != td->tags[tagno]) {
			/*
			 * Unexpected tag. Too bad.
			 */
		    	ASN_DEBUG("Expected: %s, expectation failed",
				ber_tlv_tag_string(td->tags[tagno]));
			RETURN(RC_FAIL);
		    }
		}

		/*
		 * Attention: if there are more tags expected,
		 * ensure that the current tag is presented
		 * in constructed form (it contains other tags!).
		 * If this one is the last one, check that the tag form
		 * matches the one given in descriptor.
		 */
		if(tagno < (td->tags_count - 1)) {
			if(tlv_constr == 0) {
				RETURN(RC_FAIL);
			}
		} else {
			if(td->last_tag_form != tlv_constr
			&& td->last_tag_form != -1) {
				RETURN(RC_FAIL);
			}
		}

		/*
		 * Fetch and process L from TLV.
		 */
		len_len = ber_fetch_length(tlv_constr,
			(char *)ptr + tag_len, size - tag_len, &tlv_len);
		switch(len_len) {
		case -1: RETURN(RC_FAIL);
		case 0: RETURN(RC_WMORE);
		}

		/*
		 * FIXME
		 * As of today, the chain of tags
		 * must either contain several indefinite length TLVs,
		 * or several definite length ones.
		 * No mixing is allowed.
		 */
		if(tlv_len == -1) {
			/*
			 * Indefinite length.
			 */
			if(limit_len == -1) {
				expect_00_terminators++;
			} else {
				ASN_DEBUG("Unexpected indefinite length "
					"in a chain of definite lengths");
				RETURN(RC_FAIL);
			}
			ADVANCE(tag_len + len_len);
			continue;
		} else {
			if(expect_00_terminators) {
				ASN_DEBUG("Unexpected definite length "
					"in a chain of indefinite lengths");
				RETURN(RC_FAIL);
			}
		}

		/*
		 * Check that multiple TLVs specify ever decreasing length,
		 * which is consistent.
		 */
		if(limit_len == -1) {
			limit_len    = tlv_len + tag_len + len_len;
		} else if(limit_len != tlv_len + tag_len + len_len) {
			/*
			 * Inner TLV specifies length which is inconsistent
			 * with the outer TLV's length value.
			 */
			ASN_DEBUG("Outer TLV is %d and inner is %d",
				limit_len, tlv_len);
			RETURN(RC_FAIL);
		}

		ADVANCE(tag_len + len_len);

		limit_len -= (tag_len + len_len);
		if((ssize_t)size > limit_len) {
			/*
			 * Make sure that we won't consume more bytes
			 * from the large buffer than the inferred limit.
			 */
			size = limit_len;
		}
	}

	if(opt_tlv_form)
		*opt_tlv_form = tlv_constr;
	if(expect_00_terminators)
		*last_length = -expect_00_terminators;
	else
		*last_length = tlv_len;

	RETURN(RC_OK);
}
