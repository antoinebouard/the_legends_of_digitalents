#ifndef DEF_CHARACTER
#define DEF_CHARACTER
#include <Gamebuino-Meta.h>;

class Character {
    private :
    // Déclaration variable

    int basePositionX;
    int basePositionY;
    int positionX;
    int positionY;
    int speed = 2;
    int characterSize = 4;
    int life;

    public : 

    // Constructeur
    Character(int positionX, int positionY, int life);

    void move();
    void collide(Character character, Character ennemy);
    void botMove(Character &character, Character &ennemy);
    void attack(Character &character, Character &ennemy);
    void characterInScreen();
    void takeDamage(int damage);
    void reset();
    boolean isAlive();

    // Getters & Setters
    int getPositionX();
    void setPositionX(int position);

    int getPositionY();
    void setPositionY(int position);

    int getBasePositionX();
    void setBasePositionX(int position);

    int getBasePositionY();
    void setBasePositionY(int position);

    int getSpeed();
    void setSpeed(int speed);

    int getCharacterSize();
    void setCharacterSize(int size);

    int getLife();
    void setLife(int life);
};
#endif