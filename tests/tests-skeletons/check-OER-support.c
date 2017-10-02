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

static void
check_round_trip(size_t length) {
    fprintf(stderr, "Round-trip for %zu\n", length);

    /* Serialize */
    size_t enc_len = 0;
    size_t enc_len_len = oer_serialize_length(length, fill_buffer, &enc_len);
    assert(enc_len == enc_len_len);

    /* Deserialize */
    size_t recovered_length = 0;
    for(size_t part = 0; part < enc_len; part++) {
        size_t ret = oer_fetch_length(buffer, part, &recovered_length);
        assert(ret == 0);   /* More data expected. */
    }
    size_t dec_len = oer_fetch_length(buffer, enc_len, &recovered_length);
    assert(dec_len == enc_len);
    if(recovered_length != length) {
        fprintf(stderr, "Round-trip failed %zu->%zu (encoded %zd, decoded %zd)\n",
                length, recovered_length, enc_len, dec_len);
        assert(recovered_length == length);
    }
}

int main() {

    check_round_trip(0);
    check_round_trip(1);
    check_round_trip(127);
    check_round_trip(128);
    check_round_trip(129);
    check_round_trip(255);
    check_round_trip(256);
    check_round_trip(65534);
    check_round_trip(65535);
    check_round_trip(65536);
    check_round_trip(65538);
    check_round_trip(16000000);
    check_round_trip(16777216);
    check_round_trip(2147483648);
    check_round_trip(4294967296);

}

