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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse asn1p_parse
#define yylex   asn1p_lex
#define yyerror asn1p_error
#define yylval  asn1p_lval
#define yychar  asn1p_char
#define yydebug asn1p_debug
#define yynerrs asn1p_nerrs


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




/* Copy the first part of user declarations.  */
#line 1 "asn1p_y.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

#define YYPARSE_PARAM	param
#define YYPARSE_PARAM_TYPE	void **
#define YYERROR_VERBOSE

int yylex(void);
int yyerror(const char *msg);
#ifdef	YYBYACC
int yyparse(void **param);	/* byacc does not produce a prototype */
#endif
void asn1p_lexer_hack_push_opaque_state(void);
void asn1p_lexer_hack_enable_with_syntax(void);
void asn1p_lexer_hack_push_encoding_control(void);
#define	yylineno	asn1p_lineno
extern int asn1p_lineno;

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

#define	checkmem(ptr)	do {						\
		if(!(ptr))						\
		return yyerror("Memory failure");			\
	} while(0)

#define	CONSTRAINT_INSERT(root, constr_type, arg1, arg2) do {		\
		if(arg1->type != constr_type) {				\
			int __ret;					\
			root = asn1p_constraint_new(yylineno);		\
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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 389 "asn1p_y.c"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/local/share/bison/yacc.c.  */
#line 410 "asn1p_y.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];	\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  7
#define YYLAST   838

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  108
/* YYNRULES -- Number of rules. */
#define YYNRULES  291
/* YYNRULES -- Number of states. */
#define YYNSTATES  448

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   116,     2,     2,     2,     2,     2,     2,
     109,   110,     2,     2,   112,     2,   117,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   113,   111,
     118,     2,     2,     2,   119,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   114,     2,   115,   101,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   107,   103,   108,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   102,   104,   105,   106
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    19,    20,    22,    26,
      29,    31,    34,    36,    41,    43,    44,    46,    48,    51,
      54,    57,    60,    63,    66,    67,    69,    71,    74,    76,
      78,    80,    82,    84,    85,    89,    91,    95,    98,   100,
     103,   104,   106,   111,   113,   117,   119,   123,   125,   129,
     133,   136,   138,   142,   144,   148,   150,   154,   159,   161,
     163,   168,   172,   176,   183,   190,   192,   196,   198,   202,
     206,   210,   214,   216,   220,   222,   224,   226,   228,   229,
     231,   233,   237,   241,   244,   248,   250,   252,   256,   259,
     261,   263,   269,   270,   272,   274,   278,   281,   286,   290,
     294,   298,   302,   306,   307,   309,   310,   317,   319,   322,
     324,   326,   328,   332,   334,   338,   342,   346,   347,   350,
     352,   357,   362,   367,   374,   381,   383,   388,   392,   394,
     398,   402,   406,   408,   412,   414,   418,   420,   422,   424,
     426,   430,   434,   436,   441,   443,   445,   449,   450,   454,
     456,   458,   460,   462,   464,   466,   468,   470,   474,   476,
     478,   480,   482,   485,   487,   489,   491,   493,   496,   499,
     501,   503,   506,   509,   511,   513,   515,   517,   519,   522,
     524,   527,   529,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   561,   563,
     565,   566,   568,   570,   575,   579,   584,   586,   588,   592,
     598,   600,   604,   608,   612,   616,   621,   625,   627,   629,
     633,   637,   641,   645,   647,   649,   650,   656,   658,   661,
     664,   668,   670,   672,   674,   676,   678,   680,   682,   684,
     688,   694,   696,   700,   702,   706,   707,   709,   711,   713,
     715,   717,   719,   723,   728,   730,   734,   737,   741,   743,
     747,   748,   750,   752,   755,   758,   762,   764,   768,   770,
     775,   780,   782,   784,   786,   788,   789,   791,   794,   799,
     800,   802,   804,   806,   807,   809,   811,   813,   815,   817,
     818,   820
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     121,     0,    -1,   122,    -1,   123,    -1,   122,   123,    -1,
     224,   124,    38,   128,     3,    25,   131,    43,    -1,    -1,
     125,    -1,   107,   126,   108,    -1,   107,   108,    -1,   127,
      -1,   126,   127,    -1,   227,    -1,   227,   109,    10,   110,
      -1,    10,    -1,    -1,   129,    -1,   130,    -1,   129,   130,
      -1,    45,    88,    -1,    56,    88,    -1,    24,    88,    -1,
      47,    57,    -1,    15,    61,    -1,    -1,   132,    -1,   133,
      -1,   132,   133,    -1,   135,    -1,   141,    -1,   147,    -1,
     177,    -1,   145,    -1,    -1,    42,    15,   134,    -1,   187,
      -1,    58,   136,   111,    -1,    58,    50,    -1,   138,    -1,
     136,   138,    -1,    -1,   125,    -1,   139,    50,   224,   137,
      -1,   140,    -1,   139,   112,   140,    -1,   224,    -1,   224,
     107,   108,    -1,   227,    -1,    46,   142,   111,    -1,    46,
      21,   111,    -1,    46,   111,    -1,   143,    -1,   142,   112,
     143,    -1,   224,    -1,   224,   107,   108,    -1,   227,    -1,
     107,   194,   108,    -1,   224,   146,     3,   144,    -1,   186,
      -1,   171,    -1,   171,   107,   150,   108,    -1,   224,     3,
     167,    -1,   224,     3,   157,    -1,   224,   107,   148,   108,
       3,   167,    -1,   224,   107,   148,   108,     3,   157,    -1,
     149,    -1,   148,   112,   149,    -1,   224,    -1,   224,   113,
     227,    -1,   224,   113,   224,    -1,   184,   113,   227,    -1,
     184,   113,   224,    -1,   151,    -1,   150,   112,   151,    -1,
     167,    -1,   180,    -1,   227,    -1,   144,    -1,    -1,   153,
      -1,   154,    -1,   153,   112,   154,    -1,   227,   167,   213,
      -1,   167,   213,    -1,    34,    72,   167,    -1,   166,    -1,
     156,    -1,   155,   112,   156,    -1,   227,   167,    -1,   166,
      -1,   167,    -1,    32,   107,   159,   108,   161,    -1,    -1,
      92,    -1,   160,    -1,   159,   112,   160,    -1,    16,   213,
      -1,    17,   167,   158,   213,    -1,    17,   175,   213,    -1,
      17,   176,   213,    -1,    16,   175,   213,    -1,    16,   167,
     213,    -1,    16,   176,   213,    -1,    -1,   162,    -1,    -1,
      99,    86,   107,   163,   164,   108,    -1,   165,    -1,   164,
     165,    -1,     4,    -1,    18,    -1,   174,    -1,   114,   164,
     115,    -1,   106,    -1,   106,   116,   181,    -1,   106,   116,
     218,    -1,   219,   169,   191,    -1,    -1,   168,   170,    -1,
     146,    -1,    31,   107,   155,   108,    -1,    82,   107,   152,
     108,    -1,    83,   107,   152,   108,    -1,    82,   191,    72,
     226,   219,   169,    -1,    83,   191,    72,   226,   219,   169,
      -1,    22,    -1,    22,    39,    29,   227,    -1,    60,    72,
     171,    -1,    14,    -1,    14,   117,   224,    -1,   225,   117,
     224,    -1,    14,   117,   227,    -1,   225,    -1,   225,   117,
     172,    -1,   173,    -1,   172,   117,   173,    -1,   174,    -1,
      16,    -1,    17,    -1,    16,    -1,   175,   117,    16,    -1,
     175,   117,    17,    -1,    15,    -1,   227,   146,     3,   178,
      -1,   180,    -1,   181,    -1,   227,   113,   178,    -1,    -1,
     107,   179,   183,    -1,    67,    -1,    49,    -1,    90,    -1,
       6,    -1,     8,    -1,   182,    -1,   218,    -1,   227,    -1,
     224,   117,   227,    -1,     7,    -1,    11,    -1,    12,    -1,
       5,    -1,   183,     5,    -1,    28,    -1,    67,    -1,    80,
      -1,   185,    -1,    71,    85,    -1,    69,    55,    -1,    81,
      -1,    48,    -1,    40,    75,    -1,    30,    85,    -1,    95,
      -1,    51,    -1,   187,    -1,    62,    -1,    44,    -1,    26,
      85,    -1,   184,    -1,   185,   215,    -1,    27,    -1,    52,
      -1,    53,    -1,    54,    -1,    63,    -1,    68,    -1,    78,
      -1,    87,    -1,    89,    -1,    94,    -1,    96,    -1,    97,
      -1,    98,    -1,    70,    -1,   103,    -1,   104,    -1,   101,
      -1,   102,    -1,   100,    -1,    -1,   192,    -1,   193,    -1,
      84,   109,   194,   110,    -1,   109,   194,   110,    -1,   193,
     109,   194,   110,    -1,   106,    -1,   195,    -1,   195,   112,
     106,    -1,   195,   112,   106,   112,   195,    -1,   196,    -1,
      21,   100,   196,    -1,   195,   188,   196,    -1,   195,   189,
     196,    -1,   196,   190,   196,    -1,   199,   109,   194,   110,
      -1,   109,   194,   110,    -1,   200,    -1,   201,    -1,   200,
     198,   200,    -1,    65,   198,   200,    -1,   200,   198,    64,
      -1,    65,   198,    64,    -1,   207,    -1,   202,    -1,    -1,
      35,    29,   107,   197,   183,    -1,   105,    -1,   105,   118,
      -1,   118,   105,    -1,   118,   105,   118,    -1,    84,    -1,
      50,    -1,    49,    -1,    90,    -1,   218,    -1,   182,    -1,
     227,    -1,   224,    -1,    99,    33,   193,    -1,    99,    34,
     107,   203,   108,    -1,   204,    -1,   203,   112,   204,    -1,
     106,    -1,   227,   191,   205,    -1,    -1,   206,    -1,    77,
      -1,    19,    -1,    73,    -1,   208,    -1,   209,    -1,   107,
     224,   108,    -1,   208,   107,   210,   108,    -1,   211,    -1,
     210,   112,   211,    -1,   119,   212,    -1,   119,   117,   212,
      -1,   227,    -1,   212,   117,   227,    -1,    -1,   214,    -1,
      73,    -1,    37,   178,    -1,   107,   108,    -1,   107,   216,
     108,    -1,   217,    -1,   216,   112,   217,    -1,   227,    -1,
     227,   109,   218,   110,    -1,   227,   109,   181,   110,    -1,
     218,    -1,   106,    -1,    10,    -1,    13,    -1,    -1,   220,
      -1,   221,   223,    -1,   114,   222,    10,   115,    -1,    -1,
      93,    -1,    23,    -1,    79,    -1,    -1,    56,    -1,    45,
      -1,    14,    -1,    15,    -1,    15,    -1,    -1,   227,    -1,
       9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   323,   323,   329,   335,   351,   376,   378,   381,   385,
     390,   397,   405,   410,   414,   423,   425,   433,   437,   445,
     449,   452,   455,   459,   479,   481,   489,   493,   525,   529,
     538,   545,   558,   566,   565,   579,   591,   602,   607,   613,
     619,   621,   624,   635,   641,   647,   654,   660,   668,   672,
     675,   682,   688,   694,   701,   707,   716,   718,   728,   742,
     752,   768,   778,   794,   800,   807,   817,   827,   832,   839,
     846,   854,   864,   870,   876,   880,   888,   899,   921,   923,
     925,   931,   937,   945,   951,   958,   963,   969,   975,   981,
     984,   990,  1000,  1002,  1005,  1013,  1020,  1033,  1044,  1054,
    1065,  1075,  1086,  1097,  1099,  1106,  1104,  1113,  1118,  1124,
    1129,  1132,  1136,  1141,  1150,  1159,  1170,  1192,  1199,  1218,
    1222,  1228,  1234,  1240,  1250,  1260,  1266,  1277,  1291,  1300,
    1310,  1320,  1330,  1338,  1359,  1368,  1377,  1379,  1386,  1393,
    1399,  1403,  1409,  1429,  1439,  1441,  1442,  1449,  1449,  1454,
    1461,  1467,  1472,  1476,  1480,  1483,  1488,  1500,  1517,  1522,
    1527,  1560,  1570,  1584,  1586,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1603,  1605,  1606,  1609,
    1616,  1628,  1630,  1634,  1638,  1639,  1640,  1641,  1642,  1646,
    1647,  1648,  1649,  1653,  1654,  1661,  1661,  1662,  1662,  1663,
    1665,  1667,  1672,  1676,  1685,  1689,  1694,  1699,  1702,  1708,
    1718,  1722,  1725,  1728,  1731,  1736,  1745,  1753,  1759,  1765,
    1772,  1780,  1788,  1797,  1800,  1804,  1803,  1814,  1816,  1817,
    1818,  1821,  1825,  1830,  1836,  1841,  1844,  1847,  1860,  1874,
    1878,  1883,  1887,  1892,  1899,  1912,  1914,  1917,  1921,  1924,
    1929,  1933,  1941,  1956,  1962,  1969,  1982,  1994,  2009,  2013,
    2030,  2035,  2038,  2043,  2065,  2070,  2075,  2081,  2087,  2095,
    2103,  2111,  2118,  2128,  2133,  2163,  2165,  2168,  2175,  2181,
    2183,  2184,  2185,  2188,  2190,  2191,  2194,  2199,  2206,  2213,
    2215,  2220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_whitespace", "TOK_opaque", 
  "TOK_bstring", "TOK_cstring", "TOK_hstring", "TOK_identifier", 
  "TOK_number", "TOK_tuple", "TOK_quadruple", "TOK_number_negative", 
  "TOK_typereference", "TOK_capitalreference", "TOK_typefieldreference", 
  "TOK_valuefieldreference", "TOK_Literal", "TOK_ABSENT", 
  "TOK_ABSTRACT_SYNTAX", "TOK_ALL", "TOK_ANY", "TOK_APPLICATION", 
  "TOK_AUTOMATIC", "TOK_BEGIN", "TOK_BIT", "TOK_BMPString", "TOK_BOOLEAN", 
  "TOK_BY", "TOK_CHARACTER", "TOK_CHOICE", "TOK_CLASS", "TOK_COMPONENT", 
  "TOK_COMPONENTS", "TOK_CONSTRAINED", "TOK_CONTAINING", "TOK_DEFAULT", 
  "TOK_DEFINITIONS", "TOK_DEFINED", "TOK_EMBEDDED", "TOK_ENCODED", 
  "TOK_ENCODING_CONTROL", "TOK_END", "TOK_ENUMERATED", "TOK_EXPLICIT", 
  "TOK_EXPORTS", "TOK_EXTENSIBILITY", "TOK_EXTERNAL", "TOK_FALSE", 
  "TOK_FROM", "TOK_GeneralizedTime", "TOK_GeneralString", 
  "TOK_GraphicString", "TOK_IA5String", "TOK_IDENTIFIER", "TOK_IMPLICIT", 
  "TOK_IMPLIED", "TOK_IMPORTS", "TOK_INCLUDES", "TOK_INSTANCE", 
  "TOK_INSTRUCTIONS", "TOK_INTEGER", "TOK_ISO646String", "TOK_MAX", 
  "TOK_MIN", "TOK_MINUS_INFINITY", "TOK_NULL", "TOK_NumericString", 
  "TOK_OBJECT", "TOK_ObjectDescriptor", "TOK_OCTET", "TOK_OF", 
  "TOK_OPTIONAL", "TOK_PATTERN", "TOK_PDV", "TOK_PLUS_INFINITY", 
  "TOK_PRESENT", "TOK_PrintableString", "TOK_PRIVATE", "TOK_REAL", 
  "TOK_RELATIVE_OID", "TOK_SEQUENCE", "TOK_SET", "TOK_SIZE", "TOK_STRING", 
  "TOK_SYNTAX", "TOK_T61String", "TOK_TAGS", "TOK_TeletexString", 
  "TOK_TRUE", "TOK_TYPE_IDENTIFIER", "TOK_UNIQUE", "TOK_UNIVERSAL", 
  "TOK_UniversalString", "TOK_UTCTime", "TOK_UTF8String", 
  "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH", "TOK_EXCEPT", 
  "'^'", "TOK_INTERSECTION", "'|'", "TOK_UNION", "TOK_TwoDots", 
  "TOK_ThreeDots", "'{'", "'}'", "'('", "')'", "';'", "','", "':'", "'['", 
  "']'", "'!'", "'.'", "'<'", "'@'", "$accept", "ParsedGrammar", 
  "ModuleList", "ModuleSpecification", "optObjectIdentifier", 
  "ObjectIdentifier", "ObjectIdentifierBody", "ObjectIdentifierElement", 
  "optModuleSpecificationFlags", "ModuleSpecificationFlags", 
  "ModuleSpecificationFlag", "optModuleSpecificationBody", 
  "ModuleSpecificationBody", "ModuleSpecificationElement", "@1", 
  "ImportsDefinition", "ImportsBundleSet", "AssignedIdentifier", 
  "ImportsBundle", "ImportsList", "ImportsElement", "ExportsDefinition", 
  "ExportsBody", "ExportsElement", "ValueSet", "ValueSetTypeAssignment", 
  "DefinedType", "DataTypeReference", "ParameterArgumentList", 
  "ParameterArgumentName", "ActualParameterList", "ActualParameter", 
  "optComponentTypeLists", "ComponentTypeLists", "ComponentType", 
  "AlternativeTypeLists", "AlternativeType", "ObjectClass", "optUnique", 
  "FieldSpec", "ClassField", "optWithSyntax", "WithSyntax", "@2", 
  "WithSyntaxList", "WithSyntaxToken", "ExtensionAndException", "Type", 
  "NSTD_IndirectMarker", "TypeDeclaration", "TypeDeclarationSet", 
  "ComplexTypeReference", "ComplexTypeReferenceAmpList", 
  "ComplexTypeReferenceElement", "PrimitiveFieldReference", "FieldName", 
  "DefinedObjectClass", "ValueDefinition", "Value", "@3", "SimpleValue", 
  "DefinedValue", "RestrictedCharacterStringValue", "Opaque", 
  "BasicTypeId", "BasicTypeId_UniverationCompatible", "BasicType", 
  "BasicString", "Union", "Intersection", "Except", "optConstraints", 
  "Constraints", "SetOfConstraints", "ElementSetSpecs", "ElementSetSpec", 
  "ConstraintSubtypeElement", "@4", "ConstraintRangeSpec", 
  "ConstraintSpec", "SingleValue", "ContainedSubtype", 
  "InnerTypeConstraint", "WithComponentsList", "WithComponentsElement", 
  "optPresenceConstraint", "PresenceConstraint", "TableConstraint", 
  "SimpleTableConstraint", "ComponentRelationConstraint", 
  "AtNotationList", "AtNotationElement", "ComponentIdList", "optMarker", 
  "Marker", "UniverationDefinition", "UniverationList", 
  "UniverationElement", "SignedNumber", "optTag", "Tag", "TagTypeValue", 
  "TagClass", "TagPlicit", "TypeRefName", "ObjectClassReference", 
  "optIdentifier", "Identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,    94,   356,   124,   357,   358,   359,   123,   125,    40,
      41,    59,    44,    58,    91,    93,    33,    46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   120,   121,   122,   122,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   134,   133,   133,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   140,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   143,   144,   145,   146,   146,
     146,   147,   147,   147,   147,   148,   148,   149,   149,   149,
     149,   149,   150,   150,   151,   151,   151,   151,   152,   152,
     153,   153,   154,   154,   154,   154,   155,   155,   156,   156,
     156,   157,   158,   158,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   161,   161,   163,   162,   164,   164,   165,
     165,   165,   165,   166,   166,   166,   167,   168,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   171,   171,   172,   172,   173,   174,   174,   175,
     175,   175,   176,   177,   178,   178,   178,   179,   178,   178,
     180,   180,   180,   180,   180,   180,   181,   181,   182,   182,
     182,   183,   183,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   185,   186,
     186,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   188,   188,   189,   189,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   194,   194,
     195,   195,   195,   195,   195,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   197,   196,   198,   198,   198,
     198,   199,   199,   200,   200,   200,   200,   200,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   206,
     207,   207,   208,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     217,   217,   217,   218,   218,   219,   219,   220,   221,   222,
     222,   222,   222,   223,   223,   223,   224,   224,   225,   226,
     226,   227
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     2,     1,     2,
       0,     1,     4,     1,     3,     1,     3,     1,     3,     3,
       2,     1,     3,     1,     3,     1,     3,     4,     1,     1,
       4,     3,     3,     6,     6,     1,     3,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     0,     1,
       1,     3,     3,     2,     3,     1,     1,     3,     2,     1,
       1,     5,     0,     1,     1,     3,     2,     4,     3,     3,
       3,     3,     3,     0,     1,     0,     6,     1,     2,     1,
       1,     1,     3,     1,     3,     3,     3,     0,     2,     1,
       4,     4,     4,     6,     6,     1,     4,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     3,     1,     4,     1,     1,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     4,     3,     4,     1,     1,     3,     5,
       1,     3,     3,     3,     3,     4,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     0,     5,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     3,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     2,     3,     1,     3,     1,     4,
       4,     1,     1,     1,     1,     0,     1,     2,     4,     0,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     0,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   286,   287,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   291,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    23,    21,    19,    22,    20,     0,    18,    13,    24,
     181,     0,     0,   182,   183,   184,     0,   185,   186,   194,
     187,   188,   189,   190,   191,   192,   193,     0,    25,    26,
      28,    29,    32,    30,    31,    35,     0,     0,    33,     0,
      50,     0,    51,    53,    55,    37,     0,    38,     0,    43,
      45,    47,     5,    27,   275,   128,   288,     0,   163,     0,
       0,   177,   170,   174,   176,   164,     0,     0,   165,   169,
     173,     0,     0,    59,   179,   166,    58,   175,   132,     0,
      34,    49,    48,     0,     0,    36,    39,     0,     0,     0,
       0,   279,    62,    61,   117,   276,   283,     0,   178,   172,
     171,   168,   167,     0,    65,     0,   166,    67,     0,   275,
       0,   180,     0,     0,    52,    54,    40,    44,    46,     0,
     281,   282,   280,     0,     0,   200,   285,   284,   277,   129,
     131,     0,     0,     0,     0,     0,    57,   152,   158,   153,
     273,   159,   160,   274,   150,   151,    77,     0,    72,    74,
      75,   154,   155,    76,   272,   264,     0,   266,   271,   268,
     137,   138,   133,   134,   136,   130,   149,   147,   143,   144,
     145,     0,   156,    41,    42,   275,   275,     0,    94,     0,
     125,     0,     0,   200,   200,   119,   118,     0,     0,   116,
     201,   202,   275,    66,    71,    70,    69,    68,     0,     0,
     233,   232,     0,   231,   234,     0,   206,     0,     0,   236,
       0,   207,   210,     0,   217,   218,   224,   223,   250,   251,
     235,   238,   237,    60,   275,   265,     0,     0,     0,     0,
       0,     0,   142,   139,     0,   262,   260,   260,   260,    96,
     261,    92,   260,   260,   103,     0,   278,     0,   275,     0,
     275,     0,   275,     0,     0,     0,     0,    64,    63,     0,
       0,   227,     0,     0,     0,     0,     0,     0,    56,   197,
     198,   195,   196,     0,     0,     0,   199,     0,     0,     0,
       0,    73,   267,     0,     0,   156,   135,   161,   148,   157,
     146,   263,   101,     0,   100,   102,    93,   260,    98,    99,
       0,    91,   104,    95,     0,   113,     0,    86,    89,    90,
     275,   127,     0,     0,    79,    80,    85,   260,   275,   289,
       0,   289,     0,   204,     0,   211,   225,   228,   229,   222,
     220,   239,     0,   252,   216,   208,   212,   213,   214,     0,
     221,   219,     0,     0,   254,   270,   269,   162,   140,   141,
      97,     0,   126,     0,   120,   275,    88,   275,   121,   275,
      83,   260,   275,   290,   122,   275,   203,   205,     0,   230,
     243,     0,   241,   200,     0,   215,     0,   256,   258,   253,
       0,   105,   114,   115,    87,    84,    81,    82,   117,   117,
     226,   240,     0,   245,   209,   257,     0,   255,     0,   123,
     124,   242,   248,   249,   247,   244,   246,   259,   109,   110,
       0,     0,   107,   111,     0,   106,   108,   112
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    27,    28,
      29,    57,    58,    59,   110,    60,    76,   204,    77,    78,
      79,    61,    71,    72,   176,    62,   102,    63,   133,   134,
     177,   178,   343,   344,   345,   336,   337,   122,   327,   207,
     208,   331,   332,   428,   441,   442,   346,   347,   154,   155,
     216,   103,   192,   193,   443,   267,   268,    64,   198,   259,
     199,   200,   239,   318,   104,   105,   106,   107,   304,   305,
     307,   219,   220,   221,   240,   241,   242,   398,   293,   243,
     244,   245,   246,   401,   402,   435,   436,   247,   248,   249,
     373,   374,   407,   269,   270,   141,   186,   187,   250,   124,
     125,   126,   153,   158,   251,   108,   392,   252
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -403
static const short yypact[] =
{
     133,  -403,  -403,    18,   133,  -403,   -50,  -403,  -403,    50,
     -14,  -403,  -403,  -403,  -403,    76,  -403,   -45,   165,  -403,
    -403,    62,    38,    69,    89,    81,    97,   184,   165,  -403,
     116,  -403,  -403,  -403,  -403,  -403,   172,  -403,  -403,   511,
    -403,   216,    61,  -403,  -403,  -403,   208,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   229,   511,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   341,   664,  -403,   132,
    -403,   173,  -403,   180,  -403,  -403,    32,  -403,   -25,  -403,
     182,  -403,  -403,  -403,   -11,   174,  -403,   222,  -403,   232,
     248,  -403,  -403,  -403,  -403,  -403,   271,   252,  -403,  -403,
    -403,   740,   330,   234,  -403,   236,  -403,  -403,   237,   336,
    -403,  -403,  -403,   200,   241,  -403,  -403,   133,   200,   249,
     257,    -1,  -403,  -403,  -403,  -403,    28,   200,  -403,  -403,
    -403,  -403,  -403,    67,  -403,   253,  -403,   259,   263,   104,
      70,  -403,   331,   192,  -403,  -403,   -50,  -403,  -403,   289,
    -403,  -403,  -403,   365,   588,   -58,  -403,  -403,  -403,  -403,
    -403,   376,   740,   200,   200,   225,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,    78,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   108,  -403,  -403,   273,
    -403,  -403,   266,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   267,   274,  -403,  -403,   154,    74,   141,  -403,   275,
     347,   281,   324,   135,   179,  -403,  -403,   291,   225,  -403,
    -403,   292,   -11,  -403,  -403,  -403,  -403,  -403,   298,   377,
    -403,  -403,   -24,  -403,  -403,   302,  -403,   133,   225,  -403,
     297,   226,   307,   305,   -24,  -403,  -403,  -403,   308,  -403,
    -403,  -403,  -403,  -403,   104,  -403,    87,   215,   335,   411,
     409,   192,  -403,  -403,   192,  -403,    25,    91,    25,  -403,
    -403,   328,    91,    25,   325,   289,  -403,   394,    60,   345,
      59,   353,    59,   354,   225,   317,   225,  -403,  -403,   453,
     322,   313,   327,   301,   332,   326,   334,   333,  -403,  -403,
    -403,  -403,  -403,   338,   453,   453,  -403,   453,   225,   309,
     315,  -403,  -403,   346,   348,  -403,  -403,  -403,   435,  -403,
    -403,  -403,  -403,   361,  -403,  -403,  -403,    25,  -403,  -403,
     359,  -403,  -403,  -403,   409,   343,   186,  -403,  -403,  -403,
     355,  -403,   374,   349,   358,  -403,  -403,    25,   355,   409,
     363,   409,   362,  -403,   364,  -403,  -403,  -403,   360,  -403,
    -403,   292,    39,  -403,  -403,   367,  -403,  -403,  -403,   366,
    -403,  -403,    23,   188,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   370,  -403,   215,  -403,    60,  -403,   355,  -403,    54,
    -403,    25,   355,  -403,  -403,   355,  -403,  -403,   411,  -403,
    -403,   189,  -403,   -58,   440,  -403,   409,   356,  -403,  -403,
     315,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
     435,  -403,    39,   177,     4,   356,   409,  -403,    11,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
      11,    36,  -403,  -403,    27,  -403,  -403,  -403
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -403,  -403,  -403,   476,  -403,   337,  -403,   466,  -403,  -403,
     454,  -403,  -403,   426,  -403,  -403,  -403,  -403,   410,  -403,
     369,  -403,  -403,   372,   357,  -403,   -53,  -403,  -403,   329,
    -403,   238,   211,  -403,   105,  -403,   111,   276,  -403,  -403,
     224,  -403,  -403,  -403,    57,  -402,  -258,   -83,  -403,   -57,
    -403,   221,  -403,   243,  -137,   300,   303,  -403,     0,  -403,
    -130,  -250,  -135,   106,   -88,     1,  -403,    -3,  -403,  -403,
    -403,  -211,  -403,   213,    -5,   107,   -12,  -403,   264,  -403,
    -243,  -403,  -403,  -403,    88,  -403,  -403,  -403,  -403,  -403,
    -403,   102,   109,  -256,  -403,  -403,  -403,   258,  -105,  -125,
    -403,  -403,  -403,  -403,    19,  -403,   162,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -261
static const short yytable[] =
{
      17,   123,   281,   283,   181,   194,    17,   313,   181,   180,
     322,   324,   325,   135,   109,   438,   328,   329,     7,     6,
     338,   120,   150,     6,    18,   117,   217,   190,   191,   439,
      67,   438,    12,    74,   182,   188,    65,    81,   182,   446,
     438,    12,   446,   190,   191,   439,     1,     2,    12,    67,
     360,   218,   190,   191,   439,    65,   179,     9,    66,    12,
      13,    73,   264,    12,    21,    80,   371,    81,    12,    12,
      12,   380,    30,   156,   135,     1,     2,    66,   151,    12,
     170,   291,    69,   173,   157,    12,    13,   118,   342,   262,
     263,   390,   152,   342,   292,    80,    12,   170,   265,    31,
     173,   215,   136,   121,    74,   299,   300,   301,   302,    81,
     167,   168,   169,    12,   170,   171,   172,   173,   160,   181,
     137,   194,   266,   271,   180,   440,   181,   338,   264,   181,
     183,   189,    73,   412,   202,   417,   146,    80,    34,   288,
     406,   440,   447,   115,   445,   400,   159,     1,     2,   182,
     440,   188,   314,   174,   225,   227,   182,    32,    14,   182,
     335,   195,   201,   136,   265,   335,   335,   -78,   121,   262,
     263,   179,    70,   121,   121,   161,   184,    33,   185,   162,
      22,   137,   224,   226,    19,    35,   253,    36,   121,    23,
     254,   264,   423,   184,   175,   339,   432,    39,   167,   168,
     169,    12,   170,   171,   172,   173,     1,     2,   323,    12,
      24,   165,    25,   285,     1,     2,   255,    12,   121,   217,
     256,    26,     1,     2,    12,   170,    38,   265,   173,     1,
       2,    68,   168,   297,    12,   170,   171,   172,   173,     1,
       2,   174,   280,   111,   218,   183,   228,   189,   315,   274,
     433,   319,   202,   275,   434,   202,   296,   386,    75,   196,
     229,   320,  -260,   217,   321,   391,  -260,   418,   121,   340,
     419,   348,    82,   348,   230,   231,   201,   355,   413,   352,
     201,   354,   175,   201,   112,   113,   282,   114,   218,   119,
     232,   127,   366,   367,   384,   368,   409,   421,   385,   197,
     410,   422,   339,   369,   415,   205,   206,   128,   168,   233,
      12,   170,   171,   172,   173,   234,   168,   129,    12,   170,
     171,   172,   173,   130,   235,   382,   131,   299,   300,   301,
     302,   236,   237,   138,   238,   294,   295,   132,   303,   143,
     393,   139,   393,   140,    84,     1,     2,   190,   191,   145,
     230,   190,   191,   403,   142,    85,    86,   148,   230,    85,
      86,   429,   430,   408,   149,   359,   163,    87,    40,    88,
     165,    89,   164,   370,   315,   209,   340,   378,   379,   222,
     348,    90,   257,   258,   260,    91,   277,   261,   278,    92,
     276,   234,    93,    43,    44,    45,   279,   408,   289,   234,
     284,   286,   201,    94,    47,   298,   290,   306,    95,    48,
      96,    49,    97,   403,   308,   310,   317,   437,    12,    50,
     326,    98,    99,   334,   330,   349,   351,   353,    51,   356,
      52,   357,   358,   362,   372,    53,   100,    54,    55,    56,
     377,   218,   363,   364,   365,   381,   387,   168,   101,    12,
     170,   171,   172,   173,     1,     2,   375,   388,   376,   383,
     168,   228,    12,   170,   171,   172,   173,     1,     2,   121,
     389,   394,   396,   426,   397,   229,   405,   411,   399,   404,
       8,    20,    37,   203,    83,   144,   116,   147,   229,   230,
     231,   223,   311,   350,   416,   166,   414,   444,   287,   333,
     341,   316,   230,   231,   420,   232,   272,   361,   309,   273,
     431,   424,   427,   395,   312,   425,     0,     0,   232,     0,
      12,     0,     0,     0,   233,     1,     2,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,   233,    40,   235,
       0,     0,     0,   234,     0,     0,     0,   237,     0,   238,
       0,     0,   235,    41,     0,     0,     0,    42,     0,     0,
     237,     0,   238,    43,    44,    45,     0,     0,     0,    46,
       0,     0,     0,     0,    47,     0,     0,     0,     0,    48,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    85,    86,     0,    53,     0,    54,    55,    56,
     210,     0,     0,     0,    87,    40,    88,     0,    89,   211,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,    91,     0,     0,     0,    92,     0,     0,    93,
      43,    44,    45,     0,     0,     0,     0,     0,   212,     0,
      94,    47,     0,     0,     0,    95,    48,    96,    49,    97,
       0,     0,     0,     0,     0,     0,    50,     0,    98,    99,
     213,   214,     0,     0,     0,    51,     0,    52,    85,    86,
       0,     0,    53,   100,    54,    55,    56,     0,     0,     0,
      87,    40,    88,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,    91,     0,
       0,     0,    92,     0,     0,    93,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,    94,    47,     0,     0,
       0,    95,    48,    96,    49,    97,     0,     0,     0,     0,
       0,     0,    50,     0,    98,    99,     0,     0,     0,     0,
       0,    51,     0,    52,     1,     2,     0,     0,    53,   100,
      54,    55,    56,     0,     0,     0,    87,    40,    88,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,    91,     0,     0,     0,    92,     0,
       0,    93,    43,    44,    45,     0,     0,     0,     0,     0,
       0,     0,    94,    47,     0,     0,     0,    95,    48,    96,
      49,    97,     0,     0,     0,     0,     0,     0,    50,     0,
      98,    99,     0,     0,     0,     0,     0,    51,     0,    52,
       0,     0,     0,     0,    53,   100,    54,    55,    56
};

static const short yycheck[] =
{
       9,    84,   213,   214,   139,   142,    15,   257,   143,   139,
     266,   267,   268,   101,    67,     4,   272,   273,     0,     0,
     278,    32,    23,     4,    38,    50,    84,    16,    17,    18,
      39,     4,     9,    42,   139,   140,    39,    46,   143,   441,
       4,     9,   444,    16,    17,    18,    14,    15,     9,    58,
     293,   109,    16,    17,    18,    58,   139,   107,    39,     9,
      10,    42,    37,     9,   109,    46,   309,    76,     9,     9,
       9,   327,    10,    45,   162,    14,    15,    58,    79,     9,
      10,   105,    21,    13,    56,     9,    10,   112,    34,    15,
      16,   347,    93,    34,   118,    76,     9,    10,    73,    61,
      13,   154,   101,   114,   113,   101,   102,   103,   104,   118,
       6,     7,     8,     9,    10,    11,    12,    13,   127,   254,
     101,   258,   205,   206,   254,   114,   261,   385,    37,   264,
     139,   140,   113,   383,   143,   391,   117,   118,    57,   222,
     117,   114,   115,   111,   108,   106,   127,    14,    15,   254,
     114,   256,   257,    49,   163,   164,   261,    88,   108,   264,
     106,   142,   143,   162,    73,   106,   106,   108,   114,    15,
      16,   254,   111,   114,   114,   108,   106,    88,   108,   112,
      15,   162,   163,   164,   108,    88,   108,     3,   114,    24,
     112,    37,   403,   106,    90,   278,    19,    25,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   117,     9,
      45,   107,    47,   218,    14,    15,   108,     9,   114,    84,
     112,    56,    14,    15,     9,    10,   110,    73,    13,    14,
      15,    15,     7,   238,     9,    10,    11,    12,    13,    14,
      15,    49,   107,   111,   109,   254,    21,   256,   257,   108,
      73,   260,   261,   112,    77,   264,   237,   340,    50,    67,
      35,   261,   108,    84,   264,   348,   112,   392,   114,   278,
     395,   280,    43,   282,    49,    50,   257,   289,   383,   284,
     261,   286,    90,   264,   111,   112,   107,   107,   109,   107,
      65,   117,   304,   305,   108,   307,   108,   108,   112,   107,
     112,   112,   385,   308,   387,    16,    17,    85,     7,    84,
       9,    10,    11,    12,    13,    90,     7,    85,     9,    10,
      11,    12,    13,    75,    99,   334,    55,   101,   102,   103,
     104,   106,   107,     3,   109,    33,    34,    85,   112,     3,
     349,   107,   351,   107,     3,    14,    15,    16,    17,   108,
      49,    16,    17,   362,   117,    14,    15,   108,    49,    14,
      15,   418,   419,   372,   107,    64,   113,    26,    27,    28,
     107,    30,   113,    64,   383,    10,   385,    16,    17,     3,
     389,    40,   109,   117,   117,    44,    39,   113,   107,    48,
     115,    90,    51,    52,    53,    54,    72,   406,   100,    90,
     109,   109,   383,    62,    63,   108,    29,   100,    67,    68,
      69,    70,    71,   422,   109,   107,     5,   426,     9,    78,
      92,    80,    81,    29,    99,    72,    72,   110,    87,   107,
      89,   118,   105,   107,   119,    94,    95,    96,    97,    98,
       5,   109,   108,   110,   106,    86,    72,     7,   107,     9,
      10,    11,    12,    13,    14,    15,   110,   108,   110,   116,
       7,    21,     9,    10,    11,    12,    13,    14,    15,   114,
     112,   108,   110,   117,   110,    35,   110,   107,   118,   112,
       4,    15,    28,   146,    58,   113,    76,   118,    35,    49,
      50,   162,   254,   282,   389,   138,   385,   440,   222,   275,
     279,   258,    49,    50,   398,    65,   206,   294,   244,   206,
     422,   404,   410,   351,   256,   406,    -1,    -1,    65,    -1,
       9,    -1,    -1,    -1,    84,    14,    15,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    84,    27,    99,
      -1,    -1,    -1,    90,    -1,    -1,    -1,   107,    -1,   109,
      -1,    -1,    99,    42,    -1,    -1,    -1,    46,    -1,    -1,
     107,    -1,   109,    52,    53,    54,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      89,    -1,    14,    15,    -1,    94,    -1,    96,    97,    98,
      22,    -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,    89,    14,    15,
      -1,    -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    14,    15,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    14,    15,   121,   122,   123,   224,     0,   123,   107,
     124,   125,     9,    10,   108,   126,   127,   227,    38,   108,
     127,   109,    15,    24,    45,    47,    56,   128,   129,   130,
      10,    61,    88,    88,    57,    88,     3,   130,   110,    25,
      27,    42,    46,    52,    53,    54,    58,    63,    68,    70,
      78,    87,    89,    94,    96,    97,    98,   131,   132,   133,
     135,   141,   145,   147,   177,   187,   224,   227,    15,    21,
     111,   142,   143,   224,   227,    50,   136,   138,   139,   140,
     224,   227,    43,   133,     3,    14,    15,    26,    28,    30,
      40,    44,    48,    51,    62,    67,    69,    71,    80,    81,
      95,   107,   146,   171,   184,   185,   186,   187,   225,   146,
     134,   111,   111,   112,   107,   111,   138,    50,   112,   107,
      32,   114,   157,   167,   219,   220,   221,   117,    85,    85,
      75,    55,    85,   148,   149,   184,   185,   224,     3,   107,
     107,   215,   117,     3,   143,   108,   224,   140,   108,   107,
      23,    79,    93,   222,   168,   169,    45,    56,   223,   224,
     227,   108,   112,   113,   113,   107,   144,     6,     7,     8,
      10,    11,    12,    13,    49,    90,   144,   150,   151,   167,
     180,   182,   218,   227,   106,   108,   216,   217,   218,   227,
      16,    17,   172,   173,   174,   224,    67,   107,   178,   180,
     181,   224,   227,   125,   137,    16,    17,   159,   160,    10,
      22,    31,    60,    82,    83,   146,   170,    84,   109,   191,
     192,   193,     3,   149,   224,   227,   224,   227,    21,    35,
      49,    50,    65,    84,    90,    99,   106,   107,   109,   182,
     194,   195,   196,   199,   200,   201,   202,   207,   208,   209,
     218,   224,   227,   108,   112,   108,   112,   109,   117,   179,
     117,   113,    15,    16,    37,    73,   167,   175,   176,   213,
     214,   167,   175,   176,   108,   112,   115,    39,   107,    72,
     107,   191,   107,   191,   109,   194,   109,   157,   167,   100,
      29,   105,   118,   198,    33,    34,   224,   194,   108,   101,
     102,   103,   104,   112,   188,   189,   100,   190,   109,   198,
     107,   151,   217,   181,   218,   227,   173,     5,   183,   227,
     178,   178,   213,   117,   213,   213,    92,   158,   213,   213,
      99,   161,   162,   160,    29,   106,   155,   156,   166,   167,
     227,   171,    34,   152,   153,   154,   166,   167,   227,    72,
     152,    72,   194,   110,   194,   196,   107,   118,   105,    64,
     200,   193,   107,   108,   110,   106,   196,   196,   196,   194,
      64,   200,   119,   210,   211,   110,   110,     5,    16,    17,
     213,    86,   227,   116,   108,   112,   167,    72,   108,   112,
     213,   167,   226,   227,   108,   226,   110,   110,   197,   118,
     106,   203,   204,   227,   112,   110,   117,   212,   227,   108,
     112,   107,   181,   218,   156,   167,   154,   213,   219,   219,
     183,   108,   112,   191,   195,   212,   117,   211,   163,   169,
     169,   204,    19,    73,    77,   205,   206,   227,     4,    18,
     114,   164,   165,   174,   164,   108,   165,   115
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 2:
#line 324 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 330 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 335 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 356 "asn1p_y.y"
    {

		if(yyvsp[-1].a_module) {
			yyval.a_module = yyvsp[-1].a_module;
		} else {
			/* There's a chance that a module is just plain empty */
			yyval.a_module = asn1p_module_new();
		}
		checkmem(yyval.a_module);

		yyval.a_module->ModuleName = yyvsp[-7].tv_str;
		yyval.a_module->module_oid = yyvsp[-6].a_oid;
		yyval.a_module->module_flags = yyvsp[-4].a_module_flags;
	}
    break;

  case 6:
#line 377 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 7:
#line 378 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 8:
#line 382 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 9:
#line 385 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 10:
#line 391 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 11:
#line 397 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 406 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 13:
#line 410 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 14:
#line 414 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 15:
#line 424 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 16:
#line 425 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 17:
#line 434 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 437 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 446 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 449 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 452 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 455 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 459 "asn1p_y.y"
    {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp(yyvsp[-1].tv_str, "TAG") == 0) {
		 	yyval.a_module_flags = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp(yyvsp[-1].tv_str, "XER") == 0) {
		 	yyval.a_module_flags = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at line %d: "
				"Unrecognized encoding reference\n",
				yyvsp[-1].tv_str, yylineno);
		 	yyval.a_module_flags = MSF_unk_INSTRUCTIONS;
		}
		free(yyvsp[-1].tv_str);
	}
    break;

  case 24:
#line 480 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 25:
#line 481 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 26:
#line 490 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 27:
#line 493 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;

		/* Behave well when one of them is skipped. */
		if(!(yyvsp[-1].a_module)) {
			if(yyvsp[0].a_module) yyval.a_module = yyvsp[0].a_module;
			break;
		}

#ifdef	MY_IMPORT
#error	MY_IMPORT DEFINED ELSEWHERE!
#endif
#define	MY_IMPORT(foo,field)	do {				\
		while(TQ_FIRST(&(yyvsp[0].a_module->foo))) {			\
			TQ_ADD(&(yyval.a_module->foo),			\
				TQ_REMOVE(&(yyvsp[0].a_module->foo), field),	\
				field);				\
		}						\
		assert(TQ_FIRST(&(yyvsp[0].a_module->foo)) == 0);		\
	} while(0)

		MY_IMPORT(imports, xp_next);
		MY_IMPORT(exports, xp_next);
		MY_IMPORT(members, next);
#undef	MY_IMPORT

	}
    break;

  case 28:
#line 526 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 29:
#line 529 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		if(yyvsp[0].a_xports) {
			TQ_ADD(&(yyval.a_module->exports), yyvsp[0].a_xports, xp_next);
		} else {
			/* "EXPORTS ALL;" ? */
		}
	}
    break;

  case 30:
#line 538 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 545 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 558 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 33:
#line 566 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 567 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at line %d ignored\n",
			yyvsp[-1].tv_str, yylineno);
		free(yyvsp[-1].tv_str);
		yyval.a_module = 0;
	}
    break;

  case 35:
#line 579 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 592 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 37:
#line 602 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 38:
#line 608 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 39:
#line 613 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 40:
#line 620 "asn1p_y.y"
    { memset(&yyval.a_aid, 0, sizeof(yyval.a_aid)); }
    break;

  case 41:
#line 621 "asn1p_y.y"
    { yyval.a_aid.oid = yyvsp[0].a_oid; }
    break;

  case 42:
#line 625 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->fromModuleName = yyvsp[-1].tv_str;
		yyval.a_xports->identifier = yyvsp[0].a_aid;
		/* This stupid thing is used for look-back hack. */
		saved_aid = yyval.a_xports->identifier.oid ? 0 : &(yyval.a_xports->identifier);
		checkmem(yyval.a_xports);
	}
    break;

  case 43:
#line 636 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 44:
#line 641 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 45:
#line 648 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 46:
#line 654 "asn1p_y.y"
    {		/* Completely equivalent to above */
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 47:
#line 660 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 48:
#line 669 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 49:
#line 672 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 50:
#line 675 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 51:
#line 683 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 52:
#line 688 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 53:
#line 695 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 54:
#line 701 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 55:
#line 707 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 56:
#line 716 "asn1p_y.y"
    { yyval.a_constr = yyvsp[-1].a_constr; }
    break;

  case 57:
#line 719 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 58:
#line 729 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 59:
#line 742 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 60:
#line 752 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[-3].a_ref;
		yyval.a_expr->rhs_pspecs = yyvsp[-1].a_expr;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 61:
#line 772 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 62:
#line 778 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 63:
#line 794 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 64:
#line 800 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 65:
#line 808 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = asn1p_paramlist_new(yylineno);
		checkmem(yyval.a_plist);
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 66:
#line 817 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 67:
#line 828 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 68:
#line 832 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 69:
#line 839 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 70:
#line 846 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 71:
#line 854 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 72:
#line 865 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 73:
#line 870 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 74:
#line 877 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 75:
#line 880 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = "?";
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 76:
#line 888 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		yyval.a_expr->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 77:
#line 899 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->expr_type = A1TC_VALUESET;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 78:
#line 922 "asn1p_y.y"
    { yyval.a_expr = asn1p_expr_new(yylineno); }
    break;

  case 79:
#line 923 "asn1p_y.y"
    { yyval.a_expr = yyvsp[0].a_expr; }
    break;

  case 80:
#line 926 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 81:
#line 931 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 82:
#line 938 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 83:
#line 945 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 84:
#line 951 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 85:
#line 958 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 86:
#line 964 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 87:
#line 969 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 88:
#line 976 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
	}
    break;

  case 89:
#line 981 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 90:
#line 984 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 91:
#line 991 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 92:
#line 1001 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 93:
#line 1002 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 94:
#line 1006 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 95:
#line 1013 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 96:
#line 1023 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 97:
#line 1033 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		yyval.a_expr->unique = yyvsp[-1].a_int;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		asn1p_expr_add(yyval.a_expr, yyvsp[-2].a_expr);
	}
    break;

  case 98:
#line 1044 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 99:
#line 1054 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_OFS;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 100:
#line 1065 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVSFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 101:
#line 1075 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add(yyval.a_expr, yyvsp[-1].a_expr);
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 102:
#line 1086 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_OSFS;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 103:
#line 1098 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 104:
#line 1099 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 105:
#line 1106 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 106:
#line 1108 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 107:
#line 1114 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 108:
#line 1118 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 109:
#line 1125 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		yyval.a_wchunk->type = WC_WHITESPACE;
	}
    break;

  case 110:
#line 1129 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].tv_str, strlen(yyvsp[0].tv_str), 0);
	}
    break;

  case 111:
#line 1132 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].a_refcomp.name, strlen(yyvsp[0].a_refcomp.name), 0);
		yyval.a_wchunk->type = WC_FIELD;
	}
    break;

  case 112:
#line 1136 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromsyntax(yyvsp[-1].a_wsynt);
	}
    break;

  case 113:
#line 1142 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 114:
#line 1150 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->value = yyvsp[0].a_value;
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 115:
#line 1159 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		yyval.a_expr->value = yyvsp[0].a_value;
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 116:
#line 1171 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyval.a_expr->tag = yyvsp[-2].a_tag;
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if(yyval.a_expr->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| yyval.a_expr->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&(yyval.a_expr->members))->constraints);
			TQ_FIRST(&(yyval.a_expr->members))->constraints = yyvsp[0].a_constr;
		} else {
			if(yyval.a_expr->constraints) {
				assert(!yyvsp[-1].a_expr);
			} else {
				yyval.a_expr->constraints = yyvsp[0].a_constr;
			}
		}
	}
    break;

  case 117:
#line 1193 "asn1p_y.y"
    {
		yyval.a_int = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 118:
#line 1200 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->marker.flags |= yyvsp[-1].a_int;

		if((yyval.a_expr->marker.flags & EM_INDIRECT)
		&& (yyval.a_expr->marker.flags & EM_OPTIONAL) != EM_OPTIONAL) {
			fprintf(stderr,
				"INFO: Directive <ASN1C:RepresentAsPointer> "
				"applied to %s at line %d\n",
				ASN_EXPR_TYPE2STR(yyval.a_expr->expr_type)
					?  ASN_EXPR_TYPE2STR(yyval.a_expr->expr_type)
					: "member",
				yyval.a_expr->_lineno
			);
		}
	}
    break;

  case 119:
#line 1219 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 120:
#line 1222 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 121:
#line 1228 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 122:
#line 1234 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 123:
#line 1240 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-4].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		yyvsp[0].a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_expr->tag = yyvsp[-1].a_tag;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 124:
#line 1250 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-4].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SET_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		yyvsp[0].a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_expr->tag = yyvsp[-1].a_tag;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 125:
#line 1260 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 126:
#line 1266 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_expr->reference,
			yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 127:
#line 1277 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 128:
#line 1292 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 129:
#line 1300 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[-2].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[-2].tv_str);
	}
    break;

  case 130:
#line 1310 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[-2].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[-2].tv_str);
	}
    break;

  case 131:
#line 1320 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[-2].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		free(yyvsp[-2].tv_str);
	}
    break;

  case 132:
#line 1330 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 133:
#line 1338 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[0].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[-2].tv_str, RLT_CAPITALS);
		free(yyvsp[-2].tv_str);
		checkmem(ret == 0);
		/*
		 * Move the last element infront.
		 */
		{
			struct asn1p_ref_component_s tmp_comp;
			tmp_comp = yyval.a_ref->components[yyval.a_ref->comp_count-1];
			memmove(&yyval.a_ref->components[1],
				&yyval.a_ref->components[0],
				sizeof(yyval.a_ref->components[0])
				* (yyval.a_ref->comp_count - 1));
			yyval.a_ref->components[0] = tmp_comp;
		}
	}
    break;

  case 134:
#line 1360 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 135:
#line 1368 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 137:
#line 1381 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 138:
#line 1386 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 139:
#line 1395 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 140:
#line 1399 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 141:
#line 1403 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_Amplowercase);
	}
    break;

  case 142:
#line 1410 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
	}
    break;

  case 143:
#line 1430 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 146:
#line 1442 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_CHOICE_IDENTIFIER;
		yyval.a_value->value.choice_identifier.identifier = yyvsp[-2].tv_str;
		yyval.a_value->value.choice_identifier.value = yyvsp[0].a_value;
	}
    break;

  case 147:
#line 1449 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 148:
#line 1449 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 149:
#line 1454 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_NULL;
	}
    break;

  case 150:
#line 1462 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 151:
#line 1467 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 152:
#line 1472 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 153:
#line 1476 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 154:
#line 1480 "asn1p_y.y"
    {
		yyval.a_value = yyval.a_value;
	}
    break;

  case 155:
#line 1483 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 156:
#line 1489 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_value = asn1p_value_fromref(ref, 0);
		checkmem(yyval.a_value);
		free(yyvsp[0].tv_str);
	}
    break;

  case 157:
#line 1500 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, yyvsp[-2].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_value = asn1p_value_fromref(ref, 0);
		checkmem(yyval.a_value);
		free(yyvsp[-2].tv_str);
		free(yyvsp[0].tv_str);
	}
    break;

  case 158:
#line 1518 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 159:
#line 1522 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TUPLE;
	}
    break;

  case 160:
#line 1527 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_QUADRUPLE;
	}
    break;

  case 161:
#line 1561 "asn1p_y.y"
    {
		yyval.tv_opaque.len = yyvsp[0].tv_opaque.len + 1;
		yyval.tv_opaque.buf = malloc(yyval.tv_opaque.len + 1);
		checkmem(yyval.tv_opaque.buf);
		yyval.tv_opaque.buf[0] = '{';
		memcpy(yyval.tv_opaque.buf + 1, yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len);
		yyval.tv_opaque.buf[yyval.tv_opaque.len] = '\0';
		free(yyvsp[0].tv_opaque.buf);
	}
    break;

  case 162:
#line 1570 "asn1p_y.y"
    {
		int newsize = yyvsp[-1].tv_opaque.len + yyvsp[0].tv_opaque.len;
		char *p = malloc(newsize + 1);
		checkmem(p);
		memcpy(p         , yyvsp[-1].tv_opaque.buf, yyvsp[-1].tv_opaque.len);
		memcpy(p + yyvsp[-1].tv_opaque.len, yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len);
		p[newsize] = '\0';
		free(yyvsp[-1].tv_opaque.buf);
		free(yyvsp[0].tv_opaque.buf);
		yyval.tv_opaque.buf = p;
		yyval.tv_opaque.len = newsize;
	}
    break;

  case 163:
#line 1585 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 164:
#line 1586 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 165:
#line 1587 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 166:
#line 1588 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 167:
#line 1589 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 168:
#line 1590 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 169:
#line 1591 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 170:
#line 1592 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 171:
#line 1593 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 172:
#line 1594 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 173:
#line 1595 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 174:
#line 1596 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 175:
#line 1597 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 176:
#line 1604 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 177:
#line 1605 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 178:
#line 1606 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 179:
#line 1610 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 180:
#line 1616 "asn1p_y.y"
    {
		if(yyvsp[0].a_expr) {
			yyval.a_expr = yyvsp[0].a_expr;
		} else {
			yyval.a_expr = asn1p_expr_new(yylineno);
			checkmem(yyval.a_expr);
		}
		yyval.a_expr->expr_type = yyvsp[-1].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 181:
#line 1629 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 182:
#line 1630 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 183:
#line 1634 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 184:
#line 1638 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 185:
#line 1639 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 186:
#line 1640 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 187:
#line 1641 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 188:
#line 1642 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 189:
#line 1646 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 190:
#line 1647 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 191:
#line 1648 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 192:
#line 1649 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 193:
#line 1653 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 194:
#line 1654 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 200:
#line 1666 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 201:
#line 1667 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 202:
#line 1673 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 203:
#line 1676 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 204:
#line 1686 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 205:
#line 1689 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 206:
#line 1695 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 207:
#line 1699 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 208:
#line 1702 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 209:
#line 1708 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 210:
#line 1719 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 211:
#line 1722 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_AEX, yyvsp[0].a_constr, 0);
	}
    break;

  case 212:
#line 1725 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 213:
#line 1728 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 214:
#line 1731 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 215:
#line 1737 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 216:
#line 1745 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 217:
#line 1753 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 218:
#line 1759 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_TYPE;
		yyval.a_constr->containedSubtype = yyvsp[0].a_value;
	}
    break;

  case 219:
#line 1765 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 220:
#line 1772 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 221:
#line 1780 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 222:
#line 1788 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_start->type = ATV_MIN;
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 223:
#line 1797 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 224:
#line 1800 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 225:
#line 1804 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 226:
#line 1804 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CT_CTDBY;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_constr->value);
		yyval.a_constr->value->type = ATV_UNPARSED;
	}
    break;

  case 227:
#line 1815 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 228:
#line 1816 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 229:
#line 1817 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 230:
#line 1818 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 231:
#line 1822 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 232:
#line 1825 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 233:
#line 1831 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 234:
#line 1836 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 235:
#line 1841 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 236:
#line 1844 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 237:
#line 1847 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_value = asn1p_value_fromref(ref, 0);
		checkmem(yyval.a_value);
		free(yyvsp[0].tv_str);
	}
    break;

  case 238:
#line 1861 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		yyval.a_value = asn1p_value_fromref(ref, 0);
		checkmem(yyval.a_value);
		free(yyvsp[0].tv_str);
	}
    break;

  case 239:
#line 1875 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMP, yyvsp[0].a_constr, 0);
	}
    break;

  case 240:
#line 1878 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 241:
#line 1884 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 242:
#line 1887 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 243:
#line 1893 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
		yyval.a_constr->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 244:
#line 1899 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
		if(yyvsp[-1].a_constr) asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 245:
#line 1913 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 246:
#line 1914 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 247:
#line 1918 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 248:
#line 1921 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 249:
#line 1924 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 250:
#line 1930 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 251:
#line 1933 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 252:
#line 1942 "asn1p_y.y"
    {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, yyvsp[-1].tv_str, 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, ct, 0);
	}
    break;

  case 253:
#line 1957 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 254:
#line 1963 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 255:
#line 1969 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 256:
#line 1983 "asn1p_y.y"
    {
		char *p = malloc(strlen(yyvsp[0].tv_str) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, yyvsp[0].tv_str);
		yyval.a_ref = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_ref, p, 0);
		checkmem(ret == 0);
		free(p);
		free(yyvsp[0].tv_str);
	}
    break;

  case 257:
#line 1994 "asn1p_y.y"
    {
		char *p = malloc(strlen(yyvsp[0].tv_str) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, yyvsp[0].tv_str);
		yyval.a_ref = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_ref, p, 0);
		checkmem(ret == 0);
		free(p);
		free(yyvsp[0].tv_str);
	}
    break;

  case 258:
#line 2010 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 259:
#line 2013 "asn1p_y.y"
    {
		int l1 = strlen(yyvsp[-2].tv_str);
		int l3 = strlen(yyvsp[0].tv_str);
		yyval.tv_str = malloc(l1 + 1 + l3 + 1);
		memcpy(yyval.tv_str, yyvsp[-2].tv_str, l1);
		yyval.tv_str[l1] = '.';
		memcpy(yyval.tv_str + l1 + 1, yyvsp[0].tv_str, l3);
		yyval.tv_str[l1 + 1 + l3] = '\0';
	}
    break;

  case 260:
#line 2031 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_NOMARK;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 261:
#line 2035 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 262:
#line 2039 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_OPTIONAL | EM_INDIRECT;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 263:
#line 2043 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_DEFAULT;
		yyval.a_marker.default_value = yyvsp[0].a_value;
	}
    break;

  case 264:
#line 2066 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
	}
    break;

  case 265:
#line 2070 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 266:
#line 2076 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 267:
#line 2081 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 268:
#line 2088 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 269:
#line 2095 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 270:
#line 2103 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 271:
#line 2111 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 272:
#line 2118 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 273:
#line 2129 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 274:
#line 2133 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 275:
#line 2164 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 276:
#line 2165 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 277:
#line 2169 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = yyvsp[0].a_tag.tag_mode;
	}
    break;

  case 278:
#line 2176 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-2].a_tag;
		yyval.a_tag.tag_value = yyvsp[-1].a_int;
	}
    break;

  case 279:
#line 2182 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 280:
#line 2183 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_UNIVERSAL; }
    break;

  case 281:
#line 2184 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_APPLICATION; }
    break;

  case 282:
#line 2185 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_PRIVATE; }
    break;

  case 283:
#line 2189 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_DEFAULT; }
    break;

  case 284:
#line 2190 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_IMPLICIT; }
    break;

  case 285:
#line 2191 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_EXPLICIT; }
    break;

  case 286:
#line 2195 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 287:
#line 2199 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 288:
#line 2207 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 289:
#line 2214 "asn1p_y.y"
    { yyval.tv_str = 0; }
    break;

  case 290:
#line 2215 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 291:
#line 2221 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 4303 "asn1p_y.c"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 2227 "asn1p_y.y"



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

int
yyerror(const char *msg) {
	extern char *asn1p_text;
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near line %d (token \"%s\"): %s\n",
		yylineno, asn1p_text, msg);
	return -1;
}


