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

# -g  include debug symbols in the executable so that the code can be
# 		run through the debugger effectively
#
# -Wall	show all warnings from gcc


.PHONY: clean all

# TARGETS is used below to hold the name of all the executables
# built by this Makefile.  This allows us to add the executable name
# in one place and have both all and clean updated. 

# Note that the list is spanning two lines.  The \ character indicates that
# the list continues on the next line.  WARNING: There must be no characters
# other than the newline after the \.  A blank space after the \ gives errors. 

TARGETS=bin/pointers bin/pointersWorksheet  bin/pointersTest \
	bin/pointerToStaticData bin/charArraysAndStrings bin/fileIO \
	bin/handles bin/bitShift

all: ${TARGETS}

bin:
	mkdir -p bin

bin/pointers: bin/pointers.o 
	${CC} ${CFLAGS} -o bin/pointers bin/pointers.o 
	
bin/pointers.o: src/pointers.c
	${CC} ${CFLAGS} -o bin/pointers.o -c src/pointers.c

bin/charArraysAndStrings: bin/charArraysAndStrings.o
	${CC} ${CFLAGS} -o bin/charArraysAndStrings bin/charArraysAndStrings.o
	
bin/charArraysAndStrings.o: src/charArraysAndStrings.c
	${CC} ${CFLAGS} -o bin/charArraysAndStrings.o -c src/charArraysAndStrings.c

bin/pointerToStaticData: bin/pointerToStaticData.o
	${CC} ${CFLAGS} -o bin/pointerToStaticData bin/pointerToStaticData.o
	
bin/pointerToStaticData.o: src/pointerToStaticData.c
	${CC} ${CFLAGS} -o bin/pointerToStaticData.o -c src/pointerToStaticData.c
	
bin/pointersWorksheet: bin/pointersWorksheet.o
	${CC} ${CFLAGS} -o bin/pointersWorksheet bin/pointersWorksheet.o
	
bin/pointersWorksheet.o: src/pointersWorksheet.c
	${CC} ${CFLAGS} -o bin/pointersWorksheet.o -c src/pointersWorksheet.c

bin/defineVsConst: src/defineVsConst.c
	${CC} ${CFLAGS} -o bin/defineVsConst.o -c src/defineVsConst.c

bin/fileIO: bin/fileIO.o
	${CC} ${CFLAGS} -o bin/fileIO bin/fileIO.o
	
bin/fileIO.o: src/fileIO.c
	${CC} ${CFLAGS} -o bin/fileIO.o -c src/fileIO.c

bin/pointersTest: bin/pointersTest.o
	${CC} ${CFLAGS} -o bin/pointersTest bin/pointersTest.o
	
bin/pointersTest.o: src/pointersTest.c
	${CC} ${CFLAGS} -o bin/pointersTest.o -c src/pointersTest.c

bin/handles: bin/handles.o 
	${CC} ${CFLAGS} -o bin/handles bin/handles.o 
	
bin/handles.o: src/handles.c
	${CC} ${CFLAGS} -o bin/handles.o -c src/handles.c


bin/bitShift: bin/bitShift.o 
	${CC} ${CFLAGS} -o bin/bitShift bin/bitShift.o 
	
bin/bitShift.o: src/bitShift.c
	${CC} ${CFLAGS} -o bin/bitShift.o -c src/bitShift.c

clean:
	rm -rf bin/*.o ${TARGETS} 

valgrind: bin/main
	valgrind -v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all bin/main

printMain:
	enscript -C -T 2 -p - -M Letter -Ec --color -fCourier8 src/main.c  | ps2pdf - bin/main.pdf
