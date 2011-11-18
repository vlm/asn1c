#include "asn1fix_internal.h"

static int _consume_sp(uint8_t **pbuf, int *psize) {
	int numsp = 0;
	for(; *psize > 0; (*psize)--, (*pbuf)++) {
		if(**pbuf == ' ' || **pbuf == '\n' || **pbuf == '\r' || **pbuf == '\t') {
			numsp++;
			continue;
		} else {
			break;
		}
	}
	return numsp;
}

/*
 * Parse and convert the OBJECT IDENTIFIER and RELATIVE-OID types.
 */
int
asn1f_fix_oid(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	uint8_t *buf;
	int size;
	asn1p_oid_t *oid;
	asn1p_oid_arc_t arc = {NULL, NULL}; /* scratch arc */

	if(expr->expr_type != ASN_BASIC_OBJECT_IDENTIFIER &&
		expr->expr_type != ASN_BASIC_RELATIVE_OID)
		return 0;	/* Just ignore it */
	if(expr->meta_type != AMT_VALUE)
		return 0;
	if(expr->value->type == ATV_REFERENCED)
		return 0;

	DEBUG("(\"%s\", %x) for line %d",
		expr->Identifier, expr->expr_type, expr->_lineno);

	assert(expr->members.tq_head == NULL);
	assert(expr->value);
	
	if(expr->value->type != ATV_UNPARSED) {
		FATAL("OBJECT IDENTIFIER %s at line %d is not unparsed",
			expr->Identifier, expr->_lineno);
		return -1;
	}
	
	/*
	 * Bare minimum is 2 for {}
	 */
	if(expr->value->value.string.size < 2 ||
		expr->value->value.string.buf == NULL ||
		expr->value->value.string.buf[0] != '{') {
		FATAL("OBJECT IDENTIFIER %s at line %d does not start with a '{'",
			expr->Identifier, expr->_lineno);
		return -1;
	}
	
	buf = expr->value->value.string.buf + 1; // consume {
	size = expr->value->value.string.size - 1;
	
	oid = asn1p_oid_new();
	if(!oid)
		return -1;
	
	/* Imagine: { joint-iso-itu-t asn1(1) packed-encoding(3) 0 0 }
	 * First, consume spaces.
	 */
	_consume_sp(&buf, &size);
	
	while(1) {
		if(size <= 0) {
			FATAL("OBJECT IDENTIFIER %s at line %d ends prematurely",
				expr->Identifier, expr->_lineno);
			asn1p_oid_free(oid);
			return -1;
		} else if(buf[0] >= '0' && buf[0] <= '9') {
			/*
			 * Treat as decimal arc.
			 */
			uint8_t *arcbuf = buf;
			uint8_t substbyte;

			for(; size > 0 && *buf >= '0' && *buf <= '9'; buf++, size--);
			/* not supposed to overshoot--there should be a '}' left over at worst */
			assert(size > 0); /* guaranteed by bison parser */

			substbyte = buf[0]; /* copy the byte out, because we are replacing it with NULL */
			buf[0] = '\0';
			arc.number = (char*)arcbuf;
			arc.name = NULL;
			if (asn1p_oid_add_arc(oid, &arc)) {
				/* ran out of memory */
				asn1p_oid_free(oid);
				return -1;
			}
			buf[0] = substbyte; /* revert the byte */
			_consume_sp(&buf, &size);
		} else if(buf[0] >= 'a' && buf[0] <= 'z') {
			/*
			 * Treat as named arc.
			 */
			uint8_t substbyte_name, substbyte_number = 0xFF;
			uint8_t *bufname_end, *bufnumber_end = NULL;
			arc.name = (char*)buf;
			arc.number = NULL;
			
			/* consume identifier */
			for(; size > 0 && (
				 (*buf >= 'a' && *buf <= 'z') ||
				 (*buf >= 'A' && *buf <= 'Z') ||
				 (*buf == '-') ||
				 (*buf >= '0' && *buf <= '9'));
				buf++, size--);
			assert(size > 0);
			substbyte_name = buf[0];
			bufname_end = buf;
			
			_consume_sp(&buf, &size);
			assert(size > 0);
			if(buf[0] == '(') {
				buf++;
				_consume_sp(&buf, &size);
				
				arc.number = (char*)buf;
				for(; size > 0 && *buf >= '0' && *buf <= '9'; buf++, size--);
				assert(size > 0);
				if(arc.number == (char*)buf) {
					FATAL("OBJECT IDENTIFIER %s at line %d: primary identifier in parentheses "
						"is not a number", expr->Identifier, expr->_lineno);
					asn1p_oid_free(oid);
					return -1;
				}
				bufnumber_end = buf;
				substbyte_number = buf[0];
				_consume_sp(&buf, &size);
				assert(size > 0);
				if(buf[0] != ')') {
					FATAL("OBJECT IDENTIFIER %s at line %d is missing a ')' after "
						"the primary numeric identifier", expr->Identifier, expr->_lineno);
					asn1p_oid_free(oid);
					return -1;
				}
				buf++; /* consume the ')' */
				_consume_sp(&buf, &size);
			}

			/* NULL-terminate the name and number */
			*bufname_end = '\0';
			if(bufnumber_end) *bufnumber_end = '\0';
			
			/* now we have name or name+number */
			if(asn1p_oid_add_arc(oid, &arc)) {
				/* ran out of memory */
				asn1p_oid_free(oid);
				return -1;
			}
			*bufname_end = substbyte_name; /* revert the byte after the end of the name */
			if (bufnumber_end) *bufnumber_end = substbyte_number;
		} else if(buf[0] == '}') {
			/*
			 * Terminate.
			 */
			break;
		} else {
			FATAL("OBJECT IDENTIFIER %s at line %d has an invalid part: %s",
				expr->Identifier, expr->_lineno, buf);
			asn1p_oid_free(oid);
			return -1;
		}
	}

	free(expr->value->value.string.buf);
	expr->value->type = ATV_OBJECT_IDENTIFIER;
	expr->value->value.oid = oid; /* transfer ownership */
	return 0;
}

