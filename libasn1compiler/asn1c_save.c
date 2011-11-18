#include "asn1c_internal.h"
#include "asn1c_compat.h"
#include "asn1c_fdeps.h"
#include "asn1c_lang.h"
#include "asn1c_misc.h"
#include "asn1c_save.h"
#include "asn1c_out.h"
#include "asn1c_oid.c"

#define	HINCLUDE(s)						\
	((arg->flags & A1C_INCLUDES_QUOTED)			\
		? fprintf(fp_h, "#include \"%s\"\n", s)		\
		: fprintf(fp_h, "#include <%s>\n", s))		\

static int asn1c_dump_streams(arg_t *arg, asn1c_fdeps_t *, int, char **);
static int asn1c_print_streams(arg_t *arg);
static int asn1c_save_streams(arg_t *arg, asn1c_fdeps_t *, int, char **);
static int asn1c_copy_over(arg_t *arg, char *path);
static int identical_files(const char *fname1, const char *fname2);
static int need_to_generate_pdu_collection(arg_t *arg);
static int generate_pdu_collection_file(arg_t *arg);
static int generate_preamble(asn1p_module_t *, FILE *, int optc, char **argv);
static int include_type_to_pdu_collection(arg_t *arg);
static void pdu_collection_print_unused_types(arg_t *arg);
static const char *generate_pdu_C_definition(void);

static int asn1c_create_module_files(arg_t *arg, asn1p_module_t *mod,
	int optc, char **argv);
static int asn1c_finish_module_files(arg_t *arg, asn1p_module_t *mod,
	int optc, char **argv);
static int asn1c_save_value_streams(arg_t *arg, asn1c_fdeps_t *deps,
	int optc, char **argv);

int
asn1c_save_compiled_output(arg_t *arg, const char *datadir,
		int argc, int optc, char **argv) {
	asn1c_fdeps_t *deps = 0;
	asn1c_fdeps_t *dlist;
	asn1p_module_t *mod;
	FILE *mkf;	/* Makefile.am.sample */
	int i;
	enum {
		MODULE_OMITTED,
		MODULE_EMITTED
	} module_emitted = MODULE_OMITTED;

	deps = asn1c_read_file_dependencies(arg, datadir);
	if(!deps && datadir) {
		WARNING("Cannot read file-dependencies information "
			"from %s\n", datadir);
	}

	if(!(arg->flags & A1C_PRINT_COMPILED)) {
		TQ_FOR(mod, &(arg->asn->modules), mod_next) {
			if(asn1c_create_module_files(arg, mod, optc, argv))
				return -1;
		}
	}

	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		TQ_FOR(arg->expr, &(mod->members), next) {
			if(asn1_lang_map[arg->expr->meta_type]
				[arg->expr->expr_type].type_cb) {
				if(asn1c_dump_streams(arg, deps, optc, argv))
					return -1;
			}
		}
	}

	if(!(arg->flags & A1C_PRINT_COMPILED)) {
		TQ_FOR(mod, &(arg->asn->modules), mod_next) {
			if(asn1c_finish_module_files(arg, mod, optc, argv))
				return -1;
		}
	}

	/*
	 * Dump out the Makefile template and the rest of the support code.
	 */
	if((arg->flags & A1C_PRINT_COMPILED)
	|| (arg->flags & A1C_OMIT_SUPPORT_CODE)) {
		return 0;	/* Finished */
	}

	mkf = asn1c_open_file("Makefile.am", ".sample", 0);
	if(mkf == NULL) {
		perror("Makefile.am.sample");
		return -1;
	}

	/*
	 * Add module files to the sources when any values are present,
	 * or when A1C_MODULE_OIDS is present.
	 */

	fprintf(mkf, "ASN_MODULE_SOURCES=");
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		if(mod->_tags & MT_STANDARD_MODULE)
			continue;

		if(arg->flags & A1C_MODULE_OIDS) {
			/* emit module oid header, and mark as emitted */
			fprintf(mkf, "\t\\\n\t%s.c", mod->ModuleName);

			module_emitted = MODULE_EMITTED;
		} else {
			module_emitted = MODULE_OMITTED;
		}

		TQ_FOR(arg->expr, &(mod->members), next) {
			if(asn1_lang_map[arg->expr->meta_type]
				[arg->expr->expr_type].type_cb) {
				if(arg->expr->meta_type == AMT_VALUE) {
					assert(mod == arg->expr->module);
					if(module_emitted == MODULE_OMITTED) {
						/*
						 * we found a new module, so emit it
						 * but note that if A1C_MODULE_OIDS is present, the expectation
						 * is that we've already emitted this module
						 */
						assert(!(arg->flags & A1C_MODULE_OIDS));
						fprintf(mkf, "\t\\\n\t%s.c", mod->ModuleName);
						module_emitted = MODULE_EMITTED;
					}
				} else {
					fprintf(mkf, "\t\\\n\t%s.c",
					arg->expr->Identifier);
				}
			}
		}
	}
	
	fprintf(mkf, "\n\nASN_MODULE_HEADERS=");
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		if(mod->_tags & MT_STANDARD_MODULE)
			continue;

		if(arg->flags & A1C_MODULE_OIDS) {
			fprintf(mkf, "\t\\\n\t%s.h", mod->ModuleName);

			module_emitted = MODULE_EMITTED;
		} else {
			module_emitted = MODULE_OMITTED;
		}

		TQ_FOR(arg->expr, &(mod->members), next) {
			if(asn1_lang_map[arg->expr->meta_type]
				[arg->expr->expr_type].type_cb) {
				if(arg->expr->meta_type == AMT_VALUE) {
					assert(mod == arg->expr->module);
					if(module_emitted == MODULE_OMITTED) {
						assert(!(arg->flags & A1C_MODULE_OIDS));
						fprintf(mkf, "\t\\\n\t%s.h", mod->ModuleName);
						module_emitted = MODULE_EMITTED;
					}
				} else {
					fprintf(mkf, "\t\\\n\t%s.h",
					arg->expr->Identifier);
				}
			}
		}
	}
	fprintf(mkf, "\n\n");

	/*
	 * Move necessary skeleton files and add them to Makefile.am.sample.
	 */
	dlist = asn1c_deps_makelist(deps);
	if(dlist) {
		char buf[8129];
		char *dir_end;
		size_t dlen = strlen(datadir);

		assert(dlen < (sizeof(buf) / 2 - 2));
		memcpy(buf, datadir, dlen);
		dir_end = buf + dlen;
		*dir_end++ = '/';

		for(i = 0; i < dlist->el_count; i++) {
			char *what_class;	/* MODULE or CONVERTER */
			char *what_kind;	/* HEADERS or SOURCES */
			char *fname = dlist->elements[i]->filename;
			char *dotH;

			assert(strlen(fname) < (sizeof(buf) / 2));
			strcpy(dir_end, fname);

			if(asn1c_copy_over(arg, buf) == -1) {
				fprintf(mkf, ">>>ABORTED<<<");
				fclose(mkf);
				return -1;
			}

			/* MODULE data versus CONVERTER data */
			switch(dlist->elements[i]->usage) {
			case FDEP_CONVERTER: what_class = "CONVERTER"; break;
			default: what_class= "MODULE"; break;
			}

			/* HEADERS versus SOURCES */
			dotH = strrchr(fname, 'h');
			if(dotH && fname<dotH && dotH[-1] == '.' && !dotH[1])
				what_kind = "HEADERS";
			else
				what_kind = "SOURCES";
			fprintf(mkf, "ASN_%s_%s+=%s\n",
				what_class, what_kind, fname);
		}
	}

	if(need_to_generate_pdu_collection(arg)) {
		fprintf(mkf, "ASN_CONVERTER_SOURCES+=pdu_collection.c\n");
		if(generate_pdu_collection_file(arg))
			return -1;
	}

	fprintf(mkf, "\n\n"
		"lib_LTLIBRARIES=libsomething.la\n"
		"libsomething_la_SOURCES="
			"$(ASN_MODULE_SOURCES) $(ASN_MODULE_HEADERS)\n"
		"\n"
		"# This file may be used as an input for make(3)\n"
		"# Remove the lines below to convert it into a pure .am file\n"
		"TARGET = progname\n"
		"CFLAGS +=%s%s -I.\n"
		"OBJS=${ASN_MODULE_SOURCES:.c=.o}"
		  " ${ASN_CONVERTER_SOURCES:.c=.o}\n"
		"\nall: $(TARGET)\n"
		"\n$(TARGET): ${OBJS}"
		"\n\t$(CC) $(CFLAGS) -o $(TARGET) ${OBJS} $(LDFLAGS) $(LIBS)\n"
		"\n.SUFFIXES:"
		"\n.SUFFIXES: .c .o\n"
		"\n.c.o:"
		"\n\t$(CC) $(CFLAGS) -o $@ -c $<\n"
		"\nclean:"
		"\n\trm -f $(TARGET)"
		"\n\trm -f $(OBJS)\n"
		"\nregen: regenerate-from-asn1-source\n"
		"\nregenerate-from-asn1-source:\n\t"
		, (arg->flags & A1C_PDU_TYPE)
			? generate_pdu_C_definition() : ""
		, need_to_generate_pdu_collection(arg)
			? " -DASN_PDU_COLLECTION" : ""
	);

	for(i = 0; i < argc; i++)
		fprintf(mkf, "%s%s", i ? " " : "", argv[i]);
	fprintf(mkf, "\n\n");

	fclose(mkf);
	fprintf(stderr, "Generated Makefile.am.sample\n");

	return 0;
}

/*
 * Dump the streams.
 */
static int
asn1c_dump_streams(arg_t *arg, asn1c_fdeps_t *deps, int optc, char **argv)  {
	if(arg->flags & A1C_PRINT_COMPILED) {
		return asn1c_print_streams(arg);
	} else {
		return asn1c_save_streams(arg, deps, optc, argv);
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
			fwrite(ot->buf, ot->len, 1, stdout);
		}
	}

	return 0;
}

static int
asn1c_save_streams(arg_t *arg, asn1c_fdeps_t *deps, int optc, char **argv) {
	asn1p_expr_t *expr = arg->expr;
	compiler_streams_t *cs = expr->data;
	out_chunk_t *ot;
	FILE *fp_c, *fp_h;
	char *tmpname_c, *tmpname_h;
	char *name_buf;
	char *header_id;
	const char *c_retained = "";
	const char *h_retained = "";

	if(cs == NULL) {
		fprintf(stderr, "Cannot compile %s at line %d\n",
			expr->Identifier, expr->_lineno);
		return -1;
	}
	
	if(expr->meta_type == AMT_VALUE)
		return asn1c_save_value_streams(arg, deps, optc, argv);

	fp_c = asn1c_open_file(expr->Identifier, ".c", &tmpname_c);
	fp_h = asn1c_open_file(expr->Identifier, ".h", &tmpname_h);
	if(fp_c == NULL || fp_h == NULL) {
		if(fp_c) { unlink(tmpname_c); free(tmpname_c); fclose(fp_c); }
		if(fp_h) { unlink(tmpname_h); free(tmpname_h); fclose(fp_h); }
		return -1;
	}

	generate_preamble(expr->module, fp_c, optc, argv);
	generate_preamble(expr->module, fp_h, optc, argv);

	header_id = asn1c_make_identifier(0, expr, NULL);
	fprintf(fp_h,
		"#ifndef\t_%s_H_\n"
		"#define\t_%s_H_\n"
		"\n", header_id, header_id);

	fprintf(fp_h, "\n");
	HINCLUDE("asn_application.h");

#define	SAVE_STREAM(fp, idx, msg, actdep)	do {			\
	if(TQ_FIRST(&(cs->destination[idx].chunks)) && *msg)		\
		fprintf(fp, "\n/* %s */\n", msg);			\
	TQ_FOR(ot, &(cs->destination[idx].chunks), next) {		\
		if(actdep) asn1c_activate_dependency(deps, 0, ot->buf);	\
		fwrite(ot->buf, ot->len, 1, fp);			\
	}								\
} while(0)

	SAVE_STREAM(fp_h, OT_INCLUDES,	"Including external dependencies", 1);

	fprintf(fp_h, "\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
	SAVE_STREAM(fp_h, OT_DEPS,	"Dependencies", 0);
	SAVE_STREAM(fp_h, OT_FWD_DECLS,	"Forward declarations", 0);
	SAVE_STREAM(fp_h, OT_TYPE_DECLS, expr->Identifier, 0);
	SAVE_STREAM(fp_h, OT_FUNC_DECLS,"Implementation", 0);
	fprintf(fp_h, "\n#ifdef __cplusplus\n}\n#endif\n");

	if(!(arg->flags & A1C_NO_INCLUDE_DEPS))
	SAVE_STREAM(fp_h, OT_POST_INCLUDE, "Referred external types", 1);

	fprintf(fp_h, "\n#endif\t/* _%s_H_ */\n", header_id);

	HINCLUDE("asn_internal.h");
	fprintf(fp_c, "#include \"%s.h\"\n\n", expr->Identifier);
	if(arg->flags & A1C_NO_INCLUDE_DEPS)
		SAVE_STREAM(fp_c, OT_POST_INCLUDE, "", 1);
	TQ_FOR(ot, &(cs->destination[OT_CTABLES].chunks), next)
		fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_CODE].chunks), next)
		fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_CTDEFS].chunks), next)
		fwrite(ot->buf, ot->len, 1, fp_c);
	TQ_FOR(ot, &(cs->destination[OT_STAT_DEFS].chunks), next)
		fwrite(ot->buf, ot->len, 1, fp_c);

	assert(OT_MAX == 11);	/* Protection from reckless changes */

	fclose(fp_c);
	fclose(fp_h);

	name_buf = alloca(strlen(expr->Identifier) + 3);

	sprintf(name_buf, "%s.c", expr->Identifier);
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

	sprintf(name_buf, "%s.h", expr->Identifier);
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

	fprintf(stderr, "Compiled %s.c%s\n",
		expr->Identifier, c_retained);
	fprintf(stderr, "Compiled %s.h%s\n",
		expr->Identifier, h_retained);
	return 0;
}

static int
generate_preamble(asn1p_module_t *mod, FILE *fp, int optc, char **argv) {
	assert(mod);
	fprintf(fp,
	"/*\n"
	" * Generated by asn1c-" VERSION " <http://lionet.info/asn1c/>\n"
	" * From ASN.1 module \"%s\"\n"
	" * \tfound in \"%s\"\n",
		mod->ModuleName,
		mod->source_file_name);
	if(optc > 1) {
		int i;
		fprintf(fp, " * \t`asn1c ");
		for(i = 1; i < optc; i++)
			fprintf(fp, "%s%s", i>1?" ":"", argv[i]);
		fprintf(fp, "`\n");
	}
	fprintf(fp, " */\n\n");
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
	fpdst = asn1c_open_file(dst, "", &tmpname);
	if(!fpdst) { fclose(fpsrc); errno = EIO; return -1; }

	while(!feof(fpsrc)) {
		len = fread(buf, 1, sizeof(buf), fpsrc);
		if(fwrite(buf, 1, len, fpdst) != len) {
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
asn1c_copy_over(arg_t *arg, char *path) {
	char *fname;
#ifdef	_WIN32
	int use_real_copy = 1;
#else
	int use_real_copy = (arg->flags & A1C_SKELETONS_COPY);
#endif

	fname = a1c_basename(path);
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
				fprintf(stderr,
					"File %s is already here as %s\n",
					path, fname);
				return 1;
			} else {
				fprintf(stderr,
					"Retaining local %s (%s suggested)\n",
					fname, path);
				return 1;
			}
		} else if(errno == ENOENT) {
			/* Ignore this */
			return 0;
		} else {
			fprintf(stderr, "%s %s -> %s failed: %s\n",
				use_real_copy ? "Copy" : "Symlink",
				path, fname, strerror(errno));
			return -1;
		}
	}

	fprintf(stderr, "%s %s\t-> %s\n",
		use_real_copy ? "Copied" : "Symlinked", path, fname);

	return 1;
}


static int
generate_pdu_collection_file(arg_t *arg) {
	asn1p_module_t *mod;
	FILE *fp;

	fp = asn1c_open_file("pdu_collection", ".c", 0);
	if(fp == NULL) {
		perror("pdu_collection.c");
		return -1;
	}

	fprintf(fp,
		"/*\n"
		" * Generated by asn1c-" VERSION " (http://lionet.info/asn1c)\n"
		" */\n\n");
	fprintf(fp, "struct asn_TYPE_descriptor_s;\t"
			"/* Forward declaration */\n\n");

	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		TQ_FOR(arg->expr, &(mod->members), next) {
			if(!include_type_to_pdu_collection(arg))
				continue;
			fprintf(fp, "extern struct asn_TYPE_descriptor_s "
				"asn_DEF_%s;\n",
				asn1c_make_identifier(0, arg->expr, NULL));
		}
	}

	fprintf(fp, "\n\n");
	fprintf(fp, "struct asn_TYPE_descriptor_s *asn_pdu_collection[] = {\n");
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		int mod_printed = 0;
		TQ_FOR(arg->expr, &(mod->members), next) {
			if(!include_type_to_pdu_collection(arg))
				continue;
			if(!mod_printed++)
			fprintf(fp, "\t/* From module %s in %s */\n",
				arg->expr->module->ModuleName,
				arg->expr->module->source_file_name);
			fprintf(fp, "\t&asn_DEF_%s,\t\n",
				asn1c_make_identifier(0, arg->expr, NULL));
		}
	}

	fprintf(fp, "\t0\n};\n\n");

	pdu_collection_print_unused_types(arg);

	fclose(fp);
	fprintf(stderr, "Generated pdu_collection.c\n");

	return 0;
}

static struct PDUType {
	char *typename;
	int used;
} *pduType;
static int pduTypes;

static const char *
generate_pdu_C_definition(void) {
	const char *src;
	char *def;
	char *dst;
	if(pduTypes == 0) return "";
	def = malloc(strlen(pduType[0].typename) + 20);
	strcpy(def, " -DPDU=");
	for(src = pduType[0].typename, dst = def + 7; *src; src++, dst++)
		if((*dst = *src) == '-')
			*dst = '_';
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

static int
asn1c__pdu_type_lookup(const char *typename) {
	int i;
	for(i = 0; i < pduTypes; i++) {
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
	if(arg->flags & (A1C_PDU_ALL|A1C_PDU_AUTO))
		return 1;
	if(arg->flags & A1C_PDU_TYPE)
		return (pduTypes > 1) ? 1 : 0;
	return 0;
}

static void
pdu_collection_print_unused_types(arg_t *arg) {
	int i;
	for(i = 0; i < pduTypes; i++) {
		struct PDUType *pt = &pduType[i];
		if(!pt->used) {
			WARNING("Missing type specified in -pdu=%s",
				pt->typename);
		}
	}
}

static int
include_type_to_pdu_collection(arg_t *arg) {
	if(!asn1_lang_map[arg->expr->meta_type]
		[arg->expr->expr_type].type_cb)
		return 0;

	if((arg->flags & A1C_PDU_ALL)
	|| ((arg->flags & A1C_PDU_AUTO) && !arg->expr->_type_referenced)
	|| asn1c__pdu_type_lookup(arg->expr->Identifier)) {
		return 1;
	}

	return 0;
}

/* Value output code contributed by Sean Leonard of SeanTek(R). */


static void
asn1c_file_out_oid(asn1p_module_t *mod, FILE *fp) {
	size_t accum = 3;
	int ac;
	asn1p_oid_t *oid = mod->module_oid;

	fprintf(fp, "/* {");
	for(ac = 0; ac < oid->arcs_count; ac++) {
		const char *arcname = oid->arcs[ac].name;
		const char *arcnumber = oid->arcs[ac].number;

		if(accum + strlen(arcname ? arcname : "") > 72) {
			fprintf(fp, "\n   ");
			accum = 3;
		} else if(ac != 0) {
			accum += fprintf(fp, " ");
		}

		if(arcname) {
			accum += fprintf(fp, "%s", arcname);
			if(arcnumber) {
				accum += fprintf(fp, "(%s)", arcnumber);
			}
		} else {
			accum += fprintf(fp, "%s", arcnumber);
		}
	}
	fprintf(fp, "} */\n");
}

static int
asn1c_file_out_ber(arg_t *arg, asn1p_module_t *mod, FILE *fp) {
	uint8_t *ber = NULL;
	size_t ber_len = 0;
	size_t ber_i;
	int res;
	arg_t temp_arg = {arg->flags, arg->logger_cb, arg->default_cb};
	asn1p_expr_t temp_expr = {mod->ModuleName, AMT_VALUE, ASN_BASIC_OBJECT_IDENTIFIER};
	asn1p_value_t temp_value = {ATV_OBJECT_IDENTIFIER};

	temp_arg.expr = &temp_expr;
	temp_arg.asn = arg->asn;
	/* target and embed set to 0 on purpose */
	
	temp_expr.value = &temp_value;
	temp_expr.module = mod;

	temp_value.value.oid = mod->module_oid;

	res = asn1c_oid_ber_encode(&temp_arg, &ber, &ber_len);
	if(res)
		return res;
	
	if(!ber_len) {
		free(ber);
		return 0;
	}
	
	fprintf(fp, "0x%02X", ber[0]);
	for (ber_i = 1; ber_i < ber_len; ber_i++) {
		fprintf(fp, ", 0x%02X", ber[ber_i]);
	}

	free(ber);
	return 0;
}


static int asn1c_create_module_files(arg_t *arg, asn1p_module_t *mod,
	int optc, char **argv) {
	FILE *fp_c, *fp_h;
	char *header_id; /* for file name */
	asn1p_expr_t *expr;
	const char *mod_symbol_id; /* for C */
	unsigned char has_values[ASN_EXPR_TYPE_MAX] = {0};
	char has_a_value = 0;
	size_t i;
	char **referenced_names;

	if(mod->_tags & MT_STANDARD_MODULE)
		return 0;

	TQ_FOR(expr, &(mod->members), next) {
		if(expr->meta_type == AMT_VALUE && expr->expr_type < ASN_EXPR_TYPE_MAX) {
				has_values[expr->expr_type] = 1;
				has_a_value = 1;
		}
	}

	/* implies has_a_value without needing to check for it */
	if(arg->flags & A1C_MODULE_OIDS)
		has_values[ASN_BASIC_OBJECT_IDENTIFIER] = 1;
	else if(!has_a_value)
		return 0;

	fp_c = asn1c_open_file(mod->ModuleName, ".c", NULL);
	fp_h = asn1c_open_file(mod->ModuleName, ".h", NULL);
	
	if(fp_c == NULL || fp_h == NULL) {
		if(fp_c) { fclose(fp_c); }
		if(fp_h) { fclose(fp_h); }
		return -1;
	}

	generate_preamble(mod, fp_c, optc, argv);
	generate_preamble(mod, fp_h, optc, argv);

	header_id = asn1c_make_identifier(0, NULL, mod->ModuleName, NULL);
	fprintf(fp_h,
		"#ifndef\t_%s_H_\n"
		"#define\t_%s_H_\n"
		"\n\n", header_id, header_id);
	
	HINCLUDE("asn_application.h");

	/* Compare with GEN_INCLUDE in asn1c_out.h/asn1c_C.c */
	for(i = 0; i < ASN_EXPR_TYPE_MAX; i++) {
		if(has_values[i]) {
			char *identifier_file_name = asn1c_make_identifier(
				AMI_MASK_ONLY_SPACES | AMI_NODELIMITER, NULL,
				ASN_EXPR_TYPE2STR(i), ".h", NULL);

			/* the identifier file name may not exist, such as for A1TC_REFERENCE */
			if(identifier_file_name) {
				HINCLUDE(identifier_file_name);
			}
		}
	}

	/* include any referenced types */
	referenced_names = calloc(10, sizeof(*referenced_names));
	i = 0;
	TQ_FOR(expr, &(mod->members), next) {
		if(expr->meta_type == AMT_VALUE && expr->expr_type == A1TC_REFERENCE) {
			char *refname, *identifier_file_name;
			assert(expr->reference && expr->reference->comp_count == 1);
			assert(expr->reference->components && expr->reference->components[0].name);
			refname = expr->reference->components[0].name;
			for(i = 0; referenced_names[i] && !!strcmp(referenced_names[i], refname); i++);
			if(!referenced_names[i]) {
				/* First, emit Including external dependencies */
				if(i == 0)
					fprintf(fp_h, "\n/* Including external dependencies */\n");

				/* TODO: confirm that this is the right way to create the name */
				identifier_file_name = asn1c_make_identifier(
					AMI_MASK_ONLY_SPACES | AMI_NODELIMITER, NULL,
					refname, ".h", NULL);
				assert(identifier_file_name);

				/*
				 * Do not use HINCLUDE(identifier_file_name);
				 * instead, use quotation marks all the time (because these types are local).
				 */
				fprintf(fp_h, "#include \"%s\"\n", identifier_file_name);

				/* add to list of already-emitted names */
				referenced_names = realloc(referenced_names, sizeof(*referenced_names) * (i+2));
				if(!referenced_names)
					return -1; /* out of memory */

				referenced_names[i++] = refname;
				referenced_names[i] = NULL;
			}
		}
	}

	free(referenced_names);
	referenced_names = NULL; /* safety */

	fprintf(fp_h, "\n#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n");
	
	fprintf(fp_c, "#include \"%s.h\"\n\n", mod->ModuleName);
	
	/* not all gcc variations (such as on OS X 10.6) support diagnostic push */
	/* fprintf(fp_c, "%s", "#ifdef __GNUC__\n"
		"#pragma GCC diagnostic warning \"-Wno-cast-qual\"\n#endif\n\n"); */
	
	if(arg->flags & A1C_MODULE_OIDS) {
		/* Compare with MKID and out_name_chain */
		mod_symbol_id = asn1c_make_identifier(AMI_NODELIMITER,
			NULL, mod->ModuleName, NULL);

		asn1c_file_out_oid(mod, fp_h);

		fprintf(fp_h, "extern const OBJECT_IDENTIFIER_t %s;\n", mod_symbol_id);

		fprintf(fp_c, "static const uint8_t DEF_%s[] = {", mod_symbol_id);
		if(asn1c_file_out_ber(arg, mod, fp_c)) {
			fclose(fp_c);
			fclose(fp_h);
			return -1;
		}
		fprintf(fp_c, "};\n");

		asn1c_file_out_oid(mod, fp_c);

		fprintf(fp_c, "const OBJECT_IDENTIFIER_t %s = {(uint8_t*)(size_t)DEF_%s, sizeof(DEF_%s)}",
			mod_symbol_id, mod_symbol_id, mod_symbol_id);
		fprintf(fp_c, ";\n");
	}

	fclose(fp_c);
	fclose(fp_h);
	
	return 0;
}

static int asn1c_finish_module_files(arg_t *arg, asn1p_module_t *mod,
	int optc, char **argv) {
	FILE *fp_c, *fp_h;
	char *header_id;
	asn1p_expr_t *expr;
	char has_a_value = 0;

	if(mod->_tags & MT_STANDARD_MODULE)
		return 0;

	/* don't finish the module files if there are no values */
	if(!(arg->flags & A1C_MODULE_OIDS)) {
		TQ_FOR(expr, &(mod->members), next) {
			if(expr->meta_type == AMT_VALUE && expr->expr_type < ASN_EXPR_TYPE_MAX) {
					has_a_value = 1;
					break;
			}
		}
		if(!has_a_value)
			return 0;
	}

	fp_h = asn1c_append_file(mod->ModuleName, ".h");
	fp_c = asn1c_append_file(mod->ModuleName, ".c");
	
	if(fp_h == NULL || fp_c == NULL) {
		if(fp_h) { fclose(fp_h); }
		if(fp_c) { fclose(fp_c); }
		return -1;
	}
	
	header_id = asn1c_make_identifier(0, NULL, mod->ModuleName, NULL);

	fprintf(fp_h, "\n#ifdef __cplusplus\n}\n#endif\n");

	fprintf(fp_h, "\n#endif\t/* _%s_H_ */\n", header_id);
	HINCLUDE("asn_internal.h");
	
	/* not all compilers support diagnostic pop */
	/* fputs("\n#ifdef __GNUC__\n#pragma GCC diagnostic pop\n#endif", fp_c); */
	
	fclose(fp_h);
	fclose(fp_c);

	/* the module files do not record whether they were retained at this time */
	fprintf(stderr, "Compiled %s.c\n",
		mod->ModuleName);
	fprintf(stderr, "Compiled %s.h\n",
		mod->ModuleName);

	return 0;
}

static int
asn1c_save_value_streams(arg_t *arg, asn1c_fdeps_t *deps, int optc, char **argv) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_module_t *mod = expr->module;
	compiler_streams_t *cs = expr->data;
	out_chunk_t *ot;
	FILE *fp_c, *fp_h;

	assert(expr && mod && expr->meta_type == AMT_VALUE);

	if(mod->_tags & MT_STANDARD_MODULE)
		return 0;

	fp_c = asn1c_append_file(mod->ModuleName, ".c");
	fp_h = asn1c_append_file(mod->ModuleName, ".h");
	
	if(fp_c == NULL || fp_h == NULL) {
		if(fp_c) { fclose(fp_c); }
		if(fp_h) { fclose(fp_h); }
		return -1;
	}
	
	/* SAVE_STREAM(fp_h, OT_INCLUDES, "Including external dependencies", 1); */
	/* if(TQ_FIRST(&(cs->destination[OT_INCLUDES].chunks)) && 1)
		fprintf(fp_h, "\n/ * %s * /\n", "Including external dependencies"); */
/*	TQ_FOR(ot, &(cs->destination[OT_INCLUDES].chunks), next) { */
	for((ot) = TQ_FIRST(&(cs->destination[OT_INCLUDES].chunks));
		(ot); (ot) = ot->next.tq_next) {

		/* if(1) */ asn1c_activate_dependency(deps, 0, ot->buf);
		/* fwrite(ot->buf, ot->len, 1, fp_h); */
	}

	SAVE_STREAM(fp_h, OT_FUNC_DECLS, "", 0);
	
	SAVE_STREAM(fp_c, OT_STAT_DEFS, "", 0);

	fclose(fp_c);
	fclose(fp_h);
	return 0;
}

