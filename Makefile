FILES = $(wildcard **/*.s)
OBJECTS = $(FILES:.s=.o)

CC = i386-elf-gcc
LD = i386-elf-ld
AS = nasm
QEMU = qemu-system-x86_64 -hda build/beczuniaos-latest-build.iso

CCFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -m32 -nostartfiles -nostdlib -I$(shell pwd)/kernel/include
LDFLAGS = -T boot/linker.ld -melf_i386
ASFLAGS = -f elf


all: clean build_dir compile $(OBJECTS) link check_multiboot grub run_qemu

build_dir: 
	echo $(FILES)
	mkdir -p build/boot/grub && \
	mkdir -p build/tmp

link:
	$(LD) $(LDFLAGS) $(wildcard build/tmp/*.o) -o build/boot/kernel.bin

check_multiboot:
	grub-file --is-x86-multiboot build/boot/kernel.bin

compile:
	$(CC) $(CCFLAGS) $(shell find . -type f -name "*.cc") -o build/tmp/kernel.o

%.o: %.s
	$(AS) $(ASFLAGS) $< -o build/tmp/$(notdir $@)

grub: 
	cp boot/grub/* build/boot/grub && \
	grub-mkrescue -v -o ./build/beczuniaos-latest-build.iso ./build

clean:
	rm -rf build/

run_qemu:
	$(QEMU)