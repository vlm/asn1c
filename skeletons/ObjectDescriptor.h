/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_ObjectDescriptor_H_
#define	_ObjectDescriptor_H_

#include <GraphicString.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef GraphicString_t ObjectDescriptor_t;  /* Implemented via GraphicString */

extern asn_TYPE_descriptor_t asn_DEF_ObjectDescriptor;
extern asn_TYPE_operation_t asn_OP_ObjectDescriptor;

#define ObjectDescriptor_constraint   asn_generic_unknown_constraint

#ifdef __cplusplus
}
#endif

#endif	/* _ObjectDescriptor_H_ */
