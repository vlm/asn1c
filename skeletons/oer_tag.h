/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_OER_TAG_H_
#define	_OER_TAG_H_

#include <ber_tlv_tag.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned oer_tag_t;
/*
 * Several functions for printing the TAG in the canonical form
 * (i.e. "[PRIVATE 0]").
 * Return values correspond to their libc counterparts (if any).
 */
ssize_t oer_tag_snprint(oer_tag_t tag, char *buf, size_t buflen);
ssize_t oer_tag_fwrite(oer_tag_t tag, FILE *);
char *oer_tag_string(oer_tag_t tag);


/*
 * This function tries to fetch the tag from the input stream.
 * RETURN VALUES:
 * 	 0:	More data expected than bufptr contains.
 * 	-1:	Fatal error deciphering tag.
 *	>0:	Number of bytes used from bufptr. tag_r will contain the tag.
 */
ssize_t oer_fetch_tag(const void *bufptr, size_t size, oer_tag_t *tag_r);

/*
 * This function serializes the tag (T from TLV) in BER format.
 * It always returns number of bytes necessary to represent the tag,
 * it is a caller's responsibility to check the return value
 * against the supplied buffer's size.
 */
size_t oer_tag_serialize(oer_tag_t tag, void *bufptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif	/* _OER_TAG_H_ */
