#include "asn1c_internal.h"
#include "asn1c_misc.h"

#include <asn1fix_export.h>

/*
 * Construct identifier from multiple parts.
 * Convert unsafe characters to underscores.
 */
char *
asn1c_make_identifier(int unsafe_only_spaces, char *arg1, ...) {
	static char *storage;
	static int storage_size;
	int nodelimiter = 0;
	va_list ap;
	char *str;
	int size;
	char *p;

	if(arg1 == NULL)
		return NULL;

	/*
	 * Estimate the necessary storage size
	 */
	size = strlen(arg1);
	va_start(ap, arg1);
	while((str = va_arg(ap, char *)))
		size += 1 + strlen(str);
	va_end(ap);

	/*
	 * Make sure we have this amount of storage.
	 */
	if(storage_size <= size) {
		if(storage) free(storage);
		storage = malloc(size + 1);
		if(storage) {
			storage_size = size;
		} else {
			storage_size = 0;
			return NULL;
		}
	}

	/*
	 * Fill-in the storage.
	 */
	va_start(ap, arg1);
	str = arg1;
	p = storage;
	for(str = arg1; str; str = va_arg(ap, char *)) {
		int subst_made = 0;

		if(str[0] == ' ' && str[1] == '\0') {
			*p++ = ' ';
			nodelimiter = 1;	/* No delimiter */
			continue;
		}

		if(str != arg1 && !nodelimiter)
			*p++ = '_';	/* Delimiter between tokens */
		nodelimiter = 0;

		for(; *str; str++) {
			if(isalnum(*str)) {
				*p++ = *str;
				subst_made = 0;
			} else if(!subst_made++) {
				if(unsafe_only_spaces && !isspace(*str)) {
					*p ++ = *str;
				} else {
					*p++ = '_';
				}
			}
		}
	}
	va_end(ap);
	*p = '\0';

	assert((p - storage) <= storage_size);

	return storage;
}

char *
asn1c_type_name(arg_t *arg, asn1p_expr_t *expr, enum tnfmt _format) {
	asn1p_expr_t *top_parent;
	char *typename;

	/* Rewind to the topmost parent expression */
	if((top_parent = expr->parent_expr))
		while(top_parent->parent_expr)
			top_parent = top_parent->parent_expr;

	switch(expr->expr_type) {
	case A1TC_REFERENCE:
		typename = expr->reference->components[
			expr->reference->comp_count-1].name;
		if(typename[0] == '&') {
			arg_t tmp = *arg;

			/*
			 * This is a reference to a type defined in a class.
			 * Resolve it and use instead.
			 */
			tmp.expr = asn1f_class_access_ex(arg->asn, arg->mod,
				arg->expr, expr->reference);
			if(tmp.expr) return NULL;

			tmp.mod = tmp.expr->module;
			return asn1c_type_name(&tmp, tmp.expr, _format);
		}

		if(_format == TNF_CTYPE) {
			/*
			 * If the component references the type itself,
			 * switch to a recursion safe type representation
			 * ("struct foo" instead of "foo_t").
			 */
			asn1p_expr_t *terminal;
			terminal = asn1f_find_terminal_type_ex(
				arg->asn, arg->mod, expr);
			if(terminal && terminal == top_parent) {
				_format = TNF_RSAFE;
			}
		}
		break;
#if 0
	case ASN_CONSTR_SEQUENCE_OF:
	case ASN_CONSTR_SET_OF:
		if(expr->Identifier) {
			typename = expr->Identifier;
		} else {
			asn1p_expr_t *child;
			child = TQ_FIRST(&(expr->members));
			typename = asn1c_type_name(arg, child, _format);
			if(typename)
				return typename;
			_format = TNF_SAFE;
			typename = child->Identifier;
		}
		break;
#endif
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
	case ASN_BASIC_REAL:
		if((arg->flags & A1C_USE_NATIVE_TYPES)) {
			switch(_format) {
			case TNF_CTYPE:
			case TNF_RSAFE:
				if(expr->expr_type == ASN_BASIC_REAL)
					return "double";
				else
					return "int";
			default: break;
			}
			switch(expr->expr_type) {
			case ASN_BASIC_INTEGER:
				return "NativeInteger";
			case ASN_BASIC_ENUMERATED:
				return "NativeEnumerated";
			case ASN_BASIC_REAL:
				return "NativeReal";
			default: break;
			}
		}
		/* Fall through */
	default:
		if(expr->expr_type
		& (ASN_CONSTR_MASK | ASN_BASIC_MASK | ASN_STRING_MASK)) {
			if(_format == TNF_RSAFE)
				_format = TNF_CTYPE;
			typename = ASN_EXPR_TYPE2STR(expr->expr_type);
		} else {
			_format = TNF_RSAFE;
			typename = expr->Identifier;
		}
	}

	switch(_format) {
	case TNF_UNMODIFIED:
	case TNF_INCLUDE:
		return asn1c_make_identifier(1, typename, 0);
	case TNF_SAFE:
		return asn1c_make_identifier(0, typename, 0);
	case TNF_CTYPE:
		return asn1c_make_identifier(0, typename, "t", 0);
	case TNF_RSAFE:
		return asn1c_make_identifier(0, "struct", " ", typename, 0);
	}

	assert(!"unreachable");
	return typename;
}

