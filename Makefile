C_SOURCES = $(wildcard kernel/*.c kernel/**/*.c drivers/*.c drivers/**/*.c)
HEADERS = $(wildcard kernel/*.h kernel/**/*.c drivers/*.h drivers/**/*.h)
OBJ = ${C_SOURCES:.c=.o}

CC = i386-elf-gcc
LD = i386-elf-ld
# GDB = /usr/local/i386elfgcc/bin/i386-elf-gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g

all: clean run

os-image.bin: boot/bootsector.bin kernel.bin
	cat $^ > beczuniaos-latest-build.bin

kernel.bin: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ --oformat binary

kernel.elf: boot/kernel_entry.o ${OBJ}
	${LD} -o $@ -Ttext 0x1000 $^ 

run: os-image.bin
	qemu-system-i386 -fda beczuniaos-latest-build.bin


# debug: os-image.bin kernel.elf
# 	qemu-system-i386 -s -fda os-image.bin &
# 	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o beczuniaos-latest-build.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o
