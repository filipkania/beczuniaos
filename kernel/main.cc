#include <terminal.h>
#include <string.h>
#include <stdlib.h>

extern "C" int main() {
    Terminal::clear();

    Terminal::write("test", Terminal::Colors::CYAN, Terminal::Colors::DARK_GREY);
    char a[5];
    char b[] = "test";
    memmove(a, b, 4);
    Terminal::write(a);

    return 0;
}