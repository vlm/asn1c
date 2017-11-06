/*
 * Structures and prototypes ternary search tree
 */
#ifndef ASN1_HASH_H
#define ASN1_HASH_H

typedef struct asn1_hash_s {
    struct asn1_hash_s *left;
    struct asn1_hash_s *right;
    struct asn1_hash_s *equal;   /* serves as pointer to node or 
                                    data if key = '\0' */ 

    char ch;                     /* character */

} asn1_hash_t;

void *asn1_hash_insert(asn1_hash_t **root, const char *s, void *data);
void *asn1_hash_search(const asn1_hash_t *root, const char *s);
void asn1_hash_traverse_fn(asn1_hash_t *p,
                           void (*fn)(void *fn_data, void *node_data));
void asn1_hash_traverse_fn_with_data(asn1_hash_t *p,
                                     void (*fn)(void *fn_data, void *node_data),
                                     void *fn_data);
void asn1_hash_destroy(asn1_hash_t *p);
void asn1_hash_destroy_with_cleanup(asn1_hash_t *p,
                                    void (*cleanup)(void *data));

#endif /* ASN1_HASH_H */

