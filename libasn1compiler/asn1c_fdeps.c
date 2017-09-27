#include "asn1c_internal.h"
#include "asn1c_fdeps.h"

static asn1c_fdeps_t *asn1c_new_dep(const char *filename);
static int asn1c_dep_add(asn1c_fdeps_t *deps, asn1c_fdeps_t *d);

int
asn1c_activate_dependency(asn1c_fdeps_t *deps, asn1c_fdeps_t *cur, const char *data) {
	const char *fname;
	int i;

	if(!deps || !data || !*data)
		return 0;
	if(!cur) cur = deps;

	if(cur->usage > FDEP_NOTUSED)
		return 1;	/* Already activated */

	fname = data;
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
			char *p = alloca((end - start) + 1);
			memcpy(p, start, end - start);
			p[end-start] = '\0';
			fname = p;
		} else {
			return 0;
		}
	}

	if(cur->filename && strcmp(cur->filename, fname) == 0) {
		cur->usage = FDEP_REFERRED;

		/* Activate subdependencies */
		for(i = 0; i < cur->el_count; i++) {
			asn1c_activate_dependency(deps,
				cur->elements[i],
				cur->elements[i]->filename);
		}

		/*
		 * This might be a link to someplace else.
		 */
		return asn1c_activate_dependency(deps, NULL, fname);
	} else {
		for(i = 0; i < cur->el_count; i++) {
			asn1c_activate_dependency(deps,
				cur->elements[i], fname);
		}
	}

	return 0;
}

asn1c_fdeps_t *
asn1c_read_file_dependencies(arg_t *arg, const char *datadir) {
	char buf[4096];
	asn1c_fdeps_t *deps;
	asn1c_fdeps_t *cur;
	FILE *f;
	enum fdep_usage special_section = FDEP_NOTUSED;

	(void)arg;

	if(!datadir || strlen(datadir) > sizeof(buf) / 2) {
		errno = EINVAL;
		return NULL;
	} else {
		sprintf(buf, "%s/file-dependencies", datadir);
	}

	f = fopen(buf, "r");
	if(!f) return NULL;

	deps = asn1c_new_dep(0);
	assert(deps);

	while(fgets(buf, sizeof(buf), f)) {
		char *p = strchr(buf, '#');
		if(p) *p = '\0';	/* Remove comments */

		cur = deps;
		for(p = strtok(buf, " \t\r\n"); p;
				p = strtok(NULL, " \t\r\n")) {
			asn1c_fdeps_t *d;

			/*
			 * Special "prefix" section.
			 */
			if(strchr(p, ':')) {
				special_section = FDEP_IGNORE;
				if(strcmp(p, "COMMON-FILES:") == 0) {
					special_section = FDEP_COMMON_FILES;
				} else if(strcmp(p, "CONVERTER:") == 0) {
					special_section = FDEP_CONVERTER;
				} else if((arg->flags & A1C_GEN_OER)
					  && strcmp(p, "CODEC-OER:") == 0) {
					special_section = FDEP_CODEC_OER;
				} else if((arg->flags & A1C_GEN_PER)
					  && strcmp(p, "CODEC-PER:") == 0) {
					special_section = FDEP_CODEC_PER;
				}
				break;
			}

			if(special_section == FDEP_IGNORE)
				continue;

			d = asn1c_new_dep(p);
			d->usage = special_section;

			if(asn1c_dep_add(cur, d) == 1)
				cur = d;
		}
	}

	fclose(f);

	return deps;
}

static asn1c_fdeps_t *
asn1c_new_dep(const char *filename) {
	asn1c_fdeps_t *d;

	d = calloc(1, sizeof(*d));
	if(filename) {
		d->filename = strdup(filename);
		if(!d->filename) return NULL;
	}

	return d;
}

static void
asn1c_free_dep(asn1c_fdeps_t *d) {

	if(d) {
		if(d->filename) free(d->filename);
		d->filename = 0;
		free(d);
	}
}

static int
asn1c_dep_add(asn1c_fdeps_t *deps, asn1c_fdeps_t *d) {
	int n;

	/* Check for duplicates */
	for(n = 0; n < deps->el_count; n++) {
		if(strcmp(deps->elements[n]->filename, d->filename) == 0)
			return 0;
	}

	if(deps->el_count == deps->el_size) {
		void *p;
		n = deps->el_size?deps->el_size << 2:16;
		p = realloc(deps->elements,
			n * sizeof(deps->elements[0]));
		assert(p);
		deps->elements = p;
		deps->el_size = n;
	}

	deps->elements[deps->el_count++] = d;
	return 1;
}

asn1c_fdeps_t *
asn1c_deps_flatten(const asn1c_fdeps_t *deps) {
	asn1c_fdeps_t *dlist;
	asn1c_fdeps_t *d;

	if(!deps) {
		errno = EINVAL;
		return 0;
	}

	dlist = asn1c_new_dep(0);

	if(deps->filename && deps->usage != FDEP_NOTUSED) {
		d = asn1c_new_dep(deps->filename);
		d->usage = deps->usage;
		if(!asn1c_dep_add(dlist, d)) {
			asn1c_free_dep(d);
		}
	}

	for(int i = 0; i < deps->el_count; i++) {
		d = asn1c_deps_flatten(deps->elements[i]);
		assert(!d->filename);
		for(int j = 0; j < d->el_count; j++) {
			if(asn1c_dep_add(dlist, d->elements[j])) {
				d->elements[j] = 0;
			}
		}
		asn1c_deps_freelist(d);
	}

	return dlist;
}

void
asn1c_deps_freelist(asn1c_fdeps_t *deps) {
	if(deps) {
		int i;
		if(deps->elements) {
			for(i = 0; i < deps->el_count; i++) {
				asn1c_deps_freelist(deps->elements[i]);
				deps->elements[i] = 0;
			}
			free(deps->elements);
			deps->elements = 0;			
		}
		asn1c_free_dep(deps);
	}
}
