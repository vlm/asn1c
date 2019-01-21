#!/bin/sh

ORIG="./.check-xxber.orig.$$.tmp"
TEST="./.check-xxber.test.$$.tmp"

builddir=${builddir:-.}
ENBER=${builddir}/enber/enber
UNBER=${builddir}/unber/unber

# Test diff(1) capabilities
diff -a . . 2>/dev/null && diffArgs="-a"		# Assume text files
diff -u . . 2>/dev/null && diffArgs="$diffArgs -u"	# Unified diff output

cat<<EOM > $ORIG
<I O="0" T="[UNIVERSAL 16]" TL="2" V="Indefinite" A="SEQUENCE">
<P O="2" T="[UNIVERSAL 19]" TL="2" V="2" A="PrintableString">&#x55;&#x53;</P>
<C O="6" T="[UNIVERSAL 16]" TL="2" V="22" A="SEQUENCE">
<P O="8" T="[UNIVERSAL 2]" TL="2" V="4" A="INTEGER">&#x31;&#xa6;&#x20;&#x47;</P>
<C O="14" T="[UNIVERSAL 16]" TL="2" V="6" A="SEQUENCE">
<P O="16" T="[UNIVERSAL 2]" TL="2" V="4" A="INTEGER">&#x31;&#xa6;&#x20;&#x47;</P>
</C O="22" T="[UNIVERSAL 16]" A="SEQUENCE" L="8">
<C O="22" T="[UNIVERSAL 16]" TL="2" V="6" A="SEQUENCE">
<P O="24" T="[UNIVERSAL 2]" TL="2" V="4" A="INTEGER">&#x31;&#xa6;&#x20;&#x47;</P>
</C O="30" T="[UNIVERSAL 16]" A="SEQUENCE" L="8">
</C O="30" T="[UNIVERSAL 16]" A="SEQUENCE" L="24">
<I O="30" T="[UNIVERSAL 16]" TL="2" V="Indefinite" A="SEQUENCE">
</I O="32" T="[UNIVERSAL 0]" TL="2" L="4">
EOM

${ENBER} $ORIG | ${UNBER} -p -i 0 - > $TEST 2>&1
diff $diffArgs "$ORIG" "$TEST" >/dev/null 2>&1
diffExitCode=$?

if [ "$diffExitCode" = "0" ]; then
	echo "FAILED: $0: expected failure, got success"
	exit 42;
fi

# Append necessary terminator
echo '</I O="34" T="[UNIVERSAL 0]" TL="2" L="36">' >> $ORIG

# Try trancoding again
${ENBER} $ORIG | ${UNBER} -p -i 0 - > $TEST 2>&1

diff $diffArgs "$ORIG" "$TEST"
diffExitCode=$?

rm -f $ORIG $TEST

exit $diffExitCode
