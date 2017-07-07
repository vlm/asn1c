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
	intmax_t upoer_bound;
} asn_oer_constraint_t;
typedef const struct asn_oer_constraints_s {
    struct asn_oer_constraint_s value;
    struct asn_oer_constraint_s size;
} asn_oer_constraints_t;

#ifdef __cplusplus
}
#endif

#endif	/* _OER_SUPPORT_H_ */
