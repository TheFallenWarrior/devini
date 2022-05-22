GCC := ../i386-elf-gcc/bin/i386-elf-gcc
GPP := ../i386-elf-gcc/bin/i386-elf-g++
LD  := ../i386-elf-gcc/bin/i386-elf-ld
QEMUx86 := qemu-system-i386

OS_ISO := ./dist/devini.iso
KRN_IMG := ./iso/boot/kernel.bin

CFLAGS := -Og -Wall -c -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc  -fno-builtin

ASM_SRC := $(shell find src/boot -name *.asm)
ASM_OBJ := $(patsubst src/boot/%.asm, build/x86/%.o, $(ASM_SRC))

KRN_SRC := $(shell find src/kernel -name *.c)
KRN_OBJ := $(patsubst src/kernel/%.c, build/c/%.o, $(KRN_SRC))

LIB_SRC := $(shell find sysroot/lib -maxdepth 5 -name *.c)

OBJ := $(ASM_OBJ) $(KRN_OBJ)

.PHONY: all compile assemble build run clean

all: compile assemble build run

compile:
	mkdir -p ./build/c
	$(GCC) $(CFLAGS) --sysroot=./sysroot -isystem=/include -std=gnu11 $(KRN_SRC) $(LIB_SRC)
	mv -f ./*.o -t ./build/c

assemble:
	mkdir -p ./build/x86
	nasm -f elf32 $(ASM_SRC) -o $(ASM_OBJ)

build:
	$(LD) -T ./link.ld -o $(KRN_IMG) $(ASM_OBJ) $(shell find build/c -name *.o)
	mkdir -p ./dist
	grub-mkrescue -o $(OS_ISO) ./iso

run:
	$(QEMUx86) -cdrom $(OS_ISO)

clean:
	rm -r ./build ./dist $(KRN_IMG)
