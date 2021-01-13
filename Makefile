OBJECTS := boot/boot.o

CC = i386-elf-gcc
LD = i386-elf-ld
AS = nasm
QEMU = qemu-system-x86_64 -hda build/beczuniaos-latest-build.iso

CCFLAGS = -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T boot/linker.ld -melf_i386
ASFLAGS = -f elf


all: clean build_dir kernel.bin grub run_qemu

build_dir: 
	mkdir -p build/boot/grub && \
	mkdir -p build/tmp

kernel.bin: $(OBJECTS)
	$(LD) $(LDFLAGS) $(wildcard build/tmp/*.o) -o build/boot/kernel.bin

%.c: %.c
	$(CC) $(CFLAGS) $< -o build/tmp/$(notdir $@)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o build/tmp/$(notdir $@)

grub: 
	cp boot/grub/* build/boot/grub && \
	grub-mkrescue -v -o ./build/beczuniaos-latest-build.iso ./build

clean:
	rm -rf build/

run_qemu:
	$(QEMU)