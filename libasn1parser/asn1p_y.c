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
static int yyerror(const char *msg);

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
#define AL_IMPORT(to, where, from, field)                                      \
    do {                                                                       \
        if(!(from)) break;                                                     \
        while(TQ_FIRST(&((from)->where))) {                                    \
            TQ_ADD(&((to)->where), TQ_REMOVE(&((from)->where), field), field); \
        }                                                                      \
        assert(TQ_FIRST(&((from)->where)) == 0);                               \
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
#define YYLAST   919

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  342
/* YYNRULES -- Number of states.  */
#define YYNSTATES  522

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   122,     2,     2,     2,     2,     2,     2,
     115,   116,     2,     2,   118,     2,   123,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   119,   117,
     124,     2,     2,     2,   125,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   120,     2,   121,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   113,   108,   114,     2,     2,     2,     2,
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
     105,   107,   109,   110,   111,   112
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
     156,   158,   162,   164,   168,   173,   175,   180,   184,   188,
     195,   202,   204,   208,   210,   214,   218,   222,   226,   228,
     232,   234,   236,   238,   240,   241,   243,   245,   249,   255,
     259,   262,   266,   268,   270,   274,   277,   279,   281,   287,
     288,   290,   292,   296,   299,   304,   308,   312,   316,   320,
     324,   325,   327,   328,   335,   337,   340,   342,   344,   346,
     350,   352,   356,   360,   362,   365,   368,   371,   375,   376,
     379,   381,   383,   385,   390,   395,   400,   407,   414,   416,
     421,   425,   427,   429,   433,   437,   441,   443,   447,   449,
     451,   453,   455,   459,   463,   465,   470,   472,   474,   475,
     479,   481,   483,   485,   487,   489,   491,   493,   495,   499,
     501,   503,   505,   507,   510,   512,   514,   516,   518,   520,
     523,   526,   528,   530,   533,   536,   538,   540,   542,   544,
     546,   548,   551,   553,   558,   563,   569,   574,   578,   580,
     582,   584,   586,   588,   590,   592,   594,   596,   598,   600,
     602,   604,   606,   608,   610,   612,   614,   615,   617,   618,
     620,   621,   623,   625,   629,   631,   634,   636,   638,   640,
     642,   644,   648,   654,   656,   660,   662,   666,   668,   672,
     674,   678,   680,   684,   686,   688,   690,   692,   694,   696,
     698,   701,   704,   707,   710,   714,   716,   718,   720,   722,
     724,   726,   728,   731,   733,   737,   741,   743,   745,   747,
     751,   757,   759,   763,   767,   768,   770,   772,   774,   776,
     778,   780,   782,   783,   789,   792,   794,   797,   800,   804,
     806,   808,   812,   817,   819,   823,   826,   830,   832,   836,
     837,   839,   841,   844,   846,   850,   852,   854,   858,   863,
     868,   870,   874,   879,   884,   886,   888,   892,   894,   899,
     904,   906,   908,   910,   912,   914,   915,   917,   920,   925,
     926,   928,   930,   932,   933,   935,   937,   939,   941,   942,
     944,   946,   948
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     127,     0,    -1,   104,   128,    -1,   128,    -1,   129,    -1,
     128,   129,    -1,    -1,   268,   130,   131,    42,   135,     3,
      29,   138,    47,    -1,    -1,   132,    -1,   113,   133,   114,
      -1,   113,   114,    -1,   134,    -1,   133,   134,    -1,   270,
      -1,   270,   115,    12,   116,    -1,    12,    -1,    -1,   136,
      -1,   137,    -1,   136,   137,    -1,    49,    92,    -1,    60,
      92,    -1,    28,    92,    -1,    51,    61,    -1,    18,    65,
      -1,    -1,   139,    -1,   151,   143,   140,    -1,   141,    -1,
     140,   141,    -1,   158,    -1,   193,    -1,   156,    -1,    -1,
      46,    18,   142,    -1,   204,    -1,    -1,   144,    -1,    62,
     145,   117,    -1,    62,    54,    -1,    -1,   146,    -1,   148,
      -1,   146,   148,    -1,    -1,   132,    -1,   149,    54,   268,
     147,    -1,   150,    -1,   149,   118,   150,    -1,   268,    -1,
     268,   113,   114,    -1,   270,    -1,    -1,   152,    -1,    50,
     153,   117,    -1,    50,    25,   117,    -1,    50,   117,    -1,
     154,    -1,   153,   118,   154,    -1,   268,    -1,   268,   113,
     114,    -1,   270,    -1,   113,   214,   114,    -1,   268,   178,
       3,   155,    -1,   187,    -1,   187,   113,   161,   114,    -1,
     268,     3,   178,    -1,   268,     3,   168,    -1,   268,   113,
     159,   114,     3,   178,    -1,   268,   113,   159,   114,     3,
     168,    -1,   160,    -1,   159,   118,   160,    -1,   268,    -1,
     268,   119,   270,    -1,   268,   119,   268,    -1,   201,   119,
     270,    -1,   201,   119,   268,    -1,   162,    -1,   161,   118,
     162,    -1,   181,    -1,   196,    -1,   197,    -1,   155,    -1,
      -1,   164,    -1,   165,    -1,   164,   118,   165,    -1,   164,
     118,     4,   164,     5,    -1,   270,   182,   250,    -1,   182,
     250,    -1,    38,    76,   182,    -1,   177,    -1,   167,    -1,
     166,   118,   167,    -1,   270,   182,    -1,   177,    -1,   182,
      -1,    36,   113,   170,   114,   172,    -1,    -1,    96,    -1,
     171,    -1,   170,   118,   171,    -1,    19,   250,    -1,    20,
     178,   169,   250,    -1,    20,   191,   250,    -1,    20,   192,
     250,    -1,    19,   191,   250,    -1,    19,   178,   250,    -1,
      19,   192,   250,    -1,    -1,   173,    -1,    -1,   103,    90,
     113,   174,   175,   114,    -1,   176,    -1,   175,   176,    -1,
       6,    -1,    21,    -1,   190,    -1,   120,   175,   121,    -1,
     111,    -1,   111,   122,   197,    -1,   111,   122,   261,    -1,
     179,    -1,   263,   181,    -1,   157,   208,    -1,   185,   208,
      -1,   263,   184,   208,    -1,    -1,   183,   185,    -1,   186,
      -1,   157,    -1,   203,    -1,    35,   113,   166,   114,    -1,
      86,   113,   163,   114,    -1,    87,   113,   163,   114,    -1,
      86,   209,    76,   269,   263,   184,    -1,    87,   209,    76,
     269,   263,   184,    -1,    26,    -1,    26,    43,    33,   270,
      -1,    64,    76,   187,    -1,    17,    -1,    18,    -1,    17,
     123,   268,    -1,    18,   123,   268,    -1,    18,   123,   188,
      -1,   189,    -1,   188,   123,   189,    -1,   190,    -1,    19,
      -1,    20,    -1,    19,    -1,   191,   123,    19,    -1,   191,
     123,    20,    -1,    18,    -1,   270,   178,     3,   194,    -1,
     196,    -1,   197,    -1,    -1,   113,   195,   199,    -1,    71,
      -1,    53,    -1,    94,    -1,   261,    -1,   262,    -1,   198,
      -1,   228,    -1,   272,    -1,   268,   123,   270,    -1,     9,
      -1,    15,    -1,    16,    -1,   200,    -1,   199,     7,    -1,
       7,    -1,   270,    -1,    32,    -1,    71,    -1,    84,    -1,
      75,    89,    -1,    73,    59,    -1,    85,    -1,    52,    -1,
      44,    79,    -1,    34,    89,    -1,    99,    -1,    55,    -1,
     204,    -1,   202,    -1,    66,    -1,    48,    -1,    30,    89,
      -1,   201,    -1,    66,   113,   254,   114,    -1,    48,   113,
     258,   114,    -1,    30,    89,   113,   256,   114,    -1,    22,
     113,   252,   114,    -1,    22,   113,   114,    -1,    31,    -1,
      56,    -1,    57,    -1,    58,    -1,    67,    -1,    72,    -1,
      82,    -1,    91,    -1,    93,    -1,    98,    -1,   100,    -1,
     101,    -1,   102,    -1,    74,    -1,   108,    -1,   109,    -1,
     106,    -1,   107,    -1,    -1,   210,    -1,    -1,   211,    -1,
      -1,   210,    -1,   222,    -1,   115,   212,   116,    -1,   210,
      -1,   211,   210,    -1,   213,    -1,   239,    -1,   214,    -1,
     111,    -1,   215,    -1,   215,   118,   111,    -1,   215,   118,
     111,   118,   215,    -1,   216,    -1,    25,   105,   219,    -1,
     217,    -1,   216,   205,   217,    -1,   218,    -1,   217,   206,
     218,    -1,   219,    -1,   219,   105,   219,    -1,   220,    -1,
     115,   215,   116,    -1,   227,    -1,   229,    -1,   221,    -1,
     222,    -1,   230,    -1,   223,    -1,   224,    -1,    54,   210,
      -1,    88,   210,    -1,    78,     9,    -1,    78,   270,    -1,
     225,   243,   226,    -1,   227,    -1,    69,    -1,   227,    -1,
      68,    -1,   194,    -1,     8,    -1,    10,    -1,    63,   178,
      -1,   180,    -1,   103,    37,   231,    -1,   103,    38,   232,
      -1,   210,    -1,   233,    -1,   234,    -1,   113,   235,   114,
      -1,   113,   111,   118,   235,   114,    -1,   236,    -1,   235,
     118,   236,    -1,   272,   207,   237,    -1,    -1,   238,    -1,
      81,    -1,    23,    -1,    77,    -1,   240,    -1,   244,    -1,
     242,    -1,    -1,    39,    33,   113,   241,   199,    -1,    40,
     178,    -1,   110,    -1,   110,   124,    -1,   124,   110,    -1,
     124,   110,   124,    -1,   245,    -1,   246,    -1,   113,   268,
     114,    -1,   245,   113,   247,   114,    -1,   248,    -1,   247,
     118,   248,    -1,   125,   249,    -1,   125,   123,   249,    -1,
     270,    -1,   249,   123,   270,    -1,    -1,   251,    -1,    77,
      -1,    41,   194,    -1,   253,    -1,   252,   118,   253,    -1,
     270,    -1,   255,    -1,   254,   118,   255,    -1,   270,   115,
     261,   116,    -1,   270,   115,   197,   116,    -1,   257,    -1,
     256,   118,   257,    -1,   270,   115,    12,   116,    -1,   270,
     115,   197,   116,    -1,   259,    -1,   260,    -1,   259,   118,
     260,    -1,   270,    -1,   270,   115,   261,   116,    -1,   270,
     115,   197,   116,    -1,   261,    -1,   111,    -1,    12,    -1,
      13,    -1,    14,    -1,    -1,   264,    -1,   265,   267,    -1,
     120,   266,    12,   121,    -1,    -1,    97,    -1,    27,    -1,
      83,    -1,    -1,    60,    -1,    49,    -1,    17,    -1,    18,
      -1,    -1,   270,    -1,    11,    -1,   270,    -1,   271,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   414,   414,   417,   423,   428,   445,   445,   474,   475,
     479,   482,   488,   494,   503,   507,   511,   521,   522,   531,
     534,   543,   546,   549,   552,   556,   577,   578,   587,   600,
     603,   620,   627,   641,   649,   648,   662,   675,   676,   679,
     689,   695,   696,   699,   704,   711,   712,   716,   727,   732,
     739,   745,   751,   761,   762,   774,   777,   780,   788,   793,
     800,   806,   812,   821,   824,   844,   854,   874,   880,   896,
     902,   910,   919,   930,   934,   942,   950,   958,   969,   974,
     981,   982,   990,   998,  1021,  1022,  1025,  1030,  1034,  1042,
    1049,  1055,  1062,  1068,  1073,  1080,  1085,  1088,  1095,  1105,
    1106,  1110,  1117,  1127,  1137,  1148,  1158,  1169,  1179,  1190,
    1202,  1203,  1210,  1209,  1218,  1222,  1229,  1233,  1236,  1240,
    1246,  1254,  1263,  1274,  1277,  1284,  1307,  1330,  1354,  1361,
    1380,  1381,  1384,  1385,  1391,  1397,  1403,  1413,  1423,  1429,
    1441,  1456,  1464,  1472,  1483,  1494,  1516,  1524,  1533,  1537,
    1542,  1551,  1556,  1561,  1569,  1592,  1602,  1603,  1604,  1604,
    1612,  1617,  1622,  1627,  1628,  1629,  1630,  1634,  1635,  1653,
    1657,  1662,  1670,  1679,  1694,  1695,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1720,
    1721,  1722,  1726,  1732,  1737,  1742,  1747,  1752,  1761,  1762,
    1766,  1770,  1771,  1772,  1773,  1774,  1778,  1779,  1780,  1781,
    1785,  1786,  1793,  1793,  1794,  1794,  1798,  1799,  1803,  1804,
    1808,  1809,  1810,  1814,  1820,  1821,  1830,  1830,  1832,  1835,
    1839,  1840,  1846,  1857,  1858,  1864,  1865,  1871,  1872,  1879,
    1880,  1886,  1887,  1898,  1904,  1910,  1911,  1913,  1914,  1915,
    1920,  1925,  1930,  1935,  1947,  1956,  1957,  1963,  1964,  1969,
    1972,  1977,  1985,  1991,  2003,  2006,  2012,  2013,  2013,  2014,
    2016,  2029,  2034,  2040,  2054,  2055,  2059,  2062,  2065,  2073,
    2074,  2075,  2080,  2079,  2091,  2100,  2101,  2102,  2103,  2106,
    2109,  2118,  2134,  2140,  2146,  2160,  2171,  2187,  2190,  2210,
    2214,  2218,  2222,  2229,  2234,  2240,  2249,  2254,  2261,  2269,
    2279,  2284,  2291,  2299,  2309,  2324,  2329,  2336,  2343,  2351,
    2359,  2366,  2377,  2381,  2388,  2419,  2420,  2424,  2431,  2437,
    2438,  2439,  2440,  2444,  2445,  2446,  2450,  2454,  2462,  2463,
    2469,  2476,  2483
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
  "'|'", "TOK_UNION", "\"..\"", "\"...\"", "\"concrete TypeDeclaration\"",
  "'{'", "'}'", "'('", "')'", "';'", "','", "':'", "'['", "']'", "'!'",
  "'.'", "'<'", "'@'", "$accept", "ParsedGrammar", "ModuleList",
  "ModuleDefinition", "@1", "optObjectIdentifier", "ObjectIdentifier",
  "ObjectIdentifierBody", "ObjectIdentifierElement",
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
  "ObjectClass", "optUNIQUE", "FieldSpec", "ClassField", "optWithSyntax",
  "WithSyntax", "@3", "WithSyntaxList", "WithSyntaxToken",
  "ExtensionAndException", "Type", "TaggedType", "DefinedUntaggedType",
  "UntaggedType", "MaybeIndirectTaggedType", "NSTD_IndirectMarker",
  "MaybeIndirectTypeDeclaration", "TypeDeclaration",
  "ConcreteTypeDeclaration", "ComplexTypeReference",
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement",
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass",
  "ValueAssignment", "Value", "@4", "SimpleValue", "DefinedValue",
  "RestrictedCharacterStringValue", "Opaque", "OpaqueFirstToken",
  "BasicTypeId", "BasicTypeId_UniverationCompatible", "BuiltinType",
  "BasicString", "UnionMark", "IntersectionMark", "optConstraint",
  "optManyConstraints", "optSizeOrConstraint", "Constraint",
  "ManyConstraints", "ConstraintSpec", "SubtypeConstraint",
  "ElementSetSpecs", "ElementSetSpec", "Unions", "Intersections",
  "IntersectionElements", "Elements", "SubtypeElements",
  "PermittedAlphabet", "SizeConstraint", "PatternConstraint", "ValueRange",
  "LowerEndValue", "UpperEndValue", "SingleValue", "BitStringValue",
  "ContainedSubtype", "InnerTypeConstraints", "SingleTypeConstraint",
  "MultipleTypeConstraints", "FullSpecification", "PartialSpecification",
  "TypeConstraints", "NamedConstraint", "optPresenceConstraint",
  "PresenceConstraint", "GeneralConstraint", "UserDefinedConstraint", "@5",
  "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint",
  "SimpleTableConstraint", "ComponentRelationConstraint", "AtNotationList",
  "AtNotationElement", "ComponentIdList", "optMarker", "Marker",
  "IdentifierList", "IdentifierElement", "NamedNumberList", "NamedNumber",
  "NamedBitList", "NamedBit", "Enumerations", "UniverationList",
  "UniverationElement", "SignedNumber", "RealValue", "optTag", "Tag",
  "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName", "optIdentifier",
  "Identifier", "IdentifierAsReference", "IdentifierAsValue", 0
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
     363,   364,   365,   123,   125,    40,    41,    59,    44,    58,
      91,    93,    33,    46,    60,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   126,   127,   127,   128,   128,   130,   129,   131,   131,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   140,
     140,   141,   141,   141,   142,   141,   141,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   149,   149,
     150,   150,   150,   151,   151,   152,   152,   152,   153,   153,
     154,   154,   154,   155,   156,   157,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   161,   161,
     162,   162,   162,   162,   163,   163,   164,   164,   164,   165,
     165,   165,   165,   166,   166,   167,   167,   167,   168,   169,
     169,   170,   170,   171,   171,   171,   171,   171,   171,   171,
     172,   172,   174,   173,   175,   175,   176,   176,   176,   176,
     177,   177,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   187,   187,   188,   188,   189,   190,
     190,   191,   191,   191,   192,   193,   194,   194,   195,   194,
     196,   196,   196,   196,   196,   196,   196,   197,   197,   198,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   202,
     202,   202,   203,   203,   203,   203,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   209,   210,   211,   211,   212,   212,   213,   214,
     214,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   220,   220,   220,   220,   220,
     221,   222,   223,   223,   224,   225,   225,   226,   226,   227,
     228,   228,   229,   229,   230,   230,   231,   232,   232,   233,
     234,   235,   235,   236,   237,   237,   238,   238,   238,   239,
     239,   239,   241,   240,   242,   243,   243,   243,   243,   244,
     244,   245,   246,   247,   247,   248,   248,   249,   249,   250,
     250,   251,   251,   252,   252,   253,   254,   254,   255,   255,
     256,   256,   257,   257,   258,   259,   259,   260,   260,   260,
     260,   260,   261,   261,   262,   263,   263,   264,   265,   266,
     266,   266,   266,   267,   267,   267,   268,   268,   269,   269,
     270,   271,   272
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
       1,     3,     1,     3,     4,     1,     4,     3,     3,     6,
       6,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     0,     1,     1,     3,     5,     3,
       2,     3,     1,     1,     3,     2,     1,     1,     5,     0,
       1,     1,     3,     2,     4,     3,     3,     3,     3,     3,
       0,     1,     0,     6,     1,     2,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     2,     2,     3,     0,     2,
       1,     1,     1,     4,     4,     4,     6,     6,     1,     4,
       3,     1,     1,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     3,     3,     1,     4,     1,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     4,     4,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       0,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     3,
       5,     1,     3,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     2,     1,     2,     2,     3,     1,
       1,     3,     4,     1,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     1,     3,     1,     1,     3,     4,     4,
       1,     3,     4,     4,     1,     1,     3,     1,     4,     4,
       1,     1,     1,     1,     1,     0,     1,     2,     4,     0,
       1,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   336,   337,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   340,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     198,     0,   199,   200,   201,   202,   203,   211,   204,   205,
     206,   207,   208,   209,   210,    28,    29,    33,    31,    32,
      36,   325,   325,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   325,     0,   329,     0,   123,     0,   326,   333,
       0,    45,    49,    51,    35,     0,    68,    67,     0,   176,
       0,     0,   190,   182,   186,   189,   177,     0,     0,   178,
     181,   185,     0,    71,     0,   188,   187,    73,   331,   332,
     330,     0,     0,   141,   142,     0,   138,     0,     0,   190,
       0,   189,   220,   220,   131,   124,   218,   130,    65,   192,
     132,   335,   334,   327,     0,    46,    47,     0,   191,   184,
     183,   180,   179,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,     0,   191,   325,     0,     0,     0,     0,
     325,     0,     0,   221,   222,   325,     0,   126,   224,   219,
       0,   260,   169,   261,   322,   323,   324,   170,   171,   161,
     160,   162,   158,   155,   156,   157,   165,   166,   163,   164,
       0,   341,   342,   167,   325,   325,     0,   101,   325,    72,
      77,    76,    75,    74,   328,   141,   142,     0,     0,   325,
     256,     0,     0,   229,     0,   218,   263,   259,     0,   230,
     233,   235,   237,   239,   241,   245,   246,   248,   249,     0,
     243,   244,   247,   143,   149,   150,   145,   146,   148,   144,
     197,     0,   303,   305,     0,     0,   120,     0,    93,    96,
      97,   128,   325,   321,     0,   314,   315,   320,   317,   140,
       0,   306,     0,   251,     0,     0,    85,    86,    92,   299,
     325,     0,   325,   158,     0,   226,   228,   227,   279,   281,
     280,   289,   290,   338,     0,   338,   225,   160,    83,     0,
      78,    80,    81,    82,     0,     0,   154,   151,     0,   301,
     299,   299,   299,   103,   300,    99,   299,   299,   110,     0,
      70,    69,     0,   250,   262,   252,   253,     0,     0,     0,
     125,    63,     0,   212,   213,     0,   214,   215,     0,     0,
     285,     0,     0,     0,   196,     0,   139,     0,   310,     0,
       0,   133,   325,     0,   218,    95,   194,     0,     0,   193,
       0,     0,   325,   134,   325,    90,   299,     0,   284,     0,
     223,     0,   325,   339,   135,   325,    66,     0,   174,   159,
     172,   175,   168,   302,   108,     0,   107,   109,   100,   299,
     105,   106,     0,    98,   111,   102,   234,   266,   264,     0,
     265,   267,   268,   242,   231,   236,   238,   240,   286,   287,
     258,   254,   257,   147,   304,   195,     0,     0,   121,   122,
      94,   129,   127,   316,     0,     0,   307,     0,     0,    91,
     325,    87,    89,   282,   291,     0,     0,   293,   128,   128,
      79,   173,   152,   153,   104,     0,     0,     0,   271,   216,
       0,   288,   311,     0,     0,   319,   318,   309,   308,     0,
       0,     0,   295,   297,   292,     0,   136,   137,   112,     0,
     269,     0,   274,   217,   232,   312,   313,    88,   283,   296,
       0,   294,     0,     0,   272,   277,   278,   276,   273,   275,
     298,   116,   117,     0,     0,   114,   118,   270,     0,   113,
     115,   119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   114,    56,    57,    63,
      64,   166,    65,    66,    67,    46,    47,    50,    51,   318,
      87,   245,    88,   132,   133,   319,   320,   295,   296,   297,
     277,   278,   116,   409,   226,   227,   413,   414,   502,   514,
     515,   298,   105,   106,   246,   321,   299,   373,   374,   156,
     157,   158,   266,   267,   516,   331,   332,    89,   247,   324,
     214,   215,   216,   399,   400,   159,   135,   160,   136,   355,
     358,   492,   197,   192,   198,   199,   304,   305,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     431,   260,   217,   261,   262,   418,   420,   421,   422,   467,
     468,   508,   509,   307,   308,   480,   309,   362,   310,   311,
     312,   456,   457,   482,   333,   334,   271,   272,   290,   291,
     367,   368,   284,   285,   286,   218,   219,   281,   108,   109,
     141,   163,   220,   392,   221,   222,   223
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -296
static const yytype_int16 yypact[] =
{
      51,  -296,  -296,   217,    41,   217,  -296,  -296,   217,  -296,
    -296,   -63,    53,    43,  -296,  -296,  -296,  -296,    70,  -296,
     -45,   204,  -296,  -296,    79,    32,    30,    38,   110,    87,
     200,   204,  -296,    95,  -296,  -296,  -296,  -296,  -296,   198,
    -296,  -296,   247,    12,   178,  -296,   174,  -296,   134,  -296,
     140,  -296,   183,  -296,  -296,    72,   663,  -296,  -296,  -296,
     213,   173,  -296,   187,   213,  -296,    50,  -296,   211,  -296,
    -296,   293,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,   663,  -296,  -296,  -296,  -296,
    -296,    19,   219,  -296,  -296,  -296,  -296,   217,   213,   227,
    -296,  -296,    -2,   817,    68,   340,  -296,   740,  -296,   120,
     356,   -63,  -296,  -296,  -296,   249,  -296,  -296,   272,  -296,
     274,   285,  -296,  -296,  -296,  -296,  -296,   307,   278,  -296,
    -296,  -296,    13,  -296,   250,  -296,  -296,   251,  -296,  -296,
    -296,   359,   260,   264,   265,   261,   346,   301,   279,   281,
     315,   294,   113,   135,  -296,  -296,   280,  -296,   295,  -296,
    -296,  -296,  -296,  -296,   510,  -296,  -296,   290,  -296,  -296,
    -296,  -296,  -296,   406,   817,   213,   213,   289,   368,  -296,
     217,   309,    14,   378,   299,    29,   108,   318,   403,   280,
      61,   229,   339,  -296,  -296,    61,   341,  -296,  -296,   280,
     604,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
     296,  -296,  -296,  -296,    84,    28,    98,  -296,    -2,  -296,
    -296,  -296,  -296,  -296,  -296,   264,   265,   311,   280,   219,
    -296,   104,   300,  -296,   388,   280,  -296,  -296,   304,   302,
     237,   241,  -296,   320,  -296,  -296,  -296,  -296,  -296,   -18,
     -17,  -296,  -296,  -296,  -296,  -296,   303,  -296,  -296,  -296,
    -296,   138,  -296,  -296,   403,   403,   305,   167,  -296,  -296,
    -296,  -296,   219,  -296,   314,   312,  -296,  -296,   308,  -296,
     170,  -296,   317,  -296,   353,   319,   316,  -296,  -296,    -3,
     219,   402,   219,   217,   324,  -296,  -296,  -296,  -296,  -296,
    -296,   323,  -296,   403,   331,   403,  -296,   329,  -296,   172,
    -296,  -296,  -296,  -296,   282,   403,  -296,  -296,   510,  -296,
      -3,    10,    -3,  -296,  -296,   351,    10,    -3,   345,   290,
    -296,  -296,   496,  -296,  -296,  -296,  -296,   280,   336,   334,
    -296,  -296,   342,  -296,  -296,   496,  -296,  -296,   496,   496,
     328,   344,   262,   330,  -296,   403,  -296,   181,  -296,   343,
     248,  -296,    29,   740,   280,  -296,  -296,   108,   248,  -296,
     403,   248,   219,  -296,    24,  -296,    -3,   347,  -296,   349,
    -296,   348,   219,  -296,  -296,   219,  -296,   604,  -296,   448,
    -296,  -296,  -296,  -296,  -296,   332,  -296,  -296,  -296,    -3,
    -296,  -296,   371,  -296,  -296,  -296,  -296,  -296,  -296,    25,
    -296,  -296,  -296,  -296,   352,   241,  -296,  -296,  -296,   350,
    -296,  -296,  -296,  -296,  -296,  -296,   403,   196,  -296,  -296,
    -296,  -296,  -296,  -296,   361,   362,  -296,   364,   369,  -296,
      42,  -296,  -296,  -296,  -296,    22,   188,  -296,  -296,  -296,
    -296,  -296,  -296,  -296,  -296,   354,   357,   202,  -296,   280,
     388,  -296,  -296,   370,   373,  -296,  -296,  -296,  -296,    16,
     282,   403,   367,  -296,  -296,   348,  -296,  -296,  -296,   403,
    -296,   403,    77,  -296,  -296,  -296,  -296,  -296,   448,   367,
     403,  -296,    57,   207,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,  -296,    57,    36,  -296,  -296,  -296,    39,  -296,
    -296,  -296
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -296,  -296,   461,   326,  -296,  -296,   376,  -296,   447,  -296,
    -296,   441,  -296,  -296,  -296,   399,  -296,  -296,  -296,  -296,
    -296,  -296,   428,  -296,   395,  -296,  -296,  -296,   434,   355,
    -296,  -106,  -296,  -296,   321,  -296,    99,   322,    48,   115,
    -296,   128,   287,  -296,  -296,   163,  -296,  -296,  -296,     3,
    -196,  -172,   -82,  -296,  -296,   422,  -177,  -296,  -104,   157,
    -296,   358,  -296,   168,  -164,   310,   313,  -296,  -140,  -296,
    -191,  -188,  -296,    52,  -296,   -76,  -296,  -296,   -24,  -296,
    -296,  -296,  -227,   380,  -150,  -296,  -296,  -296,   360,  -237,
    -296,   179,   182,  -258,  -296,  -296,   205,  -296,  -296,  -296,
    -296,   175,  -296,  -296,  -296,  -296,  -296,  -296,  -296,    47,
      55,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,  -296,
    -296,  -296,    54,    60,  -220,  -296,  -296,   177,  -296,   164,
    -296,   107,  -296,  -296,   171,  -160,  -296,   -87,  -296,  -296,
    -296,  -296,    11,   232,   -12,  -296,  -295
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -300
static const yytype_int16 yytable[] =
{
      20,   154,   193,   193,   107,   107,    20,   349,   280,   322,
     110,     7,   323,   279,     7,   107,     7,   268,   350,     7,
     117,   497,   102,    15,   213,    15,   287,   134,   450,     1,
       2,    53,    90,    15,   115,    15,    15,    48,   328,   293,
      15,     9,   511,    69,    92,   511,   326,   327,    53,   316,
      12,   328,    69,    15,    52,   264,   265,   512,   264,   265,
     512,    90,   294,   511,    15,    16,    68,    91,     1,     2,
      24,    52,    15,    92,   329,    68,   264,   265,   512,   385,
     294,    15,    16,    15,   416,    21,    69,   329,   343,     1,
       2,    33,   360,  -255,   154,   138,    91,    34,   134,   294,
     505,   427,   326,   327,    97,   375,   361,  -255,   111,    68,
     404,   406,   407,   345,   137,    15,   410,   411,   104,    15,
     204,   205,    35,   386,   469,   328,    62,   173,   270,    49,
      36,   174,   103,   405,   384,   276,   466,   107,   107,   104,
     276,   107,   330,   335,   104,   481,   341,   442,   104,   104,
     519,   139,   107,   276,   506,     3,   513,   344,   507,   513,
     521,   329,   104,   231,   233,   140,   452,    17,    98,   161,
     273,    37,   276,   282,   288,   -84,   292,   513,   300,    38,
     162,   104,   438,   300,    22,   137,   230,   232,   403,   464,
     444,   263,   269,   447,   469,   280,   469,   417,  -299,   268,
     279,   189,  -299,    39,   104,   449,   322,    15,   473,   323,
     439,    41,   338,     1,     2,   107,   339,   287,   445,   283,
     388,   448,    25,   189,    15,    54,   190,    42,   191,   346,
       1,     2,    26,   494,     1,     2,    55,   201,   202,   203,
      15,   204,   205,   206,   207,   208,   235,   236,   195,   474,
     191,    58,   364,    27,   237,    28,   365,    59,    60,    15,
     204,   205,   366,   369,    29,     1,     2,   154,   301,   302,
     201,   202,   203,    15,   204,   205,   206,   207,   208,     1,
       2,   371,   209,   238,   379,   372,   396,    94,   380,   398,
     397,   154,   239,    15,   -26,   435,    61,    43,   240,   436,
     210,   393,   484,   393,    95,   458,   485,   241,   459,   224,
     225,   100,   401,   402,   389,   209,   490,   189,   520,   493,
     491,   517,   520,   211,    99,   491,     1,     2,   264,   265,
     430,    10,   242,   210,    10,   143,   144,   347,   348,   104,
     243,   113,   303,   142,   244,   353,   354,   356,   357,   264,
     265,   462,   463,   273,   486,   487,   211,   194,   194,   164,
     282,   168,   167,   169,   170,   288,   171,   172,   292,   175,
     176,   177,   300,   178,   182,   212,   201,   202,   203,    15,
     204,   205,   206,   207,   208,   235,   236,   180,   181,   183,
     184,   187,   185,   237,   186,   191,   201,   202,   203,    15,
     204,   205,   206,   207,   208,   235,   236,   188,   200,   228,
     234,   274,   275,   237,    15,   313,   342,   315,   351,   325,
     352,   209,   238,   378,   369,   359,   363,   370,   376,   382,
     377,   239,   381,   383,   384,   387,   391,   240,   300,   210,
     390,   209,   238,   483,  -177,   394,   241,   408,   412,   419,
     423,   239,   428,   424,   429,   461,   189,   240,   437,   210,
     453,   465,   211,   454,     8,    23,   241,   488,   401,   483,
     470,   242,    40,   455,   471,   489,   189,   475,   476,   243,
     477,   212,   211,   244,   101,   478,   495,   165,   510,   496,
     500,   242,    96,   112,    93,   229,   460,   179,   479,   451,
     440,   212,   415,   244,   201,   202,   203,    15,   204,   205,
     206,   207,   208,   235,   236,   340,   518,   314,   201,   202,
     203,    15,   204,   205,   206,   207,   208,     1,     2,   155,
     441,   433,   498,   196,   425,   336,   503,   432,   337,   501,
     426,   499,   434,   472,   446,   289,   504,   395,   443,   209,
     238,   306,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,   209,     0,   240,     0,   210,     0,     0,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,   210,     0,     0,   189,     0,     0,     0,     0,     0,
     211,     0,     0,     0,     0,     0,     0,     0,     0,   242,
       0,     0,     0,     0,   211,     0,     0,     0,     0,   212,
       0,   244,   201,   202,   203,    15,   204,   205,   206,   207,
     208,   235,   236,   212,     0,     0,   145,     0,     0,     0,
     146,     0,     0,     0,   147,    70,   119,     0,   120,   148,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   149,     0,     0,     0,   123,   209,     0,   124,
      72,    73,    74,     0,     0,     0,     0,     0,   150,     0,
     151,    75,     0,     0,    15,   317,    76,   127,    77,   128,
       1,     2,     0,     0,     0,     0,    78,     0,   129,   130,
     152,   153,     0,     0,    70,    79,     0,    80,   211,     0,
       0,     0,    81,   131,    82,    83,    84,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,   178,     0,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,    76,     0,    77,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,    80,   143,   144,     0,
       0,    81,   145,    82,    83,    84,   146,     0,     0,     0,
     147,    70,   119,     0,   120,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   149,     0,
       0,     0,   123,     0,     0,   124,    72,    73,    74,     0,
       0,     0,     0,     0,   150,     0,   151,    75,     0,     0,
       0,   126,    76,   127,    77,   128,     0,     0,     0,     0,
       0,     0,    78,     0,   129,   130,   152,   153,     0,     0,
       0,    79,     0,    80,     1,     2,     0,     0,    81,   131,
      82,    83,    84,     0,     0,     0,     0,   118,    70,   119,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,     0,     0,   123,
       0,     0,   124,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   125,    75,     0,     0,     0,   126,    76,
     127,    77,   128,     0,     0,     0,     0,     0,     0,    78,
       0,   129,   130,     0,     0,     0,     0,     0,    79,     0,
      80,     0,     0,     0,     0,    81,   131,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   107,   152,   153,    91,    92,    18,   244,   185,   200,
      92,     0,   200,   185,     3,   102,     5,   181,   245,     8,
     102,     5,     3,    11,   164,    11,   186,   103,     4,    17,
      18,    43,    56,    11,    36,    11,    11,    25,    41,   189,
      11,     0,     6,    55,    56,     6,    18,    19,    60,   199,
     113,    41,    64,    11,    43,    19,    20,    21,    19,    20,
      21,    85,    38,     6,    11,    12,    55,    56,    17,    18,
     115,    60,    11,    85,    77,    64,    19,    20,    21,   299,
      38,    11,    12,    11,   342,    42,    98,    77,   238,    17,
      18,    12,   110,   110,   200,    27,    85,    65,   174,    38,
      23,   359,    18,    19,    54,   282,   124,   124,    97,    98,
     330,   331,   332,     9,   103,    11,   336,   337,   120,    11,
      12,    13,    92,   300,   419,    41,    54,   114,   114,   117,
      92,   118,   113,   123,   118,   111,   111,   224,   225,   120,
     111,   228,   224,   225,   120,   123,   228,   374,   120,   120,
     114,    83,   239,   111,    77,   104,   120,   239,    81,   120,
     121,    77,   120,   175,   176,    97,   386,   114,   118,    49,
     182,    61,   111,   185,   186,   114,   188,   120,   190,    92,
      60,   120,   370,   195,   114,   174,   175,   176,   328,   409,
     378,   180,   181,   381,   489,   372,   491,   347,   114,   363,
     372,    88,   118,     3,   120,   382,   397,    11,    12,   397,
     370,   116,   114,    17,    18,   302,   118,   377,   378,   111,
     302,   381,    18,    88,    11,    47,   113,    29,   115,   241,
      17,    18,    28,   470,    17,    18,    62,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   113,   437,
     115,   117,   114,    49,    25,    51,   118,   117,   118,    11,
      12,    13,   274,   275,    60,    17,    18,   373,    39,    40,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   114,    53,    54,   114,   118,   114,   114,   118,     7,
     118,   397,    63,    11,    47,   114,   113,    50,    69,   118,
      71,   313,   114,   315,   117,   392,   118,    78,   395,    19,
      20,    18,   324,   325,   303,    53,   114,    88,   514,   469,
     118,   114,   518,    94,   113,   118,    17,    18,    19,    20,
      68,     5,   103,    71,     8,    17,    18,    37,    38,   120,
     111,   114,   113,     3,   115,   108,   109,   106,   107,    19,
      20,    19,    20,   365,   458,   459,    94,   152,   153,     3,
     372,    89,   113,    89,    79,   377,    59,    89,   380,   119,
     119,    12,   384,   113,   113,   113,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   123,   123,    43,
      89,    76,   113,    25,   113,   115,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   113,   113,     3,
     121,    33,   113,    25,    11,    76,   105,    76,   114,   123,
     118,    53,    54,   115,   436,   105,   123,   122,   114,    76,
     118,    63,   115,   114,   118,    33,   113,    69,   450,    71,
     116,    53,    54,   455,   115,   114,    78,    96,   103,   113,
     116,    63,   124,   111,   110,     7,    88,    69,   115,    71,
     113,    90,    94,   114,     3,    18,    78,   113,   480,   481,
     118,   103,    31,   125,   124,   118,    88,   116,   116,   111,
     116,   113,    94,   115,    85,   116,   116,   111,   500,   116,
     123,   103,    64,    98,    60,   174,   397,   142,   450,   384,
     372,   113,   339,   115,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   228,   513,   195,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   107,
     373,   363,   480,   153,   355,   225,   489,   362,   225,   485,
     358,   481,   365,   436,   380,   187,   491,   315,   377,    53,
      54,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    53,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,   113,
      -1,   115,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   113,    -1,    -1,    22,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      66,    67,    -1,    -1,    11,    71,    72,    73,    74,    75,
      17,    18,    -1,    -1,    -1,    -1,    82,    -1,    84,    85,
      86,    87,    -1,    -1,    31,    91,    -1,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    93,    17,    18,    -1,
      -1,    98,    22,   100,   101,   102,    26,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    85,    86,    87,    -1,    -1,
      -1,    91,    -1,    93,    17,    18,    -1,    -1,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    17,    18,   104,   127,   128,   129,   268,   128,     0,
     129,   130,   113,   131,   132,    11,    12,   114,   133,   134,
     270,    42,   114,   134,   115,    18,    28,    49,    51,    60,
     135,   136,   137,    12,    65,    92,    92,    61,    92,     3,
     137,   116,    29,    50,   138,   139,   151,   152,    25,   117,
     153,   154,   268,   270,    47,    62,   143,   144,   117,   117,
     118,   113,    54,   145,   146,   148,   149,   150,   268,   270,
      31,    46,    56,    57,    58,    67,    72,    74,    82,    91,
      93,    98,   100,   101,   102,   140,   141,   156,   158,   193,
     204,   268,   270,   154,   114,   117,   148,    54,   118,   113,
      18,   141,     3,   113,   120,   178,   179,   263,   264,   265,
     178,   268,   150,   114,   142,    36,   168,   178,    30,    32,
      34,    44,    48,    52,    55,    66,    71,    73,    75,    84,
      85,    99,   159,   160,   201,   202,   204,   268,    27,    83,
      97,   266,     3,    17,    18,    22,    26,    30,    35,    48,
      64,    66,    86,    87,   157,   181,   185,   186,   187,   201,
     203,    49,    60,   267,     3,   132,   147,   113,    89,    89,
      79,    59,    89,   114,   118,   119,   119,    12,   113,   155,
     123,   123,   113,    43,    89,   113,   113,    76,   113,    88,
     113,   115,   209,   210,   222,   113,   209,   208,   210,   211,
     113,     8,     9,    10,    12,    13,    14,    15,    16,    53,
      71,    94,   113,   194,   196,   197,   198,   228,   261,   262,
     268,   270,   271,   272,    19,    20,   170,   171,     3,   160,
     268,   270,   268,   270,   121,    17,    18,    25,    54,    63,
      69,    78,   103,   111,   115,   157,   180,   194,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     227,   229,   230,   268,    19,    20,   188,   189,   190,   268,
     114,   252,   253,   270,    33,   113,   111,   166,   167,   177,
     182,   263,   270,   111,   258,   259,   260,   261,   270,   187,
     254,   255,   270,   210,    38,   163,   164,   165,   177,   182,
     270,    39,    40,   113,   212,   213,   214,   239,   240,   242,
     244,   245,   246,    76,   163,    76,   210,    71,   155,   161,
     162,   181,   196,   197,   195,   123,    18,    19,    41,    77,
     178,   191,   192,   250,   251,   178,   191,   192,   114,   118,
     168,   178,   105,   210,   178,     9,   270,    37,    38,   215,
     208,   114,   118,   108,   109,   205,   106,   107,   206,   105,
     110,   124,   243,   123,   114,   118,   270,   256,   257,   270,
     122,   114,   118,   183,   184,   182,   114,   118,   115,   114,
     118,   115,    76,   114,   118,   250,   182,    33,   178,   268,
     116,   113,   269,   270,   114,   269,   114,   118,     7,   199,
     200,   270,   270,   194,   250,   123,   250,   250,    96,   169,
     250,   250,   103,   172,   173,   171,   219,   210,   231,   113,
     232,   233,   234,   116,   111,   217,   218,   219,   124,   110,
      68,   226,   227,   189,   253,   114,   118,   115,   197,   261,
     167,   185,   208,   260,   197,   261,   255,   197,   261,   182,
       4,   165,   250,   113,   114,   125,   247,   248,   263,   263,
     162,     7,    19,    20,   250,    90,   111,   235,   236,   272,
     118,   124,   257,    12,   197,   116,   116,   116,   116,   164,
     241,   123,   249,   270,   114,   118,   184,   184,   113,   118,
     114,   118,   207,   210,   215,   116,   116,     5,   199,   249,
     123,   248,   174,   235,   236,    23,    77,    81,   237,   238,
     270,     6,    21,   120,   175,   176,   190,   114,   175,   114,
     176,   121
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
#line 414 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(2) - (2)].a_grammar);
	}
    break;

  case 3:
#line 417 "asn1p_y.y"
    {
		*(void **)param = (yyvsp[(1) - (1)].a_grammar);
	}
    break;

  case 4:
#line 423 "asn1p_y.y"
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(1) - (1)].a_module), mod_next);
	}
    break;

  case 5:
#line 428 "asn1p_y.y"
    {
		(yyval.a_grammar) = (yyvsp[(1) - (2)].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[(2) - (2)].a_module), mod_next);
	}
    break;

  case 6:
#line 445 "asn1p_y.y"
    { currentModule = asn1p_module_new(); }
    break;

  case 7:
#line 450 "asn1p_y.y"
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
#line 474 "asn1p_y.y"
    { (yyval.a_oid) = 0; }
    break;

  case 9:
#line 475 "asn1p_y.y"
    { (yyval.a_oid) = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 10:
#line 479 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(2) - (3)].a_oid);
	}
    break;

  case 11:
#line 482 "asn1p_y.y"
    {
		(yyval.a_oid) = 0;
	}
    break;

  case 12:
#line 488 "asn1p_y.y"
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(1) - (1)].a_oid_arc));
		if((yyvsp[(1) - (1)].a_oid_arc).name)
			free((yyvsp[(1) - (1)].a_oid_arc).name);
	}
    break;

  case 13:
#line 494 "asn1p_y.y"
    {
		(yyval.a_oid) = (yyvsp[(1) - (2)].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[(2) - (2)].a_oid_arc));
		if((yyvsp[(2) - (2)].a_oid_arc).name)
			free((yyvsp[(2) - (2)].a_oid_arc).name);
	}
    break;

  case 14:
#line 503 "asn1p_y.y"
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
    break;

  case 15:
#line 507 "asn1p_y.y"
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 16:
#line 511 "asn1p_y.y"
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[(1) - (1)].a_int);
	}
    break;

  case 17:
#line 521 "asn1p_y.y"
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
    break;

  case 18:
#line 522 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 19:
#line 531 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (1)].a_module_flags);
	}
    break;

  case 20:
#line 534 "asn1p_y.y"
    {
		(yyval.a_module_flags) = (yyvsp[(1) - (2)].a_module_flags) | (yyvsp[(2) - (2)].a_module_flags);
	}
    break;

  case 21:
#line 543 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
    break;

  case 22:
#line 546 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
    break;

  case 23:
#line 549 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
    break;

  case 24:
#line 552 "asn1p_y.y"
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
    break;

  case 25:
#line 556 "asn1p_y.y"
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
#line 577 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 27:
#line 578 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 28:
#line 587 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[(1) - (3)].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[(2) - (3)].a_module), xp_next);
		asn1p_module_move_members((yyval.a_module), (yyvsp[(3) - (3)].a_module));

		asn1p_module_free((yyvsp[(1) - (3)].a_module));
		asn1p_module_free((yyvsp[(2) - (3)].a_module));
		asn1p_module_free((yyvsp[(3) - (3)].a_module));
	}
    break;

  case 29:
#line 600 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (1)].a_module);
	}
    break;

  case 30:
#line 603 "asn1p_y.y"
    {
		if((yyvsp[(1) - (2)].a_module)) {
			(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		} else {
			(yyval.a_module) = (yyvsp[(2) - (2)].a_module);
			break;
		}
        asn1p_module_move_members((yyval.a_module), (yyvsp[(2) - (2)].a_module));
		asn1p_module_free((yyvsp[(2) - (2)].a_module));
	}
    break;

  case 31:
#line 620 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 32:
#line 627 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 33:
#line 641 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[(1) - (1)].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[(1) - (1)].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 34:
#line 649 "asn1p_y.y"
    { asn1p_lexer_hack_push_encoding_control(); }
    break;

  case 35:
#line 650 "asn1p_y.y"
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
#line 662 "asn1p_y.y"
    {
		return yyerror(
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
    break;

  case 37:
#line 675 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 39:
#line 679 "asn1p_y.y"
    {
		if(!saved_aid && 0)
			return yyerror("Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[(2) - (3)].a_module);
	}
    break;

  case 40:
#line 689 "asn1p_y.y"
    {
		return yyerror("Empty IMPORTS list");
	}
    break;

  case 41:
#line 695 "asn1p_y.y"
    { (yyval.a_module) = asn1p_module_new(); }
    break;

  case 43:
#line 699 "asn1p_y.y"
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(1) - (1)].a_xports), xp_next);
	}
    break;

  case 44:
#line 704 "asn1p_y.y"
    {
		(yyval.a_module) = (yyvsp[(1) - (2)].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[(2) - (2)].a_xports), xp_next);
	}
    break;

  case 45:
#line 711 "asn1p_y.y"
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
    break;

  case 46:
#line 712 "asn1p_y.y"
    { (yyval.a_aid).oid = (yyvsp[(1) - (1)].a_oid); }
    break;

  case 47:
#line 716 "asn1p_y.y"
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
#line 727 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 49:
#line 732 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 50:
#line 739 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 51:
#line 745 "asn1p_y.y"
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 52:
#line 751 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
    break;

  case 53:
#line 761 "asn1p_y.y"
    { (yyval.a_module) = 0; }
    break;

  case 54:
#line 762 "asn1p_y.y"
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
#line 774 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(2) - (3)].a_xports);
	}
    break;

  case 56:
#line 777 "asn1p_y.y"
    {
		(yyval.a_xports) = 0;
	}
    break;

  case 57:
#line 780 "asn1p_y.y"
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
    break;

  case 58:
#line 788 "asn1p_y.y"
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[(1) - (1)].a_expr), next);
	}
    break;

  case 59:
#line 793 "asn1p_y.y"
    {
		(yyval.a_xports) = (yyvsp[(1) - (3)].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[(3) - (3)].a_expr), next);
	}
    break;

  case 60:
#line 800 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 61:
#line 806 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 62:
#line 812 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
    break;

  case 63:
#line 821 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 64:
#line 824 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(4) - (4)].a_constr);
	}
    break;

  case 65:
#line 844 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(1) - (1)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
    break;

  case 66:
#line 854 "asn1p_y.y"
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
#line 874 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
    break;

  case 68:
#line 880 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (3)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 69:
#line 896 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 70:
#line 902 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(6) - (6)].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (6)].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[(3) - (6)].a_plist);
	}
    break;

  case 71:
#line 910 "asn1p_y.y"
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

  case 72:
#line 919 "asn1p_y.y"
    {
		int ret;
		(yyval.a_plist) = (yyvsp[(1) - (3)].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[(3) - (3)].a_parg).governor, (yyvsp[(3) - (3)].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[(3) - (3)].a_parg).governor);
		free((yyvsp[(3) - (3)].a_parg).argument);
	}
    break;

  case 73:
#line 930 "asn1p_y.y"
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 74:
#line 934 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[(1) - (3)].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
		free((yyvsp[(1) - (3)].tv_str));
	}
    break;

  case 75:
#line 942 "asn1p_y.y"
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
#line 950 "asn1p_y.y"
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[(1) - (3)].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[(3) - (3)].tv_str);
	}
    break;

  case 77:
#line 958 "asn1p_y.y"
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
#line 969 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 79:
#line 974 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 81:
#line 982 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 82:
#line 990 "asn1p_y.y"
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
#line 998 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 84:
#line 1021 "asn1p_y.y"
    { (yyval.a_expr) = NEW_EXPR(); }
    break;

  case 85:
#line 1022 "asn1p_y.y"
    { (yyval.a_expr) = (yyvsp[(1) - (1)].a_expr); }
    break;

  case 86:
#line 1025 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 87:
#line 1030 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 88:
#line 1034 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (5)].a_expr);
		asn1p_expr_add_many((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
		asn1p_expr_free((yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 89:
#line 1042 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 90:
#line 1049 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 91:
#line 1055 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 92:
#line 1062 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 93:
#line 1068 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 94:
#line 1073 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 95:
#line 1080 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 96:
#line 1085 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 97:
#line 1088 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 98:
#line 1095 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 99:
#line 1105 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 100:
#line 1106 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 101:
#line 1110 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 102:
#line 1117 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 103:
#line 1127 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
	}
    break;

  case 104:
#line 1137 "asn1p_y.y"
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

  case 105:
#line 1148 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 106:
#line 1158 "asn1p_y.y"
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

  case 107:
#line 1169 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[(2) - (3)].a_ref);
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 108:
#line 1179 "asn1p_y.y"
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

  case 109:
#line 1190 "asn1p_y.y"
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

  case 110:
#line 1202 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 111:
#line 1203 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 112:
#line 1210 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 113:
#line 1212 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 114:
#line 1218 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 115:
#line 1222 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 116:
#line 1229 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 117:
#line 1233 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 118:
#line 1236 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 119:
#line 1240 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 120:
#line 1246 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 121:
#line 1254 "asn1p_y.y"
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

  case 122:
#line 1263 "asn1p_y.y"
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
#line 1277 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
        (yyval.a_expr)->tag = (yyvsp[(1) - (2)].a_tag);
    }
    break;

  case 125:
#line 1284 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[(2) - (2)].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[(2) - (2)].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[(2) - (2)].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[(2) - (2)].a_constr);
			}
		}
	}
    break;

  case 126:
#line 1307 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		/*
		 * Outer constraint for SEQUENCE OF and SET OF applies
		 * to the inner type.
		 */
		if((yyval.a_expr)->expr_type == ASN_CONSTR_SEQUENCE_OF
		|| (yyval.a_expr)->expr_type == ASN_CONSTR_SET_OF) {
			assert(!TQ_FIRST(&((yyval.a_expr)->members))->constraints);
			TQ_FIRST(&((yyval.a_expr)->members))->constraints = (yyvsp[(2) - (2)].a_constr);
		} else {
			if((yyval.a_expr)->constraints) {
				assert(!(yyvsp[(2) - (2)].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[(2) - (2)].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[(2) - (2)].a_constr);
			}
		}
	}
    break;

  case 127:
#line 1330 "asn1p_y.y"
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

  case 128:
#line 1354 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 129:
#line 1361 "asn1p_y.y"
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

  case 133:
#line 1385 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 134:
#line 1391 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 135:
#line 1397 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1403 "asn1p_y.y"
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

  case 137:
#line 1413 "asn1p_y.y"
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

  case 138:
#line 1423 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 139:
#line 1429 "asn1p_y.y"
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

  case 140:
#line 1441 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 141:
#line 1456 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 142:
#line 1464 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
		checkmem(ret == 0);
	}
    break;

  case 143:
#line 1472 "asn1p_y.y"
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

  case 144:
#line 1483 "asn1p_y.y"
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

  case 145:
#line 1494 "asn1p_y.y"
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

  case 146:
#line 1516 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].a_refcomp).name, (yyvsp[(1) - (1)].a_refcomp).lex_type);
		free((yyvsp[(1) - (1)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 147:
#line 1524 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 149:
#line 1537 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 150:
#line 1542 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 151:
#line 1551 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 152:
#line 1556 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 153:
#line 1561 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 154:
#line 1569 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 155:
#line 1592 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 158:
#line 1604 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 159:
#line 1604 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 160:
#line 1612 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 161:
#line 1617 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 162:
#line 1622 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 168:
#line 1635 "asn1p_y.y"
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

  case 169:
#line 1653 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 170:
#line 1657 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 171:
#line 1662 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 172:
#line 1670 "asn1p_y.y"
    {
		(yyval.tv_opaque).len = (yyvsp[(1) - (1)].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc(1 + (yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[(1) - (1)].tv_opaque).buf);
    }
    break;

  case 173:
#line 1679 "asn1p_y.y"
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

  case 175:
#line 1695 "asn1p_y.y"
    {
        (yyval.tv_opaque).len = strlen((yyvsp[(1) - (1)].tv_str));
        (yyval.tv_opaque).buf = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 176:
#line 1701 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 177:
#line 1702 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 178:
#line 1703 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 179:
#line 1704 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 180:
#line 1705 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 181:
#line 1706 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 182:
#line 1707 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 183:
#line 1708 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 184:
#line 1709 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 185:
#line 1710 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 186:
#line 1711 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 189:
#line 1720 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 190:
#line 1721 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 191:
#line 1722 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 192:
#line 1726 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 193:
#line 1732 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 194:
#line 1737 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 195:
#line 1742 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(4) - (5)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 196:
#line 1747 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 197:
#line 1752 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 198:
#line 1761 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 199:
#line 1762 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 200:
#line 1766 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 201:
#line 1770 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 202:
#line 1771 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 203:
#line 1772 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 204:
#line 1773 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 205:
#line 1774 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 206:
#line 1778 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 207:
#line 1779 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 208:
#line 1780 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 209:
#line 1781 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 210:
#line 1785 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 211:
#line 1786 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 216:
#line 1798 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 218:
#line 1803 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 220:
#line 1808 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 223:
#line 1814 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(2) - (3)].a_constr), 0);
    }
    break;

  case 225:
#line 1821 "asn1p_y.y"
    {
        if((yyvsp[(2) - (2)].a_constr)->type == ACT_CA_SET && (yyvsp[(2) - (2)].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr));
        }
	}
    break;

  case 229:
#line 1835 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 231:
#line 1840 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
   }
    break;

  case 232:
#line 1846 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
   }
    break;

  case 234:
#line 1858 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 236:
#line 1865 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 238:
#line 1872 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 240:
#line 1880 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 242:
#line 1887 "asn1p_y.y"
    {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        checkmem(ret == 0);
    }
    break;

  case 243:
#line 1898 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 244:
#line 1904 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 250:
#line 1920 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 251:
#line 1925 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 252:
#line 1930 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 253:
#line 1935 "asn1p_y.y"
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

  case 254:
#line 1947 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
    }
    break;

  case 256:
#line 1957 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
    break;

  case 258:
#line 1964 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
    break;

  case 260:
#line 1972 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 261:
#line 1977 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 262:
#line 1985 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
    }
    break;

  case 263:
#line 1991 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(1) - (1)].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 264:
#line 2003 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 265:
#line 2006 "asn1p_y.y"
    {
        assert((yyvsp[(3) - (3)].a_constr)->type == ACT_CA_CSV);
        (yyvsp[(3) - (3)].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[(3) - (3)].a_constr);
	}
    break;

  case 269:
#line 2014 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 270:
#line 2016 "asn1p_y.y"
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

  case 271:
#line 2029 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(1) - (1)].a_constr));
    }
    break;

  case 272:
#line 2034 "asn1p_y.y"
    {
        (yyval.a_constr) = (yyvsp[(1) - (3)].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 273:
#line 2040 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[(1) - (3)].a_value);
        if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        (yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
    }
    break;

  case 274:
#line 2054 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 275:
#line 2055 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 276:
#line 2059 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 277:
#line 2062 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 278:
#line 2065 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 282:
#line 2080 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 283:
#line 2080 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 284:
#line 2091 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 285:
#line 2100 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 286:
#line 2101 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 287:
#line 2102 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 288:
#line 2103 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 289:
#line 2106 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 290:
#line 2109 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 291:
#line 2118 "asn1p_y.y"
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

  case 292:
#line 2134 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 293:
#line 2140 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 294:
#line 2146 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 295:
#line 2160 "asn1p_y.y"
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

  case 296:
#line 2171 "asn1p_y.y"
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

  case 297:
#line 2187 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 298:
#line 2190 "asn1p_y.y"
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

  case 299:
#line 2210 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 300:
#line 2214 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 301:
#line 2218 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 302:
#line 2222 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 303:
#line 2229 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 304:
#line 2234 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
    }
    break;

  case 305:
#line 2240 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 306:
#line 2249 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 307:
#line 2254 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 308:
#line 2261 "asn1p_y.y"
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
#line 2269 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 310:
#line 2279 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 311:
#line 2284 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 312:
#line 2291 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[(3) - (4)].a_int));
	}
    break;

  case 313:
#line 2299 "asn1p_y.y"
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
#line 2309 "asn1p_y.y"
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

  case 315:
#line 2324 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 316:
#line 2329 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 317:
#line 2336 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 318:
#line 2343 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 319:
#line 2351 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 320:
#line 2359 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 321:
#line 2366 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 322:
#line 2377 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 323:
#line 2381 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 324:
#line 2388 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 325:
#line 2419 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 326:
#line 2420 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 327:
#line 2424 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 328:
#line 2431 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 329:
#line 2437 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 330:
#line 2438 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 331:
#line 2439 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 332:
#line 2440 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 333:
#line 2444 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 334:
#line 2445 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 335:
#line 2446 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 336:
#line 2450 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 337:
#line 2454 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 338:
#line 2462 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 339:
#line 2463 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 340:
#line 2469 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 341:
#line 2476 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		free((yyvsp[(1) - (1)].tv_str));
    }
    break;

  case 342:
#line 2483 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 4957 "asn1p_y.c"
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


#line 2487 "asn1p_y.y"



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

static int
yyerror(const char *msg) {
	extern char *asn1p_text;
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near %s:%d (token \"%s\"): %s\n",
		ASN_FILENAME, yylineno, asn1p_text, msg);
	return -1;
}


