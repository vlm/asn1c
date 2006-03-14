#include "asn1c_internal.h"
#include "asn1c_misc.h"

#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportable stuff from libasn1fix */

/*
 * Checks that the given string is not a reserved C/C++ keyword.
 * ISO/IEC 9899:1999 (C99), A.1.2
 */
static char *res_kwd[] = {
	"const", "auto", "register", "volatile", "restrict", "extern",
	"static", "inline",
	"signed", "unsigned",
	"void", "char", "short", "int", "long", "float", "double",
	"enum", "union", "struct", "typedef", "class",
	"switch", "case", "default", "break", "continue",
	"if", "else", "do", "for", "while", "goto",
	"sizeof", "return"
};
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
	size_t size;
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

	/* Rewind to the topmost parent expression */
	if((top_parent = expr->parent_expr))
		while(top_parent->parent_expr)
			top_parent = top_parent->parent_expr;

	DEBUG("asn1c_type_name(%s: 0x%x)", expr->Identifier, expr->expr_type);

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
			tmp.expr = asn1f_class_access_ex(arg->asn,
				arg->expr->module, arg->expr, expr->reference);
			if(!tmp.expr) return NULL;

			return asn1c_type_name(&tmp, tmp.expr, _format);
		}

		if(_format == TNF_RSAFE) {
			asn1p_expr_t *terminal;
			terminal = asn1f_find_terminal_type_ex(arg->asn, expr);
			if(terminal && terminal->expr_type & ASN_CONSTR_MASK) {
				typename = terminal->Identifier;
			}
		}

		if(_format == TNF_CTYPE) {
			/*
			 * If the component references the type itself,
			 * switch to a recursion-safe type naming
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
		if((expr->expr_type == ASN_BASIC_REAL
			&& (arg->flags & A1C_USE_NATIVE_TYPES))
		|| asn1c_type_fits_long(arg, expr)) {
			switch(_format) {
			case TNF_CTYPE:
			case TNF_RSAFE:
				if(expr->expr_type == ASN_BASIC_REAL)
					return "double";
				else
					return "long";
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
		return asn1c_make_identifier(AMI_MASK_ONLY_SPACES, typename, 0);
	case TNF_SAFE:
		return asn1c_make_identifier(0, typename, 0);
	case TNF_CTYPE:	/* C type */
		return asn1c_make_identifier(0, typename, "t", 0);
	case TNF_RSAFE:	/* Recursion-safe type */
		return asn1c_make_identifier(AMI_CHECK_RESERVED,
			"struct", " ", typename, 0);
	}

	assert(!"unreachable");
	return typename;
}

/*
 * Check whether the specified INTEGER or ENUMERATED type can be represented
 * using the generic 'long' type.
 */
enum asn1c_fitslong_e
asn1c_type_fits_long(arg_t *arg, asn1p_expr_t *expr) {
	asn1cnst_range_t *range = 0;
	asn1cnst_edge_t left;
	asn1cnst_edge_t right;
	asn1p_expr_t *v;

/*
 * Since we don't know the sizeof(long) on the possible target platform
 * which will be compiling the code generated by asn1c, let's play it
 * simple: long's range is equal to or greater than int32_t.
 * NOTE: the most negative integer cannot be written in C, as the C99
 * standard will give it an unsigned type.
 * It is defined here as a constant expression.
 */
#define	RIGHTMAX	2147483647	/* of 32-bit integer type */
#define	LEFTMIN		(-RIGHTMAX-1)	/* of 32-bit integer type */

	/* Descend to the terminal type */
	expr = asn1f_find_terminal_type_ex(arg->asn, expr);
	if(expr == 0) return FL_NOTFIT;

	/* The "fits into long" operation is relevant only for integer types */
	switch(expr->expr_type) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		break;
	default:
		return FL_NOTFIT;
	}

	/*
	 * First, evaluate the range of explicitly given identifiers.
	 */
	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type != A1TC_UNIVERVAL)
			continue;
		if(v->value->value.v_integer < LEFTMIN
		|| v->value->value.v_integer > RIGHTMAX)
			return FL_NOTFIT;
	}

	if(!expr->combined_constraints) 
		return (arg->flags & A1C_USE_NATIVE_TYPES)
			? FL_FORCED : FL_NOTFIT;

	/*
	 * Second, if -fbless-SIZE is given, the (SIZE()) constraint may be
	 * applied (non-standard! but we can deal with this) to the type.
	 * Check the range.
	 */
	range = asn1constraint_compute_PER_range(expr->expr_type,
		expr->combined_constraints, ACT_CT_SIZE, 0, 0,
		CPR_simulate_fbless_SIZE);
	if(range) {
		if(!range->incompatible) {
			right = range->right;
			/* Use 4 instead of sizeof(long) is justified! */
			if(right.type == ARE_VALUE && right.value <= 4)
				return FL_FITSOK;
		}
		asn1constraint_range_free(range);
	}

	/*
	 * Third, pull up the PER visible range of the INTEGER.
	 */
	range = asn1constraint_compute_PER_range(expr->expr_type,
		expr->combined_constraints, ACT_EL_RANGE, 0, 0, 0);
	if(!range
	|| range->empty_constraint
	|| range->extensible
	|| range->incompatible
	|| range->not_PER_visible
	) {
		asn1constraint_range_free(range);
		return (arg->flags & A1C_USE_NATIVE_TYPES)
			? FL_FORCED : FL_NOTFIT;
	}

	left = range->left;
	right = range->right;
	asn1constraint_range_free(range);

	/* If some fixed value is outside of target range, not fit */
	if(left.type == ARE_VALUE
			&& (left.value < LEFTMIN || left.value > RIGHTMAX))
		return FL_NOTFIT;
	if(right.type == ARE_VALUE
			&& (right.value > RIGHTMAX || right.value < LEFTMIN))
		return FL_NOTFIT;

	/* If the range is open, fits only if -fnative-types is given */
	if(left.type != ARE_VALUE || right.type != ARE_VALUE) {
		return (arg->flags & A1C_USE_NATIVE_TYPES)
			? FL_FORCED : FL_NOTFIT;
	}

	return FL_FITSOK;
}

