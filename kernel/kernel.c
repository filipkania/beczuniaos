#include "../drivers/video/ports.h"

void main() {
    port_byte_out(0x3d4, 14);
    int position = port_byte_in(0x3d5);
    position = position << 8;

    port_byte_out(0x3d4, 15);
    position += port_byte_in(0x3d5);

    int offset_from_vga = position * 2;

    char *vga = 0xb8000;
    vga[offset_from_vga] = 'A'; 
    vga[offset_from_vga+1] = 'E';
}