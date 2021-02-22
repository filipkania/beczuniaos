#include <terminal.h>
#include <stdint.h>

uint8_t Terminal::combine_colors(enum Terminal::Colors foreground, enum Terminal::Colors background) {
    return foreground | background << 4;
}