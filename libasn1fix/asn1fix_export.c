#include "asn1fix_internal.h"
#include "asn1fix_export.h"

extern arg_t a1f_replace_me_with_proper_interface_arg;


asn1p_expr_t *
asn1f_lookup_symbol_ex(
		asn1p_t *asn,
		asn1p_expr_t *expr,
		asn1p_ref_t *ref) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = expr->module;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;


	return asn1f_lookup_symbol(&arg, expr->module, expr->rhs_pspecs, ref);
}

asn1p_expr_t *
asn1f_class_access_ex(asn1p_t *asn,
		asn1p_module_t *mod,
		asn1p_expr_t *expr,
		asn1p_expr_t *rhs_pspecs,
		asn1p_ref_t *ref) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = mod;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

	return asn1f_class_access(&arg, mod, rhs_pspecs, ref);
}

asn1p_expr_t *
asn1f_find_terminal_type_ex(asn1p_t *asn, asn1p_expr_t *expr) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = expr->module;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

	return asn1f_find_terminal_type(&arg, expr);
}

int
asn1f_fix_dereference_values_ex(asn1p_t *asn, asn1p_module_t *mod,
        asn1p_expr_t *expr) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = mod;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

	return asn1f_fix_dereference_values(&arg);
}

