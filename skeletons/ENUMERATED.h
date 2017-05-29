/*-
 * Copyright (c) 2003, 2005 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_ENUMERATED_H_
#define	_ENUMERATED_H_

#include <INTEGER.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef INTEGER_t ENUMERATED_t;		/* Implemented via INTEGER */

extern asn_TYPE_descriptor_t asn_DEF_ENUMERATED;
extern asn_TYPE_operation_t asn_OP_ENUMERATED;

per_type_decoder_f ENUMERATED_decode_uper;
per_type_encoder_f ENUMERATED_encode_uper;

#define ENUMERATED_constraint  asn_generic_no_constraint

#ifdef __cplusplus
}
#endif

#endif	/* _ENUMERATED_H_ */
