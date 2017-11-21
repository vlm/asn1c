/*
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info> and contributors.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <NativeInteger.h>
#include <asn_internal.h>

asn_dec_rval_t
NativeInteger_decode_bner(const asn_codec_ctx_t *opt_codec_ctx,
                          const asn_TYPE_descriptor_t *td, void **nint_ptr,
                          const void *buf_ptr, size_t size, ber_tlv_tag_t tag,
                          int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)nint_ptr;
    (void)buf_ptr;
    (void)size;
    (void)tag;
    (void)tag_mode;

    asn_dec_rval_t tmp_error = {RC_FAIL, 0};
    ASN_DEBUG("%s Not yet implemented. Failed to decode %s", __func__,
              td->name);
    return tmp_error;
}

asn_enc_rval_t
NativeInteger_encode_bner(const asn_TYPE_descriptor_t *td, const void *sptr,
                          int tag_mode, ber_tlv_tag_t tag,
                          asn_app_consume_bytes_f *cb, void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)cb;
    (void)app_key;

    ASN_DEBUG("%s Not yet implemented. Failed to encode %s", __func__,
              td->name);
    ASN__ENCODE_FAILED;
}
