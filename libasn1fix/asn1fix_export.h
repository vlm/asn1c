/*
 * This header exports fixer procedures that are common enough to be used
 * in other modules.
 */
#ifndef	_ASN1FIX_EXPORT_H_
#define	_ASN1FIX_EXPORT_H_

#include <asn1fix_tags.h>

/*
 *  Exportable version of an asn1f_lookup_symbol().
 */
asn1p_expr_t *asn1f_lookup_symbol_ex(
		asn1p_t *asn,
		asn1p_module_t **module_rw,
		asn1p_expr_t *expr,
		asn1p_ref_t *ref);

/*
 *  Exportable version of an asn1f_class_access().
 */
asn1p_expr_t *asn1f_class_access_ex(asn1p_t *asn, asn1p_module_t *mod,
	asn1p_expr_t *expr, asn1p_ref_t *, asn1p_module_t **mod_r);

/*
 * Exportable version of asn1f_find_terminal_type().
 */
asn1p_expr_t *asn1f_find_terminal_type_ex(asn1p_t *asn, asn1p_module_t *mod,
	asn1p_expr_t *tc, asn1p_module_t **opt_module_r);

#endif	/* _ASN1FIX_EXPORT_H_ */

