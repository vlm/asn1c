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
     TOK_number_negative = 266,
     TOK_realnumber = 267,
     TOK_tuple = 268,
     TOK_quadruple = 269,
     TOK_typereference = 270,
     TOK_capitalreference = 271,
     TOK_typefieldreference = 272,
     TOK_valuefieldreference = 273,
     TOK_Literal = 274,
     TOK_ABSENT = 275,
     TOK_ABSTRACT_SYNTAX = 276,
     TOK_ALL = 277,
     TOK_ANY = 278,
     TOK_APPLICATION = 279,
     TOK_AUTOMATIC = 280,
     TOK_BEGIN = 281,
     TOK_BIT = 282,
     TOK_BMPString = 283,
     TOK_BOOLEAN = 284,
     TOK_BY = 285,
     TOK_CHARACTER = 286,
     TOK_CHOICE = 287,
     TOK_CLASS = 288,
     TOK_COMPONENT = 289,
     TOK_COMPONENTS = 290,
     TOK_CONSTRAINED = 291,
     TOK_CONTAINING = 292,
     TOK_DEFAULT = 293,
     TOK_DEFINITIONS = 294,
     TOK_DEFINED = 295,
     TOK_EMBEDDED = 296,
     TOK_ENCODED = 297,
     TOK_ENCODING_CONTROL = 298,
     TOK_END = 299,
     TOK_ENUMERATED = 300,
     TOK_EXPLICIT = 301,
     TOK_EXPORTS = 302,
     TOK_EXTENSIBILITY = 303,
     TOK_EXTERNAL = 304,
     TOK_FALSE = 305,
     TOK_FROM = 306,
     TOK_GeneralizedTime = 307,
     TOK_GeneralString = 308,
     TOK_GraphicString = 309,
     TOK_IA5String = 310,
     TOK_IDENTIFIER = 311,
     TOK_IMPLICIT = 312,
     TOK_IMPLIED = 313,
     TOK_IMPORTS = 314,
     TOK_INCLUDES = 315,
     TOK_INSTANCE = 316,
     TOK_INSTRUCTIONS = 317,
     TOK_INTEGER = 318,
     TOK_ISO646String = 319,
     TOK_MAX = 320,
     TOK_MIN = 321,
     TOK_MINUS_INFINITY = 322,
     TOK_NULL = 323,
     TOK_NumericString = 324,
     TOK_OBJECT = 325,
     TOK_ObjectDescriptor = 326,
     TOK_OCTET = 327,
     TOK_OF = 328,
     TOK_OPTIONAL = 329,
     TOK_PATTERN = 330,
     TOK_PDV = 331,
     TOK_PLUS_INFINITY = 332,
     TOK_PRESENT = 333,
     TOK_PrintableString = 334,
     TOK_PRIVATE = 335,
     TOK_REAL = 336,
     TOK_RELATIVE_OID = 337,
     TOK_SEQUENCE = 338,
     TOK_SET = 339,
     TOK_SIZE = 340,
     TOK_STRING = 341,
     TOK_SYNTAX = 342,
     TOK_T61String = 343,
     TOK_TAGS = 344,
     TOK_TeletexString = 345,
     TOK_TRUE = 346,
     TOK_TYPE_IDENTIFIER = 347,
     TOK_UNIQUE = 348,
     TOK_UNIVERSAL = 349,
     TOK_UniversalString = 350,
     TOK_UTCTime = 351,
     TOK_UTF8String = 352,
     TOK_VideotexString = 353,
     TOK_VisibleString = 354,
     TOK_WITH = 355,
     TOK_EXCEPT = 356,
     TOK_INTERSECTION = 357,
     TOK_UNION = 358,
     TOK_TwoDots = 359,
     TOK_ThreeDots = 360
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
#define TOK_number_negative 266
#define TOK_realnumber 267
#define TOK_tuple 268
#define TOK_quadruple 269
#define TOK_typereference 270
#define TOK_capitalreference 271
#define TOK_typefieldreference 272
#define TOK_valuefieldreference 273
#define TOK_Literal 274
#define TOK_ABSENT 275
#define TOK_ABSTRACT_SYNTAX 276
#define TOK_ALL 277
#define TOK_ANY 278
#define TOK_APPLICATION 279
#define TOK_AUTOMATIC 280
#define TOK_BEGIN 281
#define TOK_BIT 282
#define TOK_BMPString 283
#define TOK_BOOLEAN 284
#define TOK_BY 285
#define TOK_CHARACTER 286
#define TOK_CHOICE 287
#define TOK_CLASS 288
#define TOK_COMPONENT 289
#define TOK_COMPONENTS 290
#define TOK_CONSTRAINED 291
#define TOK_CONTAINING 292
#define TOK_DEFAULT 293
#define TOK_DEFINITIONS 294
#define TOK_DEFINED 295
#define TOK_EMBEDDED 296
#define TOK_ENCODED 297
#define TOK_ENCODING_CONTROL 298
#define TOK_END 299
#define TOK_ENUMERATED 300
#define TOK_EXPLICIT 301
#define TOK_EXPORTS 302
#define TOK_EXTENSIBILITY 303
#define TOK_EXTERNAL 304
#define TOK_FALSE 305
#define TOK_FROM 306
#define TOK_GeneralizedTime 307
#define TOK_GeneralString 308
#define TOK_GraphicString 309
#define TOK_IA5String 310
#define TOK_IDENTIFIER 311
#define TOK_IMPLICIT 312
#define TOK_IMPLIED 313
#define TOK_IMPORTS 314
#define TOK_INCLUDES 315
#define TOK_INSTANCE 316
#define TOK_INSTRUCTIONS 317
#define TOK_INTEGER 318
#define TOK_ISO646String 319
#define TOK_MAX 320
#define TOK_MIN 321
#define TOK_MINUS_INFINITY 322
#define TOK_NULL 323
#define TOK_NumericString 324
#define TOK_OBJECT 325
#define TOK_ObjectDescriptor 326
#define TOK_OCTET 327
#define TOK_OF 328
#define TOK_OPTIONAL 329
#define TOK_PATTERN 330
#define TOK_PDV 331
#define TOK_PLUS_INFINITY 332
#define TOK_PRESENT 333
#define TOK_PrintableString 334
#define TOK_PRIVATE 335
#define TOK_REAL 336
#define TOK_RELATIVE_OID 337
#define TOK_SEQUENCE 338
#define TOK_SET 339
#define TOK_SIZE 340
#define TOK_STRING 341
#define TOK_SYNTAX 342
#define TOK_T61String 343
#define TOK_TAGS 344
#define TOK_TeletexString 345
#define TOK_TRUE 346
#define TOK_TYPE_IDENTIFIER 347
#define TOK_UNIQUE 348
#define TOK_UNIVERSAL 349
#define TOK_UniversalString 350
#define TOK_UTCTime 351
#define TOK_UTF8String 352
#define TOK_VideotexString 353
#define TOK_VisibleString 354
#define TOK_WITH 355
#define TOK_EXCEPT 356
#define TOK_INTERSECTION 357
#define TOK_UNION 358
#define TOK_TwoDots 359
#define TOK_ThreeDots 360




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

static asn1p_module_t *currentModule;
#define	NEW_EXPR()	(asn1p_expr_new(yylineno, currentModule))

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

#ifdef	AL_IMPORT
#error	AL_IMPORT DEFINED ELSEWHERE!
#endif
#define	AL_IMPORT(to,where,from,field)	do {				\
		if(!(from)) break;					\
		while(TQ_FIRST(&((from)->where))) {			\
			TQ_ADD(&((to)->where),				\
				TQ_REMOVE(&((from)->where), field),	\
				field);					\
		}							\
		assert(TQ_FIRST(&((from)->where)) == 0);		\
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
#line 88 "asn1p_y.y"
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
} yystype;
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 408 "asn1p_y.c"
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
#line 429 "asn1p_y.c"

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
#define YYLAST   871

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  121
/* YYNRULES -- Number of rules. */
#define YYNRULES  309
/* YYNRULES -- Number of states. */
#define YYNSTATES  469

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   117,     2,     2,     2,     2,     2,     2,
     110,   111,     2,     2,   113,     2,   118,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   114,   112,
     119,     2,     2,     2,   120,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   115,     2,   116,   102,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   108,   104,   109,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   103,   105,   106,
     107
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    11,    21,    22,    24,
      28,    31,    33,    36,    38,    43,    45,    46,    48,    50,
      53,    56,    59,    62,    65,    68,    69,    71,    75,    77,
      80,    82,    84,    86,    87,    91,    93,    94,    96,   100,
     103,   104,   106,   108,   111,   112,   114,   119,   121,   125,
     127,   131,   133,   134,   136,   140,   144,   147,   149,   153,
     155,   159,   161,   165,   170,   172,   174,   179,   183,   187,
     194,   201,   203,   207,   209,   213,   217,   221,   225,   227,
     231,   233,   235,   237,   239,   240,   242,   244,   248,   252,
     255,   259,   261,   263,   267,   270,   272,   274,   280,   281,
     283,   285,   289,   292,   297,   301,   305,   309,   313,   317,
     318,   320,   321,   328,   330,   333,   335,   337,   339,   343,
     345,   349,   353,   357,   358,   361,   363,   368,   373,   378,
     385,   392,   394,   399,   403,   405,   409,   413,   417,   419,
     423,   425,   429,   431,   433,   435,   437,   441,   445,   447,
     452,   454,   456,   460,   461,   465,   467,   469,   471,   473,
     475,   477,   479,   481,   485,   487,   489,   491,   493,   496,
     498,   500,   502,   504,   507,   510,   512,   514,   517,   520,
     522,   524,   526,   528,   530,   533,   535,   538,   540,   542,
     544,   546,   548,   550,   552,   554,   556,   558,   560,   562,
     564,   566,   568,   570,   572,   574,   575,   577,   579,   583,
     585,   590,   594,   599,   601,   603,   607,   613,   615,   619,
     621,   625,   627,   631,   633,   637,   642,   646,   648,   650,
     654,   658,   662,   666,   668,   670,   673,   676,   678,   680,
     682,   684,   686,   688,   690,   692,   696,   702,   704,   708,
     710,   714,   715,   717,   719,   721,   723,   725,   727,   729,
     730,   736,   739,   741,   744,   747,   751,   753,   755,   759,
     764,   766,   770,   773,   777,   779,   783,   784,   786,   788,
     791,   794,   798,   800,   804,   806,   811,   816,   818,   820,
     822,   824,   826,   828,   829,   831,   834,   839,   840,   842,
     844,   846,   847,   849,   851,   853,   855,   857,   858,   860
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     122,     0,    -1,   123,    -1,   124,    -1,   123,   124,    -1,
      -1,   238,   125,   126,    39,   130,     3,    26,   133,    44,
      -1,    -1,   127,    -1,   108,   128,   109,    -1,   108,   109,
      -1,   129,    -1,   128,   129,    -1,   241,    -1,   241,   110,
      10,   111,    -1,    10,    -1,    -1,   131,    -1,   132,    -1,
     131,   132,    -1,    46,    89,    -1,    57,    89,    -1,    25,
      89,    -1,    48,    58,    -1,    16,    62,    -1,    -1,   134,
      -1,   146,   138,   135,    -1,   136,    -1,   135,   136,    -1,
     153,    -1,   183,    -1,   151,    -1,    -1,    43,    16,   137,
      -1,   193,    -1,    -1,   139,    -1,    59,   140,   112,    -1,
      59,    51,    -1,    -1,   141,    -1,   143,    -1,   141,   143,
      -1,    -1,   127,    -1,   144,    51,   238,   142,    -1,   145,
      -1,   144,   113,   145,    -1,   238,    -1,   238,   108,   109,
      -1,   241,    -1,    -1,   147,    -1,    47,   148,   112,    -1,
      47,    22,   112,    -1,    47,   112,    -1,   149,    -1,   148,
     113,   149,    -1,   238,    -1,   238,   108,   109,    -1,   241,
      -1,   108,   200,   109,    -1,   238,   152,     3,   150,    -1,
     192,    -1,   177,    -1,   177,   108,   156,   109,    -1,   238,
       3,   173,    -1,   238,     3,   163,    -1,   238,   108,   154,
     109,     3,   173,    -1,   238,   108,   154,   109,     3,   163,
      -1,   155,    -1,   154,   113,   155,    -1,   238,    -1,   238,
     114,   241,    -1,   238,   114,   238,    -1,   190,   114,   241,
      -1,   190,   114,   238,    -1,   157,    -1,   156,   113,   157,
      -1,   173,    -1,   186,    -1,   241,    -1,   150,    -1,    -1,
     159,    -1,   160,    -1,   159,   113,   160,    -1,   241,   173,
     226,    -1,   173,   226,    -1,    35,    73,   173,    -1,   172,
      -1,   162,    -1,   161,   113,   162,    -1,   241,   173,    -1,
     172,    -1,   173,    -1,    33,   108,   165,   109,   167,    -1,
      -1,    93,    -1,   166,    -1,   165,   113,   166,    -1,    17,
     226,    -1,    18,   173,   164,   226,    -1,    18,   181,   226,
      -1,    18,   182,   226,    -1,    17,   181,   226,    -1,    17,
     173,   226,    -1,    17,   182,   226,    -1,    -1,   168,    -1,
      -1,   100,    87,   108,   169,   170,   109,    -1,   171,    -1,
     170,   171,    -1,     4,    -1,    19,    -1,   180,    -1,   115,
     170,   116,    -1,   107,    -1,   107,   117,   187,    -1,   107,
     117,   231,    -1,   233,   175,   196,    -1,    -1,   174,   176,
      -1,   152,    -1,    32,   108,   161,   109,    -1,    83,   108,
     158,   109,    -1,    84,   108,   158,   109,    -1,    83,   196,
      73,   240,   233,   175,    -1,    84,   196,    73,   240,   233,
     175,    -1,    23,    -1,    23,    40,    30,   241,    -1,    61,
      73,   177,    -1,    15,    -1,    15,   118,   238,    -1,   239,
     118,   238,    -1,    15,   118,   241,    -1,   239,    -1,   239,
     118,   178,    -1,   179,    -1,   178,   118,   179,    -1,   180,
      -1,    17,    -1,    18,    -1,    17,    -1,   181,   118,    17,
      -1,   181,   118,    18,    -1,    16,    -1,   241,   152,     3,
     184,    -1,   186,    -1,   187,    -1,   241,   114,   184,    -1,
      -1,   108,   185,   189,    -1,    68,    -1,    50,    -1,    91,
      -1,     6,    -1,     8,    -1,   188,    -1,   231,    -1,   241,
      -1,   238,   118,   241,    -1,     7,    -1,    13,    -1,    14,
      -1,     5,    -1,   189,     5,    -1,    29,    -1,    68,    -1,
      81,    -1,   191,    -1,    72,    86,    -1,    70,    56,    -1,
      82,    -1,    49,    -1,    41,    76,    -1,    31,    86,    -1,
      96,    -1,    52,    -1,   193,    -1,    63,    -1,    45,    -1,
      27,    86,    -1,   190,    -1,   191,   228,    -1,    28,    -1,
      53,    -1,    54,    -1,    55,    -1,    64,    -1,    69,    -1,
      79,    -1,    88,    -1,    90,    -1,    95,    -1,    97,    -1,
      98,    -1,    99,    -1,    71,    -1,   104,    -1,   105,    -1,
     102,    -1,   103,    -1,    -1,   197,    -1,   198,    -1,   110,
     215,   111,    -1,   199,    -1,    85,   110,   200,   111,    -1,
     110,   200,   111,    -1,   199,   110,   200,   111,    -1,   107,
      -1,   201,    -1,   201,   113,   107,    -1,   201,   113,   107,
     113,   201,    -1,   202,    -1,    22,   101,   205,    -1,   203,
      -1,   202,   194,   203,    -1,   204,    -1,   203,   195,   204,
      -1,   205,    -1,   205,   101,   205,    -1,   207,   110,   200,
     111,    -1,   110,   200,   111,    -1,   208,    -1,   209,    -1,
     208,   219,   208,    -1,    66,   219,   208,    -1,   208,   219,
      65,    -1,    66,   219,    65,    -1,   210,    -1,   206,    -1,
      75,     7,    -1,    75,   241,    -1,    85,    -1,    51,    -1,
      50,    -1,    91,    -1,   232,    -1,   188,    -1,   241,    -1,
     238,    -1,   100,    34,   199,    -1,   100,    35,   108,   211,
     109,    -1,   212,    -1,   211,   113,   212,    -1,   107,    -1,
     241,   196,   213,    -1,    -1,   214,    -1,    78,    -1,    20,
      -1,    74,    -1,   216,    -1,   220,    -1,   218,    -1,    -1,
      36,    30,   108,   217,   189,    -1,    37,   173,    -1,   106,
      -1,   106,   119,    -1,   119,   106,    -1,   119,   106,   119,
      -1,   221,    -1,   222,    -1,   108,   238,   109,    -1,   221,
     108,   223,   109,    -1,   224,    -1,   223,   113,   224,    -1,
     120,   225,    -1,   120,   118,   225,    -1,   241,    -1,   225,
     118,   241,    -1,    -1,   227,    -1,    74,    -1,    38,   184,
      -1,   108,   109,    -1,   108,   229,   109,    -1,   230,    -1,
     229,   113,   230,    -1,   241,    -1,   241,   110,   231,   111,
      -1,   241,   110,   187,   111,    -1,   231,    -1,   107,    -1,
      10,    -1,    11,    -1,   231,    -1,    12,    -1,    -1,   234,
      -1,   235,   237,    -1,   115,   236,    10,   116,    -1,    -1,
      94,    -1,    24,    -1,    80,    -1,    -1,    57,    -1,    46,
      -1,    15,    -1,    16,    -1,    16,    -1,    -1,   241,    -1,
       9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   354,   354,   360,   366,   383,   382,   411,   413,   416,
     420,   425,   432,   440,   445,   449,   458,   460,   468,   472,
     480,   484,   487,   490,   494,   514,   516,   524,   533,   537,
     552,   560,   573,   581,   580,   594,   606,   608,   610,   621,
     626,   628,   630,   636,   642,   644,   647,   658,   664,   670,
     677,   683,   692,   694,   705,   709,   712,   719,   725,   731,
     738,   744,   753,   755,   765,   779,   789,   805,   815,   831,
     837,   844,   854,   864,   869,   876,   883,   891,   901,   907,
     913,   917,   925,   936,   958,   960,   962,   968,   974,   982,
     988,   995,  1000,  1006,  1012,  1018,  1021,  1027,  1037,  1039,
    1042,  1050,  1057,  1070,  1081,  1091,  1102,  1112,  1123,  1134,
    1136,  1143,  1141,  1150,  1155,  1161,  1166,  1169,  1173,  1178,
    1187,  1196,  1207,  1229,  1236,  1255,  1259,  1265,  1271,  1277,
    1287,  1297,  1303,  1314,  1328,  1337,  1347,  1357,  1367,  1375,
    1396,  1405,  1414,  1416,  1423,  1430,  1436,  1440,  1446,  1466,
    1476,  1478,  1479,  1486,  1486,  1491,  1498,  1504,  1509,  1513,
    1517,  1520,  1525,  1537,  1554,  1559,  1564,  1597,  1607,  1621,
    1623,  1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,
    1633,  1634,  1640,  1642,  1643,  1646,  1653,  1665,  1667,  1671,
    1675,  1676,  1677,  1678,  1679,  1683,  1684,  1685,  1686,  1690,
    1691,  1698,  1698,  1699,  1699,  1701,  1703,  1708,  1710,  1715,
    1719,  1728,  1732,  1737,  1742,  1745,  1751,  1761,  1763,  1768,
    1770,  1775,  1777,  1783,  1785,  1790,  1799,  1807,  1813,  1819,
    1826,  1834,  1842,  1851,  1854,  1859,  1865,  1875,  1879,  1884,
    1890,  1895,  1896,  1897,  1910,  1924,  1928,  1933,  1937,  1942,
    1949,  1962,  1964,  1967,  1971,  1974,  1981,  1983,  1984,  1989,
    1987,  1999,  2007,  2009,  2010,  2011,  2013,  2017,  2025,  2040,
    2046,  2053,  2066,  2078,  2093,  2097,  2114,  2119,  2122,  2127,
    2149,  2154,  2159,  2165,  2171,  2179,  2187,  2195,  2202,  2212,
    2217,  2223,  2225,  2255,  2257,  2260,  2267,  2273,  2275,  2276,
    2277,  2280,  2282,  2283,  2286,  2291,  2298,  2305,  2307,  2312
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_whitespace", "TOK_opaque", 
  "TOK_bstring", "TOK_cstring", "TOK_hstring", "TOK_identifier", 
  "TOK_number", "TOK_number_negative", "TOK_realnumber", "TOK_tuple", 
  "TOK_quadruple", "TOK_typereference", "TOK_capitalreference", 
  "TOK_typefieldreference", "TOK_valuefieldreference", "TOK_Literal", 
  "TOK_ABSENT", "TOK_ABSTRACT_SYNTAX", "TOK_ALL", "TOK_ANY", 
  "TOK_APPLICATION", "TOK_AUTOMATIC", "TOK_BEGIN", "TOK_BIT", 
  "TOK_BMPString", "TOK_BOOLEAN", "TOK_BY", "TOK_CHARACTER", "TOK_CHOICE", 
  "TOK_CLASS", "TOK_COMPONENT", "TOK_COMPONENTS", "TOK_CONSTRAINED", 
  "TOK_CONTAINING", "TOK_DEFAULT", "TOK_DEFINITIONS", "TOK_DEFINED", 
  "TOK_EMBEDDED", "TOK_ENCODED", "TOK_ENCODING_CONTROL", "TOK_END", 
  "TOK_ENUMERATED", "TOK_EXPLICIT", "TOK_EXPORTS", "TOK_EXTENSIBILITY", 
  "TOK_EXTERNAL", "TOK_FALSE", "TOK_FROM", "TOK_GeneralizedTime", 
  "TOK_GeneralString", "TOK_GraphicString", "TOK_IA5String", 
  "TOK_IDENTIFIER", "TOK_IMPLICIT", "TOK_IMPLIED", "TOK_IMPORTS", 
  "TOK_INCLUDES", "TOK_INSTANCE", "TOK_INSTRUCTIONS", "TOK_INTEGER", 
  "TOK_ISO646String", "TOK_MAX", "TOK_MIN", "TOK_MINUS_INFINITY", 
  "TOK_NULL", "TOK_NumericString", "TOK_OBJECT", "TOK_ObjectDescriptor", 
  "TOK_OCTET", "TOK_OF", "TOK_OPTIONAL", "TOK_PATTERN", "TOK_PDV", 
  "TOK_PLUS_INFINITY", "TOK_PRESENT", "TOK_PrintableString", 
  "TOK_PRIVATE", "TOK_REAL", "TOK_RELATIVE_OID", "TOK_SEQUENCE", 
  "TOK_SET", "TOK_SIZE", "TOK_STRING", "TOK_SYNTAX", "TOK_T61String", 
  "TOK_TAGS", "TOK_TeletexString", "TOK_TRUE", "TOK_TYPE_IDENTIFIER", 
  "TOK_UNIQUE", "TOK_UNIVERSAL", "TOK_UniversalString", "TOK_UTCTime", 
  "TOK_UTF8String", "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH", 
  "TOK_EXCEPT", "'^'", "TOK_INTERSECTION", "'|'", "TOK_UNION", 
  "TOK_TwoDots", "TOK_ThreeDots", "'{'", "'}'", "'('", "')'", "';'", 
  "','", "':'", "'['", "']'", "'!'", "'.'", "'<'", "'@'", "$accept", 
  "ParsedGrammar", "ModuleList", "ModuleDefinition", "@1", 
  "optObjectIdentifier", "ObjectIdentifier", "ObjectIdentifierBody", 
  "ObjectIdentifierElement", "optModuleDefinitionFlags", 
  "ModuleDefinitionFlags", "ModuleDefinitionFlag", "optModuleBody", 
  "ModuleBody", "AssignmentList", "Assignment", "@2", "optImports", 
  "ImportsDefinition", "optImportsBundleSet", "ImportsBundleSet", 
  "AssignedIdentifier", "ImportsBundle", "ImportsList", "ImportsElement", 
  "optExports", "ExportsDefinition", "ExportsBody", "ExportsElement", 
  "ValueSet", "ValueSetTypeAssignment", "DefinedType", 
  "DataTypeReference", "ParameterArgumentList", "ParameterArgumentName", 
  "ActualParameterList", "ActualParameter", "optComponentTypeLists", 
  "ComponentTypeLists", "ComponentType", "AlternativeTypeLists", 
  "AlternativeType", "ObjectClass", "optUnique", "FieldSpec", 
  "ClassField", "optWithSyntax", "WithSyntax", "@3", "WithSyntaxList", 
  "WithSyntaxToken", "ExtensionAndException", "Type", 
  "NSTD_IndirectMarker", "TypeDeclaration", "TypeDeclarationSet", 
  "ComplexTypeReference", "ComplexTypeReferenceAmpList", 
  "ComplexTypeReferenceElement", "PrimitiveFieldReference", "FieldName", 
  "DefinedObjectClass", "ValueDefinition", "Value", "@4", "SimpleValue", 
  "DefinedValue", "RestrictedCharacterStringValue", "Opaque", 
  "BasicTypeId", "BasicTypeId_UniverationCompatible", "BasicType", 
  "BasicString", "UnionMark", "IntersectionMark", "optConstraints", 
  "Constraint", "SubtypeConstraint", "SetOfConstraints", 
  "ElementSetSpecs", "ElementSetSpec", "Unions", "Intersections", 
  "IntersectionElements", "ConstraintSubtypeElement", "PatternConstraint", 
  "ConstraintSpec", "SingleValue", "ContainedSubtype", 
  "InnerTypeConstraint", "WithComponentsList", "WithComponentsElement", 
  "optPresenceConstraint", "PresenceConstraint", "GeneralConstraint", 
  "UserDefinedConstraint", "@5", "ContentsConstraint", 
  "ConstraintRangeSpec", "TableConstraint", "SimpleTableConstraint", 
  "ComponentRelationConstraint", "AtNotationList", "AtNotationElement", 
  "ComponentIdList", "optMarker", "Marker", "UniverationDefinition", 
  "UniverationList", "UniverationElement", "SignedNumber", "RealValue", 
  "optTag", "Tag", "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName", 
  "ObjectClassReference", "optIdentifier", "Identifier", 0
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
     355,   356,    94,   357,   124,   358,   359,   360,   123,   125,
      40,    41,    59,    44,    58,    91,    93,    33,    46,    60,
      64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   121,   122,   123,   123,   125,   124,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   134,   135,   135,
     136,   136,   136,   137,   136,   136,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   144,   144,   145,
     145,   145,   146,   146,   147,   147,   147,   148,   148,   149,
     149,   149,   150,   151,   152,   152,   152,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   156,   156,
     157,   157,   157,   157,   158,   158,   159,   159,   160,   160,
     160,   160,   161,   161,   162,   162,   162,   163,   164,   164,
     165,   165,   166,   166,   166,   166,   166,   166,   166,   167,
     167,   169,   168,   170,   170,   171,   171,   171,   171,   172,
     172,   172,   173,   174,   175,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   177,   177,   177,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   181,   182,   183,
     184,   184,   184,   185,   184,   184,   186,   186,   186,   186,
     186,   186,   187,   187,   188,   188,   188,   189,   189,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   191,   191,   191,   192,   192,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   199,   199,   200,   200,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   206,   206,   207,   207,   208,
     208,   208,   208,   208,   209,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   214,   214,   215,   215,   215,   217,
     216,   218,   219,   219,   219,   219,   220,   220,   221,   222,
     223,   223,   224,   224,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   235,   236,   236,   236,
     236,   237,   237,   237,   238,   238,   239,   240,   240,   241
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     0,     9,     0,     1,     3,
       2,     1,     2,     1,     4,     1,     0,     1,     1,     2,
       2,     2,     2,     2,     2,     0,     1,     3,     1,     2,
       1,     1,     1,     0,     3,     1,     0,     1,     3,     2,
       0,     1,     1,     2,     0,     1,     4,     1,     3,     1,
       3,     1,     0,     1,     3,     3,     2,     1,     3,     1,
       3,     1,     3,     4,     1,     1,     4,     3,     3,     6,
       6,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     1,     3,     3,     2,
       3,     1,     1,     3,     2,     1,     1,     5,     0,     1,
       1,     3,     2,     4,     3,     3,     3,     3,     3,     0,
       1,     0,     6,     1,     2,     1,     1,     1,     3,     1,
       3,     3,     3,     0,     2,     1,     4,     4,     4,     6,
       6,     1,     4,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     3,     1,     4,
       1,     1,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     3,     1,
       4,     3,     4,     1,     1,     3,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     4,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     1,     3,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     2,     1,     2,     2,     3,     1,     1,     3,     4,
       1,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     3,     1,     3,     1,     4,     4,     1,     1,     1,
       1,     1,     1,     0,     1,     2,     4,     0,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   304,   305,     0,     2,     3,     5,     1,     4,     7,
       0,     0,     8,   309,    15,    10,     0,    11,    13,    16,
       9,    12,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,    24,    22,    20,    23,    21,     0,    19,    14,
      52,     0,     0,    26,    36,    53,     0,    56,     0,    57,
      59,    61,     6,    40,     0,    37,    55,    54,     0,     0,
      39,     0,    41,    42,     0,    47,    49,    51,   187,     0,
     188,   189,   190,   191,   192,   200,   193,   194,   195,   196,
     197,   198,   199,    27,    28,    32,    30,    31,    35,     0,
       0,    58,    60,    38,    43,     0,     0,     0,    33,    29,
     293,   134,   306,     0,   169,     0,     0,   183,   176,   180,
     182,   170,     0,     0,   171,   175,   179,     0,     0,    65,
     185,   172,    64,   181,   138,     0,    44,    48,    50,    34,
       0,   297,    68,    67,   123,   294,   301,     0,   184,   178,
     177,   174,   173,     0,    71,     0,   172,    73,     0,   293,
       0,   186,     0,     0,    45,    46,     0,   299,   300,   298,
       0,     0,   205,   303,   302,   295,   135,   137,     0,     0,
       0,     0,     0,    63,   158,   164,   159,   289,   290,   165,
     166,   156,   157,    83,     0,    78,    80,    81,   160,   161,
      82,   288,   280,     0,   282,   287,   284,   143,   144,   139,
     140,   142,   136,   155,   153,   149,   150,   151,     0,   162,
     293,   293,     0,   100,     0,   131,     0,     0,   205,   205,
     125,   124,     0,     0,   122,   206,   207,   209,   293,    72,
      77,    76,    75,    74,   292,     0,   239,   238,     0,     0,
     237,   240,     0,   213,     0,   242,     0,   214,   217,   219,
     221,   223,   234,     0,   227,   228,   233,   291,   241,   244,
     243,    66,   293,   281,     0,     0,     0,     0,     0,     0,
     148,   145,     0,   278,   276,   276,   276,   102,   277,    98,
     276,   276,   109,     0,   296,     0,   293,     0,   293,     0,
     293,     0,     0,     0,   293,     0,     0,     0,   256,   258,
     257,   266,   267,     0,    70,    69,     0,   262,     0,     0,
     235,   236,     0,     0,     0,    62,     0,   201,   202,     0,
     203,   204,     0,     0,     0,     0,    79,   283,     0,     0,
     162,   141,   167,   154,   163,   152,   279,   107,     0,   106,
     108,    99,   276,   104,   105,     0,    97,   110,   101,     0,
     119,     0,    92,    95,    96,   293,   133,     0,     0,    85,
      86,    91,   276,   293,   307,     0,   307,     0,     0,   261,
       0,   211,   208,     0,     0,   218,   263,   264,   232,   230,
       0,   245,     0,   226,   215,   220,   222,   224,     0,   231,
     229,   286,   285,   168,   146,   147,   103,     0,   132,     0,
     126,   293,    94,   293,   127,   293,    89,   276,   293,   308,
     128,   293,   210,   259,   268,     0,     0,   270,   212,   265,
     249,     0,   247,   205,     0,   225,   111,   120,   121,    93,
      90,    87,    88,   123,   123,     0,     0,   272,   274,   269,
       0,   246,     0,   251,   216,     0,   129,   130,   260,   273,
       0,   271,   248,   254,   255,   253,   250,   252,   115,   116,
       0,     0,   113,   117,   275,     0,   112,   114,   118
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,     9,    11,    12,    16,    17,    28,
      29,    30,    42,    43,    83,    84,   129,    54,    55,    61,
      62,   155,    63,    64,    65,    44,    45,    48,    49,   183,
      85,   118,    86,   143,   144,   184,   185,   358,   359,   360,
     351,   352,   132,   342,   212,   213,   346,   347,   445,   461,
     462,   361,   362,   161,   162,   221,   119,   199,   200,   463,
     275,   276,    87,   205,   267,   206,   207,   245,   333,   120,
     121,   122,   123,   319,   322,   224,   225,   226,   227,   296,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     421,   422,   456,   457,   297,   298,   435,   299,   309,   300,
     301,   302,   416,   417,   437,   277,   278,   151,   193,   194,
     257,   258,   134,   135,   136,   160,   165,   259,   124,   408,
     260
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -292
static const short yypact[] =
{
     104,  -292,  -292,    27,   104,  -292,  -292,  -292,  -292,   -75,
      71,    17,  -292,  -292,  -292,  -292,    81,  -292,   -36,   141,
    -292,  -292,    90,   107,   134,   139,   182,   172,   181,   141,
    -292,   156,  -292,  -292,  -292,  -292,  -292,   243,  -292,  -292,
     245,    73,   235,  -292,   222,  -292,   171,  -292,    80,  -292,
     183,  -292,  -292,   167,   528,  -292,  -292,  -292,   186,   191,
    -292,   190,   186,  -292,   -21,  -292,   196,  -292,  -292,   293,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   528,  -292,  -292,  -292,  -292,  -292,   279,
     696,  -292,  -292,  -292,  -292,   104,   186,   204,  -292,  -292,
      -5,   201,  -292,   237,  -292,   249,   262,  -292,  -292,  -292,
    -292,  -292,   284,   255,  -292,  -292,  -292,   772,   341,   238,
    -292,   244,  -292,  -292,   227,   350,   -75,  -292,  -292,  -292,
     247,     5,  -292,  -292,  -292,  -292,   -12,   186,  -292,  -292,
    -292,  -292,  -292,     2,  -292,   248,  -292,   250,   251,    95,
      68,  -292,   270,   206,  -292,  -292,   233,  -292,  -292,  -292,
     347,   620,    36,  -292,  -292,  -292,  -292,  -292,   360,   772,
     186,   186,   442,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,   121,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   124,  -292,  -292,   256,  -292,  -292,   252,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,   253,   254,
     162,    52,   126,  -292,   257,   325,   271,   307,    89,    96,
    -292,  -292,   272,   397,  -292,  -292,  -292,   273,    -5,  -292,
    -292,  -292,  -292,  -292,  -292,   280,  -292,  -292,   105,    57,
    -292,  -292,   277,  -292,   442,  -292,   275,   281,   211,   215,
    -292,   285,  -292,   278,   105,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,    95,  -292,    30,   216,   304,   380,   381,   206,
    -292,  -292,   206,  -292,    20,    76,    20,  -292,  -292,   299,
      76,    20,   296,   233,  -292,   363,    58,   311,    40,   324,
      40,   326,   442,   368,   286,   104,   291,   292,  -292,  -292,
    -292,   306,  -292,   442,  -292,  -292,   554,   297,   309,   234,
    -292,  -292,   317,   320,   318,  -292,   310,  -292,  -292,   554,
    -292,  -292,   554,   554,   442,   411,  -292,  -292,   319,   327,
    -292,  -292,  -292,   426,  -292,  -292,  -292,  -292,   312,  -292,
    -292,  -292,    20,  -292,  -292,   348,  -292,  -292,  -292,   381,
     322,   129,  -292,  -292,  -292,   286,  -292,   364,   332,   323,
    -292,  -292,    20,   286,   381,   333,   381,   334,   335,  -292,
     337,  -292,  -292,   330,   349,  -292,  -292,   340,  -292,  -292,
     442,   273,     9,  -292,   331,   215,  -292,  -292,   351,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,   357,  -292,   216,
    -292,    58,  -292,   286,  -292,    41,  -292,    20,   286,  -292,
    -292,   286,  -292,  -292,  -292,    26,   140,  -292,  -292,  -292,
    -292,   151,  -292,    36,   509,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,   380,   381,   352,  -292,  -292,
     330,  -292,     9,   131,  -292,    19,  -292,  -292,   426,   352,
     381,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
      19,    53,  -292,  -292,  -292,    43,  -292,  -292,  -292
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -292,  -292,  -292,   462,  -292,  -292,   342,  -292,   451,  -292,
    -292,   440,  -292,  -292,  -292,   388,  -292,  -292,  -292,  -292,
    -292,  -292,   412,  -292,   377,  -292,  -292,  -292,   417,   329,
    -292,   -68,  -292,  -292,   314,  -292,   217,   188,  -292,    75,
    -292,    83,   258,  -292,  -292,   198,  -292,  -292,  -292,    25,
    -193,  -278,   -98,  -292,   -97,  -292,   200,  -292,   223,  -142,
     283,   287,  -292,    21,  -292,  -140,  -258,  -137,    55,   -71,
     -52,  -292,   -30,  -292,  -292,  -215,  -292,  -292,   179,  -161,
      72,  -292,   176,   177,  -291,  -292,  -292,  -118,  -292,  -292,
    -292,    59,  -292,  -292,  -292,  -292,  -292,  -292,   246,  -292,
    -292,  -292,  -292,    63,    70,  -255,  -292,  -292,  -292,   264,
    -136,  -292,  -110,  -292,  -292,  -292,  -292,     1,  -292,   143,
     -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -277
static const short yytable[] =
{
      18,     6,   133,   289,   291,     6,    18,   328,   353,   187,
     201,   246,   188,   189,   195,   375,   188,   189,    13,   337,
     339,   340,   125,   458,    88,   343,   344,     7,   130,   157,
      95,    51,   387,    10,   163,    13,   197,   198,   459,    13,
     177,   178,    50,    67,    90,   164,   145,   458,    51,    13,
      13,   186,    67,    88,    66,    89,    19,   458,   272,    50,
     197,   198,   459,    66,   310,   146,    13,    13,   270,   271,
     197,   198,   459,    90,    22,   357,   357,    13,   177,   178,
      13,    14,    13,   314,    89,   158,    67,   396,     1,     2,
      13,    14,    96,   220,   273,    46,   126,    66,   145,   159,
      31,   174,   175,   176,    13,   177,   178,   406,   179,   180,
     131,   168,   274,   279,   272,   169,   420,   146,   147,     1,
       2,   222,   187,   353,   201,   188,   189,   167,   195,   329,
     305,   367,   188,   189,   460,   188,   189,   191,   166,   190,
     196,   427,   374,   209,   436,   181,   223,   350,   350,   -84,
     273,   453,   432,   202,   208,   131,   131,    23,   460,   468,
     231,   233,   466,   388,   186,   350,    24,   131,   460,    32,
     147,   230,   232,   131,   222,   191,    13,   192,   270,   271,
      15,   222,     1,     2,    37,    47,   182,    25,   354,    26,
      20,   379,    57,    58,   338,    13,   369,   288,    27,   223,
     272,     1,     2,   172,   290,   454,   223,   390,   443,   455,
     131,   307,   174,   175,   176,    13,   177,   178,    60,   179,
     180,     1,     2,    33,   308,    13,   177,   178,    34,   311,
     261,     1,     2,   263,   262,   282,   273,   264,   400,   283,
      35,   175,   401,    13,   177,   178,   234,   179,   180,   439,
     210,   211,   190,   440,   196,   330,   181,   402,   334,   209,
     441,    36,   209,   428,   442,   407,   208,    39,   467,    40,
     208,  -276,   467,   208,   203,  -276,   355,   131,   363,    52,
     363,    53,   100,    56,   236,     1,     2,   197,   198,   -25,
     335,    59,    41,   336,   101,   102,   370,   182,   433,   378,
      92,   434,    93,   354,    97,   430,   103,    68,   104,    98,
     105,   312,   313,   128,   204,   317,   318,   320,   321,   137,
     106,   197,   198,   138,   107,   241,   101,   102,   108,   394,
     395,   109,    70,    71,    72,   139,   446,   447,   140,   398,
     141,   142,   110,    73,   148,   152,   149,   111,    74,   112,
      75,   113,   150,   153,   409,   156,   409,   214,    76,   172,
     114,   115,   170,   228,   171,   285,   265,    77,   269,    78,
     266,   268,   423,   284,    79,   116,    80,    81,    82,   286,
     287,   306,   292,   303,   315,   332,   323,   117,   324,   330,
      13,   355,   341,   349,   316,   363,   345,   364,   368,   366,
     208,   131,   371,   372,   175,   438,    13,   177,   178,   234,
     179,   180,     1,     2,   373,   377,   376,   384,   175,   235,
      13,   177,   178,   234,   179,   180,   438,   380,   382,   383,
     391,   393,   423,   293,   294,   397,   405,   403,   392,   399,
     464,   404,   410,   413,   424,   412,   414,   236,   237,   175,
     415,    13,   177,   178,   234,   179,   180,     1,     2,   419,
     418,   236,   425,   238,   235,   426,     8,    21,   154,    38,
     450,    99,   239,   127,    94,    91,   389,   173,   365,   326,
     431,   348,   240,   229,   429,   465,   304,   356,   241,   331,
     448,   381,   236,   237,   280,   385,   444,   242,   281,   386,
     325,   452,   241,   451,   243,   295,   449,   244,   238,   411,
       0,     0,     0,     0,     0,     0,   175,   239,    13,   177,
     178,   234,   179,   180,     1,     2,     0,   240,   327,     0,
       0,   235,     0,   241,     0,     0,     0,    13,     0,     0,
       0,     0,   242,     1,     2,     0,     0,     0,     0,   243,
       0,     0,   244,     0,     0,     0,    68,     0,     0,   236,
     237,   175,     0,    13,   177,   178,   234,   179,   180,     1,
       2,    69,     0,     0,     0,   238,     0,     0,     0,     0,
       0,    70,    71,    72,   239,     0,     0,     0,     0,     0,
       0,     0,    73,     0,   240,     0,     0,    74,     0,    75,
     241,     0,     0,     0,   236,   237,     0,    76,     0,   242,
       0,     0,     0,     0,     0,     0,    77,     0,    78,   244,
     238,     0,     0,    79,     0,    80,    81,    82,     0,   239,
       0,     0,     0,     0,     0,   101,   102,     0,     0,   240,
       0,     0,     0,   215,     0,   241,     0,   103,    68,   104,
       0,   105,   216,     0,   242,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   244,   107,     0,     0,     0,   108,
       0,     0,   109,    70,    71,    72,     0,     0,     0,     0,
       0,   217,     0,   110,    73,     0,     0,     0,   111,    74,
     112,    75,   113,     0,     0,     0,     0,     0,     0,    76,
       0,   114,   115,   218,   219,     0,     0,     0,    77,     0,
      78,   101,   102,     0,     0,    79,   116,    80,    81,    82,
       0,     0,     0,   103,    68,   104,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,   107,     0,     0,     0,   108,     0,     0,   109,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,   110,
      73,     0,     0,     0,   111,    74,   112,    75,   113,     0,
       0,     0,     0,     0,     0,    76,     0,   114,   115,     0,
       0,     0,     0,     0,    77,     0,    78,     1,     2,     0,
       0,    79,   116,    80,    81,    82,     0,     0,     0,   103,
      68,   104,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,   107,     0,     0,
       0,   108,     0,     0,   109,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,   110,    73,     0,     0,     0,
     111,    74,   112,    75,   113,     0,     0,     0,     0,     0,
       0,    76,     0,   114,   115,     0,     0,     0,     0,     0,
      77,     0,    78,     0,     0,     0,     0,    79,   116,    80,
      81,    82
};

static const short yycheck[] =
{
      10,     0,   100,   218,   219,     4,    16,   265,   286,   149,
     152,   172,   149,   149,   150,   306,   153,   153,     9,   274,
     275,   276,    90,     4,    54,   280,   281,     0,    33,    24,
      51,    41,   323,   108,    46,     9,    17,    18,    19,     9,
      10,    11,    41,    53,    54,    57,   117,     4,    58,     9,
       9,   149,    62,    83,    53,    54,    39,     4,    38,    58,
      17,    18,    19,    62,     7,   117,     9,     9,    16,    17,
      17,    18,    19,    83,   110,    35,    35,     9,    10,    11,
       9,    10,     9,   244,    83,    80,    96,   342,    15,    16,
       9,    10,   113,   161,    74,    22,    95,    96,   169,    94,
      10,     6,     7,     8,     9,    10,    11,   362,    13,    14,
     115,   109,   210,   211,    38,   113,   107,   169,   117,    15,
      16,    85,   262,   401,   266,   262,   262,   137,   264,   265,
     228,   292,   269,   269,   115,   272,   272,   107,   137,   149,
     150,   399,   303,   153,   118,    50,   110,   107,   107,   109,
      74,    20,   407,   152,   153,   115,   115,    16,   115,   116,
     170,   171,   109,   324,   262,   107,    25,   115,   115,    62,
     169,   170,   171,   115,    85,   107,     9,   109,    16,    17,
     109,    85,    15,    16,     3,   112,    91,    46,   286,    48,
     109,   309,   112,   113,   118,     9,   294,   108,    57,   110,
      38,    15,    16,   108,   108,    74,   110,   325,   423,    78,
     115,   106,     6,     7,     8,     9,    10,    11,    51,    13,
      14,    15,    16,    89,   119,     9,    10,    11,    89,   239,
     109,    15,    16,   109,   113,   109,    74,   113,   109,   113,
      58,     7,   113,     9,    10,    11,    12,    13,    14,   109,
      17,    18,   262,   113,   264,   265,    50,   355,   268,   269,
     109,    89,   272,   399,   113,   363,   265,   111,   461,    26,
     269,   109,   465,   272,    68,   113,   286,   115,   288,    44,
     290,    59,     3,   112,    50,    15,    16,    17,    18,    44,
     269,   108,    47,   272,    15,    16,   295,    91,   408,    65,
     109,   411,   112,   401,   108,   403,    27,    28,    29,    16,
      31,    34,    35,   109,   108,   104,   105,   102,   103,   118,
      41,    17,    18,    86,    45,    91,    15,    16,    49,    17,
      18,    52,    53,    54,    55,    86,   433,   434,    76,   349,
      56,    86,    63,    64,     3,   118,   108,    68,    69,    70,
      71,    72,   108,     3,   364,   108,   366,    10,    79,   108,
      81,    82,   114,     3,   114,    40,   110,    88,   114,    90,
     118,   118,   382,   116,    95,    96,    97,    98,    99,   108,
      73,   101,   110,   110,   109,     5,   101,   108,   110,   399,
       9,   401,    93,    30,   113,   405,   100,    73,    30,    73,
     399,   115,   111,   111,     7,   415,     9,    10,    11,    12,
      13,    14,    15,    16,   108,   106,   119,   107,     7,    22,
       9,    10,    11,    12,    13,    14,   436,   110,   108,   111,
     111,     5,   442,    36,    37,    87,   113,    73,   111,   117,
     450,   109,   109,   108,   113,   111,   109,    50,    51,     7,
     120,     9,    10,    11,    12,    13,    14,    15,    16,   119,
     111,    50,   111,    66,    22,   108,     4,    16,   126,    29,
     118,    83,    75,    96,    62,    58,    65,   148,   290,   262,
     405,   283,    85,   169,   401,   460,   228,   287,    91,   266,
     435,   312,    50,    51,   211,   319,   424,   100,   211,   322,
     254,   442,    91,   440,   107,   108,   436,   110,    66,   366,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    75,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    85,   264,    -1,
      -1,    22,    -1,    91,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,   100,    15,    16,    -1,    -1,    -1,    -1,   107,
      -1,    -1,   110,    -1,    -1,    -1,    28,    -1,    -1,    50,
      51,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    43,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    85,    -1,    -1,    69,    -1,    71,
      91,    -1,    -1,    -1,    50,    51,    -1,    79,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,   110,
      66,    -1,    -1,    95,    -1,    97,    98,    99,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    85,
      -1,    -1,    -1,    23,    -1,    91,    -1,    27,    28,    29,
      -1,    31,    32,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,   110,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    63,    64,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    88,    -1,
      90,    15,    16,    -1,    -1,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    90,    15,    16,    -1,
      -1,    95,    96,    97,    98,    99,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    15,    16,   122,   123,   124,   238,     0,   124,   125,
     108,   126,   127,     9,    10,   109,   128,   129,   241,    39,
     109,   129,   110,    16,    25,    46,    48,    57,   130,   131,
     132,    10,    62,    89,    89,    58,    89,     3,   132,   111,
      26,    47,   133,   134,   146,   147,    22,   112,   148,   149,
     238,   241,    44,    59,   138,   139,   112,   112,   113,   108,
      51,   140,   141,   143,   144,   145,   238,   241,    28,    43,
      53,    54,    55,    64,    69,    71,    79,    88,    90,    95,
      97,    98,    99,   135,   136,   151,   153,   183,   193,   238,
     241,   149,   109,   112,   143,    51,   113,   108,    16,   136,
       3,    15,    16,    27,    29,    31,    41,    45,    49,    52,
      63,    68,    70,    72,    81,    82,    96,   108,   152,   177,
     190,   191,   192,   193,   239,   152,   238,   145,   109,   137,
      33,   115,   163,   173,   233,   234,   235,   118,    86,    86,
      76,    56,    86,   154,   155,   190,   191,   238,     3,   108,
     108,   228,   118,     3,   127,   142,   108,    24,    80,    94,
     236,   174,   175,    46,    57,   237,   238,   241,   109,   113,
     114,   114,   108,   150,     6,     7,     8,    10,    11,    13,
      14,    50,    91,   150,   156,   157,   173,   186,   188,   231,
     241,   107,   109,   229,   230,   231,   241,    17,    18,   178,
     179,   180,   238,    68,   108,   184,   186,   187,   238,   241,
      17,    18,   165,   166,    10,    23,    32,    61,    83,    84,
     152,   176,    85,   110,   196,   197,   198,   199,     3,   155,
     238,   241,   238,   241,    12,    22,    50,    51,    66,    75,
      85,    91,   100,   107,   110,   188,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   231,   232,   238,
     241,   109,   113,   109,   113,   110,   118,   185,   118,   114,
      16,    17,    38,    74,   173,   181,   182,   226,   227,   173,
     181,   182,   109,   113,   116,    40,   108,    73,   108,   196,
     108,   196,   110,    36,    37,   108,   200,   215,   216,   218,
     220,   221,   222,   110,   163,   173,   101,   106,   119,   219,
       7,   241,    34,    35,   200,   109,   113,   104,   105,   194,
     102,   103,   195,   101,   110,   219,   157,   230,   187,   231,
     241,   179,     5,   189,   241,   184,   184,   226,   118,   226,
     226,    93,   164,   226,   226,   100,   167,   168,   166,    30,
     107,   161,   162,   172,   173,   241,   177,    35,   158,   159,
     160,   172,   173,   241,    73,   158,    73,   200,    30,   173,
     238,   111,   111,   108,   200,   205,   119,   106,    65,   208,
     110,   199,   108,   111,   107,   203,   204,   205,   200,    65,
     208,   111,   111,     5,    17,    18,   226,    87,   241,   117,
     109,   113,   173,    73,   109,   113,   226,   173,   240,   241,
     109,   240,   111,   108,   109,   120,   223,   224,   111,   119,
     107,   211,   212,   241,   113,   111,   108,   187,   231,   162,
     173,   160,   226,   233,   233,   217,   118,   225,   241,   109,
     113,   109,   113,   196,   201,   169,   175,   175,   189,   225,
     118,   224,   212,    20,    74,    78,   213,   214,     4,    19,
     115,   170,   171,   180,   241,   170,   109,   171,   116
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
#line 355 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 361 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 366 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 383 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 6:
#line 388 "asn1p_y.y"
    {

		yyval.a_module = currentModule;

		if(yyvsp[-1].a_module) {
			asn1p_module_t tmp = *(yyval.a_module);
			*(yyval.a_module) = *(yyvsp[-1].a_module);
			*(yyvsp[-1].a_module) = tmp;
			asn1p_module_free(yyvsp[-1].a_module);
		} else {
			/* There's a chance that a module is just plain empty */
		}

		yyval.a_module->ModuleName = yyvsp[-8].tv_str;
		yyval.a_module->module_oid = yyvsp[-6].a_oid;
		yyval.a_module->module_flags = yyvsp[-4].a_module_flags;
	}
    break;

  case 7:
#line 412 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 8:
#line 413 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 9:
#line 417 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 10:
#line 420 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 11:
#line 426 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 432 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 13:
#line 441 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 14:
#line 445 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 15:
#line 449 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 16:
#line 459 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 17:
#line 460 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 469 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 472 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 20:
#line 481 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 21:
#line 484 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 22:
#line 487 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 23:
#line 490 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 24:
#line 494 "asn1p_y.y"
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

  case 25:
#line 515 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 26:
#line 516 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 27:
#line 525 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		AL_IMPORT(yyval.a_module, exports, yyvsp[-2].a_module, xp_next);
		AL_IMPORT(yyval.a_module, imports, yyvsp[-1].a_module, xp_next);
		AL_IMPORT(yyval.a_module, members, yyvsp[0].a_module, next);
	}
    break;

  case 28:
#line 534 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 29:
#line 537 "asn1p_y.y"
    {
		if(yyvsp[-1].a_module) {
			yyval.a_module = yyvsp[-1].a_module;
		} else {
			yyval.a_module = yyvsp[0].a_module;
			break;
		}
		AL_IMPORT(yyval.a_module, members, yyvsp[0].a_module, next);
	}
    break;

  case 30:
#line 553 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 560 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 573 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 33:
#line 581 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 582 "asn1p_y.y"
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
#line 594 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 607 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 38:
#line 611 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 39:
#line 621 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 40:
#line 627 "asn1p_y.y"
    { yyval.a_module = asn1p_module_new(); }
    break;

  case 42:
#line 631 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 43:
#line 636 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 44:
#line 643 "asn1p_y.y"
    { memset(&yyval.a_aid, 0, sizeof(yyval.a_aid)); }
    break;

  case 45:
#line 644 "asn1p_y.y"
    { yyval.a_aid.oid = yyvsp[0].a_oid; }
    break;

  case 46:
#line 648 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->fromModuleName = yyvsp[-1].tv_str;
		yyval.a_xports->identifier = yyvsp[0].a_aid;
		/* This stupid thing is used for look-back hack. */
		saved_aid = yyval.a_xports->identifier.oid ? 0 : &(yyval.a_xports->identifier);
		checkmem(yyval.a_xports);
	}
    break;

  case 47:
#line 659 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 48:
#line 664 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 49:
#line 671 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 50:
#line 677 "asn1p_y.y"
    {		/* Completely equivalent to above */
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 683 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 693 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 53:
#line 694 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		if(yyvsp[0].a_xports) {
			TQ_ADD(&(yyval.a_module->exports), yyvsp[0].a_xports, xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
    break;

  case 54:
#line 706 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 55:
#line 709 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 56:
#line 712 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 57:
#line 720 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 58:
#line 725 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 59:
#line 732 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 60:
#line 738 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 744 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 753 "asn1p_y.y"
    { yyval.a_constr = yyvsp[-1].a_constr; }
    break;

  case 63:
#line 756 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 64:
#line 766 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 65:
#line 779 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 66:
#line 789 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[-3].a_ref;
		yyval.a_expr->rhs_pspecs = yyvsp[-1].a_expr;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 67:
#line 809 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 68:
#line 815 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 69:
#line 831 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 70:
#line 837 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 71:
#line 845 "asn1p_y.y"
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

  case 72:
#line 854 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 73:
#line 865 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 74:
#line 869 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 75:
#line 876 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 76:
#line 883 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 77:
#line 891 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 78:
#line 902 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 79:
#line 907 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 80:
#line 914 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 81:
#line 917 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = "?";
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 82:
#line 925 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		yyval.a_expr->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 83:
#line 936 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->expr_type = A1TC_VALUESET;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 84:
#line 959 "asn1p_y.y"
    { yyval.a_expr = NEW_EXPR(); }
    break;

  case 85:
#line 960 "asn1p_y.y"
    { yyval.a_expr = yyvsp[0].a_expr; }
    break;

  case 86:
#line 963 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 87:
#line 968 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 88:
#line 975 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 89:
#line 982 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 90:
#line 988 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 91:
#line 995 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 92:
#line 1001 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 93:
#line 1006 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 94:
#line 1013 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
	}
    break;

  case 95:
#line 1018 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 96:
#line 1021 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 97:
#line 1028 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 98:
#line 1038 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 99:
#line 1039 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 100:
#line 1043 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 101:
#line 1050 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 102:
#line 1060 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 103:
#line 1070 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		yyval.a_expr->unique = yyvsp[-1].a_int;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		asn1p_expr_add(yyval.a_expr, yyvsp[-2].a_expr);
	}
    break;

  case 104:
#line 1081 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 105:
#line 1091 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_OFS;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 106:
#line 1102 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVSFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 107:
#line 1112 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add(yyval.a_expr, yyvsp[-1].a_expr);
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 108:
#line 1123 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_OSFS;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 109:
#line 1135 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 110:
#line 1136 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 111:
#line 1143 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 112:
#line 1145 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 113:
#line 1151 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 114:
#line 1155 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 115:
#line 1162 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_opaque.buf, 0);
		yyval.a_wchunk->type = WC_WHITESPACE;
	}
    break;

  case 116:
#line 1166 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_str, 0);
	}
    break;

  case 117:
#line 1169 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].a_refcomp.name, 0);
		yyval.a_wchunk->type = WC_FIELD;
	}
    break;

  case 118:
#line 1173 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromsyntax(yyvsp[-1].a_wsynt);
	}
    break;

  case 119:
#line 1179 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 120:
#line 1187 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->value = yyvsp[0].a_value;
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 121:
#line 1196 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		yyval.a_expr->value = yyvsp[0].a_value;
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 122:
#line 1208 "asn1p_y.y"
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

  case 123:
#line 1230 "asn1p_y.y"
    {
		yyval.a_int = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 124:
#line 1237 "asn1p_y.y"
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

  case 125:
#line 1256 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 126:
#line 1259 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 127:
#line 1265 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 128:
#line 1271 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1277 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-4].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		yyvsp[0].a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_expr->tag = yyvsp[-1].a_tag;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 130:
#line 1287 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->constraints = yyvsp[-4].a_constr;
		yyval.a_expr->expr_type = ASN_CONSTR_SET_OF;
		yyval.a_expr->meta_type = AMT_TYPE;
		yyvsp[0].a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_expr->tag = yyvsp[-1].a_tag;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 131:
#line 1297 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 132:
#line 1303 "asn1p_y.y"
    {
		int ret;
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_expr->reference,
			yyvsp[0].tv_str, RLT_lowercase);
		checkmem(ret == 0);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 133:
#line 1314 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1329 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 135:
#line 1337 "asn1p_y.y"
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

  case 136:
#line 1347 "asn1p_y.y"
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

  case 137:
#line 1357 "asn1p_y.y"
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

  case 138:
#line 1367 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 139:
#line 1375 "asn1p_y.y"
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

  case 140:
#line 1397 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 141:
#line 1405 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 143:
#line 1418 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 144:
#line 1423 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 145:
#line 1432 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 146:
#line 1436 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 147:
#line 1440 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_Amplowercase);
	}
    break;

  case 148:
#line 1447 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
	}
    break;

  case 149:
#line 1467 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 152:
#line 1479 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_CHOICE_IDENTIFIER;
		yyval.a_value->value.choice_identifier.identifier = yyvsp[-2].tv_str;
		yyval.a_value->value.choice_identifier.value = yyvsp[0].a_value;
	}
    break;

  case 153:
#line 1486 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 154:
#line 1486 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 155:
#line 1491 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_NULL;
	}
    break;

  case 156:
#line 1499 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 157:
#line 1504 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 158:
#line 1509 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 159:
#line 1513 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 160:
#line 1517 "asn1p_y.y"
    {
		yyval.a_value = yyval.a_value;
	}
    break;

  case 161:
#line 1520 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 162:
#line 1526 "asn1p_y.y"
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

  case 163:
#line 1537 "asn1p_y.y"
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

  case 164:
#line 1555 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 165:
#line 1559 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TUPLE;
	}
    break;

  case 166:
#line 1564 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_QUADRUPLE;
	}
    break;

  case 167:
#line 1598 "asn1p_y.y"
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

  case 168:
#line 1607 "asn1p_y.y"
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

  case 169:
#line 1622 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 170:
#line 1623 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 171:
#line 1624 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 172:
#line 1625 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 173:
#line 1626 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 174:
#line 1627 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 175:
#line 1628 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 176:
#line 1629 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 177:
#line 1630 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 178:
#line 1631 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 179:
#line 1632 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 180:
#line 1633 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 181:
#line 1634 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 182:
#line 1641 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 183:
#line 1642 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 184:
#line 1643 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 185:
#line 1647 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 186:
#line 1653 "asn1p_y.y"
    {
		if(yyvsp[0].a_expr) {
			yyval.a_expr = yyvsp[0].a_expr;
		} else {
			yyval.a_expr = NEW_EXPR();
			checkmem(yyval.a_expr);
		}
		yyval.a_expr->expr_type = yyvsp[-1].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 187:
#line 1666 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 188:
#line 1667 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 189:
#line 1671 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 190:
#line 1675 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 191:
#line 1676 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 192:
#line 1677 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 193:
#line 1678 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 194:
#line 1679 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 195:
#line 1683 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 196:
#line 1684 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 197:
#line 1685 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 198:
#line 1686 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 199:
#line 1690 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 200:
#line 1691 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 205:
#line 1702 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 206:
#line 1703 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 208:
#line 1710 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 209:
#line 1716 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 210:
#line 1719 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 211:
#line 1729 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 212:
#line 1732 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 213:
#line 1738 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 214:
#line 1742 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 215:
#line 1745 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 216:
#line 1751 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 218:
#line 1763 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_AEX, yyvsp[0].a_constr, 0);
	}
    break;

  case 220:
#line 1770 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 222:
#line 1777 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 224:
#line 1785 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 225:
#line 1791 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 226:
#line 1799 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 227:
#line 1807 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 228:
#line 1813 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_TYPE;
		yyval.a_constr->containedSubtype = yyvsp[0].a_value;
	}
    break;

  case 229:
#line 1819 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 230:
#line 1826 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 231:
#line 1834 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 232:
#line 1842 "asn1p_y.y"
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

  case 233:
#line 1851 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 234:
#line 1854 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 235:
#line 1860 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_CT_PATTERN;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
	}
    break;

  case 236:
#line 1865 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, yyvsp[0].tv_str, RLT_lowercase);
		yyval.a_constr->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 237:
#line 1876 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 238:
#line 1879 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 239:
#line 1885 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 240:
#line 1890 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 243:
#line 1897 "asn1p_y.y"
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

  case 244:
#line 1911 "asn1p_y.y"
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

  case 245:
#line 1925 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMP, yyvsp[0].a_constr, 0);
	}
    break;

  case 246:
#line 1928 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 247:
#line 1934 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 248:
#line 1937 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 249:
#line 1943 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
		yyval.a_constr->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 250:
#line 1949 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
		if(yyvsp[-1].a_constr) asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 251:
#line 1963 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 252:
#line 1964 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 253:
#line 1968 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 254:
#line 1971 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 255:
#line 1974 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 259:
#line 1989 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 260:
#line 1989 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CT_CTDBY;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_constr->value);
		yyval.a_constr->value->type = ATV_UNPARSED;
	}
    break;

  case 261:
#line 2000 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_CT_CTNG;
		yyval.a_constr->value = asn1p_value_fromtype(yyvsp[0].a_expr);
	}
    break;

  case 262:
#line 2008 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 263:
#line 2009 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 264:
#line 2010 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 265:
#line 2011 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 266:
#line 2014 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 267:
#line 2017 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 268:
#line 2026 "asn1p_y.y"
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

  case 269:
#line 2041 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 270:
#line 2047 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 271:
#line 2053 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 272:
#line 2067 "asn1p_y.y"
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

  case 273:
#line 2078 "asn1p_y.y"
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

  case 274:
#line 2094 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 275:
#line 2097 "asn1p_y.y"
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

  case 276:
#line 2115 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_NOMARK;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 277:
#line 2119 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 278:
#line 2123 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_OPTIONAL | EM_INDIRECT;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 279:
#line 2127 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_DEFAULT;
		yyval.a_marker.default_value = yyvsp[0].a_value;
	}
    break;

  case 280:
#line 2150 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
	}
    break;

  case 281:
#line 2154 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 282:
#line 2160 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 283:
#line 2165 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 284:
#line 2172 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 285:
#line 2179 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 286:
#line 2187 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 287:
#line 2195 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 288:
#line 2202 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 289:
#line 2213 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 290:
#line 2217 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 292:
#line 2225 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromdouble(yyvsp[0].a_dbl);
		checkmem(yyval.a_value);
	}
    break;

  case 293:
#line 2256 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 294:
#line 2257 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 295:
#line 2261 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = yyvsp[0].a_tag.tag_mode;
	}
    break;

  case 296:
#line 2268 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-2].a_tag;
		yyval.a_tag.tag_value = yyvsp[-1].a_int;
	}
    break;

  case 297:
#line 2274 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 298:
#line 2275 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_UNIVERSAL; }
    break;

  case 299:
#line 2276 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_APPLICATION; }
    break;

  case 300:
#line 2277 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_PRIVATE; }
    break;

  case 301:
#line 2281 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_DEFAULT; }
    break;

  case 302:
#line 2282 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_IMPLICIT; }
    break;

  case 303:
#line 2283 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_EXPLICIT; }
    break;

  case 304:
#line 2287 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 305:
#line 2291 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 306:
#line 2299 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 307:
#line 2306 "asn1p_y.y"
    { yyval.tv_str = 0; }
    break;

  case 308:
#line 2307 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 309:
#line 2313 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 4385 "asn1p_y.c"

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


#line 2319 "asn1p_y.y"



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


