#include "Menu.h"

Menu::Menu(){
    mainMenu();
}

void Menu::mainMenu(){ 
    std::cout << "Coloque el punto de inicio. Use las el teclado numerico para moverse\n[Arriba(8),Abajo(2),Izquierda(4),Derecha(6),Salir(0)].\n";
    this->pointer.setCurrentPosition();
    
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    
    this->laberinto.drawLaberinto();
    
    this->laberinto.setInicio();
    
    this->pointer.move();
    
    std::cout << "\n";
    std::cout << "Coloque la meta. Use las el teclado numerico para moverse\n[Arriba(8),Abajo(2),Izquierda(4),Derecha(6),Salir(0)].\n";
    std::cout << "\n";
    this->pointer.setCurrentPosition();
    
    this->laberinto.setMeta();
    
    this->laberinto.drawObstaculos();
    
    this->pointer.move();
    std::cout << "\n";
    
    std::cout << "Seleccione el metodo de busqueda: ";
    this->pointer.setCurrentPosition();
    
    std::cout << "\n1) Amplitud\n2) Profundidad\n3) Iterativa\n";
    this->pointer.move();
    
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
    this->laberinto.printStats();
}