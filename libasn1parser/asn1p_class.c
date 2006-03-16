#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

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
			free(wc->content.token); break;
		case WC_REFERENCE: asn1p_ref_free(wc->content.ref); break;
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
			nc->content.token = malloc(strlen(wc->content.token)+1);
			strcpy(nc->content.token, wc->content.token);
			break;
		case WC_REFERENCE:
			nc->content.ref = asn1p_ref_clone(wc->content.ref);
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
asn1p_wsyntx_chunk_fromref(asn1p_ref_t *ref, int do_copy) {
	asn1p_wsyntx_chunk_t *wc;

	if(do_copy) {
		static asn1p_wsyntx_chunk_t tmp;
		tmp.type = WC_REFERENCE;
		tmp.content.ref = ref;
		wc = asn1p_wsyntx_chunk_clone(&tmp);
	} else {
		wc = asn1p_wsyntx_chunk_new();
		if(wc) {
			wc->type = WC_REFERENCE;
			wc->content.ref = ref;
		}
	}

	return wc;
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_frombuf(char *buf, int len, int do_copy) {
	asn1p_wsyntx_chunk_t *wc;

	if(do_copy) {
		static asn1p_wsyntx_chunk_t tmp;
		tmp.type = WC_LITERAL;
		tmp.content.token = buf;
		wc = asn1p_wsyntx_chunk_clone(&tmp);
	} else {
		wc = asn1p_wsyntx_chunk_new();
		if(wc) {
			wc->type = WC_LITERAL;
			wc->content.token = buf;
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

