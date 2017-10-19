#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"
#include "asn1p_expr.h"

void
asn1p_value_set_source(asn1p_value_t *value, asn1p_module_t *module,
                       int lineno) {
    if(value) {
        switch(value->type) {
        case ATV_TYPE:
            asn1p_expr_set_source(value->value.v_type, module, lineno);
            break;
        case ATV_REFERENCED:
            asn1p_ref_set_source(value->value.reference, module, lineno);
            break;
        case ATV_VALUESET:
            asn1p_constraint_set_source(value->value.constraint, module,
                                        lineno);
            break;
        default:
            break;
        }
    }
}

int
asn1p_value_compare(const asn1p_value_t *a, const asn1p_value_t *b) {
    if(a->type != b->type) {
        return -1;
    }

    switch(a->type) {
    case ATV_NULL:
    case ATV_NOVALUE:
    case ATV_MAX:
    case ATV_MIN:
    case ATV_FALSE:
    case ATV_TRUE:
        break;
    case ATV_TYPE:
        return asn1p_expr_compare(a->value.v_type, b->value.v_type);
    case ATV_REAL:
        return (a->value.v_double == b->value.v_double) ? 0 : -1;
    case ATV_INTEGER:
    case ATV_TUPLE:
    case ATV_QUADRUPLE:
        return (a->value.v_integer == b->value.v_integer) ? 0 : -1;
    case ATV_STRING:
    case ATV_UNPARSED:
        if(a->value.string.size != b->value.string.size
           || memcmp(a->value.string.buf, b->value.string.buf,
                     a->value.string.size)
                  != 0) {
            return -1;
        }
        return 0;
    case ATV_BITVECTOR:
        if(a->value.binary_vector.size_in_bits
               != b->value.binary_vector.size_in_bits
           || memcmp(a->value.binary_vector.bits, b->value.binary_vector.bits,
                     (a->value.binary_vector.size_in_bits+7) >> 3)
                  != 0) {
            return -1;
        }
        return 0;
    case ATV_VALUESET:
        return asn1p_constraint_compare(a->value.constraint,
                                        b->value.constraint);
    case ATV_REFERENCED:
        return asn1p_ref_compare(a->value.reference, b->value.reference);
    case ATV_CHOICE_IDENTIFIER:
        if(strcmp(a->value.choice_identifier.identifier,
                  b->value.choice_identifier.identifier)
           != 0) {
            return -1;
        }
        return asn1p_value_compare(a->value.choice_identifier.value,
                                   b->value.choice_identifier.value);
    }

    return 0;
}

asn1p_value_t *
asn1p_value_fromref(asn1p_ref_t *ref, int do_copy) {
	if(ref) {
		asn1p_value_t *v = calloc(1, sizeof *v);
		if(v) {
			if(do_copy) {
				v->value.reference = asn1p_ref_clone(ref);
				if(v->value.reference == NULL) {
					free(v);
					return NULL;
				}
			} else {
				v->value.reference = ref;
			}
			v->type = ATV_REFERENCED;
		}
		return v;
	} else {
		errno = EINVAL;
		return NULL;
	}
}

asn1p_value_t *
asn1p_value_fromconstr(asn1p_constraint_t *ct, int do_copy) {
	if(ct) {
		asn1p_value_t *v = calloc(1, sizeof *v);
		if(v) {
			if(do_copy) {
				v->value.constraint
					= asn1p_constraint_clone(ct);
				if(v->value.constraint == NULL) {
					free(v);
					return NULL;
				}
			} else {
				v->value.constraint = ct;
			}
			v->type = ATV_VALUESET;
		}
		return v;
	} else {
		errno = EINVAL;
		return NULL;
	}
}

asn1p_value_t *
asn1p_value_frombits(uint8_t *bits, int size_in_bits, int do_copy) {
	if(bits) {
		asn1p_value_t *v = calloc(1, sizeof *v);
		assert(size_in_bits >= 0);
		if(v) {
			if(do_copy) {
				int size = ((size_in_bits + 7) >> 3);
				void *p;
				p = malloc(size + 1);
				if(p) {
					memcpy(p, bits, size);
					((char *)p)[size] = '\0'; /* JIC */
				} else {
					free(v);
					return NULL;
				}
				v->value.binary_vector.bits = p;
			} else {
				v->value.binary_vector.bits = (void *)bits;
			}
			v->value.binary_vector.size_in_bits = size_in_bits;
			v->type = ATV_BITVECTOR;
		}
		return v;
	} else {
		errno = EINVAL;
		return NULL;
	}
}

asn1p_value_t *
asn1p_value_frombuf(char *buffer, int size, int do_copy) {
	if(buffer) {
		asn1p_value_t *v = calloc(1, sizeof *v);
		assert(size >= 0);
		if(v) {
			if(do_copy) {
				void *p = malloc(size + 1);
				if(p) {
					memcpy(p, buffer, size);
					((char *)p)[size] = '\0'; /* JIC */
				} else {
					free(v);
					return NULL;
				}
				v->value.string.buf = p;
			} else {
				v->value.string.buf = (uint8_t *)buffer;
			}
			v->value.string.size = size;
			v->type = ATV_STRING;
		}
		return v;
	} else {
		errno = EINVAL;
		return NULL;
	}
}

asn1p_value_t *
asn1p_value_fromdouble(double d) {
	asn1p_value_t *v = calloc(1, sizeof *v);
	if(v) {
		v->value.v_double = d;
		v->type = ATV_REAL;
	}
	return v;
}

asn1p_value_t *
asn1p_value_fromint(asn1c_integer_t i) {
	asn1p_value_t *v = calloc(1, sizeof *v);
	if(v) {
		v->value.v_integer = i;
		v->type = ATV_INTEGER;
	}
	return v;
}

asn1p_value_t *
asn1p_value_fromtype(asn1p_expr_t *expr) {
	asn1p_value_t *v = calloc(1, sizeof *v);
	if(v) {
		v->value.v_type = expr;
		v->type = ATV_TYPE;
		expr->ref_cnt++;
	}
	return v;
}

asn1p_value_t *
asn1p_value_clone(asn1p_value_t *v) {
	return asn1p_value_clone_with_resolver(v, 0, 0);
}

asn1p_value_t *
asn1p_value_clone_with_resolver(asn1p_value_t *v,
		asn1p_value_t *(*resolver)(asn1p_value_t *, void *rarg),
		void *rarg) {
	asn1p_value_t *clone = NULL;
	if(v) {
		switch(v->type) {
		case ATV_NOVALUE:
		case ATV_NULL:
			return calloc(1, sizeof(*clone));
		case ATV_REAL:
			return asn1p_value_fromdouble(v->value.v_double);
		case ATV_TYPE:
			return asn1p_value_fromtype(v->value.v_type);
		case ATV_INTEGER:
		case ATV_MIN:
		case ATV_MAX:
		case ATV_FALSE:
		case ATV_TRUE:
		case ATV_TUPLE:
		case ATV_QUADRUPLE:
			clone = asn1p_value_fromint(v->value.v_integer);
			if(clone) clone->type = v->type;
			return clone;
		case ATV_STRING:
			clone = asn1p_value_frombuf((char *)v->value.string.buf,
				v->value.string.size, 1);
			if(clone) clone->type = v->type;
			return clone;
		case ATV_UNPARSED:
			clone = asn1p_value_frombuf((char *)v->value.string.buf,
				v->value.string.size, 1);
			if(clone) clone->type = ATV_UNPARSED;
			return clone;
		case ATV_BITVECTOR:
			return asn1p_value_frombits(v->value.binary_vector.bits,
				v->value.binary_vector.size_in_bits, 1);
		case ATV_REFERENCED:
			if(resolver) {
				clone = resolver(v, rarg);
				if(clone) return clone;
				else if(errno != ESRCH) return NULL;
			}
			return asn1p_value_fromref(v->value.reference, 1);
		case ATV_VALUESET:
			if(resolver) {
				clone = resolver(v, rarg);
				if(clone) return clone;
				else if(errno != ESRCH) return NULL;
			}
			return asn1p_value_fromconstr(v->value.constraint, 1);
		case ATV_CHOICE_IDENTIFIER: {
			char *id = v->value.choice_identifier.identifier;
			clone = calloc(1, sizeof(*clone));
			if(!clone) return NULL;
			clone->type = v->type;
			id = strdup(id);
			if(!id) { asn1p_value_free(clone); return NULL; }
			clone->value.choice_identifier.identifier = id;
			v = asn1p_value_clone(v->value.choice_identifier.value);
			if(!v) { asn1p_value_free(clone); return NULL; }
			clone->value.choice_identifier.value = v;
			return clone;
		    }
		}

		assert(!"UNREACHABLE");
	}
	return v;
}

void
asn1p_value_free(asn1p_value_t *v) {
	if(v) {
		switch(v->type) {
		case ATV_NOVALUE:
		case ATV_NULL:
			break;
		case ATV_TYPE:
			asn1p_expr_free(v->value.v_type);
			break;
		case ATV_REAL:
		case ATV_INTEGER:
		case ATV_MIN:
		case ATV_MAX:
		case ATV_FALSE:
		case ATV_TRUE:
		case ATV_TUPLE:
		case ATV_QUADRUPLE:
			/* No freeing necessary */
			break;
		case ATV_STRING:
		case ATV_UNPARSED:
			assert(v->value.string.buf);
			free(v->value.string.buf);
			break;
		case ATV_BITVECTOR:
			assert(v->value.binary_vector.bits);
			free(v->value.binary_vector.bits);
			break;
		case ATV_REFERENCED:
			asn1p_ref_free(v->value.reference);
			break;
		case ATV_VALUESET:
			asn1p_constraint_free(v->value.constraint);
			break;
		case ATV_CHOICE_IDENTIFIER:
			free(v->value.choice_identifier.identifier);
			asn1p_value_free(v->value.choice_identifier.value);
			break;
		}
		memset(v, 0, sizeof(*v));
		free(v);
	}
}

