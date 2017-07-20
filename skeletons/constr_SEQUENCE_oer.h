/*-
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	CONSTR_SEQUENCE_OER_H
#define	CONSTR_SEQUENCE_OER_H
#ifdef __cplusplus
extern "C" {
#endif

#include <asn_application.h>
#include <asn_codecs.h>

oer_type_decoder_f SEQUENCE_decode_oer;
oer_type_encoder_f SEQUENCE_encode_oer;

#ifdef __cplusplus
}
#endif
#endif	/* CONSTR_SEQUENCE_OER_H */
