#include <Gamebuino-Meta.h>

class Screen {
    private :
    // Déclaration variable

    int positionX = 22;
    int positionY = 32;
    int speedX = 1;
    int speedY = 1;
    int character_size = 4;

    public : 

    // Constructeur
    Screen();

    void display();
};