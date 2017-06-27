#include "asn1fix_internal.h"
#include "asn1fix_cws.h"

static int _asn1f_parse_class_object_data(arg_t *, asn1p_expr_t *eclass,
		struct asn1p_ioc_row_s *row, asn1p_wsyntx_t *syntax,
		uint8_t *buf, const uint8_t *bend,
		int optional_mode, uint8_t **newpos);
static int _asn1f_assign_cell_value(arg_t *arg, struct asn1p_ioc_row_s *row, struct asn1p_ioc_cell_s *cell, uint8_t *buf, const uint8_t *bend);
static asn1p_wsyntx_chunk_t *asn1f_next_literal_chunk(asn1p_wsyntx_t *syntax, asn1p_wsyntx_chunk_t *chunk, uint8_t *buf);

int
asn1f_check_class_object(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *eclass;
	asn1p_ioc_row_t *row;
	int ret;

	if(expr->meta_type != AMT_VALUE
	|| expr->expr_type != A1TC_REFERENCE
	|| !expr->value
	|| expr->value->type != ATV_UNPARSED)
		return 0;

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
		0, 0);

	asn1p_ioc_row_delete(row);

	return ret;
}

int
asn1f_parse_class_object(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *eclass;
	asn1p_ioc_row_t *row;
	void *new_rows_ptr;
	int ret;

	if(expr->meta_type != AMT_VALUE
	|| expr->expr_type != A1TC_REFERENCE
	|| !expr->value
	|| expr->value->type != ATV_UNPARSED)
		return 0;

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

	row = asn1p_ioc_row_new(eclass);
	assert(row);

	ret = _asn1f_parse_class_object_data(arg, eclass, row,
		eclass->with_syntax,
		expr->value->value.string.buf + 1,
		expr->value->value.string.buf
			+ expr->value->value.string.size - 1,
		0, 0);
	if(ret) {
		LOG((int)(ret < 0),
			"Cannot parse %s of CLASS %s found at line %d",
			expr->Identifier, eclass->Identifier, expr->_lineno);
		asn1p_ioc_row_delete(row);
		return ret;
	}

	new_rows_ptr = realloc(eclass->object_class_matrix.row,
			(eclass->object_class_matrix.rows + 1)
			* sizeof(eclass->object_class_matrix.row[0]));
	assert(new_rows_ptr);
	eclass->object_class_matrix.row = new_rows_ptr;
	eclass->object_class_matrix.row[eclass->object_class_matrix.rows] = row;
	eclass->object_class_matrix.rows++;
	/* Propagate max identifier length */
	if(eclass->object_class_matrix.max_identifier_length
			< row->max_identifier_length)
		eclass->object_class_matrix.max_identifier_length
			= row->max_identifier_length;

	return 0;
}

#define	SKIPSPACES	for(; buf < bend && isspace(*buf); buf++)

static int
_asn1f_parse_class_object_data(arg_t *arg, asn1p_expr_t *eclass,
		struct asn1p_ioc_row_s *row, asn1p_wsyntx_t *syntax,
		uint8_t *buf, const uint8_t *bend,
		int optional_mode, uint8_t **newpos) {
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
			uint8_t *buf_old = buf;
			uint8_t *p = 0;

			SKIPSPACES;

			next_literal = asn1f_next_literal_chunk(syntax, chunk, buf);
			if(!next_literal) {
				p += (bend - p);
			} else {
				p = (uint8_t *)strstr((char *)buf, (char *)next_literal->content.token);
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
			ret = _asn1f_assign_cell_value(arg, row, cell, buf, p);
			if(ret) return ret;
			buf = p;
			if(newpos) *newpos = buf;
		    } break;
		case WC_OPTIONALGROUP: {
			uint8_t *np = 0;
			SKIPSPACES;
			ret = _asn1f_parse_class_object_data(arg, eclass, row,
				chunk->content.syntax, buf, bend, 1, &np);
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
_asn1f_assign_cell_value(arg_t *arg, struct asn1p_ioc_row_s *row, struct asn1p_ioc_cell_s *cell,
		uint8_t *buf, const uint8_t *bend) {
	asn1p_expr_t *expr = (asn1p_expr_t *)NULL;
	int idLength;
	char *p;
	int new_ref = 1;
	asn1p_t *asn;
	asn1p_module_t *mod;
	asn1p_expr_t *type_expr = (asn1p_expr_t *)NULL;
	int i, ret = 0, psize;
	char *pp;

	if((bend - buf) <= 0) {
		FATAL("Assignment warning: empty string is being assigned into %s for %s at line %d",
			cell->field->Identifier,
			arg->expr->Identifier, arg->expr->_lineno);
		return -1;
	}

	p = malloc(bend - buf + 1);
	assert(p);
	memcpy(p, buf, bend - buf);
	p[bend - buf] = '\0';
	/* remove trailing space */
	for (i = bend - buf - 1; (i > 0) && isspace(p[i]); i--)
		p[i] = '\0';

	/* This value 100 should be larger than following formatting string */
	psize = bend - buf + 100;
	pp = malloc(psize);
	if(pp == NULL) {
		free(p);
		return -1;
	}

	if(cell->field->expr_type == A1TC_CLASSFIELD_TFS) {
		ret = snprintf(pp, psize,
			"M DEFINITIONS ::=\nBEGIN\n"
			"V ::= %s\n"
			"END\n",
			p
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
				p
			);
	} else {
		WARNING("asn1c only be able to parse TypeFieldSpec and FixedTypeValueFieldSpec. Failed when parsing %s at line %d\n", p, arg->expr->_lineno);
		free(p);  /* bad idea freeing object you refer to later! */
		free(pp);
		return -1;
	}
	DEBUG("ASN.1 :\n\n%s\n", pp);

	assert(ret < psize);
	psize = ret;

	asn = asn1p_parse_buffer(pp, psize, A1P_NOFLAGS);
	free(pp);
	if(asn == NULL) {
		FATAL("Cannot parse Setting token %s "
			"at line %d",
			p,
			arg->expr->_lineno
		);
		free(p);
		return -1;
	} else {
		mod = TQ_FIRST(&(asn->modules));
		assert(mod);
		expr = TQ_REMOVE(&(mod->members), next);
		assert(expr);

		free(expr->Identifier);
		expr->module = arg->expr->module;
		expr->_lineno = arg->expr->_lineno;
		if (expr->reference) {
			expr->reference->module = arg->expr->module;
			expr->reference->_lineno = arg->expr->_lineno;
			expr->Identifier = strdup(expr->reference->components[expr->reference->comp_count - 1].name);
		} else {
			expr->Identifier = p;
		}
		asn1p_delete(asn);
	}

	if(expr->reference &&
		!asn1f_lookup_symbol(arg, arg->mod, expr->rhs_pspecs, expr->reference)) {

		asn1p_ref_free(expr->reference);
		new_ref = 0;
		expr->reference = type_expr->reference;
		if (asn1f_value_resolve(arg, expr, 0)) {
			expr->reference = 0;
			asn1p_expr_free(expr);
			FATAL("Cannot find %s referenced by %s at line %d",
				p, arg->expr->Identifier,
				arg->expr->_lineno);
			free(p); /* freeing must happen *after* p was used in FATAL() */
			return -1;
		}
	}

	DEBUG("Field %s assignment of %s got %s",
		cell->field->Identifier, p, expr->Identifier);

	cell->value = expr;
	cell->new_ref = new_ref;

	idLength = strlen(expr->Identifier);
	if(row->max_identifier_length < idLength)
		row->max_identifier_length = idLength;

	if(expr->Identifier != p)
		free(p);

	return 0;
}

static asn1p_wsyntx_chunk_t *
asn1f_next_literal_chunk(asn1p_wsyntx_t *syntax, asn1p_wsyntx_chunk_t *chunk, uint8_t *buf)
{
	asn1p_wsyntx_chunk_t *next_chunk;

	next_chunk = TQ_NEXT(chunk, next);
	do {
		if(next_chunk == (struct asn1p_wsyntx_chunk_s *)0) {
			if(!syntax->parent)
				break;
			next_chunk = TQ_NEXT(syntax->parent, next);
		} else if(next_chunk->type == WC_LITERAL) {
			if(strstr((char *)buf, (char *)next_chunk->content.token))
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
