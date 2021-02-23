#include <terminal.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    Terminal::write("test", Terminal::Colors::CYAN, Terminal::Colors::DARK_GREY);

    char poc[10];
    memset(poc, (int) "12345", 5);

    Terminal::write(poc);

    return 0;
}