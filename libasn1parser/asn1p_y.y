%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

#define YYPARSE_PARAM	param
#define YYPARSE_PARAM_TYPE	void **
#define YYERROR_VERBOSE
#define YYDEBUG 1
#define YYFPRINTF   prefixed_fprintf

/*
 * Prefix parser debug with "PARSER: " for easier human eye scanning.
 */
static int
__attribute__((format(printf, 2, 3)))
prefixed_fprintf(FILE *f, const char *fmt, ...) {
    static int line_ended = 1;
    va_list ap;
    va_start(ap, fmt);
    if(line_ended) {
        fprintf(f, "PARSER: ");
        line_ended = 0;
    }
    size_t len = strlen(fmt);
    if(len && fmt[len-1] == '\n') {
        line_ended = 1;
    }
    int ret = vfprintf(f, fmt, ap);
    va_end(ap);
    return ret;
}

int yylex(void);
static int yyerror(const char *msg);

#ifdef	YYBYACC
int yyparse(void **param);	/* byacc does not produce a prototype */
#endif
void asn1p_lexer_hack_push_opaque_state(void);
void asn1p_lexer_hack_enable_with_syntax(void);
void asn1p_lexer_hack_push_encoding_control(void);
#define	yylineno	asn1p_lineno
extern int asn1p_lineno;
const char *asn1p_parse_debug_filename;
#define ASN_FILENAME asn1p_parse_debug_filename

/*
 * Process directives as <ASN1C:RepresentAsPointer>
 */
extern int asn1p_as_pointer;

/*
 * This temporary variable is used to solve the shortcomings of 1-lookahead
 * parser.
 */
static struct AssignedIdentifier *saved_aid;

static asn1p_value_t *_convert_bitstring2binary(char *str, int base);
static void _fixup_anonymous_identifier(asn1p_expr_t *expr);

static asn1p_module_t *currentModule;
#define	NEW_EXPR()	(asn1p_expr_new(yylineno, currentModule))

#define	checkmem(ptr)	do {						\
		if(!(ptr))						\
		return yyerror("Memory failure");			\
	} while(0)

#define	CONSTRAINT_INSERT(root, constr_type, arg1, arg2) do {		\
		if(arg1->type != constr_type) {				\
			int __ret;					\
			root = asn1p_constraint_new(yylineno, currentModule);	\
			checkmem(root);					\
			root->type = constr_type;			\
			__ret = asn1p_constraint_insert(root,		\
				arg1);					\
			checkmem(__ret == 0);				\
		} else {						\
			root = arg1;					\
		}							\
		if(arg2) {						\
			int __ret					\
			= asn1p_constraint_insert(root, arg2);		\
			checkmem(__ret == 0);				\
		}							\
	} while(0)

#ifdef	AL_IMPORT
#error	AL_IMPORT DEFINED ELSEWHERE!
#endif
#define AL_IMPORT(to, where, from, field)                                      \
    do {                                                                       \
        if(!(from)) break;                                                     \
        while(TQ_FIRST(&((from)->where))) {                                    \
            TQ_ADD(&((to)->where), TQ_REMOVE(&((from)->where), field), field); \
        }                                                                      \
        assert(TQ_FIRST(&((from)->where)) == 0);                               \
    } while(0)

%}


/*
 * Token value definition.
 * a_*:   ASN-specific types.
 * tv_*:  Locally meaningful types.
 */
%union {
	asn1p_t			*a_grammar;
	asn1p_module_flags_e	 a_module_flags;
	asn1p_module_t		*a_module;
	asn1p_expr_type_e	 a_type;	/* ASN.1 Type */
	asn1p_expr_t		*a_expr;	/* Constructed collection */
	asn1p_constraint_t	*a_constr;	/* Constraint */
	enum asn1p_constraint_type_e	a_ctype;/* Constraint type */
	asn1p_xports_t		*a_xports;	/* IMports/EXports */
	struct AssignedIdentifier a_aid;	/* Assigned Identifier */
	asn1p_oid_t		*a_oid;		/* Object Identifier */
	asn1p_oid_arc_t		 a_oid_arc;	/* Single OID's arc */
	struct asn1p_type_tag_s	 a_tag;		/* A tag */
	asn1p_ref_t		*a_ref;		/* Reference to custom type */
	asn1p_wsyntx_t		*a_wsynt;	/* WITH SYNTAX contents */
	asn1p_wsyntx_chunk_t	*a_wchunk;	/* WITH SYNTAX chunk */
	struct asn1p_ref_component_s a_refcomp;	/* Component of a reference */
	asn1p_value_t		*a_value;	/* Number, DefinedValue, etc */
	struct asn1p_param_s	 a_parg;	/* A parameter argument */
	asn1p_paramlist_t	*a_plist;	/* A pargs list */
	struct asn1p_expr_marker_s a_marker;	/* OPTIONAL/DEFAULT */
	enum asn1p_constr_pres_e a_pres;	/* PRESENT/ABSENT/OPTIONAL */
	asn1c_integer_t		 a_int;
	double			 a_dbl;
	char	*tv_str;
	struct {
		char *buf;
		int len;
	}	tv_opaque;
	struct {
		char *name;
		struct asn1p_type_tag_s tag;
	} tv_nametag;
};

/*
 * Token types returned by scanner.
 */
%token			TOK_PPEQ	/* "::=", Pseudo Pascal EQuality */
%token			TOK_VBracketLeft TOK_VBracketRight	/* "[[", "]]" */
%token	<tv_opaque>	TOK_whitespace	/* A span of whitespace */
%token	<tv_opaque>	TOK_opaque	/* opaque data (driven from .y) */
%token	<tv_str>	TOK_bstring
%token	<tv_opaque>	TOK_cstring
%token	<tv_str>	TOK_hstring
%token	<tv_str>	TOK_identifier "identifier"
%token	<a_int>		TOK_number "number"
%token	<a_int>		TOK_number_negative "negative number"
%token	<a_dbl>		TOK_realnumber
%token	<a_int>		TOK_tuple
%token	<a_int>		TOK_quadruple
%token	<tv_str>	TOK_typereference
%token	<tv_str>	TOK_capitalreference		/* "CLASS1" */
%token	<tv_str>	TOK_typefieldreference		/* "&Pork" */
%token	<tv_str>	TOK_valuefieldreference		/* "&id" */
%token	<tv_str>	TOK_Literal			/* "BY" */

/*
 * Tokens available with asn1p_lexer_hack_push_extended_values().
 */
%token              TOK_ExtValue_BIT_STRING

/*
 * Token types representing ASN.1 standard keywords.
 */
%token			TOK_ABSENT
%token			TOK_ABSTRACT_SYNTAX
%token			TOK_ALL
%token			TOK_ANY
%token			TOK_APPLICATION
%token			TOK_AUTOMATIC
%token			TOK_BEGIN
%token			TOK_BIT
%token			TOK_BMPString
%token			TOK_BOOLEAN
%token			TOK_BY
%token			TOK_CHARACTER
%token			TOK_CHOICE
%token			TOK_CLASS
%token			TOK_COMPONENT
%token			TOK_COMPONENTS
%token			TOK_CONSTRAINED
%token			TOK_CONTAINING
%token			TOK_DEFAULT
%token			TOK_DEFINITIONS
%token			TOK_DEFINED
%token			TOK_EMBEDDED
%token			TOK_ENCODED
%token			TOK_ENCODING_CONTROL
%token			TOK_END
%token			TOK_ENUMERATED
%token			TOK_EXPLICIT
%token			TOK_EXPORTS
%token			TOK_EXTENSIBILITY
%token			TOK_EXTERNAL
%token			TOK_FALSE
%token			TOK_FROM
%token			TOK_GeneralizedTime
%token			TOK_GeneralString
%token			TOK_GraphicString
%token			TOK_IA5String
%token			TOK_IDENTIFIER
%token			TOK_IMPLICIT
%token			TOK_IMPLIED
%token			TOK_IMPORTS
%token			TOK_INCLUDES
%token			TOK_INSTANCE
%token			TOK_INSTRUCTIONS
%token			TOK_INTEGER
%token			TOK_ISO646String
%token			TOK_MAX
%token			TOK_MIN
%token			TOK_MINUS_INFINITY
%token			TOK_NULL
%token			TOK_NumericString
%token			TOK_OBJECT
%token			TOK_ObjectDescriptor
%token			TOK_OCTET
%token			TOK_OF
%token			TOK_OPTIONAL
%token			TOK_PATTERN
%token			TOK_PDV
%token			TOK_PLUS_INFINITY
%token			TOK_PRESENT
%token			TOK_PrintableString
%token			TOK_PRIVATE
%token			TOK_REAL
%token			TOK_RELATIVE_OID
%token			TOK_SEQUENCE
%token			TOK_SET
%token			TOK_SIZE
%token			TOK_STRING
%token			TOK_SYNTAX
%token			TOK_T61String
%token			TOK_TAGS
%token			TOK_TeletexString
%token			TOK_TRUE
%token			TOK_TYPE_IDENTIFIER
%token			TOK_UNIQUE
%token			TOK_UNIVERSAL
%token			TOK_UniversalString
%token			TOK_UTCTime
%token			TOK_UTF8String
%token			TOK_VideotexString
%token			TOK_VisibleString
%token			TOK_WITH
%token			UTF8_BOM    "UTF-8 byte order mark"

%nonassoc		TOK_EXCEPT
%left			'^' TOK_INTERSECTION
%left			'|' TOK_UNION

/* Misc tags */
%token			TOK_TwoDots		".."
%token			TOK_ThreeDots	"..."


/*
 * Types defined herein.
 */
%type	<a_grammar>		ModuleList
%type	<a_module>		ModuleDefinition
%type	<a_module>		ModuleBody
%type	<a_module>		AssignmentList
%type	<a_module>		Assignment
%type	<a_module>		optModuleBody	/* Optional */
%type	<a_module_flags>	optModuleDefinitionFlags
%type	<a_module_flags>	ModuleDefinitionFlags	/* Set of FL */
%type	<a_module_flags>	ModuleDefinitionFlag		/* Single FL */
%type	<a_module>		optImports
%type	<a_module>		optExports
%type	<a_module>		ImportsDefinition
%type	<a_module>		optImportsBundleSet
%type	<a_module>		ImportsBundleSet
%type	<a_xports>		ImportsBundle
%type	<a_xports>		ImportsList
%type	<a_xports>		ExportsDefinition
%type	<a_xports>		ExportsBody
%type	<a_expr>		ImportsElement
%type	<a_expr>		ExportsElement
%type	<a_expr>		ExtensionAndException
%type	<a_expr>		Type
%type	<a_expr>		TaggedType
%type	<a_expr>		MaybeIndirectTaggedType
%type	<a_expr>		UntaggedType
%type	<a_expr>		DefinedUntaggedType
%type	<a_expr>		ConcreteTypeDeclaration "concrete TypeDeclaration"
%type	<a_expr>		TypeDeclaration
%type	<a_expr>		MaybeIndirectTypeDeclaration
%type	<a_ref>			ComplexTypeReference
%type	<a_ref>			ComplexTypeReferenceAmpList
%type	<a_refcomp>		ComplexTypeReferenceElement
%type	<a_refcomp>		PrimitiveFieldReference
%type	<a_expr>		FieldSpec
%type	<a_ref>			FieldName
%type	<a_ref>			DefinedObjectClass
%type	<a_expr>		ClassField
%type	<a_expr>		ObjectClass
%type	<a_expr>		DataTypeReference	/* Type1 ::= Type2 */
%type	<a_expr>		DefinedType
%type	<a_constr>		ValueSet		/* {a|b|c}*/
%type	<a_expr>		ValueSetTypeAssignment  /* Val INTEGER ::= {1|2} */
%type	<a_expr>		ValueAssignment		/* val INTEGER ::= 1*/
%type	<a_value>		Value
%type	<a_value>		SimpleValue
%type	<a_value>		DefinedValue
%type	<a_value>		SignedNumber
%type	<a_value>		RealValue
%type	<a_value>		BitStringValue
%type	<a_expr>		optComponentTypeLists
%type	<a_expr>		ComponentTypeLists
%type	<a_expr>		ComponentType
%type	<a_expr>		AlternativeTypeLists
%type	<a_expr>		AlternativeType
%type	<a_expr>		UniverationList
%type	<a_expr>		Enumerations
%type	<a_expr>		NamedBitList
%type	<a_expr>		NamedBit
%type	<a_expr>		NamedNumberList
%type	<a_expr>		NamedNumber
%type	<a_expr>		IdentifierList
%type	<a_expr>		IdentifierElement
%type	<a_expr>		UniverationElement
%type	<tv_str>		TypeRefName
%type	<tv_str>		Identifier
%type	<a_ref>		    IdentifierAsReference
%type	<a_value>		IdentifierAsValue
%type	<tv_str>		optIdentifier
%type	<a_parg>		ParameterArgumentName
%type	<a_plist>		ParameterArgumentList
%type	<a_expr>		ActualParameter
%type	<a_expr>		ActualParameterList
%type	<a_aid>			AssignedIdentifier	/* OID/DefinedValue */
%type	<a_oid>			ObjectIdentifier	/* OID */
%type	<a_oid>			optObjectIdentifier	/* Optional OID */
%type	<a_oid>			ObjectIdentifierBody
%type	<a_oid_arc>		ObjectIdentifierElement
%type	<a_expr>		BuiltinType
%type	<a_type>		BasicTypeId
%type	<a_type>		BasicTypeId_UniverationCompatible
%type	<a_type>		BasicString
%type	<tv_opaque>		Opaque
%type	<tv_opaque>		OpaqueFirstToken
%type	<a_tag>			Tag 		/* [UNIVERSAL 0] IMPLICIT */
%type	<a_tag>			TagClass TagTypeValue TagPlicit
%type	<a_tag>			optTag		/* [UNIVERSAL 0] IMPLICIT */
%type	<a_constr>		optConstraint
%type	<a_constr>		optManyConstraints  /* Only for Type */
%type	<a_constr>		ManyConstraints
%type	<a_constr>		optSizeOrConstraint
%type	<a_constr>		Constraint
%type	<a_constr>		PermittedAlphabet
%type	<a_constr>		SizeConstraint
%type	<a_constr>		SingleTypeConstraint
%type	<a_constr>		MultipleTypeConstraints
%type	<a_constr>		NamedConstraint
%type	<a_constr>		FullSpecification
%type	<a_constr>		PartialSpecification
%type	<a_constr>		TypeConstraints
%type	<a_constr>		ConstraintSpec
%type	<a_constr>		SubtypeConstraint
%type	<a_constr>		GeneralConstraint
%type	<a_constr>		ElementSetSpecs		/* 1..2,...,3 */
%type	<a_constr>		ElementSetSpec		/* 1..2 */
%type	<a_constr>		Unions
%type	<a_constr>		Intersections
%type	<a_constr>		IntersectionElements
%type	<a_constr>		Elements
%type	<a_constr>		SubtypeElements /* 1..2 */
%type	<a_constr>		SimpleTableConstraint
%type	<a_constr>		UserDefinedConstraint
%type	<a_constr>		TableConstraint
%type	<a_constr>		ContentsConstraint
%type	<a_constr>		PatternConstraint
%type	<a_constr>		InnerTypeConstraints
%type	<a_constr>		ValueRange
%type	<a_constr>		ComponentRelationConstraint
%type	<a_constr>		AtNotationList
%type	<a_ref>			AtNotationElement
%type	<a_value>		SingleValue
%type	<a_value>		LowerEndValue
%type	<a_value>		UpperEndValue
%type	<a_value>		ContainedSubtype
%type	<a_ctype>		ConstraintRangeSpec
%type	<a_value>		RestrictedCharacterStringValue
%type	<a_wsynt>		optWithSyntax
%type	<a_wsynt>		WithSyntax
%type	<a_wsynt>		WithSyntaxList
%type	<a_wchunk>		WithSyntaxToken
%type	<a_marker>		optMarker Marker
%type	<a_int>			optUNIQUE
%type	<a_pres>		optPresenceConstraint PresenceConstraint
%type	<tv_str>		ComponentIdList
%type	<a_int>			NSTD_IndirectMarker

%%


ParsedGrammar:
	UTF8_BOM ModuleList {
		*(void **)param = $2;
	}
	| ModuleList {
		*(void **)param = $1;
	}
	;

ModuleList:
	ModuleDefinition {
		$$ = asn1p_new();
		checkmem($$);
		TQ_ADD(&($$->modules), $1, mod_next);
	}
	| ModuleList ModuleDefinition {
		$$ = $1;
		TQ_ADD(&($$->modules), $2, mod_next);
	}
	;

/*
 * ASN module definition.
 * === EXAMPLE ===
 * MySyntax DEFINITIONS AUTOMATIC TAGS ::=
 * BEGIN
 * ...
 * END 
 * === EOF ===
 */

ModuleDefinition:
	TypeRefName { currentModule = asn1p_module_new(); }
	optObjectIdentifier TOK_DEFINITIONS
		optModuleDefinitionFlags
		TOK_PPEQ TOK_BEGIN
		optModuleBody
		TOK_END {

		$$ = currentModule;

		if($8) {
			asn1p_module_t tmp = *($$);
			*($$) = *($8);
			*($8) = tmp;
			asn1p_module_free($8);
		} else {
			/* There's a chance that a module is just plain empty */
		}

		$$->ModuleName = $1;
		$$->module_oid = $3;
		$$->module_flags = $5;
	}
	;

/*
 * Object Identifier Definition
 * { iso member-body(2) 3 }
 */
optObjectIdentifier:
	{ $$ = 0; }
	| ObjectIdentifier { $$ = $1; }
	;
	
ObjectIdentifier:
	'{' ObjectIdentifierBody '}' {
		$$ = $2;
	}
	| '{' '}' {
		$$ = 0;
	}
	;

ObjectIdentifierBody:
	ObjectIdentifierElement {
		$$ = asn1p_oid_new();
		asn1p_oid_add_arc($$, &$1);
		if($1.name)
			free($1.name);
	}
	| ObjectIdentifierBody ObjectIdentifierElement {
		$$ = $1;
		asn1p_oid_add_arc($$, &$2);
		if($2.name)
			free($2.name);
	}
	;

ObjectIdentifierElement:
	Identifier {					/* iso */
		$$.name = $1;
		$$.number = -1;
	}
	| Identifier '(' TOK_number ')' {		/* iso(1) */
		$$.name = $1;
		$$.number = $3;
	}
	| TOK_number {					/* 1 */
		$$.name = 0;
		$$.number = $1;
	}
	;
	
/*
 * Optional module flags.
 */
optModuleDefinitionFlags:
	{ $$ = MSF_NOFLAGS; }
	| ModuleDefinitionFlags {
		$$ = $1;
	}
	;

/*
 * Module flags.
 */
ModuleDefinitionFlags:
	ModuleDefinitionFlag {
		$$ = $1;
	}
	| ModuleDefinitionFlags ModuleDefinitionFlag {
		$$ = $1 | $2;
	}
	;

/*
 * Single module flag.
 */
ModuleDefinitionFlag:
	TOK_EXPLICIT TOK_TAGS {
		$$ = MSF_EXPLICIT_TAGS;
	}
	| TOK_IMPLICIT TOK_TAGS {
		$$ = MSF_IMPLICIT_TAGS;
	}
	| TOK_AUTOMATIC TOK_TAGS {
		$$ = MSF_AUTOMATIC_TAGS;
	}
	| TOK_EXTENSIBILITY TOK_IMPLIED {
		$$ = MSF_EXTENSIBILITY_IMPLIED;
	}
	/* EncodingReferenceDefault */
	| TOK_capitalreference TOK_INSTRUCTIONS {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp($1, "TAG") == 0) {
		 	$$ = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp($1, "XER") == 0) {
		 	$$ = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at %s:%d: "
				"Unrecognized encoding reference\n",
				$1, ASN_FILENAME, yylineno);
		 	$$ = MSF_unk_INSTRUCTIONS;
		}
		free($1);
	}
	;

/*
 * Optional module body.
 */
optModuleBody:
	{ $$ = 0; }
	| ModuleBody {
		$$ = $1;
	}
	;

/*
 * ASN.1 Module body.
 */
ModuleBody:
	optExports optImports AssignmentList {
		$$ = asn1p_module_new();
		AL_IMPORT($$, exports, $1, xp_next);
		AL_IMPORT($$, imports, $2, xp_next);
		asn1p_module_move_members($$, $3);

		asn1p_module_free($1);
		asn1p_module_free($2);
		asn1p_module_free($3);
	}
	;

AssignmentList:
	Assignment {
		$$ = $1;
	}
	| AssignmentList Assignment {
		if($1) {
			$$ = $1;
		} else {
			$$ = $2;
			break;
		}
        asn1p_module_move_members($$, $2);
		asn1p_module_free($2);
	}
	;


/*
 * One of the elements of ASN.1 module specification.
 */
Assignment:
	DataTypeReference {
		$$ = asn1p_module_new();
		checkmem($$);
		assert($1->expr_type != A1TC_INVALID);
		assert($1->meta_type != AMT_INVALID);
		asn1p_module_member_add($$, $1);
	}
	| ValueAssignment {
		$$ = asn1p_module_new();
		checkmem($$);
		assert($1->expr_type != A1TC_INVALID);
		assert($1->meta_type != AMT_INVALID);
		asn1p_module_member_add($$, $1);
	}
	/*
	 * Value set definition
	 * === EXAMPLE ===
	 * EvenNumbers INTEGER ::= { 2 | 4 | 6 | 8 }
	 * === EOF ===
	 * Also ObjectClassSet.
	 */
	| ValueSetTypeAssignment {
		$$ = asn1p_module_new();
		checkmem($$);
		assert($1->expr_type != A1TC_INVALID);
		assert($1->meta_type != AMT_INVALID);
		asn1p_module_member_add($$, $1);
	}
	| TOK_ENCODING_CONTROL TOK_capitalreference 
		{ asn1p_lexer_hack_push_encoding_control(); }
			{
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at %s:%d ignored\n",
			$2, ASN_FILENAME, yylineno);
		free($2);
		$$ = 0;
	}

	/*
	 * Erroneous attemps
	 */
	| BasicString {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
	;

/*
 * === EXAMPLE ===
 * IMPORTS Type1, value FROM Module { iso standard(0) } ;
 * === EOF ===
 */
optImports:
	{ $$ = 0; }
	| ImportsDefinition;

ImportsDefinition:
	TOK_IMPORTS optImportsBundleSet ';' {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		$$ = $2;
	}
	/*
	 * Some error cases.
	 */
	| TOK_IMPORTS TOK_FROM /* ... */ {
		return yyerror("Empty IMPORTS list");
	}
	;

optImportsBundleSet:
	{ $$ = asn1p_module_new(); }
	| ImportsBundleSet;

ImportsBundleSet:
	ImportsBundle {
		$$ = asn1p_module_new();
		checkmem($$);
		TQ_ADD(&($$->imports), $1, xp_next);
	}
	| ImportsBundleSet ImportsBundle {
		$$ = $1;
		TQ_ADD(&($$->imports), $2, xp_next);
	}
	;

AssignedIdentifier:
	{ memset(&$$, 0, sizeof($$)); }
	| ObjectIdentifier { $$.oid = $1; };
	/* | DefinedValue { $$.value = $1; }; // Handled through saved_aid */

ImportsBundle:
	ImportsList TOK_FROM TypeRefName AssignedIdentifier {
		$$ = $1;
		$$->fromModuleName = $3;
		$$->identifier = $4;
		/* This stupid thing is used for look-back hack. */
		saved_aid = $$->identifier.oid ? 0 : &($$->identifier);
		checkmem($$);
	}
	;

ImportsList:
	ImportsElement {
		$$ = asn1p_xports_new();
		checkmem($$);
		TQ_ADD(&($$->xp_members), $1, next);
	}
	| ImportsList ',' ImportsElement {
		$$ = $1;
		TQ_ADD(&($$->xp_members), $3, next);
	}
	;

ImportsElement:
	TypeRefName {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_REFERENCE;
	}
	| TypeRefName '{' '}' {		/* Completely equivalent to above */
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_REFERENCE;
	}
	| Identifier {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_REFERENCE;
	}
	;


optExports:
	{ $$ = 0; }
	| ExportsDefinition {
		$$ = asn1p_module_new();
		checkmem($$);
		if($1) {
			TQ_ADD(&($$->exports), $1, xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
	;

ExportsDefinition:
	TOK_EXPORTS ExportsBody ';' {
		$$ = $2;
	}
	| TOK_EXPORTS TOK_ALL ';' {
		$$ = 0;
	}
	| TOK_EXPORTS ';' {
		/* Empty EXPORTS clause effectively prohibits export. */
		$$ = asn1p_xports_new();
		checkmem($$);
	}
	;

ExportsBody:
	ExportsElement {
		$$ = asn1p_xports_new();
		assert($$);
		TQ_ADD(&($$->xp_members), $1, next);
	}
	| ExportsBody ',' ExportsElement {
		$$ = $1;
		TQ_ADD(&($$->xp_members), $3, next);
	}
	;

ExportsElement:
	TypeRefName {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_EXPORTVAR;
	}
	| TypeRefName '{' '}' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_EXPORTVAR;
	}
	| Identifier {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->expr_type = A1TC_EXPORTVAR;
	}
	;


ValueSet: '{' ElementSetSpecs '}' { $$ = $2; };

ValueSetTypeAssignment:
	TypeRefName Type TOK_PPEQ ValueSet {
		$$ = $2;
		assert($$->Identifier == 0);
		$$->Identifier = $1;
		$$->meta_type = AMT_VALUESET;
		$$->constraints = $4;
	}
	;

DefinedType:
	/*
	 * A DefinedType reference.
	 * "CLASS1.&id.&id2"
	 * or
	 * "Module.Type"
	 * or
	 * "Module.identifier"
	 * or
	 * "Type"
	 */
	ComplexTypeReference {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->reference = $1;
		$$->expr_type = A1TC_REFERENCE;
		$$->meta_type = AMT_TYPEREF;
	}
	/*
	 * A parameterized assignment.
	 */
	| ComplexTypeReference '{' ActualParameterList '}' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->reference = $1;
		$$->rhs_pspecs = $3;
		$$->expr_type = A1TC_REFERENCE;
		$$->meta_type = AMT_TYPEREF;
	}
	;

/*
 * Data Type Reference.
 * === EXAMPLE ===
 * Type3 ::= CHOICE { a Type1,  b Type 2 }
 * === EOF ===
 */
DataTypeReference:
	/*
	 * Optionally tagged type definition.
	 */
	TypeRefName TOK_PPEQ Type {
		$$ = $3;
		$$->Identifier = $1;
		assert($$->expr_type);
		assert($$->meta_type);
	}
	| TypeRefName TOK_PPEQ ObjectClass {
		$$ = $3;
		$$->Identifier = $1;
		assert($$->expr_type == A1TC_CLASSDEF);
		assert($$->meta_type == AMT_OBJECTCLASS);
	}
	/*
	 * Parameterized <Type> declaration:
	 * === EXAMPLE ===
	 *   SIGNED { ToBeSigned } ::= SEQUENCE {
	 *      toBeSigned  ToBeSigned,
	 *      algorithm   AlgorithmIdentifier,
	 *      signature   BIT STRING
	 *   }
	 * === EOF ===
	 */
	| TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ Type {
		$$ = $6;
		$$->Identifier = $1;
		$$->lhs_params = $3;
	}
	/* Parameterized CLASS declaration */
	| TypeRefName '{' ParameterArgumentList '}' TOK_PPEQ ObjectClass {
		$$ = $6;
		$$->Identifier = $1;
		$$->lhs_params = $3;
	}
	;

ParameterArgumentList:
	ParameterArgumentName {
		int ret;
		$$ = asn1p_paramlist_new(yylineno);
		checkmem($$);
		ret = asn1p_paramlist_add_param($$, $1.governor, $1.argument);
		checkmem(ret == 0);
		asn1p_ref_free($1.governor);
		free($1.argument);
	}
	| ParameterArgumentList ',' ParameterArgumentName {
		int ret;
		$$ = $1;
		ret = asn1p_paramlist_add_param($$, $3.governor, $3.argument);
		checkmem(ret == 0);
		asn1p_ref_free($3.governor);
		free($3.argument);
	}
	;
	
ParameterArgumentName:
	TypeRefName {
		$$.governor = NULL;
		$$.argument = $1;
	}
	| TypeRefName ':' Identifier {
		int ret;
		$$.governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$.governor, $1, 0);
		checkmem(ret == 0);
		$$.argument = $3;
		free($1);
	}
	| TypeRefName ':' TypeRefName {
		int ret;
		$$.governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$.governor, $1, 0);
		checkmem(ret == 0);
		$$.argument = $3;
		free($1);
	}
	| BasicTypeId ':' Identifier {
		int ret;
		$$.governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$.governor,
			ASN_EXPR_TYPE2STR($1), 1);
		checkmem(ret == 0);
		$$.argument = $3;
	}
	| BasicTypeId ':' TypeRefName {
		int ret;
		$$.governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$.governor,
			ASN_EXPR_TYPE2STR($1), 1);
		checkmem(ret == 0);
		$$.argument = $3;
	}
	;

ActualParameterList:
	ActualParameter {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| ActualParameterList ',' ActualParameter {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

ActualParameter:
	UntaggedType    /* act. Type */
	| SimpleValue {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("?");
		$$->expr_type = A1TC_REFERENCE;
		$$->meta_type = AMT_VALUE;
		$$->value = $1;
	}
	| DefinedValue {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("?");
		$$->expr_type = A1TC_REFERENCE;
		$$->meta_type = AMT_VALUE;
		$$->value = $1;
	}
	| ValueSet {
		$$ = NEW_EXPR();
		$$->expr_type = A1TC_VALUESET;
		$$->meta_type = AMT_VALUESET;
		$$->constraints = $1;
	}
	;

/*
	| '{' ActualParameter '}' {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $2);
		$$->expr_type = A1TC_PARAMETRIZED;
		$$->meta_type = AMT_TYPE;
	}
	;
*/

/*
 * A collection of constructed data type members.
 */
optComponentTypeLists:
	{ $$ = NEW_EXPR(); }
	| ComponentTypeLists { $$ = $1; };

ComponentTypeLists:
	ComponentType {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| ComponentTypeLists ',' ComponentType {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	| ComponentTypeLists ',' TOK_VBracketLeft ComponentTypeLists TOK_VBracketRight {
		$$ = $1;
		asn1p_expr_add_many($$, $4);
		asn1p_expr_free($4);
	}
	;

ComponentType:
	Identifier MaybeIndirectTaggedType optMarker {
		$$ = $2;
		assert($$->Identifier == 0);
		$$->Identifier = $1;
		$3.flags |= $$->marker.flags;
		$$->marker = $3;
	}
	| MaybeIndirectTaggedType optMarker {
		$$ = $1;
		$2.flags |= $$->marker.flags;
		$$->marker = $2;
		_fixup_anonymous_identifier($$);
	}
	| TOK_COMPONENTS TOK_OF MaybeIndirectTaggedType {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->meta_type = $3->meta_type;
		$$->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add($$, $3);
	}
	| ExtensionAndException {
		$$ = $1;
	}
	;

AlternativeTypeLists:
	AlternativeType {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| AlternativeTypeLists ',' AlternativeType {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

AlternativeType:
	Identifier MaybeIndirectTaggedType {
		$$ = $2;
		assert($$->Identifier == 0);
		$$->Identifier = $1;
	}
	| ExtensionAndException {
		$$ = $1;
	}
	| MaybeIndirectTaggedType {
		$$ = $1;
		_fixup_anonymous_identifier($$);
	}
	;

ObjectClass:
	TOK_CLASS '{' FieldSpec '}' optWithSyntax {
		$$ = $3;
		checkmem($$);
		$$->with_syntax = $5;
		assert($$->expr_type == A1TC_CLASSDEF);
		assert($$->meta_type == AMT_OBJECTCLASS);
	}
	;

optUNIQUE:
	{ $$ = 0; }
	| TOK_UNIQUE { $$ = 1; }
	;

FieldSpec:
	ClassField {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_CLASSDEF;
		$$->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add($$, $1);
	}
	| FieldSpec ',' ClassField {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

	/* X.681 */
ClassField:

	/* TypeFieldSpec ::= typefieldreference TypeOptionalitySpec? */
	TOK_typefieldreference optMarker {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		$$->marker = $2;
	}

	/* FixedTypeValueFieldSpec ::= valuefieldreference Type UNIQUE ? ValueOptionalitySpec ? */
	| TOK_valuefieldreference Type optUNIQUE optMarker {
		$$ = NEW_EXPR();
		$$->Identifier = $1;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		$$->unique = $3;
		$$->marker = $4;
		asn1p_expr_add($$, $2);
	}

	/* VariableTypeValueFieldSpec ::= valuefieldreference FieldName ValueOptionalitySpec ? */
	| TOK_valuefieldreference FieldName optMarker {
		$$ = NEW_EXPR();
		$$->Identifier = $1;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_VTVFS;
		$$->reference = $2;
		$$->marker = $3;
	}

	/*  ObjectFieldSpec ::= objectfieldreference DefinedObjectClass ObjectOptionalitySpec ? */
	| TOK_valuefieldreference DefinedObjectClass optMarker {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->reference = $2;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_OFS;
		$$->marker = $3;
	}

	/* VariableTypeValueSetFieldSpec ::= valuesetfieldreference FieldName ValueOptionalitySpec ? */
	| TOK_typefieldreference FieldName optMarker {
		$$ = NEW_EXPR();
		$$->Identifier = $1;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_VTVSFS;
		$$->reference = $2;
		$$->marker = $3;
	}

	/* FixedTypeValueSetFieldSpec ::= valuesetfieldreference Type ValueSetOptionalitySpec ? */
	| TOK_typefieldreference Type optMarker {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add($$, $2);
		$$->marker = $3;
	}

	/*  ObjectSetFieldSpec ::= objectsetfieldreference DefinedObjectClass ObjectOptionalitySpec ? */
	| TOK_typefieldreference DefinedObjectClass optMarker {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = $1;
		$$->reference = $2;
		$$->meta_type = AMT_OBJECTFIELD;
		$$->expr_type = A1TC_CLASSFIELD_OSFS;
		$$->marker = $3;
	}
	;

optWithSyntax:
	{ $$ = 0; }
	| WithSyntax {
		$$ = $1;
	}
	;

WithSyntax:
	TOK_WITH TOK_SYNTAX '{'
		{ asn1p_lexer_hack_enable_with_syntax(); }
		WithSyntaxList
		'}' {
		$$ = $5;
	}
	;

WithSyntaxList:
	WithSyntaxToken {
		$$ = asn1p_wsyntx_new();
		TQ_ADD(&($$->chunks), $1, next);
	}
	| WithSyntaxList WithSyntaxToken {
		$$ = $1;
		TQ_ADD(&($$->chunks), $2, next);
	}
	;

WithSyntaxToken:
	TOK_whitespace {
		$$ = asn1p_wsyntx_chunk_fromstring($1.buf, 0);
		$$->type = WC_WHITESPACE;
	}
	| TOK_Literal {
		$$ = asn1p_wsyntx_chunk_fromstring($1, 0);
	}
	| PrimitiveFieldReference {
		$$ = asn1p_wsyntx_chunk_fromstring($1.name, 0);
		$$->type = WC_FIELD;
	}
	| '[' WithSyntaxList ']' {
		$$ = asn1p_wsyntx_chunk_fromsyntax($2);
	}
	;

ExtensionAndException:
	TOK_ThreeDots {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("...");
		checkmem($$->Identifier);
		$$->expr_type = A1TC_EXTENSIBLE;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_ThreeDots '!' DefinedValue {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("...");
		checkmem($$->Identifier);
		$$->value = $3;
		$$->expr_type = A1TC_EXTENSIBLE;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_ThreeDots '!' SignedNumber {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("...");
		$$->value = $3;
		checkmem($$->Identifier);
		$$->expr_type = A1TC_EXTENSIBLE;
		$$->meta_type = AMT_TYPE;
	}
	;

Type: TaggedType;

TaggedType:
    optTag UntaggedType {
        $$ = $2;
        $$->tag = $1;
    }
    ;

DefinedUntaggedType:
	DefinedType optManyConstraints {
		$$ = $1;
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if($$->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| $$->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&($$->members))->constraints);
			TQ_FIRST(&($$->members))->constraints = $2;
		} else {
			if($$->constraints) {
				assert(!$2);
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free($2);
			} else {
				$$->constraints = $2;
			}
		}
	}
	;

UntaggedType:
	TypeDeclaration optManyConstraints {
		$$ = $1;
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if($$->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| $$->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&($$->members))->constraints);
			TQ_FIRST(&($$->members))->constraints = $2;
		} else {
			if($$->constraints) {
				assert(!$2);
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free($2);
			} else {
				$$->constraints = $2;
			}
		}
	}
	;

MaybeIndirectTaggedType:
    optTag MaybeIndirectTypeDeclaration optManyConstraints {
		$$ = $2;
		$$->tag = $1;
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if($$->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| $$->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&($$->members))->constraints);
			TQ_FIRST(&($$->members))->constraints = $3;
		} else {
			if($$->constraints) {
				assert(!$2);
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free($3);
			} else {
				$$->constraints = $3;
			}
		}
	}
    ;

NSTD_IndirectMarker:
	{
		$$ = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
	;

MaybeIndirectTypeDeclaration:
    NSTD_IndirectMarker TypeDeclaration {
        $$ = $2;
		$$->marker.flags |= $1;

		if(($$->marker.flags & EM_INDIRECT)
		&& ($$->marker.flags & EM_OPTIONAL) != EM_OPTIONAL) {
			fprintf(stderr,
				"INFO: Directive <ASN1C:RepresentAsPointer> "
				"applied to %s at %s:%d\n",
				ASN_EXPR_TYPE2STR($$->expr_type)
					?  ASN_EXPR_TYPE2STR($$->expr_type)
					: "member",
				ASN_FILENAME, $$->_lineno
			);
		}
    }
    ;

TypeDeclaration:
    ConcreteTypeDeclaration
    | DefinedType;

ConcreteTypeDeclaration:
	BuiltinType
	| TOK_CHOICE '{' AlternativeTypeLists '}' {
		$$ = $3;
		assert($$->expr_type == A1TC_INVALID);
		$$->expr_type = ASN_CONSTR_CHOICE;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_SEQUENCE '{' optComponentTypeLists '}' {
		$$ = $3;
		assert($$->expr_type == A1TC_INVALID);
		$$->expr_type = ASN_CONSTR_SEQUENCE;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_SET '{' optComponentTypeLists '}' {
		$$ = $3;
		assert($$->expr_type == A1TC_INVALID);
		$$->expr_type = ASN_CONSTR_SET;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_SEQUENCE optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->constraints = $2;
		$$->expr_type = ASN_CONSTR_SEQUENCE_OF;
		$$->meta_type = AMT_TYPE;
		$6->Identifier = $4;
		$6->tag = $5;
		asn1p_expr_add($$, $6);
	}
	| TOK_SET optSizeOrConstraint TOK_OF optIdentifier optTag MaybeIndirectTypeDeclaration {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->constraints = $2;
		$$->expr_type = ASN_CONSTR_SET_OF;
		$$->meta_type = AMT_TYPE;
		$6->Identifier = $4;
		$6->tag = $5;
		asn1p_expr_add($$, $6);
	}
	| TOK_ANY 					{
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = ASN_TYPE_ANY;
		$$->meta_type = AMT_TYPE;
	}
	| TOK_ANY TOK_DEFINED TOK_BY Identifier		{
		int ret;
		$$ = NEW_EXPR();
		checkmem($$);
		$$->reference = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$->reference,
			$4, RLT_lowercase);
		checkmem(ret == 0);
		$$->expr_type = ASN_TYPE_ANY;
		$$->meta_type = AMT_TYPE;
		free($4);
	}
	| TOK_INSTANCE TOK_OF ComplexTypeReference {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->reference = $3;
		$$->expr_type = A1TC_INSTANCE;
		$$->meta_type = AMT_TYPE;
	}
	;

/*
 * A type name consisting of several components.
 * === EXAMPLE ===
 * === EOF ===
 */
ComplexTypeReference:
	TOK_typereference {
		int ret;
		$$ = asn1p_ref_new(yylineno, currentModule);
		checkmem($$);
		ret = asn1p_ref_add_component($$, $1, RLT_UNKNOWN);
		checkmem(ret == 0);
		free($1);
	}
	| TOK_capitalreference {
		int ret;
		$$ = asn1p_ref_new(yylineno, currentModule);
		checkmem($$);
		ret = asn1p_ref_add_component($$, $1, RLT_CAPITALS);
		free($1);
		checkmem(ret == 0);
	}
	| TOK_typereference '.' TypeRefName {
		int ret;
		$$ = asn1p_ref_new(yylineno, currentModule);
		checkmem($$);
		ret = asn1p_ref_add_component($$, $1, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component($$, $3, RLT_UNKNOWN);
		checkmem(ret == 0);
		free($1);
		free($3);
	}
	| TOK_capitalreference '.' TypeRefName {
		int ret;
		$$ = asn1p_ref_new(yylineno, currentModule);
		checkmem($$);
		ret = asn1p_ref_add_component($$, $1, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component($$, $3, RLT_UNKNOWN);
		checkmem(ret == 0);
		free($1);
		free($3);
	}
	| TOK_capitalreference '.' ComplexTypeReferenceAmpList {
		int ret;
		$$ = $3;
		ret = asn1p_ref_add_component($$, $1, RLT_CAPITALS);
		free($1);
		checkmem(ret == 0);
		/*
		 * Move the last element infront.
		 */
		{
			struct asn1p_ref_component_s tmp_comp;
			tmp_comp = $$->components[$$->comp_count-1];
			memmove(&$$->components[1],
				&$$->components[0],
				sizeof($$->components[0])
				* ($$->comp_count - 1));
			$$->components[0] = tmp_comp;
		}
	}
	;

ComplexTypeReferenceAmpList:
	ComplexTypeReferenceElement {
		int ret;
		$$ = asn1p_ref_new(yylineno, currentModule);
		checkmem($$);
		ret = asn1p_ref_add_component($$, $1.name, $1.lex_type);
		free($1.name);
		checkmem(ret == 0);
	}
	| ComplexTypeReferenceAmpList '.' ComplexTypeReferenceElement {
		int ret;
		$$ = $1;
		ret = asn1p_ref_add_component($$, $3.name, $3.lex_type);
		free($3.name);
		checkmem(ret == 0);
	}
	;

ComplexTypeReferenceElement:	PrimitiveFieldReference;

PrimitiveFieldReference:
	/* "&Type1" */
	TOK_typefieldreference {
		$$.lex_type = RLT_AmpUppercase;
		$$.name = $1;
	}
	/* "&id" */
	| TOK_valuefieldreference {
		$$.lex_type = RLT_Amplowercase;
		$$.name = $1;
	}
	;


FieldName:
	/* "&Type1" */
	TOK_typefieldreference {
		$$ = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component($$, $1, RLT_AmpUppercase);
		free($1);
	}
	| FieldName '.' TOK_typefieldreference {
		$$ = $$;
		asn1p_ref_add_component($$, $3, RLT_AmpUppercase);
		free($3);
	}
	| FieldName '.' TOK_valuefieldreference {
		$$ = $$;
		asn1p_ref_add_component($$, $3, RLT_Amplowercase);
		free($3);
	}
	;

DefinedObjectClass:
	TOK_capitalreference {
		$$ = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component($$, $1, RLT_CAPITALS);
		free($1);
	}
/*
	| TypeRefName '.' TOK_capitalreference {
		$$ = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component($$, $1, RLT_AmpUppercase);
		asn1p_ref_add_component($$, $3, RLT_CAPITALS);
		free($1);
		free($3);
	}
*/
	;


/*
 * === EXAMPLE ===
 * value INTEGER ::= 1
 * === EOF ===
 */
ValueAssignment:
	Identifier Type TOK_PPEQ Value {
		$$ = $2;
		assert($$->Identifier == NULL);
		$$->Identifier = $1;
		$$->meta_type = AMT_VALUE;
		$$->value = $4;
	}
	;

Value:
	SimpleValue
	| DefinedValue
	| '{' { asn1p_lexer_hack_push_opaque_state(); } Opaque {
		$$ = asn1p_value_frombuf($3.buf, $3.len, 0);
		checkmem($$);
		$$->type = ATV_UNPARSED;
	}
    ;

SimpleValue:
	TOK_NULL {
		$$ = asn1p_value_fromint(0);
		checkmem($$);
		$$->type = ATV_NULL;
	}
	| TOK_FALSE {
		$$ = asn1p_value_fromint(0);
		checkmem($$);
		$$->type = ATV_FALSE;
	}
	| TOK_TRUE {
		$$ = asn1p_value_fromint(1);
		checkmem($$);
		$$->type = ATV_TRUE;
	}
	| SignedNumber
	| RealValue
	| RestrictedCharacterStringValue
	| BitStringValue
	;

DefinedValue:
	IdentifierAsValue
	| TypeRefName '.' Identifier {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, $1, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(ref, $3, RLT_lowercase);
		checkmem(ret == 0);
		$$ = asn1p_value_fromref(ref, 0);
		checkmem($$);
		free($1);
		free($3);
	}
	;


RestrictedCharacterStringValue:
	TOK_cstring {
		$$ = asn1p_value_frombuf($1.buf, $1.len, 0);
		checkmem($$);
	}
	| TOK_tuple {
		$$ = asn1p_value_fromint($1);
		checkmem($$);
		$$->type = ATV_TUPLE;
	}
	| TOK_quadruple {
		$$ = asn1p_value_fromint($1);
		checkmem($$);
		$$->type = ATV_QUADRUPLE;
	}
	;

Opaque:
    OpaqueFirstToken {
		$$.len = $1.len + 1;
		$$.buf = malloc(1 + $$.len + 1);
		checkmem($$.buf);
		$$.buf[0] = '{';
		memcpy($$.buf + 1, $1.buf, $1.len);
		$$.buf[$$.len] = '\0';
		free($1.buf);
    }
	| Opaque TOK_opaque {
		int newsize = $1.len + $2.len;
		char *p = malloc(newsize + 1);
		checkmem(p);
		memcpy(p         , $1.buf, $1.len);
		memcpy(p + $1.len, $2.buf, $2.len);
		p[newsize] = '\0';
		free($1.buf);
		free($2.buf);
		$$.buf = p;
		$$.len = newsize;
	}
	;

OpaqueFirstToken:
    TOK_opaque
    | Identifier {
        $$.len = strlen($1);
        $$.buf = $1;
    };

BasicTypeId:
	TOK_BOOLEAN { $$ = ASN_BASIC_BOOLEAN; }
	| TOK_NULL { $$ = ASN_BASIC_NULL; }
	| TOK_REAL { $$ = ASN_BASIC_REAL; }
	| TOK_OCTET TOK_STRING { $$ = ASN_BASIC_OCTET_STRING; }
	| TOK_OBJECT TOK_IDENTIFIER { $$ = ASN_BASIC_OBJECT_IDENTIFIER; }
	| TOK_RELATIVE_OID { $$ = ASN_BASIC_RELATIVE_OID; }
	| TOK_EXTERNAL { $$ = ASN_BASIC_EXTERNAL; }
	| TOK_EMBEDDED TOK_PDV { $$ = ASN_BASIC_EMBEDDED_PDV; }
	| TOK_CHARACTER TOK_STRING { $$ = ASN_BASIC_CHARACTER_STRING; }
	| TOK_UTCTime { $$ = ASN_BASIC_UTCTime; }
	| TOK_GeneralizedTime { $$ = ASN_BASIC_GeneralizedTime; }
	| BasicString
	| BasicTypeId_UniverationCompatible
	;

/*
 * A type identifier which may be used with "{ a(1), b(2) }" clause.
 */
BasicTypeId_UniverationCompatible:
	TOK_INTEGER { $$ = ASN_BASIC_INTEGER; }
	| TOK_ENUMERATED { $$ = ASN_BASIC_ENUMERATED; }
	| TOK_BIT TOK_STRING { $$ = ASN_BASIC_BIT_STRING; }
	;

BuiltinType:
	BasicTypeId {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = $1;
		$$->meta_type = AMT_TYPE;
	}
    | TOK_INTEGER '{' NamedNumberList '}' {
        $$ = $3;
        $$->expr_type = ASN_BASIC_INTEGER;
        $$->meta_type = AMT_TYPE;
    }
    | TOK_ENUMERATED '{' Enumerations '}' {
        $$ = $3;
        $$->expr_type = ASN_BASIC_ENUMERATED;
        $$->meta_type = AMT_TYPE;
    }
    | TOK_BIT TOK_STRING '{' NamedBitList '}' {
        $$ = $4;
        $$->expr_type = ASN_BASIC_BIT_STRING;
        $$->meta_type = AMT_TYPE;
    }
    | TOK_ExtValue_BIT_STRING '{' IdentifierList '}' {
        $$ = $3;
        $$->expr_type = ASN_BASIC_BIT_STRING;
        $$->meta_type = AMT_TYPE;
    }
    | TOK_ExtValue_BIT_STRING '{' '}' {
		$$ = NEW_EXPR();
		checkmem($$);
        $$->expr_type = ASN_BASIC_BIT_STRING;
        $$->meta_type = AMT_TYPE;
    }
	;

BasicString:
	TOK_BMPString { $$ = ASN_STRING_BMPString; }
	| TOK_GeneralString {
		$$ = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
	| TOK_GraphicString {
		$$ = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
	| TOK_IA5String { $$ = ASN_STRING_IA5String; }
	| TOK_ISO646String { $$ = ASN_STRING_ISO646String; }
	| TOK_NumericString { $$ = ASN_STRING_NumericString; }
	| TOK_PrintableString { $$ = ASN_STRING_PrintableString; }
	| TOK_T61String {
		$$ = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
	| TOK_TeletexString { $$ = ASN_STRING_TeletexString; }
	| TOK_UniversalString { $$ = ASN_STRING_UniversalString; }
	| TOK_UTF8String { $$ = ASN_STRING_UTF8String; }
	| TOK_VideotexString {
		$$ = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
	| TOK_VisibleString { $$ = ASN_STRING_VisibleString; }
	| TOK_ObjectDescriptor { $$ = ASN_STRING_ObjectDescriptor; }
	;


/*
 * Data type constraints.
 */
UnionMark:		'|' | TOK_UNION;
IntersectionMark:	'^' | TOK_INTERSECTION;

/* empty | Constraint */
optConstraint:
	{ $$ = 0; }
	| Constraint;

/* empty | Constraint... */
optManyConstraints:
	{ $$ = 0; }
	| ManyConstraints;

/* empty | Constraint | SIZE(...) */
optSizeOrConstraint:
	{ $$ = 0; }
	| Constraint
	| SizeConstraint
	;

Constraint:
    '(' ConstraintSpec ')' {
		CONSTRAINT_INSERT($$, ACT_CA_SET, $2, 0);
    }
    ;

ManyConstraints:
    Constraint
	| ManyConstraints Constraint {
        if($2->type == ACT_CA_SET && $2->el_count == 1) {
            CONSTRAINT_INSERT($$, ACT_CA_SET, $1, $2->elements[0]);
        } else {
            CONSTRAINT_INSERT($$, ACT_CA_SET, $1, $2);
        }
	}
	;

ConstraintSpec: SubtypeConstraint | GeneralConstraint;

SubtypeConstraint: ElementSetSpecs;

ElementSetSpecs:
	TOK_ThreeDots  {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		$$->type = ACT_EL_EXT;
	}
   | ElementSetSpec
   | ElementSetSpec ',' TOK_ThreeDots {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT($$, ACT_CA_CSV, $1, ct);
   }
   | ElementSetSpec ',' TOK_ThreeDots ',' ElementSetSpec {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT($$, ACT_CA_CSV, $1, ct);
       ct = $$;
       CONSTRAINT_INSERT($$, ACT_CA_CSV, ct, $5);
   }
;

ElementSetSpec:
	Unions
	| TOK_ALL TOK_EXCEPT Elements {
		CONSTRAINT_INSERT($$, ACT_CA_AEX, $3, 0);
	}
	;

Unions:
	Intersections
	| Unions UnionMark Intersections {
		CONSTRAINT_INSERT($$, ACT_CA_UNI, $1, $3);
	}
	;

Intersections:
	IntersectionElements
	|  Intersections IntersectionMark IntersectionElements {
		CONSTRAINT_INSERT($$, ACT_CA_INT, $1, $3);
	}
	;


IntersectionElements:
	Elements
	| Elements TOK_EXCEPT Elements {
		CONSTRAINT_INSERT($$, ACT_CA_EXC, $1, $3);
	}
	;

Elements:
    SubtypeElements
    | '(' ElementSetSpec ')' {
        int ret;
        $$ = asn1p_constraint_new(yylineno, currentModule);
        checkmem($$);
        $$->type = ACT_CA_SET;
        ret = asn1p_constraint_insert($$, $2);
        checkmem(ret == 0);
    }
    ;

SubtypeElements:
	SingleValue {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		$$->type = ACT_EL_VALUE;
		$$->value = $1;
	}
	| ContainedSubtype {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		$$->type = ACT_EL_TYPE;
		$$->containedSubtype = $1;
	}
    | PermittedAlphabet /* FROM ... */
    | SizeConstraint    /* SIZE ... */
    /* | TypeConstraint is via ContainedSubtype */
	| InnerTypeConstraints  /* WITH COMPONENT[S] ... */
	| PatternConstraint     /* PATTERN ... */
	| ValueRange
	;


PermittedAlphabet:
	TOK_FROM Constraint {
		CONSTRAINT_INSERT($$, ACT_CT_FROM, $2, 0);
	};

SizeConstraint:
	TOK_SIZE Constraint {
		CONSTRAINT_INSERT($$, ACT_CT_SIZE, $2, 0);
	};

PatternConstraint:
	TOK_PATTERN TOK_cstring {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		$$->type = ACT_CT_PATTERN;
		$$->value = asn1p_value_frombuf($2.buf, $2.len, 0);
	}
	| TOK_PATTERN Identifier {
		asn1p_ref_t *ref;
		$$ = asn1p_constraint_new(yylineno, currentModule);
		$$->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, $2, RLT_lowercase);
		$$->value = asn1p_value_fromref(ref, 0);
		free($2);
	}
	;

ValueRange:
    LowerEndValue ConstraintRangeSpec UpperEndValue {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		$$->type = $2;
		$$->range_start = $1;
		$$->range_stop = $3;
    };

LowerEndValue:
    SingleValue
    | TOK_MIN {
		$$ = asn1p_value_fromint(-123);
		$$->type = ATV_MIN;
    };

UpperEndValue:
    SingleValue
    | TOK_MAX {
		$$ = asn1p_value_fromint(321);
		$$->type = ATV_MAX;
    };

SingleValue: Value;

BitStringValue:
	TOK_bstring {
		$$ = _convert_bitstring2binary($1, 'B');
		checkmem($$);
		free($1);
	}
	| TOK_hstring {
		$$ = _convert_bitstring2binary($1, 'H');
		checkmem($$);
		free($1);
	}
	;

ContainedSubtype:
    TOK_INCLUDES Type {
		$$ = asn1p_value_fromtype($2);
		checkmem($$);
		asn1p_expr_free($2);
    }
    /* Can't put Type here because of conflicts. Simplified subset */
    | DefinedUntaggedType {
		$$ = asn1p_value_fromtype($1);
		checkmem($$);
		asn1p_expr_free($1);
    }
	;

/*
 * X.680 08/2015
 * #51.8.5
 */
InnerTypeConstraints:
	TOK_WITH TOK_COMPONENT SingleTypeConstraint {
		CONSTRAINT_INSERT($$, ACT_CT_WCOMP, $3, 0);
	}
	| TOK_WITH TOK_COMPONENTS MultipleTypeConstraints {
        assert($3->type == ACT_CA_CSV);
        $3->type = ACT_CT_WCOMPS;
        $$ = $3;
	}
	;
SingleTypeConstraint: Constraint;
MultipleTypeConstraints: FullSpecification | PartialSpecification;
FullSpecification: '{' TypeConstraints '}' { $$ = $2; };
PartialSpecification:
    '{' TOK_ThreeDots ',' TypeConstraints '}' {
        assert($4->type == ACT_CA_CSV);
		$$ = asn1p_constraint_new(yylineno, currentModule);
        $$->type = ACT_CA_CSV;
		asn1p_constraint_t *ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		ct->type = ACT_EL_EXT;
        asn1p_constraint_insert($$, ct);
        for(unsigned i = 0; i < $4->el_count; i++) {
            asn1p_constraint_insert($$, $4->elements[i]);
        }
    };
TypeConstraints:
    NamedConstraint {
        $$ = asn1p_constraint_new(yylineno, currentModule);
        $$->type = ACT_CA_CSV;
        asn1p_constraint_insert($$, $1);
    }
    | TypeConstraints ',' NamedConstraint {
        $$ = $1;
        asn1p_constraint_insert($$, $3);
	}
	;
NamedConstraint:
	IdentifierAsValue optConstraint optPresenceConstraint {
        $$ = asn1p_constraint_new(yylineno, currentModule);
        checkmem($$);
        $$->type = ACT_EL_VALUE;
        $$->value = $1;
        if($2) asn1p_constraint_insert($$, $2);
        $$->presence = $3;
    }
    ;

/*
 * presence constraint for NamedConstraint
 */
optPresenceConstraint:
	{ $$ = ACPRES_DEFAULT; }
	| PresenceConstraint { $$ = $1; }
	;

PresenceConstraint:
	TOK_PRESENT {
		$$ = ACPRES_PRESENT;
	}
	| TOK_ABSENT {
		$$ = ACPRES_ABSENT;
	}
	| TOK_OPTIONAL {
		$$ = ACPRES_OPTIONAL;
	}
	;


/* X.682 */
GeneralConstraint:
	UserDefinedConstraint
	| TableConstraint
	| ContentsConstraint
	;

UserDefinedConstraint:
	TOK_CONSTRAINED TOK_BY '{'
		{ asn1p_lexer_hack_push_opaque_state(); } Opaque /* '}' */ {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		$$->type = ACT_CT_CTDBY;
		$$->value = asn1p_value_frombuf($5.buf, $5.len, 0);
		checkmem($$->value);
		$$->value->type = ATV_UNPARSED;
	}
	;

ContentsConstraint:
	TOK_CONTAINING Type {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		$$->type = ACT_CT_CTNG;
		$$->value = asn1p_value_fromtype($2);
		asn1p_expr_free($2);
	}
	;

ConstraintRangeSpec:
	TOK_TwoDots		{ $$ = ACT_EL_RANGE; }
	| TOK_TwoDots '<'	{ $$ = ACT_EL_RLRANGE; }
	| '<' TOK_TwoDots	{ $$ = ACT_EL_LLRANGE; }
	| '<' TOK_TwoDots '<'	{ $$ = ACT_EL_ULRANGE; }
	;
TableConstraint:
	SimpleTableConstraint {
		$$ = $1;
	}
	| ComponentRelationConstraint {
		$$ = $1;
	}
	;

/*
 * "{ExtensionSet}"
 */
SimpleTableConstraint:
	'{' TypeRefName '}' {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, $2, 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT($$, ACT_CA_CRC, ct, 0);
		free($2);
	}
	;

ComponentRelationConstraint:
	SimpleTableConstraint '{' AtNotationList '}' {
		CONSTRAINT_INSERT($$, ACT_CA_CRC, $1, $3);
	}
	;

AtNotationList:
	AtNotationElement {
		$$ = asn1p_constraint_new(yylineno, currentModule);
		checkmem($$);
		$$->type = ACT_EL_VALUE;
		$$->value = asn1p_value_fromref($1, 0);
	}
	| AtNotationList ',' AtNotationElement {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref($3, 0);
		CONSTRAINT_INSERT($$, ACT_CA_CSV, $1, ct);
	}
	;

/*
 * @blah
 */
AtNotationElement:
	'@' ComponentIdList {
		char *p = malloc(strlen($2) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, $2);
		$$ = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$, p, 0);
		checkmem(ret == 0);
		free(p);
		free($2);
	}
	| '@' '.' ComponentIdList {
		char *p = malloc(strlen($3) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, $3);
		$$ = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component($$, p, 0);
		checkmem(ret == 0);
		free(p);
		free($3);
	}
	;

/* identifier "." ... */
ComponentIdList:
	Identifier {
		$$ = $1;
	}
	| ComponentIdList '.' Identifier {
		int l1 = strlen($1);
		int l3 = strlen($3);
		$$ = malloc(l1 + 1 + l3 + 1);
		memcpy($$, $1, l1);
		$$[l1] = '.';
		memcpy($$ + l1 + 1, $3, l3);
		$$[l1 + 1 + l3] = '\0';
		free($1);
		free($3);
	}
	;



/*
 * MARKERS
 */

optMarker:
	{
		$$.flags = EM_NOMARK;
		$$.default_value = 0;
	}
	| Marker { $$ = $1; }
	;

Marker:
	TOK_OPTIONAL {
		$$.flags = EM_OPTIONAL | EM_INDIRECT;
		$$.default_value = 0;
	}
	| TOK_DEFAULT Value {
		$$.flags = EM_DEFAULT;
		$$.default_value = $2;
	}
	;

IdentifierList:
    IdentifierElement {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
    }
    | IdentifierList ',' IdentifierElement {
		$$ = $1;
		asn1p_expr_add($$, $3);
    };

IdentifierElement:
    Identifier {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
    }

NamedNumberList:
	NamedNumber {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| NamedNumberList ',' NamedNumber {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

NamedNumber:
	Identifier '(' SignedNumber ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = $3;
	}
	| Identifier '(' DefinedValue ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = $3;
	};

NamedBitList:
	NamedBit {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| NamedBitList ',' NamedBit {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

NamedBit:
	Identifier '(' TOK_number ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = asn1p_value_fromint($3);
	}
	| Identifier '(' DefinedValue ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = $3;
	};

Enumerations:
    UniverationList {
		$$ = $1;
        asn1p_expr_t *first_memb = TQ_FIRST(&($$->members));
        if(first_memb) {
            if(first_memb->expr_type == A1TC_EXTENSIBLE) {
                return yyerror(
                    "The ENUMERATION cannot start with extension (...).");
            }
        } else {
            return yyerror(
                "The ENUMERATION list cannot be empty.");
        }
    }

UniverationList:
	UniverationElement {
		$$ = NEW_EXPR();
		checkmem($$);
		asn1p_expr_add($$, $1);
	}
	| UniverationList ',' UniverationElement {
		$$ = $1;
		asn1p_expr_add($$, $3);
	}
	;

UniverationElement:
	Identifier {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
	}
	| Identifier '(' SignedNumber ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = $3;
	}
	| Identifier '(' DefinedValue ')' {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->Identifier = $1;
		$$->value = $3;
	}
	| SignedNumber {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->expr_type = A1TC_UNIVERVAL;
		$$->meta_type = AMT_VALUE;
		$$->value = $1;
	}
	| TOK_ThreeDots {
		$$ = NEW_EXPR();
		checkmem($$);
		$$->Identifier = strdup("...");
		checkmem($$->Identifier);
		$$->expr_type = A1TC_EXTENSIBLE;
		$$->meta_type = AMT_VALUE;
	}
	;

SignedNumber:
	TOK_number {
		$$ = asn1p_value_fromint($1);
		checkmem($$);
	}
	| TOK_number_negative {
		$$ = asn1p_value_fromint($1);
		checkmem($$);
	}
	;

RealValue:
	TOK_realnumber {
		$$ = asn1p_value_fromdouble($1);
		checkmem($$);
	}
	;

/*
 * SEQUENCE definition.
 * === EXAMPLE ===
 * Struct1 ::= SEQUENCE {
 * 	memb1 Struct2,
 * 	memb2 SEQUENCE OF {
 * 		memb2-1 Struct 3
 * 	}
 * }
 * === EOF ===
 */



/*
 * SET definition.
 * === EXAMPLE ===
 * Person ::= SET {
 * 	name [0] PrintableString (SIZE(1..20)),
 * 	country [1] PrintableString (SIZE(1..20)) DEFAULT default-country,
 * }
 * === EOF ===
 */

optTag:
	{ memset(&$$, 0, sizeof($$)); }
	| Tag { $$ = $1; }
	;

Tag:
	TagTypeValue TagPlicit {
		$$ = $1;
		$$.tag_mode = $2.tag_mode;
	}
	;

TagTypeValue:
	'[' TagClass TOK_number ']' {
		$$ = $2;
		$$.tag_value = $3;
	};

TagClass:
	{ $$.tag_class = TC_CONTEXT_SPECIFIC; }
	| TOK_UNIVERSAL { $$.tag_class = TC_UNIVERSAL; }
	| TOK_APPLICATION { $$.tag_class = TC_APPLICATION; }
	| TOK_PRIVATE { $$.tag_class = TC_PRIVATE; }
	;

TagPlicit:
	{ $$.tag_mode = TM_DEFAULT; }
	| TOK_IMPLICIT { $$.tag_mode = TM_IMPLICIT; }
	| TOK_EXPLICIT { $$.tag_mode = TM_EXPLICIT; }
	;

TypeRefName:
	TOK_typereference {
		checkmem($1);
		$$ = $1;
	}
	| TOK_capitalreference {
		checkmem($1);
		$$ = $1;
	}
	;


optIdentifier:
	{ $$ = 0; }
	| Identifier {
		$$ = $1;
	}
	;

Identifier:
	TOK_identifier {
		checkmem($1);
		$$ = $1;
	}
	;

IdentifierAsReference:
    Identifier {
		$$ = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component($$, $1, RLT_lowercase);
		free($1);
    };

IdentifierAsValue:
    IdentifierAsReference {
		$$ = asn1p_value_fromref($1, 0);
    };

%%


/*
 * Convert Xstring ('0101'B or '5'H) to the binary vector.
 */
static asn1p_value_t *
_convert_bitstring2binary(char *str, int base) {
	asn1p_value_t *val;
	int slen;
	int memlen;
	int baselen;
	int bits;
	uint8_t *binary_vector;
	uint8_t *bv_ptr;
	uint8_t cur_val;

	assert(str);
	assert(str[0] == '\'');

	switch(base) {
	case 'B':
		baselen = 1;
		break;
	case 'H':
		baselen = 4;
		break;
	default:
		assert(base == 'B' || base == 'H');
		errno = EINVAL;
		return NULL;
	}

	slen = strlen(str);
	assert(str[slen - 1] == base);
	assert(str[slen - 2] == '\'');

	memlen = slen / (8 / baselen);	/* Conservative estimate */

	bv_ptr = binary_vector = malloc(memlen + 1);
	if(bv_ptr == NULL)
		/* ENOMEM */
		return NULL;

	cur_val = 0;
	bits = 0;
	while(*(++str) != '\'') {
		switch(baselen) {
		case 1:
			switch(*str) {
			case '1':
				cur_val |= 1 << (7 - (bits % 8));
			case '0':
				break;
			default:
				assert(!"_y UNREACH1");
			case ' ': case '\r': case '\n':
				continue;
			}
			break;
		case 4:
			switch(*str) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				cur_val |= (*str - '0') << (4 - (bits % 8));
				break;
			case 'A': case 'B': case 'C':
			case 'D': case 'E': case 'F':
				cur_val |= ((*str - 'A') + 10)
					<< (4 - (bits % 8));
				break;
			default:
				assert(!"_y UNREACH2");
			case ' ': case '\r': case '\n':
				continue;
			}
			break;
		}

		bits += baselen;
		if((bits % 8) == 0) {
			*bv_ptr++ = cur_val;
			cur_val = 0;
		}
	}

	*bv_ptr = cur_val;
	assert((bv_ptr - binary_vector) <= memlen);

	val = asn1p_value_frombits(binary_vector, bits, 0);
	if(val == NULL) {
		free(binary_vector);
	}

	return val;
}

/*
 * For unnamed types (used in old X.208 compliant modules)
 * generate some sort of interim names, to not to force human being to fix
 * the specification's compliance to modern ASN.1 standards.
 */
static void
_fixup_anonymous_identifier(asn1p_expr_t *expr) {
	char *p;
	assert(expr->Identifier == 0);

	/*
	 * Try to figure out the type name
	 * without going too much into details
	 */
	expr->Identifier = ASN_EXPR_TYPE2STR(expr->expr_type);
	if(expr->reference && expr->reference->comp_count > 0)
		expr->Identifier = expr->reference->components[0].name;

	fprintf(stderr,
		"WARNING: Line %d: expected lower-case member identifier, "
		"found an unnamed %s.\n"
		"WARNING: Obsolete X.208 syntax detected, "
		"please give the member a name.\n",
		yylineno, expr->Identifier ? expr->Identifier : "type");

	if(!expr->Identifier)
		expr->Identifier = "unnamed";
	expr->Identifier = strdup(expr->Identifier);
	assert(expr->Identifier);
	/* Make a lowercase identifier from the type name */
	for(p = expr->Identifier; *p; p++) {
		switch(*p) {
		case 'A' ... 'Z': *p += 32; break;
		case ' ': *p = '_'; break;
		case '-': *p = '_'; break;
		}
	}
	fprintf(stderr, "NOTE: Assigning temporary identifier \"%s\". "
			"Name clash may occur later.\n",
		expr->Identifier);
}

static int
yyerror(const char *msg) {
	extern char *asn1p_text;
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near %s:%d (token \"%s\"): %s\n",
		ASN_FILENAME, yylineno, asn1p_text, msg);
	return -1;
}

