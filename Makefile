#############################################################################
# File name:  Makefile
# Author:     $Author: chadd $
# Date:       Sep 7, 2011
# Class:      CS 300
# Assignment: In Class Example
# Purpose: 		This is the Makefile for the CS300 sample code.    
# RevisionID:  $Id: Makefile 54 2011-09-29 23:07:21Z chadd $
#############################################################################


CC=gcc
CFLAGS=-g -Wall
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ec --color -fCourier8

# -g  include debug symbols in the executable so that the code can be
# 		run through the debugger effectively
#
# -Wall	show all warnings from gcc

.PHONY: clean

# TARGETS is used below to hold the name of all the executables
# built by this Makefile.  This allows us to add the executable name
# in one place and have both all and clean updated. 

# Note that the list is spanning two lines.  The \ character indicates that
# the list continues on the next line.  WARNING: There must be no characters
# other than the newline after the \.  A blank space after the \ gives errors. 

TARGETS=bin/pointers bin/pointersWorksheet  bin/pointersTest \
	bin/pointerToStaticData bin/charArraysAndStrings bin/fileIO \
	bin/handles bin/bitShift bin/structExample  bin/structExampleWithStrings \
	bin/examstats bin/commandLineArgs bin/resizeArray bin/functionPointers \
	bin/helloworld bin/constants

all: bin ${TARGETS}

bin:
	mkdir -p bin

# Automatically generate rules
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
bin/%: bin/%.o
	gcc -o $@ ${CFLAGS} $^

bin/%.o: src/%.c
	gcc -c -o $@ ${CFLAGS} $<


# Custom rules
# bin/helloworld: bin/helloworld.o 
# 	${CC} ${CFLAGS} -o bin/functionPointers bin/functionPointers.o 
	
# bin/helloworld.o: src/helloworld.c
# 	${CC} ${CFLAGS} -o bin/helloworld.o -c src/helloworld.c

clean:
	rm -rf bin/*.o ${TARGETS} bin/*.pdf

valgrind: bin/examstats
	valgrind ${VALGRIND_FLAGS} bin/examstats

printexamstats:
	enscript ${ENSCRIPT_FLAGS} src/examstats.c  | ps2pdf - bin/examstats.pdf

valgrindresizeArray: bin/resizeArray
	valgrind ${VALGRIND_FLAGS} bin/resizeArray

# https://www.gnu.org/software/make/manual/html_node/Chained-Rules.html
# https://www.gnu.org/software/make/manual/html_node/Special-Targets.html
.PRECIOUS: bin/%.o
