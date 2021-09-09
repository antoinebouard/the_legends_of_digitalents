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
        positionY = positionY - speed;
    }
    if (gb.buttons.repeat(BUTTON_UP, 0)){
        positionY = positionY - speed;    
    }  
    if (gb.buttons.pressed(BUTTON_RIGHT)) {
    setImage(heroRight);
    setDirection(1);
    gb.display.drawImage(getPositionX(),getPositionY(),heroRight);
    }
    if (gb.buttons.pressed(BUTTON_LEFT)) {
    setImage(heroLeft);
    setDirection(2);
    gb.display.drawImage(getPositionX(),getPositionY(),heroLeft);
    }          
    this->characterInScreen();
}

void Character::attack(Character &character, Character &ennemy) {
    if (gb.buttons.pressed(BUTTON_A)) {
        if (character.getDirection() == 2)
        {
           character.setImage(heroKicksLeft);
        }
        if (character.getDirection() == 1)
        {
           character.setImage(heroKicksRight);
        }
        
        //gb.display.fillCircle(character.getPositionX() + 6, character.getPositionY() + 1,1);
        if (gb.collide.rectRect(character.getPositionX() + 6, character.getPositionY() + 1,1,1,
                                ennemy.getPositionX(), ennemy.getPositionY(), ennemy.getCharacterSize(), ennemy.getCharacterSize())) {
            ennemy.takeDamage(1);
        }
    }
    if (gb.buttons.pressed(BUTTON_B)) {
        gb.display.print("attaque distante");
    }
}

void Character::botAttack(Character &character, Character &ennemy) {
    gb.display.fillCircle(character.getPositionX() - 6, character.getPositionY() + 1,2);
    if (gb.collide.rectRect(character.getPositionX() - 6, character.getPositionY() + 1,2,2,
                                ennemy.getPositionX(), ennemy.getPositionY(), ennemy.getCharacterSize(), ennemy.getCharacterSize())) {
        ennemy.takeDamage(7);
     }
}

void Character::takeDamage(int damage) {
    this->setLife(this->getLife() - damage);
}

void Character::collide(Character character, Character ennemy) {
    if(gb.collide.rectRect(character.getPositionX(), character.getPositionY(), character.getCharacterSize(), character.getCharacterSize(),
                            ennemy.getPositionX(), ennemy.getPositionY(), ennemy.getCharacterSize(), ennemy.getCharacterSize())){
        positionX = positionX - 2;
        life = life - 1;
    }
}

void Character::botMove(Character &character, Character &ennemy, int attack_timer) {
    gb.display.print(rand() % 4);
    if (attack_timer % 25 == 0) {
        switch (rand() % 4) {
            case 0 :
                botAttack(ennemy, character);
                break;
            case 1 :
                positionX = positionX - speed;
                break;
            case 2 :
                positionX = positionX + speed;
                break;
            case 3 :
                positionY = positionY + speed;
                break;
            case 4 :
                positionY = positionY - speed;
                break;
        }        
        attack_timer = 0;
    }
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


Image Character::getImage(){
    return this->image;
}
void Character::setImage(Image image){
    this->image = image;
}

int Character::getLife() {
    return this->life;
}

void Character::setLife(int pLife) {
    this->life = pLife;
}

int Character::getDirection(){
    return this->direction;
}

void Character::setDirection(int direction){
    this->direction = direction;
}