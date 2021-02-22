#include <terminal.h>

void Terminal::clear() {
    for(size_t row = 0; row < Terminal::size::width; row++) {
        for(size_t col = 0; col < Terminal::size::height; col++) {
            framebuffer[row * col * 2] = ' ';
        }
    }
}