#include "asn1c_internal.h"
#include "asn1c_compat.h"

#ifndef	MAXPATHLEN
#define	MAXPATHLEN	1024
#endif

#ifndef	DEFFILEMODE	/* Normally in <sys/stat.h> */
#ifdef	WIN32
#define	DEFFILEMODE	0
#else
#define	DEFFILEMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#endif
#endif

FILE *
asn1c_open_file(const char *name, const char *ext) {
	int created = 1;
#ifndef	WIN32
	struct stat sb;
#endif
	char *fname;
	size_t len;
	FILE *fp;
	int fd;

	/*
	 * Compute filenames.
	 */
	len = strlen(name) + strlen(ext) + 1;
	fname = alloca(len);
	snprintf(fname, len, "%s%s", name, ext);

	/*
	 * Create files.
	 */
	fd = open(fname, O_CREAT | O_EXCL | O_WRONLY, DEFFILEMODE);
	if(fd == -1 && errno == EEXIST) {
		fd = open(fname, O_WRONLY, DEFFILEMODE);
		created = 0;
	}
	if(fd == -1) {
		perror(fname);
		return NULL;
	}

#ifndef	WIN32
	/*
	 * Check sanity.
	 */
	if(fstat(fd, &sb) || !S_ISREG(sb.st_mode)) {
		fprintf(stderr, "%s: Not a regular file\n", fname);
		if(created) unlink(fname);
		close(fd);
		return NULL;
	}

	(void)ftruncate(fd, 0);
#else
	_chsize(fd, 0);
#endif	/* WIN32 */

	/*
	 * Convert file descriptor into file pointer.
	 */
	fp = fdopen(fd, "w");
	if(fp == NULL) {
		if(created) unlink(fname);
		close(fd);
	}
	return fp;
}


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

	if((pend - name) >= (int)sizeof(strbuf) - 1) {
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

	if((last - path) >= (int)sizeof(strbuf)) {
		errno = ENAMETOOLONG;
		return 0;
	}

	memcpy(strbuf, path, last - path);
	strbuf[last - path] = '\0';

	return strbuf;
}

