#include "asn1c_internal.h"
#include "asn1c_out.h"

/*
 * Add an elementary chunk of target language text
 * into appropriate output stream.
 */
int
asn1c_compiled_output(arg_t *arg, const char *fmt, ...) {
	struct compiler_stream_destination_s *dst;
	const char *p;
	int lf_found;
	va_list ap;
	out_chunk_t *m;
	int ret;

	switch(arg->target->target) {
	case OT_IGNORE:
		return 0;
	default:
		dst = &arg->target->destination[arg->target->target];
		break;
	}

	/*
	 * Make sure the output has a single LF and only at the end.
	 */
	for(lf_found = 0, p = fmt; *p; p++) {
		if(*p == '\n') {
			lf_found++;
			assert(p[1] == '\0');
		}
	}
	assert(lf_found <= 1);

	/*
	 * Print out the indentation.
	 */
	if(dst->indented == 0) {
		int i = dst->indent_level;
		dst->indented = 1;
		while(i--) {
			ret = asn1c_compiled_output(arg, "\t");
			if(ret == -1) return -1;
		}
	}
	if(lf_found)
		dst->indented = 0;

	/*
	 * Allocate buffer.
	 */
	m = calloc(1, sizeof(out_chunk_t));
	if(m == NULL) return -1;

	m->len = 16;
	do {
		void *tmp;
		m->len <<= 2;
		tmp = realloc(m->buf, m->len);
		if(tmp) {
			m->buf = (char *)tmp;
		} else {
			free(m->buf);
			free(m);
			return -1;
		}
		va_start(ap, fmt);
		ret = vsnprintf(m->buf, m->len, fmt, ap);
		va_end(ap);
	} while(ret >= (m->len - 1) || ret < 0);

	m->len = ret;

	if(arg->target->target == OT_INCLUDES
	|| arg->target->target == OT_FWD_DECLS
	|| arg->target->target == OT_POST_INCLUDE) {
		out_chunk_t *v;
		TQ_FOR(v, &dst->chunks, next) {
			if(m->len == v->len
			&& !memcmp(m->buf, v->buf, m->len))
				break;
		}
		if(v) {
			/* Entry is already present. Skip it. */
			free(m->buf);
			free(m);
			return 0;
		}
	}

	TQ_ADD(&dst->chunks, m, next);

	return 0;
}
