#include <terminal.h>

void Terminal::move_higher() {
    for (size_t y = 0; y < size::height - 1; y++) {
        for (size_t x = 0; x < size::width; x++) {
            size_t d = (y * size::width + x) * 2, c = ((y + 1) * size::width + x) * 2;

            framebuffer[d] = framebuffer[c];
            framebuffer[d + 1] = framebuffer[c + 1];
        }
    }

    for (size_t x = 0; x < size::width; x++) {
        size_t d = ((size::height - 1) * size::width + x) * 2;
        framebuffer[d] = ' ';
        framebuffer[d + 1] = combine_colors(Colors::WHITE, Colors::BLACK);
    }

    lastColumn = 0;
}