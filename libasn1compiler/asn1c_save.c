#include "asn1c_internal.h"
#include "asn1c_compat.h"
#include "asn1c_fdeps.h"
#include "asn1c_lang.h"
#include "asn1c_misc.h"
#include "asn1c_save.h"
#include "asn1c_out.h"

#ifndef HAVE_SYMLINK
#define symlink(a,b) (errno=ENOSYS, -1)
#endif

/* Pedantically check fprintf's return value. */
static int safe_fprintf(FILE *fp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    assert(ret >= 0);
    return ret;
}

/* Pedantically check fwrite's return value. */
static size_t safe_fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream) {
    size_t ret = fwrite(ptr, 1, size * nitems, stream);
    assert(ret == size * nitems);
    return ret;
}

#define	HINCLUDE(s)						\
	((arg->flags & A1C_INCLUDES_QUOTED)			\
		? safe_fprintf(fp_h, "#include \"%s\"\n", s)		\
		: safe_fprintf(fp_h, "#include <%s>\n", s))		\

enum include_type_result {
    TI_NOT_INCLUDED,
    TI_INCLUDED_FROM_BULK,
    TI_INCLUDED_FROM_CMDLINE
};

static int asn1c_dump_streams(arg_t *arg, asn1c_dep_chainset *, const char *, int, char **);
static int asn1c_print_streams(arg_t *arg);
static int asn1c_save_streams(arg_t *arg, asn1c_dep_chainset *, const char *,
                              int, char **);
static int asn1c_copy_over(arg_t *arg, const char *destdir, const char *path,
                           const char *msg);
static int identical_files(const char *fname1, const char *fname2);
static int need_to_generate_pdu_collection(arg_t *arg);
static abuf *generate_pdu_collection(arg_t *arg);
static int generate_pdu_collection_file(arg_t *arg, const char *destdir);
static int generate_preamble(arg_t *, FILE *, int optc, char **argv);
static enum include_type_result include_type_to_pdu_collection(arg_t *arg);
static int pdu_collection_has_unused_types(arg_t *arg);
static const char *generate_pdu_C_definition(void);
static void asn1c__cleanup_pdu_type(void);
static int asn1c__pdu_type_lookup(const char *typename);

static int
asn1c__save_library_makefile(arg_t *arg, const asn1c_dep_chainset *deps,
                             const char *datadir, const char *destdir,
                             const char *makefile_name) {
    asn1p_module_t *mod;
    FILE *mkf;

	mkf = asn1c_open_file(destdir, makefile_name, "", 0);
	if(mkf == NULL) {
		perror(makefile_name);
		return -1;
	}

	safe_fprintf(mkf, "ASN_MODULE_SRCS=");
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		TQ_FOR(arg->expr, &(mod->members), next) {
			if(asn1_lang_map[arg->expr->meta_type]
				[arg->expr->expr_type].type_cb) {
				safe_fprintf(mkf, "\t\\\n\t%s%s.c", destdir,
				asn1c_make_identifier(AMI_MASK_ONLY_SPACES, arg->expr, 0));
			}
		}
	}
	safe_fprintf(mkf, "\n\nASN_MODULE_HDRS=");
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		TQ_FOR(arg->expr, &(mod->members), next) {
			if(asn1_lang_map[arg->expr->meta_type]
				[arg->expr->expr_type].type_cb) {
                safe_fprintf(
                    mkf, "\t\\\n\t%s%s.h", destdir,
                    asn1c_make_identifier(AMI_MASK_ONLY_SPACES, arg->expr, 0));
            }
		}
	}
	safe_fprintf(mkf, "\n\n");

	/*
	 * Move necessary skeleton files and add them to Makefile.am.targets.
	 */
    asn1c_dep_chain *dlist = asn1c_deps_flatten(deps, ~FDEP_CONVERTER);
    if(dlist) {
		char dstpath[PATH_MAX];
		char *dir_end;
		size_t dlen = strlen(datadir);

		assert(dlen < (sizeof(dstpath) / 2 - 2));
		memcpy(dstpath, datadir, dlen);
		dir_end = dstpath + dlen;
		*dir_end++ = '/';

		for(size_t i = 0; i < dlist->deps_count; i++) {
			char where[32]; /* Location of the */
			char *what_kind;	/* HDRS or SRCS */
			const asn1c_dep_filename *dep_file = dlist->deps[i];
			char *fname = dep_file->filename;
			char *dotH;

			assert(strlen(fname) < (sizeof(dstpath) / 2));
			strcpy(dir_end, fname);

			if(arg->flags & A1C_DEBUG) {
				snprintf(where, sizeof(where), "(line %d col %d)",
				dep_file->lineno, dep_file->column);
			} else {
				where[0] = '\0';
			}

            if(asn1c_copy_over(arg, destdir, dstpath, where) == -1) {
                safe_fprintf(mkf, ">>>ABORTED<<<");
				fclose(mkf);
				return -1;
			}

			/* HDRS versus SRCS */
			dotH = strrchr(fname, 'h');
			if(dotH && fname < dotH && dotH[-1] == '.' && !dotH[1]) {
				what_kind = "HDRS";
			} else {
				what_kind = "SRCS";
			}
            safe_fprintf(mkf, "ASN_MODULE_%s+=%s%s\n", what_kind, destdir,
                         fname);
        }

		asn1c_dep_chain_free(dlist);
	}

	safe_fprintf(
		mkf,
		"\n"
		"ASN_MODULE_CFLAGS=%s%s",
		(arg->flags & A1C_GEN_OER) ? "" : "-DASN_DISABLE_OER_SUPPORT ",
		(arg->flags & A1C_GEN_PER) ? "" : "-DASN_DISABLE_PER_SUPPORT ");

	safe_fprintf(
		mkf,
		"\n\n"
		"lib_LTLIBRARIES+=libasncodec.la\n"
		"libasncodec_la_SOURCES="
		"$(ASN_MODULE_SRCS) $(ASN_MODULE_HDRS)\n"
		"libasncodec_la_CPPFLAGS=-I$(top_srcdir)/%s\n"
		"libasncodec_la_CFLAGS=$(ASN_MODULE_CFLAGS)\n"
		"libasncodec_la_LDFLAGS=-lm\n", destdir);
	fclose(mkf);
    safe_fprintf(stderr, "Generated %s%s\n", destdir, makefile_name);

    return 0;
}

static int
asn1c__save_example_mk_makefile(arg_t *arg, const asn1c_dep_chainset *deps,
                                const char *datadir, const char *destdir,
                                const char *makefile_name,
                                const char *library_makefile_name, int argc,
                                char **argv) {
    FILE *mkf;
    asn1c_dep_chain *dlist = asn1c_deps_flatten(deps, FDEP_CONVERTER);

    /* Generate converter-example.mk snippet */
    mkf = asn1c_open_file(destdir, makefile_name, "", 0);
    if(mkf == NULL) {
        perror(makefile_name);
        return -1;
    }
    safe_fprintf(
        mkf,
        "include %s%s\n\n"
        "LIBS += -lm\n"
        "CFLAGS += $(ASN_MODULE_CFLAGS) %s%s-I.\n"
        "ASN_LIBRARY ?= libasncodec.a\n"
        "ASN_PROGRAM ?= converter-example\n"
        "ASN_PROGRAM_SRCS ?= ",
        destdir, library_makefile_name,
        (arg->flags & A1C_PDU_TYPE) ? generate_pdu_C_definition() : "",
        need_to_generate_pdu_collection(arg) ? "-DASN_PDU_COLLECTION " : "");

    if(dlist) {
        for(size_t i = 0; i < dlist->deps_count; i++) {
            char dstpath[PATH_MAX];
            int ret = snprintf(dstpath, sizeof(dstpath), "%s/%s", datadir,
                               dlist->deps[i]->filename);
            assert(ret > 0 && (size_t)ret < sizeof(dstpath));
            if(asn1c_copy_over(arg, destdir, dstpath, "implicit") == -1) {
                safe_fprintf(mkf, ">>>ABORTED<<<");
                fclose(mkf);
                return -1;
			}
            safe_fprintf(mkf, "\\\n\t%s%s", destdir, dlist->deps[i]->filename);
        }
        asn1c_dep_chain_free(dlist);
    }

    if(need_to_generate_pdu_collection(arg)) {
        safe_fprintf(mkf, "\\\n\t%spdu_collection.c", destdir);
        if(generate_pdu_collection_file(arg, destdir)) {
            return -1;
        }
    }

    safe_fprintf(
        mkf,
        "\n\nall: $(ASN_PROGRAM)\n"
        "\n$(ASN_PROGRAM): $(ASN_LIBRARY) $(ASN_PROGRAM_SRCS:.c=.o)"
        "\n\t$(CC) $(CFLAGS) $(CPPFLAGS) -o $(ASN_PROGRAM) "
        "$(ASN_PROGRAM_SRCS:.c=.o) $(LDFLAGS) $(ASN_LIBRARY) $(LIBS)\n"
        "\n$(ASN_LIBRARY): $(ASN_MODULE_SRCS:.c=.o)"
        "\n\t$(AR) rcs $@ $(ASN_MODULE_SRCS:.c=.o)\n"
        "\n.SUFFIXES:"
        "\n.SUFFIXES: .c .o\n"
        "\n.c.o:"
        "\n\t$(CC) $(CFLAGS) -o $@ -c $<\n"
        "\nclean:"
        "\n\trm -f $(ASN_PROGRAM) $(ASN_LIBRARY)"
        "\n\trm -f $(ASN_MODULE_SRCS:.c=.o) $(ASN_PROGRAM_SRCS:.c=.o)\n"
        "\nregen: regenerate-from-asn1-source\n"
        "\nregenerate-from-asn1-source:\n\t");

    for(int i = 0; i < argc; i++)
        safe_fprintf(mkf, "%s%s", i ? " " : "", argv[i]);
    safe_fprintf(mkf, "\n\n");

    fclose(mkf);
    safe_fprintf(stderr, "Generated %s%s\n", destdir, makefile_name);

	return 0;
}

static int
asn1c__save_example_am_makefile(arg_t *arg, const asn1c_dep_chainset *deps, const char *datadir,
                                const char *destdir, const char *makefile_name,
                                const char *library_makefile_name, int argc,
                                char **argv) {
	FILE *mkf;
	asn1c_dep_chain *dlist = asn1c_deps_flatten(deps, FDEP_CONVERTER);

	/* Generate example.am snippet */
	mkf = asn1c_open_file(destdir, makefile_name, "", 0);
	if(mkf == NULL) {
		return -1;
	}
	safe_fprintf(mkf,
	             "include %s%s\n\n"
	             "bin_PROGRAMS += asn1convert\n"
	             "asn1convert_CFLAGS = $(ASN_MODULE_CFLAGS) %s%s\n"
	             "asn1convert_CPPFLAGS = -I$(top_srcdir)/%s\n"
	             "asn1convert_LDADD = libasncodec.la\n"
	             "asn1convert_SOURCES = ",
	             destdir, library_makefile_name,
	             (arg->flags & A1C_PDU_TYPE) ? generate_pdu_C_definition() : "",
	             need_to_generate_pdu_collection(arg) ? "-DASN_PDU_COLLECTION " : "", destdir);

	if(dlist) {
		for(size_t i = 0; i < dlist->deps_count; i++) {
			char dstpath[PATH_MAX];
			int ret = snprintf(dstpath, sizeof(dstpath), "%s/%s", datadir,
			                   dlist->deps[i]->filename);
			assert(ret > 0 && (size_t)ret < sizeof(dstpath));
			if(asn1c_copy_over(arg, destdir, dstpath, "implicit") == -1) {
				safe_fprintf(mkf, ">>>ABORTED<<<");
				fclose(mkf);
				return -1;
			}
			safe_fprintf(mkf, "\\\n\t%s%s", destdir, dlist->deps[i]->filename);
		}
		asn1c_dep_chain_free(dlist);
	}

	if(need_to_generate_pdu_collection(arg)) {
		safe_fprintf(mkf, "\\\n\t%spdu_collection.c", destdir);
		if(generate_pdu_collection_file(arg, destdir))
			return -1;
	}

	safe_fprintf(mkf,
	             "\nregen: regenerate-from-asn1-source\n"
	             "\nregenerate-from-asn1-source:\n\t");

	for(int i = 0; i < argc; i++)
		safe_fprintf(mkf, "%s%s", i ? " " : "", argv[i]);
	safe_fprintf(mkf, "\n\n");

	fclose(mkf);
	safe_fprintf(stderr, "Generated %s%s\n", destdir, makefile_name);

	return 0;
}

static int
asn1c__save_autotools_example(const char *destdir,
                              const char *program_makefile_name) {
	FILE *fd;
	const char* confac = "configure.ac";
	const char* makeam = "Makefile.am";

	if ((access(confac, F_OK) != -1)
	    || (access(makeam, F_OK) != -1))
	{
		safe_fprintf(stderr, "Refusing to overwrite existing '%s' or '%s'\n", confac, makeam);
		return -1;
	}

	fd = asn1c_open_file("", confac, "", 0);
	if(fd == NULL) {
		perror(confac);
		return -1;
	}

	safe_fprintf(fd,
	             "AC_INIT([asn1convert],[0.1])\n"
	             "AM_INIT_AUTOMAKE([-Werror foreign subdir-objects])\n"
	             "AC_PREREQ([2.62])\n"
	             "AC_PROG_CC\n"
	             "LT_INIT\n"
	             "AM_SILENT_RULES([yes])\n"
	             "AC_CONFIG_FILES([Makefile])\n"
	             "AC_OUTPUT\n");
	fclose(fd);
	safe_fprintf(stderr, "Generated minimal example %s\n", confac);

	fd = asn1c_open_file("", makeam, "", 0);
	if(fd == NULL) {
		perror(makeam);
		return -1;
	}

	safe_fprintf(fd,
	             "bin_PROGRAMS =\n"
	             "lib_LTLIBRARIES =\n"
	             "include %s%s\n\n",
	             destdir, program_makefile_name);

	fclose(fd);
	safe_fprintf(stderr, "Generated minimal example %s\n", makeam);
	safe_fprintf(stderr, "\nRun the following to generate a configure script:\n");
	safe_fprintf(stderr, "$ autoreconf --force --install\n");
	return 0;
}

static int
can_generate_pdu_collection(arg_t *arg) {
    abuf *buf = generate_pdu_collection(arg);
    if(!buf) {
        return -1;
    }
    abuf_free(buf);
    return 0;
}

int
asn1c_save_compiled_output(arg_t *arg, const char *datadir, const char *destdir,
                           int argc, int optc, char **argv) {
    int ret = -1;

    const char* example_am_makefile = "Makefile.am.asn1convert";
    const char* program_makefile = "converter-example.mk";
    const char* library_makefile = "Makefile.am.libasncodec";

    /*
     * Early check that we can properly generate PDU collection.
     */
    if(can_generate_pdu_collection(arg) == -1) {
        return -1;
    }

    asn1c_dep_chainset *deps;
    do {
        asn1p_module_t *mod;

        deps = asn1c_read_file_dependencies(arg, datadir);
        if(!deps && datadir) {
            WARNING(
                "Cannot read file-dependencies information "
                "from %s\n",
                datadir);
        }

        TQ_FOR(mod, &(arg->asn->modules), mod_next) {
            TQ_FOR(arg->expr, &(mod->members), next) {
                if(asn1_lang_map[arg->expr->meta_type][arg->expr->expr_type]
                       .type_cb) {
                    ret = asn1c_dump_streams(arg, deps, destdir, optc, argv);
                    if(ret) break;
                }
            }
        }

        /*
         * Dump out the Makefile template and the rest of the support code.
         */
        if((arg->flags & A1C_PRINT_COMPILED)
           || (arg->flags & A1C_OMIT_SUPPORT_CODE)) {
            ret = 0;    /* Success */
            break;
        }

        if(ret) break;

        ret = asn1c__save_library_makefile(arg, deps, datadir, destdir,
                                           library_makefile);
        if(ret) break;

        if(arg->flags & A1C_GEN_EXAMPLE) {
            ret = asn1c__save_example_mk_makefile(arg, deps, datadir, destdir,
                                                  program_makefile,
                                                  library_makefile, argc, argv);
            if(ret) break;
            ret = asn1c__save_example_am_makefile(arg, deps, datadir, destdir,
                                                  example_am_makefile,
                                                  library_makefile, argc, argv);
            if(ret) break;

            if(arg->flags & A1C_GEN_AUTOTOOLS_EXAMPLE) {
                ret = asn1c__save_autotools_example(destdir, example_am_makefile);
                if(ret) break;
            }
        }
    } while(0);

    asn1c_dep_chainset_free(deps);
    asn1c__cleanup_pdu_type();

    return ret;
}

/*
 * Dump the streams.
 */
static int
asn1c_dump_streams(arg_t *arg, asn1c_dep_chainset *deps, const char *destdir,
                   int optc, char **argv) {
    if(arg->flags & A1C_PRINT_COMPILED) {
		return asn1c_print_streams(arg);
	} else {
		return asn1c_save_streams(arg, deps, destdir, optc, argv);
	}
}

static int
asn1c_print_streams(arg_t *arg)  {
	compiler_streams_t *cs = arg->expr->data;
	asn1p_expr_t *expr = arg->expr;
	int i;

	for(i = 1; i < OT_MAX; i++) {
		out_chunk_t *ot;
		if(TQ_FIRST(&cs->destination[i].chunks) == NULL)
			continue;

		printf("\n/*** <<< %s [%s] >>> ***/\n\n",
			_compiler_stream2str[i],
			expr->Identifier);

		TQ_FOR(ot, &(cs->destination[i].chunks), next) {
			safe_fwrite(ot->buf, ot->len, 1, stdout);
		}
	}

	return 0;
}

static int
asn1c_save_streams(arg_t *arg, asn1c_dep_chainset *deps, const char *destdir,
                   int optc, char **argv) {
    asn1p_expr_t *expr = arg->expr;
	compiler_streams_t *cs = expr->data;
	out_chunk_t *ot;
	FILE *fp_c, *fp_h;
	char *tmpname_c, *tmpname_h;
	char name_buf[FILENAME_MAX];
	const char *header_id;
	const char *c_retained = "";
	const char *h_retained = "";
	char *filename;

	if(cs == NULL) {
		safe_fprintf(stderr, "Cannot compile %s at line %d\n",
			expr->Identifier, expr->_lineno);
		return -1;
	}

	filename = strdup(asn1c_make_identifier(AMI_MASK_ONLY_SPACES, expr, (char*)0));
	fp_c = asn1c_open_file(destdir, filename, ".c", &tmpname_c);
    if(fp_c == NULL) {
        return -1;
    }
    fp_h = asn1c_open_file(destdir, filename, ".h", &tmpname_h);
    if(fp_h == NULL) {
        unlink(tmpname_c);
        free(tmpname_c);
        fclose(fp_c);
        return -1;
    }

	generate_preamble(arg, fp_c, optc, argv);
	generate_preamble(arg, fp_h, optc, argv);

	header_id = asn1c_make_identifier(0, expr, NULL);
	safe_fprintf(fp_h,
		"#ifndef\t_%s_H_\n"
		"#define\t_%s_H_\n"
		"\n", header_id, header_id);

	safe_fprintf(fp_h, "\n");
	HINCLUDE("asn_application.h");

#define	SAVE_STREAM(fp, idx, msg, actdep)	do {			\
	if(TQ_FIRST(&(cs->destination[idx].chunks)) && *msg)		\
		safe_fprintf(fp, "\n/* %s */\n", msg);			\
	TQ_FOR(ot, &(cs->destination[idx].chunks), next) {		\
		if(actdep) asn1c_activate_dependency(deps, ot->buf, header_id);	\
		safe_fwrite(ot->buf, ot->len, 1, fp);			\
	}								\
} while(0)

	SAVE_STREAM(fp_h, OT_INCLUDES,	"Including external dependencies", 1);

	safe_fprintf(fp_h, "\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
	SAVE_STREAM(fp_h, OT_DEPS,	"Dependencies", 0);
	SAVE_STREAM(fp_h, OT_FWD_DECLS,	"Forward declarations", 0);
	SAVE_STREAM(fp_h, OT_FWD_DEFS,	"Forward definitions", 0);
	SAVE_STREAM(fp_h, OT_TYPE_DECLS, expr->Identifier, 0);
	SAVE_STREAM(fp_h, OT_FUNC_DECLS,"Implementation", 0);
	safe_fprintf(fp_h, "\n#ifdef __cplusplus\n}\n#endif\n");

	if(!(arg->flags & A1C_NO_INCLUDE_DEPS))
	SAVE_STREAM(fp_h, OT_POST_INCLUDE, "Referred external types", 1);

	safe_fprintf(fp_h, "\n#endif\t/* _%s_H_ */\n", header_id);

	HINCLUDE("asn_internal.h");
	safe_fprintf(fp_c, "#include \"%s.h\"\n\n", filename);
	if(arg->flags & A1C_NO_INCLUDE_DEPS)
		SAVE_STREAM(fp_c, OT_POST_INCLUDE, "", 1);
	TQ_FOR(ot, &(cs->destination[OT_IOC_TABLES].chunks), next)
		safe_fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_CTABLES].chunks), next)
		safe_fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_CODE].chunks), next)
		safe_fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_CTDEFS].chunks), next)
		safe_fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_STAT_DEFS].chunks), next)
		safe_fwrite(ot->buf, ot->len, 1, fp_c);

	assert(OT_MAX == 13);	/* Protection from reckless changes */

	fclose(fp_c);
	fclose(fp_h);

    int ret = snprintf(name_buf, sizeof(name_buf), "%s%s.c", destdir, filename);
    assert(ret > 0 && ret < (ssize_t)sizeof(name_buf));

	if(identical_files(name_buf, tmpname_c)) {
		c_retained = " (contents unchanged)";
		unlink(tmpname_c);
	} else {
		if(rename(tmpname_c, name_buf)) {
			unlink(tmpname_c);
			perror(tmpname_c);
			free(tmpname_c);
			free(tmpname_h);
			return -1;
		}
	}

	sprintf(name_buf, "%s%s.h", destdir, filename);
	if(identical_files(name_buf, tmpname_h)) {
		h_retained = " (contents unchanged)";
		unlink(tmpname_h);
	} else {
		if(rename(tmpname_h, name_buf)) {
			unlink(tmpname_h);
			perror(tmpname_h);
			free(tmpname_c);
			free(tmpname_h);
			return -1;
		}
	}

	free(tmpname_c);
	free(tmpname_h);

	safe_fprintf(stderr, "Compiled %s%s.c%s\n",
		destdir, filename, c_retained);
	safe_fprintf(stderr, "Compiled %s%s.h%s\n",
		destdir, filename, h_retained);
	free(filename);
	return 0;
}

static int
generate_preamble(arg_t *arg, FILE *fp, int optc, char **argv) {
	safe_fprintf(fp,
	"/*\n"
	" * Generated by asn1c-" VERSION " (http://lionet.info/asn1c)\n"
	" * From ASN.1 module \"%s\"\n"
	" * \tfound in \"%s\"\n",
		arg->expr->module->ModuleName,
		arg->expr->module->source_file_name);
	if(optc > 1) {
		int i;
		safe_fprintf(fp, " * \t`asn1c ");
		for(i = 1; i < optc; i++)
			safe_fprintf(fp, "%s%s", i>1?" ":"", argv[i]);
		safe_fprintf(fp, "`\n");
	}
	safe_fprintf(fp, " */\n\n");
	return 0;
}

static int
identical_files(const char *fname1, const char *fname2) {
	char buf[2][4096];
	FILE *fp1, *fp2;
	size_t olen, nlen;
	int retval = 1;	/* Files are identical */

#ifndef	_WIN32
	struct stat sb;

	if(lstat(fname1, &sb) || !S_ISREG(sb.st_mode)
	|| lstat(fname2, &sb) || !S_ISREG(sb.st_mode)) {
		return 0;	/* Files are not identical */
	}
#endif

	fp1 = fopen(fname1, "r");
	if(!fp1) { return 0; }
	fp2 = fopen(fname2, "r");
	if(!fp2) { fclose(fp1); return 0; }

	while((olen = fread(buf[0], 1, sizeof(buf[0]), fp1))) {
		nlen = fread(buf[1], 1, olen, fp2);
		if(nlen != olen || memcmp(buf[0], buf[1], nlen)) {
			retval = 0;
			break;
		}
	}
	nlen = fread(buf[1], 1, 1, fp2);
	if(nlen) retval = 0;

	fclose(fp1);
	fclose(fp2);
	return retval;
}

/*
 * Copy file for real.
 */
static int
real_copy(const char *src, const char *dst) {
	unsigned char buf[4096];
	char *tmpname;
	FILE *fpsrc, *fpdst;
	size_t len;
	int retval = 0;

	if(identical_files(src, dst))
		return retval;	/* Success, no need to copy for real. */

	fpsrc = fopen(src, "r");
	if(!fpsrc) { errno = EIO; return -1; }
	fpdst = asn1c_open_file(NULL, dst, "", &tmpname);
	if(!fpdst) { fclose(fpsrc); errno = EIO; return -1; }

	while(!feof(fpsrc)) {
		len = fread(buf, 1, sizeof(buf), fpsrc);
		if(safe_fwrite(buf, 1, len, fpdst) != len) {
			perror(tmpname);
			errno = EIO;
			retval = -1;
			break;
		}
	}
	fclose(fpsrc);
	fclose(fpdst);

	/* Check if copied correctly, and rename into a permanent name */
	if(retval) {
		unlink(tmpname);
	} else if(rename(tmpname, dst)) {
		unlink(tmpname);
		perror(tmpname);
		retval = -1;
	}
	free(tmpname);
	return retval;
}

static int
asn1c_copy_over(arg_t *arg, const char *destdir, const char *path,
                const char *msg) {
#ifdef	_WIN32
	int use_real_copy = 1;
#else
	int use_real_copy = !(arg->flags & A1C_LINK_SKELETONS);
#endif

	const char *fname = a1c_basename(path, destdir);
	if(!fname
	|| (use_real_copy ? real_copy(path, fname) : symlink(path, fname))
	) {
		if(errno == EEXIST) {
			struct stat sb1, sb2;
			if(stat(path, &sb1) == 0
			&& stat(fname, &sb2) == 0
			&& sb1.st_dev == sb2.st_dev
			&& sb1.st_ino == sb2.st_ino) {
				/*
				 * Nothing to do.
				 */
				safe_fprintf(stderr,
					"File %s is already here as %s\n",
					path, fname);
				return 1;
			} else {
				safe_fprintf(stderr,
					"Retaining local %s (%s suggested)\n",
					fname, path);
				return 1;
			}
		} else if(errno == ENOENT) {
			/* Ignore this */
			return 0;
		} else {
			safe_fprintf(stderr, "%s %s -> %s failed: %s\n",
				use_real_copy ? "Copy" : "Symlink",
				path, fname, strerror(errno));
			return -1;
		}
	}

    const int has_msg = msg && *msg;
    safe_fprintf(stderr, "%s %s\t-> %s%s%s\n",
                 use_real_copy ? "Copied" : "Symlinked", path, fname,
                 has_msg ? " " : "", has_msg ? msg : "");

    return 1;
}


static int
generate_pdu_collection_file(arg_t *arg, const char *destdir) {
    abuf *buf = generate_pdu_collection(arg);
    assert(buf);

    FILE *fp = asn1c_open_file(destdir, "pdu_collection", ".c", 0);
	if(fp == NULL) {
		perror("pdu_collection.c");
		return -1;
	}
    safe_fwrite(buf->buffer, buf->length, 1, fp);
    fclose(fp);

	safe_fprintf(stderr, "Generated pdu_collection.c\n");
    return 0;
}

static abuf *
generate_pdu_collection(arg_t *arg) {
	asn1p_module_t *mod;
    abuf *buf = abuf_new();

    abuf_printf(buf, "/*\n * Generated by asn1c-" VERSION
                     " (http://lionet.info/asn1c)\n */\n\n");
    abuf_printf(buf,
                "struct asn_TYPE_descriptor_s;\t"
                "/* Forward declaration */\n\n");


    TQ_FOR(mod, &(arg->asn->modules), mod_next) {
        TQ_FOR(arg->expr, &(mod->members), next) {
            if(include_type_to_pdu_collection(arg) == TI_NOT_INCLUDED) continue;
            abuf_printf(buf,
                        "extern struct asn_TYPE_descriptor_s "
                        "asn_DEF_%s;\n",
                        asn1c_make_identifier(0, arg->expr, NULL));
        }
    }

    abuf_printf(buf, "\n\n");
	abuf_printf(buf, "struct asn_TYPE_descriptor_s *asn_pdu_collection[] = {\n");
    TQ_FOR(mod, &(arg->asn->modules), mod_next) {
        int mod_printed = 0;
        TQ_FOR(arg->expr, &(mod->members), next) {
            switch(include_type_to_pdu_collection(arg)) {
            case TI_NOT_INCLUDED:
                continue;
            case TI_INCLUDED_FROM_BULK:
                /* Increment */
                asn1c__pdu_type_lookup(arg->expr->Identifier);
                break;
            case TI_INCLUDED_FROM_CMDLINE:
                break;
            }
            if(!mod_printed++) {
                abuf_printf(buf, "\t/* From module %s in %s */\n",
                             arg->expr->module->ModuleName,
                             arg->expr->module->source_file_name);
            }
            abuf_printf(buf, "\t&asn_DEF_%s,\t\n",
                         asn1c_make_identifier(0, arg->expr, NULL));
        }
    }

    abuf_printf(buf, "\t0\n};\n\n");

    if(pdu_collection_has_unused_types(arg)) {
        abuf_free(buf);
        return NULL;
    }

	return buf;
}

static struct PDUType {
	char *typename;
	int used;
} *pduType;
static size_t pduTypes;

static const char *
generate_pdu_C_definition(void) {
    const char *src;
    char *def;
	char *dst;
    if(pduTypes == 0) return "";
    def = malloc(strlen(pduType[0].typename) + 20);
    assert(def);
    strcpy(def, "-DPDU=");
	for(src = pduType[0].typename, dst = def + 6; *src; src++, dst++) {
        if((*dst = *src) == '-') {
            *dst = '_';
        }
    }
    *dst++ = ' ';
    *dst = 0;
    return def;
}

void
asn1c__add_pdu_type(const char *ctypename) {
	char *typename = strdup(ctypename);
	assert(typename && *typename);

	pduType = realloc(pduType, sizeof(pduType[0]) * (pduTypes + 1));
	assert(pduType);
	pduType[pduTypes].used = 0;
	pduType[pduTypes].typename = typename;
	pduTypes++;
}

static void
asn1c__cleanup_pdu_type() {
    for(size_t i = 0; i < pduTypes; i++) {
        free(pduType[i].typename);
    }
    free(pduType);
	pduType = NULL;
    pduTypes = 0;
}

static int
asn1c__pdu_type_lookup(const char *typename) {
    for(size_t i = 0; i < pduTypes; i++) {
        struct PDUType *pt = &pduType[i];
        if(strcmp(pt->typename, typename) == 0) {
            pt->used++;
            return 1;
        }
    }
    return 0;
}

static int
need_to_generate_pdu_collection(arg_t *arg) {
    /* If -pdu=all or -pdu=auto are given, we need to generate one. */
	if(arg->flags & (A1C_PDU_ALL|A1C_PDU_AUTO))
		return 1;

    /*
     * If no -pdu=... flags were given, need to do it, too,
     * effectively producing -pdu=auto.
     */
    if(!(arg->flags & (A1C_PDU_ALL | A1C_PDU_AUTO | A1C_PDU_TYPE))) return 1;

    if(arg->flags & A1C_PDU_TYPE) {
        return (pduTypes > 1) ? 1 : 0;
    }
	return 0;
}

static int
pdu_collection_has_unused_types(arg_t *arg) {
    int ret = 0;

    for(size_t i = 0; i < pduTypes; i++) {
        struct PDUType *pt = &pduType[i];
        if(!pt->used) {
            FATAL("Unknown ASN.1 type specified in -pdu=%s", pt->typename);
            ret = -1;
        }
    }

    return ret;
}

static enum include_type_result
include_type_to_pdu_collection(arg_t *arg) {
    if(!asn1_lang_map[arg->expr->meta_type][arg->expr->expr_type].type_cb)
        return 0;

    /* Parameterized types can't serve as PDU's without instantiation. */
    if(arg->expr->lhs_params) {
        return 0;
    }

    if((arg->flags & A1C_PDU_ALL)
       /* -pdu=auto */
       || ((arg->flags & A1C_PDU_AUTO) && !arg->expr->_type_referenced)
       /* No -pdu=... whatsoever, act as if -pdu=auto */
       || (!(arg->flags & (A1C_PDU_ALL | A1C_PDU_AUTO | A1C_PDU_TYPE))
           && !arg->expr->_type_referenced)
       || asn1c__pdu_type_lookup(arg->expr->Identifier)) {
        return 1;
    }

    return 0;
}
