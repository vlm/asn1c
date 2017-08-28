/*
 * Structures and prototypes related to parameterization
 */
#ifndef	ASN1_NAMESPACE_H
#define	ASN1_NAMESPACE_H

struct asn1p_ref_s;     /* Forward declaration */
struct asn1p_expr_s;    /* Forward declaration */
struct asn1p_module_s;  /* Forward declaration */

typedef struct asn1_namespace_s {
    struct asn1_namespace_element_s {
        enum {
            NAM_SPACE,  /* The whole search space (e.g. Module) */
            NAM_SYMBOL, /* A particular symbol */
        } selector;
        union {
            struct {
                struct asn1p_module_s *module;
                int stop_search;    /* This module MUST contain the symbol */
            } space;
            struct {
                struct asn1p_ref_s *opt_governor;   /* optional */
                char *identifier;
                struct asn1p_expr_s *resolution;
            } symbol;
        } u;
    } *elements;
    size_t elements_count;
    size_t elements_size;
} asn1_namespace_t;

/*
 * Set callback used to initialize standard namespaces.
 */
void asn1_namespace_add_standard_namespaces_callback(
    void (*)(asn1_namespace_t *));

asn1_namespace_t *asn1_namespace_new(void);
void asn1_namespace_free(asn1_namespace_t *);

asn1_namespace_t *asn1_namespace_clone(const asn1_namespace_t *);

asn1_namespace_t *asn1_namespace_new_from_module(struct asn1p_module_s *mod, int stop_search);

void asn1_namespace_add_module(asn1_namespace_t *,
                               struct asn1p_module_s *module, int stop_search);

void asn1_namespace_add_symbol(asn1_namespace_t *,
                                struct asn1p_ref_s *opt_governor,
                                const char *identifier,
                                struct asn1p_expr_s *resolved_argument);

/*
 * Human-readable namespace layout.
 * Returns a reference to a statically allocated string.
 */
const char *asn1_namespace_string(const asn1_namespace_t *);

/*
 * Create a new namespace by cloning (ns1) and adding (ns2) on top.
 * Destroys (ns2).
 */
asn1_namespace_t *asn1_namespace_new_ND(const asn1_namespace_t *ns1,
                                        asn1_namespace_t *ns2);

/*
 * Introduce and destroy namespace around the given code.
 * This aids memory management around dynamic namespaces.
 */
#define WITH_MODULE_NAMESPACE(mod, ns_var, code)     \
    ({                                               \
        struct asn1_namespace_s *ns_var =           \
            asn1_namespace_new_from_module(mod, 1); \
        typeof(code) ret = code;                     \
        asn1_namespace_free(ns_var);                \
        ret;                                         \
    })

#endif	/* ASN1_NAMESPACE_H */
