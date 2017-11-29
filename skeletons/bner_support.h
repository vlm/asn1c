/*
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info> and contributors.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef _BNER_SUPPORT_H_
#define _BNER_SUPPORT_H_

#include <ber_tlv_tag.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int init_bner(void);
void fini_bner(void);
int is_bner_fixed_pdu(const char *pdu_type_name);

enum bner_application_tag {
    BNER_APPLICATION_TAG_NULL = 0,
    BNER_APPLICATION_TAG_BOOLEAN = 1,
    BNER_APPLICATION_TAG_UNSIGNED = 2,
    BNER_APPLICATION_TAG_SIGNED = 3,
    BNER_APPLICATION_TAG_REAL = 4,
    BNER_APPLICATION_TAG_DOUBLE = 5,
    BNER_APPLICATION_TAG_OCTET_STR = 6,
    BNER_APPLICATION_TAG_CHAR_STR = 7,
    BNER_APPLICATION_TAG_BIT_STR = 8,
    BNER_APPLICATION_TAG_ENUMERATED = 9,
    BNER_APPLICATION_TAG_DATE = 10,
    BNER_APPLICATION_TAG_TIME = 11,
    BNER_APPLICATION_TAG_OBJECT_ID = 12
    /* 13, 14, 15 Reserved for ASHRAE */
};

enum bner_lvt_type {
    BNER_LVT_LENGTH = 0,
    BNER_LVT_VALUE = 1,
    BNER_LVT_TYPE = 2
};

enum bner_boolean { BNER_FALSE = 0, BNER_TRUE = 1 };

enum bner_construct_tag { BNER_OPENING_TAG = 6, BNER_CLOSING_TAG = 7 };

struct bner_tag_lvt_s {
    ber_tlv_tag_t tag;
    enum bner_lvt_type lvt_type;
    union {
        uint32_t length;
        enum bner_boolean value;
        enum bner_construct_tag type;
    } u;
};

typedef struct bner_tag_lvt_s bner_tag_lvt_t;

static inline int
is_bner_opening_tag(bner_tag_lvt_t tag) {
    return tag.lvt_type == BNER_LVT_TYPE && tag.u.type == BNER_OPENING_TAG;
}
static inline int
is_bner_opening_tag_match(bner_tag_lvt_t tag, ber_tlv_tag_t tag_match) {
    return is_bner_opening_tag(tag) && BER_TAGS_EQUAL(tag.tag, tag_match);
}

static inline int
is_bner_closing_tag(bner_tag_lvt_t tag) {
    return tag.lvt_type == BNER_LVT_TYPE && tag.u.type == BNER_CLOSING_TAG;
}
static inline int
is_bner_closing_tag_match(bner_tag_lvt_t tag, ber_tlv_tag_t tag_match) {
    return is_bner_closing_tag(tag) && BER_TAGS_EQUAL(tag.tag, tag_match);
}

ber_tlv_tag_t convert_ber_to_bner_tag(ber_tlv_tag_t ber_tag);

/*
 * Several functions for printing the TAG in the canonical form
 * (i.e. "[APPLICATION 1]").
 * Return values correspond to their libc counterparts (if any).
 */
ssize_t bner_tag_lvt_snprint(const bner_tag_lvt_t *tag_lvt, char *buf,
                             size_t buflen);
ssize_t bner_tag_lvt_fwrite(const bner_tag_lvt_t *tag, FILE *f);
char *bner_tag_lvt_string(const bner_tag_lvt_t *tag);


/*
 * This function tries to fetch the tag, lvt and length from the BNER input
 *stream.
 * RETURN VALUES:
 * 	 0:	More data expected than bufptr contains.
 * 	-1:	Fatal error deciphering tag.
 *	>0:	Number of bytes used from bufptr. tag_lvt_r will populated.
 */
asn_dec_rval_t bner_fetch_tag_lvt(const void *bufp, size_t size,
                                  bner_tag_lvt_t *tag_lvt_r);

/*
 * This function serializes the tag, lvt and length in BNER format.
 * It always returns number of bytes necessary to represent the tag,
 * it is a caller's responsibility to check the return value
 * against the supplied buffer's size.
 */
size_t bner_tag_lvt_serialize(bner_tag_lvt_t tag_lvt, void *bufptr,
                              size_t size);

asn_dec_rval_t bner_skip_construct(ber_tlv_tag_t tag, const void *buf_ptr,
                                   size_t size);

#ifdef __cplusplus
}
#endif

#endif /* _BNER_SUPPORT_H_ */
