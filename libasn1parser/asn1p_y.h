typedef union {
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
	char	*tv_str;
	struct {
		char *buf;
		int len;
	}	tv_opaque;
	struct {
		char *name;
		struct asn1p_type_tag_s tag;
	} tv_nametag;
} YYSTYPE;
#define	TOK_PPEQ	257
#define	TOK_opaque	258
#define	TOK_bstring	259
#define	TOK_cstring	260
#define	TOK_hstring	261
#define	TOK_identifier	262
#define	TOK_number	263
#define	TOK_tuple	264
#define	TOK_quadruple	265
#define	TOK_number_negative	266
#define	TOK_typereference	267
#define	TOK_capitalreference	268
#define	TOK_typefieldreference	269
#define	TOK_valuefieldreference	270
#define	TOK_Literal	271
#define	TOK_ABSENT	272
#define	TOK_ABSTRACT_SYNTAX	273
#define	TOK_ALL	274
#define	TOK_ANY	275
#define	TOK_APPLICATION	276
#define	TOK_AUTOMATIC	277
#define	TOK_BEGIN	278
#define	TOK_BIT	279
#define	TOK_BMPString	280
#define	TOK_BOOLEAN	281
#define	TOK_BY	282
#define	TOK_CHARACTER	283
#define	TOK_CHOICE	284
#define	TOK_CLASS	285
#define	TOK_COMPONENT	286
#define	TOK_COMPONENTS	287
#define	TOK_CONSTRAINED	288
#define	TOK_CONTAINING	289
#define	TOK_DEFAULT	290
#define	TOK_DEFINITIONS	291
#define	TOK_DEFINED	292
#define	TOK_EMBEDDED	293
#define	TOK_ENCODED	294
#define	TOK_ENCODING_CONTROL	295
#define	TOK_END	296
#define	TOK_ENUMERATED	297
#define	TOK_EXPLICIT	298
#define	TOK_EXPORTS	299
#define	TOK_EXTENSIBILITY	300
#define	TOK_EXTERNAL	301
#define	TOK_FALSE	302
#define	TOK_FROM	303
#define	TOK_GeneralizedTime	304
#define	TOK_GeneralString	305
#define	TOK_GraphicString	306
#define	TOK_IA5String	307
#define	TOK_IDENTIFIER	308
#define	TOK_IMPLICIT	309
#define	TOK_IMPLIED	310
#define	TOK_IMPORTS	311
#define	TOK_INCLUDES	312
#define	TOK_INSTANCE	313
#define	TOK_INSTRUCTIONS	314
#define	TOK_INTEGER	315
#define	TOK_ISO646String	316
#define	TOK_MAX	317
#define	TOK_MIN	318
#define	TOK_MINUS_INFINITY	319
#define	TOK_NULL	320
#define	TOK_NumericString	321
#define	TOK_OBJECT	322
#define	TOK_ObjectDescriptor	323
#define	TOK_OCTET	324
#define	TOK_OF	325
#define	TOK_OPTIONAL	326
#define	TOK_PATTERN	327
#define	TOK_PDV	328
#define	TOK_PLUS_INFINITY	329
#define	TOK_PRESENT	330
#define	TOK_PrintableString	331
#define	TOK_PRIVATE	332
#define	TOK_REAL	333
#define	TOK_RELATIVE_OID	334
#define	TOK_SEQUENCE	335
#define	TOK_SET	336
#define	TOK_SIZE	337
#define	TOK_STRING	338
#define	TOK_SYNTAX	339
#define	TOK_T61String	340
#define	TOK_TAGS	341
#define	TOK_TeletexString	342
#define	TOK_TRUE	343
#define	TOK_TYPE_IDENTIFIER	344
#define	TOK_UNIQUE	345
#define	TOK_UNIVERSAL	346
#define	TOK_UniversalString	347
#define	TOK_UTCTime	348
#define	TOK_UTF8String	349
#define	TOK_VideotexString	350
#define	TOK_VisibleString	351
#define	TOK_WITH	352
#define	TOK_EXCEPT	353
#define	TOK_INTERSECTION	354
#define	TOK_UNION	355
#define	TOK_TwoDots	356
#define	TOK_ThreeDots	357


extern YYSTYPE asn1p_lval;
