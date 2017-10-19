#include <assert.h>
#include <oer_support.c>

static char buffer[128];

static int fill_buffer(const void *data, size_t size, void *app_key) {
    size_t *offset = (size_t *)app_key;
    assert(*offset + size < sizeof(buffer));
    memcpy(&buffer[*offset], data, size);
    *offset += size;
    return 0;
}

#define CHECK(a, b) check_round_trip(__LINE__, a, b)

static void
check_round_trip(int lineno, int ok, size_t length) {
    fprintf(stderr, "%03d: Round-trip for %zu\n", lineno, length);

    /* Serialize */
    size_t enc_len = 0;
    ssize_t enc_len_len = oer_serialize_length(length, fill_buffer, &enc_len);
    assert(enc_len_len > 0);
    assert(enc_len == (size_t)enc_len_len);

    /* Deserialize */
    size_t recovered_length = 0;
    for(size_t part = 0; part < enc_len; part++) {
        size_t ret = oer_fetch_length(buffer, part, &recovered_length);
        assert(ret == 0);   /* More data expected. */
    }
    ssize_t dec_len = oer_fetch_length(buffer, enc_len, &recovered_length);
    if(ok) {
        assert(dec_len > 0);
        assert((size_t)dec_len == enc_len);
        if(recovered_length != length) {
            fprintf(stderr,
                    "Round-trip failed %zu->%zu (encoded %zd, decoded %zd)\n",
                    length, recovered_length, enc_len, dec_len);
            assert(recovered_length == length);
        }
    } else {
        assert(dec_len == -1);
    }
}

int main() {
    int bits64 = sizeof(size_t) > 4;

    CHECK(1, 0);
    CHECK(1, 1);
    CHECK(1, 127);
    CHECK(1, 128);
    CHECK(1, 129);
    CHECK(1, 255);
    CHECK(1, 256);
    CHECK(1, 65534);
    CHECK(1, 65535);
    CHECK(1, 65536);
    CHECK(1, 65538);
    CHECK(1, 16000000);
    CHECK(1, 16777216);
    CHECK(bits64, 2147483648);
    CHECK(bits64, 4294967295UL);

}

