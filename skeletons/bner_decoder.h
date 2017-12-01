/*
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info> and contributors.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef _BNER_DECODER_H_
#define _BNER_DECODER_H_

#include <asn_application.h>
#include <bner_support.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s; /* Forward declaration */
struct asn_codec_ctx_s;       /* Forward declaration */

/*
 * Type of generic function which decodes the byte stream into the structure.
 */
typedef asn_dec_rval_t(bner_type_decoder_f)(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buf_ptr, size_t size, ber_tlv_tag_t tag, int tag_mode);

/*
 * The BNER decoder of any type.
 * This function may be invoked directly from the application.
 */
asn_dec_rval_t bner_decode(const struct asn_codec_ctx_s *opt_codec_ctx,
                           const struct asn_TYPE_descriptor_s *td,
                           void **struct_ptr,  /* Ptr to target's struct ptr */
                           const void *buffer, /* Data to be decoded */
                           size_t size         /* Size of that buffer */
                           );

#ifdef __cplusplus
}
#endif

#endif /* _BNER_DECODER_H_ */
