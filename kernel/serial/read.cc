#include <serial.h>
#include <io.h>

char Serial::read() {
    while (!serial_received());

    return inb(COM_PORT);
}