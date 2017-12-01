/*
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info> and contributors.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef _BNER_ENCODER_H_
#define _BNER_ENCODER_H_

#include <asn_application.h>
#include <bner_support.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s; /* Forward declaration */
struct asn_codec_ctx_s;       /* Forward declaration */

/*
 * Type of the generic BNER encoder.
 */
typedef asn_enc_rval_t(bner_type_encoder_f)(
    const struct asn_TYPE_descriptor_s *td,
    const void *struct_ptr, /* Structure to be encoded */
    int tag_mode,           /* {-1,0,1}: IMPLICIT, no, EXPLICIT */
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb, /* Callback */
    void *app_key /* Arbitrary callback argument */
    );

/*
 * The BNER encoder of any type.
 * This function may be invoked directly by the application.
 */
asn_enc_rval_t bner_encode(const struct asn_TYPE_descriptor_s *td,
                           const void *struct_ptr, /* Structure to be encoded */
                           asn_app_consume_bytes_f *consume_bytes_cb,
                           void *app_key /* Arbitrary callback argument */
                           );

/* A variant of bner_encode() which encodes data into a pre-allocated buffer */
asn_enc_rval_t bner_encode_to_buffer(const struct asn_TYPE_descriptor_s *td,
                                     const void *struct_ptr, void *buffer,
                                     size_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif /* _BNER_ENCODER_H_ */
