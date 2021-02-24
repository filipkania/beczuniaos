#include <string.h>

char *itoa(int value) {
    int i = 0;
    static char str[128];
    bool isNegative = (value < 0);

    if (isNegative)
        value = -value;

    do {
        str[i++] = value % 10 + '0';
    } while ((value /= 10) > 0);

    if (isNegative) {
        str[i++] = '-';
    }
    str[i] = '\0';

    reverse_string(str);

    return str;
}