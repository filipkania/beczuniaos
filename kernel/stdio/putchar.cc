#include <stdio.h>
#include <terminal.h>

int putchar(int ic) {
    char c = (char) ic;
    Terminal::writeWithLength(&c, sizeof(c));
    return ic;
}