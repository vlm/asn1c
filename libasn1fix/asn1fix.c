#include "asn1fix_internal.h"
#include "asn1fix.h"

/* Print everything to stderr */
static void _default_error_logger(int _severity, const char *fmt, ...);

/*
 * Internal check functions.
 */
static int asn1f_fix_module__phase_1(arg_t *arg);
static int asn1f_fix_module__phase_2(arg_t *arg);
static int asn1f_fix_simple(arg_t *arg);	/* For INTEGER/ENUMERATED */
static int asn1f_fix_constructed(arg_t *arg);	/* For SEQUENCE/SET/CHOICE */
static int asn1f_resolve_constraints(arg_t *arg); /* For subtype constraints */
static int asn1f_check_constraints(arg_t *arg);	/* For subtype constraints */
static int asn1f_check_duplicate(arg_t *arg);
static int asn1f_apply_unique_index(arg_t *arg);

arg_t a1f_replace_me_with_proper_interface_arg;

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

	/* Allow SIZE() constraint for INTEGER and other types */
	if(flags & A1F_EXTENDED_SizeConstraint) {
		arg.flags |= A1F_EXTENDED_SizeConstraint;
		flags &= ~A1F_EXTENDED_SizeConstraint;
		if(arg.debug) {
			arg.debug(-1,
				"Extended SizeConstraint support enabled");
		}
	}

	a1f_replace_me_with_proper_interface_arg = arg;

	/*
	 * Check that we haven't missed an unknown flag.
	 */
	if(flags) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * Process each module in the list.
	 * PHASE I.
	 */
	TQ_FOR(arg.mod, &(asn->modules), mod_next) {
		int ret = asn1f_fix_module__phase_1(&arg);
		/*
		 * These lines are used for illustration purposes.
		 * RET2RVAL() is used everywhere else.
		 */
		if(ret == -1) fatals++;
		if(ret == 1) warnings++;
	}
	/* PHASE II. */
	TQ_FOR(arg.mod, &(asn->modules), mod_next) {
		int ret = asn1f_fix_module__phase_2(&arg);
		if(ret == -1) fatals++;
		if(ret == 1) warnings++;
	}

	memset(&a1f_replace_me_with_proper_interface_arg, 0, sizeof(arg_t));

	/*
	 * Compute a return value.
	 */
	return fatals?-1:warnings?1:0;
}

/*
 * Check the internals of a single module.
 */
static int
asn1f_fix_module__phase_1(arg_t *arg) {
	asn1p_expr_t *expr;
	int rvalue = 0;
	int ret;

	switch((arg->mod->module_flags & MSF_MASK_TAGS)) {
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

	switch((arg->mod->module_flags & MSF_MASK_INSTRUCTIONS)) {
	case MSF_NOFLAGS:
		/*
		 * arg->mod->module_flags |= MSF_TAG_INSTRUCTIONS;
		 */
		break;
	case MSF_unk_INSTRUCTIONS:
		WARNING("Module %s defined with unrecognized "
			"encoding reference", arg->mod->Identifier);
		RET2RVAL(1, rvalue);
		/* Fall through */
	case MSF_TAG_INSTRUCTIONS:
	case MSF_XER_INSTRUCTIONS:
		break;
	default:
		FATAL("Module %s defined with ambiguous encoding reference",
			arg->mod->Identifier);
		RET2RVAL(-1, rvalue);
	}

	/*
	 * Do various non-recursive transformations.
	 */
	TQ_FOR(expr, &(arg->mod->members), next) {
		arg->expr = expr;

		/* Check whether this type is a duplicate */
		ret = asn1f_check_duplicate(arg);
		RET2RVAL(ret, rvalue);

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
		 * 2.5.4
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_dereference_types);
		RET2RVAL(ret, rvalue);

		/*
		 * Fix tagging of top-level types.
		 */
		ret = asn1f_fix_constr_tag(arg, 1);
		RET2RVAL(ret, rvalue);

		/*
		 * 2.[234] Process SEQUENCE/SET/CHOICE types.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_constructed);
		RET2RVAL(ret, rvalue);

		/*
		 * 2.5.5
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_dereference_values);
		RET2RVAL(ret, rvalue);

		/*
		 * Resolve references in constraints.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_resolve_constraints);
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
		arg->expr = expr;

		ret = asn1f_recurse_expr(arg, asn1f_check_constr_tags_distinct);
		RET2RVAL(ret, rvalue);

		assert(arg->expr == expr);
	}

	return rvalue;
}

static int
asn1f_fix_module__phase_2(arg_t *arg) {
	asn1p_expr_t *expr;
	int rvalue = 0;
	int ret;

	TQ_FOR(expr, &(arg->mod->members), next) {
		arg->expr = expr;

		if(expr->meta_type == AMT_PARAMTYPE)
			/* Do not process the parametrized types here */
			continue;

		/*
		 * Dereference DEFAULT values.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_fix_dereference_defaults);
		RET2RVAL(ret, rvalue);

		/*
		 * Check semantic validity of constraints.
		 */
		ret = asn1f_recurse_expr(arg, asn1f_check_constraints);
		RET2RVAL(ret, rvalue);

		/*
		 * Uniquely tag each inner type.
		 */
		asn1f_apply_unique_index(0);
		ret = asn1f_recurse_expr(arg, asn1f_apply_unique_index);
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
	ret = asn1f_fix_constr_tag(arg, 0);
	RET2RVAL(ret, rvalue);

	/* Import COMPONENTS OF stuff */
	ret = asn1f_pull_components_of(arg);
	RET2RVAL(ret, rvalue);

	return rvalue;
}

static int
asn1f_resolve_constraints(arg_t *arg) {
	asn1p_expr_t *top_parent;
	asn1p_expr_type_e etype;
	int rvalue = 0;
	int ret;

	top_parent = asn1f_find_terminal_type(arg, arg->expr);
	if(top_parent)
		etype = top_parent->expr_type;
	else	etype = A1TC_INVALID;

	DEBUG("(%s)", arg->expr->Identifier);

	ret = asn1constraint_resolve(arg, arg->expr->module,
		arg->expr->constraints, etype, 0);
	RET2RVAL(ret, rvalue);

	return rvalue;
}

static int
asn1f_check_constraints(arg_t *arg) {
	static enum asn1p_constraint_type_e test_types[] = {
		ACT_EL_RANGE, ACT_CT_SIZE, ACT_CT_FROM };
	asn1p_expr_t *top_parent;
	asn1cnst_range_t *range;
	asn1p_expr_type_e etype;
	unsigned int i;
	int rvalue = 0;
	int ret;

	DEBUG("(%s{%d/%d})",
		arg->expr->Identifier,
		arg->expr->meta_type, arg->expr->expr_type);

	top_parent = asn1f_find_terminal_type(arg, arg->expr);
	if(!top_parent)
		return 0;
	etype = top_parent->expr_type;

	ret = asn1constraint_pullup(arg);
	RET2RVAL(ret, rvalue);

	for(i = 0; i < sizeof(test_types)/sizeof(test_types[0]); i++) {
		range = asn1constraint_compute_PER_range(
				etype,
				arg->expr->combined_constraints,
				test_types[i], 0, 0, 0);
		if(!range && errno == EPERM) {
			FATAL("This error happened for \"%s\" (meta %d) "
				"at line %d",
				arg->expr->Identifier,
				arg->expr->meta_type,
				arg->expr->_lineno);
			return -1;
		}
		asn1constraint_range_free(range);
	}

	return rvalue;
}

static int
asn1f_check_duplicate(arg_t *arg) {
	arg_t tmparg = *arg;

	/*
	 * This is a linear scan in search of a similar type.
	 * The linear scan is just fine for the task, no need to over-optimize.
	 */
	TQ_FOR(tmparg.mod, &arg->asn->modules, mod_next) {
		TQ_FOR(tmparg.expr, &(tmparg.mod->members), next) {
			assert(tmparg.expr->Identifier);
			assert(arg->expr->Identifier);
			if(tmparg.expr == arg->expr) break;

			if(strcmp(tmparg.expr->Identifier,
				arg->expr->Identifier) == 0) {
				int diff_files = strcmp(arg->mod->source_file_name, tmparg.mod->source_file_name) ? 1 : 0;
				FATAL("ASN.1 expression \"%s\" at line %d of module %s\n"
				"clashes with expression \"%s\" at line %d of module %s"
				"%s%s%s.\n"
				"Please rename either instance to resolve the conflict",
					arg->expr->Identifier,
					arg->expr->_lineno,
					arg->mod->Identifier,
					tmparg.expr->Identifier,
					tmparg.expr->_lineno,
					tmparg.mod->Identifier,
					diff_files ? " (" : "",
					diff_files ? tmparg.mod->source_file_name : "",
					diff_files ? ")" : ""
				);
				return -1;
			}
		}
		if(tmparg.mod == arg->mod) break;
	}

	return 0;
}

static int
asn1f_apply_unique_index(arg_t *arg) {
	static int unique_index;
	if(!arg) { unique_index = 0; return 0; }

	arg->expr->_type_unique_index = ++unique_index;

	return 0;
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
