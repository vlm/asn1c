/*
 * This is the public interface for the processor (fixer) of the ASN.1 tree
 * produced by the libasn1parser.
 */
#ifndef	ASN1FIX_H
#define	ASN1FIX_H

#include <asn1parser.h>

/*
 * Operation flags for the function below.
 */
enum asn1f_flags {
	A1F_NOFLAGS,
	A1F_DEBUG			= 0x01,	/* Print debugging output */
	A1F_EXTENDED_SizeConstraint	= 0x02,	/* Enable constraint gen code */
};

/*
 * Perform a set of semantics checks, transformations and small fixes
 * on the given tree.
 * RETURN VALUES:
 * 	-1:	Some fatal problems were encountered.
 *	 0:	No inconsistencies were found.
 *	 1:	Some warnings were issued, but no fatal problems encountered.
 */
int asn1f_process(asn1p_t *_asn,
	enum asn1f_flags,
	void (*error_log_callback)(int _severity, const char *fmt, ...));


/*
 * Explicitly mark type as known.
 */
int asn1f_make_known_external_type(const char *);

#endif	/* ASN1FIX_H */
