#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

#include "asn1fix.h"
#include "asn1fix_internal.h"

/* Print everything to stderr */
static void _default_error_logger(int _severity, const char *fmt, ...);

/*
 * Internal check functions.
 */
static int asn1f_fix_module(arg_t *arg);
static int asn1f_fix_simple(arg_t *arg);	/* For INTEGER/ENUMERATED */
static int asn1f_fix_constructed(arg_t *arg);	/* For SEQUENCE/SET/CHOICE */
static int asn1f_fix_constraints(arg_t *arg);	/* For subtype constraints */


/*
 * Scan every module defined here in search for inconsistences.
 */
int
asn1f_process(asn1p_t *asn, enum asn1f_flags flags,
		error_logger_f error_logger) {
	arg_t arg;
	int fatals = 0;
	int warnings = 0;

	/*
	 * Check validity of arguments.
	 */
	if(asn == NULL) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * If errors handler is not specified, default to internal one.
	 */
	if(error_logger == 0) {
		error_logger = _default_error_logger;
	}

	memset(&arg, 0, sizeof(arg));
	arg.asn = asn;
	arg.eh = error_logger;

	if(flags & A1F_DEBUG) {
		arg.debug = arg.eh;
		arg.debug(-1, "Called %s() with flags %d", __func__, flags);
		flags &= ~A1F_DEBUG;
	}

	/*
	 * Check that we haven't missed an unknown flag.
	 */
	if(flags) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * Process each module in the list.
	 */
	TQ_FOR(arg.mod, &(asn->modules), mod_next) {
		int ret = asn1f_fix_module(&arg);
		/*
		 * These lines are used for illustration purposes.
		 * RET2RVAL() is used everywhere else.
		 */
		if(ret == -1) fatals++;
		if(ret == 1) warnings++;
	}

	/*
	 * Compute a return value.
	 */
	return fatals?-1:warnings?1:0;
}

/*
 * Check the internals of a single module.
 */
static int
asn1f_fix_module(arg_t *arg) {
	asn1p_expr_t *expr;
	int rvalue = 0;

	switch((arg->mod->module_flags
	& (MSF_EXPLICIT_TAGS | MSF_IMPLICIT_TAGS | MSF_AUTOMATIC_TAGS))) {
	case MSF_NOFLAGS:
	case MSF_EXPLICIT_TAGS:
	case MSF_IMPLICIT_TAGS:
	case MSF_AUTOMATIC_TAGS:
		break;
	default:
		FATAL("Module %s defined with ambiguous global tagging mode",
			arg->mod->Identifier);
		RET2RVAL(-1, rvalue);
	}

	/*
	 * Do various non-recursive transformations.
	 * Order is not important.
	 */
	TQ_FOR(expr, &(arg->mod->members), next) {
		int ret;
		arg->expr = expr;

		if(expr->meta_type == AMT_PARAMTYPE)
			/* Do not process the parametrized type just yet */
			continue;

		DEBUG("=== Now processing \"%s\" at line %d ===",
			expr->Identifier, expr->_lineno);
		assert(expr->meta_type != AMT_INVALID);

		/*
		 * 2.1 Pre-process simple types (ENUMERATED, INTEGER, etc).
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_simple);
		RET2RVAL(ret, rvalue);

		/*
		 * 2.[234] Process SEQUENCE/SET/CHOICE types.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_constructed);
		RET2RVAL(ret, rvalue);

		/*
		 * 2.5.4
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_dereference_types);
		RET2RVAL(ret, rvalue);

		/*
		 * 2.5.5
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_dereference_values);
		RET2RVAL(ret, rvalue);

		/*
		 * Resolve references in constraints.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_constraints);
		RET2RVAL(ret, rvalue);

		/*
		 * 6. INTEGER value processed at 2.5.4.
		 */

		/*
		 * Make sure everybody's behaving well.
		 */
		assert(arg->expr == expr);
	}

	/*
	 * 5. Automatic tagging
	 */
	TQ_FOR(expr, &(arg->mod->members), next) {
		int ret;

		arg->expr = expr;

		ret = asn1f_recurse_expr(arg, asn1f_fix_constr_autotag);
		RET2RVAL(ret, rvalue);

		assert(arg->expr == expr);
	}

	/*
	 * 8. fix BIT STRING
	 * 9. fix spaces in cstrings
	 */
	TQ_FOR(expr, &(arg->mod->members), next) {
		int ret;
		arg->expr = expr;

		ret = asn1f_recurse_expr(arg, asn1f_fix_bit_string);
		RET2RVAL(ret, rvalue);

		ret = asn1f_recurse_expr(arg, asn1f_fix_cstring);
		RET2RVAL(ret, rvalue);

		assert(arg->expr == expr);
	}

	/*
	 * ... Check for tags distinctness.
	 */
	TQ_FOR(expr, &(arg->mod->members), next) {
		int ret;
		arg->expr = expr;

		ret = asn1f_recurse_expr(arg, asn1f_check_constr_tags_distinct);
		RET2RVAL(ret, rvalue);

		assert(arg->expr == expr);
	}

	return rvalue;
}


static int
asn1f_fix_simple(arg_t *arg) {
	int rvalue = 0;
	int ret;

	ret = asn1f_fix_enum(arg);
	RET2RVAL(ret, rvalue);

	ret = asn1f_fix_integer(arg);
	RET2RVAL(ret, rvalue);

	return rvalue;
}

static int
asn1f_fix_constructed(arg_t *arg) {
	int rvalue = 0;
	int ret;

	switch(arg->expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	/* Check identifier distinctness */
	ret = asn1f_check_unique_expr(arg, NULL);
	RET2RVAL(ret, rvalue);

	/* Fix extensibility */
	ret = asn1f_fix_constr_ext(arg);
	RET2RVAL(ret, rvalue);

	/* Fix tagging */
	ret = asn1f_fix_constr_tag(arg);
	RET2RVAL(ret, rvalue);

	return rvalue;
}

static int
_constraint_value_resolve(arg_t *arg, asn1p_value_t **value) {
	asn1p_expr_t expr;
	asn1p_expr_t *tmp_expr;
	asn1p_module_t *tmp_mod;
	asn1p_module_t *mod_r = NULL;
	int rvalue = 0;
	int ret;

	tmp_expr = asn1f_lookup_symbol(arg, (*value)->value.reference, &mod_r);
	if(tmp_expr == NULL) {
		FATAL("Cannot find symbol %s "
			"used in %s subtype constraint at line %d",
			asn1f_printable_reference((*value)->value.reference),
			arg->expr->Identifier, arg->expr->_lineno);
		assert((*value)->type == ATV_REFERENCED);
		return -1;
	}

	memset(&expr, 0, sizeof(expr));
	expr.meta_type = tmp_expr->meta_type;
	expr.expr_type = tmp_expr->expr_type;
	expr.Identifier = tmp_expr->Identifier;
	expr.value = *value;
	tmp_expr = arg->expr;
	tmp_mod = arg->mod;
	arg->expr = &expr;
	arg->mod = mod_r;
	ret = asn1f_fix_dereference_values(arg);
	RET2RVAL(ret, rvalue);
	arg->expr = tmp_expr;
	arg->mod = tmp_mod;
	assert(expr.value);
	*value = expr.value;

	return rvalue;
}

static int
_resolve_constraints(arg_t *arg, asn1p_constraint_t *ct) {
	int rvalue = 0;
	int ret;
	int el;

	/* Don't touch information object classes */
	if(ct->type == ACT_CT_WCOMP
	|| ct->type == ACT_CT_WCOMPS
	|| ct->type == ACT_CA_CRC)
		return 0;

	if(ct->value && ct->value->type == ATV_REFERENCED) {
		ret = _constraint_value_resolve(arg, &ct->value);
		RET2RVAL(ret, rvalue);
	}
	if(ct->range_start && ct->range_start->type == ATV_REFERENCED) {
		ret = _constraint_value_resolve(arg, &ct->range_start);
		RET2RVAL(ret, rvalue);
	}
	if(ct->range_stop && ct->range_stop->type == ATV_REFERENCED) {
		ret = _constraint_value_resolve(arg, &ct->range_stop);
		RET2RVAL(ret, rvalue);
	}

	for(el = 0; el < ct->el_count; el++) {
		ret = _resolve_constraints(arg, ct->elements[el]);
		RET2RVAL(ret, rvalue);
	}

	return rvalue;
}

static int
asn1f_fix_constraints(arg_t *arg) {
	int rvalue = 0;
	int ret;

	if(arg->expr->constraints) {
		ret = _resolve_constraints(arg, arg->expr->constraints);
		RET2RVAL(ret, rvalue);
	}

	return rvalue;
}

/*
 * Print everything to stderr
 */
static void
_default_error_logger(int _severity, const char *fmt, ...) {
	va_list ap;
	char *pfx = "";

	switch(_severity) {
	case -1: pfx = "DEBUG: "; break;
	case 0: pfx = "WARNING: "; break;
	case 1: pfx = "FATAL: "; break;
	}
	
	fprintf(stderr, "%s", pfx);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}
