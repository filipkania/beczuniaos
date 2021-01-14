#include <stdint.h>
#include <stddef.h>

namespace Terminal {
    struct Colors {
        static const int BLACK = 0;
        static const int BLUE = 1;
        static const int GREEN = 2;
        static const int CYAN = 3;
        static const int RED = 4;
        static const int MAGENTA = 5;
        static const int BROWN = 6;
        static const int LIGHT_GREY = 7;
        static const int DARK_GREY = 8;
        static const int LIGHT_BLUE = 9;
        static const int LIGHT_GREEN = 10;
        static const int LIGHT_CYAN = 11;
        static const int LIGHT_RED = 12;
        static const int LIGHT_MAGENTA = 13;
        static const int LIGHT_BROWN = 14;
        static const int WHITE = 15;
    };

    uint8_t combine_colors(const int fg, const int bg);

    uint16_t vga_entry(unsigned char uc, uint8_t color);

    void initialize();

    void setColor(uint8_t color);

    void putEntryAt(char c, uint8_t color, size_t x, size_t y);

    void putChar(char c);

    void writeWithLength(const char* data, size_t size);

    void write(const char* data);
}