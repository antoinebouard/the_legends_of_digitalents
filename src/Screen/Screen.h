#ifndef DEF_SCREEN
#define DEF_SCREEN
#include <Gamebuino-Meta.h>;
#include "../Character/Character.h";

class Screen {
    public :
    // Constructeur
    Screen();

    // Méthodes
    void display(Character character, Character ennemy);
    void gameOver(String victory, Character character, Character ennemy);

    private :

    // Argument
};
#endif