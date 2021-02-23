#include <terminal.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    char test[] = "abcdef";
    strcat(test, "\n12345");

    Terminal::write(test);
    return 0;
}