/*
 * Copyright (c) 2005 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_PER_SUPPORT_H_
#define	_PER_SUPPORT_H_

#include <asn_system.h>		/* Platform-specific types */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This structure describes a position inside an incoming PER bit stream.
 */
typedef struct asn_per_data_s {
 const uint8_t *buffer;	/* Pointer to the octet stream */
        size_t  nboff;	/* Bit offset to the meaningful bit */
        size_t  nbits;	/* Number of bits in the stream */
} asn_per_data_t;

/*
 * This structure supports forming PER output.
 */
typedef struct asn_per_outp_s {
	uint8_t *buffer;	/* Pointer into the (tmpspace) */
	size_t nboff;		/* Bit offset to the meaningful bit */
	size_t nbits;		/* Number of bits left in (tmpspace) */
	uint8_t tmpspace[32];	/* Preliminary storage to hold data */
	int (*outper)(const void *data, size_t size, void *op_key);
	void *op_key;
} asn_per_outp_t;

/*
 * Extract a small number of bits (<= 31) from the specified PER data pointer.
 * This function returns -1 if the specified number of bits could not be
 * extracted due to EOD or other conditions.
 */
int32_t per_get_few_bits(asn_per_data_t *per_data, int get_nbits);

/* Output a small number of bits (<= 31) */
int per_put_few_bits(asn_per_outp_t *per_data, uint32_t bits, int obits);

/*
 * Extract a large number of bits from the specified PER data pointer.
 * This function returns -1 if the specified number of bits could not be
 * extracted due to EOD or other conditions.
 */
int per_get_many_bits(asn_per_data_t *pd, uint8_t *dst, int right_align,
			int get_nbits);

/* Output a large number of bits */
int per_put_many_bits(asn_per_outp_t *po, const uint8_t *src, int put_nbits);

/*
 * Get the length "n" from the Unaligned PER stream.
 */
ssize_t uper_get_length(asn_per_data_t *pd,
			int effective_bound_bits,
			int *repeat);

/*
 * Put the length "n" to the Unaligned PER stream.
 * This function returns the number of units which may be flushed
 * in the next units saving iteration.
 */
ssize_t uper_put_length(asn_per_outp_t *po, size_t whole_length);

/*
 * Get the normally small non-negative whole number.
 */
ssize_t uper_get_nsnnwn(asn_per_data_t *pd);

/*
 * Put the normally small non-negative whole number.
 */
int uper_put_nsnnwn(asn_per_outp_t *po, int n);

#ifdef __cplusplus
}
#endif

#endif	/* _PER_SUPPORT_H_ */
