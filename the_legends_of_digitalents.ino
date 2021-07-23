#include <Gamebuino-Meta.h>
#include "src/Screen/Screen.h";

Screen screen = Screen();

void setup() {
    gb.begin();
}

void loop() {
    while(!gb.update());
    gb.display.clear();
    screen.display();
}