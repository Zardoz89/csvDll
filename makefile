# Simple makefile to compile a Gemix module on linux

.PHONY: all clean 32 64

CC = gcc
CFLAGS ?= -fPIC -fpermissive #-funsigned-char -w -O1
LDFLAGS ?= -shared
INCLUDE = -Iinclude
# Uncomment to enable debug mode of CSV module
DEFS = #-DCSV_DEBUG

C32  = -m32 -DGMX_BUILD_32BIT
C64  = -m64 -DGMX_BUILD_64BIT

all: dist/x86/GMXEXT_mod_csv.so dist/x64/GMXEXT_mod_csv.so

32: dist/x86/GMXEXT_mod_csv.so

64: dist/x64/GMXEXT_mod_csv.so

dist/x86/GMXEXT_mod_csv.so: src/csv.cpp src/csv_funcs.cpp src/csv_parser.cpp
	mkdir -p dist/x86
	$(CC) ${C32} ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${DEFS} $^ -o $@

dist/x64/GMXEXT_mod_csv.so: src/csv.cpp src/csv_funcs.cpp src/csv_parser.cpp
	mkdir -p dist/x64
	$(CC) ${C64} ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${DEFS} $^ -o $@

clean:
	rm -rf dist/*

