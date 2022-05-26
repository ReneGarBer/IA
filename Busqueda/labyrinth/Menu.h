#ifndef Menu_h
#define Menu_h
#include "Pointer.h"
#include "Laberinto.h"

class Menu{
public:
    Menu();

private:
    Pointer pointer;
    Laberinto laberinto;
    void mainMenu();
    void drawMenu();
    void infoMenu();
};

#endif //Menu_h