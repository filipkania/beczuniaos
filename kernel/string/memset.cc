#include <string.h>

void *memset(void *dst, int value, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ((unsigned char *) dst)[i] = ((unsigned char *) value)[i];
    }

    return dst;
}