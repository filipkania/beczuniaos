#include <stdlib.h>
#include <terminal.h>
#include <string.h>

void __internal_assert(const char *msg, const char *file, int line, const char *function) {
    auto str = formatstr(
        "\n{}(): {}:{} - assertion {} failed.",
        function,
        file,
        itoa(line),
        msg
    );

    Terminal::write(str);

    __ABORT();
}