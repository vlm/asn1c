#ifndef	_ASN1C_FDEPS_H_
#define	_ASN1C_FDEPS_H_

typedef struct asn1c_fdeps_s {
	char *filename;		/* Or 0, if root. */

	int used_somewhere;	/* Somefile refers to it */

	struct asn1c_fdeps_s **elements;
	int el_size;
	int el_count;
} asn1c_fdeps_t;

asn1c_fdeps_t *asn1c_read_file_dependencies(arg_t *arg, const char *datadir);

/* Data may be a filename or an "#include <>" string. */
int asn1c_activate_dependency(asn1c_fdeps_t *deps, asn1c_fdeps_t *cur,
	const char *data);

asn1c_fdeps_t *asn1c_deps_makelist(asn1c_fdeps_t *deps);

#endif	/* _ASN1C_FDEPS_H_ */
