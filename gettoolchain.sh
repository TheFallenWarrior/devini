#!/bin/bash

if [ $(uname -m) = "x86_64" ]; then
    wget https://newos.org/toolchains/i386-elf-7.5.0-Linux-x86_64.tar.xz
    tar -x -f i386-elf-7.5.0-Linux-x86_64.tar.xz
    mkdir ./toolchain/
    mv i386-elf-7.5.0-Linux-x86_64 ./toolchain/i386-elf-gcc
    rm i386-elf-7.5.0-Linux-x86_64.tar.xz
    echo Cross-compiler installed at \'./toolchain\'.
elif [[ $(uname -m) = "i386" || $(uname -m) = "i686" ]]; then
    echo You don\'t need a cross-compiler. Regular gcc will be used instead.
else
    echo The toolchain isn\'t supported by your architecture.
    echo Either build your own cross-compiler or use an emulated machine as your build envirenment
fi