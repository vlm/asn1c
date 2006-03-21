/*
 * This header exports fixer procedures that are common enough to be used
 * in other modules.
 */
#ifndef	_ASN1FIX_EXPORT_H_
#define	_ASN1FIX_EXPORT_H_

#include "asn1fix_tags.h"

/*
 * Create a human-readable representation of a reference and value.
 */
char const *asn1f_printable_reference(asn1p_ref_t *ref);
char const *asn1f_printable_value(asn1p_value_t *value);

/*
 *  Exportable version of an asn1f_lookup_symbol().
 */
asn1p_expr_t *asn1f_lookup_symbol_ex(
		asn1p_t *asn,
		asn1p_expr_t *expr,
		asn1p_ref_t *ref);

/*
 *  Exportable version of an asn1f_class_access().
 */
asn1p_expr_t *asn1f_class_access_ex(asn1p_t *asn, asn1p_module_t *mod,
	asn1p_expr_t *expr, asn1p_expr_t *rhs_rspecs, asn1p_ref_t *);

/*
 * Exportable version of asn1f_find_terminal_type().
 */
asn1p_expr_t *asn1f_find_terminal_type_ex(asn1p_t *asn, asn1p_expr_t *tc);

/*
 * Exportable version of asn1f_fix_dereference_values();
 */
int asn1f_fix_dereference_values_ex(asn1p_t *asn, asn1p_module_t *mod,
	asn1p_expr_t *expr);

#endif	/* _ASN1FIX_EXPORT_H_ */
