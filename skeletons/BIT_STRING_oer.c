/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef ASN_DISABLE_OER_SUPPORT

#include <asn_internal.h>
#include <BIT_STRING.h>
#include <errno.h>

asn_dec_rval_t
BIT_STRING_decode_oer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
                      const asn_oer_constraints_t *constraints, void **sptr,
                      const void *ptr, size_t size) {
    BIT_STRING_t *st = (BIT_STRING_t *)*sptr;
    const asn_oer_constraints_t *cts =
        constraints ? constraints : td->oer_constraints;
    ssize_t ct_size = cts ? cts->size : -1;
    asn_dec_rval_t rval = {RC_OK, 0};
    size_t expected_length = 0;

    (void)opt_codec_ctx;

    if(!st) {
        st = (BIT_STRING_t *)(*sptr = CALLOC(1, sizeof(*st)));
        if(!st) ASN__DECODE_FAILED;
    }

    if(ct_size >= 0) {
        expected_length = (ct_size + 7) >> 3;
        st->bits_unused = (8 - (ct_size & 7)) & 7;
    } else {
        /*
         * X.696 (08/2015) #13.3.1
         * Encode length determinant as _number of octets_, but only
         * if upper bound is not equal to lower bound.
         */
        ssize_t len_len = oer_fetch_length(ptr, size, &expected_length);
        if(len_len > 0) {
            ptr = (const char *)ptr + len_len;
            size -= len_len;
        } else if(len_len == 0) {
            ASN__DECODE_STARVED;
        } else if(len_len < 0) {
            ASN__DECODE_FAILED;
        }

        if(expected_length < 1) {
            ASN__DECODE_STARVED;
        }

        st->bits_unused = ((const uint8_t *)ptr)[0];
        if(st->bits_unused & ~7) {
            ASN_DEBUG("%s: unused bits outside of 0..7 range", td->name);
            ASN__DECODE_FAILED;
        }
        ptr = (const char *)ptr + 1;
        size--;
        expected_length--;
        rval.consumed = len_len + 1;
    }

    if(size < expected_length) {
        ASN__DECODE_STARVED;
    } else {
        uint8_t *buf = MALLOC(expected_length + 1);
        if(buf == NULL) {
            ASN__DECODE_FAILED;
        } else {
            memcpy(buf, ptr, expected_length);
            buf[expected_length] = '\0';
        }
        FREEMEM(st->buf);
        st->buf = buf;
        st->size = expected_length;
        if(expected_length > 0) {
            buf[expected_length - 1] &= (0xff << st->bits_unused);
        }

        rval.consumed += expected_length;
        return rval;
    }
}

/*
 * Encode as Canonical OER.
 */
asn_enc_rval_t
BIT_STRING_encode_oer(asn_TYPE_descriptor_t *td,
                        const asn_oer_constraints_t *constraints, void *sptr,
                        asn_app_consume_bytes_f *cb, void *app_key) {
    asn_enc_rval_t er = {-1,td,sptr};
    (void)constraints;
    (void)cb;
    (void)app_key;
    return er;
}


#endif  /* ASN_DISABLE_OER_SUPPORT */
