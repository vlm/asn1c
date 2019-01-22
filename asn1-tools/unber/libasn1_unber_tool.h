/*
 * Copyright (c) 2004-2019 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/* Set global options. */
void set_minimalistic_output(int v);
void set_single_type_decoding(int v);
void set_pretty_printing(int v);
int set_skip_bytes(long v);
int set_indent_size(int indent_size);

/*
 * Convert BER-encoded file into the low level non-standard XML-like structure.
 * Primarily used for manual debugging.
 */
int unber_file(const char *fname);

typedef struct input_stream {
    /*
     * Return the next character as if it were an unsigned int converted to
     * an int. Returns -1 on EOF or error.
     */
    int (*nextChar)(struct input_stream *);
    /*
     * Return the number of bytes consumed from the stream so far.
     */
    off_t (*bytesRead)(struct input_stream *);
} input_stream_t;

typedef struct output_stream {
    /*
     * Return the next character as if it were an unsigned int converted to
     * an int. Returns -1 on EOF or error.
     */
    int (*vprintf)(struct output_stream *, const char *fmt, va_list);
    int (*vprintfError)(struct output_stream *, const char *fmt, va_list);
} output_stream_t;

/*
 * Lower level converter.
 */
int unber_stream(const char *fname, input_stream_t *, output_stream_t *);

/*
 * Decode the TLV given by the given string.
 */
int decode_tlv_from_hex_string(const char *datastring);

