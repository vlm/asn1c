#undef	NDEBUG
#include "asn1fix_internal.h"

#ifdef	_WIN32
#include <io.h>
#include <direct.h>
#define	chdir _chdir
#else
#include <dirent.h>
#include <sysexits.h>
#endif
#include <errno.h>
#include <libgen.h>

#include "genhash.h"
#include "asn1fix.h"
#include "asn1_buffer.h"
#include "asn1_namespace.h"

#ifndef TOP_SRCDIR
#define TOP_SRCDIR_S    ".."
#else
#define STRINGIFY_MACRO2(x)  #x
#define STRINGIFY_MACRO(x)  STRINGIFY_MACRO2(x)
#define TOP_SRCDIR_S    STRINGIFY_MACRO(TOP_SRCDIR)
#endif

static int check(const char *fname,
	enum asn1p_flags parser_flags,
	enum asn1f_flags fixer_flags);
static int post_fix_check(asn1p_t *asn);
static int post_fix_check_element(asn1p_module_t *mod, asn1p_expr_t *expr);

int
main(int ac, char **av) {
#ifdef	_WIN32
	intptr_t dir;
	struct _finddata_t c_file;
#else
	struct dirent *dp;
	DIR *dir;
#endif
	int failed = 0;
	int completed = 0;
	enum asn1p_flags parser_flags = A1P_NOFLAGS;
	enum asn1f_flags fixer_flags  = A1F_NOFLAGS;
	const char *filename;
	size_t len;

	/*
	 * Just in case when one decides that some flags better be
	 * enabled during `ASN1_FIXER_FLAGS=1 make check` or some
	 * similar usage.
	 */
	if(getenv("ASN1_PARSER_FLAGS"))
		parser_flags = atoi(getenv("ASN1_PARSER_FLAGS"));
	if(getenv("ASN1_FIXER_FLAGS"))
		fixer_flags = atoi(getenv("ASN1_FIXER_FLAGS"));

	/*
	 * Go into a directory with tests.
	 */
	if(ac <= 1) {
        abuf *asn1_tests_dirname = abuf_new();
        const char *top_srcdir = getenv("top_srcdir");
        if(!top_srcdir) top_srcdir = TOP_SRCDIR_S;

        abuf_printf(asn1_tests_dirname, "%s/tests/tests-asn1c-compiler",
                    top_srcdir);

        fprintf(stderr, "Testing in %s...\n", top_srcdir);
        int ret = chdir(asn1_tests_dirname->buffer);
        if(ret == -1)
            fprintf(stderr, "%s: %s\n", asn1_tests_dirname->buffer,
                    strerror(errno));
        assert(ret == 0);
        /* For some reasons, tests could be hidden under extra tests dir. */
#ifdef	_WIN32
		dir = _findfirst("*.asn1", &c_file);
		assert(dir != -1L);
#else
		dir = opendir(".");
		assert(dir);
#endif	/* _WIN32 */
	} else {
		dir = 0;
	}

	/*
	 * Scan every *.asn1 file and try to parse and fix it.
	 */
    if(dir) {
#ifdef	_WIN32
        do {
            filename = c_file.name;
#else
        while((dp = readdir(dir))) {
            filename = dp->d_name;
#endif	/* _WIN32 */
            len = strlen(filename);
            if(len <= 5 || !isdigit(filename[0])
               || strcmp(filename + len - 5, ".asn1"))
                continue;
            int ret = check(filename, parser_flags, fixer_flags);
            if(ret) {
                fprintf(stderr, "FAILED: %s\n", filename);
                failed++;
            }
            completed++;
#ifdef	_WIN32
        } while(_findnext(dir, &c_file) == 0);
        _findclose(dir);
#else
        }
        closedir(dir);
#endif	/* _WIN32 */


        fprintf(stderr,
                "Tests COMPLETED: %d\n"
                "Tests FAILED:    %d\n",
                completed, failed);
    } else {
        for(int i = 1; i < ac; i++) {
            int ret = check(av[i], parser_flags, fixer_flags);
            if(ret) {
                fprintf(stderr, "FAILED: %s\n", av[i]);
                failed++;
            }
            completed++;
        }
    }

    if(completed == 0) {
        fprintf(stderr, "No tests defined?!\n");
        exit(EX_NOINPUT);
    }

    if(failed) {
        exit(EX_DATAERR);
    }
    return 0;
}

static int
check(const char *fname,
		enum asn1p_flags parser_flags,
		enum asn1f_flags fixer_flags) {
	asn1p_t *asn;
	int expected_parseable;		/* Is it expected to be parseable? */
	int expected_fix_code;		/* What code a fixer must return */
	int r_value = 0;

	/*
	 * Figure out how the processing should go by inferring
	 * expectations from the file name.
	 */
	if(strstr(fname, "-OK.")) {
		expected_parseable = 1;
		expected_fix_code  = 0;
	} else if(strstr(fname, "-NP.")) {
		expected_parseable = 0;
		expected_fix_code  = 123;	/* Does not matter */
	} else if(strstr(fname, "-SE.")) {
		expected_parseable = 1;
		expected_fix_code  = -1;	/* Semantically incorrect */
	} else if(strstr(fname, "-SW.")) {
		expected_parseable = 1;
		expected_fix_code  = 1;	/* Semantically suspicious */
	} else {
		fprintf(stderr, "%s: Invalid file name format\n", fname);
		return -1;
	}

	/* Flag modifiers */
	if(strstr(fname, "-blessSize-"))
		fixer_flags |= A1F_EXTENDED_SizeConstraint;

	fprintf(stderr, "[=> %s]\n", fname);

	/*
	 * Perform low-level parsing.
	 */
	if(!expected_parseable)
		fprintf(stderr, "Expecting error...\n");
	asn = asn1p_parse_file(fname, parser_flags);
	if(asn == NULL) {
		if(expected_parseable) {
			fprintf(stderr, "Cannot parse file \"%s\"\n", fname);
			r_value = -1;
		} else {
			fprintf(stderr,
				"Previous error is EXPECTED, no worry\n");
		}
	} else if(!expected_parseable) {
		fprintf(stderr,
			"The file \"%s\" is not expected to be parseable, "
			"yet parsing was successfull!\n", fname);
		r_value = -1;
	}
	if(!asn) return r_value;

	if(r_value == 0) {
        char *fname_copy = strdup(fname);
        char *test_dir = dirname(fname_copy);
        abuf *skeletons_dirname = abuf_new();
		asn1p_t *std_asn;

        abuf_printf(skeletons_dirname,
                    "%s/../../skeletons/standard-modules/"
                    "ASN1C-UsefulInformationObjectClasses.asn1",
                    test_dir);
        free(fname_copy);

        std_asn = asn1p_parse_file(skeletons_dirname->buffer, A1P_NOFLAGS);
        if(std_asn) {
			asn1p_module_t *mod;
			while((mod = TQ_REMOVE(&(std_asn->modules), mod_next))) {
				mod->_tags |= MT_STANDARD_MODULE;
				TQ_ADD(&(asn->modules), mod, mod_next);
			}
			asn1p_delete(std_asn);

            /* Allow referencing imported modules. */
            asn1f_use_standard_namespaces(asn);
		} else {
            fprintf(stderr, "%s: %s\n", skeletons_dirname->buffer,
                    strerror(errno));
        }

        abuf_free(skeletons_dirname);
    }

	/*
	 * Perform semantical checks and fixes.
	 */
	if(r_value == 0) {
		int ret;

		if(expected_fix_code)
			fprintf(stderr, "Expecting some problems...\n");

		ret = asn1f_process(asn, fixer_flags, 0);
		if(ret) {
			if(ret == expected_fix_code) {
				fprintf(stderr,
					"Previous error is EXPECTED, "
					"no worry\n");
			} else {
				fprintf(stderr,
					"Cannot process file \"%s\": %d\n",
					fname, ret);
				r_value = -1;
		}
		} else if(ret != expected_fix_code) {
			fprintf(stderr,
				"File \"%s\" is expected "
				"to be semantically incorrect, "
				"yet processing was successful!\n",
				fname);
			r_value = -1;
		}
	}

	/*
	 * Check validity of some values, if grammar has special
	 * instructions for that.
	 */
	if(r_value == 0) {
		if(post_fix_check(asn))
			r_value = -1;
	}

	/*
	 * Destroy the asn.
	 */
#ifdef	CLEAN_EVERYTHING
	asn1p_delete(asn);
#endif

	return r_value;
}


static int
post_fix_check(asn1p_t *asn) {
	asn1p_module_t *mod;
	asn1p_expr_t *expr;
	int r_value = 0;

	TQ_FOR(mod, &(asn->modules), mod_next) {
		TQ_FOR(expr, &(mod->members), next) {
			assert(expr->Identifier);
			if(strncmp(expr->Identifier, "check-", 6) == 0) {
				if(post_fix_check_element(mod, expr))
					r_value = -1;
			}
		}
	}

	return r_value;
}


static int
post_fix_check_element(asn1p_module_t *mod, asn1p_expr_t *check_expr) {
	asn1p_expr_t *expr = NULL;
	char *name;
	asn1p_value_t *value;

	if(check_expr->expr_type != ASN_BASIC_INTEGER
	|| check_expr->meta_type != AMT_VALUE) {
		fprintf(stderr,
			"CHECKER: Unsupported type of \"%s\" value: "
			"%d at line %d of %s\n",
			check_expr->Identifier,
			check_expr->expr_type,
			check_expr->_lineno,
			mod->source_file_name
		);
		return -1;
	}

	assert(check_expr->meta_type == AMT_VALUE);

	value = check_expr->value;
	if(value == NULL || value->type != ATV_INTEGER) {
		fprintf(stderr,
			"CHECKER: Unsupported value type of \"%s\": "
			"%d at line %d of %s\n",
			check_expr->Identifier,
			value?(signed)value->type:-1,
			expr->_lineno,
			mod->source_file_name
		);
		return -1;
	}

	name = check_expr->Identifier + sizeof("check-") - 1;

	/*
	 * Scan in search for the original.
	 */
    expr = genhash_get(mod->members_hash, name);
	if(expr == NULL) {
		fprintf(stderr,
			"CHECKER: Value \"%s\" requested by "
			"\"check-%s\" at line %d of %s is not found!\n",
			name, name, check_expr->_lineno,
			mod->source_file_name
		);
		return -1;
	}

	if(0 && expr->expr_type != check_expr->expr_type) {
		fprintf(stderr,
			"CHECKER: Value type of \"%s\" (=%d) at line %d "
			"does not have desired type %d as requested by "
			"\"check-%s\" in %s\n",
			expr->Identifier,
			expr->expr_type,
			expr->_lineno,
			check_expr->expr_type,
			name,
			mod->source_file_name
		);
		return -1;
	}

	if(expr->value == NULL
	|| expr->value->type != value->type) {
		fprintf(stderr,
			"CHECKER: Value of \"%s\" (\"%s\", type=%d) at line %d "
			"does not have desired type %d as requested by "
			"\"check-%s\" in %s\n",
			expr->Identifier,
			asn1f_printable_value(expr->value),
			expr->value->type,
			expr->_lineno,
			value->type,
			name,
			mod->source_file_name
		);
		return -1;
	}

	return 0;
}


