#include "asn1c_internal.h"
#include "asn1c_constraint.h"
#include "asn1c_misc.h"
#include "asn1c_out.h"

#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportable stuff from libasn1fix */

static int asn1c_emit_constraint_tables(arg_t *arg, int got_size);
static int emit_alphabet_check_loop(arg_t *arg, asn1cnst_range_t *range);
static int emit_value_determination_code(arg_t *arg, asn1p_expr_type_e etype);
static int emit_size_determination_code(arg_t *arg, asn1p_expr_type_e etype);
static asn1p_expr_type_e _find_terminal_type(arg_t *arg);
static int emit_range_comparison_code(arg_t *arg, asn1cnst_range_t *range, const char *varname, asn1_integer_t natural_start, asn1_integer_t natural_stop);

#define	MKID(id)	asn1c_make_identifier(0, (id), 0)

static int global_compile_mark;

int
asn1c_emit_constraint_checking_code(arg_t *arg) {
	asn1cnst_range_t *r_size;
	asn1cnst_range_t *r_value;
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_type_e etype;
	asn1p_constraint_t *ct;
	int got_something = 0;
	int produce_st = 0;

	ct = expr->combined_constraints;
	if(ct == NULL)
		return 1;	/* No additional constraints defined */

	etype = _find_terminal_type(arg);

	r_value=asn1constraint_compute_PER_range(etype, ct, ACT_EL_RANGE, 0, 0);
	r_size = asn1constraint_compute_PER_range(etype, ct, ACT_CT_SIZE, 0, 0);
	if(r_value) {
		if(r_value->not_PER_visible
		|| r_value->extensible
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
		if(r_size->not_PER_visible
		|| r_size->extensible
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
		if(!(arg->flags & A1C_USE_NATIVE_INTEGERS))
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
	if(produce_st)
	OUT("const %s_t *st = sptr;\n",
		asn1c_type_name(arg, arg->expr, TNF_SAFE));

	if(r_size || r_value) {
		if(r_size) {
			OUT("size_t size;\n");
		}
		if(r_value)
			switch(etype) {
			case ASN_BASIC_INTEGER:
			case ASN_BASIC_ENUMERATED:
				OUT("long value;\n");
				break;
			case ASN_BASIC_BOOLEAN:
				OUT("int value;\n");
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
		OUT("_ASN_ERRLOG(app_errlog, app_key,\n");
		OUT("\t\"%%s: value not given\", td->name);\n");
		OUT("return -1;\n");
		INDENT(-1);
	OUT("}\n");
	OUT("\n");

	if(r_value)
		emit_value_determination_code(arg, etype);
	if(r_size)
		emit_size_determination_code(arg, etype);

	INDENT(-1);
	REDIR(OT_CTABLES);
	/* Emit FROM() tables */
	asn1c_emit_constraint_tables(arg, r_size?1:0);
	REDIR(OT_CODE);
	INDENT(+1);

	/*
	 * Here is an if() {} else {} constaint checking code.
	 */
	OUT("\n");
	OUT("if(");
	INDENT(+1);
		if(r_size) {
			if(got_something++) { OUT("\n"); OUT(" && "); }
			OUT("(");
			emit_range_comparison_code(arg, r_size, "size", 0, -1);
			OUT(")");
		}
		if(r_value) {
			if(got_something++) { OUT("\n"); OUT(" && "); }
			OUT("(");
			if(etype == ASN_BASIC_BOOLEAN)
				emit_range_comparison_code(arg, r_value,
					"value", 0, 1);
			else
				emit_range_comparison_code(arg, r_value,
					"value", -1, -1);
			OUT(")");
		}
		if(ct->_compile_mark) {
			if(got_something++) { OUT("\n"); OUT(" && "); }
			OUT("check_permitted_alphabet_%d(sptr)",
				ct->_compile_mark);
		}
		if(!got_something) {
			OUT("1 /* No applicable constraints whatsoever */");
			OUT(") {\n");
			INDENT(-1);
			INDENTED(OUT("/* Nothing is here. See below */\n"));
			OUT("}\n");
			OUT("\n");
			return 1;
		}
	INDENT(-1);
	OUT(") {\n");
		INDENT(+1);
		OUT("/* Constraint check succeeded */\n");
		OUT("return 1;\n");
		INDENT(-1);
	OUT("} else {\n");
		INDENT(+1);
			OUT("_ASN_ERRLOG(app_errlog, app_key,\n");
			OUT("\t\"%%s: constraint failed\", td->name);\n");
			OUT("return -1;\n");
		INDENT(-1);
	OUT("}\n");

	return 0;
}

static int
asn1c_emit_constraint_tables(arg_t *arg, int got_size) {
	asn1_integer_t range_start;
	asn1_integer_t range_stop;
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

	range = asn1constraint_compute_PER_range(etype, ct, ACT_CT_FROM, 0, 0);
	if(!range) return 0;

	if(range->not_PER_visible
	|| range->extensible
	|| range->empty_constraint) {
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
		 * than waste 4k of table space
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

	if(!ct->_compile_mark)
		ct->_compile_mark = ++global_compile_mark;

	if(use_table) {
		int i, n = 0;
		int untl;
		memset(table, 0, sizeof(table));
		for(i = -1; i < range->el_count; i++) {
			asn1cnst_range_t *r;
			asn1_integer_t v;
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
		OUT("static int permitted_alphabet_table_%d[%d] = {\n",
			ct->_compile_mark, max_table_size);
		for(n = 0; n < untl; n++) {
			OUT("%d,", table[n]?1:0);
			if(!((n+1) % 16)) {
				int c;
				if(!n) {
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
		OUT("\n");
	} else if(etype == ASN_STRING_UTF8String) {
		/*
		 * UTF8String type is a special case in many respects.
		 */
		assert(range_stop > 255);	/* This one's unobvious */
		if(got_size) {
			/*
			 * Size has been already determined.
			 * The UTF8String length checker also checks
			 * for the syntax validity, so we don't have
			 * to repeat this process twice.
			 */
			ct->_compile_mark = 0;	/* Don't generate code */
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
			ct->_compile_mark);
	INDENT(+1);
	if(utf8_full_alphabet_check) {
		OUT("if(UTF8String_length((UTF8String_t *)sptr, td->name, \n");
		OUT("\tapp_errlog, app_key) == -1)\n");
		OUT("\t\treturn 0; /* Alphabet (sic!) test failed. */\n");
		OUT("\n");
	} else {
		if(use_table) {
			OUT("int *table = permitted_alphabet_table_%d;\n",
				ct->_compile_mark);
			emit_alphabet_check_loop(arg, 0);
		} else {
			emit_alphabet_check_loop(arg, range);
		}
	}
	OUT("return 1;\n");
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	asn1constraint_range_free(range);

	return 0;
}

static int
emit_alphabet_check_loop(arg_t *arg, asn1cnst_range_t *range) {
	asn1_integer_t natural_stop;
	asn1p_expr_t *terminal;

	terminal = asn1f_find_terminal_type_ex(arg->asn, arg->mod, arg->expr);
	if(terminal) {
		OUT("/* The underlying type is %s */\n",
			ASN_EXPR_TYPE2STR(terminal->expr_type));
	} else {
		terminal = arg->expr;
	}
	OUT("const %s_t *st = sptr;\n",
		asn1c_type_name(arg, terminal, TNF_SAFE));

	switch(terminal->expr_type) {
	case ASN_STRING_UTF8String:
		OUT("const uint8_t *ch = st->buf;\n");
		OUT("const uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint8_t cv = *ch;\n");
			if(!range) OUT("if(cv >= 0x80) return 0;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_UniversalString:
		OUT("const uint32_t *ch = st->buf;\n");
		OUT("const uint32_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size % 4) return 0; /* (size%4)! */\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint32_t cv = (((const uint8_t *)ch)[0] << 24)\n");
			OUT("\t\t| (((const uint8_t *)ch)[1] << 16)\n");
			OUT("\t\t| (((const uint8_t *)ch)[2] << 8)\n");
			OUT("\t\t|  ((const uint8_t *)ch)[3];\n");
			if(!range) OUT("if(cv > 255) return 0;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_BMPString:
		OUT("const uint16_t *ch = st->buf;\n");
		OUT("const uint16_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size % 2) return 0; /* (size%2)! */\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint16_t cv = (((const uint8_t *)ch)[0] << 8)\n");
			OUT("\t\t| ((const uint8_t *)ch)[1];\n");
			if(!range) OUT("if(cv > 255) return 0;\n");
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
		OUT("if(!(");
		emit_range_comparison_code(arg, range, "cv", 0, natural_stop);
		OUT(")) return 0;\n");
	} else {
		OUT("if(!table[cv]) return 0;\n");
	}

	INDENT(-1);
	OUT("}\n");

	return 0;
}

static int
emit_range_comparison_code(arg_t *arg, asn1cnst_range_t *range, const char *varname, asn1_integer_t natural_start, asn1_integer_t natural_stop) {
	int ignore_left;
	int ignore_right;
	int generated_something = 0;
	int i;

	for(i = -1; i < range->el_count; i++) {
		asn1cnst_range_t *r;
		if(i == -1) {
			if(range->el_count) continue;
			r = range;
		} else {
			if(i) OUT(" || ");
			r = range->elements[i];
		}

		if(r != range) OUT("(");

		ignore_left = (r->left.type == ARE_MIN)
				|| (natural_start != -1
					&& r->left.value <= natural_start);
		ignore_right = (r->right.type == ARE_MAX)
				|| (natural_stop != -1
					&& r->right.value >= natural_stop);
		if(ignore_left && ignore_right) {
			OUT("1 /* Constraint matches natural range of %s */",
				varname);
			continue;
		}

		if(ignore_left) {
			OUT("%s <= %lld", varname,
				(long long)r->right.value);
		} else if(ignore_right) {
			OUT("%s >= %lld", varname,
				(long long)r->left.value);
		} else if(r->left.value == r->right.value) {
			OUT("%s == %lld", varname,
				(long long)r->right.value);
		} else {
			OUT("%s >= %lld && %s <= %lld",
				varname,
				(long long)r->left.value,
				varname,
				(long long)r->right.value);
		}
		if(r != range) OUT(")");
		generated_something = 1;
	}

	return generated_something;
}

static int
emit_size_determination_code(arg_t *arg, asn1p_expr_type_e etype) {

	switch(etype) {
	case ASN_BASIC_BIT_STRING:
		OUT("if(st->size > 0) {\n");
		OUT("\t/* Size in bits */\n");
		OUT("\tsize = (st->size - 1) - (st->buf[0] & 0x7);\n");
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
		OUT("size = UTF8String_length(st, td->name, app_errlog, app_key);\n");
		OUT("if(size == (size_t)-1) return -1;\n");
		break;
	case ASN_CONSTR_SET_OF:
	case ASN_CONSTR_SEQUENCE_OF:
		OUT("{ /* Determine the number of elements */\n");
			INDENT(+1);
			OUT("const A_%s_OF(void) *list;\n",
				etype==ASN_CONSTR_SET_OF?"SET":"SEQUENCE");
			OUT("(const void *)list = sptr;\n");
			OUT("size = list->count;\n");
			INDENT(-1);
		OUT("}\n");
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
emit_value_determination_code(arg_t *arg, asn1p_expr_type_e etype) {

	switch(etype) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		if(arg->flags & A1C_USE_NATIVE_INTEGERS) {
			OUT("value = *(const int *)sptr;\n");
		} else {
			OUT("if(asn1_INTEGER2long(st, &value)) {\n");
				INDENT(+1);
				OUT("_ASN_ERRLOG(app_errlog, app_key,\n");
				OUT("\t\"%%s: value too large\", td->name);\n");
				OUT("return -1;\n");
				INDENT(-1);
			OUT("}\n");
		}
		break;
	case ASN_BASIC_BOOLEAN:
		OUT("value = (*(const int *)sptr) ? 1 : 0;\n");
		break;
	default:
		WARNING("%s:%d: Value cannot be determined "
			"for constraint check for %s",
			arg->mod->source_file_name,
			arg->expr->_lineno,
			arg->expr->Identifier
		);
		OUT_NOINDENT(
			"#error %s:%d: Value of %s cannot be determined\n",
			arg->mod->source_file_name,
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
	expr = asn1f_find_terminal_type_ex(arg->asn, arg->mod, arg->expr);
	if(expr) return expr->expr_type;
	return A1TC_INVALID;
}

