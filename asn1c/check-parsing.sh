#!/bin/sh

tmpfile=".check-parsing.$$.tmp"

diff -a . . 2>/dev/null && diffArgs="-a"

ec=0

for ref in ../tests/*.asn1.-*; do
	src=`echo "$ref" | sed -e 's/\.-[-a-zA-Z0-9=]*$//'`
	flags=`echo "$ref" | sed -e 's/.*\.-//'`
	echo "Checking $src against $ref"
	./asn1c "-$flags" "$src" > "$tmpfile" || ec=$?
	if [ $? = 0 ]; then
		diff $diffArgs -u "$ref" "$tmpfile" || ec=$?
	fi
	if [ "$1" != "regenerate" ]; then
		rm -f "$tmpfile"
	else
		mv "$tmpfile" "$ref"
	fi
done

exit $ec
