%{

#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"
#include "asn1p_y.h"

int asn1p_lex(void);
void asn1p_lexer_hack_push_opaque_state(void);		/* Used in .y */
void asn1p_lexer_hack_enable_with_syntax(void);		/* Used in .y */
void asn1p_lexer_hack_push_encoding_control(void);	/* Used in .y */

#define	YY_FATAL_ERROR(msg)	do {			\
		fprintf(stderr,				\
			"lexer error at line %d, "	\
			"text \"%s\"\n",		\
			yylineno, yytext);		\
		exit(1);				\
	} while(0)

int asn1p_lexer_pedantic_1990 = 0;
int asn1p_lexer_types_year = 0;
int asn1p_lexer_constructs_year = 0;
static int _check_dashes(char *ptr);
static asn1_integer_t asn1p_atoi(char *ptr); /* errno is either 0 or ERANGE */

/*
 * Check that the type is defined in the year of the standard choosen.
 */
#define	TYPE_LIFETIME(fyr, lyr)				\
	(!asn1p_lexer_types_year			\
	|| (fyr && fyr <= asn1p_lexer_types_year)	\
	|| (lyr && lyr  > asn1p_lexer_types_year))

/*
 * Check the the construction (or concept, i.e. CLASS) is defined in
 * a given year.
 */
#define	CONSTRUCT_LIFETIME(fyr, lyr)			\
	(!asn1p_lexer_constructs_year			\
	|| (fyr && fyr <= asn1p_lexer_constructs_year)	\
	|| (lyr && lyr  > asn1p_lexer_constructs_year))

/*
 * Make sure that the label is compliant with the naming rules.
 */
#define	CHECK_DASHES	do {				\
	if(_check_dashes(yytext)) {			\
		fprintf(stderr,				\
		"%s: Identifier format invalid: "	\
		"Improper dash location\n", yytext);	\
		return -1;				\
	} } while(0)

/*
 * Append quoted string.
 */
#define	QAPPEND(text, tlen)	do {				\
		char *prev_text = asn1p_lval.tv_opaque.buf;	\
		int prev_len = asn1p_lval.tv_opaque.len;	\
		char *p;					\
								\
		p = malloc((tlen) + prev_len + 1);		\
		if(p == NULL) return -1;			\
								\
		if(prev_text) memcpy(p, prev_text, prev_len);	\
		memcpy(p + prev_len, text, tlen);		\
		p[prev_len + (tlen)] = '\0';			\
								\
		free(asn1p_lval.tv_opaque.buf);			\
		asn1p_lval.tv_opaque.buf = p;			\
		asn1p_lval.tv_opaque.len = (tlen) + prev_len;	\
	} while(0)

%}

%option	never-interactive
%option	noinput 
%option	noyywrap stack
/* Performance penalty is OK */
%option yylineno	
/* Controlled from within application */
%option debug		

%pointer

%x dash_comment
%x cpp_comment
%x quoted
%x opaque
%x encoding_control
%x with_syntax

/* Newline */
NL	[\r\v\f\n]
/* White-space */
WSP	[\t\r\v\f\n ]

%%

"--"		yy_push_state(dash_comment);
<dash_comment>{

	{NL}	yy_pop_state();

	--	yy_pop_state();	/* End of comment */
	-	/* Eat single dash */
	[^\r\v\f\n-]+	/* Eat */

}
<INITIAL,cpp_comment>"/*"		yy_push_state(cpp_comment);
<cpp_comment>{
	[^*/]	/* Eat */
	"*/"	yy_pop_state();
	.	/* Eat */
}


	/*
	 * This is state is being set from corresponding .y module when
	 * higher-level data is necessary to make proper parsing of the
	 * underlying data. Thus, we enter the <opaque> state and save
	 * everything for later processing.
	 */
<opaque>{

	"{"	{
			yy_push_state(opaque);
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
		}

	"}"	{
			yy_pop_state();
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
		}

	[^{}:=]+	{
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
		}

	"::="	{
			fprintf(stderr,
				"ASN.1 Parser syncronization failure: "
				"\"%s\" at line %d must not appear "
				"inside value definition\n",
				yytext, yylineno);
			return -1;
		}

	[:=]	{
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
		}

	}

\"[^\"]*		{
			asn1p_lval.tv_opaque.buf = 0;
			asn1p_lval.tv_opaque.len = 0;
			QAPPEND(yytext+1, yyleng-1);
			yy_push_state(quoted);
		}
<quoted>{

	\"\"	{ QAPPEND(yytext, yyleng-1); }	/* Add a single quote */
	[^\"]+	{ QAPPEND(yytext, yyleng); }

	\"	{
			yy_pop_state();
			/* Do not append last quote:
			// QAPPEND(yytext, yyleng); */

			if(asn1p_lexer_pedantic_1990
			&& strchr(yytext, '\n')) {
				fprintf(stderr, "%s: "
				"Newlines are prohibited by ASN.1:1990\n",
				asn1p_lval.tv_opaque.buf);
				return -1;
			}

			return TOK_cstring;
		}

	}

<encoding_control>{
	ENCODING-CONTROL	{
			const char *s = "ENCODING-CONTROL";
			const char *p = s + sizeof("ENCODING-CONTROL") - 2;
			for(; p >= s; p--) unput(*p);
			yy_pop_state();
		}
	END	unput('D'); unput('N'); unput('E'); yy_pop_state();
	[^{} \t\r\v\f\n]+
	[[:alnum:]]+
	.	/* Eat everything else */
	"\n"
	}

'[0-9A-F \t\r\v\f\n]+'H {
		/* " \t\r\n" weren't allowed in ASN.1:1990. */
		asn1p_lval.tv_str = yytext;
		return TOK_hstring;
	}

'[01 \t\r\v\f\n]+'B	{
		/* " \t\r\n" weren't allowed in ASN.1:1990. */
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_bstring;
	}


-[1-9][0-9]*	{
		asn1p_lval.a_int = asn1p_atoi(yytext);
		if(errno == ERANGE)
			return -1;
		return TOK_number_negative;
	}

[1-9][0-9]*	{
		asn1p_lval.a_int = asn1p_atoi(yytext);
		if(errno == ERANGE)
			return -1;
		return TOK_number;
	}

"0"	{
		asn1p_lval.a_int = asn1p_atoi(yytext);
		if(errno == ERANGE)
			return -1;
		return TOK_number;
	}

	/*
	 * Tags
	 */
\[(UNIVERSAL[ \t\r\v\f\n]+|APPLICATION[ \t\r\v\f\n]+|PRIVATE[ \t\r\v\f\n]+)?[0-9]+\]	{
		char *p;
		memset(&asn1p_lval.a_tag, 0, sizeof(asn1p_lval.a_tag));
		switch(yytext[1]) {
		case 'U':
			asn1p_lval.a_tag.tag_class = TC_UNIVERSAL;
			p = yytext + sizeof("UNIVERSAL") + 1;
			break;
		case 'A':
			asn1p_lval.a_tag.tag_class = TC_APPLICATION;
			p = yytext + sizeof("APPLICATION") + 1;
			break;
		case 'P':
			asn1p_lval.a_tag.tag_class = TC_PRIVATE;
			p = yytext + sizeof("PRIVATE") + 1;
			break;
		default:
			assert(yytext[1] >= '0' && yytext[1] <= '9');
			asn1p_lval.a_tag.tag_class = TC_CONTEXT_SPECIFIC;
			p = yytext + 1;
			break;
		}
		asn1p_lval.a_tag.tag_value = asn1p_atoi(p);
		if(*p == '0' && asn1p_lval.a_tag.tag_value) {
			fprintf(stderr,
			"Tag value at line %d "
			"cannot start with zero "
			"and have multiple digits: \"%s\"\n",
			yylineno, yytext);
			return -1;
		}
		return TOK_tag;
	}

\[[A-Z]+[ \t\r\v\f\n]+[0-9]+\]	{
		fprintf(stderr,
			"Unsupported tag syntax at line %d: \"%s\"\n",
			yylineno, yytext);
		return -1;
	}

ABSENT			return TOK_ABSENT;
	/*
ABSTRACT-SYNTAX		return TOK_ABSTRACT_SYNTAX;
	*/
ALL			return TOK_ALL;
ANY			{
				/* Appeared in 1990, removed in 1997 */
				if(TYPE_LIFETIME(1990, 1997))
					return TOK_ANY;	
				fprintf(stderr, "Keyword \"%s\" at line %d "
					"is obsolete\n", yytext, yylineno);
				REJECT;
			}
APPLICATION		return TOK_APPLICATION;
AUTOMATIC		return TOK_AUTOMATIC;
BEGIN			return TOK_BEGIN;
BIT			return TOK_BIT;
BMPString		{
				if(TYPE_LIFETIME(1994, 0))
					return TOK_BMPString;
				REJECT;
			}
BOOLEAN			return TOK_BOOLEAN;
BY			return TOK_BY;
CHARACTER		return TOK_CHARACTER;
CHOICE			return TOK_CHOICE;
CLASS			return TOK_CLASS;
COMPONENT		return TOK_COMPONENT;
COMPONENTS		return TOK_COMPONENTS;
CONSRAINED		return TOK_CONSTRAINED;
CONTAINING		return TOK_CONTAINING;
DEFAULT			return TOK_DEFAULT;
DEFINED			{
				/* Appeared in 1990, removed in 1997 */
				if(TYPE_LIFETIME(1990, 1997))
					return TOK_DEFINED;
				fprintf(stderr, "Keyword \"%s\" at line %d "
					"is obsolete\n", yytext, yylineno);
				/* Deprecated since */
				REJECT;
			}
DEFINITIONS		return TOK_DEFINITIONS;
EMBEDDED		return TOK_EMBEDDED;
ENCODED			return TOK_ENCODED;
ENCODING-CONTROL	return TOK_ENCODING_CONTROL;
END			return TOK_END;
ENUMERATED		return TOK_ENUMERATED;
EXCEPT			return TOK_EXCEPT;
EXPLICIT		return TOK_EXPLICIT;
EXPORTS			return TOK_EXPORTS;
EXTENSIBILITY		return TOK_EXTENSIBILITY;
EXTERNAL		return TOK_EXTERNAL;
FALSE			return TOK_FALSE;
FROM			return TOK_FROM;
GeneralizedTime		return TOK_GeneralizedTime;
GeneralString		return TOK_GeneralString;
GraphicString		return TOK_GraphicString;
IA5String		return TOK_IA5String;
IDENTIFIER		return TOK_IDENTIFIER;
IMPLICIT		return TOK_IMPLICIT;
IMPLIED			return TOK_IMPLIED;
IMPORTS			return TOK_IMPORTS;
INCLUDES		return TOK_INCLUDES;
INSTANCE		return TOK_INSTANCE;
INSTRUCTIONS		return TOK_INSTRUCTIONS;
INTEGER			return TOK_INTEGER;
INTERSECTION		return TOK_INTERSECTION;
ISO646String		return TOK_ISO646String;
MAX			return TOK_MAX;
MIN			return TOK_MIN;
MINUS-INFINITY		return TOK_MINUS_INFINITY;
NULL			return TOK_NULL;
NumericString		return TOK_NumericString;
OBJECT			return TOK_OBJECT;
ObjectDescriptor	return TOK_ObjectDescriptor;
OCTET			return TOK_OCTET;
OF			return TOK_OF;
OPTIONAL		return TOK_OPTIONAL;
PATTERN			return TOK_PATTERN;
PDV			return TOK_PDV;
PLUS-INFINITY		return TOK_PLUS_INFINITY;
PRESENT			return TOK_PRESENT;
PrintableString		return TOK_PrintableString;
PRIVATE			return TOK_PRIVATE;
REAL			return TOK_REAL;
RELATIVE-OID		return TOK_RELATIVE_OID;
SEQUENCE		return TOK_SEQUENCE;
SET			return TOK_SET;
SIZE			return TOK_SIZE;
STRING			return TOK_STRING;
SYNTAX			return TOK_SYNTAX;
T61String		return TOK_T61String;
TAGS			return TOK_TAGS;
TeletexString		return TOK_TeletexString;
TRUE			return TOK_TRUE;
TYPE-IDENTIFIER		return TOK_TYPE_IDENTIFIER;
UNION			return TOK_UNION;
UNIQUE			return TOK_UNIQUE;
UNIVERSAL		return TOK_UNIVERSAL;
UniversalString		{
				if(TYPE_LIFETIME(1994, 0))
					return TOK_UniversalString;
				REJECT;
			}
UTCTime			return TOK_UTCTime;
UTF8String		{
				if(TYPE_LIFETIME(1994, 0))
					return TOK_UTF8String;
				REJECT;
			}
VideotexString		return TOK_VideotexString;
VisibleString		return TOK_VisibleString;
WITH			return TOK_WITH;


<INITIAL,with_syntax>&[A-Z][A-Za-z0-9-]*	{
		CHECK_DASHES;
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_typefieldreference;
	}

<INITIAL,with_syntax>&[a-z][a-zA-Z0-9-]*	{
		CHECK_DASHES;
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_valuefieldreference;
	}


[a-z][a-zA-Z0-9-]*	{
		CHECK_DASHES;
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_identifier;
	}

	/*
	 * objectclassreference
	 */
[A-Z][A-Z0-9-]*	{
		CHECK_DASHES;
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_capitalreference;
	}

	/*
	 * typereference, modulereference
	 * NOTE: TOK_objectclassreference must be combined
	 * with this token to produce true typereference.
	 */
[A-Z][A-Za-z0-9-]*	{
		CHECK_DASHES;
		asn1p_lval.tv_str = strdup(yytext);
		return TOK_typereference;
	}

"::="		return TOK_PPEQ;

"..."		return TOK_ThreeDots;
".."		return TOK_TwoDots;

[(){},;:|!.&@\[\]]	return yytext[0];

{WSP}+	/* Ignore whitespace */

[^A-Za-z0-9:=,{}<.@()[]'\"|&^*;!-] {
		if(TYPE_LIFETIME(1994, 0))
			fprintf(stderr, "ERROR: ");
		fprintf(stderr,
		"Symbol '%c' at line %d is prohibited "
		"by ASN.1:1994 and ASN.1:1997\n",
			yytext[0], yylineno);
		if(TYPE_LIFETIME(1994, 0))
			return -1;
	}

<with_syntax>{

	[^&{} \t\r\v\f\n]+	{
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
			}

	{WSP}+		{
			asn1p_lval.tv_opaque.buf = strdup(yytext);
			asn1p_lval.tv_opaque.len = yyleng;
			return TOK_opaque;
			}

	"}"		{
				yy_pop_state();
				return '}';
			}

}

[|^]	return yytext[0];	/* Union, Intersection */

<*>.	{
		fprintf(stderr,
			"Unexpected token at line %d: \"%s\"\n",
			yylineno, yytext);
		while(YYSTATE != INITIAL)
			yy_pop_state();
		if(0) {
			yy_top_state();	/* Just to use this function. */
			yy_fatal_error("Parse error");
		}
		return -1;
}

<*><<EOF>>      {
		while(YYSTATE != INITIAL)
			yy_pop_state();
		yyterminate();
	}


%%

/*
 * Very dirty but wonderful hack allowing to rule states from within .y file.
 */
void asn1p_lexer_hack_push_opaque_state() { yy_push_state(opaque); }

/*
 * Another hack which disables recognizing some tokens when inside WITH SYNTAX.
 */
void asn1p_lexer_hack_enable_with_syntax() { yy_push_state(with_syntax); }

/* Yet another */
void asn1p_lexer_hack_push_encoding_control() {
	yy_push_state(encoding_control);
}

/*
 * Check that a token does not end with dash and does not contain
 * several dashes in succession.
 * "Name", "Type-Id", "T-y-p-e-i-d" are OK
 * "end-", "vustom--value" are INVALID
 */
static int
_check_dashes(char *ptr) {
	int prev_dash = 0;

	assert(*ptr != '-');

	for(;; ptr++) {
		switch(*ptr) {
		case '-':
			if(prev_dash++)	/* No double dashes */
				return -1;
			continue;
		case '\0':
			if(prev_dash)	/* No dashes at the end */
				return -1;
			break;
		default:
			prev_dash = 0;
			continue;
		}
		break;
	}

	return 0;
}

static asn1_integer_t
asn1p_atoi(char *ptr) {
	asn1_integer_t value;
	errno = 0;	/* Clear the error code */

	if(sizeof(value) <= sizeof(int)) {
		value = strtol(ptr, 0, 10);
	} else {
#ifdef	HAVE_STRTOIMAX
		value = strtoimax(ptr, 0, 10);
#elif	HAVE_STRTOLL
		value = strtoll(ptr, 0, 10);
#else
		value = strtol(ptr, 0, 10);
#endif
	}

	if(errno == ERANGE) {
		fprintf(stderr,
			"Value \"%s\" at line %d is too large "
			"for this compiler! Please contact the vendor.",
			ptr, yylineno);
		errno = ERANGE;	/* Restore potentially clobbered errno */
	}

	return value;
}

