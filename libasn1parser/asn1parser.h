/*
 * This is a parser of the ASN.1 grammar.
 */
#ifndef	ASN1PARSER_H
#define	ASN1PARSER_H

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif	/* HAVE_CONFIG_H */

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
typedef	intmax_t asn1c_integer_t;
#ifdef	PRIdMAX
#define	PRIdASN	PRIdMAX
#define	PRIuASN	PRIuMAX
#else
#define	PRIdASN	"lld"	/* Or j? */
#define	PRIuASN	"llu"	/* Or j? */
#endif

#include "asn1p_list.h"
#include "asn1p_oid.h"		/* Object identifiers (OIDs) */
#include "asn1p_ref.h"		/* References to custom types */
#include "asn1p_value.h"	/* Value definition */
#include "asn1p_param.h"	/* Parameterization */
#include "asn1p_constr.h"	/* Type Constraints */
#include "asn1p_xports.h"	/* IMports/EXports */
#include "asn1p_module.h"	/* ASN.1 definition module */
#include "asn1p_class.h"	/* CLASS-related stuff */
#include "asn1p_expr.h"		/* A single ASN.1 expression */

/*
 * Parser flags.
 */
enum asn1p_flags {
	A1P_NOFLAGS,
	/*
	 * Enable verbose debugging output from lexer.
	 */
	A1P_LEXER_DEBUG			= 0x0001
};

/*
 * Perform low-level parsing of ASN.1 module[s]
 * and return a list of module trees.
 */
asn1p_t	*asn1p_parse_file(const char *filename,
	enum asn1p_flags);
asn1p_t	*asn1p_parse_buffer(const char *buffer, int size /* = -1 */,
	enum asn1p_flags);

int asn1p_atoi(const char *ptr, asn1c_integer_t *r_value);

#endif	/* ASN1PARSER_H */
