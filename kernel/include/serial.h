#pragma once

#include <stdint.h>

namespace Serial {
    static const uint16_t COM_PORT = 0x3f8;
    extern int READY;
    bool initialize();

    void send(const char *str);
}