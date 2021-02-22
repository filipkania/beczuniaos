#pragma once

#include <stddef.h>

namespace Terminal {

    struct size {
        static const size_t width = 80;
        static const size_t height = 25;
    };

    static auto framebuffer = (char *) 0xB8000;

    void write(const char *str);

    void clear();
}