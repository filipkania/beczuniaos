#include <terminal.h>
#include <string.h>

extern "C" int main() {
    Terminal::clear();

    Terminal::write("test", Terminal::Colors::CYAN, Terminal::Colors::DARK_GREY);

    char test[] = "abcdef";
    char poc[10];

    memcpy(poc, test, strlen(test));

    Terminal::write(poc);

    return 0;
}