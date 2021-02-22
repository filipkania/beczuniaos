#include <terminal.h>
#include <string.h>

void Terminal::write(const char *str) {
    for (size_t i = 0; i < strlen(str) * 2; i += 2) {
        framebuffer[i] = str[i / 2];
        framebuffer[i + 1] = 0x05;
    }
}