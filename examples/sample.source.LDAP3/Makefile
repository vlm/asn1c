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

ASN_MODULE_HEADERS+=BOOLEAN.h
ASN_MODULE_SOURCES+=BOOLEAN.c
ASN_MODULE_HEADERS+=ENUMERATED.h
ASN_MODULE_SOURCES+=ENUMERATED.c
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
ASN_MODULE_HEADERS+=constr_CHOICE.h
ASN_MODULE_SOURCES+=constr_CHOICE.c
ASN_MODULE_HEADERS+=constr_SEQUENCE.h
ASN_MODULE_SOURCES+=constr_SEQUENCE.c
ASN_MODULE_HEADERS+=constr_SEQUENCE_OF.h
ASN_MODULE_SOURCES+=constr_SEQUENCE_OF.c
ASN_MODULE_HEADERS+=constr_SET_OF.h
ASN_MODULE_SOURCES+=constr_SET_OF.c
ASN_MODULE_HEADERS+=asn_application.h
ASN_MODULE_HEADERS+=asn_system.h
ASN_MODULE_HEADERS+=asn_codecs.h
ASN_MODULE_HEADERS+=asn_internal.h
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
ASN_CONVERTER_SOURCES+=converter-sample.c


lib_LTLIBRARIES=libsomething.la
libsomething_la_SOURCES=$(ASN_MODULE_SOURCES) $(ASN_MODULE_HEADERS)

# This file may be used as an input for make(3)
# Remove the lines below to convert it into a pure .am file
TARGET = ldap3dump
CFLAGS += -DHAVE_CONFIG_H -DPDU=LDAPMessage -I.
OBJS=${ASN_MODULE_SOURCES:.c=.o} ${ASN_CONVERTER_SOURCES:.c=.o}

all: LDAPMessage.c $(TARGET)

$(TARGET): ${OBJS}
	$(CC) $(CFLAGS) -o $(TARGET) ${OBJS} $(LDFLAGS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

regen: regenerate-from-asn1-source

regenerate-from-asn1-source:
	../../asn1c/asn1c -S ../../skeletons -fcompound-names ../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1


LDAPMessage.c: ../sample.makefile.regen ../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1
	make regen-makefile
	@touch LDAPMessage.c
	make

regen-makefile:
	ASN1CMDOPTS="-fcompound-names" \
	ASN1MODULES="../rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1" \
	ASN1PDU=LDAPMessage \
	PROGNAME=ldap3dump \
	../sample.makefile.regen

check: ${TARGET}
	@if test -f sample-LDAPMessage-1.[db]er ; then \
	for f in sample-LDAPMessage-*.[db]er; do \
	echo "Recoding $$f into XER and back..."; \
	./${TARGET} -iber -oxer -b 1 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer -b 17 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer -b 33 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer -b 980 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -ixer -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 2; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 2; \
	rm -f ./.tmp.[12].$$$$; \
	done; fi
	@if test -f sample-LDAPMessage-1.xer ; then \
	for f in sample-LDAPMessage-*.xer; do \
	echo "Recoding $$f into DER and back..."; \
	./${TARGET} -ixer -oder -b 1 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -ixer -oder -b 17 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -ixer -oder -b 33 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -ixer -oder -b 980 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -ixer -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 2; \
	diff $$f ./.tmp.2.$$$$ || exit 2; \
	rm -f ./.tmp.[12].$$$$; \
	done; fi
	@if test -f sample-LDAPMessage-1.per ; then \
	for f in sample-LDAPMessage-[1-9].per; do \
	echo "Recoding $$f into DER into XER and back..."; \
	./${TARGET} -iper -oxer -b 1 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iper -oxer -b 17 $$f > ./.tmp.2.$$$$ || exit 2; \
	./${TARGET} -iper -oxer -b 33 $$f > ./.tmp.3.$$$$ || exit 2; \
	./${TARGET} -iper -oxer -b 980 $$f > ./.tmp.4.$$$$ || exit 2; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 2; \
	diff ./.tmp.2.$$$$ ./.tmp.3.$$$$ || exit 2; \
	diff ./.tmp.3.$$$$ ./.tmp.4.$$$$ || exit 2; \
	./${TARGET} -iper -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 2; \
	./${TARGET} -ixer -oder ./.tmp.2.$$$$ > ./.tmp.3.$$$$ || exit 2; \
	diff ./.tmp.1.$$$$ ./.tmp.3.$$$$ || exit 2; \
	rm -f ./.tmp.[1234].$$$$; \
	done; fi
	@if test -f sample-LDAPMessage-1-padded.per ; then \
	for f in sample-*-[1-9]-padded.per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z-]+)-[0-9].*/\1/"`; \
	echo "Recoding byte-padded $$f into DER into XER and back..."; \
	./${TARGET} -per-padded -p $$pdu -iper -oxer -b 1 $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -per-padded -p $$pdu -iper -oxer -b 17 $$f > ./.tmp.2.$$$$ || exit 2; \
	./${TARGET} -per-padded -p $$pdu -iper -oxer -b 33 $$f > ./.tmp.3.$$$$ || exit 2; \
	./${TARGET} -per-padded -p $$pdu -iper -oxer -b 980 $$f > ./.tmp.4.$$$$ || exit 2; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 2; \
	diff ./.tmp.2.$$$$ ./.tmp.3.$$$$ || exit 2; \
	diff ./.tmp.3.$$$$ ./.tmp.4.$$$$ || exit 2; \
	./${TARGET} -per-padded -p $$pdu -iper -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -ixer -oper ./.tmp.2.$$$$ > ./.tmp.1.$$$$ || exit 2; \
	diff $$f ./.tmp.1.$$$$ || exit 2; \
	rm -f ./.tmp.[1234].$$$$; \
	done; fi
	@echo ================
	@echo All tests passed
	@echo ================

distclean: clean
	rm -f $(ASN_MODULE_SOURCES)
	rm -f $(ASN_MODULE_HEADERS)
	rm -f $(ASN_CONVERTER_SOURCES) $(ASN_CONVERTER_HEADERS)
	rm -f Makefile.am.sample
