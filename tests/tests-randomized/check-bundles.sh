#!/bin/sh

#
# Create an ASN.1 source code project for each line in each of the
# bundles/*.txt files, compile and run that it can be encoded, decoded,
# and fuzzed (if fuzzing is available).
#

set -e

usage() {
    echo "Usage:"
    echo "  $0 -h"
    echo "  $0 [--dirty] -t \"<ASN.1 text defining type T, in string form>\""
    echo "  $0 [--dirty] bundles/<bundle-name.txt> [<line>]"
    echo "Where options are:"
    echo "  -h              Show this help screen"
    echo "  -e <syntax>     Verify a given encoding explicitly (default is ALL)"
    echo "  --asn1c <flag>  Add this flag to asn1c"
    echo "  --dirty         Reuse compile results from the previous run(s)"
    echo "  -t <ASN.1>      Run this particular typel"
    echo "Examples:"
    echo "  $0 -t UTF8String"
    echo "  $0 -t \"T ::= INTEGER (0..1)\""
    echo "  $0 bundles/01-INTEGER-bundle.txt 3"
    exit 1
}

RNDTEMP=.tmp.random

srcdir="${srcdir:-.}"
abs_top_srcdir="${abs_top_srcdir:-$(pwd)/../../}"
abs_top_builddir="${abs_top_builddir:-$(pwd)/../../}"

tests_succeeded=0
tests_failed=0
stop_after_failed=1  # We stop after 3 failures.
need_clean_before_bundle=1  # Clean before testing a bundle file
need_clean_before_test=1    # Before each line in a bundle file
encodings=""    # Default is to verify all supported ASN.1 transfer syntaxes
parallelism=4
asn1c_flags=""

make_clean_before_bundle() {
    test "${need_clean_before_bundle}" = "1" && rm -rf ${RNDTEMP}
}

make_clean_before_test() {
    test "${need_clean_before_test}" = "1" && rm -rf ${RNDTEMP}
}

# Get all the type-bearding lines in file and process them individually
verify_asn_types_in_file() {
    local filename="$1"
    local need_line="$2"
    test "x$filename" != "x" || usage

    make_clean_before_bundle

    echo "Open [$filename]"
    local line=0
    while read -r asn; do
        line=$((line+1))
        if echo "$asn" | sed -e 's/--.*//;' | grep -vqi "[A-Z]"; then
            # Ignore lines consisting of just comments.
            continue;
        fi
        if [ "x$need_line" != "x" ] && [ "$need_line" != "$line" ]; then
            # We need a different line.
            continue;
        fi
        verify_asn_type "$asn" "in $filename $line"
        if [ "${tests_failed}" = "${stop_after_failed}" ]; then
            echo "STOP after ${tests_failed} failures, OK ${tests_succeeded}"
            exit 1
        fi
    done < "$filename"
}

verify_asn_type() {
    local asn="$1"
    shift
    local where="$*"
    test "x$asn" != "x" || usage

    if echo "$asn" | grep -qv "::="; then
        asn="T ::= $asn"
    fi
    echo "Testing [$asn] ${where}"

    mkdir -p ${RNDTEMP}
    if (set -e && cd ${RNDTEMP} && compile_and_test "$asn" "${where}"); then
        echo "OK [$asn] ${where}"
        tests_succeeded=$((tests_succeeded+1))
    else
        tests_failed=$((tests_failed+1))
        echo "FAIL [$asn] ${where}"
    fi
}

# compile_and_test "<text>" "<where found>" [<asn.1 flags>]
compile_and_test() {
    if [ "x${asn1c_flags}" != "x" ]; then
        if ! compile_and_test_with "$@" ${asn1c_flags} ; then
            return 1
        fi
    else
        if ! compile_and_test_with "$@" ; then
            echo "Can't compile and test narrow"
            return 1
        fi

        if ! compile_and_test_with "$@" "-fwide-types"; then
            echo "Can't compile and test wide"
            return 2
        fi
    fi

    return 0
}

compile_and_test_with() {
    local asn="$1"
    local where="$2"
    shift 2

    make_clean_before_test

    if ! asn_compile "$asn" "$where" "$@"; then
        echo "Cannot compile ASN.1 $asn"
        return 1
    fi

    rm -f random-test-driver.o
    rm -f random-test-driver
    if ! make -j${parallelism}; then
        echo "Cannot compile C for $asn in ${RNDTEMP}"
        return 2
    fi

    # Maximum size of the random data
    local rmax=$(echo "$asn" | sed -Ee '/RMAX/!d;s/.*RMAX=([0-9]+).*/\1/')
    if [ "0${rmax}" -lt 1 ]; then rmax=128; fi

    echo "Checking random data encode-decode"
    local round_trip_check_cmd="${ASAN_ENV_FLAGS} ./random-test-driver -s ${rmax} ${encodings} -c"
    if ! eval "$round_trip_check_cmd"; then
        if [ "x$CC" = "x" ]; then CCSTR=""; else CCSTR="CC=${CC} "; fi
        echo "RETRY:"
        echo "(cd ${RNDTEMP} && ${CCSTR}CFLAGS=\"${LIBFUZZER_CFLAGS} ${CFLAGS}\" make && ${ASAN_ENV_FLAGS} ./random-test-driver -s ${rmax} ${encodings} -c)"
        return 3
    fi

    echo "Generating new random data"
    rm -rf random-data
    cmd="${ASAN_ENV_FLAGS} UBSAN_OPTIONS=print_stacktrace=1"
    cmd="${cmd} ./random-test-driver -s ${rmax} ${encodings} -g random-data"
    if ! eval "$cmd" ; then
        echo "RETRY:"
        echo "(cd ${RNDTEMP} && $cmd)"
        return 4
    fi

    # Do a LibFuzzer based testing
    local fuzz_time=10
    local fuzz_cmd="${ASAN_ENV_FLAGS} UBSAN_OPTIONS=print_stacktrace=1"
    fuzz_cmd="${fuzz_cmd} ./random-test-driver"
    fuzz_cmd="${fuzz_cmd} -timeout=3 -max_total_time=${fuzz_time} -max_len=128"

    if ! grep -q "^fuzz:" Makefile ; then
        local fuzz_targets=$(echo random-data/* | sed -e 's/random-data./fuzz-/g')
        {
        echo "fuzz: $fuzz_targets"
        echo "fuzz-%: random-data/% random-test-driver"
        echo "	ASN1_DATA_DIR=\$< ${fuzz_cmd} \$<"
        } >> Makefile
    fi

    # If LIBFUZZER_CFLAGS are properly defined, do the fuzz test as well
    if echo "${LIBFUZZER_CFLAGS}" | grep -qi "[a-z]"; then

        echo "Recompiling for fuzzing..."
        rm -f random-test-driver.o
        rm -f random-test-driver
        CFLAGS="${LIBFUZZER_CFLAGS} ${CFLAGS}" make -j${parallelism}

        echo "Fuzzing will take a multiple of $fuzz_time seconds..."
        if ! make -j${parallelism} fuzz ; then
            echo "RETRY:"
            echo "(cd ${RNDTEMP} && CC=${CC} CFLAGS=\"${LIBFUZZER_CFLAGS} ${CFLAGS}\" make fuzz)"
            return 5
        fi
    fi

    return 0
}

asn_compile() {
    local asn="$1"
    local where="$2"
    shift 2

    # Create "INTEGER (1..2)" from "T ::= INTEGER (1..2) -- RMAX=5"
    local short_asn=$(echo "$asn" | sed -e 's/ *--.*//;s/RMAX=[^ ]* //;')
    if [ $(echo "$short_asn" | grep -c "::=") = 1 ]; then
        short_asn=$(echo "$short_asn" | sed -e 's/.*::= *//')
    fi

    test ! -f Makefile.am   # Protection from accidental clobbering
    echo "Test DEFINITIONS ::= BEGIN $asn" > test.asn1
    echo "-- ${where}" >> test.asn1
    echo "END" >> test.asn1
    if ! "${abs_top_builddir}/asn1c/asn1c" -S "${abs_top_srcdir}/skeletons" \
        -gen-OER -gen-PER "$@" test.asn1
    then
        return 1
    fi
    rm -f converter-example.c
    ln -sf ../random-test-driver.c || cp ../random-test-driver.c .
    echo "CFLAGS+= -DASN1_TEXT='$short_asn'" > Makefile
    sed -e 's/converter-example/random-test-driver/' \
        < Makefile.am.example >> Makefile
    echo "Makefile.am.example -> Makefile"
}

# Command line parsing
while :; do
    case "$1" in
        -h) usage ;;
        --asn1c) asn1c_flags="${asn1c_flags} $2"; shift 2; continue ;;
        --dirty)
            need_clean_before_bundle=0
            need_clean_before_test=0
            shift
            continue
            ;;
        -e) encodings="${encodings} -e $2"; shift 2; continue;;
        -j) parallelism="$1"; shift 2; continue;;
        -t)
            parallelism=1   # Better for debuggability
            verify_asn_type "$2" || exit 1 ;;
        "")
            for bundle in $(echo bundles/*txt | sort -nr); do
                verify_asn_types_in_file "$bundle"
            done
        ;;
        *)
            verify_asn_types_in_file "$@"
        ;;
    esac
    break
done

if [ "$tests_succeeded" != "0" ] && [ "$tests_failed" = "0" ]; then
    echo "OK $tests_succeeded tests"
else
    echo "FAILED $tests_failed tests, OK $tests_succeeded tests"
    exit 1
fi
