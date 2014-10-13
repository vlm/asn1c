#include "asn1fix_internal.h"
#include "asn1fix_cws.h"

static int _asn1f_parse_class_object_data(arg_t *, asn1p_expr_t *eclass,
		struct asn1p_ioc_row_s *row, asn1p_wsyntx_t *syntax,
		uint8_t *buf, const uint8_t *bend,
		int optional_mode, uint8_t **newpos);
static int _asn1f_assign_cell_value(arg_t *arg, struct asn1p_ioc_row_s *row, struct asn1p_ioc_cell_s *cell, uint8_t *buf, const uint8_t *bend);

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
			int lbraces = 0;
			uint8_t *p;

			SKIPSPACES;

			p = buf;
			if(p < bend && *p == '{')
				lbraces = 1, p++;
			for(; p < bend; p++) {
				if(lbraces) {
					/* Search the terminating brace */
					switch(*p) {
					case '}': lbraces--; break;
					case '{': lbraces++; break;
					}
				} else if(isspace(*p)) {
					break;
				}
			}
			if(lbraces) {
				FATAL("Field reference %s found in class value definition for %s at line %d can not be satisfied by broken value \"%s\"",
				chunk->content.token,
				arg->expr->Identifier, arg->expr->_lineno, buf);
				if(newpos) *newpos = buf;
				return -1;
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
	asn1p_expr_t *expr;
	asn1p_ref_t *ref;
	int idLength;
	char *p;

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

	if(!isalpha(*p)) {

		if(isdigit(*p)) {
			asn1c_integer_t value;
			if(asn1p_atoi(p, &value)) {
				FATAL("Value %s at line %d is too large for this compiler! Contact the asn1c author.\n", p, arg->expr->_lineno);
				return -1;
			}
			expr = asn1p_expr_new(arg->expr->_lineno, arg->expr->module);
			expr->Identifier = p;
			expr->meta_type = AMT_VALUE; 
			expr->expr_type = ASN_BASIC_INTEGER;
			expr->value = asn1p_value_fromint(value);
		} else {
			WARNING("asn1c is not yet able to parse arbitrary direct values; try converting %s at line %d to a reference.", p, arg->expr->_lineno);
			free(p);
			return 1;
		}
	} else {
		ref = asn1p_ref_new(arg->expr->_lineno);
		asn1p_ref_add_component(ref, p, RLT_UNKNOWN);
		assert(ref);
	
		expr = asn1f_lookup_symbol(arg, arg->mod, arg->expr->rhs_pspecs, ref);
		if(!expr) {
			FATAL("Cannot find %s referenced by %s at line %d",
				p, arg->expr->Identifier,
				arg->expr->_lineno);
			return -1;
		}
	}

	DEBUG("Field %s assignment of %s got %s",
		cell->field->Identifier, p, expr->Identifier);

	cell->value = expr;

	idLength = strlen(expr->Identifier);
	if(row->max_identifier_length < idLength)
		row->max_identifier_length = idLength;

	return 0;
}

