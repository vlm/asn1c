#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

asn1p_ioc_row_t *
asn1p_ioc_row_new(asn1p_expr_t *oclass) {
	asn1p_ioc_row_t *row;
	asn1p_expr_t *field;
	int columns = 0;

	assert(oclass->expr_type == A1TC_CLASSDEF);

	row = calloc(1, sizeof *row);
	if(!row) return NULL;

	TQ_FOR(field, &oclass->members, next)
		columns++;

	row->column = calloc(columns, sizeof *row->column);
	if(!row->column) {
		free(row);
		return NULL;
	}
	row->columns = columns;

	columns = 0;
	TQ_FOR(field, &oclass->members, next) {
		int fieldIdLen = strlen(field->Identifier);
		if(fieldIdLen > row->max_identifier_length)
			row->max_identifier_length = fieldIdLen;
		row->column[columns].field = field;
		row->column[columns].value = NULL;
		columns++;
	}

	return row;
}

void
asn1p_ioc_row_delete(asn1p_ioc_row_t *row) {
	if(row) {
		if(row->column) {
			free(row->column);
		}
		free(row);
	}
}

struct asn1p_ioc_cell_s *
asn1p_ioc_row_cell_fetch(asn1p_ioc_row_t *row, const char *fieldname) {
	int i;
	for(i = 0; i < row->columns; i++) {
		if(strcmp(row->column[i].field->Identifier, fieldname) == 0)
			return &row->column[i];
	}
	errno = ESRCH;
	return NULL;
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_new() {
	asn1p_wsyntx_chunk_t *wc;

	wc = calloc(1, sizeof(*wc));

	return wc;
}

void
asn1p_wsyntx_chunk_free(asn1p_wsyntx_chunk_t *wc) {
	if(wc) {
		switch(wc->type) {
		case WC_LITERAL:
		case WC_WHITESPACE:
		case WC_FIELD:
			free(wc->content.token); break;
		case WC_OPTIONALGROUP:
			asn1p_wsyntx_free(wc->content.syntax);
			break;
		}
		free(wc);
	}
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_clone(asn1p_wsyntx_chunk_t *wc) {
	asn1p_wsyntx_chunk_t *nc;

	nc = asn1p_wsyntx_chunk_new();
	if(nc) {
		nc->type = wc->type;
		switch(wc->type) {
		case WC_LITERAL:
		case WC_WHITESPACE:
		case WC_FIELD:
			nc->content.token = malloc(strlen(wc->content.token)+1);
			strcpy(nc->content.token, wc->content.token);
			break;
		case WC_OPTIONALGROUP:
			nc->content.syntax = asn1p_wsyntx_clone(wc->content.syntax);
			break;
		}
	}

	return nc;
}

asn1p_wsyntx_t *
asn1p_wsyntx_new() {
	asn1p_wsyntx_t *wx;

	wx = calloc(1, sizeof(*wx));
	if(wx) {
		TQ_INIT(&(wx->chunks));
	}

	return wx;
}

void
asn1p_wsyntx_free(asn1p_wsyntx_t *wx) {
	if(wx) {
		asn1p_wsyntx_chunk_t *wc;
		while((wc = TQ_REMOVE(&(wx->chunks), next)))
			asn1p_wsyntx_chunk_free(wc);
		free(wx);
	}
}

asn1p_wsyntx_t *
asn1p_wsyntx_clone(asn1p_wsyntx_t *wx) {
	asn1p_wsyntx_t *nw;

	nw = asn1p_wsyntx_new();
	if(nw) {
		asn1p_wsyntx_chunk_t *wc;
		asn1p_wsyntx_chunk_t *nc;
		TQ_FOR(wc, &(wx->chunks), next) {
			nc = asn1p_wsyntx_chunk_clone(wc);
			if(nc) {
				TQ_ADD(&(nw->chunks), nc, next);
			} else {
				asn1p_wsyntx_free(nw);
				return NULL;
			}
		}
	}

	return nw;
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_fromstring(char *token, int do_copy) {
	asn1p_wsyntx_chunk_t *wc;

	if(do_copy) {
		static asn1p_wsyntx_chunk_t tmp;
		tmp.type = WC_LITERAL;
		tmp.content.token = token;
		wc = asn1p_wsyntx_chunk_clone(&tmp);
	} else {
		wc = asn1p_wsyntx_chunk_new();
		if(wc) {
			wc->type = WC_LITERAL;
			wc->content.token = token;
		}
	}

	return wc;
}


asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_fromsyntax(asn1p_wsyntx_t *syntax) {
	asn1p_wsyntx_chunk_t *wc;

	wc = asn1p_wsyntx_chunk_new();
	if(wc) {
		wc->type = WC_OPTIONALGROUP;
		wc->content.syntax = syntax;
	}

	return wc;
}

