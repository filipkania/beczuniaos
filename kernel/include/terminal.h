#pragma once

#include <stddef.h>
#include <stdint.h>

namespace Terminal {
    enum Colors {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHT_GREY = 7,
        DARK_GREY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        LIGHT_BROWN = 14,
        WHITE = 15
    };

    struct size {
        static const size_t width = 80;
        static const size_t height = 25;
    };

    static unsigned int lastRow = 0;
    static unsigned int lastColumn = 0;

    static auto framebuffer = (char *) 0xB8000;

    void write(const char *str, Colors text_color = Colors::WHITE, Colors background_color = Colors::BLACK);

    void clear();

    void move_higher();

    uint8_t combine_colors(enum Terminal::Colors foreground, enum Terminal::Colors background);

}