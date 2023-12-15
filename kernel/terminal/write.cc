#include <terminal.h>
#include <string.h>

void Terminal::write(const char *str, Colors text_color, Colors background_color) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (lastRow == size::height - 1 && lastColumn == size::width)
            move_higher();

        if (lastColumn == size::width) {
            lastColumn = 0;

            if (lastRow != size::height - 1) {
                lastRow += 1;
            }
        }

        if (str[i] != '\n') {
            size_t p = (lastRow * size::width + lastColumn) * 2;
            framebuffer[p] = str[i];
            framebuffer[p + 1] = combine_colors(text_color, background_color);

            lastColumn += 1;
        } else {
            lastColumn = size::width;
        }
    }
}
