#include "Screen.h";
// Hero sprites

Screen::Screen() {
    // Constructeur
}


void Screen::display(Character character, Character ennemy) {
    //gb.display.setColor(BROWN);
    //gb.display.fillRect(character.getPositionX(), 
    //                    character.getPositionY(), 
    //                    character.getCharacterSize(), 
    //                    character.getCharacterSize());
    gb.display.drawImage(character.getPositionX(),character.getPositionY(),character.getImage());
    gb.display.setColor(RED);
    gb.display.fillRect(ennemy.getPositionX(), 
                        ennemy.getPositionY(), 
                        ennemy.getCharacterSize(), 
                        ennemy.getCharacterSize());
    gb.display.setColor(GREEN);
    // position horinzontale ,position verticale,Longueur, Largeur
    gb.display.fillRect(5,2,character.getLife(),3);
    gb.display.fillRect(45,2,ennemy.getLife(),3);
    gb.display.setFontSize(1);
    gb.display.setCursor(5, 7);
    gb.display.print("Player 1");
    gb.display.setCursor(45, 7);
    gb.display.print("Player 2");
}

void Screen::gameOver(String victory, Character character, Character ennemy) {
    gb.display.println(victory);
    gb.display.println("Press start to play!");
}

