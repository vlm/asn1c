#include "asn1fix_internal.h"

static int asn1f_fix_bit_string_type(arg_t *arg);
static int asn1f_fix_bit_string_value(arg_t *arg, asn1p_expr_t *ttype);
static void asn1f_BS_remove_trailing_zero_bits(asn1p_value_t *value);
static int asn1f_BS_unparsed_convert(arg_t *arg, asn1p_value_t *value, asn1p_expr_t *ttype);

int
asn1f_fix_bit_string(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;
	int ret;

	if(expr->meta_type == AMT_VALUE) {
		asn1p_expr_t *ttype;

		DEBUG("(%s) for line %d", expr->Identifier, expr->_lineno);

		ttype = asn1f_find_terminal_type(arg, expr);
		if(ttype && ttype->expr_type == ASN_BASIC_BIT_STRING) {
			ret = asn1f_fix_bit_string_value(arg, ttype);
			RET2RVAL(ret, r_value);
		}
	}

	if(expr->meta_type == AMT_TYPE
	&& expr->expr_type == ASN_BASIC_BIT_STRING) {
		ret = asn1f_fix_bit_string_type(arg);
		RET2RVAL(ret, r_value);
	}

	return r_value;
}

static int _compare_value(asn1p_expr_t *expr1, asn1p_expr_t *expr2) {
	return expr2->value->value.v_integer - expr1->value->value.v_integer;
}

static int
asn1f_fix_bit_string_type(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int r_value = 0;
	int ret;

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			FATAL("Extension marker (...) is not allowed "
				"as a BIT STRING NamedBit at line %d ",
				v->_lineno);
			return -1;
		}
		if(v->expr_type != A1TC_UNIVERVAL) {
			FATAL("BIT STRING value at line %d "
				"is not an identifier", v->_lineno);
			return -1;
		}

		/* 21.1 */
		if(v->value == NULL) {
			FATAL("BIT STRING NamedBit value at line %d "
				"must be explicitly specified in braces",
				v->_lineno);
			return -1;
		} else if(v->value->type == ATV_REFERENCED) {
			/* Resolve the value */
            if(asn1f_value_resolve(arg, v, 0))
                return -1;
		}
		if(v->value->type != ATV_INTEGER
		|| v->value->value.v_integer < 0) {
			FATAL("BIT STRING NamedBit value at line %d: "
				"non-negative integer value expected",
				v->_lineno);
			return -1;
		}

		/* Check value uniqueness as per 21.4 */
		ret = asn1f_check_unique_expr_child(arg, v,
				_compare_value, "value");
		RET2RVAL(ret, r_value);
		/* Check identifier uniqueness as per 21.5 */
		ret = asn1f_check_unique_expr_child(arg, v, 0, "identifier");
		RET2RVAL(ret, r_value);
	}

	return r_value;
}

static int
asn1f_fix_bit_string_value(arg_t *arg, asn1p_expr_t *ttype) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;

	DEBUG("(%s) for line %d",
		expr->Identifier, expr->_lineno);

	switch(expr->value->type) {
	case ATV_UNPARSED:
		/*
		 * Most definitely we have something like
		 * 	value BitStringType1 ::= { a, b, c }
		 * which could not be parsed by the LALR parser, mostly
		 * because it requires knowledge about BitStringType1
		 * during the parsing. So, here's a little hack: we create
		 * a buffer containing the full specification of a module,
		 * which contains some pre-defined INTEGER type with the
		 * opaque definition "{ a, b, c }" from the bit string.
		 */
		if(asn1f_BS_unparsed_convert(arg, expr->value, ttype)) {
			r_value = -1;
			break;
		}
		/* Fall through: remove trailing zero bits */
        /* Fall through */
	case ATV_BITVECTOR:
		asn1f_BS_remove_trailing_zero_bits(expr->value);
		break;
	default:
		break;
	}

	return r_value;
}

static void
asn1f_BS_remove_trailing_zero_bits(asn1p_value_t *value) {
	int lmfb = -1;	/* Last meaningful byte position */
	int bits;	/* Number of bits in the BIT STRING value */
	int b;

	assert(value->type == ATV_BITVECTOR);

	bits = value->value.binary_vector.size_in_bits;
	/*
	 * Figure out the rightmost meaningful byte.
	 */
	for(b = 0; b < ((bits + 7) >> 3); b++) {
		uint8_t uc = value->value.binary_vector.bits[b];
		if(uc && b > lmfb)
			lmfb = b;
	}
	if(lmfb == -1) {
		bits = 0;
	} else {
		uint8_t uc;
		uc = value->value.binary_vector.bits[lmfb];
		bits = (lmfb+1) * 8;
		/*
		 * Squeeze the bit string width until the rightmost
		 * bit is set.
		 */
		for(; uc && (uc & 1) == 0; uc >>= 1)
			bits--;
		if(uc == 0) {
			bits = lmfb * 8;
		}
	}
	value->value.binary_vector.size_in_bits = bits;
}

static int
asn1f_BS_unparsed_convert(arg_t *arg, asn1p_value_t *value, asn1p_expr_t *ttype) {
	asn1p_t *asn;
	asn1p_module_t *mod;
	asn1p_expr_t *V;
	asn1p_expr_t *bit;
	asn1c_integer_t aI;
	uint8_t *bitbuf;
	int bits;
	int psize;
	char *p;
	int ret;
	int r_value = 0;

	assert(value->type == ATV_UNPARSED);

	psize = value->value.string.size + sizeof("M DEFINITIONS ::= BEGIN V ::= BIT STRING END") + 32;
	p = malloc(psize);
	if(p == NULL)
		return -1;

	ret = snprintf(p, psize,
		"M DEFINITIONS ::=\nBEGIN\n"
		"V ::= #BIT STRING %s\n"
		"END\n",
		value->value.string.buf
	);
	assert(ret < psize);
	psize = ret;

	asn = asn1p_parse_buffer(p, psize, arg->expr->module->source_file_name,
                             arg->expr->_lineno, A1P_EXTENDED_VALUES);
	free(p);
	if(asn == NULL) {
		FATAL("Cannot parse BIT STRING value %s "
			"defined as %s at line %d",
			arg->expr->Identifier,
			value->value.string.buf,
			arg->expr->_lineno
		);
		return -1;
	}

	mod = TQ_FIRST(&(asn->modules));
	assert(mod);
	V = TQ_FIRST(&(mod->members));
	assert(V);
	assert(strcmp(V->Identifier, "V") == 0);

	/*
	 * Simple loop just to fetch the maximal bit position
	 * out of the BIT STRING value defined as NamedBitList.
	 */
	aI = -1;
	TQ_FOR(bit, &(V->members), next) {
		asn1p_expr_t *bitdef;
		bitdef = asn1f_lookup_child(ttype, bit->Identifier);
		if(bitdef && bitdef->value
		&& bitdef->value->type == ATV_INTEGER) {
			if(bitdef->value->value.v_integer > aI)
				aI = bitdef->value->value.v_integer;
		}
	}

	if(aI > 1024 * 1024 * 8) {	/* One megabyte */
		FATAL("Unsupportedly large BIT STRING value \"%s\" "
			"defined at line %d "
			"(larger than 1MByte)",
			arg->expr->Identifier,
			arg->expr->_lineno
		);
		asn1p_delete(asn);
		return -1;
	}

	bits = aI + 1;	/* Number of bits is more than a last bit position */
	bitbuf = calloc(1, 1 + ((bits + 7) / 8));
	if(bitbuf == NULL) {
		asn1p_delete(asn);
		return -1;
	}

	TQ_FOR(bit, &(V->members), next) {
		asn1p_expr_t *bitdef;
		int set_bit_pos;

		if(bit->value) {
			WARNING("Identifier \"%s\" at line %d "
				"must not have a value",
				bit->Identifier, bit->_lineno);
			RET2RVAL(1, r_value);
		}
		bitdef = asn1f_lookup_child(ttype, bit->Identifier);
		if(bitdef == NULL) {
			FATAL("Identifier \"%s\" at line %d is not defined "
				"in the \"%s\" type definition at line %d",
				bit->Identifier,
				bit->_lineno,
				ttype->Identifier,
				ttype->_lineno
			);
			RET2RVAL(-1, r_value);
			continue;
		}
		if(bitdef->value == NULL
		|| bitdef->value->type != ATV_INTEGER) {
			FATAL("Broken identifier "
				"\"%s\" at line %d "
				"referenced by \"%s\" at line %d",
				bitdef->Identifier,
				bitdef->_lineno,
				arg->expr->Identifier,
				arg->expr->_lineno
			);
			RET2RVAL(-1, r_value);
			continue;
		}

		assert(bitdef->value->value.v_integer < bits);
		set_bit_pos = bitdef->value->value.v_integer;
		bitbuf[set_bit_pos>>3] |= 1 << (7-(set_bit_pos % 8));
	}

	asn1p_delete(asn);
	free(value->value.string.buf);
	value->type = ATV_BITVECTOR;
	value->value.binary_vector.bits = bitbuf;
	value->value.binary_vector.size_in_bits = bits;

	return r_value;
}
