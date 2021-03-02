#include <string.h>
#include <stdlib.h>


char *formatstr(const char *format, ...) {
    va_list params;
    va_start(params, format);

    return __internal__format(format, params);
}

char *__internal__format(const char* format, va_list params) {
    static char str[512];
    bool canHaveNextArgument = true;
    size_t location = 0;

    for (size_t i = 0; i < 512; i++)
        str[i] = '\0';

    for (size_t i = 0; i < strlen(format); i++) {
        if (format[i] == '{' && format[i + 1] == '}' && canHaveNextArgument) {
            const char *arg = va_arg(params, char *);

            if (arg != nullptr) {
                location += strcat(str, arg);
            } else {
                location += strcat(str, "{}");
                canHaveNextArgument = false;
            }
        } else if (format[i - 1] == '{' && format[i] == '}' && canHaveNextArgument)
            continue;
        else {
            str[location] = format[i];
            location += 1;
        }
    }

    auto length = strlen(str);
    str[length] = '\0';
    ASSERT(length < 512);

    va_end(params);

    return str;
}