/*
 * A Module definition structure used by the ASN.1 parser.
 */
#ifndef	ASN1_PARSER_MODULE_H
#define	ASN1_PARSER_MODULE_H

struct asn1p_module_s;

/*
 * A simple container for several modules.
 */
typedef struct asn1p_s {
	TQ_HEAD(struct asn1p_module_s)	modules;
} asn1p_t;

asn1p_t *asn1p_new(void);
void asn1p_delete(asn1p_t *asn);

struct genhash_s;   /* Forward declaration */

/*
 * Flags specific to a module.
 */
typedef enum asn1p_module_flags {
	MSF_NOFLAGS,
	MSF_unk_INSTRUCTIONS		= 0x001,
	MSF_TAG_INSTRUCTIONS		= 0x002,
	MSF_XER_INSTRUCTIONS		= 0x004,
	MSF_EXPLICIT_TAGS		= 0x010,
	MSF_IMPLICIT_TAGS		= 0x020,
	MSF_AUTOMATIC_TAGS		= 0x040,
	MSF_EXTENSIBILITY_IMPLIED	= 0x100,
} asn1p_module_flags_e;
#define	MSF_MASK_INSTRUCTIONS		0x0f
#define	MSF_MASK_TAGS			0xf0

/*
 * === EXAMPLE ===
 * MySyntax DEFINITIONS AUTOMATIC TAGS ::=
 * BEGIN
 * ...
 * END
 * === EOF ===
 */
typedef struct asn1p_module_s {

	/*
	 * Human-readable module reference.
	 */
	char *ModuleName;   /* Must be the first field */

	/*
	 * Name of the source file.
	 */
	char *source_file_name;

	/*
	 * Unique module identifier, OID.
	 */
	asn1p_oid_t *module_oid;	/* Optional OID of the module */

	/*
	 * Module flags.
	 */
	asn1p_module_flags_e module_flags;	/* AUTOMATIC TAGS? */

	/*
	 * List of everything that this module EXPORTS.
	 */
	TQ_HEAD(struct asn1p_xports_s)	exports;

	/*
	 * List of everything that this module IMPORTS.
	 */
	TQ_HEAD(struct asn1p_xports_s)	imports;

	/*
	 * List of everything that this module defines itself.
	 */
	TQ_HEAD(struct asn1p_expr_s)	members;   /* Do not access directly */
    struct genhash_s *members_hash;

	/*
	 * Next module in the list.
	 */
	TQ_ENTRY(struct asn1p_module_s)
		mod_next;

	/* All modules */
	asn1p_t *asn1p;

	/*
	 * Internally useful properties.
	 */
	enum {
	  MT_STANDARD_MODULE = 0x01,	/* Module came from standard-modules */
	} _tags;
} asn1p_module_t;

/*
 * Constructor and destructor.
 */
asn1p_module_t *asn1p_module_new(void);
void asn1p_module_free(asn1p_module_t *mod);

void asn1p_module_move_members(asn1p_module_t *to, asn1p_module_t *from);
void asn1p_module_member_add(asn1p_module_t *mod, struct asn1p_expr_s *expr);


#endif	/* ASN1_PARSER_MODULE_H */
