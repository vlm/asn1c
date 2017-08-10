/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	OER_ENCODER_H
#define	OER_ENCODER_H

#include <asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s;	/* Forward declaration */

/*
 * The Octet Encoding Rules (OER, X.696 08/2015) encoder for any type.
 * This function may be invoked directly by the application.
 */
asn_enc_rval_t oer_encode(struct asn_TYPE_descriptor_s *type_descriptor,
                          void *struct_ptr, /* Structure to be encoded */
                          asn_app_consume_bytes_f *consume_bytes_cb,
                          void *app_key /* Arbitrary callback argument */
                          );

/* A variant of oer_encode() which encodes data into the pre-allocated buffer */
asn_enc_rval_t oer_encode_to_buffer(
    struct asn_TYPE_descriptor_s *type_descriptor,
    const asn_oer_constraints_t *constraints,
    void *struct_ptr,  /* Structure to be encoded */
    void *buffer,      /* Pre-allocated buffer */
    size_t buffer_size /* Initial buffer size (maximum) */
    );

/*
 * Type of the generic OER encoder.
 */
typedef asn_enc_rval_t(oer_type_encoder_f)(
    struct asn_TYPE_descriptor_s *type_descriptor,
    const asn_oer_constraints_t *constraints,
    void *struct_ptr,                          /* Structure to be encoded */
    asn_app_consume_bytes_f *consume_bytes_cb, /* Callback */
    void *app_key                              /* Arbitrary callback argument */
    );


#ifdef __cplusplus
}
#endif

#endif	/* OER_ENCODER_H */
