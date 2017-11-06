#include <stdio.h>
#include <stdlib.h>
#include "asn1fix_internal.h"
#include "asn1fix_cws.h"

static int _asn1f_parse_class_object_data(arg_t *, asn1p_expr_t *eclass,
		struct asn1p_ioc_row_s *row, asn1p_wsyntx_t *syntax,
		const uint8_t *buf, const uint8_t *bend,
		int optional_mode, const uint8_t **newpos, int counter);
static int _asn1f_assign_cell_value(arg_t *arg, struct asn1p_ioc_cell_s *cell, const uint8_t *buf, const uint8_t *bend, int counter);
static asn1p_wsyntx_chunk_t *asn1f_next_literal_chunk(asn1p_wsyntx_t *syntax, asn1p_wsyntx_chunk_t *chunk, const uint8_t *buf);

int
asn1f_check_class_object(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *eclass;
	asn1p_ioc_row_t *row;
	int ret;

	if(expr->meta_type != AMT_VALUESET
	|| expr->expr_type != A1TC_REFERENCE
	|| !expr->value
	|| expr->value->type != ATV_UNPARSED) {
		return 0;
    }

	eclass = asn1f_find_terminal_type(arg, expr);
	if(!eclass
	|| eclass->meta_type != AMT_OBJECTCLASS
	|| eclass->expr_type != A1TC_CLASSDEF) {
		return 0;
	}

	if(!eclass->with_syntax) {
		DEBUG("Can't process classes without %s just yet",
			"WITH SYNTAX");
		return 0;
	}

	row = asn1p_ioc_row_new(eclass);
	assert(row);

	ret = _asn1f_parse_class_object_data(arg, eclass, row,
		eclass->with_syntax,
		expr->value->value.string.buf + 1,
		expr->value->value.string.buf
			+ expr->value->value.string.size - 1,
		0, 0, 0);

	asn1p_ioc_row_delete(row);

	return ret;
}

static int
_asn1f_is_ioc_row_duplicate(asn1p_ioc_table_t *it, asn1p_ioc_row_t *row) {
    if(!it) {
        return 0;
    }

    for(size_t i = 0; i < it->rows; i++) {
        switch(asn1p_ioc_row_match(it->row[i], row)) {
        default:
        case -1:
            return -1;
        case 1:
            continue;
        case 0:
            return 1; /* Duplicate! */
        }
    }
    return 0;
}

struct parse_object_key {
    arg_t *arg;
    asn1p_expr_t *expr;   /* InformationObjectSet */
    asn1p_expr_t *eclass; /* CLASS */
    int sequence;          /* Sequence counter */
};

/*
 * Add to the IoC table if the row is unique.
 */
static int
_asn1f_add_unique_row(arg_t *arg, asn1p_expr_t *expr, asn1p_ioc_row_t *row) {
    assert(expr->ioc_table);

    /* Look for duplicates */
    switch(_asn1f_is_ioc_row_duplicate(expr->ioc_table, row)) {
    case -1:
        DEBUG("Found Information Object Duplicate in %s", expr->Identifier,
              expr->_lineno);
        return -1;
    case 0:
        /* Not a duplicate */
        break;
    case 1:
        /* Proper duplicate detected; ignore */
        asn1p_ioc_row_delete(row);
        return 0;
        }

    asn1p_ioc_table_add(expr->ioc_table, row);

    return 0;
}

/*
 * Given a single blob of unparsed Information Object specification, parse it
 * into a given InformationObjectSet.
 */
static int
_asn1f_parse_object_cb(const uint8_t *buf, size_t size, void *keyp) {
    struct parse_object_key *key = keyp;
    arg_t *arg = key->arg;
    asn1p_expr_t *expr = key->expr;
    asn1p_expr_t *eclass = key->eclass;
	asn1p_ioc_row_t *row;
    int ret;

    key->sequence++;

	row = asn1p_ioc_row_new(eclass);
	assert(row);

    ret = _asn1f_parse_class_object_data(arg, eclass, row, eclass->with_syntax,
                                         buf, buf + size, 0, 0, key->sequence);
    if(ret) {
        LOG(ret, "Cannot parse %s of CLASS %s found at line %d",
            expr->Identifier, eclass->Identifier, expr->_lineno);
        asn1p_ioc_row_delete(row);
		return ret;
	}

    /* Add object to a CLASS. */
    if(_asn1f_add_unique_row(arg, eclass, row) != 0)
        return -1;

    /*
     * Add a copy of the object to the Information Object Set.
     */
	row = asn1p_ioc_row_new(eclass);
	assert(row);
    ret = _asn1f_parse_class_object_data(arg, eclass, row, eclass->with_syntax,
                                         buf, buf + size, 0, 0, key->sequence);
    assert(ret == 0);

    if(_asn1f_add_unique_row(arg, expr, row) != 0)
        return -1;

    return 0;
}

static int
_asn1f_foreach_unparsed_union(const asn1p_constraint_t *ct_union,
                              int (*process)(const uint8_t *buf, size_t size,
                                             void *key),
                              void *key) {
    assert(ct_union->type == ACT_CA_UNI);

    for(size_t j = 0; j < ct_union->el_count; j++) {
        const asn1p_constraint_t *ct2 = ct_union->elements[j];
        if(ct2->type == ACT_EL_VALUE && ct2->value->type == ATV_UNPARSED) {
            if(process
               && process(ct2->value->value.string.buf + 1,
                          ct2->value->value.string.size - 2, key)
                      != 0) {
                return -1;
            }
            continue;
        }
        return -1;
    }

    return 0;
}

static int
_asn1f_foreach_unparsed(arg_t *arg, const asn1p_constraint_t *ct,
                        int (*process)(const uint8_t *buf, size_t size,
                                       void *key),
                        void *keyp) {
    struct parse_object_key *key = keyp;
    if(!ct) return -1;

    switch(ct->type) {
    default:
        DEBUG("Constraint is of unknown type %d for CWS", ct->type);
        return -1;
    case ACT_EL_EXT:    /* ... */
        if(key) {
            key->expr->ioc_table->extensible = 1;
        }
        return 0;
    case ACT_CA_UNI:    /* | */
        return _asn1f_foreach_unparsed_union(ct, process, keyp);
    case ACT_CA_CSV:    /* , */
        break;
    case ACT_EL_VALUE:
        return 0;
    }

    for(size_t i = 0; i < ct->el_count; i++) {
        const asn1p_constraint_t *ct1 = ct->elements[i];
        if(_asn1f_foreach_unparsed(arg, ct1, process, keyp) != 0) {
            return -1;
        }
    }

    return 0;
}

static int
_asn1f_constraint_looks_like_object_set(arg_t *arg,
                                        const asn1p_constraint_t *ct) {
    return 0 == _asn1f_foreach_unparsed(arg, ct, NULL, NULL);
}

int
asn1f_parse_class_object(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *eclass;
    enum {
        FROM_VALUE,
        FROM_CONSTRAINT,
    } source = FROM_VALUE;

	if(expr->meta_type == AMT_VALUE
	&& expr->expr_type == A1TC_REFERENCE
	&& expr->value && expr->value->type == ATV_UNPARSED) {
        source = FROM_VALUE;
    } else if(expr->meta_type != AMT_VALUESET
	|| expr->expr_type != A1TC_REFERENCE) {
        return 0;
    } else if(expr->value && expr->value->type == ATV_UNPARSED) {
        source = FROM_VALUE;
    } else if(!expr->value) {
        if(_asn1f_constraint_looks_like_object_set(arg, expr->constraints)) {
            source = FROM_CONSTRAINT;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

	/*
	 * Find the governing class.
	 */
	eclass = asn1f_find_terminal_type(arg, expr);
	if(!eclass
	|| eclass->meta_type != AMT_OBJECTCLASS
	|| eclass->expr_type != A1TC_CLASSDEF) {
		return 0;
	}

	DEBUG("Value %s of CLASS %s found at line %d",
		expr->Identifier, eclass->Identifier, expr->_lineno);

	if(!eclass->with_syntax) {
		DEBUG("Can't process classes without %s just yet",
			"WITH SYNTAX");
		return 0;
	}

    struct parse_object_key key = {
        .arg = arg,
        .expr = expr,
        .eclass = eclass,
        .sequence = 0
    };

    if(!expr->ioc_table) {
        expr->ioc_table = asn1p_ioc_table_new();
    }

    if(!eclass->ioc_table) {
        eclass->ioc_table = asn1p_ioc_table_new();
    }

    switch(source) {
    case FROM_VALUE:
        if(_asn1f_parse_object_cb(expr->value->value.string.buf + 1,
                           expr->value->value.string.size - 2, &key)
           != 0) {
            return -1;
        }
        break;
    case FROM_CONSTRAINT:
        if(_asn1f_foreach_unparsed(arg, expr->constraints,
                                   _asn1f_parse_object_cb, &key)
           != 0) {
            return -1;
        }
    }

	return 0;
}

#define	SKIPSPACES	for(; buf < bend && isspace(*buf); buf++)

static int
_asn1f_parse_class_object_data(arg_t *arg, asn1p_expr_t *eclass,
		struct asn1p_ioc_row_s *row, asn1p_wsyntx_t *syntax,
		const uint8_t *buf, const uint8_t *bend,
		int optional_mode, const uint8_t **newpos, int counter) {
	struct asn1p_wsyntx_chunk_s *chunk;
	int ret;

	TQ_FOR(chunk, (&syntax->chunks), next) {
		switch(chunk->type) {
		case WC_LITERAL: {
			int token_len = strlen(chunk->content.token);
			SKIPSPACES;
			if(bend - buf < token_len
			|| memcmp(buf, chunk->content.token, token_len)) {
				if(!optional_mode) {
					FATAL("While parsing object class value %s at line %d: Expected: \"%s\", found: \"%s\"",
					arg->expr->Identifier, arg->expr->_lineno, chunk->content.token, buf);
				}
				if(newpos) *newpos = buf;
				return -1;
			}
			buf += token_len;
		    } break;
		case WC_WHITESPACE: break;	/* Ignore whitespace */
		case WC_FIELD: {
			struct asn1p_ioc_cell_s *cell;
			asn1p_wsyntx_chunk_t *next_literal;
			const uint8_t *buf_old = buf;
			const uint8_t *p = 0;

			SKIPSPACES;

			next_literal = asn1f_next_literal_chunk(syntax, chunk, buf);
			if(!next_literal) {
				p += (bend - p);
			} else {
				p = (uint8_t *)strstr((const char *)buf, (const char *)next_literal->content.token);
				if(!p) {
					if (!optional_mode)
						FATAL("Next literal \"%s\" not found !", next_literal->content.token);

					if(newpos) *newpos = buf_old;
					return -1;
				}
			}
			cell = asn1p_ioc_row_cell_fetch(row,
					chunk->content.token);
			if(cell == NULL) {
				FATAL("Field reference %s found in WITH SYNAX {} clause does not match actual field in Object Class %s",
					chunk->content.token,
					eclass->Identifier, eclass->_lineno);
				if(newpos) *newpos = buf;
				return -1;
			}
			DEBUG("Reference %s satisfied by %s (%d)",
				chunk->content.token,
				buf, p - buf);
			ret = _asn1f_assign_cell_value(arg, cell, buf, p, counter);
			if(ret) return ret;
			buf = p;
			if(newpos) *newpos = buf;
		    } break;
		case WC_OPTIONALGROUP: {
			const uint8_t *np = 0;
			SKIPSPACES;
			ret = _asn1f_parse_class_object_data(arg, eclass, row,
				chunk->content.syntax, buf, bend, 1, &np, counter);
			if(newpos) *newpos = np;
			if(ret && np != buf)
				return ret;
			buf = np;
		    } break;
		}
	}


	if(newpos) *newpos = buf;
	return 0;
}


static int
_asn1f_assign_cell_value(arg_t *arg, struct asn1p_ioc_cell_s *cell,
                         const uint8_t *buf, const uint8_t *bend, int counter) {
    asn1p_expr_t *expr = (asn1p_expr_t *)NULL;
	char *mivr; /* Most Immediate Value Representation */
	int new_ref = 1;
	asn1p_t *asn;
	asn1p_expr_t *type_expr = (asn1p_expr_t *)NULL;
	int i, ret = 0, psize;
	char *pp;

	if((bend - buf) <= 0) {
		FATAL("Assignment warning: empty string is being assigned into %s for %s at line %d",
			cell->field->Identifier,
			arg->expr->Identifier, arg->expr->_lineno);
		return -1;
	}

	mivr = malloc(bend - buf + 1);
	assert(mivr);
	memcpy(mivr, buf, bend - buf);
	mivr[bend - buf] = '\0';
	/* remove trailing space */
	for (i = bend - buf - 1; (i > 0) && isspace(mivr[i]); i--)
		mivr[i] = '\0';

	/* This value 100 should be larger than following formatting string */
	psize = bend - buf + 100;
	pp = calloc(1, psize);
	if(pp == NULL) {
		free(mivr);
		return -1;
	}

	if(cell->field->expr_type == A1TC_CLASSFIELD_TFS) {
		ret = snprintf(pp, psize,
			"M DEFINITIONS ::=\nBEGIN\n"
			"V ::= %s\n"
			"END\n",
			mivr
		);
	} else if(cell->field->expr_type == A1TC_CLASSFIELD_FTVFS) {
		type_expr = TQ_FIRST(&(cell->field->members));
		ret = snprintf(pp, psize,
				"M DEFINITIONS ::=\nBEGIN\n"
				"v %s ::= %s\n"
				"END\n",
				type_expr->reference ? 
					type_expr->reference->components[0].name : 
					_asn1p_expr_type2string(type_expr->expr_type),
				mivr
			);
	} else {
		WARNING("asn1c only be able to parse TypeFieldSpec and FixedTypeValueFieldSpec. Failed when parsing %s at line %d\n", mivr, arg->expr->_lineno);
		free(mivr);
		free(pp);
		return -1;
	}
	DEBUG("ASN.1:\n\n%s\n", pp);

	assert(ret < psize);
	psize = ret;

	asn = asn1p_parse_buffer(pp, psize,
		arg->expr->module->source_file_name, arg->expr->_lineno, A1P_NOFLAGS);
	free(pp);
	if(asn == NULL) {
		FATAL("Cannot parse Setting token %s "
			"at line %d",
			mivr,
			arg->expr->_lineno
		);
		free(mivr);
		return -1;
	} else {
        asn1p_module_t *mod = TQ_FIRST(&(asn->modules));
        assert(mod);

        /* This member removal is safe with respect to members hash since the
         * entire asn module will be deleted down below.
         */
        expr = TQ_REMOVE(&(mod->members), next);
		assert(expr);

        expr->parent_expr = NULL;
        asn1p_expr_set_source(expr, arg->expr->module, arg->expr->_lineno);
        expr->_type_unique_index = counter;
        DEBUG("Parsed identifier %s, mivr [%s], reference [%s] value [%s]",
              expr->Identifier, mivr, asn1p_ref_string(expr->reference),
              asn1f_printable_value(expr->value));
        free(expr->Identifier);
        if(expr->value) {
			expr->Identifier = strdup(asn1f_printable_value(expr->value));
        } else if (expr->reference) {
			expr->Identifier = strdup(expr->reference->components[expr->reference->comp_count - 1].name);
		} else {
			expr->Identifier = mivr;
		}
		asn1p_delete(asn);
	}

	if(expr->reference &&
		!asn1f_lookup_symbol(arg, expr->rhs_pspecs, expr->reference)) {

		asn1p_ref_free(expr->reference);
		new_ref = 0;
		expr->reference = type_expr->reference;
		if (asn1f_value_resolve(arg, expr, 0)) {
			expr->reference = 0;
			asn1p_expr_free(expr);
			FATAL("Cannot find %s referenced by %s at line %d",
				mivr, arg->expr->Identifier,
				arg->expr->_lineno);
			free(mivr);
			return -1;
		}
	}

	DEBUG("Field %s assignment of %s got %s",
		cell->field->Identifier, mivr, expr->Identifier);

	cell->value = expr;
	cell->new_ref = new_ref;

	if(expr->Identifier != mivr) {
		free(mivr);
    }

	return 0;
}

static asn1p_wsyntx_chunk_t *
asn1f_next_literal_chunk(asn1p_wsyntx_t *syntax, asn1p_wsyntx_chunk_t *chunk, const uint8_t *buf)
{
	asn1p_wsyntx_chunk_t *next_chunk;

	next_chunk = TQ_NEXT(chunk, next);
	do {
		if(next_chunk == (struct asn1p_wsyntx_chunk_s *)0) {
			if(!syntax->parent)
				break;
			next_chunk = TQ_NEXT(syntax->parent, next);
		} else if(next_chunk->type == WC_LITERAL) {
			if(strstr((const char *)buf, (char *)next_chunk->content.token))
				break;
			if(!syntax->parent)
				break;
			next_chunk = TQ_NEXT(syntax->parent, next);
		} else if(next_chunk->type == WC_WHITESPACE) {
			next_chunk = TQ_NEXT(next_chunk, next);
		} else if(next_chunk->type == WC_OPTIONALGROUP) {
			syntax = next_chunk->content.syntax;
			next_chunk = TQ_FIRST(((&next_chunk->content.syntax->chunks)));
		} else 
			break;
	} while (next_chunk);

	return next_chunk;
}
