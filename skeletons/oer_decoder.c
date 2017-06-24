#include <asn_application.h>
#include <asn_internal.h>
#include <oer_decoder.h>
asn_dec_rval_t
oer_decode(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td, void **sptr, const void *buffer, size_t size)
{
	asn_codec_ctx_t s_codec_ctx;
	asn_dec_rval_t rval;
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
		s_codec_ctx.max_stack_size = ASN__DEFAULT_STACK_MAX;
		opt_codec_ctx = &s_codec_ctx;
	}

	/*
	 * Invoke type-specific decoder.
	 */
	if(!td->oer_decoder)
		ASN__DECODE_FAILED;	/* PER is not compiled in */
	return td->oer_decoder(opt_codec_ctx, td, 0, sptr, buffer, size);
}

