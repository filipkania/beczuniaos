#include <terminal.h>
#include <string.h>
#include <stdlib.h>

extern "C" int main() {
    Terminal::clear();

    static_assert(1);

    ASSERT(1 == 0);

    return 0;
}