ASN_MODULE_SOURCES=	\
	LDAPMessage.c	\
	MessageID.c	\
	LDAPString.c	\
	LDAPOID.c	\
	LDAPDN.c	\
	RelativeLDAPDN.c	\
	AttributeDescription.c	\
	AttributeValue.c	\
	AttributeValueAssertion.c	\
	AssertionValue.c	\
	PartialAttribute.c	\
	Attribute.c	\
	MatchingRuleId.c	\
	LDAPResult.c	\
	Referral.c	\
	URI.c	\
	Controls.c	\
	Control.c	\
	BindRequest.c	\
	AuthenticationChoice.c	\
	SaslCredentials.c	\
	BindResponse.c	\
	UnbindRequest.c	\
	SearchRequest.c	\
	AttributeSelection.c	\
	Filter.c	\
	SubstringFilter.c	\
	MatchingRuleAssertion.c	\
	SearchResultEntry.c	\
	PartialAttributeList.c	\
	SearchResultReference.c	\
	SearchResultDone.c	\
	ModifyRequest.c	\
	ModifyResponse.c	\
	AddRequest.c	\
	AttributeList.c	\
	AddResponse.c	\
	DelRequest.c	\
	DelResponse.c	\
	ModifyDNRequest.c	\
	ModifyDNResponse.c	\
	CompareRequest.c	\
	CompareResponse.c	\
	AbandonRequest.c	\
	ExtendedRequest.c	\
	ExtendedResponse.c	\
	IntermediateResponse.c

ASN_MODULE_HEADERS=	\
	LDAPMessage.h	\
	MessageID.h	\
	LDAPString.h	\
	LDAPOID.h	\
	LDAPDN.h	\
	RelativeLDAPDN.h	\
	AttributeDescription.h	\
	AttributeValue.h	\
	AttributeValueAssertion.h	\
	AssertionValue.h	\
	PartialAttribute.h	\
	Attribute.h	\
	MatchingRuleId.h	\
	LDAPResult.h	\
	Referral.h	\
	URI.h	\
	Controls.h	\
	Control.h	\
	BindRequest.h	\
	AuthenticationChoice.h	\
	SaslCredentials.h	\
	BindResponse.h	\
	UnbindRequest.h	\
	SearchRequest.h	\
	AttributeSelection.h	\
	Filter.h	\
	SubstringFilter.h	\
	MatchingRuleAssertion.h	\
	SearchResultEntry.h	\
	PartialAttributeList.h	\
	SearchResultReference.h	\
	SearchResultDone.h	\
	ModifyRequest.h	\
	ModifyResponse.h	\
	AddRequest.h	\
	AttributeList.h	\
	AddResponse.h	\
	DelRequest.h	\
	DelResponse.h	\
	ModifyDNRequest.h	\
	ModifyDNResponse.h	\
	CompareRequest.h	\
	CompareResponse.h	\
	AbandonRequest.h	\
	ExtendedRequest.h	\
	ExtendedResponse.h	\
	IntermediateResponse.h

ASN_MODULE_HEADERS+=OPEN_TYPE.h
ASN_MODULE_SOURCES+=OPEN_TYPE.c
ASN_MODULE_HEADERS+=constr_CHOICE.h
ASN_MODULE_HEADERS+=BOOLEAN.h
ASN_MODULE_SOURCES+=BOOLEAN.c
ASN_MODULE_HEADERS+=INTEGER.h
ASN_MODULE_HEADERS+=NativeEnumerated.h
ASN_MODULE_SOURCES+=INTEGER.c
ASN_MODULE_HEADERS+=NULL.h
ASN_MODULE_SOURCES+=NULL.c
ASN_MODULE_SOURCES+=NativeEnumerated.c
ASN_MODULE_HEADERS+=NativeInteger.h
ASN_MODULE_SOURCES+=NativeInteger.c
ASN_MODULE_HEADERS+=asn_SEQUENCE_OF.h
ASN_MODULE_SOURCES+=asn_SEQUENCE_OF.c
ASN_MODULE_HEADERS+=asn_SET_OF.h
ASN_MODULE_SOURCES+=asn_SET_OF.c
ASN_MODULE_SOURCES+=constr_CHOICE.c
ASN_MODULE_HEADERS+=constr_SEQUENCE.h
ASN_MODULE_SOURCES+=constr_SEQUENCE.c
ASN_MODULE_HEADERS+=constr_SEQUENCE_OF.h
ASN_MODULE_SOURCES+=constr_SEQUENCE_OF.c
ASN_MODULE_HEADERS+=constr_SET_OF.h
ASN_MODULE_SOURCES+=constr_SET_OF.c
ASN_MODULE_HEADERS+=asn_application.h
ASN_MODULE_SOURCES+=asn_application.c
ASN_MODULE_HEADERS+=asn_ioc.h
ASN_MODULE_HEADERS+=asn_system.h
ASN_MODULE_HEADERS+=asn_codecs.h
ASN_MODULE_HEADERS+=asn_internal.h
ASN_MODULE_HEADERS+=asn_bit_data.h
ASN_MODULE_SOURCES+=asn_bit_data.c
ASN_MODULE_HEADERS+=OCTET_STRING.h
ASN_MODULE_SOURCES+=OCTET_STRING.c
ASN_MODULE_HEADERS+=BIT_STRING.h
ASN_MODULE_SOURCES+=BIT_STRING.c
ASN_MODULE_SOURCES+=asn_codecs_prim.c
ASN_MODULE_HEADERS+=asn_codecs_prim.h
ASN_MODULE_HEADERS+=ber_tlv_length.h
ASN_MODULE_SOURCES+=ber_tlv_length.c
ASN_MODULE_HEADERS+=ber_tlv_tag.h
ASN_MODULE_SOURCES+=ber_tlv_tag.c
ASN_MODULE_HEADERS+=ber_decoder.h
ASN_MODULE_SOURCES+=ber_decoder.c
ASN_MODULE_HEADERS+=der_encoder.h
ASN_MODULE_SOURCES+=der_encoder.c
ASN_MODULE_HEADERS+=constr_TYPE.h
ASN_MODULE_SOURCES+=constr_TYPE.c
ASN_MODULE_HEADERS+=constraints.h
ASN_MODULE_SOURCES+=constraints.c
ASN_MODULE_HEADERS+=xer_support.h
ASN_MODULE_SOURCES+=xer_support.c
ASN_MODULE_HEADERS+=xer_decoder.h
ASN_MODULE_SOURCES+=xer_decoder.c
ASN_MODULE_HEADERS+=xer_encoder.h
ASN_MODULE_SOURCES+=xer_encoder.c
ASN_MODULE_HEADERS+=per_support.h
ASN_MODULE_SOURCES+=per_support.c
ASN_MODULE_HEADERS+=per_decoder.h
ASN_MODULE_SOURCES+=per_decoder.c
ASN_MODULE_HEADERS+=per_encoder.h
ASN_MODULE_SOURCES+=per_encoder.c
ASN_MODULE_HEADERS+=per_opentype.h
ASN_MODULE_SOURCES+=per_opentype.c
ASN_CONVERTER_SOURCES+=converter-sample.c


lib_LTLIBRARIES=libsomething.la
libsomething_la_SOURCES=$(ASN_MODULE_SOURCES) $(ASN_MODULE_HEADERS)

# This file may be used as an input for make(3)
# Remove the lines below to convert it into a pure .am file
TARGET = ldap3dump
LIBS += -lm
CPPFLAGS += -DASN_CONVERTER_TITLE="Lightweight Directory Access Protocol V3 decoder" -DHAVE_CONFIG_H -DJUNKTEST -D_DEFAULT_SOURCE  -DASN_DISABLE_OER_SUPPORT -DASN_DISABLE_PER_SUPPORT -DPDU=LDAPMessage -I.
OBJS=${ASN_MODULE_SOURCES:.c=.o} ${ASN_CONVERTER_SOURCES:.c=.o}

all: maybe-wip-pause LDAPMessage.c $(TARGET)

$(TARGET): ${OBJS}
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) ${OBJS} $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

regen: regenerate-from-asn1-source

regenerate-from-asn1-source:
	../../asn1c/asn1c -S ../../skeletons -pdu=LDAPMessage -fcompound-names ../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1


LDAPMessage.c: ../sample.makefile.regen ../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1
	make regen-makefile
	@touch LDAPMessage.c
	make

regen-makefile:
	TITLE="Lightweight Directory Access Protocol V3 decoder" \
	ASN1CMDOPTS="-fcompound-names" \
	ASN1MODULES="../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1" \
	ASN1PDU=LDAPMessage \
	PROGNAME=ldap3dump \
	CPPFLAGS="" \
	../sample.makefile.regen

check: ${TARGET} check-ber check-xer check-oer check-per
	@echo ================
	@echo All tests passed
	@echo ================

check-ber:
	@if test -f sample-LDAPMessage-1.[db]er ; then \
	for f in sample-*-*.[db]er; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -ixer -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 6; \
	done; done; fi

check-xer:
	@if test -f sample-LDAPMessage-1.xer ; then \
	for f in sample-*-*.xer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -ixer -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 6; \
	done; done; fi

check-oer:
	@if test -f sample-LDAPMessage-1.*oer ; then \
	for f in sample-*-*.*oer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -ioer -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -ixer -ooer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait) ($$b) ..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 6; \
	done; done; fi

check-per:
	@if test -f sample-LDAPMessage-1-nopad.per ; then \
	for f in sample-*-[1-9]-nopad.per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding non-padded $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -per-nopad -iper -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	./${TARGET} -p $$pdu -b $$b -ixer -oder ./.tmp.2.$$$$ > ./.tmp.3.$$$$ || exit 4; \
	diff ./.tmp.1.$$$$ ./.tmp.3.$$$$ || exit 5; \
	rm -f ./.tmp.[123].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 6; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 7; \
	done; done; fi
	@if test -f sample-LDAPMessage-1.per ; then \
	for f in sample-*-[1-9].per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -iper -oder $$f > ./.tmp.1.$$$$ || exit 3; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 4; \
	./${TARGET} -p $$pdu -b $$b -ixer -oper ./.tmp.2.$$$$ > ./.tmp.1.$$$$ || exit 5; \
	diff $$f ./.tmp.1.$$$$ || exit 6; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 7; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 8; \
	done; done; fi

maybe-wip-pause:
	@if [ -f WIP ]; then cat WIP; sleep 2; fi

distclean: clean
	rm -f $(ASN_MODULE_SOURCES)
	rm -f $(ASN_MODULE_HEADERS)
	rm -f $(ASN_CONVERTER_SOURCES) $(ASN_CONVERTER_HEADERS)
	rm -f Makefile.am.sample
