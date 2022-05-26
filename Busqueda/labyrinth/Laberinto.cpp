#include "Laberinto.h"

Laberinto::Laberinto(){
    this->path = "";
    this->paths_looked = 0;
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
}

void Laberinto::setInicio(){
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
    
    int i[2] = { 0,0 };
    bool salir = false;
    while(!salir){
        Pointer aux_lab = this->inicio;
        std::cin >> arrow;
        switch(arrow){
            case 8:
                if(this->inicio.getYPointer() > upper_bound){
                    i[1]--;
                    this->inicio.prevLine();
                }
                break;
            case 2:
                if(this->inicio.getYPointer() < lower_bound){
                    i[1]++;
                    this->inicio.nextLine();
                }
                break;
            case 4:
                if(this->inicio.getXPointer() > left_bound){
                    i[0]--;
                    this->inicio -= 2;
                }
                break;
            case 6:
                if(this->inicio.getXPointer() < right_bound){
                    i[0]++;
                    this->inicio += 2;
                }
                break;
            case 5:
                //cambiar color a rojo
                laberinto[i[0]][i[1]] = 'O';
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
    //regresar color a blanco

}

void Laberinto::setMeta(){
    this->meta.move();
    std::cout << "X";
    int arrow;
    int upper_bound = this->meta.getYPointer();
    int lower_bound = upper_bound + 9;
    int left_bound = this->meta.getXPointer() + 1;
    int right_bound = left_bound + 17;

    Pointer aux_pointer;
    aux_pointer.prevLine();
    aux_pointer.prevLine();
    aux_pointer.move();
    std::cout << "Mover: ";
    aux_pointer.setCurrentPosition();

    int i[2] = { 0,0 };
    bool salir = false;
    while (!salir) {
        Pointer aux_lab = this->meta;
        std::cin >> arrow;
        switch (arrow) {
        case 8:
            if (this->meta.getYPointer() > upper_bound) {
                this->meta.prevLine();
            }
            break;
        case 2:
            if (this->meta.getYPointer() < lower_bound) {
                this->meta.nextLine();
            }
            break;
        case 4:
            if (this->meta.getXPointer() > left_bound) {
                this->meta -= 2;
            }
            break;
        case 6:
            if (this->meta.getXPointer() < right_bound) {
                this->meta += 2;
            }
            break;
        case 5:
            //cambiar color a rojo
            laberinto[i[0]][i[1]] = 'X';
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

    for (int y = upper_bound; y <= lower_bound; y += 1){
        for (int x = left_bound, int f = 1; x <= right_bound; x += 2, f++) {
            srand(time(NULL));
            int coin = rand() % 10 + 1;
            if (coin < 5) {
                this->aux.setPosition(x, y);
                if (this->aux != this->inicio &&
                    this->aux != this->meta) {
                    this->laberinto[x-f][y - 6] = '#';
                    this->aux.move();
                    std::cout << "#";
                }
            }
        }
    }
}

//void Laberinto::busquedaAmplitud(){}
//
//void Laberinto::busquedaProfundidad(){}
//
//void Laberinto::busquedaIterativa(){}
//
//void Laberinto::walkPath(){}