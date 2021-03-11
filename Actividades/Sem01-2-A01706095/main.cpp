//  Naomi Estefanía Nieto Vega A01706095
//  main.cpp
//  Actividad individual 1 - TC1031
//  Semestre Febrero-Junio 2021

#include <iostream>
#include <vector>
#include <string>
#include "ListaTemplate.h"
#include "ListaTemplate.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    /* Caso de prueba 1 */
    Lista<int> a;
    for (int i = 1; i < 5; i++){
        a.insert(i);
    }
    cout << "Los datos en la lista son: " << endl;
    a.print();
    cout << endl;
    cout << "El dato en posicion 1 es: " << a.getData(1) << endl;

    /* Caso de prueba 2 */
    Lista<string> b;
    b.insert("Hola");
    b.insert("Amigos");
    b.insert("TC1031");
    b.insert("Rosa");
    cout << "El dato en la posicion 0 es: " << b.getData(0) << endl;
    cout << "El dato en la posicion 1 es: " << b.getData(1) << endl;
    cout << "El dato en la posicion 2 es: " << b.getData(2) << endl;
    cout << "El size de b es: " << b.getSize() << endl;
    b.erase();
    cout << endl;

    /* Caso de prueba 3 */
    Lista<bool> c;
    c.insert(false);
    c.insert(true);
    c.insert(true);
    c.insert(false);
    cout << "El dato en posicion 0 es: " << c.getData(0) << endl;
    cout << "El dato en posicion 1 es: " << c.getData(1) << endl;
    cout << "Los datos en la lista son: " << endl;
    c.print();
    cout << "El size de c es: " << c.getSize() << endl;
        
    return 0;
};