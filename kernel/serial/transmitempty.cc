#include <serial.h>
#include <io.h>

bool Serial::is_transmit_empty() {
    return (inb(COM_PORT + 5) & 0x20) != 0;
}