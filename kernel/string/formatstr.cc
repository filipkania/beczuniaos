#include <string.h>
#include <stdlib.h>


char *formatstr(const char *format, ...) {
    va_list params;
    va_start(params, format);

    static char str[512];
    size_t location = 0;

    for (size_t i = 0; i < 512; i++)
        str[i] = '\0';

    for (size_t i = 0; i < strlen(format); i++) {
        if (format[i] == '{' && format[i + 1] == '}') {
            const char *arg = va_arg(params, char *);

            if (arg != (const char *) nullptr) {
                location += strcat(str, arg);
            } else
                location += strcat(str, "nullptr");
        } else if (format[i - 1] == '{' && format[i] == '}')
            continue;
        else {
            str[location] = format[i];
            location += 1;
        }
    }

    auto length = strlen(str);
    str[length] = '\0';
    ASSERT(length < 512);

    return str;
}