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
		if(wc->ref)
			asn1p_ref_free(wc->ref);
		if(wc->buf)
			free(wc->buf);
		free(wc);
	}
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_clone(asn1p_wsyntx_chunk_t *wc) {
	asn1p_wsyntx_chunk_t *nc;

	nc = asn1p_wsyntx_chunk_new();
	if(nc) {
		if(wc->buf) {
			nc->buf = malloc(wc->len + 1);
			if(nc->buf) {
				nc->len = wc->len;
				memcpy(nc->buf, wc->buf, wc->len);
				nc->buf[nc->len] = '\0';
			}
		}
		if(wc->ref) {
			nc->ref = asn1p_ref_clone(wc->ref);
		}

		if(!nc->ref && !nc->buf) {
			asn1p_wsyntx_chunk_free(nc);
			return NULL;
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
		tmp.ref = ref;
		wc = asn1p_wsyntx_chunk_clone(&tmp);
	} else {
		wc = asn1p_wsyntx_chunk_new();
		if(wc) wc->ref = ref;
	}

	return wc;
}

asn1p_wsyntx_chunk_t *
asn1p_wsyntx_chunk_frombuf(char *buf, int len, int do_copy) {
	asn1p_wsyntx_chunk_t *wc;

	if(do_copy) {
		static asn1p_wsyntx_chunk_t tmp;
		tmp.buf = buf;
		tmp.len = len;
		wc = asn1p_wsyntx_chunk_clone(&tmp);
	} else {
		wc = asn1p_wsyntx_chunk_new();
		if(wc) {
			wc->buf = buf;
			wc->len = len;
		}
	}

	return wc;
}

