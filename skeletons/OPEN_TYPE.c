/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <OPEN_TYPE.h>
#include <constr_CHOICE.h>
#include <per_opentype.h>
#include <errno.h>

asn_TYPE_operation_t asn_OP_OPEN_TYPE = {
	OPEN_TYPE_free,
	OPEN_TYPE_print,
	OPEN_TYPE_compare,
	OPEN_TYPE_constraint,
	OPEN_TYPE_decode_ber,
	OPEN_TYPE_encode_der,
	OPEN_TYPE_decode_xer,
	OPEN_TYPE_encode_xer,
	0, 0,	/* No OER support, use "-gen-OER" to enable */
	OPEN_TYPE_decode_uper,
	OPEN_TYPE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
};

#ifndef  ASN_DISABLE_PER_SUPPORT

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

#endif  /* ASN_DISABLE_PER_SUPPORT */
