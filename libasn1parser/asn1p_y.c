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
     TOK_VBracketLeft = 259,
     TOK_VBracketRight = 260,
     TOK_whitespace = 261,
     TOK_opaque = 262,
     TOK_bstring = 263,
     TOK_cstring = 264,
     TOK_hstring = 265,
     TOK_identifier = 266,
     TOK_number = 267,
     TOK_number_negative = 268,
     TOK_realnumber = 269,
     TOK_tuple = 270,
     TOK_quadruple = 271,
     TOK_typereference = 272,
     TOK_capitalreference = 273,
     TOK_typefieldreference = 274,
     TOK_valuefieldreference = 275,
     TOK_Literal = 276,
     TOK_ABSENT = 277,
     TOK_ABSTRACT_SYNTAX = 278,
     TOK_ALL = 279,
     TOK_ANY = 280,
     TOK_APPLICATION = 281,
     TOK_AUTOMATIC = 282,
     TOK_BEGIN = 283,
     TOK_BIT = 284,
     TOK_BMPString = 285,
     TOK_BOOLEAN = 286,
     TOK_BY = 287,
     TOK_CHARACTER = 288,
     TOK_CHOICE = 289,
     TOK_CLASS = 290,
     TOK_COMPONENT = 291,
     TOK_COMPONENTS = 292,
     TOK_CONSTRAINED = 293,
     TOK_CONTAINING = 294,
     TOK_DEFAULT = 295,
     TOK_DEFINITIONS = 296,
     TOK_DEFINED = 297,
     TOK_EMBEDDED = 298,
     TOK_ENCODED = 299,
     TOK_ENCODING_CONTROL = 300,
     TOK_END = 301,
     TOK_ENUMERATED = 302,
     TOK_EXPLICIT = 303,
     TOK_EXPORTS = 304,
     TOK_EXTENSIBILITY = 305,
     TOK_EXTERNAL = 306,
     TOK_FALSE = 307,
     TOK_FROM = 308,
     TOK_GeneralizedTime = 309,
     TOK_GeneralString = 310,
     TOK_GraphicString = 311,
     TOK_IA5String = 312,
     TOK_IDENTIFIER = 313,
     TOK_IMPLICIT = 314,
     TOK_IMPLIED = 315,
     TOK_IMPORTS = 316,
     TOK_INCLUDES = 317,
     TOK_INSTANCE = 318,
     TOK_INSTRUCTIONS = 319,
     TOK_INTEGER = 320,
     TOK_ISO646String = 321,
     TOK_MAX = 322,
     TOK_MIN = 323,
     TOK_MINUS_INFINITY = 324,
     TOK_NULL = 325,
     TOK_NumericString = 326,
     TOK_OBJECT = 327,
     TOK_ObjectDescriptor = 328,
     TOK_OCTET = 329,
     TOK_OF = 330,
     TOK_OPTIONAL = 331,
     TOK_PATTERN = 332,
     TOK_PDV = 333,
     TOK_PLUS_INFINITY = 334,
     TOK_PRESENT = 335,
     TOK_PrintableString = 336,
     TOK_PRIVATE = 337,
     TOK_REAL = 338,
     TOK_RELATIVE_OID = 339,
     TOK_SEQUENCE = 340,
     TOK_SET = 341,
     TOK_SIZE = 342,
     TOK_STRING = 343,
     TOK_SYNTAX = 344,
     TOK_T61String = 345,
     TOK_TAGS = 346,
     TOK_TeletexString = 347,
     TOK_TRUE = 348,
     TOK_TYPE_IDENTIFIER = 349,
     TOK_UNIQUE = 350,
     TOK_UNIVERSAL = 351,
     TOK_UniversalString = 352,
     TOK_UTCTime = 353,
     TOK_UTF8String = 354,
     TOK_VideotexString = 355,
     TOK_VisibleString = 356,
     TOK_WITH = 357,
     UTF8_BOM = 358,
     TOK_EXCEPT = 359,
     TOK_INTERSECTION = 360,
     TOK_UNION = 361,
     TOK_TwoDots = 362,
     TOK_ThreeDots = 363
   };
#endif
/* Tokens.  */
#define TOK_PPEQ 258
#define TOK_VBracketLeft 259
#define TOK_VBracketRight 260
#define TOK_whitespace 261
#define TOK_opaque 262
#define TOK_bstring 263
#define TOK_cstring 264
#define TOK_hstring 265
#define TOK_identifier 266
#define TOK_number 267
#define TOK_number_negative 268
#define TOK_realnumber 269
#define TOK_tuple 270
#define TOK_quadruple 271
#define TOK_typereference 272
#define TOK_capitalreference 273
#define TOK_typefieldreference 274
#define TOK_valuefieldreference 275
#define TOK_Literal 276
#define TOK_ABSENT 277
#define TOK_ABSTRACT_SYNTAX 278
#define TOK_ALL 279
#define TOK_ANY 280
#define TOK_APPLICATION 281
#define TOK_AUTOMATIC 282
#define TOK_BEGIN 283
#define TOK_BIT 284
#define TOK_BMPString 285
#define TOK_BOOLEAN 286
#define TOK_BY 287
#define TOK_CHARACTER 288
#define TOK_CHOICE 289
#define TOK_CLASS 290
#define TOK_COMPONENT 291
#define TOK_COMPONENTS 292
#define TOK_CONSTRAINED 293
#define TOK_CONTAINING 294
#define TOK_DEFAULT 295
#define TOK_DEFINITIONS 296
#define TOK_DEFINED 297
#define TOK_EMBEDDED 298
#define TOK_ENCODED 299
#define TOK_ENCODING_CONTROL 300
#define TOK_END 301
#define TOK_ENUMERATED 302
#define TOK_EXPLICIT 303
#define TOK_EXPORTS 304
#define TOK_EXTENSIBILITY 305
#define TOK_EXTERNAL 306
#define TOK_FALSE 307
#define TOK_FROM 308
#define TOK_GeneralizedTime 309
#define TOK_GeneralString 310
#define TOK_GraphicString 311
#define TOK_IA5String 312
#define TOK_IDENTIFIER 313
#define TOK_IMPLICIT 314
#define TOK_IMPLIED 315
#define TOK_IMPORTS 316
#define TOK_INCLUDES 317
#define TOK_INSTANCE 318
#define TOK_INSTRUCTIONS 319
#define TOK_INTEGER 320
#define TOK_ISO646String 321
#define TOK_MAX 322
#define TOK_MIN 323
#define TOK_MINUS_INFINITY 324
#define TOK_NULL 325
#define TOK_NumericString 326
#define TOK_OBJECT 327
#define TOK_ObjectDescriptor 328
#define TOK_OCTET 329
#define TOK_OF 330
#define TOK_OPTIONAL 331
#define TOK_PATTERN 332
#define TOK_PDV 333
#define TOK_PLUS_INFINITY 334
#define TOK_PRESENT 335
#define TOK_PrintableString 336
#define TOK_PRIVATE 337
#define TOK_REAL 338
#define TOK_RELATIVE_OID 339
#define TOK_SEQUENCE 340
#define TOK_SET 341
#define TOK_SIZE 342
#define TOK_STRING 343
#define TOK_SYNTAX 344
#define TOK_T61String 345
#define TOK_TAGS 346
#define TOK_TeletexString 347
#define TOK_TRUE 348
#define TOK_TYPE_IDENTIFIER 349
#define TOK_UNIQUE 350
#define TOK_UNIVERSAL 351
#define TOK_UniversalString 352
#define TOK_UTCTime 353
#define TOK_UTF8String 354
#define TOK_VideotexString 355
#define TOK_VisibleString 356
#define TOK_WITH 357
#define UTF8_BOM 358
#define TOK_EXCEPT 359
#define TOK_INTERSECTION 360
#define TOK_UNION 361
#define TOK_TwoDots 362
#define TOK_ThreeDots 363




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
			root = asn1p_constraint_new(yylineno, currentModule);	\
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
#line 436 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 449 "asn1p_y.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   812

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  317
/* YYNRULES -- Number of states.  */
#define YYNSTATES  479

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   120,     2,     2,     2,     2,     2,     2,
     113,   114,     2,     2,   116,     2,   121,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   117,   115,
     122,     2,     2,     2,   123,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   118,     2,   119,   105,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,   107,   112,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     106,   108,   109,   110
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    14,    24,    25,
      27,    31,    34,    36,    39,    41,    46,    48,    49,    51,
      53,    56,    59,    62,    65,    68,    71,    72,    74,    78,
      80,    83,    85,    87,    89,    90,    94,    96,    97,    99,
     103,   106,   107,   109,   111,   114,   115,   117,   122,   124,
     128,   130,   134,   136,   137,   139,   143,   147,   150,   152,
     156,   158,   162,   164,   168,   173,   175,   177,   182,   186,
     190,   197,   204,   206,   210,   212,   216,   220,   224,   228,
     230,   234,   236,   238,   240,   242,   243,   245,   247,   251,
     257,   261,   264,   268,   270,   272,   276,   279,   281,   283,
     289,   290,   292,   294,   298,   301,   306,   310,   314,   318,
     322,   326,   327,   329,   330,   337,   339,   342,   344,   346,
     348,   352,   354,   358,   362,   366,   367,   370,   372,   377,
     382,   387,   394,   401,   403,   408,   412,   414,   418,   422,
     426,   428,   432,   434,   438,   440,   442,   444,   446,   450,
     454,   456,   461,   463,   465,   469,   470,   474,   476,   478,
     480,   482,   484,   486,   488,   490,   494,   496,   498,   500,
     502,   505,   507,   509,   511,   513,   516,   519,   521,   523,
     526,   529,   531,   533,   535,   537,   539,   542,   544,   547,
     549,   551,   553,   555,   557,   559,   561,   563,   565,   567,
     569,   571,   573,   575,   577,   579,   581,   583,   584,   586,
     588,   590,   595,   599,   604,   606,   608,   610,   612,   616,
     622,   624,   628,   630,   634,   636,   640,   642,   646,   651,
     655,   657,   659,   663,   667,   671,   675,   677,   679,   680,
     684,   687,   690,   692,   694,   696,   698,   700,   702,   704,
     706,   708,   710,   712,   716,   722,   724,   728,   730,   734,
     735,   737,   739,   741,   743,   745,   747,   749,   750,   756,
     759,   761,   764,   767,   771,   773,   775,   779,   784,   786,
     790,   793,   797,   799,   803,   804,   806,   808,   811,   814,
     818,   820,   824,   826,   831,   836,   838,   840,   842,   844,
     846,   848,   849,   851,   854,   859,   860,   862,   864,   866,
     867,   869,   871,   873,   875,   877,   878,   880
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     125,     0,    -1,   103,   126,    -1,   126,    -1,   127,    -1,
     126,   127,    -1,    -1,   244,   128,   129,    41,   133,     3,
      28,   136,    46,    -1,    -1,   130,    -1,   111,   131,   112,
      -1,   111,   112,    -1,   132,    -1,   131,   132,    -1,   247,
      -1,   247,   113,    12,   114,    -1,    12,    -1,    -1,   134,
      -1,   135,    -1,   134,   135,    -1,    48,    91,    -1,    59,
      91,    -1,    27,    91,    -1,    50,    60,    -1,    18,    64,
      -1,    -1,   137,    -1,   149,   141,   138,    -1,   139,    -1,
     138,   139,    -1,   156,    -1,   186,    -1,   154,    -1,    -1,
      45,    18,   140,    -1,   196,    -1,    -1,   142,    -1,    61,
     143,   115,    -1,    61,    53,    -1,    -1,   144,    -1,   146,
      -1,   144,   146,    -1,    -1,   130,    -1,   147,    53,   244,
     145,    -1,   148,    -1,   147,   116,   148,    -1,   244,    -1,
     244,   111,   112,    -1,   247,    -1,    -1,   150,    -1,    49,
     151,   115,    -1,    49,    24,   115,    -1,    49,   115,    -1,
     152,    -1,   151,   116,   152,    -1,   244,    -1,   244,   111,
     112,    -1,   247,    -1,   111,   204,   112,    -1,   244,   155,
       3,   153,    -1,   195,    -1,   180,    -1,   180,   111,   159,
     112,    -1,   244,     3,   176,    -1,   244,     3,   166,    -1,
     244,   111,   157,   112,     3,   176,    -1,   244,   111,   157,
     112,     3,   166,    -1,   158,    -1,   157,   116,   158,    -1,
     244,    -1,   244,   117,   247,    -1,   244,   117,   244,    -1,
     193,   117,   247,    -1,   193,   117,   244,    -1,   160,    -1,
     159,   116,   160,    -1,   176,    -1,   189,    -1,   247,    -1,
     153,    -1,    -1,   162,    -1,   163,    -1,   162,   116,   163,
      -1,   162,   116,     4,   162,     5,    -1,   247,   176,   232,
      -1,   176,   232,    -1,    37,    75,   176,    -1,   175,    -1,
     165,    -1,   164,   116,   165,    -1,   247,   176,    -1,   175,
      -1,   176,    -1,    35,   111,   168,   112,   170,    -1,    -1,
      95,    -1,   169,    -1,   168,   116,   169,    -1,    19,   232,
      -1,    20,   176,   167,   232,    -1,    20,   184,   232,    -1,
      20,   185,   232,    -1,    19,   184,   232,    -1,    19,   176,
     232,    -1,    19,   185,   232,    -1,    -1,   171,    -1,    -1,
     102,    89,   111,   172,   173,   112,    -1,   174,    -1,   173,
     174,    -1,     6,    -1,    21,    -1,   183,    -1,   118,   173,
     119,    -1,   110,    -1,   110,   120,   190,    -1,   110,   120,
     237,    -1,   239,   178,   199,    -1,    -1,   177,   179,    -1,
     155,    -1,    34,   111,   164,   112,    -1,    85,   111,   161,
     112,    -1,    86,   111,   161,   112,    -1,    85,   199,    75,
     246,   239,   178,    -1,    86,   199,    75,   246,   239,   178,
      -1,    25,    -1,    25,    42,    32,   247,    -1,    63,    75,
     180,    -1,    17,    -1,    17,   121,   244,    -1,   245,   121,
     244,    -1,    17,   121,   247,    -1,   245,    -1,   245,   121,
     181,    -1,   182,    -1,   181,   121,   182,    -1,   183,    -1,
      19,    -1,    20,    -1,    19,    -1,   184,   121,    19,    -1,
     184,   121,    20,    -1,    18,    -1,   247,   176,     3,   187,
      -1,   189,    -1,   190,    -1,   247,   117,   187,    -1,    -1,
     111,   188,   192,    -1,    70,    -1,    52,    -1,    93,    -1,
       8,    -1,    10,    -1,   191,    -1,   237,    -1,   247,    -1,
     244,   121,   247,    -1,     9,    -1,    15,    -1,    16,    -1,
       7,    -1,   192,     7,    -1,    31,    -1,    70,    -1,    83,
      -1,   194,    -1,    74,    88,    -1,    72,    58,    -1,    84,
      -1,    51,    -1,    43,    78,    -1,    33,    88,    -1,    98,
      -1,    54,    -1,   196,    -1,    65,    -1,    47,    -1,    29,
      88,    -1,   193,    -1,   194,   234,    -1,    30,    -1,    55,
      -1,    56,    -1,    57,    -1,    66,    -1,    71,    -1,    81,
      -1,    90,    -1,    92,    -1,    97,    -1,    99,    -1,   100,
      -1,   101,    -1,    73,    -1,   107,    -1,   108,    -1,   105,
      -1,   106,    -1,    -1,   200,    -1,   201,    -1,   202,    -1,
      87,   113,   203,   114,    -1,   113,   203,   114,    -1,   202,
     113,   203,   114,    -1,   204,    -1,   221,    -1,   110,    -1,
     205,    -1,   205,   116,   110,    -1,   205,   116,   110,   116,
     205,    -1,   206,    -1,    24,   104,   209,    -1,   207,    -1,
     206,   197,   207,    -1,   208,    -1,   207,   198,   208,    -1,
     209,    -1,   209,   104,   209,    -1,   212,   113,   204,   114,
      -1,   113,   204,   114,    -1,   213,    -1,   215,    -1,   213,
     225,   213,    -1,    68,   225,   213,    -1,   213,   225,    67,
      -1,    68,   225,    67,    -1,   216,    -1,   211,    -1,    -1,
     111,   210,   192,    -1,    77,     9,    -1,    77,   247,    -1,
      87,    -1,    53,    -1,    52,    -1,    93,    -1,   238,    -1,
     191,    -1,   214,    -1,   247,    -1,     8,    -1,    10,    -1,
     180,    -1,   102,    36,   202,    -1,   102,    37,   111,   217,
     112,    -1,   218,    -1,   217,   116,   218,    -1,   110,    -1,
     247,   199,   219,    -1,    -1,   220,    -1,    80,    -1,    22,
      -1,    76,    -1,   222,    -1,   226,    -1,   224,    -1,    -1,
      38,    32,   111,   223,   192,    -1,    39,   176,    -1,   109,
      -1,   109,   122,    -1,   122,   109,    -1,   122,   109,   122,
      -1,   227,    -1,   228,    -1,   111,   244,   112,    -1,   227,
     111,   229,   112,    -1,   230,    -1,   229,   116,   230,    -1,
     123,   231,    -1,   123,   121,   231,    -1,   247,    -1,   231,
     121,   247,    -1,    -1,   233,    -1,    76,    -1,    40,   187,
      -1,   111,   112,    -1,   111,   235,   112,    -1,   236,    -1,
     235,   116,   236,    -1,   247,    -1,   247,   113,   237,   114,
      -1,   247,   113,   190,   114,    -1,   237,    -1,   110,    -1,
      12,    -1,    13,    -1,   237,    -1,    14,    -1,    -1,   240,
      -1,   241,   243,    -1,   118,   242,    12,   119,    -1,    -1,
      96,    -1,    26,    -1,    82,    -1,    -1,    59,    -1,    48,
      -1,    17,    -1,    18,    -1,    18,    -1,    -1,   247,    -1,
      11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   358,   358,   361,   367,   372,   389,   389,   418,   419,
     423,   426,   432,   438,   447,   451,   455,   465,   466,   475,
     478,   487,   490,   493,   496,   500,   521,   522,   531,   544,
     547,   564,   571,   584,   592,   591,   605,   618,   619,   622,
     632,   638,   639,   642,   647,   654,   655,   659,   670,   675,
     682,   688,   694,   704,   705,   717,   720,   723,   731,   736,
     743,   749,   755,   764,   767,   777,   790,   800,   820,   826,
     842,   848,   856,   865,   876,   880,   888,   896,   904,   915,
     920,   927,   930,   938,   949,   972,   973,   976,   981,   985,
     993,  1000,  1006,  1013,  1019,  1024,  1031,  1036,  1039,  1046,
    1056,  1057,  1061,  1068,  1078,  1088,  1099,  1109,  1120,  1130,
    1141,  1153,  1154,  1161,  1160,  1169,  1173,  1180,  1184,  1187,
    1191,  1197,  1205,  1214,  1226,  1250,  1257,  1276,  1279,  1285,
    1291,  1297,  1307,  1317,  1323,  1335,  1350,  1358,  1369,  1380,
    1391,  1399,  1421,  1429,  1438,  1442,  1447,  1456,  1461,  1466,
    1474,  1497,  1507,  1508,  1509,  1516,  1516,  1521,  1529,  1534,
    1539,  1544,  1549,  1552,  1558,  1569,  1587,  1591,  1596,  1604,
    1613,  1628,  1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,
    1637,  1638,  1639,  1640,  1647,  1648,  1649,  1653,  1659,  1672,
    1673,  1677,  1681,  1682,  1683,  1684,  1685,  1689,  1690,  1691,
    1692,  1696,  1697,  1704,  1704,  1705,  1705,  1708,  1709,  1715,
    1719,  1722,  1732,  1735,  1741,  1744,  1750,  1754,  1757,  1763,
    1774,  1775,  1781,  1782,  1788,  1789,  1796,  1797,  1803,  1811,
    1819,  1825,  1831,  1838,  1846,  1854,  1863,  1866,  1869,  1869,
    1879,  1884,  1896,  1899,  1905,  1910,  1915,  1916,  1917,  1918,
    1932,  1937,  1945,  1965,  1968,  1974,  1977,  1983,  1989,  2003,
    2004,  2008,  2011,  2014,  2022,  2023,  2024,  2029,  2028,  2040,
    2049,  2050,  2051,  2052,  2055,  2058,  2067,  2083,  2089,  2095,
    2109,  2120,  2136,  2139,  2159,  2163,  2167,  2171,  2194,  2198,
    2204,  2209,  2216,  2223,  2231,  2239,  2246,  2257,  2261,  2268,
    2269,  2300,  2301,  2305,  2312,  2318,  2319,  2320,  2321,  2325,
    2326,  2327,  2331,  2335,  2343,  2350,  2351,  2357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_VBracketLeft",
  "TOK_VBracketRight", "TOK_whitespace", "TOK_opaque", "TOK_bstring",
  "TOK_cstring", "TOK_hstring", "TOK_identifier", "TOK_number",
  "TOK_number_negative", "TOK_realnumber", "TOK_tuple", "TOK_quadruple",
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
  "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH",
  "\"UTF-8 byte order mark\"", "TOK_EXCEPT", "'^'", "TOK_INTERSECTION",
  "'|'", "TOK_UNION", "TOK_TwoDots", "TOK_ThreeDots", "'{'", "'}'", "'('",
  "')'", "';'", "','", "':'", "'['", "']'", "'!'", "'.'", "'<'", "'@'",
  "$accept", "ParsedGrammar", "ModuleList", "ModuleDefinition", "@1",
  "optObjectIdentifier", "ObjectIdentifier", "ObjectIdentifierBody",
  "ObjectIdentifierElement", "optModuleDefinitionFlags",
  "ModuleDefinitionFlags", "ModuleDefinitionFlag", "optModuleBody",
  "ModuleBody", "AssignmentList", "Assignment", "@2", "optImports",
  "ImportsDefinition", "optImportsBundleSet", "ImportsBundleSet",
  "AssignedIdentifier", "ImportsBundle", "ImportsList", "ImportsElement",
  "optExports", "ExportsDefinition", "ExportsBody", "ExportsElement",
  "ValueSet", "ValueSetTypeAssignment", "DefinedType", "DataTypeReference",
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
  "SubtypeConstraint", "SetOfConstraints", "ConstraintSpecs",
  "ElementSetSpecs", "ElementSetSpec", "Unions", "Intersections",
  "IntersectionElements", "ConstraintSubtypeElement", "@5",
  "PatternConstraint", "ConstraintSpec", "SingleValue", "BitStringValue",
  "ContainedSubtype", "InnerTypeConstraint", "WithComponentsList",
  "WithComponentsElement", "optPresenceConstraint", "PresenceConstraint",
  "GeneralConstraint", "UserDefinedConstraint", "@6", "ContentsConstraint",
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
     355,   356,   357,   358,   359,    94,   360,   124,   361,   362,
     363,   123,   125,    40,    41,    59,    44,    58,    91,    93,
      33,    46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   125,   126,   126,   128,   127,   129,   129,
     130,   130,   131,   131,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   135,   136,   136,   137,   138,
     138,   139,   139,   139,   140,   139,   139,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   147,   147,
     148,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   152,   153,   154,   155,   155,   155,   156,   156,
     156,   156,   157,   157,   158,   158,   158,   158,   158,   159,
     159,   160,   160,   160,   160,   161,   161,   162,   162,   162,
     163,   163,   163,   163,   164,   164,   165,   165,   165,   166,
     167,   167,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   172,   171,   173,   173,   174,   174,   174,
     174,   175,   175,   175,   176,   177,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   180,   180,   180,
     180,   180,   181,   181,   182,   183,   183,   184,   184,   184,
     185,   186,   187,   187,   187,   188,   187,   187,   189,   189,
     189,   189,   189,   189,   190,   190,   191,   191,   191,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   194,   194,   195,   195,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   197,   197,   198,   198,   199,   199,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   204,   204,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   209,
     211,   211,   212,   212,   213,   213,   213,   213,   213,   213,
     214,   214,   215,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   220,   221,   221,   221,   223,   222,   224,
     225,   225,   225,   225,   226,   226,   227,   228,   229,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   234,   234,
     235,   235,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   241,   242,   242,   242,   242,   243,
     243,   243,   244,   244,   245,   246,   246,   247
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     0,     9,     0,     1,
       3,     2,     1,     2,     1,     4,     1,     0,     1,     1,
       2,     2,     2,     2,     2,     2,     0,     1,     3,     1,
       2,     1,     1,     1,     0,     3,     1,     0,     1,     3,
       2,     0,     1,     1,     2,     0,     1,     4,     1,     3,
       1,     3,     1,     0,     1,     3,     3,     2,     1,     3,
       1,     3,     1,     3,     4,     1,     1,     4,     3,     3,
       6,     6,     1,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     0,     1,     1,     3,     5,
       3,     2,     3,     1,     1,     3,     2,     1,     1,     5,
       0,     1,     1,     3,     2,     4,     3,     3,     3,     3,
       3,     0,     1,     0,     6,     1,     2,     1,     1,     1,
       3,     1,     3,     3,     3,     0,     2,     1,     4,     4,
       4,     6,     6,     1,     4,     3,     1,     3,     3,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     3,     3,
       1,     4,     1,     1,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     4,     3,     4,     1,     1,     1,     1,     3,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     4,     3,
       1,     1,     3,     3,     3,     3,     1,     1,     0,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     1,     3,     1,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     2,
       1,     2,     2,     3,     1,     1,     3,     4,     1,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     2,     3,
       1,     3,     1,     4,     4,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     4,     0,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   312,   313,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   317,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     189,     0,   190,   191,   192,   193,   194,   202,   195,   196,
     197,   198,   199,   200,   201,    28,    29,    33,    31,    32,
      36,     0,   301,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   301,   136,   314,     0,   171,     0,     0,   185,
     178,   182,   184,   172,     0,     0,   173,   177,   181,     0,
       0,    66,   187,   174,    65,   183,   140,   305,     0,   125,
     302,   309,    45,    49,    51,    35,     0,    69,    68,     0,
     186,   180,   179,   176,   175,     0,    72,     0,   174,    74,
       0,   301,     0,   188,     0,   307,   308,   306,     0,     0,
       0,   207,   311,   310,   303,    46,    47,     0,   137,   139,
       0,     0,     0,     0,     0,    64,   160,   166,   161,   297,
     298,   167,   168,   158,   159,    84,     0,    79,    81,    82,
     162,   163,    83,   296,   288,     0,   290,   295,   292,   145,
     146,   141,   142,   144,   138,     0,   157,   155,   151,   152,
     153,     0,   164,   133,     0,     0,   207,   207,   127,   126,
       0,     0,   124,   208,   209,   210,   301,   301,     0,   102,
     301,    73,    78,    77,    76,    75,   250,   251,   300,     0,
     244,   243,     0,     0,   242,   245,     0,   216,   238,     0,
     252,   247,     0,   217,   220,   222,   224,   226,   237,     0,
     230,   248,   231,   236,   299,   246,   249,    67,   301,   289,
       0,     0,     0,   304,     0,     0,     0,     0,   301,     0,
     301,     0,   301,     0,     0,     0,   301,   238,     0,   214,
     215,   264,   266,   265,   274,   275,     0,   150,   147,     0,
     286,   284,   284,   284,   104,   285,   100,   284,   284,   111,
       0,    71,    70,     0,   270,     0,     0,   240,   241,     0,
       0,     0,     0,    63,     0,   203,   204,     0,   205,   206,
       0,     0,     0,     0,    80,   291,     0,     0,   164,   143,
     169,   156,   165,   154,     0,   121,     0,    94,    97,    98,
     301,   135,     0,     0,    86,    87,    93,   284,   301,   315,
       0,   315,     0,     0,   269,     0,   212,     0,     0,   287,
     109,     0,   108,   110,   101,   284,   106,   107,     0,    99,
     112,   103,   221,   271,   272,   235,   233,   253,     0,   239,
     229,   218,   223,   225,   227,     0,   234,   232,   294,   293,
     170,   134,     0,   128,   301,    96,   301,   129,   301,    91,
     284,   301,   316,   130,   301,   211,   267,   276,     0,     0,
     278,   213,   148,   149,   105,     0,   273,   257,     0,   255,
     207,     0,   228,   122,   123,    95,    92,   301,    88,    90,
     125,   125,     0,     0,   280,   282,   277,     0,   113,   254,
       0,   259,   219,     0,   131,   132,   268,   281,     0,   279,
       0,   256,   262,   263,   261,   258,   260,    89,   283,   117,
     118,     0,     0,   115,   119,     0,   114,   116,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   135,    56,    57,    63,
      64,   166,    65,    66,    67,    46,    47,    50,    51,   185,
      87,   120,    88,   145,   146,   186,   187,   353,   354,   355,
     346,   347,   137,   375,   228,   229,   379,   380,   460,   472,
     473,   356,   357,   160,   161,   219,   250,   201,   202,   474,
     302,   303,    89,   208,   274,   209,   210,   251,   341,   122,
     123,   124,   125,   327,   330,   222,   223,   224,   225,   288,
     289,   253,   254,   255,   256,   257,   321,   258,   259,   260,
     261,   262,   263,   428,   429,   465,   466,   290,   291,   442,
     292,   316,   293,   294,   295,   419,   420,   444,   304,   305,
     153,   195,   196,   264,   265,   129,   130,   131,   158,   164,
     211,   126,   411,   266
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const yytype_int16 yypact[] =
{
      97,  -312,  -312,   275,    72,   275,  -312,  -312,   275,  -312,
    -312,     1,    39,    62,  -312,  -312,  -312,  -312,    83,  -312,
      51,   343,  -312,  -312,   159,   134,   144,   169,   154,   174,
     247,   343,  -312,   171,  -312,  -312,  -312,  -312,  -312,   245,
    -312,  -312,   187,    52,   237,  -312,   240,  -312,   191,  -312,
       2,  -312,   202,  -312,  -312,   185,   558,  -312,  -312,  -312,
     228,   208,  -312,   211,   228,  -312,    -8,  -312,   258,  -312,
    -312,   357,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   558,  -312,  -312,  -312,  -312,
    -312,   224,   230,  -312,  -312,  -312,  -312,   275,   228,   265,
    -312,  -312,   -11,   262,  -312,   290,  -312,   291,   306,  -312,
    -312,  -312,  -312,  -312,   327,   298,  -312,  -312,  -312,   711,
     384,   277,  -312,   278,  -312,  -312,   279,   155,   395,  -312,
    -312,   181,     1,  -312,  -312,  -312,   288,  -312,  -312,   228,
    -312,  -312,  -312,  -312,  -312,   -75,  -312,   284,  -312,   286,
     293,    69,    80,  -312,   292,  -312,  -312,  -312,   393,   584,
     635,   104,  -312,  -312,  -312,  -312,  -312,   299,  -312,  -312,
     404,   711,   228,   228,   448,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   100,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   118,  -312,  -312,   295,  -312,
    -312,   296,  -312,  -312,  -312,   297,  -312,  -312,  -312,  -312,
    -312,   300,   301,   367,   302,   336,    98,   161,  -312,  -312,
     307,   342,  -312,  -312,  -312,   309,    92,    47,   131,  -312,
     -11,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   308,
    -312,  -312,   -13,   173,  -312,  -312,   294,  -312,  -312,   448,
    -312,  -312,   303,   310,   229,   257,  -312,   320,  -312,   314,
     -13,  -312,  -312,  -312,  -312,  -312,  -312,  -312,    69,  -312,
      45,   316,   345,  -312,   407,   417,   584,   398,     6,   350,
      76,   358,    76,   359,   342,   400,   230,   275,   322,  -312,
    -312,  -312,  -312,  -312,   326,  -312,   342,  -312,  -312,   584,
    -312,   129,   123,   129,  -312,  -312,   344,   123,   129,   338,
     299,  -312,  -312,   496,   319,   333,   210,  -312,  -312,   332,
     337,   407,   329,  -312,   339,  -312,  -312,   496,  -312,  -312,
     496,   496,   448,   330,  -312,  -312,   340,   353,  -312,  -312,
    -312,   440,  -312,  -312,   417,   331,   170,  -312,  -312,  -312,
     230,  -312,   375,   356,   354,  -312,  -312,   129,   230,   417,
     361,   417,   355,   360,  -312,   362,  -312,   365,   376,  -312,
    -312,   352,  -312,  -312,  -312,   129,  -312,  -312,   386,  -312,
    -312,  -312,  -312,  -312,   369,  -312,  -312,   309,    19,   440,
    -312,   373,   257,  -312,  -312,   378,  -312,  -312,  -312,  -312,
    -312,  -312,   316,  -312,     6,  -312,   230,  -312,    38,  -312,
     129,   230,  -312,  -312,   230,  -312,  -312,  -312,     9,   172,
    -312,  -312,  -312,  -312,  -312,   383,  -312,  -312,   188,  -312,
     104,   469,  -312,  -312,  -312,  -312,  -312,    60,  -312,  -312,
    -312,  -312,   407,   417,   374,  -312,  -312,   365,  -312,  -312,
      19,   152,  -312,    41,  -312,  -312,   440,   374,   417,  -312,
      15,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,    15,     8,  -312,  -312,    34,  -312,  -312,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,   473,   117,  -312,  -312,   364,  -312,   479,  -312,
    -312,   467,  -312,  -312,  -312,   414,  -312,  -312,  -312,  -312,
    -312,  -312,   438,  -312,   405,  -312,  -312,  -312,   455,   368,
    -312,   363,  -312,  -312,   346,  -312,   251,   238,    87,   119,
    -312,   122,   304,  -312,  -312,   218,  -312,  -312,  -312,    58,
    -223,  -255,   -89,  -312,   -67,  -312,   -86,  -312,   259,  -138,
     305,   311,  -312,   -93,  -312,  -133,  -256,  -140,  -311,   -81,
     -52,  -312,   -24,  -312,  -312,  -215,  -312,  -312,   214,   -83,
    -166,    99,  -312,   209,   212,  -225,  -312,  -312,  -312,  -294,
    -312,  -312,  -312,  -312,    89,  -312,  -312,  -312,  -312,  -312,
    -312,   280,  -312,  -312,  -312,  -312,    96,   101,  -203,  -312,
    -312,  -312,   281,  -126,  -312,  -112,  -312,  -312,  -312,  -312,
       4,  -312,   184,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -285
static const yytype_int16 yytable[] =
{
      20,   281,   283,   128,     7,   121,    20,     7,   252,     7,
     389,   190,     7,   138,   469,   336,   203,    15,   189,   190,
      15,   469,   386,   348,   136,   191,   197,   199,   200,   470,
      15,    53,    90,   191,   199,   200,   470,   170,   147,   397,
     469,   171,   437,    69,    92,    97,   467,    52,    53,    15,
      15,    16,    69,   199,   200,   470,    15,   179,   180,    68,
      91,    90,   188,    15,    52,   297,   298,   148,    68,     1,
       2,    15,     9,    92,   121,   352,    48,   176,   177,   178,
      15,   179,   180,   322,   181,   182,    69,    15,   382,    91,
     147,    15,   179,   180,    15,    16,   314,   352,   370,   372,
     373,   132,    68,    21,   376,   377,   394,   127,    98,   315,
     297,   298,    12,   352,     1,     2,   345,    59,    60,   148,
     476,   183,    10,   149,   127,    10,   471,   169,   190,   427,
     443,   456,   299,   471,   203,   189,   190,   301,   306,   192,
     198,   312,   191,   168,   197,   337,   433,   212,   345,   348,
     191,    17,   471,   478,   409,   193,   127,   408,   204,   190,
     233,   235,   184,   299,    24,   127,   395,    49,   300,   299,
     345,    33,   424,   191,   462,   149,   232,   234,   127,   188,
     174,   155,   317,   343,    15,   220,   345,   127,   -85,   349,
     193,   220,   194,   351,   127,    22,    15,   364,    34,   300,
       3,   362,     1,     2,  -284,   300,   369,   439,  -284,   280,
     127,   221,   267,   368,    37,   451,   268,   221,   236,   177,
     237,    15,   179,   180,   238,   181,   182,   102,   463,   162,
     269,   318,   464,   -26,   270,    35,    43,   156,    62,    15,
     163,   103,   104,   309,   371,     1,     2,   310,   220,   477,
      39,   157,   477,   105,    70,   106,   192,   107,   198,   338,
      36,   405,   240,   342,   212,    38,   350,   108,   358,   410,
     358,   109,   282,    42,   221,   110,   434,   385,   111,    72,
      73,    74,   403,    54,   446,    41,   404,   212,   447,   112,
      75,   365,     1,     2,   113,    76,   114,    77,   115,   440,
     449,    55,   441,   245,   450,    78,    58,   116,   117,     1,
       2,   199,   200,    61,    79,   349,    80,   436,   226,   227,
      94,    81,   118,    82,    83,    84,    95,    15,   179,   180,
     319,   320,   401,     1,     2,   119,   325,   326,   236,   177,
     237,    15,   179,   180,   238,   181,   182,   412,   127,   412,
     236,   177,   237,    15,   179,   180,   238,   181,   182,   103,
     104,    25,   328,   329,   199,   200,   239,   103,   104,    99,
      26,   422,   423,   454,   455,   100,   430,   134,   140,   141,
     285,   286,   240,   139,   142,   143,   144,   150,   151,   152,
     338,    27,   350,    28,   240,   241,   358,   396,   159,   167,
     154,   172,    29,   173,   174,   205,   445,   230,   271,   277,
     242,   279,   313,   278,   340,   323,   273,   272,   276,   243,
     284,   275,   296,   245,   331,   358,   324,   332,    15,   244,
     344,   445,   363,   359,   361,   245,   366,   367,   430,   374,
     378,   383,   384,   390,   246,   221,   468,   400,   388,   391,
     406,   402,   247,   287,   398,   249,   236,   177,   237,    15,
     179,   180,   238,   181,   182,   103,   104,   399,   407,   415,
     408,   416,   239,   413,   417,   425,     8,   236,   177,   237,
      15,   179,   180,   238,   181,   182,   103,   104,   418,   431,
     421,   426,   432,   239,   448,   458,   165,    23,    40,   101,
     240,   241,    96,   133,   236,   177,   237,    15,   179,   180,
     238,   181,   182,   103,   104,    93,   242,   231,   175,   334,
     360,   240,   241,   218,   453,   243,   435,   438,   381,   475,
     452,   339,   307,   387,   311,   244,   392,   242,   308,   461,
     333,   245,   393,   459,   457,   414,   243,     0,   240,   241,
     246,   335,     0,     0,     0,     0,   244,     0,   247,   248,
       0,   249,   245,     0,   242,     0,     0,     0,     0,    15,
       0,   246,     0,   243,     0,     1,     2,     0,     0,     0,
     248,     0,   249,   244,     0,     0,     0,     0,    70,   245,
       0,     0,   176,   177,   178,    15,   179,   180,   246,   181,
     182,     1,     2,    71,     0,     0,     0,   248,     0,   249,
       0,     0,     0,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,    76,
       0,    77,     0,     0,     0,     0,   183,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
      80,     0,   103,   104,   206,    81,     0,    82,    83,    84,
     213,     0,     0,     0,   105,    70,   106,     0,   107,   214,
       0,     0,     0,     0,     0,     0,     0,   184,   108,     0,
       0,     0,   109,     0,     0,     0,   110,     0,     0,   111,
      72,    73,    74,     0,     0,   207,     0,     0,   215,     0,
     112,    75,     0,     0,     0,   113,    76,   114,    77,   115,
       0,     0,     0,     0,     0,     0,    78,     0,   116,   117,
     216,   217,     0,     0,     0,    79,     0,    80,     1,     2,
       0,     0,    81,   118,    82,    83,    84,     0,     0,     0,
     105,    70,   106,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,   109,     0,
       0,     0,   110,     0,     0,   111,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   112,    75,     0,     0,
       0,   113,    76,   114,    77,   115,     0,     0,     0,     0,
       0,     0,    78,     0,   116,   117,     0,     0,     0,     0,
       0,    79,     0,    80,     0,     0,     0,     0,    81,   118,
      82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   216,   217,    92,     0,    91,    18,     3,   174,     5,
     321,   151,     8,   102,     6,   271,   154,    11,   151,   159,
      11,     6,   316,   278,    35,   151,   152,    19,    20,    21,
      11,    43,    56,   159,    19,    20,    21,   112,   119,   333,
       6,   116,     4,    55,    56,    53,     5,    43,    60,    11,
      11,    12,    64,    19,    20,    21,    11,    12,    13,    55,
      56,    85,   151,    11,    60,    18,    19,   119,    64,    17,
      18,    11,     0,    85,   160,    37,    24,     8,     9,    10,
      11,    12,    13,   249,    15,    16,    98,    11,   313,    85,
     171,    11,    12,    13,    11,    12,   109,    37,   301,   302,
     303,    97,    98,    41,   307,   308,   331,   118,   116,   122,
      18,    19,   111,    37,    17,    18,   110,   115,   116,   171,
     112,    52,     5,   119,   118,     8,   118,   139,   268,   110,
     121,   442,    40,   118,   272,   268,   276,   226,   227,   151,
     152,   230,   268,   139,   270,   271,   402,   159,   110,   404,
     276,   112,   118,   119,   357,   110,   118,   116,   154,   299,
     172,   173,    93,    40,   113,   118,   332,   115,    76,    40,
     110,    12,   375,   299,    22,   171,   172,   173,   118,   268,
     111,    26,     9,   276,    11,    87,   110,   118,   112,   278,
     110,    87,   112,   279,   118,   112,    11,   286,    64,    76,
     103,   284,    17,    18,   112,    76,   299,   410,   116,   111,
     118,   113,   112,   296,    60,   430,   116,   113,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     3,    76,    48,
     112,   243,    80,    46,   116,    91,    49,    82,    53,    11,
      59,    17,    18,   112,   121,    17,    18,   116,    87,   472,
       3,    96,   475,    29,    30,    31,   268,    33,   270,   271,
      91,   350,    52,   275,   276,    91,   278,    43,   280,   358,
     282,    47,   111,    28,   113,    51,   402,    67,    54,    55,
      56,    57,   112,    46,   112,   114,   116,   299,   116,    65,
      66,   287,    17,    18,    70,    71,    72,    73,    74,   411,
     112,    61,   414,    93,   116,    81,   115,    83,    84,    17,
      18,    19,    20,   111,    90,   404,    92,   406,    19,    20,
     112,    97,    98,    99,   100,   101,   115,    11,    12,    13,
      36,    37,   344,    17,    18,   111,   107,   108,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   359,   118,   361,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    18,   105,   106,    19,    20,    24,    17,    18,   111,
      27,    19,    20,   440,   441,    18,   388,   112,    88,    88,
      38,    39,    52,   121,    78,    58,    88,     3,   111,   111,
     402,    48,   404,    50,    52,    53,   408,    67,     3,   111,
     121,   117,    59,   117,   111,    12,   418,     3,   113,    42,
      68,    75,   104,   111,     7,   112,   119,   121,   117,    77,
     113,   121,   113,    93,   104,   437,   116,   113,    11,    87,
      32,   443,    32,    75,    75,    93,   114,   111,   450,    95,
     102,   122,   109,   114,   102,   113,   458,     7,   111,   110,
      75,   120,   110,   111,   114,   113,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   114,   112,   114,
     116,   111,    24,   112,   112,    89,     3,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   123,   116,
     114,   122,   114,    24,   111,   121,   132,    18,    31,    85,
      52,    53,    64,    98,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    60,    68,   171,   150,   268,
     282,    52,    53,   160,   437,    77,   404,   408,   310,   471,
     431,   272,   227,   319,   230,    87,   327,    68,   227,   450,
     260,    93,   330,   447,   443,   361,    77,    -1,    52,    53,
     102,   270,    -1,    -1,    -1,    -1,    87,    -1,   110,   111,
      -1,   113,    93,    -1,    68,    -1,    -1,    -1,    -1,    11,
      -1,   102,    -1,    77,    -1,    17,    18,    -1,    -1,    -1,
     111,    -1,   113,    87,    -1,    -1,    -1,    -1,    30,    93,
      -1,    -1,     8,     9,    10,    11,    12,    13,   102,    15,
      16,    17,    18,    45,    -1,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    71,
      -1,    73,    -1,    -1,    -1,    -1,    52,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    -1,    17,    18,    70,    97,    -1,    99,   100,   101,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    43,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    54,
      55,    56,    57,    -1,    -1,   111,    -1,    -1,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    92,    17,    18,
      -1,    -1,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    92,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    18,   103,   125,   126,   127,   244,   126,     0,
     127,   128,   111,   129,   130,    11,    12,   112,   131,   132,
     247,    41,   112,   132,   113,    18,    27,    48,    50,    59,
     133,   134,   135,    12,    64,    91,    91,    60,    91,     3,
     135,   114,    28,    49,   136,   137,   149,   150,    24,   115,
     151,   152,   244,   247,    46,    61,   141,   142,   115,   115,
     116,   111,    53,   143,   144,   146,   147,   148,   244,   247,
      30,    45,    55,    56,    57,    66,    71,    73,    81,    90,
      92,    97,    99,   100,   101,   138,   139,   154,   156,   186,
     196,   244,   247,   152,   112,   115,   146,    53,   116,   111,
      18,   139,     3,    17,    18,    29,    31,    33,    43,    47,
      51,    54,    65,    70,    72,    74,    83,    84,    98,   111,
     155,   180,   193,   194,   195,   196,   245,   118,   176,   239,
     240,   241,   244,   148,   112,   140,    35,   166,   176,   121,
      88,    88,    78,    58,    88,   157,   158,   193,   194,   244,
       3,   111,   111,   234,   121,    26,    82,    96,   242,     3,
     177,   178,    48,    59,   243,   130,   145,   111,   244,   247,
     112,   116,   117,   117,   111,   153,     8,     9,    10,    12,
      13,    15,    16,    52,    93,   153,   159,   160,   176,   189,
     191,   237,   247,   110,   112,   235,   236,   237,   247,    19,
      20,   181,   182,   183,   244,    12,    70,   111,   187,   189,
     190,   244,   247,    25,    34,    63,    85,    86,   155,   179,
      87,   113,   199,   200,   201,   202,    19,    20,   168,   169,
       3,   158,   244,   247,   244,   247,     8,    10,    14,    24,
      52,    53,    68,    77,    87,    93,   102,   110,   111,   113,
     180,   191,   204,   205,   206,   207,   208,   209,   211,   212,
     213,   214,   215,   216,   237,   238,   247,   112,   116,   112,
     116,   113,   121,   119,   188,   121,   117,    42,   111,    75,
     111,   199,   111,   199,   113,    38,    39,   111,   203,   204,
     221,   222,   224,   226,   227,   228,   113,    18,    19,    40,
      76,   176,   184,   185,   232,   233,   176,   184,   185,   112,
     116,   166,   176,   104,   109,   122,   225,     9,   247,    36,
      37,   210,   204,   112,   116,   107,   108,   197,   105,   106,
     198,   104,   113,   225,   160,   236,   190,   237,   247,   182,
       7,   192,   247,   187,    32,   110,   164,   165,   175,   176,
     247,   180,    37,   161,   162,   163,   175,   176,   247,    75,
     161,    75,   203,    32,   176,   244,   114,   111,   203,   187,
     232,   121,   232,   232,    95,   167,   232,   232,   102,   170,
     171,   169,   209,   122,   109,    67,   213,   202,   111,   192,
     114,   110,   207,   208,   209,   204,    67,   213,   114,   114,
       7,   247,   120,   112,   116,   176,    75,   112,   116,   232,
     176,   246,   247,   112,   246,   114,   111,   112,   123,   229,
     230,   114,    19,    20,   232,    89,   122,   110,   217,   218,
     247,   116,   114,   190,   237,   165,   176,     4,   163,   232,
     239,   239,   223,   121,   231,   247,   112,   116,   111,   112,
     116,   199,   205,   162,   178,   178,   192,   231,   121,   230,
     172,   218,    22,    76,    80,   219,   220,     5,   247,     6,
      21,   118,   173,   174,   183,   173,   112,   174,   119
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
#line 358 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(2) - (2)].a_grammar);
	}
    break;

  case 3:
#line 361 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 4:
#line 367 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 5:
#line 372 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 6:
#line 389 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 7:
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

  case 8:
#line 418 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 9:
#line 419 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 10:
#line 423 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 11:
#line 426 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 12:
#line 432 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(1) - (1)].a_oid_arc));
		if((yyvsp[(1) - (1)].a_oid_arc).name)
			free((yyvsp[(1) - (1)].a_oid_arc).name);
	}
    break;

  case 13:
#line 438 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(1) - (2)].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(2) - (2)].a_oid_arc));
		if((yyvsp[(2) - (2)].a_oid_arc).name)
			free((yyvsp[(2) - (2)].a_oid_arc).name);
	}
    break;

  case 14:
#line 447 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
    break;

  case 15:
#line 451 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 16:
#line 455 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[(1) - (1)].a_int);
	}
    break;

  case 17:
#line 465 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 18:
#line 466 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 475 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 20:
#line 478 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 21:
#line 487 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 22:
#line 490 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 23:
#line 493 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 24:
#line 496 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 25:
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

  case 26:
#line 521 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 27:
#line 522 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 28:
#line 531 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[(1) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[(2) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), members, (yyvsp[(3) - (3)].a_module), next);

		asn1p_module_free((yyvsp[(1) - (3)].a_module));
		asn1p_module_free((yyvsp[(2) - (3)].a_module));
		asn1p_module_free((yyvsp[(3) - (3)].a_module));
	}
    break;

  case 29:
#line 544 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 30:
#line 547 "asn1p_y.y"
    {
		if((yyvsp[(1) - (2)].a_module)) {
			(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		} else {
			(yyval.a_module) = (yyvsp[(2) - (2)].a_module);
			break;
		}
		AL_IMPORT((yyval.a_module), members, (yyvsp[(2) - (2)].a_module), next);
		asn1p_module_free((yyvsp[(2) - (2)].a_module));
	}
    break;

  case 31:
#line 564 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 32:
#line 571 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 33:
#line 584 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 34:
#line 592 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 35:
#line 593 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at line %d ignored\n",
			(yyvsp[(2) - (3)].tv_str), yylineno);
		free((yyvsp[(2) - (3)].tv_str));
		(yyval.a_module) = 0;
	}
    break;

  case 36:
#line 605 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 37:
#line 618 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 39:
#line 622 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 40:
#line 632 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 41:
#line 638 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 43:
#line 642 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 44:
#line 647 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 45:
#line 654 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 46:
#line 655 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 47:
#line 659 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (4)].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[(3) - (4)].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[(4) - (4)].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
    break;

  case 48:
#line 670 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 49:
#line 675 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 50:
#line 682 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 688 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 694 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 53:
#line 704 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 54:
#line 705 "asn1p_y.y"
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

  case 55:
#line 717 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 56:
#line 720 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 57:
#line 723 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 58:
#line 731 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 59:
#line 736 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 60:
#line 743 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 749 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 755 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 63:
#line 764 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 64:
#line 767 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 65:
#line 777 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 66:
#line 790 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 67:
#line 800 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (4)].a_ref);
		(yyval.a_expr)->rhs_pspecs = (yyvsp[(3) - (4)].a_expr);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 68:
#line 820 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 69:
#line 826 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 70:
#line 842 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 848 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 72:
#line 856 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[(1) - (1)].a_parg).governor, (yyvsp[(1) - (1)].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[(1) - (1)].a_parg).governor);
		free((yyvsp[(1) - (1)].a_parg).argument);
	}
    break;

  case 73:
#line 865 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = (yyvsp[(1) - (3)].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[(3) - (3)].a_parg).governor, (yyvsp[(3) - (3)].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[(3) - (3)].a_parg).governor);
		free((yyvsp[(3) - (3)].a_parg).argument);
	}
    break;

  case 74:
#line 876 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 75:
#line 880 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 76:
#line 888 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 77:
#line 896 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[(1) - (3)].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 78:
#line 904 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[(1) - (3)].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 79:
#line 915 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 80:
#line 920 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 81:
#line 927 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 82:
#line 930 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 83:
#line 938 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		(yyval.a_expr)->value = asn1p_value_fromref(ref, 0);
	}
    break;

  case 84:
#line 949 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 85:
#line 972 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 86:
#line 973 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 87:
#line 976 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 88:
#line 981 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 89:
#line 985 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (5)].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
		asn1p_expr_free((yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 90:
#line 993 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 91:
#line 1000 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 92:
#line 1006 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 93:
#line 1013 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 94:
#line 1019 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 95:
#line 1024 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 96:
#line 1031 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 97:
#line 1036 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 98:
#line 1039 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 99:
#line 1046 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 100:
#line 1056 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 101:
#line 1057 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 102:
#line 1061 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 103:
#line 1068 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 104:
#line 1078 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
	}
    break;

  case 105:
#line 1088 "asn1p_y.y"
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

  case 106:
#line 1099 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 107:
#line 1109 "asn1p_y.y"
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

  case 108:
#line 1120 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 109:
#line 1130 "asn1p_y.y"
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

  case 110:
#line 1141 "asn1p_y.y"
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

  case 111:
#line 1153 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 112:
#line 1154 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 113:
#line 1161 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 114:
#line 1163 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 115:
#line 1169 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 116:
#line 1173 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 117:
#line 1180 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 118:
#line 1184 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 119:
#line 1187 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 120:
#line 1191 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 121:
#line 1197 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 122:
#line 1205 "asn1p_y.y"
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

  case 123:
#line 1214 "asn1p_y.y"
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

  case 124:
#line 1226 "asn1p_y.y"
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
				/* Check this : optConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[(3) - (3)].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[(3) - (3)].a_constr);
			}
		}
	}
    break;

  case 125:
#line 1250 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 126:
#line 1257 "asn1p_y.y"
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

  case 127:
#line 1276 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 128:
#line 1279 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1285 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 130:
#line 1291 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 131:
#line 1297 "asn1p_y.y"
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

  case 132:
#line 1307 "asn1p_y.y"
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

  case 133:
#line 1317 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1323 "asn1p_y.y"
    {
		int ret;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference,
			(yyvsp[(4) - (4)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		free((yyvsp[(4) - (4)].tv_str));
	}
    break;

  case 135:
#line 1335 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1350 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 137:
#line 1358 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 138:
#line 1369 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 139:
#line 1380 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (3)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		free((yyvsp[(1) - (3)].tv_str));
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 140:
#line 1391 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
		checkmem(ret == 0);
	}
    break;

  case 141:
#line 1399 "asn1p_y.y"
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

  case 142:
#line 1421 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].a_refcomp).name, (yyvsp[(1) - (1)].a_refcomp).lex_type);
		free((yyvsp[(1) - (1)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 143:
#line 1429 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 145:
#line 1442 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 146:
#line 1447 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 147:
#line 1456 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 148:
#line 1461 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 149:
#line 1466 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 150:
#line 1474 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 151:
#line 1497 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 154:
#line 1509 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 155:
#line 1516 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 156:
#line 1516 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 157:
#line 1521 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 158:
#line 1529 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 159:
#line 1534 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 160:
#line 1539 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 161:
#line 1544 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 162:
#line 1549 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 163:
#line 1552 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 164:
#line 1558 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 165:
#line 1569 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
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
#line 1587 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 167:
#line 1591 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 168:
#line 1596 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 169:
#line 1604 "asn1p_y.y"
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
#line 1613 "asn1p_y.y"
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
#line 1628 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 172:
#line 1629 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 173:
#line 1630 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 174:
#line 1631 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 175:
#line 1632 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 176:
#line 1633 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 177:
#line 1634 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 178:
#line 1635 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 179:
#line 1636 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 180:
#line 1637 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 181:
#line 1638 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 182:
#line 1639 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 183:
#line 1640 "asn1p_y.y"
    { (yyval.a_type) = (yyvsp[(1) - (1)].a_type); }
    break;

  case 184:
#line 1647 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 185:
#line 1648 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 186:
#line 1649 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 187:
#line 1653 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 188:
#line 1659 "asn1p_y.y"
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
#line 1672 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 190:
#line 1673 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 191:
#line 1677 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 192:
#line 1681 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 193:
#line 1682 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 194:
#line 1683 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 195:
#line 1684 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 196:
#line 1685 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 197:
#line 1689 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 198:
#line 1690 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 199:
#line 1691 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 200:
#line 1692 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 201:
#line 1696 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 202:
#line 1697 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 207:
#line 1708 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 208:
#line 1709 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 210:
#line 1719 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (1)].a_constr), 0);
	}
    break;

  case 211:
#line 1722 "asn1p_y.y"
    {
		/*
		 * This is a special case, for compatibility purposes.
		 * It goes without parentheses.
		 */
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(3) - (4)].a_constr), 0);
	}
    break;

  case 212:
#line 1732 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(2) - (3)].a_constr);
	}
    break;

  case 213:
#line 1735 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 214:
#line 1741 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 215:
#line 1744 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 216:
#line 1750 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 217:
#line 1754 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 218:
#line 1757 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 219:
#line 1763 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
		ct = (yyval.a_constr);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
	}
    break;

  case 221:
#line 1775 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 223:
#line 1782 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 225:
#line 1789 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 227:
#line 1797 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 228:
#line 1803 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(1) - (4)].a_ctype);
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (4)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 229:
#line 1811 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CA_SET;
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 230:
#line 1819 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 231:
#line 1825 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 232:
#line 1831 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 233:
#line 1838 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
		(yyval.a_constr)->range_start->type = ATV_MIN;
	}
    break;

  case 234:
#line 1846 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 235:
#line 1854 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_start->type = ATV_MIN;
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 236:
#line 1863 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 237:
#line 1866 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 238:
#line 1869 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 239:
#line 1869 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 240:
#line 1879 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 241:
#line 1884 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, (yyvsp[(2) - (2)].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
		free((yyvsp[(2) - (2)].tv_str));
	}
    break;

  case 242:
#line 1896 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_SIZE;
	}
    break;

  case 243:
#line 1899 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_FROM;
	}
    break;

  case 244:
#line 1905 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 245:
#line 1910 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 249:
#line 1918 "asn1p_y.y"
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
		checkmem(ref);
		ret = asn1p_ref_add_component(ref, (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_value) = asn1p_value_fromref(ref, 0);
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 250:
#line 1932 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 251:
#line 1937 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 252:
#line 1945 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
		checkmem((yyval.a_value));
	}
    break;

  case 253:
#line 1965 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 254:
#line 1968 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(4) - (5)].a_constr), 0);
	}
    break;

  case 255:
#line 1974 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 256:
#line 1977 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMPS, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 257:
#line 1983 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_EXT;
		(yyval.a_constr)->value = asn1p_value_frombuf("...", 3, 1);
	}
    break;

  case 258:
#line 1989 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(1) - (3)].tv_str), strlen((yyvsp[(1) - (3)].tv_str)), 0);
		(yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
		if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
	}
    break;

  case 259:
#line 2003 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 260:
#line 2004 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 261:
#line 2008 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 262:
#line 2011 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 263:
#line 2014 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 267:
#line 2029 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 268:
#line 2029 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 269:
#line 2040 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 270:
#line 2049 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 271:
#line 2050 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 272:
#line 2051 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 273:
#line 2052 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 274:
#line 2055 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 275:
#line 2058 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 276:
#line 2067 "asn1p_y.y"
    {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, (yyvsp[(2) - (3)].tv_str), 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, ct, 0);
		free((yyvsp[(2) - (3)].tv_str));
	}
    break;

  case 277:
#line 2083 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 278:
#line 2089 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 279:
#line 2095 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 280:
#line 2109 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[(2) - (2)].tv_str)) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, (yyvsp[(2) - (2)].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[(2) - (2)].tv_str));
	}
    break;

  case 281:
#line 2120 "asn1p_y.y"
    {
		char *p = malloc(strlen((yyvsp[(3) - (3)].tv_str)) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, (yyvsp[(3) - (3)].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 282:
#line 2136 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 283:
#line 2139 "asn1p_y.y"
    {
		int l1 = strlen((yyvsp[(1) - (3)].tv_str));
		int l3 = strlen((yyvsp[(3) - (3)].tv_str));
		(yyval.tv_str) = malloc(l1 + 1 + l3 + 1);
		memcpy((yyval.tv_str), (yyvsp[(1) - (3)].tv_str), l1);
		(yyval.tv_str)[l1] = '.';
		memcpy((yyval.tv_str) + l1 + 1, (yyvsp[(3) - (3)].tv_str), l3);
		(yyval.tv_str)[l1 + 1 + l3] = '\0';
		free((yyvsp[(1) - (3)].tv_str));
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 284:
#line 2159 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 285:
#line 2163 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 286:
#line 2167 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 287:
#line 2171 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 288:
#line 2194 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
	}
    break;

  case 289:
#line 2198 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
	}
    break;

  case 290:
#line 2204 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 291:
#line 2209 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 292:
#line 2216 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 293:
#line 2223 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 294:
#line 2231 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 295:
#line 2239 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 296:
#line 2246 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 297:
#line 2257 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 298:
#line 2261 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 300:
#line 2269 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 301:
#line 2300 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 302:
#line 2301 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 303:
#line 2305 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 304:
#line 2312 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 305:
#line 2318 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 306:
#line 2319 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 307:
#line 2320 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 308:
#line 2321 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 309:
#line 2325 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 310:
#line 2326 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 311:
#line 2327 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 312:
#line 2331 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 313:
#line 2335 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 314:
#line 2343 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 315:
#line 2350 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 316:
#line 2351 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 317:
#line 2357 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4856 "asn1p_y.c"
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


#line 2363 "asn1p_y.y"



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


