/*
 * CLASS-related stuff.
 */
#ifndef	ASN1_PARSER_CLASS_H
#define	ASN1_PARSER_CLASS_H

struct asn1p_expr_s;	/* Forward declaration */

typedef struct asn1p_ioc_row_s {
	struct asn1p_ioc_cell_s {
		struct asn1p_expr_s *field;	/* may never be NULL */
		struct asn1p_expr_s *value;	/* may be left uninitialized */
		int new_ref;
	} *column;
	size_t columns;
} asn1p_ioc_row_t;

asn1p_ioc_row_t *asn1p_ioc_row_new(struct asn1p_expr_s *oclass);
asn1p_ioc_row_t *asn1p_ioc_row_clone(asn1p_ioc_row_t *src, int base_idx);
size_t asn1p_ioc_row_max_identifier_length(asn1p_ioc_row_t *);
void asn1p_ioc_row_delete(asn1p_ioc_row_t *);

typedef struct asn1p_ioc_table_s {
    asn1p_ioc_row_t **row;
    size_t rows;
    int extensible; /* 0 if non-extensible (sealed). Otherwise, extensible. */
} asn1p_ioc_table_t;

asn1p_ioc_table_t *asn1p_ioc_table_new(void);
void asn1p_ioc_table_add(asn1p_ioc_table_t *, asn1p_ioc_row_t *row);
void asn1p_ioc_table_append(asn1p_ioc_table_t *it, asn1p_ioc_table_t *src);
size_t asn1p_ioc_table_max_identifier_length(asn1p_ioc_table_t *);
void asn1p_ioc_table_free(asn1p_ioc_table_t *);

/*
 * Match is similar to a comparison,
 * but -1 means error and 1 means not equal. 0 is OK
 */
int asn1p_ioc_row_match(const asn1p_ioc_row_t *, const asn1p_ioc_row_t *);

struct asn1p_ioc_cell_s *asn1p_ioc_row_cell_fetch(asn1p_ioc_row_t *,
		const char *fieldname);

/*
 * WITH SYNTAX free-form chunks.
 */
typedef struct asn1p_wsyntx_chunk_s {
	enum {
		WC_LITERAL,
		WC_WHITESPACE,
		WC_FIELD,
		WC_OPTIONALGROUP
	} type;
	/*
	 * WC_LITERAL -> {token}
	 * WC_WHITESPACE -> {token}
	 * WC_FIELD -> {token}
	 * WC_OPTIONALGROUP -> {syntax}
	 */
	union {
		char *token;
		struct asn1p_wsyntx_s *syntax;
	} content;

	TQ_ENTRY(struct asn1p_wsyntx_chunk_s) next;
} asn1p_wsyntx_chunk_t;

typedef struct asn1p_wsyntx_s {

	struct asn1p_wsyntx_chunk_s *parent;

	TQ_HEAD(struct asn1p_wsyntx_chunk_s) chunks;

} asn1p_wsyntx_t;


/*
 * Constructor, destructor and cloning function.
 */
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_new(void);
void asn1p_wsyntx_chunk_free(asn1p_wsyntx_chunk_t *);
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_clone(asn1p_wsyntx_chunk_t *);

asn1p_wsyntx_t *asn1p_wsyntx_new(void);
void asn1p_wsyntx_free(asn1p_wsyntx_t *);
asn1p_wsyntx_t *asn1p_wsyntx_clone(asn1p_wsyntx_t *);

/*
 * RETURN VALUES:
 * 	 0:	Component has been added
 * 	-1:	Failure to add component (refer to errno)
 */
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_fromstring(char *token, int _copy);
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_fromsyntax(asn1p_wsyntx_t *syntax);


#endif	/* ASN1_PARSER_CLASS_H */
