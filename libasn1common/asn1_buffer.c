#include <sys/types.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "asn1_buffer.h"

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
abuf_resize_by(abuf *ab, size_t add_bytes) {
    union {
        const char *c_buf;
        char *nc_buf;
    } const_cast;
    const_cast.c_buf = ab->buffer;

    assert(ab->buffer[ab->length] == '\0');

    size_t new_size = ab->length + add_bytes;
    char *p = realloc(const_cast.nc_buf, new_size);
    assert(p);
    ab->buffer = p;
    assert(ab->buffer[ab->length] == '\0');
    ab->size = new_size;
}

void abuf_str(abuf *ab, const char *str) {
    abuf_printf(ab, "%s", str);
}

void abuf_buf(abuf *ab, const abuf *buf) {
    abuf_printf(ab, "%s", buf->buffer);
}

void abuf_printf(abuf *ab, const char *fmt, ...) {
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
            break;
        }
        const_cast.nc_buf[ab->length] = '\0'; /* Restore order */
        abuf_resize_by(ab, ret + 1);
    }
}

