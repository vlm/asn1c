#include <asn1c_compat.h>

#include <string.h>
#include <errno.h>

#ifdef	HAVE_SYS_PARAM_H
#include <sys/param.h>	/* For MAXPATHLEN */
#endif

#ifndef	MAXPATHLEN
#define	MAXPATHLEN	1024
#endif

char *
a1c_basename(const char *path) {
	static char strbuf[MAXPATHLEN];
	const char *pend;
	const char *name;

	pend = path + strlen(path);
	if(pend == path) {
		strcpy(strbuf, ".");
		return strbuf;
	}

	/* Skip tailing slashes */
	for(pend--; pend > path && *pend == '/'; pend--);

	if(pend == path && *path == '/') {
		strcpy(strbuf, "/");
		return strbuf;
	}

	for(name = pend; name > path && name[-1] != '/'; name--);

	if((pend - name) >= sizeof(strbuf) - 1) {
		errno = ENAMETOOLONG;
		return 0;
	}

	memcpy(strbuf, name, pend - name + 1);
	strbuf[pend - name + 1] = '\0';

	return strbuf;
}


char *
a1c_dirname(const char *path) {
	static char strbuf[MAXPATHLEN];
	const char *pend;
	const char *last = 0;
	int in_slash = 0;

	/* One-pass determination of the last char of the pathname */
	for(pend = path; ; pend++) {
		switch(*pend) {
		case '\0': break;
		case '/':
			if(!in_slash) {
				last = pend;
				in_slash = 1;
			}
			continue;
		default:
			if(in_slash) in_slash = 0;
			continue;
		}
		break;
	}

	if(last <= path) {
		strcpy(strbuf, *path == '/' ? "/" : ".");
		return strbuf;
	}

	if(!last) {
		strcpy(strbuf, "/");
		return strbuf;
	}

	if((last - path) >= sizeof(strbuf)) {
		errno = ENAMETOOLONG;
		return 0;
	}

	memcpy(strbuf, path, last - path);
	strbuf[last - path] = '\0';

	return strbuf;
}

