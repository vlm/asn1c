/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef ASN_DISABLE_OER_SUPPORT

#include <asn_internal.h>
#include <NativeInteger.h>
#include <errno.h>

asn_dec_rval_t
NativeInteger_decode_oer(asn_codec_ctx_t *opt_codec_ctx,
                         asn_TYPE_descriptor_t *td,
                         const asn_oer_constraints_t *constraints,
                         void **nint_ptr, const void *ptr, size_t size) {
    asn_INTEGER_specifics_t *specs = (asn_INTEGER_specifics_t *)td->specifics;
    asn_dec_rval_t rval = {RC_OK, 0};
    long *native = (long *)*nint_ptr;
    INTEGER_t tmpint;
    INTEGER_t *tmpintptr = &tmpint;

    memset(&tmpint, 0, sizeof(tmpint));

    if(!native) {
        native = (long *)(*nint_ptr = CALLOC(1, sizeof(*native)));
        if(!native) ASN__DECODE_FAILED;
    }

    /*
     * OPTIMIZATION: Encode directly rather than passing through INTEGER.
     * Saves a memory allocation.
     */
    rval = INTEGER_decode_oer(opt_codec_ctx, &asn_DEF_INTEGER, constraints,
                              (void **)&tmpintptr, ptr, size);
    if(rval.code != RC_OK) {
        ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_INTEGER, &tmpint);
        return rval;
    }

    if(specs && specs->field_unsigned) {
        unsigned long ul;
        if(asn_INTEGER2ulong(&tmpint, &ul) != 0) {
            ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_INTEGER, &tmpint);
            rval.code = RC_FAIL;
            rval.consumed = 0;
            return rval;
        } else {
            *native = ul;
        }
    } else {
        long l;
        if(asn_INTEGER2long(&tmpint, &l) != 0) {
            ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_INTEGER, &tmpint);
            rval.code = RC_FAIL;
            rval.consumed = 0;
            return rval;
        } else {
            *native = l;
        }
    }

    return rval;
}

/*
 * Encode as Canonical OER.
 */
asn_enc_rval_t
NativeInteger_encode_oer(asn_TYPE_descriptor_t *td,
                         const asn_oer_constraints_t *constraints, void *sptr,
                         asn_app_consume_bytes_f *cb, void *app_key) {
    asn_INTEGER_specifics_t *specs = (asn_INTEGER_specifics_t *)td->specifics;
    INTEGER_t tmpint;
    long native;

    if(!sptr) ASN__ENCODE_FAILED;

    native = *(const long *)sptr;
    memset(&tmpint, 0, sizeof(tmpint));

    ASN_DEBUG("Encoding %s %ld as NativeInteger", td ? td->name : "", native);

    if((specs && specs->field_unsigned) ? asn_ulong2INTEGER(&tmpint, native)
                                        : asn_long2INTEGER(&tmpint, native)) {
        ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_INTEGER, &tmpint);
        ASN__ENCODE_FAILED;
    } else {
        asn_enc_rval_t er =
            INTEGER_encode_oer(td, constraints, &tmpint, cb, app_key);
        ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_INTEGER, &tmpint);
        return er;
    }
}

#endif  /* ASN_DISABLE_OER_SUPPORT */
