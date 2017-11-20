/*
 * Copyright (c) 2017 Jon Ringle <jringle@gridpoint.com>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <bner_encoder.h>
#include <errno.h>

/*
 * The BNER encoder of any type.
 */
asn_enc_rval_t
bner_encode(const asn_TYPE_descriptor_t *td, const void *sptr,
            asn_app_consume_bytes_f *consume_bytes, void *app_key) {
    if(!td) ASN__ENCODE_FAILED;

    ASN_DEBUG("BNER encoder invoked for %s", td->name);

    /*
     * Invoke type-specific encoder.
     */
    return td->op->bner_encoder(td, sptr, 0, 0, consume_bytes, app_key);
}

/*
 * Argument type and callback necessary for bner_encode_to_buffer().
 */
typedef struct enc_to_buf_arg {
    void *buffer;
    size_t left;
} enc_to_buf_arg;

static int
encode_to_buffer_cb(const void *buffer, size_t size, void *key) {
    enc_to_buf_arg *arg = (enc_to_buf_arg *)key;

    if(arg->left < size) return -1; /* Data exceeds the available buffer size */

    memcpy(arg->buffer, buffer, size);
    arg->buffer = ((char *)arg->buffer) + size;
    arg->left -= size;

    return 0;
}

/*
 * A variant of the bner_encode() which encodes the data into the provided
 * buffer
 */
asn_enc_rval_t
bner_encode_to_buffer(const asn_TYPE_descriptor_t *td, const void *struct_ptr,
                      void *buffer, size_t buffer_size) {
    enc_to_buf_arg arg;
    asn_enc_rval_t ec;

    arg.buffer = buffer;
    arg.left = buffer_size;

    ec = td->op->bner_encoder(
        td, struct_ptr, /* Pointer to the destination structure */
        0, 0, encode_to_buffer_cb, &arg);

    if(ec.encoded != -1) {
        assert(ec.encoded == (ssize_t)(buffer_size - arg.left));
        /* Return the encoded contents size */
    }
    return ec;
}
