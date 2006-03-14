#include "asn1fix_internal.h"
#include "asn1fix_cws.h"

int
asn1f_parse_class_with_syntax(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;

	if(expr->expr_type != A1TC_CLASSDEF
	|| expr->with_syntax == NULL)
		return 0;

	DEBUG("Class %s: checking WITH SYNTAX", expr->Identifier);

	return 0;
}
