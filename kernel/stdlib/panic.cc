#include <stdlib.h>
#include <terminal.h>

void KERNEL_PANIC() {
    Terminal::clear();
    Terminal::write("KERNEL PANIC! :((");

    __ABORT();
}