#include <stdlib.h>

void __ABORT() {
    asm("hlt");
    while(1) {};
}