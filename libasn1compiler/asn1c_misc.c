#include "asn1c_internal.h"
#include "asn1c_misc.h"

#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportable stuff from libasn1fix */

/*
 * Checks that the given string is not a reserved C/C++ keyword [1],[2].
 * _* keywords not included, since asn1 identifiers cannot begin with hyphen [3]
 * [1] ISO/IEC 9899:2011 (C11), 6.4.1
 * [2] ISO/IEC 14882:2014 (C++14), 2.12
 * [3] ISO/IEC 8824-1:2003 (asn1) 11.3
 */
static char *res_kwd[] = {
		/* C */
	"auto", "break", "case", "char", "const", "continue", "default", "do",
	"double", "else", "enum", "extern", "float", "for", "goto", "if",
	"inline", "int", "long", "register", "restrict", "return", "short",
	"signed", "sizeof", "static", "struct", "switch", "typedef", "union",
	"unsigned", "void", "volatile", "while",
		/* C++ */
	"alignas", "alignof", "and", "and_eq", "asm", "bitand", "bitor", "bool",
	"catch", "char16_t", "char32_t", "class", "compl", "const_cast",
	"constexpr", "decltype", "delete", "delete", "dynamic_cast",
	"explicit", "export", "false", "friend", "mutable", "namespace", "new",
	"noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq",
	"private", "protected", "public", "reinterpret_cast", "static_assert",
	"static_cast", "template", "this", "thread_local", "throw", "true", "try",
	"typeid", "typename", "using", "virtual", "wchar_t", "xor", "xor_eq"
};
static int
reserved_keyword(const char *str) {
	size_t i;
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
const char *
asn1c_make_identifier(enum ami_flags_e flags, asn1p_expr_t *expr, ...) {
	static char *storage;
	static int storage_size;
	int nodelimiter = 0;
	va_list ap;
	char *str;
	char *nextstr;
	char *first = 0;
	ssize_t size = 0;
	char *p;
	char *prefix = NULL;
	char *sptr[4], **psptr = &sptr[0];
	int sptr_cnt = 0;

	if(expr) {
		/*
		 * Estimate the necessary storage size
		 */
		if(expr->Identifier == NULL)
			return "Member";
		/*
		 * Add MODULE name to resolve clash
		 */
		if(expr->_mark & TM_NAMECLASH) {
			size += strlen(expr->module->ModuleName) + 2;
			sptr[sptr_cnt++] = expr->module->ModuleName;
		}
		sptr[sptr_cnt++] = expr->Identifier;

		size += strlen(expr->Identifier);
		if(expr->spec_index != -1) {
			static char buf[32];
			size += 1 + snprintf(buf, sizeof buf, "%dP%d",
				expr->_lineno, expr->spec_index);
			sptr[sptr_cnt++] = (char *)&buf;
		}
	} else {
		size = -1;
	}
	sptr[sptr_cnt++] = (char *)0;

	va_start(ap, expr);
	while((str = va_arg(ap, char *)))
		size += 1 + strlen(str);
	va_end(ap);
	if(size == -1) return NULL;

	if(prefix)
		size += 1 + strlen(prefix);
	/*
	 * Make sure we have the required amount of storage.
	 */
	if(storage_size <= size) {
        char *tmp = malloc(size + 1);
        if(tmp) {
            free(storage);
            storage = tmp;
            storage_size = size + 1;
        } else {
            return NULL;
        }
	}

	/*
	 * Fill-in the storage.
	 */
	va_start(ap, expr);
	p = storage;
	if(prefix) {
		strcpy(storage, prefix);
		p += strlen(prefix);
	}
	nextstr = "";
	for(str = 0; str || nextstr; str = nextstr) {
		int subst_made = 0;
		nextstr = *(psptr) ? *(psptr++) : va_arg(ap, char *);

		if(str == 0) {
			str = first = nextstr;
			nextstr = *(psptr) ? *(psptr++) : va_arg(ap, char *);
			if (!first) continue;
		}

		if(str[0] == ' ' && str[1] == '\0') {
			*p++ = ' ';
			nodelimiter = 1;	/* No delimiter */
			continue;
		}

		if(str != first && !nodelimiter && !(flags & AMI_NODELIMITER))
			*p++ = '_';	/* Delimiter between tokens */
		nodelimiter = 0;

		/*
		 * If it is a single argument, check that it does not clash
		 * with C/C++ language keywords.
		 */
		if((flags & AMI_CHECK_RESERVED)
		&& str == first && !nextstr && reserved_keyword(str)) {
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

const char *
asn1c_type_name(arg_t *arg, asn1p_expr_t *expr, enum tnfmt _format) {
	asn1p_expr_t *exprid = 0;
	asn1p_expr_t *top_parent;
	asn1p_expr_t *terminal = 0;
	int stdname = 0;
	const char *typename;

	/* Rewind to the topmost parent expression */
	if((top_parent = expr->parent_expr))
		while(top_parent->parent_expr)
			top_parent = top_parent->parent_expr;

	if(0) DEBUG("asn1c_type_name(%s: 0x%x)",
		expr->Identifier, expr->expr_type);

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
            tmp.expr = WITH_MODULE_NAMESPACE(
                arg->expr->module, expr_ns,
                asn1f_class_access_ex(arg->asn, arg->expr->module, expr_ns,
                                      arg->expr, expr->rhs_pspecs,
                                      expr->reference));
            if(!tmp.expr) return NULL;

			return asn1c_type_name(&tmp, tmp.expr, _format);
		}

        terminal = WITH_MODULE_NAMESPACE(
            expr->module, expr_ns,
            (expr->meta_type == AMT_TYPEREF) ? 
                asn1f_lookup_symbol_ex(arg->asn, expr_ns, expr, expr->reference) :
                asn1f_find_terminal_type_ex(arg->asn, expr_ns, expr));

        if(_format == TNF_RSAFE) {
			if(terminal && terminal->expr_type & ASN_CONSTR_MASK) {
				typename = terminal->Identifier;
			}
		}

		if(_format == TNF_CTYPE || _format == TNF_CONSTYPE) {
			/*
			 * If the component references the type itself,
			 * switch to a recursion-safe type naming
			 * ("struct foo" instead of "foo_t").
			 */
			if(terminal && terminal == top_parent) {
				_format = TNF_RSAFE;
			}
		}

		if(_format != TNF_RSAFE  && terminal && ((terminal->spec_index != -1) || (terminal->_mark & TM_NAMECLASH))) {
			exprid = terminal;
			typename = 0;
		}

		break;
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
	case ASN_BASIC_REAL:
        if((expr->expr_type == ASN_BASIC_REAL
            && (_format == TNF_CONSTYPE || !(arg->flags & A1C_USE_WIDE_TYPES)
                || asn1c_REAL_fits(arg, expr) != RL_NOTFIT))
           || asn1c_type_fits_long(arg, expr)) {
            switch(_format) {
			case TNF_CONSTYPE:
				if(expr->expr_type == ASN_BASIC_REAL) {
                    return "double";
                } else if(asn1c_type_fits_long(arg, expr) == FL_FITS_UNSIGN) {
                    return "unsigned long";
                } else {
                    return "long";
                }
            case TNF_CTYPE:
            case TNF_RSAFE:
                if(expr->expr_type == ASN_BASIC_REAL) {
                    asn1cnst_range_t *range = asn1constraint_compute_OER_range(
                        expr->Identifier, ASN_BASIC_REAL,
                        expr->combined_constraints, ACT_EL_RANGE, 0, 0, 0);
                    if(range->narrowing == NARROW_FLOAT32) {
                        asn1constraint_range_free(range);
                        return "float";
                    } else {
                        asn1constraint_range_free(range);
                        return "double";
                    }
                } else if(asn1c_type_fits_long(arg, expr) == FL_FITS_UNSIGN) {
                    return "unsigned long";
                } else {
                    return "long";
                }
            default:
				typename = 0;
				switch(expr->expr_type) {
				case ASN_BASIC_INTEGER:
					typename = "NativeInteger"; break;
				case ASN_BASIC_ENUMERATED:
					typename = "NativeEnumerated"; break;
				case ASN_BASIC_REAL:
					typename = "NativeReal"; break;
				default:
					break;
				}
				break;
			}
			if(typename) {
				if(_format != TNF_INCLUDE)
					return typename;
				stdname = 1;
				break;
			}
		}
		/* Fall through */
	default:
		if(expr->expr_type
		& (ASN_CONSTR_MASK | ASN_BASIC_MASK | ASN_STRING_MASK)) {
			if(_format == TNF_RSAFE)
				_format = TNF_CTYPE;
			stdname = 1;
			typename = ASN_EXPR_TYPE2STR(expr->expr_type);
		} else {
			_format = TNF_RSAFE;
			typename = expr->Identifier;
		}
	}

	switch(_format) {
	case TNF_UNMODIFIED:
		return asn1c_make_identifier(AMI_MASK_ONLY_SPACES | AMI_NODELIMITER,
			0, MODULE_NAME_OF(exprid), exprid ? exprid->Identifier : typename, (char*)0);
	case TNF_INCLUDE:
		return asn1c_make_identifier(
			AMI_MASK_ONLY_SPACES | AMI_NODELIMITER,
			0, ((!stdname || (arg->flags & A1C_INCLUDES_QUOTED))
				? "\"" : "<"),
			MODULE_NAME_OF(exprid),
			exprid ? exprid->Identifier : typename,
			((!stdname || (arg->flags & A1C_INCLUDES_QUOTED))
				? ".h\"" : ".h>"), (char*)0);
	case TNF_SAFE:
		return asn1c_make_identifier(0, exprid, typename, (char*)0);
	case TNF_CTYPE:	/* C type */
	case TNF_CONSTYPE:	/* C type */
		return asn1c_make_identifier(0, exprid,
				exprid?"t":typename, exprid?0:"t", (char*)0);
	case TNF_RSAFE:	/* Recursion-safe type */
		return asn1c_make_identifier(AMI_CHECK_RESERVED | AMI_NODELIMITER, 0,
			"struct", " ", MODULE_NAME_OF(exprid), typename, (char*)0);
	}

	assert(!"unreachable");
	return typename;
}

static asn1p_expr_type_e
expr_get_type(arg_t *arg, asn1p_expr_t *expr) {
        asn1p_expr_t *terminal;
        terminal = asn1f_find_terminal_type_ex(arg->asn, arg->ns, expr);
        if(terminal) return terminal->expr_type;
        return A1TC_INVALID;
}

enum asn1c_fitsfloat_e
asn1c_REAL_fits(arg_t *arg, asn1p_expr_t *expr) {
    asn1p_expr_type_e etype = expr_get_type(arg, arg->expr);
    if(etype == ASN_BASIC_REAL) {
        asn1cnst_range_t *range = asn1constraint_compute_OER_range(
            expr->Identifier, etype, expr->combined_constraints, ACT_EL_RANGE,
            0, 0, 0);
        enum asn1c_fitsfloat_e fits;
        switch(range->narrowing) {
        case NARROW_FLOAT32:
            fits = RL_FITS_FLOAT32;
            break;
        case NARROW_DOUBLE64:
            fits = RL_FITS_DOUBLE64;
            break;
        default:
            fits = RL_NOTFIT;
            break;
        }
        asn1constraint_range_free(range);
        return fits;
    } else {
        return 0;
    }
}

/*
 * Check whether the specified INTEGER or ENUMERATED type can be represented
 * using the generic 'long' or 'unsigned long' type.
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
    expr = WITH_MODULE_NAMESPACE(
        expr->module, expr_ns,
        asn1f_find_terminal_type_ex(arg->asn, expr_ns, expr));
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
		return (arg->flags & A1C_USE_WIDE_TYPES)
			? FL_NOTFIT : FL_PRESUMED;

	/*
	 * Second, if -fbless-SIZE is given, the (SIZE()) constraint may be
	 * applied (non-standard! but we can deal with this) to the type.
	 * Check the range.
	 */
	range = asn1constraint_compute_constraint_range(expr->Identifier,
		expr->expr_type,
		expr->combined_constraints, ACT_CT_SIZE, 0, 0,
		CPR_simulate_fbless_SIZE);
	if(range) {
		if(!range->incompatible) {
			right = range->right;
			/* Use 4 instead of sizeof(long) is justified! */
			if(right.type == ARE_VALUE && right.value <= 4)
				return FL_FITS_SIGNED;
		}
		asn1constraint_range_free(range);
	}

	/*
	 * Third, pull up the PER visible range of the INTEGER.
	 */
	range = asn1constraint_compute_PER_range(expr->Identifier, expr->expr_type,
		expr->combined_constraints, ACT_EL_RANGE, 0, 0, 0);

	if(!range
	/* Commenting out
    || range->extensible
     * because this may or may not indicate wide type.
     */
    || (range->extensible && (arg->flags & A1C_USE_WIDE_TYPES))
	|| range->empty_constraint
	|| range->incompatible
	|| range->not_PER_visible
	) {
		asn1constraint_range_free(range);
		return (arg->flags & A1C_USE_WIDE_TYPES)
			? FL_NOTFIT : FL_PRESUMED;
	}

	left = range->left;
	right = range->right;
	asn1constraint_range_free(range);

	/* Special case for unsigned */
    if(!(arg->flags & A1C_USE_WIDE_TYPES) && left.type == ARE_VALUE
       && left.value >= 0 && left.value <= 2147483647
       && right.type == ARE_MAX) {
        return FL_FITS_UNSIGN;
    }
    if(left.type == ARE_VALUE
		&& left.value >= 0
	&& right.type == ARE_VALUE
		&& right.value > 2147483647
		&& right.value <= (asn1c_integer_t)(4294967295UL))
		return FL_FITS_UNSIGN;
		

	/* If some fixed value is outside of target range, not fit */
	if(left.type == ARE_VALUE
			&& (left.value < LEFTMIN || left.value > RIGHTMAX))
		return FL_NOTFIT;
	if(right.type == ARE_VALUE
			&& (right.value > RIGHTMAX || right.value < LEFTMIN))
		return FL_NOTFIT;

	/* If the range is open, fits only unless -fwide-types is given */
	if(left.type != ARE_VALUE || right.type != ARE_VALUE) {
		return (arg->flags & A1C_USE_WIDE_TYPES)
			? FL_NOTFIT : FL_PRESUMED;
	}

	return FL_FITS_SIGNED;
}

