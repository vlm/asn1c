/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <OPEN_TYPE.h>
#include <constr_CHOICE.h>
#include <per_opentype.h>
#include <errno.h>


asn_dec_rval_t
OPEN_TYPE_uper_get(asn_codec_ctx_t *opt_codec_ctx,
                   asn_TYPE_descriptor_t *td, void *sptr,
                   asn_TYPE_member_t *elm, asn_per_data_t *pd) {
    asn_type_selector_result_t selected;
    void *memb_ptr;   /* Pointer to the member */
    void **memb_ptr2; /* Pointer to that pointer */
    asn_dec_rval_t rv;

    if(!(elm->flags & ATF_OPEN_TYPE) || !elm->type_selector) {
        ASN__DECODE_FAILED;
    }

    selected = elm->type_selector(td, sptr);
    if(!selected.presence_index) {
        ASN__DECODE_FAILED;
    }

    /* Fetch the pointer to this member */
    assert(elm->flags == ATF_OPEN_TYPE);
    if(elm->flags & ATF_POINTER) {
        memb_ptr2 = (void **)((char *)sptr + elm->memb_offset);
    } else {
        memb_ptr = (char *)sptr + elm->memb_offset;
        memb_ptr2 = &memb_ptr;
    }
    if(*memb_ptr2 != NULL) {
        /* Make sure we reset the structure first before encoding */
        if(CHOICE_variant_set_presence(elm->type, *memb_ptr2, 0)
           != 0) {
            ASN__DECODE_FAILED;
        }
    }

    void *inner_value =
        (char *)*memb_ptr2
        + elm->type->elements[selected.presence_index - 1].memb_offset;

    rv = uper_open_type_get(opt_codec_ctx, selected.type_descriptor, NULL,
                            &inner_value, pd);
    switch(rv.code) {
    case RC_OK:
        if(CHOICE_variant_set_presence(elm->type, *memb_ptr2,
                                       selected.presence_index)
           == 0) {
            break;
        } else {
            rv.code = RC_FAIL;
        }
        /* Fall through */
    case RC_WMORE:
    case RC_FAIL:
        if(*memb_ptr2) {
            asn_CHOICE_specifics_t *specs = selected.type_descriptor->specifics;
            if(elm->flags & ATF_POINTER) {
                ASN_STRUCT_FREE(*selected.type_descriptor, inner_value);
                *memb_ptr2 = NULL;
            } else {
                ASN_STRUCT_FREE_CONTENTS_ONLY(*selected.type_descriptor,
                                              inner_value);
                memset(*memb_ptr2, 0, specs->struct_size);
            }
        }
    }
    return rv;
}

asn_dec_rval_t
OPEN_TYPE_oer_get(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
                  void *sptr, asn_TYPE_member_t *elm, const void *ptr,
                  size_t size) {
    asn_type_selector_result_t selected;
    void *memb_ptr;   /* Pointer to the member */
    void **memb_ptr2; /* Pointer to that pointer */
    asn_dec_rval_t rv;
    size_t ot_ret;

    if(!(elm->flags & ATF_OPEN_TYPE) || !elm->type_selector) {
        ASN__DECODE_FAILED;
    }

    selected = elm->type_selector(td, sptr);
    if(!selected.presence_index) {
        ASN__DECODE_FAILED;
    }

    /* Fetch the pointer to this member */
    if(elm->flags & ATF_POINTER) {
        memb_ptr2 = (void **)((char *)sptr + elm->memb_offset);
    } else {
        memb_ptr = (char *)sptr + elm->memb_offset;
        memb_ptr2 = &memb_ptr;
    }
    if(*memb_ptr2 != NULL) {
        /* Make sure we reset the structure first before encoding */
        if(CHOICE_variant_set_presence(selected.type_descriptor, *memb_ptr2, 0)
           != 0) {
            ASN__DECODE_FAILED;
        }
    }

    ot_ret = oer_open_type_get(opt_codec_ctx, selected.type_descriptor, NULL,
                               memb_ptr2, ptr, size);
    switch(ot_ret) {
    default:
        if(CHOICE_variant_set_presence(selected.type_descriptor, *memb_ptr2,
                                       selected.presence_index)
           == 0) {
            rv.code = RC_OK;
            rv.consumed = ot_ret;
            return rv;
        } else {
            /* Oh, now a full-blown failure failure */
        }
        /* Fall through */
    case -1:
        rv.code = RC_FAIL;
        rv.consumed = 0;
        break;
    case 0:
        rv.code = RC_WMORE;
        rv.consumed = 0;
        break;
    }

    if(*memb_ptr2) {
        asn_CHOICE_specifics_t *specs = selected.type_descriptor->specifics;
        if(elm->flags & ATF_POINTER) {
            ASN_STRUCT_FREE(*selected.type_descriptor, *memb_ptr2);
            *memb_ptr2 = NULL;
        } else {
            ASN_STRUCT_FREE_CONTENTS_ONLY(*selected.type_descriptor,
                                          *memb_ptr2);
            memset(*memb_ptr2, 0, specs->struct_size);
        }
    }
    return rv;
}
