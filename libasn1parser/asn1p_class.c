#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"
#include "asn1p_class.h"

asn1p_ioc_table_t *
asn1p_ioc_table_new() {
    asn1p_ioc_table_t *it = calloc(1, sizeof(*it));
    assert(it);
    return it;
}

void
asn1p_ioc_table_add(asn1p_ioc_table_t *it, asn1p_ioc_row_t *row) {
    assert(it);

    asn1p_ioc_row_t **new_rows =
        realloc(it->row, (it->rows + 1) * sizeof(it->row[0]));
    assert(new_rows);
    it->row = new_rows;
    it->row[it->rows++] = row;
}

void
asn1p_ioc_table_append(asn1p_ioc_table_t *it, asn1p_ioc_table_t *src) {
    int base_idx;

    if(!src || !it) return;

    base_idx = it->rows;
    for(size_t i = 0; i < src->rows; i++) {
        asn1p_ioc_table_add(it, asn1p_ioc_row_clone(src->row[i], base_idx));
    }
}

void
asn1p_ioc_table_free(asn1p_ioc_table_t *it) {
    if(it) {
        for(size_t i = 0; i < it->rows; i++) {
            asn1p_ioc_row_delete(it->row[i]);
        }
        free(it->row);
        free(it);
    }
}

size_t
asn1p_ioc_table_max_identifier_length(asn1p_ioc_table_t *it) {
    size_t max_length = 0;
    if(it) {
        for(size_t i = 0; i < it->rows; i++) {
            size_t len = asn1p_ioc_row_max_identifier_length(it->row[i]);
            if(len > max_length) max_length = len;
        }
    }
    return max_length;
}

size_t
asn1p_ioc_row_max_identifier_length(asn1p_ioc_row_t *row) {
    size_t max_length = 0;
    if(row) {
        for(size_t i = 0; i < row->columns; i++) {
            if(row->column[i].value) {
                size_t len = strlen(row->column[i].value->Identifier);
                if(len > max_length) max_length = len;
            }
        }
    }
    return max_length;
}

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
		row->column[columns].field = field;
		row->column[columns].value = NULL;
		columns++;
	}

	return row;
}

asn1p_ioc_row_t *
asn1p_ioc_row_clone(asn1p_ioc_row_t *src, int base_idx) {
	asn1p_ioc_row_t *row;

	row = calloc(1, sizeof *row);
	if(!row) return NULL;

	row->column = calloc(src->columns, sizeof *src->column);
	if(!row->column) {
		free(row);
		return NULL;
	}
	row->columns = src->columns;

	for(size_t i = 0; i < src->columns; i++) {
		row->column[i].field = src->column[i].field;
		row->column[i].value = 0;
		if(src->column[i].value) {
			row->column[i].value = asn1p_expr_clone(src->column[i].value, 0);
			row->column[i].value->_type_unique_index += base_idx;
		}
		row->column[i].new_ref = 1;
	}

	return row;
}

void
asn1p_ioc_row_delete(asn1p_ioc_row_t *row) {
	if(row) {
		if(row->column) {
			for(size_t i = 0; i < row->columns; i++) {
				if(!row->column[i].new_ref && row->column[i].value) {
					/* 
					 * Field 'reference' comes from asn1fix_cws.c :
					 * TQ_FIRST(&cell->field->members)->reference
					 * so it should not be freed here.
					 */
					row->column[i].value->reference = NULL;
				}
				asn1p_expr_free(row->column[i].value);
			}
			free(row->column);
		}
		free(row);
	}
}

int
asn1p_ioc_row_match(const asn1p_ioc_row_t *a, const asn1p_ioc_row_t *b) {
    assert(a && b);

    if(a->columns != b->columns)
        return -1;  /* Bad! */

    for(size_t i = 0; i < a->columns; i++) {
        assert(a->column[i].field);
        assert(b->column[i].field);
        if(strcmp(a->column[i].field->Identifier,
                  b->column[i].field->Identifier)
           != 0) {
            return -1;  /* Bad! */
        }
        if((a->column[i].value && !b->column[i].value)
           || (!a->column[i].value && b->column[i].value)) {
            return 1;   /* Not match */
        }
        if(a->column[i].value && b->column[i].value) {
            if(asn1p_expr_compare(a->column[i].value, b->column[i].value)
               != 0) {
                return 1;   /* Not match */
            }
        }
    }

    return 0;
}

struct asn1p_ioc_cell_s *
asn1p_ioc_row_cell_fetch(asn1p_ioc_row_t *row, const char *fieldname) {
	for(size_t i = 0; i < row->columns; i++) {
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
		syntax->parent = wc;
	}

	return wc;
}

