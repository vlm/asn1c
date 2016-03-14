/*
 * Miscellaneous functions necessary for several other modules.
 */
#ifndef	ASN1FIX_MISC_H
#define	ASN1FIX_MISC_H

/*
 * Recursively invoke a given function over the given expr and all its
 * children.
 */
int asn1f_recurse_expr(arg_t *arg, int (*f)(arg_t *arg));

/*
 * Check that every child of a given expr has unique identifier.
 */
int asn1f_check_unique_expr(arg_t *arg);

/*
 * Check that every preceeding child of the given expr is not
 * having the name of the given one.
 * If opt_compare == NULL, the default comparison of the argument's
 * names (identifiers) will be performed.
 */
int asn1f_check_unique_expr_child(arg_t *arg, asn1p_expr_t *child,
		int (*opt_compare)(asn1p_expr_t *a, asn1p_expr_t *b),
		const char *opt_property_name);

/*
 * Return number of children.
 */
int asn1f_count_children(asn1p_expr_t *parent);

/*
 * Check if type is explicitly known.
 */
int asn1f_check_known_external_type(const char *);

#endif	/* ASN1FIX_MISC_H */
