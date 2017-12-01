/*
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info> and contributors.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <bner_fixed_stubs.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

/*
 * BACnet defines two different encodings:
 * 1) Fixed encoding (Clause 20.1)
 * The fixed encoding is used on the following PDUs:
 *		BACnetPDU
 *		BACnet-Confirmed-Request-PDU
 *		BACnet-Unconfirmed-Request-PDU
 *		BACnet-SimpleACK-PDU
 *		BACnet-ComplexACK-PDU
 *		BACnet-SegmentACK-PDU
 *		BACnet-Error-PDU
 *		BACnet-Reject-PDU
 *		BACnet-Abort-PDU
 *		BACnet-Confirmed-Service-Request
 *		BACnet-Unconfirmed-Service-Request
 *		BACnet-Confirmed-Service-ACK
 *		BACnet-Error
 *
 * The fixed encoding is outside the scope of the asn1 compiler, and
 * only a weak function that fails encoding/decoding these PDUs is provided here
 *
 * 2) Variable encoding (Clause 20.2)
 * All other BACnet rules are encoded with the BNER variable encoding.
 * This encoding is provided for in the asn1 compiler
 */

asn_TYPE_operation_t asn_OP_BACnetPDU = {CHOICE_free,
                                         CHOICE_print,
                                         CHOICE_compare,
                                         CHOICE_decode_ber,
                                         CHOICE_encode_der,
                                         CHOICE_decode_xer,
                                         CHOICE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
                                         0,
                                         0,
#else
                                         CHOICE_decode_oer,
                                         CHOICE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
                                         0,
                                         0,
#else
                                         CHOICE_decode_uper,
                                         CHOICE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
                                         0,
                                         0,
#else
                                         CHOICE_decode_BACnetPDU,
                                         CHOICE_encode_BACnetPDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
                                         CHOICE_random_fill,
                                         CHOICE_outmost_tag};

asn_dec_rval_t
CC_ATTRIBUTE(weak)
    CHOICE_decode_BACnetPDU(const struct asn_codec_ctx_s *opt_codec_ctx,
                            const struct asn_TYPE_descriptor_s *td,
                            void **struct_ptr, const void *buffer, size_t size,
                            ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak)
    CHOICE_encode_BACnetPDU(const struct asn_TYPE_descriptor_s *td,
                            const void *sptr, int tag_mode, ber_tlv_tag_t tag,
                            asn_app_consume_bytes_f *consume_bytes_cb,
                            void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Confirmed_Request_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_Confirmed_Request_PDU,
    SEQUENCE_encode_BACnet_Confirmed_Request_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_Confirmed_Request_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_encode_BACnet_Confirmed_Request_PDU(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Unconfirmed_Request_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_Unconfirmed_Request_PDU,
    SEQUENCE_encode_BACnet_Unconfirmed_Request_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_Unconfirmed_Request_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_encode_BACnet_Unconfirmed_Request_PDU(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_SimpleACK_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_SimpleACK_PDU,
    SEQUENCE_encode_BACnet_SimpleACK_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_SimpleACK_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_encode_BACnet_SimpleACK_PDU(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_ComplexACK_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_ComplexACK_PDU,
    SEQUENCE_encode_BACnet_ComplexACK_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_ComplexACK_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_encode_BACnet_ComplexACK_PDU(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_SegmentACK_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_SegmentACK_PDU,
    SEQUENCE_encode_BACnet_SegmentACK_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_SegmentACK_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_encode_BACnet_SegmentACK_PDU(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Error_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_Error_PDU,
    SEQUENCE_encode_BACnet_Error_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_Error_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak)
    SEQUENCE_encode_BACnet_Error_PDU(const struct asn_TYPE_descriptor_s *td,
                                     const void *sptr, int tag_mode,
                                     ber_tlv_tag_t tag,
                                     asn_app_consume_bytes_f *consume_bytes_cb,
                                     void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Reject_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_Reject_PDU,
    SEQUENCE_encode_BACnet_Reject_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_Reject_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak)
    SEQUENCE_encode_BACnet_Reject_PDU(const struct asn_TYPE_descriptor_s *td,
                                      const void *sptr, int tag_mode,
                                      ber_tlv_tag_t tag,
                                      asn_app_consume_bytes_f *consume_bytes_cb,
                                      void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Abort_PDU = {
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_compare,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_oer,
    SEQUENCE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_uper,
    SEQUENCE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    SEQUENCE_decode_BACnet_Abort_PDU,
    SEQUENCE_encode_BACnet_Abort_PDU,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    SEQUENCE_random_fill,
    0 /* Use generic outmost tag fetcher */
};

asn_dec_rval_t
CC_ATTRIBUTE(weak) SEQUENCE_decode_BACnet_Abort_PDU(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak)
    SEQUENCE_encode_BACnet_Abort_PDU(const struct asn_TYPE_descriptor_s *td,
                                     const void *sptr, int tag_mode,
                                     ber_tlv_tag_t tag,
                                     asn_app_consume_bytes_f *consume_bytes_cb,
                                     void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Confirmed_Service_Request = {
    CHOICE_free,
    CHOICE_print,
    CHOICE_compare,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_oer,
    CHOICE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_uper,
    CHOICE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_BACnet_Confirmed_Service_Request,
    CHOICE_encode_BACnet_Confirmed_Service_Request,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    CHOICE_random_fill,
    CHOICE_outmost_tag};

asn_dec_rval_t
CC_ATTRIBUTE(weak) CHOICE_decode_BACnet_Confirmed_Service_Request(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) CHOICE_encode_BACnet_Confirmed_Service_Request(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Unconfirmed_Service_Request = {
    CHOICE_free,
    CHOICE_print,
    CHOICE_compare,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_oer,
    CHOICE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_uper,
    CHOICE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
    0,
    0,
#else
    CHOICE_decode_BACnet_Unconfirmed_Service_Request,
    CHOICE_encode_BACnet_Unconfirmed_Service_Request,
#endif /* ASN_DISABLE_BNER_SUPPORT */
    CHOICE_random_fill,
    CHOICE_outmost_tag};

asn_dec_rval_t
CC_ATTRIBUTE(weak) CHOICE_decode_BACnet_Unconfirmed_Service_Request(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) CHOICE_encode_BACnet_Unconfirmed_Service_Request(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Confirmed_Service_ACK = {CHOICE_free,
                                                            CHOICE_print,
                                                            CHOICE_compare,
                                                            CHOICE_decode_ber,
                                                            CHOICE_encode_der,
                                                            CHOICE_decode_xer,
                                                            CHOICE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
                                                            0,
                                                            0,
#else
                                                            CHOICE_decode_oer,
                                                            CHOICE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
                                                            0,
                                                            0,
#else
                                                            CHOICE_decode_uper,
                                                            CHOICE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
                                                            0,
                                                            0,
#else
                                                            CHOICE_decode_BACnet_Confirmed_Service_ACK,
                                                            CHOICE_encode_BACnet_Confirmed_Service_ACK,
#endif /* ASN_DISABLE_BNER_SUPPORT */
                                                            CHOICE_random_fill,
                                                            CHOICE_outmost_tag};

asn_dec_rval_t
CC_ATTRIBUTE(weak) CHOICE_decode_BACnet_Confirmed_Service_ACK(
    const struct asn_codec_ctx_s *opt_codec_ctx,
    const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
    const void *buffer, size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak) CHOICE_encode_BACnet_Confirmed_Service_ACK(
    const struct asn_TYPE_descriptor_s *td, const void *sptr, int tag_mode,
    ber_tlv_tag_t tag, asn_app_consume_bytes_f *consume_bytes_cb,
    void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}

asn_TYPE_operation_t asn_OP_BACnet_Error = {CHOICE_free,
                                            CHOICE_print,
                                            CHOICE_compare,
                                            CHOICE_decode_ber,
                                            CHOICE_encode_der,
                                            CHOICE_decode_xer,
                                            CHOICE_encode_xer,
#ifdef ASN_DISABLE_OER_SUPPORT
                                            0,
                                            0,
#else
                                            CHOICE_decode_oer,
                                            CHOICE_encode_oer,
#endif /* ASN_DISABLE_OER_SUPPORT */
#ifdef ASN_DISABLE_PER_SUPPORT
                                            0,
                                            0,
#else
                                            CHOICE_decode_uper,
                                            CHOICE_encode_uper,
#endif /* ASN_DISABLE_PER_SUPPORT */
#ifdef ASN_DISABLE_BNER_SUPPORT
                                            0,
                                            0,
#else
                                            CHOICE_decode_BACnet_Error,
                                            CHOICE_encode_BACnet_Error,
#endif /* ASN_DISABLE_BNER_SUPPORT */
                                            CHOICE_random_fill,
                                            CHOICE_outmost_tag};

asn_dec_rval_t
CC_ATTRIBUTE(weak)
    CHOICE_decode_BACnet_Error(const struct asn_codec_ctx_s *opt_codec_ctx,
                               const struct asn_TYPE_descriptor_s *td,
                               void **struct_ptr, const void *buffer,
                               size_t size, ber_tlv_tag_t tag, int tag_mode) {
    (void)opt_codec_ctx;
    (void)td;
    (void)struct_ptr;
    (void)buffer;
    (void)size;
    (void)tag;
    (void)tag_mode;
    ASN_DEBUG("Missing %s", __func__);
    ASN__DECODE_FAILED;
}

asn_enc_rval_t
CC_ATTRIBUTE(weak)
    CHOICE_encode_BACnet_Error(const struct asn_TYPE_descriptor_s *td,
                               const void *sptr, int tag_mode,
                               ber_tlv_tag_t tag,
                               asn_app_consume_bytes_f *consume_bytes_cb,
                               void *app_key) {
    (void)td;
    (void)sptr;
    (void)tag_mode;
    (void)tag;
    (void)consume_bytes_cb;
    (void)app_key;
    ASN_DEBUG("Missing %s", __func__);
    ASN__ENCODE_FAILED;
}
