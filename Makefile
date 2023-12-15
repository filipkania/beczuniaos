AS = i686-elf-as
CC = i686-elf-g++
QEMU = qemu-system-x86_64

CCFLAGS = -std=c++2a -ffreestanding -O2 -Wall -Wextra -Wno-unused-variable -Ikernel/include
QEMUFLAGS = -s -hda build/beczuniaos-latest-build.iso -serial stdio -display gtk

CC_SOURCES := $(shell find . -type f -name "*.cc")
ASM_SOURCES := $(shell find . -type f -name "*.s")

OBJ = ${CC_SOURCES:.cc=.o} ${ASM_SOURCES:.s=.o}

all:
	${MAKE} build

run:
	${MAKE} build && ${MAKE} qemu

build: prepare grub

prepare:
	rm -rf build/
	mkdir -p build/boot/grub
	mkdir build/target
	cp boot/grub/* build/boot/grub

%.o: %.cc
	${CC} $(CCFLAGS) -c $< -o build/target/$(notdir $@)

%.o: %.s
	${AS} $< -o build/target/$(notdir $@)

kernel.bin: ${OBJ}
	${CC} -T boot/linker.ld -o build/boot/kernel.bin -ffreestanding -O2 -nostdlib $(addprefix build/target/, $(notdir $^))

check-multiboot: kernel.bin
	grub-file --is-x86-multiboot build/boot/kernel.bin

grub: check-multiboot
	grub-mkrescue -o build/beczuniaos-latest-build.iso build/


clear_objects:
	rm -rf $(OBJ)

clean: clear_objects
	rm -rf build/


qemu:
	$(QEMU) $(QEMUFLAGS)
