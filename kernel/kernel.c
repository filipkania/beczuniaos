#include "../drivers/video/screen.h"
#include "./util.h"

void main() {
    clear_screen();

    for(int i = 0; i < 50; i++) {
        char a[255];
        int_to_ascii(i, a);
        kprint("test\n");
    }
}