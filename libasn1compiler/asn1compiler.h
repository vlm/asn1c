#ifndef	ASN1_COMPILER_H
#define	ASN1_COMPILER_H

#include <asn1parser.h>

enum asn1c_flags {
	A1C_NOFLAGS,
	/*
	 * Debug the compiler.
	 */
	A1C_DEBUG		= 0x0001,
	/*
	 * Do not split the target output in several files, just print it.
	 * (Note: the output is not likely to be compilable in this case).
	 */
	A1C_PRINT_COMPILED	= 0x0002,
	/*
	 * Generate only the tables for ASN.1 types,
	 * do not emit ASN.1 parsing support code.
	 */
	A1C_OMIT_SUPPORT_CODE	= 0x0004,
	/*
	 * Use native data types instead of INTEGER_t et al.
	 */
	A1C_USE_NATIVE_TYPES	= 0x0008,
	/*
	 * Do not use C99 extensions.
	 */
	A1C_NO_C99		= 0x0010,
	/*
	 * Enable use of unnamed unions (non-portable feature).
	 */
	A1C_UNNAMED_UNIONS	= 0x0020,
	/*
	 * Don't make the asn1_DEF_'s of structure members "static".
	 */
	A1C_ALL_DEFS_GLOBAL	= 0x0040,
	/*
	 * Do not generate constraint checking code.
	 */
	A1C_NO_CONSTRAINTS	= 0x0080,
	/*
	 * Generate type_id_PR_member things identifiers of id_PR_member.
	 */
	A1C_COMPOUND_NAMES	= 0x0100,
	/*
	 * Do not generate courtesy #includes for external dependencies.
	 */
	A1C_NO_INCLUDE_DEPS	= 0x0200,
	/*
	 * Compile members of CHOICE as indirect pointers.
	 */
	A1C_INDIRECT_CHOICE	= 0x0400,
	/*
	 * -fskeletons-copy
	 * Copy support files rather than symlink them.
	 */
	A1C_SKELETONS_COPY	= 0x0800,
	/*
	 * -gen-PER
	 * Generate PER support code
	 */
	A1C_GEN_PER		= 0x1000,
	/*
	 * -pdu=auto
	 * Generate PDU table
	 */
	A1C_PDU_AUTO		= 0x2000
};

/*
 * Compile the ASN.1 specification.
 */
int asn1_compile(asn1p_t *asn, const char *datadir, enum asn1c_flags,
	int argc, int optc, char **argv);

#endif	/* ASN1_COMPILER_H */
