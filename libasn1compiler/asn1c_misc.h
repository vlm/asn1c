#ifndef	_ASN1_COMPILER_MISC_H_
#define	_ASN1_COMPILER_MISC_H_

/*
 * Make the target language identifier out of one or more names.
 * The function will concatenate the names and replace unsafe characters
 * with safe ones.
 */
enum ami_flags_e {
  AMI_MASK_ONLY_SPACES	= 1,	/* Mask only spaces, everything else's safe */
  AMI_CHECK_RESERVED	= 2,	/* Check against reserved keywords */
  AMI_NODELIMITER       = 4,	/* Do not put delimiter, just concatenate */
};
char *asn1c_make_identifier(enum ami_flags_e, asn1p_expr_t *expr, ...);

/*
 * Return the type name of the specified expression.
 */
enum tnfmt {
	TNF_UNMODIFIED	= 0x10,	/* Return unmodified type name */
	TNF_INCLUDE	= 0x20,	/* Format for #include <> */
	TNF_CTYPE	= 0x30,	/* Format as normal C-ish type (append "_t") */
	TNF_SAFE	= 0x40, /* Replace unsafe characters with _ */
	TNF_RSAFE	= 0x50,	/* Recursion-safe C type format */
};
char *asn1c_type_name(arg_t *arg, asn1p_expr_t *expr, enum tnfmt _format);

/*
 * Check whether the specified INTEGER or ENUMERATED type can be represented
 * using the generic 'long' type.
 * Return values:
 * 	FL_NOTFIT:	No, it cannot be represented using long.
 * 	FL_FITSOK:	It can be represented using long.
 * 	FL_FORCED:	Probably can't, but -fnative-types is in force.
 */
enum asn1c_fitslong_e {
	FL_NOTFIT,
	FL_FITSOK,
	FL_FORCED,
};
enum asn1c_fitslong_e asn1c_type_fits_long(arg_t *arg, asn1p_expr_t *expr);

#endif	/* _ASN1_COMPILER_MISC_H_ */
