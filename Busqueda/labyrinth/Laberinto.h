#ifndef Laberinto_h
#define Laberinto_h
#include "Pointer.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

class Laberinto{
private:
    Laberinto();
    void drawLaberinto();
    void setInicio();
    void setMeta();
    void busquedaAmplitud();
    void busquedaProfundidad();
    void busquedaIterativa();
    void printStats();
    void walkPath();
    
protected:
    char laberinto[10][10]; 
    Pointer pointer;
    int paths_looked;
    int inicio[2];
    int meta[2];
    std::string path;
};

#endif