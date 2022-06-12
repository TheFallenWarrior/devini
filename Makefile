GCCx64 := ./toolchain/i386-elf-gcc/bin/i386-elf-gcc
GPPx64 := ./toolchain/i386-elf-gcc/bin/i386-elf-g++
LDx64  := ./toolchain/i386-elf-gcc/bin/i386-elf-ld
GCC := gcc
GPP := gpp
LD  := ld
QEMU := qemu-system-i386

OS_ISO := ./dist/devini.iso
KRN_IMG := ./iso/boot/kernel.bin

CFLAGS := -Og -Wall -c -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc  -fno-builtin

ASM_SRC := $(shell find src/boot -name *.asm)
KRN_SRC := $(shell find src/kernel -name *.c)
LIB_SRC := $(shell find sysroot/lib -maxdepth 5 -name *.c)

.PHONY: all compile assemble build run clean

all: compile assemble build run

compile:
	mkdir -p ./build/c
	if [ $(shell uname -m) = "x86_64" ]; then \
		$(GCCx64) $(CFLAGS) --sysroot=./sysroot -isystem=/include -std=gnu11 $(KRN_SRC) $(LIB_SRC) ;\
	elif [[ $(shell uname -m) = "i386" || $(shell uname -m) = "i686"]]; then \
		$(GCC) $(CFLAGS) --sysroot=./sysroot -isystem=/include -std=gnu11 $(KRN_SRC) $(LIB_SRC) ;\
	fi
	mv -f ./*.o -t ./build/c

assemble:
	mkdir -p ./build/x86
	nasm -f elf32 $(ASM_SRC)
	mv -f ./src/boot/*.o -t ./build/x86

build:
	mkdir -p ./dist
	if [ $(shell uname -m) = "x86_64" ]; then \
		$(LDx64) -T ./link.ld -o $(KRN_IMG) $(shell find ./build/ -maxdepth 3 -name *.o) ;\
	elif [[ $(shell uname -m) = "i386" || $(shell uname -m) = "i686"]]; then \
		$(LD) -T ./link.ld -o $(KRN_IMG) $(shell find ./build/ -maxdepth 3 -name *.o) ;\
	fi
	grub-mkrescue -o $(OS_ISO) ./iso

run:
	$(QEMU) -cdrom $(OS_ISO)

clean:
	rm -r ./build ./dist $(KRN_IMG)
