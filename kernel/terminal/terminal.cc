#include <string.h>
#include <terminal.h>

struct VGA {
    static const int height = 25;
    static const int width = 80;
};

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color = 0x0E;
uint16_t* terminal_buffer;

uint8_t Terminal::combineColors(const int fg, const int bg) {
    return fg | bg << 4;
}

uint16_t Terminal::vgaEntry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

void Terminal::initialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = combineColors(Colors::WHITE, Colors::BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;

    for (size_t y = 0; y < VGA::height; y++) {
        for (size_t x = 0; x < VGA::width; x++) {
            const size_t index = y * VGA::width + x;
            terminal_buffer[index] = vgaEntry(' ', terminal_color);
        }
    }
}

void Terminal::setColor(uint8_t color) {
    terminal_color = color;
}

void Terminal::putEntryAt(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA::width + x;
    terminal_buffer[index] = vgaEntry(c, color);
}

void Terminal::putChar(char c) {
    putEntryAt(c, terminal_color, terminal_column, terminal_row);

    if (++terminal_column == VGA::width) {
        terminal_column = 0;
        if (++terminal_row == VGA::height)
            terminal_row = 0;
    }
}

void Terminal::writeWithLength(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        putChar(data[i]);
}

void Terminal::write(const char* data) {
    writeWithLength(data, strlen(data));
}