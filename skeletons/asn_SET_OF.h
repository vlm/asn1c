/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_SET_OF_H
#define	ASN_SET_OF_H

#define	A_SET_OF(type)					\
	struct {					\
		type **array;				\
		int count;	/* Meaningful size */	\
		int size;	/* Allocated size */	\
		void (*free)(type *);			\
	}

#define	ASN_SET_ADD(headptr, ptr)		\
	asn_set_add((headptr), (ptr))

/*******************************************
 * Implementation of the SET OF structure.
 */

/*
 * Add another structure into the set by its pointer.
 * RETURN VALUES:
 * 0 for success and -1/errno for failure.
 */
int  asn_set_add(void *asn_set_of_x, void *ptr);

/*
 * Delete the element from the set by its number (base 0).
 * This is a constant-time operation. The order of elements before the
 * deleted ones is guaranteed, the order of elements after the deleted
 * one is NOT guaranteed.
 * If _do_free is given AND the (*free) is initialized, the element
 * will be freed using the custom (*free) function as well.
 */
void asn_set_del(void *asn_set_of_x, int number, int _do_free);

/*
 * Empty the contents of the set. Will free the elements, if (*free) is given.
 * Will NOT free the set itself.
 */
void asn_set_empty(void *asn_set_of_x);

#endif	/* ASN_SET_OF_H */
