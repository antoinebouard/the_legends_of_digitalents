#include <Gamebuino-Meta.h>;
#include "src/Screen/Screen.h";
#include "src/Character/Character.h";

Character character = Character();
Screen screen = Screen();

void setup() {
    gb.begin();
}

void loop() {
    while(!gb.update());
    gb.display.clear();
    character.move();
    screen.display(character);
}