/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <OCTET_STRING.h>
#include <assert.h>
#include <errno.h>

/*
 * OCTET STRING basic type description.
 */
static ber_tlv_tag_t asn_DEF_OCTET_STRING_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))
};
asn_TYPE_descriptor_t asn_DEF_OCTET_STRING = {
	"OCTET STRING",
	OCTET_STRING_free,
	OCTET_STRING_print,	/* non-ascii stuff, generally */
	asn_generic_no_constraint,
	OCTET_STRING_decode_ber,
	OCTET_STRING_encode_der,
	0,				/* Not implemented yet */
	OCTET_STRING_encode_xer,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_OCTET_STRING_tags,
	sizeof(asn_DEF_OCTET_STRING_tags)
	  / sizeof(asn_DEF_OCTET_STRING_tags[0]),
	asn_DEF_OCTET_STRING_tags,	/* Same as above */
	sizeof(asn_DEF_OCTET_STRING_tags)
	  / sizeof(asn_DEF_OCTET_STRING_tags[0]),
	0, 0,	/* No members */
	0	/* No specifics */
};

#undef	_CH_PHASE
#undef	NEXT_PHASE
#undef	PREV_PHASE
#define	_CH_PHASE(ctx, inc) do {	\
		if(ctx->phase == 0)	\
			ctx->step = 0;	\
		ctx->phase += inc;	\
	} while(0)
#define	NEXT_PHASE(ctx)	_CH_PHASE(ctx, +1)
#define	PREV_PHASE(ctx)	_CH_PHASE(ctx, -1)

#undef	ADVANCE
#define	ADVANCE(num_bytes)	do {			\
		size_t num = (num_bytes);		\
		buf_ptr = ((char *)buf_ptr) + num;	\
		size -= num;				\
		consumed_myself += num;			\
	} while(0)

#undef	RETURN
#define	RETURN(_code)	do {			\
		rval.code = _code;		\
		rval.consumed = consumed_myself;\
		return rval;			\
	} while(0)

#undef	APPEND
#define	APPEND(bufptr, bufsize)	do {					\
		size_t _bs = (bufsize);					\
		size_t _ns = ctx->step;	/* Allocated */			\
		if(_ns <= (size_t)(st->size + _bs)) {			\
			void *ptr;					\
			/* Be nice and round to the memory allocator */	\
			do { _ns = _ns ? _ns<<2 : 16; }			\
			    while(_ns <= (size_t)(st->size + _bs));	\
			ptr = REALLOC(st->buf, _ns);			\
			if(ptr) {					\
				st->buf = (uint8_t *)ptr;		\
				ctx->step = _ns;			\
			} else {					\
				RETURN(RC_FAIL);			\
			}						\
		}							\
		memcpy(st->buf + st->size, bufptr, _bs);		\
		st->size += _bs;					\
		if(st->size < 0)					\
			/* Why even care?.. JIC */			\
			RETURN(RC_FAIL);				\
		/* Convenient nul-termination */			\
		st->buf[st->size] = '\0';				\
	} while(0)

/*
 * The main reason why ASN.1 is still alive is that too much time and effort
 * is necessary for learning it more or less adequately, thus creating a gut
 * necessity to demonstrate that aquired skill everywhere afterwards.
 * No, I am not going to explain what the following stuff is.
 */
struct _stack_el {
	ber_tlv_len_t	left;	/* What's left to read (or -1) */
	ber_tlv_len_t	got;	/* What was actually processed */
	int	cont_level;	/* Depth of subcontainment */
	int	want_nulls;	/* Want null "end of content" octets? */
	int	bits_chopped;	/* Flag in BIT STRING mode */
	ber_tlv_tag_t	tag;	/* For debugging purposes */
	struct _stack_el *prev;
	struct _stack_el *next;
};
struct _stack {
	struct _stack_el *tail;
	struct _stack_el *cur_ptr;
};

static struct _stack_el *
OS__add_stack_el(struct _stack *st) {
	struct _stack_el *nel;

	/*
	 * Reuse the old stack frame or allocate a new one.
	 */
	if(st->cur_ptr && st->cur_ptr->next) {
		nel = st->cur_ptr->next;
		nel->bits_chopped = 0;
		nel->got = 0;
		/* Retain the nel->cont_level, it's correct. */
	} else {
		(void *)nel = CALLOC(1, sizeof(struct _stack_el));
		if(nel == NULL)
			return NULL;
	
		if(st->tail) {
			/* Increase a subcontainment depth */
			nel->cont_level = st->tail->cont_level + 1;
			st->tail->next = nel;
		}
		nel->prev = st->tail;
		st->tail = nel;
	}

	st->cur_ptr = nel;

	return nel;
}

static struct _stack *
_new_stack() {
	struct _stack *st;
	(void *)st = CALLOC(1, sizeof(struct _stack));
	if(st == NULL)
		return NULL;

	return st;
}

/*
 * Decode OCTET STRING type.
 */
ber_dec_rval_t
OCTET_STRING_decode_ber(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td,
	void **os_structure, void *buf_ptr, size_t size, int tag_mode) {
	OCTET_STRING_t *st = (OCTET_STRING_t *)*os_structure;
	ber_dec_rval_t rval;
	asn_struct_ctx_t *ctx;
	ssize_t consumed_myself = 0;
	struct _stack *stck;	/* A stack structure */
	struct _stack_el *sel = 0;	/* Stack element */
	int tlv_constr;
	enum type_type_e {
		_TT_GENERIC	= 0,	/* Just a random OCTET STRING */
		_TT_BIT_STRING	= 1,	/* BIT STRING type, a special case */
		_TT_ANY		= 2,	/* ANY type, a special case too */
	} type_type = (enum type_type_e)(int)td->specifics;

	ASN_DEBUG("Decoding %s as %s (frame %ld)",
		td->name,
		(type_type == _TT_GENERIC) ? "OCTET STRING" : "OS-SpecialCase",
		(long)size);

	/*
	 * Create the string if does not exist.
	 */
	if(st == NULL) {
		(void *)st = *os_structure = CALLOC(1, sizeof(*st));
		if(st == NULL)
			RETURN(RC_FAIL);
	}

	/* Restore parsing context */
	ctx = &st->_asn_ctx;

	switch(ctx->phase) {
	case 0:
		/*
		 * Check tags.
		 */
		rval = ber_check_tags(opt_codec_ctx, td, ctx,
			buf_ptr, size, tag_mode, -1,
			&ctx->left, &tlv_constr);
		if(rval.code != RC_OK) {
			RETURN(rval.code);
		}

		if(tlv_constr) {
			/*
			 * Complex operation, requires stack of expectations.
			 */
			ctx->ptr = _new_stack();
			if(ctx->ptr) {
				(void *)stck = ctx->ptr;
				if(type_type == _TT_BIT_STRING) {
					/* Number of meaningless tail bits */
					APPEND("\0", 1);
				}
			} else {
				RETURN(RC_FAIL);
			}
		} else {
			/*
			 * Jump into stackless primitive decoding.
			 */
			_CH_PHASE(ctx, 3);
			if(type_type == _TT_ANY)
				APPEND(buf_ptr, rval.consumed);
			ADVANCE(rval.consumed);
			goto phase3;
		}

		NEXT_PHASE(ctx);
		/* Fall through */
	case 1:
	phase1:
		/*
		 * Fill the stack with expectations.
		 */
		(void *)stck = ctx->ptr;
		sel = stck->cur_ptr;
	  do {
		ber_tlv_tag_t tlv_tag;
		ber_tlv_len_t tlv_len;
		ber_tlv_tag_t expected_tag;
		ssize_t tl, ll, tlvl;
				/* This one works even if (sel->left == -1) */
		ssize_t Left = ((!sel||(size_t)sel->left >= size)
					?(ssize_t)size:sel->left);


		ASN_DEBUG("%p, s->l=%d, s->wn=%d, s->g=%d\n", sel,
			sel?sel->left:0,
			sel?sel->want_nulls:0,
			sel?sel->got:0
		);
		if(sel && sel->left <= 0 && sel->want_nulls == 0) {
			if(sel->prev) {
				struct _stack_el *prev = sel->prev;
				if(prev->left != -1) {
					if(prev->left < sel->got)
						RETURN(RC_FAIL);
					prev->left -= sel->got;
				}
				prev->got += sel->got;
				sel = stck->cur_ptr = prev;
				if(!sel) break;
				tlv_constr = 1;
				continue;
			} else {
				sel = stck->cur_ptr = 0;
				break;	/* Nothing to wait */
			}
		}

		tl = ber_fetch_tag(buf_ptr, Left, &tlv_tag);
		ASN_DEBUG("fetch tag(size=%d,L=%d), %sstack, left=%d, wn=%d, tl=%d",
			(int)size, Left, sel?"":"!",
			sel?sel->left:0, sel?sel->want_nulls:0, tl);
		switch(tl) {
		case -1: RETURN(RC_FAIL);
		case 0: RETURN(RC_WMORE);
		}

		tlv_constr = BER_TLV_CONSTRUCTED(buf_ptr);

		ll = ber_fetch_length(tlv_constr,
				(char *)buf_ptr + tl, Left - tl, &tlv_len);
		ASN_DEBUG("Got tag=%s, tc=%d, left=%ld, tl=%d, len=%d, ll=%d",
			ber_tlv_tag_string(tlv_tag), tlv_constr,
				(long)Left, tl, tlv_len, ll);
		switch(ll) {
		case -1: RETURN(RC_FAIL);
		case 0: RETURN(RC_WMORE);
		}

		if(sel && sel->want_nulls
			&& ((uint8_t *)buf_ptr)[0] == 0
			&& ((uint8_t *)buf_ptr)[1] == 0)
		{

			ASN_DEBUG("Eat EOC; wn=%d--", sel->want_nulls);

			if(type_type == _TT_ANY) APPEND("\0\0", 2);

			ADVANCE(2);
			sel->got += 2;
			if(sel->left != -1) {
				sel->left -= 2;	/* assert(sel->left >= 2) */
			}

			sel->want_nulls--;
			if(sel->want_nulls == 0) {
				/* Move to the next expectation */
				sel->left = 0;
				tlv_constr = 1;
			}

			continue;
		}

		/*
		 * Set up expected tags,
		 * depending on ASN.1 type being decoded.
		 */
		switch(type_type) {
		case _TT_BIT_STRING:
			/* X.690: 8.6.4.1, NOTE 2 */
			/* Fall through */
		case _TT_GENERIC:
		default:
			if(sel) {
				int level = sel->cont_level;
				if(level < td->all_tags_count) {
					expected_tag = td->all_tags[level];
					break;
				} else if(td->all_tags_count) {
					expected_tag = td->all_tags
						[td->all_tags_count - 1];
					break;
				}
				/* else, Fall through */
			}
			/* Fall through */
		case _TT_ANY:
			expected_tag = tlv_tag;
			break;
		}


		if(tlv_tag != expected_tag) {
			char buf[2][32];
			ber_tlv_tag_snprint(tlv_tag,
				buf[0], sizeof(buf[0]));
			ber_tlv_tag_snprint(td->tags[td->tags_count-1],
				buf[1], sizeof(buf[1]));
			ASN_DEBUG("Tag does not match expectation: %s != %s",
				buf[0], buf[1]);
			RETURN(RC_FAIL);
		}

		tlvl = tl + ll;	/* Combined length of T and L encoding */
		if((tlv_len + tlvl) < 0) {
			/* tlv_len value is too big */
			ASN_DEBUG("TLV encoding + length (%ld) is too big",
				(long)tlv_len);
			RETURN(RC_FAIL);
		}

		/*
		 * Append a new expectation.
		 */
		sel = OS__add_stack_el(stck);
		if(!sel) RETURN(RC_FAIL);

		sel->tag = tlv_tag;

		sel->want_nulls = (tlv_len==-1);
		if(sel->prev && sel->prev->left != -1) {
			/* Check that the parent frame is big enough */
			if(sel->prev->left < tlvl + (tlv_len==-1?0:tlv_len))
				RETURN(RC_FAIL);
			if(tlv_len == -1)
				sel->left = sel->prev->left - tlvl;
			else
				sel->left = tlv_len;
		} else {
			sel->left = tlv_len;
		}
		if(type_type == _TT_ANY) APPEND(buf_ptr, tlvl);
		sel->got += tlvl;
		ADVANCE(tlvl);

		ASN_DEBUG("+EXPECT2 got=%d left=%d, wn=%d, clvl=%d",
			sel->got, sel->left, sel->want_nulls, sel->cont_level);

	  } while(tlv_constr);
		if(sel == NULL) {
			/* Finished operation, "phase out" */
			ASN_DEBUG("Phase out");
			_CH_PHASE(ctx, +3);
			break;
		}

		NEXT_PHASE(ctx);
		/* Fall through */
	case 2:
		(void *)stck = ctx->ptr;
		sel = stck->cur_ptr;
		ASN_DEBUG("Phase 2: Need %ld bytes, size=%ld, alrg=%ld, wn=%d",
			(long)sel->left, (long)size, (long)sel->got,
				sel->want_nulls);
	    {
		ber_tlv_len_t len;

		assert(sel->left >= 0);

		len = ((ber_tlv_len_t)size < sel->left)
				? (ber_tlv_len_t)size : sel->left;
		if(len > 0) {
			if(type_type == _TT_BIT_STRING
			&& sel->bits_chopped == 0) {
				/*
				 * Finalize the previous chunk:
				 * strip down unused bits.
				 */
				st->buf[st->size-1] &= 0xff << st->buf[0];

				APPEND(((char *)buf_ptr+1), (len - 1));
				st->buf[0] = *(uint8_t *)buf_ptr;
				sel->bits_chopped = 1;
			} else {
				APPEND(buf_ptr, len);
			}
			ADVANCE(len);
			sel->left -= len;
			sel->got += len;
		}

		if(sel->left) {
			ASN_DEBUG("OS left %ld, size = %ld, wn=%d\n",
				(long)sel->left, (long)size, sel->want_nulls);
			RETURN(RC_WMORE);
		}

		PREV_PHASE(ctx);
		goto phase1;
	    }
		break;
	case 3:
	phase3:
		/*
		 * Primitive form, no stack required.
		 */
		if(size < (size_t)ctx->left) {
			APPEND(buf_ptr, size);
			ctx->left -= size;
			ADVANCE(size);
			RETURN(RC_WMORE);
		} else {
			APPEND(buf_ptr, ctx->left);
			ADVANCE(ctx->left);
			ctx->left = 0;

			NEXT_PHASE(ctx);
		}
		break;
	}

	if(sel) {
		ASN_DEBUG("3sel p=%p, wn=%d, l=%ld, g=%ld, size=%ld",
			sel->prev, sel->want_nulls,
			(long)sel->left, (long)sel->got, (long)size);
		if(sel->prev || sel->want_nulls > 1 || sel->left > 0) {
			RETURN(RC_WMORE);
		}
	}

	/*
	 * BIT STRING-specific processing.
	 */
	if(type_type == _TT_BIT_STRING && st->size >= 2) {
		/* Finalize BIT STRING: zero out unused bits. */
		st->buf[st->size-1] &= 0xff << st->buf[0];
	}

	ASN_DEBUG("Took %d bytes to encode %s: [%s]:%d",
		consumed_myself, td->name,
		(type_type == _TT_GENERIC) ? (char *)st->buf : "", st->size);


	RETURN(RC_OK);
}

/*
 * Encode OCTET STRING type using DER.
 */
asn_enc_rval_t
OCTET_STRING_encode_der(asn_TYPE_descriptor_t *td, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;
	OCTET_STRING_t *st = (OCTET_STRING_t *)ptr;
	int add_byte = 0;
	int is_bit_str = (td->specifics == (void *)1);
	int is_ANY_type = (td->specifics == (void *)2);

	ASN_DEBUG("%s %s as OCTET STRING",
		cb?"Estimating":"Encoding", td->name);

	/*
	 * Canonicalize BIT STRING.
	 */
	if(is_bit_str && st->buf) {
		switch(st->size) {
		case 0: add_byte = 1; break;
		case 1: st->buf[0] = 0; break;
		default:
			/* Finalize BIT STRING: zero out unused bits. */
			st->buf[st->size-1] &= 0xff << st->buf[0];
		}
	}

	if(is_ANY_type) {
		erval.encoded = 0;
	} else {
		erval.encoded = der_write_tags(td, st->size + add_byte,
			tag_mode, 0, tag, cb, app_key);
		if(erval.encoded == -1) {
			erval.failed_type = td;
			erval.structure_ptr = ptr;
			return erval;
		}
	}

	if(cb) {
		uint8_t zero;
		uint8_t *buf;
		int size;

		/* BIT STRING-aware handling */
		if(add_byte) {
			zero = 0;
			buf = &zero;
			size = 1;
		} else if(st->buf) {
			buf = st->buf;
			size = st->size;
		} else {
			assert(st->size == 0);
			buf = 0;	/* Not used */
			size = 0;
		}

		if(size) {
			if(cb(buf, size, app_key) < 0) {
				erval.encoded = -1;
				erval.failed_type = td;
				erval.structure_ptr = ptr;
				return erval;
			}
		}
	}

	erval.encoded += st->size + add_byte;

	return erval;
}

asn_enc_rval_t
OCTET_STRING_encode_xer(asn_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	static const char *h2c = "0123456789ABCDEF";
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	asn_enc_rval_t er;
	char scratch[16 * 3 + 4];
	char *p = scratch;
	uint8_t *buf;
	uint8_t *end;
	size_t i;

	if(!st || !st->buf)
		_ASN_ENCODE_FAILED;

	er.encoded = 0;

	/*
	 * Dump the contents of the buffer in hexadecimal.
	 */
	buf = st->buf;
	end = buf + st->size;
	if(flags & XER_F_CANONICAL) {
		char *scend = scratch + (sizeof(scratch) - 2);
		for(; buf < end; buf++) {
			if(p >= scend) {
				_ASN_CALLBACK(scratch, p - scratch);
				er.encoded += p - scratch;
				p = scratch;
			}
			*p++ = h2c[(*buf >> 4) & 0x0F];
			*p++ = h2c[*buf & 0x0F];
		}

		_ASN_CALLBACK(scratch, p-scratch);	/* Dump the rest */
		er.encoded += p - scratch;
	} else {
		for(i = 0; buf < end; buf++, i++) {
			if(!(i % 16) && (i || st->size > 16)) {
				_ASN_CALLBACK(scratch, p-scratch);
				er.encoded += (p-scratch);
				p = scratch;
				_i_ASN_TEXT_INDENT(1, ilevel);
			}
			*p++ = h2c[(*buf >> 4) & 0x0F];
			*p++ = h2c[*buf & 0x0F];
			*p++ = 0x20;
		}
		if(p - scratch) {
			p--;	/* Remove the tail space */
			_ASN_CALLBACK(scratch, p-scratch); /* Dump the rest */
			er.encoded += p - scratch;
			if(st->size > 16)
				_i_ASN_TEXT_INDENT(1, ilevel-1);
		}
	}

	return er;
cb_failed:
	_ASN_ENCODE_FAILED;
}

static struct OCTET_STRING__xer_escape_table_s {
	char *string;
	int size;
} OCTET_STRING__xer_escape_table[] = {
#define	OSXET(s)	{ s, sizeof(s) - 1 }
	OSXET("\074\156\165\154\057\076"),	/* <nul/> */
	OSXET("\074\163\157\150\057\076"),	/* <soh/> */
	OSXET("\074\163\164\170\057\076"),	/* <stx/> */
	OSXET("\074\145\164\170\057\076"),	/* <etx/> */
	OSXET("\074\145\157\164\057\076"),	/* <eot/> */
	OSXET("\074\145\156\161\057\076"),	/* <enq/> */
	OSXET("\074\141\143\153\057\076"),	/* <ack/> */
	OSXET("\074\142\145\154\057\076"),	/* <bel/> */
	OSXET("\074\142\163\057\076"),		/* <bs/> */
	OSXET("\011"),				/* \t */
	OSXET("\012"),				/* \n */
	OSXET("\074\166\164\057\076"),		/* <vt/> */
	OSXET("\074\146\146\057\076"),		/* <ff/> */
	OSXET("\015"),				/* \r */
	OSXET("\074\163\157\057\076"),		/* <so/> */
	OSXET("\074\163\151\057\076"),		/* <si/> */
	OSXET("\074\144\154\145\057\076"),	/* <dle/> */
	OSXET("\074\144\143\061\057\076"),	/* <de1/> */
	OSXET("\074\144\143\062\057\076"),	/* <de2/> */
	OSXET("\074\144\143\063\057\076"),	/* <de3/> */
	OSXET("\074\144\143\064\057\076"),	/* <de4/> */
	OSXET("\074\156\141\153\057\076"),	/* <nak/> */
	OSXET("\074\163\171\156\057\076"),	/* <syn/> */
	OSXET("\074\145\164\142\057\076"),	/* <etb/> */
	OSXET("\074\143\141\156\057\076"),	/* <can/> */
	OSXET("\074\145\155\057\076"),		/* <em/> */
	OSXET("\074\163\165\142\057\076"),	/* <sub/> */
	OSXET("\074\145\163\143\057\076"),	/* <esc/> */
	OSXET("\074\151\163\064\057\076"),	/* <is4/> */
	OSXET("\074\151\163\063\057\076"),	/* <is3/> */
	OSXET("\074\151\163\062\057\076"),	/* <is2/> */
	OSXET("\074\151\163\061\057\076"),	/* <is1/> */
	{ 0, 0 },	/* " " */
	{ 0, 0 },	/* ! */
	{ 0, 0 },	/* \" */
	{ 0, 0 },	/* # */
	{ 0, 0 },	/* $ */
	{ 0, 0 },	/* % */
	OSXET("\046\141\155\160\073"),	/* &amp; */
	{ 0, 0 },	/* ' */
	{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}, /* ()*+,-./ */
	{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}, /* 01234567 */
	{0,0},{0,0},{0,0},{0,0},			 /* 89:; */
	OSXET("\046\154\164\073"),	/* &lt; */
	{ 0, 0 },	/* = */
	OSXET("\046\147\164\073"),	/* &gt; */
};

asn_enc_rval_t
OCTET_STRING_encode_xer_ascii(asn_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	asn_enc_rval_t er;
	uint8_t *buf, *end;
	uint8_t *ss;	/* Sequence start */
	ssize_t encoded_len = 0;

	(void)ilevel;	/* Unused argument */
	(void)flags;	/* Unused argument */

	if(!st || !st->buf)
		_ASN_ENCODE_FAILED;

	buf = st->buf;
	end = buf + st->size;
	for(ss = buf; buf < end; buf++) {
		int ch = *buf;
		int s_len;	/* Special encoding sequence length */

		/*
		 * Escape certain characters: X.680/11.15
		 */
		if(ch < sizeof(OCTET_STRING__xer_escape_table)
			/sizeof(OCTET_STRING__xer_escape_table[0])
		&& (s_len = OCTET_STRING__xer_escape_table[ch].size)) {
			if(((buf - ss) && cb(ss, buf - ss, app_key) < 0)
			|| cb(OCTET_STRING__xer_escape_table[ch].string, s_len,
					app_key) < 0)
				_ASN_ENCODE_FAILED;
			encoded_len += (buf - ss) + s_len;
			ss = buf + 1;
		}
	}

	encoded_len += (buf - ss);
	if((buf - ss) && cb(ss, buf - ss, app_key) < 0)
		_ASN_ENCODE_FAILED;

	er.encoded = encoded_len;
	return er;
}

int
OCTET_STRING_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	static const char *h2c = "0123456789ABCDEF";
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	char scratch[16 * 3 + 4];
	char *p = scratch;
	uint8_t *buf;
	uint8_t *end;
	size_t i;

	(void)td;	/* Unused argument */

	if(!st || !st->buf) return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;

	/*
	 * Dump the contents of the buffer in hexadecimal.
	 */
	buf = st->buf;
	end = buf + st->size;
	for(i = 0; buf < end; buf++, i++) {
		if(!(i % 16) && (i || st->size > 16)) {
			if(cb(scratch, p - scratch, app_key) < 0)
				return -1;
			_i_INDENT(1);
			p = scratch;
		}
		*p++ = h2c[(*buf >> 4) & 0x0F];
		*p++ = h2c[*buf & 0x0F];
		*p++ = 0x20;
	}

	if(p > scratch) {
		p--;	/* Remove the tail space */
		if(cb(scratch, p - scratch, app_key) < 0)
			return -1;
	}

	return 0;
}

int
OCTET_STRING_print_ascii(asn_TYPE_descriptor_t *td, const void *sptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st && st->buf) {
		return (cb(st->buf, st->size, app_key) < 0) ? -1 : 0;
	} else {
		return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;
	}
}

void
OCTET_STRING_free(asn_TYPE_descriptor_t *td, void *sptr, int contents_only) {
	OCTET_STRING_t *st = (OCTET_STRING_t *)sptr;
	struct _stack *stck = (struct _stack *)st->_asn_ctx.ptr;

	if(!td || !st)
		return;

	ASN_DEBUG("Freeing %s as OCTET STRING", td->name);

	if(st->buf) {
		FREEMEM(st->buf);
	}

	/*
	 * Remove decode-time stack.
	 */
	if(stck) {
		while(stck->tail) {
			struct _stack_el *sel = stck->tail;
			stck->tail = sel->prev;
			FREEMEM(sel);
		}
		FREEMEM(stck);
	}

	if(!contents_only) {
		FREEMEM(st);
	}
}

/*
 * Conversion routines.
 */
int
OCTET_STRING_fromBuf(OCTET_STRING_t *st, const char *str, int len) {
	void *buf;

	if(st == 0 || (str == 0 && len)) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * Clear the OCTET STRING.
	 */
	if(str == NULL) {
		if(st->buf)
			FREEMEM(st->buf);
		st->size = 0;
		return 0;
	}

	/* Determine the original string size, if not explicitly given */
	if(len < 0)
		len = strlen(str);

	/* Allocate and fill the memory */
	buf = MALLOC(len + 1);
	if(buf == NULL) {
		return -1;
	} else {
		st->buf = (uint8_t *)buf;
		st->size = len;
	}

	memcpy(buf, str, len);
	st->buf[st->size] = '\0';	/* Couldn't use memcpy(len+1)! */

	return 0;
}

OCTET_STRING_t *
OCTET_STRING_new_fromBuf(const char *str, int len) {
	OCTET_STRING_t *st;

	(void *)st = CALLOC(1, sizeof(*st));
	if(st && str && OCTET_STRING_fromBuf(st, str, len)) {
		free(st);
		st = NULL;
	}

	return st;
}

