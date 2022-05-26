#include "Laberinto.h"

Laberinto::Laberinto(){
    this->inicio[0] = -1;
    this->inicio[1] = -1;
    this->meta[0] = -1;
    this->meta[1] = -1;
    this->path = "";
    this->paths_looked = 0;
}

void Laberinto::drawLaberinto(){
    this->pointer.setCurrentPosition();
    this->pointer.nextLine();
    this->pointer++;
    cout<<"._._._._._._._._._._.\n";
    for(int i = 0; i < 10; i++){
        cout <<"|_|_|_|_|_|_|_|_|_|_|\n";
    }
}

void Laberinto::setInicio(){}

void Laberinto::setMeta(){}

void Laberinto::busquedaAmplitud(){}

void Laberinto::busquedaProfundidad(){}

void Laberinto::busquedaIterativa(){}

void Laberinto::walkPath(){}