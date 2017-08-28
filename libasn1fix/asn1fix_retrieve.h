/*
 * Miscellaneous functions necessary for several other modules.
 */
#ifndef	ASN1FIX_RETRIEVE_H
#define	ASN1FIX_RETRIEVE_H

/*
 * Simple search for the label in the descendants of the given node.
 * ERRORS:
 * NULL/ESRCH
 */
asn1p_expr_t *asn1f_lookup_child(asn1p_expr_t *tc, const char *name);

/*
 * Return a module which contain a specified name, as stated in appropriate
 * IMPORTS section of the current module (arg->mod).
 *
 * RETURN VALUES:
 * NULL/ESRCH:	The name was not found in IMPORTS section.
 * NULL/EPERM:	The name was not found in EXPORTS section of the source module.
 * Also, NULL with errno values defined by asn1f_lookup_module().
 */
asn1p_module_t *asn1f_lookup_in_imports(arg_t *arg, asn1p_module_t *mod, const char *name);

/*
 * Return a module by its name or optional OID.
 *
 * RETURN VALUES:
 * NULL/ENOENT:	No module was found by the specified name and oid
 * NULL/ETOOMANYREFS:	Several modules are matching the specified name and oid
 */
asn1p_module_t *asn1f_lookup_module(arg_t *arg,
		const char *module_name,
		const asn1p_oid_t *module_oid);

/*
 * Return the reference to a destination of the given reference,
 * symbol lookup. Not a recursive function.
 */
asn1p_expr_t *asn1f_lookup_symbol(arg_t *arg, asn1p_expr_t *rhs_pspecs,
                                  const asn1p_ref_t *ref);

/*
 * Recursively find the original type for the given expression.
 * i.e.:
 * If the original specification defines
 * 	v Type1 ::= 5
 * 	Type1 ::= Type2 (1..5)
 * 	Type3 ::= Type4 (2..7)
 * 	Type4 ::= INTEGER (1..10)
 * Then this function, given the the first expression as an argument,
 * would return an expression for Type4.
 * WARNING: No attempts are made to honor constraints at this moment.
 */
asn1p_expr_t *asn1f_find_terminal_type(arg_t *arg, asn1p_expr_t *tc);

/*
 * Recursively find the original value for the given expression.
 * i.e.:
 * If the original specification defines
 * 	v Type1 ::= value
 * 	value Type2 ::= value2
 * 	value2 Type3 ::= 3
 * Then this function will return the expression for value2 if given
 * the v as an argment.
 */
asn1p_expr_t *asn1f_find_terminal_value(arg_t *arg, asn1p_expr_t *tc);

/*
 * Recursively find the original type with constraint for the given
 * expression.
 */
asn1p_expr_t *asn1f_find_ancestor_type_with_PER_constraint(arg_t *arg, asn1p_expr_t *tc);


#endif	/* ASN1FIX_RETRIEVE_H */
