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
#define YYLAST   820

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  100
/* YYNRULES -- Number of rules. */
#define YYNRULES  256
/* YYNRULES -- Number of states. */
#define YYNSTATES  396

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
     135,   137,   139,   146,   148,   150,   151,   153,   155,   159,
     161,   163,   168,   173,   177,   184,   186,   190,   192,   196,
     200,   202,   206,   208,   210,   212,   216,   220,   224,   226,
     228,   232,   235,   237,   243,   244,   246,   248,   252,   255,
     260,   265,   266,   268,   269,   276,   278,   281,   283,   285,
     287,   291,   295,   298,   300,   302,   307,   312,   317,   322,
     327,   329,   334,   339,   341,   345,   347,   351,   355,   357,
     361,   363,   367,   369,   371,   373,   375,   380,   381,   385,
     387,   389,   391,   393,   395,   397,   401,   403,   406,   408,
     410,   412,   414,   417,   420,   422,   424,   427,   430,   432,
     434,   436,   438,   441,   443,   446,   448,   450,   452,   454,
     456,   458,   460,   462,   464,   466,   468,   470,   472,   474,
     476,   478,   480,   482,   484,   485,   487,   489,   494,   498,
     503,   505,   509,   515,   517,   521,   525,   529,   534,   538,
     540,   544,   548,   552,   556,   558,   560,   562,   565,   568,
     572,   574,   576,   578,   580,   582,   584,   586,   592,   594,
     598,   600,   604,   605,   607,   609,   611,   613,   615,   617,
     621,   626,   628,   632,   635,   639,   641,   645,   646,   648,
     650,   653,   655,   657,   658,   662,   665,   669,   671,   675,
     677,   682,   687,   689,   691,   693,   695,   696,   698,   700,
     703,   706,   708,   710,   712,   714,   716
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     116,     0,    -1,   117,    -1,   118,    -1,   117,   118,    -1,
     211,   119,    34,   123,     3,    21,   126,    39,    -1,    -1,
     120,    -1,   104,   121,   105,    -1,   104,   105,    -1,   122,
      -1,   121,   122,    -1,   213,    -1,   213,   106,     9,   107,
      -1,     9,    -1,    -1,   124,    -1,   125,    -1,   124,   125,
      -1,    41,    84,    -1,    52,    84,    -1,    20,    84,    -1,
      43,    53,    -1,    12,    57,    -1,    -1,   127,    -1,   128,
      -1,   127,   128,    -1,   130,    -1,   135,    -1,   143,    -1,
     169,    -1,   138,    -1,    -1,    38,    12,   129,    -1,   177,
      -1,    54,   131,   108,    -1,    54,    46,    -1,   132,    -1,
     131,   132,    -1,   133,    46,   211,   119,    -1,   134,    -1,
     133,   109,   134,    -1,   211,    -1,   213,    -1,    42,   136,
     108,    -1,    42,    17,   108,    -1,    42,   108,    -1,   137,
      -1,   136,   109,   137,    -1,   211,    -1,   213,    -1,   211,
     139,     3,   104,   140,   105,    -1,   164,    -1,   174,    -1,
      -1,   141,    -1,   142,    -1,   141,   109,   142,    -1,   102,
      -1,   185,    -1,   211,     3,   209,    87,    -1,   211,     3,
     209,   162,    -1,   211,     3,   152,    -1,   211,   104,   144,
     105,     3,   162,    -1,   145,    -1,   144,   109,   145,    -1,
     211,    -1,   211,   110,   213,    -1,   174,   110,   213,    -1,
     147,    -1,   146,   109,   147,    -1,   162,    -1,   213,    -1,
     149,    -1,   148,   109,   149,    -1,   214,   162,   201,    -1,
      30,    68,   162,    -1,   161,    -1,   151,    -1,   150,   109,
     151,    -1,   214,   162,    -1,   161,    -1,    28,   104,   154,
     105,   156,    -1,    -1,    88,    -1,   155,    -1,   154,   109,
     155,    -1,   167,   201,    -1,   167,   162,   201,   153,    -1,
     167,   167,   201,   153,    -1,    -1,   157,    -1,    -1,    95,
      82,   104,   158,   159,   105,    -1,   160,    -1,   159,   160,
      -1,     4,    -1,   167,    -1,   102,    -1,   102,   111,   172,
      -1,   102,   111,   208,    -1,   163,   181,    -1,   176,    -1,
     177,    -1,    27,   104,   150,   105,    -1,    78,   104,   148,
     105,    -1,    79,   104,   148,   105,    -1,    78,   181,    68,
     163,    -1,    79,   181,    68,   163,    -1,    18,    -1,    18,
      35,    25,   213,    -1,   211,   104,   146,   105,    -1,   164,
      -1,    56,    68,   164,    -1,    11,    -1,    11,   112,   211,
      -1,    11,   112,   213,    -1,   212,    -1,   212,   112,   165,
      -1,   166,    -1,   165,   112,   166,    -1,   168,    -1,   168,
      -1,    13,    -1,    14,    -1,   213,   139,     3,   170,    -1,
      -1,   104,   171,   173,    -1,     5,    -1,     7,    -1,     6,
      -1,   208,    -1,   172,    -1,   213,    -1,   211,   112,   213,
      -1,     4,    -1,   173,     4,    -1,    24,    -1,    63,    -1,
      76,    -1,   175,    -1,    67,    81,    -1,    65,    51,    -1,
      77,    -1,    44,    -1,    36,    71,    -1,    26,    81,    -1,
      91,    -1,    47,    -1,    58,    -1,    40,    -1,    22,    81,
      -1,   174,    -1,   175,   205,    -1,    23,    -1,    48,    -1,
      49,    -1,    50,    -1,    59,    -1,    64,    -1,    74,    -1,
      83,    -1,    85,    -1,    90,    -1,    92,    -1,    93,    -1,
      94,    -1,    66,    -1,    99,    -1,   100,    -1,    97,    -1,
      98,    -1,    96,    -1,    -1,   182,    -1,   183,    -1,    80,
     106,   184,   107,    -1,   106,   184,   107,    -1,   183,   106,
     184,   107,    -1,   185,    -1,   185,   109,   102,    -1,   185,
     109,   102,   109,   185,    -1,   186,    -1,   185,   178,   186,
      -1,   185,   179,   186,    -1,   186,   180,   186,    -1,   188,
     106,   184,   107,    -1,   106,   184,   107,    -1,   189,    -1,
     189,   187,   189,    -1,    61,   187,   189,    -1,   189,   187,
      60,    -1,    61,   187,    60,    -1,   195,    -1,   190,    -1,
     101,    -1,   101,   113,    -1,   113,   101,    -1,   113,   101,
     113,    -1,    80,    -1,    46,    -1,   208,    -1,   213,    -1,
       6,    -1,    45,    -1,    86,    -1,    95,    30,   104,   191,
     105,    -1,   192,    -1,   191,   109,   192,    -1,   102,    -1,
     213,   181,   193,    -1,    -1,   194,    -1,    73,    -1,    15,
      -1,    69,    -1,   196,    -1,   197,    -1,   104,   211,   105,
      -1,   196,   104,   198,   105,    -1,   199,    -1,   198,   109,
     199,    -1,   114,   200,    -1,   114,   112,   200,    -1,   213,
      -1,   200,   112,   213,    -1,    -1,   202,    -1,    69,    -1,
      33,   203,    -1,   189,    -1,   174,    -1,    -1,   104,   204,
     173,    -1,   104,   105,    -1,   104,   206,   105,    -1,   207,
      -1,   206,   109,   207,    -1,   213,    -1,   213,   106,   208,
     107,    -1,   213,   106,   172,   107,    -1,   208,    -1,   102,
      -1,     9,    -1,    10,    -1,    -1,   210,    -1,   103,    -1,
     103,    52,    -1,   103,    41,    -1,    11,    -1,    12,    -1,
      12,    -1,     8,    -1,   213,    -1,   213,   210,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   300,   300,   306,   312,   328,   353,   355,   358,   362,
     367,   374,   382,   387,   391,   400,   402,   410,   414,   422,
     426,   429,   432,   436,   456,   458,   466,   470,   502,   506,
     515,   522,   535,   543,   542,   556,   569,   576,   581,   587,
     593,   602,   608,   614,   621,   629,   633,   636,   643,   649,
     655,   662,   671,   681,   689,   697,   699,   709,   712,   716,
     719,   731,   743,   750,   766,   775,   785,   795,   800,   807,
     817,   823,   829,   833,   845,   851,   857,   865,   872,   877,
     883,   889,   896,   901,   911,   913,   916,   924,   930,   939,
     945,   962,   964,   971,   969,   978,   983,   989,   993,  1004,
    1013,  1022,  1033,  1054,  1058,  1064,  1070,  1076,  1082,  1090,
    1098,  1104,  1118,  1142,  1149,  1163,  1172,  1182,  1192,  1200,
    1221,  1230,  1239,  1240,  1242,  1249,  1261,  1272,  1271,  1278,
    1282,  1286,  1290,  1293,  1298,  1310,  1326,  1337,  1351,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1369,  1371,  1372,  1375,  1382,  1394,  1396,  1400,  1404,  1405,
    1406,  1407,  1408,  1412,  1413,  1414,  1415,  1419,  1420,  1427,
    1427,  1428,  1428,  1429,  1431,  1433,  1438,  1442,  1451,  1455,
    1460,  1464,  1470,  1480,  1484,  1487,  1490,  1495,  1504,  1512,
    1518,  1525,  1533,  1541,  1550,  1553,  1558,  1560,  1561,  1562,
    1565,  1569,  1574,  1578,  1589,  1594,  1599,  1606,  1612,  1616,
    1621,  1627,  1639,  1641,  1644,  1648,  1651,  1656,  1660,  1668,
    1683,  1689,  1696,  1709,  1721,  1736,  1740,  1757,  1759,  1762,
    1766,  1772,  1775,  1777,  1777,  1797,  1802,  1807,  1813,  1819,
    1827,  1835,  1843,  1850,  1860,  1865,  1895,  1897,  1900,  1905,
    1909,  1915,  1920,  1927,  1934,  1941,  1946
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
  "ValueSetBody", "ValueSetElement", "DataTypeReference", 
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList", 
  "ActualParameter", "ComponentTypeLists", "ComponentType", 
  "AlternativeTypeLists", "AlternativeType", "ClassDeclaration", 
  "optUnique", "ClassFieldList", "ClassField", "optWithSyntax", 
  "WithSyntax", "@2", "WithSyntaxFormat", "WithSyntaxFormatToken", 
  "ExtensionAndException", "Type", "TypeDeclaration", 
  "ComplexTypeReference", "ComplexTypeReferenceAmpList", 
  "ComplexTypeReferenceElement", "ClassFieldIdentifier", "ClassFieldName", 
  "ValueDefinition", "InlineOrDefinedValue", "@3", "DefinedValue", 
  "Opaque", "BasicTypeId", "BasicTypeId_UniverationCompatible", 
  "BasicType", "BasicString", "Union", "Intersection", "Except", 
  "optConstraints", "Constraints", "SetOfConstraints", "ElementSetSpecs", 
  "ElementSetSpec", "ConstraintSubtypeElement", "ConstraintRangeSpec", 
  "ConstraintSpec", "ConstraintValue", "WithComponents", 
  "WithComponentsList", "WithComponentsElement", "optPresenceConstraint", 
  "PresenceConstraint", "TableConstraint", "SimpleTableConstraint", 
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
     137,   137,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   143,   143,   144,   144,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   149,   150,
     150,   151,   151,   152,   153,   153,   154,   154,   155,   155,
     155,   156,   156,   158,   157,   159,   159,   160,   160,   161,
     161,   161,   162,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   164,   164,   164,   164,
     165,   165,   166,   167,   168,   168,   169,   171,   170,   170,
     170,   170,   170,   170,   172,   172,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   178,
     178,   179,   179,   180,   181,   181,   182,   182,   183,   183,
     184,   184,   184,   185,   185,   185,   185,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   187,   187,   187,   187,
     188,   188,   189,   189,   189,   189,   189,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   194,   195,   195,   196,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   203,   205,   205,   206,   206,   207,
     207,   207,   207,   207,   208,   208,   209,   209,   210,   210,
     210,   211,   211,   212,   213,   214,   214
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     2,     1,     2,
       4,     1,     3,     1,     1,     3,     3,     2,     1,     3,
       1,     1,     6,     1,     1,     0,     1,     1,     3,     1,
       1,     4,     4,     3,     6,     1,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     3,     3,     3,     1,     1,
       3,     2,     1,     5,     0,     1,     1,     3,     2,     4,
       4,     0,     1,     0,     6,     1,     2,     1,     1,     1,
       3,     3,     2,     1,     1,     4,     4,     4,     4,     4,
       1,     4,     4,     1,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     4,     0,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     4,     3,     4,
       1,     3,     5,     1,     3,     3,     3,     4,     3,     1,
       3,     3,     3,     3,     1,     1,     1,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     1,     1,     0,     3,     2,     3,     1,     3,     1,
       4,     4,     1,     1,     1,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   251,   252,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   254,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    23,    21,    19,    22,    20,     0,    18,    13,    24,
     155,     0,     0,   156,   157,   158,     0,   159,   160,   168,
     161,   162,   163,   164,   165,   166,   167,     0,    25,    26,
      28,    29,    32,    30,    31,    35,     0,     0,    33,     0,
      47,     0,    48,    50,    51,    37,     0,    38,     0,    41,
      43,    44,     5,    27,   246,   115,   253,     0,   138,     0,
       0,   151,   145,   149,   150,   139,     0,     0,   140,   144,
     148,     0,     0,    53,    54,   141,   118,     0,    34,    46,
      45,     0,    36,    39,     0,     0,     0,   248,    63,     0,
     247,     0,   152,   147,   146,   143,   142,     0,    65,     0,
      67,     0,     0,     0,    49,     6,    42,     0,   250,   249,
     115,   253,   110,     0,     0,   174,   174,    61,    62,   174,
     113,   153,   141,   103,   104,     0,   116,   117,     0,     0,
       0,     0,    55,   124,   125,   119,   120,   122,   129,   131,
     130,   244,   245,   127,   126,   133,   132,     0,   134,    40,
       0,    86,   227,   123,     0,     0,     0,     0,     0,     0,
       0,   175,   176,     0,     0,   102,     0,   154,     0,     0,
      66,    69,    68,   204,   205,   201,     0,   200,   206,     0,
      59,     0,     0,     0,    56,    57,    60,   183,     0,   189,
     195,   194,   217,   218,   202,   203,     0,     0,     0,    91,
       0,     0,   229,   227,   227,    88,   228,     0,    99,     0,
      79,    82,   255,     0,   114,     0,     0,     0,    74,    78,
       0,     0,   180,     0,     0,     0,     0,   243,   235,     0,
     237,   242,   239,     0,    70,    72,    73,    64,   196,     0,
       0,     0,     0,     0,    52,     0,   171,   172,   169,   170,
       0,     0,   173,     0,     0,     0,     0,   121,   136,   128,
     135,     0,    83,    92,    87,   233,   232,   231,   230,    84,
      84,   111,     0,   105,     0,   256,    81,     0,     0,   106,
       0,   227,   178,     0,   108,     0,   107,   109,   236,     0,
       0,   112,     0,   197,   198,   193,   191,     0,   219,   188,
      58,   184,   185,   186,     0,   192,   190,     0,     0,   221,
     137,     0,     0,    85,    89,    90,   100,   101,    80,   177,
      77,    75,    76,   181,   179,   238,     0,     0,    71,   199,
     210,     0,   208,   174,   187,     0,   223,   225,   220,     0,
      93,   234,     0,   241,   240,   207,     0,   212,   224,     0,
     222,     0,   182,   209,   215,   216,   214,   211,   213,   226,
      97,     0,    95,    98,    94,    96
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    27,    28,
      29,    57,    58,    59,   108,    60,    76,    77,    78,    79,
      61,    71,    72,    62,   102,   213,   214,   215,    63,   127,
     128,   263,   264,   247,   248,   239,   240,   118,   344,   180,
     181,   292,   293,   381,   391,   392,   249,   265,   149,   150,
     165,   166,   182,   183,    64,   174,   227,   175,   289,   151,
     152,   153,   154,   280,   281,   283,   190,   191,   192,   251,
     252,   217,   270,   218,   219,   220,   361,   362,   387,   388,
     221,   222,   223,   338,   339,   366,   235,   236,   298,   342,
     197,   259,   260,   224,   119,   120,   155,   106,   225,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -255
static const short yypact[] =
{
      89,  -255,  -255,    64,    89,  -255,   -25,  -255,  -255,    33,
      79,  -255,  -255,  -255,  -255,    52,  -255,    -8,   180,  -255,
    -255,   147,    91,    77,    80,   119,    96,   183,   180,  -255,
     120,  -255,  -255,  -255,  -255,  -255,   177,  -255,  -255,   414,
    -255,   205,    28,  -255,  -255,  -255,   131,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,   196,   414,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,   182,   712,  -255,   142,
    -255,    32,  -255,  -255,  -255,  -255,    13,  -255,   -12,  -255,
    -255,  -255,  -255,  -255,     1,   141,  -255,   188,  -255,   206,
     201,  -255,  -255,  -255,  -255,  -255,   237,   208,  -255,  -255,
    -255,   729,   287,  -255,  -255,  -255,   185,   296,  -255,  -255,
    -255,   249,  -255,  -255,    89,   249,   210,    76,  -255,   575,
    -255,   249,  -255,  -255,  -255,  -255,  -255,    -2,  -255,   202,
     207,   211,   133,    78,  -255,   -25,  -255,   133,  -255,  -255,
     -41,   215,   274,   216,   254,   110,   127,  -255,  -255,   -28,
    -255,  -255,   223,  -255,  -255,   225,  -255,  -255,   327,   729,
     323,   323,   246,  -255,  -255,   221,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,   224,  -255,  -255,
      92,  -255,   498,  -255,   312,     6,   259,   232,    -3,    49,
     271,  -255,   234,    -3,   275,  -255,    60,  -255,   353,   652,
    -255,  -255,  -255,  -255,  -255,  -255,   -20,  -255,  -255,   315,
    -255,    89,    49,   241,   233,  -255,   144,   251,   245,   -20,
    -255,  -255,   250,  -255,  -255,  -255,   133,   349,   323,   260,
     133,   258,  -255,   -13,   -13,  -255,  -255,   323,   247,    94,
    -255,  -255,   256,   652,  -255,    49,   289,   104,  -255,  -255,
     652,   253,   139,   652,    49,   125,   652,  -255,  -255,   174,
    -255,  -255,   257,   176,  -255,  -255,  -255,  -255,   255,   265,
     160,   268,   264,   267,  -255,   246,  -255,  -255,  -255,  -255,
      49,    49,  -255,    49,    49,   165,   269,  -255,  -255,   369,
    -255,   299,  -255,  -255,  -255,  -255,  -255,  -255,  -255,   290,
     290,  -255,   266,  -255,     6,  -255,  -255,   277,   652,  -255,
      -3,   -13,  -255,   280,  -255,   278,  -255,  -255,  -255,    65,
     266,  -255,   353,  -255,   273,  -255,  -255,    20,  -255,  -255,
    -255,  -255,  -255,  -255,   281,  -255,  -255,    15,   191,  -255,
    -255,   283,   349,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,   282,  -255,  -255,   285,   288,  -255,  -255,
    -255,   199,  -255,   -28,  -255,   323,   284,  -255,  -255,   269,
    -255,   369,    49,  -255,  -255,  -255,    20,    23,   284,   323,
    -255,   146,   144,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,    18,  -255,  -255,  -255,  -255
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -255,  -255,  -255,   386,   263,  -255,  -255,   379,  -255,  -255,
     371,  -255,  -255,   346,  -255,  -255,  -255,   329,  -255,   291,
    -255,  -255,   297,  -255,   340,  -255,  -255,   135,  -255,  -255,
     262,  -255,    93,   220,   113,  -255,   124,  -255,   114,  -255,
     194,  -255,  -255,  -255,  -255,    42,  -172,  -117,  -209,   -55,
    -255,   209,  -179,  -106,  -255,  -255,  -255,  -254,    97,   -50,
     -48,  -255,    -4,  -255,  -255,  -255,  -139,  -255,  -255,   -96,
    -161,   -18,   222,  -255,  -140,  -255,  -255,    58,  -255,  -255,
    -255,  -255,  -255,  -255,    71,    83,  -157,  -255,  -255,  -255,
    -255,  -255,   123,  -124,  -255,   212,     4,  -255,    -9,  -170
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -253
static const short yytable[] =
{
      17,   216,   148,   234,     6,    12,    17,   194,     6,   176,
     195,   103,   103,   241,    12,   243,   104,   104,   105,   105,
     231,    12,   390,    12,     1,     2,   167,   246,    12,   116,
      67,   163,   164,    74,   114,    65,    12,    81,   384,     1,
       2,    12,    13,    66,   314,    69,    73,   317,   346,    67,
      80,   129,   187,   105,    65,   203,   232,    12,   171,   172,
      12,    13,    66,  -251,     7,   233,   356,    81,    12,   171,
     172,   121,   261,    12,   171,   172,   299,   300,   189,     9,
      80,   268,   267,   168,   169,   170,    12,   171,   172,     1,
       2,   297,   385,   269,   204,   205,   386,   115,    21,   238,
       1,     2,    74,   158,   117,   130,    81,   159,   238,   129,
     206,   105,   157,    18,   216,    73,   273,   138,   135,    80,
     167,   112,   360,   394,   178,   156,   306,   365,   139,   207,
     326,   244,   241,   311,   243,   208,    70,   177,    14,    12,
     110,   111,     1,     2,   209,   336,   163,   164,    31,   307,
     390,   201,   202,   211,   352,   212,    30,    19,   315,   163,
     164,    32,   257,   130,    33,   258,   203,   257,    12,   171,
     172,   203,    34,    12,   171,   172,   242,    75,   347,   242,
      35,   296,   173,   105,   242,    84,    36,   262,   334,   266,
     187,   350,    22,    85,    86,   261,   357,   229,    39,   303,
      23,   230,   393,   304,    87,   204,    88,   187,    89,   309,
     204,   382,   393,   310,   188,   272,   189,    68,    90,   290,
     325,    24,    91,    25,   377,   335,    92,    38,   301,    93,
     316,   193,    26,   189,   310,    82,   276,   277,   278,   279,
      94,   276,   277,   278,   279,    95,   208,    96,   313,    97,
     109,   208,   203,   121,    12,   171,   172,    12,    98,    99,
       1,     2,   331,   332,   203,   333,    12,   171,   172,   122,
      85,    86,   124,   100,    12,   171,   172,     1,     2,   318,
      87,   321,    88,   319,    89,   322,   101,   123,   125,   126,
     131,   204,   205,   178,    90,   242,   368,   132,    91,   133,
     369,   242,    92,   204,   375,    93,   177,   206,   376,   184,
     262,   178,   160,   266,   137,   162,    94,   161,   363,  -252,
     185,    95,   186,    96,   177,    97,   207,   196,   367,   198,
     199,    12,   208,   226,    98,    99,   228,   237,   245,   253,
     254,   209,   275,   256,   208,   271,   274,   282,   210,   100,
     211,   284,   212,   288,   286,   291,   367,   308,   302,   117,
     312,    12,   295,   320,   140,   141,   324,   363,   323,   328,
     389,   142,   327,   340,   329,    87,    40,    88,   343,    89,
     143,   341,   353,   337,   349,   354,   359,   370,   364,    90,
       8,   372,   373,    91,    20,   374,   379,    92,   179,    37,
      93,    43,    44,    45,    83,   113,   136,   107,   134,   144,
     330,    94,    47,   255,   345,   358,    95,    48,    96,    49,
      97,   200,    12,   351,   294,     1,     2,    50,   348,    98,
      99,   145,   146,   395,   383,   287,    51,    40,    52,   371,
     380,   285,   355,    53,   100,    54,    55,    56,   378,     0,
       0,     0,    41,     0,   305,     0,    42,     0,     0,     0,
       0,     0,    43,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,    47,     0,     0,     0,     0,    48,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,     0,     0,     0,    53,     0,    54,    55,    56,   140,
     141,   163,   164,     0,     0,     0,   142,     0,     0,     0,
      87,    40,    88,     0,    89,   143,     0,     0,     0,     0,
       0,   231,     0,     0,    90,     0,     0,     0,    91,     0,
       0,     0,    92,     0,     0,    93,    43,    44,    45,     0,
       0,     0,     0,     0,   144,     0,    94,    47,     0,     0,
       0,    95,    48,    96,    49,    97,     0,   232,     0,     0,
       0,     0,    50,     0,    98,    99,   145,   146,     0,     0,
       0,    51,     0,    52,     0,     0,   140,   141,    53,   100,
      54,    55,    56,   142,     0,     0,     0,    87,    40,    88,
       0,    89,   143,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,    91,     0,     0,     0,    92,
       0,     0,    93,    43,    44,    45,     0,     0,     0,     0,
       0,   144,     0,    94,    47,     0,     0,     0,    95,    48,
      96,    49,    97,     0,     0,     0,     0,     0,     0,    50,
       0,    98,    99,   145,   146,     0,     0,     0,    51,     0,
      52,     0,   147,   140,   141,    53,   100,    54,    55,    56,
     142,     0,     0,     0,    87,    40,    88,     0,    89,   143,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,    91,     0,     0,     0,    92,     0,     0,    93,
      43,    44,    45,     0,     0,     0,     0,     0,   144,     0,
      94,    47,     0,     0,     0,    95,    48,    96,    49,    97,
       0,     0,     0,    85,    86,     0,    50,     0,    98,    99,
     145,   146,     0,     0,    87,    51,    88,    52,    89,     0,
       1,     2,    53,   100,    54,    55,    56,     0,    90,     0,
       0,    87,    91,    88,     0,    89,    92,     0,     0,    93,
       0,     0,     0,     0,     0,    90,     0,     0,     0,    91,
      94,     0,     0,    92,     0,    95,    93,    96,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    94,    98,    99,
       0,     0,    95,     0,    96,     0,    97,     0,     0,     0,
       0,     0,     0,   100,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100
};

static const short yycheck[] =
{
       9,   162,   119,   182,     0,     8,    15,   146,     4,   133,
     149,    66,    67,   185,     8,   185,    66,    67,    66,    67,
      33,     8,     4,     8,    11,    12,   132,    30,     8,    28,
      39,    13,    14,    42,    46,    39,     8,    46,    15,    11,
      12,     8,     9,    39,   253,    17,    42,   256,   302,    58,
      46,   101,    80,   101,    58,     6,    69,     8,     9,    10,
       8,     9,    58,   104,     0,   182,   320,    76,     8,     9,
      10,   112,   196,     8,     9,    10,   233,   234,   106,   104,
      76,   101,   199,     5,     6,     7,     8,     9,    10,    11,
      12,   231,    69,   113,    45,    46,    73,   109,   106,   102,
      11,    12,   111,   105,   103,   101,   115,   109,   102,   159,
      61,   159,   121,    34,   275,   111,   212,    41,   114,   115,
     226,   108,   102,   105,   133,   121,   243,   112,    52,    80,
     270,   186,   304,   250,   304,    86,   108,   133,   105,     8,
     108,   109,    11,    12,    95,   285,    13,    14,    57,   245,
       4,   160,   161,   104,   311,   106,     9,   105,   254,    13,
      14,    84,   102,   159,    84,   105,     6,   102,     8,     9,
      10,     6,    53,     8,     9,    10,   185,    46,   302,   188,
      84,   231,   104,   231,   193,     3,     3,   196,   284,   198,
      80,   308,    12,    11,    12,   319,   320,   105,    21,   105,
      20,   109,   381,   109,    22,    45,    24,    80,    26,   105,
      45,   372,   391,   109,   104,   211,   106,    12,    36,   228,
      60,    41,    40,    43,   363,    60,    44,   107,   237,    47,
     105,   104,    52,   106,   109,    39,    97,    98,    99,   100,
      58,    97,    98,    99,   100,    63,    86,    65,   109,    67,
     108,    86,     6,   112,     8,     9,    10,     8,    76,    77,
      11,    12,   280,   281,     6,   283,     8,     9,    10,    81,
      11,    12,    71,    91,     8,     9,    10,    11,    12,   105,
      22,   105,    24,   109,    26,   109,   104,    81,    51,    81,
       3,    45,    46,   302,    36,   304,   105,   112,    40,     3,
     109,   310,    44,    45,   105,    47,   302,    61,   109,    35,
     319,   320,   110,   322,   104,   104,    58,   110,   327,   104,
     104,    63,    68,    65,   320,    67,    80,   104,   337,   104,
       3,     8,    86,   112,    76,    77,   112,    25,   106,    68,
     106,    95,   109,    68,    86,    30,   105,    96,   102,    91,
     104,   106,   106,     4,   104,    95,   365,    68,   111,   103,
     107,     8,   104,   106,    11,    12,   101,   376,   113,   105,
     379,    18,   104,     4,   107,    22,    23,    24,    88,    26,
      27,    82,   102,   114,   107,   107,   113,   104,   107,    36,
       4,   109,   107,    40,    15,   107,   112,    44,   135,    28,
      47,    48,    49,    50,    58,    76,   115,    67,   111,    56,
     275,    58,    59,   193,   300,   322,    63,    64,    65,    66,
      67,   159,     8,   310,   230,    11,    12,    74,   304,    76,
      77,    78,    79,   391,   376,   226,    83,    23,    85,   342,
     369,   219,   319,    90,    91,    92,    93,    94,   365,    -1,
      -1,    -1,    38,    -1,   242,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    85,    -1,    -1,    11,    12,    90,    91,
      92,    93,    94,    18,    -1,    -1,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      -1,    -1,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      85,    -1,    87,    11,    12,    90,    91,    92,    93,    94,
      18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    59,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    11,    12,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    22,    83,    24,    85,    26,    -1,
      11,    12,    90,    91,    92,    93,    94,    -1,    36,    -1,
      -1,    22,    40,    24,    -1,    26,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
      58,    -1,    -1,    44,    -1,    63,    47,    65,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    76,    77,
      -1,    -1,    63,    -1,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    11,    12,   116,   117,   118,   211,     0,   118,   104,
     119,   120,     8,     9,   105,   121,   122,   213,    34,   105,
     122,   106,    12,    20,    41,    43,    52,   123,   124,   125,
       9,    57,    84,    84,    53,    84,     3,   125,   107,    21,
      23,    38,    42,    48,    49,    50,    54,    59,    64,    66,
      74,    83,    85,    90,    92,    93,    94,   126,   127,   128,
     130,   135,   138,   143,   169,   177,   211,   213,    12,    17,
     108,   136,   137,   211,   213,    46,   131,   132,   133,   134,
     211,   213,    39,   128,     3,    11,    12,    22,    24,    26,
      36,    40,    44,    47,    58,    63,    65,    67,    76,    77,
      91,   104,   139,   164,   174,   175,   212,   139,   129,   108,
     108,   109,   108,   132,    46,   109,    28,   103,   152,   209,
     210,   112,    81,    81,    71,    51,    81,   144,   145,   174,
     211,     3,   112,     3,   137,   211,   134,   104,    41,    52,
      11,    12,    18,    27,    56,    78,    79,    87,   162,   163,
     164,   174,   175,   176,   177,   211,   211,   213,   105,   109,
     110,   110,   104,    13,    14,   165,   166,   168,     5,     6,
       7,     9,    10,   104,   170,   172,   208,   211,   213,   119,
     154,   155,   167,   168,    35,   104,    68,    80,   104,   106,
     181,   182,   183,   104,   181,   181,   104,   205,   104,     3,
     145,   213,   213,     6,    45,    46,    61,    80,    86,    95,
     102,   104,   106,   140,   141,   142,   185,   186,   188,   189,
     190,   195,   196,   197,   208,   213,   112,   171,   112,   105,
     109,    33,    69,   162,   167,   201,   202,    25,   102,   150,
     151,   161,   213,   214,   164,   106,    30,   148,   149,   161,
     214,   184,   185,    68,   106,   148,    68,   102,   105,   206,
     207,   208,   213,   146,   147,   162,   213,   162,   101,   113,
     187,    30,   211,   184,   105,   109,    97,    98,    99,   100,
     178,   179,    96,   180,   106,   187,   104,   166,     4,   173,
     213,    95,   156,   157,   155,   104,   174,   189,   203,   201,
     201,   213,   111,   105,   109,   210,   162,   184,    68,   105,
     109,   162,   107,   109,   163,   184,   105,   163,   105,   109,
     106,   105,   109,   113,   101,    60,   189,   104,   105,   107,
     142,   186,   186,   186,   184,    60,   189,   114,   198,   199,
       4,    82,   204,    88,   153,   153,   172,   208,   151,   107,
     162,   149,   201,   102,   107,   207,   172,   208,   147,   113,
     102,   191,   192,   213,   107,   112,   200,   213,   105,   109,
     104,   173,   109,   107,   107,   105,   109,   181,   200,   112,
     199,   158,   185,   192,    15,    69,    73,   193,   194,   213,
       4,   159,   160,   167,   105,   160
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
#line 301 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 307 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 312 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 333 "asn1p_y.y"
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
#line 354 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 7:
#line 355 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 8:
#line 359 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 9:
#line 362 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 10:
#line 368 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 11:
#line 374 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 383 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 13:
#line 387 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 14:
#line 391 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 15:
#line 401 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 16:
#line 402 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 17:
#line 411 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 414 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 423 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 426 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 429 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 432 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 436 "asn1p_y.y"
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
#line 457 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 25:
#line 458 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 26:
#line 467 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 27:
#line 470 "asn1p_y.y"
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
#line 503 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 29:
#line 506 "asn1p_y.y"
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
#line 515 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 522 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 535 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 33:
#line 543 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 544 "asn1p_y.y"
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
#line 556 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic type, "
			"use -ftypesXY to switch back "
			"to older version of ASN.1 standard");
	}
    break;

  case 36:
#line 570 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 37:
#line 576 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 38:
#line 582 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 39:
#line 587 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 40:
#line 594 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->from = yyvsp[-1].tv_str;
		yyval.a_xports->from_oid = yyvsp[0].a_oid;
		checkmem(yyval.a_xports);
	}
    break;

  case 41:
#line 603 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 42:
#line 608 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 43:
#line 615 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 44:
#line 621 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 45:
#line 630 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 46:
#line 633 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 47:
#line 636 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 48:
#line 644 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 49:
#line 649 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 50:
#line 656 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 51:
#line 662 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 52:
#line 672 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-4].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		// take care of optValueSetBody 
	}
    break;

  case 53:
#line 682 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 54:
#line 689 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 55:
#line 698 "asn1p_y.y"
    { }
    break;

  case 56:
#line 699 "asn1p_y.y"
    {
	}
    break;

  case 57:
#line 710 "asn1p_y.y"
    {
	}
    break;

  case 58:
#line 712 "asn1p_y.y"
    {
	}
    break;

  case 59:
#line 717 "asn1p_y.y"
    {
	}
    break;

  case 60:
#line 719 "asn1p_y.y"
    {
	}
    break;

  case 61:
#line 735 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		yyval.a_expr->expr_type = A1TC_TYPEID;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 62:
#line 743 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 63:
#line 750 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 64:
#line 766 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->params = yyvsp[-3].a_plist;
		yyval.a_expr->meta_type = AMT_PARAMTYPE;
	}
    break;

  case 65:
#line 776 "asn1p_y.y"
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
#line 785 "asn1p_y.y"
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
#line 796 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 68:
#line 800 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 69:
#line 807 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 70:
#line 818 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 71:
#line 823 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 72:
#line 830 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 73:
#line 833 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 74:
#line 846 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 75:
#line 851 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 76:
#line 858 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_nametag.name;
		yyval.a_expr->tag = yyvsp[-2].tv_nametag.tag;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 77:
#line 865 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 78:
#line 872 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 79:
#line 878 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 80:
#line 883 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 81:
#line 890 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_nametag.name;
		yyval.a_expr->tag = yyvsp[-1].tv_nametag.tag;
	}
    break;

  case 82:
#line 896 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 83:
#line 902 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 84:
#line 912 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 85:
#line 913 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 86:
#line 917 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECT;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 87:
#line 924 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 88:
#line 931 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].a_refcomp.name;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 89:
#line 939 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		yyval.a_expr->Identifier = yyvsp[-3].a_refcomp.name;
		yyval.a_expr->marker = yyvsp[-1].a_marker;
		yyval.a_expr->unique = yyvsp[0].a_int;
	}
    break;

  case 90:
#line 945 "asn1p_y.y"
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

  case 91:
#line 963 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 92:
#line 964 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 93:
#line 971 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 94:
#line 973 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 95:
#line 979 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 96:
#line 983 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 97:
#line 990 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
	}
    break;

  case 98:
#line 993 "asn1p_y.y"
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

  case 99:
#line 1005 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 100:
#line 1013 "asn1p_y.y"
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

  case 101:
#line 1022 "asn1p_y.y"
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

  case 102:
#line 1034 "asn1p_y.y"
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

  case 103:
#line 1055 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 104:
#line 1058 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 105:
#line 1064 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 106:
#line 1070 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 107:
#line 1076 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 108:
#line 1082 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 109:
#line 1090 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SET_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 110:
#line 1098 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 111:
#line 1104 "asn1p_y.y"
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

  case 112:
#line 1118 "asn1p_y.y"
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

  case 113:
#line 1142 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 114:
#line 1149 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 115:
#line 1164 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 116:
#line 1172 "asn1p_y.y"
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

  case 117:
#line 1182 "asn1p_y.y"
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

  case 118:
#line 1192 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 119:
#line 1200 "asn1p_y.y"
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

  case 120:
#line 1222 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 121:
#line 1230 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 124:
#line 1244 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 125:
#line 1249 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 126:
#line 1262 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 127:
#line 1272 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 128:
#line 1273 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 129:
#line 1278 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 130:
#line 1282 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 131:
#line 1286 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 132:
#line 1290 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 133:
#line 1293 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 134:
#line 1299 "asn1p_y.y"
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

  case 135:
#line 1310 "asn1p_y.y"
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

  case 136:
#line 1327 "asn1p_y.y"
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

  case 137:
#line 1337 "asn1p_y.y"
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

  case 138:
#line 1352 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 139:
#line 1353 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 140:
#line 1354 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 141:
#line 1355 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 142:
#line 1356 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 143:
#line 1357 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 144:
#line 1358 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 145:
#line 1359 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 146:
#line 1360 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 147:
#line 1361 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 148:
#line 1362 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 149:
#line 1363 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 150:
#line 1370 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 151:
#line 1371 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 152:
#line 1372 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 153:
#line 1376 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 154:
#line 1382 "asn1p_y.y"
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

  case 155:
#line 1395 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 156:
#line 1396 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported");
	}
    break;

  case 157:
#line 1400 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported");
	}
    break;

  case 158:
#line 1404 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 159:
#line 1405 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 160:
#line 1406 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 161:
#line 1407 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 162:
#line 1408 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported");
	}
    break;

  case 163:
#line 1412 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 164:
#line 1413 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 165:
#line 1414 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 166:
#line 1415 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported");
	}
    break;

  case 167:
#line 1419 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 168:
#line 1420 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 174:
#line 1432 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 175:
#line 1433 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 176:
#line 1439 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 177:
#line 1442 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 178:
#line 1452 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 179:
#line 1455 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 180:
#line 1461 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 181:
#line 1464 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 182:
#line 1470 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 183:
#line 1481 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 184:
#line 1484 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 185:
#line 1487 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 186:
#line 1490 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 187:
#line 1496 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 188:
#line 1504 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 189:
#line 1512 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 190:
#line 1518 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 191:
#line 1525 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 192:
#line 1533 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 193:
#line 1541 "asn1p_y.y"
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

  case 194:
#line 1550 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 195:
#line 1553 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 196:
#line 1559 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 197:
#line 1560 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 198:
#line 1561 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 199:
#line 1562 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 200:
#line 1566 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 201:
#line 1569 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 202:
#line 1575 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 203:
#line 1578 "asn1p_y.y"
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

  case 204:
#line 1589 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 205:
#line 1594 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 206:
#line 1599 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 207:
#line 1607 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 208:
#line 1613 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 209:
#line 1616 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 210:
#line 1622 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 211:
#line 1627 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
	}
    break;

  case 212:
#line 1640 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 213:
#line 1641 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 214:
#line 1645 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 215:
#line 1648 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 216:
#line 1651 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 217:
#line 1657 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 218:
#line 1660 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 219:
#line 1669 "asn1p_y.y"
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

  case 220:
#line 1684 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 221:
#line 1690 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 222:
#line 1696 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 223:
#line 1710 "asn1p_y.y"
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

  case 224:
#line 1721 "asn1p_y.y"
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

  case 225:
#line 1737 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 226:
#line 1740 "asn1p_y.y"
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

  case 227:
#line 1758 "asn1p_y.y"
    { yyval.a_marker = EM_NOMARK; }
    break;

  case 228:
#line 1759 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 229:
#line 1763 "asn1p_y.y"
    {
		yyval.a_marker = EM_OPTIONAL;
	}
    break;

  case 230:
#line 1766 "asn1p_y.y"
    {
		yyval.a_marker = EM_DEFAULT;
		/* FIXME: store DefaultValue somewhere */
	}
    break;

  case 231:
#line 1773 "asn1p_y.y"
    {
	}
    break;

  case 232:
#line 1775 "asn1p_y.y"
    {
	}
    break;

  case 233:
#line 1777 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 234:
#line 1777 "asn1p_y.y"
    {
	}
    break;

  case 235:
#line 1798 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
	}
    break;

  case 236:
#line 1802 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 237:
#line 1808 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 238:
#line 1813 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 239:
#line 1820 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 240:
#line 1827 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 241:
#line 1835 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 242:
#line 1843 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 243:
#line 1850 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 244:
#line 1861 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 245:
#line 1865 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 246:
#line 1896 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 247:
#line 1897 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 248:
#line 1901 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[0].a_tag;
		yyval.a_tag.tag_mode = TM_DEFAULT;
	}
    break;

  case 249:
#line 1905 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_IMPLICIT;
	}
    break;

  case 250:
#line 1909 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_EXPLICIT;
	}
    break;

  case 251:
#line 1916 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 252:
#line 1920 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 253:
#line 1928 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 254:
#line 1935 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 255:
#line 1942 "asn1p_y.y"
    {
		memset(&yyval.tv_nametag, 0, sizeof(yyval.tv_nametag));
		yyval.tv_nametag.name = yyvsp[0].tv_str;
	}
    break;

  case 256:
#line 1946 "asn1p_y.y"
    {
		yyval.tv_nametag.name = yyvsp[-1].tv_str;
		yyval.tv_nametag.tag = yyvsp[0].a_tag;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 3923 "asn1p_y.c"

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


#line 1953 "asn1p_y.y"



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
		yylineno, asn1p_text, msg);
	return -1;
}



