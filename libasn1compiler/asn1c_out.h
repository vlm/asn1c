#ifndef	_ASN1_COMPILED_OUTPUT_H_
#define	_ASN1_COMPILED_OUTPUT_H_

/*
 * An elementary chunk of target language text.
 */
typedef struct out_chunk {
	char *buf;
	int len;

	TQ_ENTRY(struct out_chunk) next;
} out_chunk_t;

typedef struct compiler_streams {
	enum {
		OT_IGNORE	= -1,
		OT_ASSERT	= 0,
		OT_INCLUDES,	/* #include files */
		OT_DEPS,	/* Dependencies (other than #includes) */
		OT_TYPE_DECLS,	/* Type declarations */
		OT_FUNC_DECLS,	/* Function declarations */
		OT_STAT_DEFS,	/* Static definitions */
		OT_CODE,	/* Some code */
		OT_MAX
	} target;
	TQ_HEAD(out_chunk_t) targets[OT_MAX];
} compiler_streams_t;

static char *_compiler_stream2str[] __attribute__ ((unused))
    = { "ASSERT", "INCLUDES", "DEPS", "TYPE-DECLS", "FUNC-DECLS", "STAT-DEFS", "CODE" };

int asn1c_compiled_output(arg_t *arg, const char *fmt, ...);


/*****************************************************************
 * Useful macros for invoking asn1c_compiled_output() and friends.
 */

/* Redirect output to a different stream. */
#define	REDIR(foo)	do { arg->target->target = foo; } while(0)

#define	INDENT(val)		arg->indent_level += (val)
#define	INDENTED(code)	do {			\
		INDENT(+1);			\
		do { code; } while(0);		\
		INDENT(-1);			\
	} while(0)

#define	FLAT(code)	do {			\
		int _il = arg->indent_level;	\
		arg->indent_level = 0;		\
		do { code; } while(0);		\
		arg->indent_level = _il;	\
	} while(0)

#define	EMBED(ev)	do {					\
		int saved_target = arg->target->target;		\
		REDIR(OT_TYPE_DECLS);				\
		arg->embed++;					\
		INDENTED(arg_t _tmp = *arg;			\
			_tmp.expr = ev;				\
			_tmp.default_cb(&_tmp);			\
		);						\
		arg->embed--;					\
		assert(arg->target->target == OT_TYPE_DECLS);	\
		REDIR(saved_target);				\
	} while(0)

/* Output a piece of text into a default stream */
#define	OUT(fmt, args...)	asn1c_compiled_output(arg, fmt, ##args)
#define	OUT_NOINDENT(fmt, args...)	do {	\
	int _saved_indent = arg->indent_level;	\
	arg->indent_level = 0;			\
	OUT(fmt, ##args);			\
	arg->indent_level = _saved_indent;	\
} while(0)

/* Generate #include line */
#define	GEN_INCLUDE(filename)	do {				\
	int saved_target = arg->target->target;			\
	REDIR(OT_INCLUDES);					\
	OUT_NOINDENT("#include <%s.h>\n", filename);		\
	REDIR(saved_target);					\
} while(0)

/* Generate ASN.1 type declaration */
#define	GEN_DECLARE(expr)	do {				\
	int saved_target = arg->target->target;			\
	REDIR(OT_DEPS);						\
	OUT_NOINDENT("extern asn1_TYPE_descriptor_t "		\
			"asn1_DEF_%s;\n",			\
			MKID(expr->Identifier));		\
	REDIR(saved_target);					\
} while(0)

#endif	/* _ASN1_COMPILED_OUTPUT_H_ */
