/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_ASN1_CONSTRAINTS_VALIDATOR_H_
#define	_ASN1_CONSTRAINTS_VALIDATOR_H_

#include <asn_types.h>	/* System-dependent types */

struct asn1_TYPE_descriptor_s;		/* Forward declaration */

/*
 * Validate the structure according to the ASN.1 constraints.
 * If errbuf and errlen are given, they shall be pointing to the appropriate
 * buffer space and its length before calling this function. Alternatively,
 * they could be passed as NULL's. If constraints validation fails,
 * errlen will contain the actual number of bytes taken from the errbuf
 * to encode an error message (properly 0-terminated).
 */
int
asn_check_constraints(struct asn1_TYPE_descriptor_s *type_descriptor,
	const void *struct_ptr,	/* Target language's structure */
	char *errbuf,		/* Returned error description */
	size_t *errlen		/* Length of the error description */
	);

/*
 * Generic type for constraint checking callback,
 * associated with every type descriptor.
 */
typedef int (asn_constr_check_f)(
	struct asn1_TYPE_descriptor_s *type_descriptor,
	const void *struct_ptr,
	asn_app_consume_bytes_f *optional_app_errlog,	/* Log the error */
	void *optional_app_key		/* Opaque key passed to app_errlog */
	);

/*******************************
 * INTERNALLY USEFUL FUNCTIONS *
 *******************************/

asn_constr_check_f asn_generic_no_constraint;	/* No constraint whatsoever */
asn_constr_check_f asn_generic_unknown_constraint; /* Not fully supported */

/*
 * Invoke the callback with a complete error message.
 */
#ifdef	__GNUC__
#define	_ASN_ERRLOG(app_errlog, app_key, fmt, args...)	do {	\
	if(app_errlog)						\
		_asn_i_log_error(app_errlog,			\
			app_key, fmt, ##args);			\
} while(0);
#else	/* Preprocessor does not support variable args macros */
#define	_ASN_ERRLOG	if(app_errlog) _asn_i_log_error
#endif

extern void _asn_i_log_error(asn_app_consume_bytes_f *, void *key,
	const char *fmt, ...) __attribute__ ((format(printf, 3, 4)));

#endif	/* _ASN1_CONSTRAINTS_VALIDATOR_H_ */
