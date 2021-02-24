#include <terminal.h>
#include <string.h>
#include <stdlib.h>

extern "C" int main() {
    Terminal::clear();

    Terminal::write("test", Terminal::Colors::CYAN, Terminal::Colors::DARK_GREY);
    char a[5];
    itoa(-41, a);
    ASSERT_NOT_REACHED();
    Terminal::write(a);

    return 0;
}