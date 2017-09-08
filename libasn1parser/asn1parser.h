/*
 * This is a parser of the ASN.1 grammar.
 */
#ifndef	ASN1PARSER_H
#define	ASN1PARSER_H

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif	/* HAVE_CONFIG_H */

#include "asn1_ref.h"
#include "asn1_buffer.h"
#include "asn1_namespace.h"

#include "asn1p_integer.h"
#include "asn1p_list.h"
#include "asn1p_oid.h"		/* Object identifiers (OIDs) */
#include "asn1p_module.h"	/* ASN.1 definition module */
#include "asn1p_value.h"	/* Value definition */
#include "asn1p_param.h"	/* Parameterization */
#include "asn1p_constr.h"	/* Type Constraints */
#include "asn1p_xports.h"	/* IMports/EXports */
#include "asn1p_class.h"	/* CLASS-related stuff */
#include "asn1p_expr.h"		/* A single ASN.1 expression */

/*
 * Parser flags.
 */
enum asn1p_flags {
    A1P_NOFLAGS,
    /*
     * Enable verbose debugging output from lexer and parser.
     */
    A1P_DEBUG_LEXER = 0x01,
    A1P_DEBUG_PARSER = 0x02,
    /*
     * Unlock internal helper value types.
     */
    A1P_EXTENDED_VALUES = 0x04
};

/*
 * Perform low-level parsing of ASN.1 module[s]
 * and return a list of module trees.
 */
asn1p_t	*asn1p_parse_file(const char *filename,
	enum asn1p_flags);
asn1p_t	*asn1p_parse_buffer(const char *buffer, int size /* = -1 */,
	const char *debug_filename, int initial_lineno,
	enum asn1p_flags);

extern const char *asn1p_parse_debug_filename;

int asn1p_lex_destroy();

#endif	/* ASN1PARSER_H */
