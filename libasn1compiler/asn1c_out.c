#include "asn1c_internal.h"

/*
 * Add an elementary chunk of target language text
 * into appropriate output stream.
 */
int
asn1c_compiled_output(arg_t *arg, const char *fmt, ...) {
	const char *p;
	int lf_found;
	va_list ap;
	out_chunk_t *m;
	char *buf;
	int ret;

	switch(arg->target->target) {
	case OT_IGNORE:
		return 0;
	case OT_ASSERT:
		assert(arg->target->target != OT_ASSERT);
		return -1;
	default:
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
	if(arg->indented == 0) {
		int i = arg->indent_level;
		arg->indented = 1;
		while(i--) {
			ret = asn1c_compiled_output(arg, "\t");
			if(ret == -1) return -1;
		}
	}
	if(lf_found)
		arg->indented = 0;

	/*
	 * Estimate necessary size.
	 */
	buf = "";
	va_start(ap, fmt);
	ret = vsnprintf(buf, 0, fmt, ap);
	va_end(ap);
	assert(ret >= 0);

	/*
	 * Allocate buffer.
	 */
	m = calloc(1, sizeof(out_chunk_t));
	if(m == NULL) return -1;
	m->len = ret + 1;
	m->buf = malloc(ret + 1);
	if(m->buf == NULL) {
		free(m);
		return -1;
	}

	/*
	 * Fill the buffer.
	 */
	va_start(ap, fmt);
	ret = vsnprintf(m->buf, m->len, fmt, ap);
	assert(ret < m->len);
	m->len = ret;
	va_end(ap);

	if(arg->target->target == OT_INCLUDES) {
		out_chunk_t *v;
		TQ_FOR(v, &(arg->target->targets[OT_INCLUDES]), next) {
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

	TQ_ADD(&(arg->target->targets[arg->target->target]), m, next);

	return 0;
}
