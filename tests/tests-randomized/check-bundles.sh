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
    echo "  $0 -t \"<ASN.1 definition for type T, in string form>\""
    echo "  $0 bundles/<bundle-name.txt> [<line>]"
    echo "Examples:"
    echo "  $0 -t UTF8String"
    echo "  $0 -t \"T ::= INTEGER (0..1)\""
    echo "  $0 bundles/01-INTEGER-bundle.txt 3"
    exit 1
}

tests_succeeded=0
tests_failed=0

# Get all the type-bearding lines in file and process them individually
verify_asn_types_in_file() {
    local filename="$1"
    local need_line="$2"
    test "x$filename" != "x" || usage
    echo "Open [$filename]"
    local line=0
    while read asn; do
        line=$((line+1))
        if echo "$asn" | sed -e 's/--.*//;' | grep -vqi "[A-Z]"; then
            # Ignore lines consisting of just comments.
            continue;
        fi
        if [ "x$need_line" != "x" -a "$need_line" != "$line" ]; then
            # We need a different line.
            continue;
        fi
        verify_asn_type "$asn" "in $filename $line"
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

    mkdir -p .tmp.random
    if (cd .tmp.random && compile_and_test "$asn" "$@"); then
        echo "OK [$asn] ${where}"
        tests_succeeded=$((tests_succeeded+1))
    else
        tests_failed=$((tests_failed+1))
        echo "FAIL [$asn] ${where}"
    fi
}

compile_and_test() {
    local asn="$1"
    shift

    if ! asn_compile "$asn" "$@"; then
        echo "Cannot compile ASN.1 $asn"
        return 1
    fi

    rm -f random-test-driver.o
    rm -f random-test-driver
    if ! make -j4; then
        echo "Cannot compile C for $asn in .tmp.random"
        return 2
    fi

    echo "Checking random data encode-decode"
    if ! eval ${ASAN_ENV_FLAGS} ./random-test-driver -c; then
        return 3
    fi

    # If LIBFUZZER_CFLAGS are properly defined, do the fuzz test as well
    if echo "${LIBFUZZER_CFLAGS}" | grep -qi "[a-z]"; then
        echo "Generating new random data"
        rm -rf random-data
        ./random-test-driver -g random-data

        echo "Recompiling for fuzzing..."
        rm -f random-test-driver.o
        rm -f random-test-driver
        CFLAGS="${LIBFUZZER_CFLAGS} ${CFLAGS}" make

        # Do a LibFuzzer based testing
        fuzz_time=10
        echo "Fuzzing will take $fuzz_time seconds..."
        set -x
        eval ${ASAN_ENV_FLAGS} UBSAN_OPTIONS=print_stacktrace=1 \
        ./random-test-driver \
        -timeout=3 -max_total_time=${fuzz_time} -max_len=128
    fi

    return 0;
}

srcdir="${srcdir:-.}"
abs_top_srcdir="${abs_top_srcdir:-$(pwd)/../../}"
abs_top_builddir="${abs_top_builddir:-$(pwd)/../../}"

asn_compile() {
    local asn="$1"
    shift
    test ! -f Makefile.am   # Protection from accidental clobbering
    echo "Test DEFINITIONS ::= BEGIN $asn" > test.asn1
    echo "END" >> test.asn1
    ${abs_top_builddir}/asn1c/asn1c -S ${abs_top_srcdir}/skeletons \
        -gen-OER -gen-PER test.asn1
    rm -f converter-example.c
    ln -sf ../random-test-driver.c || cp ../random-test-driver.c .
    sed -e 's/converter-example/random-test-driver/' \
        < Makefile.am.example > Makefile
    echo "Makefile.am.example -> Makefile"
}

# Command line parsing
case "$1" in
    -h) usage ;;
    -t) verify_asn_type "$2" || exit 1;;
    "")
        for bundle in bundles/*txt; do
            verify_asn_types_in_file "$bundle"
        done
    ;;
    *)
        verify_asn_types_in_file "$@"
    ;;
esac

if [ "$tests_succeeded" != "0" -a "$tests_failed" = "0" ]; then
    echo "OK $tests_succeeded tests"
else
    echo "FAILED $tests_failed tests, OK $tests_succeeded tests"
    exit 1
fi
