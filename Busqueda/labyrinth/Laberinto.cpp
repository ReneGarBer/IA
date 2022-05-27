#include "Laberinto.h"

Laberinto::Laberinto(){
    this->path = "";
    this->paths_open = 0;
}

void Laberinto::drawLaberinto(){
    this->inicio.setCurrentPosition();
    this->inicio.nextLine();
    ++this->inicio;
    this->meta = this->inicio;
    this->aux = this->inicio;
    std::cout<<" _ _ _ _ _ _ _ _ _ _ \n";
    for(int i = 0; i < 10; i++){
        std::cout <<"|_|_|_|_|_|_|_|_|_|_|\n";
    }
    this->stats.setCurrentPosition();
}

void Laberinto::setInicio(){
    int i = 0, j = 0;
    this->inicio.move();
    std::cout << "O";
    int arrow;
    int upper_bound = this->inicio.getYPointer();
    int lower_bound = upper_bound+9;
    int left_bound = this->inicio.getXPointer()+1;
    int right_bound = left_bound + 17;

    Pointer aux_pointer;
    aux_pointer.prevLine();
    aux_pointer.prevLine();
    aux_pointer.move();
    std::cout << "Mover: ";
    aux_pointer.setCurrentPosition();

    bool salir = false;
    while(!salir){
        Pointer aux_lab = this->inicio;
        std::cin >> arrow;
        switch(arrow){
            case 8:
                if(this->inicio.getYPointer() > upper_bound){
                    i--;
                    this->inicio.prevLine();
                }
                break;
            case 2:
                if(this->inicio.getYPointer() < lower_bound){
                    i++;
                    this->inicio.nextLine();
                }
                break;
            case 4:
                if(this->inicio.getXPointer() > left_bound){
                    j--;
                    this->inicio -= 2;
                }
                break;
            case 6:
                if(this->inicio.getXPointer() < right_bound){
                    j++;
                    this->inicio += 2;
                }
                break;
            case 5:
                //cambiar color a rojo
                this->laberinto[i][j] = 'O';
                setRaiz(i,j);
                salir = true;
                break;
            default:
                break;
        }
        
        this->inicio.move();
        std::cout << "O";

        if (this->inicio != aux_lab) {
            aux_lab.move();
            std::cout << "_";
        }

        aux_pointer.move();
    }
}

void Laberinto::setMeta(){
    int i = 0, j = 0;
    this->meta.move();
    Pointer aux_pointer;
    aux_pointer.prevLine();
    aux_pointer.prevLine();
    if (this->raiz.j == 0 && this->raiz.i == 0) {
        this->meta.nextLine();
        i++;
    }
    this->meta.move();
    std::cout << "X";
    int arrow;
    int upper_bound = this->meta.getYPointer();
    int lower_bound = upper_bound + 9;
    int left_bound = this->meta.getXPointer() + 1;
    int right_bound = left_bound + 17;

    aux_pointer.move();
    std::cout << " Mover: ";
    aux_pointer.setCurrentPosition();

    bool salir = false;
    while (!salir) {
        Pointer aux_lab = this->meta;
        std::cin >> arrow;
        switch (arrow) {
        case 8:
            if (this->meta.getYPointer() > upper_bound) {
                this->meta.prevLine();
                i--;
            }
            break;
        case 2:
            if (this->meta.getYPointer() < lower_bound) {
                this->meta.nextLine();
                i++;
            }
            break;
        case 4:
            if (this->meta.getXPointer() > left_bound) {
                this->meta -= 2;
                j--;
            }
            break;
        case 6:
            if (this->meta.getXPointer() < right_bound) {
                this->meta += 2;
                j++;
            }
            break;
        case 5:
            //cambiar color a rojo
            this->laberinto[i][j] = 'X';
            salir = true;
            break;
        default:
            break;
        }

        if (this->meta == this->inicio) {
            switch (arrow) {
            case 8:
                this->meta.nextLine();
                break;
            case 2:
                this->meta.prevLine();
                break;
            case 4:
                this->meta += 2;
                break;
            case 6:
                this->meta -= 2;
                break;
            default:
                break;
            }
        }
        else {
            this->meta.move();
            std::cout << "X";
        }

        if (this->meta != aux_lab) {
            aux_lab.move();
            std::cout << "_";
        }

        aux_pointer.move();
    }
    //regresar color a blanco
}

void Laberinto::drawObstaculos(){

    int upper_bound = this->aux.getYPointer();
    int lower_bound = upper_bound + 9;
    int left_bound = this->aux.getXPointer();
    int right_bound = left_bound + 18;

    for (int i = upper_bound; i <= lower_bound; i += 1){
        int f = 1;
        for (int j = left_bound; j <= right_bound; j += 2, f++) {
            srand(time(NULL));
            int coin = rand() % 10 + 1;
            if (coin < 5) {
                this->aux.setPosition(j, i);
                if (this->aux != this->inicio &&
                    this->aux != this->meta) {
                    this->laberinto[i-upper_bound][j - f] = '#';
                    this->aux.move();
                    std::cout << "#";
                }
            }
            Sleep(10);
        }
    }
}

void Laberinto::abrirEstado_pila(Estado& estado){
    switch (estado.tipo) {
    case 5:
        open8_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (inRightBound(estado.j + 1)) {
                if (notObstaculo(estado.i - 1, estado.j + 1)) {
                    std::string path = estado.path + "9";
                    Estado aux(estado.i - 1, estado.j + 1, 9, path);
                    pila.push(aux);
                    this->paths_open++;
                }
            }
        }
        open6_pila(estado);
        if (inLowerBound(estado.i + 1)) {
            if (inRightBound(estado.j + 1)) {
                if (notObstaculo(estado.i + 1, estado.j + 1)) {
                    std::string path = estado.path + "3";
                    Estado aux(estado.i + 1, estado.j + 1, 3, path);
                    pila.push(aux);
                    this->paths_open++;
                }
            }
        }
        open2_pila(estado);
        if (inLowerBound(estado.i + 1)) {
            if (inLeftBound(estado.j - 1)) {
                if (notObstaculo(estado.i + 1, estado.j - 1)) {
                    std::string path = estado.path + "1";
                    Estado aux(estado.i - 1, estado.j + 1, 1, path);
                    pila.push(aux);
                    this->paths_open++;
                }
            }
        }
        open4_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (inLeftBound(estado.j - 1)) {
                if (notObstaculo(estado.i + 1, estado.j - 1)) {
                    std::string path = estado.path + "7";
                    Estado aux(estado.i - 1, estado.j - 1, 7, path);
                    pila.push(aux);
                    this->paths_open++;
                }
            }
        }
        break;
    case 8:
        open8_pila(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open9_pila(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open7_pila(estado);
            }
        }
        break;
    case 9:
        open9_pila(estado);
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open7_pila(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open3_pila(estado);
            }
        }
        break;
    case 6:
        open6_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open9_pila(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open3_pila(estado);
            }
        }
        break;
    case 3:
        open3_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open9_pila(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open1_pila(estado);
            }
        }
        break;
    case 2:
        open2_pila(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open3_pila(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open1_pila(estado);
            }
        }
        break;
    case 1:
        open1_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open7_pila(estado);
            }
        }
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open3_pila(estado);
            }
        }
        break;
    case 4:
        open4_pila(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open7_pila(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open1_pila(estado);
            }
        }
        break;
    case 7:
        open7_pila(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open9_pila(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open1_pila(estado);
            }
        }
        break;
    default:
        break;
    }
}

void Laberinto::abrirEstado_cola(Estado& estado){
    switch (estado.tipo) {
    case 5:
        open8_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (inRightBound(estado.j + 1)) {
                if (notObstaculo(estado.i - 1, estado.j + 1)) {
                    std::string path = estado.path + "9";
                    Estado aux(estado.i - 1, estado.j + 1, 9, path);
                    cola.push(aux);
                    this->paths_open++;
                }
            }
        }
        open6_cola(estado);
        if (inLowerBound(estado.i + 1)) {
            if (inRightBound(estado.j + 1)) {
                if (notObstaculo(estado.i + 1, estado.j + 1)) {
                    std::string path = estado.path + "3";
                    Estado aux(estado.i + 1, estado.j + 1, 3, path);
                    cola.push(aux);
                    this->paths_open++;
                }
            }
        }
        open2_cola(estado);
        if (inLowerBound(estado.i + 1)) {
            if (inLeftBound(estado.j - 1)) {
                if (notObstaculo(estado.i + 1, estado.j - 1)) {
                    std::string path = estado.path + "1";
                    Estado aux(estado.i - 1, estado.j + 1, 1, path);
                    cola.push(aux);
                    this->paths_open++;
                }
            }
        }
        open4_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (inLeftBound(estado.j - 1)) {
                if (notObstaculo(estado.i + 1, estado.j - 1)) {
                    std::string path = estado.path + "7";
                    Estado aux(estado.i - 1, estado.j - 1, 7, path);
                    cola.push(aux);
                    this->paths_open++;
                }
            }
        }
        break;
    case 8:
        open8_cola(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open9_cola(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open7_cola(estado);
            }
        }
        break;
    case 9:
        open9_cola(estado);
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open7_cola(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open3_cola(estado);
            }
        }
        break;
    case 6:
        open6_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open9_cola(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open3_cola(estado);
            }
        }
        break;
    case 3:
        open3_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open9_cola(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open1_cola(estado);
            }
        }
        break;
    case 2:
        open2_cola(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open3_cola(estado);
            }
        }
        if (inLeftBound(estado.j - 1)) {
            if (!notObstaculo(estado.i, estado.j - 1)) {
                open1_cola(estado);
            }
        }
        break;
    case 1:
        open1_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open7_cola(estado);
            }
        }
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open3_cola(estado);
            }
        }
        break;
    case 4:
        open4_cola(estado);
        if (inUpperBound(estado.i - 1)) {
            if (!notObstaculo(estado.i - 1, estado.j)) {
                open7_cola(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open1_cola(estado);
            }
        }
        break;
    case 7:
        open7_cola(estado);
        if (inRightBound(estado.j + 1)) {
            if (!notObstaculo(estado.i, estado.j + 1)) {
                open9_cola(estado);
            }
        }
        if (inLowerBound(estado.i + 1)) {
            if (!notObstaculo(estado.i + 1, estado.j)) {
                open1_cola(estado);
            }
        }
        break;
    default:
        break;
    }
}

void Laberinto::setRaiz(int i, int j){
    this->raiz.j = j;
    this->raiz.i = i;
    this->raiz.tipo = 5;
    this->raiz.path = "5";
}

bool Laberinto::esMeta(Estado& estado){
    this->solucion = this->laberinto[estado.i][estado.j] == 'X';
    return this->solucion;
}

bool Laberinto::inUpperBound(int i){
    return i >= 0;
}

bool Laberinto::inLowerBound(int i){
    return i <= 9;
}

bool Laberinto::inLeftBound(int j){
    return j >= 0;
}

bool Laberinto::inRightBound(int j){
    return j <= 9;
}

bool Laberinto::notObstaculo(int i, int j){
    return this->laberinto[i][j] != '#';
}

void Laberinto::open8_pila(Estado& estado){
    if (inUpperBound(estado.i - 1)) {
        if (notObstaculo(estado.j, estado.i - 1)) {
            std::string path = estado.path + "8";
            Estado aux(estado.i - 1, estado.j, 8, path);
            pila.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open9_pila(Estado& estado) {
    open8_pila(estado);
    if (inUpperBound(estado.i - 1)) {
        if (inRightBound(estado.j + 1)) {
            if (notObstaculo(estado.i - 1, estado.j + 1)) {
                std::string path = estado.path + "9";
                Estado aux(estado.i - 1, estado.j + 1, 9, path);
                pila.push(aux);
                this->paths_open++;
            }
        }
    }
    open6_pila(estado);
}

void Laberinto::open6_pila(Estado& estado) {
    if (inRightBound(estado.j + 1)) {
        if (notObstaculo(estado.j + 1, estado.i)) {
            std::string path = estado.path + "6";
            Estado aux(estado.i, estado.j + 1, 6, path);
            pila.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open3_pila(Estado& estado) {
    open6_pila(estado);
    if (inLowerBound(estado.i + 1)) {
        if (inRightBound(estado.j + 1)) {
            if (notObstaculo(estado.i + 1, estado.j + 1)) {
                std::string path = estado.path + "3";
                Estado aux(estado.i + 1, estado.j + 1, 3, path);
                pila.push(aux);
                this->paths_open++;
            }
        }
    }
    open2_pila(estado);
}

void Laberinto::open2_pila(Estado& estado) {
    if (inLowerBound(estado.i + 1)) {
        if (notObstaculo(estado.i + 1, estado.j)) {
            std::string path = estado.path + "2";
            Estado aux(estado.i + 1, estado.j, 2, path);
            pila.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open1_pila(Estado& estado) {
    open2_pila(estado);
    if (inLowerBound(estado.i + 1)) {
        if (inLeftBound(estado.j - 1)) {
            if (notObstaculo(estado.i + 1, estado.j - 1)) {
                std::string path = estado.path + "1";
                Estado aux(estado.i - 1, estado.j + 1, 1, path);
                pila.push(aux);
                this->paths_open++;
            }
        }
    }
    open4_pila(estado);
}

void Laberinto::open4_pila(Estado& estado) {
    if (inLeftBound(estado.j-1)) {
        if (notObstaculo(estado.i, estado.j - 1)) {
            std::string path = estado.path + "4";
            Estado aux(estado.i, estado.j - 1, 4, path);
            pila.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open7_pila(Estado& estado) {
    open4_pila(estado);
    if (inUpperBound(estado.i - 1)) {
        if (inLeftBound(estado.j - 1)) {
            if (notObstaculo(estado.i + 1, estado.j - 1)) {
                std::string path = estado.path + "7";
                Estado aux(estado.i - 1, estado.j - 1, 7, path);
                pila.push(aux);
                this->paths_open++;
            }
        }
    }
    open8_pila(estado);
}

void Laberinto::open8_cola(Estado& estado) {
    if (inUpperBound(estado.i - 1)) {
        if (notObstaculo(estado.j, estado.i - 1)) {
            std::string path = estado.path + "8";
            Estado aux(estado.i - 1, estado.j, 8, path);
            cola.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open9_cola(Estado& estado) {
    open8_cola(estado);
    if (inUpperBound(estado.i - 1)) {
        if (inRightBound(estado.j + 1)) {
            if (notObstaculo(estado.i - 1, estado.j + 1)) {
                std::string path = estado.path + "9";
                Estado aux(estado.i - 1, estado.j + 1, 9, path);
                cola.push(aux);
                this->paths_open++;
            }
        }
    }
    open6_cola(estado);
}

void Laberinto::open6_cola(Estado& estado) {
    if (inRightBound(estado.j + 1)) {
        if (notObstaculo(estado.j + 1, estado.i)) {
            std::string path = estado.path + "6";
            Estado aux(estado.i, estado.j + 1, 6, path);
            cola.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open3_cola(Estado& estado) {
    open6_cola(estado);
    if (inLowerBound(estado.i + 1)) {
        if (inRightBound(estado.j + 1)) {
            if (notObstaculo(estado.i + 1, estado.j + 1)) {
                std::string path = estado.path + "3";
                Estado aux(estado.i + 1, estado.j + 1, 3, path);
                cola.push(aux);
                this->paths_open++;
            }
        }
    }
    open2_cola(estado);
}

void Laberinto::open2_cola(Estado& estado) {
    if (inLowerBound(estado.i + 1)) {
        if (notObstaculo(estado.i + 1, estado.j)) {
            std::string path = estado.path + "2";
            Estado aux(estado.i + 1, estado.j, 2, path);
            cola.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open1_cola(Estado& estado) {
    open2_cola(estado);
    if (inLowerBound(estado.i + 1)) {
        if (inLeftBound(estado.j - 1)) {
            if (notObstaculo(estado.i + 1, estado.j - 1)) {
                std::string path = estado.path + "1";
                Estado aux(estado.i - 1, estado.j + 1, 1, path);
                cola.push(aux);
                this->paths_open++;
            }
        }
    }
    open4_cola(estado);
}

void Laberinto::open4_cola(Estado& estado) {
    if (inLeftBound(estado.j - 1)) {
        if (notObstaculo(estado.i, estado.j - 1)) {
            std::string path = estado.path + "4";
            Estado aux(estado.i, estado.j - 1, 4, path);
            cola.push(aux);
            this->paths_open++;
        }
    }
}

void Laberinto::open7_cola(Estado& estado) {
    open4_cola(estado);
    if (inUpperBound(estado.i - 1)) {
        if (inLeftBound(estado.j - 1)) {
            if (notObstaculo(estado.i + 1, estado.j - 1)) {
                std::string path = estado.path + "7";
                Estado aux(estado.i - 1, estado.j - 1, 7, path);
                cola.push(aux);
                this->paths_open++;
            }
        }
    }
    open8_cola(estado);
}

void Laberinto::busquedaAmplitud(){
    this->pila.push(this->raiz);

    while (!this->pila.empty()) {
        Estado aux = this->pila.top();
        if (esMeta(aux)) {
            this->raiz = aux;
            break;
        }
        this->pila.pop();
        abrirEstado_pila(aux);
    }
}

void Laberinto::busquedaProfundidad(){
    this->cola.push(this->raiz);

    while (!this->cola.empty()) {
        Estado aux = this->cola.front();
        if (esMeta(aux)) {
            this->raiz = aux;
            break;
        }
        this->cola.pop();
        abrirEstado_cola(aux);
    }
}

void Laberinto::busquedaIterativa(){
    for (int i = 0; i < 4; i++) {
        this->cola.push(this->raiz);

        while (!this->cola.empty()) {
            Estado aux = this->cola.front();
            if (esMeta(aux)) {
                this->raiz = aux;
                break;
            }
            this->cola.pop();
            abrirEstado_cola(aux);
        }
    }
}

void Laberinto::printStats(){
    this->stats.nextLine();
    this->stats.move();
    std::cout << "Caminos abiertos: " << this->paths_open << std::endl;
    std::cout << "Solucion encontrada: " << solucion << std::endl;
    std::cout << "Camino: " << this->raiz.path << std::endl;
}

void Laberinto::walkPath(){
    for (int i = 0; i < this->raiz.path.length()-1; i++) {
        int arrow = this->raiz.path[i]-48;
        switch (arrow) {
        case 8:
            this->inicio.prevLine();
            break;
        case 9:
            this->inicio.nextLine();
            this->inicio += 2;
            break;
        case 6:
            this->inicio += 2;
            break;
        case 3:
            this->inicio += 2;
            this->inicio.nextLine();
            break;
        case 2:
            this->inicio.nextLine();
            break;
        case 1:
            this->inicio -= 2;
            this->inicio.nextLine();
            break;
        case 4:
            this->inicio -= 2;
            break;
        case 7:
            this->inicio -= 2;
            this->inicio.prevLine();
            break;
        default:
            break;
        }
        this->inicio.move();
        std::cout << "O";
        Sleep(10);
    }
} 