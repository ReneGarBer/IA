#include "estado.h"

estado::estado(){
    this->puzzle[0] = ' ';
    for (int i = 1; i <= 8; i++) {
        this->puzzle[i] = (char)(i + 48);
    }
    this->blank = 0;
}

void estado::operator=(estado& estado){
    for (int i = 0; i < 9; i++) {
        this->puzzle[i] = estado.puzzle[i];
    }
    this->path = estado.path;
    this->blank = estado.blank;
}

bool estado::operator==(estado& estado){
    for (int i = 0; i < 9; i++) {
        if (this->puzzle[i] != estado.puzzle[i])
            return false;
    }
    return true;
}

bool estado::operator < (estado& estado){
    return this->path == estado.path.substr(0,estado.path.length()-1);
}

bool estado::operator<=(estado& estado){
    return *this == estado || *this < estado;
}