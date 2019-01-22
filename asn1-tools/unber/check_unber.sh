#!/bin/sh

FUZZ_TIME=${FUZZ_TIME:-10}
builddir=${builddir:-.}

env ${ASAN_ENV_FLAGS:-} ${builddir}/check_unber \
    -timeout=3                      \
    -max_total_time=${FUZZ_TIME}    \
    -max_len=500
