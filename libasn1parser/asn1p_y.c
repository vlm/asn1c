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
#define YYDEBUG 1

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
#line 89 "asn1p_y.y"
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
	struct {
		asn1c_integer_t a_int;
		char *ascii_int; /* recorded as ASCII base-10 number */
	} tv_int;
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
#line 435 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 448 "asn1p_y.c"

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
#define YYLAST   855

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  122
/* YYNRULES -- Number of rules.  */
#define YYNRULES  314
/* YYNRULES -- Number of states.  */
#define YYNSTATES  474

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
     452,   454,   456,   460,   464,   465,   469,   471,   473,   475,
     477,   479,   482,   484,   486,   488,   492,   494,   496,   498,
     500,   503,   505,   507,   509,   511,   514,   517,   519,   521,
     524,   527,   529,   531,   533,   535,   537,   540,   542,   545,
     547,   549,   551,   553,   555,   557,   559,   561,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   582,   584,
     586,   588,   593,   597,   602,   604,   606,   610,   616,   618,
     620,   624,   626,   630,   632,   636,   638,   642,   647,   651,
     653,   655,   659,   663,   667,   671,   673,   675,   678,   681,
     683,   685,   687,   689,   691,   693,   695,   697,   699,   701,
     703,   707,   713,   715,   719,   721,   725,   726,   728,   730,
     732,   734,   736,   738,   740,   741,   747,   750,   752,   755,
     758,   762,   764,   766,   770,   775,   777,   781,   784,   788,
     790,   794,   795,   797,   799,   802,   805,   809,   811,   815,
     817,   822,   827,   829,   831,   833,   835,   837,   839,   840,
     842,   845,   850,   851,   853,   855,   857,   858,   860,   862,
     864,   866,   868,   869,   871
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     122,     0,    -1,   123,    -1,   124,    -1,   123,   124,    -1,
      -1,   239,   125,   126,    39,   130,     3,    26,   133,    44,
      -1,    -1,   127,    -1,   108,   128,   109,    -1,   108,   109,
      -1,   129,    -1,   128,   129,    -1,   242,    -1,   242,   110,
      10,   111,    -1,    10,    -1,    -1,   131,    -1,   132,    -1,
     131,   132,    -1,    46,    89,    -1,    57,    89,    -1,    25,
      89,    -1,    48,    58,    -1,    16,    62,    -1,    -1,   134,
      -1,   146,   138,   135,    -1,   136,    -1,   135,   136,    -1,
     153,    -1,   183,    -1,   151,    -1,    -1,    43,    16,   137,
      -1,   193,    -1,    -1,   139,    -1,    59,   140,   112,    -1,
      59,    51,    -1,    -1,   141,    -1,   143,    -1,   141,   143,
      -1,    -1,   127,    -1,   144,    51,   239,   142,    -1,   145,
      -1,   144,   113,   145,    -1,   239,    -1,   239,   108,   109,
      -1,   242,    -1,    -1,   147,    -1,    47,   148,   112,    -1,
      47,    22,   112,    -1,    47,   112,    -1,   149,    -1,   148,
     113,   149,    -1,   239,    -1,   239,   108,   109,    -1,   242,
      -1,   108,   200,   109,    -1,   239,   152,     3,   150,    -1,
     192,    -1,   177,    -1,   177,   108,   156,   109,    -1,   239,
       3,   173,    -1,   239,     3,   163,    -1,   239,   108,   154,
     109,     3,   173,    -1,   239,   108,   154,   109,     3,   163,
      -1,   155,    -1,   154,   113,   155,    -1,   239,    -1,   239,
     114,   242,    -1,   239,   114,   239,    -1,   190,   114,   242,
      -1,   190,   114,   239,    -1,   157,    -1,   156,   113,   157,
      -1,   173,    -1,   186,    -1,   242,    -1,   150,    -1,    -1,
     159,    -1,   160,    -1,   159,   113,   160,    -1,   242,   173,
     227,    -1,   173,   227,    -1,    35,    73,   173,    -1,   172,
      -1,   162,    -1,   161,   113,   162,    -1,   242,   173,    -1,
     172,    -1,   173,    -1,    33,   108,   165,   109,   167,    -1,
      -1,    93,    -1,   166,    -1,   165,   113,   166,    -1,    17,
     227,    -1,    18,   173,   164,   227,    -1,    18,   181,   227,
      -1,    18,   182,   227,    -1,    17,   181,   227,    -1,    17,
     173,   227,    -1,    17,   182,   227,    -1,    -1,   168,    -1,
      -1,   100,    87,   108,   169,   170,   109,    -1,   171,    -1,
     170,   171,    -1,     4,    -1,    19,    -1,   180,    -1,   115,
     170,   116,    -1,   107,    -1,   107,   117,   187,    -1,   107,
     117,   232,    -1,   234,   175,   196,    -1,    -1,   174,   176,
      -1,   152,    -1,    32,   108,   161,   109,    -1,    83,   108,
     158,   109,    -1,    84,   108,   158,   109,    -1,    83,   196,
      73,   241,   234,   175,    -1,    84,   196,    73,   241,   234,
     175,    -1,    23,    -1,    23,    40,    30,   242,    -1,    61,
      73,   177,    -1,    15,    -1,    15,   118,   239,    -1,   240,
     118,   239,    -1,    15,   118,   242,    -1,   240,    -1,   240,
     118,   178,    -1,   179,    -1,   178,   118,   179,    -1,   180,
      -1,    17,    -1,    18,    -1,    17,    -1,   181,   118,    17,
      -1,   181,   118,    18,    -1,    16,    -1,   242,   173,     3,
     184,    -1,   186,    -1,   187,    -1,   108,   128,   109,    -1,
     242,   114,   184,    -1,    -1,   108,   185,   189,    -1,    68,
      -1,    50,    -1,    91,    -1,     6,    -1,     8,    -1,   108,
     109,    -1,   188,    -1,   232,    -1,   242,    -1,   239,   118,
     242,    -1,     7,    -1,    13,    -1,    14,    -1,     5,    -1,
     189,     5,    -1,    29,    -1,    68,    -1,    81,    -1,   191,
      -1,    72,    86,    -1,    70,    56,    -1,    82,    -1,    49,
      -1,    41,    76,    -1,    31,    86,    -1,    96,    -1,    52,
      -1,   193,    -1,    63,    -1,    45,    -1,    27,    86,    -1,
     190,    -1,   191,   229,    -1,    28,    -1,    53,    -1,    54,
      -1,    55,    -1,    64,    -1,    69,    -1,    79,    -1,    88,
      -1,    90,    -1,    95,    -1,    97,    -1,    98,    -1,    99,
      -1,    71,    -1,   104,    -1,   105,    -1,   102,    -1,   103,
      -1,    -1,   197,    -1,   198,    -1,   199,    -1,    85,   110,
     200,   111,    -1,   110,   200,   111,    -1,   199,   110,   200,
     111,    -1,   107,    -1,   201,    -1,   201,   113,   107,    -1,
     201,   113,   107,   113,   201,    -1,   216,    -1,   202,    -1,
      22,   101,   205,    -1,   203,    -1,   202,   194,   203,    -1,
     204,    -1,   203,   195,   204,    -1,   205,    -1,   205,   101,
     205,    -1,   207,   110,   200,   111,    -1,   110,   200,   111,
      -1,   208,    -1,   210,    -1,   208,   220,   208,    -1,    66,
     220,   208,    -1,   208,   220,    65,    -1,    66,   220,    65,
      -1,   211,    -1,   206,    -1,    75,     7,    -1,    75,   242,
      -1,    85,    -1,    51,    -1,    50,    -1,    91,    -1,   233,
      -1,   188,    -1,   209,    -1,   242,    -1,     6,    -1,     8,
      -1,   239,    -1,   100,    34,   199,    -1,   100,    35,   108,
     212,   109,    -1,   213,    -1,   212,   113,   213,    -1,   107,
      -1,   242,   196,   214,    -1,    -1,   215,    -1,    78,    -1,
      20,    -1,    74,    -1,   217,    -1,   221,    -1,   219,    -1,
      -1,    36,    30,   108,   218,   189,    -1,    37,   173,    -1,
     106,    -1,   106,   119,    -1,   119,   106,    -1,   119,   106,
     119,    -1,   222,    -1,   223,    -1,   108,   239,   109,    -1,
     222,   108,   224,   109,    -1,   225,    -1,   224,   113,   225,
      -1,   120,   226,    -1,   120,   118,   226,    -1,   242,    -1,
     226,   118,   242,    -1,    -1,   228,    -1,    74,    -1,    38,
     184,    -1,   108,   109,    -1,   108,   230,   109,    -1,   231,
      -1,   230,   113,   231,    -1,   242,    -1,   242,   110,   232,
     111,    -1,   242,   110,   187,   111,    -1,   232,    -1,   107,
      -1,    10,    -1,    11,    -1,   232,    -1,    12,    -1,    -1,
     235,    -1,   236,   238,    -1,   115,   237,    10,   116,    -1,
      -1,    94,    -1,    24,    -1,    80,    -1,    -1,    57,    -1,
      46,    -1,    15,    -1,    16,    -1,    16,    -1,    -1,   242,
      -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   361,   361,   367,   372,   389,   389,   418,   419,   423,
     428,   435,   443,   454,   458,   466,   480,   481,   490,   493,
     502,   505,   508,   511,   515,   536,   537,   546,   555,   558,
     574,   581,   594,   602,   601,   615,   628,   629,   632,   642,
     648,   649,   652,   657,   664,   665,   669,   680,   685,   692,
     698,   704,   714,   715,   727,   730,   733,   741,   746,   753,
     759,   765,   774,   777,   787,   800,   810,   830,   836,   852,
     858,   866,   875,   886,   890,   897,   904,   912,   923,   928,
     935,   938,   946,   957,   980,   981,   984,   989,   996,  1003,
    1009,  1016,  1022,  1027,  1034,  1039,  1042,  1049,  1059,  1060,
    1064,  1071,  1081,  1091,  1102,  1112,  1123,  1133,  1144,  1156,
    1157,  1164,  1163,  1172,  1176,  1183,  1187,  1190,  1194,  1200,
    1208,  1217,  1229,  1251,  1258,  1277,  1280,  1286,  1292,  1298,
    1308,  1318,  1324,  1335,  1350,  1358,  1368,  1378,  1388,  1396,
    1418,  1426,  1435,  1439,  1444,  1453,  1457,  1461,  1468,  1488,
    1498,  1499,  1501,  1513,  1520,  1520,  1525,  1533,  1538,  1543,
    1547,  1551,  1555,  1558,  1564,  1575,  1593,  1597,  1602,  1610,
    1619,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1653,  1654,  1655,  1659,  1665,  1678,
    1679,  1683,  1687,  1688,  1689,  1690,  1691,  1695,  1696,  1697,
    1698,  1702,  1703,  1710,  1710,  1711,  1711,  1714,  1715,  1721,
    1725,  1728,  1738,  1741,  1747,  1751,  1754,  1760,  1768,  1774,
    1775,  1781,  1782,  1788,  1789,  1796,  1797,  1803,  1811,  1819,
    1825,  1831,  1838,  1846,  1854,  1863,  1866,  1872,  1877,  1888,
    1891,  1897,  1902,  1907,  1908,  1909,  1910,  1924,  1928,  1935,
    1949,  1952,  1958,  1961,  1967,  1973,  1987,  1988,  1992,  1995,
    1998,  2006,  2007,  2008,  2013,  2012,  2024,  2032,  2033,  2034,
    2035,  2038,  2041,  2050,  2065,  2071,  2077,  2091,  2102,  2118,
    2121,  2139,  2143,  2147,  2151,  2174,  2178,  2184,  2189,  2196,
    2203,  2211,  2219,  2226,  2237,  2241,  2248,  2249,  2280,  2281,
    2285,  2292,  2298,  2299,  2300,  2301,  2305,  2306,  2307,  2311,
    2315,  2323,  2330,  2331,  2337
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
     355,   356,    94,   357,   124,   358,   359,   360,   123,   125,
      40,    41,    59,    44,    58,    91,    93,    33,    46,    60,
      64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
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
     184,   184,   184,   184,   185,   184,   184,   186,   186,   186,
     186,   186,   186,   186,   187,   187,   188,   188,   188,   189,
     189,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   191,   192,   192,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     198,   198,   199,   199,   200,   200,   200,   200,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   206,   206,   207,
     207,   208,   208,   208,   208,   208,   208,   209,   209,   210,
     211,   211,   212,   212,   213,   213,   214,   214,   215,   215,
     215,   216,   216,   216,   218,   217,   219,   220,   220,   220,
     220,   221,   221,   222,   223,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   231,   231,   231,   232,   232,   233,   233,   234,   234,
     235,   236,   237,   237,   237,   237,   238,   238,   238,   239,
     239,   240,   241,   241,   242
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
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     4,     3,     4,     1,     1,     3,     5,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     4,     3,     1,
       1,     3,     3,     3,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     1,     3,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     2,     1,     2,     2,
       3,     1,     1,     3,     4,     1,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     3,     1,     3,     1,
       4,     4,     1,     1,     1,     1,     1,     1,     0,     1,
       2,     4,     0,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   309,   310,     0,     2,     3,     5,     1,     4,     7,
       0,     0,     8,   314,    15,    10,     0,    11,    13,    16,
       9,    12,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,    24,    22,    20,    23,    21,     0,    19,    14,
      52,     0,     0,    26,    36,    53,     0,    56,     0,    57,
      59,    61,     6,    40,     0,    37,    55,    54,     0,     0,
      39,     0,    41,    42,     0,    47,    49,    51,   189,     0,
     190,   191,   192,   193,   194,   202,   195,   196,   197,   198,
     199,   200,   201,    27,    28,    32,    30,    31,    35,     0,
     298,    58,    60,    38,    43,     0,     0,     0,    33,    29,
     298,   134,   311,     0,   171,     0,     0,   185,   178,   182,
     184,   172,     0,     0,   173,   177,   181,     0,     0,    65,
     187,   174,    64,   183,   138,   302,     0,   123,   299,   306,
      44,    48,    50,    34,     0,    68,    67,     0,   186,   180,
     179,   176,   175,     0,    71,     0,   174,    73,     0,   298,
       0,   188,     0,   304,   305,   303,     0,     0,     0,   207,
     308,   307,   300,    45,    46,     0,   135,   137,     0,     0,
       0,     0,     0,    63,   159,   166,   160,   294,   295,   167,
     168,   157,   158,     0,    83,     0,    78,    80,    81,   162,
     163,    82,   293,   285,     0,   287,   292,   289,   143,   144,
     139,   140,   142,   136,     0,   156,   154,   149,   150,   151,
       0,   164,   131,     0,     0,   207,   207,   125,   124,     0,
       0,   122,   208,   209,   210,   298,   298,     0,   100,   298,
      72,    77,    76,    75,    74,   247,   248,   297,     0,     0,
     298,   241,   240,     0,     0,   239,   242,     0,   214,     0,
       0,   244,     0,   215,   219,   221,   223,   225,   236,     0,
     229,   245,   230,   235,   218,   261,   263,   262,   271,   272,
     296,   243,   249,   246,   161,    66,   298,   286,     0,     0,
       0,   301,     0,     0,     0,     0,     0,   298,     0,   298,
       0,   298,     0,     0,     0,     0,   148,   145,     0,   283,
     281,   281,   281,   102,   282,    98,   281,   281,   109,     0,
      70,    69,     0,     0,   266,   267,     0,     0,   237,   238,
       0,     0,     0,     0,    62,     0,   203,   204,     0,   205,
     206,     0,     0,     0,     0,     0,    79,   288,     0,     0,
     164,   141,   152,   169,   155,   165,   153,     0,   119,     0,
      92,    95,    96,   298,   133,     0,     0,    85,    86,    91,
     281,   298,   312,     0,   312,     0,   212,     0,   284,   107,
       0,   106,   108,    99,   281,   104,   105,     0,    97,   110,
     101,   220,   264,   268,   269,   234,   232,   250,     0,   273,
     228,   216,   222,   224,   226,     0,   233,   231,     0,     0,
     275,   291,   290,   170,   132,     0,   126,   298,    94,   298,
     127,   298,    89,   281,   298,   313,   128,   298,   211,   213,
     146,   147,   103,     0,     0,   270,   254,     0,   252,   207,
       0,   227,     0,   277,   279,   274,     0,   120,   121,    93,
      90,    87,    88,   123,   123,   111,   265,   251,     0,   256,
     217,   278,     0,   276,   129,   130,     0,   253,   259,   260,
     258,   255,   257,   280,   115,   116,     0,     0,   113,   117,
       0,   112,   114,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     9,    11,    12,    16,    17,    28,
      29,    30,    42,    43,    83,    84,   133,    54,    55,    61,
      62,   164,    63,    64,    65,    44,    45,    48,    49,   184,
      85,   118,    86,   143,   144,   185,   186,   356,   357,   358,
     349,   350,   135,   374,   227,   228,   378,   379,   456,   467,
     468,   359,   360,   158,   159,   218,   119,   200,   201,   469,
     301,   302,    87,   207,   283,   208,   209,   251,   344,   120,
     121,   122,   123,   328,   331,   221,   222,   223,   224,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   427,   428,   461,   462,   264,   265,   424,   266,   317,
     267,   268,   269,   399,   400,   433,   303,   304,   151,   194,
     195,   270,   271,   127,   128,   129,   156,   162,   272,   124,
     414,   273
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -292
static const yytype_int16 yypact[] =
{
     267,  -292,  -292,    23,   267,  -292,  -292,  -292,  -292,   -20,
      24,    72,  -292,  -292,  -292,  -292,    40,  -292,   -50,   163,
    -292,  -292,    96,   118,   128,   137,   180,   141,   151,   163,
    -292,   136,  -292,  -292,  -292,  -292,  -292,   239,  -292,  -292,
     171,    78,   227,  -292,   214,  -292,   175,  -292,   172,  -292,
     186,  -292,  -292,   168,   571,  -292,  -292,  -292,   216,   194,
    -292,   202,   216,  -292,    -4,  -292,   211,  -292,  -292,   311,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   571,  -292,  -292,  -292,  -292,  -292,   294,
     217,  -292,  -292,  -292,  -292,   267,   216,   219,  -292,  -292,
     -17,   215,  -292,   243,  -292,   248,   262,  -292,  -292,  -292,
    -292,  -292,   275,   254,  -292,  -292,  -292,   756,   338,   234,
    -292,   236,  -292,  -292,   232,     5,   348,  -292,  -292,   155,
     -20,  -292,  -292,  -292,   251,  -292,  -292,   216,  -292,  -292,
    -292,  -292,  -292,   -48,  -292,   242,  -292,   246,   253,   106,
      80,  -292,   226,  -292,  -292,  -292,   343,   522,   680,   -46,
    -292,  -292,  -292,  -292,  -292,   272,  -292,  -292,   364,   756,
     216,   216,   449,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   403,  -292,    -5,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,    89,  -292,  -292,   258,  -292,  -292,
     252,  -292,  -292,  -292,   256,  -292,    65,  -292,  -292,  -292,
     259,   260,   329,   263,   306,    84,   100,  -292,  -292,   270,
     449,  -292,  -292,  -292,   271,   189,    19,    94,  -292,   -17,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,   282,   355,
     217,  -292,  -292,    76,   255,  -292,  -292,   257,  -292,   267,
     449,  -292,   277,   274,   196,   203,  -292,   293,  -292,   286,
      76,  -292,  -292,  -292,  -292,  -292,  -292,  -292,   291,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,   106,  -292,    92,   213,
     290,  -292,    67,   393,   391,   522,   373,    37,   297,    21,
     331,    21,   332,   449,   296,   449,  -292,  -292,   522,  -292,
     117,   -23,   117,  -292,  -292,   315,   -23,   117,   320,   272,
    -292,  -292,   554,   313,  -292,   304,   318,   665,  -292,  -292,
     316,   319,   321,   317,  -292,   322,  -292,  -292,   554,  -292,
    -292,   554,   554,   449,   674,   312,  -292,  -292,   323,   324,
    -292,  -292,  -292,  -292,   426,  -292,  -292,   391,   326,   124,
    -292,  -292,  -292,   217,  -292,   360,   327,   328,  -292,  -292,
     117,   217,   391,   335,   391,   334,  -292,   336,  -292,  -292,
     298,  -292,  -292,  -292,   117,  -292,  -292,   350,  -292,  -292,
    -292,  -292,  -292,  -292,   330,  -292,  -292,   271,    74,  -292,
    -292,   333,   203,  -292,  -292,   337,  -292,  -292,     3,   126,
    -292,  -292,  -292,  -292,  -292,   213,  -292,    37,  -292,   217,
    -292,    44,  -292,   117,   217,  -292,  -292,   217,  -292,  -292,
    -292,  -292,  -292,   342,   393,  -292,  -292,   127,  -292,   -46,
     245,  -292,   391,   349,  -292,  -292,   312,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,   426,  -292,    74,    48,
    -292,   349,   391,  -292,  -292,  -292,    63,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,    63,    53,  -292,  -292,
       9,  -292,  -292,  -292
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -292,  -292,  -292,   447,  -292,  -292,   340,   266,    -6,  -292,
    -292,   423,  -292,  -292,  -292,   383,  -292,  -292,  -292,  -292,
    -292,  -292,   406,  -292,   377,  -292,  -292,  -292,   416,   339,
    -292,   325,  -292,  -292,   307,  -292,   199,   188,  -292,    66,
    -292,    73,   261,  -292,  -292,   173,  -292,  -292,  -292,    15,
    -222,  -278,   -83,  -292,  -126,  -292,   201,  -292,   204,  -148,
     265,   269,  -292,   -85,  -292,  -141,  -268,  -135,    68,   -59,
       6,  -292,   -14,  -292,  -292,  -213,  -292,  -292,   176,  -188,
      71,  -292,   165,   166,  -291,  -292,  -292,  -169,  -292,  -292,
    -292,  -292,    50,  -292,  -292,  -292,  -292,  -292,  -292,   244,
    -292,  -292,  -292,  -292,    69,    70,  -282,  -292,  -292,  -292,
     228,  -112,  -292,  -168,  -292,  -292,  -292,  -292,     1,  -292,
     143,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -282
static const yytype_int16 yytable[] =
{
      18,     6,   290,   292,   202,     6,    18,   126,   188,   351,
      21,   338,    13,   464,   189,   298,   134,   136,   369,   371,
     372,   381,   189,     7,   375,   376,   198,   199,   465,   153,
      13,    51,   294,    13,    14,   296,   297,   190,   196,   219,
      88,   394,    50,    67,    90,   190,    13,    95,    51,    13,
      14,   299,    67,    13,    66,    89,   355,   464,   145,    50,
      22,   168,   323,    66,   220,   169,   187,   464,   458,    88,
     198,   199,   465,    90,    13,    14,    13,    14,   412,   355,
     198,   199,   465,    13,    89,   154,    67,    13,    10,    13,
     177,   178,   422,     1,     2,   370,   130,    66,   125,   155,
      46,    13,   177,   178,   275,   365,    31,   367,   276,    96,
     145,    19,   174,   175,   176,    13,   177,   178,   147,   179,
     180,   432,   459,   146,   466,   473,   460,   167,   348,   351,
     -84,   442,   202,    15,   125,   188,   125,   437,   166,   191,
     197,   189,   300,   305,   348,   395,   311,   211,   386,    20,
     189,   348,   125,   203,    37,   298,   181,   314,   210,   125,
     232,   234,   471,   189,   190,   397,   196,   339,   466,   219,
     147,   231,   233,   190,   274,   146,   342,    13,   466,    23,
      32,   426,   315,     1,     2,   219,   190,   192,    24,   193,
      47,   299,   289,   187,   220,   316,    18,   182,   277,   192,
     346,   160,   278,   308,   352,   296,   297,   309,   291,    25,
     220,    26,   161,   368,   183,   -25,   449,    33,    41,    60,
      27,   125,    13,   177,   178,    13,    34,   298,     1,     2,
      36,     1,     2,   406,   319,   435,   447,   407,    35,   436,
     448,     1,     2,   198,   199,   472,   443,    39,   472,   444,
     322,   235,   175,   236,    13,   177,   178,   237,   179,   180,
       1,     2,   318,   299,    13,    40,   191,   238,   197,   340,
     408,    52,    18,    53,   345,   211,    21,   353,   413,   361,
     210,   361,     1,     2,    57,    58,   210,    56,   211,   225,
     226,   320,   321,   438,    59,   241,   242,   100,  -281,   210,
     326,   327,  -281,    92,   125,   329,   330,   198,   199,   101,
     102,   243,   101,   102,    93,   420,   421,   454,   455,    97,
     244,   103,    68,   104,   352,   105,   440,    98,   132,   138,
     245,   141,   125,   137,   139,   106,   246,   404,   140,   107,
     142,   148,   149,   108,   150,   247,   109,    70,    71,    72,
     152,   157,   415,   204,   415,   250,   170,   110,    73,   165,
     171,   172,   111,    74,   112,    75,   113,   229,   279,   286,
     280,   287,   281,    76,   285,   114,   115,   284,   429,   288,
     293,   295,    77,   312,    78,   313,   324,   325,   434,    79,
     116,    80,    81,    82,   332,   340,   333,   353,   343,   335,
      13,   361,   117,   347,   362,   364,   210,   366,   373,   235,
     175,   236,    13,   177,   178,   237,   179,   180,     1,     2,
     377,   382,   434,   383,   384,   238,   220,   388,   390,   391,
     389,   403,   398,   409,   401,   402,   410,   423,   429,   239,
     240,   411,   463,   405,   416,   418,   430,   419,   431,   425,
     445,     8,    38,   241,   242,   235,   175,   236,    13,   177,
     178,   237,   179,   180,     1,     2,    99,   452,    94,   243,
     163,   238,   282,   131,    91,   336,   230,   441,   244,   363,
     439,   470,   380,   217,   341,   239,   240,   173,   245,   354,
     310,   306,   446,   392,   246,   307,   387,   393,   457,   241,
     242,   450,   451,   247,   334,   453,   337,   417,     0,     0,
     248,   249,   274,   250,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,   174,   175,
     176,    13,   177,   178,   245,   179,   180,     1,     2,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,   247,
       0,     0,     0,     0,     0,     0,   248,   249,     0,   250,
     235,   175,   236,    13,   177,   178,   237,   179,   180,     1,
       2,     0,   181,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     1,     2,     0,     0,
     205,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   182,    69,     0,     0,     0,     0,     0,
     243,     0,     0,     0,    70,    71,    72,     0,     0,   244,
     206,     0,     0,     0,     0,    73,     0,     0,     0,   245,
      74,     0,    75,     0,     0,   246,     0,     0,     0,     0,
      76,     0,     0,     0,   247,     0,     0,     0,     0,    77,
       0,    78,     0,     0,   250,     0,    79,     0,    80,    81,
      82,   235,   175,   236,    13,   177,   178,   237,   179,   180,
     235,   175,   236,    13,   177,   178,   237,   179,   180,     0,
       0,     0,     0,     0,     0,   101,   102,     0,     0,     0,
       0,     0,     0,   212,     0,     0,     0,   103,    68,   104,
       0,   105,   213,     0,     0,   241,     0,     0,     0,     0,
       0,   106,     0,     0,   241,   107,     0,     0,     0,   108,
     385,     0,   109,    70,    71,    72,     0,     0,     0,   396,
       0,   214,     0,   110,    73,     0,     0,     0,   111,    74,
     112,    75,   113,     0,     0,     0,   246,     0,     0,    76,
       0,   114,   115,   215,   216,   246,     0,     0,    77,     0,
      78,     1,     2,     0,     0,    79,   116,    80,    81,    82,
       0,     0,     0,   103,    68,   104,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
       0,   107,     0,     0,     0,   108,     0,     0,   109,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,   110,
      73,     0,     0,     0,   111,    74,   112,    75,   113,     0,
       0,     0,     0,     0,     0,    76,     0,   114,   115,     0,
       0,     0,     0,     0,    77,     0,    78,     0,     0,     0,
       0,    79,   116,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      10,     0,   215,   216,   152,     4,    16,    90,   149,   287,
      16,   279,     9,     4,   149,    38,    33,   100,   300,   301,
     302,   312,   157,     0,   306,   307,    17,    18,    19,    24,
       9,    41,   220,     9,    10,    16,    17,   149,   150,    85,
      54,   332,    41,    53,    54,   157,     9,    51,    58,     9,
      10,    74,    62,     9,    53,    54,    35,     4,   117,    58,
     110,   109,   250,    62,   110,   113,   149,     4,    20,    83,
      17,    18,    19,    83,     9,    10,     9,    10,   360,    35,
      17,    18,    19,     9,    83,    80,    96,     9,   108,     9,
      10,    11,   374,    15,    16,   118,    95,    96,   115,    94,
      22,     9,    10,    11,   109,   293,    10,   295,   113,   113,
     169,    39,     6,     7,     8,     9,    10,    11,   117,    13,
      14,   118,    74,   117,   115,   116,    78,   137,   107,   407,
     109,   413,   280,   109,   115,   276,   115,   405,   137,   149,
     150,   276,   225,   226,   107,   333,   229,   157,   317,   109,
     285,   107,   115,   152,     3,    38,    50,   240,   157,   115,
     170,   171,   109,   298,   276,   334,   278,   279,   115,    85,
     169,   170,   171,   285,   109,   169,   109,     9,   115,    16,
      62,   107,   106,    15,    16,    85,   298,   107,    25,   109,
     112,    74,   108,   276,   110,   119,   206,    91,   109,   107,
     285,    46,   113,   109,   287,    16,    17,   113,   108,    46,
     110,    48,    57,   298,   108,    44,   429,    89,    47,    51,
      57,   115,     9,    10,    11,     9,    89,    38,    15,    16,
      89,    15,    16,   109,   244,   109,   109,   113,    58,   113,
     113,    15,    16,    17,    18,   467,   414,   111,   470,   417,
     249,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     7,    74,     9,    26,   276,    22,   278,   279,
     353,    44,   282,    59,   284,   285,   282,   287,   361,   289,
     279,   291,    15,    16,   112,   113,   285,   112,   298,    17,
      18,    34,    35,   405,   108,    50,    51,     3,   109,   298,
     104,   105,   113,   109,   115,   102,   103,    17,    18,    15,
      16,    66,    15,    16,   112,    17,    18,   443,   444,   108,
      75,    27,    28,    29,   407,    31,   409,    16,   109,    86,
      85,    56,   115,   118,    86,    41,    91,   347,    76,    45,
      86,     3,   108,    49,   108,   100,    52,    53,    54,    55,
     118,     3,   362,    10,   364,   110,   114,    63,    64,   108,
     114,   108,    68,    69,    70,    71,    72,     3,   110,    40,
     118,   108,   116,    79,   114,    81,    82,   118,   388,    73,
     110,   110,    88,   101,    90,    30,   109,   113,   398,    95,
      96,    97,    98,    99,   101,   405,   110,   407,     5,   108,
       9,   411,   108,    30,    73,    73,   405,   111,    93,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     100,   108,   432,   119,   106,    22,   110,   108,   111,   107,
     109,     5,   120,    73,   111,   111,   109,    87,   448,    36,
      37,   113,   452,   117,   109,   111,   113,   111,   111,   119,
     108,     4,    29,    50,    51,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    83,   118,    62,    66,
     130,    22,   206,    96,    58,   276,   169,   411,    75,   291,
     407,   466,   309,   158,   280,    36,    37,   148,    85,   288,
     229,   226,   424,   328,    91,   226,   320,   331,   448,    50,
      51,   430,   432,   100,   260,   436,   278,   364,    -1,    -1,
     107,   108,   109,   110,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    85,    13,    14,    15,    16,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,    -1,   110,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    43,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    75,
     108,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    85,
      69,    -1,    71,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    88,
      -1,    90,    -1,    -1,   110,    -1,    95,    -1,    97,    98,
      99,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    50,    45,    -1,    -1,    -1,    49,
      65,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    65,
      -1,    61,    -1,    63,    64,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    91,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    91,    -1,    -1,    88,    -1,
      90,    15,    16,    -1,    -1,    95,    96,    97,    98,    99,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    90,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,   122,   123,   124,   239,     0,   124,   125,
     108,   126,   127,     9,    10,   109,   128,   129,   242,    39,
     109,   129,   110,    16,    25,    46,    48,    57,   130,   131,
     132,    10,    62,    89,    89,    58,    89,     3,   132,   111,
      26,    47,   133,   134,   146,   147,    22,   112,   148,   149,
     239,   242,    44,    59,   138,   139,   112,   112,   113,   108,
      51,   140,   141,   143,   144,   145,   239,   242,    28,    43,
      53,    54,    55,    64,    69,    71,    79,    88,    90,    95,
      97,    98,    99,   135,   136,   151,   153,   183,   193,   239,
     242,   149,   109,   112,   143,    51,   113,   108,    16,   136,
       3,    15,    16,    27,    29,    31,    41,    45,    49,    52,
      63,    68,    70,    72,    81,    82,    96,   108,   152,   177,
     190,   191,   192,   193,   240,   115,   173,   234,   235,   236,
     239,   145,   109,   137,    33,   163,   173,   118,    86,    86,
      76,    56,    86,   154,   155,   190,   191,   239,     3,   108,
     108,   229,   118,    24,    80,    94,   237,     3,   174,   175,
      46,    57,   238,   127,   142,   108,   239,   242,   109,   113,
     114,   114,   108,   150,     6,     7,     8,    10,    11,    13,
      14,    50,    91,   108,   150,   156,   157,   173,   186,   188,
     232,   242,   107,   109,   230,   231,   232,   242,    17,    18,
     178,   179,   180,   239,    10,    68,   108,   184,   186,   187,
     239,   242,    23,    32,    61,    83,    84,   152,   176,    85,
     110,   196,   197,   198,   199,    17,    18,   165,   166,     3,
     155,   239,   242,   239,   242,     6,     8,    12,    22,    36,
      37,    50,    51,    66,    75,    85,    91,   100,   107,   108,
     110,   188,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   216,   217,   219,   221,   222,   223,
     232,   233,   239,   242,   109,   109,   113,   109,   113,   110,
     118,   116,   128,   185,   118,   114,    40,   108,    73,   108,
     196,   108,   196,   110,   200,   110,    16,    17,    38,    74,
     173,   181,   182,   227,   228,   173,   181,   182,   109,   113,
     163,   173,   101,    30,   173,   106,   119,   220,     7,   242,
      34,    35,   239,   200,   109,   113,   104,   105,   194,   102,
     103,   195,   101,   110,   220,   108,   157,   231,   187,   232,
     242,   179,   109,     5,   189,   242,   184,    30,   107,   161,
     162,   172,   173,   242,   177,    35,   158,   159,   160,   172,
     173,   242,    73,   158,    73,   200,   111,   200,   184,   227,
     118,   227,   227,    93,   164,   227,   227,   100,   167,   168,
     166,   205,   108,   119,   106,    65,   208,   199,   108,   109,
     111,   107,   203,   204,   205,   200,    65,   208,   120,   224,
     225,   111,   111,     5,   242,   117,   109,   113,   173,    73,
     109,   113,   227,   173,   241,   242,   109,   241,   111,   111,
      17,    18,   227,    87,   218,   119,   107,   212,   213,   242,
     113,   111,   118,   226,   242,   109,   113,   187,   232,   162,
     173,   160,   227,   234,   234,   108,   189,   109,   113,   196,
     201,   226,   118,   225,   175,   175,   169,   213,    20,    74,
      78,   214,   215,   242,     4,    19,   115,   170,   171,   180,
     170,   109,   171,   116
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
#line 361 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 3:
#line 367 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 4:
#line 372 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 5:
#line 389 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 6:
#line 394 "asn1p_y.y"
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
#line 418 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 8:
#line 419 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 9:
#line 423 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 10:
#line 428 "asn1p_y.y"
    {
printf("found a possible empty body with %p\n", &((yyval.a_oid)));
		(yyval.a_oid) = 0;
	}
    break;

  case 11:
#line 435 "asn1p_y.y"
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
#line 443 "asn1p_y.y"
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
#line 454 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = 0;
	}
    break;

  case 14:
#line 458 "asn1p_y.y"
    {		/* iso(1) */
		{
			struct {asn1c_integer_t a; char *b;} *pid = &((yyvsp[(3) - (4)].a_int));
			printf("ObjectIdentifierElement: %s( %i %s)\n", ((yyvsp[(1) - (4)].tv_str)), (int)((yyvsp[(3) - (4)].a_int)), pid->b);
			(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
			(yyval.a_oid_arc).number = pid->b;
		}
	}
    break;

  case 15:
#line 466 "asn1p_y.y"
    {					/* 1 */
		{
			struct {asn1c_integer_t a; char *b;} *pid = &((yyvsp[(1) - (1)].a_int));
			printf("ObjectIdentifierElement: %i %s\n", (int)((yyvsp[(1) - (1)].a_int)), pid->b);
			(yyval.a_oid_arc).name = 0;
			(yyval.a_oid_arc).number = pid->b;
		}
	}
    break;

  case 16:
#line 480 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 17:
#line 481 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 18:
#line 490 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 493 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 20:
#line 502 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 21:
#line 505 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 22:
#line 508 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 23:
#line 511 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 24:
#line 515 "asn1p_y.y"
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
#line 536 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 26:
#line 537 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 27:
#line 546 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[(1) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[(2) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), members, (yyvsp[(3) - (3)].a_module), next);
	}
    break;

  case 28:
#line 555 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 29:
#line 558 "asn1p_y.y"
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
#line 574 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 31:
#line 581 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 32:
#line 594 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 33:
#line 602 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 34:
#line 603 "asn1p_y.y"
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
#line 615 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 36:
#line 628 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 38:
#line 632 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 39:
#line 642 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 40:
#line 648 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 42:
#line 652 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 43:
#line 657 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 44:
#line 664 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 45:
#line 665 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 46:
#line 669 "asn1p_y.y"
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
#line 680 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 48:
#line 685 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 49:
#line 692 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 50:
#line 698 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 704 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 714 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 53:
#line 715 "asn1p_y.y"
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
#line 727 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 55:
#line 730 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 56:
#line 733 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 57:
#line 741 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 58:
#line 746 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 59:
#line 753 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 60:
#line 759 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 765 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 774 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 63:
#line 777 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 64:
#line 787 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 65:
#line 800 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 66:
#line 810 "asn1p_y.y"
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
#line 830 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 68:
#line 836 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 69:
#line 852 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 70:
#line 858 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 866 "asn1p_y.y"
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
#line 875 "asn1p_y.y"
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
#line 886 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 74:
#line 890 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 75:
#line 897 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 76:
#line 904 "asn1p_y.y"
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
#line 912 "asn1p_y.y"
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
#line 923 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 79:
#line 928 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 80:
#line 935 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 81:
#line 938 "asn1p_y.y"
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
#line 946 "asn1p_y.y"
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
#line 957 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 84:
#line 980 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 85:
#line 981 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 86:
#line 984 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 87:
#line 989 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 88:
#line 996 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 89:
#line 1003 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 90:
#line 1009 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 91:
#line 1016 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 92:
#line 1022 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 93:
#line 1027 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 94:
#line 1034 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 95:
#line 1039 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 96:
#line 1042 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 97:
#line 1049 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 98:
#line 1059 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 99:
#line 1060 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 100:
#line 1064 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 101:
#line 1071 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 102:
#line 1081 "asn1p_y.y"
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
#line 1091 "asn1p_y.y"
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
#line 1102 "asn1p_y.y"
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
#line 1112 "asn1p_y.y"
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
#line 1123 "asn1p_y.y"
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
#line 1133 "asn1p_y.y"
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
#line 1144 "asn1p_y.y"
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
#line 1156 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 110:
#line 1157 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 111:
#line 1164 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 112:
#line 1166 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 113:
#line 1172 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 114:
#line 1176 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 115:
#line 1183 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 116:
#line 1187 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 117:
#line 1190 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 118:
#line 1194 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 119:
#line 1200 "asn1p_y.y"
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
#line 1208 "asn1p_y.y"
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
#line 1217 "asn1p_y.y"
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
#line 1229 "asn1p_y.y"
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
#line 1251 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 124:
#line 1258 "asn1p_y.y"
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
#line 1277 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 126:
#line 1280 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 127:
#line 1286 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 128:
#line 1292 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1298 "asn1p_y.y"
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
#line 1308 "asn1p_y.y"
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
#line 1318 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 132:
#line 1324 "asn1p_y.y"
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
#line 1335 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1350 "asn1p_y.y"
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
#line 1358 "asn1p_y.y"
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
#line 1368 "asn1p_y.y"
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
#line 1378 "asn1p_y.y"
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
#line 1388 "asn1p_y.y"
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
#line 1396 "asn1p_y.y"
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
#line 1418 "asn1p_y.y"
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
#line 1426 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 143:
#line 1439 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 144:
#line 1444 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 145:
#line 1453 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
	}
    break;

  case 146:
#line 1457 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
	}
    break;

  case 147:
#line 1461 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
	}
    break;

  case 148:
#line 1468 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
	}
    break;

  case 149:
#line 1488 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 152:
#line 1501 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		printf("!!! Value pointer: %p and OID pointer: %p\n", ((yyval.a_value)), ((yyvsp[(2) - (3)].a_oid)));
		/* $$->value.oid = asn1p_oid_construct(($1)); */
		(yyval.a_value)->type = ATV_NULL;
		(yyval.a_value)->type = ATV_OBJECT_IDENTIFIER;
		assert((yyvsp[(2) - (3)].a_oid));
		if (((yyvsp[(2) - (3)].a_oid))) {
			(yyval.a_value)->value.oid = asn1p_oid_construct(((yyvsp[(2) - (3)].a_oid))->arcs, ((yyvsp[(2) - (3)].a_oid))->arcs_count);
		}
	}
    break;

  case 153:
#line 1513 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 154:
#line 1520 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 155:
#line 1520 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 156:
#line 1525 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 157:
#line 1533 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 158:
#line 1538 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 159:
#line 1543 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
	}
    break;

  case 160:
#line 1547 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
	}
    break;

  case 161:
#line 1551 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		(yyval.a_value)->type = ATV_EMPTY;
	}
    break;

  case 162:
#line 1555 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 163:
#line 1558 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 164:
#line 1564 "asn1p_y.y"
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

  case 165:
#line 1575 "asn1p_y.y"
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

  case 166:
#line 1593 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 167:
#line 1597 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 168:
#line 1602 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 169:
#line 1610 "asn1p_y.y"
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

  case 170:
#line 1619 "asn1p_y.y"
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

  case 171:
#line 1634 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 172:
#line 1635 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 173:
#line 1636 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 174:
#line 1637 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 175:
#line 1638 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 176:
#line 1639 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 177:
#line 1640 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 178:
#line 1641 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 179:
#line 1642 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 180:
#line 1643 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 181:
#line 1644 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 182:
#line 1645 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 183:
#line 1646 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 184:
#line 1653 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 185:
#line 1654 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 186:
#line 1655 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 187:
#line 1659 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 188:
#line 1665 "asn1p_y.y"
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

  case 189:
#line 1678 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 190:
#line 1679 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 191:
#line 1683 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 192:
#line 1687 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 193:
#line 1688 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 194:
#line 1689 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 195:
#line 1690 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 196:
#line 1691 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 197:
#line 1695 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 198:
#line 1696 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 199:
#line 1697 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 200:
#line 1698 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 201:
#line 1702 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 202:
#line 1703 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 207:
#line 1714 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 208:
#line 1715 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 210:
#line 1725 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (1)].a_constr), 0);
	}
    break;

  case 211:
#line 1728 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(3) - (4)].a_constr), 0);
	}
    break;

  case 212:
#line 1738 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(2) - (3)].a_constr);
	}
    break;

  case 213:
#line 1741 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 214:
#line 1747 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 215:
#line 1751 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 216:
#line 1754 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 217:
#line 1760 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
		ct = (yyval.a_constr);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
	}
    break;

  case 218:
#line 1768 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 220:
#line 1775 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 222:
#line 1782 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 224:
#line 1789 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 226:
#line 1797 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 227:
#line 1803 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(1) - (4)].a_ctype);
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (4)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 228:
#line 1811 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CA_SET;
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 229:
#line 1819 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 230:
#line 1825 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 231:
#line 1831 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 232:
#line 1838 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
		(yyval.a_constr)->range_start->type = ATV_MIN;
	}
    break;

  case 233:
#line 1846 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 234:
#line 1854 "asn1p_y.y"
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

  case 235:
#line 1863 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 236:
#line 1866 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 237:
#line 1872 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 238:
#line 1877 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno);
		asn1p_ref_add_component(ref, (yyvsp[(2) - (2)].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 239:
#line 1888 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_SIZE;
	}
    break;

  case 240:
#line 1891 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_FROM;
	}
    break;

  case 241:
#line 1897 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 242:
#line 1902 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 246:
#line 1910 "asn1p_y.y"
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

  case 247:
#line 1924 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
	}
    break;

  case 248:
#line 1928 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
	}
    break;

  case 249:
#line 1935 "asn1p_y.y"
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

  case 250:
#line 1949 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 251:
#line 1952 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(4) - (5)].a_constr), 0);
	}
    break;

  case 252:
#line 1958 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 253:
#line 1961 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 254:
#line 1967 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_EXT;
		(yyval.a_constr)->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 255:
#line 1973 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(1) - (3)].tv_str), strlen((yyvsp[(1) - (3)].tv_str)), 0);
		(yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
		if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
	}
    break;

  case 256:
#line 1987 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 257:
#line 1988 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 258:
#line 1992 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 259:
#line 1995 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 260:
#line 1998 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 264:
#line 2013 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 265:
#line 2013 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 266:
#line 2024 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 267:
#line 2032 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 268:
#line 2033 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 269:
#line 2034 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 270:
#line 2035 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 271:
#line 2038 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 272:
#line 2041 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 273:
#line 2050 "asn1p_y.y"
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

  case 274:
#line 2065 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 275:
#line 2071 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 276:
#line 2077 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 277:
#line 2091 "asn1p_y.y"
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

  case 278:
#line 2102 "asn1p_y.y"
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

  case 279:
#line 2118 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 280:
#line 2121 "asn1p_y.y"
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

  case 281:
#line 2139 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 282:
#line 2143 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 283:
#line 2147 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 284:
#line 2151 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 285:
#line 2174 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
	}
    break;

  case 286:
#line 2178 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
	}
    break;

  case 287:
#line 2184 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 288:
#line 2189 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 289:
#line 2196 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 290:
#line 2203 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 291:
#line 2211 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 292:
#line 2219 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 293:
#line 2226 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 294:
#line 2237 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 295:
#line 2241 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 297:
#line 2249 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 298:
#line 2280 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 299:
#line 2281 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 300:
#line 2285 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 301:
#line 2292 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 302:
#line 2298 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 303:
#line 2299 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 304:
#line 2300 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 305:
#line 2301 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 306:
#line 2305 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 307:
#line 2306 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 308:
#line 2307 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 309:
#line 2311 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 310:
#line 2315 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 311:
#line 2323 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 312:
#line 2330 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 313:
#line 2331 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 314:
#line 2337 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4841 "asn1p_y.c"
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


#line 2343 "asn1p_y.y"



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


