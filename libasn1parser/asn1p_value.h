/*
 * A generic value of different syntaxes.
 */
#ifndef	ASN1_PARSER_VALUE_H
#define	ASN1_PARSER_VALUE_H

/*
 * A wrapper around various kinds of values.
 */
typedef struct asn1p_value_s {
	/*
	 * The value of the element.
	 */
	enum {
		ATV_NOVALUE,
		ATV_REFERENCED,
		ATV_REAL,
		ATV_INTEGER,
		ATV_MIN,
		ATV_MAX,
		ATV_FALSE,
		ATV_TRUE,
		ATV_STRING,
		ATV_UNPARSED,
		ATV_BITVECTOR,
	} type;	/* Value type and location */

	union {
		asn1p_ref_t	*reference;
		asn1_integer_t	 v_integer;
		double		 v_double;
		/*
		 * Binary bits vector.
		 */
		struct {
			uint8_t *buf;
			int size;
		} string;
		struct {
			uint8_t *bits;
			int size_in_bits;
		} binary_vector;
	} value;
} asn1p_value_t;

/*
 * Constructors and destructor for value.
 * If ref, bits or buffer are omitted, the corresponding function returns
 * (asn1p_value_t *)0 with errno = EINVAL.
 * Allocated value (where applicable) is guaranteed to be NUL-terminated.
 */
asn1p_value_t *asn1p_value_fromref(asn1p_ref_t *ref, int do_copy);
asn1p_value_t *asn1p_value_frombits(uint8_t *bits, int size_in_bits, int dc);
asn1p_value_t *asn1p_value_frombuf(char *buffer, int size, int do_copy);
asn1p_value_t *asn1p_value_fromdouble(double);
asn1p_value_t *asn1p_value_fromint(asn1_integer_t);
asn1p_value_t *asn1p_value_clone(asn1p_value_t *);
void asn1p_value_free(asn1p_value_t *);

#endif	/* ASN1_PARSER_VALUE_H */
