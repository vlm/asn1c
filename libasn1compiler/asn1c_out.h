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
		OT_DEPS,	/* Dependencies */
		OT_TYPE_DECLS,	/* Type declarations */
		OT_FUNC_DECLS,	/* Function declarations */
		OT_STAT_DEFS,	/* Static definitions */
		OT_CODE,	/* Some code */
		OT_MAX
	} target;
	TQ_HEAD(out_chunk_t) targets[OT_MAX];
} compiler_streams_t;

static char *_compiler_stream2str[] __attribute__ ((unused))
	= { "DEPS", "TYPE-DECLS", "FUNC-DECLS", "STAT-DEFS", "CODE" };

int asn1c_compiled_output(arg_t *arg, const char *fmt, ...);

#endif	/* _ASN1_COMPILED_OUTPUT_H_ */
