#include <iostream>
#include "puzzle8.h"

using namespace std;

int main(){
     puzzle8 puzzle;
     int opcion;
     cout << "-- PUZZLE 8 --";
     cout << "<Selecciona el modo de juego>\n";
     cout << "1) Manual\n" << "2) automatico Amplitud\n"
         << "3) automatico Profundidad\n" << "4) automatico Iterativa\n";
     cin >> opcion;

     if (opcion == 1) {
         while (!puzzle.solved()) {
             puzzle.print();
             int m;
             cin >> m;
             puzzle.move(m);
             system("cls");
         }
     }
     else if (opcion == 2) {
        int o;
        cout << "Seleccione la dificultad\n";
        cout << "1) Facil\n" << "2) Dificil\n";
        cin >> o;
        if (o == 1) {
            puzzle.amplitudEasyMode();
        }
        if (o == 2) {
            cout << "Se realizan un maximo de 5000 intentos";
            puzzle.busquedaAmplitud();
        }
        cout << "1) mostrar solucion paso a paso.\n2) ver animacion.\n";
        cin >> o;

        if (o == 1)
            puzzle.walkPath();
        if (o == 2)
            puzzle.walkPathAnimated();
        cout << "Se exploraron " << puzzle.getIntentos() << " estados con la busqueda en amplitud\n";
     }
     else if (opcion == 3) {
        int o;
        cout << "Seleccione la dificultad\n";
        cout << "1) Facil\n" << "2) Dificil\n";
        cin >> o;
        if (o == 1) {
            puzzle.profundidadEasyMode();
        }if (o == 2) {
            cout << "La profundidad por defecto es de 10 niveles.\n1) Cambiar";
            cin >> o;
            if (o == 1) {
                cout << "Profundidad: ";
                cin >> o;
                puzzle.setMaxdepth(o);
            }
            puzzle.busquedaProfundidad();
        }
        cout << "1) mostrar solucion paso a paso.\n2) ver animacion.\n";
        cin >> o;

        if (o == 1)
            puzzle.walkPath();
        if (o == 2)
            puzzle.walkPathAnimated();
        cout << "Se exploraron " << puzzle.getIntentos() << " estados con la busqueda a profundiad\n";
     }
     else if (opcion == 4) {
        int o;
        cout << "Seleccione la dificultad\n";
        cout << "1) Facil\n" << "2) Dificil\n";
        cin >> o;
        if (o == 1) {
            puzzle.iterativaEasyMode();
        }if (o == 2) {
            puzzle.busquedaIterativa();
        }
        cout << "1) mostrar solucion paso a paso.\n2) ver animacion.\n";
        cin >> o;

        if (o == 1)
            puzzle.walkPath();
        if (o == 2)
            puzzle.walkPathAnimated();
        cout << "Se exploraron " << puzzle.getIntentos() << " estados conl a busqueda a profundidad iterativa\n";
     }
     else {
          cout << "Gracias por jugar\n";
     }
     return 0;
}