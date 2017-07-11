/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are oermitted subject to BSD license.
 */
#include <asn_system.h>
#include <asn_internal.h>

#include <oer_support.h>

/*
 * Fetch the length determinant (X.696 08/2015, #8.6) into *len_r.
 * RETURN VALUES:
 *       0:     More data expected than bufptr contains.
 *      -1:     Fatal error deciphering length.
 *      >0:     Number of bytes used from bufptr.
 */
ssize_t
oer_fetch_length(const void *bufptr, size_t size, size_t *len_r) {
    uint8_t first_byte;
    uint8_t len_len;    /* Length of the length determinant */
    const uint8_t *b;
    const uint8_t *bend;
    size_t len;

    if(size == 0) {
        *len_r = 0;
        return 0;
    }

    first_byte = *(const uint8_t *)bufptr;
    if((first_byte & 0x80) == 0) {   /* Short form */
        *len_r = first_byte; /* 0..127 */
        return 1;
    }

    len_len = (first_byte & 0x7f);
    if((1 + len_len) > size) {
        *len_r = 0;
        return 0;
    }

    b = (const uint8_t *)bufptr + 1;
    bend = b + len_len;

    for(; b < bend && *b == 0; b++) {
        /* Skip the leading 0-bytes */
    }

    if((bend - b) > sizeof(size_t)) {
        /* Length is not representable by the native size_t type */
        *len_r = 0;
        return -1;
    }

    for(len = 0; b < bend; b++) {
        len = (len << 8) + *b;
    }

    *len_r = len;
    assert(len_len + 1 == bend - (const uint8_t *)bufptr);
    return len_len + 1;
}


