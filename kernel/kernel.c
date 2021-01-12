#include "../drivers/video/screen.h"

void main() {
    clear_screen();
    sprint_change_color(RED_ON_WHITE);
    sprint("qwertyuiop");
}