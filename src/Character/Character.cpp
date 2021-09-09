#include "Character.h";

Character::Character(int positionX, int positionY, int life) {
    this->setPositionX(positionX);
    this->setPositionY(positionY);
    this->setBasePositionX(positionX);
    this->setBasePositionY(positionY);
    this->setLife(life);
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
    this->characterInScreen();
}

void Character::attack(Character &character, Character &ennemy) {
    if (gb.buttons.pressed(BUTTON_A)) {
        gb.display.fillCircle(character.getPositionX() + 6, character.getPositionY() + 1,1);
        if (gb.collide.rectRect(character.getPositionX() + 6, character.getPositionY() + 1,1,1,
                                ennemy.getPositionX(), ennemy.getPositionY(), ennemy.getCharacterSize(), ennemy.getCharacterSize())) {
            ennemy.takeDamage(1);
        }
    }
    if (gb.buttons.pressed(BUTTON_B)) {
        gb.display.print("attaque distante");
    }
}

void Character::takeDamage(int damage) {
    gb.display.println(this->getLife());
    this->setLife(this->getLife() - 1);
    gb.display.println(damage);    
    gb.display.println(this->getLife());
}

void Character::collide(Character character, Character ennemy) {
    if(gb.collide.rectRect(character.getPositionX(), character.getPositionY(), character.getCharacterSize(), character.getCharacterSize(),
                            ennemy.getPositionX(), ennemy.getPositionY(), ennemy.getCharacterSize(), ennemy.getCharacterSize())){
        positionX = positionX - 2;
        life = life - 1;
    }
}

void Character::botMove(Character &character, Character &ennemy) {
    attack(character, ennemy);
    //positionX = positionX - speed;
    //delay(1000);
    //positionX = positionX + speed;
    this->characterInScreen();
}

void Character::characterInScreen() {
    if(positionX + characterSize > gb.display.width()) {
        positionX = gb.display.width() - 5;
    }
    if(positionY + characterSize > gb.display.height()){
        positionY = gb.display.height() - 5;
    }
    if (positionY < 0) {
        positionY = 0;
    }
    if (positionX < 0) {
        positionX = 0;
    }
}

boolean Character::isAlive() {
    if (life <= 0) {
        return false;
    }
    return true;
}

void Character::reset() {
    gb.display.print("reset");
    this->setLife(30);
    isAlive();
    positionX = basePositionX;
    positionY = basePositionY;
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

int Character::getBasePositionX() {
    return this->basePositionX;
}

void Character::setBasePositionX(int position) {
    this->basePositionX = position;
}

int Character::getBasePositionY() {
    return this->basePositionY;
}

void Character::setBasePositionY(int position) {
    this->basePositionY = position;
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

int Character::getLife() {
    return this->life;
}

void Character::setLife(int pLife) {
    this->life = pLife;
}