# Devini

Devini is a C framework for making bare-metal x86 programs.
It has its own custom kernel and libc, and aims to make it
easy to port existing terminal programs and tools to it.

## Using

Disclaimer: As Devini is on very early stages of
development, it may need some tinkering to get it working
for an specific use.

Simply edit the src/kernel/main.c to include your custom
code, you may also add new source and header files to that
folder and they'll be compiled as well, without the need
of editing the makefile.

## Building

In order to build the system, you'll need a Linux machine
(or equivalent UNIX-like environment), and a gcc
cross-compiler targeting elf-i386; run `gettoolchain.sh`
to have it automatically set up for you.

You'll also need  make, nasm, grub (for the
grub-mkrescue command), qemu and xorriso. If you are
on Debian-based distro you can run `sudo apt install
make nasm qemu qemu-system-x86 xorriso` to install them.

After that, you only need to type `make` from the
project directory, and a bootable iso will be
created in the 'dist' folder.

## to-do
_Read 'todo.txt' in the top-level directory for the full list._
* Make a proper keyboard driver that uses interrupts;
* Add a `printf()` function;
* Improve the libc so it's slightly more compliant;
* Add support for FAT-formatted floppies and hard-disks;
* Add a UNIX-like virtual filesystem.