/*
 * Regression test for the ASN_REJECT_UNKNOWN_EXTENSIONS escape hatch
 * (see asn_internal.h). This program is only ever built with
 * -DASN_REJECT_UNKNOWN_EXTENSIONS defined (and linked against the
 * skeletons library variant compiled the same way, libasn1cskeletons_strict.la
 * -- see tests/tests-skeletons/Makefile.am and skeletons/Makefile.am), so
 * that the three unknown-extension decode sites it exercises are actually
 * compiled with the macro:
 *
 *   1. constr_CHOICE.c   CHOICE_decode_uper()  -- unknown extension alternative
 *   2. NativeEnumerated.c NativeEnumerated_decode_uper() -- unknown ext value
 *   3. constr_CHOICE_oer.c CHOICE_decode_oer() -- unknown extension alternative
 *
 * Each wire below is a genuine, complete encoding of "a newer peer selected
 * an extension addition this (older, strict) decoder does not know about."
 * Without the macro (see git history / HANDOFF.md), each of these decodes
 * RC_OK (skipping or relaying the unknown material for forward
 * compatibility, per X.691/X.696). With ASN_REJECT_UNKNOWN_EXTENSIONS
 * defined, all three must cleanly RC_FAIL instead.
 */
#undef NDEBUG
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include <asn_application.h>
#include <per_support.h>
#include <constr_CHOICE.h>
#include <NativeEnumerated.h>

#ifndef ASN_REJECT_UNKNOWN_EXTENSIONS
#error "check-PER-strict-ext must be built with -DASN_REJECT_UNKNOWN_EXTENSIONS"
#endif

/* ===================================================================== *
 * Site 2: NativeEnumerated_decode_uper(), unknown extension value.
 * Reuses the base_specs/wire from check-PER-NativeEnumerated.c: a
 * 2-member root ENUMERATED, extensible, receiving wire 0x80 (extension
 * bit + nsnnwn index 0) from a peer that added a 3rd member. Without the
 * macro this decodes RC_OK, storing LONG_MAX (see
 * check-PER-NativeEnumerated.c's "relay_ok(0x80, LONG_MAX)").
 * ===================================================================== */
static const asn_INTEGER_enum_map_t ne_base_value2enum[] = {
    { 0, 3, "ee1" },
    { 1, 3, "ee2" }
};
static const unsigned int ne_base_enum2value[] = { 0, 1 };
static const asn_INTEGER_specifics_t ne_base_specs = {
    ne_base_value2enum, ne_base_enum2value, 2, 3, 1, 0, 0
};
static const asn_per_constraints_t ne_ext_constraints = {
    { APC_CONSTRAINED | APC_EXTENSIBLE, 1, 1, 0, 1 }, /* value (root index) */
    { APC_UNCONSTRAINED, -1, -1, 0, 0 },
    0, 0
};

static void
check_NativeEnumerated_strict(void) {
    asn_TYPE_descriptor_t td;
    asn_per_data_t pd;
    asn_dec_rval_t rv;
    long value = -1;
    long *value_ptr = &value;
    static const uint8_t wire[1] = { 0x80 }; /* ext bit + nsnnwn index 0 */

    memset(&td, 0, sizeof(td));
    td.name = "E";
    td.specifics = &ne_base_specs;

    memset(&pd, 0, sizeof(pd));
    pd.buffer = wire;
    pd.nboff = 0;
    pd.nbits = 8 * sizeof(wire);

    rv = NativeEnumerated_decode_uper(NULL, &td, &ne_ext_constraints,
                                       (void **)&value_ptr, &pd);
    fprintf(stderr,
            "NativeEnumerated strict: wire 0x%02x => code %d (want RC_FAIL)\n",
            wire[0], (int)rv.code);
    assert(rv.code == RC_FAIL);
}

/* ===================================================================== *
 * Shared minimal CHOICE scaffolding for sites 1 and 3.
 *
 * elements_count == 0 and ext_start == 0 guarantee that ANY selected
 * alternative index is treated as an unknown extension addition -- the
 * decoders never dereference td.elements, so it is safely left NULL/empty.
 * ===================================================================== */
typedef struct {
    int present;
    asn_struct_ctx_t _asn_ctx;
} StrictChoice_t;

/*
 * bsearch() (used internally by CHOICE_decode_oer() to look up the tag)
 * requires a non-NULL base pointer even when nmemb == 0, so tag2el must
 * point somewhere valid; its contents are never read since tag2el_count
 * is 0.
 */
static const asn_TYPE_tag2member_t strict_choice_empty_tag2el[1] = {
    { 0, 0, 0, 0 }
};

static const asn_CHOICE_specifics_t strict_choice_specs = {
    sizeof(StrictChoice_t),             /* struct_size */
    offsetof(StrictChoice_t, _asn_ctx), /* ctx_offset */
    offsetof(StrictChoice_t, present),  /* pres_offset */
    sizeof(int),                        /* pres_size */
    strict_choice_empty_tag2el, 0,      /* tag2el, tag2el_count: none known */
    0, 0,                                /* to/from_canonical_order */
    0                                    /* ext_start: extensible, addition 0 unknown */
};

/* ===================================================================== *
 * Site 1: CHOICE_decode_uper(), unknown extension alternative.
 *
 * Wire: [extension bit=1][nsnnwn index=0][open type: length=1, content=0xAA]
 * built with the same per_put_few_bits()/uper_put_nsnnwn() primitives the
 * decoder's counterpart (uper_get_nsnnwn/uper_get_length) reads, so byte
 * boundaries need not be hand-computed. Without the macro this decodes
 * RC_OK (open type skipped, CHOICE presented as absent -- see the
 * "Phase 4" comment in constr_CHOICE.c's CHOICE_decode_uper()).
 * ===================================================================== */
static const asn_per_constraints_t choice_ext_constraints = {
    { APC_EXTENSIBLE, 0, 0, 0, 0 },     /* value: extensible, no root range */
    { APC_UNCONSTRAINED, -1, -1, 0, 0 },
    0, 0
};

static void
check_CHOICE_uper_strict(void) {
    asn_TYPE_descriptor_t td;
    asn_per_outp_t po;
    asn_per_data_t pd;
    asn_dec_rval_t rv;
    void *st = NULL;
    uint8_t wire[8];
    size_t nbytes;

    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    assert(per_put_few_bits(&po, 1, 1) == 0);   /* extension bit */
    assert(uper_put_nsnnwn(&po, 0) == 0);        /* extension index 0 */
    assert(per_put_few_bits(&po, 1, 8) == 0);    /* open type length = 1 */
    assert(per_put_few_bits(&po, 0xAA, 8) == 0); /* open type content */

    nbytes = (size_t)(po.buffer - po.tmpspace) + (po.nboff ? 1 : 0);
    assert(nbytes <= sizeof(wire));
    memcpy(wire, po.tmpspace, nbytes);

    memset(&td, 0, sizeof(td));
    td.name = "C";
    td.specifics = &strict_choice_specs;

    memset(&pd, 0, sizeof(pd));
    pd.buffer = wire;
    pd.nboff = 0;
    pd.nbits = 8 * nbytes;

    rv = CHOICE_decode_uper(NULL, &td, &choice_ext_constraints, &st, &pd);
    fprintf(stderr, "CHOICE UPER strict: %zu-byte wire => code %d (want RC_FAIL)\n",
            nbytes, (int)rv.code);
    assert(rv.code == RC_FAIL);
    if(st) free(st);
}

/* ===================================================================== *
 * Site 3: CHOICE_decode_oer(), unknown extension alternative.
 *
 * Wire: [tag=0x05][open type: length=1, content=0xAA]. tag2el_count == 0
 * guarantees the tag is never found among known alternatives, so (with
 * ext_start != -1) this always takes the "unknown extension" branch.
 * Without the macro this decodes RC_OK (open type skipped, CHOICE
 * presented as absent).
 * ===================================================================== */
static void
check_CHOICE_oer_strict(void) {
    asn_TYPE_descriptor_t td;
    asn_dec_rval_t rv;
    void *st = NULL;
    static const uint8_t wire[3] = { 0x05, 0x01, 0xAA };

    memset(&td, 0, sizeof(td));
    td.name = "C";
    td.specifics = &strict_choice_specs;

    rv = CHOICE_decode_oer(NULL, &td, NULL, &st, wire, sizeof(wire));
    fprintf(stderr, "CHOICE OER strict: wire => code %d (want RC_FAIL)\n",
            (int)rv.code);
    assert(rv.code == RC_FAIL);
    if(st) free(st);
}

int
main(void) {
    check_NativeEnumerated_strict();
    check_CHOICE_uper_strict();
    check_CHOICE_oer_strict();
    printf("Finished OK\n");
    return 0;
}
