/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_INTEGER_H_
#define	_INTEGER_H_

#include <constr_TYPE.h>

typedef struct INTEGER {
	uint8_t *buf;	/* Buffer with consecutive INTEGER bits (big-endian) */
	int size;	/* Size of the buffer */
} INTEGER_t;

extern asn1_TYPE_descriptor_t asn1_DEF_INTEGER;

ber_type_decoder_f INTEGER_decode_ber;
der_type_encoder_f INTEGER_encode_der;
asn_struct_print_f INTEGER_print;
asn_struct_free_f INTEGER_free;

/***********************************
 * Some handy conversion routines. *
 ***********************************/

/*
 * Returns 0 if it was possible to convert, -1 otherwise.
 * -1/EINVAL: Mandatory argument missing
 * -1/ERANGE: Value encoded is out of range for long representation
 */
int asn1_INTEGER2long(const INTEGER_t *i, long *l);

#endif	/* _INTEGER_H_ */
