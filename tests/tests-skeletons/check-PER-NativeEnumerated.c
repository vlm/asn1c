/*
 * Regression test for UPER coding of an extensible NativeEnumerated
 * (skeletons/NativeEnumerated.c), Solution C -- reference-isomorphic lossless
 * relay of unknown extension values.
 *
 * A value added by a newer version of the type (an "unknown extension")
 * must:
 *   - decode successfully (X.680 #6 forbids failing) so an enclosing type
 *     keeps parsing its subsequent fields (forward compatibility);
 *   - be stored as LONG_MAX - wire_index, distinct per index and never
 *     aliasing any value known to this older decoder (even sparse maps);
 *   - re-encode byte-for-byte identically (relay), like the reference toolchain.
 * Known root/extension values must be completely unaffected, and a value
 * outside the reserved region (or handed to a non-extensible enumeration)
 * must still fail to encode.
 *
 * Golden bytes cross-checked against the reference toolchain and asn1tools (base decodes
 * 0x83 to INT_MAX-3 and relays it back to 0x83; full encodes ee1..ee6 to
 * 00/40/80/81/82/83).
 */
#undef NDEBUG
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include <asn_application.h>
#include <NativeEnumerated.h>
#include <per_support.h>

/*
 * base:   E ::= ENUMERATED { ee1(0), ee2(1), ... }
 * (root count 2, so specs->extension = 3, map_count = 2)
 */
static const asn_INTEGER_enum_map_t base_value2enum[] = {
    { 0, 3, "ee1" },
    { 1, 3, "ee2" }
};
static const unsigned int base_enum2value[] = { 0, 1 };
static const asn_INTEGER_specifics_t base_specs = {
    base_value2enum, base_enum2value, 2, 3, 1, 0, 0
};

/*
 * full:   E ::= ENUMERATED { ee1(0), ee2(1), ..., ee3(3), ee4(4), ee5(5), ee6(6) }
 * A newer version that knows the extension additions the base version does not.
 */
static const asn_INTEGER_enum_map_t full_value2enum[] = {
    { 0, 3, "ee1" }, { 1, 3, "ee2" }, { 3, 3, "ee3" },
    { 4, 3, "ee4" }, { 5, 3, "ee5" }, { 6, 3, "ee6" }
};
static const unsigned int full_enum2value[] = { 0, 1, 2, 3, 4, 5 };
static const asn_INTEGER_specifics_t full_specs = {
    full_value2enum, full_enum2value, 6, 3, 1, 0, 0
};

/*
 * sparse: S ::= ENUMERATED { a(0), b(2), ... }
 * The unknown-extension placeholder must not alias the known b(2): storing
 * the extension ordinal instead of LONG_MAX-index would, since ordinal 2
 * equals b's value.
 */
static const asn_INTEGER_enum_map_t sparse_value2enum[] = {
    { 0, 1, "a" },
    { 2, 1, "b" }
};
static const unsigned int sparse_enum2value[] = { 0, 1 };
static const asn_INTEGER_specifics_t sparse_specs = {
    sparse_value2enum, sparse_enum2value, 2, 3, 1, 0, 0
};

/*
 * noext:  N ::= ENUMERATED { x(0), y(1) }  -- NOT extensible.
 */
static const asn_INTEGER_enum_map_t noext_value2enum[] = {
    { 0, 1, "x" },
    { 1, 1, "y" }
};
static const unsigned int noext_enum2value[] = { 0, 1 };
static const asn_INTEGER_specifics_t noext_specs = {
    noext_value2enum, noext_enum2value, 2, 0, 1, 0, 0
};

static const asn_per_constraints_t ext_constraints = {
    { APC_CONSTRAINED | APC_EXTENSIBLE, 1, 1, 0, 1 }, /* value (root index) */
    { APC_UNCONSTRAINED, -1, -1, 0, 0 },
    0, 0
};
static const asn_per_constraints_t noext_constraints = {
    { APC_CONSTRAINED, 1, 1, 0, 1 },
    { APC_UNCONSTRAINED, -1, -1, 0, 0 },
    0, 0
};

static long
decode_uper(int lineno, const asn_INTEGER_specifics_t *specs,
            const asn_per_constraints_t *ct,
            enum asn_dec_rval_code_e expected_code,
            const void *bytes, size_t nbytes) {
    asn_TYPE_descriptor_t td = asn_DEF_NativeEnumerated;
    asn_per_data_t pd;
    asn_dec_rval_t rv;
    long value = -1;
    long *value_ptr = &value;

    td.specifics = specs;
    memset(&pd, 0, sizeof(pd));
    pd.buffer = (const uint8_t *)bytes;
    pd.nboff = 0;
    pd.nbits = 8 * nbytes;

    rv = NativeEnumerated_decode_uper(NULL, &td, ct, (void **)&value_ptr, &pd);
    fprintf(stderr, "%d: uper decode [%02x] => code %d, value %ld\n",
            lineno, *(const uint8_t *)bytes, (int)rv.code, value);
    assert(rv.code == expected_code);
    return value;
}

/*
 * Encode "value" and, on success, return the number of whole bytes produced,
 * copying them into out[]. Returns -1 on ENCODE_FAILED.
 */
static ssize_t
encode_uper(const asn_INTEGER_specifics_t *specs,
            const asn_per_constraints_t *ct, long value, uint8_t *out) {
    asn_TYPE_descriptor_t td = asn_DEF_NativeEnumerated;
    asn_per_outp_t po;
    asn_enc_rval_t er;
    size_t nbytes;

    td.specifics = specs;
    memset(&po, 0, sizeof(po));
    po.buffer = po.tmpspace;
    po.nbits = 8 * sizeof(po.tmpspace);

    er = NativeEnumerated_encode_uper(&td, ct, &value, &po);
    if(er.encoded < 0) return -1;
    nbytes = (po.buffer - po.tmpspace) + (po.nboff ? 1 : 0);
    if(out) memcpy(out, po.tmpspace, nbytes);
    return (ssize_t)nbytes;
}

/* Decode "wire", then re-encode; assert the byte-identical round trip. */
static long
relay_ok(int lineno, const asn_INTEGER_specifics_t *specs,
         unsigned char wire, long expect_value) {
    unsigned char in = wire;
    uint8_t out[8];
    ssize_t n;
    long v = decode_uper(lineno, specs, &ext_constraints, RC_OK, &in, 1);
    assert(v == expect_value);
    n = encode_uper(specs, &ext_constraints, v, out);
    fprintf(stderr, "%d: relay 0x%02x => value %ld => re-encode %zd byte 0x%02x\n",
            lineno, wire, v, n, n > 0 ? out[0] : 0);
    assert(n == 1);
    assert(out[0] == wire);
    return v;
}

int
main(void) {
    long value;
    uint8_t out[8];
    ssize_t n;

    /* ------- Known root values: decode and re-encode unchanged. ------- */
    value = decode_uper(__LINE__, &base_specs, &ext_constraints, RC_OK, "\x00", 1);
    assert(value == 0);                                 /* ee1 */
    value = decode_uper(__LINE__, &base_specs, &ext_constraints, RC_OK, "\x40", 1);
    assert(value == 1);                                 /* ee2 */
    n = encode_uper(&base_specs, &ext_constraints, 0, out);
    assert(n == 1 && out[0] == 0x00);
    n = encode_uper(&base_specs, &ext_constraints, 1, out);
    assert(n == 1 && out[0] == 0x40);

    /*
     * ------- Unknown extension values: lossless relay. -------
     * A newer peer's ee3/ee4/ee6 arrive as extension indices 0/1/3. They must
     * decode (RC_OK) into LONG_MAX-index (distinct per index, no aliasing) and
     * re-encode to the identical byte.
     */
    relay_ok(__LINE__, &base_specs, 0x80, LONG_MAX);    /* ext index 0 */
    relay_ok(__LINE__, &base_specs, 0x81, LONG_MAX - 1);/* ext index 1 */
    relay_ok(__LINE__, &base_specs, 0x83, LONG_MAX - 3);/* ext index 3 (ee6) */

    /* The stored value is recognised as an unknown-extension placeholder. */
    assert(ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(LONG_MAX));
    assert(ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(LONG_MAX - 3));
    assert(!ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(0));
    assert(!ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(LONG_MAX - 70000));

    /*
     * ------- Sparse enumeration { a(0), b(2), ... }: no aliasing. -------
     * The known b(2) still decodes to 2; an unknown extension (ordinal 0 that
     * would collide with b under an ordinal scheme) must become LONG_MAX and
     * relay back to 0x80.
     */
    value = decode_uper(__LINE__, &sparse_specs, &ext_constraints, RC_OK, "\x40", 1);
    assert(value == 2);                                 /* known b(2) */
    value = relay_ok(__LINE__, &sparse_specs, 0x80, LONG_MAX);
    assert(value != 2);                                 /* must not alias b(2) */

    /*
     * ------- Newer version knows the additions: byte-exact encoding. -------
     * full encodes ee1..ee6 to 00/40/80/81/82/83 (three-tool golden), and
     * decodes 0x81 to the real value 4 (a known extension now, not unknown).
     */
    {
        static const long vals[6]        = { 0, 1, 3, 4, 5, 6 };
        static const unsigned char gold[6] = { 0x00, 0x40, 0x80, 0x81, 0x82, 0x83 };
        int i;
        for(i = 0; i < 6; i++) {
            n = encode_uper(&full_specs, &ext_constraints, vals[i], out);
            fprintf(stderr, "full encode %ld => %zd byte 0x%02x (want 0x%02x)\n",
                    vals[i], n, n > 0 ? out[0] : 0, gold[i]);
            assert(n == 1 && out[0] == gold[i]);
        }
        value = decode_uper(__LINE__, &full_specs, &ext_constraints, RC_OK, "\x81", 1);
        assert(value == 4);                             /* known ee4 */
    }

    /*
     * ------- Cross-header relay. -------
     * A value the base version could not understand (0x83) is stored by base,
     * then handed to the full version's encoder. Even though the full version
     * knows extension index 3 as ee6, the relay path replays the index (the
     * index is version-stable), producing the identical 0x83.
     */
    value = decode_uper(__LINE__, &base_specs, &ext_constraints, RC_OK, "\x83", 1);
    assert(value == LONG_MAX - 3);
    n = encode_uper(&full_specs, &ext_constraints, value, out);
    fprintf(stderr, "cross-header relay: base stored %ld => full encodes %zd byte 0x%02x\n",
            value, n, n > 0 ? out[0] : 0);
    assert(n == 1 && out[0] == 0x83);

    /*
     * ------- Negative cases. -------
     * A value below the reserved region (index would exceed 65535) is not a
     * valid relay placeholder and must fail to encode; a reserved-region value
     * handed to a NON-extensible enumeration must also fail.
     */
    assert(encode_uper(&base_specs, &ext_constraints, LONG_MAX - 70000, out) == -1);
    assert(encode_uper(&noext_specs, &noext_constraints, LONG_MAX, out) == -1);
    /* A plain unknown integer (not a placeholder, not a known value) fails. */
    assert(encode_uper(&base_specs, &ext_constraints, 42, out) == -1);

    printf("Finished OK\n");
    return 0;
}
