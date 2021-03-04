#include <terminal.h>
#include <stdlib.h>
#include <serial.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    if (Serial::initialize())
        Serial::READY = 1;
    char str[5];
    itoa(5, str);

    dbgln("test {}", str);

    ASSERT_NOT_REACHED();

    return 0;
}