/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_CONSTR_SEQUENCE_OF_H_
#define	_CONSTR_SEQUENCE_OF_H_

#include <asn_application.h>
#include <constr_SET_OF.h>		/* Implemented using SET OF */

/*
 * A set specialized functions dealing with the SEQUENCE OF type.
 * Implemented using SET OF.
 */
#define	SEQUENCE_OF_free	SET_OF_free
#define	SEQUENCE_OF_print	SET_OF_print
#define	SEQUENCE_OF_constraint	SET_OF_constraint
#define	SEQUENCE_OF_decode_ber	SET_OF_decode_ber
der_type_encoder_f SEQUENCE_OF_encode_der;
xer_type_encoder_f SEQUENCE_OF_encode_xer;

#endif	/* _CONSTR_SET_OF_H_ */
