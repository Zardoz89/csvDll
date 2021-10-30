# Simple makefile to compile a Gemix module on linux

.PHONY: all clean 32 64 example install_32 install_64

CC = gcc
CFLAGS ?= -fPIC -fpermissive #-funsigned-char -w -O1
LDFLAGS ?= -shared
INCLUDE = -Iinclude
# Uncomment to enable debug mode of CSV module
DEFS = #-DCSV_DEBUG

C32  = -m32 -DGMX_BUILD_32BIT
C64  = -m64 -DGMX_BUILD_64BIT

GEMIX_COMPILER_PATH := /opt/gemix/
GEMIX_COMPILER := ./gmxc-linux-x86
EXE_PATH := $(CURDIR)/exe/

all: dist/x86/GMXEXT_mod_csv.so dist/x64/GMXEXT_mod_csv.so

32: dist/x86/GMXEXT_mod_csv.so

64: dist/x64/GMXEXT_mod_csv.so

dist/x86/GMXEXT_mod_csv.so: src/csv.cpp src/csv_funcs.cpp src/csv_parser.cpp
	mkdir -p dist/x86
	$(CC) ${C32} ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${DEFS} $^ -o $@

dist/x64/GMXEXT_mod_csv.so: src/csv.cpp src/csv_funcs.cpp src/csv_parser.cpp
	mkdir -p dist/x64
	$(CC) ${C64} ${CFLAGS} ${INCLUDE} ${LDFLAGS} ${DEFS} $^ -o $@

example: examples/example.prg
	cd ${GEMIX_COMPILER_PATH} && ${GEMIX_COMPILER} ${CURDIR}/$< $@
	mkdir -p ${EXE_PATH}
	mv ${GEMIX_COMPILER_PATH}$@* ${EXE_PATH}
	cp examples/*.csv ${EXE_PATH}

install_32: 32
	cp dist/x86 ${GEMIX_COMPILER_PATH}/modules/linux/x86/release

install_64: 64
	cp dist/x64 ${GEMIX_COMPILER_PATH}/modules/linux/x64/release

clean:
	rm -rf dist/*
	rm -rf exe

