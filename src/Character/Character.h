#ifndef DEF_CHARACTER
#define DEF_CHARACTER
#include <Gamebuino-Meta.h>;

class Character {
    private :
    // Déclaration variable

    int positionX = 22;
    int positionY = 32;
    int speed = 2;
    int characterSize = 4;

    public : 

    // Constructeur
    Character();

    void move();

    // Getters & Setters
    int getPositionX();
    void setPositionX(int position);

    int getPositionY();
    void setPositionY(int position);

    int getSpeed();
    void setSpeed(int speed);

    int getCharacterSize();
    void setCharacterSize(int size);
};
#endif