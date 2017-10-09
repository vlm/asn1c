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
abs_top_srcdir="${abs_top_srcdir:-`pwd`/../../}"
abs_top_builddir="${abs_top_builddir:-`pwd`/../../}"

tests_succeeded=0
tests_failed=0
stop_after_failed=1  # We stop after 3 failures.
need_clean_before_bundle=1  # Clean before testing a bundle file
need_clean_before_test=0    # Before each line in a bundle file
encodings=""    # Default is to verify all supported ASN.1 transfer syntaxes
parallelism=4
asn1c_flags=""

make_clean_before_bundle() {
    if [ "${need_clean_before_bundle}" = "1" ] ; then
        (cd ${RNDTEMP} && Make clean) || :
    fi
}

make_clean_before_test() {
    if [ "${need_clean_before_test}" = "1" ] ; then
        Make clean
    fi
}

# Get all the type-bearding lines in file and process them individually
verify_asn_types_in_file() {
    filename="$1"
    need_line="$2"
    test "x$filename" != "x" || usage

    make_clean_before_bundle

    echo "Open [$filename]"
    line=0
    asn=""
    while read asn; do
        line=`echo "$line+1" | bc`
        if echo "$asn" | sed -e 's/--.*//;' | grep -vi "[A-Z]" > /dev/null; then
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
    asn="$1"
    where="$2"
    shift 2
    test "x$asn" != "x" || usage

    if echo "$asn" | grep -v "::=" > /dev/null; then
        asn="T ::= $asn"
    fi
    echo "Testing [$asn] ${where}"

    mkdir -p ${RNDTEMP}
    if (set -e && cd ${RNDTEMP} && compile_and_test "$asn" "${where}"); then
        echo "OK [$asn] ${where}"
        tests_succeeded=`echo "$tests_succeeded + 1" | bc`
    else
        tests_failed=`echo "$tests_failed + 1" | bc`
        echo "FAIL [$asn] ${where}"
    fi
}

Make() {
    ${MAKE:-make} -j "${parallelism}" "$@" || return $?
}

get_param() {
    param="$1"
    default="$2"
    text="$3"


    echo "$asn" | awk "/$param=/{for(i=1;i<=NF;i++)if(substr(\$i,0,length(\"${param}=\"))==\"${param}=\")PARAM=substr(\$i,length(\"${param}=\")+1)}END{if(PARAM)print PARAM;else print \"${default}\";}"
}

# compile_and_test "<text>" "<where found>"
compile_and_test() {
    asn="$1"
    where="$2"

    make_clean_before_test

    asn_compile "$asn" "$where"
    if [ $? -ne 0 ]; then
        echo "Cannot compile ASN.1 $asn"
        return 1
    fi

    rm -f random-test-driver.o
    rm -f random-test-driver
    CFLAGS="${CFLAGS}" Make
    if [ $? -ne 0 ] ; then
        echo "Cannot compile C for $asn in ${RNDTEMP}"
        return 2
    fi

    # Maximum size of the random data
    rmax=`get_param RMAX 128 "$asn"`
    if [ "0${rmax}" -lt 1 ]; then rmax=128; fi

    echo "Checking random data encode-decode"
    round_trip_check_cmd="${ASAN_ENV_FLAGS} ./random-test-driver -s ${rmax} ${encodings} -c"
    if eval "$round_trip_check_cmd"; then
        echo "Random test OK"
    else
        if [ "x$CC" = "x" ]; then CCSTR=""; else CCSTR="CC=${CC} "; fi
        echo "RETRY:"
        echo "(cd ${RNDTEMP} && ${CCSTR}CFLAGS=\"${LIBFUZZER_CFLAGS} ${CFLAGS}\" ${MAKE:-make} && ${ASAN_ENV_FLAGS} ./random-test-driver -s ${rmax} ${encodings} -c)"
        return 3
    fi

    echo "Generating new random data"
    rm -rf random-data
    cmd="${ASAN_ENV_FLAGS} UBSAN_OPTIONS=print_stacktrace=1"
    cmd="${cmd} ./random-test-driver -s ${rmax} ${encodings} -g random-data"
    if eval "$cmd" ; then
        echo "Random data generated OK"
    else
        echo "RETRY:"
        echo "(cd ${RNDTEMP} && $cmd)"
        return 4
    fi

    # Do a LibFuzzer based testing
    fuzz_time=10
    fuzz_cmd="${ASAN_ENV_FLAGS} UBSAN_OPTIONS=print_stacktrace=1"
    fuzz_cmd="${fuzz_cmd} ./random-test-driver"
    fuzz_cmd="${fuzz_cmd} -timeout=3 -max_total_time=${fuzz_time} -max_len=128"

    if grep "^fuzz:" Makefile >/dev/null ; then
        echo "No fuzzer defined, skipping fuzzing"
    else
        fuzz_targets=`echo random-data/* | sed -e 's/random-data./fuzz-/g'`
        {
        echo "fuzz: $fuzz_targets"
        echo "fuzz-%: random-data/% random-test-driver"
        echo "	ASN1_DATA_DIR=\$< ${fuzz_cmd} \$<"
        } >> Makefile
    fi

    # If LIBFUZZER_CFLAGS are properly defined, do the fuzz test as well
    if echo "${LIBFUZZER_CFLAGS}" | grep -i "[a-z]" > /dev/null; then

        echo "Recompiling for fuzzing..."
        rm -f random-test-driver.o
        rm -f random-test-driver
        CFLAGS="${LIBFUZZER_CFLAGS} ${CFLAGS}" Make
        if [ $? -ne 0 ]; then
            echo "Recompile failed"
            return 4
        fi

        echo "Fuzzing will take a multiple of $fuzz_time seconds..."
        Make fuzz
        if [ $? -ne 0 ]; then
            echo "RETRY:"
            echo "(cd ${RNDTEMP} && CC=${CC} CFLAGS=\"${LIBFUZZER_CFLAGS} ${CFLAGS}\" ${MAKE:-make} fuzz)"
            return 5
        fi
    fi

    return 0
}

asn_compile() {
    asn="$1"
    where="$2"

    # Create "INTEGER (1..2)" from "T ::= INTEGER (1..2) -- RMAX=5"
    short_asn=`echo "$asn" | sed -e 's/ *--.*//;s/RMAX=[^ ]* //;'`
    if [ `echo "$short_asn" | grep -c "::="` = 1 ]; then
        short_asn=`echo "$short_asn" | sed -e 's/.*::= *//'`
    fi

    test ! -f Makefile.am   # Protection from accidental clobbering
    echo "Test DEFINITIONS ::= BEGIN $asn" > test.asn1
    echo "-- ${where}" >> test.asn1
    echo "END" >> test.asn1
    echo "${abs_top_builddir}/asn1c/asn1c" -S "${abs_top_srcdir}/skeletons"
    if "${abs_top_builddir}/asn1c/asn1c" -S "${abs_top_srcdir}/skeletons" \
        -gen-OER -gen-PER ${asn1c_flags} test.asn1
    then
        echo "ASN.1 compiled OK"
    else
        return 1
    fi
    rm -f converter-example.c
    ln -sf "../${srcdir}/random-test-driver.c" || cp "../${srcdir}/random-test-driver.c" .
    echo "CFLAGS+= -DASN1_TEXT='$short_asn'" > Makefile
    sed -e 's/converter-example/random-test-driver/' \
        < Makefile.am.example >> Makefile
    echo "Makefile.am.example -> Makefile"
}

# Make up to four different passes:
#  CFLAGS: | asn1c_flags:
#   -m64   | -fnative-types
#   -m32   | -fnative-types
#   -m64   | -fwide-types
#   -m32   | -fwide-types
# *) Of course, -m64 and -fnative-types are just implied.
test_drive() {
    func="$1"
    shift

    if [ "x${asn1c_flags}" = "x" ] ; then
        # Test for native types and wide types
        asn1c_flags=" " test_drive "${func}" "$@"
        asn1c_flags="-fnative-types" test_drive "${func}" "$@"
        return 0
    fi

    echo "MODE: default"
    # Default (likely 64-bit) mode
    ${func} "$@"

    # 32-bit mode, if available
    if echo "${CFLAGS_M32}" | grep -i '[a-z]' > /dev/null ; then
        echo "MODE: 32-bit"
        # Unconditional clean, can't reuse object code.
        (cd ${RNDTEMP} && Make clean)
        # -m32 doesn't support fuzzing (no such library), so we remove fuzzer.
        # -m32 doesn't support leak sanitizing (it hangs), so we remove
        # ASAN_ENV_FLAGS which enable leak check.
        CFLAGS="${CFLAGS} ${CFLAGS_M32}" CFLAGS_M32="" \
        LIBFUZZER_CFLAGS="" ASAN_ENV_FLAGS="" \
            ${func} "$@"
    fi
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
            test_drive verify_asn_type "$2" "(command line)" || exit 1 ;;
        "")
            for bundle in `ls -1 ${srcdir}/bundles/*.txt | sort -nr`; do
                test_drive verify_asn_types_in_file "$bundle"
            done
        ;;
        *)
            test_drive verify_asn_types_in_file "$@"
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
