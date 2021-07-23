#include "Character.h";

Character::Character() {
}

void Character::move() {
    if (gb.buttons.repeat(BUTTON_LEFT, 0)){
        positionX = positionX - speed;
    }
    if (gb.buttons.repeat(BUTTON_RIGHT, 0)){
        positionX = positionX + speed;
    }
    if (gb.buttons.repeat(BUTTON_DOWN, 0)){
        positionY = positionY + speed;
    }
    if (gb.buttons.repeat(BUTTON_UP, 0)){
        positionY = positionY - speed;
    }    
}

// Getters & Setters
int Character::getPositionX() {
    return this->positionX;
}

void Character::setPositionX(int position) {
    this->positionX = position;
}

int Character::getPositionY() {
    return this->positionY;
}

void Character::setPositionY(int position) {
    this->positionY = position;
}

int Character::getSpeed() {
    return this->speed;
}

void Character::setSpeed(int speed) {
    this->speed = speed;
}

int Character::getCharacterSize() {
    return this->characterSize;
}

void Character::setCharacterSize(int size) {
    this->characterSize = size;
}