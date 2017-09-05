
AM_CFLAGS = @ADD_CFLAGS@

AM_CPPFLAGS =                       \
    -I$(top_srcdir)/libasn1common   \
    -I$(top_srcdir)/libasn1parser   \
    -I$(top_srcdir)/libasn1print    \
    -I$(top_srcdir)/libasn1fix

noinst_LTLIBRARIES = libasn1compiler.la

libasn1compiler_la_SOURCES =                \
    asn1compiler.c asn1compiler.h           \
    asn1c_misc.c asn1c_misc.h               \
    asn1c_out.c asn1c_out.h                 \
    asn1c_lang.c asn1c_lang.h               \
    asn1c_naming.c asn1c_naming.h           \
    asn1c_save.c asn1c_save.h               \
    asn1c_C.c asn1c_C.h                     \
    asn1c_constraint.c asn1c_constraint.h   \
    asn1c_compat.c asn1c_compat.h           \
    asn1c_ioc.c asn1c_ioc.h                 \
    asn1c_fdeps.c asn1c_fdeps.h             \
    asn1c_internal.h
