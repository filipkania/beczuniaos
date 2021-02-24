#include <string.h>

void *memmove(const void *a, const void *b, size_t size) {
    const auto a_src = (unsigned char *) a;
    const auto b_src = (unsigned char *) b;

    if (a_src > b_src) {
        for (size_t i = 0; i < size; i++) {
            a_src[i] = b_src[i];
        }
    } else {
        for (size_t i = size; i != 0; i--) {
            a_src[i - 1] = b_src[i - 1];
        }
    }

    return (void *) a;
}