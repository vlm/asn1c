/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * This type differs from the standard INTEGER in that it is modelled using
 * the fixed machine type (long, int, short), so it can hold only values of
 * limited length. There is no type (i.e., NativeInteger_t, any integer type
 * will do).
 * This type may be used when integer range is limited by subtype constraints.
 */
#ifndef	_NativeInteger_H_
#define	_NativeInteger_H_

#include <constr_TYPE.h>

extern asn1_TYPE_descriptor_t asn1_DEF_NativeInteger;

ber_type_decoder_f NativeInteger_decode_ber;
der_type_encoder_f NativeInteger_encode_der;
asn_struct_print_f NativeInteger_print;
asn_struct_free_f  NativeInteger_free;

#endif	/* _NativeInteger_H_ */
