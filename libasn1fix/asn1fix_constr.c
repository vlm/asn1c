#include "asn1fix_internal.h"

static int _asn1f_check_if_tag_must_be_explicit(arg_t *arg, asn1p_expr_t *v);
static int _asn1f_compare_tags(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b);
static int _asn1f_fix_type_tag(arg_t *arg, asn1p_expr_t *expr);

int
asn1f_pull_components_of(arg_t *arg) {
	TQ_HEAD(asn1p_expr_t) list;
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
		break;
	default:
		return 0;
	}

	TQ_INIT(&list);

	/*
	 * Look into
	 */
	while((memb = TQ_REMOVE(&(expr->members), next))) {
		asn1p_expr_t *coft;	/* COMPONENTS OF thing itself */
		asn1p_expr_t *terminal;	/* Terminal of the referenced type */

		if(memb->expr_type != A1TC_COMPONENTS_OF) {
			TQ_ADD(&list, memb, next);
			continue;
		}

		coft = TQ_FIRST(&memb->members);
		assert(coft);
		assert(!TQ_NEXT(coft, next));

		/*
		 * Find the referenced type.
		 */
		terminal = asn1f_find_terminal_type(arg, coft);
		if(!terminal || (terminal->expr_type != expr->expr_type)) {
			FATAL("COMPONENTS OF at line %d "
				"must reference a %s type",
				coft->_lineno,
				expr->expr_type==ASN_CONSTR_SET
					? "SET" : "SEQUENCE"
			);
			TQ_ADD(&list, memb, next);
			r_value = -1;
			continue;
		}

		/*
		 * Clone the final structure.
		 */

		coft = asn1p_expr_clone(terminal, 1 /* Skip extensions */);
		if(!coft) return -1;	/* ENOMEM */

		if(1) {
			asn1p_expr_free(memb);	/* Don't need it anymore*/
		} else {
			/* Actual removal clashes with constraints... skip. */
		}

		/*
		 * Move all components of the cloned structure
		 * into the current one.
		 */
		while((memb = TQ_REMOVE(&(coft->members), next))) {
			TQ_ADD(&list, memb, next);
			memb->parent_expr = expr;
		}

		asn1p_expr_free(coft);	/* Remove wrapper */
	}

	/* Move the stuff back */
	TQ_MOVE(&(expr->members), &list);

	return r_value;
}

/*
 * Fix extensibility parts inside constructed types (SEQUENCE, SET, CHOICE).
 */
int
asn1f_fix_constr_ext(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	TQ_HEAD(asn1p_expr_t) root_list;
	TQ_HEAD(asn1p_expr_t) ext_list;
	TQ_HEAD(asn1p_expr_t) *cur_list;
	int r_value = 0;
	int ext_count = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	DEBUG("(%s) for line %d", expr->Identifier, expr->_lineno);

	TQ_INIT(&root_list);
	TQ_INIT(&ext_list);
	cur_list = (void *)&root_list;

	/*
	 * Split the set of fields into two lists, the root list
	 * and the extensions list.
	 */
	while((v = TQ_REMOVE(&(expr->members), next))) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			ext_count++;
			switch(ext_count) {
			case 1: cur_list = (void *)&ext_list; break;
			case 2:
				cur_list = (void *)&root_list;
				if(v->value) {
					FATAL("Optional extension marker "
						"must not contain "
						"an exception mark "
						"at line %d", v->_lineno);
					r_value = -1;
				}
				asn1p_expr_free(v);
				continue;
			case 3:
				FATAL("Third extension marker "
				"is not allowed at line %d", v->_lineno);
                /* Fall through */
			default:
				r_value = -1;
			}
		}

		TQ_ADD(cur_list, v, next);
	}

	/*
	 * Copy the root list and extension list back into the main list.
	 */
	TQ_MOVE(&(expr->members), &root_list);
	while((v = TQ_REMOVE(&ext_list, next)))
		TQ_ADD(&(expr->members), v, next);

	if(arg->mod->module_flags & MSF_EXTENSIBILITY_IMPLIED
	&& ext_count == 0) {
		v = asn1p_expr_new(0, arg->mod);
		if(v) {
			v->Identifier = strdup("...");
			v->expr_type = A1TC_EXTENSIBLE;
			v->meta_type = AMT_TYPE;
			v->_lineno = expr->_lineno;	/* The best we can do */
			if(v->Identifier == NULL) {
				asn1p_expr_free(v);
				r_value = -1;
			} else {
				asn1p_expr_add(expr, v);
			}
		} else {
			r_value = -1;
		}
	}

	return r_value;
}


int
asn1f_fix_constr_tag(arg_t *arg, int fix_top_level) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int root_tagged = 0;	/* The root component is manually tagged */
	int ext_tagged = 0;	/* The extensions are manually tagged */
	int component_number = 0;
	int r_value = 0;

	DEBUG("(%s) for line %d", expr->Identifier, expr->_lineno);

	/*
	 * Fix the top-level type itself first.
	 */
	if(fix_top_level) {
		if(expr->tag.tag_class == TC_NOCLASS)
			return r_value;

		if(_asn1f_fix_type_tag(arg, expr))
			r_value = -1;

		return r_value;
	}

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	TQ_FOR(v, &(expr->members), next) {

		if(v->expr_type == A1TC_EXTENSIBLE) {
			component_number++;
			continue;
		}

		if(v->tag.tag_class == TC_NOCLASS) {
			continue;
		}

		switch(component_number) {
		case 0: case 2:
			root_tagged = 1; break;
		default:
			ext_tagged = 1; break;
		}

		if(_asn1f_fix_type_tag(arg, v))
			r_value = -1;

	}

	if((arg->mod->module_flags & MSF_AUTOMATIC_TAGS)
	&& !root_tagged) {
		if(ext_tagged) {
			/* X.690: 28.4 */
			FATAL("In %s at line %d: "
				"extensions are tagged "
				"but root components are not",
				expr->Identifier, expr->_lineno);
			r_value = -1;
		} else {
			/* Make a decision on automatic tagging */
			expr->auto_tags_OK = 1;
		}
	}

	return r_value;
}

static int
_asn1f_fix_type_tag(arg_t *arg, asn1p_expr_t *expr) {
	int must_explicit = _asn1f_check_if_tag_must_be_explicit(arg, expr);
	int module_impl_tags = (arg->mod->module_flags
				& (MSF_IMPLICIT_TAGS | MSF_AUTOMATIC_TAGS));
	int r_value = 0;

	if(expr->tag.tag_mode == TM_DEFAULT) {
		if(must_explicit || module_impl_tags == 0)
			expr->tag.tag_mode = TM_EXPLICIT;
		else
			expr->tag.tag_mode = TM_IMPLICIT;
	}

	/*
	 * Perform a final sanity check.
	 */
	if(must_explicit) {
		if(expr->tag.tag_mode == TM_IMPLICIT) {
			FATAL("%s tagged in IMPLICIT mode "
				"but must be EXPLICIT at line %d",
				expr->Identifier, expr->_lineno);
			r_value = -1;
		} else {
			expr->tag.tag_mode = TM_EXPLICIT;
		}
	}

	return r_value;
}

int
asn1f_fix_constr_autotag(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	asn1c_integer_t tag_value = 0;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		if(expr->auto_tags_OK)
			break;
		/* Automatic tagging is not applicable */
		/* Fall through */
	default:
		return 0;
	}

	DEBUG("(%s) for line %d", expr->Identifier, expr->_lineno);

	TQ_FOR(v, &(expr->members), next) {
		int must_explicit;

		if(v->expr_type == A1TC_EXTENSIBLE) {
			/* 28.5, d) */
			continue;
		}

		if(0) {
			/* This may be not true in case COMPONENTS OF */
			assert(v->tag.tag_class == TC_NOCLASS);
		}

		must_explicit = _asn1f_check_if_tag_must_be_explicit(arg, v);

		v->tag.tag_class = TC_CONTEXT_SPECIFIC;
		v->tag.tag_mode = must_explicit ? TM_EXPLICIT : TM_IMPLICIT;
		v->tag.tag_value = tag_value++;
	}

	return r_value;
}

/*
 * Check that tags are distinct.
 */
int
asn1f_check_constr_tags_distinct(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	TQ_FOR(v, &(expr->members), next) {
		/*
		 * In every series of non-mandatory components,
		 * the tags must be distinct from each other AND the
		 * tag of the following mandatory component.
		 * For SET and CHOICE treat everything as a big set of
		 * non-mandatory components.
		 */
		if(expr->expr_type != ASN_CONSTR_SEQUENCE || v->marker.flags) {
			asn1p_expr_t *nv;
			for(nv = v; (nv = TQ_NEXT(nv, next));) {
				DEBUG("S/C comparing tags %s s. %s",
					v->Identifier, nv->Identifier);
				if(_asn1f_compare_tags(arg, v, nv))
					r_value = -1;
				if(expr->expr_type == ASN_CONSTR_SEQUENCE
				&& !nv->marker.flags) break;
			}
		}
	}

	return r_value;
}

static int
_asn1f_check_if_tag_must_be_explicit(arg_t *arg, asn1p_expr_t *v) {
	struct asn1p_type_tag_s tag;
	struct asn1p_type_tag_s save_tag;
	asn1p_expr_t *reft;
	int ret;

	/*
	 * Fetch the _next_ tag for this type.
	 */
	save_tag = v->tag;			/* Save existing tag */
	memset(&v->tag, 0, sizeof(v->tag));	/* Remove it temporarily */
	ret = asn1f_fetch_outmost_tag(arg->asn, arg->ns, arg->mod, v, &tag, 0);
	v->tag = save_tag;			/* Restore the tag back */

	if(ret == 0) return 0;	/* If found tag, it's okay */

	reft = asn1f_find_terminal_type(arg, v);
	if(reft) {
		switch(reft->expr_type) {
		case ASN_TYPE_ANY:
		case ASN_CONSTR_CHOICE:
			return 1;
		default:
			return 0;
		}
	}

	return 0;
}

/*
 * Check that the tags are distinct.
 */
static int
_asn1f_compare_tags(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b) {
	struct asn1p_type_tag_s ta, tb;
	int ra, rb;
	int ret;

	ra = asn1f_fetch_outmost_tag(arg->asn, arg->ns, arg->mod, a,
			&ta, AFT_IMAGINARY_ANY);
	rb = asn1f_fetch_outmost_tag(arg->asn, arg->ns, arg->mod, b,
			&tb, AFT_IMAGINARY_ANY);

	/*
	 * If both tags are explicitly or implicitly given, use them.
	 */
	DEBUG("Fetching outmost tags: %d, %d", ra, rb);
	if(ra == 0 && rb == 0) {
		/*
		 * Simple case: fetched both tags.
		 */

		if((ta.tag_value == tb.tag_value
			&& ta.tag_class == tb.tag_class)
		|| ta.tag_value == -1	/* Spread IMAGINARY ANY tag... */
		|| tb.tag_value == -1	/* ...it is an evil virus, fear it! */
		) {
			char tagbuf[2][TAG2STRING_BUFFER_SIZE];
			char *p = (a->expr_type == A1TC_EXTENSIBLE)
				?"potentially ":"";
			FATAL("Processing %s at line %d: component \"%s\" at line %d %shas the same tag "
				"as component \"%s\" at line %d",
				arg->expr->Identifier,
				arg->expr->_lineno,
				a->Identifier,
				a->_lineno,
				p,
				b->Identifier,
				b->_lineno
			);
			FATAL("Consider adding AUTOMATIC TAGS "
				"after module %s DEFINITIONS, "
				"or manually tag components",
				arg->expr->module->ModuleName);
			DEBUG("Tags: %s %s  vs.  %s %s",
				asn1p_tag2string(&ta, tagbuf[0]),
				a->Identifier,
				asn1p_tag2string(&tb, tagbuf[1]),
				b->Identifier
			);
			if((arg->mod->module_flags & MSF_EXTENSIBILITY_IMPLIED)
			&& (a->expr_type == A1TC_EXTENSIBLE)
			&& (b->expr_type == A1TC_EXTENSIBLE)) {
				FATAL("The previous error is due to "
					"improper use of "
					"EXTENSIBILITY IMPLIED flag "
					"of module %s",
					arg->mod->ModuleName);
			}
			return -1;
		} else {
			/* Tags are distinct */
			return 0;
		}
	}

	/**********************************************************
	 * Now we must perform some very funny recursion to check
	 * multiple components of CHOICE type, etc.
	 */

	DEBUG("Comparing tags %s:%x <-> %s:%x",
		a->Identifier, a->expr_type,
		b->Identifier, b->expr_type);

	if(ra && a->meta_type == AMT_TYPEREF) {

		DEBUG(" %s is a type reference", a->Identifier);

        a = asn1f_lookup_symbol(arg, a->rhs_pspecs, a->reference);
        if(!a) return 0;	/* Already FATAL()'ed somewhere else */
        return WITH_MODULE(a->module, _asn1f_compare_tags(arg, a, b));
    }

	if(ra && a->expr_type == ASN_CONSTR_CHOICE) {
		asn1p_expr_t *v;

		DEBUG(" %s is a choice type (%d)", a->Identifier, a->_mark);

		/*
		 * Iterate over members of CHOICE.
		 */
		//if(a->_mark & TM_RECURSION) return 0;
		TQ_FOR(v, &(a->members), next) {
			//a->_mark |= TM_RECURSION;
			ret = _asn1f_compare_tags(arg, v, b);
			//a->_mark &= ~TM_RECURSION;
			if(ret) return ret;
		}
		return 0;
	}

	if(rb && b->expr_type == ASN_CONSTR_CHOICE) {
		return _asn1f_compare_tags(arg, b, a);
	}

	if(a->_mark & TM_RECURSION) return 0;
	if(b->_mark & TM_RECURSION) return 0;
	a->_mark |= TM_RECURSION;
	b->_mark |= TM_RECURSION;
	ret = _asn1f_compare_tags(arg, b, a);
	a->_mark &= ~TM_RECURSION;
	b->_mark &= ~TM_RECURSION;

	return ret;
}

