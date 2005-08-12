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
#define	TOK_ABSENT	271
#define	TOK_ABSTRACT_SYNTAX	272
#define	TOK_ALL	273
#define	TOK_ANY	274
#define	TOK_APPLICATION	275
#define	TOK_AUTOMATIC	276
#define	TOK_BEGIN	277
#define	TOK_BIT	278
#define	TOK_BMPString	279
#define	TOK_BOOLEAN	280
#define	TOK_BY	281
#define	TOK_CHARACTER	282
#define	TOK_CHOICE	283
#define	TOK_CLASS	284
#define	TOK_COMPONENT	285
#define	TOK_COMPONENTS	286
#define	TOK_CONSTRAINED	287
#define	TOK_CONTAINING	288
#define	TOK_DEFAULT	289
#define	TOK_DEFINITIONS	290
#define	TOK_DEFINED	291
#define	TOK_EMBEDDED	292
#define	TOK_ENCODED	293
#define	TOK_ENCODING_CONTROL	294
#define	TOK_END	295
#define	TOK_ENUMERATED	296
#define	TOK_EXPLICIT	297
#define	TOK_EXPORTS	298
#define	TOK_EXTENSIBILITY	299
#define	TOK_EXTERNAL	300
#define	TOK_FALSE	301
#define	TOK_FROM	302
#define	TOK_GeneralizedTime	303
#define	TOK_GeneralString	304
#define	TOK_GraphicString	305
#define	TOK_IA5String	306
#define	TOK_IDENTIFIER	307
#define	TOK_IMPLICIT	308
#define	TOK_IMPLIED	309
#define	TOK_IMPORTS	310
#define	TOK_INCLUDES	311
#define	TOK_INSTANCE	312
#define	TOK_INSTRUCTIONS	313
#define	TOK_INTEGER	314
#define	TOK_ISO646String	315
#define	TOK_MAX	316
#define	TOK_MIN	317
#define	TOK_MINUS_INFINITY	318
#define	TOK_NULL	319
#define	TOK_NumericString	320
#define	TOK_OBJECT	321
#define	TOK_ObjectDescriptor	322
#define	TOK_OCTET	323
#define	TOK_OF	324
#define	TOK_OPTIONAL	325
#define	TOK_PATTERN	326
#define	TOK_PDV	327
#define	TOK_PLUS_INFINITY	328
#define	TOK_PRESENT	329
#define	TOK_PrintableString	330
#define	TOK_PRIVATE	331
#define	TOK_REAL	332
#define	TOK_RELATIVE_OID	333
#define	TOK_SEQUENCE	334
#define	TOK_SET	335
#define	TOK_SIZE	336
#define	TOK_STRING	337
#define	TOK_SYNTAX	338
#define	TOK_T61String	339
#define	TOK_TAGS	340
#define	TOK_TeletexString	341
#define	TOK_TRUE	342
#define	TOK_TYPE_IDENTIFIER	343
#define	TOK_UNIQUE	344
#define	TOK_UNIVERSAL	345
#define	TOK_UniversalString	346
#define	TOK_UTCTime	347
#define	TOK_UTF8String	348
#define	TOK_VideotexString	349
#define	TOK_VisibleString	350
#define	TOK_WITH	351
#define	TOK_EXCEPT	352
#define	TOK_INTERSECTION	353
#define	TOK_UNION	354
#define	TOK_TwoDots	355
#define	TOK_ThreeDots	356


extern YYSTYPE asn1p_lval;
