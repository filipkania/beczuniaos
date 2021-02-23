#include <stdlib.h>
#include <terminal.h>

void KERNEL_PANIC() {
    Terminal::clear();
    Terminal::write("KERNEL PANIC! :((");

    asm("hlt");
    while(1) {};
}