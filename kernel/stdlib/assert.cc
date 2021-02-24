#include <stdlib.h>
#include <terminal.h>
#include <string.h>

void __internal_assert(const char *msg, const char *file, int line, const char *function) {
    char str[150] = "\n";
    char line_str[5];

    strcat(str, function);
    strcat(str, "(): ");

    strcat(str, file);
    strcat(str, ":");

    itoa(line, line_str);
    strcat(str, line_str);

    strcat(str, " - assertion ");

    strcat(str, msg);

    strcat(str, " failed.");

    Terminal::write(str);

    __ABORT();
}