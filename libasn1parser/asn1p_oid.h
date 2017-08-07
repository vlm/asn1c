/*
 * Object Identifier definition.
 */
#ifndef	ASN1_PARSER_OID_H
#define	ASN1_PARSER_OID_H

/********************************
 * Single Object Identifier Arc *
 ********************************/

/*
 * Object identifier arc (one number in the hierarchy).
 */
typedef struct asn1p_oid_arc_s {
	asn1c_integer_t number;	/* -1 if not yet defined */
	char *name;	/* 0 if not defined */
} asn1p_oid_arc_t;


/*
 * Arc constructor.
 */
asn1p_oid_arc_t *asn1p_oid_arc_new(
	const char *optName, asn1c_integer_t optNumber /* = -1 */);
/*
 * Arc destructor.
 */
void asn1p_oid_arc_free(asn1p_oid_arc_t *);


/**************************************************
 * Object Identifier itself, a collection of arcs *
 **************************************************/

/*
 * Object Identifier as a collection of arcs.
 */
typedef struct asn1p_oid_s {
	asn1p_oid_arc_t *arcs;
	int arcs_count;
} asn1p_oid_t;

/*
 * OID constructors.
 */
asn1p_oid_t *asn1p_oid_new(void);
asn1p_oid_t *asn1p_oid_construct(asn1p_oid_arc_t *, int narcs);

/*
 * Add another arc using given one as a template
 */
int asn1p_oid_add_arc(asn1p_oid_t *, asn1p_oid_arc_t *template);

/*
 * OID destructor.
 */
void asn1p_oid_free(asn1p_oid_t *);

/*
 * RETURN VALUES:
 *	0: The specified OIDs are equal.
 *	-1 or 1 otherwise.
 */
int asn1p_oid_compare(const asn1p_oid_t *a, const asn1p_oid_t *b);


#endif	/* ASN1_PARSER_OID_H */
