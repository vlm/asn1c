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
     TOK_whitespace = 259,
     TOK_opaque = 260,
     TOK_bstring = 261,
     TOK_cstring = 262,
     TOK_hstring = 263,
     TOK_identifier = 264,
     TOK_number = 265,
     TOK_tuple = 266,
     TOK_quadruple = 267,
     TOK_number_negative = 268,
     TOK_typereference = 269,
     TOK_capitalreference = 270,
     TOK_typefieldreference = 271,
     TOK_valuefieldreference = 272,
     TOK_Literal = 273,
     TOK_ABSENT = 274,
     TOK_ABSTRACT_SYNTAX = 275,
     TOK_ALL = 276,
     TOK_ANY = 277,
     TOK_APPLICATION = 278,
     TOK_AUTOMATIC = 279,
     TOK_BEGIN = 280,
     TOK_BIT = 281,
     TOK_BMPString = 282,
     TOK_BOOLEAN = 283,
     TOK_BY = 284,
     TOK_CHARACTER = 285,
     TOK_CHOICE = 286,
     TOK_CLASS = 287,
     TOK_COMPONENT = 288,
     TOK_COMPONENTS = 289,
     TOK_CONSTRAINED = 290,
     TOK_CONTAINING = 291,
     TOK_DEFAULT = 292,
     TOK_DEFINITIONS = 293,
     TOK_DEFINED = 294,
     TOK_EMBEDDED = 295,
     TOK_ENCODED = 296,
     TOK_ENCODING_CONTROL = 297,
     TOK_END = 298,
     TOK_ENUMERATED = 299,
     TOK_EXPLICIT = 300,
     TOK_EXPORTS = 301,
     TOK_EXTENSIBILITY = 302,
     TOK_EXTERNAL = 303,
     TOK_FALSE = 304,
     TOK_FROM = 305,
     TOK_GeneralizedTime = 306,
     TOK_GeneralString = 307,
     TOK_GraphicString = 308,
     TOK_IA5String = 309,
     TOK_IDENTIFIER = 310,
     TOK_IMPLICIT = 311,
     TOK_IMPLIED = 312,
     TOK_IMPORTS = 313,
     TOK_INCLUDES = 314,
     TOK_INSTANCE = 315,
     TOK_INSTRUCTIONS = 316,
     TOK_INTEGER = 317,
     TOK_ISO646String = 318,
     TOK_MAX = 319,
     TOK_MIN = 320,
     TOK_MINUS_INFINITY = 321,
     TOK_NULL = 322,
     TOK_NumericString = 323,
     TOK_OBJECT = 324,
     TOK_ObjectDescriptor = 325,
     TOK_OCTET = 326,
     TOK_OF = 327,
     TOK_OPTIONAL = 328,
     TOK_PATTERN = 329,
     TOK_PDV = 330,
     TOK_PLUS_INFINITY = 331,
     TOK_PRESENT = 332,
     TOK_PrintableString = 333,
     TOK_PRIVATE = 334,
     TOK_REAL = 335,
     TOK_RELATIVE_OID = 336,
     TOK_SEQUENCE = 337,
     TOK_SET = 338,
     TOK_SIZE = 339,
     TOK_STRING = 340,
     TOK_SYNTAX = 341,
     TOK_T61String = 342,
     TOK_TAGS = 343,
     TOK_TeletexString = 344,
     TOK_TRUE = 345,
     TOK_TYPE_IDENTIFIER = 346,
     TOK_UNIQUE = 347,
     TOK_UNIVERSAL = 348,
     TOK_UniversalString = 349,
     TOK_UTCTime = 350,
     TOK_UTF8String = 351,
     TOK_VideotexString = 352,
     TOK_VisibleString = 353,
     TOK_WITH = 354,
     TOK_EXCEPT = 355,
     TOK_INTERSECTION = 356,
     TOK_UNION = 357,
     TOK_TwoDots = 358,
     TOK_ThreeDots = 359
   };
#endif
#define TOK_PPEQ 258
#define TOK_whitespace 259
#define TOK_opaque 260
#define TOK_bstring 261
#define TOK_cstring 262
#define TOK_hstring 263
#define TOK_identifier 264
#define TOK_number 265
#define TOK_tuple 266
#define TOK_quadruple 267
#define TOK_number_negative 268
#define TOK_typereference 269
#define TOK_capitalreference 270
#define TOK_typefieldreference 271
#define TOK_valuefieldreference 272
#define TOK_Literal 273
#define TOK_ABSENT 274
#define TOK_ABSTRACT_SYNTAX 275
#define TOK_ALL 276
#define TOK_ANY 277
#define TOK_APPLICATION 278
#define TOK_AUTOMATIC 279
#define TOK_BEGIN 280
#define TOK_BIT 281
#define TOK_BMPString 282
#define TOK_BOOLEAN 283
#define TOK_BY 284
#define TOK_CHARACTER 285
#define TOK_CHOICE 286
#define TOK_CLASS 287
#define TOK_COMPONENT 288
#define TOK_COMPONENTS 289
#define TOK_CONSTRAINED 290
#define TOK_CONTAINING 291
#define TOK_DEFAULT 292
#define TOK_DEFINITIONS 293
#define TOK_DEFINED 294
#define TOK_EMBEDDED 295
#define TOK_ENCODED 296
#define TOK_ENCODING_CONTROL 297
#define TOK_END 298
#define TOK_ENUMERATED 299
#define TOK_EXPLICIT 300
#define TOK_EXPORTS 301
#define TOK_EXTENSIBILITY 302
#define TOK_EXTERNAL 303
#define TOK_FALSE 304
#define TOK_FROM 305
#define TOK_GeneralizedTime 306
#define TOK_GeneralString 307
#define TOK_GraphicString 308
#define TOK_IA5String 309
#define TOK_IDENTIFIER 310
#define TOK_IMPLICIT 311
#define TOK_IMPLIED 312
#define TOK_IMPORTS 313
#define TOK_INCLUDES 314
#define TOK_INSTANCE 315
#define TOK_INSTRUCTIONS 316
#define TOK_INTEGER 317
#define TOK_ISO646String 318
#define TOK_MAX 319
#define TOK_MIN 320
#define TOK_MINUS_INFINITY 321
#define TOK_NULL 322
#define TOK_NumericString 323
#define TOK_OBJECT 324
#define TOK_ObjectDescriptor 325
#define TOK_OCTET 326
#define TOK_OF 327
#define TOK_OPTIONAL 328
#define TOK_PATTERN 329
#define TOK_PDV 330
#define TOK_PLUS_INFINITY 331
#define TOK_PRESENT 332
#define TOK_PrintableString 333
#define TOK_PRIVATE 334
#define TOK_REAL 335
#define TOK_RELATIVE_OID 336
#define TOK_SEQUENCE 337
#define TOK_SET 338
#define TOK_SIZE 339
#define TOK_STRING 340
#define TOK_SYNTAX 341
#define TOK_T61String 342
#define TOK_TAGS 343
#define TOK_TeletexString 344
#define TOK_TRUE 345
#define TOK_TYPE_IDENTIFIER 346
#define TOK_UNIQUE 347
#define TOK_UNIVERSAL 348
#define TOK_UniversalString 349
#define TOK_UTCTime 350
#define TOK_UTF8String 351
#define TOK_VideotexString 352
#define TOK_VisibleString 353
#define TOK_WITH 354
#define TOK_EXCEPT 355
#define TOK_INTERSECTION 356
#define TOK_UNION 357
#define TOK_TwoDots 358
#define TOK_ThreeDots 359




#ifndef YYSTYPE
#line 72 "asn1p_y.y"
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
} yystype;
/* Line 1281 of /usr/local/share/bison/yacc.c.  */
#line 282 "y.tab.h"
# define YYSTYPE yystype
#endif

extern YYSTYPE asn1p_lval;


#endif /* not BISON_ASN_P_Y_H */

