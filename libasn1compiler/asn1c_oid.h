/* OID support contributed by Sean Leonard of SeanTek(R). */

#ifndef	ASN1_COMPILER_OID_H
#define	ASN1_COMPILER_OID_H

/*
 * Encodes the OBJECT IDENTIFIER or RELATIVE-OID in arg
 * to BER encoding (base128). This code is taken from
 * OBJECT_IDENTIFIER in the skeletons, also contributed
 * by Sean Leonard of SeanTek.
 */
int asn1c_oid_ber_encode(arg_t *arg, uint8_t **ber, size_t *ber_len);

#endif	/* ASN1_COMPILER_OID_H */
