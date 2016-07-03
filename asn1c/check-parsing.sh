#!/bin/sh

# Test diff(1) capabilities
diff -a . . 2>/dev/null && diffArgs="-a"		# Assume text files
diff -u . . 2>/dev/null && diffArgs="$diffArgs -u"	# Unified diff output

ec=0

set -e

PROCESSING=""
print_status() {
    echo "Error while processing $PROCESSING"
}

trap print_status EXIT

if [ "x${top_srcdir}" = "x" ]; then
  top_srcdir=".."
fi

for ref in ${top_srcdir}/tests/*.asn1.-*; do
	# Figure out the initial source file used to generate this output.
	src=$(echo "$ref" | sed -e 's/\.-[-a-zA-Z0-9=]*$//')
	# Figure out compiler flags used to create the file.
	flags=$(echo "$ref" | sed -e 's/.*\.-//')
	echo "Checking $src against $ref"
	template=.tmp.check-parsing.$$
	oldversion=${template}.old
	newversion=${template}.new
	PROCESSING="$ref (from $src)"
	LANG=C sed -e 's/^found in .*/found in .../' < "$ref" > "$oldversion"
	(./asn1c -S ${top_srcdir}/skeletons "-$flags" "$src" | LANG=C sed -e 's/^found in .*/found in .../' > "$newversion") || ec=$?
	if [ $? = 0 ]; then
		diff $diffArgs "$oldversion" "$newversion" || ec=$?
	fi
	rm -f $oldversion $newversion
	if [ "$1" = "regenerate" ]; then
		./asn1c -S ${top_srcdir}/skeletons "-$flags" "$src" > "$ref"
	fi
done

if [ $ec = 0 ]; then
    trap '' EXIT
fi

exit $ec
