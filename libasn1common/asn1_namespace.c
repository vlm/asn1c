#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1_ref.h"
#include "asn1_buffer.h"
#include "asn1_namespace.h"

static void (*_add_standard_namespaces_cb)(asn1_namespace_t *);

void
asn1_namespace_add_standard_namespaces_callback(
    void (*cb)(asn1_namespace_t *)) {
    _add_standard_namespaces_cb = cb;
}

asn1_namespace_t *
asn1_namespace_new() {
    asn1_namespace_t *ns = calloc(1, sizeof(*ns));

    if(_add_standard_namespaces_cb) {
        _add_standard_namespaces_cb(ns);
    }

    return ns;
}

void
asn1_namespace_free(asn1_namespace_t *ns) {
    if(ns) {
        for(size_t i = 0; i < ns->elements_count; i++) {
            switch(ns->elements[i].selector) {
            case NAM_SPACE:
                break;
            case NAM_SYMBOL:
                free(ns->elements[i].u.symbol.identifier);
                break;
            }
        }
        free(ns->elements);
        free(ns);
    }
}

asn1_namespace_t *
asn1_namespace_clone(const asn1_namespace_t *old_ns) {
    asn1_namespace_t *new_ns = calloc(1, sizeof(*new_ns));

    for(size_t i = 0; i < old_ns->elements_count; i++) {
        switch(old_ns->elements[i].selector) {
        case NAM_SPACE:
            asn1_namespace_add_module(new_ns,
                                       old_ns->elements[i].u.space.module,
                                       old_ns->elements[i].u.space.stop_search);
            break;
        case NAM_SYMBOL:
            asn1_namespace_add_symbol(
                new_ns, old_ns->elements[i].u.symbol.opt_governor,
                old_ns->elements[i].u.symbol.identifier,
                old_ns->elements[i].u.symbol.resolution);
            break;
        }
    }

    return new_ns;
}

static size_t
_add_element(asn1_namespace_t *ns) {
    size_t idx = ns->elements_count;

    if(ns->elements_count >= ns->elements_size) {
        size_t elc = ns->elements_size ? ns->elements_size * 2 : 4;
        ns->elements = realloc(ns->elements, sizeof(ns->elements[0]) * elc);
        ns->elements_size = elc;
    }

    ns->elements_count++;
    return idx;
}

void
asn1_namespace_add_symbol(asn1_namespace_t *ns,
                          struct asn1p_ref_s *opt_governor,
                          const char *identifier,
                          struct asn1p_expr_s *resolved_argument) {
    size_t idx = _add_element(ns);

    ns->elements[idx].selector = NAM_SYMBOL;
    ns->elements[idx].u.symbol.opt_governor = opt_governor;
    ns->elements[idx].u.symbol.identifier = strdup(identifier);
    ns->elements[idx].u.symbol.resolution = resolved_argument;
}

asn1_namespace_t *
asn1_namespace_new_from_module(struct asn1p_module_s *module, int stop_search) {
    asn1_namespace_t *ns = asn1_namespace_new();
    asn1_namespace_add_module(ns, module, stop_search);
    return ns;
}

void
asn1_namespace_add_module(asn1_namespace_t *ns, struct asn1p_module_s *module,
                          int stop_search) {
    size_t idx = _add_element(ns);

    ns->elements[idx].selector = NAM_SPACE,
    ns->elements[idx].u.space.module = module;
    ns->elements[idx].u.space.stop_search = stop_search;
}

const char *
asn1_namespace_string(const asn1_namespace_t *ns) {
    static abuf ab;

    abuf_clear(&ab);

    if(ns) {
        abuf_str(&ab, "{");
        for(size_t i = 0; i < ns->elements_count; i++) {
            if(i) abuf_str(&ab, ",");
            switch(ns->elements[i].selector) {
            case NAM_SPACE:
                abuf_printf(
                    &ab, "M:\"%s\"%s",
                    *(const char *const *)ns->elements[i].u.space.module,
                    ns->elements[i].u.space.stop_search ? "!" : "");
                break;
            case NAM_SYMBOL:
                abuf_printf(&ab, "S:\"%s%s%s\"",
                            ns->elements[i].u.symbol.opt_governor
                                ? asn1p_ref_string(
                                      ns->elements[i].u.symbol.opt_governor)
                                : "",
                            ns->elements[i].u.symbol.opt_governor ? ":" : "",
                            ns->elements[i].u.symbol.identifier);
                break;
            }
        }
        abuf_str(&ab, "}");
        return ab.buffer;
    } else {
        return "<no namespace>";
    }
}

