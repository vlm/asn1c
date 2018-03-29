#ifndef	ASN1P_INTEGER_H
#define	ASN1P_INTEGER_H

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif	/* HAVE_CONFIG_H */

#include <asn1_buffer.h>

#ifdef	HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif	/* HAVE_SYS_TYPES_H */
#ifdef	HAVE_INTTYPES_H
#include <inttypes.h>		/* POSIX 1003.1-2001, C99 */
#else	/* HAVE_INTTYPES_H */
#ifdef	HAVE_STDINT_H
#include <stdint.h>		/* SUSv2+ */
#endif	/* HAVE_STDINT_H */
#endif	/* HAVE_INTTYPES_H */

/*
 * Basic integer type used in numerous places.
 * ASN.1 does not define any limits on this number, so it must be sufficiently
 * large to accomodate typical inputs. It does not have to be a dynamically
 * allocated type with potentially unlimited width: consider the width of
 * an integer defined here as one of the "compiler limitations".
 * NOTE: this is NOT a type for ASN.1 "INTEGER" type representation, this
 * type is used by the compiler itself to handle large integer values
 * specified inside ASN.1 grammar.
 */
#ifdef  HAVE_128_BIT_INT
typedef	__int128 asn1c_integer_t;
#else
typedef	intmax_t asn1c_integer_t;
#endif

int asn1p_atoi(const char *ptr, asn1c_integer_t *r_value);
const char *asn1p_itoa(asn1c_integer_t value);   /* Ptr to a static buf */
/*
 * Return values:
 * -1: The value did not fit in the buffer.
 * >0: The length in bytes of the stringified numeric value.
 */
int asn1p_itoa_s(char *buf, size_t size,
                 asn1c_integer_t value); /* Return -1 on error, or length. */

/*
 * Convert asn1c_integer_t into INTEGER_t structure.
 */
abuf *asn1p_integer_as_INTEGER(asn1c_integer_t value);

#endif	/* ASN1P_INTEGER_H */
