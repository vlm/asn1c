/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <OBJECT_IDENTIFIER.h>
#include <limits.h>	/* for CHAR_BIT */
#include <assert.h>
#include <errno.h>

/*
 * OBJECT IDENTIFIER basic type description.
 */
static ber_tlv_tag_t asn1_DEF_OBJECT_IDENTIFIER_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (6 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_OBJECT_IDENTIFIER = {
	"OBJECT IDENTIFIER",
	OBJECT_IDENTIFIER_constraint,
	INTEGER_decode_ber,	/* Implemented in terms of INTEGER type */
	OBJECT_IDENTIFIER_encode_der,
	OBJECT_IDENTIFIER_print,
	INTEGER_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_OBJECT_IDENTIFIER_tags,
	sizeof(asn1_DEF_OBJECT_IDENTIFIER_tags)
	    / sizeof(asn1_DEF_OBJECT_IDENTIFIER_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};


/*
 * Encode OBJECT IDENTIFIER type using DER.
 */
der_enc_rval_t
OBJECT_IDENTIFIER_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	der_enc_rval_t erval;
	OBJECT_IDENTIFIER_t *st = (OBJECT_IDENTIFIER_t *)ptr;

	ASN_DEBUG("%s %s as OBJECT IDENTIFIER (tm=%d)",
		cb?"Encoding":"Estimating", sd->name, tag_mode);

	erval.encoded = der_write_tags(sd, st->size, tag_mode, tag,
		cb, app_key);
	ASN_DEBUG("OBJECT IDENTIFIER %s wrote tags %d",
		sd->name, (int)erval.encoded);
	if(erval.encoded == -1) {
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
		return erval;
	}

	if(cb && st->buf) {
		ssize_t ret;

		ret = cb(st->buf, st->size, app_key);
		if(ret == -1) {
			erval.encoded = -1;
			erval.failed_type = sd;
			erval.structure_ptr = ptr;
			return erval;
		}
	} else {
		assert(st->buf || st->size == 0);
	}

	erval.encoded += st->size;

	return erval;
}

int
OBJECT_IDENTIFIER_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const OBJECT_IDENTIFIER_t *st = (const OBJECT_IDENTIFIER_t *)sptr;

	if(st && st->buf) {
		if(st->size < 1) {
			_ASN_ERRLOG(app_errlog, app_key,
				"%s: at least one numerical value expected",
				td->name);
			return -1;
		}
	} else {
		_ASN_ERRLOG(app_errlog, app_key,
			"%s: value not given", td->name);
		return -1;
	}

	return 0;
}


int
OBJECT_IDENTIFIER_get_single_arc(uint8_t *arcbuf, unsigned int arclen, signed int add, void *rvbuf, unsigned int rvsize) {
	unsigned LE = 1;	/* Little endian (x86) */
	uint8_t *arcend = arcbuf + arclen;	/* End of arc */
	void *rvstart = rvbuf;	/* Original start of the value buffer */
	unsigned int cache = 0;	/* No more than 14 significant bits */
	int inc;	/* Return value growth direction */

	rvsize *= CHAR_BIT;	/* bytes to bits */
	arclen *= 7;		/* bytes to bits */

	/*
	 * The arc has the number of bits
	 * cannot be represented using supplied return value type.
	 */
	if(arclen > rvsize) {
		if(arclen > (rvsize + CHAR_BIT)) {
			errno = ERANGE;	/* Overflow */
			return -1;
		} else {
			/*
			 * Even if the number of bits in the arc representation
			 * is higher than the width of supplied * return value
			 * type, there is still possible to fit it when there
			 * are few unused high bits in the arc value
			 * representaion.
			 * 
			 * Moreover, there is a possibility that the
			 * number could actually fit the arc space, given
			 * that add is negative, but we don't handle
			 * such "temporary lack of precision" situation here.
			 * May be considered as a bug.
			 */
			uint8_t mask = (0xff << (7-(arclen - rvsize))) & 0x7f;
			if((*arcbuf & mask)) {
				errno = ERANGE;	/* Overflow */
				return -1;
			}
			/* Fool the routine computing unused bits */
			arclen -= 7;
			cache = *arcbuf & 0x7f;
			arcbuf++;
		}
	}

	/* Faster path for common size */
	if(rvsize == (CHAR_BIT * sizeof(unsigned long))) {
		unsigned long accum;
		/* Gather all bits into the accumulator */
		for(accum = cache; arcbuf < arcend; arcbuf++)
			accum = (accum << 7) | (*arcbuf & ~0x80);
		if(accum < (unsigned)-add) {
			errno = ERANGE;	/* Overflow */
			return -1;
		}
		*(unsigned long *)rvbuf = accum + add;
		return 0;
	}

#ifndef	WORDS_BIGENDIAN
	if(*(unsigned char *)&LE) {	/* Little endian (x86) */
		/* "Convert" to big endian */
		(unsigned char *)rvbuf += rvsize / CHAR_BIT - 1;
		((unsigned char *)rvstart)--;
		inc = -1;	/* Descending */
	} else
#endif	/* !WORDS_BIGENDIAN */
		inc = +1;	/* Big endian is known [at compile time] */

	{
		int bits;	/* typically no more than 3-4 bits */

		/* Clear the high unused bits */
		for(bits = rvsize - arclen;
			bits > CHAR_BIT;
				(unsigned char *)rvbuf += inc, bits -= CHAR_BIT)
				*(unsigned char *)rvbuf = 0;

		/* Fill the body of a value */
		for(; arcbuf < arcend; arcbuf++) {
			cache = (cache << 7) | (*arcbuf & 0x7f);
			bits += 7;
			if(bits >= CHAR_BIT) {
				bits -= CHAR_BIT;
				*(unsigned char *)rvbuf = (cache >> bits);
				(unsigned char *)rvbuf += inc;
			}
		}
		if(bits) {
			*(unsigned char *)rvbuf = cache;
			(unsigned char *)rvbuf += inc;
		}
	}

	if(add) {
		for((unsigned char *)rvbuf -= inc; rvbuf != rvstart; (unsigned char *)rvbuf -= inc) {
			int v = add + *(unsigned char *)rvbuf;
			if(v & (-1 << CHAR_BIT)) {
				*(unsigned char *)rvbuf
					= (unsigned char)(v + (1 << CHAR_BIT));
				add = -1;
			} else {
				*(unsigned char *)rvbuf = v;
				break;
			}
		}
		if(rvbuf == rvstart) {
			/* No space to carry over */
			errno = ERANGE;	/* Overflow */
			return -1;
		}
	}

	return 0;
}


int
OBJECT_IDENTIFIER_print_arc(uint8_t *arcbuf, int arclen, int add,
		asn_app_consume_bytes_f *cb, void *app_key) {
	char scratch[64];	/* Conservative estimate */
	unsigned long accum;	/* Bits accumulator */
	char *p;		/* Position in the scratch buffer */

	if(OBJECT_IDENTIFIER_get_single_arc(arcbuf, arclen, add,
			&accum, sizeof(accum)))
		return -1;

	/* Fill the scratch buffer in reverse. */
	p = scratch + sizeof(scratch);
	for(; accum; accum /= 10)
		*(--p) = (char)(accum % 10) + 0x30;

	return cb(p, sizeof(scratch) - (p - scratch), app_key);
}

int
OBJECT_IDENTIFIER_print(asn1_TYPE_descriptor_t *td, const void *sptr,
	int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	const OBJECT_IDENTIFIER_t *st = (const OBJECT_IDENTIFIER_t *)sptr;
	int startn;
	int add = 0;
	int i;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!st || !st->buf)
		return cb("<absent>", 8, app_key);

	/* Dump preamble */
	if(cb("{ ", 2, app_key))
		return -1;

	for(i = 0, startn = 0; i < st->size; i++) {
		uint8_t b = st->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;

		if(startn == 0) {
			/*
			 * First two arcs are encoded through the backdoor.
			 */
			if(i) {
				add = -80;
				if(cb("2", 1, app_key)) return -1;
			} else if(b <= 39) {
				add = 0;
				if(cb("0", 1, app_key)) return -1;
			} else if(b < 79) {
				add = -40;
				if(cb("1", 1, app_key)) return -1;
			} else {
				add = -80;
				if(cb("2", 1, app_key)) return -1;
			}
		}

		if(cb(" ", 1, app_key))	/* Separate arcs */
			return -1;

		if(OBJECT_IDENTIFIER_print_arc(&st->buf[startn],
				i - startn + 1, add,
				cb, app_key))
			return -1;
		startn = i + 1;
		add = 0;
	}

	return cb(" }", 2, app_key);
}

int
OBJECT_IDENTIFIER_get_arcs(OBJECT_IDENTIFIER_t *oid, void *arcs,
		unsigned int arc_type_size, unsigned int arc_slots) {
	void *arcs_end = (char *)arcs + (arc_type_size * arc_slots);
	int num_arcs = 0;
	int startn = 0;
	int add = 0;
	int i;

	if(!oid || !oid->buf || (arc_slots && arc_type_size <= 1)) {
		errno = EINVAL;
		return -1;
	}

	for(i = 0; i < oid->size; i++) {
		uint8_t b = oid->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;

		if(num_arcs == 0) {
			/*
			 * First two arcs are encoded through the backdoor.
			 */
			unsigned LE = 1;	/* Little endian */
			int first_arc;
			num_arcs++;
			if(!arc_slots) { num_arcs++; continue; }

			if(i) first_arc = 2;
			else if(b <= 39) first_arc = 0;
			else if(b < 79)	first_arc = 1;
			else first_arc = 2;

			add = -40 * first_arc;
			memset(arcs, 0, arc_type_size);
			*(unsigned char *)((char *)arcs
				+ ((*(char *)&LE)?0:(arc_type_size - 1)))
					= first_arc;
			(char *)arcs += arc_type_size;
		}

		/* Decode, if has space */
		if(arcs < arcs_end) {
			if(OBJECT_IDENTIFIER_get_single_arc(&oid->buf[startn],
				i - startn + 1, add,
					arcs, arc_type_size))
				return -1;
			startn = i + 1;
			(char *)arcs += arc_type_size;
			add = 0;
		}
		num_arcs++;
	}

	return num_arcs;
}


/*
 * Save the single value as an object identifier arc.
 */
int
OBJECT_IDENTIFIER_set_single_arc(uint8_t *arcbuf, void *arcval, unsigned int arcval_size, int prepared_order) {
	/*
	 * The following conditions must hold:
	 * assert(arcval);
	 * assert(arcval_size > 0);
	 * assert(arcbuf);
	 */
#ifdef	WORDS_BIGENDIAN
	const unsigned isLittleEndian = 0;
#else
	unsigned LE = 1;
	unsigned isLittleEndian = *(char *)&LE;
#endif
	uint8_t *tp, *tend;
	unsigned int cache;
	uint8_t *bp = arcbuf;
	int bits;
#ifdef	__GNUC__
	uint8_t buffer[arcval_size];
#else
	uint8_t *buffer = alloca(arcval_size);
	if(!buffer) { errno = ENOMEM; return -1; }
#endif

	if(isLittleEndian && !prepared_order) {
		uint8_t *a = (unsigned char *)arcval + arcval_size - 1;
		uint8_t *aend = (uint8_t *)arcval;
		uint8_t *msb = buffer + arcval_size - 1;
		for(tp = buffer; a >= aend; tp++, a--)
			if((*tp = *a) && (tp < msb))
				msb = tp;
		tend = &buffer[arcval_size];
		tp = msb;	/* Most significant non-zero byte */
	} else {
		/* Look for most significant non-zero byte */
		tend = (unsigned char *)arcval + arcval_size;
		for(tp = (uint8_t *)arcval; tp < tend - 1; tp++)
			if(*tp) break;
	}

	/*
	 * Split the value in 7-bits chunks.
	 */
	bits = ((tend - tp) * CHAR_BIT) % 7;
	if(bits) {
		cache = *tp >> (CHAR_BIT - bits);
		if(cache) {
			*bp++ = cache | 0x80;
			cache = *tp++;
			bits = CHAR_BIT - bits;
		} else {
			bits = -bits;
		}
	} else {
		cache = 0;
	}
	for(; tp < tend; tp++) {
		cache = (cache << CHAR_BIT) + *tp;
		bits += CHAR_BIT;
		while(bits >= 7) {
			bits -= 7;
			*bp++ = 0x80 | (cache >> bits);
		}
	}
	if(bits) *bp++ = cache;
	bp[-1] &= 0x7f;	/* Clear the last bit */

	return bp - arcbuf;
}

int
OBJECT_IDENTIFIER_set_arcs(OBJECT_IDENTIFIER_t *oid, void *arcs, unsigned int arc_type_size, unsigned int arc_slots) {
	uint8_t *buf;
	uint8_t *bp;
	unsigned LE = 1;	/* Little endian (x86) */
	unsigned isLittleEndian = *((char *)&LE);
	unsigned int arc0;
	unsigned int arc1;
	unsigned size;
	unsigned i;

	if(!oid || !arcs || arc_type_size < 1 || arc_slots < 2) {
		errno = EINVAL;
		return -1;
	}

	switch(arc_type_size) {
	case sizeof(char):
		arc0 = ((unsigned char *)arcs)[0];
		arc1 = ((unsigned char *)arcs)[1];
		break;
	case sizeof(short):
		arc0 = ((unsigned short *)arcs)[0];
		arc1 = ((unsigned short *)arcs)[1];
		break;
	case sizeof(int):
		arc0 = ((unsigned int *)arcs)[0];
		arc1 = ((unsigned int *)arcs)[1];
		break;
	default:
		arc1 = arc0 = 0;
		if(isLittleEndian) {	/* Little endian (x86) */
			unsigned char *ps, *pe;
			/* If more significant bytes are present,
			 * make them > 255 quick */
			for(ps = (unsigned char *)arcs + 1, pe = ps+arc_type_size;
					ps < pe; ps++)
				arc0 |= *ps, arc1 |= *(ps + arc_type_size);
			arc0 <<= CHAR_BIT, arc1 <<= CHAR_BIT;
			arc0 = *((unsigned char *)arcs + 0);
			arc1 = *((unsigned char *)arcs + arc_type_size);
		} else {
			unsigned char *ps, *pe;
			/* If more significant bytes are present,
			 * make them > 255 quick */
			for(ps = (unsigned char *)arcs, pe = ps+arc_type_size - 1; ps < pe; ps++)
				arc0 |= *ps, arc1 |= *(ps + arc_type_size);
			arc0 = *((unsigned char *)arcs + arc_type_size - 1);
			arc1 = *((unsigned char *)arcs +(arc_type_size<< 1)-1);
		}
	}

	/*
	 * The previous chapter left us with the first and the second arcs.
	 * The values are not precise (that is, they are valid only if
	 * they're less than 255), but OK for the purposes of making
	 * the sanity test below.
	 */
	if(arc0 <= 1) {
		if(arc1 >= 39) {
			/* 8.19.4: At most 39 subsequent values (including 0) */
			errno = ERANGE;
			return -1;
		}
	} else if(arc0 > 2) {
		/* 8.19.4: Only three values are allocated from the root node */
		errno = ERANGE;
		return -1;
	}
	/*
	 * After above tests it is known that the value of arc0 is completely
	 * trustworthy (0..2). However, the arc1's value is still meaningless.
	 */

	/*
	 * Roughly estimate the maximum size necessary to encode these arcs.
	 * This estimation implicitly takes in account the following facts,
	 * that cancel each other:
	 * 	* the first two arcs are encoded in a single value.
	 * 	* the first value may require more space (+1 byte)
	 * 	* the value of the first arc which is in range (0..2)
	 */
	size = ((arc_type_size * CHAR_BIT + 6) / 7) * arc_slots;
	bp = buf = (uint8_t *)MALLOC(size + 1);
	if(!buf) {
		/* ENOMEM */
		return -1;
	}

	/*
	 * Encode the first two arcs.
	 * These require special treatment.
	 */
	{
		uint8_t *tp;
#ifdef	__GNUC__
		uint8_t first_value[1 + arc_type_size];	/* of two arcs */
		uint8_t *fv = first_value;
#else
		uint8_t *first_value = alloca(1 + arc_type_size);
		uint8_t *fv = first_value;
		if(!first_value) {
			errno = ENOMEM;
			return -1;
		}
#endif

		/*
		 * Simulate first_value = arc0 * 40 + arc1;
		 */
		/* Copy the second (1'st) arcs[1] into the first_value */
		*fv++ = 0;
		(char *)arcs += arc_type_size;
		if(isLittleEndian) {
			uint8_t *aend = (unsigned char *)arcs - 1;
			uint8_t *a1 = (unsigned char *)arcs + arc_type_size - 1;
			for(; a1 > aend; fv++, a1--) *fv = *a1;
		} else {
			uint8_t *a1 = (uint8_t *)arcs;
			uint8_t *aend = a1 + arc_type_size;
			for(; a1 < aend; fv++, a1++) *fv = *a1;
		}
		/* Increase the first_value by arc0 */
		arc0 *= 40;	/* (0..80) */
		for(tp = first_value + arc_type_size; tp >= first_value; tp--) {
			unsigned int v = *tp;
			v += arc0;
			*tp = v;
			if(v >= (1 << CHAR_BIT)) arc0 = v >> CHAR_BIT;
			else break;
		}

		assert(tp >= first_value);

		bp += OBJECT_IDENTIFIER_set_single_arc(bp, first_value,
			fv - first_value, 1);
 	}

	/*
	 * Save the rest of arcs.
	 */
	for((char *)arcs += arc_type_size, i = 2;
			i < arc_slots; i++, (char *)arcs += arc_type_size) {
		bp += OBJECT_IDENTIFIER_set_single_arc(bp,
			arcs, arc_type_size, 0);
	}

	assert((unsigned)(bp - buf) <= size);

	/*
	 * Replace buffer.
	 */
	oid->size = bp - buf;
	bp = oid->buf;
	oid->buf = buf;
	if(bp) FREEMEM(bp);

	return 0;
}

