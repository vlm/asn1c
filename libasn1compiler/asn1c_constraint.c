#include "asn1c_internal.h"
#include "asn1c_constraint.h"
#include "asn1c_misc.h"
#include "asn1c_out.h"
#include "asn1c_naming.h"

#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportables from libasn1fix */

static int asn1c_emit_constraint_tables(arg_t *arg, int got_size);
static int emit_alphabet_check_loop(arg_t *arg, asn1cnst_range_t *range);
static int emit_value_determination_code(arg_t *arg, asn1p_expr_type_e etype, asn1cnst_range_t *r_value);
static int emit_size_determination_code(arg_t *arg, asn1p_expr_type_e etype);
static asn1p_expr_type_e _find_terminal_type(arg_t *arg);
static abuf *emit_range_comparison_code(asn1cnst_range_t *range,
                                          const char *varname,
                                          asn1c_integer_t natural_start,
                                          asn1c_integer_t natural_stop);
static int native_long_sign(arg_t *arg, asn1cnst_range_t *r);	/* -1, 0, 1 */

static int
ulong_optimization(arg_t *arg, asn1p_expr_type_e etype, asn1cnst_range_t *r_size,
						asn1cnst_range_t *r_value)
{
	return (!r_size && r_value
		&& (etype == ASN_BASIC_INTEGER
		|| etype == ASN_BASIC_ENUMERATED)
		&& native_long_sign(arg, r_value) == 0);
}

int
asn1c_emit_constraint_checking_code(arg_t *arg) {
	asn1cnst_range_t *r_size;
	asn1cnst_range_t *r_value;
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_type_e etype;
	asn1p_constraint_t *ct;
	int alphabet_table_compiled;
	int produce_st = 0;
	int ulong_optimize = 0;
	int value_unsigned = 0;
	int ret = 0;

	ct = expr->combined_constraints;
	if(ct == NULL)
		return 1;	/* No additional constraints defined */

	etype = _find_terminal_type(arg);

	r_value=asn1constraint_compute_constraint_range(expr->Identifier, etype, ct, ACT_EL_RANGE,0,0,0);
	r_size =asn1constraint_compute_constraint_range(expr->Identifier, etype, ct, ACT_CT_SIZE, 0,0,0);
	if(r_value) {
		if(r_value->incompatible
		|| r_value->empty_constraint
		|| (r_value->left.type == ARE_MIN
			&& r_value->right.type == ARE_MAX)
		|| (etype == ASN_BASIC_BOOLEAN
			&& r_value->left.value == 0
			&& r_value->right.value == 1)
		) {
			asn1constraint_range_free(r_value);
			r_value = 0;
		}
	}
	if(r_size) {
		if(r_size->incompatible
		|| r_size->empty_constraint
		|| (r_size->left.value == 0	/* or .type == MIN */
			&& r_size->right.type == ARE_MAX)
		) {
			asn1constraint_range_free(r_size);
			r_size = 0;
		}
	}

	/*
	 * Do we really need an "*st = sptr" pointer?
	 */
	switch(etype) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		if(asn1c_type_fits_long(arg, arg->expr) == FL_NOTFIT)
			produce_st = 1;
		break;
	case ASN_BASIC_REAL:
        if((arg->flags & A1C_USE_WIDE_TYPES)
           && asn1c_REAL_fits(arg, arg->expr) == RL_NOTFIT)
            produce_st = 1;
		break;
	case ASN_BASIC_BIT_STRING:
	case ASN_BASIC_OCTET_STRING:
		produce_st = 1;
		break;
	default:
		if(etype & ASN_STRING_MASK)
			produce_st = 1;
		break;
	}
	if(produce_st) {
		const char *tname = asn1c_type_name(arg, arg->expr, TNF_SAFE);
		OUT("const %s_t *st = (const %s_t *)sptr;\n", tname, tname);
	}

	if(r_size || r_value) {
		if(r_size) {
			OUT("size_t size;\n");
		}
		if(r_value)
			switch(etype) {
			case ASN_BASIC_INTEGER:
			case ASN_BASIC_ENUMERATED:
				if(native_long_sign(arg, r_value) >= 0) {
					ulong_optimize = ulong_optimization(arg, etype, r_size, r_value);
					if(!ulong_optimize) {
						value_unsigned = 1;
						OUT("unsigned long value;\n");
					}
				} else {
					OUT("long value;\n");
				}
				break;
			case ASN_BASIC_REAL:
				OUT("%s value;\n", c_name(arg).type.constrained_c_name);
				break;
			case ASN_BASIC_BOOLEAN:
				OUT("BOOLEAN_t value;\n");
				break;
			default:
				break;
		}
	}

	OUT("\n");

	/*
	 * Protection against null input.
	 */
	OUT("if(!sptr) {\n");
		INDENT(+1);
		OUT("ASN__CTFAIL(app_key, td, sptr,\n");
		OUT("\t\"%%s: value not given (%%s:%%d)\",\n");
		OUT("\ttd->name, __FILE__, __LINE__);\n");
		OUT("return -1;\n");
		INDENT(-1);
	OUT("}\n");
	OUT("\n");

	if((r_value) && (!ulong_optimize))
		emit_value_determination_code(arg, etype, r_value);
	if(r_size)
		emit_size_determination_code(arg, etype);

	INDENT(-1);
	REDIR(OT_CTABLES);
	/* Emit FROM() tables */
	alphabet_table_compiled =
		(asn1c_emit_constraint_tables(arg, r_size?1:0) == 1);
	REDIR(OT_CODE);
	INDENT(+1);

	/*
	 * Optimization for unsigned longs.
	 */
	if(ulong_optimize) {
		OUT("\n");
		OUT("/* Constraint check succeeded */\n");
		OUT("return 0;\n");
		goto end;
	}

	/*
	 * Here is an if() {} else {} consrtaint checking code.
	 */
	int got_something = 0;
    int value_unused = 0;
	OUT("\n");
	OUT("if(");
	INDENT(+1);
		if(r_size) {
            abuf *ab = emit_range_comparison_code(r_size, "size", 0, -1);
            if(ab->length)  {
                OUT("(%s)", ab->buffer);
                got_something++;
            }
            abuf_free(ab);
		}
		if(r_value) {
			if(got_something) { OUT("\n"); OUT(" && "); }
            abuf *ab;
            if(etype == ASN_BASIC_BOOLEAN)
                ab = emit_range_comparison_code(r_value, "value", 0, 1);
            else
                ab = emit_range_comparison_code(r_value, "value",
                                                value_unsigned ? 0 : -1, -1);
            if(ab->length)  {
                OUT("(%s)", ab->buffer);
                got_something++;
            } else {
                value_unused = 1;
            }
            abuf_free(ab);
		}
		if(alphabet_table_compiled) {
			if(got_something) { OUT("\n"); OUT(" && "); }
			OUT("!check_permitted_alphabet_%d(%s)",
				arg->expr->_type_unique_index,
				produce_st ? "st" : "sptr");
            got_something++;
        }
		if(!got_something) {
			OUT("1 /* No applicable constraints whatsoever */");
			OUT(") {\n");
			INDENT(-1);
			if(produce_st) {
				INDENTED(OUT("(void)st; /* Unused variable */\n"));
			}
			if(value_unused) {
				INDENTED(OUT("(void)value; /* Unused variable */\n"));
			}
			INDENTED(OUT("/* Nothing is here. See below */\n"));
			OUT("}\n");
			OUT("\n");
			ret = 1;
			goto end;
		}
	INDENT(-1);
	OUT(") {\n");
		INDENT(+1);
		switch(etype) {
		case ASN_CONSTR_SEQUENCE_OF:
			OUT("/* Perform validation of the inner elements */\n");
			OUT("return SEQUENCE_OF_constraint(td, sptr, ctfailcb, app_key);\n");
			break;
		case ASN_CONSTR_SET_OF:
			OUT("/* Perform validation of the inner elements */\n");
			OUT("return SET_OF_constraint(td, sptr, ctfailcb, app_key);\n");
			break;
		default:
			OUT("/* Constraint check succeeded */\n");
			OUT("return 0;\n");
		}
		INDENT(-1);
	OUT("} else {\n");
		INDENT(+1);
			OUT("ASN__CTFAIL(app_key, td, sptr,\n");
			OUT("\t\"%%s: constraint failed (%%s:%%d)\",\n");
			OUT("\ttd->name, __FILE__, __LINE__);\n");
			OUT("return -1;\n");
		INDENT(-1);
	OUT("}\n");

end:
	if (r_value) asn1constraint_range_free(r_value);
	if (r_size) asn1constraint_range_free(r_size);

	return ret;
}

static int
asn1c_emit_constraint_tables(arg_t *arg, int got_size) {
	asn1c_integer_t range_start;
	asn1c_integer_t range_stop;
	asn1p_expr_type_e etype;
	asn1cnst_range_t *range;
	asn1p_constraint_t *ct;
	int utf8_full_alphabet_check = 0;
	int max_table_size = 256;
	int table[256];
	int use_table;

	ct = arg->expr->combined_constraints;
	if(!ct) return 0;

	etype = _find_terminal_type(arg);

	range = asn1constraint_compute_constraint_range(arg->expr->Identifier, etype, ct, ACT_CT_FROM, 0,0,0);
	if(!range) return 0;

	if(range->incompatible
	|| range->empty_constraint) {
		asn1constraint_range_free(range);
		return 0;
	}

	if(range->left.type == ARE_MIN
	&& range->right.type == ARE_MAX) {
		/*
		 * The permitted alphabet constraint checker code guarantees
		 * that either both bounds (left/right) are present, or
		 * they're absent simultaneously. Thus, this assertion
		 * legitimately holds true.
		 */
		assert(range->el_count == 0);
		/* The full range is specified. Ignore it. */
		asn1constraint_range_free(range);
		return 0;
	}

	range_start = range->left.value;
	range_stop = range->right.value;
	assert(range->left.type == ARE_VALUE);
	assert(range->right.type == ARE_VALUE);
	assert(range_start <= range_stop);

	range_start = 0;	/* Force old behavior */

	/*
	 * Check if we need a test table to check the alphabet.
	 */
	use_table = 1;
	if(range->el_count == 0) {
		/*
		 * It's better to have a short if() check
		 * than waste 1k of table space
		 */
		use_table = 0;
	}
	if((range_stop - range_start) > 255)
		use_table = 0;
	if(etype == ASN_STRING_UTF8String) {
		if(range_stop >= 0x80)
			use_table = 0;
		else
			max_table_size = 128;
	}

	if(use_table) {
		int cardinal = 0;
		int i, n = 0;
		int untl;
		memset(table, 0, sizeof(table));
		for(i = -1; i < range->el_count; i++) {
			asn1cnst_range_t *r;
			asn1c_integer_t v;
			if(i == -1) {
				if(range->el_count) continue;
				r = range;
			} else {
				r = range->elements[i];
			}
			for(v = r->left.value; v <= r->right.value; v++) {
				assert((v - range_start) >= 0);
				assert((v - range_start) < max_table_size);
				table[v - range_start] = ++n;
			}
		}

		untl = (range_stop - range_start) + 1;
		untl += (untl % 16)?16 - (untl % 16):0;
		OUT("static const int permitted_alphabet_table_%d[%d] = {\n",
			arg->expr->_type_unique_index, max_table_size);
		for(n = 0; n < untl; n++) {
			cardinal += table[n] ? 1 : 0;
			OUT("%2d,", table[n]);
			if(!((n+1) % 16)) {
				int c;
				if(!n || (n-15) + range_start >= 0x80) {
					OUT("\n");
					continue;
				}
				OUT("\t/* ");
				for(c = n - 15; c <= n; c++) {
					if(table[c]) {
						int a = c + range_start;
						if(a > 0x20 && a < 0x80)
							OUT("%c", a);
						else
							OUT(".");
					} else {
						OUT(" ");
					}
				}
				OUT(" */");
				OUT("\n");
			}
		}
		OUT("};\n");

		if((arg->flags & A1C_GEN_PER)
		&& (etype & ASN_STRING_KM_MASK)) {
		    int c;
		    OUT("static const int permitted_alphabet_code2value_%d[%d] = {\n",
			arg->expr->_type_unique_index, cardinal);
		    for(n = c = 0; c < max_table_size; c++) {
			if(table[c]) {
				OUT("%d,", c);
				if(!((++n) % 16)) OUT("\n");
			}
		    }
		    OUT("};\n");
		    OUT("\n");
		    DEBUG("code2value map gen for %s", arg->expr->Identifier);
		    arg->expr->_mark |= TM_PERFROMCT;
		}

		OUT("\n");
	} else if(etype == ASN_STRING_UTF8String) {
		/*
		 * UTF8String type is a special case in many respects.
		 */
		if(got_size) {
			/*
			 * Size has been already determined.
			 * The UTF8String length checker also checks
			 * for the syntax validity, so we don't have
			 * to repeat this process twice.
			 */
			asn1constraint_range_free(range);
			return 0;
		} else {
			utf8_full_alphabet_check = 1;
		}
	} else {
		/*
		 * This permitted alphabet check will be
		 * expressed using conditional statements
		 * instead of table lookups. Table would be
		 * to large or otherwise inappropriate (too sparse?).
		 */
	}

	OUT("static int check_permitted_alphabet_%d(const void *sptr) {\n",
			arg->expr->_type_unique_index);
	INDENT(+1);
	if(utf8_full_alphabet_check) {
		OUT("if(UTF8String_length((const UTF8String_t *)sptr) < 0)\n");
		OUT("\treturn -1; /* Alphabet (sic!) test failed. */\n");
		OUT("\n");
	} else {
		if(use_table) {
			OUT("const int *table = permitted_alphabet_table_%d;\n",
				arg->expr->_type_unique_index);
			emit_alphabet_check_loop(arg, 0);
		} else {
			emit_alphabet_check_loop(arg, range);
		}
	}
	OUT("return 0;\n");
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	asn1constraint_range_free(range);

	return 1;
}

static int
emit_alphabet_check_loop(arg_t *arg, asn1cnst_range_t *range) {
	asn1c_integer_t natural_stop;
	asn1p_expr_t *terminal;
	const char *tname;

	terminal = asn1f_find_terminal_type_ex(arg->asn, arg->ns, arg->expr);
	if(terminal) {
		OUT("/* The underlying type is %s */\n",
			ASN_EXPR_TYPE2STR(terminal->expr_type));
	} else {
		terminal = arg->expr;
	}
	tname = asn1c_type_name(arg, terminal, TNF_SAFE);
	OUT("const %s_t *st = (const %s_t *)sptr;\n", tname, tname);

	switch(terminal->expr_type) {
	case ASN_STRING_UTF8String:
		OUT("const uint8_t *ch = st->buf;\n");
		OUT("const uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint8_t cv = *ch;\n");
			if(!range) OUT("if(cv >= 0x80) return -1;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_UniversalString:
		OUT("const uint8_t *ch = st->buf;\n");
		OUT("const uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size %% 4) return -1; /* (size%%4)! */\n");
		OUT("for(; ch < end; ch += 4) {\n");
			INDENT(+1);
			OUT("uint32_t cv = (ch[0] << 24)\n");
			OUT("\t\t| (ch[1] << 16)\n");
			OUT("\t\t| (ch[2] << 8)\n");
			OUT("\t\t|  ch[3];\n");
			if(!range) OUT("if(cv > 255) return -1;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_BMPString:
		OUT("const uint8_t *ch = st->buf;\n");
		OUT("const uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size %% 2) return -1; /* (size%%2)! */\n");
		OUT("for(; ch < end; ch += 2) {\n");
			INDENT(+1);
			OUT("uint16_t cv = (ch[0] << 8)\n");
			OUT("\t\t| ch[1];\n");
			if(!range) OUT("if(cv > 255) return -1;\n");
		natural_stop = 0xffff;
		break;
	case ASN_BASIC_OCTET_STRING:
	default:
		OUT("const uint8_t *ch = st->buf;\n");
		OUT("const uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint8_t cv = *ch;\n");
		natural_stop = 0xff;
		break;
	}

	if(range) {
        abuf *ab = emit_range_comparison_code(range, "cv", 0, natural_stop);
        if(ab->length) {
            OUT("if(!(%s)) return -1;\n", ab->buffer);
        } else {
            OUT("(void)cv; /* Unused variable */\n");
        }
	} else {
		OUT("if(!table[cv]) return -1;\n");
	}

	INDENT(-1);
	OUT("}\n");

	return 0;
}

static void
abuf_oint(abuf *ab, asn1c_integer_t v) {
    if(v == (-2147483647L - 1)) {
        abuf_printf(ab, "(-2147483647L - 1)");
    } else {
        abuf_printf(ab, "%s", asn1p_itoa(v));
    }
}

static abuf *
emit_range_comparison_code(asn1cnst_range_t *range, const char *varname,
                           asn1c_integer_t natural_start,
                           asn1c_integer_t natural_stop) {
    abuf *ab = abuf_new();

    if(range->el_count == 0) {
        int ignore_left =
            (range->left.type == ARE_MIN)
            || (natural_start != -1 && range->left.value <= natural_start);
        int ignore_right =
            (range->right.type == ARE_MAX)
            || (natural_stop != -1 && range->right.value >= natural_stop);

        if(ignore_left && ignore_right) {
            /* Empty constraint comparison */
        } else if(ignore_left) {
            abuf_printf(ab, "%s <= ", varname);
            abuf_oint(ab, range->right.value);
        } else if(ignore_right) {
            abuf_printf(ab, "%s >= ", varname);
            abuf_oint(ab, range->left.value);
        } else if(range->left.value == range->right.value) {
            abuf_printf(ab, "%s == ", varname);
            abuf_oint(ab, range->right.value);
        } else {
            abuf_printf(ab, "%s >= ", varname);
            abuf_oint(ab, range->left.value);
            abuf_printf(ab, " && ");
            abuf_printf(ab, "%s <= ", varname);
            abuf_oint(ab, range->right.value);
        }
    } else {
        for(int i = 0; i < range->el_count; i++) {
            asn1cnst_range_t *r = range->elements[i];

            abuf *rec = emit_range_comparison_code(r, varname, natural_start,
                                                   natural_stop);
            if(rec->length) {
                if(ab->length) {
                    abuf_str(ab, " || ");
                }
                abuf_str(ab, "(");
                abuf_buf(ab, rec);
                abuf_str(ab, ")");
            } else {
                /* Ignore this part */
            }
            abuf_free(rec);
        }
    }

    return ab;
}

static int
emit_size_determination_code(arg_t *arg, asn1p_expr_type_e etype) {

	switch(etype) {
	case ASN_BASIC_BIT_STRING:
		OUT("if(st->size > 0) {\n");
		OUT("\t/* Size in bits */\n");
		OUT("\tsize = 8 * st->size - (st->bits_unused & 0x07);\n");
		OUT("} else {\n");
		OUT("\tsize = 0;\n");
		OUT("}\n");
		break;
	case ASN_STRING_UniversalString:
		OUT("size = st->size >> 2;\t/* 4 byte per character */\n");
		break;
	case ASN_STRING_BMPString:
		OUT("size = st->size >> 1;\t/* 2 byte per character */\n");
		break;
	case ASN_STRING_UTF8String:
		OUT("size = UTF8String_length(st);\n");
		OUT("if((ssize_t)size < 0) {\n");
		OUT("\tASN__CTFAIL(app_key, td, sptr,\n");
		OUT("\t\t\"%%s: UTF-8: broken encoding (%%s:%%d)\",\n");
		OUT("\t\ttd->name, __FILE__, __LINE__);\n");
		OUT("\treturn -1;\n");
		OUT("}\n");
		break;
	case ASN_CONSTR_SET_OF:
	case ASN_CONSTR_SEQUENCE_OF:
		OUT("/* Determine the number of elements */\n");
		OUT("size = _A_C%s_FROM_VOID(sptr)->count;\n",
			etype==ASN_CONSTR_SET_OF?"SET":"SEQUENCE");
		break;
	case ASN_BASIC_OCTET_STRING:
		OUT("size = st->size;\n");
		break;
	default:
		if(etype & ASN_STRING_MASK) {
			OUT("size = st->size;\n");
			break;
		} else {
			const char *type_name = ASN_EXPR_TYPE2STR(etype);
			if(!type_name) type_name = arg->expr->Identifier;
			WARNING("SizeConstraint is not defined for %s",
				type_name);
			OUT_NOINDENT("#warning SizeConstraint "
				"is not defined for %s!\n", type_name);
			OUT("size = st->size;\n");
		}
		return -1;
	}

	return 0;
}

static int
emit_value_determination_code(arg_t *arg, asn1p_expr_type_e etype, asn1cnst_range_t *r_value) {

	switch(etype) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		if(asn1c_type_fits_long(arg, arg->expr) == FL_FITS_UNSIGN) {
			OUT("value = *(const unsigned long *)sptr;\n");
		} else if(asn1c_type_fits_long(arg, arg->expr) != FL_NOTFIT) {
			OUT("value = *(const long *)sptr;\n");
		} else {
			/*
			 * In some cases we can explore our knowledge of
			 * underlying INTEGER_t->buf format.
			 */
			if(r_value->el_count == 0
			&& (
				/* Speed-up common case: (0..MAX) */
				(r_value->left.type == ARE_VALUE
				&& r_value->left.value == 0
				&& r_value->right.type == ARE_MAX)
			    ||
				/* Speed-up common case: (MIN..-1) */
				(r_value->left.type == ARE_MIN
				&& r_value->right.type == ARE_VALUE
				&& r_value->right.value == -1)
			)) {
				OUT("/* Check if the sign bit is present */\n");
				OUT("value = st->buf ? ((st->buf[0] & 0x80) ? -1 : 1) : 0;\n");
				break;
			}

			if(native_long_sign(arg, r_value) >= 0) {
				/* Special case for treating unsigned longs */
				OUT("if(asn_INTEGER2ulong(st, &value)) {\n");
				INDENT(+1);
				OUT("ASN__CTFAIL(app_key, td, sptr,\n");
				OUT("\t\"%%s: value too large (%%s:%%d)\",\n");
				OUT("\ttd->name, __FILE__, __LINE__);\n");
				OUT("return -1;\n");
				INDENT(-1);
				OUT("}\n");
			} else {
				OUT("if(asn_INTEGER2long(st, &value)) {\n");
				INDENT(+1);
				OUT("ASN__CTFAIL(app_key, td, sptr,\n");
				OUT("\t\"%%s: value too large (%%s:%%d)\",\n");
				OUT("\ttd->name, __FILE__, __LINE__);\n");
				OUT("return -1;\n");
				INDENT(-1);
				OUT("}\n");
			}
		}
		break;
	case ASN_BASIC_REAL:
		if(arg->flags & A1C_USE_WIDE_TYPES) {
			OUT("if(asn_REAL2double(st, &value)) {\n");
				INDENT(+1);
				OUT("ASN__CTFAIL(app_key, td, sptr,\n");
				OUT("\t\"%%s: value too large (%%s:%%d)\",\n");
				OUT("\ttd->name, __FILE__, __LINE__);\n");
				OUT("return -1;\n");
				INDENT(-1);
			OUT("}\n");
		} else {
			OUT("value = *(const %s *)sptr;\n", c_name(arg).type.c_name);
		}
		break;
	case ASN_BASIC_BOOLEAN:
		OUT("value = (*(const long *)sptr) ? 1 : 0;\n");
		break;
	default:
		WARNING("%s:%d: Value cannot be determined "
			"for constraint check for %s",
			arg->expr->module->source_file_name,
			arg->expr->_lineno,
			arg->expr->Identifier
		);
		OUT_NOINDENT(
			"#error %s:%d: Value of %s cannot be determined\n",
			arg->expr->module->source_file_name,
			arg->expr->_lineno,
			arg->expr->Identifier
		);
		break;
	}

	return 0;
}

static asn1p_expr_type_e
_find_terminal_type(arg_t *arg) {
	asn1p_expr_t *expr;
	expr = asn1f_find_terminal_type_ex(arg->asn, arg->ns, arg->expr);
	if(expr) return expr->expr_type;
	return A1TC_INVALID;
}

static int
native_long_sign(arg_t *arg, asn1cnst_range_t *r) {
    if(!(arg->flags & A1C_USE_WIDE_TYPES) && r->left.type == ARE_VALUE
       && r->left.value >= 0 && r->left.value <= 2147483647
        && r->right.type == ARE_MAX) {
        return 1;
    }
	if(r->left.type == ARE_VALUE
	&& r->left.value >= 0
	&& r->right.type == ARE_VALUE
	&& r->right.value > 2147483647
	&& r->right.value <= (asn1c_integer_t)(4294967295UL)) {
		if(r->el_count == 0
		&& r->left.value == 0
		&& r->right.value == 4294967295UL)
			return 0;
		else
			return 1;
	} else {
		return -1;
	}
}
