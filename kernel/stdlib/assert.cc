#include <stdlib.h>
#include <terminal.h>
#include <string.h>

void __internal_assert(const char *msg, const char *file, int line, const char *function) {
    char line_str[5];
    itoa(line, line_str);

    auto str = formatstr(
        "\n{}(): {}:{} - assertion {} failed.",
        function,
        file,
        line_str,
        msg
    );

    Terminal::write(str);

    __ABORT();
}