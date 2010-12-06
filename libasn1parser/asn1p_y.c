/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 432 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 445 "asn1p_y.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
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
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  122
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  122
/* YYNRULES -- Number of rules.  */
#define YYNRULES  312
/* YYNRULES -- Number of states.  */
#define YYNSTATES  470

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   118,     2,     2,     2,     2,     2,     2,
     111,   112,     2,     2,   114,     2,   119,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   115,   113,
     120,     2,     2,     2,   121,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   116,     2,   117,   103,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   109,   105,   110,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   104,   106,
     107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
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
     564,   566,   568,   570,   572,   574,   575,   577,   579,   581,
     586,   590,   595,   597,   599,   603,   609,   611,   613,   617,
     619,   623,   625,   629,   631,   635,   640,   644,   646,   648,
     652,   656,   660,   664,   666,   668,   671,   674,   676,   678,
     680,   682,   684,   686,   688,   690,   692,   694,   696,   700,
     706,   708,   712,   714,   718,   719,   721,   723,   725,   727,
     729,   731,   733,   734,   740,   743,   745,   748,   751,   755,
     757,   759,   763,   768,   770,   774,   777,   781,   783,   787,
     788,   790,   792,   795,   798,   802,   804,   808,   810,   815,
     820,   822,   824,   826,   828,   830,   832,   833,   835,   838,
     843,   844,   846,   848,   850,   851,   853,   855,   857,   859,
     861,   862,   864
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     123,     0,    -1,   124,    -1,   125,    -1,   124,   125,    -1,
      -1,   240,   126,   127,    40,   131,     3,    27,   134,    45,
      -1,    -1,   128,    -1,   109,   129,   110,    -1,   109,   110,
      -1,   130,    -1,   129,   130,    -1,   243,    -1,   243,   111,
      20,   112,    -1,    20,    -1,    -1,   132,    -1,   133,    -1,
     132,   133,    -1,    47,    90,    -1,    58,    90,    -1,    26,
      90,    -1,    49,    59,    -1,    16,    63,    -1,    -1,   135,
      -1,   147,   139,   136,    -1,   137,    -1,   136,   137,    -1,
     154,    -1,   184,    -1,   152,    -1,    -1,    44,    16,   138,
      -1,   194,    -1,    -1,   140,    -1,    60,   141,   113,    -1,
      60,    52,    -1,    -1,   142,    -1,   144,    -1,   142,   144,
      -1,    -1,   128,    -1,   145,    52,   240,   143,    -1,   146,
      -1,   145,   114,   146,    -1,   240,    -1,   240,   109,   110,
      -1,   243,    -1,    -1,   148,    -1,    48,   149,   113,    -1,
      48,    23,   113,    -1,    48,   113,    -1,   150,    -1,   149,
     114,   150,    -1,   240,    -1,   240,   109,   110,    -1,   243,
      -1,   109,   201,   110,    -1,   240,   153,     3,   151,    -1,
     193,    -1,   178,    -1,   178,   109,   157,   110,    -1,   240,
       3,   174,    -1,   240,     3,   164,    -1,   240,   109,   155,
     110,     3,   174,    -1,   240,   109,   155,   110,     3,   164,
      -1,   156,    -1,   155,   114,   156,    -1,   240,    -1,   240,
     115,   243,    -1,   240,   115,   240,    -1,   191,   115,   243,
      -1,   191,   115,   240,    -1,   158,    -1,   157,   114,   158,
      -1,   174,    -1,   187,    -1,   243,    -1,   151,    -1,    -1,
     160,    -1,   161,    -1,   160,   114,   161,    -1,   243,   174,
     228,    -1,   174,   228,    -1,    36,    74,   174,    -1,   173,
      -1,   163,    -1,   162,   114,   163,    -1,   243,   174,    -1,
     173,    -1,   174,    -1,    34,   109,   166,   110,   168,    -1,
      -1,    94,    -1,   167,    -1,   166,   114,   167,    -1,    17,
     228,    -1,    18,   174,   165,   228,    -1,    18,   182,   228,
      -1,    18,   183,   228,    -1,    17,   182,   228,    -1,    17,
     174,   228,    -1,    17,   183,   228,    -1,    -1,   169,    -1,
      -1,   101,    88,   109,   170,   171,   110,    -1,   172,    -1,
     171,   172,    -1,     4,    -1,    19,    -1,   181,    -1,   116,
     171,   117,    -1,   108,    -1,   108,   118,   188,    -1,   108,
     118,   233,    -1,   235,   176,   197,    -1,    -1,   175,   177,
      -1,   153,    -1,    33,   109,   162,   110,    -1,    84,   109,
     159,   110,    -1,    85,   109,   159,   110,    -1,    84,   197,
      74,   242,   235,   176,    -1,    85,   197,    74,   242,   235,
     176,    -1,    24,    -1,    24,    41,    31,   243,    -1,    62,
      74,   178,    -1,    15,    -1,    15,   119,   240,    -1,   241,
     119,   240,    -1,    15,   119,   243,    -1,   241,    -1,   241,
     119,   179,    -1,   180,    -1,   179,   119,   180,    -1,   181,
      -1,    17,    -1,    18,    -1,    17,    -1,   182,   119,    17,
      -1,   182,   119,    18,    -1,    16,    -1,   243,   174,     3,
     185,    -1,   187,    -1,   188,    -1,   243,   115,   185,    -1,
      -1,   109,   186,   190,    -1,    69,    -1,    51,    -1,    92,
      -1,     6,    -1,     8,    -1,   189,    -1,   233,    -1,   243,
      -1,   240,   119,   243,    -1,     7,    -1,    13,    -1,    14,
      -1,     5,    -1,   190,     5,    -1,    30,    -1,    69,    -1,
      82,    -1,   192,    -1,    73,    87,    -1,    71,    57,    -1,
      83,    -1,    50,    -1,    42,    77,    -1,    32,    87,    -1,
      97,    -1,    53,    -1,   194,    -1,    64,    -1,    46,    -1,
      28,    87,    -1,   191,    -1,   192,   230,    -1,    29,    -1,
      54,    -1,    55,    -1,    56,    -1,    65,    -1,    70,    -1,
      80,    -1,    89,    -1,    91,    -1,    96,    -1,    98,    -1,
      99,    -1,   100,    -1,    72,    -1,   105,    -1,   106,    -1,
     103,    -1,   104,    -1,    -1,   198,    -1,   199,    -1,   200,
      -1,    86,   111,   201,   112,    -1,   111,   201,   112,    -1,
     200,   111,   201,   112,    -1,   108,    -1,   202,    -1,   202,
     114,   108,    -1,   202,   114,   108,   114,   202,    -1,   217,
      -1,   203,    -1,    23,   102,   206,    -1,   204,    -1,   203,
     195,   204,    -1,   205,    -1,   204,   196,   205,    -1,   206,
      -1,   206,   102,   206,    -1,   208,   111,   201,   112,    -1,
     111,   201,   112,    -1,   209,    -1,   211,    -1,   209,   221,
     209,    -1,    67,   221,   209,    -1,   209,   221,    66,    -1,
      67,   221,    66,    -1,   212,    -1,   207,    -1,    76,     7,
      -1,    76,   243,    -1,    86,    -1,    52,    -1,    51,    -1,
      92,    -1,   234,    -1,   189,    -1,   210,    -1,   243,    -1,
       6,    -1,     8,    -1,   240,    -1,   101,    35,   200,    -1,
     101,    36,   109,   213,   110,    -1,   214,    -1,   213,   114,
     214,    -1,   108,    -1,   243,   197,   215,    -1,    -1,   216,
      -1,    79,    -1,    21,    -1,    75,    -1,   218,    -1,   222,
      -1,   220,    -1,    -1,    37,    31,   109,   219,   190,    -1,
      38,   174,    -1,   107,    -1,   107,   120,    -1,   120,   107,
      -1,   120,   107,   120,    -1,   223,    -1,   224,    -1,   109,
     240,   110,    -1,   223,   109,   225,   110,    -1,   226,    -1,
     225,   114,   226,    -1,   121,   227,    -1,   121,   119,   227,
      -1,   243,    -1,   227,   119,   243,    -1,    -1,   229,    -1,
      75,    -1,    39,   185,    -1,   109,   110,    -1,   109,   231,
     110,    -1,   232,    -1,   231,   114,   232,    -1,   243,    -1,
     243,   111,   233,   112,    -1,   243,   111,   188,   112,    -1,
     233,    -1,   108,    -1,    10,    -1,    11,    -1,   233,    -1,
      12,    -1,    -1,   236,    -1,   237,   239,    -1,   116,   238,
      10,   117,    -1,    -1,    95,    -1,    25,    -1,    81,    -1,
      -1,    58,    -1,    47,    -1,    15,    -1,    16,    -1,    16,
      -1,    -1,   243,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   357,   357,   363,   368,   385,   385,   414,   415,   419,
     422,   428,   436,   447,   451,   455,   465,   466,   475,   478,
     487,   490,   493,   496,   500,   521,   522,   531,   540,   543,
     559,   566,   579,   587,   586,   600,   613,   614,   617,   627,
     633,   634,   637,   642,   649,   650,   654,   665,   670,   677,
     683,   689,   699,   700,   712,   715,   718,   726,   731,   738,
     744,   750,   759,   762,   772,   785,   795,   815,   821,   837,
     843,   851,   860,   871,   875,   882,   889,   897,   908,   913,
     920,   923,   931,   942,   965,   966,   969,   974,   981,   988,
     994,  1001,  1007,  1012,  1019,  1024,  1027,  1034,  1044,  1045,
    1049,  1056,  1066,  1076,  1087,  1097,  1108,  1118,  1129,  1141,
    1142,  1149,  1148,  1157,  1161,  1168,  1172,  1175,  1179,  1185,
    1193,  1202,  1214,  1236,  1243,  1262,  1265,  1271,  1277,  1283,
    1293,  1303,  1309,  1320,  1335,  1343,  1353,  1363,  1373,  1381,
    1403,  1411,  1420,  1424,  1429,  1438,  1442,  1446,  1453,  1473,
    1483,  1484,  1485,  1492,  1492,  1497,  1505,  1510,  1515,  1519,
    1523,  1526,  1532,  1543,  1561,  1565,  1570,  1578,  1587,  1602,
    1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,
    1613,  1614,  1621,  1622,  1623,  1627,  1633,  1646,  1647,  1651,
    1655,  1656,  1657,  1658,  1659,  1663,  1664,  1665,  1666,  1670,
    1671,  1678,  1678,  1679,  1679,  1682,  1683,  1689,  1693,  1696,
    1706,  1709,  1715,  1719,  1722,  1728,  1736,  1742,  1743,  1749,
    1750,  1756,  1757,  1764,  1765,  1771,  1779,  1787,  1793,  1799,
    1806,  1814,  1822,  1831,  1834,  1840,  1845,  1856,  1859,  1865,
    1870,  1875,  1876,  1877,  1878,  1892,  1896,  1903,  1917,  1920,
    1926,  1929,  1935,  1941,  1955,  1956,  1960,  1963,  1966,  1974,
    1975,  1976,  1981,  1980,  1992,  2000,  2001,  2002,  2003,  2006,
    2009,  2018,  2033,  2039,  2045,  2059,  2070,  2086,  2089,  2107,
    2111,  2115,  2119,  2142,  2146,  2152,  2157,  2164,  2171,  2179,
    2187,  2194,  2205,  2209,  2216,  2217,  2248,  2249,  2253,  2260,
    2266,  2267,  2268,  2269,  2273,  2274,  2275,  2279,  2283,  2291,
    2298,  2299,  2305
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_whitespace",
  "TOK_opaque", "TOK_bstring", "TOK_cstring", "TOK_hstring",
  "TOK_identifier", "TOK_number", "TOK_number_negative", "TOK_realnumber",
  "TOK_tuple", "TOK_quadruple", "TOK_typereference",
  "TOK_capitalreference", "TOK_typefieldreference",
  "TOK_valuefieldreference", "TOK_Literal", "TOK_arcnumber", "TOK_ABSENT",
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
  "ModuleList", "ModuleDefinition", "@1", "optObjectIdentifier",
  "ObjectIdentifier", "ObjectIdentifierBody", "ObjectIdentifierElement",
  "optModuleDefinitionFlags", "ModuleDefinitionFlags",
  "ModuleDefinitionFlag", "optModuleBody", "ModuleBody", "AssignmentList",
  "Assignment", "@2", "optImports", "ImportsDefinition",
  "optImportsBundleSet", "ImportsBundleSet", "AssignedIdentifier",
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
  "ValueAssignment", "Value", "@4", "SimpleValue", "DefinedValue",
  "RestrictedCharacterStringValue", "Opaque", "BasicTypeId",
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString",
  "UnionMark", "IntersectionMark", "optConstraints", "Constraint",
  "SubtypeConstraint", "SetOfConstraints", "ElementSetSpecs",
  "ElementSetSpec", "Unions", "Intersections", "IntersectionElements",
  "ConstraintSubtypeElement", "PatternConstraint", "ConstraintSpec",
  "SingleValue", "BitStringValue", "ContainedSubtype",
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
static const yytype_uint16 yytoknum[] =
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
     355,   356,   357,    94,   358,   124,   359,   360,   361,   123,
     125,    40,    41,    59,    44,    58,    91,    93,    33,    46,
      60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   122,   123,   124,   124,   126,   125,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   133,   133,   134,   134,   135,   136,   136,
     137,   137,   137,   138,   137,   137,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   148,   149,   149,   150,
     150,   150,   151,   152,   153,   153,   153,   154,   154,   154,
     154,   155,   155,   156,   156,   156,   156,   156,   157,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   161,   161,
     161,   161,   162,   162,   163,   163,   163,   164,   165,   165,
     166,   166,   167,   167,   167,   167,   167,   167,   167,   168,
     168,   170,   169,   171,   171,   172,   172,   172,   172,   173,
     173,   173,   174,   175,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   178,   178,   178,   178,
     179,   179,   180,   181,   181,   182,   182,   182,   183,   184,
     185,   185,   185,   186,   185,   185,   187,   187,   187,   187,
     187,   187,   188,   188,   189,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   192,   192,   192,   193,   193,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   207,   207,   208,   208,   209,
     209,   209,   209,   209,   209,   210,   210,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   216,   216,   217,
     217,   217,   219,   218,   220,   221,   221,   221,   221,   222,
     222,   223,   224,   225,   225,   226,   226,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   232,
     232,   232,   233,   233,   234,   234,   235,   235,   236,   237,
     238,   238,   238,   238,   239,   239,   239,   240,   240,   241,
     242,   242,   243
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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
       1,     1,     1,     1,     1,     0,     1,     1,     1,     4,
       3,     4,     1,     1,     3,     5,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     4,     3,     1,     1,     3,
       3,     3,     3,     1,     1,     2,     2,     1,     1,     1,
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
static const yytype_uint16 yydefact[] =
{
       0,   307,   308,     0,     2,     3,     5,     1,     4,     7,
       0,     0,     8,   312,    15,    10,     0,    11,    13,    16,
       9,    12,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,    24,    22,    20,    23,    21,     0,    19,    14,
      52,     0,     0,    26,    36,    53,     0,    56,     0,    57,
      59,    61,     6,    40,     0,    37,    55,    54,     0,     0,
      39,     0,    41,    42,     0,    47,    49,    51,   187,     0,
     188,   189,   190,   191,   192,   200,   193,   194,   195,   196,
     197,   198,   199,    27,    28,    32,    30,    31,    35,     0,
     296,    58,    60,    38,    43,     0,     0,     0,    33,    29,
     296,   134,   309,     0,   169,     0,     0,   183,   176,   180,
     182,   170,     0,     0,   171,   175,   179,     0,     0,    65,
     185,   172,    64,   181,   138,   300,     0,   123,   297,   304,
      44,    48,    50,    34,     0,    68,    67,     0,   184,   178,
     177,   174,   173,     0,    71,     0,   172,    73,     0,   296,
       0,   186,     0,   302,   303,   301,     0,     0,     0,   205,
     306,   305,   298,    45,    46,     0,   135,   137,     0,     0,
       0,     0,     0,    63,   158,   164,   159,   292,   293,   165,
     166,   156,   157,    83,     0,    78,    80,    81,   160,   161,
      82,   291,   283,     0,   285,   290,   287,   143,   144,   139,
     140,   142,   136,     0,   155,   153,   149,   150,   151,     0,
     162,   131,     0,     0,   205,   205,   125,   124,     0,     0,
     122,   206,   207,   208,   296,   296,     0,   100,   296,    72,
      77,    76,    75,    74,   245,   246,   295,     0,     0,   296,
     239,   238,     0,     0,   237,   240,     0,   212,     0,     0,
     242,     0,   213,   217,   219,   221,   223,   234,     0,   227,
     243,   228,   233,   216,   259,   261,   260,   269,   270,   294,
     241,   247,   244,    66,   296,   284,     0,     0,     0,   299,
       0,     0,     0,     0,   296,     0,   296,     0,   296,     0,
       0,     0,     0,   148,   145,     0,   281,   279,   279,   279,
     102,   280,    98,   279,   279,   109,     0,    70,    69,     0,
       0,   264,   265,     0,     0,   235,   236,     0,     0,     0,
       0,    62,     0,   201,   202,     0,   203,   204,     0,     0,
       0,     0,     0,    79,   286,     0,     0,   162,   141,   167,
     154,   163,   152,     0,   119,     0,    92,    95,    96,   296,
     133,     0,     0,    85,    86,    91,   279,   296,   310,     0,
     310,     0,   210,     0,   282,   107,     0,   106,   108,    99,
     279,   104,   105,     0,    97,   110,   101,   218,   262,   266,
     267,   232,   230,   248,     0,   271,   226,   214,   220,   222,
     224,     0,   231,   229,     0,     0,   273,   289,   288,   168,
     132,     0,   126,   296,    94,   296,   127,   296,    89,   279,
     296,   311,   128,   296,   209,   211,   146,   147,   103,     0,
       0,   268,   252,     0,   250,   205,     0,   225,     0,   275,
     277,   272,     0,   120,   121,    93,    90,    87,    88,   123,
     123,   111,   263,   249,     0,   254,   215,   276,     0,   274,
     129,   130,     0,   251,   257,   258,   256,   253,   255,   278,
     115,   116,     0,     0,   113,   117,     0,   112,   114,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     9,    11,    12,    16,    17,    28,
      29,    30,    42,    43,    83,    84,   133,    54,    55,    61,
      62,   164,    63,    64,    65,    44,    45,    48,    49,   183,
      85,   118,    86,   143,   144,   184,   185,   352,   353,   354,
     345,   346,   135,   370,   226,   227,   374,   375,   452,   463,
     464,   355,   356,   158,   159,   217,   119,   199,   200,   465,
     298,   299,    87,   206,   280,   207,   208,   250,   340,   120,
     121,   122,   123,   325,   328,   220,   221,   222,   223,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   423,   424,   457,   458,   263,   264,   420,   265,   314,
     266,   267,   268,   395,   396,   429,   300,   301,   151,   193,
     194,   269,   270,   127,   128,   129,   156,   162,   271,   124,
     410,   272
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -271
static const yytype_int16 yypact[] =
{
     278,  -271,  -271,    47,   278,  -271,  -271,  -271,  -271,   -86,
      10,    13,  -271,  -271,  -271,  -271,    40,  -271,    33,   243,
    -271,  -271,   146,   115,    81,   124,   135,   131,   229,   243,
    -271,   153,  -271,  -271,  -271,  -271,  -271,   233,  -271,  -271,
      32,    59,   230,  -271,   224,  -271,   176,  -271,   -18,  -271,
     199,  -271,  -271,   239,   523,  -271,  -271,  -271,   183,   200,
    -271,   204,   183,  -271,   -16,  -271,   203,  -271,  -271,   299,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   523,  -271,  -271,  -271,  -271,  -271,   357,
     208,  -271,  -271,  -271,  -271,   278,   183,   209,  -271,  -271,
     -14,   213,  -271,   251,  -271,   255,   270,  -271,  -271,  -271,
    -271,  -271,   292,   264,  -271,  -271,  -271,   677,   349,   244,
    -271,   245,  -271,  -271,   236,    26,   353,  -271,  -271,   148,
     -86,  -271,  -271,  -271,   248,  -271,  -271,   183,  -271,  -271,
    -271,  -271,  -271,   -45,  -271,   246,  -271,   247,   249,   104,
      74,  -271,   281,  -271,  -271,  -271,   354,   194,   600,    78,
    -271,  -271,  -271,  -271,  -271,   289,  -271,  -271,   356,   677,
     183,   183,   461,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,  -271,    76,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,  -271,   101,  -271,  -271,   252,  -271,  -271,   250,
    -271,  -271,  -271,   253,  -271,  -271,  -271,  -271,  -271,   269,
     256,   324,   257,   293,    82,   202,  -271,  -271,   279,   461,
    -271,  -271,  -271,   283,   142,     0,   108,  -271,   -14,  -271,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,   266,   361,   208,
    -271,  -271,   -70,   240,  -271,  -271,   290,  -271,   278,   461,
    -271,   285,   282,   225,   231,  -271,   296,  -271,   291,   -70,
    -271,  -271,  -271,  -271,  -271,  -271,  -271,   295,  -271,  -271,
    -271,  -271,  -271,  -271,   104,  -271,    80,   312,   319,  -271,
     395,   392,   194,   374,    18,   325,    69,   334,    69,   335,
     461,   302,   461,  -271,  -271,   194,  -271,    22,   -11,    22,
    -271,  -271,   321,   -11,    22,   315,   289,  -271,  -271,   479,
     308,  -271,   303,   317,   217,  -271,  -271,   314,   310,   322,
     329,  -271,   323,  -271,  -271,   479,  -271,  -271,   479,   479,
     461,   369,   328,  -271,  -271,   330,   331,  -271,  -271,  -271,
     428,  -271,  -271,   392,   318,   136,  -271,  -271,  -271,   208,
    -271,   370,   337,   336,  -271,  -271,    22,   208,   392,   341,
     392,   333,  -271,   340,  -271,  -271,   326,  -271,  -271,  -271,
      22,  -271,  -271,   371,  -271,  -271,  -271,  -271,  -271,  -271,
     338,  -271,  -271,   283,    23,  -271,  -271,   346,   231,  -271,
    -271,   350,  -271,  -271,     6,   147,  -271,  -271,  -271,  -271,
    -271,   312,  -271,    18,  -271,   208,  -271,    57,  -271,    22,
     208,  -271,  -271,   208,  -271,  -271,  -271,  -271,  -271,   355,
     395,  -271,  -271,   167,  -271,    78,   228,  -271,   392,   344,
    -271,  -271,   328,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,   428,  -271,    23,    24,  -271,   344,   392,  -271,
    -271,  -271,    37,  -271,  -271,  -271,  -271,  -271,  -271,  -271,
    -271,  -271,    37,    53,  -271,  -271,     7,  -271,  -271,  -271
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -271,  -271,  -271,   474,  -271,  -271,   351,  -271,   449,  -271,
    -271,   450,  -271,  -271,  -271,   397,  -271,  -271,  -271,  -271,
    -271,  -271,   420,  -271,   387,  -271,  -271,  -271,   438,   352,
    -271,   339,  -271,  -271,   332,  -271,   232,   214,  -271,    96,
    -271,   102,   276,  -271,  -271,   201,  -271,  -271,  -271,    46,
    -247,  -270,   -87,  -271,   -94,  -271,   226,  -271,   237,  -148,
     284,   294,  -271,  -112,  -271,  -142,  -265,  -139,    90,   -75,
     -41,  -271,    97,  -271,  -271,  -213,  -271,  -271,   197,  -211,
      91,  -271,   191,   190,  -200,  -271,  -271,  -227,  -271,  -271,
    -271,  -271,    77,  -271,  -271,  -271,  -271,  -271,  -271,   261,
    -271,  -271,  -271,  -271,    92,    94,  -264,  -271,  -271,  -271,
     258,  -128,  -271,  -108,  -271,  -271,  -271,  -271,     5,  -271,
     163,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -280
static const yytype_int16 yytable[] =
{
      18,   287,   289,   126,   201,     6,    18,   187,   291,     6,
     188,   460,   335,   136,   347,    13,   293,   294,   188,    13,
     134,   189,   195,    10,   197,   198,   461,    13,   295,   189,
      14,    51,    13,   365,   367,   368,    95,   312,   320,   371,
     372,   460,   145,    67,    90,   454,    50,     7,    51,    13,
     313,   153,    67,    19,   197,   198,   461,   460,    66,    89,
      14,   295,   186,    50,   296,   168,    13,    66,    13,   169,
     197,   198,   461,    90,     1,     2,   146,   -25,    13,   361,
      41,   363,    46,    13,   177,   178,    67,   382,    89,    13,
     177,   178,   408,   351,   145,    57,    58,   296,    96,   455,
     130,    66,   125,   456,   393,   351,   418,   154,   366,   377,
     174,   175,   176,    13,   177,   178,   125,   179,   180,   391,
      15,   155,   147,   462,   469,   428,   344,   167,   146,   390,
     201,   422,   187,   347,   125,   188,   433,   297,   302,   190,
     196,   308,   166,   188,    22,   438,   189,   210,   195,   336,
      20,    88,   311,   462,   189,   181,   188,   202,   293,   294,
     231,   233,   209,   467,   218,   344,    31,   189,   218,   462,
     342,    33,    47,   125,   147,   230,   232,   344,    32,   -84,
      88,   295,   191,   364,   192,   125,   273,   186,   191,   219,
     274,   286,    13,   219,    35,   160,   182,   348,     1,     2,
     174,   175,   176,    13,   177,   178,   161,   179,   180,     1,
       2,   275,   445,   172,    34,   276,   468,   296,   305,   468,
     125,    36,   306,   234,   175,   235,    13,   177,   178,   236,
     179,   180,    37,   316,   234,   175,   235,    13,   177,   178,
     236,   179,   180,     1,     2,   181,   402,   315,    13,    13,
     403,   237,  -279,   319,     1,     2,  -279,   431,   125,    23,
      40,   432,   404,   204,   190,    39,   196,   337,   240,    24,
     409,   341,   210,   434,   349,    52,   357,   443,   357,   240,
     241,   444,   209,   381,    53,   210,   182,   209,   218,    56,
      25,    60,    26,     1,     2,   242,     1,     2,   197,   198,
     209,    27,   439,   205,   243,   440,   224,   225,    59,   245,
      92,   288,    97,   219,   244,    98,   348,    93,   436,   132,
     245,    13,   177,   178,   125,   317,   318,     1,     2,   246,
     323,   324,   137,   400,   326,   327,   197,   198,   138,   249,
     101,   102,   139,   416,   417,   450,   451,   140,   411,   141,
     411,   142,   148,   149,   150,   152,   157,   165,   172,   228,
     100,   170,   171,   277,   203,   283,   284,   285,   309,   278,
     279,   282,   101,   102,   425,   234,   175,   235,    13,   177,
     178,   236,   179,   180,   430,   103,    68,   104,   281,   105,
     290,   337,   310,   349,   292,   321,   322,   357,   329,   106,
     339,    13,   330,   107,   332,   343,   209,   108,   358,   360,
     109,    70,    71,    72,   362,   369,   373,   378,   430,   384,
     240,   110,    73,   379,   380,   219,   111,    74,   112,    75,
     113,   387,   385,   399,   425,   392,   401,    76,   459,   114,
     115,   386,   397,   398,   405,   414,    77,   406,    78,   394,
     407,   412,   415,    79,   116,    80,    81,    82,   421,   419,
     426,   245,   427,   448,   441,    21,   117,   234,   175,   235,
      13,   177,   178,   236,   179,   180,     1,     2,     8,    38,
      99,   163,    94,   131,   237,   234,   175,   235,    13,   177,
     178,   236,   179,   180,     1,     2,    91,   216,   238,   239,
     173,   229,   359,   437,   307,   435,   333,   376,   466,   303,
     442,   350,   240,   241,   383,   338,   388,   446,   389,   304,
     331,   453,   447,   413,   449,     0,     0,     0,   242,     0,
     240,   241,    13,     0,   334,     0,     0,   243,     1,     2,
       0,     0,     0,     0,     0,     0,   242,   244,     0,     0,
       0,     0,    68,   245,     0,   243,     0,     0,     0,     0,
       0,     0,   246,     0,     0,   244,     0,    69,     0,   247,
     248,   245,   249,     0,     0,     0,     0,    70,    71,    72,
     246,     0,     0,     0,     0,     0,     0,     0,    73,     0,
     249,     0,     0,    74,     0,    75,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,    78,   101,   102,     0,     0,    79,
       0,    80,    81,    82,   211,     0,     0,     0,   103,    68,
     104,     0,   105,   212,     0,     0,     0,     0,     0,     0,
       0,     0,   106,     0,     0,     0,   107,     0,     0,     0,
     108,     0,     0,   109,    70,    71,    72,     0,     0,     0,
       0,     0,   213,     0,   110,    73,     0,     0,     0,   111,
      74,   112,    75,   113,     0,     0,     0,     0,     0,     0,
      76,     0,   114,   115,   214,   215,     0,     0,     0,    77,
       0,    78,     1,     2,     0,     0,    79,   116,    80,    81,
      82,     0,     0,     0,     0,   103,    68,   104,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,   107,     0,     0,     0,   108,     0,     0,
     109,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,   110,    73,     0,     0,     0,   111,    74,   112,    75,
     113,     0,     0,     0,     0,     0,     0,    76,     0,   114,
     115,     0,     0,     0,     0,     0,    77,     0,    78,     0,
       0,     0,     0,    79,   116,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      10,   214,   215,    90,   152,     0,    16,   149,   219,     4,
     149,     4,   277,   100,   284,     9,    16,    17,   157,     9,
      34,   149,   150,   109,    17,    18,    19,     9,    39,   157,
      20,    41,     9,   297,   298,   299,    52,   107,   249,   303,
     304,     4,   117,    53,    54,    21,    41,     0,    58,     9,
     120,    25,    62,    40,    17,    18,    19,     4,    53,    54,
      20,    39,   149,    58,    75,   110,     9,    62,     9,   114,
      17,    18,    19,    83,    15,    16,   117,    45,     9,   290,
      48,   292,    23,     9,    10,    11,    96,   314,    83,     9,
      10,    11,   356,    36,   169,   113,   114,    75,   114,    75,
      95,    96,   116,    79,   331,    36,   370,    81,   119,   309,
       6,     7,     8,     9,    10,    11,   116,    13,    14,   330,
     110,    95,   117,   116,   117,   119,   108,   137,   169,   329,
     278,   108,   274,   403,   116,   274,   401,   224,   225,   149,
     150,   228,   137,   282,   111,   409,   274,   157,   276,   277,
     110,    54,   239,   116,   282,    51,   295,   152,    16,    17,
     170,   171,   157,   110,    86,   108,    20,   295,    86,   116,
     282,    90,   113,   116,   169,   170,   171,   108,    63,   110,
      83,    39,   108,   295,   110,   116,   110,   274,   108,   111,
     114,   109,     9,   111,    59,    47,    92,   284,    15,    16,
       6,     7,     8,     9,    10,    11,    58,    13,    14,    15,
      16,   110,   425,   109,    90,   114,   463,    75,   110,   466,
     116,    90,   114,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     3,   243,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    51,   110,     7,     9,     9,
     114,    23,   110,   248,    15,    16,   114,   110,   116,    16,
      27,   114,   349,    69,   274,   112,   276,   277,    51,    26,
     357,   281,   282,   401,   284,    45,   286,   110,   288,    51,
      52,   114,   277,    66,    60,   295,    92,   282,    86,   113,
      47,    52,    49,    15,    16,    67,    15,    16,    17,    18,
     295,    58,   410,   109,    76,   413,    17,    18,   109,    92,
     110,   109,   109,   111,    86,    16,   403,   113,   405,   110,
      92,     9,    10,    11,   116,    35,    36,    15,    16,   101,
     105,   106,   119,   343,   103,   104,    17,    18,    87,   111,
      15,    16,    87,    17,    18,   439,   440,    77,   358,    57,
     360,    87,     3,   109,   109,   119,     3,   109,   109,     3,
       3,   115,   115,   111,    10,    41,   109,    74,   102,   119,
     117,   115,    15,    16,   384,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   394,    28,    29,    30,   119,    32,
     111,   401,    31,   403,   111,   110,   114,   407,   102,    42,
       5,     9,   111,    46,   109,    31,   401,    50,    74,    74,
      53,    54,    55,    56,   112,    94,   101,   109,   428,   109,
      51,    64,    65,   120,   107,   111,    69,    70,    71,    72,
      73,   108,   110,     5,   444,    66,   118,    80,   448,    82,
      83,   112,   112,   112,    74,   112,    89,   110,    91,   121,
     114,   110,   112,    96,    97,    98,    99,   100,   120,    88,
     114,    92,   112,   119,   109,    16,   109,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     4,    29,
      83,   130,    62,    96,    23,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    58,   158,    37,    38,
     148,   169,   288,   407,   228,   403,   274,   306,   462,   225,
     420,   285,    51,    52,   317,   278,   325,   426,   328,   225,
     259,   444,   428,   360,   432,    -1,    -1,    -1,    67,    -1,
      51,    52,     9,    -1,   276,    -1,    -1,    76,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    86,    -1,    -1,
      -1,    -1,    29,    92,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,    86,    -1,    44,    -1,   108,
     109,    92,   111,    -1,    -1,    -1,    -1,    54,    55,    56,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
     111,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    91,    15,    16,    -1,    -1,    96,
      -1,    98,    99,   100,    24,    -1,    -1,    -1,    28,    29,
      30,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    -1,    -1,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    64,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    89,
      -1,    91,    15,    16,    -1,    -1,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,    -1,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,   123,   124,   125,   240,     0,   125,   126,
     109,   127,   128,     9,    20,   110,   129,   130,   243,    40,
     110,   130,   111,    16,    26,    47,    49,    58,   131,   132,
     133,    20,    63,    90,    90,    59,    90,     3,   133,   112,
      27,    48,   134,   135,   147,   148,    23,   113,   149,   150,
     240,   243,    45,    60,   139,   140,   113,   113,   114,   109,
      52,   141,   142,   144,   145,   146,   240,   243,    29,    44,
      54,    55,    56,    65,    70,    72,    80,    89,    91,    96,
      98,    99,   100,   136,   137,   152,   154,   184,   194,   240,
     243,   150,   110,   113,   144,    52,   114,   109,    16,   137,
       3,    15,    16,    28,    30,    32,    42,    46,    50,    53,
      64,    69,    71,    73,    82,    83,    97,   109,   153,   178,
     191,   192,   193,   194,   241,   116,   174,   235,   236,   237,
     240,   146,   110,   138,    34,   164,   174,   119,    87,    87,
      77,    57,    87,   155,   156,   191,   192,   240,     3,   109,
     109,   230,   119,    25,    81,    95,   238,     3,   175,   176,
      47,    58,   239,   128,   143,   109,   240,   243,   110,   114,
     115,   115,   109,   151,     6,     7,     8,    10,    11,    13,
      14,    51,    92,   151,   157,   158,   174,   187,   189,   233,
     243,   108,   110,   231,   232,   233,   243,    17,    18,   179,
     180,   181,   240,    10,    69,   109,   185,   187,   188,   240,
     243,    24,    33,    62,    84,    85,   153,   177,    86,   111,
     197,   198,   199,   200,    17,    18,   166,   167,     3,   156,
     240,   243,   240,   243,     6,     8,    12,    23,    37,    38,
      51,    52,    67,    76,    86,    92,   101,   108,   109,   111,
     189,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   217,   218,   220,   222,   223,   224,   233,
     234,   240,   243,   110,   114,   110,   114,   111,   119,   117,
     186,   119,   115,    41,   109,    74,   109,   197,   109,   197,
     111,   201,   111,    16,    17,    39,    75,   174,   182,   183,
     228,   229,   174,   182,   183,   110,   114,   164,   174,   102,
      31,   174,   107,   120,   221,     7,   243,    35,    36,   240,
     201,   110,   114,   105,   106,   195,   103,   104,   196,   102,
     111,   221,   109,   158,   232,   188,   233,   243,   180,     5,
     190,   243,   185,    31,   108,   162,   163,   173,   174,   243,
     178,    36,   159,   160,   161,   173,   174,   243,    74,   159,
      74,   201,   112,   201,   185,   228,   119,   228,   228,    94,
     165,   228,   228,   101,   168,   169,   167,   206,   109,   120,
     107,    66,   209,   200,   109,   110,   112,   108,   204,   205,
     206,   201,    66,   209,   121,   225,   226,   112,   112,     5,
     243,   118,   110,   114,   174,    74,   110,   114,   228,   174,
     242,   243,   110,   242,   112,   112,    17,    18,   228,    88,
     219,   120,   108,   213,   214,   243,   114,   112,   119,   227,
     243,   110,   114,   188,   233,   163,   174,   161,   228,   235,
     235,   109,   190,   110,   114,   197,   202,   227,   119,   226,
     176,   176,   170,   214,    21,    75,    79,   215,   216,   243,
       4,    19,   116,   171,   172,   181,   171,   110,   172,   117
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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
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
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
      YYSIZE_T yyn = 0;
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
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
      int yychecklim = YYLAST - yyn + 1;
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
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
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
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  YYUSE (yyvaluep);

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
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

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
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


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
	yytype_int16 *yyss1 = yyss;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 357 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 3:
#line 363 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 4:
#line 368 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 5:
#line 385 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 6:
#line 390 "asn1p_y.y"
    {

		(yyval.a_module) = currentModule;

		if((yyvsp[(8) - (9)].a_module)) {
			asn1p_module_t tmp = *((yyval.a_module));
			*((yyval.a_module)) = *((yyvsp[(8) - (9)].a_module));
			*((yyvsp[(8) - (9)].a_module)) = tmp;
			asn1p_module_free((yyvsp[(8) - (9)].a_module));
		} else {
			/* There's a chance that a module is just plain empty */
		}

		(yyval.a_module)->ModuleName = (yyvsp[(1) - (9)].tv_str);
		(yyval.a_module)->module_oid = (yyvsp[(3) - (9)].a_oid);
		(yyval.a_module)->module_flags = (yyvsp[(5) - (9)].a_module_flags);
	}
    break;

  case 7:
#line 414 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 8:
#line 415 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 9:
#line 419 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 10:
#line 422 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 11:
#line 428 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(1) - (1)].a_oid_arc));
		if((yyvsp[(1) - (1)].a_oid_arc).name)
			free((yyvsp[(1) - (1)].a_oid_arc).name);
		if((yyvsp[(1) - (1)].a_oid_arc).number)
			free((yyvsp[(1) - (1)].a_oid_arc).number);
	}
    break;

  case 12:
#line 436 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(1) - (2)].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(2) - (2)].a_oid_arc));
		if((yyvsp[(2) - (2)].a_oid_arc).name)
			free((yyvsp[(2) - (2)].a_oid_arc).name);
		if ((yyvsp[(2) - (2)].a_oid_arc).number)
			free((yyvsp[(2) - (2)].a_oid_arc).number);
	}
    break;

  case 13:
#line 447 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = 0;
	}
    break;

  case 14:
#line 451 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[(3) - (4)].tv_str);
	}
    break;

  case 15:
#line 455 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 16:
#line 465 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 17:
#line 466 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 18:
#line 475 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 478 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 20:
#line 487 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 21:
#line 490 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 22:
#line 493 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 23:
#line 496 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 24:
#line 500 "asn1p_y.y"
    {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp((yyvsp[(1) - (2)].tv_str), "TAG") == 0) {
		 	(yyval.a_module_flags) = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp((yyvsp[(1) - (2)].tv_str), "XER") == 0) {
		 	(yyval.a_module_flags) = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at line %d: "
				"Unrecognized encoding reference\n",
				(yyvsp[(1) - (2)].tv_str), yylineno);
		 	(yyval.a_module_flags) = MSF_unk_INSTRUCTIONS;
		}
		free((yyvsp[(1) - (2)].tv_str));
	}
    break;

  case 25:
#line 521 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 26:
#line 522 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 27:
#line 531 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[(1) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[(2) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), members, (yyvsp[(3) - (3)].a_module), next);
	}
    break;

  case 28:
#line 540 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 29:
#line 543 "asn1p_y.y"
    {
		if((yyvsp[(1) - (2)].a_module)) {
			(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		} else {
			(yyval.a_module) = (yyvsp[(2) - (2)].a_module);
			break;
		}
		AL_IMPORT((yyval.a_module), members, (yyvsp[(2) - (2)].a_module), next);
	}
    break;

  case 30:
#line 559 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 31:
#line 566 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 32:
#line 579 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 33:
#line 587 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 588 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at line %d ignored\n",
			(yyvsp[(2) - (3)].tv_str), yylineno);
		free((yyvsp[(2) - (3)].tv_str));
		(yyval.a_module) = 0;
	}
    break;

  case 35:
#line 600 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 613 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 38:
#line 617 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 39:
#line 627 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 40:
#line 633 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 42:
#line 637 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 43:
#line 642 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 44:
#line 649 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 45:
#line 650 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 46:
#line 654 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (4)].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[(3) - (4)].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[(4) - (4)].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
    break;

  case 47:
#line 665 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 48:
#line 670 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 49:
#line 677 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 50:
#line 683 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 689 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 699 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 53:
#line 700 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		if((yyvsp[(1) - (1)].a_xports)) {
			TQ_ADD(&((yyval.a_module)->exports), (yyvsp[(1) - (1)].a_xports), xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
    break;

  case 54:
#line 712 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 55:
#line 715 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 56:
#line 718 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 57:
#line 726 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 58:
#line 731 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 59:
#line 738 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 60:
#line 744 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 750 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 759 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 63:
#line 762 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 64:
#line 772 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 65:
#line 785 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 66:
#line 795 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (4)].a_ref);
		(yyval.a_expr)->rhs_pspecs = (yyvsp[(3) - (4)].a_expr);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 67:
#line 815 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 68:
#line 821 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 69:
#line 837 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 70:
#line 843 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 851 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[(1) - (1)].a_parg).governor, (yyvsp[(1) - (1)].a_parg).argument);
		checkmem(ret == 0);
		if((yyvsp[(1) - (1)].a_parg).governor) asn1p_ref_free((yyvsp[(1) - (1)].a_parg).governor);
		if((yyvsp[(1) - (1)].a_parg).argument) free((yyvsp[(1) - (1)].a_parg).argument);
	}
    break;

  case 72:
#line 860 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = (yyvsp[(1) - (3)].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[(3) - (3)].a_parg).governor, (yyvsp[(3) - (3)].a_parg).argument);
		checkmem(ret == 0);
		if((yyvsp[(3) - (3)].a_parg).governor) asn1p_ref_free((yyvsp[(3) - (3)].a_parg).governor);
		if((yyvsp[(3) - (3)].a_parg).argument) free((yyvsp[(3) - (3)].a_parg).argument);
	}
    break;

  case 73:
#line 871 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 74:
#line 875 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 75:
#line 882 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 76:
#line 889 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[(1) - (3)].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 77:
#line 897 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[(1) - (3)].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 78:
#line 908 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 79:
#line 913 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 80:
#line 920 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 81:
#line 923 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = "?";
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 82:
#line 931 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		(yyval.a_expr)->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 83:
#line 942 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 84:
#line 965 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 85:
#line 966 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 86:
#line 969 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 87:
#line 974 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 88:
#line 981 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 89:
#line 988 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 90:
#line 994 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 91:
#line 1001 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 92:
#line 1007 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 93:
#line 1012 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 94:
#line 1019 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 95:
#line 1024 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 96:
#line 1027 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 97:
#line 1034 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 98:
#line 1044 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 99:
#line 1045 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 100:
#line 1049 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 101:
#line 1056 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 102:
#line 1066 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
	}
    break;

  case 103:
#line 1076 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		(yyval.a_expr)->unique = (yyvsp[(3) - (4)].a_int);
		(yyval.a_expr)->marker = (yyvsp[(4) - (4)].a_marker);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(2) - (4)].a_expr));
	}
    break;

  case 104:
#line 1087 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 105:
#line 1097 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OFS;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 106:
#line 1108 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 107:
#line 1118 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(2) - (3)].a_expr));
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 108:
#line 1129 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OSFS;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 109:
#line 1141 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 110:
#line 1142 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 111:
#line 1149 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 112:
#line 1151 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 113:
#line 1157 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 114:
#line 1161 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 115:
#line 1168 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 116:
#line 1172 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 117:
#line 1175 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 118:
#line 1179 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 119:
#line 1185 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 120:
#line 1193 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->value = (yyvsp[(3) - (3)].a_value);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 121:
#line 1202 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		(yyval.a_expr)->value = (yyvsp[(3) - (3)].a_value);
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 122:
#line 1214 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		(yyval.a_expr)->tag = (yyvsp[(1) - (3)].a_tag);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[(3) - (3)].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[(2) - (3)].a_expr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[(3) - (3)].a_constr);
			}
		}
	}
    break;

  case 123:
#line 1236 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 124:
#line 1243 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		(yyval.a_expr)->marker.flags |= (yyvsp[(1) - (2)].a_int);

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

  case 125:
#line 1262 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 126:
#line 1265 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 127:
#line 1271 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 128:
#line 1277 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1283 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[(2) - (6)].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[(6) - (6)].a_expr)->Identifier = (yyvsp[(4) - (6)].tv_str);
		(yyvsp[(6) - (6)].a_expr)->tag = (yyvsp[(5) - (6)].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(6) - (6)].a_expr));
	}
    break;

  case 130:
#line 1293 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[(2) - (6)].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[(6) - (6)].a_expr)->Identifier = (yyvsp[(4) - (6)].tv_str);
		(yyvsp[(6) - (6)].a_expr)->tag = (yyvsp[(5) - (6)].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(6) - (6)].a_expr));
	}
    break;

  case 131:
#line 1303 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 132:
#line 1309 "asn1p_y.y"
    {
		int ret;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference,
			(yyvsp[(4) - (4)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 133:
#line 1320 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1335 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 135:
#line 1343 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 136:
#line 1353 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 137:
#line 1363 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 138:
#line 1373 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
		checkmem(ret == 0);
	}
    break;

  case 139:
#line 1381 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(3) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (3)].tv_str));
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

  case 140:
#line 1403 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].a_refcomp).name, (yyvsp[(1) - (1)].a_refcomp).lex_type);
		free((yyvsp[(1) - (1)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 141:
#line 1411 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 143:
#line 1424 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 144:
#line 1429 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 145:
#line 1438 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
	}
    break;

  case 146:
#line 1442 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
	}
    break;

  case 147:
#line 1446 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
	}
    break;

  case 148:
#line 1453 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
	}
    break;

  case 149:
#line 1473 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 152:
#line 1485 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 153:
#line 1492 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 154:
#line 1492 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 155:
#line 1497 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 156:
#line 1505 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 157:
#line 1510 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 158:
#line 1515 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
	}
    break;

  case 159:
#line 1519 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
	}
    break;

  case 160:
#line 1523 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 161:
#line 1526 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 162:
#line 1532 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 163:
#line 1543 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component(ref, (yyvsp[(3) - (3)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (3)].tv_str));
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 164:
#line 1561 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 165:
#line 1565 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 166:
#line 1570 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 167:
#line 1578 "asn1p_y.y"
    {
		(yyval.tv_opaque).len = (yyvsp[(1) - (1)].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc((yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[(1) - (1)].tv_opaque).buf);
	}
    break;

  case 168:
#line 1587 "asn1p_y.y"
    {
		int newsize = (yyvsp[(1) - (2)].tv_opaque).len + (yyvsp[(2) - (2)].tv_opaque).len;
		char *p = malloc(newsize + 1);
		checkmem(p);
		memcpy(p         , (yyvsp[(1) - (2)].tv_opaque).buf, (yyvsp[(1) - (2)].tv_opaque).len);
		memcpy(p + (yyvsp[(1) - (2)].tv_opaque).len, (yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len);
		p[newsize] = '\0';
		free((yyvsp[(1) - (2)].tv_opaque).buf);
		free((yyvsp[(2) - (2)].tv_opaque).buf);
		(yyval.tv_opaque).buf = p;
		(yyval.tv_opaque).len = newsize;
	}
    break;

  case 169:
#line 1602 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 170:
#line 1603 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 171:
#line 1604 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 172:
#line 1605 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 173:
#line 1606 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 174:
#line 1607 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 175:
#line 1608 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 176:
#line 1609 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 177:
#line 1610 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 178:
#line 1611 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 179:
#line 1612 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 180:
#line 1613 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 181:
#line 1614 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 182:
#line 1621 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 183:
#line 1622 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 184:
#line 1623 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 185:
#line 1627 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 186:
#line 1633 "asn1p_y.y"
    {
		if((yyvsp[(2) - (2)].a_expr)) {
			(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		} else {
			(yyval.a_expr) = NEW_EXPR();
			checkmem((yyval.a_expr));
		}
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (2)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 187:
#line 1646 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 188:
#line 1647 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 189:
#line 1651 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 190:
#line 1655 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 191:
#line 1656 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 192:
#line 1657 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 193:
#line 1658 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 194:
#line 1659 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 195:
#line 1663 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 196:
#line 1664 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 197:
#line 1665 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 198:
#line 1666 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 199:
#line 1670 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 200:
#line 1671 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 205:
#line 1682 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 206:
#line 1683 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 208:
#line 1693 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (1)].a_constr), 0);
	}
    break;

  case 209:
#line 1696 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(3) - (4)].a_constr), 0);
	}
    break;

  case 210:
#line 1706 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(2) - (3)].a_constr);
	}
    break;

  case 211:
#line 1709 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 212:
#line 1715 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 213:
#line 1719 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 214:
#line 1722 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 215:
#line 1728 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
		ct = (yyval.a_constr);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
	}
    break;

  case 216:
#line 1736 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 218:
#line 1743 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 220:
#line 1750 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 222:
#line 1757 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 224:
#line 1765 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 225:
#line 1771 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(1) - (4)].a_ctype);
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (4)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 226:
#line 1779 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CA_SET;
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 227:
#line 1787 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 228:
#line 1793 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 229:
#line 1799 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 230:
#line 1806 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
		(yyval.a_constr)->range_start->type = ATV_MIN;
	}
    break;

  case 231:
#line 1814 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 232:
#line 1822 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_start->type = ATV_MIN;
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 233:
#line 1831 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 234:
#line 1834 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 235:
#line 1840 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 236:
#line 1845 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, (yyvsp[(2) - (2)].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 237:
#line 1856 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_SIZE;
	}
    break;

  case 238:
#line 1859 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_FROM;
	}
    break;

  case 239:
#line 1865 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 240:
#line 1870 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 244:
#line 1878 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 245:
#line 1892 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
	}
    break;

  case 246:
#line 1896 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
	}
    break;

  case 247:
#line 1903 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 248:
#line 1917 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 249:
#line 1920 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(4) - (5)].a_constr), 0);
	}
    break;

  case 250:
#line 1926 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 251:
#line 1929 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 252:
#line 1935 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_EXT;
		(yyval.a_constr)->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 253:
#line 1941 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(1) - (3)].tv_str), strlen((yyvsp[(1) - (3)].tv_str)), 0);
		(yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
		if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
	}
    break;

  case 254:
#line 1955 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 255:
#line 1956 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 256:
#line 1960 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 257:
#line 1963 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 258:
#line 1966 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 262:
#line 1981 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 263:
#line 1981 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 264:
#line 1992 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 265:
#line 2000 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 266:
#line 2001 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 267:
#line 2002 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 268:
#line 2003 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 269:
#line 2006 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 270:
#line 2009 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 271:
#line 2018 "asn1p_y.y"
    {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, (yyvsp[(2) - (3)].tv_str), 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, ct, 0);
	}
    break;

  case 272:
#line 2033 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 273:
#line 2039 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 274:
#line 2045 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 275:
#line 2059 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[(2) - (2)].tv_str)) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, (yyvsp[(2) - (2)].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[(2) - (2)].tv_str));
	}
    break;

  case 276:
#line 2070 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[(3) - (3)].tv_str)) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, (yyvsp[(3) - (3)].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 277:
#line 2086 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 278:
#line 2089 "asn1p_y.y"
    {
		int l1 = strlen((yyvsp[(1) - (3)].tv_str));
		int l3 = strlen((yyvsp[(3) - (3)].tv_str));
		(yyval.tv_str) = malloc(l1 + 1 + l3 + 1);
		memcpy((yyval.tv_str), (yyvsp[(1) - (3)].tv_str), l1);
		(yyval.tv_str)[l1] = '.';
		memcpy((yyval.tv_str) + l1 + 1, (yyvsp[(3) - (3)].tv_str), l3);
		(yyval.tv_str)[l1 + 1 + l3] = '\0';
	}
    break;

  case 279:
#line 2107 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 280:
#line 2111 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 281:
#line 2115 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 282:
#line 2119 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 283:
#line 2142 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
	}
    break;

  case 284:
#line 2146 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
	}
    break;

  case 285:
#line 2152 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 286:
#line 2157 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 287:
#line 2164 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 288:
#line 2171 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 289:
#line 2179 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 290:
#line 2187 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 291:
#line 2194 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 292:
#line 2205 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 293:
#line 2209 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 295:
#line 2217 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 296:
#line 2248 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 297:
#line 2249 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 298:
#line 2253 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 299:
#line 2260 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 300:
#line 2266 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 301:
#line 2267 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 302:
#line 2268 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 303:
#line 2269 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 304:
#line 2273 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 305:
#line 2274 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 306:
#line 2275 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 307:
#line 2279 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 308:
#line 2283 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 309:
#line 2291 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 310:
#line 2298 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 311:
#line 2299 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 312:
#line 2305 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4785 "asn1p_y.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
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
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2311 "asn1p_y.y"



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


