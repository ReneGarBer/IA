#ifndef Laberinto_h
#define Laberinto_h
#include "Pointer.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <time.h>
#include <random>
#include "Estado.h"

class Laberinto{
public:
    Laberinto();
    void drawLaberinto();
    void setInicio();
    void setMeta();
    void drawObstaculos();
    void busquedaAmplitud();
    void busquedaProfundidad();
    void busquedaIterativa();
    void printStats();
    void walkPath();
    
private:
    void abrirEstado_pila(Estado&);
    void abrirEstado_cola(Estado&);
    void setRaiz(int, int);
    bool esMeta(Estado&);
    bool inUpperBound(int);
    bool inLowerBound(int);
    bool inLeftBound(int);
    bool inRightBound(int);
    bool notObstaculo(int, int);
    void open8_pila(Estado&);
    void open9_pila(Estado&);
    void open6_pila(Estado&);
    void open3_pila(Estado&);
    void open2_pila(Estado&);
    void open1_pila(Estado&);
    void open4_pila(Estado&);
    void open7_pila(Estado&);
    void open8_cola(Estado&);
    void open9_cola(Estado&);
    void open6_cola(Estado&);
    void open3_cola(Estado&);
    void open2_cola(Estado&);
    void open1_cola(Estado&);
    void open4_cola(Estado&);
    void open7_cola(Estado&);
    Estado raiz;
    std::stack<Estado> pila;
    std::queue<Estado> cola;
    char laberinto[10][10]; 
    Pointer inicio;
    Pointer meta;
    Pointer aux;
    Pointer stats;
    int paths_open;
    bool solucion;
    std::string path;
};

#endif