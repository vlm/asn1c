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
} mder_octet_str_types;

typedef uint16_t mder_octet_str;

/*
 * Pre-computed MDER Subtype constraint info.
 */
typedef void* asn_mder_contraints_t;

#define CHECK_UINT16(_len) do	{				\
	if (((_len) < 0) || ((_len) > 65535))			\
		goto cb_failed;					\
} while (0)

#ifdef	WORDS_BIGENDIAN		/* Opportunistic optimization */
#define MDER_OUTPUT_INT_U16_LENGTH(_len) do	{		\
	CHECK_UINT16(_len);					\
        if (cb) {						\
		uint16_t aux = (uint16_t)(_len);		\
		_ASN_CALLBACK((uint8_t *)&aux, 2);		\
        }							\
} while (0)
#else	/* Works even if WORDS_BIGENDIAN is not set where should've been */
#define MDER_OUTPUT_INT_U16_LENGTH(_len) do	{		\
	CHECK_UINT16(_len);					\
	if (cb) {						\
		uint8_t lbuf[2]; /* length for variable O-S */	\
		lbuf[0] = ((_len) >> 8) & 0xff;			\
		lbuf[1] = (_len) & 0xff;			\
		_ASN_CALLBACK(lbuf, 2);				\
        }							\
} while (0)
#endif

#define MDER_INPUT_INT_U16(_int, _buf) do {		\
	_int = 0;					\
	_int = ((uint8_t *)_buf)[0];			\
	_int = (_int << 8) | ((uint8_t *)_buf)[1];	\
}while (0)

#ifdef __cplusplus
}
#endif

#endif	/* _MDER_SUPPORT_H_ */
