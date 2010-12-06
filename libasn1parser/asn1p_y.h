/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

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
     TOK_number_negative = 266,
     TOK_realnumber = 267,
     TOK_tuple = 268,
     TOK_quadruple = 269,
     TOK_typereference = 270,
     TOK_capitalreference = 271,
     TOK_typefieldreference = 272,
     TOK_valuefieldreference = 273,
     TOK_Literal = 274,
     TOK_arcnumber = 275,
     TOK_ABSENT = 276,
     TOK_ABSTRACT_SYNTAX = 277,
     TOK_ALL = 278,
     TOK_ANY = 279,
     TOK_APPLICATION = 280,
     TOK_AUTOMATIC = 281,
     TOK_BEGIN = 282,
     TOK_BIT = 283,
     TOK_BMPString = 284,
     TOK_BOOLEAN = 285,
     TOK_BY = 286,
     TOK_CHARACTER = 287,
     TOK_CHOICE = 288,
     TOK_CLASS = 289,
     TOK_COMPONENT = 290,
     TOK_COMPONENTS = 291,
     TOK_CONSTRAINED = 292,
     TOK_CONTAINING = 293,
     TOK_DEFAULT = 294,
     TOK_DEFINITIONS = 295,
     TOK_DEFINED = 296,
     TOK_EMBEDDED = 297,
     TOK_ENCODED = 298,
     TOK_ENCODING_CONTROL = 299,
     TOK_END = 300,
     TOK_ENUMERATED = 301,
     TOK_EXPLICIT = 302,
     TOK_EXPORTS = 303,
     TOK_EXTENSIBILITY = 304,
     TOK_EXTERNAL = 305,
     TOK_FALSE = 306,
     TOK_FROM = 307,
     TOK_GeneralizedTime = 308,
     TOK_GeneralString = 309,
     TOK_GraphicString = 310,
     TOK_IA5String = 311,
     TOK_IDENTIFIER = 312,
     TOK_IMPLICIT = 313,
     TOK_IMPLIED = 314,
     TOK_IMPORTS = 315,
     TOK_INCLUDES = 316,
     TOK_INSTANCE = 317,
     TOK_INSTRUCTIONS = 318,
     TOK_INTEGER = 319,
     TOK_ISO646String = 320,
     TOK_MAX = 321,
     TOK_MIN = 322,
     TOK_MINUS_INFINITY = 323,
     TOK_NULL = 324,
     TOK_NumericString = 325,
     TOK_OBJECT = 326,
     TOK_ObjectDescriptor = 327,
     TOK_OCTET = 328,
     TOK_OF = 329,
     TOK_OPTIONAL = 330,
     TOK_PATTERN = 331,
     TOK_PDV = 332,
     TOK_PLUS_INFINITY = 333,
     TOK_PRESENT = 334,
     TOK_PrintableString = 335,
     TOK_PRIVATE = 336,
     TOK_REAL = 337,
     TOK_RELATIVE_OID = 338,
     TOK_SEQUENCE = 339,
     TOK_SET = 340,
     TOK_SIZE = 341,
     TOK_STRING = 342,
     TOK_SYNTAX = 343,
     TOK_T61String = 344,
     TOK_TAGS = 345,
     TOK_TeletexString = 346,
     TOK_TRUE = 347,
     TOK_TYPE_IDENTIFIER = 348,
     TOK_UNIQUE = 349,
     TOK_UNIVERSAL = 350,
     TOK_UniversalString = 351,
     TOK_UTCTime = 352,
     TOK_UTF8String = 353,
     TOK_VideotexString = 354,
     TOK_VisibleString = 355,
     TOK_WITH = 356,
     TOK_EXCEPT = 357,
     TOK_INTERSECTION = 358,
     TOK_UNION = 359,
     TOK_TwoDots = 360,
     TOK_ThreeDots = 361
   };
#endif
/* Tokens.  */
#define TOK_PPEQ 258
#define TOK_whitespace 259
#define TOK_opaque 260
#define TOK_bstring 261
#define TOK_cstring 262
#define TOK_hstring 263
#define TOK_identifier 264
#define TOK_number 265
#define TOK_number_negative 266
#define TOK_realnumber 267
#define TOK_tuple 268
#define TOK_quadruple 269
#define TOK_typereference 270
#define TOK_capitalreference 271
#define TOK_typefieldreference 272
#define TOK_valuefieldreference 273
#define TOK_Literal 274
#define TOK_arcnumber 275
#define TOK_ABSENT 276
#define TOK_ABSTRACT_SYNTAX 277
#define TOK_ALL 278
#define TOK_ANY 279
#define TOK_APPLICATION 280
#define TOK_AUTOMATIC 281
#define TOK_BEGIN 282
#define TOK_BIT 283
#define TOK_BMPString 284
#define TOK_BOOLEAN 285
#define TOK_BY 286
#define TOK_CHARACTER 287
#define TOK_CHOICE 288
#define TOK_CLASS 289
#define TOK_COMPONENT 290
#define TOK_COMPONENTS 291
#define TOK_CONSTRAINED 292
#define TOK_CONTAINING 293
#define TOK_DEFAULT 294
#define TOK_DEFINITIONS 295
#define TOK_DEFINED 296
#define TOK_EMBEDDED 297
#define TOK_ENCODED 298
#define TOK_ENCODING_CONTROL 299
#define TOK_END 300
#define TOK_ENUMERATED 301
#define TOK_EXPLICIT 302
#define TOK_EXPORTS 303
#define TOK_EXTENSIBILITY 304
#define TOK_EXTERNAL 305
#define TOK_FALSE 306
#define TOK_FROM 307
#define TOK_GeneralizedTime 308
#define TOK_GeneralString 309
#define TOK_GraphicString 310
#define TOK_IA5String 311
#define TOK_IDENTIFIER 312
#define TOK_IMPLICIT 313
#define TOK_IMPLIED 314
#define TOK_IMPORTS 315
#define TOK_INCLUDES 316
#define TOK_INSTANCE 317
#define TOK_INSTRUCTIONS 318
#define TOK_INTEGER 319
#define TOK_ISO646String 320
#define TOK_MAX 321
#define TOK_MIN 322
#define TOK_MINUS_INFINITY 323
#define TOK_NULL 324
#define TOK_NumericString 325
#define TOK_OBJECT 326
#define TOK_ObjectDescriptor 327
#define TOK_OCTET 328
#define TOK_OF 329
#define TOK_OPTIONAL 330
#define TOK_PATTERN 331
#define TOK_PDV 332
#define TOK_PLUS_INFINITY 333
#define TOK_PRESENT 334
#define TOK_PrintableString 335
#define TOK_PRIVATE 336
#define TOK_REAL 337
#define TOK_RELATIVE_OID 338
#define TOK_SEQUENCE 339
#define TOK_SET 340
#define TOK_SIZE 341
#define TOK_STRING 342
#define TOK_SYNTAX 343
#define TOK_T61String 344
#define TOK_TAGS 345
#define TOK_TeletexString 346
#define TOK_TRUE 347
#define TOK_TYPE_IDENTIFIER 348
#define TOK_UNIQUE 349
#define TOK_UNIVERSAL 350
#define TOK_UniversalString 351
#define TOK_UTCTime 352
#define TOK_UTF8String 353
#define TOK_VideotexString 354
#define TOK_VisibleString 355
#define TOK_WITH 356
#define TOK_EXCEPT 357
#define TOK_INTERSECTION 358
#define TOK_UNION 359
#define TOK_TwoDots 360
#define TOK_ThreeDots 361




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 88 "asn1p_y.y"
{
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
}
/* Line 1529 of yacc.c.  */
#line 296 "asn1p_y.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE asn1p_lval;

