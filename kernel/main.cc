#include <terminal.h>
#include <string.h>
#include <stdlib.h>

extern "C" int main() {
    Terminal::clear();

    ASSERT(1 == 0);

    return 0;
}