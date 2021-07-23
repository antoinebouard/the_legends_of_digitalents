#include "Screen.h";

Screen::Screen() {
    // Constructeur
}

void Screen::display() {
    gb.display.setColor(BROWN);
    gb.display.fillRect(positionX, positionY, character_size, character_size);
}