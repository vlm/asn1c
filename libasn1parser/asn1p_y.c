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
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

#define YYPARSE_PARAM	param
#define YYPARSE_PARAM_TYPE	void **
#define YYERROR_VERBOSE
#define YYDEBUG 1
#define YYFPRINTF   prefixed_fprintf

/*
 * Prefix parser debug with "PARSER: " for easier human eye scanning.
 */
static int
__attribute__((format(printf, 2, 3)))
prefixed_fprintf(FILE *f, const char *fmt, ...) {
    static int line_ended = 1;
    va_list ap;
    va_start(ap, fmt);
    if(line_ended) {
        fprintf(f, "PARSER: ");
        line_ended = 0;
    }
    size_t len = strlen(fmt);
    if(len && fmt[len-1] == '\n') {
        line_ended = 1;
    }
    int ret = vfprintf(f, fmt, ap);
    va_end(ap);
    return ret;
}

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
#line 115 "asn1p_y.y"
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
#line 465 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 478 "asn1p_y.c"

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
#define YYLAST   921

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  144
/* YYNRULES -- Number of rules.  */
#define YYNRULES  347
/* YYNRULES -- Number of states.  */
#define YYNSTATES  523

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
     603,   605,   606,   608,   609,   611,   612,   614,   616,   620,
     622,   625,   627,   629,   631,   633,   635,   639,   645,   647,
     651,   653,   657,   659,   663,   665,   669,   671,   675,   677,
     679,   681,   683,   685,   687,   689,   690,   694,   697,   700,
     703,   706,   710,   712,   714,   716,   718,   720,   722,   724,
     726,   728,   730,   732,   734,   737,   738,   740,   744,   748,
     750,   752,   754,   758,   764,   766,   770,   774,   775,   777,
     779,   781,   783,   785,   787,   789,   790,   796,   799,   801,
     804,   807,   811,   813,   815,   819,   824,   826,   830,   833,
     837,   839,   843,   844,   846,   848,   851,   853,   857,   859,
     861,   865,   870,   875,   877,   881,   886,   891,   893,   895,
     899,   901,   906,   911,   913,   915,   917,   919,   921,   923,
     924,   926,   929,   934,   935,   937,   939,   941,   942,   944,
     946,   948,   950,   952,   953,   955,   957,   959
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     126,     0,    -1,   104,   127,    -1,   127,    -1,   128,    -1,
     127,   128,    -1,    -1,   263,   129,   130,    42,   134,     3,
      29,   137,    47,    -1,    -1,   131,    -1,   112,   132,   113,
      -1,   112,   113,    -1,   133,    -1,   132,   133,    -1,   266,
      -1,   266,   114,    12,   115,    -1,    12,    -1,    -1,   135,
      -1,   136,    -1,   135,   136,    -1,    49,    92,    -1,    60,
      92,    -1,    28,    92,    -1,    51,    61,    -1,    18,    65,
      -1,    -1,   138,    -1,   150,   142,   139,    -1,   140,    -1,
     139,   140,    -1,   157,    -1,   187,    -1,   155,    -1,    -1,
      46,    18,   141,    -1,   197,    -1,    -1,   143,    -1,    62,
     144,   116,    -1,    62,    54,    -1,    -1,   145,    -1,   147,
      -1,   145,   147,    -1,    -1,   131,    -1,   148,    54,   263,
     146,    -1,   149,    -1,   148,   117,   149,    -1,   263,    -1,
     263,   112,   113,    -1,   266,    -1,    -1,   151,    -1,    50,
     152,   116,    -1,    50,    25,   116,    -1,    50,   116,    -1,
     153,    -1,   152,   117,   153,    -1,   263,    -1,   263,   112,
     113,    -1,   266,    -1,   112,   207,   113,    -1,   263,   156,
       3,   154,    -1,   196,    -1,   181,    -1,   181,   112,   160,
     113,    -1,   263,     3,   177,    -1,   263,     3,   167,    -1,
     263,   112,   158,   113,     3,   177,    -1,   263,   112,   158,
     113,     3,   167,    -1,   159,    -1,   158,   117,   159,    -1,
     263,    -1,   263,   118,   266,    -1,   263,   118,   263,    -1,
     194,   118,   266,    -1,   194,   118,   263,    -1,   161,    -1,
     160,   117,   161,    -1,   177,    -1,   190,    -1,   266,    -1,
     154,    -1,    -1,   163,    -1,   164,    -1,   163,   117,   164,
      -1,   163,   117,     4,   163,     5,    -1,   266,   177,   245,
      -1,   177,   245,    -1,    38,    76,   177,    -1,   176,    -1,
     166,    -1,   165,   117,   166,    -1,   266,   177,    -1,   176,
      -1,   177,    -1,    36,   112,   169,   113,   171,    -1,    -1,
      96,    -1,   170,    -1,   169,   117,   170,    -1,    19,   245,
      -1,    20,   177,   168,   245,    -1,    20,   185,   245,    -1,
      20,   186,   245,    -1,    19,   185,   245,    -1,    19,   177,
     245,    -1,    19,   186,   245,    -1,    -1,   172,    -1,    -1,
     103,    90,   112,   173,   174,   113,    -1,   175,    -1,   174,
     175,    -1,     6,    -1,    21,    -1,   184,    -1,   119,   174,
     120,    -1,   111,    -1,   111,   121,   191,    -1,   111,   121,
     256,    -1,   258,   179,   201,    -1,    -1,   178,   180,    -1,
     156,    -1,    35,   112,   165,   113,    -1,    86,   112,   162,
     113,    -1,    87,   112,   162,   113,    -1,    86,   202,    76,
     265,   258,   179,    -1,    87,   202,    76,   265,   258,   179,
      -1,    26,    -1,    26,    43,    33,   266,    -1,    64,    76,
     181,    -1,    17,    -1,    17,   122,   263,    -1,   264,   122,
     263,    -1,    17,   122,   266,    -1,   264,    -1,   264,   122,
     182,    -1,   183,    -1,   182,   122,   183,    -1,   184,    -1,
      19,    -1,    20,    -1,    19,    -1,   185,   122,    19,    -1,
     185,   122,    20,    -1,    18,    -1,   266,   177,     3,   188,
      -1,   190,    -1,   191,    -1,   266,   118,   188,    -1,    -1,
     112,   189,   193,    -1,    71,    -1,    53,    -1,    94,    -1,
       8,    -1,    10,    -1,   192,    -1,   256,    -1,   266,    -1,
     263,   122,   266,    -1,     9,    -1,    15,    -1,    16,    -1,
       7,    -1,   193,     7,    -1,    32,    -1,    71,    -1,    84,
      -1,    75,    89,    -1,    73,    59,    -1,    85,    -1,    52,
      -1,    44,    79,    -1,    34,    89,    -1,    99,    -1,    55,
      -1,   197,    -1,   195,    -1,    66,    -1,    48,    -1,    30,
      89,    -1,   194,    -1,    66,   112,   249,   113,    -1,    48,
     112,   253,   113,    -1,    30,    89,   112,   251,   113,    -1,
      22,   112,   247,   113,    -1,    22,   112,   113,    -1,    31,
      -1,    56,    -1,    57,    -1,    58,    -1,    67,    -1,    72,
      -1,    82,    -1,    91,    -1,    93,    -1,    98,    -1,   100,
      -1,   101,    -1,   102,    -1,    74,    -1,   108,    -1,   109,
      -1,   106,    -1,   107,    -1,    -1,   203,    -1,    -1,   204,
      -1,    -1,   203,    -1,   216,    -1,   114,   205,   115,    -1,
     203,    -1,   204,   203,    -1,   206,    -1,   234,    -1,   207,
      -1,   111,    -1,   208,    -1,   208,   117,   111,    -1,   208,
     117,   111,   117,   208,    -1,   209,    -1,    25,   105,   212,
      -1,   210,    -1,   209,   198,   210,    -1,   211,    -1,   210,
     199,   211,    -1,   212,    -1,   212,   105,   212,    -1,   213,
      -1,   114,   208,   115,    -1,   221,    -1,   223,    -1,   215,
      -1,   216,    -1,   225,    -1,   217,    -1,   218,    -1,    -1,
     112,   214,   193,    -1,    54,   203,    -1,    88,   203,    -1,
      78,     9,    -1,    78,   266,    -1,   219,   238,   220,    -1,
     221,    -1,    69,    -1,   221,    -1,    68,    -1,    53,    -1,
      94,    -1,   257,    -1,   192,    -1,   222,    -1,   266,    -1,
       8,    -1,    10,    -1,   224,   177,    -1,    -1,    63,    -1,
     103,    37,   226,    -1,   103,    38,   227,    -1,   203,    -1,
     228,    -1,   229,    -1,   112,   230,   113,    -1,   112,   111,
     117,   230,   113,    -1,   231,    -1,   230,   117,   231,    -1,
     268,   200,   232,    -1,    -1,   233,    -1,    81,    -1,    23,
      -1,    77,    -1,   235,    -1,   239,    -1,   237,    -1,    -1,
      39,    33,   112,   236,   193,    -1,    40,   177,    -1,   110,
      -1,   110,   123,    -1,   123,   110,    -1,   123,   110,   123,
      -1,   240,    -1,   241,    -1,   112,   263,   113,    -1,   240,
     112,   242,   113,    -1,   243,    -1,   242,   117,   243,    -1,
     124,   244,    -1,   124,   122,   244,    -1,   266,    -1,   244,
     122,   266,    -1,    -1,   246,    -1,    77,    -1,    41,   188,
      -1,   248,    -1,   247,   117,   248,    -1,   266,    -1,   250,
      -1,   249,   117,   250,    -1,   266,   114,   256,   115,    -1,
     266,   114,   191,   115,    -1,   252,    -1,   251,   117,   252,
      -1,   266,   114,    12,   115,    -1,   266,   114,   191,   115,
      -1,   254,    -1,   255,    -1,   254,   117,   255,    -1,   266,
      -1,   266,   114,   256,   115,    -1,   266,   114,   191,   115,
      -1,   256,    -1,   111,    -1,    12,    -1,    13,    -1,   256,
      -1,    14,    -1,    -1,   259,    -1,   260,   262,    -1,   119,
     261,    12,   120,    -1,    -1,    97,    -1,    27,    -1,    83,
      -1,    -1,    60,    -1,    49,    -1,    17,    -1,    18,    -1,
      18,    -1,    -1,   266,    -1,    11,    -1,   266,    -1,   267,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   410,   410,   413,   419,   424,   441,   441,   470,   471,
     475,   478,   484,   490,   499,   503,   507,   517,   518,   527,
     530,   539,   542,   545,   548,   552,   573,   574,   583,   596,
     599,   616,   623,   637,   645,   644,   658,   671,   672,   675,
     685,   691,   692,   695,   700,   707,   708,   712,   723,   728,
     735,   741,   747,   757,   758,   770,   773,   776,   784,   789,
     796,   802,   808,   817,   820,   830,   843,   853,   873,   879,
     895,   901,   909,   918,   929,   933,   941,   949,   957,   968,
     973,   980,   983,   991,  1002,  1025,  1026,  1029,  1034,  1038,
    1046,  1053,  1059,  1066,  1072,  1077,  1084,  1089,  1092,  1099,
    1109,  1110,  1114,  1121,  1131,  1141,  1152,  1162,  1173,  1183,
    1194,  1206,  1207,  1214,  1213,  1222,  1226,  1233,  1237,  1240,
    1244,  1250,  1258,  1267,  1279,  1303,  1310,  1329,  1332,  1338,
    1344,  1350,  1360,  1370,  1376,  1388,  1403,  1411,  1422,  1433,
    1444,  1452,  1474,  1482,  1491,  1495,  1500,  1509,  1514,  1519,
    1527,  1550,  1560,  1561,  1562,  1569,  1569,  1574,  1582,  1587,
    1592,  1597,  1602,  1605,  1611,  1622,  1640,  1644,  1649,  1657,
    1666,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1700,  1701,  1702,  1706,  1712,  1717,
    1722,  1727,  1732,  1741,  1742,  1746,  1750,  1751,  1752,  1753,
    1754,  1758,  1759,  1760,  1761,  1765,  1766,  1773,  1773,  1774,
    1774,  1778,  1779,  1783,  1784,  1788,  1789,  1790,  1794,  1800,
    1801,  1810,  1810,  1812,  1815,  1819,  1820,  1826,  1837,  1838,
    1844,  1845,  1851,  1852,  1859,  1860,  1866,  1867,  1878,  1884,
    1890,  1891,  1893,  1894,  1895,  1896,  1896,  1907,  1912,  1917,
    1922,  1934,  1943,  1944,  1950,  1951,  1957,  1962,  1967,  1968,
    1969,  1970,  1984,  1989,  1997,  2004,  2005,  2013,  2016,  2022,
    2023,  2023,  2024,  2026,  2039,  2044,  2050,  2064,  2065,  2069,
    2072,  2075,  2083,  2084,  2085,  2090,  2089,  2101,  2110,  2111,
    2112,  2113,  2116,  2119,  2128,  2144,  2150,  2156,  2170,  2181,
    2197,  2200,  2220,  2224,  2228,  2232,  2239,  2244,  2250,  2259,
    2264,  2271,  2279,  2289,  2294,  2301,  2309,  2319,  2334,  2339,
    2346,  2353,  2361,  2369,  2376,  2387,  2391,  2398,  2399,  2430,
    2431,  2435,  2442,  2448,  2449,  2450,  2451,  2455,  2456,  2457,
    2461,  2465,  2473,  2480,  2481,  2487,  2494,  2500
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
  "ObjectClass", "optUNIQUE", "FieldSpec", "ClassField", "optWithSyntax",
  "WithSyntax", "@3", "WithSyntaxList", "WithSyntaxToken",
  "ExtensionAndException", "Type", "NSTD_IndirectMarker",
  "TypeDeclaration", "TypeDeclarationSet", "ComplexTypeReference",
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement",
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass",
  "ValueAssignment", "Value", "@4", "SimpleValue", "DefinedValue",
  "RestrictedCharacterStringValue", "Opaque", "BasicTypeId",
  "BasicTypeId_UniverationCompatible", "BasicType", "BasicString",
  "UnionMark", "IntersectionMark", "optConstraint", "optManyConstraints",
  "optSizeOrConstraint", "Constraint", "ManyConstraints", "ConstraintSpec",
  "SubtypeConstraint", "ElementSetSpecs", "ElementSetSpec", "Unions",
  "Intersections", "IntersectionElements", "Elements", "SubtypeElements",
  "@5", "PermittedAlphabet", "SizeConstraint", "PatternConstraint",
  "ValueRange", "LowerEndValue", "UpperEndValue", "SingleValue",
  "BitStringValue", "ContainedSubtype", "optINCLUDES",
  "InnerTypeConstraints", "SingleTypeConstraint",
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
     199,   200,   200,   201,   201,   202,   202,   202,   203,   204,
     204,   205,   205,   206,   207,   207,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   213,   214,   213,   215,   216,   217,
     217,   218,   219,   219,   220,   220,   221,   221,   221,   221,
     221,   221,   222,   222,   223,   224,   224,   225,   225,   226,
     227,   227,   228,   229,   230,   230,   231,   232,   232,   233,
     233,   233,   234,   234,   234,   236,   235,   237,   238,   238,
     238,   238,   239,   239,   240,   241,   242,   242,   243,   243,
     244,   244,   245,   245,   246,   246,   247,   247,   248,   249,
     249,   250,   250,   251,   251,   252,   252,   253,   254,   254,
     255,   255,   255,   255,   255,   256,   256,   257,   257,   258,
     258,   259,   260,   261,   261,   261,   261,   262,   262,   262,
     263,   263,   264,   265,   265,   266,   267,   268
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
       1,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     3,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     2,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     1,     3,     3,     1,
       1,     1,     3,     5,     1,     3,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     2,     1,     2,
       2,     3,     1,     1,     3,     4,     1,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     1,     3,     1,     1,
       3,     4,     4,     1,     3,     4,     4,     1,     1,     3,
       1,     4,     4,     1,     1,     1,     1,     1,     1,     0,
       1,     2,     4,     0,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   340,   341,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   345,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     193,     0,   194,   195,   196,   197,   198,   206,   199,   200,
     201,   202,   203,   204,   205,    28,    29,    33,    31,    32,
      36,     0,   329,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   329,   136,   342,     0,     0,   171,     0,     0,
     185,   177,   181,   184,   172,     0,     0,   173,   176,   180,
       0,     0,    66,   187,   183,    65,   182,   140,   333,     0,
     125,   330,   337,    45,    49,    51,    35,     0,    69,    68,
       0,     0,   186,   179,   178,     0,     0,   175,   174,     0,
     185,   184,     0,    72,     0,    74,     0,   329,     0,   335,
     336,   334,     0,     0,     0,   213,   339,   338,   331,    46,
      47,     0,   137,   139,   192,     0,   306,   308,     0,   325,
     326,   324,     0,   317,   318,   323,   320,     0,   309,     0,
     186,     0,     0,     0,     0,   265,    64,   160,   166,   161,
     167,   168,   158,   159,    84,     0,    79,    81,    82,   162,
     163,    83,   145,   146,   141,   142,   144,   138,     0,   157,
     155,   151,   152,   153,     0,   164,   133,     0,     0,   215,
     215,   127,   126,   265,   124,   219,   214,   329,   329,     0,
     102,   191,     0,     0,   313,     0,   189,     0,     0,   188,
       0,     0,   329,    73,    78,    77,    76,    75,   262,   263,
     328,     0,   256,     0,   266,   253,     0,     0,   257,     0,
     224,   245,   265,   259,     0,   225,   228,   230,   232,   234,
     236,   240,   241,   243,   244,     0,   238,   260,   239,   329,
     242,   327,   258,   261,    67,   329,     0,   332,     0,     0,
       0,     0,   329,     0,   329,     0,   216,   217,   329,     0,
       0,   329,   245,     0,   221,   223,   222,   282,   284,   283,
     292,   293,   220,   150,   147,     0,   304,   302,   302,   302,
     104,   303,   100,   302,   302,   111,     0,   307,   190,     0,
       0,   319,     0,     0,   164,   310,     0,     0,    71,    70,
     265,   247,   249,   250,   248,     0,     0,     0,     0,    63,
       0,   207,   208,   265,   209,   210,   265,   265,   288,     0,
       0,   264,    80,   143,   169,   156,   165,   154,     0,   121,
       0,    94,    97,    98,   329,   135,     0,     0,    86,    87,
      93,   302,   329,   343,     0,   343,     0,   287,     0,   218,
       0,   305,   109,     0,   108,   110,   101,   302,   106,   107,
       0,    99,   112,   103,   314,     0,     0,   322,   321,   312,
     311,   229,   269,   267,     0,   268,   270,   271,   246,   237,
     226,   231,   233,   235,   289,   290,   255,   251,   254,   170,
     134,     0,   128,   329,    96,   329,   129,   329,    91,   302,
     329,   344,   130,   329,   285,   294,     0,     0,   296,   148,
     149,   105,     0,   315,   316,     0,     0,   274,   346,   347,
     211,   265,   291,   122,   123,    95,    92,   329,    88,    90,
     125,   125,     0,     0,   298,   300,   295,     0,   113,     0,
     272,     0,   277,   212,   227,     0,   131,   132,   286,   299,
       0,   297,     0,     0,   275,   280,   281,   279,   276,   278,
      89,   301,   117,   118,     0,     0,   115,   119,   273,     0,
     114,   116,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   136,    56,    57,    63,
      64,   170,    65,    66,    67,    46,    47,    50,    51,   204,
      87,   121,    88,   152,   153,   205,   206,   387,   388,   389,
     380,   381,   138,   407,   239,   240,   411,   412,   502,   515,
     516,   390,   391,   164,   165,   232,   122,   214,   215,   517,
     328,   329,    89,   221,   298,   222,   223,   273,   375,   123,
     124,   125,   126,   363,   366,   492,   234,   305,   306,   236,
     313,   314,   274,   275,   276,   277,   278,   279,   280,   357,
     281,   282,   283,   284,   285,   437,   286,   287,   288,   289,
     290,   423,   425,   426,   427,   466,   467,   508,   509,   316,
     317,   482,   318,   370,   319,   320,   321,   457,   458,   484,
     330,   331,   175,   176,   187,   188,   243,   244,   182,   183,
     184,   291,   292,   130,   131,   132,   162,   168,   224,   127,
     450,   293,   469,   470
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -351
static const yytype_int16 yypact[] =
{
       0,  -351,  -351,   238,    59,   238,  -351,  -351,   238,  -351,
    -351,   -21,    26,    43,  -351,  -351,  -351,  -351,    49,  -351,
     -18,   248,  -351,  -351,   103,    70,    65,    71,   124,   113,
     216,   248,  -351,    82,  -351,  -351,  -351,  -351,  -351,   252,
    -351,  -351,   122,    77,   161,  -351,   172,  -351,   170,  -351,
      63,  -351,   177,  -351,  -351,   198,   653,  -351,  -351,  -351,
     105,   191,  -351,   196,   105,  -351,    -3,  -351,   204,  -351,
    -351,   301,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,   653,  -351,  -351,  -351,  -351,
    -351,   303,   212,  -351,  -351,  -351,  -351,   238,   105,   210,
    -351,  -351,   -10,   214,  -351,   226,   253,  -351,   261,   274,
     270,  -351,  -351,   272,  -351,   314,   297,  -351,  -351,  -351,
     819,   386,   278,  -351,  -351,  -351,  -351,   269,    28,   389,
    -351,  -351,    33,   -21,  -351,  -351,  -351,   281,  -351,  -351,
     105,    13,   283,  -351,  -351,   163,   387,  -351,  -351,   308,
    -351,  -351,    24,  -351,   282,   288,   287,   179,   250,  -351,
    -351,  -351,   395,   232,   742,   294,  -351,  -351,  -351,  -351,
    -351,   275,  -351,  -351,  -351,    93,  -351,  -351,   387,  -351,
    -351,  -351,   296,   293,  -351,  -351,   299,   104,  -351,   300,
    -351,   408,   819,   105,   105,   516,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,   112,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,   304,  -351,  -351,  -351,   307,  -351,
    -351,  -351,  -351,  -351,   306,   298,   390,   318,   356,   -14,
     139,  -351,  -351,   409,  -351,  -351,   294,   205,    23,   120,
    -351,  -351,   387,   162,  -351,   322,  -351,   163,   328,  -351,
     387,   328,   -10,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,   332,  -351,   294,  -351,  -351,   217,   294,  -351,   292,
    -351,  -351,   537,  -351,   325,   323,   240,   256,  -351,   334,
    -351,  -351,  -351,  -351,  -351,   -78,   -20,  -351,  -351,   212,
    -351,  -351,  -351,  -351,  -351,   179,   337,  -351,   434,   387,
     232,   410,    19,   347,     8,   366,  -351,  -351,     8,   369,
     413,   212,   238,   335,  -351,  -351,  -351,  -351,  -351,  -351,
     339,  -351,  -351,  -351,  -351,   232,  -351,    12,   109,    12,
    -351,  -351,   351,   109,    12,   349,   275,  -351,  -351,   387,
     260,  -351,   338,   340,  -351,  -351,   341,   342,  -351,  -351,
     644,  -351,  -351,  -351,  -351,   294,   346,   434,   344,  -351,
     343,  -351,  -351,   644,  -351,  -351,   644,   644,   345,   350,
     249,  -351,  -351,  -351,  -351,   454,  -351,  -351,   387,   352,
     167,  -351,  -351,  -351,   212,  -351,   388,   353,   357,  -351,
    -351,    12,   212,   387,   354,   387,   358,  -351,   362,  -351,
     359,  -351,  -351,   348,  -351,  -351,  -351,    12,  -351,  -351,
     379,  -351,  -351,  -351,  -351,   361,   365,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,    25,  -351,  -351,  -351,   454,  -351,
     364,   256,  -351,  -351,  -351,   363,  -351,  -351,  -351,  -351,
    -351,   328,  -351,    19,  -351,   212,  -351,    45,  -351,    12,
     212,  -351,  -351,   212,  -351,  -351,     2,   192,  -351,  -351,
    -351,  -351,   370,  -351,  -351,   367,   194,  -351,  -351,  -351,
     294,   537,  -351,  -351,  -351,  -351,  -351,    54,  -351,  -351,
    -351,  -351,   434,   387,   368,  -351,  -351,   359,  -351,   387,
    -351,   387,   126,  -351,  -351,     3,  -351,  -351,   454,   368,
     387,  -351,    51,   197,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,    51,    58,  -351,  -351,  -351,    48,
    -351,  -351,  -351
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -351,  -351,   482,    42,  -351,  -351,   360,  -351,   471,  -351,
    -351,   460,  -351,  -351,  -351,   407,  -351,  -351,  -351,  -351,
    -351,  -351,   430,  -351,   397,  -351,  -351,  -351,   436,   355,
    -351,   336,  -351,  -351,   309,  -351,   203,   199,    22,    55,
    -351,    61,   254,  -351,  -351,   169,  -351,  -351,  -351,    -6,
    -297,  -299,   -91,  -351,  -109,  -351,   206,  -351,   218,  -153,
     277,   279,  -351,  -238,  -351,  -143,  -239,  -142,  -350,   -93,
    -351,  -351,   -27,  -351,  -351,  -351,  -351,   280,  -155,  -351,
    -351,  -351,   285,  -270,  -351,   153,   147,  -219,  -351,  -351,
    -351,   150,  -351,  -351,  -351,  -351,   149,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,    44,    31,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,    47,    52,
    -294,  -351,  -351,   295,  -351,   286,  -351,   200,  -351,  -351,
     291,  -141,  -351,  -254,  -351,  -351,  -351,  -351,    20,  -351,
     145,   -12,  -351,  -351
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -303
static const yytype_int16 yytable[] =
{
      20,   129,   358,   382,   185,   216,    20,   428,   510,   342,
     235,   139,   346,    15,   208,   209,   210,     1,     2,    15,
       7,   209,   210,     7,    15,     7,   137,   154,     7,    90,
      15,    53,   368,   402,   404,   405,    15,    15,    16,   408,
     409,   323,   324,    69,    92,   369,   386,    10,    53,   477,
      10,    97,    69,   325,   512,   159,    15,   512,    90,     9,
      15,    16,   377,    52,   512,    15,   207,   212,   213,   513,
     212,   213,   513,    92,   267,    68,    91,   212,   213,   513,
      52,   322,   166,   386,    68,    21,    69,   401,    15,   326,
    -252,    12,   386,   167,     1,     2,    24,   448,   304,   154,
     233,   416,    48,  -252,     3,    91,   185,   343,   351,   128,
     347,   160,   354,   461,    98,    33,    15,   133,    68,   379,
     447,   -85,     1,     2,   483,   161,   174,   128,   173,   177,
     379,   421,   498,   186,   189,    34,   465,   191,   128,    17,
     155,   192,   128,   216,   382,   211,   327,   332,   433,   505,
     325,   225,   208,   209,   210,   479,   379,    35,   209,   210,
     172,   349,    22,    36,   128,   379,   245,   514,   522,   -26,
     514,   520,    43,   128,    15,   179,   180,   514,   217,    59,
      60,   255,   257,   209,   210,    37,   326,   197,   198,   199,
      15,   179,   180,    49,   200,   201,   480,    41,   371,   481,
     422,   494,   473,   506,   207,    38,   241,   507,    54,    15,
     242,   383,   155,   254,   256,     1,     2,   249,   521,    39,
     397,   250,   521,   323,   324,   294,   352,   267,    15,   295,
     177,   403,   202,   335,    55,   186,   344,   336,   189,   344,
     197,   198,   199,    15,   179,   180,   325,   200,   201,     1,
       2,   308,    62,   233,   353,     1,     2,   258,   198,   259,
      15,   179,   180,   260,   200,   201,    25,     1,     2,   212,
     213,    15,   415,   203,   181,   338,    26,     1,     2,   339,
     442,    42,   326,   211,   443,   202,    58,   376,   225,    61,
     384,   195,   392,   444,   237,   238,   392,    27,   128,    28,
     474,   449,   262,   219,    94,   486,   102,   490,    29,   487,
     518,   491,    95,   225,   491,   493,    99,   436,  -302,   100,
     103,   104,  -302,   135,   128,   105,   203,   245,   344,   355,
     356,   128,   398,   106,    70,   107,   140,   108,   141,    15,
     179,   180,   142,   268,   220,     1,     2,   109,   361,   362,
     143,   110,   383,   144,   476,   111,   212,   213,   112,    72,
      73,    74,   364,   365,   103,   104,   440,   459,   460,   113,
      75,   496,   497,   147,   114,    76,   115,    77,   116,   307,
     307,   451,   145,   451,   146,    78,   148,   117,   118,   156,
     157,   158,   163,   171,    79,   178,    80,   190,    15,   195,
     193,    81,   119,    82,    83,    84,   194,   218,   233,   246,
     247,   252,   468,   248,   251,   120,   300,   258,   198,   259,
      15,   179,   180,   260,   200,   201,   296,   297,   299,   344,
     302,   384,   303,   301,   261,   392,   340,   350,   359,   367,
     360,   374,   393,   378,   485,   395,   396,   406,   310,   311,
     399,   400,   410,   417,   430,   418,   419,   420,   424,   429,
     435,   439,   262,   263,   445,   392,   446,   452,   434,   462,
     454,   485,   264,   441,   447,   455,   463,   468,   265,   468,
     464,   471,   488,   456,   489,     8,   472,   266,   511,    23,
     500,    40,   101,   169,    96,   134,    93,   267,   372,   495,
     231,   253,   478,   268,   475,   413,   348,   394,   519,   385,
     309,   196,   269,   432,   373,   333,   431,   334,   315,   438,
     270,   312,   504,   272,   258,   198,   259,    15,   179,   180,
     260,   200,   201,   503,   501,   499,   345,   337,   341,   414,
     453,   261,     0,     0,     0,   258,   198,   259,    15,   179,
     180,   260,   200,   201,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
     262,   263,     0,     0,   266,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   267,     0,   265,     0,     0,     0,
     268,     0,     0,     0,     0,   266,     0,     0,     0,   269,
       0,     0,     0,     0,     0,   267,     0,   270,   271,     0,
     272,   268,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,   272,   258,   198,   259,    15,   179,   180,   260,   200,
     201,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,   263,    71,
       0,     0,     0,     0,     0,     0,     0,   264,     0,    72,
      73,    74,     0,   265,     0,     0,     0,     0,     0,     0,
      75,     0,   266,     0,     0,    76,     0,    77,     0,     0,
       0,     0,   267,     0,     0,    78,     0,     0,   268,     0,
       0,     0,     0,     0,    79,     0,    80,   269,     0,     0,
       0,    81,     0,    82,    83,    84,   271,     0,   272,   103,
     104,     0,     0,     0,   105,     0,     0,     0,   226,     0,
       0,     0,   106,    70,   107,     0,   108,   227,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
     110,     0,     0,     0,   111,     0,     0,   112,    72,    73,
      74,     0,     0,     0,     0,     0,   228,     0,   113,    75,
       0,     0,     0,   114,    76,   115,    77,   116,     0,     0,
       0,     0,     0,     0,    78,     0,   117,   118,   229,   230,
       0,     0,     0,    79,     0,    80,     1,     2,     0,     0,
      81,   119,    82,    83,    84,     0,     0,     0,     0,   149,
      70,   107,     0,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,   150,     0,     0,
       0,   111,     0,     0,   112,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,   151,    75,     0,     0,     0,
     114,    76,   115,    77,   116,     0,     0,     0,     0,     0,
       0,    78,     0,   117,   118,     0,     0,     0,     0,     0,
      79,     0,    80,     0,     0,     0,     0,    81,   119,    82,
      83,    84
};

static const yytype_int16 yycheck[] =
{
      12,    92,   272,   302,   145,   158,    18,   357,     5,   248,
     165,   102,   251,    11,   157,   157,   157,    17,    18,    11,
       0,   163,   163,     3,    11,     5,    36,   120,     8,    56,
      11,    43,   110,   327,   328,   329,    11,    11,    12,   333,
     334,    18,    19,    55,    56,   123,    38,     5,    60,     4,
       8,    54,    64,    41,     6,    27,    11,     6,    85,     0,
      11,    12,   300,    43,     6,    11,   157,    19,    20,    21,
      19,    20,    21,    85,    88,    55,    56,    19,    20,    21,
      60,   236,    49,    38,    64,    42,    98,   325,    11,    77,
     110,   112,    38,    60,    17,    18,   114,   391,   112,   192,
     114,   340,    25,   123,   104,    85,   247,   248,   263,   119,
     251,    83,   267,   407,   117,    12,    11,    97,    98,   111,
     117,   113,    17,    18,   122,    97,   113,   119,   140,   141,
     111,   350,   482,   145,   146,    65,   111,   113,   119,   113,
     120,   117,   119,   296,   443,   157,   237,   238,   367,    23,
      41,   163,   295,   295,   295,   449,   111,    92,   300,   300,
     140,   252,   113,    92,   119,   111,   178,   119,   120,    47,
     119,   113,    50,   119,    11,    12,    13,   119,   158,   116,
     117,   193,   194,   325,   325,    61,    77,     8,     9,    10,
      11,    12,    13,   116,    15,    16,   450,   115,   289,   453,
     355,   471,   441,    77,   295,    92,   113,    81,    47,    11,
     117,   302,   192,   193,   194,    17,    18,   113,   515,     3,
     311,   117,   519,    18,    19,   113,     9,    88,    11,   117,
     242,   122,    53,   113,    62,   247,   248,   117,   250,   251,
       8,     9,    10,    11,    12,    13,    41,    15,    16,    17,
      18,   112,    54,   114,   266,    17,    18,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    18,    17,    18,    19,
      20,    11,    12,    94,   111,   113,    28,    17,    18,   117,
     113,    29,    77,   295,   117,    53,   116,   299,   300,   112,
     302,   112,   304,   384,    19,    20,   308,    49,   119,    51,
     441,   392,    53,    71,   113,   113,     3,   113,    60,   117,
     113,   117,   116,   325,   117,   470,   112,    68,   113,    18,
      17,    18,   117,   113,   119,    22,    94,   339,   340,    37,
      38,   119,   312,    30,    31,    32,   122,    34,   112,    11,
      12,    13,    89,    94,   112,    17,    18,    44,   108,   109,
      89,    48,   443,    79,   445,    52,    19,    20,    55,    56,
      57,    58,   106,   107,    17,    18,   378,    19,    20,    66,
      67,   480,   481,    59,    71,    72,    73,    74,    75,   229,
     230,   393,   112,   395,   112,    82,    89,    84,    85,     3,
     112,   122,     3,   112,    91,   112,    93,    89,    11,   112,
     118,    98,    99,   100,   101,   102,   118,    12,   114,   113,
     117,     3,   424,   114,   114,   112,   118,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   122,   120,   122,   441,
     112,   443,    76,    43,    25,   447,   114,   105,   113,   105,
     117,     7,    76,    33,   456,    76,    33,    96,    39,    40,
     115,   112,   103,   115,   111,   115,   115,   115,   112,   115,
     110,     7,    53,    54,    76,   477,   113,   113,   123,    90,
     112,   483,    63,   121,   117,   113,   115,   489,    69,   491,
     115,   117,   112,   124,   117,     3,   123,    78,   500,    18,
     122,    31,    85,   133,    64,    98,    60,    88,   295,   477,
     164,   192,   447,    94,   443,   336,   252,   308,   514,   303,
     230,   156,   103,   366,   296,   238,   363,   238,   233,   370,
     111,   112,   491,   114,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   489,   487,   483,   250,   242,   247,   339,
     395,    25,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    88,    -1,    69,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    88,    -1,   111,   112,    -1,
     114,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   114,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    56,
      57,    58,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    78,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    82,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    93,   103,    -1,    -1,
      -1,    98,    -1,   100,   101,   102,   112,    -1,   114,    17,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    31,    32,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    85,    86,    87,
      -1,    -1,    -1,    91,    -1,    93,    17,    18,    -1,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    17,    18,   104,   126,   127,   128,   263,   127,     0,
     128,   129,   112,   130,   131,    11,    12,   113,   132,   133,
     266,    42,   113,   133,   114,    18,    28,    49,    51,    60,
     134,   135,   136,    12,    65,    92,    92,    61,    92,     3,
     136,   115,    29,    50,   137,   138,   150,   151,    25,   116,
     152,   153,   263,   266,    47,    62,   142,   143,   116,   116,
     117,   112,    54,   144,   145,   147,   148,   149,   263,   266,
      31,    46,    56,    57,    58,    67,    72,    74,    82,    91,
      93,    98,   100,   101,   102,   139,   140,   155,   157,   187,
     197,   263,   266,   153,   113,   116,   147,    54,   117,   112,
      18,   140,     3,    17,    18,    22,    30,    32,    34,    44,
      48,    52,    55,    66,    71,    73,    75,    84,    85,    99,
     112,   156,   181,   194,   195,   196,   197,   264,   119,   177,
     258,   259,   260,   263,   149,   113,   141,    36,   167,   177,
     122,   112,    89,    89,    79,   112,   112,    59,    89,    30,
      48,    66,   158,   159,   194,   263,     3,   112,   122,    27,
      83,    97,   261,     3,   178,   179,    49,    60,   262,   131,
     146,   112,   263,   266,   113,   247,   248,   266,   112,    12,
      13,   111,   253,   254,   255,   256,   266,   249,   250,   266,
      89,   113,   117,   118,   118,   112,   154,     8,     9,    10,
      15,    16,    53,    94,   154,   160,   161,   177,   190,   192,
     256,   266,    19,    20,   182,   183,   184,   263,    12,    71,
     112,   188,   190,   191,   263,   266,    26,    35,    64,    86,
      87,   156,   180,   114,   201,   203,   204,    19,    20,   169,
     170,   113,   117,   251,   252,   266,   113,   117,   114,   113,
     117,   114,     3,   159,   263,   266,   263,   266,     8,    10,
      14,    25,    53,    54,    63,    69,    78,    88,    94,   103,
     111,   112,   114,   192,   207,   208,   209,   210,   211,   212,
     213,   215,   216,   217,   218,   219,   221,   222,   223,   224,
     225,   256,   257,   266,   113,   117,   122,   120,   189,   122,
     118,    43,   112,    76,   112,   202,   203,   216,   112,   202,
      39,    40,   112,   205,   206,   207,   234,   235,   237,   239,
     240,   241,   203,    18,    19,    41,    77,   177,   185,   186,
     245,   246,   177,   185,   186,   113,   117,   248,   113,   117,
     114,   255,   191,   256,   266,   250,   191,   256,   167,   177,
     105,   203,     9,   266,   203,    37,    38,   214,   208,   113,
     117,   108,   109,   198,   106,   107,   199,   105,   110,   123,
     238,   177,   161,   183,     7,   193,   266,   188,    33,   111,
     165,   166,   176,   177,   266,   181,    38,   162,   163,   164,
     176,   177,   266,    76,   162,    76,    33,   177,   263,   115,
     112,   188,   245,   122,   245,   245,    96,   168,   245,   245,
     103,   171,   172,   170,   252,    12,   191,   115,   115,   115,
     115,   212,   203,   226,   112,   227,   228,   229,   193,   115,
     111,   210,   211,   212,   123,   110,    68,   220,   221,     7,
     266,   121,   113,   117,   177,    76,   113,   117,   245,   177,
     265,   266,   113,   265,   112,   113,   124,   242,   243,    19,
      20,   245,    90,   115,   115,   111,   230,   231,   266,   267,
     268,   117,   123,   191,   256,   166,   177,     4,   164,   245,
     258,   258,   236,   122,   244,   266,   113,   117,   112,   117,
     113,   117,   200,   203,   208,   163,   179,   179,   193,   244,
     122,   243,   173,   230,   231,    23,    77,    81,   232,   233,
       5,   266,     6,    21,   119,   174,   175,   184,   113,   174,
     113,   175,   120
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
#line 410 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(2) - (2)].a_grammar);
	}
    break;

  case 3:
#line 413 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 4:
#line 419 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 5:
#line 424 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 6:
#line 441 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 7:
#line 446 "asn1p_y.y"
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
#line 470 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 9:
#line 471 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 10:
#line 475 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 11:
#line 478 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 12:
#line 484 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(1) - (1)].a_oid_arc));
		if((yyvsp[(1) - (1)].a_oid_arc).name)
			free((yyvsp[(1) - (1)].a_oid_arc).name);
	}
    break;

  case 13:
#line 490 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(1) - (2)].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(2) - (2)].a_oid_arc));
		if((yyvsp[(2) - (2)].a_oid_arc).name)
			free((yyvsp[(2) - (2)].a_oid_arc).name);
	}
    break;

  case 14:
#line 499 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
    break;

  case 15:
#line 503 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 16:
#line 507 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[(1) - (1)].a_int);
	}
    break;

  case 17:
#line 517 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 18:
#line 518 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 527 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 20:
#line 530 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 21:
#line 539 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 22:
#line 542 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 23:
#line 545 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 24:
#line 548 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 25:
#line 552 "asn1p_y.y"
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
#line 573 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 27:
#line 574 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 28:
#line 583 "asn1p_y.y"
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
#line 596 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 30:
#line 599 "asn1p_y.y"
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
#line 616 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 32:
#line 623 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 33:
#line 637 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		TQ_ADD(&((yyval.a_module)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 34:
#line 645 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 35:
#line 646 "asn1p_y.y"
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
#line 658 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 37:
#line 671 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 39:
#line 675 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 40:
#line 685 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 41:
#line 691 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 43:
#line 695 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 44:
#line 700 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 45:
#line 707 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 46:
#line 708 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 47:
#line 712 "asn1p_y.y"
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
#line 723 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 49:
#line 728 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 50:
#line 735 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 741 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 747 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 53:
#line 757 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 54:
#line 758 "asn1p_y.y"
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
#line 770 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 56:
#line 773 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 57:
#line 776 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 58:
#line 784 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 59:
#line 789 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 60:
#line 796 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 802 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 808 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 63:
#line 817 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 64:
#line 820 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 65:
#line 830 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 66:
#line 843 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 67:
#line 853 "asn1p_y.y"
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
#line 873 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 69:
#line 879 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 70:
#line 895 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 901 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 72:
#line 909 "asn1p_y.y"
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
#line 918 "asn1p_y.y"
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
#line 929 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 75:
#line 933 "asn1p_y.y"
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
#line 941 "asn1p_y.y"
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
#line 949 "asn1p_y.y"
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
#line 957 "asn1p_y.y"
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
#line 968 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 80:
#line 973 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 81:
#line 980 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 82:
#line 983 "asn1p_y.y"
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
#line 991 "asn1p_y.y"
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
#line 1002 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 85:
#line 1025 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 86:
#line 1026 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 87:
#line 1029 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 88:
#line 1034 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 89:
#line 1038 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (5)].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
		asn1p_expr_free((yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 90:
#line 1046 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 91:
#line 1053 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 92:
#line 1059 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 93:
#line 1066 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 94:
#line 1072 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 95:
#line 1077 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 96:
#line 1084 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 97:
#line 1089 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 98:
#line 1092 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 99:
#line 1099 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 100:
#line 1109 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 101:
#line 1110 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 102:
#line 1114 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 103:
#line 1121 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 104:
#line 1131 "asn1p_y.y"
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
#line 1141 "asn1p_y.y"
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
#line 1152 "asn1p_y.y"
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
#line 1162 "asn1p_y.y"
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
#line 1173 "asn1p_y.y"
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
#line 1183 "asn1p_y.y"
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
#line 1194 "asn1p_y.y"
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
#line 1206 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 112:
#line 1207 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 113:
#line 1214 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 114:
#line 1216 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 115:
#line 1222 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 116:
#line 1226 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 117:
#line 1233 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 118:
#line 1237 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 119:
#line 1240 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 120:
#line 1244 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 121:
#line 1250 "asn1p_y.y"
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
#line 1258 "asn1p_y.y"
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
#line 1267 "asn1p_y.y"
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
#line 1279 "asn1p_y.y"
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
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[(3) - (3)].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[(3) - (3)].a_constr);
			}
		}
	}
    break;

  case 125:
#line 1303 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 126:
#line 1310 "asn1p_y.y"
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
#line 1329 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 128:
#line 1332 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 129:
#line 1338 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 130:
#line 1344 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 131:
#line 1350 "asn1p_y.y"
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
#line 1360 "asn1p_y.y"
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
#line 1370 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1376 "asn1p_y.y"
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
#line 1388 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1403 "asn1p_y.y"
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
#line 1411 "asn1p_y.y"
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
#line 1422 "asn1p_y.y"
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
#line 1433 "asn1p_y.y"
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
#line 1444 "asn1p_y.y"
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
#line 1452 "asn1p_y.y"
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
#line 1474 "asn1p_y.y"
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
#line 1482 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 145:
#line 1495 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 146:
#line 1500 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 147:
#line 1509 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 148:
#line 1514 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 149:
#line 1519 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 150:
#line 1527 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 151:
#line 1550 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 154:
#line 1562 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_CHOICE_IDENTIFIER;
		(yyval.a_value)->value.choice_identifier.identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_value)->value.choice_identifier.value = (yyvsp[(3) - (3)].a_value);
	}
    break;

  case 155:
#line 1569 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 156:
#line 1569 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 157:
#line 1574 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 158:
#line 1582 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 159:
#line 1587 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 160:
#line 1592 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 161:
#line 1597 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 162:
#line 1602 "asn1p_y.y"
    {
		(yyval.a_value) = (yyval.a_value);
	}
    break;

  case 163:
#line 1605 "asn1p_y.y"
    {
		(yyval.a_value) = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 164:
#line 1611 "asn1p_y.y"
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
#line 1622 "asn1p_y.y"
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
#line 1640 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 167:
#line 1644 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 168:
#line 1649 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 169:
#line 1657 "asn1p_y.y"
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
#line 1666 "asn1p_y.y"
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
#line 1681 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 172:
#line 1682 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 173:
#line 1683 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 174:
#line 1684 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 175:
#line 1685 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 176:
#line 1686 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 177:
#line 1687 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 178:
#line 1688 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 179:
#line 1689 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 180:
#line 1690 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 181:
#line 1691 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 184:
#line 1700 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 185:
#line 1701 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 186:
#line 1702 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 187:
#line 1706 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 188:
#line 1712 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 189:
#line 1717 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 190:
#line 1722 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(4) - (5)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 191:
#line 1727 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 192:
#line 1732 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 193:
#line 1741 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 194:
#line 1742 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 195:
#line 1746 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 196:
#line 1750 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 197:
#line 1751 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 198:
#line 1752 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 199:
#line 1753 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 200:
#line 1754 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 201:
#line 1758 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 202:
#line 1759 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 203:
#line 1760 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 204:
#line 1761 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 205:
#line 1765 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 206:
#line 1766 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 211:
#line 1778 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 213:
#line 1783 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 215:
#line 1788 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 218:
#line 1794 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(2) - (3)].a_constr), 0);
    }
    break;

  case 220:
#line 1801 "asn1p_y.y"
    {
        if((yyvsp[(2) - (2)].a_constr)->type == ACT_CA_SET && (yyvsp[(2) - (2)].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr));
        }
	}
    break;

  case 224:
#line 1815 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 226:
#line 1820 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
   }
    break;

  case 227:
#line 1826 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
   }
    break;

  case 229:
#line 1838 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 231:
#line 1845 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 233:
#line 1852 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 235:
#line 1860 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 237:
#line 1867 "asn1p_y.y"
    {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        checkmem(ret == 0);
    }
    break;

  case 238:
#line 1878 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 239:
#line 1884 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 245:
#line 1896 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 246:
#line 1896 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 247:
#line 1907 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 248:
#line 1912 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 249:
#line 1917 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 250:
#line 1922 "asn1p_y.y"
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

  case 251:
#line 1934 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
    }
    break;

  case 253:
#line 1944 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
    break;

  case 255:
#line 1951 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
    break;

  case 256:
#line 1957 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 257:
#line 1962 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 261:
#line 1970 "asn1p_y.y"
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

  case 262:
#line 1984 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 263:
#line 1989 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 264:
#line 1997 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		checkmem((yyval.a_value));
    }
    break;

  case 265:
#line 2004 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 266:
#line 2005 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 267:
#line 2013 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 268:
#line 2016 "asn1p_y.y"
    {
        assert((yyvsp[(3) - (3)].a_constr)->type == ACT_CA_CSV);
        (yyvsp[(3) - (3)].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[(3) - (3)].a_constr);
	}
    break;

  case 272:
#line 2024 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 273:
#line 2026 "asn1p_y.y"
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

  case 274:
#line 2039 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(1) - (1)].a_constr));
    }
    break;

  case 275:
#line 2044 "asn1p_y.y"
    {
        (yyval.a_constr) = (yyvsp[(1) - (3)].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 276:
#line 2050 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[(1) - (3)].a_value);
        if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        (yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
    }
    break;

  case 277:
#line 2064 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 278:
#line 2065 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 279:
#line 2069 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 280:
#line 2072 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 281:
#line 2075 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 285:
#line 2090 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 286:
#line 2090 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 287:
#line 2101 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 288:
#line 2110 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 289:
#line 2111 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 290:
#line 2112 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 291:
#line 2113 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 292:
#line 2116 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 293:
#line 2119 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 294:
#line 2128 "asn1p_y.y"
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

  case 295:
#line 2144 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 296:
#line 2150 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 297:
#line 2156 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 298:
#line 2170 "asn1p_y.y"
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

  case 299:
#line 2181 "asn1p_y.y"
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

  case 300:
#line 2197 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 301:
#line 2200 "asn1p_y.y"
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

  case 302:
#line 2220 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 303:
#line 2224 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 304:
#line 2228 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 305:
#line 2232 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 306:
#line 2239 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 307:
#line 2244 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
    }
    break;

  case 308:
#line 2250 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 309:
#line 2259 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 310:
#line 2264 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 311:
#line 2271 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 312:
#line 2279 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 313:
#line 2289 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 314:
#line 2294 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 315:
#line 2301 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[(3) - (4)].a_int));
	}
    break;

  case 316:
#line 2309 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 317:
#line 2319 "asn1p_y.y"
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

  case 318:
#line 2334 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 319:
#line 2339 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 320:
#line 2346 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 321:
#line 2353 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 322:
#line 2361 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 323:
#line 2369 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 324:
#line 2376 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 325:
#line 2387 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 326:
#line 2391 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 328:
#line 2399 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 329:
#line 2430 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 330:
#line 2431 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 331:
#line 2435 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 332:
#line 2442 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 333:
#line 2448 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 334:
#line 2449 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 335:
#line 2450 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 336:
#line 2451 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 337:
#line 2455 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 338:
#line 2456 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 339:
#line 2457 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 340:
#line 2461 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 341:
#line 2465 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 342:
#line 2473 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 343:
#line 2480 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 344:
#line 2481 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 345:
#line 2487 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 346:
#line 2494 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
    }
    break;

  case 347:
#line 2500 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 5048 "asn1p_y.c"
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


#line 2504 "asn1p_y.y"



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


