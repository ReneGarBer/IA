#include "puzzle8.h"

puzzle8::puzzle8(){
    shuffle(this->raiz);
    max_depth = 16;
    intentos = 0;
}

puzzle8::~puzzle8(){
}

 void puzzle8::print(estado& estado){
     std::cout <<" _ _ _ \n";
     std::cout <<'|'<< estado.puzzle[0]<<'|'<< estado.puzzle[1]<<'|'<< estado.puzzle[2]<<'|'<<'\n';
     std::cout <<'|'<< estado.puzzle[3]<<'|'<< estado.puzzle[4]<<'|'<< estado.puzzle[5]<<'|'<<'\n';
     std::cout <<'|'<< estado.puzzle[6]<<'|'<< estado.puzzle[7]<<'|'<< estado.puzzle[8]<<'|'<<'\n';
 }

 void puzzle8::print(){
     print(raiz);
 }

 void puzzle8::move(int m){
     switch(m){
         case 8:
             moveUp();
             break;
         case 2:
             moveDown();
             break;
         case 4:
             moveLeft();
             break;
         case 6:
             moveRight();
             break;
         default:
             break;
     }
 }

 void puzzle8::shuffle(estado& estado){
     srand(time(NULL));
     for(int i = 8; i> 1;i--){
         int j = rand() % i;
         swap(estado,i,j);
     }
     findBlank(estado);
 }

 void puzzle8::swap(estado& estado,int from, int to){
     char aux = estado.puzzle[from];
     estado.puzzle[from] = estado.puzzle[to];
     estado.puzzle[to] = aux;
 }

 void puzzle8::moveUp(){
     if (raiz.blank - 3 < 0) return;
     swap(raiz, raiz.blank, raiz.blank - 3);
     raiz.blank -= 3;
     raiz.path += '8';
 }

 void puzzle8::moveDown(){
     if (raiz.blank + 3 > 8) return;
     swap(raiz, raiz.blank, raiz.blank + 3);
     raiz.blank += 3;
     raiz.path += '2';
 }

 void puzzle8::moveLeft(){
     if (raiz.blank % 3 == 0) return;
     swap(raiz, raiz.blank, raiz.blank - 1);
     raiz.blank -= 1;
     raiz.path += '4';
 }

 void puzzle8::moveRight(){
     if (raiz.blank % 3 == 2) return;
     swap(raiz, raiz.blank, raiz.blank + 1);
     raiz.blank += 1;
     raiz.path += '6';
 }

 estado puzzle8::moveUp(estado& padre){
     estado aux = padre;
     if(aux.blank - 3 < 0) return aux;
     swap(aux,aux.blank,aux.blank-3);
     aux.blank-=3;
     aux.path.append("8");
     return aux;
 }

 estado puzzle8::moveDown(estado& padre){
     estado aux = padre;
     if (aux.blank + 3 > 8) return aux;
     swap(aux, aux.blank, aux.blank + 3);
     aux.blank += 3;
     aux.path.append("2");
     return aux;
 }

 estado puzzle8::moveLeft(estado& padre){
     estado aux = padre;
     if (aux.blank % 3 == 0) return aux;
     swap(aux, aux.blank, aux.blank - 1);
     aux.blank -= 1;
     aux.path.append("4");
     return aux;
 }

 estado puzzle8::moveRight(estado& padre){
     estado aux = padre;
     if (aux.blank % 3 == 2) return aux;
     swap(aux, aux.blank, aux.blank + 1);
     aux.blank += 1;
     aux.path.append("6");
     return aux;
 }

 void puzzle8::findBlank(estado& estado){
     for (int i = 0; i < 9; i++)
         if (estado.puzzle[i] == ' ') {
             estado.blank = i;
             return;
         }
 }

 bool puzzle8::solved(estado& estado){
     for(int i = 1; i <= 8; i++){
         if(estado.puzzle[i] != (char)(i+48))
             return false;
     }
     return true;
 }

 bool puzzle8::solved(){
     return solved(raiz);
 }

 bool puzzle8::hasSolution(estado & estado){
     int inv = 0;
     for(int i = 0; i < 8; i++){
         if(estado.puzzle[i]==' ') continue;
         for(int j = i+1; j < 9; j++){
             if(estado.puzzle[i] > estado.puzzle[j] && estado.puzzle[j]!=' '){
                 inv++;
             }
         }
     }
     return inv % 2 == 0;
 }

 void puzzle8::busquedaAmplitud(){
     if (!hasSolution(raiz)) {
         solucion = raiz;
         return;
     }
     abierta_a.push(raiz);
     while(!solved(abierta_a.front())&& intentos <= 5000000) {
         expandirA();
         intentos++;
     }
     solucion = abierta_a.front();
 }
 
 void puzzle8::busquedaProfundidad() {
     if (!hasSolution(raiz)) {
         solucion = raiz;
         return;
     }
     abierta_p.push(raiz);
     solucion = abierta_p.top();
     while (!solved(solucion)) {
         expandirP(max_depth);
         solucion = abierta_p.top();
         intentos++;
         if (abierta_p.empty()) break;
     }     
 }

 void puzzle8::busquedaIterativa() {
     if (!hasSolution(raiz)) {
         solucion = raiz;
         return;
     }
     
     for (int i = 1; i < 15; i++) {
         abierta_p.push(raiz);
         solucion = abierta_p.top();
         while (!solved(solucion)&&!abierta_p.empty()) {
             solucion = abierta_p.top();
             expandirP(i);             
             intentos++;
         }
         if (solved(solucion)) break;
     }
 }
 
 void puzzle8::walkPath(){
     for (int i = 0; i < solucion.path.length(); i++) {
         print(raiz);
         move((int)solucion.path[i]-48);
     }
     print(raiz);
 }

 void puzzle8::walkPathAnimated() {
     for (int i = 0; i < solucion.path.length(); i++) {
         print(raiz);
         move((int)solucion.path[i] - 48);
         Sleep(1500);
         system("cls");
     }
     print(raiz);
 }

 void puzzle8::amplitudEasyMode() {
     char easy[9] = { '1','2','3','4',' ','5','6','7','8' };
     for (int i = 0; i < 9; i++) {
         raiz.puzzle[i] = easy[i];
     }
     raiz.blank = 4;
     busquedaAmplitud();
 }

 void puzzle8::profundidadEasyMode(){
     char easy[9] = { '1','2','3','4',' ','5','6','7','8' };
     for (int i = 0; i < 9; i++) {
         raiz.puzzle[i] = easy[i];
     }
     raiz.blank = 4;
     busquedaProfundidad();
 }

 void puzzle8::iterativaEasyMode(){
     char easy[9] = { '1','2','3','4',' ','5','6','7','8' };
     for (int i = 0; i < 9; i++) {
         raiz.puzzle[i] = easy[i];
     }
     raiz.blank = 4;
     busquedaIterativa();
 }

 void puzzle8::setMaxdepth(int m){
     this->max_depth = m;
 }

 int puzzle8::getIntentos() const{
      return intentos;
 }

 void puzzle8::expandirA() {
     estado aux = abierta_a.front();
     abierta_a.pop();
     if (!(moveUp(aux) <= aux)) {
         abierta_a.push(moveUp(aux));
     }
     if (!(moveDown(aux) <= aux)) {
         abierta_a.push(moveDown(aux));
     }
     if (!(moveLeft(aux) <= aux)) {
         abierta_a.push(moveLeft(aux));
     }
     if (!(moveRight(aux) <= aux)) {
         abierta_a.push(moveRight(aux));
     }
 }

 void puzzle8::expandirP(int max_depth){
     if (abierta_p.top().path.length()>=max_depth) {
         abierta_p.pop();
         return;
     }
     estado aux = abierta_p.top();
     abierta_p.pop();
     if (!(moveUp(aux) <= aux)) {
         abierta_p.push(moveUp(aux));
     }
     if (!(moveDown(aux) <= aux)) {
         abierta_p.push(moveDown(aux));
     }
     if (!(moveLeft(aux) <= aux)) {
         abierta_p.push(moveLeft(aux));
     }
     if (!(moveRight(aux) <= aux)) {
         abierta_p.push(moveRight(aux));
     }
 }