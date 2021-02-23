#include <string.h>

char *reverse_string(char *str) {
    char temp;
    for(size_t i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return str;
}