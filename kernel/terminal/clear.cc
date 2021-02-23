#include <terminal.h>

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