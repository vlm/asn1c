#ifndef	_ASN1_COMPILER_MISC_H_
#define	_ASN1_COMPILER_MISC_H_

/*
 * Make the target language identifier out of one or more names.
 * The function will concatenate the names and replace unsafe characters
 * with safe ones.
 */
char *asn1c_make_identifier(int unsafe_only_spaces, char *arg1, ...);

/*
 * Return the type name of the specified expression.
 */
enum tnfmt {
	TNF_UNMODIFIED,		/* Return unmodified type name */
	TNF_INCLUDE,		/* Format for #include <> */
	TNF_CTYPE,		/* Format as normal C-ish type (append "_t") */
	TNF_SAFE,		/* Replace unsafe characters with _ */
	TNF_RSAFE,		/* Recursion-safe C type format */
};
char *asn1c_type_name(arg_t *arg, asn1p_expr_t *expr, enum tnfmt _format);

#endif	/* _ASN1_COMPILER_MISC_H_ */
