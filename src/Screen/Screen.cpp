#include "Screen.h";
// Hero sprites

Screen::Screen() {
    // Constructeur
}

void Screen::display(Character character) {
    //gb.display.setColor(BROWN);
    //gb.display.fillRect(character.getPositionX(), 
    //                    character.getPositionY(), 
    //                    character.getCharacterSize(), 
    //                    character.getCharacterSize());
    gb.display.drawImage(character.getPositionX(),character.getPositionY(),character.getImage());
}