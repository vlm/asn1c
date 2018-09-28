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
int ext_num = 1;

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
/* Line 187 of yacc.c.  */
#line 457 "asn1p_y.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 470 "asn1p_y.c"

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
#define YYLAST   936

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  343
/* YYNRULES -- Number of states.  */
#define YYNSTATES  525

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
     259,   262,   266,   268,   270,   274,   280,   283,   285,   287,
     293,   294,   296,   298,   302,   305,   310,   314,   318,   322,
     326,   330,   331,   333,   334,   341,   343,   346,   348,   350,
     352,   356,   358,   362,   366,   368,   371,   374,   377,   381,
     382,   385,   387,   389,   391,   396,   401,   406,   413,   420,
     422,   427,   431,   433,   435,   439,   443,   447,   449,   453,
     455,   457,   459,   461,   465,   469,   471,   476,   478,   480,
     481,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     505,   507,   509,   511,   513,   516,   518,   520,   522,   524,
     526,   529,   532,   534,   536,   539,   542,   544,   546,   548,
     550,   552,   554,   557,   559,   564,   569,   575,   580,   584,
     586,   588,   590,   592,   594,   596,   598,   600,   602,   604,
     606,   608,   610,   612,   614,   616,   618,   620,   621,   623,
     624,   626,   627,   629,   631,   635,   637,   640,   642,   644,
     646,   648,   650,   654,   660,   662,   666,   668,   672,   674,
     678,   680,   684,   686,   690,   692,   694,   696,   698,   700,
     702,   704,   707,   710,   713,   716,   720,   722,   724,   726,
     728,   730,   732,   734,   737,   739,   743,   747,   749,   751,
     753,   757,   763,   765,   769,   773,   774,   776,   778,   780,
     782,   784,   786,   788,   789,   795,   798,   800,   803,   806,
     810,   812,   814,   818,   823,   825,   829,   832,   836,   838,
     842,   843,   845,   847,   850,   852,   856,   858,   860,   864,
     869,   874,   876,   880,   885,   890,   892,   894,   898,   900,
     905,   910,   912,   914,   916,   918,   920,   921,   923,   926,
     931,   932,   934,   936,   938,   939,   941,   943,   945,   947,
     948,   950,   952,   954
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
     166,   118,   167,    -1,   166,   118,     4,   166,     5,    -1,
     270,   182,    -1,   177,    -1,   182,    -1,    36,   113,   170,
     114,   172,    -1,    -1,    96,    -1,   171,    -1,   170,   118,
     171,    -1,    19,   250,    -1,    20,   178,   169,   250,    -1,
      20,   191,   250,    -1,    20,   192,   250,    -1,    19,   191,
     250,    -1,    19,   178,   250,    -1,    19,   192,   250,    -1,
      -1,   173,    -1,    -1,   103,    90,   113,   174,   175,   114,
      -1,   176,    -1,   175,   176,    -1,     6,    -1,    21,    -1,
     190,    -1,   120,   175,   121,    -1,   111,    -1,   111,   122,
     197,    -1,   111,   122,   261,    -1,   179,    -1,   263,   181,
      -1,   157,   208,    -1,   185,   208,    -1,   263,   184,   208,
      -1,    -1,   183,   185,    -1,   186,    -1,   157,    -1,   203,
      -1,    35,   113,   166,   114,    -1,    86,   113,   163,   114,
      -1,    87,   113,   163,   114,    -1,    86,   209,    76,   269,
     263,   184,    -1,    87,   209,    76,   269,   263,   184,    -1,
      26,    -1,    26,    43,    33,   270,    -1,    64,    76,   187,
      -1,    17,    -1,    18,    -1,    17,   123,   268,    -1,    18,
     123,   268,    -1,    18,   123,   188,    -1,   189,    -1,   188,
     123,   189,    -1,   190,    -1,    19,    -1,    20,    -1,    19,
      -1,   191,   123,    19,    -1,   191,   123,    20,    -1,    18,
      -1,   270,   178,     3,   194,    -1,   196,    -1,   197,    -1,
      -1,   113,   195,   199,    -1,    71,    -1,    53,    -1,    94,
      -1,   261,    -1,   262,    -1,   198,    -1,   228,    -1,   272,
      -1,   268,   123,   270,    -1,     9,    -1,    15,    -1,    16,
      -1,   200,    -1,   199,     7,    -1,     7,    -1,   270,    -1,
      32,    -1,    71,    -1,    84,    -1,    75,    89,    -1,    73,
      59,    -1,    85,    -1,    52,    -1,    44,    79,    -1,    34,
      89,    -1,    99,    -1,    55,    -1,   204,    -1,   202,    -1,
      66,    -1,    48,    -1,    30,    89,    -1,   201,    -1,    66,
     113,   254,   114,    -1,    48,   113,   258,   114,    -1,    30,
      89,   113,   256,   114,    -1,    22,   113,   252,   114,    -1,
      22,   113,   114,    -1,    31,    -1,    56,    -1,    57,    -1,
      58,    -1,    67,    -1,    72,    -1,    82,    -1,    91,    -1,
      93,    -1,    98,    -1,   100,    -1,   101,    -1,   102,    -1,
      74,    -1,   108,    -1,   109,    -1,   106,    -1,   107,    -1,
      -1,   210,    -1,    -1,   211,    -1,    -1,   210,    -1,   222,
      -1,   115,   212,   116,    -1,   210,    -1,   211,   210,    -1,
     213,    -1,   239,    -1,   214,    -1,   111,    -1,   215,    -1,
     215,   118,   111,    -1,   215,   118,   111,   118,   215,    -1,
     216,    -1,    25,   105,   219,    -1,   217,    -1,   216,   205,
     217,    -1,   218,    -1,   217,   206,   218,    -1,   219,    -1,
     219,   105,   219,    -1,   220,    -1,   115,   215,   116,    -1,
     227,    -1,   229,    -1,   221,    -1,   222,    -1,   230,    -1,
     223,    -1,   224,    -1,    54,   210,    -1,    88,   210,    -1,
      78,     9,    -1,    78,   270,    -1,   225,   243,   226,    -1,
     227,    -1,    69,    -1,   227,    -1,    68,    -1,   194,    -1,
       8,    -1,    10,    -1,    63,   178,    -1,   180,    -1,   103,
      37,   231,    -1,   103,    38,   232,    -1,   210,    -1,   233,
      -1,   234,    -1,   113,   235,   114,    -1,   113,   111,   118,
     235,   114,    -1,   236,    -1,   235,   118,   236,    -1,   272,
     207,   237,    -1,    -1,   238,    -1,    81,    -1,    23,    -1,
      77,    -1,   240,    -1,   244,    -1,   242,    -1,    -1,    39,
      33,   113,   241,   199,    -1,    40,   178,    -1,   110,    -1,
     110,   124,    -1,   124,   110,    -1,   124,   110,   124,    -1,
     245,    -1,   246,    -1,   113,   268,   114,    -1,   245,   113,
     247,   114,    -1,   248,    -1,   247,   118,   248,    -1,   125,
     249,    -1,   125,   123,   249,    -1,   270,    -1,   249,   123,
     270,    -1,    -1,   251,    -1,    77,    -1,    41,   194,    -1,
     253,    -1,   252,   118,   253,    -1,   270,    -1,   255,    -1,
     254,   118,   255,    -1,   270,   115,   261,   116,    -1,   270,
     115,   197,   116,    -1,   257,    -1,   256,   118,   257,    -1,
     270,   115,    12,   116,    -1,   270,   115,   197,   116,    -1,
     259,    -1,   260,    -1,   259,   118,   260,    -1,   270,    -1,
     270,   115,   261,   116,    -1,   270,   115,   197,   116,    -1,
     261,    -1,   111,    -1,    12,    -1,    13,    -1,    14,    -1,
      -1,   264,    -1,   265,   267,    -1,   120,   266,    12,   121,
      -1,    -1,    97,    -1,    27,    -1,    83,    -1,    -1,    60,
      -1,    49,    -1,    17,    -1,    18,    -1,    -1,   270,    -1,
      11,    -1,   270,    -1,   271,    -1
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
     981,   982,   990,   998,  1021,  1022,  1025,  1030,  1034,  1044,
    1051,  1057,  1064,  1070,  1075,  1079,  1089,  1094,  1097,  1104,
    1114,  1115,  1119,  1126,  1136,  1146,  1157,  1167,  1178,  1188,
    1199,  1211,  1212,  1219,  1218,  1227,  1231,  1238,  1242,  1245,
    1249,  1255,  1263,  1272,  1283,  1286,  1293,  1316,  1339,  1363,
    1370,  1389,  1390,  1393,  1394,  1400,  1406,  1412,  1422,  1432,
    1438,  1450,  1465,  1473,  1481,  1492,  1503,  1525,  1533,  1542,
    1546,  1551,  1560,  1565,  1570,  1578,  1601,  1611,  1612,  1613,
    1613,  1621,  1626,  1631,  1636,  1637,  1638,  1639,  1643,  1644,
    1662,  1666,  1671,  1679,  1688,  1703,  1704,  1710,  1711,  1712,
    1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,
    1729,  1730,  1731,  1735,  1741,  1746,  1751,  1756,  1761,  1770,
    1771,  1775,  1779,  1780,  1781,  1782,  1783,  1787,  1788,  1789,
    1790,  1794,  1795,  1802,  1802,  1803,  1803,  1807,  1808,  1812,
    1813,  1817,  1818,  1819,  1823,  1829,  1830,  1839,  1839,  1841,
    1844,  1848,  1849,  1855,  1866,  1867,  1873,  1874,  1880,  1881,
    1888,  1889,  1895,  1896,  1907,  1913,  1919,  1920,  1922,  1923,
    1924,  1929,  1934,  1939,  1944,  1956,  1965,  1966,  1972,  1973,
    1978,  1981,  1986,  1994,  2000,  2012,  2015,  2021,  2022,  2022,
    2023,  2025,  2038,  2043,  2049,  2063,  2064,  2068,  2071,  2074,
    2082,  2083,  2084,  2089,  2088,  2100,  2109,  2110,  2111,  2112,
    2115,  2118,  2127,  2143,  2149,  2155,  2169,  2180,  2196,  2199,
    2219,  2223,  2227,  2231,  2238,  2243,  2249,  2258,  2263,  2270,
    2278,  2288,  2293,  2300,  2308,  2318,  2333,  2338,  2345,  2352,
    2360,  2368,  2375,  2386,  2390,  2397,  2428,  2429,  2433,  2440,
    2446,  2447,  2448,  2449,  2453,  2454,  2455,  2459,  2463,  2471,
    2472,  2478,  2485,  2492
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
     165,   165,   165,   166,   166,   166,   167,   167,   167,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   172,   172,   174,   173,   175,   175,   176,   176,   176,
     176,   177,   177,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   187,   187,   187,   187,   187,   188,   188,   189,
     190,   190,   191,   191,   191,   192,   193,   194,   194,   195,
     194,   196,   196,   196,   196,   196,   196,   196,   197,   197,
     198,   198,   198,   199,   199,   200,   200,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   202,   202,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   209,   209,   209,   210,   211,   211,   212,   212,   213,
     214,   214,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   220,   220,   220,   220,
     220,   221,   222,   223,   223,   224,   225,   225,   226,   226,
     227,   228,   228,   229,   229,   230,   230,   231,   232,   232,
     233,   234,   235,   235,   236,   237,   237,   238,   238,   238,
     239,   239,   239,   241,   240,   242,   243,   243,   243,   243,
     244,   244,   245,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   259,   259,   260,   260,
     260,   260,   260,   261,   261,   262,   263,   263,   264,   265,
     266,   266,   266,   266,   267,   267,   267,   268,   268,   269,
     269,   270,   271,   272
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
       2,     3,     1,     1,     3,     5,     2,     1,     1,     5,
       0,     1,     1,     3,     2,     4,     3,     3,     3,     3,
       3,     0,     1,     0,     6,     1,     2,     1,     1,     1,
       3,     1,     3,     3,     1,     2,     2,     2,     3,     0,
       2,     1,     1,     1,     4,     4,     4,     6,     6,     1,
       4,     3,     1,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     1,     4,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     4,     4,     5,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     3,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       3,     5,     1,     3,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     2,     1,     2,     2,     3,
       1,     1,     3,     4,     1,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     1,     3,     1,     1,     3,     4,
       4,     1,     3,     4,     4,     1,     1,     3,     1,     4,
       4,     1,     1,     1,     1,     1,     0,     1,     2,     4,
       0,     1,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   337,   338,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   341,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     199,     0,   200,   201,   202,   203,   204,   212,   205,   206,
     207,   208,   209,   210,   211,    28,    29,    33,    31,    32,
      36,   326,   326,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   326,     0,   330,     0,   124,     0,   327,   334,
       0,    45,    49,    51,    35,     0,    68,    67,     0,   177,
       0,     0,   191,   183,   187,   190,   178,     0,     0,   179,
     182,   186,     0,    71,     0,   189,   188,    73,   332,   333,
     331,     0,     0,   142,   143,     0,   139,     0,     0,   191,
       0,   190,   221,   221,   132,   125,   219,   131,    65,   193,
     133,   336,   335,   328,     0,    46,    47,     0,   192,   185,
     184,   181,   180,     0,     0,     0,     0,     0,     0,    64,
       0,     0,     0,     0,   192,   326,     0,     0,     0,     0,
     326,     0,     0,   222,   223,   326,     0,   127,   225,   220,
       0,   261,   170,   262,   323,   324,   325,   171,   172,   162,
     161,   163,   159,   156,   157,   158,   166,   167,   164,   165,
       0,   342,   343,   168,   326,   326,     0,   102,   326,    72,
      77,    76,    75,    74,   329,   142,   143,     0,     0,   326,
     257,     0,     0,   230,     0,   219,   264,   260,     0,   231,
     234,   236,   238,   240,   242,   246,   247,   249,   250,     0,
     244,   245,   248,   144,   150,   151,   146,   147,   149,   145,
     198,     0,   304,   306,     0,     0,   121,     0,    93,    97,
      98,   129,   326,   322,     0,   315,   316,   321,   318,   141,
       0,   307,     0,   252,     0,     0,    85,    86,    92,   300,
     326,     0,   326,   159,     0,   227,   229,   228,   280,   282,
     281,   290,   291,   339,     0,   339,   226,   161,    83,     0,
      78,    80,    81,    82,     0,     0,   155,   152,     0,   302,
     300,   300,   300,   104,   301,   100,   300,   300,   111,     0,
      70,    69,     0,   251,   263,   253,   254,     0,     0,     0,
     126,    63,     0,   213,   214,     0,   215,   216,     0,     0,
     286,     0,     0,     0,   197,     0,   140,     0,   311,     0,
       0,   134,   326,     0,   219,    96,   195,     0,     0,   194,
       0,     0,   326,   135,   326,    90,   300,     0,   285,     0,
     224,     0,   326,   340,   136,   326,    66,     0,   175,   160,
     173,   176,   169,   303,   109,     0,   108,   110,   101,   300,
     106,   107,     0,    99,   112,   103,   235,   267,   265,     0,
     266,   268,   269,   243,   232,   237,   239,   241,   287,   288,
     259,   255,   258,   148,   305,   196,     0,     0,   122,   123,
     326,    94,   130,   128,   317,     0,     0,   308,     0,     0,
      91,   326,    87,    89,   283,   292,     0,     0,   294,   129,
     129,    79,   174,   153,   154,   105,     0,     0,     0,   272,
     217,     0,   289,   312,     0,     0,     0,   320,   319,   310,
     309,     0,     0,     0,   296,   298,   293,     0,   137,   138,
     113,     0,   270,     0,   275,   218,   233,   313,   314,    95,
      88,   284,   297,     0,   295,     0,     0,   273,   278,   279,
     277,   274,   276,   299,   117,   118,     0,     0,   115,   119,
     271,     0,   114,   116,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   114,    56,    57,    63,
      64,   166,    65,    66,    67,    46,    47,    50,    51,   318,
      87,   245,    88,   132,   133,   319,   320,   295,   296,   297,
     277,   278,   116,   409,   226,   227,   413,   414,   505,   517,
     518,   298,   105,   106,   246,   321,   299,   373,   374,   156,
     157,   158,   266,   267,   519,   331,   332,    89,   247,   324,
     214,   215,   216,   399,   400,   159,   135,   160,   136,   355,
     358,   494,   197,   192,   198,   199,   304,   305,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     431,   260,   217,   261,   262,   418,   420,   421,   422,   468,
     469,   511,   512,   307,   308,   482,   309,   362,   310,   311,
     312,   457,   458,   484,   333,   334,   271,   272,   290,   291,
     367,   368,   284,   285,   286,   218,   219,   281,   108,   109,
     141,   163,   220,   392,   221,   222,   223
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -387
static const yytype_int16 yypact[] =
{
     104,  -387,  -387,   162,    38,   162,  -387,  -387,   162,  -387,
    -387,   -63,    53,    58,  -387,  -387,  -387,  -387,    70,  -387,
       0,   205,  -387,  -387,   111,    65,    59,    69,   107,   110,
     245,   205,  -387,   108,  -387,  -387,  -387,  -387,  -387,   231,
    -387,  -387,   185,   102,   208,  -387,   212,  -387,   160,  -387,
     189,  -387,   191,  -387,  -387,   196,   680,  -387,  -387,  -387,
     241,   188,  -387,   194,   241,  -387,   -14,  -387,   206,  -387,
    -387,   320,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,   680,  -387,  -387,  -387,  -387,
    -387,    19,   220,  -387,  -387,  -387,  -387,   162,   241,   228,
    -387,  -387,    -2,   834,   128,   340,  -387,   757,  -387,   -19,
     341,   -63,  -387,  -387,  -387,   232,  -387,  -387,   257,  -387,
     258,   271,  -387,  -387,  -387,  -387,  -387,   290,   263,  -387,
    -387,  -387,   -29,  -387,   235,  -387,  -387,   236,  -387,  -387,
    -387,   339,   243,   234,   238,   246,   319,   274,   253,   254,
     293,   261,   115,   138,  -387,  -387,   255,  -387,   264,  -387,
    -387,  -387,  -387,  -387,   547,  -387,  -387,   296,  -387,  -387,
    -387,  -387,  -387,   368,   834,   241,   241,   259,   379,  -387,
     162,   280,    12,   342,   265,    84,    90,   300,   365,   255,
      61,   270,   303,  -387,  -387,    61,   306,  -387,  -387,   255,
     621,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
     275,  -387,  -387,  -387,    51,    28,   -21,  -387,    -2,  -387,
    -387,  -387,  -387,  -387,  -387,   234,   238,   279,   255,   220,
    -387,   120,   284,  -387,   405,   255,  -387,  -387,   272,   281,
     217,   221,  -387,   295,  -387,  -387,  -387,  -387,  -387,   -26,
     112,  -387,  -387,  -387,  -387,  -387,   278,  -387,  -387,  -387,
    -387,    80,  -387,  -387,   365,   365,   283,   113,  -387,  -387,
    -387,  -387,   220,  -387,   288,   285,  -387,  -387,   291,  -387,
     143,  -387,   292,  -387,   332,   297,   294,  -387,  -387,    -9,
     220,   376,   220,   162,   309,  -387,  -387,  -387,  -387,  -387,
    -387,   313,  -387,   365,   315,   365,  -387,   316,  -387,   152,
    -387,  -387,  -387,  -387,   262,   365,  -387,  -387,   547,  -387,
      -9,    10,    -9,  -387,  -387,   314,    10,    -9,   324,   296,
    -387,  -387,   513,  -387,  -387,  -387,  -387,   255,   321,   322,
    -387,  -387,   325,  -387,  -387,   513,  -387,  -387,   513,   513,
     311,   327,   527,   310,  -387,   365,  -387,   157,  -387,   326,
     226,  -387,    25,   757,   255,  -387,  -387,    90,   226,  -387,
     365,   226,   220,  -387,    24,  -387,    -9,   330,  -387,   331,
    -387,   328,   220,  -387,  -387,   220,  -387,   621,  -387,   433,
    -387,  -387,  -387,  -387,  -387,   312,  -387,  -387,  -387,    -9,
    -387,  -387,   356,  -387,  -387,  -387,  -387,  -387,  -387,    14,
    -387,  -387,  -387,  -387,   329,   221,  -387,  -387,  -387,   336,
    -387,  -387,  -387,  -387,  -387,  -387,   365,   229,  -387,  -387,
      84,  -387,  -387,  -387,  -387,   333,   335,  -387,   338,   345,
    -387,    42,  -387,  -387,  -387,  -387,    26,   158,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,   343,   334,   175,  -387,
     255,   405,  -387,  -387,   346,   347,    16,  -387,  -387,  -387,
    -387,    22,   262,   365,   349,  -387,  -387,   328,  -387,  -387,
    -387,   365,  -387,   365,   135,  -387,  -387,  -387,  -387,  -387,
    -387,   433,   349,   365,  -387,    57,   176,  -387,  -387,  -387,
    -387,  -387,  -387,  -387,  -387,  -387,    57,    36,  -387,  -387,
    -387,    39,  -387,  -387,  -387
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -387,  -387,   452,   237,  -387,  -387,   353,  -387,   447,  -387,
    -387,   435,  -387,  -387,  -387,   384,  -387,  -387,  -387,  -387,
    -387,  -387,   411,  -387,   380,  -387,  -387,  -387,   417,   337,
    -387,  -106,  -387,  -387,   307,  -387,    83,   289,    34,   103,
      46,   116,   267,  -387,  -387,   150,  -387,  -387,  -387,   -18,
    -225,  -172,   -82,  -387,  -387,   389,  -176,  -387,  -125,   124,
    -387,   317,  -387,   137,  -164,   276,   277,  -387,  -140,  -387,
    -192,  -188,  -387,    21,  -387,   -20,  -387,  -387,     5,  -387,
    -387,  -387,  -227,   352,  -150,  -387,  -387,  -387,   318,  -237,
    -387,   151,   149,  -268,  -387,  -387,   184,  -387,  -387,  -387,
    -387,   148,  -387,  -387,  -387,  -387,  -387,  -387,  -387,    20,
      23,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,  -387,
    -387,  -387,    27,    29,  -220,  -387,  -387,   154,  -387,   133,
    -387,    79,  -387,  -387,   140,  -160,  -387,   -87,  -387,  -387,
    -387,  -387,    11,   218,   -12,  -387,  -386
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -301
static const yytype_int16 yytable[] =
{
      20,   154,   193,   193,   107,   107,    20,   349,   322,   280,
     110,     7,   323,   279,     7,   107,     7,   268,   350,     7,
     117,   499,   102,    15,   213,    15,   287,   500,   451,   440,
     161,    53,   328,   470,   115,    15,    15,    15,     9,   293,
      97,   162,   514,    69,    92,   514,   326,   327,    53,   316,
      12,   328,    69,    15,    52,   264,   265,   515,   264,   265,
     515,    90,   294,   514,    15,    16,    68,    91,   329,   326,
     327,    52,    15,    92,   416,    68,   264,   265,   515,   385,
     294,    15,    16,   134,   360,   173,    69,   329,   343,   174,
      90,   427,   328,   338,   154,    15,    91,   339,   361,   294,
      21,    15,   204,   205,    98,   470,   375,   470,   111,    68,
     404,   406,   407,    15,   137,    24,   410,   411,   104,     1,
       2,     1,     2,    33,   386,   467,   270,    48,   329,   345,
      34,    15,   103,   405,   372,   276,   276,   107,   107,   104,
     384,   107,   330,   335,   104,   104,   341,   443,   104,   483,
     522,    35,   107,   276,   134,   138,   516,   344,   508,   516,
     524,    36,   104,   231,   233,  -300,   453,    17,    37,  -300,
     273,   104,   276,   282,   288,   -84,   292,   516,   300,     1,
       2,   104,   438,   300,    22,   137,   230,   232,   403,   465,
     445,   263,   269,   448,   364,   276,   280,   417,   365,   268,
     279,   283,    38,   189,   104,   322,   450,    15,     3,   323,
     439,   139,   509,     1,     2,   107,   510,   287,   446,    49,
     388,   449,  -256,    25,    41,   140,   189,   371,   190,   346,
     191,   372,   -26,    26,   496,    43,  -256,    15,   204,   205,
      15,   474,    10,     1,     2,    10,     1,     2,    39,   475,
      62,   195,    15,   191,    27,    54,    28,   379,     1,     2,
      42,   380,   366,   369,   280,    29,   396,   154,   279,   398,
     397,   435,   486,    15,    55,   436,   487,    58,   201,   202,
     203,    15,   204,   205,   206,   207,   208,   235,   236,   492,
     520,   154,   523,   493,   493,   237,   523,     1,     2,   264,
     265,   393,    94,   393,    61,   459,    59,    60,   460,   301,
     302,    95,   401,   402,   389,   224,   225,   143,   144,    99,
     495,   347,   348,   209,   238,   353,   354,   356,   357,   264,
     265,   463,   464,   239,   488,   489,   194,   194,   100,   240,
     104,   210,   113,   142,   164,   167,   168,   169,   241,   171,
     170,   177,   172,   273,   175,   176,   178,   180,   189,   182,
     282,   181,   183,   184,   211,   288,   185,   186,   292,   187,
     191,   228,   300,   242,   188,   274,    15,   200,   275,   313,
     234,   243,   315,   303,   342,   244,   351,   201,   202,   203,
      15,   204,   205,   206,   207,   208,   235,   236,   325,   352,
     359,   363,   376,   377,   237,   370,   378,   381,   382,   387,
     408,   383,   384,   201,   202,   203,    15,   204,   205,   206,
     207,   208,   235,   236,   369,   390,   391,   412,   282,   394,
     237,  -178,   209,   238,   419,   428,   424,   429,   423,   300,
     462,   437,   239,   454,   485,   455,   466,   471,   240,   477,
     210,   478,   491,   456,   479,     8,   490,   241,   209,   238,
     472,   480,   497,   498,   165,    23,    40,   189,   239,   101,
     401,   485,   503,   211,   240,    96,   210,    93,   112,   179,
     461,   229,   242,   241,   314,   481,   476,   452,   441,   415,
     243,   513,   212,   189,   244,   340,   155,   442,   521,   211,
     433,   336,   337,   501,   289,   196,   425,   426,   242,   306,
     432,   506,   502,   447,   504,   473,   507,   444,   212,   434,
     244,   201,   202,   203,    15,   204,   205,   206,   207,   208,
     235,   236,     0,   395,     0,   201,   202,   203,    15,   204,
     205,   206,   207,   208,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   202,   203,    15,   204,
     205,   206,   207,   208,     1,     2,   209,   238,     0,     0,
       0,     0,     0,     0,     0,     0,   239,     0,     0,     0,
     209,     0,   240,     0,   210,     0,     0,     0,     0,     0,
       0,   241,     0,     0,     0,   430,     0,     0,   210,     0,
     209,   189,     0,     0,     0,     0,     0,   211,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,   210,     0,
       0,   211,     0,     0,     0,     0,   212,     0,   244,   201,
     202,   203,    15,   204,   205,   206,   207,   208,   235,   236,
     212,   211,     0,   145,     0,     0,     0,   146,     0,     0,
       0,   147,    70,   119,     0,   120,   148,     0,     0,     0,
     212,     0,     0,     0,     0,   121,     0,     0,     0,   149,
       0,     0,     0,   123,   209,     0,   124,    72,    73,    74,
       0,     0,     0,     0,     0,   150,     0,   151,    75,     0,
       0,    15,   317,    76,   127,    77,   128,     1,     2,     0,
       0,     0,     0,    78,     0,   129,   130,   152,   153,     0,
       0,    70,    79,     0,    80,   211,     0,     0,     0,    81,
     131,    82,    83,    84,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,   178,     0,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,    76,     0,    77,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    80,   143,   144,     0,     0,    81,   145,
      82,    83,    84,   146,     0,     0,     0,   147,    70,   119,
       0,   120,   148,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   149,     0,     0,     0,   123,
       0,     0,   124,    72,    73,    74,     0,     0,     0,     0,
       0,   150,     0,   151,    75,     0,     0,     0,   126,    76,
     127,    77,   128,     0,     0,     0,     0,     0,     0,    78,
       0,   129,   130,   152,   153,     0,     0,     0,    79,     0,
      80,     1,     2,     0,     0,    81,   131,    82,    83,    84,
       0,     0,     0,     0,   118,    70,   119,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,     0,     0,   123,     0,     0,   124,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     125,    75,     0,     0,     0,   126,    76,   127,    77,   128,
       0,     0,     0,     0,     0,     0,    78,     0,   129,   130,
       0,     0,     0,     0,     0,    79,     0,    80,     0,     0,
       0,     0,    81,   131,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   107,   152,   153,    91,    92,    18,   244,   200,   185,
      92,     0,   200,   185,     3,   102,     5,   181,   245,     8,
     102,     5,     3,    11,   164,    11,   186,     5,     4,     4,
      49,    43,    41,   419,    36,    11,    11,    11,     0,   189,
      54,    60,     6,    55,    56,     6,    18,    19,    60,   199,
     113,    41,    64,    11,    43,    19,    20,    21,    19,    20,
      21,    56,    38,     6,    11,    12,    55,    56,    77,    18,
      19,    60,    11,    85,   342,    64,    19,    20,    21,   299,
      38,    11,    12,   103,   110,   114,    98,    77,   238,   118,
      85,   359,    41,   114,   200,    11,    85,   118,   124,    38,
      42,    11,    12,    13,   118,   491,   282,   493,    97,    98,
     330,   331,   332,    11,   103,   115,   336,   337,   120,    17,
      18,    17,    18,    12,   300,   111,   114,    25,    77,     9,
      65,    11,   113,   123,   118,   111,   111,   224,   225,   120,
     118,   228,   224,   225,   120,   120,   228,   374,   120,   123,
     114,    92,   239,   111,   174,    27,   120,   239,    23,   120,
     121,    92,   120,   175,   176,   114,   386,   114,    61,   118,
     182,   120,   111,   185,   186,   114,   188,   120,   190,    17,
      18,   120,   370,   195,   114,   174,   175,   176,   328,   409,
     378,   180,   181,   381,   114,   111,   372,   347,   118,   363,
     372,   111,    92,    88,   120,   397,   382,    11,   104,   397,
     370,    83,    77,    17,    18,   302,    81,   377,   378,   117,
     302,   381,   110,    18,   116,    97,    88,   114,   113,   241,
     115,   118,    47,    28,   471,    50,   124,    11,    12,    13,
      11,    12,     5,    17,    18,     8,    17,    18,     3,   437,
      54,   113,    11,   115,    49,    47,    51,   114,    17,    18,
      29,   118,   274,   275,   440,    60,   114,   373,   440,     7,
     118,   114,   114,    11,    62,   118,   118,   117,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   114,
     114,   397,   517,   118,   118,    25,   521,    17,    18,    19,
      20,   313,   114,   315,   113,   392,   117,   118,   395,    39,
      40,   117,   324,   325,   303,    19,    20,    17,    18,   113,
     470,    37,    38,    53,    54,   108,   109,   106,   107,    19,
      20,    19,    20,    63,   459,   460,   152,   153,    18,    69,
     120,    71,   114,     3,     3,   113,    89,    89,    78,    59,
      79,    12,    89,   365,   119,   119,   113,   123,    88,   113,
     372,   123,    43,    89,    94,   377,   113,   113,   380,    76,
     115,     3,   384,   103,   113,    33,    11,   113,   113,    76,
     121,   111,    76,   113,   105,   115,   114,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   123,   118,
     105,   123,   114,   118,    25,   122,   115,   115,    76,    33,
      96,   114,   118,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   436,   116,   113,   103,   440,   114,
      25,   115,    53,    54,   113,   124,   111,   110,   116,   451,
       7,   115,    63,   113,   456,   114,    90,   118,    69,   116,
      71,   116,   118,   125,   116,     3,   113,    78,    53,    54,
     124,   116,   116,   116,   111,    18,    31,    88,    63,    85,
     482,   483,   123,    94,    69,    64,    71,    60,    98,   142,
     397,   174,   103,    78,   195,   451,   440,   384,   372,   339,
     111,   503,   113,    88,   115,   228,   107,   373,   516,    94,
     363,   225,   225,   482,   187,   153,   355,   358,   103,   191,
     362,   491,   483,   380,   487,   436,   493,   377,   113,   365,
     115,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,   315,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      53,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      53,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    71,    -1,
      -1,    94,    -1,    -1,    -1,    -1,   113,    -1,   115,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     113,    94,    -1,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    67,    -1,
      -1,    11,    71,    72,    73,    74,    75,    17,    18,    -1,
      -1,    -1,    -1,    82,    -1,    84,    85,    86,    87,    -1,
      -1,    31,    91,    -1,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    17,    18,    -1,    -1,    98,    22,
     100,   101,   102,    26,    -1,    -1,    -1,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
      93,    17,    18,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102
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
       4,   167,   185,   208,   260,   197,   261,   255,   197,   261,
     182,     4,   165,   250,   113,   114,   125,   247,   248,   263,
     263,   162,     7,    19,    20,   250,    90,   111,   235,   236,
     272,   118,   124,   257,    12,   197,   166,   116,   116,   116,
     116,   164,   241,   123,   249,   270,   114,   118,   184,   184,
     113,   118,   114,   118,   207,   210,   215,   116,   116,     5,
       5,   199,   249,   123,   248,   174,   235,   236,    23,    77,
      81,   237,   238,   270,     6,    21,   120,   175,   176,   190,
     114,   175,   114,   176,   121
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
		(yyvsp[(4) - (5)].a_expr)->meta_type = AMT_TYPE;
		(yyvsp[(4) - (5)].a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyvsp[(4) - (5)].a_expr)->marker.flags |= EM_OPTIONAL;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 89:
#line 1044 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (3)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (3)].tv_str);
		(yyvsp[(3) - (3)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(3) - (3)].a_marker);
	}
    break;

  case 90:
#line 1051 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (2)].a_expr);
		(yyvsp[(2) - (2)].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[(2) - (2)].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 91:
#line 1057 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[(3) - (3)].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 92:
#line 1064 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 93:
#line 1070 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 94:
#line 1075 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 95:
#line 1079 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (5)].a_expr);
		(yyvsp[(4) - (5)].a_expr)->meta_type = AMT_TYPE;
		(yyvsp[(4) - (5)].a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyvsp[(4) - (5)].a_expr)->marker.flags |= EM_OPTIONAL;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(4) - (5)].a_expr));
	}
    break;

  case 96:
#line 1089 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (2)].tv_str);
	}
    break;

  case 97:
#line 1094 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
	}
    break;

  case 98:
#line 1097 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (1)].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
    break;

  case 99:
#line 1104 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (5)].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[(5) - (5)].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
    break;

  case 100:
#line 1114 "asn1p_y.y"
    { (yyval.a_int) = 0; }
    break;

  case 101:
#line 1115 "asn1p_y.y"
    { (yyval.a_int) = 1; }
    break;

  case 102:
#line 1119 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 103:
#line 1126 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 104:
#line 1136 "asn1p_y.y"
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
#line 1146 "asn1p_y.y"
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
#line 1157 "asn1p_y.y"
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
#line 1167 "asn1p_y.y"
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
#line 1178 "asn1p_y.y"
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
#line 1188 "asn1p_y.y"
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
#line 1199 "asn1p_y.y"
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
#line 1211 "asn1p_y.y"
    { (yyval.a_wsynt) = 0; }
    break;

  case 112:
#line 1212 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (1)].a_wsynt);
	}
    break;

  case 113:
#line 1219 "asn1p_y.y"
    { asn1p_lexer_hack_enable_with_syntax(); }
    break;

  case 114:
#line 1221 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(5) - (6)].a_wsynt);
	}
    break;

  case 115:
#line 1227 "asn1p_y.y"
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(1) - (1)].a_wchunk), next);
	}
    break;

  case 116:
#line 1231 "asn1p_y.y"
    {
		(yyval.a_wsynt) = (yyvsp[(1) - (2)].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[(2) - (2)].a_wchunk), next);
	}
    break;

  case 117:
#line 1238 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
    break;

  case 118:
#line 1242 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].tv_str), 0);
	}
    break;

  case 119:
#line 1245 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[(1) - (1)].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
    break;

  case 120:
#line 1249 "asn1p_y.y"
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[(2) - (3)].a_wsynt));
	}
    break;

  case 121:
#line 1255 "asn1p_y.y"
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
#line 1263 "asn1p_y.y"
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
#line 1272 "asn1p_y.y"
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

  case 125:
#line 1286 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(2) - (2)].a_expr);
        (yyval.a_expr)->tag = (yyvsp[(1) - (2)].a_tag);
    }
    break;

  case 126:
#line 1293 "asn1p_y.y"
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
#line 1316 "asn1p_y.y"
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

  case 128:
#line 1339 "asn1p_y.y"
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

  case 129:
#line 1363 "asn1p_y.y"
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
    break;

  case 130:
#line 1370 "asn1p_y.y"
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

  case 134:
#line 1394 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 135:
#line 1400 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 136:
#line 1406 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 137:
#line 1412 "asn1p_y.y"
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

  case 138:
#line 1422 "asn1p_y.y"
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

  case 139:
#line 1432 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 140:
#line 1438 "asn1p_y.y"
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

  case 141:
#line 1450 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[(3) - (3)].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 142:
#line 1465 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 143:
#line 1473 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
		checkmem(ret == 0);
	}
    break;

  case 144:
#line 1481 "asn1p_y.y"
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
#line 1492 "asn1p_y.y"
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

  case 146:
#line 1503 "asn1p_y.y"
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

  case 147:
#line 1525 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].a_refcomp).name, (yyvsp[(1) - (1)].a_refcomp).lex_type);
		free((yyvsp[(1) - (1)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 148:
#line 1533 "asn1p_y.y"
    {
		int ret;
		(yyval.a_ref) = (yyvsp[(1) - (3)].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].a_refcomp).name, (yyvsp[(3) - (3)].a_refcomp).lex_type);
		free((yyvsp[(3) - (3)].a_refcomp).name);
		checkmem(ret == 0);
	}
    break;

  case 150:
#line 1546 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 151:
#line 1551 "asn1p_y.y"
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 152:
#line 1560 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 153:
#line 1565 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_AmpUppercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 154:
#line 1570 "asn1p_y.y"
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(3) - (3)].tv_str), RLT_Amplowercase);
		free((yyvsp[(3) - (3)].tv_str));
	}
    break;

  case 155:
#line 1578 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_CAPITALS);
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 156:
#line 1601 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(2) - (4)].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(4) - (4)].a_value);
	}
    break;

  case 159:
#line 1613 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 160:
#line 1613 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(3) - (3)].tv_opaque).buf, (yyvsp[(3) - (3)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
    break;

  case 161:
#line 1621 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
    break;

  case 162:
#line 1626 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
    break;

  case 163:
#line 1631 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
    break;

  case 169:
#line 1644 "asn1p_y.y"
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

  case 170:
#line 1662 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[(1) - (1)].tv_opaque).buf, (yyvsp[(1) - (1)].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
    break;

  case 171:
#line 1666 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
    break;

  case 172:
#line 1671 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
    break;

  case 173:
#line 1679 "asn1p_y.y"
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

  case 174:
#line 1688 "asn1p_y.y"
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

  case 176:
#line 1704 "asn1p_y.y"
    {
        (yyval.tv_opaque).len = strlen((yyvsp[(1) - (1)].tv_str));
        (yyval.tv_opaque).buf = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 177:
#line 1710 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
    break;

  case 178:
#line 1711 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_NULL; }
    break;

  case 179:
#line 1712 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_REAL; }
    break;

  case 180:
#line 1713 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
    break;

  case 181:
#line 1714 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
    break;

  case 182:
#line 1715 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
    break;

  case 183:
#line 1716 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EXTERNAL; }
    break;

  case 184:
#line 1717 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
    break;

  case 185:
#line 1718 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
    break;

  case 186:
#line 1719 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
    break;

  case 187:
#line 1720 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
    break;

  case 190:
#line 1729 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
    break;

  case 191:
#line 1730 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
    break;

  case 192:
#line 1731 "asn1p_y.y"
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
    break;

  case 193:
#line 1735 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[(1) - (1)].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
    break;

  case 194:
#line 1741 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 195:
#line 1746 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 196:
#line 1751 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(4) - (5)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 197:
#line 1756 "asn1p_y.y"
    {
        (yyval.a_expr) = (yyvsp[(3) - (4)].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 198:
#line 1761 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
    break;

  case 199:
#line 1770 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_BMPString; }
    break;

  case 200:
#line 1771 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
    break;

  case 201:
#line 1775 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
    break;

  case 202:
#line 1779 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_IA5String; }
    break;

  case 203:
#line 1780 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ISO646String; }
    break;

  case 204:
#line 1781 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_NumericString; }
    break;

  case 205:
#line 1782 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_PrintableString; }
    break;

  case 206:
#line 1783 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
    break;

  case 207:
#line 1787 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_TeletexString; }
    break;

  case 208:
#line 1788 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UniversalString; }
    break;

  case 209:
#line 1789 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_UTF8String; }
    break;

  case 210:
#line 1790 "asn1p_y.y"
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
    break;

  case 211:
#line 1794 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_VisibleString; }
    break;

  case 212:
#line 1795 "asn1p_y.y"
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
    break;

  case 217:
#line 1807 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 219:
#line 1812 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 221:
#line 1817 "asn1p_y.y"
    { (yyval.a_constr) = 0; }
    break;

  case 224:
#line 1823 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(2) - (3)].a_constr), 0);
    }
    break;

  case 226:
#line 1830 "asn1p_y.y"
    {
        if((yyvsp[(2) - (2)].a_constr)->type == ACT_CA_SET && (yyvsp[(2) - (2)].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[(1) - (2)].a_constr), (yyvsp[(2) - (2)].a_constr));
        }
	}
    break;

  case 230:
#line 1844 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
    break;

  case 232:
#line 1849 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
   }
    break;

  case 233:
#line 1855 "asn1p_y.y"
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (5)].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[(5) - (5)].a_constr));
   }
    break;

  case 235:
#line 1867 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 237:
#line 1874 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 239:
#line 1881 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 241:
#line 1889 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[(1) - (3)].a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 243:
#line 1896 "asn1p_y.y"
    {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        checkmem(ret == 0);
    }
    break;

  case 244:
#line 1907 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 245:
#line 1913 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 251:
#line 1929 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 252:
#line 1934 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[(2) - (2)].a_constr), 0);
	}
    break;

  case 253:
#line 1939 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(2) - (2)].tv_opaque).buf, (yyvsp[(2) - (2)].tv_opaque).len, 0);
	}
    break;

  case 254:
#line 1944 "asn1p_y.y"
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

  case 255:
#line 1956 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[(2) - (3)].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[(1) - (3)].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[(3) - (3)].a_value);
    }
    break;

  case 257:
#line 1966 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
    break;

  case 259:
#line 1973 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
    break;

  case 261:
#line 1981 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 262:
#line 1986 "asn1p_y.y"
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[(1) - (1)].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[(1) - (1)].tv_str));
	}
    break;

  case 263:
#line 1994 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
    }
    break;

  case 264:
#line 2000 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[(1) - (1)].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 265:
#line 2012 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[(3) - (3)].a_constr), 0);
	}
    break;

  case 266:
#line 2015 "asn1p_y.y"
    {
        assert((yyvsp[(3) - (3)].a_constr)->type == ACT_CA_CSV);
        (yyvsp[(3) - (3)].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[(3) - (3)].a_constr);
	}
    break;

  case 270:
#line 2023 "asn1p_y.y"
    { (yyval.a_constr) = (yyvsp[(2) - (3)].a_constr); }
    break;

  case 271:
#line 2025 "asn1p_y.y"
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

  case 272:
#line 2038 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(1) - (1)].a_constr));
    }
    break;

  case 273:
#line 2043 "asn1p_y.y"
    {
        (yyval.a_constr) = (yyvsp[(1) - (3)].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[(3) - (3)].a_constr));
	}
    break;

  case 274:
#line 2049 "asn1p_y.y"
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[(1) - (3)].a_value);
        if((yyvsp[(2) - (3)].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[(2) - (3)].a_constr));
        (yyval.a_constr)->presence = (yyvsp[(3) - (3)].a_pres);
    }
    break;

  case 275:
#line 2063 "asn1p_y.y"
    { (yyval.a_pres) = ACPRES_DEFAULT; }
    break;

  case 276:
#line 2064 "asn1p_y.y"
    { (yyval.a_pres) = (yyvsp[(1) - (1)].a_pres); }
    break;

  case 277:
#line 2068 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
    break;

  case 278:
#line 2071 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
    break;

  case 279:
#line 2074 "asn1p_y.y"
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
    break;

  case 283:
#line 2089 "asn1p_y.y"
    { asn1p_lexer_hack_push_opaque_state(); }
    break;

  case 284:
#line 2089 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[(5) - (5)].tv_opaque).buf, (yyvsp[(5) - (5)].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
    break;

  case 285:
#line 2100 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[(2) - (2)].a_expr));
		asn1p_expr_free((yyvsp[(2) - (2)].a_expr));
	}
    break;

  case 286:
#line 2109 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RANGE; }
    break;

  case 287:
#line 2110 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
    break;

  case 288:
#line 2111 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
    break;

  case 289:
#line 2112 "asn1p_y.y"
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
    break;

  case 290:
#line 2115 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 291:
#line 2118 "asn1p_y.y"
    {
		(yyval.a_constr) = (yyvsp[(1) - (1)].a_constr);
	}
    break;

  case 292:
#line 2127 "asn1p_y.y"
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

  case 293:
#line 2143 "asn1p_y.y"
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[(1) - (4)].a_constr), (yyvsp[(3) - (4)].a_constr));
	}
    break;

  case 294:
#line 2149 "asn1p_y.y"
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
	}
    break;

  case 295:
#line 2155 "asn1p_y.y"
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[(3) - (3)].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[(1) - (3)].a_constr), ct);
	}
    break;

  case 296:
#line 2169 "asn1p_y.y"
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

  case 297:
#line 2180 "asn1p_y.y"
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

  case 298:
#line 2196 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 299:
#line 2199 "asn1p_y.y"
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

  case 300:
#line 2219 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 301:
#line 2223 "asn1p_y.y"
    { (yyval.a_marker) = (yyvsp[(1) - (1)].a_marker); }
    break;

  case 302:
#line 2227 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
    break;

  case 303:
#line 2231 "asn1p_y.y"
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[(2) - (2)].a_value);
	}
    break;

  case 304:
#line 2238 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
    }
    break;

  case 305:
#line 2243 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
    }
    break;

  case 306:
#line 2249 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
    }
    break;

  case 307:
#line 2258 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 308:
#line 2263 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 309:
#line 2270 "asn1p_y.y"
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
#line 2278 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 311:
#line 2288 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 312:
#line 2293 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 313:
#line 2300 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[(3) - (4)].a_int));
	}
    break;

  case 314:
#line 2308 "asn1p_y.y"
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
#line 2318 "asn1p_y.y"
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

  case 316:
#line 2333 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[(1) - (1)].a_expr));
	}
    break;

  case 317:
#line 2338 "asn1p_y.y"
    {
		(yyval.a_expr) = (yyvsp[(1) - (3)].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[(3) - (3)].a_expr));
	}
    break;

  case 318:
#line 2345 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 319:
#line 2352 "asn1p_y.y"
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
#line 2360 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[(1) - (4)].tv_str);
		(yyval.a_expr)->value = (yyvsp[(3) - (4)].a_value);
	}
    break;

  case 321:
#line 2368 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[(1) - (1)].a_value);
	}
    break;

  case 322:
#line 2375 "asn1p_y.y"
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
    break;

  case 323:
#line 2386 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 324:
#line 2390 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[(1) - (1)].a_int));
		checkmem((yyval.a_value));
	}
    break;

  case 325:
#line 2397 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[(1) - (1)].a_dbl));
		checkmem((yyval.a_value));
	}
    break;

  case 326:
#line 2428 "asn1p_y.y"
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
    break;

  case 327:
#line 2429 "asn1p_y.y"
    { (yyval.a_tag) = (yyvsp[(1) - (1)].a_tag); }
    break;

  case 328:
#line 2433 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(1) - (2)].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[(2) - (2)].a_tag).tag_mode;
	}
    break;

  case 329:
#line 2440 "asn1p_y.y"
    {
		(yyval.a_tag) = (yyvsp[(2) - (4)].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[(3) - (4)].a_int);
	}
    break;

  case 330:
#line 2446 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
    break;

  case 331:
#line 2447 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
    break;

  case 332:
#line 2448 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
    break;

  case 333:
#line 2449 "asn1p_y.y"
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
    break;

  case 334:
#line 2453 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
    break;

  case 335:
#line 2454 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
    break;

  case 336:
#line 2455 "asn1p_y.y"
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
    break;

  case 337:
#line 2459 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 338:
#line 2463 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 339:
#line 2471 "asn1p_y.y"
    { (yyval.tv_str) = 0; }
    break;

  case 340:
#line 2472 "asn1p_y.y"
    {
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 341:
#line 2478 "asn1p_y.y"
    {
		checkmem((yyvsp[(1) - (1)].tv_str));
		(yyval.tv_str) = (yyvsp[(1) - (1)].tv_str);
	}
    break;

  case 342:
#line 2485 "asn1p_y.y"
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[(1) - (1)].tv_str), RLT_lowercase);
		free((yyvsp[(1) - (1)].tv_str));
    }
    break;

  case 343:
#line 2492 "asn1p_y.y"
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[(1) - (1)].a_ref), 0);
    }
    break;


/* Line 1267 of yacc.c.  */
#line 4967 "asn1p_y.c"
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


#line 2496 "asn1p_y.y"



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


