/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         asn1p_parse
#define yylex           asn1p_lex
#define yyerror         asn1p_error
#define yydebug         asn1p_debug
#define yynerrs         asn1p_nerrs

#define yylval          asn1p_lval
#define yychar          asn1p_char

/* Copy the first part of user declarations.  */
#line 3 "asn1p_y.y" /* yacc.c:339  */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

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
int yyerror(void **param, const char *msg);
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
		return yyerror(param, "Memory failure");		\
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


#line 179 "asn1p_y.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_ASN1P_ASN_P_Y_H_INCLUDED
# define YY_ASN1P_ASN_P_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int asn1p_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 114 "asn1p_y.y" /* yacc.c:355  */

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

#line 470 "asn1p_y.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE asn1p_lval;

int asn1p_parse (void **param);

#endif /* !YY_ASN1P_ASN_P_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 487 "asn1p_y.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   955

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  341
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  521

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       2,   119,     2,   120,   105,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,   107,   113,     2,     2,     2,     2,
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
     106,   108,   109,   110,   111
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   413,   413,   416,   422,   427,   444,   444,   473,   474,
     478,   481,   487,   493,   502,   506,   510,   520,   521,   530,
     533,   542,   545,   548,   551,   555,   576,   577,   586,   599,
     602,   619,   626,   640,   648,   647,   661,   674,   675,   678,
     688,   694,   695,   698,   703,   710,   711,   715,   726,   731,
     738,   744,   750,   760,   761,   773,   776,   779,   787,   792,
     799,   805,   811,   820,   823,   843,   853,   873,   879,   895,
     901,   909,   918,   929,   933,   941,   949,   957,   968,   973,
     980,   981,   989,   997,  1020,  1021,  1024,  1029,  1033,  1043,
    1050,  1056,  1063,  1069,  1074,  1081,  1086,  1089,  1096,  1106,
    1107,  1111,  1118,  1128,  1138,  1149,  1159,  1170,  1180,  1191,
    1203,  1204,  1211,  1210,  1219,  1223,  1230,  1234,  1237,  1241,
    1247,  1255,  1264,  1275,  1278,  1285,  1308,  1331,  1355,  1362,
    1381,  1382,  1385,  1386,  1392,  1398,  1404,  1414,  1424,  1430,
    1442,  1457,  1465,  1473,  1484,  1495,  1517,  1525,  1534,  1538,
    1543,  1552,  1557,  1562,  1570,  1593,  1603,  1604,  1605,  1605,
    1613,  1618,  1623,  1628,  1629,  1630,  1631,  1635,  1636,  1654,
    1658,  1663,  1671,  1680,  1695,  1696,  1702,  1703,  1704,  1705,
    1706,  1707,  1709,  1710,  1711,  1712,  1713,  1714,  1721,  1722,
    1723,  1727,  1733,  1738,  1743,  1748,  1753,  1762,  1763,  1767,
    1771,  1772,  1773,  1774,  1775,  1779,  1780,  1781,  1782,  1786,
    1787,  1794,  1794,  1795,  1795,  1799,  1800,  1804,  1805,  1809,
    1810,  1811,  1815,  1821,  1822,  1831,  1831,  1833,  1836,  1840,
    1841,  1847,  1858,  1859,  1865,  1866,  1872,  1873,  1880,  1881,
    1887,  1888,  1899,  1905,  1911,  1912,  1914,  1915,  1916,  1921,
    1926,  1931,  1936,  1948,  1957,  1958,  1964,  1965,  1970,  1973,
    1978,  1986,  1992,  2004,  2007,  2013,  2014,  2014,  2015,  2017,
    2030,  2035,  2041,  2055,  2056,  2060,  2063,  2066,  2074,  2075,
    2076,  2081,  2080,  2092,  2101,  2102,  2103,  2104,  2107,  2110,
    2119,  2135,  2141,  2147,  2161,  2172,  2188,  2191,  2211,  2215,
    2219,  2223,  2230,  2235,  2241,  2250,  2255,  2262,  2270,  2280,
    2285,  2292,  2300,  2310,  2325,  2330,  2337,  2344,  2352,  2360,
    2367,  2378,  2382,  2389,  2420,  2421,  2425,  2432,  2438,  2439,
    2440,  2441,  2445,  2446,  2447,  2451,  2455,  2463,  2464,  2470,
    2477,  2484
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "TOK_FALSE", "TOK_FROM", "TOK_GeneralizedTime", "TOK_GeneralString",
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
  "'|'", "TOK_UNION", "\"..\"", "\"...\"", "\"concrete TypeDeclaration\"",
  "'{'", "'}'", "'('", "')'", "';'", "','", "':'", "'['", "']'", "'!'",
  "'.'", "'<'", "'@'", "$accept", "ParsedGrammar", "ModuleList",
  "ModuleDefinition", "$@1", "optObjectIdentifier", "ObjectIdentifier",
  "ObjectIdentifierBody", "ObjectIdentifierElement",
  "optModuleDefinitionFlags", "ModuleDefinitionFlags",
  "ModuleDefinitionFlag", "optModuleBody", "ModuleBody", "AssignmentList",
  "Assignment", "$@2", "optImports", "ImportsDefinition",
  "optImportsBundleSet", "ImportsBundleSet", "AssignedIdentifier",
  "ImportsBundle", "ImportsList", "ImportsElement", "optExports",
  "ExportsDefinition", "ExportsBody", "ExportsElement", "ValueSet",
  "ValueSetTypeAssignment", "DefinedType", "DataTypeReference",
  "ParameterArgumentList", "ParameterArgumentName", "ActualParameterList",
  "ActualParameter", "optComponentTypeLists", "ComponentTypeLists",
  "ComponentType", "AlternativeTypeLists", "AlternativeType",
  "ObjectClass", "optUNIQUE", "FieldSpec", "ClassField", "optWithSyntax",
  "WithSyntax", "$@3", "WithSyntaxList", "WithSyntaxToken",
  "ExtensionAndException", "Type", "TaggedType", "DefinedUntaggedType",
  "UntaggedType", "MaybeIndirectTaggedType", "NSTD_IndirectMarker",
  "MaybeIndirectTypeDeclaration", "TypeDeclaration",
  "ConcreteTypeDeclaration", "ComplexTypeReference",
  "ComplexTypeReferenceAmpList", "ComplexTypeReferenceElement",
  "PrimitiveFieldReference", "FieldName", "DefinedObjectClass",
  "ValueAssignment", "Value", "$@4", "SimpleValue", "DefinedValue",
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
  "PresenceConstraint", "GeneralConstraint", "UserDefinedConstraint",
  "$@5", "ContentsConstraint", "ConstraintRangeSpec", "TableConstraint",
  "SimpleTableConstraint", "ComponentRelationConstraint", "AtNotationList",
  "AtNotationElement", "ComponentIdList", "optMarker", "Marker",
  "IdentifierList", "IdentifierElement", "NamedNumberList", "NamedNumber",
  "NamedBitList", "NamedBit", "Enumerations", "UniverationList",
  "UniverationElement", "SignedNumber", "RealValue", "optTag", "Tag",
  "TagTypeValue", "TagClass", "TagPlicit", "TypeRefName", "optIdentifier",
  "Identifier", "IdentifierAsReference", "IdentifierAsValue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     363,   364,   123,   125,    40,    41,    59,    44,    58,    91,
      93,    33,    46,    60,    64
};
# endif

#define YYPACT_NINF -389

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-389)))

#define YYTABLE_NINF -299

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,  -389,  -389,   149,    74,   149,  -389,  -389,   149,  -389,
    -389,   -83,    35,    43,  -389,  -389,  -389,  -389,    70,  -389,
      60,   259,  -389,  -389,   115,    80,   120,   122,   142,   134,
     245,   259,  -389,   143,  -389,  -389,  -389,  -389,  -389,   246,
    -389,  -389,    82,    52,   236,  -389,   225,  -389,   180,  -389,
     118,  -389,   186,  -389,  -389,    72,   693,  -389,  -389,  -389,
     206,   188,  -389,   187,   206,  -389,   -19,  -389,   193,  -389,
    -389,   291,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,   693,  -389,  -389,  -389,  -389,
    -389,    19,   198,  -389,  -389,  -389,  -389,   149,   206,   227,
    -389,  -389,     1,   854,     5,   335,  -389,   778,  -389,   111,
     339,   -83,  -389,  -389,  -389,   232,  -389,  -389,   257,  -389,
     258,   269,  -389,  -389,  -389,  -389,   290,   262,  -389,  -389,
    -389,    44,  -389,   231,  -389,  -389,   233,  -389,  -389,  -389,
     341,   242,   234,   235,   243,   315,   272,   249,   250,   288,
     254,    67,   117,  -389,  -389,   251,  -389,   256,  -389,  -389,
    -389,  -389,  -389,   705,  -389,  -389,   295,  -389,  -389,  -389,
    -389,  -389,   366,   854,   206,   206,   263,   364,  -389,   149,
     275,    15,   337,   273,    14,   100,   303,   373,   251,   108,
     229,   311,  -389,  -389,   108,   312,  -389,  -389,   251,   600,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,   266,
    -389,  -389,  -389,   146,    73,    76,  -389,     1,  -389,  -389,
    -389,  -389,  -389,  -389,   234,   235,   287,   251,   198,  -389,
      29,   286,  -389,   386,   251,  -389,  -389,   277,   276,   218,
     222,  -389,   301,  -389,  -389,  -389,  -389,  -389,   -73,    -5,
    -389,  -389,  -389,  -389,  -389,   270,  -389,  -389,  -389,  -389,
     103,  -389,  -389,   373,   373,   285,   113,  -389,  -389,  -389,
    -389,   198,  -389,   294,   292,  -389,  -389,   296,  -389,   119,
    -389,   298,  -389,   333,   300,   297,  -389,  -389,     0,   198,
     382,   198,   149,   304,  -389,  -389,  -389,  -389,  -389,  -389,
     306,  -389,   373,   307,   373,  -389,   308,  -389,   136,  -389,
    -389,  -389,  -389,   253,   373,  -389,  -389,   705,  -389,     0,
      31,     0,  -389,  -389,   326,    31,     0,   322,   295,  -389,
    -389,   493,  -389,  -389,  -389,  -389,   251,   316,   314,  -389,
    -389,   317,  -389,  -389,   493,  -389,  -389,   493,   493,   302,
     321,   507,   310,  -389,   373,  -389,   154,  -389,   319,   239,
    -389,    14,   778,   251,  -389,  -389,   100,   239,  -389,   373,
     239,   198,  -389,    24,  -389,     0,   323,  -389,   318,  -389,
     320,   198,  -389,  -389,   198,  -389,   600,  -389,   429,  -389,
    -389,  -389,  -389,  -389,   313,  -389,  -389,  -389,     0,  -389,
    -389,   351,  -389,  -389,  -389,  -389,  -389,  -389,    40,  -389,
    -389,  -389,  -389,   328,   222,  -389,  -389,  -389,   324,  -389,
    -389,  -389,  -389,  -389,  -389,   373,   261,  -389,  -389,  -389,
    -389,  -389,  -389,   331,   334,  -389,   338,   340,  -389,    88,
    -389,  -389,  -389,  -389,    13,   157,  -389,  -389,  -389,  -389,
    -389,  -389,  -389,  -389,   346,   342,   163,  -389,   251,   386,
    -389,  -389,   345,   347,  -389,  -389,  -389,  -389,    22,   253,
     373,   330,  -389,  -389,   320,  -389,  -389,  -389,   373,  -389,
     373,    30,  -389,  -389,  -389,  -389,  -389,   429,   330,   373,
    -389,    59,   171,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,    59,    36,  -389,  -389,  -389,    39,  -389,  -389,
    -389
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   335,   336,     0,     0,     3,     4,     6,     2,     1,
       5,     8,     0,     0,     9,   339,    16,    11,     0,    12,
      14,    17,    10,    13,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,    25,    23,    21,    24,    22,     0,
      20,    15,    53,     0,     0,    27,    37,    54,     0,    57,
       0,    58,    60,    62,     7,    41,     0,    38,    56,    55,
       0,     0,    40,     0,    42,    43,     0,    48,    50,    52,
     197,     0,   198,   199,   200,   201,   202,   210,   203,   204,
     205,   206,   207,   208,   209,    28,    29,    33,    31,    32,
      36,   324,   324,    59,    61,    39,    44,     0,     0,     0,
      34,    30,   324,     0,   328,     0,   123,     0,   325,   332,
       0,    45,    49,    51,    35,     0,    68,    67,     0,   176,
       0,     0,   189,   185,   188,   177,     0,     0,   178,   181,
     184,     0,    71,     0,   187,   186,    73,   330,   331,   329,
       0,     0,   141,   142,     0,   138,     0,     0,   189,     0,
     188,   219,   219,   131,   124,   217,   130,    65,   191,   132,
     334,   333,   326,     0,    46,    47,     0,   190,   183,   182,
     180,   179,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,   190,   324,     0,     0,     0,     0,   324,
       0,     0,   220,   221,   324,     0,   126,   223,   218,     0,
     259,   169,   260,   321,   322,   323,   170,   171,   161,   160,
     162,   158,   155,   156,   157,   165,   166,   163,   164,     0,
     340,   341,   167,   324,   324,     0,   101,   324,    72,    77,
      76,    75,    74,   327,   141,   142,     0,     0,   324,   255,
       0,     0,   228,     0,   217,   262,   258,     0,   229,   232,
     234,   236,   238,   240,   244,   245,   247,   248,     0,   242,
     243,   246,   143,   149,   150,   145,   146,   148,   144,   196,
       0,   302,   304,     0,     0,   120,     0,    93,    96,    97,
     128,   324,   320,     0,   313,   314,   319,   316,   140,     0,
     305,     0,   250,     0,     0,    85,    86,    92,   298,   324,
       0,   324,   158,     0,   225,   227,   226,   278,   280,   279,
     288,   289,   337,     0,   337,   224,   160,    83,     0,    78,
      80,    81,    82,     0,     0,   154,   151,     0,   300,   298,
     298,   298,   103,   299,    99,   298,   298,   110,     0,    70,
      69,     0,   249,   261,   251,   252,     0,     0,     0,   125,
      63,     0,   211,   212,     0,   213,   214,     0,     0,   284,
       0,     0,     0,   195,     0,   139,     0,   309,     0,     0,
     133,   324,     0,   217,    95,   193,     0,     0,   192,     0,
       0,   324,   134,   324,    90,   298,     0,   283,     0,   222,
       0,   324,   338,   135,   324,    66,     0,   174,   159,   172,
     175,   168,   301,   108,     0,   107,   109,   100,   298,   105,
     106,     0,    98,   111,   102,   233,   265,   263,     0,   264,
     266,   267,   241,   230,   235,   237,   239,   285,   286,   257,
     253,   256,   147,   303,   194,     0,     0,   121,   122,    94,
     129,   127,   315,     0,     0,   306,     0,     0,    91,   324,
      87,    89,   281,   290,     0,     0,   292,   128,   128,    79,
     173,   152,   153,   104,     0,     0,     0,   270,   215,     0,
     287,   310,     0,     0,   318,   317,   308,   307,     0,     0,
       0,   294,   296,   291,     0,   136,   137,   112,     0,   268,
       0,   273,   216,   231,   311,   312,    88,   282,   295,     0,
     293,     0,     0,   271,   276,   277,   275,   272,   274,   297,
     116,   117,     0,     0,   114,   118,   269,     0,   113,   115,
     119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -389,  -389,   440,    56,  -389,  -389,   350,  -389,   432,  -389,
    -389,   433,  -389,  -389,  -389,   380,  -389,  -389,  -389,  -389,
    -389,  -389,   405,  -389,   372,  -389,  -389,  -389,   411,   336,
    -389,  -106,  -389,  -389,   299,  -389,    79,   289,    32,    97,
    -389,   114,   255,  -389,  -389,   148,  -389,  -389,  -389,   -28,
    -228,  -171,   -82,  -389,  -389,   383,  -176,  -389,  -123,   121,
    -389,   305,  -389,   127,  -159,   268,   271,  -389,  -151,  -389,
    -190,  -181,  -389,    17,  -389,   -70,  -389,  -389,    12,  -389,
    -389,  -389,  -221,   360,  -149,  -389,  -389,  -389,   309,  -236,
    -389,   140,   156,  -211,  -389,  -389,   185,  -389,  -389,  -389,
    -389,   153,  -389,  -389,  -389,  -389,  -389,  -389,  -389,     9,
      37,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,  -389,
    -389,  -389,    42,    48,  -214,  -389,  -389,   165,  -389,   151,
    -389,    96,  -389,  -389,   158,  -168,  -389,   -87,  -389,  -389,
    -389,  -389,    11,   219,   -12,  -389,  -388
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    13,    14,    18,    19,    30,
      31,    32,    44,    45,    85,    86,   114,    56,    57,    63,
      64,   165,    65,    66,    67,    46,    47,    50,    51,   317,
      87,   244,    88,   131,   132,   318,   319,   294,   295,   296,
     276,   277,   116,   408,   225,   226,   412,   413,   501,   513,
     514,   297,   105,   106,   245,   320,   298,   372,   373,   155,
     156,   157,   265,   266,   515,   330,   331,    89,   246,   323,
     213,   214,   215,   398,   399,   158,   134,   159,   135,   354,
     357,   491,   196,   191,   197,   198,   303,   304,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     430,   259,   216,   260,   261,   417,   419,   420,   421,   466,
     467,   507,   508,   306,   307,   479,   308,   361,   309,   310,
     311,   455,   456,   481,   332,   333,   270,   271,   289,   290,
     366,   367,   283,   284,   285,   217,   218,   280,   108,   109,
     140,   162,   219,   391,   220,   221,   222
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,   153,   192,   192,   107,   107,    20,   348,   279,   321,
     110,     7,   212,   278,     7,   107,     7,   286,   322,     7,
     117,   267,   102,   349,    15,    15,    15,   496,   449,    12,
     468,    53,   137,   133,    97,    15,   359,   115,   344,   292,
      15,   327,   510,    69,    92,   510,    15,    16,    53,   315,
     360,    15,    69,   504,    52,   263,   264,   511,   263,   264,
     511,    10,   293,    15,    10,   510,    68,    91,    90,     1,
       2,    52,   327,    92,     9,    68,   328,    48,   263,   264,
     511,    15,    16,    15,   384,    21,    69,   138,   342,     1,
       2,   325,   326,   153,     1,     2,    91,    90,    98,    15,
     468,   139,   468,   133,  -254,   374,   505,   328,   111,    68,
     506,    15,   203,   204,   136,   403,   405,   406,  -254,    15,
     104,   409,   410,   385,   275,    62,   293,    33,   269,   -26,
     415,   103,    43,   104,   275,   480,   107,   107,   104,   383,
     107,   329,   334,   104,    34,   340,   293,   426,    17,   518,
     465,   107,   441,   404,   188,   512,   343,   172,   512,   520,
     160,   173,   230,   232,   325,   326,     1,     2,    49,   272,
     161,   451,   281,   287,    24,   291,   402,   299,   512,   189,
       3,   190,   299,    22,   136,   229,   231,   327,   437,   337,
     262,   268,   104,   338,   463,   279,   443,   416,   275,   446,
     278,   438,    37,   267,   188,   448,   321,   104,   286,   444,
     282,    35,   447,    36,   107,   322,   363,    15,   275,   387,
     364,   -84,   328,     1,     2,    38,   370,   104,   345,   194,
     371,   190,   378,   493,    59,    60,   379,   200,   201,   202,
      15,   203,   204,   205,   206,   207,   234,   235,    39,   395,
      15,   203,   204,   396,   236,   473,     1,     2,    41,  -298,
     397,   365,   368,  -298,    15,   104,   153,   434,   300,   301,
     483,   435,    15,   472,   484,    42,   489,    25,     1,     2,
     490,   208,   237,    54,   516,   519,    55,    26,   490,   519,
     153,   238,     1,     2,   263,   264,    58,   239,    61,   209,
     392,    94,   392,    95,   457,    99,   240,   458,    27,   100,
      28,   400,   401,   388,   223,   224,   188,   104,    29,   492,
     142,   143,   210,   346,   347,   352,   353,   355,   356,   263,
     264,   241,   461,   462,   485,   486,   193,   193,   141,   242,
     113,   302,   163,   243,   166,   167,   168,   169,   170,   174,
     171,   175,   272,   176,   177,   181,   179,   180,   182,   281,
     183,   184,   185,   186,   287,   190,   187,   291,   199,   227,
     273,   299,   200,   201,   202,    15,   203,   204,   205,   206,
     207,   234,   235,   233,    15,   274,   312,   314,   324,   236,
     350,   341,   362,   351,   200,   201,   202,    15,   203,   204,
     205,   206,   207,   234,   235,   358,   369,   375,   381,   376,
     377,   236,   380,   382,   383,   386,   208,   237,   390,   389,
     393,   407,  -177,   368,   411,   427,   238,   423,   418,   422,
     428,   453,   239,   436,   209,   452,   460,   299,   208,   237,
     464,   240,   482,     8,   454,   469,   474,   470,   238,   475,
      23,   188,   499,   476,   239,   477,   209,   210,   487,   488,
     494,   164,   495,   240,    40,   101,   241,   400,   482,    96,
     112,    93,   228,   188,   242,   459,   211,   178,   243,   210,
     450,   478,   339,   313,   517,   439,   414,   509,   241,   432,
     154,   288,   335,   440,   424,   336,   497,   502,   211,   305,
     243,   200,   201,   202,    15,   203,   204,   205,   206,   207,
     234,   235,   195,   425,   431,   200,   201,   202,    15,   203,
     204,   205,   206,   207,     1,     2,   500,   503,   498,   433,
     445,   471,     0,   394,   442,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   237,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,   208,
       0,   239,     0,   209,     0,     0,     0,     0,     0,     0,
     240,     0,     0,     0,   429,     0,     0,   209,     0,     0,
     188,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,     0,
     210,     0,     0,     0,     0,   211,     0,   243,   200,   201,
     202,    15,   203,   204,   205,   206,   207,   234,   235,   211,
       0,     0,   144,     0,     0,     0,   145,     0,     0,     0,
     146,    70,   119,     0,   120,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   148,     0,
       0,     0,   208,     0,   123,    72,    73,    74,     0,     0,
       0,     0,     0,   149,     0,   150,    75,     0,     0,     0,
     316,    76,   126,    77,   127,     0,     0,     0,     0,     0,
       0,    78,     0,   128,   129,   151,   152,     0,     0,     0,
      79,     0,    80,   210,     0,     0,     0,    81,   130,    82,
      83,    84,     0,     0,    15,     0,     0,     0,     0,     0,
       1,     2,   177,   200,   201,   202,    15,   203,   204,   205,
     206,   207,     1,     2,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,     0,     0,     0,     0,     0,     0,   208,     0,    75,
       0,     0,     0,     0,    76,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    78,   209,     0,     0,     0,     0,
       0,     0,     0,    79,     0,    80,     0,     0,     0,     0,
      81,     0,    82,    83,    84,   142,   143,     0,   210,     0,
     144,     0,     0,     0,   145,     0,     0,     0,   146,    70,
     119,     0,   120,   147,     0,     0,     0,   211,     0,     0,
       0,     0,   121,     0,     0,     0,   148,     0,     0,     0,
       0,     0,   123,    72,    73,    74,     0,     0,     0,     0,
       0,   149,     0,   150,    75,     0,     0,     0,   125,    76,
     126,    77,   127,     0,     0,     0,     0,     0,     0,    78,
       0,   128,   129,   151,   152,     0,     0,     0,    79,     0,
      80,     1,     2,     0,     0,    81,   130,    82,    83,    84,
       0,     0,     0,     0,   118,    70,   119,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,     0,     0,     0,     0,   123,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,   124,
      75,     0,     0,     0,   125,    76,   126,    77,   127,     0,
       0,     0,     0,     0,     0,    78,     0,   128,   129,     0,
       0,     0,     0,     0,    79,     0,    80,     0,     0,     0,
       0,    81,   130,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      12,   107,   151,   152,    91,    92,    18,   243,   184,   199,
      92,     0,   163,   184,     3,   102,     5,   185,   199,     8,
     102,   180,     3,   244,    11,    11,    11,     5,     4,   112,
     418,    43,    27,   103,    53,    11,   109,    36,     9,   188,
      11,    41,     6,    55,    56,     6,    11,    12,    60,   198,
     123,    11,    64,    23,    43,    19,    20,    21,    19,    20,
      21,     5,    38,    11,     8,     6,    55,    56,    56,    17,
      18,    60,    41,    85,     0,    64,    76,    25,    19,    20,
      21,    11,    12,    11,   298,    42,    98,    82,   237,    17,
      18,    18,    19,   199,    17,    18,    85,    85,   117,    11,
     488,    96,   490,   173,   109,   281,    76,    76,    97,    98,
      80,    11,    12,    13,   103,   329,   330,   331,   123,    11,
     119,   335,   336,   299,   110,    53,    38,    12,   113,    47,
     341,   112,    50,   119,   110,   122,   223,   224,   119,   117,
     227,   223,   224,   119,    64,   227,    38,   358,   113,   113,
     110,   238,   373,   122,    87,   119,   238,   113,   119,   120,
      49,   117,   174,   175,    18,    19,    17,    18,   116,   181,
      59,   385,   184,   185,   114,   187,   327,   189,   119,   112,
     103,   114,   194,   113,   173,   174,   175,    41,   369,   113,
     179,   180,   119,   117,   408,   371,   377,   346,   110,   380,
     371,   369,    60,   362,    87,   381,   396,   119,   376,   377,
     110,    91,   380,    91,   301,   396,   113,    11,   110,   301,
     117,   113,    76,    17,    18,    91,   113,   119,   240,   112,
     117,   114,   113,   469,   116,   117,   117,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,   113,
      11,    12,    13,   117,    25,   436,    17,    18,   115,   113,
       7,   273,   274,   117,    11,   119,   372,   113,    39,    40,
     113,   117,    11,    12,   117,    29,   113,    18,    17,    18,
     117,    52,    53,    47,   113,   513,    61,    28,   117,   517,
     396,    62,    17,    18,    19,    20,   116,    68,   112,    70,
     312,   113,   314,   116,   391,   112,    77,   394,    49,    18,
      51,   323,   324,   302,    19,    20,    87,   119,    59,   468,
      17,    18,    93,    37,    38,   107,   108,   105,   106,    19,
      20,   102,    19,    20,   457,   458,   151,   152,     3,   110,
     113,   112,     3,   114,   112,    88,    88,    78,    58,   118,
      88,   118,   364,    12,   112,   112,   122,   122,    43,   371,
      88,   112,   112,    75,   376,   114,   112,   379,   112,     3,
      33,   383,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   120,    11,   112,    75,    75,   122,    25,
     113,   104,   122,   117,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   104,   121,   113,    75,   117,
     114,    25,   114,   113,   117,    33,    52,    53,   112,   115,
     113,    95,   114,   435,   102,   123,    62,   110,   112,   115,
     109,   113,    68,   114,    70,   112,     7,   449,    52,    53,
      89,    77,   454,     3,   124,   117,   115,   123,    62,   115,
      18,    87,   122,   115,    68,   115,    70,    93,   112,   117,
     115,   111,   115,    77,    31,    85,   102,   479,   480,    64,
      98,    60,   173,    87,   110,   396,   112,   141,   114,    93,
     383,   449,   227,   194,   512,   371,   338,   499,   102,   362,
     107,   186,   224,   372,   354,   224,   479,   488,   112,   190,
     114,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   152,   357,   361,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   484,   490,   480,   364,
     379,   435,    -1,   314,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    52,
      -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,   112,    -1,   114,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   112,
      -1,    -1,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    18,   112,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    66,
      -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      97,    -1,    99,   100,   101,    17,    18,    -1,    93,    -1,
      22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,
      32,    -1,    34,    35,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      92,    17,    18,    -1,    -1,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    17,    18,   103,   126,   127,   128,   267,   127,     0,
     128,   129,   112,   130,   131,    11,    12,   113,   132,   133,
     269,    42,   113,   133,   114,    18,    28,    49,    51,    59,
     134,   135,   136,    12,    64,    91,    91,    60,    91,     3,
     136,   115,    29,    50,   137,   138,   150,   151,    25,   116,
     152,   153,   267,   269,    47,    61,   142,   143,   116,   116,
     117,   112,    53,   144,   145,   147,   148,   149,   267,   269,
      31,    46,    55,    56,    57,    66,    71,    73,    81,    90,
      92,    97,    99,   100,   101,   139,   140,   155,   157,   192,
     203,   267,   269,   153,   113,   116,   147,    53,   117,   112,
      18,   140,     3,   112,   119,   177,   178,   262,   263,   264,
     177,   267,   149,   113,   141,    36,   167,   177,    30,    32,
      34,    44,    48,    54,    65,    70,    72,    74,    83,    84,
      98,   158,   159,   200,   201,   203,   267,    27,    82,    96,
     265,     3,    17,    18,    22,    26,    30,    35,    48,    63,
      65,    85,    86,   156,   180,   184,   185,   186,   200,   202,
      49,    59,   266,     3,   131,   146,   112,    88,    88,    78,
      58,    88,   113,   117,   118,   118,    12,   112,   154,   122,
     122,   112,    43,    88,   112,   112,    75,   112,    87,   112,
     114,   208,   209,   221,   112,   208,   207,   209,   210,   112,
       8,     9,    10,    12,    13,    14,    15,    16,    52,    70,
      93,   112,   193,   195,   196,   197,   227,   260,   261,   267,
     269,   270,   271,    19,    20,   169,   170,     3,   159,   267,
     269,   267,   269,   120,    17,    18,    25,    53,    62,    68,
      77,   102,   110,   114,   156,   179,   193,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   226,
     228,   229,   267,    19,    20,   187,   188,   189,   267,   113,
     251,   252,   269,    33,   112,   110,   165,   166,   176,   181,
     262,   269,   110,   257,   258,   259,   260,   269,   186,   253,
     254,   269,   209,    38,   162,   163,   164,   176,   181,   269,
      39,    40,   112,   211,   212,   213,   238,   239,   241,   243,
     244,   245,    75,   162,    75,   209,    70,   154,   160,   161,
     180,   195,   196,   194,   122,    18,    19,    41,    76,   177,
     190,   191,   249,   250,   177,   190,   191,   113,   117,   167,
     177,   104,   209,   177,     9,   269,    37,    38,   214,   207,
     113,   117,   107,   108,   204,   105,   106,   205,   104,   109,
     123,   242,   122,   113,   117,   269,   255,   256,   269,   121,
     113,   117,   182,   183,   181,   113,   117,   114,   113,   117,
     114,    75,   113,   117,   249,   181,    33,   177,   267,   115,
     112,   268,   269,   113,   268,   113,   117,     7,   198,   199,
     269,   269,   193,   249,   122,   249,   249,    95,   168,   249,
     249,   102,   171,   172,   170,   218,   209,   230,   112,   231,
     232,   233,   115,   110,   216,   217,   218,   123,   109,    67,
     225,   226,   188,   252,   113,   117,   114,   196,   260,   166,
     184,   207,   259,   196,   260,   254,   196,   260,   181,     4,
     164,   249,   112,   113,   124,   246,   247,   262,   262,   161,
       7,    19,    20,   249,    89,   110,   234,   235,   271,   117,
     123,   256,    12,   196,   115,   115,   115,   115,   163,   240,
     122,   248,   269,   113,   117,   183,   183,   112,   117,   113,
     117,   206,   209,   214,   115,   115,     5,   198,   248,   122,
     247,   173,   234,   235,    23,    76,    80,   236,   237,   269,
       6,    21,   119,   174,   175,   189,   113,   174,   113,   175,
     120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   125,   126,   126,   127,   127,   129,   128,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   137,   137,   138,   139,
     139,   140,   140,   140,   141,   140,   140,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   147,   148,   148,
     149,   149,   149,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   153,   154,   155,   156,   156,   157,   157,   157,
     157,   158,   158,   159,   159,   159,   159,   159,   160,   160,
     161,   161,   161,   161,   162,   162,   163,   163,   163,   164,
     164,   164,   164,   165,   165,   166,   166,   166,   167,   168,
     168,   169,   169,   170,   170,   170,   170,   170,   170,   170,
     171,   171,   173,   172,   174,   174,   175,   175,   175,   175,
     176,   176,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   186,   186,   186,   186,   186,   187,   187,   188,   189,
     189,   190,   190,   190,   191,   192,   193,   193,   194,   193,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   197,
     197,   197,   198,   198,   199,   199,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   202,   202,   202,   202,   202,   202,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   208,
     208,   208,   209,   210,   210,   211,   211,   212,   213,   213,
     213,   213,   214,   214,   215,   215,   216,   216,   217,   217,
     218,   218,   219,   219,   219,   219,   219,   219,   219,   220,
     221,   222,   222,   223,   224,   224,   225,   225,   226,   227,
     227,   228,   228,   229,   229,   230,   231,   231,   232,   233,
     234,   234,   235,   236,   236,   237,   237,   237,   238,   238,
     238,   240,   239,   241,   242,   242,   242,   242,   243,   243,
     244,   245,   246,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   253,   253,   254,   254,   255,
     255,   256,   256,   257,   258,   258,   259,   259,   259,   259,
     259,   260,   260,   261,   262,   262,   263,   264,   265,   265,
     265,   265,   266,   266,   266,   267,   267,   268,   268,   269,
     270,   271
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     4,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       3,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     3,     1,     1,     1,     3,     5,
       1,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     2,     1,     2,     2,     3,     1,     1,
       3,     4,     1,     3,     2,     3,     1,     3,     0,     1,
       1,     2,     1,     3,     1,     1,     3,     4,     4,     1,
       3,     4,     4,     1,     1,     3,     1,     4,     4,     1,
       1,     1,     1,     1,     0,     1,     2,     4,     0,     1,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (param, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, param); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void **param)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (param);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void **param)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, param);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void **param)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , param);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param); \
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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void **param)
{
  YYUSE (yyvaluep);
  YYUSE (param);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void **param)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 413 "asn1p_y.y" /* yacc.c:1646  */
    {
		*(void **)param = (yyvsp[0].a_grammar);
	}
#line 2125 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 416 "asn1p_y.y" /* yacc.c:1646  */
    {
		*(void **)param = (yyvsp[0].a_grammar);
	}
#line 2133 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 422 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_grammar) = asn1p_new();
		checkmem((yyval.a_grammar));
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2143 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 427 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_grammar) = (yyvsp[-1].a_grammar);
		TQ_ADD(&((yyval.a_grammar)->modules), (yyvsp[0].a_module), mod_next);
	}
#line 2152 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 444 "asn1p_y.y" /* yacc.c:1646  */
    { currentModule = asn1p_module_new(); }
#line 2158 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 449 "asn1p_y.y" /* yacc.c:1646  */
    {

		(yyval.a_module) = currentModule;

		if((yyvsp[-1].a_module)) {
			asn1p_module_t tmp = *((yyval.a_module));
			*((yyval.a_module)) = *((yyvsp[-1].a_module));
			*((yyvsp[-1].a_module)) = tmp;
			asn1p_module_free((yyvsp[-1].a_module));
		} else {
			/* There's a chance that a module is just plain empty */
		}

		(yyval.a_module)->ModuleName = (yyvsp[-8].tv_str);
		(yyval.a_module)->module_oid = (yyvsp[-6].a_oid);
		(yyval.a_module)->module_flags = (yyvsp[-4].a_module_flags);
	}
#line 2180 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 473 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_oid) = 0; }
#line 2186 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 474 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_oid) = (yyvsp[0].a_oid); }
#line 2192 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 478 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
	}
#line 2200 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 481 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_oid) = 0;
	}
#line 2208 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 487 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_oid) = asn1p_oid_new();
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2219 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 493 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_oid) = (yyvsp[-1].a_oid);
		asn1p_oid_add_arc((yyval.a_oid), &(yyvsp[0].a_oid_arc));
		if((yyvsp[0].a_oid_arc).name)
			free((yyvsp[0].a_oid_arc).name);
	}
#line 2230 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 502 "asn1p_y.y" /* yacc.c:1646  */
    {					/* iso */
		(yyval.a_oid_arc).name = (yyvsp[0].tv_str);
		(yyval.a_oid_arc).number = -1;
	}
#line 2239 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 506 "asn1p_y.y" /* yacc.c:1646  */
    {		/* iso(1) */
		(yyval.a_oid_arc).name = (yyvsp[-3].tv_str);
		(yyval.a_oid_arc).number = (yyvsp[-1].a_int);
	}
#line 2248 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 510 "asn1p_y.y" /* yacc.c:1646  */
    {					/* 1 */
		(yyval.a_oid_arc).name = 0;
		(yyval.a_oid_arc).number = (yyvsp[0].a_int);
	}
#line 2257 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 520 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_module_flags) = MSF_NOFLAGS; }
#line 2263 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 521 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2271 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 530 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = (yyvsp[0].a_module_flags);
	}
#line 2279 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 533 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = (yyvsp[-1].a_module_flags) | (yyvsp[0].a_module_flags);
	}
#line 2287 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 542 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = MSF_EXPLICIT_TAGS;
	}
#line 2295 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 545 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = MSF_IMPLICIT_TAGS;
	}
#line 2303 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 548 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = MSF_AUTOMATIC_TAGS;
	}
#line 2311 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 551 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module_flags) = MSF_EXTENSIBILITY_IMPLIED;
	}
#line 2319 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 555 "asn1p_y.y" /* yacc.c:1646  */
    {
		/* X.680Amd1 specifies TAG and XER */
		if(strcmp((yyvsp[-1].tv_str), "TAG") == 0) {
		 	(yyval.a_module_flags) = MSF_TAG_INSTRUCTIONS;
		} else if(strcmp((yyvsp[-1].tv_str), "XER") == 0) {
		 	(yyval.a_module_flags) = MSF_XER_INSTRUCTIONS;
		} else {
			fprintf(stderr,
				"WARNING: %s INSTRUCTIONS at %s:%d: "
				"Unrecognized encoding reference\n",
				(yyvsp[-1].tv_str), ASN_FILENAME, yylineno);
		 	(yyval.a_module_flags) = MSF_unk_INSTRUCTIONS;
		}
		free((yyvsp[-1].tv_str));
	}
#line 2339 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 576 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_module) = 0; }
#line 2345 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 577 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2353 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 586 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		AL_IMPORT((yyval.a_module), exports, (yyvsp[-2].a_module), xp_next);
		AL_IMPORT((yyval.a_module), imports, (yyvsp[-1].a_module), xp_next);
		asn1p_module_move_members((yyval.a_module), (yyvsp[0].a_module));

		asn1p_module_free((yyvsp[-2].a_module));
		asn1p_module_free((yyvsp[-1].a_module));
		asn1p_module_free((yyvsp[0].a_module));
	}
#line 2368 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 599 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = (yyvsp[0].a_module);
	}
#line 2376 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 602 "asn1p_y.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].a_module)) {
			(yyval.a_module) = (yyvsp[-1].a_module);
		} else {
			(yyval.a_module) = (yyvsp[0].a_module);
			break;
		}
        asn1p_module_move_members((yyval.a_module), (yyvsp[0].a_module));
		asn1p_module_free((yyvsp[0].a_module));
	}
#line 2391 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 619 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2403 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 626 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2415 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 640 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		assert((yyvsp[0].a_expr)->expr_type != A1TC_INVALID);
		assert((yyvsp[0].a_expr)->meta_type != AMT_INVALID);
		asn1p_module_member_add((yyval.a_module), (yyvsp[0].a_expr));
	}
#line 2427 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 648 "asn1p_y.y" /* yacc.c:1646  */
    { asn1p_lexer_hack_push_encoding_control(); }
#line 2433 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 649 "asn1p_y.y" /* yacc.c:1646  */
    {
		fprintf(stderr,
			"WARNING: ENCODING-CONTROL %s "
			"specification at %s:%d ignored\n",
			(yyvsp[-1].tv_str), ASN_FILENAME, yylineno);
		free((yyvsp[-1].tv_str));
		(yyval.a_module) = 0;
	}
#line 2446 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 661 "asn1p_y.y" /* yacc.c:1646  */
    {
		return yyerror(param,
			"Attempt to redefine a standard basic string type, "
			"please comment out or remove this type redefinition.");
	}
#line 2456 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 674 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_module) = 0; }
#line 2462 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 678 "asn1p_y.y" /* yacc.c:1646  */
    {
		if(!saved_aid && 0)
			return yyerror(param, "Unterminated IMPORTS FROM, "
					"expected semicolon ';'");
		saved_aid = 0;
		(yyval.a_module) = (yyvsp[-1].a_module);
	}
#line 2474 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 688 "asn1p_y.y" /* yacc.c:1646  */
    {
		return yyerror(param, "Empty IMPORTS list");
	}
#line 2482 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 694 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_module) = asn1p_module_new(); }
#line 2488 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 698 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2498 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 703 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = (yyvsp[-1].a_module);
		TQ_ADD(&((yyval.a_module)->imports), (yyvsp[0].a_xports), xp_next);
	}
#line 2507 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 45:
#line 710 "asn1p_y.y" /* yacc.c:1646  */
    { memset(&(yyval.a_aid), 0, sizeof((yyval.a_aid))); }
#line 2513 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 711 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_aid).oid = (yyvsp[0].a_oid); }
#line 2519 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 715 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = (yyvsp[-3].a_xports);
		(yyval.a_xports)->fromModuleName = (yyvsp[-1].tv_str);
		(yyval.a_xports)->identifier = (yyvsp[0].a_aid);
		/* This stupid thing is used for look-back hack. */
		saved_aid = (yyval.a_xports)->identifier.oid ? 0 : &((yyval.a_xports)->identifier);
		checkmem((yyval.a_xports));
	}
#line 2532 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 726 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2542 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 731 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2551 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 738 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2562 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 744 "asn1p_y.y" /* yacc.c:1646  */
    {		/* Completely equivalent to above */
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2573 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 750 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
	}
#line 2584 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 760 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_module) = 0; }
#line 2590 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 761 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_module) = asn1p_module_new();
		checkmem((yyval.a_module));
		if((yyvsp[0].a_xports)) {
			TQ_ADD(&((yyval.a_module)->exports), (yyvsp[0].a_xports), xp_next);
		} else {
			/* "EXPORTS ALL;" */
		}
	}
#line 2604 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 773 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = (yyvsp[-1].a_xports);
	}
#line 2612 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 776 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = 0;
	}
#line 2620 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 779 "asn1p_y.y" /* yacc.c:1646  */
    {
		/* Empty EXPORTS clause effectively prohibits export. */
		(yyval.a_xports) = asn1p_xports_new();
		checkmem((yyval.a_xports));
	}
#line 2630 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 787 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = asn1p_xports_new();
		assert((yyval.a_xports));
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2640 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 792 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_xports) = (yyvsp[-2].a_xports);
		TQ_ADD(&((yyval.a_xports)->xp_members), (yyvsp[0].a_expr), next);
	}
#line 2649 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 799 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2660 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 805 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2671 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 811 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
		(yyval.a_expr)->expr_type = A1TC_EXPORTVAR;
	}
#line 2682 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 820 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 2688 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 823 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2700 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 843 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2712 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 853 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[-3].a_ref);
		(yyval.a_expr)->rhs_pspecs = (yyvsp[-1].a_expr);
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_TYPEREF;
	}
#line 2725 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 873 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type);
		assert((yyval.a_expr)->meta_type);
	}
#line 2736 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 879 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 2747 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 895 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2757 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 901 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->Identifier = (yyvsp[-5].tv_str);
		(yyval.a_expr)->lhs_params = (yyvsp[-3].a_plist);
	}
#line 2767 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 909 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_plist) = asn1p_paramlist_new(yylineno);
		checkmem((yyval.a_plist));
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2781 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 918 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_plist) = (yyvsp[-2].a_plist);
		ret = asn1p_paramlist_add_param((yyval.a_plist), (yyvsp[0].a_parg).governor, (yyvsp[0].a_parg).argument);
		checkmem(ret == 0);
		asn1p_ref_free((yyvsp[0].a_parg).governor);
		free((yyvsp[0].a_parg).argument);
	}
#line 2794 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 929 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_parg).governor = NULL;
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2803 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 933 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2816 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 941 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor, (yyvsp[-2].tv_str), 0);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
		free((yyvsp[-2].tv_str));
	}
#line 2829 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 949 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2842 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 957 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_parg).governor = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_parg).governor,
			ASN_EXPR_TYPE2STR((yyvsp[-2].a_type)), 1);
		checkmem(ret == 0);
		(yyval.a_parg).argument = (yyvsp[0].tv_str);
	}
#line 2855 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 968 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2865 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 973 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2874 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 981 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2887 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 989 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("?");
		(yyval.a_expr)->expr_type = A1TC_REFERENCE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 2900 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 997 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->expr_type = A1TC_VALUESET;
		(yyval.a_expr)->meta_type = AMT_VALUESET;
		(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
	}
#line 2911 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1020 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_expr) = NEW_EXPR(); }
#line 2917 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1021 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_expr) = (yyvsp[0].a_expr); }
#line 2923 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1024 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2933 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1029 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2942 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1033 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-4].a_expr);
		(yyvsp[-1].a_expr)->meta_type = AMT_TYPE;
		(yyvsp[-1].a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyvsp[-1].a_expr)->marker.flags |= EM_OPTIONAL;
		asn1p_expr_add((yyval.a_expr), (yyvsp[-1].a_expr));
	}
#line 2954 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1043 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 2966 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1050 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		(yyvsp[0].a_marker).flags |= (yyval.a_expr)->marker.flags;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 2977 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1056 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->meta_type = (yyvsp[0].a_expr)->meta_type;
		(yyval.a_expr)->expr_type = A1TC_COMPONENTS_OF;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 2989 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1063 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 2997 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1069 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3007 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1074 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3016 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1081 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		assert((yyval.a_expr)->Identifier == 0);
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
	}
#line 3026 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1086 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
	}
#line 3034 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1089 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
		_fixup_anonymous_identifier((yyval.a_expr));
	}
#line 3043 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1096 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		checkmem((yyval.a_expr));
		(yyval.a_expr)->with_syntax = (yyvsp[0].a_wsynt);
		assert((yyval.a_expr)->expr_type == A1TC_CLASSDEF);
		assert((yyval.a_expr)->meta_type == AMT_OBJECTCLASS);
	}
#line 3055 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1106 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_int) = 0; }
#line 3061 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1107 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_int) = 1; }
#line 3067 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1111 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_CLASSDEF;
		(yyval.a_expr)->meta_type = AMT_OBJECTCLASS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3079 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1118 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3088 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1128 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-1].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_TFS;	/* TypeFieldSpec */
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3101 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1138 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVFS;	/* FixedTypeValueFieldSpec */
		(yyval.a_expr)->unique = (yyvsp[-1].a_int);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
		asn1p_expr_add((yyval.a_expr), (yyvsp[-2].a_expr));
	}
#line 3115 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1149 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3128 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1159 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3142 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1170 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_VTVSFS;
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3155 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1180 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_FTVSFS;
		asn1p_expr_add((yyval.a_expr), (yyvsp[-1].a_expr));
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3169 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1191 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyval.a_expr)->reference = (yyvsp[-1].a_ref);
		(yyval.a_expr)->meta_type = AMT_OBJECTFIELD;
		(yyval.a_expr)->expr_type = A1TC_CLASSFIELD_OSFS;
		(yyval.a_expr)->marker = (yyvsp[0].a_marker);
	}
#line 3183 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1203 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_wsynt) = 0; }
#line 3189 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1204 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wsynt) = (yyvsp[0].a_wsynt);
	}
#line 3197 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1211 "asn1p_y.y" /* yacc.c:1646  */
    { asn1p_lexer_hack_enable_with_syntax(); }
#line 3203 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1213 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
	}
#line 3211 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1219 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wsynt) = asn1p_wsyntx_new();
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3220 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1223 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wsynt) = (yyvsp[-1].a_wsynt);
		TQ_ADD(&((yyval.a_wsynt)->chunks), (yyvsp[0].a_wchunk), next);
	}
#line 3229 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1230 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_opaque).buf, 0);
		(yyval.a_wchunk)->type = WC_WHITESPACE;
	}
#line 3238 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1234 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].tv_str), 0);
	}
#line 3246 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1237 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromstring((yyvsp[0].a_refcomp).name, 0);
		(yyval.a_wchunk)->type = WC_FIELD;
	}
#line 3255 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1241 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_wchunk) = asn1p_wsyntx_chunk_fromsyntax((yyvsp[-1].a_wsynt));
	}
#line 3263 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1247 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3276 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1255 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3290 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1264 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		(yyval.a_expr)->value = (yyvsp[0].a_value);
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3304 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1278 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[0].a_expr);
        (yyval.a_expr)->tag = (yyvsp[-1].a_tag);
    }
#line 3313 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1285 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
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
				assert(!(yyvsp[0].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3338 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1308 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
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
				assert(!(yyvsp[0].a_constr));
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3363 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1331 "asn1p_y.y" /* yacc.c:1646  */
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
				/* Check this : optManyConstraints is not used ?! */
				asn1p_constraint_free((yyvsp[0].a_constr));
			} else {
				(yyval.a_expr)->constraints = (yyvsp[0].a_constr);
			}
		}
	}
#line 3389 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1355 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_int) = asn1p_as_pointer ? EM_INDIRECT : 0;
		asn1p_as_pointer = 0;
	}
#line 3398 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1362 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[0].a_expr);
		(yyval.a_expr)->marker.flags |= (yyvsp[-1].a_int);

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
#line 3419 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1386 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_CHOICE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3430 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1392 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3441 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1398 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-1].a_expr);
		assert((yyval.a_expr)->expr_type == A1TC_INVALID);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3452 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1404 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SEQUENCE_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3467 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1414 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->constraints = (yyvsp[-4].a_constr);
		(yyval.a_expr)->expr_type = ASN_CONSTR_SET_OF;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		(yyvsp[0].a_expr)->Identifier = (yyvsp[-2].tv_str);
		(yyvsp[0].a_expr)->tag = (yyvsp[-1].a_tag);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 3482 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1424 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3493 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1430 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_expr)->reference,
			(yyvsp[0].tv_str), RLT_lowercase);
		checkmem(ret == 0);
		(yyval.a_expr)->expr_type = ASN_TYPE_ANY;
		(yyval.a_expr)->meta_type = AMT_TYPE;
		free((yyvsp[0].tv_str));
	}
#line 3510 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1442 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->reference = (yyvsp[0].a_ref);
		(yyval.a_expr)->expr_type = A1TC_INSTANCE;
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3522 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1457 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[0].tv_str));
	}
#line 3535 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1465 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
		checkmem(ret == 0);
	}
#line 3548 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1473 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 3564 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1484 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[-2].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_UNKNOWN);
		checkmem(ret == 0);
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 3580 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1495 "asn1p_y.y" /* yacc.c:1646  */
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
#line 3604 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1517 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		checkmem((yyval.a_ref));
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3617 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1525 "asn1p_y.y" /* yacc.c:1646  */
    {
		int ret;
		(yyval.a_ref) = (yyvsp[-2].a_ref);
		ret = asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].a_refcomp).name, (yyvsp[0].a_refcomp).lex_type);
		free((yyvsp[0].a_refcomp).name);
		checkmem(ret == 0);
	}
#line 3629 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1538 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_refcomp).lex_type = RLT_AmpUppercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3638 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1543 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_refcomp).lex_type = RLT_Amplowercase;
		(yyval.a_refcomp).name = (yyvsp[0].tv_str);
	}
#line 3647 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1552 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3657 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1557 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_AmpUppercase);
		free((yyvsp[0].tv_str));
	}
#line 3667 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1562 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_ref) = (yyval.a_ref);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_Amplowercase);
		free((yyvsp[0].tv_str));
	}
#line 3677 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1570 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_CAPITALS);
		free((yyvsp[0].tv_str));
	}
#line 3687 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1593 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		assert((yyval.a_expr)->Identifier == NULL);
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 3699 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1605 "asn1p_y.y" /* yacc.c:1646  */
    { asn1p_lexer_hack_push_opaque_state(); }
#line 3705 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1605 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_UNPARSED;
	}
#line 3715 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1613 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_NULL;
	}
#line 3725 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1618 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint(0);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_FALSE;
	}
#line 3735 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1623 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint(1);
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TRUE;
	}
#line 3745 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1636 "asn1p_y.y" /* yacc.c:1646  */
    {
		asn1p_ref_t *ref;
		int ret;
		ref = asn1p_ref_new(yylineno, currentModule);
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
#line 3764 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1654 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_value));
	}
#line 3773 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1658 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_TUPLE;
	}
#line 3783 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1663 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
		(yyval.a_value)->type = ATV_QUADRUPLE;
	}
#line 3793 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1671 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.tv_opaque).len = (yyvsp[0].tv_opaque).len + 1;
		(yyval.tv_opaque).buf = malloc(1 + (yyval.tv_opaque).len + 1);
		checkmem((yyval.tv_opaque).buf);
		(yyval.tv_opaque).buf[0] = '{';
		memcpy((yyval.tv_opaque).buf + 1, (yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len);
		(yyval.tv_opaque).buf[(yyval.tv_opaque).len] = '\0';
		free((yyvsp[0].tv_opaque).buf);
    }
#line 3807 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1680 "asn1p_y.y" /* yacc.c:1646  */
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
#line 3824 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1696 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.tv_opaque).len = strlen((yyvsp[0].tv_str));
        (yyval.tv_opaque).buf = (yyvsp[0].tv_str);
    }
#line 3833 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1702 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_BOOLEAN; }
#line 3839 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1703 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_NULL; }
#line 3845 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1704 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_REAL; }
#line 3851 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1705 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_OCTET_STRING; }
#line 3857 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1706 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_OBJECT_IDENTIFIER; }
#line 3863 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1707 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_RELATIVE_OID; }
#line 3869 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1709 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_EMBEDDED_PDV; }
#line 3875 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1710 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_CHARACTER_STRING; }
#line 3881 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1711 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_UTCTime; }
#line 3887 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1712 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_GeneralizedTime; }
#line 3893 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1721 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_INTEGER; }
#line 3899 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1722 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_ENUMERATED; }
#line 3905 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1723 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_BASIC_BIT_STRING; }
#line 3911 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1727 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = (yyvsp[0].a_type);
		(yyval.a_expr)->meta_type = AMT_TYPE;
	}
#line 3922 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1733 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_INTEGER;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3932 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1738 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_ENUMERATED;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3942 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1743 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3952 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1748 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_expr) = (yyvsp[-1].a_expr);
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3962 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1753 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
        (yyval.a_expr)->expr_type = ASN_BASIC_BIT_STRING;
        (yyval.a_expr)->meta_type = AMT_TYPE;
    }
#line 3973 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1762 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_BMPString; }
#line 3979 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1763 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_type) = ASN_STRING_GeneralString;
		fprintf(stderr, "WARNING: GeneralString is not fully supported\n");
	}
#line 3988 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1767 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_type) = ASN_STRING_GraphicString;
		fprintf(stderr, "WARNING: GraphicString is not fully supported\n");
	}
#line 3997 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1771 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_IA5String; }
#line 4003 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1772 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_ISO646String; }
#line 4009 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1773 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_NumericString; }
#line 4015 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1774 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_PrintableString; }
#line 4021 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1775 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_type) = ASN_STRING_T61String;
		fprintf(stderr, "WARNING: T61String is not fully supported\n");
	}
#line 4030 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1779 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_TeletexString; }
#line 4036 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1780 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_UniversalString; }
#line 4042 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1781 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_UTF8String; }
#line 4048 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1782 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_type) = ASN_STRING_VideotexString;
		fprintf(stderr, "WARNING: VideotexString is not fully supported\n");
	}
#line 4057 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1786 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_VisibleString; }
#line 4063 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1787 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_type) = ASN_STRING_ObjectDescriptor; }
#line 4069 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1799 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_constr) = 0; }
#line 4075 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1804 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_constr) = 0; }
#line 4081 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1809 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_constr) = 0; }
#line 4087 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1815 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), 0);
    }
#line 4095 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1822 "asn1p_y.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].a_constr)->type == ACT_CA_SET && (yyvsp[0].a_constr)->el_count == 1) {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr)->elements[0]);
        } else {
            CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_SET, (yyvsp[-1].a_constr), (yyvsp[0].a_constr));
        }
	}
#line 4107 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1836 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_EL_EXT;
	}
#line 4116 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1841 "asn1p_y.y" /* yacc.c:1646  */
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
   }
#line 4127 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1847 "asn1p_y.y" /* yacc.c:1646  */
    {
       asn1p_constraint_t *ct;
       ct = asn1p_constraint_new(yylineno, currentModule);
       ct->type = ACT_EL_EXT;
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-4].a_constr), ct);
       ct = (yyval.a_constr);
       CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, ct, (yyvsp[0].a_constr));
   }
#line 4140 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1859 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_AEX, (yyvsp[0].a_constr), 0);
	}
#line 4148 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1866 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_UNI, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4156 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1873 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_INT, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4164 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1881 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_EXC, (yyvsp[-2].a_constr), (yyvsp[0].a_constr));
	}
#line 4172 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1888 "asn1p_y.y" /* yacc.c:1646  */
    {
        int ret;
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_CA_SET;
        ret = asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        checkmem(ret == 0);
    }
#line 4185 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1899 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = (yyvsp[0].a_value);
	}
#line 4196 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1905 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_TYPE;
		(yyval.a_constr)->containedSubtype = (yyvsp[0].a_value);
	}
#line 4207 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1921 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_FROM, (yyvsp[0].a_constr), 0);
	}
#line 4215 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1926 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_SIZE, (yyvsp[0].a_constr), 0);
	}
#line 4223 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1931 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
	}
#line 4233 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1936 "asn1p_y.y" /* yacc.c:1646  */
    {
		asn1p_ref_t *ref;
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_PATTERN;
		ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component(ref, (yyvsp[0].tv_str), RLT_lowercase);
		(yyval.a_constr)->value = asn1p_value_fromref(ref, 0);
		free((yyvsp[0].tv_str));
	}
#line 4247 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1948 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = (yyvsp[-1].a_ctype);
		(yyval.a_constr)->range_start = (yyvsp[-2].a_value);
		(yyval.a_constr)->range_stop = (yyvsp[0].a_value);
    }
#line 4259 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1958 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint(-123);
		(yyval.a_value)->type = ATV_MIN;
    }
#line 4268 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1965 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint(321);
		(yyval.a_value)->type = ATV_MAX;
    }
#line 4277 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1973 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'B');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4287 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1978 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = _convert_bitstring2binary((yyvsp[0].tv_str), 'H');
		checkmem((yyval.a_value));
		free((yyvsp[0].tv_str));
	}
#line 4297 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1986 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4307 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1992 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromtype((yyvsp[0].a_expr));
		checkmem((yyval.a_value));
		asn1p_expr_free((yyvsp[0].a_expr));
    }
#line 4317 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 263:
#line 2004 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CT_WCOMP, (yyvsp[0].a_constr), 0);
	}
#line 4325 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 264:
#line 2007 "asn1p_y.y" /* yacc.c:1646  */
    {
        assert((yyvsp[0].a_constr)->type == ACT_CA_CSV);
        (yyvsp[0].a_constr)->type = ACT_CT_WCOMPS;
        (yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4335 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 268:
#line 2015 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_constr) = (yyvsp[-1].a_constr); }
#line 4341 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 269:
#line 2017 "asn1p_y.y" /* yacc.c:1646  */
    {
        assert((yyvsp[-1].a_constr)->type == ACT_CA_CSV);
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
		asn1p_constraint_t *ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_EXT;
        asn1p_constraint_insert((yyval.a_constr), ct);
        for(unsigned i = 0; i < (yyvsp[-1].a_constr)->el_count; i++) {
            asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr)->elements[i]);
        }
    }
#line 4358 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 270:
#line 2030 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        (yyval.a_constr)->type = ACT_CA_CSV;
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
    }
#line 4368 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 271:
#line 2035 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_constr) = (yyvsp[-2].a_constr);
        asn1p_constraint_insert((yyval.a_constr), (yyvsp[0].a_constr));
	}
#line 4377 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 272:
#line 2041 "asn1p_y.y" /* yacc.c:1646  */
    {
        (yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
        checkmem((yyval.a_constr));
        (yyval.a_constr)->type = ACT_EL_VALUE;
        (yyval.a_constr)->value = (yyvsp[-2].a_value);
        if((yyvsp[-1].a_constr)) asn1p_constraint_insert((yyval.a_constr), (yyvsp[-1].a_constr));
        (yyval.a_constr)->presence = (yyvsp[0].a_pres);
    }
#line 4390 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 273:
#line 2055 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_pres) = ACPRES_DEFAULT; }
#line 4396 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 274:
#line 2056 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_pres) = (yyvsp[0].a_pres); }
#line 4402 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 275:
#line 2060 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_pres) = ACPRES_PRESENT;
	}
#line 4410 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 276:
#line 2063 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_pres) = ACPRES_ABSENT;
	}
#line 4418 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 277:
#line 2066 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_pres) = ACPRES_OPTIONAL;
	}
#line 4426 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 281:
#line 2081 "asn1p_y.y" /* yacc.c:1646  */
    { asn1p_lexer_hack_push_opaque_state(); }
#line 4432 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 282:
#line 2081 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_CT_CTDBY;
		(yyval.a_constr)->value = asn1p_value_frombuf((yyvsp[0].tv_opaque).buf, (yyvsp[0].tv_opaque).len, 0);
		checkmem((yyval.a_constr)->value);
		(yyval.a_constr)->value->type = ATV_UNPARSED;
	}
#line 4445 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 283:
#line 2092 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		(yyval.a_constr)->type = ACT_CT_CTNG;
		(yyval.a_constr)->value = asn1p_value_fromtype((yyvsp[0].a_expr));
		asn1p_expr_free((yyvsp[0].a_expr));
	}
#line 4456 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 284:
#line 2101 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_ctype) = ACT_EL_RANGE; }
#line 4462 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 285:
#line 2102 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_ctype) = ACT_EL_RLRANGE; }
#line 4468 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 286:
#line 2103 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_ctype) = ACT_EL_LLRANGE; }
#line 4474 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 287:
#line 2104 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_ctype) = ACT_EL_ULRANGE; }
#line 4480 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 288:
#line 2107 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4488 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 289:
#line 2110 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = (yyvsp[0].a_constr);
	}
#line 4496 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 290:
#line 2119 "asn1p_y.y" /* yacc.c:1646  */
    {
		asn1p_ref_t *ref = asn1p_ref_new(yylineno, currentModule);
		asn1p_constraint_t *ct;
		int ret;
		ret = asn1p_ref_add_component(ref, (yyvsp[-1].tv_str), 0);
		checkmem(ret == 0);
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref(ref, 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, ct, 0);
		free((yyvsp[-1].tv_str));
	}
#line 4514 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 291:
#line 2135 "asn1p_y.y" /* yacc.c:1646  */
    {
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CRC, (yyvsp[-3].a_constr), (yyvsp[-1].a_constr));
	}
#line 4522 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 292:
#line 2141 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_constr) = asn1p_constraint_new(yylineno, currentModule);
		checkmem((yyval.a_constr));
		(yyval.a_constr)->type = ACT_EL_VALUE;
		(yyval.a_constr)->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
	}
#line 4533 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 293:
#line 2147 "asn1p_y.y" /* yacc.c:1646  */
    {
		asn1p_constraint_t *ct;
		ct = asn1p_constraint_new(yylineno, currentModule);
		checkmem(ct);
		ct->type = ACT_EL_VALUE;
		ct->value = asn1p_value_fromref((yyvsp[0].a_ref), 0);
		CONSTRAINT_INSERT((yyval.a_constr), ACT_CA_CSV, (yyvsp[-2].a_constr), ct);
	}
#line 4546 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 294:
#line 2161 "asn1p_y.y" /* yacc.c:1646  */
    {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 2);
		int ret;
		*p = '@';
		strcpy(p + 1, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
#line 4562 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 295:
#line 2172 "asn1p_y.y" /* yacc.c:1646  */
    {
		char *p = malloc(strlen((yyvsp[0].tv_str)) + 3);
		int ret;
		p[0] = '@';
		p[1] = '.';
		strcpy(p + 2, (yyvsp[0].tv_str));
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		ret = asn1p_ref_add_component((yyval.a_ref), p, 0);
		checkmem(ret == 0);
		free(p);
		free((yyvsp[0].tv_str));
	}
#line 4579 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 296:
#line 2188 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4587 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 297:
#line 2191 "asn1p_y.y" /* yacc.c:1646  */
    {
		int l1 = strlen((yyvsp[-2].tv_str));
		int l3 = strlen((yyvsp[0].tv_str));
		(yyval.tv_str) = malloc(l1 + 1 + l3 + 1);
		memcpy((yyval.tv_str), (yyvsp[-2].tv_str), l1);
		(yyval.tv_str)[l1] = '.';
		memcpy((yyval.tv_str) + l1 + 1, (yyvsp[0].tv_str), l3);
		(yyval.tv_str)[l1 + 1 + l3] = '\0';
		free((yyvsp[-2].tv_str));
		free((yyvsp[0].tv_str));
	}
#line 4603 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 298:
#line 2211 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_marker).flags = EM_NOMARK;
		(yyval.a_marker).default_value = 0;
	}
#line 4612 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 299:
#line 2215 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_marker) = (yyvsp[0].a_marker); }
#line 4618 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 300:
#line 2219 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_marker).flags = EM_OPTIONAL | EM_INDIRECT;
		(yyval.a_marker).default_value = 0;
	}
#line 4627 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 301:
#line 2223 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_marker).flags = EM_DEFAULT;
		(yyval.a_marker).default_value = (yyvsp[0].a_value);
	}
#line 4636 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 302:
#line 2230 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4646 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 303:
#line 2235 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
    }
#line 4655 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 304:
#line 2241 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
    }
#line 4667 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 305:
#line 2250 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4677 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 306:
#line 2255 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4686 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 307:
#line 2262 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4699 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 308:
#line 2270 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4712 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 309:
#line 2280 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4722 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 310:
#line 2285 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4731 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 311:
#line 2292 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = asn1p_value_fromint((yyvsp[-1].a_int));
	}
#line 4744 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 312:
#line 2300 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4757 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 313:
#line 2310 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[0].a_expr);
        asn1p_expr_t *first_memb = TQ_FIRST(&((yyval.a_expr)->members));
        if(first_memb) {
            if(first_memb->expr_type == A1TC_EXTENSIBLE) {
                return yyerror(param,
                    "The ENUMERATION cannot start with extension (...).");
            }
        } else {
            return yyerror(param,
                "The ENUMERATION list cannot be empty.");
        }
    }
#line 4775 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 314:
#line 2325 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4785 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 315:
#line 2330 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = (yyvsp[-2].a_expr);
		asn1p_expr_add((yyval.a_expr), (yyvsp[0].a_expr));
	}
#line 4794 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 316:
#line 2337 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[0].tv_str);
	}
#line 4806 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 317:
#line 2344 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4819 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 318:
#line 2352 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->Identifier = (yyvsp[-3].tv_str);
		(yyval.a_expr)->value = (yyvsp[-1].a_value);
	}
#line 4832 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 319:
#line 2360 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->expr_type = A1TC_UNIVERVAL;
		(yyval.a_expr)->meta_type = AMT_VALUE;
		(yyval.a_expr)->value = (yyvsp[0].a_value);
	}
#line 4844 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 320:
#line 2367 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_expr) = NEW_EXPR();
		checkmem((yyval.a_expr));
		(yyval.a_expr)->Identifier = strdup("...");
		checkmem((yyval.a_expr)->Identifier);
		(yyval.a_expr)->expr_type = A1TC_EXTENSIBLE;
		(yyval.a_expr)->meta_type = AMT_VALUE;
	}
#line 4857 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 321:
#line 2378 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4866 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 322:
#line 2382 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromint((yyvsp[0].a_int));
		checkmem((yyval.a_value));
	}
#line 4875 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 323:
#line 2389 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromdouble((yyvsp[0].a_dbl));
		checkmem((yyval.a_value));
	}
#line 4884 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 324:
#line 2420 "asn1p_y.y" /* yacc.c:1646  */
    { memset(&(yyval.a_tag), 0, sizeof((yyval.a_tag))); }
#line 4890 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 325:
#line 2421 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag) = (yyvsp[0].a_tag); }
#line 4896 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 326:
#line 2425 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_tag) = (yyvsp[-1].a_tag);
		(yyval.a_tag).tag_mode = (yyvsp[0].a_tag).tag_mode;
	}
#line 4905 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 327:
#line 2432 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_tag) = (yyvsp[-2].a_tag);
		(yyval.a_tag).tag_value = (yyvsp[-1].a_int);
	}
#line 4914 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 328:
#line 2438 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_class = TC_CONTEXT_SPECIFIC; }
#line 4920 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 329:
#line 2439 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_class = TC_UNIVERSAL; }
#line 4926 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 330:
#line 2440 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_class = TC_APPLICATION; }
#line 4932 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 331:
#line 2441 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_class = TC_PRIVATE; }
#line 4938 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 332:
#line 2445 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_mode = TM_DEFAULT; }
#line 4944 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 333:
#line 2446 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_mode = TM_IMPLICIT; }
#line 4950 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 334:
#line 2447 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.a_tag).tag_mode = TM_EXPLICIT; }
#line 4956 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 335:
#line 2451 "asn1p_y.y" /* yacc.c:1646  */
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4965 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 336:
#line 2455 "asn1p_y.y" /* yacc.c:1646  */
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4974 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 337:
#line 2463 "asn1p_y.y" /* yacc.c:1646  */
    { (yyval.tv_str) = 0; }
#line 4980 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 338:
#line 2464 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4988 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 339:
#line 2470 "asn1p_y.y" /* yacc.c:1646  */
    {
		checkmem((yyvsp[0].tv_str));
		(yyval.tv_str) = (yyvsp[0].tv_str);
	}
#line 4997 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 340:
#line 2477 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_ref) = asn1p_ref_new(yylineno, currentModule);
		asn1p_ref_add_component((yyval.a_ref), (yyvsp[0].tv_str), RLT_lowercase);
		free((yyvsp[0].tv_str));
    }
#line 5007 "asn1p_y.c" /* yacc.c:1646  */
    break;

  case 341:
#line 2484 "asn1p_y.y" /* yacc.c:1646  */
    {
		(yyval.a_value) = asn1p_value_fromref((yyvsp[0].a_ref), 0);
    }
#line 5015 "asn1p_y.c" /* yacc.c:1646  */
    break;


#line 5019 "asn1p_y.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (param, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (param, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, param);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp, param);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (param, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, param);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, param);
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
  return yyresult;
}
#line 2488 "asn1p_y.y" /* yacc.c:1906  */



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
	if(bv_ptr == NULL) {
		/* ENOMEM */
		return NULL;
	}

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
yyerror(void **param, const char *msg) {
	(void)param;
	extern char *asn1p_text;
	fprintf(stderr,
		"ASN.1 grammar parse error "
		"near %s:%d (token \"%s\"): %s\n",
		ASN_FILENAME, yylineno, asn1p_text, msg);
	return -1;
}

