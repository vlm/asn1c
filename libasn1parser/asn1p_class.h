/*
 * CLASS-related stuff.
 */
#ifndef	ASN1_PARSER_CLASS_H
#define	ASN1_PARSER_CLASS_H

#include "asn1p_ref.h"

/*
 * WITH SYNTAX free-form chunks.
 */
typedef struct asn1p_wsyntx_chunk_s {
	enum {
		WC_LITERAL,
		WC_REFERENCE,
		WC_OPTIONALGROUP
	} type;
	/*
	 * WC_LITERAL -> {buf, len}
	 * WC_REFERENCE -> {ref}
	 * WC_OPTIONALGROUP -> {syntax}
	 */
	union {
		char	*token;
		asn1p_ref_t *ref;
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
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_fromref(asn1p_ref_t *ref, int do_copy);
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_frombuf(char *buf, int len, int _copy);
asn1p_wsyntx_chunk_t *asn1p_wsyntx_chunk_fromsyntax(asn1p_wsyntx_t *syntax);


#endif	/* ASN1_PARSER_CLASS_H */
