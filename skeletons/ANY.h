/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef ASN_TYPE_ANY_H
#define ASN_TYPE_ANY_H

#include <constr_TYPE.h>
#include <OCTET_STRING.h>	/* Implemented via OCTET SRING type */

typedef struct ANY {
	uint8_t *buf;	/* BER-encoded ANY contents */
	int size;	/* Size of the above buffer */

	ber_dec_ctx_t _ber_dec_ctx;	/* Parsing across buffer boundaries */
} ANY_t;

extern asn1_TYPE_descriptor_t asn1_DEF_ANY;

ber_type_decoder_f ANY_decode_ber;
der_type_encoder_f ANY_encode_der;
asn_struct_print_f ANY_print;
asn_struct_free_f ANY_free;

/******************************
 * Handy conversion routines. *
 ******************************/

#define	ANY_fromBuf(s, buf, size)	OCTET_STRING_fromBuf((s), (buf), (size))
#define	ANY_new_fromBuf(buf, size)	OCTET_STRING_new_fromBuf((buf), (size))

#endif	/* ASN_TYPE_ANY_H */
