#ifndef	ASN1C_COMPAT_H
#define	ASN1C_COMPAT_H

#ifdef	HAVE_CONFIG_H
#include <config.h>
#endif

/*
 * Open the arbitrary file by its base name and extension.
 */
FILE *asn1c_open_file(const char *base_part, const char *extension);

/*
 * Obtain base name and directory name of a path.
 * Some systems have them in <libgen.h> as dirname(3) and basename(3).
 */
char *a1c_basename(const char *path);
char *a1c_dirname(const char *path);

#endif	/* ASN1C_COMPAT_H */
