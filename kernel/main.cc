#include <terminal.h>
#include <stdlib.h>
#include <serial.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    if (Serial::initialize())
        Serial::READY = 1;

    dbgln("test {}", "ABCDEF");
    dbgln("test {}", "ABCDEF");

    ASSERT_NOT_REACHED();

    return 0;
}