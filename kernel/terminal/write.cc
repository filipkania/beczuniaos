#include <terminal.h>
#include <string.h>

void Terminal::write(const char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '\n') {
            size_t p = (currentRow * size::width + currentColumn) * 2;
            framebuffer[p] = str[i];
            framebuffer[p + 1] = combine_colors(Colors::WHITE, Colors::BLACK);

            currentColumn += 1;
        } else {
            currentColumn = size::width;
        }

        if (currentColumn >= size::width) {
            currentRow += 1;
            currentColumn = 0;

            if (currentRow >= size::height) {
                currentRow = 0;
            }
        }
    }
}