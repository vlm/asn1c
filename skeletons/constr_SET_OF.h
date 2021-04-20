/*-
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	CONSTR_SET_OF_H
#define	CONSTR_SET_OF_H

#include <asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct asn_SET_OF_specifics_s {
    /*
     * Target structure description.
     */
    unsigned struct_size;       /* Size of the target structure. */
    unsigned ctx_offset;        /* Offset of the asn_struct_ctx_t member */

    /* XER-specific stuff */
    int as_XMLValueList; /* The member type must be encoded like this */
} asn_SET_OF_specifics_t;

/*
 * A set specialized functions dealing with the SET OF type.
 */
asn_struct_free_f SET_OF_free;
asn_struct_print_f SET_OF_print;
asn_struct_compare_f SET_OF_compare;
asn_constr_check_f SET_OF_constraint;
ber_type_decoder_f SET_OF_decode_ber;
der_type_encoder_f SET_OF_encode_der;
xer_type_decoder_f SET_OF_decode_xer;
xer_type_encoder_f SET_OF_encode_xer;
oer_type_decoder_f SET_OF_decode_oer;
oer_type_encoder_f SET_OF_encode_oer;
per_type_decoder_f SET_OF_decode_uper;
per_type_encoder_f SET_OF_encode_uper;
per_type_decoder_f SET_OF_decode_aper;
per_type_encoder_f SET_OF_encode_aper;
asn_random_fill_f  SET_OF_random_fill;
extern asn_TYPE_operation_t asn_OP_SET_OF;

#ifdef __cplusplus
}
#endif

#endif	/* CONSTR_SET_OF_H */
