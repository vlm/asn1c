/*
 * Copyright (c) 2017 Jon Ringle <jringle@gridpoint.com>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <bner_decoder.h>
#include <errno.h>

/*
 * The BNER decoder of any type.
 */
asn_dec_rval_t
bner_decode(const asn_codec_ctx_t *opt_codec_ctx,
            const asn_TYPE_descriptor_t *td, void **struct_ptr, const void *ptr,
            size_t size) {
    asn_codec_ctx_t s_codec_ctx;

    if(!td) {
        asn_dec_rval_t tmp_error = {RC_FAIL, 0};
        ASN_DEBUG("%s: Failed to decode. type_descriptor NULL", __func__);
        return tmp_error;
    }

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
    return td->op->bner_decoder(opt_codec_ctx, td,
                                struct_ptr, /* Pointer to the dest struct */
                                ptr, size,  /* Buffer and its size */
                                -1,         /* Unknown tag */
                                0           /* Default tag mode is 0 */
                                );
}
