#include <asn1fix_internal.h>
#include <asn1fix_crange.h>

/*
 * Check that a specific constraint is compatible
 * with the given expression type.
 */
int
asn1constraint_compatible(asn1p_expr_type_e expr_type,
	enum asn1p_constraint_type_e constr_type) {

	/*
	 * X.680-0207, Table 9.
	 */

	switch(constr_type) {
	case ACT_INVALID:
		return 0;
	case ACT_EL_VALUE:
		return 1;
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		switch(expr_type) {
		case ASN_BASIC_ENUMERATED:
		case ASN_BASIC_BOOLEAN:
			/*
			 * The ValueRange constraint is not formally
			 * applicable to the above types. However, we
			 * support it just fine.
			 */
			/* Fall through */
		case ASN_BASIC_INTEGER:
		case ASN_BASIC_REAL:
			return 1;
		default:
			if(expr_type & ASN_STRING_MASK)
				return 1;
		}
		return 0;
	case ACT_EL_EXT:
		return -1;
	case ACT_CT_FROM:
		if(expr_type & ASN_STRING_MASK)
			return 1;
		return 0;
	case ACT_CT_SIZE:
		switch(expr_type) {
		case ASN_BASIC_BIT_STRING:
		case ASN_BASIC_OCTET_STRING:
		case ASN_BASIC_CHARACTER_STRING:
		case ASN_CONSTR_SEQUENCE_OF:
		case ASN_CONSTR_SET_OF:
			return 1;
		default:
			if(expr_type & ASN_STRING_MASK)
				return 1;
		}
		return 0;
	case ACT_CT_WCOMP:
	case ACT_CT_WCOMPS:
		switch(expr_type) {
		case A1TC_INSTANCE:
		case ASN_BASIC_EXTERNAL:
		case ASN_BASIC_EMBEDDED_PDV:
		case ASN_BASIC_REAL:
		case ASN_BASIC_CHARACTER_STRING:
		case ASN_CONSTR_CHOICE:
		case ASN_CONSTR_SEQUENCE:
		case ASN_CONSTR_SEQUENCE_OF:
		case ASN_CONSTR_SET:
		case ASN_CONSTR_SET_OF:
			return 1;
		default: break;
		}
		return 0;
	case ACT_CA_SET:
	case ACT_CA_CRC:
	case ACT_CA_CSV:
	case ACT_CA_UNI:
	case ACT_CA_INT:
	case ACT_CA_EXC:
		return 1;
	}

	return -1;
}


#define	DECL(foo, val1, val2)					\
	static asn1cnst_range_t range_ ## foo = {		\
			{ ARE_VALUE, 0, val1 },			\
			{ ARE_VALUE, 0, val2 },			\
			0, 0, 0, 0, 0, 0 };

asn1cnst_range_t *
asn1constraint_default_alphabet(asn1p_expr_type_e expr_type) {
	DECL(uint7,	0x00, 0x7f);
	DECL(uint8,	0x00, 0xff);
	DECL(Space,	0x20, 0x20);
	DECL(ApostropheAndParens, 0x27, 0x29);
	DECL(PlusTillColon, 0x2b, 0x3a);
	DECL(Equal,	0x3d, 0x3d);
	DECL(QuestionMark, 0x3f, 0x3f);
	DECL(Digits,	0x30, 0x39);
	DECL(AlphaCap,	0x41, 0x5a);
	DECL(AlphaLow,	0x61, 0x7a);
	DECL(PlusCommaMinusDot, 0x2b, 0x2e);
	DECL(Plus,	0x2b, 0x2b);
	DECL(MinusDot,	0x2d, 0x2e);
	DECL(Z,		0x5a, 0x5a);
	static asn1cnst_range_t *range_NumericString_array[] = {
			&range_Space, &range_Digits };
	static asn1cnst_range_t *range_PrintableString_array[] = {
			&range_Space,
			&range_ApostropheAndParens,
			&range_PlusTillColon,
			&range_Equal,
			&range_QuestionMark,
			&range_AlphaCap,
			&range_AlphaLow
	};
	static asn1cnst_range_t *range_UTCTime_array[] = {
			&range_Plus, &range_MinusDot, &range_Digits, &range_Z };
	static asn1cnst_range_t *range_GeneralizedTime_array[] = {
			&range_PlusCommaMinusDot, &range_Digits, &range_Z };
	static asn1cnst_range_t range_NumericString = {
			{ ARE_VALUE, 0, 0x20 },
			{ ARE_VALUE, 0, 0x39 },
			range_NumericString_array,
			sizeof(range_NumericString_array)
				/sizeof(range_NumericString_array[0]),
			0, 0, 0, 0 };
	static asn1cnst_range_t range_PrintableString = {
			{ ARE_VALUE, 0, 0x20 },
			{ ARE_VALUE, 0, 0x7a },
			range_PrintableString_array,
			sizeof(range_PrintableString_array)
				/sizeof(range_PrintableString_array[0]),
			0, 0, 0, 0 };
	static asn1cnst_range_t range_VisibleString = {
			{ ARE_VALUE, 0, 0x20 },
			{ ARE_VALUE, 0, 0x7e },
			0, 0, 0, 0, 0, 0 };
	static asn1cnst_range_t range_UTCTime = {
			{ ARE_VALUE, 0, 0x2b },
			{ ARE_VALUE, 0, 0x5a },
			range_UTCTime_array,
			sizeof(range_UTCTime_array)
				/sizeof(range_UTCTime_array[0]),
			0, 0, 0, 0 };
	static asn1cnst_range_t range_GeneralizedTime = {
			{ ARE_VALUE, 0, 0x2b },
			{ ARE_VALUE, 0, 0x5a },
			range_GeneralizedTime_array,
			sizeof(range_GeneralizedTime_array)
				/sizeof(range_GeneralizedTime_array[0]),
			0, 0, 0, 0 };

	switch(expr_type) {
	case ASN_STRING_NumericString:
		return &range_NumericString;
	case ASN_STRING_PrintableString:
		return &range_PrintableString;
	case ASN_STRING_VisibleString:
		return &range_VisibleString;
	case ASN_STRING_IA5String:
		return &range_uint7;
	case ASN_BASIC_OCTET_STRING:
		return &range_uint8;
	case ASN_BASIC_UTCTime:
		return &range_UTCTime;
	case ASN_BASIC_GeneralizedTime:
		return &range_GeneralizedTime;
	default:
		break;
	}

	return NULL;
}
