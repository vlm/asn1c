#ifndef	_ASN1PRINT_H_
#define	_ASN1PRINT_H_

enum asn1print_flags {
	APF_NOFLAGS,
	APF_LINE_COMMENTS	= 0x01, /* Include line comments */
	APF_DEBUG_CONSTRAINTS	= 0x02,	/* Explain constraints */
};

/*
 * Print the contents of the parsed ASN.1 syntax tree.
 */
int asn1print(asn1p_t *asn, enum asn1print_flags flags);


#endif	/* _ASN1PRINT_H_ */
