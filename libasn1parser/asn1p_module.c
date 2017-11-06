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
		asn1p_xports_t *xports;

		free(mod->ModuleName);
		free(mod->source_file_name);

		asn1p_oid_free(mod->module_oid);

		while((xports = TQ_REMOVE(&(mod->exports), xp_next)))
			asn1p_xports_free(xports);

		while((xports = TQ_REMOVE(&(mod->imports), xp_next)))
			asn1p_xports_free(xports);

		while((expr = TQ_REMOVE(&(mod->members), next)))
			asn1p_expr_free(expr);

		asn1_hash_destroy(mod->members_hash);

		free(mod);
	}
}

void
asn1p_module_build_name_hash(asn1p_module_t *mod) {
	asn1p_expr_t *expr;

	if(!mod || mod->members_hash)
             return;

	TQ_FOR(expr, &(mod->members), next) {
		asn1_hash_insert(&mod->members_hash,
                                 expr->Identifier, expr);
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
