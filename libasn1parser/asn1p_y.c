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
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 363 "asn1p_y.c"
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
#line 384 "asn1p_y.c"

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
#define YYLAST   775

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  113
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  99
/* YYNRULES -- Number of rules. */
#define YYNRULES  248
/* YYNRULES -- Number of states. */
#define YYNSTATES  375

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   354

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   109,     2,     2,     2,     2,     2,     2,
     104,   105,     2,     2,   107,     2,   110,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   108,   106,
     111,     2,     2,     2,   112,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    96,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   102,    94,   103,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    95,
      97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    19,    20,    22,    26,
      29,    31,    34,    36,    41,    43,    44,    46,    48,    51,
      54,    57,    60,    63,    64,    66,    68,    71,    73,    75,
      77,    79,    81,    83,    87,    90,    92,    95,   100,   102,
     106,   108,   110,   114,   118,   121,   123,   127,   129,   131,
     138,   140,   142,   143,   145,   150,   155,   159,   166,   168,
     172,   174,   178,   182,   184,   188,   190,   192,   194,   198,
     204,   205,   207,   209,   213,   216,   220,   225,   226,   228,
     229,   236,   238,   241,   243,   245,   248,   250,   254,   256,
     260,   264,   266,   268,   270,   275,   277,   281,   283,   287,
     291,   293,   297,   299,   303,   305,   307,   309,   311,   316,
     317,   321,   323,   325,   327,   329,   331,   333,   337,   339,
     342,   344,   346,   348,   350,   353,   356,   358,   360,   363,
     366,   368,   370,   372,   374,   377,   379,   382,   384,   386,
     388,   390,   392,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   415,   420,   425,   430,   435,   437,   442,   443,
     445,   447,   449,   451,   453,   455,   460,   462,   465,   469,
     471,   475,   481,   483,   487,   489,   491,   495,   497,   501,
     503,   507,   509,   513,   518,   520,   522,   524,   527,   530,
     534,   536,   538,   540,   542,   544,   546,   548,   550,   552,
     558,   560,   564,   566,   570,   571,   573,   575,   577,   579,
     581,   583,   587,   592,   594,   598,   601,   605,   607,   611,
     612,   614,   616,   619,   621,   623,   624,   628,   631,   635,
     637,   641,   643,   648,   653,   655,   657,   659,   661,   662,
     664,   666,   669,   672,   674,   676,   678,   680,   682
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     114,     0,    -1,   115,    -1,   116,    -1,   115,   116,    -1,
     208,   117,    34,   121,     3,    21,   124,    38,    -1,    -1,
     118,    -1,   102,   119,   103,    -1,   102,   103,    -1,   120,
      -1,   119,   120,    -1,   210,    -1,   210,   104,     9,   105,
      -1,     9,    -1,    -1,   122,    -1,   123,    -1,   122,   123,
      -1,    40,    82,    -1,    51,    82,    -1,    20,    82,    -1,
      42,    52,    -1,    -1,   125,    -1,   126,    -1,   125,   126,
      -1,   127,    -1,   132,    -1,   138,    -1,   162,    -1,   135,
      -1,   170,    -1,    53,   128,   106,    -1,    53,    45,    -1,
     129,    -1,   128,   129,    -1,   130,    45,   208,   117,    -1,
     131,    -1,   130,   107,   131,    -1,   208,    -1,   210,    -1,
      41,   133,   106,    -1,    41,    17,   106,    -1,    41,   106,
      -1,   134,    -1,   133,   107,   134,    -1,   208,    -1,   210,
      -1,   208,   136,     3,   102,   137,   103,    -1,   157,    -1,
     167,    -1,    -1,   178,    -1,   208,     3,   206,    85,    -1,
     208,     3,   206,   154,    -1,   208,     3,   144,    -1,   208,
     102,   139,   103,     3,   154,    -1,   140,    -1,   139,   107,
     140,    -1,   208,    -1,   208,   108,   210,    -1,   167,   108,
     210,    -1,   142,    -1,   141,   107,   142,    -1,   156,    -1,
     210,    -1,   153,    -1,   143,   107,   153,    -1,    28,   102,
     146,   103,   148,    -1,    -1,    86,    -1,   147,    -1,   146,
     107,   147,    -1,   160,   198,    -1,   160,   154,   145,    -1,
     160,   160,   198,   145,    -1,    -1,   149,    -1,    -1,    93,
      80,   102,   150,   151,   103,    -1,   152,    -1,   151,   152,
      -1,     4,    -1,   160,    -1,   211,   154,    -1,   155,    -1,
     156,   172,   198,    -1,   100,    -1,   100,   109,   165,    -1,
     100,   109,   205,    -1,   169,    -1,   170,    -1,   171,    -1,
     208,   102,   141,   103,    -1,   157,    -1,    55,    66,   157,
      -1,    11,    -1,    11,   110,   208,    -1,    11,   110,   210,
      -1,   209,    -1,   209,   110,   158,    -1,   159,    -1,   158,
     110,   159,    -1,   161,    -1,   161,    -1,    13,    -1,    14,
      -1,   210,   136,     3,   163,    -1,    -1,   102,   164,   166,
      -1,     5,    -1,     7,    -1,     6,    -1,   205,    -1,   165,
      -1,   210,    -1,   208,   110,   210,    -1,     4,    -1,   166,
       4,    -1,    24,    -1,    61,    -1,    74,    -1,   168,    -1,
      65,    79,    -1,    63,    50,    -1,    75,    -1,    43,    -1,
      36,    69,    -1,    26,    79,    -1,    89,    -1,    46,    -1,
      56,    -1,    39,    -1,    22,    79,    -1,   167,    -1,   168,
     202,    -1,    23,    -1,    47,    -1,    48,    -1,    49,    -1,
      57,    -1,    62,    -1,    72,    -1,    81,    -1,    83,    -1,
      88,    -1,    90,    -1,    91,    -1,    92,    -1,    64,    -1,
      27,   102,   143,   103,    -1,    76,   102,   143,   103,    -1,
      77,   102,   143,   103,    -1,    76,   172,    66,   156,    -1,
      77,   172,    66,   156,    -1,    18,    -1,    18,    35,    25,
     210,    -1,    -1,   176,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,    98,    -1,    78,   104,   178,   105,    -1,
     177,    -1,   176,   177,    -1,   104,   178,   105,    -1,   179,
      -1,   179,   107,   100,    -1,   179,   107,   100,   107,   179,
      -1,   100,    -1,   100,   107,   179,    -1,   180,    -1,   181,
      -1,   180,   173,   181,    -1,   182,    -1,   181,   174,   182,
      -1,   183,    -1,   182,   175,   183,    -1,   186,    -1,   186,
     184,   186,    -1,   185,   104,   178,   105,    -1,   192,    -1,
     187,    -1,    99,    -1,    99,   111,    -1,   111,    99,    -1,
     111,    99,   111,    -1,    78,    -1,    45,    -1,   205,    -1,
     210,    -1,     6,    -1,    59,    -1,    58,    -1,    44,    -1,
      84,    -1,    93,    30,   102,   188,   103,    -1,   189,    -1,
     188,   107,   189,    -1,   100,    -1,   210,   172,   190,    -1,
      -1,   191,    -1,    71,    -1,    15,    -1,    67,    -1,   193,
      -1,   194,    -1,   102,   208,   103,    -1,   193,   102,   195,
     103,    -1,   196,    -1,   195,   107,   196,    -1,   112,   197,
      -1,   112,   110,   197,    -1,   210,    -1,   197,   110,   210,
      -1,    -1,   199,    -1,    67,    -1,    33,   200,    -1,   186,
      -1,   167,    -1,    -1,   102,   201,   166,    -1,   102,   103,
      -1,   102,   203,   103,    -1,   204,    -1,   203,   107,   204,
      -1,   210,    -1,   210,   104,   205,   105,    -1,   210,   104,
     165,   105,    -1,   205,    -1,   100,    -1,     9,    -1,    10,
      -1,    -1,   207,    -1,   101,    -1,   101,    51,    -1,   101,
      40,    -1,    11,    -1,    12,    -1,    12,    -1,     8,    -1,
     210,    -1,   210,   207,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   297,   297,   303,   309,   325,   350,   352,   355,   359,
     364,   371,   379,   384,   388,   397,   399,   407,   411,   419,
     423,   426,   429,   437,   439,   448,   452,   478,   482,   491,
     498,   511,   522,   535,   542,   547,   553,   559,   568,   574,
     580,   587,   595,   599,   602,   609,   615,   621,   628,   637,
     647,   655,   663,   665,   677,   689,   696,   712,   722,   732,
     742,   747,   754,   764,   770,   776,   780,   792,   798,   804,
     814,   816,   819,   827,   833,   842,   847,   864,   866,   873,
     871,   880,   885,   891,   895,   920,   927,   932,   940,   949,
     958,   969,   973,   979,   987,  1011,  1018,  1032,  1041,  1051,
    1061,  1069,  1090,  1099,  1108,  1109,  1111,  1118,  1130,  1141,
    1140,  1147,  1151,  1155,  1159,  1162,  1167,  1179,  1195,  1206,
    1220,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,
    1231,  1232,  1238,  1240,  1241,  1244,  1251,  1263,  1265,  1269,
    1273,  1274,  1275,  1276,  1277,  1281,  1282,  1283,  1284,  1288,
    1289,  1292,  1299,  1305,  1311,  1319,  1327,  1333,  1349,  1351,
    1354,  1354,  1355,  1355,  1356,  1358,  1371,  1374,  1379,  1385,
    1389,  1396,  1404,  1409,  1418,  1420,  1422,  1427,  1429,  1435,
    1437,  1442,  1449,  1456,  1464,  1467,  1472,  1474,  1475,  1476,
    1479,  1483,  1488,  1492,  1503,  1507,  1512,  1517,  1522,  1529,
    1535,  1539,  1544,  1550,  1562,  1564,  1567,  1571,  1574,  1579,
    1583,  1591,  1606,  1612,  1619,  1632,  1644,  1659,  1663,  1680,
    1682,  1685,  1689,  1695,  1698,  1700,  1700,  1720,  1725,  1730,
    1736,  1742,  1750,  1758,  1766,  1773,  1783,  1788,  1818,  1820,
    1823,  1828,  1832,  1838,  1843,  1849,  1856,  1863,  1868
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_opaque", "TOK_bstring", 
  "TOK_cstring", "TOK_hstring", "TOK_identifier", "TOK_number", 
  "TOK_number_negative", "TOK_typereference", "TOK_objectclassreference", 
  "TOK_typefieldreference", "TOK_valuefieldreference", "TOK_ABSENT", 
  "TOK_ABSTRACT_SYNTAX", "TOK_ALL", "TOK_ANY", "TOK_APPLICATION", 
  "TOK_AUTOMATIC", "TOK_BEGIN", "TOK_BIT", "TOK_BMPString", "TOK_BOOLEAN", 
  "TOK_BY", "TOK_CHARACTER", "TOK_CHOICE", "TOK_CLASS", "TOK_COMPONENT", 
  "TOK_COMPONENTS", "TOK_CONSTRAINED", "TOK_CONTAINING", "TOK_DEFAULT", 
  "TOK_DEFINITIONS", "TOK_DEFINED", "TOK_EMBEDDED", "TOK_ENCODED", 
  "TOK_END", "TOK_ENUMERATED", "TOK_EXPLICIT", "TOK_EXPORTS", 
  "TOK_EXTENSIBILITY", "TOK_EXTERNAL", "TOK_FALSE", "TOK_FROM", 
  "TOK_GeneralizedTime", "TOK_GeneralString", "TOK_GraphicString", 
  "TOK_IA5String", "TOK_IDENTIFIER", "TOK_IMPLICIT", "TOK_IMPLIED", 
  "TOK_IMPORTS", "TOK_INCLUDES", "TOK_INSTANCE", "TOK_INTEGER", 
  "TOK_ISO646String", "TOK_MAX", "TOK_MIN", "TOK_MINUS_INFINITY", 
  "TOK_NULL", "TOK_NumericString", "TOK_OBJECT", "TOK_ObjectDescriptor", 
  "TOK_OCTET", "TOK_OF", "TOK_OPTIONAL", "TOK_PATTERN", "TOK_PDV", 
  "TOK_PLUS_INFINITY", "TOK_PRESENT", "TOK_PrintableString", 
  "TOK_PRIVATE", "TOK_REAL", "TOK_RELATIVE_OID", "TOK_SEQUENCE", 
  "TOK_SET", "TOK_SIZE", "TOK_STRING", "TOK_SYNTAX", "TOK_T61String", 
  "TOK_TAGS", "TOK_TeletexString", "TOK_TRUE", "TOK_TYPE_IDENTIFIER", 
  "TOK_UNIQUE", "TOK_UNIVERSAL", "TOK_UniversalString", "TOK_UTCTime", 
  "TOK_UTF8String", "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH", 
  "'|'", "TOK_UNION", "'^'", "TOK_INTERSECTION", "TOK_EXCEPT", 
  "TOK_TwoDots", "TOK_ThreeDots", "TOK_tag", "'{'", "'}'", "'('", "')'", 
  "';'", "','", "':'", "'!'", "'.'", "'<'", "'@'", "$accept", 
  "ParsedGrammar", "ModuleList", "ModuleSpecification", 
  "optObjectIdentifier", "ObjectIdentifier", "ObjectIdentifierBody", 
  "ObjectIdentifierElement", "optModuleSpecificationFlags", 
  "ModuleSpecificationFlags", "ModuleSpecificationFlag", 
  "optModuleSpecificationBody", "ModuleSpecificationBody", 
  "ModuleSpecificationElement", "ImportsDefinition", "ImportsBundleSet", 
  "ImportsBundle", "ImportsList", "ImportsElement", "ExportsDefinition", 
  "ExportsBody", "ExportsElement", "ValueSetDefinition", "DefinedTypeRef", 
  "optValueSetBody", "DataTypeReference", "ParameterArgumentList", 
  "ParameterArgumentName", "ActualParameterList", "ActualParameter", 
  "ConstructedDataTypeDefinition", "ClassDeclaration", "optUnique", 
  "ClassFieldList", "ClassField", "optWithSyntax", "WithSyntax", "@1", 
  "WithSyntaxFormat", "WithSyntaxFormatToken", "DataTypeMember", 
  "ConstrainedTypeDeclaration", "ExtensionAndException", 
  "TypeDeclaration", "ComplexTypeReference", 
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement", 
  "ClassFieldIdentifier", "ClassFieldName", "ValueDefinition", 
  "InlineOrDefinedValue", "@2", "DefinedValue", "Opaque", "BasicTypeId", 
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString", 
  "ConstructedType", "optConstraints", "Union", "Intersection", "Except", 
  "Constraints", "SingleConstraint", "ConstraintElementSet", 
  "ConstraintElement", "ConstraintElementUnion", 
  "ConstraintElementIntersection", "ConstraintElementException", 
  "ConstraintSubtypeElement", "ConstraintRangeSpec", "ConstraintSpec", 
  "ConstraintValue", "WithComponents", "WithComponentsList", 
  "WithComponentsElement", "optPresenceConstraint", "PresenceConstraint", 
  "TableConstraint", "SimpleTableConstraint", 
  "ComponentRelationConstraint", "AtNotationList", "AtNotationElement", 
  "ComponentIdList", "optMarker", "Marker", "DefaultValue", "@3", 
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
     345,   346,   347,   348,   124,   349,    94,   350,   351,   352,
     353,   354,   123,   125,    40,    41,    59,    44,    58,    33,
      46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   113,   114,   115,   115,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   130,   130,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   139,   139,
     140,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   146,   146,   147,   147,   147,   148,   148,   150,
     149,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     155,   156,   156,   156,   156,   156,   156,   157,   157,   157,
     157,   157,   158,   158,   159,   160,   161,   161,   162,   164,
     163,   163,   163,   163,   163,   163,   165,   165,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   176,   176,   176,   177,   178,
     178,   178,   178,   178,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   183,   183,   183,   184,   184,   184,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   191,   192,
     192,   193,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   199,   199,   200,   200,   201,   200,   202,   202,   203,
     203,   204,   204,   204,   204,   204,   205,   205,   206,   206,
     207,   207,   207,   208,   208,   209,   210,   211,   211
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     2,     4,     1,     3,
       1,     1,     3,     3,     2,     1,     3,     1,     1,     6,
       1,     1,     0,     1,     4,     4,     3,     6,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     3,     5,
       0,     1,     1,     3,     2,     3,     4,     0,     1,     0,
       6,     1,     2,     1,     1,     2,     1,     3,     1,     3,
       3,     1,     1,     1,     4,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     1,     4,     0,     1,
       1,     1,     1,     1,     1,     4,     1,     2,     3,     1,
       3,     5,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     4,     1,     1,     1,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     1,     1,     0,     3,     2,     3,     1,
       3,     1,     4,     4,     1,     1,     1,     1,     0,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,   243,   244,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   246,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,    16,    17,     0,
      21,    19,    22,    20,     0,    18,    13,    23,   137,     0,
     138,   139,   140,     0,   141,   142,   150,   143,   144,   145,
     146,   147,   148,   149,     0,    24,    25,    27,    28,    31,
      29,    30,    32,     0,     0,     0,    44,     0,    45,    47,
      48,    34,     0,    35,     0,    38,    40,    41,     5,    26,
     238,    97,   245,     0,   120,     0,     0,   133,   127,   131,
     132,   121,     0,     0,   122,   126,   130,     0,     0,    50,
      51,   123,   100,     0,    43,    42,     0,    33,    36,     0,
       0,     0,   240,    56,     0,   239,     0,   134,   129,   128,
     125,   124,     0,    58,     0,    60,     0,     0,     0,    46,
       6,    39,     0,   242,   241,    97,   245,   156,     0,     0,
     158,   158,    54,    55,   158,    95,   135,   123,    91,    92,
      93,     0,    98,    99,     0,     0,     0,     0,    52,   106,
     107,   101,   102,   104,   111,   113,   112,   236,   237,   109,
     108,   115,   114,     0,   116,    37,     0,    72,   219,   105,
       0,     0,     0,     0,     0,     0,     0,   159,   166,     0,
       0,   219,     0,   136,     0,     0,    59,    62,    61,   194,
     197,   191,   196,   195,   190,   198,     0,   172,     0,     0,
      53,   169,   174,   175,   177,   179,     0,   181,   185,   184,
     209,   210,   192,   193,     0,     0,     0,    77,     0,     0,
     221,    70,   219,    74,   220,     0,    88,     0,    67,    86,
     247,     0,    96,     0,     0,     0,     0,   167,     0,     0,
      87,   235,   227,     0,   229,   234,   231,     0,    63,    65,
      66,    57,     0,     0,     0,    49,     0,   160,   161,     0,
     162,   163,     0,   164,     0,     0,   186,     0,     0,     0,
     103,   118,   110,   117,     0,    69,    78,    73,   225,   224,
     223,   222,    71,    75,    70,   157,     0,   151,     0,   248,
      85,     0,   152,   168,   154,   153,   155,   228,     0,     0,
      94,     0,     0,   173,   211,   170,   176,   178,   180,     0,
     187,   188,   182,     0,     0,   213,   119,     0,     0,    76,
      89,    90,    68,   165,   230,     0,     0,    64,   202,     0,
     200,   158,     0,   183,   189,     0,   215,   217,   212,     0,
      79,   226,   233,   232,   199,     0,   204,   171,   216,     0,
     214,     0,   201,   207,   208,   206,   203,   205,   218,    83,
       0,    81,    84,    80,    82
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    26,    27,
      28,    54,    55,    56,    57,    72,    73,    74,    75,    58,
      67,    68,    59,    98,   209,    60,   122,   123,   257,   258,
     237,   113,   293,   176,   177,   285,   286,   361,   370,   371,
     238,   143,   239,   144,   145,   161,   162,   178,   179,    61,
     170,   225,   171,   282,   146,   147,   148,   149,   150,   186,
     269,   272,   274,   187,   188,   210,   211,   212,   213,   214,
     215,   278,   216,   217,   218,   339,   340,   366,   367,   219,
     220,   221,   324,   325,   346,   233,   234,   291,   328,   193,
     253,   254,   222,   114,   115,   151,   102,   223,   241
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -206
static const short yypact[] =
{
     227,  -206,  -206,    27,   227,  -206,   -38,  -206,  -206,    13,
      52,  -206,  -206,  -206,  -206,    47,  -206,   -12,    42,  -206,
    -206,   106,    51,    76,   111,    83,   146,    42,  -206,    63,
    -206,  -206,  -206,  -206,   152,  -206,  -206,   380,  -206,    12,
    -206,  -206,  -206,    91,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   160,   380,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   131,   670,   107,  -206,   147,  -206,  -206,
    -206,  -206,    24,  -206,   -19,  -206,  -206,  -206,  -206,  -206,
      -3,   114,  -206,   150,  -206,   155,   174,  -206,  -206,  -206,
    -206,  -206,   201,   184,  -206,  -206,  -206,   686,   258,  -206,
    -206,  -206,   156,   265,  -206,  -206,   191,  -206,  -206,   227,
     191,   168,   101,  -206,   537,  -206,   191,  -206,  -206,  -206,
    -206,  -206,    75,  -206,   164,   166,   183,   242,    33,  -206,
     -38,  -206,   242,  -206,  -206,    44,   186,   249,   189,   220,
      -8,    36,  -206,  -206,   -13,  -206,  -206,   190,  -206,  -206,
    -206,   192,  -206,  -206,   290,   686,   293,   293,   238,  -206,
    -206,   188,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   194,  -206,  -206,    90,  -206,   462,  -206,
     280,    23,   246,   202,    23,   238,   243,   208,  -206,    23,
     244,    20,    59,  -206,   321,   612,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,   283,   210,   227,   212,
    -206,   211,   165,   182,   221,  -206,   217,   -40,  -206,  -206,
     222,  -206,  -206,  -206,   242,   319,   293,   234,   242,   206,
    -206,   248,    20,  -206,  -206,   293,   219,    97,  -206,  -206,
     229,   612,  -206,   238,   115,   230,   612,  -206,   118,   612,
    -206,  -206,  -206,   120,  -206,  -206,   233,   128,  -206,  -206,
    -206,  -206,   239,    67,   250,  -206,   252,  -206,  -206,    67,
    -206,  -206,    67,  -206,    67,   238,   231,   255,   267,   237,
    -206,  -206,   351,  -206,   276,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   248,  -206,   199,  -206,    23,  -206,
    -206,   253,  -206,  -206,  -206,  -206,  -206,  -206,    71,   199,
    -206,   321,    29,  -206,  -206,   254,   182,   221,  -206,   257,
    -206,   260,  -206,    -6,   133,  -206,  -206,   261,   319,  -206,
    -206,  -206,  -206,  -206,  -206,   268,   269,  -206,  -206,   134,
    -206,   -13,    67,  -206,  -206,   293,   256,  -206,  -206,   237,
    -206,   351,  -206,  -206,  -206,    29,    18,  -206,   256,   293,
    -206,   177,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
       3,  -206,  -206,  -206,  -206
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -206,  -206,  -206,   355,   235,  -206,  -206,   357,  -206,  -206,
     348,  -206,  -206,   324,  -206,  -206,   308,  -206,   271,  -206,
    -206,   281,  -206,   325,  -206,  -206,  -206,   245,  -206,    79,
     -28,  -206,   100,  -206,   171,  -206,  -206,  -206,  -206,    31,
     108,  -117,  -206,  -189,   -54,  -206,   181,  -175,  -115,  -206,
    -206,  -206,  -165,    80,   -50,   -45,  -206,    58,  -206,  -140,
    -206,  -206,  -206,  -206,   228,  -111,  -205,  -206,   138,   142,
     143,  -206,  -206,  -178,  -206,  -206,    61,  -206,  -206,  -206,
    -206,  -206,  -206,    69,    74,  -142,  -206,  -206,  -206,  -206,
    -206,   112,  -120,  -206,   185,    11,  -206,    -9,  -206
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -245
static const short yytable[] =
{
      17,   190,    12,   232,   191,   259,    17,   369,   172,    99,
      99,     6,   163,   100,   100,     6,   159,   160,   101,   101,
      12,    12,    13,     1,     2,   111,   109,     7,    64,    65,
      70,    12,    12,   363,    77,     1,     2,    12,   164,   165,
     166,    12,   167,   168,     1,     2,    64,   124,    63,   250,
      69,   290,   101,   229,    76,    12,    13,   304,   313,   276,
     306,   231,    22,    77,     9,   183,    63,    12,   167,   168,
     183,   277,   255,   199,   245,    12,   167,   168,   261,    12,
     167,   168,    23,    76,    24,   364,    18,   230,   110,   365,
     294,   185,    21,    25,   184,    62,   185,    70,   112,    12,
     322,    77,     1,     2,   345,   124,   373,   153,   125,   163,
     101,   200,   201,    62,   183,    29,    14,    69,    66,   174,
     130,    76,   259,   236,   300,   202,   203,   152,   242,   338,
     107,   330,   301,    30,    80,   169,    71,   357,   189,   173,
     185,   133,    81,    82,   335,   204,  -243,   197,   198,    34,
      19,   205,   134,    83,   116,    84,   244,    85,    31,   251,
     206,   248,   252,    32,   319,    33,   125,    86,    36,   208,
      87,   251,   240,    37,    88,   240,   331,    89,   154,   289,
     240,   369,   155,   256,   101,   260,   372,    90,   255,   336,
     159,   160,    91,   227,    92,   372,    93,   228,    78,    12,
     297,   356,     1,     2,   298,    94,    95,    12,   167,   168,
       1,     2,   199,   104,    12,   167,   168,   283,   302,   264,
      96,   305,   298,   307,   116,   298,   295,   308,    83,   117,
      84,   310,    85,    97,   118,   311,   348,   354,     1,     2,
     349,   355,    86,   119,   199,    87,    12,   167,   168,    88,
     200,   120,    89,   105,   106,   159,   160,    81,    82,   267,
     268,   126,    90,   121,   202,   203,   127,    91,   128,    92,
     132,    93,   156,   199,   157,    12,   167,   168,   270,   271,
      94,    95,   200,   201,   180,   158,   182,   174,  -244,   240,
     205,   181,   192,   195,   194,    96,   202,   203,   224,   256,
     174,    12,   260,   341,   226,   235,   243,   173,   288,   246,
     249,   200,   185,   262,   347,   265,   204,   263,   266,   273,
     173,   275,   205,   281,   279,   202,   203,   284,   296,    12,
     112,   206,   135,   136,   292,   303,   347,   309,   207,   137,
     208,   312,   320,    83,    38,    84,   341,    85,   138,   323,
     368,   205,   315,   314,   321,   326,   327,    86,   333,     8,
      87,   342,   343,   350,    88,   175,   359,    89,    40,    41,
      42,   344,    20,   352,   353,    35,   139,    90,    44,    79,
     108,   131,    91,    45,    92,    46,    93,   129,    12,   103,
     337,     1,     2,    47,   329,    94,    95,   140,   141,   287,
     196,   374,    48,    38,    49,   280,   332,   316,   351,    50,
      96,    51,    52,    53,   317,   247,   362,   318,   360,   358,
     334,    39,     0,     0,     0,   299,     0,    40,    41,    42,
       0,     0,     0,    43,     0,     0,     0,    44,     0,     0,
       0,     0,    45,     0,    46,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,     0,     0,     0,    50,     0,
      51,    52,    53,   135,   136,   159,   160,     0,     0,     0,
     137,     0,     0,     0,    83,    38,    84,     0,    85,   138,
       0,     0,     0,     0,     0,   229,     0,     0,    86,     0,
       0,    87,     0,     0,     0,    88,     0,     0,    89,    40,
      41,    42,     0,     0,     0,     0,     0,   139,    90,    44,
       0,     0,     0,    91,    45,    92,    46,    93,     0,   230,
       0,     0,     0,     0,    47,     0,    94,    95,   140,   141,
       0,     0,     0,    48,     0,    49,     0,     0,   135,   136,
      50,    96,    51,    52,    53,   137,     0,     0,     0,    83,
      38,    84,     0,    85,   138,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,     0,    87,     0,     0,     0,
      88,     0,     0,    89,    40,    41,    42,     0,     0,     0,
       0,     0,   139,    90,    44,     0,     0,     0,    91,    45,
      92,    46,    93,     0,     0,     0,     0,     0,     0,    47,
       0,    94,    95,   140,   141,     0,     0,     0,    48,     0,
      49,     0,   142,   135,   136,    50,    96,    51,    52,    53,
     137,     0,     0,     0,    83,    38,    84,     0,    85,   138,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    87,     0,     0,     0,    88,     0,     0,    89,    40,
      41,    42,     0,     0,     0,     0,     0,   139,    90,    44,
       0,     0,     0,    91,    45,    92,    46,    93,     0,     0,
       0,    81,    82,     0,    47,     0,    94,    95,   140,   141,
       0,     0,    83,    48,    84,    49,    85,     1,     2,     0,
      50,    96,    51,    52,    53,     0,    86,     0,    83,    87,
      84,     0,    85,    88,     0,     0,    89,     0,     0,     0,
       0,     0,    86,     0,     0,    87,    90,     0,     0,    88,
       0,    91,    89,    92,     0,    93,     0,     0,     0,     0,
       0,     0,    90,     0,    94,    95,     0,    91,     0,    92,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96
};

static const short yycheck[] =
{
       9,   141,     8,   178,   144,   194,    15,     4,   128,    63,
      64,     0,   127,    63,    64,     4,    13,    14,    63,    64,
       8,     8,     9,    11,    12,    28,    45,     0,    37,    17,
      39,     8,     8,    15,    43,    11,    12,     8,     5,     6,
       7,     8,     9,    10,    11,    12,    55,    97,    37,   191,
      39,   229,    97,    33,    43,     8,     9,   246,   263,    99,
     249,   178,    20,    72,   102,    78,    55,     8,     9,    10,
      78,   111,   192,     6,   185,     8,     9,    10,   195,     8,
       9,    10,    40,    72,    42,    67,    34,    67,   107,    71,
     232,   104,   104,    51,   102,    37,   104,   106,   101,     8,
     278,   110,    11,    12,   110,   155,   103,   116,    97,   224,
     155,    44,    45,    55,    78,     9,   103,   106,   106,   128,
     109,   110,   311,   100,   241,    58,    59,   116,   182,   100,
     106,   296,   243,    82,     3,   102,    45,   342,   102,   128,
     104,    40,    11,    12,   309,    78,   102,   156,   157,     3,
     103,    84,    51,    22,   110,    24,   184,    26,    82,   100,
      93,   189,   103,    52,   275,    82,   155,    36,   105,   102,
      39,   100,   181,    21,    43,   184,   296,    46,   103,   229,
     189,     4,   107,   192,   229,   194,   361,    56,   308,   309,
      13,    14,    61,   103,    63,   370,    65,   107,    38,     8,
     103,   341,    11,    12,   107,    74,    75,     8,     9,    10,
      11,    12,     6,   106,     8,     9,    10,   226,   103,   208,
      89,   103,   107,   103,   110,   107,   235,   107,    22,    79,
      24,   103,    26,   102,    79,   107,   103,   103,    11,    12,
     107,   107,    36,    69,     6,    39,     8,     9,    10,    43,
      44,    50,    46,   106,   107,    13,    14,    11,    12,    94,
      95,     3,    56,    79,    58,    59,   110,    61,     3,    63,
     102,    65,   108,     6,   108,     8,     9,    10,    96,    97,
      74,    75,    44,    45,    35,   102,    66,   296,   102,   298,
      84,   102,   102,     3,   102,    89,    58,    59,   110,   308,
     309,     8,   311,   312,   110,    25,   104,   296,   102,    66,
      66,    44,   104,    30,   323,   103,    78,   107,   107,    98,
     309,   104,    84,     4,   102,    58,    59,    93,   109,     8,
     101,    93,    11,    12,    86,   105,   345,   104,   100,    18,
     102,   102,   111,    22,    23,    24,   355,    26,    27,   112,
     359,    84,   100,   103,    99,     4,    80,    36,   105,     4,
      39,   107,   105,   102,    43,   130,   110,    46,    47,    48,
      49,   111,    15,   105,   105,    27,    55,    56,    57,    55,
      72,   110,    61,    62,    63,    64,    65,   106,     8,    64,
     311,    11,    12,    72,   294,    74,    75,    76,    77,   228,
     155,   370,    81,    23,    83,   224,   298,   269,   328,    88,
      89,    90,    91,    92,   272,   187,   355,   274,   349,   345,
     308,    41,    -1,    -1,    -1,   240,    -1,    47,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    62,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,
      90,    91,    92,    11,    12,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    81,    -1,    83,    -1,    -1,    11,    12,
      88,    89,    90,    91,    92,    18,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
      83,    -1,    85,    11,    12,    88,    89,    90,    91,    92,
      18,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    11,    12,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    22,    81,    24,    83,    26,    11,    12,    -1,
      88,    89,    90,    91,    92,    -1,    36,    -1,    22,    39,
      24,    -1,    26,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    39,    56,    -1,    -1,    43,
      -1,    61,    46,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    74,    75,    -1,    61,    -1,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    11,    12,   114,   115,   116,   208,     0,   116,   102,
     117,   118,     8,     9,   103,   119,   120,   210,    34,   103,
     120,   104,    20,    40,    42,    51,   121,   122,   123,     9,
      82,    82,    52,    82,     3,   123,   105,    21,    23,    41,
      47,    48,    49,    53,    57,    62,    64,    72,    81,    83,
      88,    90,    91,    92,   124,   125,   126,   127,   132,   135,
     138,   162,   170,   208,   210,    17,   106,   133,   134,   208,
     210,    45,   128,   129,   130,   131,   208,   210,    38,   126,
       3,    11,    12,    22,    24,    26,    36,    39,    43,    46,
      56,    61,    63,    65,    74,    75,    89,   102,   136,   157,
     167,   168,   209,   136,   106,   106,   107,   106,   129,    45,
     107,    28,   101,   144,   206,   207,   110,    79,    79,    69,
      50,    79,   139,   140,   167,   208,     3,   110,     3,   134,
     208,   131,   102,    40,    51,    11,    12,    18,    27,    55,
      76,    77,    85,   154,   156,   157,   167,   168,   169,   170,
     171,   208,   208,   210,   103,   107,   108,   108,   102,    13,
      14,   158,   159,   161,     5,     6,     7,     9,    10,   102,
     163,   165,   205,   208,   210,   117,   146,   147,   160,   161,
      35,   102,    66,    78,   102,   104,   172,   176,   177,   102,
     172,   172,   102,   202,   102,     3,   140,   210,   210,     6,
      44,    45,    58,    59,    78,    84,    93,   100,   102,   137,
     178,   179,   180,   181,   182,   183,   185,   186,   187,   192,
     193,   194,   205,   210,   110,   164,   110,   103,   107,    33,
      67,   154,   160,   198,   199,    25,   100,   143,   153,   155,
     210,   211,   157,   104,   143,   178,    66,   177,   143,    66,
     198,   100,   103,   203,   204,   205,   210,   141,   142,   156,
     210,   154,    30,   107,   208,   103,   107,    94,    95,   173,
      96,    97,   174,    98,   175,   104,    99,   111,   184,   102,
     159,     4,   166,   210,    93,   148,   149,   147,   102,   167,
     186,   200,    86,   145,   198,   210,   109,   103,   107,   207,
     154,   178,   103,   105,   156,   103,   156,   103,   107,   104,
     103,   107,   102,   179,   103,   100,   181,   182,   183,   178,
     111,    99,   186,   112,   195,   196,     4,    80,   201,   145,
     165,   205,   153,   105,   204,   165,   205,   142,   100,   188,
     189,   210,   107,   105,   111,   110,   197,   210,   103,   107,
     102,   166,   105,   105,   103,   107,   172,   179,   197,   110,
     196,   150,   189,    15,    67,    71,   190,   191,   210,     4,
     151,   152,   160,   103,   152
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
#line 298 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 304 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 309 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 330 "asn1p_y.y"
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
#line 351 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 7:
#line 352 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 8:
#line 356 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 9:
#line 359 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 10:
#line 365 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 11:
#line 371 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 380 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 13:
#line 384 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 14:
#line 388 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 15:
#line 398 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 16:
#line 399 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 17:
#line 408 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 411 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 420 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 423 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 426 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 429 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 438 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 24:
#line 439 "asn1p_y.y"
    {
		assert(yyvsp[0].a_module);
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 25:
#line 449 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 26:
#line 452 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;

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

  case 27:
#line 479 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 28:
#line 482 "asn1p_y.y"
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

  case 29:
#line 491 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 30:
#line 498 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 511 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 522 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic type, "
			"use -ftypesXY to switch back "
			"to older version of ASN.1 standard");
	}
    break;

  case 33:
#line 536 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 34:
#line 542 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 35:
#line 548 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 36:
#line 553 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 37:
#line 560 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->from = yyvsp[-1].tv_str;
		yyval.a_xports->from_oid = yyvsp[0].a_oid;
		checkmem(yyval.a_xports);
	}
    break;

  case 38:
#line 569 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 39:
#line 574 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 40:
#line 581 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 41:
#line 587 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 42:
#line 596 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 43:
#line 599 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 44:
#line 602 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 45:
#line 610 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 46:
#line 615 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 47:
#line 622 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 48:
#line 628 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 49:
#line 638 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-4].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		// take care of optValueSetBody 
	}
    break;

  case 50:
#line 648 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 51:
#line 655 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 52:
#line 664 "asn1p_y.y"
    { }
    break;

  case 53:
#line 665 "asn1p_y.y"
    {
	}
    break;

  case 54:
#line 681 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		yyval.a_expr->expr_type = A1TC_TYPEID;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 55:
#line 689 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->tag = yyvsp[-1].a_tag;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 56:
#line 696 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 57:
#line 713 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->params = yyvsp[-3].a_plist;
		yyval.a_expr->meta_type = AMT_PARAMTYPE;
	}
    break;

  case 58:
#line 723 "asn1p_y.y"
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

  case 59:
#line 732 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 60:
#line 743 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 61:
#line 747 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 62:
#line 754 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 63:
#line 765 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 64:
#line 770 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 65:
#line 777 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 66:
#line 780 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 67:
#line 793 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 68:
#line 798 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 69:
#line 805 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECT);
	}
    break;

  case 70:
#line 815 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 71:
#line 816 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 72:
#line 820 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECT;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 73:
#line 827 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 74:
#line 834 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].a_refcomp.name;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 75:
#line 842 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].a_refcomp.name;
		yyval.a_expr->unique = yyvsp[0].a_int;
	}
    break;

  case 76:
#line 847 "asn1p_y.y"
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

  case 77:
#line 865 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 78:
#line 866 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 79:
#line 873 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 80:
#line 875 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 81:
#line 881 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 82:
#line 885 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 83:
#line 892 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
	}
    break;

  case 84:
#line 895 "asn1p_y.y"
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

  case 85:
#line 921 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_nametag.name;
		yyval.a_expr->tag = yyvsp[-1].tv_nametag.tag;
	}
    break;

  case 86:
#line 927 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 87:
#line 933 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		yyval.a_expr->constraints = yyvsp[-1].a_constr;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 88:
#line 941 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 89:
#line 949 "asn1p_y.y"
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

  case 90:
#line 958 "asn1p_y.y"
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

  case 91:
#line 970 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 92:
#line 973 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 93:
#line 979 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		checkmem(yyval.a_expr);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 94:
#line 987 "asn1p_y.y"
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

  case 95:
#line 1011 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 96:
#line 1018 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 97:
#line 1033 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 98:
#line 1041 "asn1p_y.y"
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

  case 99:
#line 1051 "asn1p_y.y"
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

  case 100:
#line 1061 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 101:
#line 1069 "asn1p_y.y"
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

  case 102:
#line 1091 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 103:
#line 1099 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 106:
#line 1113 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 107:
#line 1118 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 108:
#line 1131 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 109:
#line 1141 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 110:
#line 1142 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 111:
#line 1147 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 112:
#line 1151 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 113:
#line 1155 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 114:
#line 1159 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 115:
#line 1162 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 116:
#line 1168 "asn1p_y.y"
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

  case 117:
#line 1179 "asn1p_y.y"
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

  case 118:
#line 1196 "asn1p_y.y"
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

  case 119:
#line 1206 "asn1p_y.y"
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

  case 120:
#line 1221 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 121:
#line 1222 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 122:
#line 1223 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 123:
#line 1224 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 124:
#line 1225 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 125:
#line 1226 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 126:
#line 1227 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 127:
#line 1228 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 128:
#line 1229 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 129:
#line 1230 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 130:
#line 1231 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 131:
#line 1232 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 132:
#line 1239 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 133:
#line 1240 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 134:
#line 1241 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 135:
#line 1245 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1251 "asn1p_y.y"
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

  case 137:
#line 1264 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 138:
#line 1265 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		return yyerror("GeneralString is not supported");
	}
    break;

  case 139:
#line 1269 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		return yyerror("GraphicString is not supported");
	}
    break;

  case 140:
#line 1273 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 141:
#line 1274 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 142:
#line 1275 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 143:
#line 1276 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 144:
#line 1277 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		return yyerror("T61String not implemented yet");
	}
    break;

  case 145:
#line 1281 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 146:
#line 1282 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 147:
#line 1283 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 148:
#line 1284 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		return yyerror("VideotexString is no longer supported");
	}
    break;

  case 149:
#line 1288 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 150:
#line 1289 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 151:
#line 1293 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 152:
#line 1299 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 153:
#line 1305 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 154:
#line 1311 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 155:
#line 1319 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-2].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SET_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 156:
#line 1327 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_CONSTR_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 157:
#line 1333 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_expr->reference,
			yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_expr->expr_type = ASN_CONSTR_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 158:
#line 1350 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 159:
#line 1351 "asn1p_y.y"
    { yyval.a_constr = yyvsp[0].a_constr; }
    break;

  case 165:
#line 1359 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parenthesis.
		 */
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CT_SIZE;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 166:
#line 1371 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 167:
#line 1374 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-1].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 168:
#line 1380 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 169:
#line 1386 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 170:
#line 1389 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 171:
#line 1396 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 172:
#line 1404 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 173:
#line 1409 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 174:
#line 1418 "asn1p_y.y"
    { yyval.a_constr = yyvsp[0].a_constr; }
    break;

  case 175:
#line 1421 "asn1p_y.y"
    { yyval.a_constr = yyvsp[0].a_constr; }
    break;

  case 176:
#line 1422 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 177:
#line 1428 "asn1p_y.y"
    { yyval.a_constr = yyvsp[0].a_constr; }
    break;

  case 178:
#line 1430 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 179:
#line 1436 "asn1p_y.y"
    { yyval.a_constr = yyvsp[0].a_constr; }
    break;

  case 180:
#line 1437 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 181:
#line 1443 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 182:
#line 1449 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 183:
#line 1456 "asn1p_y.y"
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
#line 1464 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 185:
#line 1467 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 186:
#line 1473 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 187:
#line 1474 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 188:
#line 1475 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 189:
#line 1476 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 190:
#line 1480 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 191:
#line 1483 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 192:
#line 1489 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 193:
#line 1492 "asn1p_y.y"
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

  case 194:
#line 1503 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 195:
#line 1507 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(123);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_MIN;
	}
    break;

  case 196:
#line 1512 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(321);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_MAX;
	}
    break;

  case 197:
#line 1517 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 198:
#line 1522 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 199:
#line 1530 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 200:
#line 1536 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 201:
#line 1539 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 202:
#line 1545 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 203:
#line 1550 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
	}
    break;

  case 204:
#line 1563 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 205:
#line 1564 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 206:
#line 1568 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 207:
#line 1571 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 208:
#line 1574 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 209:
#line 1580 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 210:
#line 1583 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 211:
#line 1592 "asn1p_y.y"
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

  case 212:
#line 1607 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 213:
#line 1613 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 214:
#line 1619 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 215:
#line 1633 "asn1p_y.y"
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

  case 216:
#line 1644 "asn1p_y.y"
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

  case 217:
#line 1660 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 218:
#line 1663 "asn1p_y.y"
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

  case 219:
#line 1681 "asn1p_y.y"
    { yyval.a_marker = EM_NOMARK; }
    break;

  case 220:
#line 1682 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 221:
#line 1686 "asn1p_y.y"
    {
		yyval.a_marker = EM_OPTIONAL;
	}
    break;

  case 222:
#line 1689 "asn1p_y.y"
    {
		yyval.a_marker = EM_DEFAULT;
		/* FIXME: store DefaultValue somewhere */
	}
    break;

  case 223:
#line 1696 "asn1p_y.y"
    {
	}
    break;

  case 224:
#line 1698 "asn1p_y.y"
    {
	}
    break;

  case 225:
#line 1700 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 226:
#line 1700 "asn1p_y.y"
    {
	}
    break;

  case 227:
#line 1721 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
	}
    break;

  case 228:
#line 1725 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 229:
#line 1731 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 230:
#line 1736 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		TQ_ADD(&(yyval.a_expr->members), yyvsp[0].a_expr, next);
	}
    break;

  case 231:
#line 1743 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 232:
#line 1750 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 233:
#line 1758 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 234:
#line 1766 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 235:
#line 1773 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(asn1p_lineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 236:
#line 1784 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 237:
#line 1788 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 238:
#line 1819 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 239:
#line 1820 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 240:
#line 1824 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[0].a_tag;
		yyval.a_tag.tag_mode = TM_DEFAULT;
	}
    break;

  case 241:
#line 1828 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_IMPLICIT;
	}
    break;

  case 242:
#line 1832 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = TM_EXPLICIT;
	}
    break;

  case 243:
#line 1839 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 244:
#line 1843 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 245:
#line 1850 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 246:
#line 1857 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 247:
#line 1864 "asn1p_y.y"
    {
		memset(&yyval.tv_nametag, 0, sizeof(yyval.tv_nametag));
		yyval.tv_nametag.name = yyvsp[0].tv_str;
	}
    break;

  case 248:
#line 1868 "asn1p_y.y"
    {
		yyval.tv_nametag.name = yyvsp[-1].tv_str;
		yyval.tv_nametag.tag = yyvsp[0].a_tag;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 3786 "asn1p_y.c"

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


#line 1875 "asn1p_y.y"



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



