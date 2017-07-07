/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef ASN_DISABLE_OER_SUPPORT

#include <asn_internal.h>
#include <INTEGER.h>
#include <errno.h>

asn_dec_rval_t
INTEGER_decode_oer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
                   asn_oer_constraints_t *constraints, void **sptr,
                   const void *ptr, size_t size) {
    asn_INTEGER_specifics_t *specs = (asn_INTEGER_specifics_t *)td->specifics;
    asn_dec_rval_t rval = {RC_OK, 0};
    INTEGER_t *st = (INTEGER_t *)*sptr;
    asn_oer_constraint_t *ct;
    int repeat;

    (void)opt_codec_ctx;

    if(!st) {
        st = (INTEGER_t *)(*sptr = CALLOC(1, sizeof(*st)));
        if(!st) ASN__DECODE_FAILED;
    }

    if(!constraints) constraints = td->oer_constraints;
    ct = constraints ? &constraints->value : 0;

    FREEMEM(st->buf);
    st->buf = 0;
    st->size = 0;
}

#endif  /* ASN_DISABLE_OER_SUPPORT */
