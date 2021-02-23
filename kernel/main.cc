#include <terminal.h>

extern "C" int main() {
    Terminal::clear();
    Terminal::write("Hey!");

    return 0;
}