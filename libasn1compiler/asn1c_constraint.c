#include "asn1c_internal.h"
#include "asn1c_constraint.h"

#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportable stuff from libasn1fix */

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

	OUT("const %s_t *st = sptr;\n", MKID(arg->expr->Identifier));

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

int
asn1c_emit_constraint_tables(arg_t *arg, asn1p_constraint_t *ct) {
	asn1_integer_t range_start;
	asn1_integer_t range_stop;
	asn1p_expr_type_e etype;
	asn1cnst_range_t *range;
	int table[256];
	int use_table;

	if(!ct) ct = arg->expr->combined_constraints;
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
	if((range_stop - range_start) > 255)
		use_table = 0;
	if(range->el_count == 0)
		use_table = 0;

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
				assert((v - range_start) < 256);
				table[v - range_start] = ++n;
			}
		}

		OUT("static int permitted_alphabet_table_%d[256] = {\n",
			ct->_compile_mark);
		untl = (range_stop - range_start) + 1;
		untl += (untl % 16)?16 - (untl % 16):0;
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
	}

	OUT("static int check_permitted_alphabet_%d(const void *sptr) {\n",
			ct->_compile_mark);
		INDENT(+1);
		if(use_table) {
			OUT("int *table = permitted_alphabet_table_%d;\n",
				ct->_compile_mark);
			emit_alphabet_check_loop(arg, 0);
		} else {
			emit_alphabet_check_loop(arg, range);
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
	asn1p_expr_type_e etype;
	asn1_integer_t natural_stop;

	etype = _find_terminal_type(arg);

	OUT("/* The underlying type is %s */\n",
		ASN_EXPR_TYPE2STR(etype));
	OUT("const %s_t *st = sptr;\n", MKID(arg->expr->Identifier));

	switch(etype) {
	case ASN_STRING_UTF8String:
		OUT("uint8_t *ch = st->buf;\n");
		OUT("uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint8_t cv = *ch;\n");
			if(!range) OUT("if(cv >= 0x80) return 0;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_UniversalString:
		OUT("uint32_t *ch = st->buf;\n");
		OUT("uint32_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size % 4) return 0; /* (size%4)! */\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint32_t cv = (((uint8_t *)ch)[0] << 24)\n");
			OUT("\t\t| (((uint8_t *)ch)[1] << 16)\n");
			OUT("\t\t| (((uint8_t *)ch)[2] << 8)\n");
			OUT("\t\t|  ((uint8_t *)ch)[3]\n");
			if(!range) OUT("if(cv > 255) return 0;\n");
		natural_stop = 0xffffffffUL;
		break;
	case ASN_STRING_BMPString:
		OUT("uint16_t *ch = st->buf;\n");
		OUT("uint16_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("if(st->size % 2) return 0; /* (size%2)! */\n");
		OUT("for(; ch < end; ch++) {\n");
			INDENT(+1);
			OUT("uint16_t cv = (((uint8_t *)ch)[0] << 8)\n");
			OUT("\t\t| ((uint8_t *)ch)[1];\n");
			if(!range) OUT("if(cv > 255) return 0;\n");
		natural_stop = 0xffff;
		break;
	case ASN_BASIC_OCTET_STRING:
	default:
		OUT("uint8_t *ch = st->buf;\n");
		OUT("uint8_t *end = ch + st->size;\n");
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
	}

	return 0;
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
			OUT("A_%s_OF(void) *list;\n",
				etype==ASN_CONSTR_SET_OF?"SET":"SEQUENCE");
			OUT("(void *)list = st;\n");
			OUT("size = list->count;\n");
			INDENT(-1);
		OUT("}\n");
		break;
	default:
		if((etype & ASN_STRING_MASK)
		|| etype == ASN_BASIC_OCTET_STRING) {
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
			OUT("value = *(int *)st;\n");
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
		OUT("value = (*(int *)st) ? 1 : 0;\n");
		break;
	default:
		WARNING("Value cannot be determined "
			"for constraint check for %s at line %d\n",
			arg->expr->Identifier, arg->expr->_lineno);
		OUT("#error Value cannot be determined for %s at %d\n",
			arg->expr->Identifier, arg->expr->_lineno);
		break;
	}

	return 0;
}

static asn1p_expr_type_e
_find_terminal_type(arg_t *arg) {
	asn1p_expr_t *expr;
	expr = asn1f_find_terminal_type_ex(arg->asn, arg->mod, arg->expr, NULL);
	if(expr) return expr->expr_type;
	return A1TC_INVALID;
}

