#ifndef	_ASN1PRINT_H_
#define	_ASN1PRINT_H_

enum asn1print_flags_e {
	APF_NOFLAGS		= 0x00,
	APF_LINE_COMMENTS	= 0x01,
};

/*
 * Print the contents of the parsed ASN.1 syntax tree.
 */
int asn1print(asn1p_t *asn, enum asn1print_flags_e flags);


#endif	/* _ASN1PRINT_H_ */
