#include <terminal.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    Terminal::write("test", Terminal::Colors::CYAN, Terminal::Colors::DARK_GREY);

    Terminal::write((memcmp("test", "tset", 4) == 0) ? "y" : "n");

    return 0;
}