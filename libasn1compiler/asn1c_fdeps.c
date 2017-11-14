#include "asn1c_internal.h"
#include "asn1c_fdeps.h"

static asn1c_dep_filename *asn1c_dep_filename_new(const char *filename);
static void asn1c_dep_add(asn1c_dep_chain *dlist, const char *filename,
                         int lineno, int column);
static asn1c_dep_chain *asn1c_dep_chain_new(void);

static asn1c_dep_chain *
asn1c_dep_chains_add_new(asn1c_dep_chainset *deps,
                         enum asn1c_dep_section section, int active) {
    asn1c_dep_chain *dc = asn1c_dep_chain_new();
    asn1c_tagged_dep_chain *tc = calloc(1, sizeof(*tc));
    tc->chain = dc;
    tc->section = section;
    tc->activated.active = active;

    deps->chains = realloc(deps->chains,
                           sizeof(deps->chains[0]) * (deps->chains_count + 1));
    assert(deps->chains);
    deps->chains[deps->chains_count] = tc;
    deps->chains_count++;

    return dc;
}

void
asn1c_activate_dependency(asn1c_dep_chainset *deps, const char *data,
                          const char *by) {
    char fname_scratch[PATH_MAX];

    if(!deps || !data || !*data) {
        return;
    }

    assert(deps->chains_count);

    const char *fname = data;
    if(*data == '#') {
        const char *start = data;
        const char *end = 0;

        start = strchr(data, '<');
        if(start) {
            start++;
            end = strchr(start, '>');
        } else if((start = strchr(data, '\"'))) {
            start++;
            end = strchr(start, '\"');
        }
        if(end) {
            assert((end-start) + 1 < (ssize_t)sizeof(fname_scratch));
            memcpy(fname_scratch, start, end - start);
            fname_scratch[end-start] = '\0';
            fname = fname_scratch;
        } else {
            return;
        }
    }

    for(size_t i = 0; i < deps->chains_count; i++) {
        asn1c_tagged_dep_chain *ch = deps->chains[i];
        if(!ch->activated.active && ch->chain->deps_count > 0
           && strcmp(ch->chain->deps[0]->filename, fname) == 0) {
            ch->activated.by = strdup(by);
            ch->activated.active = 1;

            for(size_t j = 0; j < ch->chain->deps_count; j++) {
                asn1c_activate_dependency(deps, ch->chain->deps[j]->filename,
                                          by);
            }
        }
    }
}

asn1c_dep_chainset *
asn1c_read_file_dependencies(arg_t *arg, const char *datadir) {
	char buf[4096];
	asn1c_dep_chainset *deps;
	FILE *f;
    int lineno = 0;

	if(!datadir || strlen(datadir) > sizeof(buf) / 2) {
		errno = EINVAL;
		return NULL;
	} else {
		sprintf(buf, "%s/file-dependencies", datadir);
	}

	f = fopen(buf, "r");
	if(!f) return NULL;

	deps = calloc(1, sizeof(*deps));
	assert(deps);
    enum asn1c_dep_section section = FDEP_COMMON_FILES;
    int activate = 0;

    while(fgets(buf, sizeof(buf), f)) {
		char *p = strchr(buf, '#');
		if(p) *p = '\0';	/* Remove comments */

        lineno++;

        asn1c_dep_chain *dc = asn1c_dep_chains_add_new(deps, section, activate);

        for(p = strtok(buf, " \t\r\n"); p;
				p = strtok(NULL, " \t\r\n")) {

			/*
			 * Special "prefix" section.
			 */
			if(strchr(p, ':')) {
				if(strcmp(p, "COMMON-FILES:") == 0) {
					section = FDEP_COMMON_FILES;
                    activate = 1;
				} else if(strcmp(p, "CONVERTER:") == 0) {
                    activate = 1;
					section = FDEP_CONVERTER;
				} else if((arg->flags & A1C_GEN_OER)
					  && strcmp(p, "CODEC-OER:") == 0) {
                    activate = 0;
					section = FDEP_CODEC_OER;
				} else if((arg->flags & A1C_GEN_PER)
					  && strcmp(p, "CODEC-PER:") == 0) {
                    activate = 0;
					section = FDEP_CODEC_PER;
				} else {
					section = FDEP_IGNORE;
                    activate = 0;
                }
                break;
			}

            asn1c_dep_add(dc, p, lineno, p - buf);
        }
	}

	fclose(f);

    /* A single filename by itself means that we should include that */
    for(size_t i = 0; i < deps->chains_count; i++) {
        asn1c_tagged_dep_chain *ch = deps->chains[i];
        if(!ch->activated.active && ch->chain->deps_count == 1) {
            asn1c_activate_dependency(deps, ch->chain->deps[0]->filename,
                                      "implicit");
        }
    }

	return deps;
}

static asn1c_dep_filename *
asn1c_dep_filename_new(const char *filename) {
    asn1c_dep_filename *d;

    assert(filename);

    d = calloc(1, sizeof(*d));
    assert(d);
    d->filename = strdup(filename);
    assert(d->filename);

	return d;
}

static asn1c_dep_chain *
asn1c_dep_chain_new() {
    return calloc(1, sizeof(asn1c_dep_chain));
}

static void
asn1c_dep_add(asn1c_dep_chain *dlist, const char *filename, int lineno, int column) {
    asn1c_dep_filename *df = asn1c_dep_filename_new(filename);
    df->lineno = lineno;
    df->column = column;

    dlist->deps =
        realloc(dlist->deps, (dlist->deps_count + 1) * sizeof(dlist->deps[0]));
    assert(dlist->deps);
    dlist->deps[dlist->deps_count] = df;
    dlist->deps_count += 1;
}

static int
asn1c_dep_has_filename(const asn1c_dep_chain *dlist, const char *filename) {
    for(size_t i = 0; i < dlist->deps_count; i++) {
        if(strcmp(dlist->deps[i]->filename, filename) == 0) {
            return 1;
        }
    }
    return 0;
}

asn1c_dep_chain *
asn1c_deps_flatten(const asn1c_dep_chainset *deps,
                   enum asn1c_dep_section include_section) {
    asn1c_dep_chain *dlist;

	if(!deps) {
		errno = EINVAL;
		return 0;
	}

	dlist = asn1c_dep_chain_new();

	for(size_t i = 0; i < deps->chains_count; i++) {
        asn1c_tagged_dep_chain *tc = deps->chains[i];
        asn1c_dep_chain *dc = tc->chain;

        if(!tc->activated.active) {
            continue;
        }
        if((tc->section & include_section) == 0) {
            continue;
        }

        for(size_t j = 0; j < dc->deps_count; j++) {
            if(!asn1c_dep_has_filename(dlist, dc->deps[j]->filename))  {
                asn1c_dep_add(dlist, dc->deps[j]->filename, dc->deps[j]->lineno,
                              dc->deps[j]->column);
            }
        }
    }

	return dlist;
}

void
asn1c_dep_chain_free(asn1c_dep_chain *dc) {
    if(dc) {
        for(size_t i = 0; i < dc->deps_count; i++) {
            asn1c_dep_filename *df = dc->deps[i];
            free(df->filename);
            free(df);
        }
        free(dc->deps);
    }
}

void
asn1c_dep_chainset_free(asn1c_dep_chainset *deps) {
	if(deps) {
        for(size_t i = 0; i < deps->chains_count; i++) {
            asn1c_dep_chain_free(deps->chains[i]->chain);
            free(deps->chains[i]->activated.by);
            free(deps->chains[i]);
        }
        free(deps->chains);
        free(deps);
    }
}
