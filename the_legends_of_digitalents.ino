#include <Gamebuino-Meta.h>;
#include "src/Screen/Screen.h";
#include "src/Character/Character.h";

Character character = Character(22,32,30);
Character ennemy = Character(57,32,30);
Screen screen = Screen();
int attack_timer = 0;

void setup() {
    gb.begin();
}

void loop() {
    while(!gb.update());
    gb.display.clear();
    if(character.isAlive() && ennemy.isAlive()) {
        attack_timer++;
        character.move();
        character.attack(character, ennemy);
        character.collide(character, ennemy);
        ennemy.botMove(character, ennemy, attack_timer);
        screen.display(character, ennemy);
    } else if (!character.isAlive()) {
        screen.gameOver("You lose ! HAHAHA   YOU'RE BAD !", character, ennemy);
        if (gb.buttons.pressed(BUTTON_MENU)){
            character.reset();
            ennemy.reset();
        }
    } else if (!ennemy.isAlive()) {
        screen.gameOver("You win !", character, ennemy);
        if (gb.buttons.pressed(BUTTON_MENU)){
            character.reset();
            ennemy.reset();
        }
    }
}

