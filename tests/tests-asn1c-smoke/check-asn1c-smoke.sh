#!/usr/bin/env bash

set -x
set -e
set -o pipefail

top_builddir=${top_builddir:-../..}
top_srcdir=${top_srcdir:-../..}

cleanup() {
    rm -rf *.[acho] Makefile.am.* *.mk *.txt *.asn
    rm -f converter-example
}

print_state() {
    local err=$?
    set +x
    set +e
    trap "" EXIT ERR
    echo "Error $err while processing:"
    cat test.asn
    cat status.txt
    echo "FAILED"
    exit $err
}

verify() {
    local type="$1"
    local flags="$2"

    cleanup

    asncmd="${top_builddir}/asn1c/asn1c -Wdebug-compiler -flink-skeletons -S ${top_srcdir}/skeletons $flags test.asn"

    {
    echo "$asncmd"
    echo "${MAKE:-make} -f converter-example.mk"
    } > status.txt

    echo "Module DEFINITIONS::=BEGIN T::=$type END" > test.asn
    $asncmd
    CFLAGS=-O0 ${MAKE:-make} -f converter-example.mk | tail -10
}

verify_type_with_variants() {
    local type="$1"
    for flags in "-no-gen-PER" "-no-gen-OER" "-no-gen-PER -no-gen-OER" ""; do
        for native in "" "-fwide-types"; do
            verify "$type" "$flags $native"
        done
    done
}

verify_compile_and_link_variants() {
    for type in INTEGER "INTEGER(0..1)" "ENUMERATED{foo}" NULL BOOLEAN \
                "BIT STRING" \
                "OBJECT IDENTIFIER" "RELATIVE-OID" \
                "SEQUENCE{f INTEGER}" \
                "CHOICE{f INTEGER}" \
                "OCTET STRING" IA5String "IA5String(SIZE(1))" UTF8String \
                REAL "SET OF INTEGER" "SEQUENCE OF INTEGER"; do
        verify_type_with_variants "$type"
    done
}

trap print_state EXIT ERR
if [ "x$*" = "x" ]; then
    verify_compile_and_link_variants
else
    for type in "$@"; do
        verify_type_with_variants "$type"
    done
fi
set +x
trap '' EXIT ERR

cleanup
echo "OK"
