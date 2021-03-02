#include <string.h>
#include <serial.h>
#include <stdlib.h>

void __internal__debug(const char *file, int line, const char *format, ...) {
    if (!Serial::READY)
        return;

    va_list params;
    va_start(params, format);

    auto prefix = formatstr(
            "{}[{}:{}]{} ",
            Serial::ANSI_Colors::green,
            file,
            itoa(line),
            Serial::ANSI_Colors::reset
    );

    char format_str[strlen(format) + strlen(prefix) + 5] = {};

    strcat(format_str, prefix);
    strcat(format_str, format);
    strcat(format_str, "\n");

    Serial::send(__internal__format(format_str, params));

    return;
}