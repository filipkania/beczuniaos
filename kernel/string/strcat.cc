#include <string.h>

void strcat(char *dst, const char *src) {
    size_t dst_length = strlen(dst);
    int end_addr = dst_length + strlen(src);

    for (size_t i = 0; i < strlen(src); i++) {
        dst[dst_length + i] = src[i];
    }
    dst[end_addr] = '\0';

    return;
}