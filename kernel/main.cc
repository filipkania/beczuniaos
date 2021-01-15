#include <terminal.h>

extern "C" int main() {
	// Terminal::initialize();
	Terminal::write("abcdef");

	while(1) {};
	return 0;
}