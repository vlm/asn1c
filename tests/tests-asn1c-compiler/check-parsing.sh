#!/bin/sh

# Test diff(1) capabilities
diff -a . . 2>/dev/null && diffArgs="-a"		# Assume text files
diff -u . . 2>/dev/null && diffArgs="$diffArgs -u"	# Unified diff output

ec=0

if [ "$1" != "regenerate" ]; then
    set -e
fi

PROCESSING=""
print_status() {
    echo "Error while processing $PROCESSING"
}

trap print_status EXIT

top_srcdir="${top_srcdir:-../..}"
top_builddir="${top_builddir:-../..}"

for ref in ${top_srcdir}/tests/tests-asn1c-compiler/*.asn1.-*; do
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
	(${top_builddir}/asn1c/asn1c -S ${top_srcdir}/skeletons -no-gen-OER -no-gen-PER "-$flags" "$src" | LANG=C sed -e 's/^found in .*/found in .../' > "$newversion") || ec=$?
	if [ $? = 0 ]; then
		diff $diffArgs "$oldversion" "$newversion" || ec=$?
	fi
	rm -f $oldversion $newversion
	if [ "$1" = "regenerate" ]; then
		${top_builddir}/asn1c/asn1c -S ${top_srcdir}/skeletons -no-gen-OER -no-gen-PER "-$flags" "$src" > "$ref"
	fi
done

if [ $ec = 0 ]; then
    trap '' EXIT
fi

exit $ec
