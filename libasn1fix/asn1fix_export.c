#include "asn1fix_internal.h"
#include "asn1fix_export.h"

extern arg_t a1f_replace_me_with_proper_interface_arg;

static asn1p_t *asn1f_ssn_asn_;

static void
_add_standard_namespaces(asn1_namespace_t *ns) {
    asn1p_oid_t *uioc_oid;
    asn1p_oid_arc_t arcs[] = {{1, "iso"},           {3, "org"},
                              {6, "dod"},           {1, "internet"},
                              {4, "private"},       {1, "enterprise"},
                              {9363, "spelio"},     {1, "software"},
                              {5, "asn1c"},         {3, "standard-modules"},
                              {0, "auto-imported"}, {1, 0}};

    uioc_oid = asn1p_oid_construct(arcs, sizeof(arcs) / sizeof(arcs[0]));

    asn1p_module_t *module = asn1f_lookup_module_ex(
        asn1f_ssn_asn_, "ASN1C-UsefulInformationObjectClasses", uioc_oid);
    asn1p_oid_free(uioc_oid);

    if(module) {
        asn1_namespace_add_module(ns, module, 0);
    }
}

void
asn1f_use_standard_namespaces(asn1p_t *asn) {
    asn1f_ssn_asn_ = asn;
    asn1_namespace_add_standard_namespaces_callback(_add_standard_namespaces);
}

asn1p_module_t *
asn1f_lookup_module_ex(asn1p_t *asn, const char *module_name,
                       const asn1p_oid_t *oid) {
    arg_t arg;

    memset(&arg, 0, sizeof(arg));

    arg.asn = asn;
    arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
    arg.debug = a1f_replace_me_with_proper_interface_arg.debug;
    return asn1f_lookup_module(&arg, module_name, oid);
}

asn1p_expr_t *
asn1f_lookup_symbol_ex(asn1p_t *asn, asn1_namespace_t *ns, asn1p_expr_t *expr,
                       const asn1p_ref_t *ref) {
    arg_t arg;

    memset(&arg, 0, sizeof(arg));

    arg.asn = asn;
    arg.ns = ns;
    arg.mod = expr->module;
    arg.expr = expr;
    arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
    arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

    return asn1f_lookup_symbol(&arg, expr->rhs_pspecs, ref);
}

asn1p_expr_t *
asn1f_class_access_ex(asn1p_t *asn,
		asn1p_module_t *mod,
		asn1_namespace_t *ns,
		asn1p_expr_t *expr,
		asn1p_expr_t *rhs_pspecs,
		const asn1p_ref_t *ref) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = mod;
	arg.ns = ns;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

    return asn1f_class_access(&arg, rhs_pspecs, ref);
}

asn1p_expr_t *
asn1f_find_terminal_type_ex(asn1p_t *asn, asn1_namespace_t *ns,
                            asn1p_expr_t *expr) {
    arg_t arg;

    memset(&arg, 0, sizeof(arg));

    arg.asn = asn;
    arg.ns = ns;
    arg.mod = expr->module;
    arg.expr = expr;
    arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
    arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

    return asn1f_find_terminal_type(&arg, expr);
}

asn1p_expr_t *
asn1f_find_ancestor_type_with_PER_constraint_ex(asn1p_t *asn, asn1p_expr_t *expr) {
	arg_t arg;

	memset(&arg, 0, sizeof(arg));

	arg.asn = asn;
	arg.mod = expr->module;
	arg.expr = expr;
	arg.eh = a1f_replace_me_with_proper_interface_arg.eh;
	arg.debug = a1f_replace_me_with_proper_interface_arg.debug;

	return asn1f_find_ancestor_type_with_PER_constraint(&arg, expr);
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

