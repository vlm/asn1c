#!/bin/sh

#
# This script is designed to quickly create lots of files in underlying
# test-* directories, do lots of other magic stuff and exit cleanly.
#

# Compute the .asn1 spec name by the given file name.
source=$(echo "$1" | sed -e 's/.*\///')
testno=`echo "$source" | cut -f2 -d'-' | cut -f1 -d'.'`

args=$(echo "$source" | sed -e 's/\.c$//')
testdir=test-${args}

OFS=$IFS
IFS="."
set $args
shift
IFS=$OFS

if [ ! -d $testdir ]; then
	mkdir $testdir		|| exit $?
fi
cd $testdir			|| exit $?
ln -fs ../$source		|| exit $?
# Compile the corresponding .asn1 spec.
set -x
../../asn1c	\
	-S ../../../skeletons	\
	-Wdebug-compiler "$@"	\
	../../../tests/${testno}-*.asn1 || exit $?
set +x

# Create a Makefile for the project.
cat > Makefile <<EOM
CFLAGS=-I. -W -Wall -Werror -g ${CFLAGS} -DEMIT_ASN_DEBUG
SRCS=`echo *.c`
OBJS=\${SRCS:.c=.o}
check-executable: \${OBJS}
	\${CC} \${CFLAGS} -o check-executable \${OBJS}
.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	\${CC} \${CFLAGS} -o \$@ -c \$<
check: check-executable
	./check-executable
clean:
	@rm -f *.o
EOM

# Perform building and checking 
make check	|| exit $?

# Uncomment this to jeopardize debugging
# make clean

