#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asn1_hash.h"


/* 
 * Insert data pointer into a hash using each character of string s as key.
 *
 * Return 0 if insertion is done.
 * Return -1 if insertion is failed.
 * Return existing pointer with the same key.
 */
void *
asn1_hash_insert(asn1_hash_t **root, const char *s, void *data) {
    asn1_hash_t *curr, **p_curr;
    const char *c;

    if (!root || !s)
        return (void *)-1;

    c = (const char *)s;
    p_curr = root;
    while ((curr = *p_curr)) {
        if (*c == curr->ch) {
            if (*c++ == 0) {
               return (void *)curr->equal;
            }
            p_curr = &(curr->equal);
        } else if (*c < curr->ch)
            p_curr = &(curr->left);
        else
            p_curr = &(curr->right);
    }

    for (;;) {
        if (!(*p_curr = (asn1_hash_t *)calloc(1, sizeof(asn1_hash_t)))) {
             return (void *)-1;
        }

        curr = *p_curr;
        curr->ch = *c;
        curr->left = curr->right = curr->equal = (asn1_hash_t *)0;

        if (*c++ == 0) {
            curr->equal = (asn1_hash_t *)data;
            return 0;
        }
        p_curr = &(curr->equal);
    }
}

/* 
 * Search the hash using each character of string s as key.
 */
void *
asn1_hash_search(const asn1_hash_t *root, const char *s) {
    const asn1_hash_t *curr;

    curr = root;
    while (curr) {
        if (*s == curr->ch) {
            if (*s == 0)
                return (void *)curr->equal;
            s++;
            curr = curr->equal;
        } else if (*s < curr->ch)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return (void *)0;
}

/* 
 * Traverse the hash.
 */
void asn1_hash_traverse_fn(asn1_hash_t *p,
                           void (*fn)(void *fn_data, void *node_data)) {
    asn1_hash_traverse_fn_with_data(p, fn, NULL);
}

void asn1_hash_traverse_fn_with_data(asn1_hash_t *p,
                                     void (*fn)(void *fn_data, void *node_data), 
                                     void *fn_data) {
    if (!p)
        return;

    asn1_hash_traverse_fn_with_data(p->left, fn, fn_data);
    if (p->ch)
       asn1_hash_traverse_fn_with_data(p->equal, fn, fn_data);
    else if (fn)
       fn(fn_data, p->equal);
    asn1_hash_traverse_fn_with_data(p->right, fn, fn_data);
}

/*
 * Destroy the ternary tree.
 */
void
asn1_hash_destroy(asn1_hash_t *p) {
    asn1_hash_destroy_with_cleanup(p, NULL);
}

void
asn1_hash_destroy_with_cleanup(asn1_hash_t *p,
                               void (*cleanup)(void *data)) {
    if (!p)
        return;

    asn1_hash_destroy_with_cleanup(p->left, cleanup);
    if (p->ch)
       asn1_hash_destroy_with_cleanup(p->equal, cleanup);
    else if (cleanup)
       cleanup(p->equal);
    asn1_hash_destroy_with_cleanup(p->right, cleanup);
    free(p);
}
