/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * This file contains the declaration structure called "ASN.1 Type Definition",
 * which holds all information necessary for encoding and decoding routines.
 * This structure even contains pointer to these encoding and decoding routines
 * for each defined ASN.1 type.
 */
#ifndef	_CONSTR_TYPE_H
#define	_CONSTR_TYPE_H

struct asn1_TYPE_descriptor_s;	/* Forward declaration */
struct asn1_TYPE_member_s;	/* Forward declaration */

/*
 * Type of the return value of the encoding functions (der_encode, xer_encode).
 */
typedef struct asn_enc_rval_s {
	/*
	 * Number of bytes encoded.
	 * -1 indicates failure to encode the structure.
	 * In this case, the members below this one are meaningful.
	 */
	ssize_t encoded;

	/*
	 * Members meaningful when (encoded == -1), for post mortem analysis.
	 */

	/* Type which cannot be encoded */
	struct asn1_TYPE_descriptor_s *failed_type;

	/* Pointer to the structure of that type */
	void *structure_ptr;
} asn_enc_rval_t;
#define	_ASN_ENCODE_FAILED do {					\
	asn_enc_rval_t __er = { -1, td, sptr };			\
	return __er;						\
} while(0)

#include <ber_tlv_length.h>
#include <ber_tlv_tag.h>
#include <ber_decoder.h>
#include <der_encoder.h>
#include <xer_encoder.h>
#include <constraints.h>

/*
 * Free the structure according to its specification.
 * If (free_contents_only) is set, the wrapper structure itself (struct_ptr)
 * will not be freed. (It may be useful in case the structure is allocated
 * statically or arranged on the stack, yet its elements are allocated
 * dynamically.)
 */
typedef void (asn_struct_free_f)(
		struct asn1_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr, int free_contents_only);

/*
 * Print the structure according to its specification.
 */
typedef int (asn_struct_print_f)(
		struct asn1_TYPE_descriptor_s *type_descriptor,
		const void *struct_ptr,
		int level,	/* Indentation level */
		asn_app_consume_bytes_f *callback, void *app_key);

/*
 * Return the outmost tag of the type.
 * If the type is untagged CHOICE, the dynamic operation is performed.
 * NOTE: This function pointer type is only useful internally.
 * Do not use it in your application.
 */
typedef ber_tlv_tag_t (asn_outmost_tag_f)(
		struct asn1_TYPE_descriptor_s *type_descriptor,
		const void *struct_ptr, int tag_mode, ber_tlv_tag_t tag);
/* The instance of the above function type; used internally. */
asn_outmost_tag_f asn1_TYPE_outmost_tag;


/*
 * The definitive description of the destination language's structure.
 */
typedef struct asn1_TYPE_descriptor_s {
	char *name;	/* A name of the ASN.1 type */

	/*
	 * Generalized functions for dealing with the specific type.
	 * May be directly invoked by applications.
	 */
	asn_struct_free_f  *free_struct;	/* Free the structure */
	asn_struct_print_f *print_struct;	/* Human readable output */
	asn_constr_check_f *check_constraints;	/* Constraints validator */
	ber_type_decoder_f *ber_decoder;	/* Free-form BER decoder */
	der_type_encoder_f *der_encoder;	/* Canonical DER encoder */
	int (*xer_decoder);/* PLACEHOLDER */ /* Free-form XER decoder */
	xer_type_encoder_f *xer_encoder;	/* [Canonical] XER encoder */

	/*
	 * Functions used internally. Should not be used by applications.
	 */
	asn_outmost_tag_f  *outmost_tag;	/* <optional, internal> */

	/*
	 * Tags that are expected to occur.
	 */
	ber_tlv_tag_t *tags;	/* Effective tags sequence for this type */
	int tags_count;		/* Number of tags which are expected */
	ber_tlv_tag_t *all_tags;/* Every tag for BER/containment */
	int all_tags_count;	/* Number of tags */

	int last_tag_form;	/* Acceptable form of the tag (prim, constr) */

	/*
	 * An ASN.1 production type members (members of SEQUENCE, SET, CHOICE).
	 */
	struct asn1_TYPE_member_s *elements;
	int elements_count;

	/*
	 * Additional information describing the type, used by appropriate
	 * functions above.
	 */
	void *specifics;
} asn1_TYPE_descriptor_t;

/*
 * An element of the constructed type, i.e. SEQUENCE, SET, CHOICE.
 */
  enum asn1_TYPE_flags_e {
	ATF_NOFLAGS,
	ATF_POINTER	= 0x01,	/* Represented by the pointer */
	ATF_OPEN_TYPE	= 0x02,	/* ANY type, without meaningful tag */
  };
typedef struct asn1_TYPE_member_s {
	enum asn1_TYPE_flags_e flags;	/* Element's presentation flags */
	int optional;	/* Following optional members, including current */
	int memb_offset;		/* Offset of the element */
	ber_tlv_tag_t tag;		/* Outmost (most immediate) tag */
	int tag_mode;		/* IMPLICIT/no/EXPLICIT tag at current level */
	asn1_TYPE_descriptor_t *type;	/* Member type descriptor */
	asn_constr_check_f *memb_constraints;	/* Constraints validator */
	char *name;			/* ASN.1 identifier of the element */
} asn1_TYPE_member_t;

/*
 * BER tag to element number mapping.
 */
typedef struct asn1_TYPE_tag2member_s {
	ber_tlv_tag_t el_tag;	/* Outmost tag of the member */
	int el_no;		/* Index of the associated member, base 0 */
	int toff_first;		/* First occurence of the el_tag, relative */
	int toff_last;		/* Last occurence of the el_tag, relatvie */
} asn1_TYPE_tag2member_t;


/*
 * This function is a wrapper around (td)->print_struct, which prints out
 * the contents of the target language's structure (struct_ptr) into the
 * file pointer (stream) in human readable form.
 * RETURN VALUES:
 * 	 0: The structure is printed.
 * 	-1: Problem dumping the structure.
 * (See also xer_fprint() in xer_encoder.h)
 */
int asn_fprint(FILE *stream,		/* Destination stream descriptor */
	asn1_TYPE_descriptor_t *td,	/* ASN.1 type descriptor */
	const void *struct_ptr);	/* Structure to be printed */

#endif	/* _CONSTR_TYPE_H_ */
