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
     TOK_ExtValue_BIT_STRING = 277,
     TOK_ABSENT = 278,
     TOK_ABSTRACT_SYNTAX = 279,
     TOK_ALL = 280,
     TOK_ANY = 281,
     TOK_APPLICATION = 282,
     TOK_AUTOMATIC = 283,
     TOK_BEGIN = 284,
     TOK_BIT = 285,
     TOK_BMPString = 286,
     TOK_BOOLEAN = 287,
     TOK_BY = 288,
     TOK_CHARACTER = 289,
     TOK_CHOICE = 290,
     TOK_CLASS = 291,
     TOK_COMPONENT = 292,
     TOK_COMPONENTS = 293,
     TOK_CONSTRAINED = 294,
     TOK_CONTAINING = 295,
     TOK_DEFAULT = 296,
     TOK_DEFINITIONS = 297,
     TOK_DEFINED = 298,
     TOK_EMBEDDED = 299,
     TOK_ENCODED = 300,
     TOK_ENCODING_CONTROL = 301,
     TOK_END = 302,
     TOK_ENUMERATED = 303,
     TOK_EXPLICIT = 304,
     TOK_EXPORTS = 305,
     TOK_EXTENSIBILITY = 306,
     TOK_EXTERNAL = 307,
     TOK_FALSE = 308,
     TOK_FROM = 309,
     TOK_GeneralizedTime = 310,
     TOK_GeneralString = 311,
     TOK_GraphicString = 312,
     TOK_IA5String = 313,
     TOK_IDENTIFIER = 314,
     TOK_IMPLICIT = 315,
     TOK_IMPLIED = 316,
     TOK_IMPORTS = 317,
     TOK_INCLUDES = 318,
     TOK_INSTANCE = 319,
     TOK_INSTRUCTIONS = 320,
     TOK_INTEGER = 321,
     TOK_ISO646String = 322,
     TOK_MAX = 323,
     TOK_MIN = 324,
     TOK_MINUS_INFINITY = 325,
     TOK_NULL = 326,
     TOK_NumericString = 327,
     TOK_OBJECT = 328,
     TOK_ObjectDescriptor = 329,
     TOK_OCTET = 330,
     TOK_OF = 331,
     TOK_OPTIONAL = 332,
     TOK_PATTERN = 333,
     TOK_PDV = 334,
     TOK_PLUS_INFINITY = 335,
     TOK_PRESENT = 336,
     TOK_PrintableString = 337,
     TOK_PRIVATE = 338,
     TOK_REAL = 339,
     TOK_RELATIVE_OID = 340,
     TOK_SEQUENCE = 341,
     TOK_SET = 342,
     TOK_SIZE = 343,
     TOK_STRING = 344,
     TOK_SYNTAX = 345,
     TOK_T61String = 346,
     TOK_TAGS = 347,
     TOK_TeletexString = 348,
     TOK_TRUE = 349,
     TOK_TYPE_IDENTIFIER = 350,
     TOK_UNIQUE = 351,
     TOK_UNIVERSAL = 352,
     TOK_UniversalString = 353,
     TOK_UTCTime = 354,
     TOK_UTF8String = 355,
     TOK_VideotexString = 356,
     TOK_VisibleString = 357,
     TOK_WITH = 358,
     UTF8_BOM = 359,
     TOK_EXCEPT = 360,
     TOK_INTERSECTION = 361,
     TOK_UNION = 362,
     TOK_TwoDots = 363,
     TOK_ThreeDots = 364
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
#define TOK_ExtValue_BIT_STRING 277
#define TOK_ABSENT 278
#define TOK_ABSTRACT_SYNTAX 279
#define TOK_ALL 280
#define TOK_ANY 281
#define TOK_APPLICATION 282
#define TOK_AUTOMATIC 283
#define TOK_BEGIN 284
#define TOK_BIT 285
#define TOK_BMPString 286
#define TOK_BOOLEAN 287
#define TOK_BY 288
#define TOK_CHARACTER 289
#define TOK_CHOICE 290
#define TOK_CLASS 291
#define TOK_COMPONENT 292
#define TOK_COMPONENTS 293
#define TOK_CONSTRAINED 294
#define TOK_CONTAINING 295
#define TOK_DEFAULT 296
#define TOK_DEFINITIONS 297
#define TOK_DEFINED 298
#define TOK_EMBEDDED 299
#define TOK_ENCODED 300
#define TOK_ENCODING_CONTROL 301
#define TOK_END 302
#define TOK_ENUMERATED 303
#define TOK_EXPLICIT 304
#define TOK_EXPORTS 305
#define TOK_EXTENSIBILITY 306
#define TOK_EXTERNAL 307
#define TOK_FALSE 308
#define TOK_FROM 309
#define TOK_GeneralizedTime 310
#define TOK_GeneralString 311
#define TOK_GraphicString 312
#define TOK_IA5String 313
#define TOK_IDENTIFIER 314
#define TOK_IMPLICIT 315
#define TOK_IMPLIED 316
#define TOK_IMPORTS 317
#define TOK_INCLUDES 318
#define TOK_INSTANCE 319
#define TOK_INSTRUCTIONS 320
#define TOK_INTEGER 321
#define TOK_ISO646String 322
#define TOK_MAX 323
#define TOK_MIN 324
#define TOK_MINUS_INFINITY 325
#define TOK_NULL 326
#define TOK_NumericString 327
#define TOK_OBJECT 328
#define TOK_ObjectDescriptor 329
#define TOK_OCTET 330
#define TOK_OF 331
#define TOK_OPTIONAL 332
#define TOK_PATTERN 333
#define TOK_PDV 334
#define TOK_PLUS_INFINITY 335
#define TOK_PRESENT 336
#define TOK_PrintableString 337
#define TOK_PRIVATE 338
#define TOK_REAL 339
#define TOK_RELATIVE_OID 340
#define TOK_SEQUENCE 341
#define TOK_SET 342
#define TOK_SIZE 343
#define TOK_STRING 344
#define TOK_SYNTAX 345
#define TOK_T61String 346
#define TOK_TAGS 347
#define TOK_TeletexString 348
#define TOK_TRUE 349
#define TOK_TYPE_IDENTIFIER 350
#define TOK_UNIQUE 351
#define TOK_UNIVERSAL 352
#define TOK_UniversalString 353
#define TOK_UTCTime 354
#define TOK_UTF8String 355
#define TOK_VideotexString 356
#define TOK_VisibleString 357
#define TOK_WITH 358
#define UTF8_BOM 359
#define TOK_EXCEPT 360
#define TOK_INTERSECTION 361
#define TOK_UNION 362
#define TOK_TwoDots 363
#define TOK_ThreeDots 364




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
const char *asn1p_parse_debug_filename;
#define ASN_FILENAME asn1p_parse_debug_filename

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
#line 90 "asn1p_y.y"
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
#line 440 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 453 "asn1p_y.c"

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
#define YYLAST   932

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  137
/* YYNRULES -- Number of rules.  */
#define YYNRULES  339
/* YYNRULES -- Number of states.  */
#define YYNSTATES  524

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   121,     2,     2,     2,     2,     2,     2,
     114,   115,     2,     2,   117,     2,   122,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   118,   116,
     123,     2,     2,     2,   124,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   119,     2,   120,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,   108,   113,     2,     2,     2,     2,
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
     105,   107,   109,   110,   111
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
     502,   505,   507,   509,   511,   514,   517,   519,   521,   524,
     527,   529,   531,   533,   535,   537,   539,   542,   544,   549,
     554,   560,   565,   569,   571,   573,   575,   577,   579,   581,
     583,   585,   587,   589,   591,   593,   595,   597,   599,   601,
     603,   605,   606,   608,   609,   611,   616,   618,   622,   627,
     629,   631,   633,   635,   637,   641,   647,   649,   653,   655,
     659,   661,   665,   667,   671,   676,   680,   682,   684,   688,
     692,   696,   700,   702,   704,   705,   709,   712,   715,   717,
     719,   721,   723,   725,   727,   729,   731,   733,   735,   737,
     741,   745,   747,   749,   751,   755,   761,   763,   767,   771,
     772,   774,   776,   778,   780,   782,   784,   786,   787,   793,
     796,   798,   801,   804,   808,   810,   812,   816,   821,   823,
     827,   830,   834,   836,   840,   841,   843,   845,   848,   850,
     854,   856,   858,   862,   867,   872,   874,   878,   883,   888,
     890,   892,   896,   898,   903,   908,   910,   912,   914,   916,
     918,   920,   921,   923,   926,   931,   932,   934,   936,   938,
     939,   941,   943,   945,   947,   949,   950,   952,   954,   956
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     126,     0,    -1,   104,   127,    -1,   127,    -1,   128,    -1,
     127,   128,    -1,    -1,   256,   129,   130,    42,   134,     3,
      29,   137,    47,    -1,    -1,   131,    -1,   112,   132,   113,
      -1,   112,   113,    -1,   133,    -1,   132,   133,    -1,   259,
      -1,   259,   114,    12,   115,    -1,    12,    -1,    -1,   135,
      -1,   136,    -1,   135,   136,    -1,    49,    92,    -1,    60,
      92,    -1,    28,    92,    -1,    51,    61,    -1,    18,    65,
      -1,    -1,   138,    -1,   150,   142,   139,    -1,   140,    -1,
     139,   140,    -1,   157,    -1,   187,    -1,   155,    -1,    -1,
      46,    18,   141,    -1,   197,    -1,    -1,   143,    -1,    62,
     144,   116,    -1,    62,    54,    -1,    -1,   145,    -1,   147,
      -1,   145,   147,    -1,    -1,   131,    -1,   148,    54,   256,
     146,    -1,   149,    -1,   148,   117,   149,    -1,   256,    -1,
     256,   112,   113,    -1,   259,    -1,    -1,   151,    -1,    50,
     152,   116,    -1,    50,    25,   116,    -1,    50,   116,    -1,
     153,    -1,   152,   117,   153,    -1,   256,    -1,   256,   112,
     113,    -1,   259,    -1,   112,   206,   113,    -1,   256,   156,
       3,   154,    -1,   196,    -1,   181,    -1,   181,   112,   160,
     113,    -1,   256,     3,   177,    -1,   256,     3,   167,    -1,
     256,   112,   158,   113,     3,   177,    -1,   256,   112,   158,
     113,     3,   167,    -1,   159,    -1,   158,   117,   159,    -1,
     256,    -1,   256,   118,   259,    -1,   256,   118,   256,    -1,
     194,   118,   259,    -1,   194,   118,   256,    -1,   161,    -1,
     160,   117,   161,    -1,   177,    -1,   190,    -1,   259,    -1,
     154,    -1,    -1,   163,    -1,   164,    -1,   163,   117,   164,
      -1,   163,   117,     4,   163,     5,    -1,   259,   177,   238,
      -1,   177,   238,    -1,    38,    76,   177,    -1,   176,    -1,
     166,    -1,   165,   117,   166,    -1,   259,   177,    -1,   176,
      -1,   177,    -1,    36,   112,   169,   113,   171,    -1,    -1,
      96,    -1,   170,    -1,   169,   117,   170,    -1,    19,   238,
      -1,    20,   177,   168,   238,    -1,    20,   185,   238,    -1,
      20,   186,   238,    -1,    19,   185,   238,    -1,    19,   177,
     238,    -1,    19,   186,   238,    -1,    -1,   172,    -1,    -1,
     103,    90,   112,   173,   174,   113,    -1,   175,    -1,   174,
     175,    -1,     6,    -1,    21,    -1,   184,    -1,   119,   174,
     120,    -1,   111,    -1,   111,   121,   191,    -1,   111,   121,
     249,    -1,   251,   179,   200,    -1,    -1,   178,   180,    -1,
     156,    -1,    35,   112,   165,   113,    -1,    86,   112,   162,
     113,    -1,    87,   112,   162,   113,    -1,    86,   201,    76,
     258,   251,   179,    -1,    87,   201,    76,   258,   251,   179,
      -1,    26,    -1,    26,    43,    33,   259,    -1,    64,    76,
     181,    -1,    17,    -1,    17,   122,   256,    -1,   257,   122,
     256,    -1,    17,   122,   259,    -1,   257,    -1,   257,   122,
     182,    -1,   183,    -1,   182,   122,   183,    -1,   184,    -1,
      19,    -1,    20,    -1,    19,    -1,   185,   122,    19,    -1,
     185,   122,    20,    -1,    18,    -1,   259,   177,     3,   188,
      -1,   190,    -1,   191,    -1,   259,   118,   188,    -1,    -1,
     112,   189,   193,    -1,    71,    -1,    53,    -1,    94,    -1,
       8,    -1,    10,    -1,   192,    -1,   249,    -1,   259,    -1,
     256,   122,   259,    -1,     9,    -1,    15,    -1,    16,    -1,
       7,    -1,   193,     7,    -1,    32,    -1,    71,    -1,    84,
      -1,    75,    89,    -1,    73,    59,    -1,    85,    -1,    52,
      -1,    44,    79,    -1,    34,    89,    -1,    99,    -1,    55,
      -1,   197,    -1,   195,    -1,    66,    -1,    48,    -1,    30,
      89,    -1,   194,    -1,    66,   112,   242,   113,    -1,    48,
     112,   246,   113,    -1,    30,    89,   112,   244,   113,    -1,
      22,   112,   240,   113,    -1,    22,   112,   113,    -1,    31,
      -1,    56,    -1,    57,    -1,    58,    -1,    67,    -1,    72,
      -1,    82,    -1,    91,    -1,    93,    -1,    98,    -1,   100,
      -1,   101,    -1,   102,    -1,    74,    -1,   108,    -1,   109,
      -1,   106,    -1,   107,    -1,    -1,   202,    -1,    -1,   202,
      -1,    88,   114,   204,   115,    -1,   203,    -1,   114,   204,
     115,    -1,   203,   114,   204,   115,    -1,   205,    -1,   227,
      -1,   206,    -1,   111,    -1,   207,    -1,   207,   117,   111,
      -1,   207,   117,   111,   117,   207,    -1,   208,    -1,    25,
     105,   211,    -1,   209,    -1,   208,   198,   209,    -1,   210,
      -1,   209,   199,   210,    -1,   211,    -1,   211,   105,   211,
      -1,   214,   114,   206,   115,    -1,   114,   206,   115,    -1,
     215,    -1,   217,    -1,   215,   231,   215,    -1,    69,   231,
     215,    -1,   215,   231,    68,    -1,    69,   231,    68,    -1,
     218,    -1,   213,    -1,    -1,   112,   212,   193,    -1,    78,
       9,    -1,    78,   259,    -1,    88,    -1,    54,    -1,    53,
      -1,    94,    -1,   250,    -1,   192,    -1,   216,    -1,   259,
      -1,     8,    -1,    10,    -1,   177,    -1,   103,    37,   219,
      -1,   103,    38,   220,    -1,   202,    -1,   221,    -1,   222,
      -1,   112,   223,   113,    -1,   112,   111,   117,   223,   113,
      -1,   224,    -1,   223,   117,   224,    -1,   261,   200,   225,
      -1,    -1,   226,    -1,    81,    -1,    23,    -1,    77,    -1,
     228,    -1,   232,    -1,   230,    -1,    -1,    39,    33,   112,
     229,   193,    -1,    40,   177,    -1,   110,    -1,   110,   123,
      -1,   123,   110,    -1,   123,   110,   123,    -1,   233,    -1,
     234,    -1,   112,   256,   113,    -1,   233,   112,   235,   113,
      -1,   236,    -1,   235,   117,   236,    -1,   124,   237,    -1,
     124,   122,   237,    -1,   259,    -1,   237,   122,   259,    -1,
      -1,   239,    -1,    77,    -1,    41,   188,    -1,   241,    -1,
     240,   117,   241,    -1,   259,    -1,   243,    -1,   242,   117,
     243,    -1,   259,   114,   249,   115,    -1,   259,   114,   191,
     115,    -1,   245,    -1,   244,   117,   245,    -1,   259,   114,
      12,   115,    -1,   259,   114,   191,   115,    -1,   247,    -1,
     248,    -1,   247,   117,   248,    -1,   259,    -1,   259,   114,
     249,   115,    -1,   259,   114,   191,   115,    -1,   249,    -1,
     111,    -1,    12,    -1,    13,    -1,   249,    -1,    14,    -1,
      -1,   252,    -1,   253,   255,    -1,   119,   254,    12,   120,
      -1,    -1,    97,    -1,    27,    -1,    83,    -1,    -1,    60,
      -1,    49,    -1,    17,    -1,    18,    -1,    18,    -1,    -1,
     259,    -1,    11,    -1,   259,    -1,   260,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   378,   378,   381,   387,   392,   409,   409,   438,   439,
     443,   446,   452,   458,   467,   471,   475,   485,   486,   495,
     498,   507,   510,   513,   516,   520,   541,   542,   551,   564,
     567,   584,   591,   605,   613,   612,   626,   639,   640,   643,
     653,   659,   660,   663,   668,   675,   676,   680,   691,   696,
     703,   709,   715,   725,   726,   738,   741,   744,   752,   757,
     764,   770,   776,   785,   788,   798,   811,   821,   841,   847,
     863,   869,   877,   886,   897,   901,   909,   917,   925,   936,
     941,   948,   951,   959,   970,   993,   994,   997,  1002,  1006,
    1014,  1021,  1027,  1034,  1040,  1045,  1052,  1057,  1060,  1067,
    1077,  1078,  1082,  1089,  1099,  1109,  1120,  1130,  1141,  1151,
    1162,  1174,  1175,  1182,  1181,  1190,  1194,  1201,  1205,  1208,
    1212,  1218,  1226,  1235,  1247,  1271,  1278,  1297,  1300,  1306,
    1312,  1318,  1328,  1338,  1344,  1356,  1371,  1379,  1390,  1401,
    1412,  1420,  1442,  1450,  1459,  1463,  1468,  1477,  1482,  1487,
    1495,  1518,  1528,  1529,  1530,  1537,  1537,  1542,  1550,  1555,
    1560,  1565,  1570,  1573,  1579,  1590,  1608,  1612,  1617,  1625,
    1634,  1649,  1650,  1651,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,  1659,  1660,  1661,  1668,  1669,  1670,  1674,  1680,  1685,
    1690,  1695,  1700,  1709,  1710,  1714,  1718,  1719,  1720,  1721,
    1722,  1726,  1727,  1728,  1729,  1733,  1734,  1741,  1741,  1742,
    1742,  1746,  1747,  1751,  1752,  1753,  1759,  1765,  1768,  1773,
    1773,  1775,  1778,  1782,  1783,  1789,  1800,  1801,  1807,  1808,
    1814,  1815,  1822,  1823,  1829,  1837,  1845,  1851,  1857,  1864,
    1872,  1880,  1889,  1890,  1891,  1891,  1901,  1906,  1918,  1921,
    1927,  1932,  1937,  1938,  1939,  1940,  1954,  1959,  1967,  1978,
    1981,  1987,  1988,  1988,  1989,  1991,  2004,  2009,  2015,  2029,
    2030,  2034,  2037,  2040,  2048,  2049,  2050,  2055,  2054,  2066,
    2075,  2076,  2077,  2078,  2081,  2084,  2093,  2109,  2115,  2121,
    2135,  2146,  2162,  2165,  2185,  2189,  2193,  2197,  2204,  2209,
    2215,  2224,  2229,  2236,  2244,  2254,  2259,  2266,  2274,  2284,
    2299,  2304,  2311,  2318,  2326,  2334,  2341,  2352,  2356,  2363,
    2364,  2395,  2396,  2400,  2407,  2413,  2414,  2415,  2416,  2420,
    2421,  2422,  2426,  2430,  2438,  2445,  2446,  2452,  2459,  2465
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PPEQ", "TOK_VBracketLeft",
  "TOK_VBracketRight", "TOK_whitespace", "TOK_opaque", "TOK_bstring",
  "TOK_cstring", "TOK_hstring", "\"identifier\"", "\"number\"",
  "\"negative number\"", "TOK_realnumber", "TOK_tuple", "TOK_quadruple",
  "TOK_typereference", "TOK_capitalreference", "TOK_typefieldreference",
  "TOK_valuefieldreference", "TOK_Literal", "TOK_ExtValue_BIT_STRING",
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
  "TOK_VideotexString", "TOK_VisibleString", "TOK_WITH",
  "\"UTF-8 byte order mark\"", "TOK_EXCEPT", "'^'", "TOK_INTERSECTION",
  "'|'", "TOK_UNION", "\"..\"", "\"...\"", "'{'", "'}'", "'('", "')'",
  "';'", "','", "':'", "'['", "']'", "'!'", "'.'", "'<'", "'@'", "$accept",
  "ParsedGrammar", "ModuleList", "ModuleDefinition", "@1",
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
  "UnionMark", "IntersectionMark", "optConstraints", "optSizeConstraints",
  "Constraint", "SetOfConstraints", "ConstraintSpec", "SubtypeConstraint",
  "ElementSetSpecs", "ElementSetSpec", "Unions", "Intersections",
  "IntersectionElements", "ConstraintSubtypeElement", "@5",
  "PatternConstraint", "ConstraintType", "SingleValue", "BitStringValue",
  "ContainedSubtype", "InnerTypeConstraint", "SingleTypeConstraint",
  "MultipleTypeConstraints", "FullSpecification", "PartialSpecification",
  "TypeConstraints", "NamedConstraint", "optPresenceConstraint",
  "PresenceConstraint", "GeneralConstraint", "UserDefinedConstraint", "@6",
  "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint",
  "SimpleTableConstraint", "ComponentRelationConstraint", "AtNotationList",
  "AtNotationElement", "ComponentIdList", "optMarker", "Marker",
  "IdentifierList", "IdentifierElement", "NamedNumberList", "NamedNumber",
  "NamedBitList", "NamedBit", "Enumerations", "UniverationList",
  "UniverationElement", "SignedNumber", "RealValue", "optTag", "Tag",
  "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName",
  "ObjectClassReference", "optIdentifier", "Identifier",
  "IdentifierAsReference", "IdentifierAsValue", 0
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
     355,   356,   357,   358,   359,   360,    94,   361,   124,   362,
     363,   364,   123,   125,    40,    41,    59,    44,    58,    91,
      93,    33,    46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   125,   126,   126,   127,   127,   129,   128,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   137,   137,   138,   139,
     139,   140,   140,   140,   141,   140,   140,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   147,   148,   148,
     149,   149,   149,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   153,   154,   155,   156,   156,   156,   157,   157,
     157,   157,   158,   158,   159,   159,   159,   159,   159,   160,
     160,   161,   161,   161,   161,   162,   162,   163,   163,   163,
     164,   164,   164,   164,   165,   165,   166,   166,   166,   167,
     168,   168,   169,   169,   170,   170,   170,   170,   170,   170,
     170,   171,   171,   173,   172,   174,   174,   175,   175,   175,
     175,   176,   176,   176,   177,   178,   179,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   181,   181,   181,   181,
     181,   181,   182,   182,   183,   184,   184,   185,   185,   185,
     186,   187,   188,   188,   188,   189,   188,   188,   190,   190,
     190,   190,   190,   190,   191,   191,   192,   192,   192,   193,
     193,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   195,   195,   195,   196,   196,   196,
     196,   196,   196,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   198,   198,   199,
     199,   200,   200,   201,   201,   201,   202,   203,   203,   204,
     204,   205,   206,   206,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   212,   211,   213,   213,   214,   214,
     215,   215,   215,   215,   215,   215,   216,   216,   217,   218,
     218,   219,   220,   220,   221,   222,   223,   223,   224,   225,
     225,   226,   226,   226,   227,   227,   227,   229,   228,   230,
     231,   231,   231,   231,   232,   232,   233,   234,   235,   235,
     236,   236,   237,   237,   238,   238,   239,   239,   240,   240,
     241,   242,   242,   243,   243,   244,   244,   245,   245,   246,
     247,   247,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   251,   251,   252,   253,   254,   254,   254,   254,   255,
     255,   255,   256,   256,   257,   258,   258,   259,   260,   261
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
       2,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     4,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     4,     1,     3,     4,     1,
       1,     1,     1,     1,     3,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     4,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     0,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     3,     5,     1,     3,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     2,
       1,     2,     2,     3,     1,     1,     3,     4,     1,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     1,     3,
       1,     1,     3,     4,     4,     1,     3,     4,     4,     1,
       1,     3,     1,     4,     4,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     4,     0,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   332,   333,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   337,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     193,     0,   194,   195,   196,   197,   198,   206,   199,   200,
     201,   202,   203,   204,   205,    28,    29,    33,    31,    32,
      36,     0,   321,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   321,   136,   334,     0,     0,   171,     0,     0,
     185,   177,   181,   184,   172,     0,     0,   173,   176,   180,
       0,     0,    66,   187,   183,    65,   182,   140,   325,     0,
     125,   322,   329,    45,    49,    51,    35,     0,    69,    68,
       0,     0,   186,   179,   178,     0,     0,   175,   174,     0,
     185,   184,     0,    72,     0,    74,     0,   321,     0,   327,
     328,   326,     0,     0,     0,   211,   331,   330,   323,    46,
      47,     0,   137,   139,   192,     0,   298,   300,     0,   317,
     318,   316,     0,   309,   310,   315,   312,     0,   301,     0,
     186,     0,     0,     0,     0,   321,    64,   160,   166,   161,
     167,   168,   158,   159,    84,     0,    79,    81,    82,   162,
     163,    83,   145,   146,   141,   142,   144,   138,     0,   157,
     155,   151,   152,   153,     0,   164,   133,     0,     0,   213,
     213,   127,   126,   321,   124,   212,   216,   321,   321,     0,
     102,   191,     0,     0,   305,     0,   189,     0,     0,   188,
       0,     0,   321,    73,    78,    77,    76,    75,   256,   257,
     320,     0,   250,   249,     0,     0,   248,   251,     0,   222,
     244,   321,   258,   253,     0,   223,   226,   228,   230,   232,
     243,     0,   236,   254,   237,   242,   319,   252,   255,    67,
     321,     0,   324,     0,     0,     0,     0,   321,     0,     0,
     321,     0,   214,   321,     0,     0,   321,   244,     0,   219,
     221,   220,   274,   276,   275,   284,   285,   321,   150,   147,
       0,   296,   294,   294,   294,   104,   295,   100,   294,   294,
     111,     0,   299,   190,     0,     0,   311,     0,     0,   164,
     302,     0,     0,    71,    70,   321,   280,     0,     0,   246,
     247,     0,     0,     0,     0,    63,     0,   207,   208,   321,
     209,   210,   321,   321,   321,     0,    80,   143,   169,   156,
     165,   154,     0,   121,     0,    94,    97,    98,   321,   135,
     321,     0,     0,    86,    87,    93,   294,   321,   335,     0,
     335,     0,   279,     0,   217,     0,     0,   297,   109,     0,
     108,   110,   101,   294,   106,   107,     0,    99,   112,   103,
     306,     0,     0,   314,   313,   304,   303,   227,   281,   282,
     241,   239,   261,   259,     0,   260,   262,   263,   245,   235,
     224,   229,   231,   233,     0,   240,   238,   170,   134,     0,
     128,   321,    96,     0,   321,   129,   321,    91,   294,   321,
     336,   130,   321,   277,   286,     0,     0,   288,   218,   148,
     149,   105,     0,   307,   308,   283,     0,     0,   266,   338,
     339,   211,   321,   234,   122,   123,    95,   215,    92,   321,
      88,    90,   125,   125,     0,     0,   290,   292,   287,     0,
     113,     0,   264,     0,   269,   225,     0,   131,   132,   278,
     291,     0,   289,     0,     0,   267,   272,   273,   271,   268,
     270,    89,   293,   117,   118,     0,     0,   115,   119,   265,
       0,   114,   116,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   136,    56,    57,    63,
      64,   170,    65,    66,    67,    46,    47,    50,    51,   204,
      87,   121,    88,   152,   153,   205,   206,   382,   383,   384,
     374,   375,   138,   403,   239,   240,   407,   408,   503,   516,
     517,   385,   272,   164,   165,   232,   122,   214,   215,   518,
     323,   324,    89,   221,   293,   222,   223,   273,   369,   123,
     124,   125,   126,   359,   362,   234,   301,   235,   236,   308,
     309,   310,   275,   276,   277,   278,   279,   353,   280,   281,
     282,   283,   284,   285,   423,   425,   426,   427,   467,   468,
     509,   510,   311,   312,   484,   313,   348,   314,   315,   316,
     456,   457,   486,   325,   326,   175,   176,   187,   188,   243,
     244,   182,   183,   184,   286,   287,   130,   131,   132,   162,
     168,   224,   127,   449,   288,   470,   471
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -330
static const yytype_int16 yypact[] =
{
      90,  -330,  -330,   158,    53,   158,  -330,  -330,   158,  -330,
    -330,   -47,    17,    30,  -330,  -330,  -330,  -330,    24,  -330,
     -35,   203,  -330,  -330,    99,   122,   113,   132,   173,   148,
     276,   203,  -330,   162,  -330,  -330,  -330,  -330,  -330,   266,
    -330,  -330,   274,    74,   237,  -330,   238,  -330,   210,  -330,
     116,  -330,   197,  -330,  -330,   193,   676,  -330,  -330,  -330,
     281,   215,  -330,   236,   281,  -330,    -5,  -330,   242,  -330,
    -330,   338,  -330,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,   676,  -330,  -330,  -330,  -330,
    -330,   604,   240,  -330,  -330,  -330,  -330,   158,   281,   264,
    -330,  -330,     1,   258,  -330,   269,   294,  -330,   295,   306,
     275,  -330,  -330,   277,  -330,   327,   301,  -330,  -330,  -330,
     830,   388,   283,  -330,  -330,  -330,  -330,   271,   140,   393,
    -330,  -330,   123,   -47,  -330,  -330,  -330,   285,  -330,  -330,
     281,    19,   287,  -330,  -330,    82,   389,  -330,  -330,   312,
    -330,  -330,    71,  -330,   284,   286,   291,   106,   313,  -330,
    -330,  -330,   394,   233,   753,   296,  -330,  -330,  -330,  -330,
    -330,   328,  -330,  -330,  -330,    78,  -330,  -330,   389,  -330,
    -330,  -330,   292,   297,  -330,  -330,   299,   103,  -330,   303,
    -330,   405,   830,   281,   281,   437,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,   142,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,   289,  -330,  -330,  -330,   302,  -330,
    -330,  -330,  -330,  -330,   308,   307,   366,   309,   343,   114,
     115,  -330,  -330,   304,  -330,  -330,   310,   145,    22,   143,
    -330,  -330,   389,   144,  -330,   314,  -330,    82,   263,  -330,
     389,   263,     1,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,   321,  -330,  -330,   -20,   208,  -330,  -330,   324,  -330,
    -330,   437,  -330,  -330,   318,   315,   255,   259,  -330,   330,
    -330,   319,   -20,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
     106,   348,  -330,   429,   389,   233,   404,    66,   352,   325,
      12,   362,  -330,    12,   364,   408,   240,   158,   329,  -330,
    -330,  -330,  -330,  -330,  -330,   342,  -330,   304,  -330,  -330,
     233,  -330,    10,    21,    10,  -330,  -330,   346,    21,    10,
     353,   328,  -330,  -330,   389,   196,  -330,   340,   344,  -330,
    -330,   345,   349,  -330,  -330,   555,   334,   351,   257,  -330,
    -330,   296,   354,   429,   350,  -330,   347,  -330,  -330,   555,
    -330,  -330,   555,   555,   437,   326,  -330,  -330,  -330,   456,
    -330,  -330,   389,   356,   176,  -330,  -330,  -330,   240,  -330,
     304,   392,   357,   358,  -330,  -330,    10,   240,   389,   359,
     389,   368,  -330,   361,  -330,   360,   363,  -330,  -330,   355,
    -330,  -330,  -330,    10,  -330,  -330,   379,  -330,  -330,  -330,
    -330,   367,   370,  -330,  -330,  -330,  -330,  -330,  -330,   365,
    -330,  -330,  -330,  -330,    31,  -330,  -330,  -330,   456,  -330,
     369,   259,  -330,  -330,   372,  -330,  -330,  -330,  -330,   263,
    -330,    66,  -330,   386,   240,  -330,    16,  -330,    10,   240,
    -330,  -330,   240,  -330,  -330,    14,   177,  -330,  -330,  -330,
    -330,  -330,   371,  -330,  -330,  -330,   385,   188,  -330,  -330,
    -330,   296,   484,  -330,  -330,  -330,  -330,  -330,  -330,    46,
    -330,  -330,  -330,  -330,   429,   389,   381,  -330,  -330,   360,
    -330,   389,  -330,   389,    23,  -330,     9,  -330,  -330,   456,
     381,   389,  -330,    61,   189,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,  -330,    61,    55,  -330,  -330,  -330,
      50,  -330,  -330,  -330
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -330,  -330,   468,   184,  -330,  -330,   374,  -330,   458,  -330,
    -330,   473,  -330,  -330,  -330,   420,  -330,  -330,  -330,  -330,
    -330,  -330,   444,  -330,   412,  -330,  -330,  -330,   451,   373,
    -330,   375,  -330,  -330,   320,  -330,   223,   211,    37,    72,
    -330,    76,   267,  -330,  -330,   190,  -330,  -330,  -330,     5,
    -213,  -289,   -91,  -330,  -111,  -330,   224,  -330,   232,  -153,
     288,   290,  -330,  -237,  -330,  -140,  -238,  -141,  -329,   -32,
    -330,  -330,   -30,  -330,  -330,    56,   300,  -211,  -330,  -207,
    -330,  -193,    52,  -330,   174,   170,  -300,  -330,  -330,  -330,
    -209,  -330,  -330,  -330,  -330,  -330,  -330,  -330,    43,    42,
    -330,  -330,  -330,  -330,  -330,  -330,   254,  -330,  -330,  -330,
    -330,    54,    57,  -290,  -330,  -330,   305,  -330,   311,  -330,
     207,  -330,  -330,   298,  -142,  -330,  -103,  -330,  -330,  -330,
    -330,     4,  -330,   154,   -12,  -330,  -330
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -295
static const yytype_int16 yytable[] =
{
      20,   129,   274,   185,     7,   216,    20,     7,   376,     7,
     337,   139,     7,   341,   511,   210,   209,   208,   302,   302,
     479,   210,   209,    15,   428,    15,    90,    15,    15,    16,
      15,    53,   398,   400,   401,    15,    16,   137,   404,   405,
     318,   319,    15,    69,    92,   417,   506,    52,    53,    97,
     381,   320,    69,     9,   381,    90,   513,    15,   371,    68,
      91,   513,   320,   433,    52,    12,   207,   513,    68,   212,
     213,   514,    21,    92,   212,   213,   514,    15,   354,    24,
     212,   213,   514,   397,   381,    15,    69,   321,   154,    91,
     346,     1,     2,    15,   179,   180,   447,   412,   321,    48,
     507,   133,    68,   347,   508,   185,   338,     1,     2,   342,
     396,    33,    98,   461,   197,   198,   199,    15,   179,   180,
     128,   200,   201,   373,   155,   -85,   446,   373,   173,   177,
      17,   128,   174,   186,   189,   128,   485,    22,   216,   421,
     422,   128,   466,   399,   172,   211,   322,   327,   210,   209,
     208,   225,   376,   210,   209,   499,   436,   373,   481,   202,
     154,   344,   217,   318,   319,   128,   245,   159,   521,   515,
     523,   434,   166,   443,   515,     1,     2,   373,   210,   209,
     515,   255,   257,   167,   191,   128,   320,    34,   192,    10,
      49,   241,    10,   181,     3,   242,   155,   254,   256,   207,
     203,   474,   299,   299,    15,    35,   377,    15,   411,   386,
       1,     2,   386,     1,     2,   392,   249,   349,   195,    15,
     250,    25,   321,   160,    36,   128,   300,   303,   233,   233,
     177,    26,    59,    60,    37,   186,   339,   161,   189,   339,
      38,   197,   198,   199,    15,   179,   180,    62,   200,   201,
       1,     2,    27,   350,    28,   289,   330,   333,  -294,   290,
     331,   334,  -294,    29,   128,   258,   198,   259,    15,   179,
     180,   260,   200,   201,    15,   179,   180,    41,   211,    39,
       1,     2,   370,   225,    54,   378,   202,   442,   387,   440,
     488,   387,    15,   441,   489,    42,   448,   475,     1,     2,
      55,   492,   519,   522,   219,   493,   493,   522,   225,    61,
     262,   393,   258,   198,   259,    15,   179,   180,   260,   200,
     201,   -26,   245,   339,    43,   420,    58,   203,    94,   261,
       1,     2,   212,   213,   258,   198,   259,    15,   179,   180,
     260,   200,   201,   305,   306,   220,   482,   237,   238,   483,
     377,   267,    95,   478,    99,   386,   100,   262,   263,   128,
     438,   351,   352,   357,   358,   360,   361,   212,   213,   103,
     104,   497,   498,   264,   459,   460,   450,   135,   450,   262,
     140,   141,   265,   142,   143,   144,   147,   145,   386,   146,
     148,   156,   266,   158,   435,   157,   163,   171,   267,   178,
      15,   190,   193,   195,   194,   246,   218,   268,   252,   296,
     233,   291,   469,   248,   247,   269,   307,   251,   271,   298,
     267,   297,   292,   128,   317,   295,   345,   339,   335,   378,
     294,   355,   356,   364,   387,   363,   368,   372,   388,   380,
     390,   391,   402,   487,   394,   258,   198,   259,    15,   179,
     180,   260,   200,   201,   395,   413,   406,   418,   430,   414,
     415,   419,   261,   437,   416,   429,   424,   387,   444,   462,
     445,     8,   451,   487,   454,   446,    23,   439,   458,   469,
     453,   469,   463,   490,   455,   464,   472,   473,   465,   512,
     262,   263,   258,   198,   259,    15,   179,   180,   260,   200,
     201,   477,   491,   501,    40,   101,   264,   169,    96,   261,
     134,    93,   253,   366,   389,   265,   496,   476,   480,   343,
     520,   409,   379,   367,   495,   266,   328,   494,   329,   196,
     304,   267,   432,   431,   504,   505,   365,   262,   263,   231,
     268,   410,   500,   502,   452,   336,     0,   332,   269,   270,
       0,   271,     0,   264,     0,     0,   128,     0,     0,     0,
       0,   340,   265,   258,   198,   259,    15,   179,   180,   260,
     200,   201,   266,     0,     0,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,   271,     0,
       0,     0,     0,   128,     0,     0,     0,   102,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,   264,     0,   105,     0,     0,     0,
       0,     0,     0,   265,   106,    70,   107,     0,   108,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   109,   267,
       0,     0,   110,     0,     0,     0,   111,     0,   268,   112,
      72,    73,    74,     0,     0,     0,     0,   270,     0,   271,
     113,    75,     0,     0,   128,   114,    76,   115,    77,   116,
       0,     0,     0,     0,     0,     0,    78,    15,   117,   118,
       0,     0,     0,     1,     2,    79,     0,    80,     0,     0,
       0,     0,    81,   119,    82,    83,    84,    70,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,    76,     0,
      77,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,    80,
     103,   104,     0,     0,    81,   105,    82,    83,    84,   226,
       0,     0,     0,   106,    70,   107,     0,   108,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,   110,     0,     0,     0,   111,     0,     0,   112,    72,
      73,    74,     0,     0,     0,     0,     0,   228,     0,   113,
      75,     0,     0,     0,   114,    76,   115,    77,   116,     0,
       0,     0,     0,     0,     0,    78,     0,   117,   118,   229,
     230,     0,     0,     0,    79,     0,    80,     1,     2,     0,
       0,    81,   119,    82,    83,    84,     0,     0,     0,     0,
     149,    70,   107,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,   150,     0,
       0,     0,   111,     0,     0,   112,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   151,    75,     0,     0,
       0,   114,    76,   115,    77,   116,     0,     0,     0,     0,
       0,     0,    78,     0,   117,   118,     0,     0,     0,     0,
       0,    79,     0,    80,     0,     0,     0,     0,    81,   119,
      82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,    92,   195,   145,     0,   158,    18,     3,   297,     5,
     248,   102,     8,   251,     5,   157,   157,   157,   229,   230,
       4,   163,   163,    11,   353,    11,    56,    11,    11,    12,
      11,    43,   322,   323,   324,    11,    12,    36,   328,   329,
      18,    19,    11,    55,    56,   345,    23,    43,    60,    54,
      38,    41,    64,     0,    38,    85,     6,    11,   295,    55,
      56,     6,    41,   363,    60,   112,   157,     6,    64,    19,
      20,    21,    42,    85,    19,    20,    21,    11,   271,   114,
      19,    20,    21,   320,    38,    11,    98,    77,   120,    85,
     110,    17,    18,    11,    12,    13,   386,   335,    77,    25,
      77,    97,    98,   123,    81,   247,   248,    17,    18,   251,
     317,    12,   117,   403,     8,     9,    10,    11,    12,    13,
     119,    15,    16,   111,   120,   113,   117,   111,   140,   141,
     113,   119,   113,   145,   146,   119,   122,   113,   291,   348,
     351,   119,   111,   122,   140,   157,   237,   238,   290,   290,
     290,   163,   441,   295,   295,   484,   365,   111,   448,    53,
     192,   252,   158,    18,    19,   119,   178,    27,   113,   119,
     120,   364,    49,   380,   119,    17,    18,   111,   320,   320,
     119,   193,   194,    60,   113,   119,    41,    65,   117,     5,
     116,   113,     8,   111,   104,   117,   192,   193,   194,   290,
      94,   439,    88,    88,    11,    92,   297,    11,    12,   300,
      17,    18,   303,    17,    18,   306,   113,     9,   112,    11,
     117,    18,    77,    83,    92,   119,   112,   112,   114,   114,
     242,    28,   116,   117,    61,   247,   248,    97,   250,   251,
      92,     8,     9,    10,    11,    12,    13,    54,    15,    16,
      17,    18,    49,   265,    51,   113,   113,   113,   113,   117,
     117,   117,   117,    60,   119,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    11,    12,    13,   115,   290,     3,
      17,    18,   294,   295,    47,   297,    53,   378,   300,   113,
     113,   303,    11,   117,   117,    29,   387,   439,    17,    18,
      62,   113,   113,   516,    71,   117,   117,   520,   320,   112,
      53,   307,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    47,   334,   335,    50,    68,   116,    94,   113,    25,
      17,    18,    19,    20,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    39,    40,   112,   449,    19,    20,   452,
     441,    94,   116,   444,   112,   446,    18,    53,    54,   119,
     372,    37,    38,   108,   109,   106,   107,    19,    20,    17,
      18,   482,   483,    69,    19,    20,   388,   113,   390,    53,
     122,   112,    78,    89,    89,    79,    59,   112,   479,   112,
      89,     3,    88,   122,    68,   112,     3,   112,    94,   112,
      11,    89,   118,   112,   118,   113,    12,   103,     3,    43,
     114,   122,   424,   114,   117,   111,   112,   114,   114,    76,
      94,   112,   120,   119,   114,   118,   105,   439,   114,   441,
     122,   113,   117,   114,   446,   105,     7,    33,    76,   114,
      76,    33,    96,   455,   115,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   112,   115,   103,   123,   111,   115,
     115,   110,    25,     7,   115,   115,   112,   479,    76,    90,
     113,     3,   113,   485,   113,   117,    18,   121,   115,   491,
     112,   493,   115,   112,   124,   115,   117,   115,   123,   501,
      53,    54,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   115,   117,   122,    31,    85,    69,   133,    64,    25,
      98,    60,   192,   290,   303,    78,   479,   441,   446,   252,
     515,   331,   298,   291,   472,    88,   238,   471,   238,   156,
     230,    94,   362,   359,   491,   493,   282,    53,    54,   164,
     103,   334,   485,   489,   390,   247,    -1,   242,   111,   112,
      -1,   114,    -1,    69,    -1,    -1,   119,    -1,    -1,    -1,
      -1,   250,    78,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,     3,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    69,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    44,    94,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,   103,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,   112,    -1,   114,
      66,    67,    -1,    -1,   119,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    11,    84,    85,
      -1,    -1,    -1,    17,    18,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    93,
      17,    18,    -1,    -1,    98,    22,   100,   101,   102,    26,
      -1,    -1,    -1,    30,    31,    32,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    85,    86,
      87,    -1,    -1,    -1,    91,    -1,    93,    17,    18,    -1,
      -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    17,    18,   104,   126,   127,   128,   256,   127,     0,
     128,   129,   112,   130,   131,    11,    12,   113,   132,   133,
     259,    42,   113,   133,   114,    18,    28,    49,    51,    60,
     134,   135,   136,    12,    65,    92,    92,    61,    92,     3,
     136,   115,    29,    50,   137,   138,   150,   151,    25,   116,
     152,   153,   256,   259,    47,    62,   142,   143,   116,   116,
     117,   112,    54,   144,   145,   147,   148,   149,   256,   259,
      31,    46,    56,    57,    58,    67,    72,    74,    82,    91,
      93,    98,   100,   101,   102,   139,   140,   155,   157,   187,
     197,   256,   259,   153,   113,   116,   147,    54,   117,   112,
      18,   140,     3,    17,    18,    22,    30,    32,    34,    44,
      48,    52,    55,    66,    71,    73,    75,    84,    85,    99,
     112,   156,   181,   194,   195,   196,   197,   257,   119,   177,
     251,   252,   253,   256,   149,   113,   141,    36,   167,   177,
     122,   112,    89,    89,    79,   112,   112,    59,    89,    30,
      48,    66,   158,   159,   194,   256,     3,   112,   122,    27,
      83,    97,   254,     3,   178,   179,    49,    60,   255,   131,
     146,   112,   256,   259,   113,   240,   241,   259,   112,    12,
      13,   111,   246,   247,   248,   249,   259,   242,   243,   259,
      89,   113,   117,   118,   118,   112,   154,     8,     9,    10,
      15,    16,    53,    94,   154,   160,   161,   177,   190,   192,
     249,   259,    19,    20,   182,   183,   184,   256,    12,    71,
     112,   188,   190,   191,   256,   259,    26,    35,    64,    86,
      87,   156,   180,   114,   200,   202,   203,    19,    20,   169,
     170,   113,   117,   244,   245,   259,   113,   117,   114,   113,
     117,   114,     3,   159,   256,   259,   256,   259,     8,    10,
      14,    25,    53,    54,    69,    78,    88,    94,   103,   111,
     112,   114,   177,   192,   206,   207,   208,   209,   210,   211,
     213,   214,   215,   216,   217,   218,   249,   250,   259,   113,
     117,   122,   120,   189,   122,   118,    43,   112,    76,    88,
     112,   201,   202,   112,   201,    39,    40,   112,   204,   205,
     206,   227,   228,   230,   232,   233,   234,   114,    18,    19,
      41,    77,   177,   185,   186,   238,   239,   177,   185,   186,
     113,   117,   241,   113,   117,   114,   248,   191,   249,   259,
     243,   191,   249,   167,   177,   105,   110,   123,   231,     9,
     259,    37,    38,   212,   206,   113,   117,   108,   109,   198,
     106,   107,   199,   105,   114,   231,   161,   183,     7,   193,
     259,   188,    33,   111,   165,   166,   176,   177,   259,   181,
     114,    38,   162,   163,   164,   176,   177,   259,    76,   162,
      76,    33,   177,   256,   115,   112,   204,   188,   238,   122,
     238,   238,    96,   168,   238,   238,   103,   171,   172,   170,
     245,    12,   191,   115,   115,   115,   115,   211,   123,   110,
      68,   215,   202,   219,   112,   220,   221,   222,   193,   115,
     111,   209,   210,   211,   206,    68,   215,     7,   259,   121,
     113,   117,   177,   204,    76,   113,   117,   238,   177,   258,
     259,   113,   258,   112,   113,   124,   235,   236,   115,    19,
      20,   238,    90,   115,   115,   123,   111,   223,   224,   259,
     260,   261,   117,   115,   191,   249,   166,   115,   177,     4,
     164,   238,   251,   251,   229,   122,   237,   259,   113,   117,
     112,   117,   113,   117,   200,   207,   163,   179,   179,   193,
     237,   122,   236,   173,   223,   224,    23,    77,    81,   225,
     226,     5,   259,     6,    21,   119,   174,   175,   184,   113,
     174,   113,   175,   120
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
#line 378 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(2) - (2)].a_grammar);
	}
    break;

  case 3:
#line 381 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 4:
#line 387 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 5:
#line 392 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 6:
#line 409 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 7:
#line 414 "asn1p_y.y"
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
#line 438 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 9:
#line 439 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 10:
#line 443 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 11:
#line 446 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 12:
#line 452 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(1) - (1)].a_oid_arc));
		if((yyvsp[(1) - (1)].a_oid_arc).name)
			free((yyvsp[(1) - (1)].a_oid_arc).name);
	}
    break;

  case 13:
#line 458 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(1) - (2)].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(2) - (2)].a_oid_arc));
		if((yyvsp[(2) - (2)].a_oid_arc).name)
			free((yyvsp[(2) - (2)].a_oid_arc).name);
	}
    break;

  case 14:
#line 467 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
    break;

  case 15:
#line 471 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 16:
#line 475 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[(1) - (1)].a_int);
	}
    break;

  case 17:
#line 485 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 18:
#line 486 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 495 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 20:
#line 498 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 21:
#line 507 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 22:
#line 510 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 23:
#line 513 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 24:
#line 516 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 25:
#line 520 "asn1p_y.y"
    {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp((yyvsp[(1) - (2)].tv_str), "TAG") == 0) {
		 	(yyval.a_module_flags) = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp((yyvsp[(1) - (2)].tv_str), "XER") == 0) {
		 	(yyval.a_module_flags) = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at %s:%d: "
				"Unrecognized encoding reference\n",
				(yyvsp[(1) - (2)].tv_str), ASN_FILENAME, yylineno);
		 	(yyval.a_module_flags) = MSF_unk_INSTRUCTIONS;
		}
		free((yyvsp[(1) - (2)].tv_str));
	}
    break;

  case 26:
#line 541 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 27:
#line 542 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 28:
#line 551 "asn1p_y.y"
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
#line 564 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 30:
#line 567 "asn1p_y.y"
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
#line 584 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 32:
#line 591 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 33:
#line 605 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 34:
#line 613 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 35:
#line 614 "asn1p_y.y"
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at %s:%d ignored\n",
			(yyvsp[(2) - (3)].tv_str), ASN_FILENAME, yylineno);
		free((yyvsp[(2) - (3)].tv_str));
		(yyval.a_module) = 0;
	}
    break;

  case 36:
#line 626 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 37:
#line 639 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 39:
#line 643 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 40:
#line 653 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 41:
#line 659 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 43:
#line 663 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 44:
#line 668 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 45:
#line 675 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 46:
#line 676 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 47:
#line 680 "asn1p_y.y"
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
#line 691 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 49:
#line 696 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 50:
#line 703 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 709 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 715 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 53:
#line 725 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 54:
#line 726 "asn1p_y.y"
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
#line 738 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 56:
#line 741 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 57:
#line 744 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 58:
#line 752 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 59:
#line 757 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 60:
#line 764 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 770 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 776 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 63:
#line 785 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 64:
#line 788 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 65:
#line 798 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 66:
#line 811 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 67:
#line 821 "asn1p_y.y"
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
#line 841 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 69:
#line 847 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 70:
#line 863 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 869 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 72:
#line 877 "asn1p_y.y"
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
#line 886 "asn1p_y.y"
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
#line 897 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 75:
#line 901 "asn1p_y.y"
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
#line 909 "asn1p_y.y"
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
#line 917 "asn1p_y.y"
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
#line 925 "asn1p_y.y"
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
#line 936 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 80:
#line 941 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 81:
#line 948 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 82:
#line 951 "asn1p_y.y"
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
#line 959 "asn1p_y.y"
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
#line 970 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 85:
#line 993 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 86:
#line 994 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 87:
#line 997 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 88:
#line 1002 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 89:
#line 1006 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (5)].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
		asn1p_expr_free((yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 90:
#line 1014 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 91:
#line 1021 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 92:
#line 1027 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 93:
#line 1034 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 94:
#line 1040 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 95:
#line 1045 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 96:
#line 1052 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 97:
#line 1057 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 98:
#line 1060 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 99:
#line 1067 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 100:
#line 1077 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 101:
#line 1078 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 102:
#line 1082 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 103:
#line 1089 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 104:
#line 1099 "asn1p_y.y"
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
#line 1109 "asn1p_y.y"
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
#line 1120 "asn1p_y.y"
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
#line 1130 "asn1p_y.y"
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
#line 1141 "asn1p_y.y"
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
#line 1151 "asn1p_y.y"
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
#line 1162 "asn1p_y.y"
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
#line 1174 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 112:
#line 1175 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 113:
#line 1182 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 114:
#line 1184 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 115:
#line 1190 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 116:
#line 1194 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 117:
#line 1201 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 118:
#line 1205 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 119:
#line 1208 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 120:
#line 1212 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 121:
#line 1218 "asn1p_y.y"
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
#line 1226 "asn1p_y.y"
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
#line 1235 "asn1p_y.y"
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
#line 1247 "asn1p_y.y"
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
#line 1271 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 126:
#line 1278 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		(yyval.a_expr)->marker.flags |= (yyvsp[(1) - (2)].a_int);

		if(((yyval.a_expr)->marker.flags & EM_INDIRECT)
		&& ((yyval.a_expr)->marker.flags & EM_OPTIONAL) != EM_OPTIONAL) {
			fprintf(stderr,
				"INFO: Directive <ASN1C:RepresentAsPointer> "
				"applied to %s at %s:%d\n",
				ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					?  ASN_EXPR_TYPE2STR((yyval.a_expr)->expr_type)
					: "member",
				ASN_FILENAME, (yyval.a_expr)->_lineno
			);
		}
	}
    break;

  case 127:
#line 1297 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 128:
#line 1300 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1306 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 130:
#line 1312 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 131:
#line 1318 "asn1p_y.y"
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
#line 1328 "asn1p_y.y"
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
#line 1338 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1344 "asn1p_y.y"
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
#line 1356 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1371 "asn1p_y.y"
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
#line 1379 "asn1p_y.y"
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
#line 1390 "asn1p_y.y"
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
#line 1401 "asn1p_y.y"
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
#line 1412 "asn1p_y.y"
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
#line 1420 "asn1p_y.y"
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
#line 1442 "asn1p_y.y"
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
#line 1450 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 145:
#line 1463 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 146:
#line 1468 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 147:
#line 1477 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 148:
#line 1482 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 149:
#line 1487 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 150:
#line 1495 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 151:
#line 1518 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 154:
#line 1530 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 155:
#line 1537 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 156:
#line 1537 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 157:
#line 1542 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 158:
#line 1550 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 159:
#line 1555 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 160:
#line 1560 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 161:
#line 1565 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 162:
#line 1570 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 163:
#line 1573 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 164:
#line 1579 "asn1p_y.y"
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
#line 1590 "asn1p_y.y"
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
#line 1608 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 167:
#line 1612 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 168:
#line 1617 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 169:
#line 1625 "asn1p_y.y"
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
#line 1634 "asn1p_y.y"
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
#line 1649 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 172:
#line 1650 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 173:
#line 1651 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 174:
#line 1652 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 175:
#line 1653 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 176:
#line 1654 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 177:
#line 1655 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 178:
#line 1656 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 179:
#line 1657 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 180:
#line 1658 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 181:
#line 1659 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 184:
#line 1668 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 185:
#line 1669 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 186:
#line 1670 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 187:
#line 1674 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 188:
#line 1680 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 189:
#line 1685 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 190:
#line 1690 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(4) - (5)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 191:
#line 1695 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 192:
#line 1700 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 193:
#line 1709 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 194:
#line 1710 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 195:
#line 1714 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 196:
#line 1718 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 197:
#line 1719 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 198:
#line 1720 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 199:
#line 1721 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 200:
#line 1722 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 201:
#line 1726 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 202:
#line 1727 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 203:
#line 1728 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 204:
#line 1729 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 205:
#line 1733 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 206:
#line 1734 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 211:
#line 1746 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 213:
#line 1751 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 215:
#line 1753 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(3) - (4)].a_constr), 0);
	}
    break;

  case 216:
#line 1759 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (1)].a_constr), 0);
    }
    break;

  case 217:
#line 1765 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(2) - (3)].a_constr);
	}
    break;

  case 218:
#line 1768 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 222:
#line 1778 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 224:
#line 1783 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 225:
#line 1789 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		ct->type = ACT_EL_EXT;
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
		ct = (yyval.a_constr);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
	}
    break;

  case 227:
#line 1801 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 229:
#line 1808 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 231:
#line 1815 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 233:
#line 1823 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 234:
#line 1829 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(1) - (4)].a_ctype);
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (4)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 235:
#line 1837 "asn1p_y.y"
    {
		int ret;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CA_SET;
		ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
		checkmem(ret == 0);
	}
    break;

  case 236:
#line 1845 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 237:
#line 1851 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 238:
#line 1857 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 239:
#line 1864 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = asn1p_value_fromint(-123);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
		(yyval.a_constr)->range_start->type = ATV_MIN;
	}
    break;

  case 240:
#line 1872 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = asn1p_value_fromint(321);
		(yyval.a_constr)->range_stop->type = ATV_MAX;
	}
    break;

  case 241:
#line 1880 "asn1p_y.y"
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

  case 244:
#line 1891 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 245:
#line 1891 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 246:
#line 1901 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 247:
#line 1906 "asn1p_y.y"
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

  case 248:
#line 1918 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_SIZE;
	}
    break;

  case 249:
#line 1921 "asn1p_y.y"
    {
		(yyval.a_ctype) = ACT_CT_FROM;
	}
    break;

  case 250:
#line 1927 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 251:
#line 1932 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 255:
#line 1940 "asn1p_y.y"
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

  case 256:
#line 1954 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 257:
#line 1959 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 258:
#line 1967 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(1) - (1)].a_expr));
		checkmem((yyval.a_value));
    }
    break;

  case 259:
#line 1978 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 260:
#line 1981 "asn1p_y.y"
    {
        assert((yyvsp[(3) - (3)].a_constr)->type == ACT_CA_CSV);
        (yyvsp[(3) - (3)].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[(3) - (3)].a_constr);
	}
    break;

  case 264:
#line 1989 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 265:
#line 1991 "asn1p_y.y"
    {
        assert((yyvsp[(4) - (5)].a_constr)->type == ACT_CA_CSV);
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
		asn1p_constraint_t *ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_EXT;
        asn1p_constraint_insert((yyval.a_constr), ct);
        for(unsigned i = 0; i < (yyvsp[(4) - (5)].a_constr)->el_count; i++) {
            asn1p_constraint_insert((yyval.a_constr), (yyvsp[(4) - (5)].a_constr)->elements[i]);
        }
    }
    break;

  case 266:
#line 2004 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(1) - (1)].a_constr));
    }
    break;

  case 267:
#line 2009 "asn1p_y.y"
    {
        (yyval.a_constr) = (yyvsp[(1) - (3)].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 268:
#line 2015 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[(1) - (3)].a_value);
        if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        (yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
    }
    break;

  case 269:
#line 2029 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 270:
#line 2030 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 271:
#line 2034 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 272:
#line 2037 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 273:
#line 2040 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 277:
#line 2055 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 278:
#line 2055 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 279:
#line 2066 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 280:
#line 2075 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 281:
#line 2076 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 282:
#line 2077 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 283:
#line 2078 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 284:
#line 2081 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 285:
#line 2084 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 286:
#line 2093 "asn1p_y.y"
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

  case 287:
#line 2109 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 288:
#line 2115 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 289:
#line 2121 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 290:
#line 2135 "asn1p_y.y"
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

  case 291:
#line 2146 "asn1p_y.y"
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

  case 292:
#line 2162 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 293:
#line 2165 "asn1p_y.y"
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

  case 294:
#line 2185 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 295:
#line 2189 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 296:
#line 2193 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 297:
#line 2197 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 298:
#line 2204 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 299:
#line 2209 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
    }
    break;

  case 300:
#line 2215 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 301:
#line 2224 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 302:
#line 2229 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 303:
#line 2236 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 304:
#line 2244 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 305:
#line 2254 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 306:
#line 2259 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 307:
#line 2266 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[(3) - (4)].a_int));
	}
    break;

  case 308:
#line 2274 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 309:
#line 2284 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
        asn1p_expr_t *first_memb = TQ_FIRST(&((yyval.a_expr)->members));
        if(first_memb) {
            if(first_memb->expr_type == A1TC_EXTENSIBLE) {
                return yyerror(
                    "The ENUMERATION cannot start with extension (...).");
            }
        } else {
            return yyerror(
                "The ENUMERATION list cannot be empty.");
        }
    }
    break;

  case 310:
#line 2299 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 311:
#line 2304 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 312:
#line 2311 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 313:
#line 2318 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 314:
#line 2326 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 315:
#line 2334 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 316:
#line 2341 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 317:
#line 2352 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 318:
#line 2356 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 320:
#line 2364 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 321:
#line 2395 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 322:
#line 2396 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 323:
#line 2400 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 324:
#line 2407 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 325:
#line 2413 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 326:
#line 2414 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 327:
#line 2415 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 328:
#line 2416 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 329:
#line 2420 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 330:
#line 2421 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 331:
#line 2422 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 332:
#line 2426 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 333:
#line 2430 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 334:
#line 2438 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 335:
#line 2445 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 336:
#line 2446 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 337:
#line 2452 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 338:
#line 2459 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
    }
    break;

  case 339:
#line 2465 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 5044 "asn1p_y.c"
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


#line 2469 "asn1p_y.y"



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
		"near %s:%d (token \"%s\"): %s\n",
		ASN_FILENAME, yylineno, asn1p_text, msg);
	return -1;
}


