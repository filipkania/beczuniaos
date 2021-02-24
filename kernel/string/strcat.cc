#include <string.h>

int strcat(char *dst, const char *src) {
    size_t dst_length = strlen(dst);
    size_t src_length = strlen(src);
    int end_addr = dst_length + src_length;

    for (size_t i = 0; i < strlen(src); i++) {
        dst[dst_length + i] = src[i];
    }
    dst[end_addr] = '\0';

    return src_length;
}