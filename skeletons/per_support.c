/*
 * Copyright (c) 2005 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_system.h>
#include <per_support.h>

/*
 * Extract a small number of bits (<= 31) from the specified PER data pointer.
 */
int32_t
per_get_few_bits(asn_per_data_t *pd, int nbits) {
	size_t off;	/* Next after last bit offset */
	uint32_t accum;
	uint8_t *buf;

	if(nbits < 0 || pd->nboff + nbits > pd->nbits)
		return -1;

	/*
	 * Normalize position indicator.
	 */
	if(pd->nboff >= 8) {
		pd->buffer += (pd->nboff >> 3);
		pd->nbits  -= (pd->nboff & ~0x07);
		pd->nboff  &= 0x07;
	}
	off = (pd->nboff += nbits);
	buf = pd->buffer;

	/*
	 * Extract specified number of bits.
	 */
	if(off <= 8)
		accum = nbits ? (buf[0]) >> (8 - off) : 0;
	else if(off <= 16)
		accum = ((buf[0] << 8) + buf[1]) >> (16 - off);
	else if(off <= 24)
		accum = ((buf[0] << 16) + (buf[1] << 8) + buf[2]) >> (24 - off);
	else if(off <= 31)
		accum = ((buf[0] << 24) + (buf[1] << 16)
			+ (buf[2] << 8) + (buf[3])) >> (32 - off);
	else if(nbits <= 31) {
		asn_per_data_t tpd = *pd;
		/* Here are we with our 31-bits limit plus 1..7 bits offset. */
		tpd.nboff -= nbits;
		accum  = per_get_few_bits(&tpd, nbits - 24) << 24;
		accum |= per_get_few_bits(&tpd, 24);
	} else {
		pd->nboff -= nbits;	/* Oops, revert back */
		return -1;
	}

	return (accum & (((uint32_t)1 << nbits) - 1));
}

/*
 * Extract a large number of bits from the specified PER data pointer.
 */
int
per_get_many_bits(asn_per_data_t *pd, uint8_t *dst, int alright, int nbits) {
	int32_t value;

	if(alright && (nbits & 7)) {
		/* Perform right alignment of a first few bits */
		value = per_get_few_bits(pd, nbits & 0x07);
		if(value < 0) return -1;
		*dst++ = value;	/* value is already right-aligned */
		nbits &= ~7;
	}

	while(nbits) {
		if(nbits >= 24) {
			value = per_get_few_bits(pd, 24);
			if(value < 0) return -1;
			*(dst++) = value >> 16;
			*(dst++) = value >> 8;
			*(dst++) = value;
			nbits -= 24;
		} else {
			value = per_get_few_bits(pd, nbits);
			if(value < 0) return -1;
			if(nbits & 7) {	/* implies alright */
				value <<= 8 - (nbits & 7),
				nbits += 8 - (nbits & 7);
				if(nbits > 24)
					*dst++ = value >> 24;
			}
			if(nbits > 16)
				*dst++ = value >> 16;
			if(nbits > 8)
				*dst++ = value >> 8;
			*dst++ = value;
			break;
		}
	}

	return 0;
}

/*
 * Get the length "n" from the stream.
 */
ssize_t
uper_get_length(asn_per_data_t *pd, int ebits, int *repeat) {
	ssize_t value;

	*repeat = 0;

	if(ebits >= 0) return per_get_few_bits(pd, ebits);

	value = per_get_few_bits(pd, 8);
	if(value < 0) return -1;
	if((value & 128) == 0)	/* #10.9.3.6 */
		return (value & 0x7F);
	if((value & 64) == 0) {	/* #10.9.3.7 */
		value = ((value & 63) << 8) | per_get_few_bits(pd, 8);
		if(value < 0) return -1;
		return value;
	}
	value &= 63;	/* this is "m" from X.691, #10.9.3.8 */
	if(value < 1 || value > 4)
		return -1;
	*repeat = 1;
	return (16384 * value);
}

/*
 * Get the normally small non-negative whole number.
 * X.691, #10.6
 */
ssize_t
uper_get_nsnnwn(asn_per_data_t *pd) {
	ssize_t value;

	value = per_get_few_bits(pd, 7);
	if(value & 64) {	/* implicit (value < 0) */
		value &= 63;
		value <<= 2;
		value |= per_get_few_bits(pd, 2);
		if(value & 128)	/* implicit (value < 0) */
			return -1;
		if(value == 0)
			return 0;
		if(value >= 3)
			return -1;
		value = per_get_few_bits(pd, 8 * value);
		return value;
	}

	return value;
}
