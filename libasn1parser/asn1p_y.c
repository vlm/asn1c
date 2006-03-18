/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
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
/* Tokens.  */
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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 72 "asn1p_y.y"
typedef union YYSTYPE {
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
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 400 "asn1p_y.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 412 "asn1p_y.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   757

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  107
/* YYNRULES -- Number of rules. */
#define YYNRULES  286
/* YYNRULES -- Number of states. */
#define YYNSTATES  445

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    19,    20,    22,    26,
      29,    31,    34,    36,    41,    43,    44,    46,    48,    51,
      54,    57,    60,    63,    66,    67,    69,    71,    74,    76,
      78,    80,    82,    84,    85,    89,    91,    95,    98,   100,
     103,   104,   106,   111,   113,   117,   119,   123,   125,   129,
     133,   136,   138,   142,   144,   148,   150,   151,   158,   160,
     162,   166,   170,   177,   179,   183,   185,   189,   193,   197,
     199,   203,   205,   207,   208,   210,   212,   216,   220,   223,
     227,   229,   231,   235,   238,   240,   242,   248,   249,   251,
     253,   257,   260,   265,   269,   273,   277,   281,   285,   286,
     288,   289,   296,   298,   301,   303,   305,   307,   311,   313,
     317,   321,   325,   326,   329,   331,   336,   341,   346,   353,
     360,   362,   367,   372,   374,   378,   380,   384,   388,   392,
     394,   398,   400,   404,   406,   408,   410,   412,   416,   420,
     422,   427,   431,   432,   436,   438,   440,   442,   444,   446,
     448,   450,   452,   454,   458,   460,   462,   464,   466,   469,
     471,   473,   475,   477,   480,   483,   485,   487,   490,   493,
     495,   497,   499,   501,   503,   506,   508,   511,   513,   515,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   535,
     537,   539,   541,   543,   545,   547,   549,   550,   552,   554,
     559,   563,   568,   570,   574,   580,   582,   586,   590,   594,
     598,   603,   607,   609,   611,   615,   619,   623,   627,   629,
     631,   632,   638,   640,   643,   646,   650,   652,   654,   656,
     658,   660,   662,   664,   666,   670,   676,   678,   682,   684,
     688,   689,   691,   693,   695,   697,   699,   701,   705,   710,
     712,   716,   719,   723,   725,   729,   730,   732,   734,   737,
     740,   744,   746,   750,   752,   757,   762,   764,   766,   768,
     770,   771,   773,   776,   781,   782,   784,   786,   788,   789,
     791,   793,   795,   797,   799,   800,   802
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     121,     0,    -1,   122,    -1,   123,    -1,   122,   123,    -1,
     223,   124,    38,   128,     3,    25,   131,    43,    -1,    -1,
     125,    -1,   107,   126,   108,    -1,   107,   108,    -1,   127,
      -1,   126,   127,    -1,   226,    -1,   226,   109,    10,   110,
      -1,    10,    -1,    -1,   129,    -1,   130,    -1,   129,   130,
      -1,    45,    88,    -1,    56,    88,    -1,    24,    88,    -1,
      47,    57,    -1,    15,    61,    -1,    -1,   132,    -1,   133,
      -1,   132,   133,    -1,   135,    -1,   141,    -1,   147,    -1,
     177,    -1,   144,    -1,    -1,    42,    15,   134,    -1,   186,
      -1,    58,   136,   111,    -1,    58,    50,    -1,   138,    -1,
     136,   138,    -1,    -1,   125,    -1,   139,    50,   223,   137,
      -1,   140,    -1,   139,   112,   140,    -1,   223,    -1,   223,
     107,   108,    -1,   226,    -1,    46,   142,   111,    -1,    46,
      21,   111,    -1,    46,   111,    -1,   143,    -1,   142,   112,
     143,    -1,   223,    -1,   223,   107,   108,    -1,   226,    -1,
      -1,   223,   146,     3,   107,   145,   182,    -1,   171,    -1,
     183,    -1,   223,     3,   167,    -1,   223,     3,   157,    -1,
     223,   107,   148,   108,     3,   167,    -1,   149,    -1,   148,
     112,   149,    -1,   223,    -1,   223,   113,   226,    -1,   223,
     113,   223,    -1,   183,   113,   226,    -1,   151,    -1,   150,
     112,   151,    -1,   167,    -1,   226,    -1,    -1,   153,    -1,
     154,    -1,   153,   112,   154,    -1,   226,   167,   212,    -1,
     167,   212,    -1,    34,    72,   167,    -1,   166,    -1,   156,
      -1,   155,   112,   156,    -1,   226,   167,    -1,   166,    -1,
     167,    -1,    32,   107,   159,   108,   161,    -1,    -1,    92,
      -1,   160,    -1,   159,   112,   160,    -1,    16,   212,    -1,
      17,   167,   158,   212,    -1,    17,   175,   212,    -1,    17,
     176,   212,    -1,    16,   175,   212,    -1,    16,   167,   212,
      -1,    16,   176,   212,    -1,    -1,   162,    -1,    -1,    99,
      86,   107,   163,   164,   108,    -1,   165,    -1,   164,   165,
      -1,     4,    -1,    18,    -1,   174,    -1,   114,   164,   115,
      -1,   106,    -1,   106,   116,   180,    -1,   106,   116,   217,
      -1,   218,   169,   190,    -1,    -1,   168,   170,    -1,   185,
      -1,    31,   107,   155,   108,    -1,    82,   107,   152,   108,
      -1,    83,   107,   152,   108,    -1,    82,   190,    72,   225,
     218,   169,    -1,    83,   190,    72,   225,   218,   169,    -1,
      22,    -1,    22,    39,    29,   226,    -1,   223,   107,   150,
     108,    -1,   171,    -1,    60,    72,   171,    -1,    14,    -1,
      14,   117,   223,    -1,   224,   117,   223,    -1,    14,   117,
     226,    -1,   224,    -1,   224,   117,   172,    -1,   173,    -1,
     172,   117,   173,    -1,   174,    -1,    16,    -1,    17,    -1,
      16,    -1,   175,   117,    16,    -1,   175,   117,    17,    -1,
      15,    -1,   226,   146,     3,   178,    -1,   226,   113,   178,
      -1,    -1,   107,   179,   182,    -1,    67,    -1,    49,    -1,
      90,    -1,     6,    -1,     8,    -1,   181,    -1,   217,    -1,
     180,    -1,   226,    -1,   223,   117,   226,    -1,     7,    -1,
      11,    -1,    12,    -1,     5,    -1,   182,     5,    -1,    28,
      -1,    67,    -1,    80,    -1,   184,    -1,    71,    85,    -1,
      69,    55,    -1,    81,    -1,    48,    -1,    40,    75,    -1,
      30,    85,    -1,    95,    -1,    51,    -1,   186,    -1,    62,
      -1,    44,    -1,    26,    85,    -1,   183,    -1,   184,   214,
      -1,    27,    -1,    52,    -1,    53,    -1,    54,    -1,    63,
      -1,    68,    -1,    78,    -1,    87,    -1,    89,    -1,    94,
      -1,    96,    -1,    97,    -1,    98,    -1,    70,    -1,   103,
      -1,   104,    -1,   101,    -1,   102,    -1,   100,    -1,    -1,
     191,    -1,   192,    -1,    84,   109,   193,   110,    -1,   109,
     193,   110,    -1,   192,   109,   193,   110,    -1,   194,    -1,
     194,   112,   106,    -1,   194,   112,   106,   112,   194,    -1,
     195,    -1,    21,   100,   195,    -1,   194,   187,   195,    -1,
     194,   188,   195,    -1,   195,   189,   195,    -1,   198,   109,
     193,   110,    -1,   109,   193,   110,    -1,   199,    -1,   200,
      -1,   199,   197,   199,    -1,    65,   197,   199,    -1,   199,
     197,    64,    -1,    65,   197,    64,    -1,   206,    -1,   201,
      -1,    -1,    35,    29,   107,   196,   182,    -1,   105,    -1,
     105,   118,    -1,   118,   105,    -1,   118,   105,   118,    -1,
      84,    -1,    50,    -1,    49,    -1,    90,    -1,   217,    -1,
     181,    -1,   226,    -1,   223,    -1,    99,    33,   192,    -1,
      99,    34,   107,   202,   108,    -1,   203,    -1,   202,   112,
     203,    -1,   106,    -1,   226,   190,   204,    -1,    -1,   205,
      -1,    77,    -1,    19,    -1,    73,    -1,   207,    -1,   208,
      -1,   107,   223,   108,    -1,   207,   107,   209,   108,    -1,
     210,    -1,   209,   112,   210,    -1,   119,   211,    -1,   119,
     117,   211,    -1,   226,    -1,   211,   117,   226,    -1,    -1,
     213,    -1,    73,    -1,    37,   178,    -1,   107,   108,    -1,
     107,   215,   108,    -1,   216,    -1,   215,   112,   216,    -1,
     226,    -1,   226,   109,   217,   110,    -1,   226,   109,   180,
     110,    -1,   217,    -1,   106,    -1,    10,    -1,    13,    -1,
      -1,   219,    -1,   220,   222,    -1,   114,   221,    10,   115,
      -1,    -1,    93,    -1,    23,    -1,    79,    -1,    -1,    56,
      -1,    45,    -1,    14,    -1,    15,    -1,    15,    -1,    -1,
     226,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   322,   322,   328,   333,   350,   375,   376,   380,   383,
     389,   395,   404,   408,   412,   422,   423,   432,   435,   444,
     447,   450,   453,   457,   478,   479,   488,   491,   524,   527,
     536,   543,   556,   564,   563,   577,   590,   600,   606,   611,
     618,   619,   623,   634,   639,   646,   652,   658,   667,   670,
     673,   681,   686,   693,   699,   705,   716,   715,   726,   733,
     751,   757,   773,   783,   792,   803,   807,   814,   821,   832,
     837,   844,   847,   871,   872,   875,   880,   887,   894,   900,
     907,   913,   918,   925,   930,   933,   940,   950,   951,   955,
     962,   972,   982,   993,  1003,  1014,  1024,  1035,  1047,  1048,
    1055,  1054,  1063,  1067,  1074,  1078,  1081,  1085,  1091,  1099,
    1108,  1120,  1142,  1149,  1168,  1171,  1177,  1183,  1189,  1199,
    1209,  1215,  1229,  1253,  1260,  1275,  1283,  1293,  1303,  1313,
    1321,  1343,  1351,  1360,  1364,  1369,  1378,  1382,  1386,  1393,
    1413,  1423,  1430,  1430,  1435,  1440,  1445,  1450,  1454,  1458,
    1461,  1464,  1470,  1481,  1499,  1503,  1508,  1542,  1551,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,
    1577,  1578,  1585,  1586,  1587,  1591,  1597,  1610,  1611,  1615,
    1619,  1620,  1621,  1622,  1623,  1627,  1628,  1629,  1630,  1634,
    1635,  1642,  1642,  1643,  1643,  1644,  1647,  1648,  1654,  1657,
    1667,  1670,  1676,  1679,  1685,  1696,  1699,  1702,  1705,  1708,
    1714,  1722,  1730,  1736,  1742,  1749,  1757,  1765,  1774,  1777,
    1781,  1780,  1792,  1793,  1794,  1795,  1799,  1802,  1808,  1813,
    1818,  1821,  1824,  1838,  1852,  1855,  1861,  1864,  1870,  1876,
    1890,  1891,  1895,  1898,  1901,  1907,  1910,  1919,  1934,  1940,
    1946,  1960,  1971,  1987,  1990,  2008,  2012,  2016,  2020,  2043,
    2047,  2053,  2058,  2065,  2072,  2080,  2088,  2095,  2106,  2110,
    2141,  2142,  2146,  2153,  2159,  2160,  2161,  2162,  2166,  2167,
    2168,  2172,  2176,  2184,  2191,  2192,  2198
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_whitespace",
  "TOK_opaque", "TOK_bstring", "TOK_cstring", "TOK_hstring",
  "TOK_identifier", "TOK_number", "TOK_tuple", "TOK_quadruple",
  "TOK_number_negative", "TOK_typereference", "TOK_capitalreference",
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
  "TOK_PLUS_INFINITY", "TOK_PRESENT", "TOK_PrintableString", "TOK_PRIVATE",
  "TOK_REAL", "TOK_RELATIVE_OID", "TOK_SEQUENCE", "TOK_SET", "TOK_SIZE",
  "TOK_STRING", "TOK_SYNTAX", "TOK_T61String", "TOK_TAGS",
  "TOK_TeletexString", "TOK_TRUE", "TOK_TYPE_IDENTIFIER", "TOK_UNIQUE",
  "TOK_UNIVERSAL", "TOK_UniversalString", "TOK_UTCTime", "TOK_UTF8String",
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
  "ExportsBody", "ExportsElement", "ValueSetDefinition", "@2",
  "DefinedTypeRef", "DataTypeReference", "ParameterArgumentList",
  "ParameterArgumentName", "ActualParameterList", "ActualParameter",
  "optComponentTypeLists", "ComponentTypeLists", "ComponentType",
  "AlternativeTypeLists", "AlternativeType", "ObjectClass", "optUnique",
  "FieldSpec", "ClassField", "optWithSyntax", "WithSyntax", "@3",
  "WithSyntaxList", "WithSyntaxToken", "ExtensionAndException", "Type",
  "NSTD_IndirectMarker", "TypeDeclaration", "TypeDeclarationSet",
  "ComplexTypeReference", "ComplexTypeReferenceAmpList",
  "ComplexTypeReferenceElement", "PrimitiveFieldReference", "FieldName",
  "DefinedObjectClass", "ValueDefinition", "Value", "@4", "DefinedValue",
  "RestrictedCharacterStringValue", "Opaque", "BasicTypeId",
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString", "Union",
  "Intersection", "Except", "optConstraints", "Constraints",
  "SetOfConstraints", "ElementSetSpecs", "ElementSetSpec",
  "ConstraintSubtypeElement", "@5", "ConstraintRangeSpec",
  "ConstraintSpec", "SingleValue", "ContainedSubtype",
  "InnerTypeConstraint", "WithComponentsList", "WithComponentsElement",
  "optPresenceConstraint", "PresenceConstraint", "TableConstraint",
  "SimpleTableConstraint", "ComponentRelationConstraint", "AtNotationList",
  "AtNotationElement", "ComponentIdList", "optMarker", "Marker",
  "UniverationDefinition", "UniverationList", "UniverationElement",
  "SignedNumber", "optTag", "Tag", "TagTypeValue", "TagClass", "TagPlicit",
  "TypeRefName", "ObjectClassReference", "optIdentifier", "Identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
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
     141,   142,   142,   143,   143,   143,   145,   144,   146,   146,
     147,   147,   147,   148,   148,   149,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   154,
     154,   155,   155,   156,   156,   156,   157,   158,   158,   159,
     159,   160,   160,   160,   160,   160,   160,   160,   161,   161,
     163,   162,   164,   164,   165,   165,   165,   165,   166,   166,
     166,   167,   168,   169,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   171,   171,   171,   171,   171,
     171,   172,   172,   173,   174,   174,   175,   175,   175,   176,
     177,   178,   179,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   180,   180,   181,   181,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   185,   185,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   188,   188,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   193,   194,   194,   194,   194,   194,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     196,   195,   197,   197,   197,   197,   198,   198,   199,   199,
     199,   199,   199,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   205,   206,   206,   207,   208,   209,
     209,   210,   210,   211,   211,   212,   212,   213,   213,   214,
     214,   215,   215,   216,   216,   216,   216,   216,   217,   217,
     218,   218,   219,   220,   221,   221,   221,   221,   222,   222,
     222,   223,   223,   224,   225,   225,   226
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     8,     0,     1,     3,     2,
       1,     2,     1,     4,     1,     0,     1,     1,     2,     2,
       2,     2,     2,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     0,     3,     1,     3,     2,     1,     2,
       0,     1,     4,     1,     3,     1,     3,     1,     3,     3,
       2,     1,     3,     1,     3,     1,     0,     6,     1,     1,
       3,     3,     6,     1,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     0,     1,     1,     3,     3,     2,     3,
       1,     1,     3,     2,     1,     1,     5,     0,     1,     1,
       3,     2,     4,     3,     3,     3,     3,     3,     0,     1,
       0,     6,     1,     2,     1,     1,     1,     3,     1,     3,
       3,     3,     0,     2,     1,     4,     4,     4,     6,     6,
       1,     4,     4,     1,     3,     1,     3,     3,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     3,     1,
       4,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     4,
       3,     4,     1,     3,     5,     1,     3,     3,     3,     3,
       4,     3,     1,     1,     3,     3,     3,     3,     1,     1,
       0,     5,     1,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     1,     3,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       3,     1,     3,     1,     4,     4,     1,     1,     1,     1,
       0,     1,     2,     4,     0,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,   281,   282,     0,     2,     3,     6,     1,     4,     0,
       0,     7,   286,    14,     9,     0,    10,    12,    15,     8,
      11,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    23,    21,    19,    22,    20,     0,    18,    13,    24,
     177,     0,     0,   178,   179,   180,     0,   181,   182,   190,
     183,   184,   185,   186,   187,   188,   189,     0,    25,    26,
      28,    29,    32,    30,    31,    35,     0,     0,    33,     0,
      50,     0,    51,    53,    55,    37,     0,    38,     0,    43,
      45,    47,     5,    27,   270,   125,   283,     0,   159,     0,
       0,   173,   166,   170,   172,   160,     0,     0,   161,   165,
     169,     0,     0,    58,    59,   162,   171,   129,     0,    34,
      49,    48,     0,     0,    36,    39,     0,     0,     0,     0,
     274,    61,    60,   112,   271,   278,     0,   174,   168,   167,
     164,   163,     0,    63,     0,    65,     0,     0,     0,    52,
      54,    40,    44,    46,     0,   276,   277,   275,     0,     0,
     196,   280,   279,   272,   126,   128,     0,     0,     0,     0,
      56,   134,   135,   130,   131,   133,   127,   147,   154,   148,
     268,   155,   156,   269,   145,   144,   146,   142,   140,   151,
     149,   150,     0,   152,    41,    42,   270,   270,     0,    89,
       0,   125,   283,   120,     0,     0,   196,   196,   113,   123,
     175,   162,   114,     0,     0,     0,   111,   197,   198,   270,
      64,    68,    67,    66,     0,     0,     0,     0,     0,   139,
     136,     0,   257,   255,   255,   255,    91,   256,    87,   255,
     255,    98,     0,   273,     0,   270,     0,   270,     0,   270,
       0,     0,   176,   270,     0,     0,     0,   228,   227,     0,
     226,   229,     0,     0,     0,   231,     0,   202,   205,     0,
     212,   213,   219,   218,   245,   246,   230,   233,   232,     0,
      62,   157,    57,   132,   143,   153,   141,   258,    96,     0,
      95,    97,    88,   255,    93,    94,     0,    86,    99,    90,
       0,   108,     0,    81,    84,    85,   270,   124,     0,     0,
      74,    75,    80,   255,   270,   284,     0,   284,   267,   259,
       0,   261,   266,   263,     0,    69,    71,    72,     0,     0,
       0,   222,     0,     0,     0,     0,     0,     0,   200,   193,
     194,   191,   192,     0,     0,     0,   195,     0,     0,     0,
       0,     0,   158,   137,   138,    92,     0,   121,     0,   115,
     270,    83,   270,   116,   270,    78,   255,   270,   285,   117,
     270,   260,     0,     0,   122,   270,   199,   206,   220,   223,
     224,   217,   215,   234,     0,   247,   211,   203,   207,   208,
     209,     0,   216,   214,     0,     0,   249,   201,   100,   109,
     110,   152,    82,    79,    76,    77,   112,   112,   262,     0,
       0,    70,     0,   225,   238,     0,   236,   196,     0,   210,
       0,   251,   253,   248,     0,     0,   118,   119,   265,   264,
     221,   235,     0,   240,   204,   252,     0,   250,   104,   105,
       0,     0,   102,   106,   237,   243,   244,   242,   239,   241,
     254,     0,   101,   103,   107
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     3,     4,     5,    10,    11,    15,    16,    27,    28,
      29,    57,    58,    59,   109,    60,    76,   185,    77,    78,
      79,    61,    71,    72,    62,   214,   102,    63,   132,   133,
     314,   315,   299,   300,   301,   292,   293,   121,   283,   188,
     189,   287,   288,   415,   431,   432,   302,   303,   149,   150,
     198,   103,   163,   164,   433,   224,   225,    64,   178,   216,
     179,   255,   272,   104,   105,   202,   106,   334,   335,   337,
     206,   207,   208,   256,   257,   258,   402,   323,   259,   260,
     261,   262,   405,   406,   438,   439,   263,   264,   265,   385,
     386,   411,   226,   227,   242,   310,   311,   266,   123,   124,
     125,   148,   153,   267,   107,   357,   268
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -267
static const short int yypact[] =
{
     203,  -267,  -267,    16,   203,  -267,   -54,  -267,  -267,    15,
      -2,  -267,  -267,  -267,  -267,    35,  -267,   -39,   199,  -267,
    -267,    79,    45,    24,    69,    47,   110,   221,   199,  -267,
      66,  -267,  -267,  -267,  -267,  -267,   215,  -267,  -267,   430,
    -267,   230,    43,  -267,  -267,  -267,   201,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,   209,   430,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,   239,   583,  -267,   149,
    -267,   173,  -267,   155,  -267,  -267,    51,  -267,   -19,  -267,
     157,  -267,  -267,  -267,   -12,   153,  -267,   183,  -267,   187,
     205,  -267,  -267,  -267,  -267,  -267,   219,   226,  -267,  -267,
    -267,   659,   311,  -267,  -267,  -267,  -267,   208,   313,  -267,
    -267,  -267,   262,   210,  -267,  -267,   203,   262,   232,   220,
      58,  -267,  -267,  -267,  -267,   114,   262,  -267,  -267,  -267,
    -267,  -267,   -24,  -267,   225,   231,   244,   307,   171,  -267,
    -267,   -54,  -267,  -267,   278,  -267,  -267,  -267,   354,   507,
     -36,  -267,  -267,  -267,  -267,  -267,   375,   659,   379,   262,
    -267,  -267,  -267,   272,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,   273,   279,  -267,  -267,    61,    53,    48,  -267,
     276,    57,   286,   356,   289,   327,    88,   122,  -267,  -267,
    -267,   291,  -267,   293,   294,   359,  -267,  -267,   295,   288,
    -267,  -267,  -267,  -267,   400,   326,   400,   379,   171,  -267,
    -267,   171,  -267,    10,    74,    10,  -267,  -267,   314,    74,
      10,   312,   278,  -267,   381,    13,   333,    25,   342,    25,
     343,    86,  -267,     8,   359,   318,   387,  -267,  -267,   -18,
    -267,  -267,   316,   203,   359,  -267,   309,   146,   320,   317,
     -18,  -267,  -267,  -267,   321,  -267,  -267,  -267,  -267,   359,
    -267,  -267,   418,  -267,   418,  -267,  -267,  -267,  -267,   346,
    -267,  -267,  -267,    10,  -267,  -267,   339,  -267,  -267,  -267,
     379,   315,    81,  -267,  -267,  -267,   288,  -267,   355,   322,
     323,  -267,  -267,    10,   288,   379,   324,   379,  -267,  -267,
      99,  -267,  -267,   325,   125,  -267,  -267,  -267,   319,   372,
     329,   328,   335,   192,   332,   340,   334,   338,  -267,  -267,
    -267,  -267,  -267,   344,   372,   372,  -267,   372,   359,   348,
     336,   341,  -267,  -267,  -267,  -267,   345,  -267,   290,  -267,
      13,  -267,   288,  -267,     1,  -267,    10,   288,  -267,  -267,
     288,  -267,    65,   290,  -267,     8,  -267,  -267,  -267,  -267,
     347,  -267,  -267,   295,    12,  -267,  -267,   349,  -267,  -267,
    -267,   350,  -267,  -267,    -4,   131,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,   353,
     357,  -267,   400,  -267,  -267,   151,  -267,   -36,   359,  -267,
     379,   337,  -267,  -267,   336,    22,  -267,  -267,  -267,  -267,
     418,  -267,    12,    71,   228,   337,   379,  -267,  -267,  -267,
      22,    38,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,    11,  -267,  -267,  -267
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -267,  -267,  -267,   429,  -267,   351,  -267,   438,  -267,  -267,
     431,  -267,  -267,   406,  -267,  -267,  -267,  -267,   393,  -267,
     358,  -267,  -267,   361,  -267,  -267,   403,  -267,  -267,   330,
    -267,   109,   238,  -267,   124,  -267,   130,  -267,  -267,  -267,
     253,  -267,  -267,  -267,    56,  -241,  -226,   -77,  -267,   -20,
    -267,  -108,  -267,   274,  -114,   303,   304,  -267,   -83,  -267,
    -266,   -53,  -215,    39,   352,  -267,    -7,  -267,  -267,  -267,
    -194,  -267,   170,  -183,    87,   -22,  -267,   236,  -267,  -260,
    -267,  -267,  -267,    75,  -267,  -267,  -267,  -267,  -267,  -267,
      85,    92,  -211,  -267,  -267,  -267,   141,  -127,   -71,  -267,
    -267,  -267,  -267,     4,  -267,   197,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -283
static const short int yytable[] =
{
      17,   274,   238,   240,     6,    12,    17,   122,     6,   294,
      12,   181,   278,   280,   281,   428,     7,    12,   284,   285,
     119,    12,    12,   165,    12,    13,   428,   161,   162,   429,
      67,   116,    65,    74,    12,   298,    18,    81,   161,   162,
     429,   199,   428,    66,    12,    13,    73,   221,   204,    67,
      80,    65,    12,     9,   161,   162,   429,     1,     2,   298,
      12,   318,    66,   372,    69,     1,     2,    81,   219,   220,
      21,   327,   345,   205,    12,   170,   219,   220,   173,   383,
      80,   145,   389,   222,   156,   180,   341,   321,   157,    30,
     435,   181,   355,   117,   181,    12,   170,   399,   221,   173,
     322,   165,   120,    74,    34,   135,    31,   291,    81,   223,
     228,   221,    32,   410,   312,   120,    73,   155,   404,   291,
     141,    80,   120,    14,   294,   430,   444,   120,   297,   183,
     154,   291,   270,   -73,   222,   276,   430,   146,   277,   120,
     134,   166,   182,    19,   436,   395,   442,   222,   437,   211,
     213,   147,   430,   203,    70,   381,   231,    33,   295,   151,
     232,   135,   114,   212,  -281,   180,   316,   120,   180,  -255,
     152,   308,   204,  -255,   126,   120,    38,   167,   168,   169,
      12,   170,   171,   172,   173,     1,     2,   420,   200,   349,
     443,   279,   308,   350,   309,   237,   134,   205,    35,   168,
     443,    12,   170,   171,   172,   173,   204,   361,   275,   183,
      12,   362,   183,   423,    22,     1,     2,     1,     2,   351,
     174,   390,   182,    23,    36,   182,   296,   356,   304,   239,
     304,   205,   313,   364,   317,   312,   400,   365,   175,   413,
      39,   247,    84,   414,    24,    68,    25,   329,   330,   331,
     332,    75,    82,    85,    86,    26,   371,   326,   333,   421,
     110,   176,   113,   422,   118,    87,    40,    88,   127,    89,
     126,    12,   128,   295,   130,   393,     1,     2,   177,    90,
     129,   347,   251,    91,   111,   112,   396,    92,   316,   397,
      93,    43,    44,    45,   186,   187,   358,   367,   358,    12,
     170,    94,    47,   173,     1,     2,    95,    48,    96,    49,
      97,   131,   378,   379,   136,   380,   138,    50,   140,    98,
      99,     1,     2,   161,   162,   137,    51,   144,    52,   329,
     330,   331,   332,    53,   100,    54,    55,    56,   158,   391,
     143,   296,   161,   162,   159,   304,   101,    85,    86,   324,
     325,   160,   182,   313,   391,   168,   317,    12,   170,   171,
     172,   173,   343,   344,   190,   407,   168,   182,    12,   170,
     171,   172,   173,     1,     2,   412,   416,   417,   209,   168,
     245,    12,   170,   171,   172,   173,     1,     2,    12,   215,
     217,   233,   218,  -282,   246,   234,   235,   247,   241,   236,
     243,   412,   120,   244,   269,   271,   282,   246,   247,   248,
     290,   286,   382,   407,   305,   307,   320,   440,   319,   328,
     336,   247,   248,   342,   249,   346,   338,   352,   340,   366,
     353,   348,   359,     8,   363,   354,   368,   249,   251,    12,
     370,   205,   375,   250,     1,     2,   369,   374,   376,   251,
     377,   387,   388,    20,   426,   384,   250,    40,   252,    37,
     409,   408,   251,   418,    83,   403,   253,   419,   254,   115,
     108,   252,    41,   139,   401,   142,    42,   306,   394,   253,
     392,   254,    43,    44,    45,   289,   441,   210,    46,   273,
     229,   230,   184,    47,   373,   424,   339,   434,    48,   427,
      49,   201,   425,   398,   360,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    52,
       0,   191,   192,     0,    53,     0,    54,    55,    56,   193,
       0,     0,     0,    87,    40,    88,     0,    89,   194,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,    91,     0,     0,     0,    92,     0,     0,    93,    43,
      44,    45,     0,     0,     0,     0,     0,   195,     0,    94,
      47,     0,     0,     0,    95,    48,    96,    49,    97,     0,
       0,     0,     0,     0,     0,    50,     0,    98,    99,   196,
     197,     0,     0,     0,    51,     0,    52,    85,    86,     0,
       0,    53,   100,    54,    55,    56,     0,     0,     0,    87,
      40,    88,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,     0,     0,    91,     0,     0,
       0,    92,     0,     0,    93,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,    94,    47,     0,     0,     0,
      95,    48,    96,    49,    97,     0,     0,     0,     0,     0,
       0,    50,     0,    98,    99,     0,     0,     0,     0,     0,
      51,     0,    52,     1,     2,     0,     0,    53,   100,    54,
      55,    56,     0,     0,     0,    87,    40,    88,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,    91,     0,     0,     0,    92,     0,     0,
      93,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,    94,    47,     0,     0,     0,    95,    48,    96,    49,
      97,     0,     0,     0,     0,     0,     0,    50,     0,    98,
      99,     0,     0,     0,     0,     0,    51,     0,    52,     0,
       0,     0,     0,    53,   100,    54,    55,    56
};

static const short int yycheck[] =
{
       9,   216,   196,   197,     0,     9,    15,    84,     4,   235,
       9,   138,   223,   224,   225,     4,     0,     9,   229,   230,
      32,     9,     9,   137,     9,    10,     4,    16,    17,    18,
      39,    50,    39,    42,     9,    34,    38,    46,    16,    17,
      18,   149,     4,    39,     9,    10,    42,    37,    84,    58,
      46,    58,     9,   107,    16,    17,    18,    14,    15,    34,
       9,   244,    58,   323,    21,    14,    15,    76,    15,    16,
     109,   254,   283,   109,     9,    10,    15,    16,    13,   339,
      76,    23,   348,    73,   108,   138,   269,   105,   112,    10,
      19,   218,   303,   112,   221,     9,    10,   363,    37,    13,
     118,   215,   114,   112,    57,   101,    61,   106,   117,   186,
     187,    37,    88,   117,   241,   114,   112,   126,   106,   106,
     116,   117,   114,   108,   350,   114,   115,   114,   236,   138,
     126,   106,   209,   108,    73,   218,   114,    79,   221,   114,
     101,   137,   138,   108,    73,   356,   108,    73,    77,   158,
     159,    93,   114,   149,   111,   338,   108,    88,   235,    45,
     112,   157,   111,   159,   107,   218,   243,   114,   221,   108,
      56,   106,    84,   112,   117,   114,   110,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,   402,   149,   108,
     431,   117,   106,   112,   108,   107,   157,   109,    88,     7,
     441,     9,    10,    11,    12,    13,    84,   108,   217,   218,
       9,   112,   221,   407,    15,    14,    15,    14,    15,   296,
      49,   348,   218,    24,     3,   221,   235,   304,   237,   107,
     239,   109,   241,   108,   243,   362,   363,   112,    67,   108,
      25,    49,     3,   112,    45,    15,    47,   101,   102,   103,
     104,    50,    43,    14,    15,    56,    64,   253,   112,   108,
     111,    90,   107,   112,   107,    26,    27,    28,    85,    30,
     117,     9,    85,   350,    55,   352,    14,    15,   107,    40,
      75,   290,    90,    44,   111,   112,   357,    48,   365,   360,
      51,    52,    53,    54,    16,    17,   305,   319,   307,     9,
      10,    62,    63,    13,    14,    15,    67,    68,    69,    70,
      71,    85,   334,   335,     3,   337,     3,    78,   108,    80,
      81,    14,    15,    16,    17,   117,    87,   107,    89,   101,
     102,   103,   104,    94,    95,    96,    97,    98,   113,   348,
     108,   350,    16,    17,   113,   354,   107,    14,    15,    33,
      34,   107,   348,   362,   363,     7,   365,     9,    10,    11,
      12,    13,    16,    17,    10,   374,     7,   363,     9,    10,
      11,    12,    13,    14,    15,   384,   396,   397,     3,     7,
      21,     9,    10,    11,    12,    13,    14,    15,     9,   117,
     117,   115,   113,   107,    35,    39,   107,    49,   107,    72,
     107,   410,   114,   109,   109,     5,    92,    35,    49,    50,
      29,    99,    64,   422,    72,    72,    29,   426,   100,   110,
     100,    49,    50,     5,    65,    86,   109,    72,   107,   110,
     108,   116,   108,     4,   109,   112,   107,    65,    90,     9,
     105,   109,   108,    84,    14,    15,   118,   107,   110,    90,
     106,   110,   107,    15,   117,   119,    84,    27,    99,    28,
     110,   112,    90,   110,    58,   118,   107,   110,   109,    76,
      67,    99,    42,   112,   365,   117,    46,   239,   354,   107,
     350,   109,    52,    53,    54,   232,   430,   157,    58,   215,
     187,   187,   141,    63,   324,   408,   260,   422,    68,   414,
      70,   149,   410,   362,   307,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      -1,    14,    15,    -1,    94,    -1,    96,    97,    98,    22,
      -1,    -1,    -1,    26,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    87,    -1,    89,    14,    15,    -1,
      -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    89,    14,    15,    -1,    -1,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      81,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    14,    15,   121,   122,   123,   223,     0,   123,   107,
     124,   125,     9,    10,   108,   126,   127,   226,    38,   108,
     127,   109,    15,    24,    45,    47,    56,   128,   129,   130,
      10,    61,    88,    88,    57,    88,     3,   130,   110,    25,
      27,    42,    46,    52,    53,    54,    58,    63,    68,    70,
      78,    87,    89,    94,    96,    97,    98,   131,   132,   133,
     135,   141,   144,   147,   177,   186,   223,   226,    15,    21,
     111,   142,   143,   223,   226,    50,   136,   138,   139,   140,
     223,   226,    43,   133,     3,    14,    15,    26,    28,    30,
      40,    44,    48,    51,    62,    67,    69,    71,    80,    81,
      95,   107,   146,   171,   183,   184,   186,   224,   146,   134,
     111,   111,   112,   107,   111,   138,    50,   112,   107,    32,
     114,   157,   167,   218,   219,   220,   117,    85,    85,    75,
      55,    85,   148,   149,   183,   223,     3,   117,     3,   143,
     108,   223,   140,   108,   107,    23,    79,    93,   221,   168,
     169,    45,    56,   222,   223,   226,   108,   112,   113,   113,
     107,    16,    17,   172,   173,   174,   223,     6,     7,     8,
      10,    11,    12,    13,    49,    67,    90,   107,   178,   180,
     181,   217,   223,   226,   125,   137,    16,    17,   159,   160,
      10,    14,    15,    22,    31,    60,    82,    83,   170,   171,
     183,   184,   185,   223,    84,   109,   190,   191,   192,     3,
     149,   226,   223,   226,   145,   117,   179,   117,   113,    15,
      16,    37,    73,   167,   175,   176,   212,   213,   167,   175,
     176,   108,   112,   115,    39,   107,    72,   107,   190,   107,
     190,   107,   214,   107,   109,    21,    35,    49,    50,    65,
      84,    90,    99,   107,   109,   181,   193,   194,   195,   198,
     199,   200,   201,   206,   207,   208,   217,   223,   226,   109,
     167,     5,   182,   173,   182,   226,   178,   178,   212,   117,
     212,   212,    92,   158,   212,   212,    99,   161,   162,   160,
      29,   106,   155,   156,   166,   167,   226,   171,    34,   152,
     153,   154,   166,   167,   226,    72,   152,    72,   106,   108,
     215,   216,   217,   226,   150,   151,   167,   226,   193,   100,
      29,   105,   118,   197,    33,    34,   223,   193,   110,   101,
     102,   103,   104,   112,   187,   188,   100,   189,   109,   197,
     107,   193,     5,    16,    17,   212,    86,   226,   116,   108,
     112,   167,    72,   108,   112,   212,   167,   225,   226,   108,
     225,   108,   112,   109,   108,   112,   110,   195,   107,   118,
     105,    64,   199,   192,   107,   108,   110,   106,   195,   195,
     195,   193,    64,   199,   119,   209,   210,   110,   107,   180,
     217,   226,   156,   167,   154,   212,   218,   218,   216,   180,
     217,   151,   196,   118,   106,   202,   203,   226,   112,   110,
     117,   211,   226,   108,   112,   163,   169,   169,   110,   110,
     182,   108,   112,   190,   194,   211,   117,   210,     4,    18,
     114,   164,   165,   174,   203,    19,    73,    77,   204,   205,
     226,   164,   108,   165,   115
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


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
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

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

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

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
  const char *yys = yystr;

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
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



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

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
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

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 322 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[0].a_grammar);
	}
    break;

  case 3:
#line 328 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
    break;

  case 4:
#line 333 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[-1].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
    break;

  case 5:
#line 354 "asn1p_y.y"
    {

		if((yyvsp[-1].a_module)) {
			(yyval.a_module) = (yyvsp[-1].a_module);
		} else {
			/* There's a chance that a module is just plain empty */
			(yyval.a_module) = asn1p_module_new();
		}
		checkmem((yyval.a_module));

		(yyval.a_module)->ModuleName = (yyvsp[-7].tv_str);
		(yyval.a_module)->module_oid = (yyvsp[-6].a_oid);
		(yyval.a_module)->module_flags = (yyvsp[-4].a_module_flags);
	}
    break;

  case 6:
#line 375 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 7:
#line 376 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[0].a_oid); }
    break;

  case 8:
#line 380 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
	}
    break;

  case 9:
#line 383 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 10:
#line 389 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
    break;

  case 11:
#line 395 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
    break;

  case 12:
#line 404 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[0].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
    break;

  case 13:
#line 408 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[-3].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[-1].a_int);
	}
    break;

  case 14:
#line 412 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[0].a_int);
	}
    break;

  case 15:
#line 422 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 16:
#line 423 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
    break;

  case 17:
#line 432 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
    break;

  case 18:
#line 435 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[-1].a_module_flags) | (yyvsp[0].a_module_flags);
	}
    break;

  case 19:
#line 444 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 20:
#line 447 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 21:
#line 450 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 22:
#line 453 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 23:
#line 457 "asn1p_y.y"
    {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp((yyvsp[-1].tv_str), "TAG") == 0) {
		 	(yyval.a_module_flags) = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp((yyvsp[-1].tv_str), "XER") == 0) {
		 	(yyval.a_module_flags) = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at line %d: "
				"Unrecognized encoding reference\n",
				(yyvsp[-1].tv_str), yylineno);
		 	(yyval.a_module_flags) = MSF_unk_INSTRUCTIONS;
		}
		free((yyvsp[-1].tv_str));
	}
    break;

  case 24:
#line 478 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 25:
#line 479 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
    break;

  case 26:
#line 488 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
    break;

  case 27:
#line 491 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[-1].a_module);

		/* Behave well when one of them is skipped. */
		if(!((yyvsp[-1].a_module))) {
			if((yyvsp[0].a_module)) (yyval.a_module) = (yyvsp[0].a_module);
			break;
		}

#ifdef	MY_IMPORT
#error	MY_IMPORT DEFINED ELSEWHERE!
#endif
#define	MY_IMPORT(foo,field)	do {				\
		while(TQ_FIRST(&((yyvsp[0].a_module)->foo))) {			\
			TQ_ADD(&((yyval.a_module)->foo),			\
				TQ_REMOVE(&((yyvsp[0].a_module)->foo), field),	\
				field);				\
		}						\
		assert(TQ_FIRST(&((yyvsp[0].a_module)->foo)) == 0);		\
	} while(0)

		MY_IMPORT(imports, xp_next);
		MY_IMPORT(exports, xp_next);
		MY_IMPORT(members, next);
#undef	MY_IMPORT

	}
    break;

  case 28:
#line 524 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
    break;

  case 29:
#line 527 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		if((yyvsp[0].a_xports)) {
			TQ_ADD(&((yyval.a_module)->exports), (yyvsp[0].a_xports), xp_next);
		} else {
			/* "EXPORTS ALL;" ? */
		}
	}
    break;

  case 30:
#line 536 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 31:
#line 543 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 32:
#line 556 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 33:
#line 564 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 565 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at line %d ignored\n",
			(yyvsp[-1].tv_str), yylineno);
		free((yyvsp[-1].tv_str));
		(yyval.a_module) = 0;
	}
    break;

  case 35:
#line 577 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 590 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[-1].a_module);
	}
    break;

  case 37:
#line 600 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 38:
#line 606 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
    break;

  case 39:
#line 611 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[-1].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
    break;

  case 40:
#line 618 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 41:
#line 619 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[0].a_oid); }
    break;

  case 42:
#line 623 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[-3].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[-1].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[0].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
    break;

  case 43:
#line 634 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 44:
#line 639 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 45:
#line 646 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 46:
#line 652 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 47:
#line 658 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 48:
#line 667 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[-1].a_xports);
	}
    break;

  case 49:
#line 670 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 50:
#line 673 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 51:
#line 681 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 52:
#line 686 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[0].a_expr), next);
	}
    break;

  case 53:
#line 693 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 54:
#line 699 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 55:
#line 705 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 56:
#line 716 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 57:
#line 716 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		/* take care of ValueSet body */
	}
    break;

  case 58:
#line 726 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 59:
#line 733 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[0].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 60:
#line 751 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 61:
#line 757 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 62:
#line 773 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->params = (yyvsp[-3].a_plist);
		(yyval.a_expr)->meta_type = AMT_PARAMTYPE;
	}
    break;

  case 63:
#line 783 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		if((yyvsp[0].a_parg).governor) asn1p_ref_free((yyvsp[0].a_parg).governor);
		if((yyvsp[0].a_parg).argument) free((yyvsp[0].a_parg).argument);
	}
    break;

  case 64:
#line 792 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = (yyvsp[-2].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		if((yyvsp[0].a_parg).governor) asn1p_ref_free((yyvsp[0].a_parg).governor);
		if((yyvsp[0].a_parg).argument) free((yyvsp[0].a_parg).argument);
	}
    break;

  case 65:
#line 803 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
    break;

  case 66:
#line 807 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
    break;

  case 67:
#line 814 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
    break;

  case 68:
#line 821 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
    break;

  case 69:
#line 832 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 70:
#line 837 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 71:
#line 844 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
    break;

  case 72:
#line 847 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 73:
#line 871 "asn1p_y.y"
    { (yyval.a_expr) = asn1p_expr_new(yylineno); }
    break;

  case 74:
#line 872 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[0].a_expr); }
    break;

  case 75:
#line 875 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 76:
#line 880 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 77:
#line 887 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 78:
#line 894 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 79:
#line 900 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[0].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 80:
#line 907 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
    break;

  case 81:
#line 913 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 82:
#line 918 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 83:
#line 925 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
	}
    break;

  case 84:
#line 930 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
    break;

  case 85:
#line 933 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 86:
#line 940 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[0].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 87:
#line 950 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 88:
#line 951 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 89:
#line 955 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 90:
#line 962 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 91:
#line 972 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 92:
#line 982 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		(yyval.a_expr)->unique = (yyvsp[-1].a_int);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		asn1p_expr_add((yyval.a_expr), (yyvsp[-2].a_expr));
	}
    break;

  case 93:
#line 993 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 94:
#line 1003 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 95:
#line 1014 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 96:
#line 1024 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[-1].a_expr));
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 97:
#line 1035 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OSFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
    break;

  case 98:
#line 1047 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 99:
#line 1048 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[0].a_wsynt);
	}
    break;

  case 100:
#line 1055 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 101:
#line 1057 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
	}
    break;

  case 102:
#line 1063 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
    break;

  case 103:
#line 1067 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
    break;

  case 104:
#line 1074 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 105:
#line 1078 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_frombuf((yyvsp[0].tv_str), strlen((yyvsp[0].tv_str)), 0);
	}
    break;

  case 106:
#line 1081 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_frombuf((yyvsp[0].a_refcomp).name, strlen((yyvsp[0].a_refcomp).name), 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 107:
#line 1085 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[-1].a_wsynt));
	}
    break;

  case 108:
#line 1091 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 109:
#line 1099 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 110:
#line 1108 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 111:
#line 1120 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyval.a_expr)->tag = (yyvsp[-2].a_tag);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[0].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[-1].a_expr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
    break;

  case 112:
#line 1142 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 113:
#line 1149 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->marker.flags |= (yyvsp[-1].a_int);

		if(((yyval.a_expr)->marker.flags & EM_INDIRECT)
		&& ((yyval.a_expr)->marker.flags & EM_OPTIONAL) != EM_OPTIONAL) {
			fprintf(stderr,
				"INFO: Directive <ASN1C:RepresentAsPointer> "
				"applied to %s at line %d\n",
				ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					?  ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					: "member",
				(yyval.a_expr)->_lineno
			);
		}
	}
    break;

  case 114:
#line 1168 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
    break;

  case 115:
#line 1171 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 116:
#line 1177 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 117:
#line 1183 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 118:
#line 1189 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 119:
#line 1199 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 120:
#line 1209 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 121:
#line 1215 "asn1p_y.y"
    {
		int ret;
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference,
			(yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 122:
#line 1229 "asn1p_y.y"
    {
		int ret;
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == 0);
		assert((yyval.a_expr)->meta_type == 0);
		assert((yyval.a_expr)->reference == 0);
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno);
		checkmem((yyval.a_expr)->reference);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference, (yyvsp[-3].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-3].tv_str));
		(yyval.a_expr)->expr_type = A1TC_PARAMETRIZED;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 123:
#line 1253 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 124:
#line 1260 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 125:
#line 1275 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[0].tv_str));
	}
    break;

  case 126:
#line 1283 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
	}
    break;

  case 127:
#line 1293 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
	}
    break;

  case 128:
#line 1303 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
	}
    break;

  case 129:
#line 1313 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
		checkmem(ret == 0);
	}
    break;

  case 130:
#line 1321 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[0].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_CAPITALS);
		free((yyvsp[-2].tv_str));
		checkmem(ret == 0);
		/*
		 * Move the last element infront.
		 */
		{
			struct asn1p_ref_component_s tmp_comp;
			tmp_comp = (yyval.a_ref)->components[(yyval.a_ref)->comp_count-1];
			memmove(&(yyval.a_ref)->components[1],
				&(yyval.a_ref)->components[0],
				sizeof((yyval.a_ref)->components[0])
				* ((yyval.a_ref)->comp_count - 1));
			(yyval.a_ref)->components[0] = tmp_comp;
		}
	}
    break;

  case 131:
#line 1343 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 132:
#line 1351 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[-2].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 134:
#line 1364 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
    break;

  case 135:
#line 1369 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
    break;

  case 136:
#line 1378 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
	}
    break;

  case 137:
#line 1382 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
	}
    break;

  case 138:
#line 1386 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_Amplowercase);
	}
    break;

  case 139:
#line 1393 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
	}
    break;

  case 140:
#line 1413 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
    break;

  case 141:
#line 1423 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[-2].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[0].a_value);
	}
    break;

  case 142:
#line 1430 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 143:
#line 1430 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 144:
#line 1435 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 145:
#line 1440 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 146:
#line 1445 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 147:
#line 1450 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'B');
		checkmem((yyval.a_value));
	}
    break;

  case 148:
#line 1454 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'H');
		checkmem((yyval.a_value));
	}
    break;

  case 149:
#line 1458 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 150:
#line 1461 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[0].a_value);
	}
    break;

  case 151:
#line 1464 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[0].a_value);
	}
    break;

  case 152:
#line 1470 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
    break;

  case 153:
#line 1481 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
    break;

  case 154:
#line 1499 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 155:
#line 1503 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 156:
#line 1508 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 157:
#line 1542 "asn1p_y.y"
    {
		(yyval.tv_opaque).len = (yyvsp[0].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc((yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[0].tv_opaque).buf);
	}
    break;

  case 158:
#line 1551 "asn1p_y.y"
    {
		int newsize = (yyvsp[-1].tv_opaque).len + (yyvsp[0].tv_opaque).len;
		char *p = malloc(newsize + 1);
		checkmem(p);
		memcpy(p         , (yyvsp[-1].tv_opaque).buf, (yyvsp[-1].tv_opaque).len);
		memcpy(p + (yyvsp[-1].tv_opaque).len, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		p[newsize] = '\0';
		free((yyvsp[-1].tv_opaque).buf);
		free((yyvsp[0].tv_opaque).buf);
		(yyval.tv_opaque).buf = p;
		(yyval.tv_opaque).len = newsize;
	}
    break;

  case 159:
#line 1566 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 160:
#line 1567 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 161:
#line 1568 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 162:
#line 1569 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[0].a_type); }
    break;

  case 163:
#line 1570 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 164:
#line 1571 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 165:
#line 1572 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 166:
#line 1573 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 167:
#line 1574 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 168:
#line 1575 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 169:
#line 1576 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 170:
#line 1577 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 171:
#line 1578 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[0].a_type); }
    break;

  case 172:
#line 1585 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 173:
#line 1586 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 174:
#line 1587 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 175:
#line 1591 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[0].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 176:
#line 1597 "asn1p_y.y"
    {
		if((yyvsp[0].a_expr)) {
			(yyval.a_expr) = (yyvsp[0].a_expr);
		} else {
			(yyval.a_expr) = asn1p_expr_new(yylineno);
			checkmem((yyval.a_expr));
		}
		(yyval.a_expr)->expr_type = (yyvsp[-1].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 177:
#line 1610 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 178:
#line 1611 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 179:
#line 1615 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 180:
#line 1619 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 181:
#line 1620 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 182:
#line 1621 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 183:
#line 1622 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 184:
#line 1623 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 185:
#line 1627 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 186:
#line 1628 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 187:
#line 1629 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 188:
#line 1630 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 189:
#line 1634 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 190:
#line 1635 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 196:
#line 1647 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 197:
#line 1648 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 198:
#line 1654 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[0].a_constr), 0);
	}
    break;

  case 199:
#line 1657 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[-1].a_constr), 0);
	}
    break;

  case 200:
#line 1667 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[-1].a_constr);
	}
    break;

  case 201:
#line 1670 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-3].a_constr), (yyvsp[-1].a_constr));
	}
    break;

  case 202:
#line 1676 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 203:
#line 1679 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
	}
    break;

  case 204:
#line 1685 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-4].a_constr), ct);
		ct = (yyval.a_constr);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[0].a_constr));
	}
    break;

  case 205:
#line 1696 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 206:
#line 1699 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[0].a_constr), 0);
	}
    break;

  case 207:
#line 1702 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
    break;

  case 208:
#line 1705 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
    break;

  case 209:
#line 1708 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
    break;

  case 210:
#line 1714 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-3].a_ctype);
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 211:
#line 1722 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CA_SET;
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 212:
#line 1730 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[0].a_value);
	}
    break;

  case 213:
#line 1736 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[0].a_value);
	}
    break;

  case 214:
#line 1742 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[-2].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[0].a_value);
	}
    break;

  case 215:
#line 1749 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = (yyvsp[0].a_value);
		(yyval.a_constr)->range_start->type = ATV_MIN;
	}
    break;

  case 216:
#line 1757 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[-2].a_value);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 217:
#line 1765 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_start->type = ATV_MIN;
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 218:
#line 1774 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 219:
#line 1777 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 220:
#line 1781 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 221:
#line 1781 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 222:
#line 1792 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 223:
#line 1793 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 224:
#line 1794 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 225:
#line 1795 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 226:
#line 1799 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_SIZE;
	}
    break;

  case 227:
#line 1802 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_FROM;
	}
    break;

  case 228:
#line 1808 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 229:
#line 1813 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 230:
#line 1818 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[0].a_value);
	}
    break;

  case 231:
#line 1821 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[0].a_value);
	}
    break;

  case 232:
#line 1824 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
    break;

  case 233:
#line 1838 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
    break;

  case 234:
#line 1852 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[0].a_constr), 0);
	}
    break;

  case 235:
#line 1855 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[-1].a_constr), 0);
	}
    break;

  case 236:
#line 1861 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 237:
#line 1864 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
    break;

  case 238:
#line 1870 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_EXT;
		(yyval.a_constr)->value = asn1p_value_frombuf("...", 3, 0);
	}
    break;

  case 239:
#line 1876 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[-2].tv_str), strlen((yyvsp[-2].tv_str)), 0);
		(yyval.a_constr)->presence = (yyvsp[0].a_pres);
		if((yyvsp[-1].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
	}
    break;

  case 240:
#line 1890 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 241:
#line 1891 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[0].a_pres); }
    break;

  case 242:
#line 1895 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 243:
#line 1898 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 244:
#line 1901 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 245:
#line 1907 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 246:
#line 1910 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
    break;

  case 247:
#line 1919 "asn1p_y.y"
    {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, (yyvsp[-1].tv_str), 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, ct, 0);
	}
    break;

  case 248:
#line 1934 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[-3].a_constr), (yyvsp[-1].a_constr));
	}
    break;

  case 249:
#line 1940 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
	}
    break;

  case 250:
#line 1946 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
	}
    break;

  case 251:
#line 1960 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
    break;

  case 252:
#line 1971 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
    break;

  case 253:
#line 1987 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;

  case 254:
#line 1990 "asn1p_y.y"
    {
		int l1 = strlen((yyvsp[-2].tv_str));
		int l3 = strlen((yyvsp[0].tv_str));
		(yyval.tv_str) = malloc(l1 + 1 + l3 + 1);
		memcpy((yyval.tv_str), (yyvsp[-2].tv_str), l1);
		(yyval.tv_str)[l1] = '.';
		memcpy((yyval.tv_str) + l1 + 1, (yyvsp[0].tv_str), l3);
		(yyval.tv_str)[l1 + 1 + l3] = '\0';
	}
    break;

  case 255:
#line 2008 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 256:
#line 2012 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[0].a_marker); }
    break;

  case 257:
#line 2016 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 258:
#line 2020 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[0].a_value);
	}
    break;

  case 259:
#line 2043 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
	}
    break;

  case 260:
#line 2047 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
	}
    break;

  case 261:
#line 2053 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 262:
#line 2058 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
    break;

  case 263:
#line 2065 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
	}
    break;

  case 264:
#line 2072 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
    break;

  case 265:
#line 2080 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
    break;

  case 266:
#line 2088 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
    break;

  case 267:
#line 2095 "asn1p_y.y"
    {
		(yyval.a_expr) = asn1p_expr_new(yylineno);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 268:
#line 2106 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 269:
#line 2110 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 270:
#line 2141 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 271:
#line 2142 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[0].a_tag); }
    break;

  case 272:
#line 2146 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[-1].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[0].a_tag).tag_mode;
	}
    break;

  case 273:
#line 2153 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[-2].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[-1].a_int);
	}
    break;

  case 274:
#line 2159 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 275:
#line 2160 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 276:
#line 2161 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 277:
#line 2162 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 278:
#line 2166 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 279:
#line 2167 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 280:
#line 2168 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 281:
#line 2172 "asn1p_y.y"
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;

  case 282:
#line 2176 "asn1p_y.y"
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;

  case 283:
#line 2184 "asn1p_y.y"
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;

  case 284:
#line 2191 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 285:
#line 2192 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;

  case 286:
#line 2198 "asn1p_y.y"
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 4429 "asn1p_y.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

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
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 2204 "asn1p_y.y"



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


