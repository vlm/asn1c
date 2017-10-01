/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include <asn_internal.h>
#include <asn_random_fill.h>
#include <constr_TYPE.h>

int
asn_random_fill(const struct asn_TYPE_descriptor_s *td, void **struct_ptr,
                size_t length) {

    if(td && td->op->random_fill) {
        asn_random_fill_result_t res =
            td->op->random_fill(td, struct_ptr, 0, length);
        return (res.code == ARFILL_OK) ? 0 : -1;
    } else {
        return -1;
    }
}

intmax_t
asn_random_between(intmax_t a, intmax_t b) {
    assert(a <= b);
    assert((b-a) < RAND_MAX);
    if(a == b) return a;
    return a + (random() % (b - a + 1));
}
