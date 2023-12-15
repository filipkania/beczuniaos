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

    for (int i = 0; i < 30; i++) {
        char asdf[5];

        itoa(i, asdf);

        Terminal::write(formatstr("Testing: doom now works :sunglasses: {}\n", asdf));
    }

    return 0;
}
