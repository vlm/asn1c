/*
 * Copyright (c) 2007 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <per_support.h>
#include <constr_TYPE.h>
#include <per_opentype.h>

typedef struct uper_ugot_key {
	asn_per_data_t oldpd;	/* Old per data source */
	size_t unclaimed;
	size_t ot_moved;	/* Number of bits moved by OT processing */
	int repeat;
} uper_ugot_key;

static int uper_ugot_refill(asn_per_data_t *pd);
static asn_dec_rval_t uper_sot_suck(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td, asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd);

/*
 * #10.1, #10.2
 */
int
uper_open_type_put(asn_TYPE_descriptor_t *td, asn_per_constraints_t *constraints, void *sptr, asn_per_outp_t *po) {
	void *buf;
	ssize_t size;

	ASN_DEBUG("Encoding as open type %s", td->name);
	size = uper_encode_to_new_buffer(td, constraints, sptr, &buf);
	if(size <= 0) return -1;

	ASN_DEBUG("Putting %s of length %d", td->name, size);
	while(size) {
		ssize_t maySave = uper_put_length(po, size);
		if(maySave < 0) break;
		if(per_put_many_bits(po, buf, maySave * 8)) break;
		buf = (char *)buf + maySave;
		size -= maySave;
	}

	if(size) {
		FREEMEM(buf);
		return -1;
	}

	return 0;
}

asn_dec_rval_t
uper_open_type_get(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd) {
	uper_ugot_key arg;
	asn_dec_rval_t rv;
	ssize_t padding;

	_ASN_STACK_OVERFLOW_CHECK(opt_codec_ctx);

	ASN_DEBUG("Getting open type off %d (%d+%d), %p", pd->moved, pd->nboff, pd->nbits, pd->buffer);
	arg.oldpd = *pd;
	arg.unclaimed = 0;
	arg.ot_moved = 0;
	arg.repeat = 1;
	pd->refill = uper_ugot_refill;
	pd->refill_key = &arg;
	pd->nbits = pd->nboff;	/* 0 good bits at this point, will refill */
	pd->moved = 0;	/* This now counts the open type size in bits */

	rv = td->uper_decoder(opt_codec_ctx, td, constraints, sptr, pd);

	ASN_DEBUG("Open type %s consumed %d off of %d unclaimed=%d, repeat=%d",
		td->name, pd->moved, arg.oldpd.moved,
		arg.unclaimed, arg.repeat);

	ASN_DEBUG("OT1 moved %d, estimated %d uncl=%d",
		arg.oldpd.moved,
		arg.oldpd.nboff + ((((int)arg.oldpd.buffer) & 0x7) << 3),
		arg.unclaimed
	);

	padding = pd->moved % 8;
	if(padding) {
		int32_t pvalue;
		if(padding > 7) {
			ASN_DEBUG("Too large padding %d in open type",
				padding);
			rv.code = RC_FAIL;
			return rv;
		}
		padding = 8 - padding;
		ASN_DEBUG("Getting padding of %d bits", padding);
		pvalue = per_get_few_bits(pd, padding);
		switch(pvalue) {
		case -1:
			ASN_DEBUG("Padding skip failed");
			_ASN_DECODE_STARVED;
		case 0: break;
		default:
			ASN_DEBUG("Non-blank padding (%d bits 0x%02x)",
				padding, pvalue);
			_ASN_DECODE_FAILED;
		}
	}
	if(pd->nbits != pd->nboff) {
		ASN_DEBUG("Open type container overhead of %d bits!", pd->nbits - pd->nboff);
		if(1) _ASN_DECODE_FAILED;
		arg.unclaimed += pd->nbits - pd->nboff;
	}

	/* Adjust pd back so it points to original data */
	pd->nbits = arg.oldpd.nbits - (pd->moved - arg.ot_moved);
	pd->moved = arg.oldpd.moved + (pd->moved - arg.ot_moved);
	pd->refill = arg.oldpd.refill;
	pd->refill_key = arg.oldpd.refill_key;

	/* Skip data not consumed by the decoder */
	if(arg.unclaimed) ASN_DEBUG("Getting unclaimed %d", arg.unclaimed);
	while(arg.unclaimed) {
		size_t toget = 24;
		if(arg.unclaimed < toget)
			toget = arg.unclaimed;
		arg.unclaimed -= toget;
		switch(per_get_few_bits(pd, toget)) {
		case -1:
			ASN_DEBUG("Claim of %d failed", toget);
			_ASN_DECODE_STARVED;
		case 0:
			ASN_DEBUG("Got claim of %d", toget);
			continue;
		default:
			/* Padding must be blank */
			ASN_DEBUG("Non-blank unconsumed padding");
			_ASN_DECODE_FAILED;
		}
	}

	if(0)	/* Special debugging assert */
	assert(pd->moved == pd->nboff + ((((int)pd->buffer) & 0x7) << 3));

	if(arg.repeat) {
		ASN_DEBUG("Not consumed the whole thing");
		rv.code = RC_FAIL;
		return rv;
	}

	return rv;
}

int
uper_open_type_skip(asn_codec_ctx_t *opt_codec_ctx, asn_per_data_t *pd) {
	asn_TYPE_descriptor_t s_td;
	asn_dec_rval_t rv;

	s_td.name = "<unknown extension>";
	s_td.uper_decoder = uper_sot_suck;

	rv = uper_open_type_get(opt_codec_ctx, &s_td, 0, 0, pd);
	if(rv.code != RC_OK)
		return -1;
	else
		return 0;
}

/*
 * Internal functions.
 */

static asn_dec_rval_t
uper_sot_suck(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd) {
	asn_dec_rval_t rv;

	(void)opt_codec_ctx;
	(void)td;
	(void)constraints;
	(void)sptr;

	while(per_get_few_bits(pd, 24) >= 0);

	rv.code = RC_OK;
	rv.consumed = pd->moved;

	return rv;
}

static int
uper_ugot_refill(asn_per_data_t *pd) {
	uper_ugot_key *arg = pd->refill_key;
	ssize_t next_chunk_bytes, next_chunk_bits;
	ssize_t avail;

	asn_per_data_t *oldpd = &arg->oldpd;

	ASN_DEBUG("REFILLING (%+db) [from %d (%d->%d)_%d] now [%d (%d->%d)_%d] uncl %d",
		pd->buffer - oldpd->buffer,
		oldpd->nbits - oldpd->nboff, oldpd->nboff, oldpd->nbits, oldpd->moved,
		pd->nbits - pd->nboff, pd->nboff, pd->nbits, pd->moved, arg->unclaimed);

	/* Advance our position to where pd is */
	oldpd->buffer = pd->buffer;
	oldpd->nboff  = pd->nboff;
	oldpd->nbits -= pd->moved - arg->ot_moved;
	oldpd->moved += pd->moved - arg->ot_moved;
	arg->ot_moved = pd->moved;

	if(arg->unclaimed) {
		/* Refill the container */
		if(per_get_few_bits(oldpd, 1))
			return -1;
		if(oldpd->nboff == 0) {
			assert(0);
			return -1;
		}
		pd->buffer = oldpd->buffer;
		pd->nboff = oldpd->nboff - 1;
		pd->nbits = oldpd->nbits;
		ASN_DEBUG("Return from UNCLAIMED");
		return 0;
	}

	if(!arg->repeat) {
		ASN_DEBUG("Want more but refill doesn't have it");
		return -1;
	}

	next_chunk_bytes = uper_get_length(oldpd, -1, &arg->repeat);
	ASN_DEBUG("Open type LENGTH %d bytes at off %d, repeat %d",
		next_chunk_bytes, oldpd->moved, arg->repeat);
	if(next_chunk_bytes < 0) return -1;
	if(next_chunk_bytes == 0) {
		pd->refill = 0;	/* No more refills, naturally */
		assert(!arg->repeat);	/* Implementation guarantee */
	}
	next_chunk_bits = next_chunk_bytes << 3;
	avail = oldpd->nbits - oldpd->nboff;
	if(avail >= next_chunk_bits) {
		pd->nbits = oldpd->nboff + next_chunk_bits;
		arg->unclaimed = 0;
	} else {
		pd->nbits = oldpd->nbits;
		arg->unclaimed = next_chunk_bits - avail;
		ASN_DEBUG("Parent has %d, require %d, will claim %d", avail, next_chunk_bits, arg->unclaimed);
	}
	pd->buffer = oldpd->buffer;
	pd->nboff = oldpd->nboff;
	return 0;
}
