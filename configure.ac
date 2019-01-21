AC_INIT([asn1c],[0.9.29],[vlm@lionet.info])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_MACRO_DIR([m4])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_YACC
AM_PROG_LEX
dnl locate ar using standard macro (old automake 1.11 does not know about AM_PROG_AR)
m4_ifdef([AM_PROG_AR],
         [AM_PROG_AR],
         [AC_PATH_PROG(AR, ar, ar, $PATH:/usr/ucb:/usr/ccs/bin)])

AC_PROG_CXX
CXXFLAGS="-std=c++11"

LT_INIT

dnl If you need to see the details, just run make V=1.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

case "$host_os" in
cygwin)
	case "$target" in
	*mingw*)
		CC="$CC -mno-cygwin"
	esac
	;;
esac

AC_ARG_ENABLE([ASN_DEBUG],
  [AS_HELP_STRING([--enable-ASN_DEBUG],
                  [produce debug log during `make check` testing])],
  [enable_asn_debug=$enableval], [enable_asn_debug=no])
  AS_IF([test x$enable_asn_debug != xno], [
      TESTSUITE_CFLAGS="-DASN_EMIT_DEBUG"
      SKELETONS_CFLAGS="-DASN_EMIT_DEBUG"
  ])

AX_CHECK_COMPILE_FLAG([-Wall], [CFLAGS="$CFLAGS -Wall"])
AX_CHECK_COMPILE_FLAG([-Wcast-qual], [CFLAGS="$CFLAGS -Wcast-qual"])
AX_CHECK_COMPILE_FLAG([-Wchar-subscripts],
      [CFLAGS="$CFLAGS -Wchar-subscripts"])
AX_CHECK_COMPILE_FLAG([-Wmissing-prototypes],
      [CFLAGS="$CFLAGS -Wmissing-prototypes"])
AX_CHECK_COMPILE_FLAG([-Wmissing-declarations],
      [CFLAGS="$CFLAGS -Wmissing-declarations"])

dnl There are legitimate uses for these features, disable warnings/errors.
AX_CHECK_COMPILE_FLAG([-Wno-error=attributes],
      [CFLAGS="$CFLAGS -Wno-error=attributes"])
AX_CHECK_COMPILE_FLAG([-Wno-error=cast-align],
      [CFLAGS="$CFLAGS -Wno-error=cast-align"])
AX_CHECK_COMPILE_FLAG([-Wno-error=visibility],
      [CFLAGS="$CFLAGS -Wno-error=visibility"])
AX_CHECK_COMPILE_FLAG([-Wno-error=parentheses-equality],
      [CFLAGS="$CFLAGS -Wno-error=parentheses-equality"])
AX_CHECK_COMPILE_FLAG([-std=gnu99],
      [CFLAGS="$CFLAGS -std=gnu99"
       TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} -std=gnu99"])
AX_CHECK_COMPILE_FLAG([-Wno-error=unused-variable],
      [TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} -Wno-error=unused-variable"])

dnl Lower the optimization level in tests to aid debugging.
dnl AX_CHECK_COMPILE_FLAG([-O1],
dnl    [TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} -O1"])
dnl AX_CHECK_COMPILE_FLAG([-fno-inline],
dnl     [TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} -fno-inline"])

AX_CODE_COVERAGE
AS_IF([test x$enable_code_coverage != xno], [
	CFLAGS="$CFLAGS $CODE_COVERAGE_CFLAGS"
	# The CODE_COVERAGE_CPPFLAGS contains -DNDEBUG flag
	# which removes assert(...) macros from code coverage and improves the
	# branches score. But when it is defined it results in few
	# unsed-but-set-variable warnings that are treated as errors in the travis-ci
	# build because these variables are only used inside assert macros.
	# error: variable ‘ret’ set but not used [-Werror=unused-but-set-variable]
	#CPPFLAGS="$CPPFLAGS $CODE_COVERAGE_CPPFLAGS"
	CXXFLAGS="$CXXFLAGS $CODE_COVERAGE_CXXFLAGS"
	AC_SEARCH_LIBS(gcov_open, gcov, [LDFLAGS="$LDFLAGS $CODE_COVERAGE_LDFLAGS"])
])

dnl Skeletons should be very compatible with most of the compilers, hence
dnl very strict backward compatibility flags.
SKELETONS_CFLAGS="${ADD_CFLAGS} ${SKELETONS_CFLAGS}"
AX_CHECK_COMPILE_FLAG([-std=c89],
    [SKELETONS_CFLAGS="$SKELETONS_CFLAGS -std=c89"])
AX_CHECK_COMPILE_FLAG([-Wpedantic],
    [SKELETONS_CFLAGS="$SKELETONS_CFLAGS -Wpedantic"],
    [
        dnl When -Wpedantic is not supported try the -pedantic instead. (gcc-4.7)
        dnl See https://gcc.gnu.org/gcc-4.8/changes.html
        AX_CHECK_COMPILE_FLAG([-pedantic],
            [SKELETONS_CFLAGS="$SKELETONS_CFLAGS -pedantic"], [], [-Werror])
    ],
    [-Werror]) #clang 3.0 prints warning when the flag is not supported

AC_ARG_ENABLE(Werror,
  [AS_HELP_STRING([--enable-Werror],
                  [abort compilation after any C compiler warning])],
  [enable_werror=$enableval], [enable_werror=no])
  AS_IF([test x$enable_werror != xno], [
      ADD_CFLAGS="${ADD_CFLAGS} -Werror -W -Wall -Wpointer-arith"
      SKELETONS_CFLAGS="${SKELETONS_CFLAGS} -Werror -W -Wall -Wpointer-arith"
      AX_CHECK_COMPILE_FLAG([-Wgnu],
        [SKELETONS_CFLAGS="${SKELETONS_CFLAGS} -Wgnu"])
  ])

AX_CHECK_COMPILE_FLAG([-Wno-long-long],
        [SKELETONS_CFLAGS="${SKELETONS_CFLAGS} -Wno-long-long"])

AC_ARG_ENABLE(test-Werror,
  [AS_HELP_STRING([--enable-test-Werror],
                  [abort compiling tests after any C compiler warning])],
  [enable_test_werror=$enableval], [enable_test_werror=no])
  AS_IF([test x$enable_test_werror != xno], [
      TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} -Werror -W -Wpointer-arith"
  ])

dnl If requested and -m32 is available to create 32-bit code,
dnl treat it like a special case to be checked.
AC_ARG_ENABLE([test-32bit],
    [AS_HELP_STRING([--enable-test-32bit],
    [enable tests for 32-bit compatibility])],
    [enable_test_32bit=$enableval], [enable_test_32bit=no])
AS_IF([test "x$enable_test_32bit" != xno], [
    AX_CHECK_COMPILE_FLAG([-m32], [CFLAGS_M32="-m32 -DEXPLICIT_32BIT"],
      [
        CFLAGS_M32=""
        AC_MSG_FAILURE([--enable-test-32bit=$enable_test_32bit is requested but not supported by the _AC_LANG compiler])
      ])
])
AC_SUBST(CFLAGS_M32)
AM_CONDITIONAL([EXPLICIT_M32], [test "x${CFLAGS_M32}" != "x"])

SANITIZER_CFLAGS=""

dnl Enable Undefined Behavior Sanitizer, if supported.
AC_ARG_ENABLE([test-ubsan],
    [AS_HELP_STRING([--disable-test-ubsan],
        [disable Undefined Behavior Sanitizer for tests])],
    [disable_test_ubsan=$enableval], [disable_test_ubsan=maybe])
AS_IF([test "x$disable_test_ubsan" != xno], [
    AX_CHECK_COMPILE_AND_LINK_FLAG([-fsanitize=undefined],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fsanitize=undefined"],
      [
        AS_IF([test "x$disable_test_ubsan" != xmaybe], [
            AC_MSG_FAILURE(
[--disable-test-ubsan=$disable_test_ubsan is not supported on a target system.
https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html#how-to-build])])
      ],
      [],
      [AC_LANG_PROGRAM([void test(int *);void test(int *n) { *n = 0; }])]
    )
    AX_CHECK_COMPILE_FLAG([-fno-sanitize-recover=undefined],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fno-sanitize-recover=undefined"])

    dnl Unsigned integer overflow is enabled separately.
    AX_CHECK_COMPILE_AND_LINK_FLAG([-fsanitize=unsigned-integer-overflow],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fsanitize=unsigned-integer-overflow"], [], [], [AC_LANG_PROGRAM([int test(unsigned); int test(unsigned n) { return n + 1; }])])
    AX_CHECK_COMPILE_FLAG([-fno-sanitize-recover=unsigned-integer-overflow],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fno-sanitize-recover=unsigned-integer-overflow"])

    dnl Nullability is enabled separately.
    AX_CHECK_COMPILE_AND_LINK_FLAG([-fsanitize=nullability],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fsanitize=nullability"])
    AX_CHECK_COMPILE_FLAG([-fno-sanitize-recover=nullability],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fno-sanitize-recover=nullability"])

    dnl Keep error messages nice. Also consider:
    dnl export ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer
    dnl export UBSAN_OPTIONS=print_stacktrace=1
    AX_CHECK_COMPILE_FLAG([-fno-omit-frame-pointer],
          [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fno-omit-frame-pointer"])
])

dnl Enable Address Sanitizer, if supported by gcc (4.8+) or clang.
dnl http://clang.llvm.org/docs/AddressSanitizer.html
ASAN_ENV_FLAGS=""
AC_ARG_ENABLE([test-asan],
    [AS_HELP_STRING([--disable-test-asan],
        [disable Address Sanitizer for tests])],
    [disable_test_asan=$enableval], [disable_test_asan=maybe])
AS_IF([test "x$disable_test_asan" != xno], [
    AX_CHECK_COMPILE_AND_LINK_FLAG([-fsanitize=address],
      [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fsanitize=address"],
      [
        AS_IF([test "x$disable_test_asan" != xmaybe], [
            AC_MSG_FAILURE(
[--disable-test-asan=$disable_test_asan is not supported on a target system.
Check out https://clang.llvm.org/docs/AddressSanitizer.html#how-to-build])])
      ])

    dnl Address sanitizer sometimes is equipped with the leak sanitizer.
    dnl If address sanitizer is not equipped with a leak sanitizer,
    dnl invoking programs with ASAN_OPTIONS=detect_leaks=1 will break them.
    ASAN_OPTIONS="detect_leaks=1"
    export ASAN_OPTIONS
    save_cflags="${CFLAGS}"
    CFLAGS="${CFLAGS} ${SANITIZER_CFLAGS}"
    AC_RUN_IFELSE([AC_LANG_PROGRAM()], [
        ASAN_ENV_FLAGS="${ASAN_ENV_FLAGS} ASAN_OPTIONS=detect_leaks=1"
    ])
    CFLAGS="${save_cflags}"
    unset ASAN_OPTIONS

    dnl Keep error messages nice. Also consider:
    dnl export ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer
    dnl export ASAN_OPTIONS=symbolize=1
    AX_CHECK_COMPILE_FLAG([-fno-omit-frame-pointer],
          [SANITIZER_CFLAGS="${SANITIZER_CFLAGS} -fno-omit-frame-pointer"])
])

dnl Enable LibFuzzer, if supported.
LIBFUZZER_CFLAGS=""
AC_ARG_ENABLE([test-fuzzer],
    [AS_HELP_STRING([--enable-test-fuzzer],
        [enable LLVM LibFuzzer for randomized testing])],
    [enable_test_fuzzer=$enableval], [enable_test_fuzzer=no])
AS_IF([test "x$enable_test_fuzzer" != xno], [
    AX_CHECK_COMPILE_AND_LINK_FLAG([-fsanitize=fuzzer],
    [LIBFUZZER_CFLAGS="-fsanitize=fuzzer -DENABLE_LIBFUZZER"],
    [AC_MSG_FAILURE(
[--enable-test-fuzzer=$enable_test_fuzzer is not supported on a target system.
Check out http://llvm.org/docs/LibFuzzer.html])],
    [],
    [AC_LANG_SOURCE([[
    #include <sys/types.h>
    int LLVMFuzzerTestOneInput(const unsigned char *Data, size_t Size);
    int LLVMFuzzerTestOneInput(const unsigned char *Data, size_t Size) {
        (void)Data;
        (void)Size;
        return 0;
    }
    ]])])
])

TESTSUITE_CFLAGS="${TESTSUITE_CFLAGS} ${SANITIZER_CFLAGS}"
SKELETONS_CFLAGS="${SKELETONS_CFLAGS} ${SANITIZER_CFLAGS}"

AC_SUBST(ADD_CFLAGS)
AC_SUBST(LIBFUZZER_CFLAGS)
AC_SUBST(SANITIZER_CFLAGS)
AC_SUBST(TESTSUITE_CFLAGS)
AC_SUBST(SKELETONS_CFLAGS)
AC_SUBST(ASAN_ENV_FLAGS)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/param.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_CHECK_TYPE([__int128],
    [AC_DEFINE(HAVE_128_BIT_INT, 1, [Have 128-bit integer])])
AC_CHECK_TYPE(intmax_t, int64_t)

dnl Test if we should test features that depend on 64-bitness.
AC_CHECK_SIZEOF([void *])
AM_CONDITIONAL([TEST_64BIT], [test "$ac_cv_sizeof_void_p" -eq 8])

dnl For mingw
AC_SEARCH_LIBS(getopt, iberty)

AC_CHECK_FUNCS(strtoimax strtoll)
AC_CHECK_FUNCS(mergesort)
AC_CHECK_FUNCS(mkstemps)
AC_CHECK_FUNCS(timegm)
AC_CHECK_DECLS(strcasecmp)
AC_CHECK_DECLS(vasprintf)
AC_TRY_LINK_FUNC([symlink],[AC_DEFINE([HAVE_SYMLINK], 1, [Define to 1 if you have the symlink function.])])

dnl Use pandoc to generate manual pages.
AC_PATH_PROG([PANDOC], pandoc)
AM_CONDITIONAL([HAVE_PANDOC], [test -n "$PANDOC"])

AC_CONFIG_FILES([\
tests/tests-c-compiler/check-src/Makefile   \
tests/tests-asn1c-compiler/Makefile         \
tests/tests-asn1c-smoke/Makefile            \
tests/tests-randomized/Makefile             \
tests/tests-c-compiler/Makefile             \
tests/tests-skeletons/Makefile              \
asn1-tools/enber/Makefile                   \
asn1-tools/unber/Makefile                   \
asn1-tools/Makefile                         \
libasn1compiler/Makefile                    \
libasn1common/Makefile                      \
libasn1parser/Makefile                      \
libasn1print/Makefile                       \
libasn1fix/Makefile                         \
doc/docsrc/Makefile                         \
skeletons/Makefile                          \
examples/Makefile                           \
doc/man/Makefile                            \
tests/Makefile                              \
asn1c/Makefile                              \
doc/Makefile                                \
Makefile                                    \
])
AC_OUTPUT

