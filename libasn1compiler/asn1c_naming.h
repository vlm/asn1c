#ifndef	ASN1_COMPILER_NAMING_H
#define	ASN1_COMPILER_NAMING_H


/*
 * A member or a field name.
 */
struct c_names {
    struct {
        const char *asn_name;       /* "T-Rex" */
        const char *part_name;      /* "T_Rex" */
        const char *base_name;      /* "T_Rex" */
        const char *c_name;         /* "T_Rex_t" */
        const char *constrained_c_name; /* "long" */
    } type;
    const char *asn_name;      /* "foo" */
    const char *part_name;     /* "foo", "signed" */
    const char *base_name;     /* "foo" if not, "parent_foo" if compound */
    const char *short_name;    /* "foo_t", "e_foo" */
    const char *full_name;     /* "struct foo", "enum foo" */
    const char *as_member;     /* "foo" (not compounded) */
    const char *presence_enum; /* "enum foo_PR" */
    const char *presence_name; /* "foo_PR" */
    const char *members_enum;  /* "enum foo" */
    const char *members_name;  /* "e_foo" */
    const char *compound_name; /* always contain "parent_foo" */
};

struct c_names c_name(arg_t *);
struct c_names c_expr_name(arg_t *, asn1p_expr_t *);
const char *c_member_name(arg_t *, asn1p_expr_t *);     /* %s_%s */
const char *c_presence_name(arg_t *, asn1p_expr_t *);   /* %s_PR_%s */

const char *c_names_format(struct c_names); /* For debugging */

/*
 * Returns 0 if no C name clashes have been encountered.
 * Returns 1 if C name clashes have been encountered.
 * Prints out the clashing items and suggests -fcompound-names.
 */
int c_name_clash(arg_t *arg);

void c_name_clash_finder_init(void);

void c_name_clash_finder_destroy(void);

#endif	/* ASN1_COMPILER_NAMING_H */
