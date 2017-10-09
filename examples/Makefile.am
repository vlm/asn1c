
dist_bin_SCRIPTS = crfc2asn1.pl

ASN1_SOURCE_1 = rfc3280.txt
ASN1_FILES_1 =				\
	rfc3280-PKIX1Explicit88.asn1	\
	rfc3280-PKIX1Implicit88.asn1

ASN1_SOURCE_2 = rfc3525.txt
ASN1_FILES_2 =				\
	rfc3525-MEDIA-GATEWAY-CONTROL.asn1

ASN1_SOURCE_3 = rfc4511.txt
ASN1_FILES_3 =				\
	rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1

BUILT_SOURCES = $(ASN1_FILES_1) $(ASN1_FILES_2) $(ASN1_FILES_3)

$(ASN1_FILES_1): crfc2asn1.pl $(ASN1_SOURCE_1)
	${srcdir}/crfc2asn1.pl ${srcdir}/$(ASN1_SOURCE_1)

$(ASN1_FILES_2): crfc2asn1.pl $(ASN1_SOURCE_2)
	${srcdir}/crfc2asn1.pl ${srcdir}/$(ASN1_SOURCE_2)

$(ASN1_FILES_3): crfc2asn1.pl $(ASN1_SOURCE_3)
	${srcdir}/crfc2asn1.pl ${srcdir}/$(ASN1_SOURCE_3)

EXTRA_DIST = \
    rfc3280.txt rfc3525.txt rfc4511.txt \
    sample.source.1609.2    \
    sample.source.J2735     \
    sample.source.LDAP3     \
    sample.source.LTE-RRC   \
    sample.source.MEGACO    \
    sample.source.MHEG5     \
    sample.source.PKIX1     \
    sample.source.RRC       \
    sample.source.TAP3      \
    sample.source.ULP       \
    sample.makefile.regen

CLEANFILES = $(ASN1_FILES_1) $(ASN1_FILES_2) $(ASN1_FILES_3)

clean-local:
	for dir in ${srcdir}/sample.source.*; do (cd $$dir && make distclean || :); done

dist-hook: clean-local
	rm -f `find $(distdir) -name "*.core" -or -name ".tmp.*"`
	rm -f `find $(distdir) -name "*.[ch].??????"`
