#include "asn1c_internal.h"
#include "asn1c_misc.h"

#include <asn1fix_export.h>

/*
 * Checks that the given string is not a reserved C/C++ keyword.
 */
static char *res_kwd[] = {
	"char", "int", "long",
	"float", "double",
	"struct", "typedef", "class" };
static int
reserved_keyword(const char *str) {
	int i;
	for(i = 0 ; i < sizeof(res_kwd)/sizeof(res_kwd[0]); i++) {
		if(strcmp(str, res_kwd[i]) == 0)
			return 1;
	}
	return 0;
}

/*
 * Construct identifier from multiple parts.
 * Convert unsafe characters to underscores.
 */
char *
asn1c_make_identifier(enum ami_flags_e flags, char *arg1, ...) {
	static char *storage;
	static int storage_size;
	int nodelimiter = 0;
	va_list ap;
	char *str;
	char *nextstr;
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
	for(str = arg1; str; str = nextstr) {
		int subst_made = 0;
		nextstr = va_arg(ap, char *);

		if(str[0] == ' ' && str[1] == '\0') {
			*p++ = ' ';
			nodelimiter = 1;	/* No delimiter */
			continue;
		}

		if(str != arg1 && !nodelimiter)
			*p++ = '_';	/* Delimiter between tokens */
		nodelimiter = 0;

		/*
		 * If it is a single argument, check that it does not clash
		 * with C/C++ language keywords.
		 */
		if((flags & AMI_CHECK_RESERVED)
		&& str == arg1 && !nextstr && reserved_keyword(str)) {
			*p++ = toupper(*str++);
			/* Fall through */
		}

		for(; *str; str++) {
			if(isalnum(*str)) {
				*p++ = *str;
				subst_made = 0;
			} else if(!subst_made++) {
				if((flags & AMI_MASK_ONLY_SPACES)
						&& !isspace(*str)) {
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
	enum ami_flags_e ami_flags = (_format & TNF_CHECK)
		? AMI_CHECK_RESERVED : 0;
	_format &= ~TNF_CHECK;

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
			terminal = asn1f_find_terminal_type_ex(arg->asn, expr);
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
		assert(ami_flags == 0);	/* (TNF_INCLUDE | TNF_CHECK)?! */
		ami_flags |= AMI_MASK_ONLY_SPACES;
		return asn1c_make_identifier(ami_flags, typename, 0);
	case TNF_SAFE:
		return asn1c_make_identifier(ami_flags, typename, 0);
	case TNF_CTYPE:
		return asn1c_make_identifier(ami_flags, typename, "t", 0);
	case TNF_RSAFE:
		return asn1c_make_identifier(ami_flags, "struct", " ", typename, 0);
	case TNF_NORCHECK:
	case TNF_CHECK:
		assert(_format != TNF_NORCHECK);
		assert(_format != TNF_CHECK);
	}

	assert(!"unreachable");
	return typename;
}

