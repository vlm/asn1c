// asn1c test.asn1 -no-gen-example -no-gen-OER -D ./gen
// cc -o program -I. -I./gen -m32 *.c gen/*.c -DASN_DISABLE_OER_SUPPORT=1

#include "MyCar.h"
#include <stdio.h>
#include <stdint.h>

static int decode(MyCar_t *mycar, uint8_t *buf, size_t size)
{
    asn_dec_rval_t ret;

    ret = uper_decode(NULL, &asn_DEF_MyCar, (void **) &mycar, buf, size, 0, 0);
    if(ret.code != RC_OK) {
        fprintf(stderr, "code=%i\n", ret.code);
        return -1;
    }

    printf("UPER decode success!\n");
    printf("num=%" PRIu32 "\n", (uint32_t)mycar->id);
    return 0;
}

int main() 
{
    int rc;
    uint8_t buf[100];
    uint64_t stamp1, stamp2;
    size_t size = sizeof(buf);
    asn_enc_rval_t ret;
    MyCar_t car1, car2;

    memset(&car1, 0, sizeof(car1));
    memset(&car2, 0, sizeof(car2));

    printf("sizeof(long) = %zd\n", sizeof(long));
    printf("sizeof(long long) = %zd\n", sizeof(long long));
    printf("sizeof(intmax_t) = %zd\n", sizeof(intmax_t));

    printf("LONG_MAX = %lu\n", LONG_MAX);
    printf("LONG_MIN = %li\n", LONG_MIN);
    printf("ULONG_MAX = %lu\n", ULONG_MAX);

    printf("LLONG_MAX = %lli\n", LLONG_MAX);
    printf("LLONG_MIN = %lli\n", LLONG_MIN);
    printf("ULLONG_MAX = %llu\n", ULLONG_MAX);

    car1.id = UINT32_MAX;
    stamp1 = 4398046511103ULL;
    asn_umax2INTEGER(&car1.detectionTime, stamp1);

    ret = asn_encode_to_buffer(0, ATS_UNALIGNED_BASIC_PER, &asn_DEF_MyCar, &car1, buf, size);
    if(ret.encoded < 0) {
        fprintf(stderr, "ERROR ASN(uper) encode failed(%s); ret=%i\n", ret.failed_type->name, (int)ret.encoded);
        exit(EXIT_FAILURE);
    }
    else {
        printf("ASN(uper) encode success\n");
    }

    ret = uper_encode_to_buffer(&asn_DEF_MyCar, NULL, &car1, buf, sizeof(buf));
    if(ret.encoded < 0) {
        fprintf(stderr, "ERROR UPER encode failed(%s); ret=%i\n", ret.failed_type->name, (int)ret.encoded);
        exit(EXIT_FAILURE);
    }
    else {
        printf("UPER encode success\n");
    }

    rc = decode(&car2, buf, size);
    if (rc) {
        exit(EXIT_FAILURE);
    }

    printf("station=%lu\n", car2.id);
    assert(car2.id == car1.id);

    asn_INTEGER2umax(&car2.detectionTime, &stamp2);
    printf("detection=%" PRIu64 "\n", stamp2);
    assert(stamp2 == stamp1);

    printf("+++++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++ SUCCESS ;-) +++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++\n");
    return EXIT_SUCCESS;
}

