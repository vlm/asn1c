/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>
 * Copyright (c) 2010 Jose Antonio Santos-Cadenas <santoscadenas@gmail.com>
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>

/*
 * The MDER decoder of any type.
 */
asn_dec_rval_t
mder_decode(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
				void **sptr, const void *buffer, size_t size) {
	asn_codec_ctx_t s_codec_ctx;

	/*
	 * Stack checker requires that the codec context
	 * must be allocated on the stack.
	 */
	if(opt_codec_ctx) {
		if(opt_codec_ctx->max_stack_size) {
			s_codec_ctx = *opt_codec_ctx;
			opt_codec_ctx = &s_codec_ctx;
		}
	} else {
		/* If context is not given, be security-conscious anyway */
		memset(&s_codec_ctx, 0, sizeof(s_codec_ctx));
		s_codec_ctx.max_stack_size = _ASN_DEFAULT_STACK_MAX;
		opt_codec_ctx = &s_codec_ctx;
	}

	/*
	 * Invoke type-specific decoder.
	 */
	if(!td->mder_decoder)
		_ASN_DECODE_FAILED;	/* MDER is not compiled in */

	return td->mder_decoder(opt_codec_ctx, td,
		sptr,	/* Pointer to the destination structure */
		buffer, size,	/* Buffer and its size */
		0		/* No specifics constraints */
		);
}

asn_dec_rval_t
NON_SUP_decode_mder(struct asn_codec_ctx_s *opt_codec_ctx,
		struct asn_TYPE_descriptor_s *td,
		void **struct_ptr, const void *buf_ptr, size_t size,
		asn_mder_contraints_t constr) {

	_ASN_DECODE_FAILED;
}
