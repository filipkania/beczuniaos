#pragma once

#include <stdint.h>

namespace Serial {
    static const uint16_t COM_PORT = 0x3f8;
    extern int READY;

    namespace ANSI_Colors {
        static const char *red = "\u001b[32m";
        static const char *black = "\u001b[30;1m";
        static const char *green = "\u001b[32;1m";
        static const char *yellow = "\u001b[33;1m";
        static const char *blue = "\u001b[34;1m";
        static const char *magenta = "\u001b[35;1m";
        static const char *cyan = "\u001b[36;1m";
        static const char *white = "\u001b[37;1m";

        static const char *reset = "\u001b[0m";
    };

    bool initialize();

    void send(const char *str);

    char read();

    bool is_transmit_empty();

    bool serial_received();
}