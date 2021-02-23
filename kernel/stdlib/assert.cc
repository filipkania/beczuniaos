#include <stdlib.h>
#include <terminal.h>
#include <string.h>

void __internal_assert(const char *msg, const char *file, int) {
    char str[] = "\nAssertion failed: ";
    strcat(str, file);
    strcat(str, ": ");

    strcat(str, msg);

    Terminal::write(str);

    __ABORT();
}