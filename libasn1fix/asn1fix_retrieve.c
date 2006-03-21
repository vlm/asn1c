#include "asn1fix_internal.h"

enum ftt_what {
	FTT_TYPE,	/* Find the type of the given expression */
	FTT_VALUE,	/* Find the value of the given expression */
};

static asn1p_expr_t *asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr, enum ftt_what);
static int asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name);


/*
 * Lookup a child by its name.
 */
asn1p_expr_t *
asn1f_lookup_child(asn1p_expr_t *tc, const char *name) {
	asn1p_expr_t *child_tc;

	TQ_FOR(child_tc, &(tc->members), next) {
		if(child_tc->Identifier
		&& strcmp(child_tc->Identifier, name) == 0) {
			return child_tc;
		}
	}

	errno = ESRCH;
	return NULL;
}

asn1p_module_t *
asn1f_lookup_in_imports(arg_t *arg, asn1p_module_t *mod, const char *name) {
	asn1p_xports_t *xp;
	asn1p_expr_t *tc;

	/*
	 * Search in which exactly module this name is defined.
	 */
	TQ_FOR(xp, &(mod->imports), xp_next) {
		TQ_FOR(tc, &(xp->members), next) {
			if(strcmp(name, tc->Identifier) == 0)
				break;
		}
		if(tc) break;
	}
	if(xp == NULL) {
		errno = ESRCH;
		return NULL;
	}

	/*
	 * Okay, right now we have a module name and, hopefully, an OID.
	 * Search the arg->asn for the specified module.
	 */
	mod = asn1f_lookup_module(arg, xp->fromModuleName, xp->identifier.oid);
	if(mod == NULL) {
		/* Conditional debug */
		if(!(arg->expr->_mark & TM_BROKEN)) {
			arg->expr->_mark |= TM_BROKEN;
			FATAL("Cannot find external module \"%s\" "
				"mentioned for "
				"\"%s\" at line %d. "
				"Obtain this module and instruct compiler to process it too.",
				xp->fromModuleName, name, arg->expr->_lineno);
		}
		/* ENOENT/ETOOMANYREFS */
		return NULL;
	}

	/*
	 * Check that the EXPORTS section of this module contains
	 * the symbol we care about, or it is EXPORTS ALL.
	 */
	if(asn1f_compatible_with_exports(arg, mod, name)) {
		errno = EPERM;
		return NULL;
	}

	return mod;
}

asn1p_module_t *
asn1f_lookup_module(arg_t *arg, const char *module_name, asn1p_oid_t *oid) {
	asn1p_module_t *mod;

	assert(module_name);

	/*
	 * If OID is given, the module_name is unused.
	 * If OID is not given, the module_name may mean
	 * either the real module's name, or the symbol which is the
	 * result of renaming. Check this first.
	 */
	if(oid == 0) {
		asn1p_xports_t *xp;
		/*
		 * Check inside the IMPORTS section for possible renaming.
		 * Renaming practically means that a module_name is mentioned
		 * somewhere in the IMPORTS section AND OID is given.
		 */
		TQ_FOR(xp, &(arg->mod->imports), xp_next) {
			if(strcmp(module_name, xp->fromModuleName))
				continue;
			if(oid) {
				FATAL("Ambiguous reference: "
					"%s "
					"matches several modules",
					module_name);
				errno = ETOOMANYREFS;
				return NULL;
			}
			/*
			 * Yes, there is a renaming.
			 * Make lookup use OID instead.
			 */
			oid = xp->identifier.oid;
		}
	}

	/*
	 * Perform lookup using OID or module_name.
	 */
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		if(oid) {
			if(mod->module_oid) {
				if(asn1p_oid_compare(oid,
					mod->module_oid)) {
					continue;
				} else {
					/* Match! Even if name doesn't. */
					return mod;
				}
			} else {
				/* Not match, even if name is the same. */
				continue;
			}
		}
	
		if(strcmp(module_name, mod->ModuleName) == 0)
			return mod;
	}

	DEBUG("\tModule \"%s\" not found", module_name);

	errno = ENOENT;
	return NULL;
}

static asn1p_expr_t *
asn1f_lookup_symbol_impl(arg_t *arg, asn1p_module_t *mod, asn1p_expr_t *rhs_pspecs, asn1p_ref_t *ref, int recursion_depth) {
	asn1p_expr_t *ref_tc;			/* Referenced tc */
	asn1p_module_t *imports_from;
	char *modulename;
	char *identifier;

	/*
	 * First of all, a reference to a symbol may be specified
	 * using several possible forms:
	 * a) simple identifier
	 *	v INTEGER ::= value
	 * b) external reference
	 * 	v INTEGER ::= Module1.value
	 * c) class-related stuff (the most complex stuff)
	 * 	v ::= <[A-Z][A-Z0-9a-z-]*>.&<[A-Z0-9a-z-]+>.
	 * All other forms are not implemented at this moment.
	 */

	DEBUG("(%s) in %s for line %d",
		asn1f_printable_reference(ref),
		mod->ModuleName,
		ref->_lineno);

	if(recursion_depth++ > 30 /* Arbitrary constant */) {
		FATAL("Excessive circular referencing detected in module %s for %s at line %d",
			mod->ModuleName,
			asn1f_printable_reference(ref),
			ref->_lineno);
		errno = ETOOMANYREFS;
		return NULL;
	}

	if(ref->comp_count == 1) {
		modulename = NULL;
		identifier = ref->components[0].name;
	} else if(ref->comp_count == 2
		&& ref->components[1].name[0] != '&') {
		modulename = ref->components[0].name;
		identifier = ref->components[1].name;
	} else if(ref->comp_count > 1
		&& isupper(ref->components[0].name[0])
		&& ref->components[1].name[0] == '&') {
		asn1p_expr_t *extract;
		/*
		 * This is a reference to a CLASS-related stuff.
		 * Employ a separate function for that.
		 */
		extract = asn1f_class_access(arg, mod, rhs_pspecs, ref);
		
		return extract;
	} else {
		DEBUG("\tToo many components: %d", ref->comp_count);
		errno = EINVAL;
		return NULL;
	}

	/*
	 * If module name is specified explicitly
	 * OR the current module's IMPORTS clause contains the identifier,
	 * fetch that module.
	 */
	if(modulename) {
		imports_from = asn1f_lookup_module(arg, modulename, 0);
		if(imports_from == NULL) {
			FATAL("Module \"%s\" "
				"mentioned at line %d is not found",
				modulename, ref->_lineno);
			return NULL;
		}

		/*
		 * Check that the EXPORTS section of this module contains
		 * the symbol we care about, or it is EXPORTS ALL.
		 */
		if(asn1f_compatible_with_exports(arg,imports_from,identifier)) {
			errno = EPERM;
			return NULL;
		}
	} else {
		/* Search inside the IMPORTS section of the current module */
		imports_from = asn1f_lookup_in_imports(arg, mod, identifier);
		if(imports_from == NULL && errno != ESRCH) {
			/*
			 * Return only of the name was not found.
			 * If module was not found or more serious error
			 * encountered, just return preserving the errno.
			 */
			return NULL;
		}
	}

	/*
	 * The symbol is being imported from another module.
	 */
  importing:
	if(imports_from) {
		asn1p_ref_t tmpref = *ref;
		asn1p_expr_t *expr;
		if(modulename) {
			/*
			 * The modulename is specified inside this reference.
			 * To avoid recursion, reformat the reference
			 * as it were local to that module.
			 */
			tmpref.components++;	/* Hide the first element */
			tmpref.comp_count--;
			assert(tmpref.comp_count > 0);
		}

		expr = asn1f_lookup_symbol_impl(arg, imports_from,
				rhs_pspecs, &tmpref, recursion_depth);
		if(!expr && !(arg->expr->_mark & TM_BROKEN)
		&& !(imports_from->_tags & MT_STANDARD_MODULE)) {
			arg->expr->_mark |= TM_BROKEN;
			if(modulename) {
				FATAL("Module %s referred by %s in module %s "
					"does not contain the requested symbol",
				imports_from->ModuleName,
				asn1f_printable_reference(ref),
				mod->ModuleName);
			} else {
				FATAL("Module %s referred in IMPORTS section "
				"for %s of module %s does not contain "
				"the requested symbol",
				imports_from->ModuleName,
				asn1f_printable_reference(ref),
				mod->ModuleName);
			}
		}
		return expr;
	}

	/*
	 * Now we know where to search for a value: in the current module.
	 */
	TQ_FOR(ref_tc, &(mod->members), next) {
		if(ref_tc->Identifier)
		if(strcmp(ref_tc->Identifier, identifier) == 0)
			break;
	}
	if(ref_tc) {
		if(rhs_pspecs && !ref_tc->lhs_params) {
			FATAL("Parameterized type %s expected "
				"for %s at line %d",
				ref_tc->Identifier,
				asn1f_printable_reference(ref),
				ref->_lineno);
			errno = EPERM;
			return NULL;
		}
		if(!rhs_pspecs && ref_tc->lhs_params) {
			FATAL("Type %s expects specialization "
				"from %s at line %d",
				ref_tc->Identifier,
				asn1f_printable_reference(ref),
				ref->_lineno);
			errno = EPERM;
			return NULL;
		}
		if(rhs_pspecs && ref_tc->lhs_params) {
			/* Specialize the target */
			ref_tc = asn1f_parameterization_fork(arg,
				ref_tc, rhs_pspecs);
		}

		return ref_tc;
	}

	/*
	 * Not found in the current module.
	 * Search in our default standard module.
	 */
	{
		/* Search inside standard module */
		static asn1p_oid_t *uioc_oid;
		if(!uioc_oid) {
			asn1p_oid_arc_t arcs[] = {
				{ 1, "iso" },
				{ 3, "org" },
				{ 6, "dod" },
				{ 1, "internet" },
				{ 4, "private" },
				{ 1, "enterprise" },
				{ 9363, "spelio" },
				{ 1, "software" },
				{ 5, "asn1c" },
				{ 3, "standard-modules" },
				{ 0, "auto-imported" },
				{ 1, 0 }
			};
			uioc_oid = asn1p_oid_construct(arcs,
				sizeof(arcs)/sizeof(arcs[0]));
		}
		if(!imports_from && (!mod->module_oid
		|| asn1p_oid_compare(mod->module_oid, uioc_oid))) {
			imports_from = asn1f_lookup_module(arg,
				"ASN1C-UsefulInformationObjectClasses",
				uioc_oid);
			if(imports_from) goto importing;
		}
	}

	DEBUG("Module \"%s\" does not contain \"%s\" "
		"mentioned at line %d: %s",
		mod->ModuleName,
		identifier,
		ref->_lineno,
		strerror(errno));

	if(asn1f_check_known_external_type(identifier) == 0) {
		errno = EEXIST; /* Exists somewhere */
	} else {
		errno = ESRCH;
	}
	return NULL;
}


asn1p_expr_t *
asn1f_lookup_symbol(arg_t *arg,
	asn1p_module_t *mod, asn1p_expr_t *rhs_pspecs, asn1p_ref_t *ref) {
	return asn1f_lookup_symbol_impl(arg, mod, rhs_pspecs, ref, 0);
}

asn1p_expr_t *
asn1f_find_terminal_type(arg_t *arg, asn1p_expr_t *expr) {
	return asn1f_find_terminal_thing(arg, expr, FTT_TYPE);
}

asn1p_expr_t *
asn1f_find_terminal_value(arg_t *arg, asn1p_expr_t *expr) {
	return asn1f_find_terminal_thing(arg, expr, FTT_VALUE);
}

static asn1p_expr_t *
asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr, enum ftt_what what) {
	asn1p_ref_t *ref = 0;
	asn1p_expr_t *tc;

	switch(what) {
	case FTT_TYPE:
		/* Expression may be a terminal type itself */
		if(expr->expr_type != A1TC_REFERENCE)
			return expr;
		ref = expr->reference;
		break;
	case FTT_VALUE:
		assert(expr->meta_type == AMT_VALUE);
		assert(expr->value);
		/* Expression may be a terminal type itself */
		if(expr->value->type != ATV_REFERENCED)
			return expr;
		ref = expr->value->value.reference;
		break;
	}

	DEBUG("%s(%s->%s) for line %d",
		(what == FTT_VALUE)?"VALUE":"TYPE",
		expr->Identifier, asn1f_printable_reference(ref),
		expr->_lineno);

	assert(ref);

	/*
	 * Lookup inside the type itself (ENUMERATED, INTEGER, etc).
	 */
	if(what == FTT_VALUE) {
		asn1p_expr_t *val_type_tc;
		val_type_tc = asn1f_find_terminal_type(arg, expr);
		if(val_type_tc
		&& asn1f_look_value_in_type(arg, val_type_tc, expr))
			return NULL;
		if(expr->value->type != ATV_REFERENCED) {
			return expr;
		}
		assert(ref == expr->value->value.reference);
		ref = expr->value->value.reference;
	}

	/*
	 * Lookup inside the default module and its IMPORTS section.
	 */
	tc = asn1f_lookup_symbol(arg, expr->module, expr->rhs_pspecs, ref);
	if(tc == NULL) {
		DEBUG("\tSymbol \"%s\" not found: %s",
			asn1f_printable_reference(ref),
			strerror(errno));
		return NULL;
	}

	/*
	 * Recursive loops detection.
	 */
	if(tc->_mark & TM_RECURSION) {
		DEBUG("Recursion loop detected for %s at line %d",
			asn1f_printable_reference(ref), ref->_lineno);
		errno = EPERM;
		return NULL;
	}

	tc->_type_referenced = 1;
	tc->_mark |= TM_RECURSION;
	WITH_MODULE(tc->module,
		expr = asn1f_find_terminal_thing(arg, tc, what));
	tc->_mark &= ~TM_RECURSION;

	return expr;
}

/*
 * Make sure that the specified name is present or otherwise does
 * not contradict with the EXPORTS clause of the specified module.
 */
static int
asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name) {
	asn1p_xports_t *exports;
	asn1p_expr_t *item;

	assert(mod);
	assert(name);

	exports = TQ_FIRST(&(mod->exports));
	if(exports == NULL) {
		/* No EXPORTS section or EXPORTS ALL; */
		return 0;
	}

	TQ_FOR(item, &(exports->members), next) {
		if(strcmp(item->Identifier, name) == 0)
			return 0;
	}

	/* Conditional debug */
	if(!(arg->expr->_mark & TM_BROKEN)) {
		arg->expr->_mark |= TM_BROKEN;
		FATAL("EXPORTS section of module %s in %s "
			"does not mention %s at line %d",
			mod->ModuleName, mod->source_file_name, name,
			arg->expr->_lineno);
	}

	errno = ESRCH;
	return -1;
}
