#include <asn_application.h>
#include <asn_internal.h>
#include <per_decoder.h>

asn_dec_rval_t
uper_decode(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td, void **sptr, const void *buffer, size_t size) {
	asn_codec_ctx_t s_codec_ctx;
	asn_per_data_t pd;

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

	/* Fill in the position indicator */
	pd.buffer = (const uint8_t *)buffer;
	pd.nboff = 0;
	pd.nbits = 8 * size; 	/* 8 is CHAR_BIT from <limits.h> */

	/*
	 * Invoke type-specific decoder.
	 */
	if(!td->uper_decoder)
		_ASN_DECODE_FAILED;	/* PER is not compiled in */
	return td->uper_decoder(opt_codec_ctx, td, 0, sptr, &pd);
}

