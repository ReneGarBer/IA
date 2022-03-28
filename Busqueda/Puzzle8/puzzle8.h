#ifndef puzzle8_h
#define puzzle8_h
#include <string>
#include <random>
#include <time.h>
#include <iostream>
#include "estado.h"
#include <queue>
#include <stack>
#include <Windows.h>

class puzzle8{
public:
    puzzle8();
    ~puzzle8();
     void print(estado&);
     void print();
     void move(int);
     void shuffle(estado&);
     bool solved(estado&);
     bool solved();
     bool hasSolution(estado&);
     void busquedaAmplitud();
     void busquedaProfundidad();
     void busquedaIterativa();
     void walkPath();
     void walkPathAnimated();
     void amplitudEasyMode();
     void profundidadEasyMode();
     void iterativaEasyMode();
     void setMaxdepth(int);
     int getIntentos()const;

private:
     estado raiz;
     estado solucion;
     int max_depth;
     int intentos;
     std::queue<estado> abierta_a;
     std::stack<estado> abierta_p;
     void swap(estado&, int, int);
     void moveUp();
     void moveDown();
     void moveLeft();
     void moveRight();
     void expandirA();
     void expandirP(int);
     estado moveUp(estado&);
     estado moveDown(estado&);
     estado moveLeft(estado&);
     estado moveRight(estado&);
     void findBlank(estado&);
};

#endif //puzzle8