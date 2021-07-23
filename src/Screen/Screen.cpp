#include "Screen.h";

Screen::Screen() {
    // Constructeur
}

void Screen::display(Character character) {
    gb.display.setColor(BROWN);
    gb.display.fillRect(character.getPositionX(), 
                        character.getPositionY(), 
                        character.getCharacterSize(), 
                        character.getCharacterSize());
}