#!/bin/sh

#
# It is found that leak checker doesn't work in 32-bit mode.
# Disable in runtime.
#

if echo "$*" | sed -e 's/.*--//' | grep 'check-32-' >/dev/null; then
    unset ASAN_OPTIONS
fi

exec "$@"
