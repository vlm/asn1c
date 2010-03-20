/*
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_MDER_SUPPORT_H_
#define	_MDER_SUPPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Size constraints shall be used for all INTEGER data types to define the
 * value range of the integer.
 */
typedef enum {
	INT_INVALID,
	INT_U8,
	INT_I8,
	INT_U16,
	INT_I16,
	INT_U32,
	INT_I32
} mder_restricted_int;

/*
 * Get the number of octets needed to encode/decode an integer type
 */
#define GET_INT_SIZE(_int,_size) do {	\
	switch (_int) {			\
	case INT_U8:			\
	case INT_I8:			\
		_size = 1;		\
		break;			\
	case INT_U16:			\
	case INT_I16:			\
		_size = 2;		\
		break;			\
	case INT_U32:			\
	case INT_I32:			\
		_size = 4;		\
		break;			\
	default:			\
		_size = 0;		\
	}				\
} while (0)

#define GET_INT_UNSIGNED(_int,_unsign) do {	\
	switch (_int) {				\
	case INT_U8:				\
	case INT_U16:				\
	case INT_U32:				\
		_unsign = 1;			\
		break;				\
	case INT_I8:				\
	case INT_I16:				\
	case INT_I32:				\
	default:				\
		_unsign = 0;			\
	}					\
} while (0)

/*
 * Size constraints shall be used for all BIT STRING data types to define the
 * value range of the bit string.
 */
typedef enum {
	BITS_INVALID,
	BITS_8 = 1,
	BITS_16 = 2,
	BITS_32 = 4
} mder_restricted_bit_str;

typedef enum {
	FIXED_OCTET_STRING,
	VARIABLE_OCTET_STRING
} mder_octet_str;

/*
 * Pre-computed MDER Subtype constrint info (if is restricted type).
 */
typedef void* asn_mder_contraints_t;

#ifdef __cplusplus
}
#endif

#endif	/* _MDER_SUPPORT_H_ */
