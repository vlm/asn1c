/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <errno.h>
#include <oer_tag.h>

ssize_t
oer_fetch_tag(const void *ptr, size_t size, ber_tlv_tag_t *tag_r) {
    /* same as ber, because for short form, bit 6 is always 0 for BER */
    return ber_fetch_tag(ptr, size, tag_r);
}


ssize_t
oer_tag_fwrite(oer_tag_t tag, FILE *f) {
	char buf[sizeof("[APPLICATION ]") + 32];
	ssize_t ret;

	ret = oer_tag_snprint(tag, buf, sizeof(buf));
	if(ret >= (ssize_t)sizeof(buf) || ret < 2) {
		errno = EPERM;
		return -1;
	}
	return fwrite(buf, 1, ret, f);
}

ssize_t
oer_tag_snprint(oer_tag_t tag, char *buf, size_t size) {
    return ber_tlv_tag_snprint(tag, buf, size);
}

char *
oer_tag_string(oer_tag_t tag) {
	static char buf[sizeof("[APPLICATION ]") + 32];

	(void)oer_tag_snprint(tag, buf, sizeof(buf));

	return buf;
}

size_t
oer_tag_serialize(oer_tag_t tag, void *bufp, size_t size) {
	int tclass = BER_TAG_CLASS(tag);
	oer_tag_t tval = BER_TAG_VALUE(tag);
	uint8_t *buf = (uint8_t *)bufp;
	uint8_t *end;
	size_t required_size;
	size_t i;

	if(tval < 63) {
		/* Encoded in 1 octet */
		if(size) buf[0] = (tclass << 6) | tval;
		return 1;
	} else if(size) {
		*buf++ = (tclass << 6) | 0x1F;
		size--;
	}

	/*
	 * Compute the size of the subsequent bytes.
	 */
	for(required_size = 1, i = 7; i < 8 * sizeof(tval); i += 7) {
		if(tval >> i)
			required_size++;
		else
			break;
	}

	if(size < required_size)
		return required_size + 1;

	/*
	 * Fill in the buffer, space permitting.
	 */
	end = buf + required_size - 1;
	for(i -= 7; buf < end; i -= 7, buf++)
		*buf = 0x80 | ((tval >> i) & 0x7F);
	*buf = (tval & 0x7F);	/* Last octet without high bit */

	return required_size + 1;
}

