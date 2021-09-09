#include <Gamebuino-Meta.h>;
#include "src/Screen/Screen.h";
#include "src/Character/Character.h";

Character character = Character(22,32,30);
Character ennemy = Character(57,32,30);
Screen screen = Screen();

void setup() {
    gb.begin();
}

void loop() {
    while(!gb.update());
    gb.display.clear();
    if(character.isAlive() && ennemy.isAlive()) {
        character.move();
        character.attack(character, ennemy);
        character.collide(character, ennemy);
        ennemy.botMove(character, ennemy);
        screen.display(character, ennemy);
    } else if (!character.isAlive()) {
        screen.gameOver("Player 2", character, ennemy);
        if (gb.buttons.pressed(BUTTON_MENU)){
            gb.display.print("Bon bouton");
            character.reset();
            ennemy.reset();
        }
    } else if (!ennemy.isAlive()) {
        screen.gameOver("Player 1", character, ennemy);
        if (gb.buttons.pressed(BUTTON_MENU)){
            gb.display.print("Bon bouton");
            character.reset();
            ennemy.reset();
        }
    }
}

