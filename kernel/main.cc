#include <terminal.h>

extern "C" int main() {
    Terminal::clear();
    Terminal::write("test\n1234");

    return 0;
}