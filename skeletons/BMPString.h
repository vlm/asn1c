/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BMPString_H_
#define	_BMPString_H_

#include <OCTET_STRING.h>

typedef OCTET_STRING_t BMPString_t;  /* Implemented via OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_BMPString;

asn_struct_print_f BMPString_print;	/* Human-readable output */
xer_type_encoder_f BMPString_encode_xer;

#endif	/* _BMPString_H_ */
