#include "asn1c_internal.h"
#include "asn1c_compat.h"

#ifndef	MAXPATHLEN
#define	MAXPATHLEN	1024
#endif

#ifndef	DEFFILEMODE	/* Normally in <sys/stat.h> */
#ifdef	_WIN32
#define	DEFFILEMODE	(S_IREAD|S_IWRITE)
#else
#define	DEFFILEMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#endif
#endif

#ifdef _WIN32
int mkstemp(char *template)
{
	char *tmpFN = _mktemp(template);
	if (tmpFN)
		return open(tmpFN, O_CREAT | O_EXCL | O_WRONLY, DEFFILEMODE);
	else
		return -1;
}
#undef HAVE_MKSTEMPS
#endif

#ifdef	HAVE_MKSTEMPS
#undef	mkstemp
#define	mkstemp(foo)	mkstemps(foo, 0)
#endif

FILE *
asn1c_open_file(const char *name, const char *ext, char **opt_tmpname) {
	int created = 1;
#ifndef	_WIN32
	struct stat sb;
#endif
	char *fname;
	size_t len;
	FILE *fp;
	int ret;
	int fd;

	/*
	 * Compute filenames.
	 */
	len = strlen(name) + strlen(ext) + sizeof(".XXXXXX");
	fname = alloca(len);
	ret = snprintf(fname, len, "%s%s%s", name, ext,
		opt_tmpname ? ".XXXXXX" : "");
	assert(ret > 0 && ret < (ssize_t)len);

	if(opt_tmpname) {
		/*
		 * Create temporary file.
		 */
		fd = mkstemp(fname);
#ifndef	_WIN32
		(void)fchmod(fd, DEFFILEMODE);
#endif
	} else {
		/*
		 * Create specified file, or open the old one.
		 */
		fd = open(fname, O_CREAT | O_EXCL | O_WRONLY, DEFFILEMODE);
		if(fd == -1 && errno == EEXIST) {
			fd = open(fname, O_WRONLY, DEFFILEMODE);
			created = 0;
		}
	}
	if(fd == -1) {
		perror(fname);
		return NULL;
	}

#ifndef	_WIN32
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
#endif	/* _WIN32 */

	/*
	 * Convert file descriptor into file pointer.
	 */
	fp = fdopen(fd, "w");
	if(fp == NULL) {
		if(created) unlink(fname);
		close(fd);
		return NULL;
	}

	/* Return the temporary file name */
	if(opt_tmpname) {
		*opt_tmpname = strdup(fname);
		if(*opt_tmpname) {
			/* Successfull */
		} else {
			if(created) unlink(fname);
			fclose(fp);
			return NULL;
		}
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

