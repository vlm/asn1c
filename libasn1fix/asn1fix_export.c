#include "asn1fix_internal.h"
#include "asn1fix_export.h"

asn1p_expr_t *
asn1f_lookup_symbol_ex(
		asn1p_t *asn,
		asn1p_module_t **module_rw,
		asn1p_expr_t *expr,
		asn1p_ref_t *ref) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = *module_rw;
	arg.expr = expr;

	return asn1f_lookup_symbol(&arg, ref, module_rw);
}

asn1p_expr_t *
asn1f_class_access_ex(asn1p_t *asn,
		asn1p_module_t *mod,
		asn1p_expr_t *expr,
		asn1p_ref_t *ref,
		asn1p_module_t **mod_r) {
	static arg_t arg;

	arg.asn = asn;
	arg.mod = mod;
	arg.expr = expr;

	return asn1f_class_access(&arg, ref, mod_r);
}

asn1p_expr_t *
asn1f_find_terminal_type_ex(asn1p_t *asn,
		asn1p_module_t *mod,
		asn1p_expr_t *expr,
		asn1p_module_t **mod_r) {
	static arg_t arg;

	arg.asn = asn;
	arg.mod = mod;
	arg.expr = expr;

	return asn1f_find_terminal_type(&arg, expr, mod_r);
}
