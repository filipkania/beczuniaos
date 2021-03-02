#include <serial.h>
#include <io.h>

bool Serial::serial_received() {
    return (inb(COM_PORT + 5) & 1) != 0;
}