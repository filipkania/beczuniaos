#include <serial.h>
#include <string.h>
#include <io.h>

void Serial::send(const char *str) {
    if (!READY)
        return;

    for (size_t i = 0; i < strlen(str); i++) {
        outb(COM_PORT, str[i]);
    }

    return;
}