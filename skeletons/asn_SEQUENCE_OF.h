/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_SEQUENCE_OF_H
#define	ASN_SEQUENCE_OF_H

#include <asn_SET_OF.h>

/*
 * SEQUENCE OF is the same as SET OF with a tiny difference:
 * the delete operation preserves the initial order of elements
 * and thus MAY operate in non-constant time.
 */
#define	A_SEQUENCE_OF(type)	A_SET_OF(type)

#define	ASN_SEQUENCE_ADD(headptr, ptr)		\
	asn_sequence_add((headptr), (ptr))

/***********************************************
 * Implementation of the SEQUENCE OF structure.
 */

#define	asn_sequence_add	asn_set_add
#define	asn_sequence_empty	asn_set_empty

/*
 * Delete the element from the set by its number (base 0).
 * This is NOT a constant-time operation.
 * The order of elements is preserved.
 * If _do_free is given AND the (*free) is initialized, the element
 * will be freed using the custom (*free) function as well.
 */
void asn_sequence_del(void *asn_sequence_of_x, int number, int _do_free);

#endif	/* ASN_SEQUENCE_OF_H */
