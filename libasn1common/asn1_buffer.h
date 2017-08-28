#ifndef	ASN1_BUFFER_H
#define	ASN1_BUFFER_H

#include <stdarg.h>

/*
 * Your typical dynamic character string buffer.
 */
typedef struct {
    const char *buffer;
    size_t length;
    size_t size;
} abuf;

/*
 * Create and destroy the buffer.
 */
abuf *abuf_new(void);
void abuf_free(abuf *);

/*
 * Erase contents of the buffer (without destroying it).
 */
void abuf_clear(abuf *);

/*
 * Add characters to the buffer.
 */
void abuf_str(abuf *, const char *str);
void abuf_buf(abuf *, const abuf *);
void abuf_add_bytes(abuf *, const char *, size_t);
int abuf_printf(abuf *, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));
int abuf_vprintf(abuf *, const char *fmt, va_list);

#endif	/* ASN1_BUFFER_H */
