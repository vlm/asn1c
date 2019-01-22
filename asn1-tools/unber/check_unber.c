#include "asn1_common.h"
#include "libasn1_unber_tool.h"

// An abstraction for getting data from the in-memory buffer.
struct memory_buffer_stream {
    input_stream_t istream;
    const uint8_t *data;
    size_t size;
    size_t offset;
};

static int memory_buffer_stream_nextChar(input_stream_t *ibs) {
    struct memory_buffer_stream *bs = (struct memory_buffer_stream *)ibs;

    if(bs->offset < bs->size) {
        return bs->data[bs->offset++];
    } else {
        return -1;
    }
}

static off_t memory_buffer_stream_bytesRead(input_stream_t *ibs) {
    struct memory_buffer_stream *bs = (struct memory_buffer_stream *)ibs;

    return (off_t)bs->offset;
}

static int
ignore_vprintf(output_stream_t *os, const char *fmt, va_list ap) {
    (void)os;
    (void)fmt;
    (void)ap;
    // Ignore all output.
    return 0;
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);

int
LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {

    // Read from a memory buffer.
    struct memory_buffer_stream mbs;
    mbs.istream.nextChar = memory_buffer_stream_nextChar;
    mbs.istream.bytesRead = memory_buffer_stream_bytesRead;
    mbs.data = Data;
    mbs.size = Size;
    mbs.offset = 0;

    // Do not print anywhere.
    struct output_stream nullstream;
    nullstream.vprintf = ignore_vprintf;
    nullstream.vprintfError = ignore_vprintf;

    (void)unber_stream("<fuzzed-input>", &mbs.istream, &nullstream);

    return 0;
}

#ifndef  ENABLE_LIBFUZZER
int main() {
    printf("libfuzzer is not compiled-in, pretend the test went OK.\n");
    return 0;
}
#endif
