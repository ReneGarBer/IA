#include "Menu.h"

Menu::Menu(){
    mainMenu();
}

void Menu::mainMenu(){
    
    std::cout << "Coloque el punto de inicio. Use las el teclado numerico para moverse [▲(8),▼(2),◄(4),►(6)]:\n";
    this->pointer.setCurrentPosition();
    this->laberinto.setInicio();
    std::cout << "Coloque la meta. Use las el teclado numerico para moverse [▲(8),▼(2),◄(4),►(6)]:";
}

void Menu::drawMenu(){

}

void Menu::infoMenu(){

}