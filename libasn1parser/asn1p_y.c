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
     TOK_opaque = 259,
     TOK_bstring = 260,
     TOK_cstring = 261,
     TOK_hstring = 262,
     TOK_identifier = 263,
     TOK_number = 264,
     TOK_number_negative = 265,
     TOK_typereference = 266,
     TOK_capitalreference = 267,
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
     TOK_ENCODING_CONTROL = 293,
     TOK_END = 294,
     TOK_ENUMERATED = 295,
     TOK_EXPLICIT = 296,
     TOK_EXPORTS = 297,
     TOK_EXTENSIBILITY = 298,
     TOK_EXTERNAL = 299,
     TOK_FALSE = 300,
     TOK_FROM = 301,
     TOK_GeneralizedTime = 302,
     TOK_GeneralString = 303,
     TOK_GraphicString = 304,
     TOK_IA5String = 305,
     TOK_IDENTIFIER = 306,
     TOK_IMPLICIT = 307,
     TOK_IMPLIED = 308,
     TOK_IMPORTS = 309,
     TOK_INCLUDES = 310,
     TOK_INSTANCE = 311,
     TOK_INSTRUCTIONS = 312,
     TOK_INTEGER = 313,
     TOK_ISO646String = 314,
     TOK_MAX = 315,
     TOK_MIN = 316,
     TOK_MINUS_INFINITY = 317,
     TOK_NULL = 318,
     TOK_NumericString = 319,
     TOK_OBJECT = 320,
     TOK_ObjectDescriptor = 321,
     TOK_OCTET = 322,
     TOK_OF = 323,
     TOK_OPTIONAL = 324,
     TOK_PATTERN = 325,
     TOK_PDV = 326,
     TOK_PLUS_INFINITY = 327,
     TOK_PRESENT = 328,
     TOK_PrintableString = 329,
     TOK_PRIVATE = 330,
     TOK_REAL = 331,
     TOK_RELATIVE_OID = 332,
     TOK_SEQUENCE = 333,
     TOK_SET = 334,
     TOK_SIZE = 335,
     TOK_STRING = 336,
     TOK_SYNTAX = 337,
     TOK_T61String = 338,
     TOK_TAGS = 339,
     TOK_TeletexString = 340,
     TOK_TRUE = 341,
     TOK_TYPE_IDENTIFIER = 342,
     TOK_UNIQUE = 343,
     TOK_UNIVERSAL = 344,
     TOK_UniversalString = 345,
     TOK_UTCTime = 346,
     TOK_UTF8String = 347,
     TOK_VideotexString = 348,
     TOK_VisibleString = 349,
     TOK_WITH = 350,
     TOK_EXCEPT = 351,
     TOK_INTERSECTION = 352,
     TOK_UNION = 353,
     TOK_TwoDots = 354,
     TOK_ThreeDots = 355,
     TOK_tag = 356
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
#define TOK_capitalreference 267
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
#define TOK_ENCODING_CONTROL 293
#define TOK_END 294
#define TOK_ENUMERATED 295
#define TOK_EXPLICIT 296
#define TOK_EXPORTS 297
#define TOK_EXTENSIBILITY 298
#define TOK_EXTERNAL 299
#define TOK_FALSE 300
#define TOK_FROM 301
#define TOK_GeneralizedTime 302
#define TOK_GeneralString 303
#define TOK_GraphicString 304
#define TOK_IA5String 305
#define TOK_IDENTIFIER 306
#define TOK_IMPLICIT 307
#define TOK_IMPLIED 308
#define TOK_IMPORTS 309
#define TOK_INCLUDES 310
#define TOK_INSTANCE 311
#define TOK_INSTRUCTIONS 312
#define TOK_INTEGER 313
#define TOK_ISO646String 314
#define TOK_MAX 315
#define TOK_MIN 316
#define TOK_MINUS_INFINITY 317
#define TOK_NULL 318
#define TOK_NumericString 319
#define TOK_OBJECT 320
#define TOK_ObjectDescriptor 321
#define TOK_OCTET 322
#define TOK_OF 323
#define TOK_OPTIONAL 324
#define TOK_PATTERN 325
#define TOK_PDV 326
#define TOK_PLUS_INFINITY 327
#define TOK_PRESENT 328
#define TOK_PrintableString 329
#define TOK_PRIVATE 330
#define TOK_REAL 331
#define TOK_RELATIVE_OID 332
#define TOK_SEQUENCE 333
#define TOK_SET 334
#define TOK_SIZE 335
#define TOK_STRING 336
#define TOK_SYNTAX 337
#define TOK_T61String 338
#define TOK_TAGS 339
#define TOK_TeletexString 340
#define TOK_TRUE 341
#define TOK_TYPE_IDENTIFIER 342
#define TOK_UNIQUE 343
#define TOK_UNIVERSAL 344
#define TOK_UniversalString 345
#define TOK_UTCTime 346
#define TOK_UTF8String 347
#define TOK_VideotexString 348
#define TOK_VisibleString 349
#define TOK_WITH 350
#define TOK_EXCEPT 351
#define TOK_INTERSECTION 352
#define TOK_UNION 353
#define TOK_TwoDots 354
#define TOK_ThreeDots 355
#define TOK_tag 356




/* Copy the first part of user declarations.  */
#line 1 "asn1p_y.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

#define YYPARSE_PARAM	param
#define YYERROR_VERBOSE

int yylex(void);
int yyerror(const char *msg);
void asn1p_lexer_hack_push_opaque_state(void);
void asn1p_lexer_hack_enable_with_syntax(void);
void asn1p_lexer_hack_push_encoding_control(void);
#define	yylineno	asn1p_lineno
extern int asn1p_lineno;


static asn1p_value_t *
	_convert_bitstring2binary(char *str, int base);

#define	checkmem(ptr)	do {				\
		if(!(ptr))				\
		return yyerror("Memory failure");	\
	} while(0)

#define	CONSTRAINT_INSERT(root, constr_type, arg1, arg2) do {	\
		if(arg1->type != constr_type) {			\
			int __ret;				\
			root = asn1p_constraint_new(yylineno);	\
			checkmem(root);				\
			root->type = constr_type;		\
			__ret = asn1p_constraint_insert(root,	\
				arg1);				\
			checkmem(__ret == 0);			\
		} else {					\
			root = arg1;				\
		}						\
		if(arg2) {					\
			int __ret				\
			= asn1p_constraint_insert(root, arg2);	\
			checkmem(__ret == 0);			\
		}						\
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
#line 58 "asn1p_y.y"
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
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 368 "asn1p_y.c"
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
#line 389 "asn1p_y.c"

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
#define YYLAST   819

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  98
/* YYNRULES -- Number of rules. */
#define YYNRULES  252
/* YYNRULES -- Number of states. */
#define YYNSTATES  391

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,     2,     2,     2,     2,     2,     2,
     106,   107,     2,     2,   109,     2,   112,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   108,
     113,     2,     2,     2,   114,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    97,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   104,    99,   105,     2,     2,     2,     2,
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
      95,    96,    98,   100,   101,   102,   103
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
     103,   108,   110,   114,   116,   118,   122,   126,   129,   131,
     135,   137,   139,   146,   148,   150,   151,   153,   158,   163,
     167,   174,   176,   180,   182,   186,   190,   192,   196,   198,
     200,   202,   206,   210,   214,   216,   218,   222,   225,   227,
     233,   234,   236,   238,   242,   245,   250,   255,   256,   258,
     259,   266,   268,   271,   273,   275,   277,   281,   285,   288,
     290,   292,   297,   302,   307,   312,   317,   319,   324,   329,
     331,   335,   337,   341,   345,   347,   351,   353,   357,   359,
     361,   363,   365,   370,   371,   375,   377,   379,   381,   383,
     385,   387,   391,   393,   396,   398,   400,   402,   404,   407,
     410,   412,   414,   417,   420,   422,   424,   426,   428,   431,
     433,   436,   438,   440,   442,   444,   446,   448,   450,   452,
     454,   456,   458,   460,   462,   464,   466,   468,   470,   472,
     474,   475,   477,   479,   484,   488,   493,   495,   499,   505,
     507,   511,   515,   519,   524,   528,   530,   534,   538,   542,
     546,   548,   550,   552,   555,   558,   562,   564,   566,   568,
     570,   572,   574,   576,   582,   584,   588,   590,   594,   595,
     597,   599,   601,   603,   605,   607,   611,   616,   618,   622,
     625,   629,   631,   635,   636,   638,   640,   643,   645,   647,
     648,   652,   655,   659,   661,   665,   667,   672,   677,   679,
     681,   683,   685,   686,   688,   690,   693,   696,   698,   700,
     702,   704,   706
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     116,     0,    -1,   117,    -1,   118,    -1,   117,   118,    -1,
     209,   119,    34,   123,     3,    21,   126,    39,    -1,    -1,
     120,    -1,   104,   121,   105,    -1,   104,   105,    -1,   122,
      -1,   121,   122,    -1,   211,    -1,   211,   106,     9,   107,
      -1,     9,    -1,    -1,   124,    -1,   125,    -1,   124,   125,
      -1,    41,    84,    -1,    52,    84,    -1,    20,    84,    -1,
      43,    53,    -1,    12,    57,    -1,    -1,   127,    -1,   128,
      -1,   127,   128,    -1,   130,    -1,   135,    -1,   141,    -1,
     167,    -1,   138,    -1,    -1,    38,    12,   129,    -1,   175,
      -1,    54,   131,   108,    -1,    54,    46,    -1,   132,    -1,
     131,   132,    -1,   133,    46,   209,   119,    -1,   134,    -1,
     133,   109,   134,    -1,   209,    -1,   211,    -1,    42,   136,
     108,    -1,    42,    17,   108,    -1,    42,   108,    -1,   137,
      -1,   136,   109,   137,    -1,   209,    -1,   211,    -1,   209,
     139,     3,   104,   140,   105,    -1,   162,    -1,   172,    -1,
      -1,   182,    -1,   209,     3,   207,    87,    -1,   209,     3,
     207,   160,    -1,   209,     3,   150,    -1,   209,   104,   142,
     105,     3,   160,    -1,   143,    -1,   142,   109,   143,    -1,
     209,    -1,   209,   110,   211,    -1,   172,   110,   211,    -1,
     145,    -1,   144,   109,   145,    -1,   160,    -1,   211,    -1,
     147,    -1,   146,   109,   147,    -1,   212,   160,   199,    -1,
      30,    68,   160,    -1,   159,    -1,   149,    -1,   148,   109,
     149,    -1,   212,   160,    -1,   159,    -1,    28,   104,   152,
     105,   154,    -1,    -1,    88,    -1,   153,    -1,   152,   109,
     153,    -1,   165,   199,    -1,   165,   160,   199,   151,    -1,
     165,   165,   199,   151,    -1,    -1,   155,    -1,    -1,    95,
      82,   104,   156,   157,   105,    -1,   158,    -1,   157,   158,
      -1,     4,    -1,   165,    -1,   102,    -1,   102,   111,   170,
      -1,   102,   111,   206,    -1,   161,   179,    -1,   174,    -1,
     175,    -1,    27,   104,   148,   105,    -1,    78,   104,   146,
     105,    -1,    79,   104,   146,   105,    -1,    78,   179,    68,
     161,    -1,    79,   179,    68,   161,    -1,    18,    -1,    18,
      35,    25,   211,    -1,   209,   104,   144,   105,    -1,   162,
      -1,    56,    68,   162,    -1,    11,    -1,    11,   112,   209,
      -1,    11,   112,   211,    -1,   210,    -1,   210,   112,   163,
      -1,   164,    -1,   163,   112,   164,    -1,   166,    -1,   166,
      -1,    13,    -1,    14,    -1,   211,   139,     3,   168,    -1,
      -1,   104,   169,   171,    -1,     5,    -1,     7,    -1,     6,
      -1,   206,    -1,   170,    -1,   211,    -1,   209,   112,   211,
      -1,     4,    -1,   171,     4,    -1,    24,    -1,    63,    -1,
      76,    -1,   173,    -1,    67,    81,    -1,    65,    51,    -1,
      77,    -1,    44,    -1,    36,    71,    -1,    26,    81,    -1,
      91,    -1,    47,    -1,    58,    -1,    40,    -1,    22,    81,
      -1,   172,    -1,   173,   203,    -1,    23,    -1,    48,    -1,
      49,    -1,    50,    -1,    59,    -1,    64,    -1,    74,    -1,
      83,    -1,    85,    -1,    90,    -1,    92,    -1,    93,    -1,
      94,    -1,    66,    -1,    99,    -1,   100,    -1,    97,    -1,
      98,    -1,    96,    -1,    -1,   180,    -1,   181,    -1,    80,
     106,   182,   107,    -1,   106,   182,   107,    -1,   181,   106,
     182,   107,    -1,   183,    -1,   183,   109,   102,    -1,   183,
     109,   102,   109,   183,    -1,   184,    -1,   183,   176,   184,
      -1,   183,   177,   184,    -1,   184,   178,   184,    -1,   186,
     106,   182,   107,    -1,   106,   182,   107,    -1,   187,    -1,
     187,   185,   187,    -1,    61,   185,   187,    -1,   187,   185,
      60,    -1,    61,   185,    60,    -1,   193,    -1,   188,    -1,
     101,    -1,   101,   113,    -1,   113,   101,    -1,   113,   101,
     113,    -1,    80,    -1,    46,    -1,   206,    -1,   211,    -1,
       6,    -1,    45,    -1,    86,    -1,    95,    30,   104,   189,
     105,    -1,   190,    -1,   189,   109,   190,    -1,   102,    -1,
     211,   179,   191,    -1,    -1,   192,    -1,    73,    -1,    15,
      -1,    69,    -1,   194,    -1,   195,    -1,   104,   209,   105,
      -1,   194,   104,   196,   105,    -1,   197,    -1,   196,   109,
     197,    -1,   114,   198,    -1,   114,   112,   198,    -1,   211,
      -1,   198,   112,   211,    -1,    -1,   200,    -1,    69,    -1,
      33,   201,    -1,   187,    -1,   172,    -1,    -1,   104,   202,
     171,    -1,   104,   105,    -1,   104,   204,   105,    -1,   205,
      -1,   204,   109,   205,    -1,   211,    -1,   211,   106,   206,
     107,    -1,   211,   106,   170,   107,    -1,   206,    -1,   102,
      -1,     9,    -1,    10,    -1,    -1,   208,    -1,   103,    -1,
     103,    52,    -1,   103,    41,    -1,    11,    -1,    12,    -1,
      12,    -1,     8,    -1,   211,    -1,   211,   208,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   298,   298,   304,   310,   326,   351,   353,   356,   360,
     365,   372,   380,   385,   389,   398,   400,   408,   412,   420,
     424,   427,   430,   434,   454,   456,   464,   468,   500,   504,
     513,   520,   533,   541,   540,   554,   567,   574,   579,   585,
     591,   600,   606,   612,   619,   627,   631,   634,   641,   647,
     653,   660,   669,   679,   687,   695,   697,   709,   721,   728,
     744,   753,   763,   773,   778,   785,   795,   801,   807,   811,
     823,   829,   835,   843,   850,   855,   861,   867,   874,   879,
     889,   891,   894,   902,   908,   917,   923,   940,   942,   949,
     947,   956,   961,   967,   971,   982,   991,  1000,  1011,  1032,
    1036,  1042,  1048,  1054,  1060,  1068,  1076,  1082,  1096,  1120,
    1127,  1141,  1150,  1160,  1170,  1178,  1199,  1208,  1217,  1218,
    1220,  1227,  1239,  1250,  1249,  1256,  1260,  1264,  1268,  1271,
    1276,  1288,  1304,  1315,  1329,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1347,  1349,  1350,  1353,
    1360,  1372,  1374,  1378,  1382,  1383,  1384,  1385,  1386,  1390,
    1391,  1392,  1393,  1397,  1398,  1405,  1405,  1406,  1406,  1407,
    1409,  1411,  1416,  1420,  1429,  1433,  1438,  1442,  1448,  1458,
    1462,  1465,  1468,  1473,  1482,  1490,  1496,  1503,  1511,  1519,
    1528,  1531,  1536,  1538,  1539,  1540,  1543,  1547,  1552,  1556,
    1567,  1572,  1577,  1584,  1590,  1594,  1599,  1605,  1617,  1619,
    1622,  1626,  1629,  1634,  1638,  1646,  1661,  1667,  1674,  1687,
    1699,  1714,  1718,  1735,  1737,  1740,  1744,  1750,  1753,  1755,
    1755,  1775,  1780,  1785,  1791,  1797,  1805,  1813,  1821,  1828,
    1838,  1843,  1873,  1875,  1878,  1883,  1887,  1893,  1898,  1905,
    1912,  1919,  1924
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_opaque", "TOK_bstring", 
  "TOK_cstring", "TOK_hstring", "TOK_identifier", "TOK_number", 
  "TOK_number_negative", "TOK_typereference", "TOK_capitalreference", 
  "TOK_typefieldreference", "TOK_valuefieldreference", "TOK_ABSENT", 
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
  "TOK_ThreeDots", "TOK_tag", "'{'", "'}'", "'('", "')'", "';'", "','", 
  "':'", "'!'", "'.'", "'<'", "'@'", "$accept", "ParsedGrammar", 
  "ModuleList", "ModuleSpecification", "optObjectIdentifier", 
  "ObjectIdentifier", "ObjectIdentifierBody", "ObjectIdentifierElement", 
  "optModuleSpecificationFlags", "ModuleSpecificationFlags", 
  "ModuleSpecificationFlag", "optModuleSpecificationBody", 
  "ModuleSpecificationBody", "ModuleSpecificationElement", "@1", 
  "ImportsDefinition", "ImportsBundleSet", "ImportsBundle", "ImportsList", 
  "ImportsElement", "ExportsDefinition", "ExportsBody", "ExportsElement", 
  "ValueSetDefinition", "DefinedTypeRef", "optValueSetBody", 
  "DataTypeReference", "ParameterArgumentList", "ParameterArgumentName", 
  "ActualParameterList", "ActualParameter", "ComponentTypeLists", 
  "ComponentType", "AlternativeTypeLists", "AlternativeType", 
  "ClassDeclaration", "optUnique", "ClassFieldList", "ClassField", 
  "optWithSyntax", "WithSyntax", "@2", "WithSyntaxFormat", 
  "WithSyntaxFormatToken", "ExtensionAndException", "Type", 
  "TypeDeclaration", "ComplexTypeReference", 
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement", 
  "ClassFieldIdentifier", "ClassFieldName", "ValueDefinition", 
  "InlineOrDefinedValue", "@3", "DefinedValue", "Opaque", "BasicTypeId", 
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString", 
  "Union", "Intersection", "Except", "optConstraints", "Constraints", 
  "SetOfConstraints", "ElementSetSpecs", "ElementSetSpec", 
  "ConstraintSubtypeElement", "ConstraintRangeSpec", "ConstraintSpec", 
  "ConstraintValue", "WithComponents", "WithComponentsList", 
  "WithComponentsElement", "optPresenceConstraint", "PresenceConstraint", 
  "TableConstraint", "SimpleTableConstraint", 
  "ComponentRelationConstraint", "AtNotationList", "AtNotationElement", 
  "ComponentIdList", "optMarker", "Marker", "DefaultValue", "@4", 
  "UniverationDefinition", "UniverationList", "UniverationElement", 
  "SignedNumber", "optTag", "Tag", "TypeRefName", "ObjectClassReference", 
  "Identifier", "TaggedIdentifier", 0
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
     345,   346,   347,   348,   349,   350,   351,    94,   352,   124,
     353,   354,   355,   356,   123,   125,    40,    41,    59,    44,
      58,    33,    46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   115,   116,   117,   117,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   128,   129,   128,   128,   130,   130,   131,   131,
     132,   133,   133,   134,   134,   135,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   140,   140,   141,   141,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   147,   148,   148,   149,   149,   150,
     151,   151,   152,   152,   153,   153,   153,   154,   154,   156,
     155,   157,   157,   158,   158,   159,   159,   159,   160,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   162,   162,   162,   162,   162,   163,   163,   164,   165,
     166,   166,   167,   169,   168,   168,   168,   168,   168,   168,
     170,   170,   171,   171,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   173,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   176,   176,   177,   177,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   182,   183,
     183,   183,   183,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   185,   185,   185,   185,   186,   186,   187,   187,
     187,   187,   187,   188,   189,   189,   190,   190,   191,   191,
     192,   192,   192,   193,   193,   194,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     201,   203,   203,   204,   204,   205,   205,   205,   205,   205,
     206,   206,   207,   207,   208,   208,   208,   209,   209,   210,
     211,   212,   212
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     2,     1,     2,
       4,     1,     3,     1,     1,     3,     3,     2,     1,     3,
       1,     1,     6,     1,     1,     0,     1,     4,     4,     3,
       6,     1,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     3,     3,     3,     1,     1,     3,     2,     1,     5,
       0,     1,     1,     3,     2,     4,     4,     0,     1,     0,
       6,     1,     2,     1,     1,     1,     3,     3,     2,     1,
       1,     4,     4,     4,     4,     4,     1,     4,     4,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     4,     0,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     4,     3,     4,     1,     3,     5,     1,
       3,     3,     3,     4,     3,     1,     3,     3,     3,     3,
       1,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     1,     1,     0,
       3,     2,     3,     1,     3,     1,     4,     4,     1,     1,
       1,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,   247,   248,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   250,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    23,    21,    19,    22,    20,     0,    18,    13,    24,
     151,     0,     0,   152,   153,   154,     0,   155,   156,   164,
     157,   158,   159,   160,   161,   162,   163,     0,    25,    26,
      28,    29,    32,    30,    31,    35,     0,     0,    33,     0,
      47,     0,    48,    50,    51,    37,     0,    38,     0,    41,
      43,    44,     5,    27,   242,   111,   249,     0,   134,     0,
       0,   147,   141,   145,   146,   135,     0,     0,   136,   140,
     144,     0,     0,    53,    54,   137,   114,     0,    34,    46,
      45,     0,    36,    39,     0,     0,     0,   244,    59,     0,
     243,     0,   148,   143,   142,   139,   138,     0,    61,     0,
      63,     0,     0,     0,    49,     6,    42,     0,   246,   245,
     111,   249,   106,     0,     0,   170,   170,    57,    58,   170,
     109,   149,   137,    99,   100,     0,   112,   113,     0,     0,
       0,     0,    55,   120,   121,   115,   116,   118,   125,   127,
     126,   240,   241,   123,   122,   129,   128,     0,   130,    40,
       0,    82,   223,   119,     0,     0,     0,     0,     0,     0,
       0,   171,   172,     0,     0,    98,     0,   150,     0,     0,
      62,    65,    64,   200,   201,   197,     0,   196,   202,     0,
       0,     0,     0,    56,   176,   179,     0,   185,   191,   190,
     213,   214,   198,   199,     0,     0,     0,    87,     0,     0,
     225,   223,   223,    84,   224,     0,    95,     0,    75,    78,
     251,     0,   110,     0,     0,     0,    70,    74,     0,     0,
       0,     0,     0,     0,   239,   231,     0,   233,   238,   235,
       0,    66,    68,    69,    60,   192,     0,     0,     0,     0,
       0,    52,   167,   168,   165,   166,     0,     0,     0,   169,
       0,     0,     0,     0,   117,   132,   124,   131,     0,    79,
      88,    83,   229,   228,   227,   226,    80,    80,   107,     0,
     101,     0,   252,    77,     0,     0,   102,     0,   223,   174,
     104,     0,   103,   105,   232,     0,     0,   108,     0,   193,
     194,   189,   187,     0,   215,   184,   177,   180,   181,   182,
       0,   188,   186,     0,     0,   217,   133,     0,     0,    81,
      85,    86,    96,    97,    76,   173,    73,    71,    72,   175,
     234,     0,     0,    67,   195,   206,     0,   204,   170,     0,
     183,     0,   219,   221,   216,     0,    89,   230,   237,   236,
     203,     0,   208,   178,   220,     0,   218,     0,   205,   211,
     212,   210,   207,   209,   222,    93,     0,    91,    94,    90,
      92
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    27,    28,
      29,    57,    58,    59,   108,    60,    76,    77,    78,    79,
      61,    71,    72,    62,   102,   212,    63,   127,   128,   260,
     261,   245,   246,   237,   238,   118,   340,   180,   181,   289,
     290,   377,   386,   387,   247,   262,   149,   150,   165,   166,
     182,   183,    64,   174,   225,   175,   286,   151,   152,   153,
     154,   277,   278,   280,   190,   191,   192,   213,   214,   215,
     267,   216,   217,   218,   356,   357,   382,   383,   219,   220,
     221,   334,   335,   362,   233,   234,   295,   338,   197,   256,
     257,   222,   119,   120,   155,   106,   223,   248
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -213
static const short yypact[] =
{
     121,  -213,  -213,    47,   121,  -213,   -44,  -213,  -213,    33,
      31,  -213,  -213,  -213,  -213,    36,  -213,   -18,    41,  -213,
    -213,    81,    97,    77,    91,    55,   146,   164,    41,  -213,
      19,  -213,  -213,  -213,  -213,  -213,   160,  -213,  -213,   413,
    -213,   185,    15,  -213,  -213,  -213,   131,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   161,   413,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,   187,   711,  -213,   107,
    -213,    65,  -213,  -213,  -213,  -213,    27,  -213,   -10,  -213,
    -213,  -213,  -213,  -213,     6,   129,  -213,   167,  -213,   170,
     199,  -213,  -213,  -213,  -213,  -213,   225,   196,  -213,  -213,
    -213,   728,   276,  -213,  -213,  -213,   168,   278,  -213,  -213,
    -213,   136,  -213,  -213,   121,   136,   178,    45,  -213,   574,
    -213,   136,  -213,  -213,  -213,  -213,  -213,    40,  -213,   173,
     176,   181,   226,    64,  -213,   -44,  -213,   226,  -213,  -213,
      24,   183,   253,   190,   221,    66,   132,  -213,  -213,   -58,
    -213,  -213,   191,  -213,  -213,   192,  -213,  -213,   290,   728,
     294,   294,   149,  -213,  -213,   193,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   200,  -213,  -213,
      51,  -213,   497,  -213,   279,    -6,   245,   202,     1,   149,
     242,  -213,   205,     1,   248,  -213,    48,  -213,   352,   651,
    -213,  -213,  -213,  -213,  -213,  -213,   -12,  -213,  -213,   288,
     121,   149,   214,  -213,   162,   227,   215,   -12,  -213,  -213,
     218,  -213,  -213,  -213,   226,   321,   294,   231,   226,   291,
    -213,    26,    26,  -213,  -213,   294,   217,    73,  -213,  -213,
     229,   651,  -213,   149,   261,    83,  -213,  -213,   651,   223,
     651,   149,   113,   651,  -213,  -213,   115,  -213,  -213,   228,
     116,  -213,  -213,  -213,  -213,   220,   236,   156,   235,   237,
     233,  -213,  -213,  -213,  -213,  -213,   239,   149,   149,  -213,
     149,   149,   198,   230,  -213,  -213,   339,  -213,   263,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,   258,   258,  -213,   257,
    -213,    -6,  -213,  -213,   240,   651,  -213,     1,    26,  -213,
    -213,   241,  -213,  -213,  -213,    69,   257,  -213,   352,  -213,
     238,  -213,  -213,    20,  -213,  -213,   244,  -213,  -213,  -213,
     243,  -213,  -213,     8,   123,  -213,  -213,   251,   321,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,   250,   252,  -213,  -213,  -213,   128,  -213,   -58,   149,
    -213,   294,   249,  -213,  -213,   230,  -213,   339,  -213,  -213,
    -213,    20,    25,   175,   249,   294,  -213,   189,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,    11,  -213,  -213,  -213,
    -213
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -213,  -213,  -213,   361,   234,  -213,  -213,   356,  -213,  -213,
     344,  -213,  -213,   315,  -213,  -213,  -213,   304,  -213,   266,
    -213,  -213,   272,  -213,   317,  -213,  -213,  -213,   232,  -213,
      67,   194,    79,  -213,    88,  -213,    93,  -213,   165,  -213,
    -213,  -213,  -213,    12,  -172,  -114,  -136,   -55,  -213,   179,
    -181,  -113,  -213,  -213,  -213,  -212,    56,   -49,   -46,  -213,
      42,  -213,  -213,  -213,  -139,  -213,  -213,  -160,    38,   -31,
     188,  -213,  -175,  -213,  -213,    35,  -213,  -213,  -213,  -213,
    -213,  -213,    39,    46,  -168,  -213,  -213,  -213,  -213,  -213,
      94,  -130,  -213,   172,     4,  -213,    -9,  -171
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -249
static const short yytable[] =
{
      17,   232,    12,   176,     6,   148,    17,   194,     6,    12,
     195,   103,   103,   239,   241,   385,    12,   104,   104,   167,
     105,   105,   187,    12,   163,   164,     1,     2,    12,   249,
      67,   244,    69,    74,   116,    12,   114,    81,     1,     2,
     379,    12,    13,    66,    12,    13,    73,     7,   189,    67,
      80,   270,   129,    22,   294,   105,    12,   171,   172,   229,
       9,    23,    66,   296,   297,    18,   258,    81,   231,   168,
     169,   170,    12,   171,   172,     1,     2,    12,   171,   172,
      80,    65,    24,   304,    25,   264,   138,   342,    21,   265,
      30,   311,   322,    26,   380,   230,   236,   139,   381,   115,
      65,   266,    74,   236,   351,   130,    81,   332,    34,   117,
     129,   167,   157,   105,   310,    73,   389,   313,   135,    80,
     361,   330,   355,    70,   178,   156,    38,   303,  -247,   239,
     241,   242,     1,     2,   308,   112,   121,   177,    14,    12,
     348,    19,     1,     2,    12,   158,   187,     1,     2,   159,
     254,   201,   202,   255,    31,   203,   227,    12,   171,   172,
     228,    32,   203,   130,    12,   171,   172,    36,   173,   343,
     188,   254,   189,   110,   111,    33,   240,    75,   300,   240,
     293,    39,   301,   105,   240,   258,   352,   259,   306,   263,
      84,   346,   307,   385,   204,   205,   388,    68,    85,    86,
      82,   204,   163,   164,   203,   388,    12,   171,   172,    87,
     206,    88,   187,    89,   269,   109,   321,   287,   312,   372,
     314,   317,   307,    90,   315,   318,   298,    91,   364,   207,
      35,    92,   365,   370,    93,   208,   193,   371,   189,   163,
     164,   121,   208,   204,   209,    94,   327,   328,   122,   329,
      95,   123,    96,   210,    97,   211,    85,    86,   331,   272,
     273,   274,   275,    98,    99,    12,   171,   172,     1,     2,
     124,   276,   272,   273,   274,   275,   125,   126,   100,   131,
     132,   133,   137,   160,   208,   162,   161,  -248,   184,   186,
     178,   101,   240,   199,   185,   196,   198,   203,   240,    12,
     171,   172,    12,   177,   235,   224,   259,   178,   243,   263,
     250,   251,   226,    87,   358,    88,   253,    89,   268,   271,
     177,   281,   283,   279,   363,   285,   288,    90,   299,   305,
     309,    91,   117,   319,   316,    92,   204,   320,    93,   323,
     325,   326,   324,   336,   333,   337,   339,   345,   349,    94,
     360,   354,   363,   359,    95,   366,    96,   368,    97,   369,
      12,   375,   358,   140,   141,     8,   384,    98,    99,   179,
     142,    20,    37,    83,    87,    40,    88,   208,    89,   143,
     113,   136,   100,   134,   107,   353,   347,   252,    90,   344,
     341,   200,    91,   291,   367,   292,    92,   373,   390,    93,
      43,    44,    45,   284,   376,   282,   378,   374,   144,   350,
      94,    47,   302,     0,     0,    95,    48,    96,    49,    97,
       0,    12,     0,     0,     1,     2,    50,     0,    98,    99,
     145,   146,     0,     0,     0,    51,    40,    52,     0,     0,
       0,     0,    53,   100,    54,    55,    56,     0,     0,     0,
       0,    41,     0,     0,     0,    42,     0,     0,     0,     0,
       0,    43,    44,    45,     0,     0,     0,    46,     0,     0,
       0,     0,    47,     0,     0,     0,     0,    48,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
       0,     0,     0,    53,     0,    54,    55,    56,   140,   141,
     163,   164,     0,     0,     0,   142,     0,     0,     0,    87,
      40,    88,     0,    89,   143,     0,     0,     0,     0,     0,
     229,     0,     0,    90,     0,     0,     0,    91,     0,     0,
       0,    92,     0,     0,    93,    43,    44,    45,     0,     0,
       0,     0,     0,   144,     0,    94,    47,     0,     0,     0,
      95,    48,    96,    49,    97,     0,   230,     0,     0,     0,
       0,    50,     0,    98,    99,   145,   146,     0,     0,     0,
      51,     0,    52,     0,     0,   140,   141,    53,   100,    54,
      55,    56,   142,     0,     0,     0,    87,    40,    88,     0,
      89,   143,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,    91,     0,     0,     0,    92,     0,
       0,    93,    43,    44,    45,     0,     0,     0,     0,     0,
     144,     0,    94,    47,     0,     0,     0,    95,    48,    96,
      49,    97,     0,     0,     0,     0,     0,     0,    50,     0,
      98,    99,   145,   146,     0,     0,     0,    51,     0,    52,
       0,   147,   140,   141,    53,   100,    54,    55,    56,   142,
       0,     0,     0,    87,    40,    88,     0,    89,   143,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,    91,     0,     0,     0,    92,     0,     0,    93,    43,
      44,    45,     0,     0,     0,     0,     0,   144,     0,    94,
      47,     0,     0,     0,    95,    48,    96,    49,    97,     0,
       0,     0,    85,    86,     0,    50,     0,    98,    99,   145,
     146,     0,     0,    87,    51,    88,    52,    89,     0,     1,
       2,    53,   100,    54,    55,    56,     0,    90,     0,     0,
      87,    91,    88,     0,    89,    92,     0,     0,    93,     0,
       0,     0,     0,     0,    90,     0,     0,     0,    91,    94,
       0,     0,    92,     0,    95,    93,    96,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    94,    98,    99,     0,
       0,    95,     0,    96,     0,    97,     0,     0,     0,     0,
       0,     0,   100,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100
};

static const short yycheck[] =
{
       9,   182,     8,   133,     0,   119,    15,   146,     4,     8,
     149,    66,    67,   185,   185,     4,     8,    66,    67,   132,
      66,    67,    80,     8,    13,    14,    11,    12,     8,   189,
      39,    30,    17,    42,    28,     8,    46,    46,    11,    12,
      15,     8,     9,    39,     8,     9,    42,     0,   106,    58,
      46,   211,   101,    12,   229,   101,     8,     9,    10,    33,
     104,    20,    58,   231,   232,    34,   196,    76,   182,     5,
       6,     7,     8,     9,    10,    11,    12,     8,     9,    10,
      76,    39,    41,   243,    43,   199,    41,   299,   106,   101,
       9,   251,   267,    52,    69,    69,   102,    52,    73,   109,
      58,   113,   111,   102,   316,   101,   115,   282,    53,   103,
     159,   224,   121,   159,   250,   111,   105,   253,   114,   115,
     112,   281,   102,   108,   133,   121,   107,   241,   104,   301,
     301,   186,    11,    12,   248,   108,   112,   133,   105,     8,
     308,   105,    11,    12,     8,   105,    80,    11,    12,   109,
     102,   160,   161,   105,    57,     6,   105,     8,     9,    10,
     109,    84,     6,   159,     8,     9,    10,     3,   104,   299,
     104,   102,   106,   108,   109,    84,   185,    46,   105,   188,
     229,    21,   109,   229,   193,   315,   316,   196,   105,   198,
       3,   305,   109,     4,    45,    46,   377,    12,    11,    12,
      39,    45,    13,    14,     6,   386,     8,     9,    10,    22,
      61,    24,    80,    26,   210,   108,    60,   226,   105,   358,
     105,   105,   109,    36,   109,   109,   235,    40,   105,    80,
      84,    44,   109,   105,    47,    86,   104,   109,   106,    13,
      14,   112,    86,    45,    95,    58,   277,   278,    81,   280,
      63,    81,    65,   104,    67,   106,    11,    12,    60,    97,
      98,    99,   100,    76,    77,     8,     9,    10,    11,    12,
      71,   109,    97,    98,    99,   100,    51,    81,    91,     3,
     112,     3,   104,   110,    86,   104,   110,   104,    35,    68,
     299,   104,   301,     3,   104,   104,   104,     6,   307,     8,
       9,    10,     8,   299,    25,   112,   315,   316,   106,   318,
      68,   106,   112,    22,   323,    24,    68,    26,    30,   105,
     316,   106,   104,    96,   333,     4,    95,    36,   111,    68,
     107,    40,   103,   113,   106,    44,    45,   101,    47,   104,
     107,   102,   105,     4,   114,    82,    88,   107,   107,    58,
     107,   113,   361,   109,    63,   104,    65,   107,    67,   107,
       8,   112,   371,    11,    12,     4,   375,    76,    77,   135,
      18,    15,    28,    58,    22,    23,    24,    86,    26,    27,
      76,   115,    91,   111,    67,   318,   307,   193,    36,   301,
     297,   159,    40,   228,   338,   104,    44,   359,   386,    47,
      48,    49,    50,   224,   365,   217,   371,   361,    56,   315,
      58,    59,   240,    -1,    -1,    63,    64,    65,    66,    67,
      -1,     8,    -1,    -1,    11,    12,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    -1,    83,    23,    85,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    11,    12,
      13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    -1,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      83,    -1,    85,    -1,    -1,    11,    12,    90,    91,    92,
      93,    94,    18,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,
      -1,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,
      -1,    87,    11,    12,    90,    91,    92,    93,    94,    18,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    -1,    -1,    -1,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    11,    12,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    -1,    22,    83,    24,    85,    26,    -1,    11,
      12,    90,    91,    92,    93,    94,    -1,    36,    -1,    -1,
      22,    40,    24,    -1,    26,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    58,
      -1,    -1,    44,    -1,    63,    47,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    76,    77,    -1,
      -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    11,    12,   116,   117,   118,   209,     0,   118,   104,
     119,   120,     8,     9,   105,   121,   122,   211,    34,   105,
     122,   106,    12,    20,    41,    43,    52,   123,   124,   125,
       9,    57,    84,    84,    53,    84,     3,   125,   107,    21,
      23,    38,    42,    48,    49,    50,    54,    59,    64,    66,
      74,    83,    85,    90,    92,    93,    94,   126,   127,   128,
     130,   135,   138,   141,   167,   175,   209,   211,    12,    17,
     108,   136,   137,   209,   211,    46,   131,   132,   133,   134,
     209,   211,    39,   128,     3,    11,    12,    22,    24,    26,
      36,    40,    44,    47,    58,    63,    65,    67,    76,    77,
      91,   104,   139,   162,   172,   173,   210,   139,   129,   108,
     108,   109,   108,   132,    46,   109,    28,   103,   150,   207,
     208,   112,    81,    81,    71,    51,    81,   142,   143,   172,
     209,     3,   112,     3,   137,   209,   134,   104,    41,    52,
      11,    12,    18,    27,    56,    78,    79,    87,   160,   161,
     162,   172,   173,   174,   175,   209,   209,   211,   105,   109,
     110,   110,   104,    13,    14,   163,   164,   166,     5,     6,
       7,     9,    10,   104,   168,   170,   206,   209,   211,   119,
     152,   153,   165,   166,    35,   104,    68,    80,   104,   106,
     179,   180,   181,   104,   179,   179,   104,   203,   104,     3,
     143,   211,   211,     6,    45,    46,    61,    80,    86,    95,
     104,   106,   140,   182,   183,   184,   186,   187,   188,   193,
     194,   195,   206,   211,   112,   169,   112,   105,   109,    33,
      69,   160,   165,   199,   200,    25,   102,   148,   149,   159,
     211,   212,   162,   106,    30,   146,   147,   159,   212,   182,
      68,   106,   146,    68,   102,   105,   204,   205,   206,   211,
     144,   145,   160,   211,   160,   101,   113,   185,    30,   209,
     182,   105,    97,    98,    99,   100,   109,   176,   177,    96,
     178,   106,   185,   104,   164,     4,   171,   211,    95,   154,
     155,   153,   104,   172,   187,   201,   199,   199,   211,   111,
     105,   109,   208,   160,   182,    68,   105,   109,   160,   107,
     161,   182,   105,   161,   105,   109,   106,   105,   109,   113,
     101,    60,   187,   104,   105,   107,   102,   184,   184,   184,
     182,    60,   187,   114,   196,   197,     4,    82,   202,    88,
     151,   151,   170,   206,   149,   107,   160,   147,   199,   107,
     205,   170,   206,   145,   113,   102,   189,   190,   211,   109,
     107,   112,   198,   211,   105,   109,   104,   171,   107,   107,
     105,   109,   179,   183,   198,   112,   197,   156,   190,    15,
      69,    73,   191,   192,   211,     4,   157,   158,   165,   105,
     158
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
#line 299 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 305 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 310 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 331 "asn1p_y.y"
    {

		if(yyvsp[-1].a_module) {
			yyval.a_module = yyvsp[-1].a_module;
		} else {
			/* There's a chance that a module is just plain empty */
			yyval.a_module = asn1p_module_new();
		}
		checkmem(yyval.a_module);

		yyval.a_module->Identifier = yyvsp[-7].tv_str;
		yyval.a_module->module_oid = yyvsp[-6].a_oid;
		yyval.a_module->module_flags = yyvsp[-4].a_module_flags;
	}
    break;

  case 6:
#line 352 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 7:
#line 353 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 8:
#line 357 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 9:
#line 360 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 10:
#line 366 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 11:
#line 372 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 381 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 13:
#line 385 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 14:
#line 389 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 15:
#line 399 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 16:
#line 400 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 17:
#line 409 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 412 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 421 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 424 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 427 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 430 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 434 "asn1p_y.y"
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
#line 455 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 25:
#line 456 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 26:
#line 465 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 27:
#line 468 "asn1p_y.y"
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
#line 501 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 29:
#line 504 "asn1p_y.y"
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
#line 513 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 520 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 533 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 33:
#line 541 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 542 "asn1p_y.y"
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
#line 554 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic type, "
			"use -ftypesXY to switch back "
			"to older version of ASN.1 standard");
	}
    break;

  case 36:
#line 568 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 37:
#line 574 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 38:
#line 580 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 39:
#line 585 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 40:
#line 592 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->from = yyvsp[-1].tv_str;
		yyval.a_xports->from_oid = yyvsp[0].a_oid;
		checkmem(yyval.a_xports);
	}
    break;

  case 41:
#line 601 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 42:
#line 606 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 43:
#line 613 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 44:
#line 619 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 45:
#line 628 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 46:
#line 631 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 47:
#line 634 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 48:
#line 642 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 49:
#line 647 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 50:
#line 654 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 51:
#line 660 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 52:
#line 670 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-4].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		// take care of optValueSetBody 
	}
    break;

  case 53:
#line 680 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 54:
#line 687 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 55:
#line 696 "asn1p_y.y"
    { }
    break;

  case 56:
#line 697 "asn1p_y.y"
    {
	}
    break;

  case 57:
#line 713 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		yyval.a_expr->expr_type = A1TC_TYPEID;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 58:
#line 721 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 59:
#line 728 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 60:
#line 744 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->params = yyvsp[-3].a_plist;
		yyval.a_expr->meta_type = AMT_PARAMTYPE;
	}
    break;

  case 61:
#line 754 "asn1p_y.y"
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

  case 62:
#line 763 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 63:
#line 774 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 64:
#line 778 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 65:
#line 785 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 66:
#line 796 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 67:
#line 801 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 68:
#line 808 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 69:
#line 811 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 70:
#line 824 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 71:
#line 829 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 72:
#line 836 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_nametag.name;
		yyval.a_expr->tag = yyvsp[-2].tv_nametag.tag;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 73:
#line 843 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 74:
#line 850 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 75:
#line 856 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 76:
#line 861 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 77:
#line 868 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_nametag.name;
		yyval.a_expr->tag = yyvsp[-1].tv_nametag.tag;
	}
    break;

  case 78:
#line 874 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 79:
#line 880 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 80:
#line 890 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 81:
#line 891 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 82:
#line 895 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECT;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 83:
#line 902 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 84:
#line 909 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].a_refcomp.name;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 85:
#line 917 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		yyval.a_expr->Identifier = yyvsp[-3].a_refcomp.name;
		yyval.a_expr->marker = yyvsp[-1].a_marker;
		yyval.a_expr->unique = yyvsp[0].a_int;
	}
    break;

  case 86:
#line 923 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-3].a_refcomp.name;
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		checkmem(yyval.a_expr->reference);
		ret = asn1p_ref_add_component(yyval.a_expr->reference,
				yyvsp[-2].a_refcomp.name, yyvsp[-2].a_refcomp.lex_type);
		checkmem(ret == 0);
		yyval.a_expr->expr_type = A1TC_CLASSFIELD;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->marker = yyvsp[-1].a_marker;
		yyval.a_expr->unique = yyvsp[0].a_int;
	}
    break;

  case 87:
#line 941 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 88:
#line 942 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 89:
#line 949 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 90:
#line 951 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 91:
#line 957 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 92:
#line 961 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 93:
#line 968 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
	}
    break;

  case 94:
#line 971 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		checkmem(ret == 0);
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromref(ref, 0);
	}
    break;

  case 95:
#line 983 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 96:
#line 991 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->value = yyvsp[0].a_value;
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 97:
#line 1000 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		yyval.a_expr->value = yyvsp[0].a_value;
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 98:
#line 1012 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
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
				assert(!yyvsp[0].a_constr);
			} else {
				yyval.a_expr->constraints = yyvsp[0].a_constr;
			}
		}
	}
    break;

  case 99:
#line 1033 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 100:
#line 1036 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 101:
#line 1042 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 102:
#line 1048 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 103:
#line 1054 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 104:
#line 1060 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 105:
#line 1068 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SET_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 106:
#line 1076 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 107:
#line 1082 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_expr->reference,
			yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 108:
#line 1096 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == 0);
		assert(yyval.a_expr->meta_type == 0);
		assert(yyval.a_expr->reference == 0);
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		checkmem(yyval.a_expr->reference);
		ret = asn1p_ref_add_component(yyval.a_expr->reference, yyvsp[-3].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[-3].tv_str);
		yyval.a_expr->expr_type = A1TC_PARAMETRIZED;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 109:
#line 1120 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 110:
#line 1127 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 111:
#line 1142 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 112:
#line 1150 "asn1p_y.y"
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

  case 113:
#line 1160 "asn1p_y.y"
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

  case 114:
#line 1170 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 115:
#line 1178 "asn1p_y.y"
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

  case 116:
#line 1200 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 117:
#line 1208 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 120:
#line 1222 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 121:
#line 1227 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 122:
#line 1240 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 123:
#line 1250 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 124:
#line 1251 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 125:
#line 1256 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 126:
#line 1260 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 127:
#line 1264 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 128:
#line 1268 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 129:
#line 1271 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 130:
#line 1277 "asn1p_y.y"
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

  case 131:
#line 1288 "asn1p_y.y"
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

  case 132:
#line 1305 "asn1p_y.y"
    {
		yyval.tv_opaque.len = yyvsp[0].tv_opaque.len + 2;
		yyval.tv_opaque.buf = malloc(yyval.tv_opaque.len + 1);
		checkmem(yyval.tv_opaque.buf);
		yyval.tv_opaque.buf[0] = '{';
		yyval.tv_opaque.buf[1] = ' ';
		memcpy(yyval.tv_opaque.buf + 2, yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len);
		yyval.tv_opaque.buf[yyval.tv_opaque.len] = '\0';
		free(yyvsp[0].tv_opaque.buf);
	}
    break;

  case 133:
#line 1315 "asn1p_y.y"
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

  case 134:
#line 1330 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 135:
#line 1331 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 136:
#line 1332 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 137:
#line 1333 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 138:
#line 1334 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 139:
#line 1335 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 140:
#line 1336 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 141:
#line 1337 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 142:
#line 1338 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 143:
#line 1339 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 144:
#line 1340 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 145:
#line 1341 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 146:
#line 1348 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 147:
#line 1349 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 148:
#line 1350 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 149:
#line 1354 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 150:
#line 1360 "asn1p_y.y"
    {
		if(yyvsp[0].a_expr) {
			yyval.a_expr = yyvsp[0].a_expr;
		} else {
			yyval.a_expr = asn1p_expr_new(asn1p_lineno);
			checkmem(yyval.a_expr);
		}
		yyval.a_expr->expr_type = yyvsp[-1].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 151:
#line 1373 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 152:
#line 1374 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		return yyerror("GeneralString is not supported");
	}
    break;

  case 153:
#line 1378 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		return yyerror("GraphicString is not supported");
	}
    break;

  case 154:
#line 1382 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 155:
#line 1383 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 156:
#line 1384 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 157:
#line 1385 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 158:
#line 1386 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		return yyerror("T61String not implemented yet");
	}
    break;

  case 159:
#line 1390 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 160:
#line 1391 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 161:
#line 1392 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 162:
#line 1393 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		return yyerror("VideotexString is no longer supported");
	}
    break;

  case 163:
#line 1397 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 164:
#line 1398 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 170:
#line 1410 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 171:
#line 1411 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 172:
#line 1417 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 173:
#line 1420 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 174:
#line 1430 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 175:
#line 1433 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 176:
#line 1439 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 177:
#line 1442 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 178:
#line 1448 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 179:
#line 1459 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 180:
#line 1462 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 181:
#line 1465 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 182:
#line 1468 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 183:
#line 1474 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 184:
#line 1482 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 185:
#line 1490 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 186:
#line 1496 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 187:
#line 1503 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 188:
#line 1511 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 189:
#line 1519 "asn1p_y.y"
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

  case 190:
#line 1528 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 191:
#line 1531 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 192:
#line 1537 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 193:
#line 1538 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 194:
#line 1539 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 195:
#line 1540 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 196:
#line 1544 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 197:
#line 1547 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 198:
#line 1553 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 199:
#line 1556 "asn1p_y.y"
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

  case 200:
#line 1567 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 201:
#line 1572 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 202:
#line 1577 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 203:
#line 1585 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 204:
#line 1591 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 205:
#line 1594 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 206:
#line 1600 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 207:
#line 1605 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
	}
    break;

  case 208:
#line 1618 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 209:
#line 1619 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 210:
#line 1623 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 211:
#line 1626 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 212:
#line 1629 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 213:
#line 1635 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 214:
#line 1638 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 215:
#line 1647 "asn1p_y.y"
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

  case 216:
#line 1662 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 217:
#line 1668 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 218:
#line 1674 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 219:
#line 1688 "asn1p_y.y"
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

  case 220:
#line 1699 "asn1p_y.y"
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

  case 221:
#line 1715 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 222:
#line 1718 "asn1p_y.y"
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

  case 223:
#line 1736 "asn1p_y.y"
    { yyval.a_marker = EM_NOMARK; }
    break;

  case 224:
#line 1737 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 225:
#line 1741 "asn1p_y.y"
    {
		yyval.a_marker = EM_OPTIONAL;
	}
    break;

  case 226:
#line 1744 "asn1p_y.y"
    {
		yyval.a_marker = EM_DEFAULT;
		/* FIXME: store DefaultValue somewhere */
	}
    break;

  case 227:
#line 1751 "asn1p_y.y"
    {
	}
    break;

  case 228:
#line 1753 "asn1p_y.y"
    {
	}
    break;

  case 229:
#line 1755 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 230:
#line 1755 "asn1p_y.y"
    {
	}
    break;

  case 231:
#line 1776 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
	}
    break;

  case 232:
#line 1780 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 233:
#line 1786 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 234:
#line 1791 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 235:
#line 1798 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 236:
#line 1805 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 237:
#line 1813 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 238:
#line 1821 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 239:
#line 1828 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 240:
#line 1839 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 241:
#line 1843 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 242:
#line 1874 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 243:
#line 1875 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 244:
#line 1879 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[0].a_tag;
		yyval.a_tag.tag_mode = TM_DEFAULT;
	}
    break;

  case 245:
#line 1883 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_IMPLICIT;
	}
    break;

  case 246:
#line 1887 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_EXPLICIT;
	}
    break;

  case 247:
#line 1894 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 248:
#line 1898 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 249:
#line 1906 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 250:
#line 1913 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 251:
#line 1920 "asn1p_y.y"
    {
		memset(&yyval.tv_nametag, 0, sizeof(yyval.tv_nametag));
		yyval.tv_nametag.name = yyvsp[0].tv_str;
	}
    break;

  case 252:
#line 1924 "asn1p_y.y"
    {
		yyval.tv_nametag.name = yyvsp[-1].tv_str;
		yyval.tv_nametag.tag = yyvsp[0].a_tag;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 3896 "asn1p_y.c"

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


#line 1931 "asn1p_y.y"



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

extern char *asn1p_text;

int
yyerror(const char *msg) {
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near line %d (token \"%s\"): %s\n",
		asn1p_lineno, asn1p_text, msg);
	return -1;
}



