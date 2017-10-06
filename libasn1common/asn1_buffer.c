#define _GNU_SOURCE
#include <sys/types.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "config.h"

#include "asn1_buffer.h"

#if !defined(HAVE_DECL_VASPRINTF) || (HAVE_DECL_VASPRINTF == 0)
int vasprintf(char **ret, const char *fmt, va_list args);
#endif

/*
 * Create and destroy the buffer.
 */
abuf *
abuf_new() {
    abuf *ab = calloc(1, sizeof(abuf));
    assert(ab);
    ab->length = 0;
    ab->size = 32;
    ab->buffer = calloc(1, ab->size);
    assert(ab->buffer);
    return ab;
}

void abuf_free(abuf *ab) {
    if(ab) {
        union {
            const char *c_buf;
            char *nc_buf;
        } const_cast;
        const_cast.c_buf = ab->buffer;
        free(const_cast.nc_buf);
        free(ab);
    }
}

/*
 * Erase contents of the buffer (without destroying it).
 */
void
abuf_clear(abuf *ab) {
    union {
        const char *c_buf;
        char *nc_buf;
    } const_cast;
    if(!ab->buffer) {
        ab->size = 32;
        ab->buffer = calloc(1, ab->size);
        assert(ab->buffer);
    }
    const_cast.c_buf = ab->buffer;
    ab->length = 0;
    const_cast.nc_buf[0] = '\0';
}

static void
abuf_resize_by(abuf *ab, size_t size) {
    union {
        const char *c_buf;
        char *nc_buf;
    } const_cast;
    const_cast.c_buf = ab->buffer;

    assert(!ab->buffer || ab->buffer[ab->length] == '\0');

    size_t new_size = ab->length + size;
    char *p = realloc(const_cast.nc_buf, new_size);
    assert(p);
    if(!ab->buffer) {
        assert(ab->length == 0);
        *p = '\0';
    }
    ab->buffer = p;
    assert(ab->buffer[ab->length] == '\0');
    ab->size = new_size;
}

void abuf_add_bytes(abuf *ab, const char *str, size_t size) {
    abuf_resize_by(ab, size + 1);
    union {
        const char *c_buf;
        char *nc_buf;
    } const_cast;
    const_cast.c_buf = ab->buffer;
    memcpy(&const_cast.nc_buf[ab->length], str, size);
    ab->length += size;
    const_cast.nc_buf[ab->length] = '\0';
}

void abuf_str(abuf *ab, const char *str) {
    abuf_add_bytes(ab, str, strlen(str));
}

void abuf_buf(abuf *ab, const abuf *buf) {
    abuf_add_bytes(ab, buf->buffer, buf->length);
}

int abuf_printf(abuf *ab, const char *fmt, ...) {
    va_list ap;

    for(;;) {
        union {
            const char *c_buf;
            char *nc_buf;
        } const_cast;
        const_cast.c_buf = ab->buffer;
        va_start(ap, fmt);
        int ret = vsnprintf(&const_cast.nc_buf[ab->length],
                            ab->size - ab->length, fmt, ap);
        va_end(ap);
        assert(ret >= 0);
        if((size_t)ret < ab->size - ab->length) {
            ab->length += ret;
            assert(ab->buffer[ab->length] == '\0');
            return ret;
        }
        const_cast.nc_buf[ab->length] = '\0'; /* Restore order */
        abuf_resize_by(ab, ret + 1);
    }
}

int abuf_vprintf(abuf *ab, const char *fmt, va_list ap) {
    int ret;
    char *str = 0;

    ret = vasprintf(&str, fmt, ap);
    assert(ret >= 0);
    assert(str != NULL);

    abuf_add_bytes(ab, str, ret);

    free(str);

    return ret;
}

#if !defined(HAVE_DECL_VASPRINTF) || (HAVE_DECL_VASPRINTF == 0)
/* Solaris doesn't have vasprintf(3). */
int
vasprintf(char **ret, const char *fmt, va_list args) {
    int actual_length = -1;
    va_list copy;
    va_copy(copy, args);

    int suggested = vsnprintf(NULL, 0, fmt, args);
    if(suggested >= 0) {
        *ret = malloc(suggested + 1);
        if(*ret) {
            int actual_length = vsnprintf(*ret, suggested + 1, fmt, copy);
            if(actual_length >= 0) {
                assert(actual_length == suggested);
                assert((*ret)[actual_length] == '\0');
            } else {
                free(*ret);
                *ret = 0;
            }
        }
    } else {
        *ret = NULL;
        assert(suggested >= 0); /* Can't function like this */
    }
    va_end(args);

    return actual_length;
}
#endif
