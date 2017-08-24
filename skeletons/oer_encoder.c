/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>

/*
 * The OER encoder of any type.
 */
asn_enc_rval_t
oer_encode(asn_TYPE_descriptor_t *type_descriptor, void *struct_ptr,
        asn_app_consume_bytes_f *consume_bytes, void *app_key) {

        ASN_DEBUG("OER encoder invoked for %s",
                type_descriptor->name);

        /*
         * Invoke type-specific encoder.
         */
        return type_descriptor->op->oer_encoder(type_descriptor, 0,
                struct_ptr,     /* Pointer to the destination structure */
                consume_bytes, app_key);
}

/*
 * Argument type and callback necessary for oer_encode_to_buffer().
 */
typedef struct enc_to_buf_arg {
        void *buffer;
        size_t left;
} enc_to_buf_arg;
static int encode_to_buffer_cb(const void *buffer, size_t size, void *key) {
        enc_to_buf_arg *arg = (enc_to_buf_arg *)key;

        if(arg->left < size)
                return -1;      /* Data exceeds the available buffer size */

        memcpy(arg->buffer, buffer, size);
        arg->buffer = ((char *)arg->buffer) + size;
        arg->left -= size;

        return 0;
}

/*
 * A variant of the oer_encode() which encodes the data into the provided buffer
 */
asn_enc_rval_t
oer_encode_to_buffer(struct asn_TYPE_descriptor_s *type_descriptor,
                     const asn_oer_constraints_t *constraints,
                     void *struct_ptr,  /* Structure to be encoded */
                     void *buffer,      /* Pre-allocated buffer */
                     size_t buffer_size /* Initial buffer size (maximum) */
                     ) {
    enc_to_buf_arg arg;
    asn_enc_rval_t ec;

    arg.buffer = buffer;
    arg.left = buffer_size;

    if(type_descriptor->op->oer_encoder == NULL) {
        ec.encoded = -1;
        ec.failed_type = type_descriptor;
        ec.structure_ptr = struct_ptr;
        ASN_DEBUG("OER encoder is not defined for %s",
                type_descriptor->name);
    } else {
        ec = type_descriptor->op->oer_encoder(
            type_descriptor, constraints,
            struct_ptr, /* Pointer to the destination structure */
            encode_to_buffer_cb, &arg);
        if(ec.encoded != -1) {
            assert(ec.encoded == (ssize_t)(buffer_size - arg.left));
            /* Return the encoded contents size */
        }
    }
    return ec;
}
