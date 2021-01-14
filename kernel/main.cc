#include <terminal.h>

extern "C" int main() {

	Terminal::initialize();
	Terminal::setColor(Terminal::combineColors(Terminal::Colors::CYAN, Terminal::Colors::BLACK));
	Terminal::write("ABCDEF");
    return 0;
}