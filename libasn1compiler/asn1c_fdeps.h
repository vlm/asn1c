#ifndef	ASN1C_FDEPS_H
#define	ASN1C_FDEPS_H

typedef struct {
    char *filename;
    int lineno;
    int column;
} asn1c_dep_filename;


/*
 * Format:
 * <observed-name> [<dependent-name> ...]
 */
typedef struct {
    asn1c_dep_filename **deps;
    size_t deps_count;
} asn1c_dep_chain;

/*
 * A single dependency chain, marked with the usage tag and activation tag.
 */
typedef struct {
    enum asn1c_dep_section {
        FDEP_IGNORE = 0,              /* Section is not used */
        FDEP_DEFAULT = (1 << 1),      /* Default dependency list */
        FDEP_REFERRED = (1 << 2),     /* Dynamic list of dependencies */
        FDEP_CONVERTER = (1 << 3),    /* Name of the file with int main() */
        FDEP_COMMON_FILES = (1 << 4), /* Section for mandatory dependencies */
        FDEP_CODEC_OER = (1 << 5),    /* Use contents only if -gen-OER */
        FDEP_CODEC_PER = (1 << 6),    /* Use contents only if -gen-PER */
    } section;                        /* Some file refers to it */

    /* Whether this chain is alive and has to be present in the output */
    struct {
        int active;
        char *by;
    } activated;

    asn1c_dep_chain *chain;
} asn1c_tagged_dep_chain;

typedef struct {
    asn1c_tagged_dep_chain **chains;
    size_t chains_count;
} asn1c_dep_chainset;

asn1c_dep_chainset *asn1c_read_file_dependencies(arg_t *arg,
                                                 const char *datadir);

/* Data may be a filename or an "#include <>" string. */
void asn1c_activate_dependency(asn1c_dep_chainset *deps, const char *data,
                               const char *by);

asn1c_dep_chain *asn1c_deps_flatten(const asn1c_dep_chainset *deps,
                                    enum asn1c_dep_section);

void asn1c_dep_chain_free(asn1c_dep_chain *);
void asn1c_dep_chainset_free(asn1c_dep_chainset *);

#endif	/* ASN1C_FDEPS_H */
