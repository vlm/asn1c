/* OID support contributed by Sean Leonard of SeanTek(R). */

#include "asn1c_internal.h"
#include "asn1c_oid.h"
#include "asn1p_oid.h"		/* Object identifiers (OIDs) */

/* From OBJECT_IDENTIFIER.c */

#ifndef CALLOC
#define	CALLOC(nmemb, size)	calloc(nmemb, size)
#endif
#ifndef MALLOC
#define	MALLOC(size)		malloc(size)
#endif
#ifndef REALLOC
#define	REALLOC(oldptr, size)	realloc(oldptr, size)
#endif
#ifndef FREEMEM
#define	FREEMEM(ptr)		free(ptr)
#endif

/* This function computes the following approximation:
   Given x decimal digits (in base 10), where the most
	 significant digit is d0, return the maximum number of bytes/octets
	 to allocate (in base 128, 7 bits used per byte).
	 The solution is:
	  bits = digits * log2(10);
	  bytes (7 bits used) = digits * log2(10) / 7 =
		 digits * log128(10) = digits * ln 10 / ln 128
		ln 10 / ln 128 ~= 0.47
		taking text_sig_digit into consideration, use:
		tenths = ((# of digits - 1) * 10 + d0mapped)
		digits = tenths / 10
		bytes = tenths * 14 / 295, where 14/295 is the closest rational
		approximation to the log blob.
*/
static inline size_t compute_reverse_length(size_t text_len, char bcd_sig_digit) {
	size_t tenths;
	
	assert(text_len <= (((SIZE_MAX - (295 - 1)) / 14) / 10));
	assert(bcd_sig_digit >= 0 && bcd_sig_digit < 10);

	switch (bcd_sig_digit) {
	case 1: tenths = 4; break;
	case 2: tenths = 5; break;
	case 3: case 4: tenths = 7; break;
	case 5: tenths = 8; break;
	case 6: tenths = 9; break;
	default: tenths = 10; /* 7 - 9 and special case 0 */
	}
	tenths += (text_len - 1) * 10;
	
	return (tenths * 14 + 295 - 1) / 295;
}

static size_t reverse_double_dabble(char *bcd, size_t bcd_len, uint8_t *ber) {
	size_t ber_len = compute_reverse_length(bcd_len, bcd[0]);

	assert(bcd && bcd_len && ber);
	/* optimized cases (common and fast--but the algorithm below
	 works for them too) */
	if(bcd_len == 1) {
		*ber = (uint8_t)*bcd;
		return 1;
	} else if(bcd_len == 2) {
		*ber = (uint8_t)bcd[0] * 10 + (uint8_t)bcd[1];
		return 1;
	} else if(bcd_len == 3 && bcd[0] == 1 &&
		(bcd[1] < 2 || (bcd[1] == 2 && bcd[2] < 8))) {
		*ber = 100 + (uint8_t)bcd[1] * 10 + (uint8_t)bcd[2];
		assert(*ber < 0x80);
		return 1;
	} else {
		size_t k = 0;
		char * const bcd_end = bcd + bcd_len;
		char * const bcd_last = bcd_end - 1;
		char *bcd_i;
		uint8_t *ber_end = ber + ber_len;
		uint8_t *ber_point = ber_end - 1;
		uint8_t * const ber_last = ber_point;
		uint8_t lsb; /* least significant bit */
		static const size_t BitsUsed = 7; // OIDs are in base128. 
		assert(bcd_len >= 3);

		memset(ber, 0, ber_len);
	
		while(bcd != bcd_end) {
			lsb = (uint8_t)*bcd_last & 0x1;
			/* put lsb into ber[x] at the correct bit position */
			if(k == BitsUsed) {
				assert(ber_point > ber);
				if(ber_point <= ber) {
					return 0; /* oh no, went too far! */
				}
				k = 0;
				ber_point--;
			}
			*ber_point |= lsb << k++;

			for(bcd_i = bcd_last; bcd_i > bcd; bcd_i--) {
				if((*(bcd_i - 1)) & 0x1) {
					*bcd_i = ((*bcd_i >> 1) | 0x08) - 0x3;
				} else {
					*bcd_i >>= 1;
				}
			}
			assert(bcd_i == bcd);
			*bcd >>= 1;
			if(!*bcd) bcd++;
		}
	
		/* Shift ber contents down to ber, if necessary */
		if(ber_point == ber) {
			while(ber < ber_last) *ber++ |= 0x80;
		} else {
			ber_len = (ber_end - ber_point);
			while(ber_point < ber_last) *ber++ = *ber_point++ | 0x80;
			*ber = *ber_point; /* shift but do not add 0x80 continuation */
		}
		return ber_len;
	}
}

static size_t perform_bcd2ber(int is_roid, char *scratch, size_t scratch_len, uint8_t *ber) {
	size_t res = 0, i = 2, base = 2;
	assert(scratch && ber);
	if(!is_roid) {
		if(scratch_len < 3) {
			errno = ERANGE;
			return 0;
		} else if(((unsigned char)scratch[0]) > 2 || scratch[1] != (char)-1 ||
			scratch[2] == (char)-1) {
			errno = EINVAL;
			return 0;
		}

		/* first handle "2.16" combine by adding 40 or 80, then encoding */
		while(i < scratch_len && scratch[i] != (char)-1) i++;
		scratch[1] = 0;
		if(scratch[0] != 0) {
			size_t j = i-2;
			int carry;
			scratch[j] += scratch[0] == 1 ? 4 : 8;
			for(carry = scratch[j] >= 10; carry && j >= base;
				carry = scratch[j] >= 10) {
				scratch[j--] -= 10;
				scratch[j] += 1;
			}
			assert(j >= base || base - j == 1);
			if(j < base) base = j;
		}
		
		res = reverse_double_dabble(scratch + base, i - base, ber);
		if(!res) {
			assert(0);
			return 0;
		}
		ber += res;
		base = ++i;
	} else { /* dealing with RELATIVE-OID */
		base = 0;
		i = 0;
	}

	/* next iterate over all other arcs */
	while(i < scratch_len) {
		while(i < scratch_len && scratch[i] != (char)-1) i++;
		assert(base != i);
		if(base != i) {
			size_t onesize;
			onesize = reverse_double_dabble(scratch + base, i - base, ber);
			if(!onesize) {
				assert(0);
				return 0;
			}
			res += onesize;
			ber += onesize;
		}
		base = ++i;
	}
	return res;
}


static size_t get_len_of_oid(arg_t *arg, asn1p_oid_t *oid, int is_roid) {
	asn1p_expr_t *expr = arg->expr;
	size_t oid_arcs_len = 0, oid_arcs_one;
	int i;

	/* Compute result. */
	for(i = 0; i < oid->arcs_count; i++) {
		if(oid->arcs[i].number) {
			oid_arcs_one = strlen(oid->arcs[i].number);
			oid_arcs_len += 1 + oid_arcs_one;
		} else if(oid->arcs[i].name) {
			/* Handle symbols. */
			char *sym = oid->arcs[i].name;
			asn1p_expr_t *v; /* value definition */
			asn1p_xports_t *imp; /* import definition */
			
			oid_arcs_one = 0;
			if(i == 0 && !is_roid) {
				if(!strcmp(sym, "itu-t")) oid_arcs_one = 2; /* 0 */
				else if(!strcmp(sym, "iso")) oid_arcs_one = 2; /* 1 */
				else if(!strcmp(sym, "joint-iso-itu-t")) oid_arcs_one = 2; /* 2 */
				else {
					asn1p_expr_t ref_v = {NULL}; /* used for moving to v->next only */
					/* Treat as OBJECT IDENTIFIER symbol. */
					
					/* First scan local members. */
					TQ_FOR(v, &(expr->module->members), next) {
						if(!strcmp(v->Identifier, sym)) {
							if(v->expr_type == ASN_BASIC_OBJECT_IDENTIFIER &&
								v->value->type == ATV_REFERENCED) {
								asn1p_ref_t *ref = v->value->value.reference;
								assert(ref);
								assert(ref->comp_count == 1 && ref->components);
								assert(ref->components[0].name);
								ref_v.Identifier = sym;
								sym = ref->components[0].name;
								TQ_NEXT(&ref_v, next) = TQ_FIRST(&(expr->module->members));
								v = &ref_v;
								continue;
							}
							if(v->expr_type != ASN_BASIC_OBJECT_IDENTIFIER ||
								v->value->type != ATV_OBJECT_IDENTIFIER) {
								/* TODO: Output that this is a type mismatch error. */
								errno = EINVAL;
								return 0;
							}
							
							/* Infinite recursion check (this checks self-references only, not buried cycles!). */
							assert(oid != v->value->value.oid);
							oid_arcs_one = get_len_of_oid(arg, v->value->value.oid, 0);
							break;
						}
					}
					
					/* Then, scan all imports. */
					if(oid_arcs_one == 0) {
						asn1p_module_t *ref_mod;
						asn1p_expr_t *ref_expr;
						
						TQ_FOR(imp, &(expr->module->imports), xp_next) {
							assert(imp->xports_type == XPT_IMPORTS);
							
							TQ_FOR(v, &(imp->members), next) {
								if(!strcmp(v->Identifier, sym)) {
									assert(v->meta_type == AMT_INVALID);
									assert(v->expr_type == A1TC_REFERENCE);
									assert(imp->identifier.oid);
									
									TQ_FOR(ref_mod, &(arg->asn->modules), mod_next) {
										if(!asn1p_oid_compare(ref_mod->module_oid, imp->identifier.oid)) {
											TQ_FOR(ref_expr, &(ref_mod->members), next) {
												if(!strcmp(ref_expr->Identifier, sym)) {
													asn1p_expr_t *stack_expr = arg->expr;
													if(ref_expr->expr_type != ASN_BASIC_OBJECT_IDENTIFIER ||
														ref_expr->value->type != ATV_OBJECT_IDENTIFIER) {
														/* TODO: Output that this is a type mismatch error. */
														errno = EINVAL;
														return 0;
													}

													assert(oid != ref_expr->value->value.oid);
													arg->expr = ref_expr;
													oid_arcs_one = get_len_of_oid(arg, ref_expr->value->value.oid, 0);
													arg->expr = stack_expr;
													break;
												}
											}
											break;
										}
									}
								}
							}
						}
						
						if(oid_arcs_one == 0) {
							/* TODO: Output no match for symbol! */
							errno = EINVAL;
							return 0;
						}
					}
				}
			} else {
				/* Treat as RELATIVE-OID symbol. */

				/* First scan local members. */
				TQ_FOR(v, &(expr->module->members), next) {
					if(!strcmp(v->Identifier, sym)) {
						if(v->expr_type != ASN_BASIC_RELATIVE_OID ||
							v->value->type != ATV_OBJECT_IDENTIFIER) {
							/* TODO: Output that this is a type mismatch error. */
							errno = EINVAL;
							return 0;
						}
						
						/* Infinite recursion check (this checks self-references only, not buried cycles!). */
						assert(oid != v->value->value.oid);
						oid_arcs_one = get_len_of_oid(arg, v->value->value.oid, 1);
						break;
					}
				}
				
				/* Then, scan all imports. */
				if(oid_arcs_one == 0) {
					asn1p_module_t *ref_mod;
					asn1p_expr_t *ref_expr;
					TQ_FOR(imp, &(expr->module->imports), xp_next) {
						assert(imp->xports_type == XPT_IMPORTS);
						
						TQ_FOR(v, &(imp->members), next) {
							if(!strcmp(v->Identifier, sym)) {
								assert(v->meta_type == AMT_INVALID);
								assert(v->expr_type == A1TC_REFERENCE);
								assert(imp->identifier.oid);
								
								TQ_FOR(ref_mod, &(arg->asn->modules), mod_next) {
									if(!asn1p_oid_compare(ref_mod->module_oid, imp->identifier.oid)) {
										TQ_FOR(ref_expr, &(ref_mod->members), next) {
											if(!strcmp(ref_expr->Identifier, sym)) {
												asn1p_expr_t *stack_expr = arg->expr;
												if(ref_expr->expr_type != ASN_BASIC_RELATIVE_OID ||
													ref_expr->value->type != ATV_OBJECT_IDENTIFIER) {
													/* TODO: Output that this is a type mismatch error. */
													errno = EINVAL;
													return 0;
												}

												assert(oid != ref_expr->value->value.oid);
												arg->expr = ref_expr;
												oid_arcs_one = get_len_of_oid(arg, ref_expr->value->value.oid, 1);
												arg->expr = stack_expr;
												break;
											}
										}
										break;
									}
								}
							}
						}
					}
					
					if(oid_arcs_one == 0) {
						/* TODO: Output no match for symbol! */
						errno = EINVAL;
						return 0;
					}
				}
			}
			
			oid_arcs_len += oid_arcs_one;
		} else {
			assert(oid->arcs[i].name || oid->arcs[i].number);
			errno = EINVAL;
			return 0;
		}
	}

	return oid_arcs_len;
}

static size_t get_bcd_of_oid(arg_t *arg, asn1p_oid_t *oid, int is_roid, char *bcd) {
	asn1p_expr_t *expr = arg->expr;
	size_t oid_arcs_one = 0, oid_arcs_one_end = 0;
	int i;

	for(i = 0; i < oid->arcs_count; i++) {
		if(oid->arcs[i].number) {
			const size_t arc_len = strlen(oid->arcs[i].number);
			size_t j;
			oid_arcs_one_end = oid_arcs_one + arc_len;
			for(j = 0; j < arc_len; j++) {
				bcd[oid_arcs_one + j] = oid->arcs[i].number[j] - '0';
			}
			assert(oid_arcs_one_end == oid_arcs_one + j);
			bcd[oid_arcs_one_end] = (char)-1;
			oid_arcs_one = oid_arcs_one_end + 1;
			oid_arcs_one_end = 0; /* safety. */
		} else if(oid->arcs[i].name) {
			/* Handle symbols. */
			char *sym = oid->arcs[i].name;
			asn1p_expr_t *v; /* value definition */
			asn1p_xports_t *imp; /* import definition */
			
			if(i == 0 && !is_roid) {
				if(!strcmp(sym, "itu-t")) {
					bcd[0] = 0;
					bcd[1] = (char)-1;
					oid_arcs_one = 2;
				} else if(!strcmp(sym, "iso")) {
					bcd[0] = 1;
					bcd[1] = (char)-1;
					oid_arcs_one = 2;
				}	else if(!strcmp(sym, "joint-iso-itu-t")) {
					bcd[0] = 2;
					bcd[1] = (char)-1;
					oid_arcs_one = 2;
				} else {
					asn1p_expr_t ref_v = {NULL}; /* used for moving to v->next only */
					/* Treat as OBJECT IDENTIFIER symbol. */
					size_t sub_arc_len_1 = 0; /* this is the length of the sub-arc, plus 1 for final (char)-1 terminator */

					/* First scan local members. */
					TQ_FOR(v, &(expr->module->members), next) {
						if(!strcmp(v->Identifier, sym)) {
							if(v->expr_type == ASN_BASIC_OBJECT_IDENTIFIER &&
								v->value->type == ATV_REFERENCED) {
								asn1p_ref_t *ref = v->value->value.reference;
								assert(ref);
								assert(ref->comp_count == 1 && ref->components);
								assert(ref->components[0].name);
								ref_v.Identifier = sym;
								sym = ref->components[0].name;
								TQ_NEXT(&ref_v, next) = TQ_FIRST(&(expr->module->members));
								v = &ref_v;
								continue;
							}
							assert(v->expr_type == ASN_BASIC_OBJECT_IDENTIFIER &&
								v->value->type == ATV_OBJECT_IDENTIFIER);

							/* Infinite recursion check (this checks self-references only, not buried cycles!). */
							assert(oid != v->value->value.oid);
							/* recurse to fill the byte ranges. */
							sub_arc_len_1 = get_bcd_of_oid(arg, v->value->value.oid,
								0, bcd + oid_arcs_one);
							oid_arcs_one += sub_arc_len_1;
							break;
						}
					}

					/* Then, scan all imports. */
					if(sub_arc_len_1 == 0) {
						asn1p_module_t *ref_mod;
						asn1p_expr_t *ref_expr;
						
						TQ_FOR(imp, &(expr->module->imports), xp_next) {
							assert(imp->xports_type == XPT_IMPORTS);
							
							TQ_FOR(v, &(imp->members), next) {
								if(!strcmp(v->Identifier, sym)) {
									assert(v->meta_type == AMT_INVALID);
									assert(v->expr_type == A1TC_REFERENCE);
									assert(imp->identifier.oid);
									
									TQ_FOR(ref_mod, &(arg->asn->modules), mod_next) {
										if(!asn1p_oid_compare(ref_mod->module_oid, imp->identifier.oid)) {
											TQ_FOR(ref_expr, &(ref_mod->members), next) {
												if(!strcmp(ref_expr->Identifier, sym)) {
													asn1p_expr_t *stack_expr = arg->expr;
													assert(ref_expr->expr_type == ASN_BASIC_OBJECT_IDENTIFIER &&
														ref_expr->value->type == ATV_OBJECT_IDENTIFIER);

													assert(oid != ref_expr->value->value.oid);
													/* recurse to fill the byte ranges. */
													arg->expr = ref_expr;
													sub_arc_len_1 = get_bcd_of_oid(arg,
														ref_expr->value->value.oid, 0, bcd + oid_arcs_one);
													arg->expr = stack_expr;
													oid_arcs_one += sub_arc_len_1;
													break;
												}
											}
											break;
										}
									}
								}
							}
						}
						
						if(sub_arc_len_1 == 0) {
							/* TODO: Output no match for symbol! */
							errno = EINVAL;
							return 0;
						}
					}
				}
			} else {
				/* Treat as RELATIVE-OID symbol. */
				size_t sub_arc_len_1 = 0;

				/* First scan local members. */
				TQ_FOR(v, &(expr->module->members), next) {
					if(!strcmp(v->Identifier, sym)) {
						assert(v->expr_type == ASN_BASIC_RELATIVE_OID &&
							v->value->type == ATV_OBJECT_IDENTIFIER);

						/* Infinite recursion check (this checks self-references only, not buried cycles!). */
						assert(oid != v->value->value.oid);
						/* recurse to fill the byte ranges. */
						sub_arc_len_1 = get_bcd_of_oid(arg, v->value->value.oid,
							1, bcd + oid_arcs_one);
						oid_arcs_one += sub_arc_len_1;
						break;
					}
				}

				/* Then, scan all imports. */
				if(sub_arc_len_1 == 0) {
					asn1p_module_t *ref_mod;
					asn1p_expr_t *ref_expr;
					
					TQ_FOR(imp, &(expr->module->imports), xp_next) {
						assert(imp->xports_type == XPT_IMPORTS);
						
						TQ_FOR(v, &(imp->members), next) {
							if(!strcmp(v->Identifier, sym)) {
								assert(v->meta_type == AMT_INVALID);
								assert(v->expr_type == A1TC_REFERENCE);
								assert(imp->identifier.oid);
								
								TQ_FOR(ref_mod, &(arg->asn->modules), mod_next) {
									if(!asn1p_oid_compare(ref_mod->module_oid, imp->identifier.oid)) {
										TQ_FOR(ref_expr, &(ref_mod->members), next) {
											if(!strcmp(ref_expr->Identifier, sym)) {
												asn1p_expr_t *stack_expr = arg->expr;
												assert(ref_expr->expr_type == ASN_BASIC_RELATIVE_OID &&
													ref_expr->value->type == ATV_OBJECT_IDENTIFIER);

												assert(oid != ref_expr->value->value.oid);
												/* recurse to fill the byte ranges. */
												arg->expr = ref_expr;
												sub_arc_len_1 = get_bcd_of_oid(arg,
													ref_expr->value->value.oid, 1, bcd + oid_arcs_one);
												arg->expr = stack_expr;
												oid_arcs_one += sub_arc_len_1;
												break;
											}
										}
										break;
									}
								}
							}
						}
					}
					
					if(sub_arc_len_1 == 0) {
						/* TODO: Output no match for symbol! */
						errno = EINVAL;
						return 0;
					}
				}
			}
			
			oid_arcs_one_end = 0; /* safety. */
		} else {
			assert(oid->arcs[i].name || oid->arcs[i].number);
			errno = EINVAL;
			return 0;
		}
	}

	return oid_arcs_one;
}

static char *MyBCDHere;

/*
 * Actual public function exposed to other asn1c modules.
 */
int asn1c_oid_ber_encode(arg_t *arg, uint8_t **ber, size_t *ber_len) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_oid_t *oid = expr->value->value.oid;
	int is_roid;
	size_t oid_arcs_len = 0;
	size_t oid_arcs_written;
	char *bcd = NULL;

	if(expr->expr_type != ASN_BASIC_OBJECT_IDENTIFIER) {
		if(expr->expr_type == ASN_BASIC_RELATIVE_OID) {
			is_roid = 1;
		} else {
			errno = EINVAL;
			return -1;
		}
	}	else {
		is_roid = 0;
	}

	if(!ber || !ber_len || !oid) {
		errno = EINVAL;
		return -1;
	}
	
	/* Compute result. */
	errno = 0;
	oid_arcs_len = get_len_of_oid(arg, oid, is_roid);
	if(!oid_arcs_len) {
		assert(errno != 0);
		return -1;
	}
	
	bcd = (char*)malloc(oid_arcs_len);
	if(!bcd) return -1;

	errno = 0;
	oid_arcs_written = get_bcd_of_oid(arg, oid, is_roid, bcd);
	char writtenandlen[512];
	MyBCDHere = bcd;
	sprintf(writtenandlen, "written = %u | len = %u",
		(unsigned int)oid_arcs_written, (unsigned int)oid_arcs_len);
	assert(oid_arcs_written == oid_arcs_len);
	assert(oid_arcs_written);
	assert(bcd[oid_arcs_written - 1] == (char)-1);

	/* Use the non-optimized, simplified estimate. */
	*ber = (uint8_t*)malloc(oid_arcs_len - 1);
	*ber_len = perform_bcd2ber(is_roid, bcd, oid_arcs_len - 1, *ber);
	assert(*ber_len <= oid_arcs_len - 1);
	free(bcd);
	if(!*ber_len) {
		free(*ber);
		*ber = NULL;
		return -1;
	}
	return 0;
}
