#include <string.h>

int memcmp(const void *a, const void *b, size_t size) {
    const auto a_src = (unsigned char *) a;
    const auto b_src = (unsigned char *) b;

    for (size_t i = 0; i < size; i++) {
        if (a_src[i] > b_src[i])
            return -1;
        else if (b_src[i] > a_src[i])
            return 1;
    }

    return 0;
}