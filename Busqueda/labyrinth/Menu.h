#ifndef Menu_h
#define Menu_h
#include "Pointer.h"
#include "Laberinto.h"

class Menu{
public:
    Menu();
    void mainMenu();
private:
    Pointer pointer;
    Laberinto laberinto;
};

#endif //Menu_h