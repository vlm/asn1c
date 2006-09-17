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
#define YYLAST   834

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  117
/* YYNRULES -- Number of rules. */
#define YYNRULES  302
/* YYNRULES -- Number of states. */
#define YYNSTATES  462

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
     103,   105,   108,   109,   111,   116,   118,   122,   124,   128,
     130,   131,   133,   137,   141,   144,   146,   150,   152,   156,
     158,   162,   167,   169,   171,   176,   180,   184,   191,   198,
     200,   204,   206,   210,   214,   218,   222,   224,   228,   230,
     232,   234,   236,   237,   239,   241,   245,   249,   252,   256,
     258,   260,   264,   267,   269,   271,   277,   278,   280,   282,
     286,   289,   294,   298,   302,   306,   310,   314,   315,   317,
     318,   325,   327,   330,   332,   334,   336,   340,   342,   346,
     350,   354,   355,   358,   360,   365,   370,   375,   382,   389,
     391,   396,   400,   402,   406,   410,   414,   416,   420,   422,
     426,   428,   430,   432,   434,   438,   442,   444,   449,   451,
     453,   457,   458,   462,   464,   466,   468,   470,   472,   474,
     476,   478,   482,   484,   486,   488,   490,   493,   495,   497,
     499,   501,   504,   507,   509,   511,   514,   517,   519,   521,
     523,   525,   527,   530,   532,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   561,   563,
     565,   567,   569,   571,   573,   574,   576,   578,   582,   584,
     589,   593,   598,   600,   602,   606,   612,   614,   618,   622,
     626,   630,   635,   639,   641,   643,   647,   651,   655,   659,
     661,   663,   665,   667,   669,   671,   673,   675,   677,   681,
     687,   689,   693,   695,   699,   700,   702,   704,   706,   708,
     710,   712,   714,   715,   721,   724,   726,   729,   732,   736,
     738,   740,   744,   749,   751,   755,   758,   762,   764,   768,
     769,   771,   773,   776,   779,   783,   785,   789,   791,   796,
     801,   803,   805,   807,   809,   811,   813,   814,   816,   819,
     824,   825,   827,   829,   831,   832,   834,   836,   838,   840,
     842,   843,   845
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     122,     0,    -1,   123,    -1,   124,    -1,   123,   124,    -1,
      -1,   234,   125,   126,    39,   130,     3,    26,   133,    44,
      -1,    -1,   127,    -1,   108,   128,   109,    -1,   108,   109,
      -1,   129,    -1,   128,   129,    -1,   237,    -1,   237,   110,
      10,   111,    -1,    10,    -1,    -1,   131,    -1,   132,    -1,
     131,   132,    -1,    46,    89,    -1,    57,    89,    -1,    25,
      89,    -1,    48,    58,    -1,    16,    62,    -1,    -1,   134,
      -1,   145,   138,   135,    -1,   136,    -1,   135,   136,    -1,
     152,    -1,   182,    -1,   150,    -1,    -1,    43,    16,   137,
      -1,   192,    -1,    -1,   139,    -1,    59,   140,   112,    -1,
      59,    51,    -1,   142,    -1,   140,   142,    -1,    -1,   127,
      -1,   143,    51,   234,   141,    -1,   144,    -1,   143,   113,
     144,    -1,   234,    -1,   234,   108,   109,    -1,   237,    -1,
      -1,   146,    -1,    47,   147,   112,    -1,    47,    22,   112,
      -1,    47,   112,    -1,   148,    -1,   147,   113,   148,    -1,
     234,    -1,   234,   108,   109,    -1,   237,    -1,   108,   200,
     109,    -1,   234,   151,     3,   149,    -1,   191,    -1,   176,
      -1,   176,   108,   155,   109,    -1,   234,     3,   172,    -1,
     234,     3,   162,    -1,   234,   108,   153,   109,     3,   172,
      -1,   234,   108,   153,   109,     3,   162,    -1,   154,    -1,
     153,   113,   154,    -1,   234,    -1,   234,   114,   237,    -1,
     234,   114,   234,    -1,   189,   114,   237,    -1,   189,   114,
     234,    -1,   156,    -1,   155,   113,   156,    -1,   172,    -1,
     185,    -1,   237,    -1,   149,    -1,    -1,   158,    -1,   159,
      -1,   158,   113,   159,    -1,   237,   172,   222,    -1,   172,
     222,    -1,    35,    73,   172,    -1,   171,    -1,   161,    -1,
     160,   113,   161,    -1,   237,   172,    -1,   171,    -1,   172,
      -1,    33,   108,   164,   109,   166,    -1,    -1,    93,    -1,
     165,    -1,   164,   113,   165,    -1,    17,   222,    -1,    18,
     172,   163,   222,    -1,    18,   180,   222,    -1,    18,   181,
     222,    -1,    17,   180,   222,    -1,    17,   172,   222,    -1,
      17,   181,   222,    -1,    -1,   167,    -1,    -1,   100,    87,
     108,   168,   169,   109,    -1,   170,    -1,   169,   170,    -1,
       4,    -1,    19,    -1,   179,    -1,   115,   169,   116,    -1,
     107,    -1,   107,   117,   186,    -1,   107,   117,   227,    -1,
     229,   174,   196,    -1,    -1,   173,   175,    -1,   151,    -1,
      32,   108,   160,   109,    -1,    83,   108,   157,   109,    -1,
      84,   108,   157,   109,    -1,    83,   196,    73,   236,   229,
     174,    -1,    84,   196,    73,   236,   229,   174,    -1,    23,
      -1,    23,    40,    30,   237,    -1,    61,    73,   176,    -1,
      15,    -1,    15,   118,   234,    -1,   235,   118,   234,    -1,
      15,   118,   237,    -1,   235,    -1,   235,   118,   177,    -1,
     178,    -1,   177,   118,   178,    -1,   179,    -1,    17,    -1,
      18,    -1,    17,    -1,   180,   118,    17,    -1,   180,   118,
      18,    -1,    16,    -1,   237,   151,     3,   183,    -1,   185,
      -1,   186,    -1,   237,   114,   183,    -1,    -1,   108,   184,
     188,    -1,    68,    -1,    50,    -1,    91,    -1,     6,    -1,
       8,    -1,   187,    -1,   227,    -1,   237,    -1,   234,   118,
     237,    -1,     7,    -1,    13,    -1,    14,    -1,     5,    -1,
     188,     5,    -1,    29,    -1,    68,    -1,    81,    -1,   190,
      -1,    72,    86,    -1,    70,    56,    -1,    82,    -1,    49,
      -1,    41,    76,    -1,    31,    86,    -1,    96,    -1,    52,
      -1,   192,    -1,    63,    -1,    45,    -1,    27,    86,    -1,
     189,    -1,   190,   224,    -1,    28,    -1,    53,    -1,    54,
      -1,    55,    -1,    64,    -1,    69,    -1,    79,    -1,    88,
      -1,    90,    -1,    95,    -1,    97,    -1,    98,    -1,    99,
      -1,    71,    -1,   104,    -1,   105,    -1,   102,    -1,   103,
      -1,   101,    -1,    -1,   197,    -1,   198,    -1,   110,   211,
     111,    -1,   199,    -1,    85,   110,   200,   111,    -1,   110,
     200,   111,    -1,   199,   110,   200,   111,    -1,   107,    -1,
     201,    -1,   201,   113,   107,    -1,   201,   113,   107,   113,
     201,    -1,   202,    -1,    22,   101,   202,    -1,   201,   193,
     202,    -1,   201,   194,   202,    -1,   202,   195,   202,    -1,
     203,   110,   200,   111,    -1,   110,   200,   111,    -1,   204,
      -1,   205,    -1,   204,   215,   204,    -1,    66,   215,   204,
      -1,   204,   215,    65,    -1,    66,   215,    65,    -1,   206,
      -1,    85,    -1,    51,    -1,    50,    -1,    91,    -1,   228,
      -1,   187,    -1,   237,    -1,   234,    -1,   100,    34,   199,
      -1,   100,    35,   108,   207,   109,    -1,   208,    -1,   207,
     113,   208,    -1,   107,    -1,   237,   196,   209,    -1,    -1,
     210,    -1,    78,    -1,    20,    -1,    74,    -1,   212,    -1,
     216,    -1,   214,    -1,    -1,    36,    30,   108,   213,   188,
      -1,    37,   172,    -1,   106,    -1,   106,   119,    -1,   119,
     106,    -1,   119,   106,   119,    -1,   217,    -1,   218,    -1,
     108,   234,   109,    -1,   217,   108,   219,   109,    -1,   220,
      -1,   219,   113,   220,    -1,   120,   221,    -1,   120,   118,
     221,    -1,   237,    -1,   221,   118,   237,    -1,    -1,   223,
      -1,    74,    -1,    38,   183,    -1,   108,   109,    -1,   108,
     225,   109,    -1,   226,    -1,   225,   113,   226,    -1,   237,
      -1,   237,   110,   227,   111,    -1,   237,   110,   186,   111,
      -1,   227,    -1,   107,    -1,    10,    -1,    11,    -1,   227,
      -1,    12,    -1,    -1,   230,    -1,   231,   233,    -1,   115,
     232,    10,   116,    -1,    -1,    94,    -1,    24,    -1,    80,
      -1,    -1,    57,    -1,    46,    -1,    15,    -1,    16,    -1,
      16,    -1,    -1,   237,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   349,   349,   355,   361,   378,   377,   406,   408,   411,
     415,   420,   427,   435,   440,   444,   453,   455,   463,   467,
     475,   479,   482,   485,   489,   509,   511,   519,   528,   532,
     547,   555,   568,   576,   575,   589,   601,   603,   605,   616,
     621,   627,   633,   635,   638,   649,   655,   661,   668,   674,
     683,   685,   696,   700,   703,   710,   716,   722,   729,   735,
     744,   746,   756,   770,   780,   796,   806,   822,   828,   835,
     845,   855,   860,   867,   874,   882,   892,   898,   904,   908,
     916,   927,   949,   951,   953,   959,   965,   973,   979,   986,
     991,   997,  1003,  1009,  1012,  1018,  1028,  1030,  1033,  1041,
    1048,  1061,  1072,  1082,  1093,  1103,  1114,  1125,  1127,  1134,
    1132,  1141,  1146,  1152,  1157,  1160,  1164,  1169,  1178,  1187,
    1198,  1220,  1227,  1246,  1250,  1256,  1262,  1268,  1278,  1288,
    1294,  1305,  1319,  1328,  1338,  1348,  1358,  1366,  1387,  1396,
    1405,  1407,  1414,  1421,  1427,  1431,  1437,  1457,  1467,  1469,
    1470,  1477,  1477,  1482,  1489,  1495,  1500,  1504,  1508,  1511,
    1516,  1528,  1545,  1550,  1555,  1588,  1598,  1612,  1614,  1615,
    1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,
    1631,  1633,  1634,  1637,  1644,  1656,  1658,  1662,  1666,  1667,
    1668,  1669,  1670,  1674,  1675,  1676,  1677,  1681,  1682,  1689,
    1689,  1690,  1690,  1691,  1693,  1695,  1700,  1702,  1707,  1711,
    1720,  1724,  1729,  1734,  1737,  1743,  1753,  1757,  1760,  1763,
    1766,  1771,  1780,  1788,  1794,  1800,  1807,  1815,  1823,  1832,
    1837,  1841,  1846,  1852,  1857,  1858,  1859,  1872,  1886,  1890,
    1895,  1899,  1904,  1911,  1924,  1926,  1929,  1933,  1936,  1943,
    1945,  1946,  1951,  1949,  1961,  1969,  1971,  1972,  1973,  1975,
    1979,  1987,  2002,  2008,  2015,  2028,  2040,  2055,  2059,  2076,
    2081,  2084,  2089,  2111,  2116,  2121,  2127,  2133,  2141,  2149,
    2157,  2164,  2174,  2179,  2185,  2187,  2217,  2219,  2222,  2229,
    2235,  2237,  2238,  2239,  2242,  2244,  2245,  2248,  2253,  2260,
    2267,  2269,  2274
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
  "ImportsDefinition", "ImportsBundleSet", "AssignedIdentifier", 
  "ImportsBundle", "ImportsList", "ImportsElement", "optExports", 
  "ExportsDefinition", "ExportsBody", "ExportsElement", "ValueSet", 
  "ValueSetTypeAssignment", "DefinedType", "DataTypeReference", 
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList", 
  "ActualParameter", "optComponentTypeLists", "ComponentTypeLists", 
  "ComponentType", "AlternativeTypeLists", "AlternativeType", 
  "ObjectClass", "optUnique", "FieldSpec", "ClassField", "optWithSyntax", 
  "WithSyntax", "@3", "WithSyntaxList", "WithSyntaxToken", 
  "ExtensionAndException", "Type", "NSTD_IndirectMarker", 
  "TypeDeclaration", "TypeDeclarationSet", "ComplexTypeReference", 
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement", 
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass", 
  "ValueDefinition", "Value", "@4", "SimpleValue", "DefinedValue", 
  "RestrictedCharacterStringValue", "Opaque", "BasicTypeId", 
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString", 
  "Union", "Intersection", "Except", "optConstraints", "Constraint", 
  "SubtypeConstraint", "SetOfConstraints", "ElementSetSpecs", 
  "ElementSetSpec", "ConstraintSubtypeElement", "ConstraintSpec", 
  "SingleValue", "ContainedSubtype", "InnerTypeConstraint", 
  "WithComponentsList", "WithComponentsElement", "optPresenceConstraint", 
  "PresenceConstraint", "GeneralConstraint", "UserDefinedConstraint", 
  "@5", "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint", 
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
       0,   121,   122,   123,   123,   125,   124,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   134,   135,   135,
     136,   136,   136,   137,   136,   136,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   143,   143,   144,   144,   144,
     145,   145,   146,   146,   146,   147,   147,   148,   148,   148,
     149,   150,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   154,   154,   154,   154,   154,   155,   155,   156,   156,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     160,   160,   161,   161,   161,   162,   163,   163,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   168,
     167,   169,   169,   170,   170,   170,   170,   171,   171,   171,
     172,   173,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   176,   176,   176,   176,   176,   176,   177,   177,
     178,   179,   179,   180,   180,   180,   181,   182,   183,   183,
     183,   184,   183,   183,   185,   185,   185,   185,   185,   185,
     186,   186,   187,   187,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     190,   190,   190,   191,   191,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   193,
     193,   194,   194,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   200,   200,   200,   200,   201,   201,   201,   201,
     201,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   203,   204,   204,   204,   204,   204,   205,   206,   206,
     207,   207,   208,   208,   209,   209,   210,   210,   210,   211,
     211,   211,   213,   212,   214,   215,   215,   215,   215,   216,
     216,   217,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   226,
     226,   226,   227,   227,   228,   228,   229,   229,   230,   231,
     232,   232,   232,   232,   233,   233,   233,   234,   234,   235,
     236,   236,   237
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     0,     9,     0,     1,     3,
       2,     1,     2,     1,     4,     1,     0,     1,     1,     2,
       2,     2,     2,     2,     2,     0,     1,     3,     1,     2,
       1,     1,     1,     0,     3,     1,     0,     1,     3,     2,
       1,     2,     0,     1,     4,     1,     3,     1,     3,     1,
       0,     1,     3,     3,     2,     1,     3,     1,     3,     1,
       3,     4,     1,     1,     4,     3,     3,     6,     6,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     0,     1,     1,     3,     3,     2,     3,     1,
       1,     3,     2,     1,     1,     5,     0,     1,     1,     3,
       2,     4,     3,     3,     3,     3,     3,     0,     1,     0,
       6,     1,     2,     1,     1,     1,     3,     1,     3,     3,
       3,     0,     2,     1,     4,     4,     4,     6,     6,     1,
       4,     3,     1,     3,     3,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     3,     1,     4,     1,     1,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     3,     1,     4,
       3,     4,     1,     1,     3,     5,     1,     3,     3,     3,
       3,     4,     3,     1,     1,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     3,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     2,     1,     2,     2,     3,     1,
       1,     3,     4,     1,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     2,     3,     1,     3,     1,     4,     4,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     4,
       0,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,   297,   298,     0,     2,     3,     5,     1,     4,     7,
       0,     0,     8,   302,    15,    10,     0,    11,    13,    16,
       9,    12,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,    24,    22,    20,    23,    21,     0,    19,    14,
      50,     0,     0,    26,    36,    51,     0,    54,     0,    55,
      57,    59,     6,     0,     0,    37,    53,    52,     0,     0,
      39,     0,    40,     0,    45,    47,    49,   185,     0,   186,
     187,   188,   189,   190,   198,   191,   192,   193,   194,   195,
     196,   197,    27,    28,    32,    30,    31,    35,     0,     0,
      56,    58,    38,    41,     0,     0,     0,    33,    29,   286,
     132,   299,     0,   167,     0,     0,   181,   174,   178,   180,
     168,     0,     0,   169,   173,   177,     0,     0,    63,   183,
     170,    62,   179,   136,     0,    42,    46,    48,    34,     0,
     290,    66,    65,   121,   287,   294,     0,   182,   176,   175,
     172,   171,     0,    69,     0,   170,    71,     0,   286,     0,
     184,     0,     0,    43,    44,     0,   292,   293,   291,     0,
       0,   204,   296,   295,   288,   133,   135,     0,     0,     0,
       0,     0,    61,   156,   162,   157,   282,   283,   163,   164,
     154,   155,    81,     0,    76,    78,    79,   158,   159,    80,
     281,   273,     0,   275,   280,   277,   141,   142,   137,   138,
     140,   134,   153,   151,   147,   148,   149,     0,   160,   286,
     286,     0,    98,     0,   129,     0,     0,   204,   204,   123,
     122,     0,     0,   120,   205,   206,   208,   286,    70,    75,
      74,    73,    72,   285,     0,   232,   231,     0,   230,   233,
       0,   212,     0,   235,     0,   213,   216,     0,   223,   224,
     229,   284,   234,   237,   236,    64,   286,   274,     0,     0,
       0,     0,     0,     0,   146,   143,     0,   271,   269,   269,
     269,   100,   270,    96,   269,   269,   107,     0,   289,     0,
     286,     0,   286,     0,   286,     0,     0,     0,   286,     0,
       0,     0,   249,   251,   250,   259,   260,     0,    68,    67,
       0,   255,     0,     0,     0,     0,     0,    60,   201,   202,
     199,   200,     0,     0,     0,   203,     0,     0,     0,    77,
     276,     0,     0,   160,   139,   165,   152,   161,   150,   272,
     105,     0,   104,   106,    97,   269,   102,   103,     0,    95,
     108,    99,     0,   117,     0,    90,    93,    94,   286,   131,
       0,     0,    83,    84,    89,   269,   286,   300,     0,   300,
       0,     0,   254,     0,   210,   207,     0,     0,   217,   256,
     257,   228,   226,     0,   238,     0,   222,   214,   218,   219,
     220,     0,   227,   225,   279,   278,   166,   144,   145,   101,
       0,   130,     0,   124,   286,    92,   286,   125,   286,    87,
     269,   286,   301,   126,   286,   209,   252,   261,     0,     0,
     263,   211,   258,   242,     0,   240,   204,     0,   221,   109,
     118,   119,    91,    88,    85,    86,   121,   121,     0,     0,
     265,   267,   262,     0,   239,     0,   244,   215,     0,   127,
     128,   253,   266,     0,   264,   241,   247,   248,   246,   243,
     245,   113,   114,     0,     0,   111,   115,   268,     0,   110,
     112,   116
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     3,     4,     5,     9,    11,    12,    16,    17,    28,
      29,    30,    42,    43,    82,    83,   128,    54,    55,    61,
     154,    62,    63,    64,    44,    45,    48,    49,   182,    84,
     117,    85,   142,   143,   183,   184,   351,   352,   353,   344,
     345,   131,   335,   211,   212,   339,   340,   438,   454,   455,
     354,   355,   160,   161,   220,   118,   198,   199,   456,   269,
     270,    86,   204,   261,   205,   206,   243,   326,   119,   120,
     121,   122,   313,   314,   316,   223,   224,   225,   226,   290,
     245,   246,   247,   248,   249,   250,   414,   415,   449,   450,
     291,   292,   428,   293,   303,   294,   295,   296,   409,   410,
     430,   271,   272,   150,   192,   193,   251,   252,   133,   134,
     135,   159,   164,   253,   123,   401,   254
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -345
static const short yypact[] =
{
     179,  -345,  -345,    94,   179,  -345,  -345,  -345,  -345,   -87,
      25,   118,  -345,  -345,  -345,  -345,    64,  -345,    37,   234,
    -345,  -345,   106,   123,   107,   113,   164,   165,   260,   234,
    -345,   157,  -345,  -345,  -345,  -345,  -345,   247,  -345,  -345,
     177,    60,   235,  -345,   239,  -345,   175,  -345,   -72,  -345,
     198,  -345,  -345,   147,   506,  -345,  -345,  -345,   246,   199,
    -345,    21,  -345,   100,  -345,   205,  -345,  -345,   299,  -345,
    -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,   506,  -345,  -345,  -345,  -345,  -345,   273,   659,
    -345,  -345,  -345,  -345,   179,   246,   212,  -345,  -345,    16,
     242,  -345,   237,  -345,   254,   270,  -345,  -345,  -345,  -345,
    -345,   306,   278,  -345,  -345,  -345,   735,   376,   272,  -345,
     275,  -345,  -345,   267,   383,   -87,  -345,  -345,  -345,   281,
      87,  -345,  -345,  -345,  -345,    14,   246,  -345,  -345,  -345,
    -345,  -345,    36,  -345,   276,  -345,   277,   284,    91,    77,
    -345,   341,   201,  -345,  -345,   214,  -345,  -345,  -345,   377,
     583,   108,  -345,  -345,  -345,  -345,  -345,   391,   735,   246,
     246,   435,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,   134,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,   186,  -345,  -345,   285,  -345,  -345,   289,  -345,
    -345,  -345,  -345,  -345,  -345,  -345,  -345,   290,   282,   162,
      76,   211,  -345,   293,   370,   303,   340,   -52,    95,  -345,
    -345,   304,   390,  -345,  -345,  -345,   305,    16,  -345,  -345,
    -345,  -345,  -345,  -345,   315,  -345,  -345,   114,  -345,  -345,
     210,  -345,   435,  -345,   308,   181,   317,   310,   114,  -345,
    -345,  -345,  -345,  -345,  -345,  -345,    91,  -345,    97,   301,
     279,   416,   413,   201,  -345,  -345,   201,  -345,   -13,    74,
     -13,  -345,  -345,   330,    74,   -13,   324,   214,  -345,   398,
      61,   323,    68,   356,    68,   357,   435,   401,   319,   179,
     321,   325,  -345,  -345,  -345,   327,  -345,   435,  -345,  -345,
     497,   318,   332,   216,   329,   335,   342,  -345,  -345,  -345,
    -345,  -345,   345,   497,   497,  -345,   497,   435,   228,  -345,
    -345,   343,   344,  -345,  -345,  -345,   453,  -345,  -345,  -345,
    -345,   349,  -345,  -345,  -345,   -13,  -345,  -345,   373,  -345,
    -345,  -345,   413,   352,   220,  -345,  -345,  -345,   319,  -345,
     397,   362,   359,  -345,  -345,   -13,   319,   413,   364,   413,
     365,   369,  -345,   371,  -345,  -345,   358,   368,  -345,  -345,
     363,  -345,  -345,   435,   305,     8,  -345,   374,  -345,  -345,
    -345,   372,  -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,
     380,  -345,   301,  -345,    61,  -345,   319,  -345,    43,  -345,
     -13,   319,  -345,  -345,   319,  -345,  -345,  -345,    -5,   221,
    -345,  -345,  -345,  -345,   222,  -345,   108,   452,  -345,  -345,
    -345,  -345,  -345,  -345,  -345,  -345,  -345,  -345,   416,   413,
     366,  -345,  -345,   358,  -345,     8,     6,   271,    49,  -345,
    -345,   453,   366,   413,  -345,  -345,  -345,  -345,  -345,  -345,
    -345,  -345,  -345,    49,    46,  -345,  -345,  -345,    28,  -345,
    -345,  -345
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -345,  -345,  -345,   485,  -345,  -345,   367,  -345,   475,  -345,
    -345,   464,  -345,  -345,  -345,   412,  -345,  -345,  -345,  -345,
    -345,   434,  -345,   404,  -345,  -345,  -345,   438,   378,  -345,
     -79,  -345,  -345,   337,  -345,   258,   232,  -345,   119,  -345,
     125,   296,  -345,  -345,   250,  -345,  -345,  -345,    71,  -344,
    -271,   -91,  -345,   -49,  -345,   248,  -345,   268,  -132,   320,
     322,  -345,    85,  -345,  -135,  -252,  -136,   103,   -89,   -78,
    -345,   -43,  -345,  -345,  -345,  -215,  -345,  -345,   229,  -151,
     121,  -126,  -345,   -84,  -345,  -345,  -345,   101,  -345,  -345,
    -345,  -345,  -345,  -345,   291,  -345,  -345,  -345,  -345,   111,
     112,  -246,  -345,  -345,  -345,   288,  -134,  -345,   -51,  -345,
    -345,  -345,  -345,     1,  -345,   191,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -270
static const short yytable[] =
{
      18,     6,   283,   285,    13,     6,    18,   321,   132,   346,
     124,    87,   187,   186,   188,   194,   187,    13,   188,   200,
     244,    10,   330,   332,   333,   266,   446,   144,   336,   337,
      13,    51,   451,   221,    13,    14,     1,     2,   145,    87,
      57,    58,    50,    66,    89,   196,   197,   452,    51,   129,
     451,    66,    13,   451,    65,    88,   282,   185,   222,    50,
     162,   267,    65,   196,   197,   452,   196,   197,   452,    13,
      13,   163,    89,    13,    14,     1,     2,    13,   350,   144,
     447,   219,    46,    88,   448,    66,    13,   176,   177,   389,
     145,   306,   264,   265,     7,   125,    65,   173,   174,   175,
      13,   176,   177,   350,   178,   179,    13,   176,   177,   399,
     460,   156,   266,   429,   460,   413,    31,   146,   268,   273,
     187,   186,   188,   346,   194,   322,   166,   187,   200,   188,
     187,   130,   188,    92,    15,   360,   299,   165,   189,   195,
     420,   180,   208,   453,   461,   167,   367,    22,   267,   168,
     343,    94,   201,   207,   425,   459,    13,    19,   130,   230,
     232,   453,     1,     2,   453,   185,   381,   157,   343,   146,
     229,   231,    47,    20,   368,   343,   130,   -82,   264,   265,
     221,   158,   181,   130,   190,    32,   191,   378,   379,   347,
     380,   130,   331,   221,     1,     2,    33,   362,    60,   171,
     266,   436,    34,   284,   190,   222,   130,   173,   174,   175,
      13,   176,   177,    95,   178,   179,     1,     2,   222,   372,
     301,   -25,    35,   174,    41,    13,   176,   177,   233,   178,
     179,   209,   210,   302,   383,   174,   267,    13,   176,   177,
     233,   178,   179,   255,   304,   305,   189,   256,   195,   323,
      23,   180,   327,   208,    36,    13,   208,   395,   421,    24,
     207,     1,     2,    37,   207,   400,   235,   207,    39,   202,
     348,  -269,   356,    40,   356,  -269,    99,   130,   235,    52,
      25,   371,    26,   308,   309,   310,   311,    56,   100,   101,
     363,    27,   181,   382,   312,   257,   196,   197,    53,   258,
     102,    67,   103,   347,   104,   423,    59,   239,    91,   203,
      13,   176,   177,    96,   105,    97,     1,     2,   106,   239,
     276,   127,   107,   137,   277,   108,    69,    70,    71,   393,
     432,   434,   391,   394,   433,   435,   109,    72,   100,   101,
     138,   110,    73,   111,    74,   112,   139,   402,   328,   402,
     426,   329,    75,   427,   113,   114,     1,     2,   196,   197,
     136,    76,   140,    77,   141,   416,   387,   388,    78,   115,
      79,    80,    81,   308,   309,   310,   311,   439,   440,   147,
     148,   116,   323,   149,   348,   151,   152,   213,   356,   155,
     169,   170,   171,   207,   227,   259,   263,   174,   431,    13,
     176,   177,   233,   178,   179,     1,     2,   260,   262,   278,
     279,   280,   234,   281,   286,   297,   300,   307,   315,   431,
     317,   325,    13,   334,   338,   416,   287,   288,   342,   357,
     359,   361,   364,   457,   130,   366,   365,   369,   370,   373,
     235,   236,   174,   375,    13,   176,   177,   233,   178,   179,
       1,     2,   377,   376,   384,   385,   237,   234,   386,   174,
     390,    13,   176,   177,   233,   178,   179,     1,     2,   392,
     396,   397,   398,   403,   234,   238,   405,   406,   408,   411,
     407,   239,   412,   418,   443,   235,   236,   417,   419,     8,
     240,    21,   153,    38,    98,    93,    90,   241,   289,   126,
     242,   237,   235,   236,   174,   228,    13,   176,   177,   233,
     178,   179,     1,     2,   319,    13,   358,   424,   237,   422,
     238,     1,     2,   298,   458,   172,   239,   341,   324,   349,
     274,   441,   275,   374,    67,   240,   445,   238,   437,   318,
       0,   442,   241,   239,   444,   242,   320,   235,   236,    68,
     404,     0,   240,     0,     0,     0,     0,     0,     0,    69,
      70,    71,   242,   237,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,    73,     0,    74,     0,     0,
       0,     0,   238,     0,     0,    75,     0,     0,   239,     0,
       0,     0,     0,     0,    76,     0,    77,   240,   100,   101,
       0,    78,     0,    79,    80,    81,   214,   242,     0,     0,
     102,    67,   103,     0,   104,   215,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,   106,     0,
       0,     0,   107,     0,     0,   108,    69,    70,    71,     0,
       0,     0,     0,     0,   216,     0,   109,    72,     0,     0,
       0,   110,    73,   111,    74,   112,     0,     0,     0,     0,
       0,     0,    75,     0,   113,   114,   217,   218,     0,     0,
       0,    76,     0,    77,   100,   101,     0,     0,    78,   115,
      79,    80,    81,     0,     0,     0,   102,    67,   103,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,   106,     0,     0,     0,   107,     0,
       0,   108,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,   109,    72,     0,     0,     0,   110,    73,   111,
      74,   112,     0,     0,     0,     0,     0,     0,    75,     0,
     113,   114,     0,     0,     0,     0,     0,    76,     0,    77,
       1,     2,     0,     0,    78,   115,    79,    80,    81,     0,
       0,     0,   102,    67,   103,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
     106,     0,     0,     0,   107,     0,     0,   108,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,   109,    72,
       0,     0,     0,   110,    73,   111,    74,   112,     0,     0,
       0,     0,     0,     0,    75,     0,   113,   114,     0,     0,
       0,     0,     0,    76,     0,    77,     0,     0,     0,     0,
      78,   115,    79,    80,    81
};

static const short yycheck[] =
{
      10,     0,   217,   218,     9,     4,    16,   259,    99,   280,
      89,    54,   148,   148,   148,   149,   152,     9,   152,   151,
     171,   108,   268,   269,   270,    38,    20,   116,   274,   275,
       9,    41,     4,    85,     9,    10,    15,    16,   116,    82,
     112,   113,    41,    53,    54,    17,    18,    19,    58,    33,
       4,    61,     9,     4,    53,    54,   108,   148,   110,    58,
      46,    74,    61,    17,    18,    19,    17,    18,    19,     9,
       9,    57,    82,     9,    10,    15,    16,     9,    35,   168,
      74,   160,    22,    82,    78,    95,     9,    10,    11,   335,
     168,   242,    16,    17,     0,    94,    95,     6,     7,     8,
       9,    10,    11,    35,    13,    14,     9,    10,    11,   355,
     454,    24,    38,   118,   458,   107,    10,   116,   209,   210,
     256,   256,   256,   394,   258,   259,   136,   263,   260,   263,
     266,   115,   266,   112,   109,   286,   227,   136,   148,   149,
     392,    50,   152,   115,   116,   109,   297,   110,    74,   113,
     107,    51,   151,   152,   400,   109,     9,    39,   115,   169,
     170,   115,    15,    16,   115,   256,   317,    80,   107,   168,
     169,   170,   112,   109,   300,   107,   115,   109,    16,    17,
      85,    94,    91,   115,   107,    62,   109,   313,   314,   280,
     316,   115,   118,    85,    15,    16,    89,   288,    51,   108,
      38,   416,    89,   108,   107,   110,   115,     6,     7,     8,
       9,    10,    11,   113,    13,    14,    15,    16,   110,   303,
     106,    44,    58,     7,    47,     9,    10,    11,    12,    13,
      14,    17,    18,   119,   318,     7,    74,     9,    10,    11,
      12,    13,    14,   109,    34,    35,   256,   113,   258,   259,
      16,    50,   262,   263,    89,     9,   266,   348,   392,    25,
     259,    15,    16,     3,   263,   356,    50,   266,   111,    68,
     280,   109,   282,    26,   284,   113,     3,   115,    50,    44,
      46,    65,    48,   102,   103,   104,   105,   112,    15,    16,
     289,    57,    91,    65,   113,   109,    17,    18,    59,   113,
      27,    28,    29,   394,    31,   396,   108,    91,   109,   108,
       9,    10,    11,   108,    41,    16,    15,    16,    45,    91,
     109,   109,    49,    86,   113,    52,    53,    54,    55,   109,
     109,   109,   342,   113,   113,   113,    63,    64,    15,    16,
      86,    68,    69,    70,    71,    72,    76,   357,   263,   359,
     401,   266,    79,   404,    81,    82,    15,    16,    17,    18,
     118,    88,    56,    90,    86,   375,    17,    18,    95,    96,
      97,    98,    99,   102,   103,   104,   105,   426,   427,     3,
     108,   108,   392,   108,   394,   118,     3,    10,   398,   108,
     114,   114,   108,   392,     3,   110,   114,     7,   408,     9,
      10,    11,    12,    13,    14,    15,    16,   118,   118,   116,
      40,   108,    22,    73,   110,   110,   101,   109,   101,   429,
     110,     5,     9,    93,   100,   435,    36,    37,    30,    73,
      73,    30,   111,   443,   115,   108,   111,   119,   106,   110,
      50,    51,     7,   108,     9,    10,    11,    12,    13,    14,
      15,    16,   107,   111,   111,   111,    66,    22,     5,     7,
      87,     9,    10,    11,    12,    13,    14,    15,    16,   117,
      73,   109,   113,   109,    22,    85,   111,   108,   120,   111,
     109,    91,   119,   111,   118,    50,    51,   113,   108,     4,
     100,    16,   125,    29,    82,    61,    58,   107,   108,    95,
     110,    66,    50,    51,     7,   168,     9,    10,    11,    12,
      13,    14,    15,    16,   256,     9,   284,   398,    66,   394,
      85,    15,    16,   227,   453,   147,    91,   277,   260,   281,
     210,   428,   210,   304,    28,   100,   435,    85,   417,   248,
      -1,   429,   107,    91,   433,   110,   258,    50,    51,    43,
     359,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,   110,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    79,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    90,   100,    15,    16,
      -1,    95,    -1,    97,    98,    99,    23,   110,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    88,    -1,    90,    15,    16,    -1,    -1,    95,    96,
      97,    98,    99,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,
      15,    16,    -1,    -1,    95,    96,    97,    98,    99,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    90,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    15,    16,   122,   123,   124,   234,     0,   124,   125,
     108,   126,   127,     9,    10,   109,   128,   129,   237,    39,
     109,   129,   110,    16,    25,    46,    48,    57,   130,   131,
     132,    10,    62,    89,    89,    58,    89,     3,   132,   111,
      26,    47,   133,   134,   145,   146,    22,   112,   147,   148,
     234,   237,    44,    59,   138,   139,   112,   112,   113,   108,
      51,   140,   142,   143,   144,   234,   237,    28,    43,    53,
      54,    55,    64,    69,    71,    79,    88,    90,    95,    97,
      98,    99,   135,   136,   150,   152,   182,   192,   234,   237,
     148,   109,   112,   142,    51,   113,   108,    16,   136,     3,
      15,    16,    27,    29,    31,    41,    45,    49,    52,    63,
      68,    70,    72,    81,    82,    96,   108,   151,   176,   189,
     190,   191,   192,   235,   151,   234,   144,   109,   137,    33,
     115,   162,   172,   229,   230,   231,   118,    86,    86,    76,
      56,    86,   153,   154,   189,   190,   234,     3,   108,   108,
     224,   118,     3,   127,   141,   108,    24,    80,    94,   232,
     173,   174,    46,    57,   233,   234,   237,   109,   113,   114,
     114,   108,   149,     6,     7,     8,    10,    11,    13,    14,
      50,    91,   149,   155,   156,   172,   185,   187,   227,   237,
     107,   109,   225,   226,   227,   237,    17,    18,   177,   178,
     179,   234,    68,   108,   183,   185,   186,   234,   237,    17,
      18,   164,   165,    10,    23,    32,    61,    83,    84,   151,
     175,    85,   110,   196,   197,   198,   199,     3,   154,   234,
     237,   234,   237,    12,    22,    50,    51,    66,    85,    91,
     100,   107,   110,   187,   200,   201,   202,   203,   204,   205,
     206,   227,   228,   234,   237,   109,   113,   109,   113,   110,
     118,   184,   118,   114,    16,    17,    38,    74,   172,   180,
     181,   222,   223,   172,   180,   181,   109,   113,   116,    40,
     108,    73,   108,   196,   108,   196,   110,    36,    37,   108,
     200,   211,   212,   214,   216,   217,   218,   110,   162,   172,
     101,   106,   119,   215,    34,    35,   200,   109,   102,   103,
     104,   105,   113,   193,   194,   101,   195,   110,   215,   156,
     226,   186,   227,   237,   178,     5,   188,   237,   183,   183,
     222,   118,   222,   222,    93,   163,   222,   222,   100,   166,
     167,   165,    30,   107,   160,   161,   171,   172,   237,   176,
      35,   157,   158,   159,   171,   172,   237,    73,   157,    73,
     200,    30,   172,   234,   111,   111,   108,   200,   202,   119,
     106,    65,   204,   110,   199,   108,   111,   107,   202,   202,
     202,   200,    65,   204,   111,   111,     5,    17,    18,   222,
      87,   237,   117,   109,   113,   172,    73,   109,   113,   222,
     172,   236,   237,   109,   236,   111,   108,   109,   120,   219,
     220,   111,   119,   107,   207,   208,   237,   113,   111,   108,
     186,   227,   161,   172,   159,   222,   229,   229,   213,   118,
     221,   237,   109,   113,   109,   113,   196,   201,   168,   174,
     174,   188,   221,   118,   220,   208,    20,    74,    78,   209,
     210,     4,    19,   115,   169,   170,   179,   237,   169,   109,
     170,   116
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
#line 350 "asn1p_y.y"
    {
		*(void **)param = yyvsp[0].a_grammar;
	}
    break;

  case 3:
#line 356 "asn1p_y.y"
    {
		yyval.a_grammar = asn1p_new();
		checkmem(yyval.a_grammar);
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 4:
#line 361 "asn1p_y.y"
    {
		yyval.a_grammar = yyvsp[-1].a_grammar;
		TQ_ADD(&(yyval.a_grammar->modules), yyvsp[0].a_module, mod_next);
	}
    break;

  case 5:
#line 378 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 6:
#line 383 "asn1p_y.y"
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
#line 407 "asn1p_y.y"
    { yyval.a_oid = 0; }
    break;

  case 8:
#line 408 "asn1p_y.y"
    { yyval.a_oid = yyvsp[0].a_oid; }
    break;

  case 9:
#line 412 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
	}
    break;

  case 10:
#line 415 "asn1p_y.y"
    {
		yyval.a_oid = 0;
	}
    break;

  case 11:
#line 421 "asn1p_y.y"
    {
		yyval.a_oid = asn1p_oid_new();
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 12:
#line 427 "asn1p_y.y"
    {
		yyval.a_oid = yyvsp[-1].a_oid;
		asn1p_oid_add_arc(yyval.a_oid, &yyvsp[0].a_oid_arc);
		if(yyvsp[0].a_oid_arc.name)
			free(yyvsp[0].a_oid_arc.name);
	}
    break;

  case 13:
#line 436 "asn1p_y.y"
    {					/* iso */
		yyval.a_oid_arc.name = yyvsp[0].tv_str;
		yyval.a_oid_arc.number = -1;
	}
    break;

  case 14:
#line 440 "asn1p_y.y"
    {		/* iso(1) */
		yyval.a_oid_arc.name = yyvsp[-3].tv_str;
		yyval.a_oid_arc.number = yyvsp[-1].a_int;
	}
    break;

  case 15:
#line 444 "asn1p_y.y"
    {					/* 1 */
		yyval.a_oid_arc.name = 0;
		yyval.a_oid_arc.number = yyvsp[0].a_int;
	}
    break;

  case 16:
#line 454 "asn1p_y.y"
    { yyval.a_module_flags = MSF_NOFLAGS; }
    break;

  case 17:
#line 455 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 18:
#line 464 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[0].a_module_flags;
	}
    break;

  case 19:
#line 467 "asn1p_y.y"
    {
		yyval.a_module_flags = yyvsp[-1].a_module_flags | yyvsp[0].a_module_flags;
	}
    break;

  case 20:
#line 476 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXPLICIT_TAGS;
	}
    break;

  case 21:
#line 479 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_IMPLICIT_TAGS;
	}
    break;

  case 22:
#line 482 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 23:
#line 485 "asn1p_y.y"
    {
		yyval.a_module_flags = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 24:
#line 489 "asn1p_y.y"
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
#line 510 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 26:
#line 511 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 27:
#line 520 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		AL_IMPORT(yyval.a_module, exports, yyvsp[-2].a_module, xp_next);
		AL_IMPORT(yyval.a_module, imports, yyvsp[-1].a_module, xp_next);
		AL_IMPORT(yyval.a_module, members, yyvsp[0].a_module, next);
	}
    break;

  case 28:
#line 529 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[0].a_module;
	}
    break;

  case 29:
#line 532 "asn1p_y.y"
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
#line 548 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 31:
#line 555 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 32:
#line 568 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		assert(yyvsp[0].a_expr->expr_type != A1TC_INVALID);
		assert(yyvsp[0].a_expr->meta_type != AMT_INVALID);
		TQ_ADD(&(yyval.a_module->members), yyvsp[0].a_expr, next);
	}
    break;

  case 33:
#line 576 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 577 "asn1p_y.y"
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
#line 589 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 602 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 38:
#line 606 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		yyval.a_module = yyvsp[-1].a_module;
	}
    break;

  case 39:
#line 616 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 40:
#line 622 "asn1p_y.y"
    {
		yyval.a_module = asn1p_module_new();
		checkmem(yyval.a_module);
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 41:
#line 627 "asn1p_y.y"
    {
		yyval.a_module = yyvsp[-1].a_module;
		TQ_ADD(&(yyval.a_module->imports), yyvsp[0].a_xports, xp_next);
	}
    break;

  case 42:
#line 634 "asn1p_y.y"
    { memset(&yyval.a_aid, 0, sizeof(yyval.a_aid)); }
    break;

  case 43:
#line 635 "asn1p_y.y"
    { yyval.a_aid.oid = yyvsp[0].a_oid; }
    break;

  case 44:
#line 639 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-3].a_xports;
		yyval.a_xports->fromModuleName = yyvsp[-1].tv_str;
		yyval.a_xports->identifier = yyvsp[0].a_aid;
		/* This stupid thing is used for look-back hack. */
		saved_aid = yyval.a_xports->identifier.oid ? 0 : &(yyval.a_xports->identifier);
		checkmem(yyval.a_xports);
	}
    break;

  case 45:
#line 650 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 46:
#line 655 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 47:
#line 662 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 48:
#line 668 "asn1p_y.y"
    {		/* Completely equivalent to above */
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 49:
#line 674 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
	}
    break;

  case 50:
#line 684 "asn1p_y.y"
    { yyval.a_module = 0; }
    break;

  case 51:
#line 685 "asn1p_y.y"
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

  case 52:
#line 697 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-1].a_xports;
	}
    break;

  case 53:
#line 700 "asn1p_y.y"
    {
		yyval.a_xports = 0;
	}
    break;

  case 54:
#line 703 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		yyval.a_xports = asn1p_xports_new();
		checkmem(yyval.a_xports);
	}
    break;

  case 55:
#line 711 "asn1p_y.y"
    {
		yyval.a_xports = asn1p_xports_new();
		assert(yyval.a_xports);
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 56:
#line 716 "asn1p_y.y"
    {
		yyval.a_xports = yyvsp[-2].a_xports;
		TQ_ADD(&(yyval.a_xports->members), yyvsp[0].a_expr, next);
	}
    break;

  case 57:
#line 723 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 58:
#line 729 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 59:
#line 735 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
		yyval.a_expr->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 60:
#line 744 "asn1p_y.y"
    { yyval.a_constr = yyvsp[-1].a_constr; }
    break;

  case 61:
#line 747 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 62:
#line 757 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 63:
#line 770 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 64:
#line 780 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[-3].a_ref;
		yyval.a_expr->rhs_pspecs = yyvsp[-1].a_expr;
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_TYPEREF;
	}
    break;

  case 65:
#line 800 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type);
		assert(yyval.a_expr->meta_type);
	}
    break;

  case 66:
#line 806 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 67:
#line 822 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 68:
#line 828 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		yyval.a_expr->Identifier = yyvsp[-5].tv_str;
		yyval.a_expr->lhs_params = yyvsp[-3].a_plist;
	}
    break;

  case 69:
#line 836 "asn1p_y.y"
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

  case 70:
#line 845 "asn1p_y.y"
    {
		int ret;
		yyval.a_plist = yyvsp[-2].a_plist;
		ret = asn1p_paramlist_add_param(yyval.a_plist, yyvsp[0].a_parg.governor, yyvsp[0].a_parg.argument);
		checkmem(ret == 0);
		if(yyvsp[0].a_parg.governor) asn1p_ref_free(yyvsp[0].a_parg.governor);
		if(yyvsp[0].a_parg.argument) free(yyvsp[0].a_parg.argument);
	}
    break;

  case 71:
#line 856 "asn1p_y.y"
    {
		yyval.a_parg.governor = NULL;
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 72:
#line 860 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 73:
#line 867 "asn1p_y.y"
    {
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor, yyvsp[-2].tv_str, 0);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 74:
#line 874 "asn1p_y.y"
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
		int ret;
		yyval.a_parg.governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component(yyval.a_parg.governor,
			ASN_EXPR_TYPE2STR(yyvsp[-2].a_type), 1);
		checkmem(ret == 0);
		yyval.a_parg.argument = yyvsp[0].tv_str;
	}
    break;

  case 76:
#line 893 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 77:
#line 898 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 78:
#line 905 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 79:
#line 908 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = "?";
		yyval.a_expr->expr_type = A1TC_REFERENCE;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 80:
#line 916 "asn1p_y.y"
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

  case 81:
#line 927 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->expr_type = A1TC_VALUESET;
		yyval.a_expr->meta_type = AMT_VALUESET;
		yyval.a_expr->constraints = yyvsp[0].a_constr;
	}
    break;

  case 82:
#line 950 "asn1p_y.y"
    { yyval.a_expr = NEW_EXPR(); }
    break;

  case 83:
#line 951 "asn1p_y.y"
    { yyval.a_expr = yyvsp[0].a_expr; }
    break;

  case 84:
#line 954 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 85:
#line 959 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 86:
#line 966 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 87:
#line 973 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		yyvsp[0].a_marker.flags |= yyval.a_expr->marker.flags;
		yyval.a_expr->marker = yyvsp[0].a_marker;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 88:
#line 979 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->meta_type = yyvsp[0].a_expr->meta_type;
		yyval.a_expr->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 89:
#line 986 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 90:
#line 992 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 91:
#line 997 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 92:
#line 1004 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		assert(yyval.a_expr->Identifier == 0);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
	}
    break;

  case 93:
#line 1009 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 94:
#line 1012 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
		_fixup_anonymous_identifier(yyval.a_expr);
	}
    break;

  case 95:
#line 1019 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		checkmem(yyval.a_expr);
		yyval.a_expr->with_syntax = yyvsp[0].a_wsynt;
		assert(yyval.a_expr->expr_type == A1TC_CLASSDEF);
		assert(yyval.a_expr->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 96:
#line 1029 "asn1p_y.y"
    { yyval.a_int = 0; }
    break;

  case 97:
#line 1030 "asn1p_y.y"
    { yyval.a_int = 1; }
    break;

  case 98:
#line 1034 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_CLASSDEF;
		yyval.a_expr->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 99:
#line 1041 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 100:
#line 1051 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = yyvsp[-1].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 101:
#line 1061 "asn1p_y.y"
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

  case 102:
#line 1072 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 103:
#line 1082 "asn1p_y.y"
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

  case 104:
#line 1093 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		yyval.a_expr->Identifier = yyvsp[-2].tv_str;
		yyval.a_expr->meta_type = AMT_OBJECTFIELD;
		yyval.a_expr->expr_type = A1TC_CLASSFIELD_VTVSFS;
		yyval.a_expr->reference = yyvsp[-1].a_ref;
		yyval.a_expr->marker = yyvsp[0].a_marker;
	}
    break;

  case 105:
#line 1103 "asn1p_y.y"
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

  case 106:
#line 1114 "asn1p_y.y"
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

  case 107:
#line 1126 "asn1p_y.y"
    { yyval.a_wsynt = 0; }
    break;

  case 108:
#line 1127 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[0].a_wsynt;
	}
    break;

  case 109:
#line 1134 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 110:
#line 1136 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
	}
    break;

  case 111:
#line 1142 "asn1p_y.y"
    {
		yyval.a_wsynt = asn1p_wsyntx_new();
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 112:
#line 1146 "asn1p_y.y"
    {
		yyval.a_wsynt = yyvsp[-1].a_wsynt;
		TQ_ADD(&(yyval.a_wsynt->chunks), yyvsp[0].a_wchunk, next);
	}
    break;

  case 113:
#line 1153 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_opaque.buf, 0);
		yyval.a_wchunk->type = WC_WHITESPACE;
	}
    break;

  case 114:
#line 1157 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].tv_str, 0);
	}
    break;

  case 115:
#line 1160 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromstring(yyvsp[0].a_refcomp.name, 0);
		yyval.a_wchunk->type = WC_FIELD;
	}
    break;

  case 116:
#line 1164 "asn1p_y.y"
    {
		yyval.a_wchunk = asn1p_wsyntx_chunk_fromsyntax(yyvsp[-1].a_wsynt);
	}
    break;

  case 117:
#line 1170 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 118:
#line 1178 "asn1p_y.y"
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

  case 119:
#line 1187 "asn1p_y.y"
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

  case 120:
#line 1199 "asn1p_y.y"
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

  case 121:
#line 1221 "asn1p_y.y"
    {
		yyval.a_int = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 122:
#line 1228 "asn1p_y.y"
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

  case 123:
#line 1247 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[0].a_expr;
	}
    break;

  case 124:
#line 1250 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_CHOICE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 125:
#line 1256 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SEQUENCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 126:
#line 1262 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
		assert(yyval.a_expr->expr_type == A1TC_INVALID);
		yyval.a_expr->expr_type = ASN_CONSTR_SET;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 127:
#line 1268 "asn1p_y.y"
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

  case 128:
#line 1278 "asn1p_y.y"
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

  case 129:
#line 1288 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = ASN_TYPE_ANY;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 130:
#line 1294 "asn1p_y.y"
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

  case 131:
#line 1305 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->reference = yyvsp[0].a_ref;
		yyval.a_expr->expr_type = A1TC_INSTANCE;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 132:
#line 1320 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_UNKNOWN);
		checkmem(ret == 0);
		free(yyvsp[0].tv_str);
	}
    break;

  case 133:
#line 1328 "asn1p_y.y"
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
#line 1338 "asn1p_y.y"
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

  case 135:
#line 1348 "asn1p_y.y"
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

  case 136:
#line 1358 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
		free(yyvsp[0].tv_str);
		checkmem(ret == 0);
	}
    break;

  case 137:
#line 1366 "asn1p_y.y"
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

  case 138:
#line 1388 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = asn1p_ref_new(yylineno);
		checkmem(yyval.a_ref);
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 139:
#line 1396 "asn1p_y.y"
    {
		int ret;
		yyval.a_ref = yyvsp[-2].a_ref;
		ret = asn1p_ref_add_component(yyval.a_ref, yyvsp[0].a_refcomp.name, yyvsp[0].a_refcomp.lex_type);
		free(yyvsp[0].a_refcomp.name);
		checkmem(ret == 0);
	}
    break;

  case 141:
#line 1409 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_AmpUppercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 142:
#line 1414 "asn1p_y.y"
    {
		yyval.a_refcomp.lex_type = RLT_Amplowercase;
		yyval.a_refcomp.name = yyvsp[0].tv_str;
	}
    break;

  case 143:
#line 1423 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 144:
#line 1427 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_AmpUppercase);
	}
    break;

  case 145:
#line 1431 "asn1p_y.y"
    {
		yyval.a_ref = yyval.a_ref;
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_Amplowercase);
	}
    break;

  case 146:
#line 1438 "asn1p_y.y"
    {
		yyval.a_ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(yyval.a_ref, yyvsp[0].tv_str, RLT_CAPITALS);
	}
    break;

  case 147:
#line 1458 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		assert(yyval.a_expr->Identifier == NULL);
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 150:
#line 1470 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_CHOICE_IDENTIFIER;
		yyval.a_value->value.choice_identifier.identifier = yyvsp[-2].tv_str;
		yyval.a_value->value.choice_identifier.value = yyvsp[0].a_value;
	}
    break;

  case 151:
#line 1477 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 152:
#line 1477 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_UNPARSED;
	}
    break;

  case 153:
#line 1482 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_NULL;
	}
    break;

  case 154:
#line 1490 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 155:
#line 1495 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 156:
#line 1500 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'B');
		checkmem(yyval.a_value);
	}
    break;

  case 157:
#line 1504 "asn1p_y.y"
    {
		yyval.a_value = _convert_bitstring2binary(yyvsp[0].tv_str, 'H');
		checkmem(yyval.a_value);
	}
    break;

  case 158:
#line 1508 "asn1p_y.y"
    {
		yyval.a_value = yyval.a_value;
	}
    break;

  case 159:
#line 1511 "asn1p_y.y"
    {
		yyval.a_value = yyvsp[0].a_value;
	}
    break;

  case 160:
#line 1517 "asn1p_y.y"
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

  case 161:
#line 1528 "asn1p_y.y"
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

  case 162:
#line 1546 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_value);
	}
    break;

  case 163:
#line 1550 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TUPLE;
	}
    break;

  case 164:
#line 1555 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_QUADRUPLE;
	}
    break;

  case 165:
#line 1589 "asn1p_y.y"
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

  case 166:
#line 1598 "asn1p_y.y"
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

  case 167:
#line 1613 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BOOLEAN; }
    break;

  case 168:
#line 1614 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_NULL; }
    break;

  case 169:
#line 1615 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_REAL; }
    break;

  case 170:
#line 1616 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 171:
#line 1617 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OCTET_STRING; }
    break;

  case 172:
#line 1618 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 173:
#line 1619 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_RELATIVE_OID; }
    break;

  case 174:
#line 1620 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EXTERNAL; }
    break;

  case 175:
#line 1621 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 176:
#line 1622 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 177:
#line 1623 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_UTCTime; }
    break;

  case 178:
#line 1624 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_GeneralizedTime; }
    break;

  case 179:
#line 1625 "asn1p_y.y"
    { yyval.a_type = yyvsp[0].a_type; }
    break;

  case 180:
#line 1632 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_INTEGER; }
    break;

  case 181:
#line 1633 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_ENUMERATED; }
    break;

  case 182:
#line 1634 "asn1p_y.y"
    { yyval.a_type = ASN_BASIC_BIT_STRING; }
    break;

  case 183:
#line 1638 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = yyvsp[0].a_type;
		yyval.a_expr->meta_type = AMT_TYPE;
	}
    break;

  case 184:
#line 1644 "asn1p_y.y"
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

  case 185:
#line 1657 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_BMPString; }
    break;

  case 186:
#line 1658 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 187:
#line 1662 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 188:
#line 1666 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_IA5String; }
    break;

  case 189:
#line 1667 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ISO646String; }
    break;

  case 190:
#line 1668 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_NumericString; }
    break;

  case 191:
#line 1669 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_PrintableString; }
    break;

  case 192:
#line 1670 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 193:
#line 1674 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_TeletexString; }
    break;

  case 194:
#line 1675 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UniversalString; }
    break;

  case 195:
#line 1676 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_UTF8String; }
    break;

  case 196:
#line 1677 "asn1p_y.y"
    {
		yyval.a_type = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 197:
#line 1681 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_VisibleString; }
    break;

  case 198:
#line 1682 "asn1p_y.y"
    { yyval.a_type = ASN_STRING_ObjectDescriptor; }
    break;

  case 204:
#line 1694 "asn1p_y.y"
    { yyval.a_constr = 0; }
    break;

  case 205:
#line 1695 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 207:
#line 1702 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 208:
#line 1708 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[0].a_constr, 0);
	}
    break;

  case 209:
#line 1711 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_SIZE, yyvsp[-1].a_constr, 0);
	}
    break;

  case 210:
#line 1721 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[-1].a_constr;
	}
    break;

  case 211:
#line 1724 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_SET, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 212:
#line 1730 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_EL_EXT;
	}
    break;

  case 213:
#line 1734 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 214:
#line 1737 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 215:
#line 1743 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-4].a_constr, ct);
		ct = yyval.a_constr;
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, ct, yyvsp[0].a_constr);
	}
    break;

  case 216:
#line 1754 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 217:
#line 1757 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_AEX, yyvsp[0].a_constr, 0);
	}
    break;

  case 218:
#line 1760 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_UNI, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 219:
#line 1763 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_INT, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 220:
#line 1766 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_EXC, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 221:
#line 1772 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-3].a_ctype;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 222:
#line 1780 "asn1p_y.y"
    {
		int ret;
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CA_SET;
		ret = asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
		checkmem(ret == 0);
	}
    break;

  case 223:
#line 1788 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = yyvsp[0].a_value;
	}
    break;

  case 224:
#line 1794 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_TYPE;
		yyval.a_constr->containedSubtype = yyvsp[0].a_value;
	}
    break;

  case 225:
#line 1800 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = yyvsp[0].a_value;
	}
    break;

  case 226:
#line 1807 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = asn1p_value_fromint(-123);
		yyval.a_constr->range_stop = yyvsp[0].a_value;
		yyval.a_constr->range_start->type = ATV_MIN;
	}
    break;

  case 227:
#line 1815 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = yyvsp[-1].a_ctype;
		yyval.a_constr->range_start = yyvsp[-2].a_value;
		yyval.a_constr->range_stop = asn1p_value_fromint(321);
		yyval.a_constr->range_stop->type = ATV_MAX;
	}
    break;

  case 228:
#line 1823 "asn1p_y.y"
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

  case 229:
#line 1832 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 230:
#line 1838 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_SIZE;
	}
    break;

  case 231:
#line 1841 "asn1p_y.y"
    {
		yyval.a_ctype = ACT_CT_FROM;
	}
    break;

  case 232:
#line 1847 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(0);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_FALSE;
	}
    break;

  case 233:
#line 1852 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(1);
		checkmem(yyval.a_value);
		yyval.a_value->type = ATV_TRUE;
	}
    break;

  case 236:
#line 1859 "asn1p_y.y"
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

  case 237:
#line 1873 "asn1p_y.y"
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

  case 238:
#line 1887 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMP, yyvsp[0].a_constr, 0);
	}
    break;

  case 239:
#line 1890 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-1].a_constr, 0);
	}
    break;

  case 240:
#line 1896 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 241:
#line 1899 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CT_WCOMPS, yyvsp[-2].a_constr, yyvsp[0].a_constr);
	}
    break;

  case 242:
#line 1905 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_EXT;
		yyval.a_constr->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 243:
#line 1911 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[-2].tv_str, strlen(yyvsp[-2].tv_str), 0);
		yyval.a_constr->presence = yyvsp[0].a_pres;
		if(yyvsp[-1].a_constr) asn1p_constraint_insert(yyval.a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 244:
#line 1925 "asn1p_y.y"
    { yyval.a_pres = ACPRES_DEFAULT; }
    break;

  case 245:
#line 1926 "asn1p_y.y"
    { yyval.a_pres = yyvsp[0].a_pres; }
    break;

  case 246:
#line 1930 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_PRESENT;
	}
    break;

  case 247:
#line 1933 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_ABSENT;
	}
    break;

  case 248:
#line 1936 "asn1p_y.y"
    {
		yyval.a_pres = ACPRES_OPTIONAL;
	}
    break;

  case 252:
#line 1951 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 253:
#line 1951 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_CT_CTDBY;
		yyval.a_constr->value = asn1p_value_frombuf(yyvsp[0].tv_opaque.buf, yyvsp[0].tv_opaque.len, 0);
		checkmem(yyval.a_constr->value);
		yyval.a_constr->value->type = ATV_UNPARSED;
	}
    break;

  case 254:
#line 1962 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		yyval.a_constr->type = ACT_CT_CTNG;
		yyval.a_constr->value = asn1p_value_fromtype(yyvsp[0].a_expr);
	}
    break;

  case 255:
#line 1970 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RANGE; }
    break;

  case 256:
#line 1971 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_RLRANGE; }
    break;

  case 257:
#line 1972 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_LLRANGE; }
    break;

  case 258:
#line 1973 "asn1p_y.y"
    { yyval.a_ctype = ACT_EL_ULRANGE; }
    break;

  case 259:
#line 1976 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 260:
#line 1979 "asn1p_y.y"
    {
		yyval.a_constr = yyvsp[0].a_constr;
	}
    break;

  case 261:
#line 1988 "asn1p_y.y"
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

  case 262:
#line 2003 "asn1p_y.y"
    {
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CRC, yyvsp[-3].a_constr, yyvsp[-1].a_constr);
	}
    break;

  case 263:
#line 2009 "asn1p_y.y"
    {
		yyval.a_constr = asn1p_constraint_new(yylineno);
		checkmem(yyval.a_constr);
		yyval.a_constr->type = ACT_EL_VALUE;
		yyval.a_constr->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
	}
    break;

  case 264:
#line 2015 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(yyvsp[0].a_ref, 0);
		CONSTRAINT_INSERT(yyval.a_constr, ACT_CA_CSV, yyvsp[-2].a_constr, ct);
	}
    break;

  case 265:
#line 2029 "asn1p_y.y"
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

  case 266:
#line 2040 "asn1p_y.y"
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

  case 267:
#line 2056 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 268:
#line 2059 "asn1p_y.y"
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

  case 269:
#line 2077 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_NOMARK;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 270:
#line 2081 "asn1p_y.y"
    { yyval.a_marker = yyvsp[0].a_marker; }
    break;

  case 271:
#line 2085 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_OPTIONAL | EM_INDIRECT;
		yyval.a_marker.default_value = 0;
	}
    break;

  case 272:
#line 2089 "asn1p_y.y"
    {
		yyval.a_marker.flags = EM_DEFAULT;
		yyval.a_marker.default_value = yyvsp[0].a_value;
	}
    break;

  case 273:
#line 2112 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
	}
    break;

  case 274:
#line 2116 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-1].a_expr;
	}
    break;

  case 275:
#line 2122 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 276:
#line 2127 "asn1p_y.y"
    {
		yyval.a_expr = yyvsp[-2].a_expr;
		asn1p_expr_add(yyval.a_expr, yyvsp[0].a_expr);
	}
    break;

  case 277:
#line 2134 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[0].tv_str;
	}
    break;

  case 278:
#line 2141 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 279:
#line 2149 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->Identifier = yyvsp[-3].tv_str;
		yyval.a_expr->value = yyvsp[-1].a_value;
	}
    break;

  case 280:
#line 2157 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->expr_type = A1TC_UNIVERVAL;
		yyval.a_expr->meta_type = AMT_VALUE;
		yyval.a_expr->value = yyvsp[0].a_value;
	}
    break;

  case 281:
#line 2164 "asn1p_y.y"
    {
		yyval.a_expr = NEW_EXPR();
		checkmem(yyval.a_expr);
		yyval.a_expr->Identifier = strdup("...");
		checkmem(yyval.a_expr->Identifier);
		yyval.a_expr->expr_type = A1TC_EXTENSIBLE;
		yyval.a_expr->meta_type = AMT_VALUE;
	}
    break;

  case 282:
#line 2175 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 283:
#line 2179 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromint(yyvsp[0].a_int);
		checkmem(yyval.a_value);
	}
    break;

  case 285:
#line 2187 "asn1p_y.y"
    {
		yyval.a_value = asn1p_value_fromdouble(yyvsp[0].a_dbl);
		checkmem(yyval.a_value);
	}
    break;

  case 286:
#line 2218 "asn1p_y.y"
    { memset(&yyval.a_tag, 0, sizeof(yyval.a_tag)); }
    break;

  case 287:
#line 2219 "asn1p_y.y"
    { yyval.a_tag = yyvsp[0].a_tag; }
    break;

  case 288:
#line 2223 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-1].a_tag;
		yyval.a_tag.tag_mode = yyvsp[0].a_tag.tag_mode;
	}
    break;

  case 289:
#line 2230 "asn1p_y.y"
    {
		yyval.a_tag = yyvsp[-2].a_tag;
		yyval.a_tag.tag_value = yyvsp[-1].a_int;
	}
    break;

  case 290:
#line 2236 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 291:
#line 2237 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_UNIVERSAL; }
    break;

  case 292:
#line 2238 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_APPLICATION; }
    break;

  case 293:
#line 2239 "asn1p_y.y"
    { yyval.a_tag.tag_class = TC_PRIVATE; }
    break;

  case 294:
#line 2243 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_DEFAULT; }
    break;

  case 295:
#line 2244 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_IMPLICIT; }
    break;

  case 296:
#line 2245 "asn1p_y.y"
    { yyval.a_tag.tag_mode = TM_EXPLICIT; }
    break;

  case 297:
#line 2249 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 298:
#line 2253 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 299:
#line 2261 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 300:
#line 2268 "asn1p_y.y"
    { yyval.tv_str = 0; }
    break;

  case 301:
#line 2269 "asn1p_y.y"
    {
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;

  case 302:
#line 2275 "asn1p_y.y"
    {
		checkmem(yyvsp[0].tv_str);
		yyval.tv_str = yyvsp[0].tv_str;
	}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 4346 "asn1p_y.c"

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


#line 2281 "asn1p_y.y"



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


