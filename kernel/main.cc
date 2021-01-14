#include <terminal/terminal.h>

extern "C" int main() {
	Terminal::initialize();
	Terminal::write("ABCDEFGHIJKLMNOPRSTUWXYZ\n");

    return 0;
}