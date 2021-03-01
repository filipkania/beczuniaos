#include <serial.h>
#include <io.h>
#include <string.h>

int Serial::READY = 0;

bool Serial::initialize() {
    const int flags[][2] = {
        //{offset, flag}
            {1, 0x00},
            {3, 0x80},
            {0, 0x03},
            {1, 0x00},
            {3, 0x03},
            {2, 0xC7},
            {4, 0x0B},
            {4, 0x1E},
            {0, 0xAE}
    };
    size_t flags_length = sizeof(flags) / sizeof(flags[0]);

    for (size_t i = 0; i < flags_length; i++) {
        outb(COM_PORT + flags[i][0], flags[i][1]);
    }

    if (inb(COM_PORT) != flags[flags_length - 1][1]) {
        return false;
    }

    outb(COM_PORT + 4, 0x0F);
    return true;
}
