#include "asn1fix_internal.h"

static int _asn1f_copy_value(arg_t *arg, asn1p_expr_t *to,asn1p_expr_t *from);

int
asn1f_value_resolve(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_module_t *val_mod;
	asn1p_expr_t *val_type_expr;
	asn1p_expr_t *value_expr;
	asn1p_expr_t *type_expr;
	int ret;

	/* Make sure this IS a value assignment */
	assert(expr->meta_type == AMT_VALUE);
	assert(expr->value);

	DEBUG("%s(=\"%s\", %x)", __func__,
		asn1f_printable_value(expr->value), expr->expr_type);

	/*
	 * 1. Find the terminal type for this assignment.
	 */
	type_expr = asn1f_find_terminal_type(arg, expr, 0);
	if(type_expr == 0) {
		DEBUG("\tTerminal type for %s not found", expr->Identifier);
		return -1;
	}

	if(asn1f_look_value_in_type(arg, type_expr, expr) == -1)
		return -1;

	/*
	 * 2. Find the terminal value also.
	 */
	value_expr = asn1f_find_terminal_value(arg, expr, &val_mod);
	if(value_expr) {
		DEBUG("\tTerminal value for %s->%s is %s at line %d",
			expr->Identifier, asn1f_printable_value(expr->value),
			value_expr->Identifier, value_expr->_lineno);
	} else {
		DEBUG("\tTerminal value for %s->%s not found",
			expr->Identifier, asn1f_printable_value(expr->value));
		return -1;
	}

	/*
	 * 3. Find the _type_ of a _terminal value_.
	 */
	WITH_MODULE(val_mod,
		val_type_expr = asn1f_find_terminal_type(arg, value_expr, 0));
	if(val_type_expr) {
		DEBUG("\tTerminal type of value %s->%s is %s at line %d",
			expr->Identifier, asn1f_printable_value(expr->value),
			val_type_expr->Identifier, val_type_expr->_lineno);
	} else {
		DEBUG("\tTerminal type of value %s->%s not found",
			expr->Identifier, asn1f_printable_value(expr->value));
		return -1;
	}

	/*
	 * 4. Check compatibility between the type of the current expression
	 * and the type of the discovered value.
	 */
	ret = asn1f_check_type_compatibility(arg, type_expr, val_type_expr);
	if(ret == -1) {
		DEBUG("\tIncompatible type of %s at %d with %s at %d",
			type_expr->Identifier, type_expr->_lineno,
			val_type_expr->Identifier, val_type_expr->_lineno);
		return -1;
	}

	if(asn1f_look_value_in_type(arg, val_type_expr, expr) == -1)
		return -1;

	/*
	 * 5. Copy value from the terminal value into the current expression.
	 */
	ret = _asn1f_copy_value(arg, expr, value_expr);
	if(ret == -1) {
		DEBUG("\tValue %s cannot be copied from line %d to line %d",
			asn1f_printable_value(value_expr->value),
			value_expr->_lineno, expr->_lineno);
		return -1;
	}

	DEBUG("\tFinal value for \"%s\" at line %d is %s",
		expr->Identifier, expr->_lineno,
		asn1f_printable_value(expr->value));

	return 0;
}

static int
_asn1f_copy_value(arg_t *arg, asn1p_expr_t *to, asn1p_expr_t *from) {
	asn1p_value_t *v;

	v = asn1p_value_clone(from->value);
	if(v) {
		asn1p_value_free(to->value);
		to->value = v;
		DEBUG("Copied value %s from \"%s\" on line %d "
			"to \"%s\" on line %d",
			asn1f_printable_value(v),
			from->Identifier,
			from->_lineno,
			to->Identifier,
			to->_lineno
		);
		return 0;
	} else {
		return -1;
	}
}

int
asn1f_look_value_in_type(arg_t *arg,
		asn1p_expr_t *type_expr,
		asn1p_expr_t *value_expr) {
	asn1p_expr_t *child_expr;
	char *identifier;

	if(value_expr->value->type != ATV_REFERENCED
	|| value_expr->value->value.reference->comp_count != 1)
		return 0;
	if(type_expr->expr_type != ASN_BASIC_INTEGER
	&& type_expr->expr_type != ASN_BASIC_ENUMERATED)
		return 0;

	DEBUG("%s(for %s in %s %x) for line %d", __func__,
		asn1f_printable_value(value_expr->value),
		type_expr->Identifier,
		type_expr->expr_type,
		value_expr->_lineno);

	/*
	 * Look into the definitions of the type itself:
	 * Type1 ::= INTEGER { a(1), b(2) }
	 * value Type1 = b	-- will assign 2
	 */
	identifier = value_expr->value->value.reference->components[0].name;

	child_expr = asn1f_lookup_child(type_expr, identifier);
	DEBUG("\tLooking into a type %s at line %d for %s at line %d: %s",
		type_expr->Identifier, type_expr->_lineno,
		identifier, value_expr->_lineno,
		child_expr
			? asn1f_printable_value(child_expr->value)
			: "<not found>"
		);

	if(child_expr && child_expr->value) {
		if(_asn1f_copy_value(arg, value_expr, child_expr))
			return -1;
		/* Fall through */
	}

	return 0;
}
