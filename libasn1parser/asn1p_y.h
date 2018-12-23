/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_ASN1P_ASN_P_Y_H_INCLUDED
# define YY_ASN1P_ASN_P_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int asn1p_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_PPEQ = 258,
    TOK_VBracketLeft = 259,
    TOK_VBracketRight = 260,
    TOK_whitespace = 261,
    TOK_opaque = 262,
    TOK_bstring = 263,
    TOK_cstring = 264,
    TOK_hstring = 265,
    TOK_identifier = 266,
    TOK_number = 267,
    TOK_number_negative = 268,
    TOK_realnumber = 269,
    TOK_tuple = 270,
    TOK_quadruple = 271,
    TOK_typereference = 272,
    TOK_capitalreference = 273,
    TOK_typefieldreference = 274,
    TOK_valuefieldreference = 275,
    TOK_Literal = 276,
    TOK_ExtValue_BIT_STRING = 277,
    TOK_ABSENT = 278,
    TOK_ABSTRACT_SYNTAX = 279,
    TOK_ALL = 280,
    TOK_ANY = 281,
    TOK_APPLICATION = 282,
    TOK_AUTOMATIC = 283,
    TOK_BEGIN = 284,
    TOK_BIT = 285,
    TOK_BMPString = 286,
    TOK_BOOLEAN = 287,
    TOK_BY = 288,
    TOK_CHARACTER = 289,
    TOK_CHOICE = 290,
    TOK_CLASS = 291,
    TOK_COMPONENT = 292,
    TOK_COMPONENTS = 293,
    TOK_CONSTRAINED = 294,
    TOK_CONTAINING = 295,
    TOK_DEFAULT = 296,
    TOK_DEFINITIONS = 297,
    TOK_DEFINED = 298,
    TOK_EMBEDDED = 299,
    TOK_ENCODED = 300,
    TOK_ENCODING_CONTROL = 301,
    TOK_END = 302,
    TOK_ENUMERATED = 303,
    TOK_EXPLICIT = 304,
    TOK_EXPORTS = 305,
    TOK_EXTENSIBILITY = 306,
    TOK_FALSE = 307,
    TOK_FROM = 308,
    TOK_GeneralizedTime = 309,
    TOK_GeneralString = 310,
    TOK_GraphicString = 311,
    TOK_IA5String = 312,
    TOK_IDENTIFIER = 313,
    TOK_IMPLICIT = 314,
    TOK_IMPLIED = 315,
    TOK_IMPORTS = 316,
    TOK_INCLUDES = 317,
    TOK_INSTANCE = 318,
    TOK_INSTRUCTIONS = 319,
    TOK_INTEGER = 320,
    TOK_ISO646String = 321,
    TOK_MAX = 322,
    TOK_MIN = 323,
    TOK_MINUS_INFINITY = 324,
    TOK_NULL = 325,
    TOK_NumericString = 326,
    TOK_OBJECT = 327,
    TOK_ObjectDescriptor = 328,
    TOK_OCTET = 329,
    TOK_OF = 330,
    TOK_OPTIONAL = 331,
    TOK_PATTERN = 332,
    TOK_PDV = 333,
    TOK_PLUS_INFINITY = 334,
    TOK_PRESENT = 335,
    TOK_PrintableString = 336,
    TOK_PRIVATE = 337,
    TOK_REAL = 338,
    TOK_RELATIVE_OID = 339,
    TOK_SEQUENCE = 340,
    TOK_SET = 341,
    TOK_SIZE = 342,
    TOK_STRING = 343,
    TOK_SYNTAX = 344,
    TOK_T61String = 345,
    TOK_TAGS = 346,
    TOK_TeletexString = 347,
    TOK_TRUE = 348,
    TOK_TYPE_IDENTIFIER = 349,
    TOK_UNIQUE = 350,
    TOK_UNIVERSAL = 351,
    TOK_UniversalString = 352,
    TOK_UTCTime = 353,
    TOK_UTF8String = 354,
    TOK_VideotexString = 355,
    TOK_VisibleString = 356,
    TOK_WITH = 357,
    UTF8_BOM = 358,
    TOK_EXCEPT = 359,
    TOK_INTERSECTION = 360,
    TOK_UNION = 361,
    TOK_TwoDots = 362,
    TOK_ThreeDots = 363
  };
#endif
/* Tokens.  */
#define TOK_PPEQ 258
#define TOK_VBracketLeft 259
#define TOK_VBracketRight 260
#define TOK_whitespace 261
#define TOK_opaque 262
#define TOK_bstring 263
#define TOK_cstring 264
#define TOK_hstring 265
#define TOK_identifier 266
#define TOK_number 267
#define TOK_number_negative 268
#define TOK_realnumber 269
#define TOK_tuple 270
#define TOK_quadruple 271
#define TOK_typereference 272
#define TOK_capitalreference 273
#define TOK_typefieldreference 274
#define TOK_valuefieldreference 275
#define TOK_Literal 276
#define TOK_ExtValue_BIT_STRING 277
#define TOK_ABSENT 278
#define TOK_ABSTRACT_SYNTAX 279
#define TOK_ALL 280
#define TOK_ANY 281
#define TOK_APPLICATION 282
#define TOK_AUTOMATIC 283
#define TOK_BEGIN 284
#define TOK_BIT 285
#define TOK_BMPString 286
#define TOK_BOOLEAN 287
#define TOK_BY 288
#define TOK_CHARACTER 289
#define TOK_CHOICE 290
#define TOK_CLASS 291
#define TOK_COMPONENT 292
#define TOK_COMPONENTS 293
#define TOK_CONSTRAINED 294
#define TOK_CONTAINING 295
#define TOK_DEFAULT 296
#define TOK_DEFINITIONS 297
#define TOK_DEFINED 298
#define TOK_EMBEDDED 299
#define TOK_ENCODED 300
#define TOK_ENCODING_CONTROL 301
#define TOK_END 302
#define TOK_ENUMERATED 303
#define TOK_EXPLICIT 304
#define TOK_EXPORTS 305
#define TOK_EXTENSIBILITY 306
#define TOK_FALSE 307
#define TOK_FROM 308
#define TOK_GeneralizedTime 309
#define TOK_GeneralString 310
#define TOK_GraphicString 311
#define TOK_IA5String 312
#define TOK_IDENTIFIER 313
#define TOK_IMPLICIT 314
#define TOK_IMPLIED 315
#define TOK_IMPORTS 316
#define TOK_INCLUDES 317
#define TOK_INSTANCE 318
#define TOK_INSTRUCTIONS 319
#define TOK_INTEGER 320
#define TOK_ISO646String 321
#define TOK_MAX 322
#define TOK_MIN 323
#define TOK_MINUS_INFINITY 324
#define TOK_NULL 325
#define TOK_NumericString 326
#define TOK_OBJECT 327
#define TOK_ObjectDescriptor 328
#define TOK_OCTET 329
#define TOK_OF 330
#define TOK_OPTIONAL 331
#define TOK_PATTERN 332
#define TOK_PDV 333
#define TOK_PLUS_INFINITY 334
#define TOK_PRESENT 335
#define TOK_PrintableString 336
#define TOK_PRIVATE 337
#define TOK_REAL 338
#define TOK_RELATIVE_OID 339
#define TOK_SEQUENCE 340
#define TOK_SET 341
#define TOK_SIZE 342
#define TOK_STRING 343
#define TOK_SYNTAX 344
#define TOK_T61String 345
#define TOK_TAGS 346
#define TOK_TeletexString 347
#define TOK_TRUE 348
#define TOK_TYPE_IDENTIFIER 349
#define TOK_UNIQUE 350
#define TOK_UNIVERSAL 351
#define TOK_UniversalString 352
#define TOK_UTCTime 353
#define TOK_UTF8String 354
#define TOK_VideotexString 355
#define TOK_VisibleString 356
#define TOK_WITH 357
#define UTF8_BOM 358
#define TOK_EXCEPT 359
#define TOK_INTERSECTION 360
#define TOK_UNION 361
#define TOK_TwoDots 362
#define TOK_ThreeDots 363

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 114 "asn1p_y.y" /* yacc.c:1909  */

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

#line 305 "asn1p_y.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE asn1p_lval;

int asn1p_parse (void **param);

#endif /* !YY_ASN1P_ASN_P_Y_H_INCLUDED  */
