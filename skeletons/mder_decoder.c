/*-
 * Copyright (c) 2010 Jose Antonio Santos-Cadenas <santoscadenas@gmail.com>
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>

/*
 * The MDER decoder of any type.
 */
asn_dec_rval_t
mder_decode(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *type_descriptor,
	void **struct_ptr, const void *ptr, size_t size) {
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
	return type_descriptor->mder_decoder(opt_codec_ctx, type_descriptor,
		struct_ptr,	/* Pointer to the destination structure */
		ptr, size,	/* Buffer and its size */
		0		/* Default tag mode is 0 */
		);
}
