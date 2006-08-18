/*
 * CLASS-related stuff.
 */
#ifndef	ASN1_PARSER_CLASS_H
#define	ASN1_PARSER_CLASS_H

#include "asn1p_ref.h"

struct asn1p_expr_s;	/* Forward declaration */

typedef struct asn1p_ioc_row_s {
	struct asn1p_ioc_cell_s {
		struct asn1p_expr_s *field;	/* may never be NULL */
		struct asn1p_expr_s *value;	/* may be left uninitialized */
	} *column;
	int columns;
	int max_identifier_length;
} asn1p_ioc_row_t;

asn1p_ioc_row_t *asn1p_ioc_row_new(struct asn1p_expr_s *oclass);
void asn1p_ioc_row_delete(asn1p_ioc_row_t *);
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
