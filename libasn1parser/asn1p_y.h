typedef union {
	asn1p_t			*a_grammar;
	asn1p_module_flags_e	 a_module_flags;
	asn1p_module_t		*a_module;
	asn1p_expr_type_e	 a_type;	/* ASN.1 Type */
	asn1p_expr_t		*a_expr;	/* Constructed collection */
	asn1p_constraint_t	*a_constr;	/* Constraint */
	enum asn1p_constraint_type_e	a_ctype;/* Constraint type */
	asn1p_xports_t		*a_xports;	/* IMports/EXports */
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
	enum asn1p_expr_marker_e a_marker;	/* OPTIONAL/DEFAULT */
	enum asn1p_constr_pres_e a_pres;	/* PRESENT/ABSENT/OPTIONAL */
	asn1_integer_t		 a_int;
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
#define	TOK_number_negative	264
#define	TOK_typereference	265
#define	TOK_objectclassreference	266
#define	TOK_typefieldreference	267
#define	TOK_valuefieldreference	268
#define	TOK_ABSENT	269
#define	TOK_ABSTRACT_SYNTAX	270
#define	TOK_ALL	271
#define	TOK_ANY	272
#define	TOK_APPLICATION	273
#define	TOK_AUTOMATIC	274
#define	TOK_BEGIN	275
#define	TOK_BIT	276
#define	TOK_BMPString	277
#define	TOK_BOOLEAN	278
#define	TOK_BY	279
#define	TOK_CHARACTER	280
#define	TOK_CHOICE	281
#define	TOK_CLASS	282
#define	TOK_COMPONENT	283
#define	TOK_COMPONENTS	284
#define	TOK_CONSTRAINED	285
#define	TOK_CONTAINING	286
#define	TOK_DEFAULT	287
#define	TOK_DEFINITIONS	288
#define	TOK_DEFINED	289
#define	TOK_EMBEDDED	290
#define	TOK_ENCODED	291
#define	TOK_END	292
#define	TOK_ENUMERATED	293
#define	TOK_EXPLICIT	294
#define	TOK_EXPORTS	295
#define	TOK_EXTENSIBILITY	296
#define	TOK_EXTERNAL	297
#define	TOK_FALSE	298
#define	TOK_FROM	299
#define	TOK_GeneralizedTime	300
#define	TOK_GeneralString	301
#define	TOK_GraphicString	302
#define	TOK_IA5String	303
#define	TOK_IDENTIFIER	304
#define	TOK_IMPLICIT	305
#define	TOK_IMPLIED	306
#define	TOK_IMPORTS	307
#define	TOK_INCLUDES	308
#define	TOK_INSTANCE	309
#define	TOK_INTEGER	310
#define	TOK_ISO646String	311
#define	TOK_MAX	312
#define	TOK_MIN	313
#define	TOK_MINUS_INFINITY	314
#define	TOK_NULL	315
#define	TOK_NumericString	316
#define	TOK_OBJECT	317
#define	TOK_ObjectDescriptor	318
#define	TOK_OCTET	319
#define	TOK_OF	320
#define	TOK_OPTIONAL	321
#define	TOK_PATTERN	322
#define	TOK_PDV	323
#define	TOK_PLUS_INFINITY	324
#define	TOK_PRESENT	325
#define	TOK_PrintableString	326
#define	TOK_PRIVATE	327
#define	TOK_REAL	328
#define	TOK_RELATIVE_OID	329
#define	TOK_SEQUENCE	330
#define	TOK_SET	331
#define	TOK_SIZE	332
#define	TOK_STRING	333
#define	TOK_SYNTAX	334
#define	TOK_T61String	335
#define	TOK_TAGS	336
#define	TOK_TeletexString	337
#define	TOK_TRUE	338
#define	TOK_TYPE_IDENTIFIER	339
#define	TOK_UNIQUE	340
#define	TOK_UNIVERSAL	341
#define	TOK_UniversalString	342
#define	TOK_UTCTime	343
#define	TOK_UTF8String	344
#define	TOK_VideotexString	345
#define	TOK_VisibleString	346
#define	TOK_WITH	347
#define	TOK_UNION	348
#define	TOK_INTERSECTION	349
#define	TOK_EXCEPT	350
#define	TOK_TwoDots	351
#define	TOK_ThreeDots	352
#define	TOK_tag	353


extern YYSTYPE asn1p_lval;
