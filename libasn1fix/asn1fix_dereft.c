#include "asn1fix_internal.h"

int
asn1f_fix_dereference_types(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *type_expr;
	int r_value = 0;

	if(expr->expr_type == A1TC_PARAMETRIZED)
		return asn1f_fix_parametrized_assignment(arg);

	if(expr->expr_type != A1TC_REFERENCE
	|| expr->meta_type != AMT_TYPEREF) {
		//assert(expr->reference == 0);
		return 0;	/* Just ignore it */
	}

	DEBUG("%s(\"%s\":%x ::= \"%s\") for line %d",
		__func__, expr->Identifier, expr->expr_type,
		asn1f_printable_value(expr->value),
		expr->_lineno);

	assert(TQ_FIRST(&(expr->members)) == 0);
	assert(expr->reference);

	/*
	 * Follow the reference.
	 */
	type_expr = asn1f_find_terminal_type(arg, expr, 0);
	if(type_expr == NULL) {
		const char *type_name;

		if(errno == EEXIST) {
			/* Ignore missing type
			 * if known to be defined externally:
			 * -fknown-extern-type=<name>
			 */
			return 0;
		}

		type_name = asn1f_printable_reference(expr->reference);
		FATAL("Unknown type \"%s\" referenced by \"%s\" at line %d",
			type_name, expr->Identifier, expr->_lineno);
		return -1;
	}

	/*
	 * Copying members of the source expression
	 * into the current expression.
	 */
	if(0) {
		asn1p_expr_t *tmp_clone;

		tmp_clone = asn1p_expr_clone(type_expr);
		if(tmp_clone == NULL) {
			FATAL("Could not clone \"%s\" at line %d",
				type_expr->Identifier, type_expr->_lineno);
			return -1;
		}

		/*
		 * Replace the referenced type with its definition.
		 */
		DEBUG("\tChanging type of \"%s\":%x to %x for line %d",
			expr->Identifier,
			expr->expr_type,
			type_expr->expr_type,
			expr->_lineno
		);
		expr->expr_type = type_expr->expr_type;
		expr->members = tmp_clone->members;
		memset(&tmp_clone->members, 0, sizeof(tmp_clone->members));
		asn1p_expr_free(tmp_clone);
	}

	return r_value;
}

