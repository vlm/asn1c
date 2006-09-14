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
#line 85 "asn1p_y.y"
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
#line 405 "asn1p_y.c"
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
#line 426 "asn1p_y.c"

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
#define YYLAST   816

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  112
/* YYNRULES -- Number of rules. */
#define YYNRULES  296
/* YYNRULES -- Number of states. */
#define YYNSTATES  453

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
       0,     0,     3,     5,     7,    10,    19,    20,    22,    26,
      29,    31,    34,    36,    41,    43,    44,    46,    48,    51,
      54,    57,    60,    63,    66,    67,    69,    73,    75,    78,
      80,    82,    84,    85,    89,    91,    92,    94,    98,   101,
     103,   106,   107,   109,   114,   116,   120,   122,   126,   128,
     129,   131,   135,   139,   142,   144,   148,   150,   154,   156,
     160,   165,   167,   169,   174,   178,   182,   189,   196,   198,
     202,   204,   208,   212,   216,   220,   222,   226,   228,   230,
     232,   234,   235,   237,   239,   243,   247,   250,   254,   256,
     258,   262,   265,   267,   269,   275,   276,   278,   280,   284,
     287,   292,   296,   300,   304,   308,   312,   313,   315,   316,
     323,   325,   328,   330,   332,   334,   338,   340,   344,   348,
     352,   353,   356,   358,   363,   368,   373,   380,   387,   389,
     394,   398,   400,   404,   408,   412,   414,   418,   420,   424,
     426,   428,   430,   432,   436,   440,   442,   447,   449,   451,
     455,   456,   460,   462,   464,   466,   468,   470,   472,   474,
     476,   480,   482,   484,   486,   488,   491,   493,   495,   497,
     499,   502,   505,   507,   509,   512,   515,   517,   519,   521,
     523,   525,   528,   530,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   561,   563,
     565,   567,   569,   571,   572,   574,   576,   581,   585,   590,
     592,   594,   598,   604,   606,   610,   614,   618,   622,   627,
     631,   633,   635,   639,   643,   647,   651,   653,   655,   656,
     662,   664,   667,   670,   674,   676,   678,   680,   682,   684,
     686,   688,   690,   694,   700,   702,   706,   708,   712,   713,
     715,   717,   719,   721,   723,   725,   729,   734,   736,   740,
     743,   747,   749,   753,   754,   756,   758,   761,   764,   768,
     770,   774,   776,   781,   786,   788,   790,   792,   794,   796,
     798,   799,   801,   804,   809,   810,   812,   814,   816,   817,
     819,   821,   823,   825,   827,   828,   830
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     122,     0,    -1,   123,    -1,   124,    -1,   123,   124,    -1,
     229,   125,    39,   129,     3,    26,   132,    44,    -1,    -1,
     126,    -1,   108,   127,   109,    -1,   108,   109,    -1,   128,
      -1,   127,   128,    -1,   232,    -1,   232,   110,    10,   111,
      -1,    10,    -1,    -1,   130,    -1,   131,    -1,   130,   131,
      -1,    46,    89,    -1,    57,    89,    -1,    25,    89,    -1,
      48,    58,    -1,    16,    62,    -1,    -1,   133,    -1,   144,
     137,   134,    -1,   135,    -1,   134,   135,    -1,   151,    -1,
     181,    -1,   149,    -1,    -1,    43,    16,   136,    -1,   191,
      -1,    -1,   138,    -1,    59,   139,   112,    -1,    59,    51,
      -1,   141,    -1,   139,   141,    -1,    -1,   126,    -1,   142,
      51,   229,   140,    -1,   143,    -1,   142,   113,   143,    -1,
     229,    -1,   229,   108,   109,    -1,   232,    -1,    -1,   145,
      -1,    47,   146,   112,    -1,    47,    22,   112,    -1,    47,
     112,    -1,   147,    -1,   146,   113,   147,    -1,   229,    -1,
     229,   108,   109,    -1,   232,    -1,   108,   198,   109,    -1,
     229,   150,     3,   148,    -1,   190,    -1,   175,    -1,   175,
     108,   154,   109,    -1,   229,     3,   171,    -1,   229,     3,
     161,    -1,   229,   108,   152,   109,     3,   171,    -1,   229,
     108,   152,   109,     3,   161,    -1,   153,    -1,   152,   113,
     153,    -1,   229,    -1,   229,   114,   232,    -1,   229,   114,
     229,    -1,   188,   114,   232,    -1,   188,   114,   229,    -1,
     155,    -1,   154,   113,   155,    -1,   171,    -1,   184,    -1,
     232,    -1,   148,    -1,    -1,   157,    -1,   158,    -1,   157,
     113,   158,    -1,   232,   171,   217,    -1,   171,   217,    -1,
      35,    73,   171,    -1,   170,    -1,   160,    -1,   159,   113,
     160,    -1,   232,   171,    -1,   170,    -1,   171,    -1,    33,
     108,   163,   109,   165,    -1,    -1,    93,    -1,   164,    -1,
     163,   113,   164,    -1,    17,   217,    -1,    18,   171,   162,
     217,    -1,    18,   179,   217,    -1,    18,   180,   217,    -1,
      17,   179,   217,    -1,    17,   171,   217,    -1,    17,   180,
     217,    -1,    -1,   166,    -1,    -1,   100,    87,   108,   167,
     168,   109,    -1,   169,    -1,   168,   169,    -1,     4,    -1,
      19,    -1,   178,    -1,   115,   168,   116,    -1,   107,    -1,
     107,   117,   185,    -1,   107,   117,   222,    -1,   224,   173,
     195,    -1,    -1,   172,   174,    -1,   150,    -1,    32,   108,
     159,   109,    -1,    83,   108,   156,   109,    -1,    84,   108,
     156,   109,    -1,    83,   195,    73,   231,   224,   173,    -1,
      84,   195,    73,   231,   224,   173,    -1,    23,    -1,    23,
      40,    30,   232,    -1,    61,    73,   175,    -1,    15,    -1,
      15,   118,   229,    -1,   230,   118,   229,    -1,    15,   118,
     232,    -1,   230,    -1,   230,   118,   176,    -1,   177,    -1,
     176,   118,   177,    -1,   178,    -1,    17,    -1,    18,    -1,
      17,    -1,   179,   118,    17,    -1,   179,   118,    18,    -1,
      16,    -1,   232,   150,     3,   182,    -1,   184,    -1,   185,
      -1,   232,   114,   182,    -1,    -1,   108,   183,   187,    -1,
      68,    -1,    50,    -1,    91,    -1,     6,    -1,     8,    -1,
     186,    -1,   222,    -1,   232,    -1,   229,   118,   232,    -1,
       7,    -1,    13,    -1,    14,    -1,     5,    -1,   187,     5,
      -1,    29,    -1,    68,    -1,    81,    -1,   189,    -1,    72,
      86,    -1,    70,    56,    -1,    82,    -1,    49,    -1,    41,
      76,    -1,    31,    86,    -1,    96,    -1,    52,    -1,   191,
      -1,    63,    -1,    45,    -1,    27,    86,    -1,   188,    -1,
     189,   219,    -1,    28,    -1,    53,    -1,    54,    -1,    55,
      -1,    64,    -1,    69,    -1,    79,    -1,    88,    -1,    90,
      -1,    95,    -1,    97,    -1,    98,    -1,    99,    -1,    71,
      -1,   104,    -1,   105,    -1,   102,    -1,   103,    -1,   101,
      -1,    -1,   196,    -1,   197,    -1,    85,   110,   198,   111,
      -1,   110,   198,   111,    -1,   197,   110,   198,   111,    -1,
     107,    -1,   199,    -1,   199,   113,   107,    -1,   199,   113,
     107,   113,   199,    -1,   200,    -1,    22,   101,   200,    -1,
     199,   192,   200,    -1,   199,   193,   200,    -1,   200,   194,
     200,    -1,   203,   110,   198,   111,    -1,   110,   198,   111,
      -1,   204,    -1,   205,    -1,   204,   202,   204,    -1,    66,
     202,   204,    -1,   204,   202,    65,    -1,    66,   202,    65,
      -1,   211,    -1,   206,    -1,    -1,    36,    30,   108,   201,
     187,    -1,   106,    -1,   106,   119,    -1,   119,   106,    -1,
     119,   106,   119,    -1,    85,    -1,    51,    -1,    50,    -1,
      91,    -1,   223,    -1,   186,    -1,   232,    -1,   229,    -1,
     100,    34,   197,    -1,   100,    35,   108,   207,   109,    -1,
     208,    -1,   207,   113,   208,    -1,   107,    -1,   232,   195,
     209,    -1,    -1,   210,    -1,    78,    -1,    20,    -1,    74,
      -1,   212,    -1,   213,    -1,   108,   229,   109,    -1,   212,
     108,   214,   109,    -1,   215,    -1,   214,   113,   215,    -1,
     120,   216,    -1,   120,   118,   216,    -1,   232,    -1,   216,
     118,   232,    -1,    -1,   218,    -1,    74,    -1,    38,   182,
      -1,   108,   109,    -1,   108,   220,   109,    -1,   221,    -1,
     220,   113,   221,    -1,   232,    -1,   232,   110,   222,   111,
      -1,   232,   110,   185,   111,    -1,   222,    -1,   107,    -1,
      10,    -1,    11,    -1,   222,    -1,    12,    -1,    -1,   225,
      -1,   226,   228,    -1,   115,   227,    10,   116,    -1,    -1,
      94,    -1,    24,    -1,    80,    -1,    -1,    57,    -1,    46,
      -1,    15,    -1,    16,    -1,    16,    -1,    -1,   232,    -1,
       9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   342,   342,   348,   354,   370,   395,   397,   400,   404,
     409,   416,   424,   429,   433,   442,   444,   452,   456,   464,
     468,   471,   474,   478,   498,   500,   508,   517,   521,   536,
     544,   557,   565,   564,   578,   590,   592,   594,   605,   610,
     616,   622,   624,   627,   638,   644,   650,   657,   663,   672,
     674,   685,   689,   692,   699,   705,   711,   718,   724,   733,
     735,   745,   759,   769,   785,   795,   811,   817,   824,   834,
     844,   849,   856,   863,   871,   881,   887,   893,   897,   905,
     916,   938,   940,   942,   948,   954,   962,   968,   975,   980,
     986,   992,   998,  1001,  1007,  1017,  1019,  1022,  1030,  1037,
    1050,  1061,  1071,  1082,  1092,  1103,  1114,  1116,  1123,  1121,
    1130,  1135,  1141,  1146,  1149,  1153,  1158,  1167,  1176,  1187,
    1209,  1216,  1235,  1239,  1245,  1251,  1257,  1267,  1277,  1283,
    1294,  1308,  1317,  1327,  1337,  1347,  1355,  1376,  1385,  1394,
    1396,  1403,  1410,  1416,  1420,  1426,  1446,  1456,  1458,  1459,
    1466,  1466,  1471,  1478,  1484,  1489,  1493,  1497,  1500,  1505,
    1517,  1534,  1539,  1544,  1577,  1587,  1601,  1603,  1604,  1605,
    1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1620,
    1622,  1623,  1626,  1633,  1645,  1647,  1651,  1655,  1656,  1657,
    1658,  1659,  1663,  1664,  1665,  1666,  1670,  1671,  1678,  1678,
    1679,  1679,  1680,  1682,  1684,  1689,  1693,  1702,  1706,  1711,
    1716,  1719,  1725,  1735,  1739,  1742,  1745,  1748,  1753,  1762,
    1770,  1776,  1782,  1789,  1797,  1805,  1814,  1817,  1821,  1820,
    1831,  1833,  1834,  1835,  1838,  1842,  1847,  1853,  1858,  1859,
    1860,  1873,  1887,  1891,  1896,  1900,  1905,  1912,  1925,  1927,
    1930,  1934,  1937,  1942,  1946,  1954,  1969,  1975,  1982,  1995,
    2007,  2022,  2026,  2043,  2048,  2051,  2056,  2078,  2083,  2088,
    2094,  2100,  2108,  2116,  2124,  2131,  2141,  2146,  2152,  2154,
    2184,  2186,  2189,  2196,  2202,  2204,  2205,  2206,  2209,  2211,
    2212,  2215,  2220,  2227,  2234,  2236,  2241
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
  "ParsedGrammar", "ModuleList", "ModuleDefinition", 
  "optObjectIdentifier", "ObjectIdentifier", "ObjectIdentifierBody", 
  "ObjectIdentifierElement", "optModuleDefinitionFlags", 
  "ModuleDefinitionFlags", "ModuleDefinitionFlag", "optModuleBody", 
  "ModuleBody", "AssignmentList", "Assignment", "@1", "optImports", 
  "ImportsDefinition", "ImportsBundleSet", "AssignedIdentifier", 
  "ImportsBundle", "ImportsList", "ImportsElement", "optExports", 
  "ExportsDefinition", "ExportsBody", "ExportsElement", "ValueSet", 
  "ValueSetTypeAssignment", "DefinedType", "DataTypeReference", 
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList", 
  "ActualParameter", "optComponentTypeLists", "ComponentTypeLists", 
  "ComponentType", "AlternativeTypeLists", "AlternativeType", 
  "ObjectClass", "optUnique", "FieldSpec", "ClassField", "optWithSyntax", 
  "WithSyntax", "@2", "WithSyntaxList", "WithSyntaxToken", 
  "ExtensionAndException", "Type", "NSTD_IndirectMarker", 
  "TypeDeclaration", "TypeDeclarationSet", "ComplexTypeReference", 
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement", 
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass", 
  "ValueDefinition", "Value", "@3", "SimpleValue", "DefinedValue", 
  "RestrictedCharacterStringValue", "Opaque", "BasicTypeId", 
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString", 
  "Union", "Intersection", "Except", "optConstraints", "Constraints", 
  "SetOfConstraints", "ElementSetSpecs", "ElementSetSpec", 
  "ConstraintSubtypeElement", "@4", "ConstraintRangeSpec", 
  "ConstraintSpec", "SingleValue", "ContainedSubtype", 
  "InnerTypeConstraint", "WithComponentsList", "WithComponentsElement", 
  "optPresenceConstraint", "PresenceConstraint", "TableConstraint", 
  "SimpleTableConstraint", "ComponentRelationConstraint", 
  "AtNotationList", "AtNotationElement", "ComponentIdList", "optMarker", 
  "Marker", "UniverationDefinition", "UniverationList", 
  "UniverationElement", "SignedNumber", "RealValue", "optTag", "Tag", 
  "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName", 
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
       0,   121,   122,   123,   123,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   131,   131,   131,   132,   132,   133,   134,   134,   135,
     135,   135,   136,   135,   135,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   142,   142,   143,   143,   143,   144,
     144,   145,   145,   145,   146,   146,   147,   147,   147,   148,
     149,   150,   150,   150,   151,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   154,   154,   155,   155,   155,
     155,   156,   156,   157,   157,   158,   158,   158,   158,   159,
     159,   160,   160,   160,   161,   162,   162,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   165,   165,   167,   166,
     168,   168,   169,   169,   169,   169,   170,   170,   170,   171,
     172,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   176,   176,   177,
     178,   178,   179,   179,   179,   180,   181,   182,   182,   182,
     183,   182,   182,   184,   184,   184,   184,   184,   184,   185,
     185,   186,   186,   186,   187,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   189,
     189,   189,   190,   190,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   192,   192,
     193,   193,   194,   195,   195,   196,   196,   197,   197,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   201,   200,
     202,   202,   202,   202,   203,   203,   204,   204,   204,   204,
     204,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   210,   210,   211,   211,   212,   213,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   221,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   226,   227,   227,   227,   227,   228,   228,
     228,   229,   229,   230,   231,   231,   232
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     1,     3,     1,     2,     1,
       1,     1,     0,     3,     1,     0,     1,     3,     2,     1,
       2,     0,     1,     4,     1,     3,     1,     3,     1,     0,
       1,     3,     3,     2,     1,     3,     1,     3,     1,     3,
       4,     1,     1,     4,     3,     3,     6,     6,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     0,     1,     1,     3,     3,     2,     3,     1,     1,
       3,     2,     1,     1,     5,     0,     1,     1,     3,     2,
       4,     3,     3,     3,     3,     3,     0,     1,     0,     6,
       1,     2,     1,     1,     1,     3,     1,     3,     3,     3,
       0,     2,     1,     4,     4,     4,     6,     6,     1,     4,
       3,     1,     3,     3,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     1,     4,     1,     1,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     4,     3,     4,     1,
       1,     3,     5,     1,     3,     3,     3,     3,     4,     3,
       1,     1,     3,     3,     3,     3,     1,     1,     0,     5,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     1,     3,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     3,     1,
       3,     1,     4,     4,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     4,     0,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   291,   292,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   296,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    23,    21,    19,    22,    20,     0,    18,    13,    49,
       0,     0,    25,    35,    50,     0,    53,     0,    54,    56,
      58,     5,     0,     0,    36,    52,    51,     0,     0,    38,
       0,    39,     0,    44,    46,    48,   184,     0,   185,   186,
     187,   188,   189,   197,   190,   191,   192,   193,   194,   195,
     196,    26,    27,    31,    29,    30,    34,     0,     0,    55,
      57,    37,    40,     0,     0,     0,    32,    28,   280,   131,
     293,     0,   166,     0,     0,   180,   173,   177,   179,   167,
       0,     0,   168,   172,   176,     0,     0,    62,   182,   169,
      61,   178,   135,     0,    41,    45,    47,    33,     0,   284,
      65,    64,   120,   281,   288,     0,   181,   175,   174,   171,
     170,     0,    68,     0,   169,    70,     0,   280,     0,   183,
       0,     0,    42,    43,     0,   286,   287,   285,     0,     0,
     203,   290,   289,   282,   132,   134,     0,     0,     0,     0,
       0,    60,   155,   161,   156,   276,   277,   162,   163,   153,
     154,    80,     0,    75,    77,    78,   157,   158,    79,   275,
     267,     0,   269,   274,   271,   140,   141,   136,   137,   139,
     133,   152,   150,   146,   147,   148,     0,   159,   280,   280,
       0,    97,     0,   128,     0,     0,   203,   203,   122,   121,
       0,     0,   119,   204,   205,   280,    69,    74,    73,    72,
      71,   279,     0,     0,   236,   235,     0,   234,   237,     0,
     209,     0,     0,   239,     0,   210,   213,     0,   220,   221,
     227,   226,   253,   254,   278,   238,   241,   240,    63,   280,
     268,     0,     0,     0,     0,     0,     0,   145,   142,     0,
     265,   263,   263,   263,    99,   264,    95,   263,   263,   106,
       0,   283,     0,   280,     0,   280,     0,   280,     0,     0,
       0,     0,    67,    66,     0,     0,   230,     0,     0,     0,
       0,     0,     0,    59,   200,   201,   198,   199,     0,     0,
       0,   202,     0,     0,     0,     0,    76,   270,     0,     0,
     159,   138,   164,   151,   160,   149,   266,   104,     0,   103,
     105,    96,   263,   101,   102,     0,    94,   107,    98,     0,
     116,     0,    89,    92,    93,   280,   130,     0,     0,    82,
      83,    88,   263,   280,   294,     0,   294,     0,   207,     0,
     214,   228,   231,   232,   225,   223,   242,     0,   255,   219,
     211,   215,   216,   217,     0,   224,   222,     0,     0,   257,
     273,   272,   165,   143,   144,   100,     0,   129,     0,   123,
     280,    91,   280,   124,   280,    86,   263,   280,   295,   125,
     280,   206,   208,     0,   233,   246,     0,   244,   203,     0,
     218,     0,   259,   261,   256,     0,   108,   117,   118,    90,
      87,    84,    85,   120,   120,   229,   243,     0,   248,   212,
     260,     0,   258,     0,   126,   127,   245,   251,   252,   250,
     247,   249,   262,   112,   113,     0,     0,   110,   114,     0,
     109,   111,   115
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    27,    28,
      29,    41,    42,    81,    82,   127,    53,    54,    60,   153,
      61,    62,    63,    43,    44,    47,    48,   181,    83,   116,
      84,   141,   142,   182,   183,   348,   349,   350,   341,   342,
     130,   332,   210,   211,   336,   337,   433,   446,   447,   351,
     352,   159,   160,   219,   117,   197,   198,   448,   272,   273,
      85,   203,   264,   204,   205,   243,   323,   118,   119,   120,
     121,   309,   310,   312,   222,   223,   224,   244,   245,   246,
     403,   298,   247,   248,   249,   250,   406,   407,   440,   441,
     251,   252,   253,   378,   379,   412,   274,   275,   149,   191,
     192,   254,   255,   132,   133,   134,   158,   163,   256,   122,
     397,   257
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -357
static const short yypact[] =
{
      83,  -357,  -357,    18,    83,  -357,   -80,  -357,  -357,    64,
       3,  -357,  -357,  -357,  -357,    74,  -357,     2,   266,  -357,
    -357,   139,   100,    88,    90,   148,   142,   230,   266,  -357,
     135,  -357,  -357,  -357,  -357,  -357,   242,  -357,  -357,   127,
      53,   233,  -357,   238,  -357,   177,  -357,    80,  -357,   199,
    -357,  -357,   173,   256,  -357,  -357,  -357,   213,   206,  -357,
      55,  -357,     8,  -357,   211,  -357,  -357,   308,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,   256,  -357,  -357,  -357,  -357,  -357,   345,   641,  -357,
    -357,  -357,  -357,    83,   213,   217,  -357,  -357,   -23,   222,
    -357,   257,  -357,   271,   276,  -357,  -357,  -357,  -357,  -357,
     303,   281,  -357,  -357,  -357,   717,   359,   261,  -357,   262,
    -357,  -357,   253,   372,   -80,  -357,  -357,  -357,   269,     6,
    -357,  -357,  -357,  -357,   134,   213,  -357,  -357,  -357,  -357,
    -357,    89,  -357,   264,  -357,   273,   272,    95,    69,  -357,
     277,   205,  -357,  -357,   300,  -357,  -357,  -357,   373,   565,
     -61,  -357,  -357,  -357,  -357,  -357,   381,   717,   213,   213,
     445,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,    92,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,   114,  -357,  -357,   278,  -357,  -357,   274,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   275,   282,    72,    40,
     117,  -357,   279,   351,   293,   330,    87,    99,  -357,  -357,
     294,   445,  -357,  -357,   295,   -23,  -357,  -357,  -357,  -357,
    -357,  -357,   305,   377,  -357,  -357,   -79,  -357,  -357,   287,
    -357,    83,   445,  -357,   301,   229,   310,   302,   -79,  -357,
    -357,  -357,   312,  -357,  -357,  -357,  -357,  -357,  -357,    95,
    -357,    27,   270,   311,   414,   412,   205,  -357,  -357,   205,
    -357,   116,   126,   116,  -357,  -357,   332,   126,   116,   323,
     300,  -357,   398,    41,   334,     4,   356,     4,   357,   445,
     320,   445,  -357,  -357,   491,   324,   315,   331,   225,   326,
     337,   329,   328,  -357,  -357,  -357,  -357,  -357,   339,   491,
     491,  -357,   491,   445,   291,   327,  -357,  -357,   338,   340,
    -357,  -357,  -357,   443,  -357,  -357,  -357,  -357,   346,  -357,
    -357,  -357,   116,  -357,  -357,   363,  -357,  -357,  -357,   412,
     347,   138,  -357,  -357,  -357,   348,  -357,   389,   360,   352,
    -357,  -357,   116,   348,   412,   362,   412,   355,  -357,   369,
    -357,  -357,  -357,   349,  -357,  -357,   295,    51,  -357,  -357,
     370,  -357,  -357,  -357,   371,  -357,  -357,    10,   145,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,   376,  -357,   270,  -357,
      41,  -357,   348,  -357,    46,  -357,   116,   348,  -357,  -357,
     348,  -357,  -357,   414,  -357,  -357,   174,  -357,   -61,   463,
    -357,   412,   368,  -357,  -357,   327,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,   443,  -357,    51,   130,   234,
     368,   412,  -357,    28,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,    28,    48,  -357,  -357,    16,
    -357,  -357,  -357
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -357,  -357,  -357,   483,  -357,   364,  -357,   474,  -357,  -357,
     462,  -357,  -357,  -357,   410,  -357,  -357,  -357,  -357,  -357,
     432,  -357,   399,  -357,  -357,  -357,   437,   366,  -357,   -62,
    -357,  -357,   341,  -357,   250,   210,  -357,   121,  -357,   120,
     292,  -357,  -357,   236,  -357,  -357,  -357,    73,  -356,  -272,
     -84,  -357,   -58,  -357,   235,  -357,   258,  -146,   313,   314,
    -357,   -21,  -357,  -124,  -255,  -122,   122,   -38,    -1,  -357,
      34,  -357,  -357,  -357,  -214,  -357,   221,   -25,   115,   -69,
    -357,   280,  -357,  -207,  -357,  -357,  -357,   104,  -357,  -357,
    -357,  -357,  -357,  -357,   111,   123,  -256,  -357,  -357,  -357,
     283,  -139,  -357,  -138,  -357,  -357,  -357,  -357,     1,  -357,
     176,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -264
static const short yytable[] =
{
      17,     6,   286,   288,   199,     6,    17,   318,   187,   193,
     128,   343,   187,    12,   131,   327,   329,   330,     7,    12,
     443,   333,   334,   185,   220,   186,   123,   296,     9,   186,
     155,    50,   443,   195,   196,   444,    12,   175,   176,   347,
     297,    49,    18,    65,    88,   195,   196,   444,    50,   221,
      12,    65,   443,    64,    87,    12,   267,   268,    49,    93,
      12,    64,    12,   184,    12,   195,   196,   444,     1,     2,
       1,     2,    88,    12,    13,    45,   385,   143,    12,   175,
     176,   347,    87,    12,    13,    65,   156,    86,   267,   268,
     451,   365,   129,   451,   124,    64,   395,   218,     1,     2,
     157,   172,   173,   174,    12,   175,   176,   376,   177,   178,
     269,   340,    21,   -81,   144,    86,   145,   199,   343,   129,
     187,    94,   193,   319,   271,   276,   165,   187,   411,   143,
     187,   445,   452,   417,   189,   185,   164,   186,   188,   194,
     422,   293,   207,   445,   186,   179,   270,   186,   340,    30,
     437,   200,   206,   340,   269,   129,   129,   450,   405,   228,
     230,   129,    31,   445,   269,    46,   144,    91,   145,   227,
     229,   -24,   220,    14,    40,   184,   189,    32,   190,    33,
     161,  -263,    12,    19,   220,  -263,   180,   129,     1,     2,
     270,   162,    56,    57,   428,   285,   290,   221,   166,   344,
     270,   258,   167,   170,   438,   259,    34,   287,   439,   221,
     129,   172,   173,   174,    12,   175,   176,   302,   177,   178,
       1,     2,    12,   260,    59,   360,   279,   261,     1,     2,
     280,    35,   173,    36,    12,   175,   176,   231,   177,   178,
     371,   372,   301,   373,   328,   325,    38,   389,   326,   418,
     188,   390,   194,   320,   414,   179,   324,   207,   415,   423,
     207,   391,   424,   206,   357,    12,   359,   206,    39,   396,
     206,     1,     2,   201,   345,   234,   353,    51,   353,    12,
     175,   176,    22,   426,    66,     1,     2,   427,   374,    55,
     364,    23,     1,     2,   195,   196,   180,    52,   173,    67,
      12,   175,   176,   231,   177,   178,   344,    58,   420,    68,
      69,    70,    24,   202,    25,    90,   238,   208,   209,    95,
      71,   299,   300,    26,    96,    72,   126,    73,   195,   196,
     387,   304,   305,   306,   307,    74,   304,   305,   306,   307,
     135,   234,   308,   136,    75,   398,    76,   398,    98,    99,
     100,    77,   138,    78,    79,    80,   375,   137,   408,   139,
      99,   100,   146,   383,   384,   434,   435,   140,   413,   147,
     148,   150,   101,    66,   102,   151,   103,   154,   168,   320,
     170,   345,   238,   212,   225,   353,   104,   169,   262,   206,
     105,   282,   263,   265,   106,   281,   266,   107,    68,    69,
      70,   283,   413,   284,   289,   291,   294,   295,   108,    71,
     303,   311,   313,   109,    72,   110,    73,   111,   408,   322,
     315,    12,   442,   335,    74,   331,   112,   113,   339,   354,
     356,   358,   361,    75,   362,    76,   221,   363,   368,   369,
      77,   114,    78,    79,    80,   367,   370,   377,   382,   380,
     386,   381,   173,   115,    12,   175,   176,   231,   177,   178,
       1,     2,   392,   129,   388,   394,   401,   232,   404,   393,
     173,   399,    12,   175,   176,   231,   177,   178,     1,     2,
     402,   233,   410,   409,   416,   232,   431,     8,   152,    20,
      37,    97,    92,   125,    89,   234,   235,   355,   173,   233,
      12,   175,   176,   231,   177,   178,     1,     2,   226,   316,
     419,   236,   171,   234,   235,   421,   338,   292,   449,   346,
     366,   321,   277,   278,   429,   425,   432,   233,   314,   236,
     237,   436,   400,     0,   430,     0,   238,     0,     0,     0,
       0,   234,   235,     0,   317,   239,     0,     0,   237,     0,
       0,     0,   240,   241,   238,   242,     0,   236,     0,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,   241,     0,   242,     0,     0,   237,     0,     0,     0,
      99,   100,   238,     0,     0,     0,     0,     0,   213,     0,
       0,   239,   101,    66,   102,     0,   103,   214,     0,   241,
       0,   242,     0,     0,     0,     0,   104,     0,     0,     0,
     105,     0,     0,     0,   106,     0,     0,   107,    68,    69,
      70,     0,     0,     0,     0,     0,   215,     0,   108,    71,
       0,     0,     0,   109,    72,   110,    73,   111,     0,     0,
       0,     0,     0,     0,    74,     0,   112,   113,   216,   217,
       0,     0,     0,    75,     0,    76,    99,   100,     0,     0,
      77,   114,    78,    79,    80,     0,     0,     0,   101,    66,
     102,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     0,     0,     0,   105,     0,     0,     0,
     106,     0,     0,   107,    68,    69,    70,     0,     0,     0,
       0,     0,     0,     0,   108,    71,     0,     0,     0,   109,
      72,   110,    73,   111,     0,     0,     0,     0,     0,     0,
      74,     0,   112,   113,     0,     0,     0,     0,     0,    75,
       0,    76,     1,     2,     0,     0,    77,   114,    78,    79,
      80,     0,     0,     0,   101,    66,   102,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,   105,     0,     0,     0,   106,     0,     0,   107,
      68,    69,    70,     0,     0,     0,     0,     0,     0,     0,
     108,    71,     0,     0,     0,   109,    72,   110,    73,   111,
       0,     0,     0,     0,     0,     0,    74,     0,   112,   113,
       0,     0,     0,     0,     0,    75,     0,    76,     0,     0,
       0,     0,    77,   114,    78,    79,    80
};

static const short yycheck[] =
{
       9,     0,   216,   217,   150,     4,    15,   262,   147,   148,
      33,   283,   151,     9,    98,   271,   272,   273,     0,     9,
       4,   277,   278,   147,    85,   147,    88,   106,   108,   151,
      24,    40,     4,    17,    18,    19,     9,    10,    11,    35,
     119,    40,    39,    52,    53,    17,    18,    19,    57,   110,
       9,    60,     4,    52,    53,     9,    16,    17,    57,    51,
       9,    60,     9,   147,     9,    17,    18,    19,    15,    16,
      15,    16,    81,     9,    10,    22,   332,   115,     9,    10,
      11,    35,    81,     9,    10,    94,    80,    53,    16,    17,
     446,   298,   115,   449,    93,    94,   352,   159,    15,    16,
      94,     6,     7,     8,     9,    10,    11,   314,    13,    14,
      38,   107,   110,   109,   115,    81,   115,   263,   390,   115,
     259,   113,   261,   262,   208,   209,   135,   266,   118,   167,
     269,   115,   116,   388,   107,   259,   135,   259,   147,   148,
     396,   225,   151,   115,   266,    50,    74,   269,   107,    10,
      20,   150,   151,   107,    38,   115,   115,   109,   107,   168,
     169,   115,    62,   115,    38,   112,   167,   112,   167,   168,
     169,    44,    85,   109,    47,   259,   107,    89,   109,    89,
      46,   109,     9,   109,    85,   113,    91,   115,    15,    16,
      74,    57,   112,   113,   408,   108,   221,   110,   109,   283,
      74,   109,   113,   108,    74,   113,    58,   108,    78,   110,
     115,     6,     7,     8,     9,    10,    11,   242,    13,    14,
      15,    16,     9,   109,    51,   294,   109,   113,    15,    16,
     113,    89,     7,     3,     9,    10,    11,    12,    13,    14,
     309,   310,   241,   312,   118,   266,   111,   109,   269,   388,
     259,   113,   261,   262,   109,    50,   265,   266,   113,   397,
     269,   345,   400,   262,   289,     9,   291,   266,    26,   353,
     269,    15,    16,    68,   283,    50,   285,    44,   287,     9,
      10,    11,    16,   109,    28,    15,    16,   113,   313,   112,
      65,    25,    15,    16,    17,    18,    91,    59,     7,    43,
       9,    10,    11,    12,    13,    14,   390,   108,   392,    53,
      54,    55,    46,   108,    48,   109,    91,    17,    18,   108,
      64,    34,    35,    57,    16,    69,   109,    71,    17,    18,
     339,   102,   103,   104,   105,    79,   102,   103,   104,   105,
     118,    50,   113,    86,    88,   354,    90,   356,     3,    15,
      16,    95,    76,    97,    98,    99,    65,    86,   367,    56,
      15,    16,     3,    17,    18,   423,   424,    86,   377,   108,
     108,   118,    27,    28,    29,     3,    31,   108,   114,   388,
     108,   390,    91,    10,     3,   394,    41,   114,   110,   388,
      45,    40,   118,   118,    49,   116,   114,    52,    53,    54,
      55,   108,   411,    73,   110,   110,   101,    30,    63,    64,
     109,   101,   110,    68,    69,    70,    71,    72,   427,     5,
     108,     9,   431,   100,    79,    93,    81,    82,    30,    73,
      73,   111,   108,    88,   119,    90,   110,   106,   109,   111,
      95,    96,    97,    98,    99,   108,   107,   120,     5,   111,
      87,   111,     7,   108,     9,    10,    11,    12,    13,    14,
      15,    16,    73,   115,   117,   113,   111,    22,   119,   109,
       7,   109,     9,    10,    11,    12,    13,    14,    15,    16,
     111,    36,   111,   113,   108,    22,   118,     4,   124,    15,
      28,    81,    60,    94,    57,    50,    51,   287,     7,    36,
       9,    10,    11,    12,    13,    14,    15,    16,   167,   259,
     390,    66,   146,    50,    51,   394,   280,   225,   445,   284,
     299,   263,   209,   209,   409,   403,   415,    36,   248,    66,
      85,   427,   356,    -1,   411,    -1,    91,    -1,    -1,    -1,
      -1,    50,    51,    -1,   261,   100,    -1,    -1,    85,    -1,
      -1,    -1,   107,   108,    91,   110,    -1,    66,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,    -1,    -1,    85,    -1,    -1,    -1,
      15,    16,    91,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      -1,   100,    27,    28,    29,    -1,    31,    32,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    88,    -1,    90,    15,    16,    -1,    -1,
      95,    96,    97,    98,    99,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    90,    15,    16,    -1,    -1,    95,    96,    97,    98,
      99,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    90,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    15,    16,   122,   123,   124,   229,     0,   124,   108,
     125,   126,     9,    10,   109,   127,   128,   232,    39,   109,
     128,   110,    16,    25,    46,    48,    57,   129,   130,   131,
      10,    62,    89,    89,    58,    89,     3,   131,   111,    26,
      47,   132,   133,   144,   145,    22,   112,   146,   147,   229,
     232,    44,    59,   137,   138,   112,   112,   113,   108,    51,
     139,   141,   142,   143,   229,   232,    28,    43,    53,    54,
      55,    64,    69,    71,    79,    88,    90,    95,    97,    98,
      99,   134,   135,   149,   151,   181,   191,   229,   232,   147,
     109,   112,   141,    51,   113,   108,    16,   135,     3,    15,
      16,    27,    29,    31,    41,    45,    49,    52,    63,    68,
      70,    72,    81,    82,    96,   108,   150,   175,   188,   189,
     190,   191,   230,   150,   229,   143,   109,   136,    33,   115,
     161,   171,   224,   225,   226,   118,    86,    86,    76,    56,
      86,   152,   153,   188,   189,   229,     3,   108,   108,   219,
     118,     3,   126,   140,   108,    24,    80,    94,   227,   172,
     173,    46,    57,   228,   229,   232,   109,   113,   114,   114,
     108,   148,     6,     7,     8,    10,    11,    13,    14,    50,
      91,   148,   154,   155,   171,   184,   186,   222,   232,   107,
     109,   220,   221,   222,   232,    17,    18,   176,   177,   178,
     229,    68,   108,   182,   184,   185,   229,   232,    17,    18,
     163,   164,    10,    23,    32,    61,    83,    84,   150,   174,
      85,   110,   195,   196,   197,     3,   153,   229,   232,   229,
     232,    12,    22,    36,    50,    51,    66,    85,    91,   100,
     107,   108,   110,   186,   198,   199,   200,   203,   204,   205,
     206,   211,   212,   213,   222,   223,   229,   232,   109,   113,
     109,   113,   110,   118,   183,   118,   114,    16,    17,    38,
      74,   171,   179,   180,   217,   218,   171,   179,   180,   109,
     113,   116,    40,   108,    73,   108,   195,   108,   195,   110,
     198,   110,   161,   171,   101,    30,   106,   119,   202,    34,
      35,   229,   198,   109,   102,   103,   104,   105,   113,   192,
     193,   101,   194,   110,   202,   108,   155,   221,   185,   222,
     232,   177,     5,   187,   232,   182,   182,   217,   118,   217,
     217,    93,   162,   217,   217,   100,   165,   166,   164,    30,
     107,   159,   160,   170,   171,   232,   175,    35,   156,   157,
     158,   170,   171,   232,    73,   156,    73,   198,   111,   198,
     200,   108,   119,   106,    65,   204,   197,   108,   109,   111,
     107,   200,   200,   200,   198,    65,   204,   120,   214,   215,
     111,   111,     5,    17,    18,   217,    87,   232,   117,   109,
     113,   171,    73,   109,   113,   217,   171,   231,   232,   109,
     231,   111,   111,   201,   119,   107,   207,   208,   232,   113,
     111,   118,   216,   232,   109,   113,   108,   185,   222,   160,
     171,   158,   217,   224,   224,   187,   109,   113,   195,   199,
     216,   118,   215,   167,   173,   173,   208,    20,    74,    78,
     209,   210,   232,     4,    19,   115,   168,   169,   178,   168,
     109,   169,   116
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
#line 343 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 349 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 354 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 375 "asn1p_y.y"
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
#line 396 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 7:
#line 397 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 8:
#line 401 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 9:
#line 404 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 10:
#line 410 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 11:
#line 416 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 425 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 13:
#line 429 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 14:
#line 433 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 15:
#line 443 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 16:
#line 444 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 17:
#line 453 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 456 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 465 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 468 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 471 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 474 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 478 "asn1p_y.y"
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
#line 499 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 25:
#line 500 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 26:
#line 509 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		AL_IMPORT(yyval.a_module, exports, yyvsp[-2].a_module, xp_next);
		AL_IMPORT(yyval.a_module, imports, yyvsp[-1].a_module, xp_next);
		AL_IMPORT(yyval.a_module, members, yyvsp[0].a_module, next);
	}
    break;

  case 27:
#line 518 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 28:
#line 521 "asn1p_y.y"
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

  case 29:
#line 537 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 30:
#line 544 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 557 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 565 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 33:
#line 566 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at line %d ignored\n",
			yyvsp[-1].tv_str, yylineno);
		free(yyvsp[-1].tv_str);
		yyval.a_module = 0;
	}
    break;

  case 34:
#line 578 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 35:
#line 591 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 37:
#line 595 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 38:
#line 605 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 39:
#line 611 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 40:
#line 616 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 41:
#line 623 "asn1p_y.y"
    { memset(&yyval.a_aid, 0, sizeof(yyval.a_aid)); }
    break;

  case 42:
#line 624 "asn1p_y.y"
    { yyval.a_aid.oid = yyvsp[0].a_oid; }
    break;

  case 43:
#line 628 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->fromModuleName = yyvsp[-1].tv_str;
		yyval.a_xports->identifier = yyvsp[0].a_aid;
		/* This stupid thing is used for look-back hack. */
		saved_aid = yyval.a_xports->identifier.oid ? 0 : &(yyval.a_xports->identifier);
		checkmem(yyval.a_xports);
	}
    break;

  case 44:
#line 639 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 45:
#line 644 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 46:
#line 651 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 47:
#line 657 "asn1p_y.y"
    {		/* Completely equivalent to above */
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 48:
#line 663 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 49:
#line 673 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 50:
#line 674 "asn1p_y.y"
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

  case 51:
#line 686 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 52:
#line 689 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 53:
#line 692 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 54:
#line 700 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 55:
#line 705 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 56:
#line 712 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 57:
#line 718 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 58:
#line 724 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 59:
#line 733 "asn1p_y.y"
    { yyval.a_constr = yyvsp[-1].a_constr; }
    break;

  case 60:
#line 736 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 61:
#line 746 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 62:
#line 759 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 63:
#line 769 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[-3].a_ref;
		yyval.a_expr->rhs_pspecs = yyvsp[-1].a_expr;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 64:
#line 789 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 65:
#line 795 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 66:
#line 811 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 67:
#line 817 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 68:
#line 825 "asn1p_y.y"
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

  case 69:
#line 834 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 70:
#line 845 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 71:
#line 849 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 72:
#line 856 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 73:
#line 863 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 74:
#line 871 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 75:
#line 882 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 76:
#line 887 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 77:
#line 894 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 78:
#line 897 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = "?";
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 79:
#line 905 "asn1p_y.y"
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

  case 80:
#line 916 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->expr_type = A1TC_VALUESET;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 81:
#line 939 "asn1p_y.y"
    { yyval.a_expr = asn1p_expr_new(yylineno); }
    break;

  case 82:
#line 940 "asn1p_y.y"
    { yyval.a_expr = yyvsp[0].a_expr; }
    break;

  case 83:
#line 943 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 84:
#line 948 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 85:
#line 955 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 86:
#line 962 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 87:
#line 968 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 88:
#line 975 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 89:
#line 981 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 90:
#line 986 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 91:
#line 993 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
	}
    break;

  case 92:
#line 998 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 93:
#line 1001 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 94:
#line 1008 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 95:
#line 1018 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 96:
#line 1019 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 97:
#line 1023 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 98:
#line 1030 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 99:
#line 1040 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 100:
#line 1050 "asn1p_y.y"
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

  case 101:
#line 1061 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 102:
#line 1071 "asn1p_y.y"
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

  case 103:
#line 1082 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVSFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 104:
#line 1092 "asn1p_y.y"
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

  case 105:
#line 1103 "asn1p_y.y"
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

  case 106:
#line 1115 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 107:
#line 1116 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 108:
#line 1123 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 109:
#line 1125 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 110:
#line 1131 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 111:
#line 1135 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 112:
#line 1142 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_opaque.buf, 0);
		yyval.a_wchunk->type = WC_WHITESPACE;
	}
    break;

  case 113:
#line 1146 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_str, 0);
	}
    break;

  case 114:
#line 1149 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].a_refcomp.name, 0);
		yyval.a_wchunk->type = WC_FIELD;
	}
    break;

  case 115:
#line 1153 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromsyntax(yyvsp[-1].a_wsynt);
	}
    break;

  case 116:
#line 1159 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 117:
#line 1167 "asn1p_y.y"
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

  case 118:
#line 1176 "asn1p_y.y"
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

  case 119:
#line 1188 "asn1p_y.y"
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

  case 120:
#line 1210 "asn1p_y.y"
    {
		yyval.a_int = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 121:
#line 1217 "asn1p_y.y"
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

  case 122:
#line 1236 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 123:
#line 1239 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 124:
#line 1245 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 125:
#line 1251 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 126:
#line 1257 "asn1p_y.y"
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

  case 127:
#line 1267 "asn1p_y.y"
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

  case 128:
#line 1277 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1283 "asn1p_y.y"
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

  case 130:
#line 1294 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 131:
#line 1309 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 132:
#line 1317 "asn1p_y.y"
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

  case 133:
#line 1327 "asn1p_y.y"
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

  case 134:
#line 1337 "asn1p_y.y"
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

  case 135:
#line 1347 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 136:
#line 1355 "asn1p_y.y"
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

  case 137:
#line 1377 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 138:
#line 1385 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 140:
#line 1398 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 141:
#line 1403 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 142:
#line 1412 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 143:
#line 1416 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 144:
#line 1420 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_Amplowercase);
	}
    break;

  case 145:
#line 1427 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
	}
    break;

  case 146:
#line 1447 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 149:
#line 1459 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_CHOICE_IDENTIFIER;
		yyval.a_value->value.choice_identifier.identifier = yyvsp[-2].tv_str;
		yyval.a_value->value.choice_identifier.value = yyvsp[0].a_value;
	}
    break;

  case 150:
#line 1466 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 151:
#line 1466 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 152:
#line 1471 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_NULL;
	}
    break;

  case 153:
#line 1479 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 154:
#line 1484 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 155:
#line 1489 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 156:
#line 1493 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 157:
#line 1497 "asn1p_y.y"
    {
		yyval.a_value = yyval.a_value;
	}
    break;

  case 158:
#line 1500 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 159:
#line 1506 "asn1p_y.y"
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

  case 160:
#line 1517 "asn1p_y.y"
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

  case 161:
#line 1535 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 162:
#line 1539 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TUPLE;
	}
    break;

  case 163:
#line 1544 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_QUADRUPLE;
	}
    break;

  case 164:
#line 1578 "asn1p_y.y"
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

  case 165:
#line 1587 "asn1p_y.y"
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

  case 166:
#line 1602 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 167:
#line 1603 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 168:
#line 1604 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 169:
#line 1605 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 170:
#line 1606 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 171:
#line 1607 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 172:
#line 1608 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 173:
#line 1609 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 174:
#line 1610 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 175:
#line 1611 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 176:
#line 1612 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 177:
#line 1613 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 178:
#line 1614 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 179:
#line 1621 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 180:
#line 1622 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 181:
#line 1623 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 182:
#line 1627 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 183:
#line 1633 "asn1p_y.y"
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

  case 184:
#line 1646 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 185:
#line 1647 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 186:
#line 1651 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 187:
#line 1655 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 188:
#line 1656 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 189:
#line 1657 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 190:
#line 1658 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 191:
#line 1659 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 192:
#line 1663 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 193:
#line 1664 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 194:
#line 1665 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 195:
#line 1666 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 196:
#line 1670 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 197:
#line 1671 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 203:
#line 1683 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 204:
#line 1684 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 205:
#line 1690 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 206:
#line 1693 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 207:
#line 1703 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 208:
#line 1706 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 209:
#line 1712 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 210:
#line 1716 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 211:
#line 1719 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 212:
#line 1725 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 213:
#line 1736 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 214:
#line 1739 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_AEX, yyvsp[0].a_constr, 0);
	}
    break;

  case 215:
#line 1742 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 216:
#line 1745 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 217:
#line 1748 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 218:
#line 1754 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 219:
#line 1762 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 220:
#line 1770 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 221:
#line 1776 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_TYPE;
		yyval.a_constr->containedSubtype = yyvsp[0].a_value;
	}
    break;

  case 222:
#line 1782 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 223:
#line 1789 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 224:
#line 1797 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 225:
#line 1805 "asn1p_y.y"
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

  case 226:
#line 1814 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 227:
#line 1817 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 228:
#line 1821 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 229:
#line 1821 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CT_CTDBY;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_constr->value);
		yyval.a_constr->value->type = ATV_UNPARSED;
	}
    break;

  case 230:
#line 1832 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 231:
#line 1833 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 232:
#line 1834 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 233:
#line 1835 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 234:
#line 1839 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 235:
#line 1842 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 236:
#line 1848 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 237:
#line 1853 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 240:
#line 1860 "asn1p_y.y"
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

  case 241:
#line 1874 "asn1p_y.y"
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

  case 242:
#line 1888 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMP, yyvsp[0].a_constr, 0);
	}
    break;

  case 243:
#line 1891 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 244:
#line 1897 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 245:
#line 1900 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 246:
#line 1906 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
		yyval.a_constr->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 247:
#line 1912 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
		if(yyvsp[-1].a_constr) asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 248:
#line 1926 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 249:
#line 1927 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 250:
#line 1931 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 251:
#line 1934 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 252:
#line 1937 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 253:
#line 1943 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 254:
#line 1946 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 255:
#line 1955 "asn1p_y.y"
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

  case 256:
#line 1970 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 257:
#line 1976 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 258:
#line 1982 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 259:
#line 1996 "asn1p_y.y"
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

  case 260:
#line 2007 "asn1p_y.y"
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

  case 261:
#line 2023 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 262:
#line 2026 "asn1p_y.y"
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

  case 263:
#line 2044 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_NOMARK;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 264:
#line 2048 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 265:
#line 2052 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_OPTIONAL | EM_INDIRECT;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 266:
#line 2056 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_DEFAULT;
		yyval.a_marker.default_value = yyvsp[0].a_value;
	}
    break;

  case 267:
#line 2079 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
	}
    break;

  case 268:
#line 2083 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 269:
#line 2089 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 270:
#line 2094 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 271:
#line 2101 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 272:
#line 2108 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 273:
#line 2116 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 274:
#line 2124 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 275:
#line 2131 "asn1p_y.y"
    {
		yyval.a_expr = asn1p_expr_new(yylineno);
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 276:
#line 2142 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 277:
#line 2146 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 279:
#line 2154 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromdouble(yyvsp[0].a_dbl);
		checkmem(yyval.a_value);
	}
    break;

  case 280:
#line 2185 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 281:
#line 2186 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 282:
#line 2190 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = yyvsp[0].a_tag.tag_mode;
	}
    break;

  case 283:
#line 2197 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-2].a_tag;
		yyval.a_tag.tag_value = yyvsp[-1].a_int;
	}
    break;

  case 284:
#line 2203 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 285:
#line 2204 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_UNIVERSAL; }
    break;

  case 286:
#line 2205 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_APPLICATION; }
    break;

  case 287:
#line 2206 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_PRIVATE; }
    break;

  case 288:
#line 2210 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_DEFAULT; }
    break;

  case 289:
#line 2211 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_IMPLICIT; }
    break;

  case 290:
#line 2212 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_EXPLICIT; }
    break;

  case 291:
#line 2216 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 292:
#line 2220 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 293:
#line 2228 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 294:
#line 2235 "asn1p_y.y"
    { yyval.tv_str = 0; }
    break;

  case 295:
#line 2236 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 296:
#line 2242 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 4313 "asn1p_y.c"

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


#line 2248 "asn1p_y.y"



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


