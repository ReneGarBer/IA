#include "Menu.h"

Menu::Menu(){
    mainMenu();
}

void Menu::mainMenu(){ 
    std::cout << "Coloque el punto de inicio. Use las el teclado numerico para moverse\n[Arriba(8),Abajo(2),Izquierda(4),Derecha(6),Salir(0)].\n";
    this->pointer.setCurrentPosition();
    std::cout<<"\n\n\n";
    this->laberinto.drawLaberinto();
    this->laberinto.setInicio();
    this->pointer.move();
    std::cout << "Coloque la meta. Use las el teclado numerico para moverse\n[Arriba(8),Abajo(2),Izquierda(4),Derecha(6),Salir(0)].\n";
    std::cout << "\n\n";
    this->laberinto.setMeta();
    this->laberinto.drawObstaculos();

 /*   std::cout << "Seleccione el método de busqueda.\n1) Amplitud\n2) Profundidad\n3) Iterativa\n";
    int opcion;
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
        this->laberinto.busquedaAmplitud();
        break;
    case 2:
        this->laberinto.busquedaProfundidad();
        break;
    case 3:
        this->laberinto.busquedaIterativa();
        break;   
    default:
        break;
    }
    this->laberinto.walkPath();
    this->laberinto.printStats();*/
}