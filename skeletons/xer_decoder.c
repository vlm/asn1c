
#include <asn_application.h>
#include <asn_internal.h>
#include <xer_support.h>		/* XER/XML parsing support */
#include <assert.h>


/*
 * Decode the XER encoding of a given type.
 */
asn_dec_rval_t
xer_decode(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **struct_ptr, void *buffer, size_t size) {
	asn_codec_ctx_t s_codec_ctx;

	/*
	 * Satisfy the requirement that the codec context
	 * must be allocated on the stack.
	 */
	if(opt_codec_ctx && opt_codec_ctx->max_stack_size) {
		s_codec_ctx = *opt_codec_ctx;
		opt_codec_ctx = &s_codec_ctx;
	}

	/*
	 * Invoke type-specific decoder.
	 */
	return td->xer_decoder(opt_codec_ctx, td, struct_ptr, 0, buffer, size);
}



struct xer__cb_arg {
	pxml_chunk_type_e	chunk_type;
	size_t			chunk_size;
	void			*chunk_buf;
	int callback_not_invoked;
};

static int
xer__token_cb(pxml_chunk_type_e type, void *_chunk_data, size_t _chunk_size, void *key) {
	struct xer__cb_arg *arg = (struct xer__cb_arg *)key;
	arg->chunk_type = type;
	arg->chunk_size = _chunk_size;
	arg->chunk_buf = _chunk_data;
	arg->callback_not_invoked = 0;
	return -1;	/* Terminate the XML parsing */
}

/*
 * Fetch the next token from the XER/XML stream.
 */
ssize_t
xer_next_token(int *stateContext, void *buffer, size_t size,
		pxer_chunk_type_e *ch_type) {
	struct xer__cb_arg arg;
	ssize_t ret;
	int new_stateContext = *stateContext;

	arg.callback_not_invoked = 1;
	ret = pxml_parse(&new_stateContext, buffer, size, xer__token_cb, &arg);
	if(ret < 0) return -1;
	if(arg.callback_not_invoked) {
		assert(ret == 0);	/* No data was consumed */
		return 0;		/* Try again with more data */
	} else {
		assert(arg.chunk_size);
		assert(arg.chunk_buf == buffer);
	}

	/*
	 * Translate the XML chunk types into more convenient ones.
	 */
	switch(arg.chunk_type) {
	case PXML_TEXT:
		*ch_type = PXER_TEXT;
		break;
	case PXML_TAG: return 0;	/* Want more */
	case PXML_TAG_END:
		*ch_type = PXER_TAG;
		break;
	case PXML_COMMENT:
	case PXML_COMMENT_END:
		*ch_type = PXER_COMMENT;
		break;
	}

	*stateContext = new_stateContext;	/* Update the context */
	return arg.chunk_size;
}

#define	CSLASH	0x2f	/* '/' */
#define	LANGLE	0x3c	/* '<' */
#define	RANGLE	0x3e	/* '>' */

xer_check_tag_e
xer_check_tag(const void *buf_ptr, int size, const char *need_tag) {
	const char *buf = (const char *)buf_ptr;
	const char *end;
	xer_check_tag_e ct = XCT_OPENING;

	if(size < 2 || buf[0] != LANGLE || buf[size-1] != RANGLE) {
		if(size >= 2)
		ASN_DEBUG("Broken XML tag: \"%c...%c\"", buf[0], buf[size - 1]);
		return XCT_BROKEN;
	}

	/*
	 * Determine the tag class.
	 */
	if(buf[1] == CSLASH) {
		buf += 2;	/* advance past "</" */
		size -= 3;	/* strip "</" and ">" */
		ct = XCT_CLOSING;
		if(size > 0 && buf[size-1] == CSLASH)
			return XCT_BROKEN;	/* </abc/> */
	} else {
		buf++;		/* advance past "<" */
		size -= 2;	/* strip "<" and ">" */
		if(size > 0 && buf[size-1] == CSLASH) {
			ct = XCT_BOTH;
			size--;	/* One more, for "/" */
		}
	}

	/*
	 * Determine the tag name.
	 */
	for(end = buf + size; buf < end; buf++, need_tag++) {
		int b = *buf, n = *need_tag;
		if(b != n) {
			if(n == 0) {
				switch(b) {
				case 0x09: case 0x0a: case 0x0c: case 0x0d:
				case 0x20:
					/* "<abc def/>": whitespace is normal */
					return ct;
				}
			}
			return (XCT__UNK__MASK | ct);
		}
		if(b == 0)
			return XCT_BROKEN;	/* Embedded 0 in buf?! */
	}
	if(*need_tag)
		return (XCT__UNK__MASK | ct);

	return ct;
}


#undef	ADVANCE
#define	ADVANCE(num_bytes)	do {				\
		size_t num = (num_bytes);			\
		buf_ptr = ((char *)buf_ptr) + num;		\
		size -= num;					\
		consumed_myself += num;				\
	} while(0)

#undef	RETURN
#define	RETURN(_code)	do {					\
		rval.code = _code;				\
		rval.consumed = consumed_myself;		\
		return rval;					\
	} while(0)

#define	XER_GOT_BODY(chunk_buf, chunk_size, size)	do {	\
		ssize_t converted_size = body_receiver		\
			(struct_key, chunk_buf, chunk_size,	\
				(size_t)chunk_size < size);	\
		if(converted_size == -1) RETURN(RC_FAIL);	\
		if(converted_size == 0 && size == chunk_size) {	\
			ctx->step = xer_state;			\
			RETURN(RC_WMORE);			\
		}						\
		chunk_size = converted_size;			\
	} while(0)
#define	XER_GOT_EMPTY()	do {					\
	if(body_receiver(struct_key, 0, 0, size > 0) == -1)	\
			RETURN(RC_FAIL);			\
	} while(0)

/*
 * Generalized function for decoding the primitive values.
 */
asn_dec_rval_t
xer_decode_general(asn_codec_ctx_t *opt_codec_ctx,
	asn_struct_ctx_t *ctx,	/* Type decoder context */
	void *struct_key,
	const char *xml_tag,	/* Expected XML tag */
	void *buf_ptr, size_t size,
	int (*opt_unexpected_tag_decoder)
		(void *struct_key, void *chunk_buf, size_t chunk_size),
	ssize_t (*body_receiver)
		(void *struct_key, void *chunk_buf, size_t chunk_size,
			int have_more)
	) {

	asn_dec_rval_t rval;
	ssize_t consumed_myself = 0;
	int xer_state;			/* XER low level parsing context */

	(void)opt_codec_ctx;

	/*
	 * Phases of XER/XML processing:
	 * Phase 0: Check that the opening tag matches our expectations.
	 * Phase 1: Processing body and reacting on closing tag.
	 */
	if(ctx->phase > 1) RETURN(RC_FAIL);
	for(xer_state = ctx->step;;) {
		pxer_chunk_type_e ch_type;	/* XER chunk type */
		ssize_t ch_size;		/* Chunk size */
		xer_check_tag_e tcv;		/* Tag check value */

		/*
		 * Get the next part of the XML stream.
		 */
		ch_size = xer_next_token(&xer_state, buf_ptr, size, &ch_type);
		switch(ch_size) {
		case -1: RETURN(RC_FAIL);
		case 0:
			ctx->step = xer_state;
			RETURN(RC_WMORE);
		default:
			switch(ch_type) {
			case PXER_COMMENT:		/* Got XML comment */
				ADVANCE(ch_size);	/* Skip silently */
				continue;
			case PXER_TEXT:
				if(ctx->phase == 0) {
					/*
					 * We have to ignore whitespace here,
					 * but in order to be forward compatible
					 * with EXTENDED-XER (EMBED-VALUES, #25)
					 * any text is just ignored here.
					 */
				} else {
					XER_GOT_BODY(buf_ptr, ch_size, size);
				}
				ADVANCE(ch_size);
				continue;
			case PXER_TAG:
				break;	/* Check the rest down there */
			}
		}

		assert(ch_type == PXER_TAG && size);

		tcv = xer_check_tag(buf_ptr, ch_size, xml_tag);
		/*
		 * Phase 0:
		 * 	Expecting the opening tag
		 * 	for the type being processed.
		 * Phase 1:
		 * 	Waiting for the closing XML tag.
		 */
		switch(tcv) {
		case XCT_BOTH:
			if(ctx->phase) break;
			/* Finished decoding of an empty element */
			XER_GOT_EMPTY();
			ADVANCE(ch_size);
			ctx->phase = 2;	/* Phase out */
			RETURN(RC_OK);
		case XCT_OPENING:
			if(ctx->phase) break;
			ADVANCE(ch_size);
			ctx->phase = 1;	/* Processing body phase */
			continue;
		case XCT_CLOSING:
			if(!ctx->phase) break;
			ADVANCE(ch_size);
			ctx->phase = 2;	/* Phase out */
			RETURN(RC_OK);
		case XCT_UNKNOWN_BO:
			if(!ctx->phase) break;
			/*
			 * Certain tags in the body may be expected.
			 */
			if(opt_unexpected_tag_decoder
			&& opt_unexpected_tag_decoder(struct_key,
					buf_ptr, ch_size) == 0) {
				/* Tag's processed fine */
				ADVANCE(ch_size);
				continue;
			}
			/* Fall through */
		default:
			break;		/* Unexpected tag */
		}

		ASN_DEBUG("Unexpected XML tag");
		break;	/* Dark and mysterious things have just happened */
	}

	RETURN(RC_FAIL);
}


int
xer_is_whitespace(void *chunk_buf, size_t chunk_size) {
	char *p = (char *)chunk_buf;
	char *pend = p + chunk_size;

	for(; p < pend; p++) {
		switch(*p) {
		/* X.693, #8.1.4
		 * HORISONTAL TAB (9)
		 * LINE FEED (10) 
		 * CARRIAGE RETURN (13) 
		 * SPACE (32)
		 */
		case 0x09: case 0x0a: case 0x0d: case 0x20:
			break;
		default:
			return 0;
		}
	}
	return 1;       /* All whitespace */
}

