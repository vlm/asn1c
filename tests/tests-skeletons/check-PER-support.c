#include <assert.h>
#include <per_support.h>

static void put(asn_per_outp_t *po, size_t length) {
    fprintf(stderr, "put(%zd)\n", length);
    do {
        int need_eom = 123;
        ssize_t may_write = uper_put_length(po, length, &need_eom);
        fprintf(stderr, "  put %zu\n", may_write);
        assert(may_write >= 0);
        assert(may_write <= length);
        assert(need_eom != 123);
        length -= may_write;
        if(need_eom) {
            assert(length == 0);
            if(uper_put_length(po, 0, 0)) {
                assert(!"Unreachable");
            }
            fprintf(stderr, "  put EOM 0\n");
        }
    } while(length);
    fprintf(stderr, "put(...) in %zu bits\n", po->nboff);
    assert(po->nboff != 0);
    assert(po->flushed_bytes == 0);
}

static size_t get(asn_per_outp_t *po) {
    asn_bit_data_t data;
    memset(&data, 0, sizeof(data));
    data.buffer = po->tmpspace;
    data.nboff = 0;
    data.nbits = 8 * (po->buffer - po->tmpspace) + po->nboff;

    fprintf(stderr, "get(): %s\n", asn_bit_data_string(&data));

    size_t length = 0;
    int repeat = 0;
    do {
        ssize_t n = uper_get_length(&data, -1, 0, &repeat);
        fprintf(stderr, "  get = %zu +%zd\n", length, n);
        assert(n >= 0);
        length += n;
    } while(repeat);
    fprintf(stderr, "get() = %zu\n", length);

    return length;
}

static void
check_round_trip(size_t length) {
    fprintf(stderr, "\nRound-trip for %zu\n", length);
    asn_per_outp_t po;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    put(&po, length);
    size_t recovered = get(&po);

    assert(recovered == length);
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
    check_round_trip(128000);
    for(size_t i = 1; i < 10; i++) {
        check_round_trip(i*16384 - 1);
        check_round_trip(i*16384);
        check_round_trip(i*16384 + 1);
    }

}

