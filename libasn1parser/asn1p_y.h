/* A Bison parser, made from asn1p_y.y, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef BISON_ASN_P_Y_H
# define BISON_ASN_P_Y_H

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_PPEQ = 258,
     TOK_opaque = 259,
     TOK_bstring = 260,
     TOK_cstring = 261,
     TOK_hstring = 262,
     TOK_identifier = 263,
     TOK_number = 264,
     TOK_number_negative = 265,
     TOK_typereference = 266,
     TOK_objectclassreference = 267,
     TOK_typefieldreference = 268,
     TOK_valuefieldreference = 269,
     TOK_ABSENT = 270,
     TOK_ABSTRACT_SYNTAX = 271,
     TOK_ALL = 272,
     TOK_ANY = 273,
     TOK_APPLICATION = 274,
     TOK_AUTOMATIC = 275,
     TOK_BEGIN = 276,
     TOK_BIT = 277,
     TOK_BMPString = 278,
     TOK_BOOLEAN = 279,
     TOK_BY = 280,
     TOK_CHARACTER = 281,
     TOK_CHOICE = 282,
     TOK_CLASS = 283,
     TOK_COMPONENT = 284,
     TOK_COMPONENTS = 285,
     TOK_CONSTRAINED = 286,
     TOK_CONTAINING = 287,
     TOK_DEFAULT = 288,
     TOK_DEFINITIONS = 289,
     TOK_DEFINED = 290,
     TOK_EMBEDDED = 291,
     TOK_ENCODED = 292,
     TOK_END = 293,
     TOK_ENUMERATED = 294,
     TOK_EXPLICIT = 295,
     TOK_EXPORTS = 296,
     TOK_EXTENSIBILITY = 297,
     TOK_EXTERNAL = 298,
     TOK_FALSE = 299,
     TOK_FROM = 300,
     TOK_GeneralizedTime = 301,
     TOK_GeneralString = 302,
     TOK_GraphicString = 303,
     TOK_IA5String = 304,
     TOK_IDENTIFIER = 305,
     TOK_IMPLICIT = 306,
     TOK_IMPLIED = 307,
     TOK_IMPORTS = 308,
     TOK_INCLUDES = 309,
     TOK_INSTANCE = 310,
     TOK_INTEGER = 311,
     TOK_ISO646String = 312,
     TOK_MAX = 313,
     TOK_MIN = 314,
     TOK_MINUS_INFINITY = 315,
     TOK_NULL = 316,
     TOK_NumericString = 317,
     TOK_OBJECT = 318,
     TOK_ObjectDescriptor = 319,
     TOK_OCTET = 320,
     TOK_OF = 321,
     TOK_OPTIONAL = 322,
     TOK_PATTERN = 323,
     TOK_PDV = 324,
     TOK_PLUS_INFINITY = 325,
     TOK_PRESENT = 326,
     TOK_PrintableString = 327,
     TOK_PRIVATE = 328,
     TOK_REAL = 329,
     TOK_RELATIVE_OID = 330,
     TOK_SEQUENCE = 331,
     TOK_SET = 332,
     TOK_SIZE = 333,
     TOK_STRING = 334,
     TOK_SYNTAX = 335,
     TOK_T61String = 336,
     TOK_TAGS = 337,
     TOK_TeletexString = 338,
     TOK_TRUE = 339,
     TOK_TYPE_IDENTIFIER = 340,
     TOK_UNIQUE = 341,
     TOK_UNIVERSAL = 342,
     TOK_UniversalString = 343,
     TOK_UTCTime = 344,
     TOK_UTF8String = 345,
     TOK_VideotexString = 346,
     TOK_VisibleString = 347,
     TOK_WITH = 348,
     TOK_UNION = 349,
     TOK_INTERSECTION = 350,
     TOK_EXCEPT = 351,
     TOK_TwoDots = 352,
     TOK_ThreeDots = 353,
     TOK_tag = 354
   };
#endif
#define TOK_PPEQ 258
#define TOK_opaque 259
#define TOK_bstring 260
#define TOK_cstring 261
#define TOK_hstring 262
#define TOK_identifier 263
#define TOK_number 264
#define TOK_number_negative 265
#define TOK_typereference 266
#define TOK_objectclassreference 267
#define TOK_typefieldreference 268
#define TOK_valuefieldreference 269
#define TOK_ABSENT 270
#define TOK_ABSTRACT_SYNTAX 271
#define TOK_ALL 272
#define TOK_ANY 273
#define TOK_APPLICATION 274
#define TOK_AUTOMATIC 275
#define TOK_BEGIN 276
#define TOK_BIT 277
#define TOK_BMPString 278
#define TOK_BOOLEAN 279
#define TOK_BY 280
#define TOK_CHARACTER 281
#define TOK_CHOICE 282
#define TOK_CLASS 283
#define TOK_COMPONENT 284
#define TOK_COMPONENTS 285
#define TOK_CONSTRAINED 286
#define TOK_CONTAINING 287
#define TOK_DEFAULT 288
#define TOK_DEFINITIONS 289
#define TOK_DEFINED 290
#define TOK_EMBEDDED 291
#define TOK_ENCODED 292
#define TOK_END 293
#define TOK_ENUMERATED 294
#define TOK_EXPLICIT 295
#define TOK_EXPORTS 296
#define TOK_EXTENSIBILITY 297
#define TOK_EXTERNAL 298
#define TOK_FALSE 299
#define TOK_FROM 300
#define TOK_GeneralizedTime 301
#define TOK_GeneralString 302
#define TOK_GraphicString 303
#define TOK_IA5String 304
#define TOK_IDENTIFIER 305
#define TOK_IMPLICIT 306
#define TOK_IMPLIED 307
#define TOK_IMPORTS 308
#define TOK_INCLUDES 309
#define TOK_INSTANCE 310
#define TOK_INTEGER 311
#define TOK_ISO646String 312
#define TOK_MAX 313
#define TOK_MIN 314
#define TOK_MINUS_INFINITY 315
#define TOK_NULL 316
#define TOK_NumericString 317
#define TOK_OBJECT 318
#define TOK_ObjectDescriptor 319
#define TOK_OCTET 320
#define TOK_OF 321
#define TOK_OPTIONAL 322
#define TOK_PATTERN 323
#define TOK_PDV 324
#define TOK_PLUS_INFINITY 325
#define TOK_PRESENT 326
#define TOK_PrintableString 327
#define TOK_PRIVATE 328
#define TOK_REAL 329
#define TOK_RELATIVE_OID 330
#define TOK_SEQUENCE 331
#define TOK_SET 332
#define TOK_SIZE 333
#define TOK_STRING 334
#define TOK_SYNTAX 335
#define TOK_T61String 336
#define TOK_TAGS 337
#define TOK_TeletexString 338
#define TOK_TRUE 339
#define TOK_TYPE_IDENTIFIER 340
#define TOK_UNIQUE 341
#define TOK_UNIVERSAL 342
#define TOK_UniversalString 343
#define TOK_UTCTime 344
#define TOK_UTF8String 345
#define TOK_VideotexString 346
#define TOK_VisibleString 347
#define TOK_WITH 348
#define TOK_UNION 349
#define TOK_INTERSECTION 350
#define TOK_EXCEPT 351
#define TOK_TwoDots 352
#define TOK_ThreeDots 353
#define TOK_tag 354




#ifndef YYSTYPE
#line 57 "asn1p_y.y"
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
} yystype;
/* Line 1281 of /usr/local/share/bison/yacc.c.  */
#line 271 "y.tab.h"
# define YYSTYPE yystype
#endif

extern YYSTYPE asn1p_lval;


#endif /* not BISON_ASN_P_Y_H */

