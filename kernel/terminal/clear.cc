#include <terminal.h>

size_t Terminal::lastRow = 0;
size_t Terminal::lastColumn = 0;

void Terminal::clear() {
    for (size_t y = 0; y < size::height; y++) {
        for (size_t x = 0; x < size::width; x++) {
            size_t i = (y * size::width + x) * 2;
            framebuffer[i] = ' ';
            framebuffer[i + 1] = combine_colors(Colors::WHITE, Colors::BLACK);
        }
    }

    lastColumn = 0;
    lastRow = 0;
}