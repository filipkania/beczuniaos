#include <string.h>
#include <serial.h>
#include <stdlib.h>

void __internal__debug(int type, const char *file, int line, const char *format, ...) {
    if (!Serial::READY)
        return;

    va_list params;
    va_start(params, format);

    char color[10];

    if (type == 1)
        strcat(color, Serial::ANSI_Colors::green);

    if (type == 2)
        strcat(color, Serial::ANSI_Colors::yellow);

    if (type == 3)
        strcat(color, Serial::ANSI_Colors::red);

    char line_str[5];
    itoa(line, line_str);

    auto prefix = formatstr(
            "{}[{}:{}]{} ",
            color,
            file,
            line_str,
            Serial::ANSI_Colors::reset
    );

    char format_str[strlen(format) + strlen(prefix) + 5] = {};

    strcat(format_str, prefix);
    strcat(format_str, format);
    strcat(format_str, "\n");

    Serial::send(__internal__format(format_str, params));

    return;
}