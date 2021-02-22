#include <terminal.h>

extern "C" int main() {
    Terminal::clear();
    Terminal::write("test12345");
    return 0;
}