/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef ASN_DISABLE_OER_SUPPORT

#include <asn_internal.h>
#include <constr_SEQUENCE.h>
#include <errno.h>

/*
 * This macro "eats" the part of the buffer which is definitely "consumed",
 * i.e. was correctly converted into local representation or rightfully skipped.
 */
#undef  ADVANCE
#define ADVANCE(num_bytes)                   \
    do {                                     \
        size_t num = num_bytes;              \
        ptr = ((const char *)ptr) + num;     \
        size -= num;                         \
        consumed_myself += num;              \
    } while(0)

/*
 * Switch to the next phase of parsing.
 */
#undef  NEXT_PHASE
#undef PHASE_OUT
#define NEXT_PHASE(ctx) \
    do {                \
        ctx->phase++;   \
        ctx->step = 0;  \
    } while(0)

/*
 * Check whether we are inside the extensions group.
 */
#define IN_EXTENSION_GROUP(specs, memb_idx)     \
        ( ((memb_idx) > (specs)->ext_after)     \
        &&((memb_idx) < (specs)->ext_before))

/*
 * Return a standardized complex structure.
 */
#undef  RETURN
#define RETURN(_code)   do {                    \
                rval.code = _code;              \
                rval.consumed = consumed_myself;\
                return rval;                    \
        } while(0)

asn_dec_rval_t
SEQUENCE_decode_oer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
                   asn_oer_constraints_t *constraints, void **struct_ptr,
                   const void *ptr, size_t size) {
    asn_SEQUENCE_specifics_t *specs = (asn_SEQUENCE_specifics_t *)td->specifics;
    asn_dec_rval_t rval = {RC_OK, 0};
    void *st = *struct_ptr; /* Target structure */
    asn_struct_ctx_t *ctx; /* Decoder context */
    size_t consumed_myself = 0; /* Consumed bytes from ptr. */


    (void)opt_codec_ctx;
    (void)specs;

    /*
     * Create the target structure if it is not present already.
     */
    if(st == 0) {
        st = *struct_ptr = CALLOC(1, specs->struct_size);
        if(st == 0) {
            RETURN(RC_FAIL);
        }
    }

    /*
     * Restore parsing context.
     */
    ctx = (asn_struct_ctx_t *)((char *)st + specs->ctx_offset);
    if(ctx->ptr == 0) {
        ctx->ptr = CALLOC(1, sizeof(asn_per_data_t));
        if(!ctx->ptr) {
            RETURN(RC_FAIL);
        }
    }

    /*
     * Start to parse where left previously.
     */
    switch(ctx->phase) {
    case 0: {
        /*
         * Fetch preamble.
         */
        asn_per_data_t *preamble = ctx->ptr;
        int has_extensions = (specs->ext_before >= 0);
        size_t preamble_bits = (has_extensions + specs->roms_count);
        size_t preamble_bytes = (preamble_bits >> 3);
        uint8_t *pbytes;

        if(size < preamble_bytes) {
            ASN__DECODE_STARVED;
        }

        pbytes = MALLOC(preamble_bytes + 1);
        if(!pbytes) {
            RETURN(RC_FAIL);
        }
        preamble->buffer = (const void *)pbytes;
        memcpy(pbytes, ptr, preamble_bytes);
        pbytes[preamble_bytes] = '\0';    /* Just in case */
        preamble->nboff = has_extensions;
        preamble->nbits = preamble_bits;
        ADVANCE(preamble_bytes);
    }
        NEXT_PHASE(ctx);
        /* FALL THROUGH */
    case 1: {
        /* Decode components of the extension root */
        asn_per_data_t *preamble = ctx->ptr;
        size_t edx;

        for(edx = (ctx->step >> 1); edx < td->elements_count;
            edx++, ctx->step = (ctx->step & ~1) + 2) {
            asn_TYPE_member_t *elm = &td->elements[edx];
            void **memb_ptr2;   /* Pointer to a pointer to a memmber */

            if(ctx->step & 1) {
                goto microphase2_decode_continues;
            }


            if(IN_EXTENSION_GROUP(specs, edx)) {
                /* Ignore non-root components in PHASE 1 */
                continue;
            }

            if(elm->optional) {
                int32_t present = per_get_few_bits(preamble, 1);
                if(present < 0) {
                    RETURN(RC_FAIL);
                } else if(present == 0) {
                    if(elm->default_value) {
                        if(elm->flags & ATF_POINTER) {
                            /* Member is a pointer to another structure */
                            memb_ptr2 =
                                (void **)((char *)st + elm->memb_offset);
                        } else {
                            void *memb_ptr = (char *)st + elm->memb_offset;
                            memb_ptr2 = &memb_ptr;
                        }
                        /* Fill-in DEFAULT */
                        if(elm->default_value(1, memb_ptr2)) {
                            RETURN(RC_FAIL);
                        }
                    }
                    /* The member is not present. */
                    continue;
                }
                /* Present OPTIONAL or DEFAULT component. */
            }

            /*
             * MICROPHASE 2: Invoke the member-specific decoder.
             */
            ctx->step |= 1; /* Confirm entering next microphase */
        microphase2_decode_continues:
            if(elm->flags & ATF_POINTER) {
                /* Member is a pointer to another structure */
                memb_ptr2 = (void **)((char *)st + elm->memb_offset);
            } else {
                void *memb_ptr = (char *)st + elm->memb_offset;
                memb_ptr2 = &memb_ptr;
            }

            rval = elm->type->oer_decoder(opt_codec_ctx, elm->type,
                                          elm->oer_constraints, memb_ptr2, ptr,
                                          size);
            switch(rval.code) {
            case RC_OK:
                ADVANCE(rval.consumed);
                break;
            case RC_WMORE:
                ADVANCE(rval.consumed);
                RETURN(RC_WMORE);
            case RC_FAIL:
                RETURN(RC_FAIL);
            }
        } /* for(all root members) */

    }
        NEXT_PHASE(ctx);
        /* FALL THROUGH */
    case 2: {
        /* Cleanup preamble. */
        asn_per_data_t *preamble = ctx->ptr;
        asn_per_data_t *extadds;
        int has_extensions = (specs->ext_before >= 0);
        int extensions_present =
            has_extensions && (((const uint8_t *)preamble->buffer)[0] & 0x80);
        uint8_t unused_bits;
        size_t len = 0;
        ssize_t len_len;
        uint8_t *ebytes;

        union {
            const uint8_t *cptr;
            uint8_t *uptr;
        } unconst;
        unconst.cptr = preamble->buffer;
        FREEMEM(unconst.uptr);
        preamble->buffer = 0;

        if(!extensions_present) {
            ctx->phase = 10;
            RETURN(RC_OK);
        }

        /*
         * X.696 (08/2015) #16.1 (c), #16.4
         * Read in the extension addition presence bitmap.
         */

        len_len = oer_fetch_length(ptr, size, &len);
        if(len_len > 0) {
            ADVANCE(len_len);
        } if(len_len < 0) {
            RETURN(RC_FAIL);
        } else {
            RETURN(RC_WMORE);
        }

        if(len == 0) {
            /* 16.4.1-2 */
            RETURN(RC_FAIL);
        } else if(len > size) {
            RETURN(RC_WMORE);
        }

        /* Account for unused bits */
        unused_bits = 0x7 & *(const uint8_t *)ptr;
        ADVANCE(1);
        len--;
        if(unused_bits && len == 0) {
            RETURN(RC_FAIL);
        }

        /* Get the extensions map */
        ebytes = MALLOC(len + 1);
        if(!ebytes) {
            RETURN(RC_FAIL);
        }
        memcpy(ebytes, ptr, len);
        ebytes[len] = '\0';

        extadds = preamble;
        memset(extadds, 0, sizeof(*extadds));
        extadds->buffer = ebytes;
        extadds->nboff = 0;
        extadds->nbits = 8 * len - unused_bits;

        ADVANCE(len);
    }
        NEXT_PHASE(ctx);
        ctx->step = (specs->ext_after + 1);
        /* Fall through */
    case 3:
        for(; ctx->step < specs->ext_before; ctx->step++) {
            asn_per_data_t *extadds = ctx->ptr;
            size_t edx = ctx->step;
            asn_TYPE_member_t *elm = &td->elements[edx];
            void **memb_ptr2;

            if(elm->flags & ATF_POINTER) {
                /* Member is a pointer to another structure */
                memb_ptr2 = (void **)((char *)st + elm->memb_offset);
            } else {
                void *memb_ptr = (char *)st + elm->memb_offset;
                memb_ptr2 = &memb_ptr;
                assert(elm->flags & ATF_POINTER); /* Extensions are indirect */
            }

            switch(per_get_few_bits(extadds, 1)) {
            case -1:
                /*
                 * Not every one of our extensions is known to the remote side.
                 * Continue filling in their defaults though.
                 */
                /* Fall through */
            case 0:
                /* Fill-in DEFAULT */
                if(elm->default_value && elm->default_value(1, memb_ptr2)) {
                    RETURN(RC_FAIL);
                }
                continue;
            case 1: {
                /* Read OER open type */
                ssize_t ot_size = oer_open_type_get(opt_codec_ctx, elm->type,
                                                    elm->oer_constraints,
                                                    memb_ptr2, ptr, size);
                if(ot_size > 0) {
                    ADVANCE(ot_size);
                } else if(ot_size < 0) {
                    RETURN(RC_FAIL);
                } else {
                    /* Roll back open type parsing */
                    per_get_undo(extadds, 1);
                    ASN_STRUCT_FREE(*elm->type, *memb_ptr2);
                    *memb_ptr2 = NULL;
                    RETURN(RC_WMORE);
                }
                break;
            }
            default:
                RETURN(RC_FAIL);
            }
        }

        NEXT_PHASE(ctx);
        /* Fall through */
    case 4:
        /* Read in the rest of Open Types while ignoring them */
        for(;;) {
            asn_per_data_t *extadds = ctx->ptr;
            switch(per_get_few_bits(extadds, 1)) {
            case 0:
                continue;
            case 1: {
                ssize_t skipped = oer_open_type_skip(ptr, size);
                if(skipped > 0) {
                    ADVANCE(skipped);
                } else if(skipped < 0) {
                    RETURN(RC_FAIL);
                } else {
                    per_get_undo(extadds, 1);
                    RETURN(RC_WMORE);
                }
                continue;
            }
            case -1:
                /* No more Open Type encoded components */
                break;
            default:
                RETURN(RC_FAIL);
            }
            break;
        }
    }

    return rval;
}

/*
 * Encode as Canonical OER.
 */
asn_enc_rval_t
SEQUENCE_encode_oer(asn_TYPE_descriptor_t *td,
                   asn_oer_constraints_t *constraints, void *sptr,
                   asn_app_consume_bytes_f *cb, void *app_key) {
    asn_enc_rval_t er;
    const uint8_t *buf;
    const uint8_t *end;
    size_t useful_bytes;
    size_t req_bytes = 0;
    int encode_as_unsigned;
    int sign = 0;

    er.encoded = -1;

    return er;
}

#endif  /* ASN_DISABLE_OER_SUPPORT */
