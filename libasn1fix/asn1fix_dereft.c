#include "asn1fix_internal.h"

int
asn1f_fix_dereference_types(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *type_expr;
	int r_value = 0;

	if(expr->expr_type != A1TC_REFERENCE
	|| expr->meta_type != AMT_TYPEREF) {
		//assert(expr->reference == 0);
		return 0;	/* Just ignore it */
	}

	DEBUG("(\"%s\":%x ::= \"%s\") for line %d",
		expr->Identifier, expr->expr_type,
		asn1f_printable_value(expr->value),
		expr->_lineno);

	assert(TQ_FIRST(&(expr->members)) == 0);
	assert(expr->reference);

	/*
	 * Follow the reference.
	 */
	type_expr = asn1f_find_terminal_type(arg, expr);
	if(type_expr == NULL) {
		const char *type_name;
		asn1p_expr_t *idexpr;

		if(errno == EEXIST) {
			/* Ignore missing type
			 * if known to be defined externally:
			 * -fknown-extern-type=<name>
			 */
			return 0;
		}

		type_name = asn1f_printable_reference(expr->reference);
		/* Avoid NULL in case of unnamed T ::= SEQUENCE OF ... */
		for(idexpr = expr; !idexpr->Identifier && idexpr->parent_expr;
			idexpr = idexpr->parent_expr);
		FATAL("Unknown type \"%s\" referenced by \"%s\" at line %d",
			type_name, idexpr->Identifier, expr->_lineno);
		return -1;
	}

	return r_value;
}

