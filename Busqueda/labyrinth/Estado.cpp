#include "Estado.h"

Estado::Estado(){
}

Estado::Estado(int i, int j, int tipo, std::string& path)
    :tipo(tipo),path(path),i(i),j(j) {
}

void Estado::operator=(Estado& estado){
    this->tipo = estado.tipo;
    this->i = estado.i;
    this->j = estado.j;
    this->path = estado.path;
}