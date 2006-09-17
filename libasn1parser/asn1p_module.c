#include <stdlib.h>
#include <string.h>

#include "asn1parser.h"

/*
 * Construct a new empty module.
 */
asn1p_module_t *
asn1p_module_new() {
	asn1p_module_t *mod;

	mod = calloc(1, sizeof *mod);
	if(mod) {
		TQ_INIT(&(mod->exports));
		TQ_INIT(&(mod->imports));
		TQ_INIT(&(mod->members));
	}
	return mod;
}

/*
 * Destroy the module.
 */
void
asn1p_module_free(asn1p_module_t *mod) {
	if(mod) {
		asn1p_expr_t *expr;

		if(mod->ModuleName)
			free(mod->ModuleName);

		if(mod->module_oid)
			asn1p_oid_free(mod->module_oid);

		while((expr = TQ_REMOVE(&(mod->members), next)))
			asn1p_expr_free(expr);

		free(mod);
	}
}

asn1p_t *
asn1p_new() {
	asn1p_t *asn;
	asn = calloc(1, sizeof(*asn));
	if(asn) {
		TQ_INIT(&(asn->modules));
	}
	return asn;
}


void
asn1p_delete(asn1p_t *asn) {
	if(asn) {
		asn1p_module_t *mod;
		while((mod = TQ_REMOVE(&(asn->modules), mod_next)))
			asn1p_module_free(mod);
		free(asn);
	}
}
