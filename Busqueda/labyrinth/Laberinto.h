#ifndef Laberinto_h
#define Laberinto_h
#include "Pointer.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <time.h>
#include <random>

class Laberinto{
public:
    Laberinto();
    void drawLaberinto();
    void setInicio();
    void setMeta();
    void drawObstaculos();
    //void busquedaAmplitud();
    //void busquedaProfundidad();
    //void busquedaIterativa();
    //void printStats();
    //void walkPath();
    
private:
    std::stack<char> pila;
    std::queue<char> cola;
    char laberinto[10][10]; 
    Pointer inicio;
    Pointer meta;
    Pointer aux;
    int paths_looked;
    std::string path;
};

#endif