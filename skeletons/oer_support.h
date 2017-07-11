/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are oermitted subject to BSD license.
 */
#ifndef	_OER_SUPPORT_H_
#define	_OER_SUPPORT_H_

#include <asn_system.h>		/* Platform-specific types */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pre-computed OER constraints.
 */
typedef const struct asn_oer_constraint_s {
	enum asn_oer_constraint_flags {
		AOC_HAS_LOWER_BOUND = 0x01,
		AOC_HAS_UPPER_BOUND = 0x02
	} flags;
	intmax_t lower_bound;
	intmax_t upper_bound;
} asn_oer_constraint_t;
typedef const struct asn_oer_constraints_s {
    struct asn_oer_constraint_s value;
    struct asn_oer_constraint_s size;
} asn_oer_constraints_t;


/*
 * Fetch the length determinant (X.696 08/2015, #8.6) into *len_r.
 * RETURN VALUES:
 *       0:     More data expected than bufptr contains.
 *      -1:     Fatal error deciphering length.
 *      >0:     Number of bytes used from bufptr.
 */
ssize_t oer_fetch_length(const void *bufptr, size_t size, size_t *len_r);

/*
 * Serialize OER length. Returns the number of bytes serialized
 * or -1 if a given callback returned with negative result.
 */
ssize_t oer_serialize_length(size_t length, asn_app_consume_bytes_f *cb, void *app_key);


#ifdef __cplusplus
}
#endif

#endif	/* _OER_SUPPORT_H_ */
