#include "asn1fix_internal.h"

struct _cstring_pattern {
	char *start;
	size_t length;
};
static int _asn1f_cstring_find_line_pattern(char *s, struct _cstring_pattern *);

int
asn1f_fix_cstring(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;

	if(expr->value && expr->value->type == ATV_STRING) {
		struct _cstring_pattern cp;
		char *buf = (char *)expr->value->value.string.buf;
		int buflen = expr->value->value.string.size;
		int start = 0;

		DEBUG("(%s) for line %d", expr->Identifier, expr->_lineno);

		while(_asn1f_cstring_find_line_pattern(buf + start, &cp)) {
			assert(cp.length);
			memmove(cp.start, cp.start + cp.length,
				buflen - ((cp.start + cp.length) - buf));
			buflen -= cp.length;
			start = cp.start - buf;
			buf[buflen] = '\0';
		}
	}

	return r_value;
}

/*
 * If a string has a newline, the tabulation and spaces before and
 * after it must be eliminated.
 */
static int
_asn1f_cstring_find_line_pattern(char *s, struct _cstring_pattern *cp) {
	int newline_found = 0;

	cp->start = NULL;

	for(;;s++) {
		switch(*s) {
		case '\r': case '\n':
			newline_found = 1;
			/* Fall through */
		case ' ': case '\t':
			if(cp->start == NULL)
				cp->start = s;
			continue;
		case '\0':
		default:
			if(newline_found) {
				cp->length = (size_t)(s - cp->start);
				return 1;
			}

			cp->start = NULL;
			if(*s == '\0')
				break;
			continue;
		}
		break;
	}

	return 0;
}


