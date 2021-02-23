AS = i686-elf-as
CC = i686-elf-g++

CCFLAGS = -std=c++2a -ffreestanding -O2 -Wall -Wextra -Wno-unused-variable

CC_SOURCES := $(shell find . -type f -name "*.cc")
ASM_SOURCES := $(shell find . -type f -name "*.s")

OBJ = ${CC_SOURCES:.cc=.o} ${ASM_SOURCES:.s=.o}

all:
	${MAKE} build || ${MAKE} prepare

build: prepare grub

prepare:
	rm -rf build/
	mkdir -p build/boot/grub
	cp boot/grub/* build/boot/grub

%.o: %.cc
	${CC} $(CCFLAGS) -c $< -o $@ -Ikernel/include

%.o: %.s
	${AS} $< -o $@

kernel.bin: ${OBJ}
	${CC} -T boot/linker.ld -o build/boot/kernel.bin -ffreestanding -O2 -nostdlib $^ -Ikernel/include

check-multiboot: kernel.bin
	grub-file --is-x86-multiboot build/boot/kernel.bin

grub: check-multiboot
	grub-mkrescue -o build/beczuniaos-latest-build.iso build/


clear_objects:
	rm -rf $(OBJ)