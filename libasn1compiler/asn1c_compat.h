#ifndef	ASN1C_COMPAT_H
#define	ASN1C_COMPAT_H

/*
 * Open the arbitrary file by its base name and extension.
 * If opt_tmpname is given, a temporary file will be created and
 * its name returned in (*opt_tmpname).
 * The (*opt_tmpname) should then be subsequently freed by free(3).
 */
FILE *asn1c_open_file(const char *destdir, const char *base_part, const char *extension,
	char **opt_tmpname);

/*
 * Obtain base name and directory name of a path.
 * Some systems have them in <libgen.h> as dirname(3) and basename(3).
 */
const char *a1c_basename(const char *path, const char* destdir);
const char *a1c_dirname(const char *path);

#endif	/* ASN1C_COMPAT_H */
