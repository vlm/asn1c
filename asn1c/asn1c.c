/*
 * This is the program that connects the libasn1* libraries together.
 * It uses them in turn to parse, fix and then compile or print the ASN.1 tree.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>		/* for stat(2) */
#include <unistd.h>
#include <libgen.h>		/* for basename(3) */
#include <sysexits.h>		/* for EX_USAGE */
#include <assert.h>
#include <errno.h>

#include <asn1parser.h>		/* Parse the ASN.1 file and build a tree */
#include <asn1fix.h>		/* Fix the ASN.1 tree */
#include <asn1print.h>		/* Print the ASN.1 tree */
#include <asn1compiler.h>	/* Compile the ASN.1 tree */

static void usage(char *av0);	/* Print the Usage screen and exit(EX_USAGE) */

int
main(int ac, char **av) {
	enum asn1p_flags asn1_parser_flags	= A1P_NOFLAGS;
	enum asn1f_flags asn1_fixer_flags	= A1F_NOFLAGS;
	enum asn1c_flags asn1_compiler_flags	= A1C_NOFLAGS;
	int print_arg__print_out = 0;	/* Don't compile, just print parsed */
	int print_arg__fix_n_print = 0;	/* Fix and print */
	enum asn1print_flags_e print_arg__flags = APF_NOFLAGS;
	int warnings_as_errors = 0;	/* Treat warnings as errors */
	char *skeletons_dir = NULL;	/* Directory with supplementary stuff */
	asn1p_t *asn = 0;		/* An ASN.1 parsed tree */
	int ret;			/* Return value from misc functions */
	int ch;				/* Command line character */
	int i;				/* Index in some loops */

	/*
	 * Process command-line options.
	 */
	while((ch = getopt(ac, av, "EFf:LNPRS:W:")) != -1)
	switch(ch) {
	case 'E':
		print_arg__print_out = 1;
		break;
	case 'F':
		print_arg__fix_n_print = 1;
		break;
	case 'f':
		if(strcmp(optarg, "types88") == 0) {
			asn1_parser_flags |= A1P_TYPES_RESTRICT_TO_1988;
		} else if(strcmp(optarg, "constr90") == 0) {
			asn1_parser_flags |= A1P_CONSTRUCTS_RESTRICT_TO_1990;
		} else if(strcmp(optarg, "native-integers") == 0) {
			asn1_compiler_flags |= A1C_USE_NATIVE_INTEGERS;
		} else if(strcmp(optarg, "no-c99") == 0) {
			asn1_compiler_flags |= A1C_NO_C99;
		} else if(strcmp(optarg, "unnamed-unions") == 0) {
			asn1_compiler_flags |= A1C_UNNAMED_UNIONS;
		} else {
			fprintf(stderr, "-f%s: Invalid argument\n", optarg);
			exit(EX_USAGE);
		}
		break;
	case 'L':
		print_arg__flags |= APF_LINE_COMMENTS;
		break;
	case 'N':
		print_arg__flags |= APF_NO_SOURCE_COMMENTS;
		break;
	case 'P':
		asn1_compiler_flags |= A1C_PRINT_COMPILED;
		break;
	case 'R':
		asn1_compiler_flags |= A1C_OMIT_SUPPORT_CODE;
		break;
	case 'S':
		skeletons_dir = optarg;
		break;
	case 'W':
		if(strcmp(optarg, "error") == 0) {
			warnings_as_errors = 1;
			break;
		} else if(strcmp(optarg, "debug-lexer") == 0) {
			asn1_parser_flags |= A1P_LEXER_DEBUG;
			break;
		} else if(strcmp(optarg, "debug-fixer") == 0) {
			asn1_fixer_flags |= A1F_DEBUG;
			break;
		} else if(strcmp(optarg, "debug-compiler") == 0) {
			asn1_compiler_flags |= A1C_DEBUG;
			break;
		} else {
			fprintf(stderr, "-W%s: Invalid argument\n", optarg);
			exit(EX_USAGE);
		}
		break;
	default:
		usage(av[0]);
	}

	/*
	 * Validate the options combination.
	 */
	if(!print_arg__print_out) {
		if(print_arg__fix_n_print) {
			fprintf(stderr, "Error: -F requires -E\n");
			exit(EX_USAGE);
		}
	}

	/*
	 * Ensure that there are some input files present.
	 */
	if(ac > optind) {
		ac -= optind;
		av += optind;
	} else {
		fprintf(stderr, "%s: No input files specified\n",
			basename(av[0]));
		exit(1);
	}

	/*
	 * Iterate over input files and parse each.
	 * All syntax trees from all files will be bundled together.
	 */
	for(i = 0; i < ac; i++) {
		asn1p_t *new_asn;

		new_asn = asn1p_parse_file(av[i], asn1_parser_flags);
		if(new_asn == NULL) {
			fprintf(stderr, "Cannot parse \"%s\"\n", av[i]);
			exit(EX_DATAERR);
		}

		/*
		 * Bundle the parsed tree with existing one.
		 */
		if(asn) {
			asn1p_module_t *mod;
			while((mod = TQ_REMOVE(&(new_asn->modules), mod_next)))
				TQ_ADD(&(asn->modules), mod, mod_next);
			asn1p_free(new_asn);
		} else {
			asn = new_asn;
		}

	}

	/*
	 * Dump the parsed ASN.1 tree if -E specified and -F is not given.
	 */
	if(print_arg__print_out && !print_arg__fix_n_print) {
		if(asn1print(asn, print_arg__flags))
			exit(EX_SOFTWARE);
		return 0;
	}


	/*
	 * Process the ASN.1 specification: perform semantic checks,
	 * expand references, etc, etc.
	 * This function will emit necessary warnings and error messages.
	 */
	ret = asn1f_process(asn, asn1_fixer_flags,
		NULL /* default fprintf(stderr) */);
	switch(ret) {
	case 1:
		if(!warnings_as_errors)
			/* Fall through */
	case 0:
		break;			/* All clear */
	case -1:
		exit(EX_DATAERR);	/* Fatal failure */
	}

	/*
	 * Dump the parsed ASN.1 tree if -E specified and -F is given.
	 */
	if(print_arg__print_out && print_arg__fix_n_print) {
		if(asn1print(asn, print_arg__flags))
			exit(EX_SOFTWARE);
		return 0;
	}

	/*
	 * Make sure the skeleton directory is out there.
	 */
	if(skeletons_dir == NULL) {
		struct stat sb;
		skeletons_dir = DATADIR;
		if((av[-optind][0] == '.' || av[-optind][1] == '/')
		&& stat(skeletons_dir, &sb)) {
			/*
			 * The default skeletons directory does not exist,
			 * compute it from my file name:
			 * ./asn1c/asn1c -> ./skeletons
			 */
			char *p;
			int len;

			p = dirname(av[-optind]);

			len = strlen(p) + sizeof("/../skeletons");
			skeletons_dir = alloca(len);
			snprintf(skeletons_dir, len, "%s/../skeletons", p);
			if(stat(skeletons_dir, &sb)) {
				fprintf(stderr,
					"WARNING: skeletons are neither in "
					"\"%s\" nor in \"%s\"!\n",
					DATADIR, skeletons_dir);
				if(warnings_as_errors)
					exit(EX_SOFTWARE);
			}
		}
	}

	/*
	 * Compile the ASN.1 tree into a set of source files
	 * of another language.
	 */
	if(asn1_compile(asn, skeletons_dir, asn1_compiler_flags)) {
		exit(EX_SOFTWARE);
	}

	return 0;
}

/*
 * Print the usage screen and exit(EX_USAGE).
 */
static void
usage(char *av0) {
	fprintf(stderr,
		"ASN.1 Compiler, v" VERSION "\n"
		"Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>\n"
		"Usage: %s [options] ...\n"
		"Where [options] are:\n"
		"\t-E\tRun only the ASN.1 parser and print out the tree\n"
		"\t-F\tDuring -E operation, also perform tree fixing\n"
		"\t-L\tGenerate \"-- #line\" comments in -E output\n"
		"\t-N\tDo not generate certain type of comments in -E output\n"
		"\n"
		"\t-P      \tConcatenate and print the compiled text\n"
		"\t-S <dir>\tDirectory with support (skeleton?) files\n"
		"\t        \t(Default is \"%s\")\n"
		"\t-R      \tRestrict output (tables only, no support code)\n"
		"\n"
		"\t-ftypes88\tUse only ASN.1:1988 embedded types\n"
/*
		"\t-fconstr90\tUse only ASN.1:1990 constructs (not available)\n"
*/
		"\t-fnative-integers\tUse native integers where possible\n"
		"\t-fno-c99\tDisable C99 extensions\n"
		"\t-funnamed-unions\tEnable unnamed unions in structures\n"
		"\n"
		"\t-Werror \tTreat warnings as errors; abort if any warning\n"
		"\t-Wdebug-lexer\tEnable verbose debugging output from lexer\n"
		"\t-Wdebug-fixer\tDebug ASN.1 semantics processor\n"
		"\t-Wdebug-compiler\tDebug ASN.1 compiler\n"
		,
		basename(av0), DATADIR
	);
	exit(EX_USAGE);
}

