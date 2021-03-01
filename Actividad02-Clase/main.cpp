//  Naomi Estefanía Nieto Vega A01706095
//  main.cpp
//  Actividad en clase 2 - TC1031
//  Semestre Febrero-Junio 2021

#include <iostream>

using namespace std;

int sumaIterativa(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++){
        suma = suma + i;
    }
    return suma;
}

int sumaRecursiva(int n) {
    int suma = 0;
    if (n > 0) {
        return n+sumaRecursiva(n-1);
    }
    else {
        return 0;
    }
}

int sumaDirecta(int n){
    int sumatoria = 0;
    if (n > 0) {
        sumatoria  = n*(n+1)/2;
        return sumatoria;
    }
    else {
        cout << "El número debe ser un entero positivo" << endl;
        return 0;
    }
}

int factorial(int n){
    if (n > 0) {
        return n*factorial(n-1);
    }
    else if (n < 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    int resp = 0;
    //resp = sumaIterativa(5);
    resp = sumaRecursiva(4);
    //resp = sumaDirecta(5);
    cout << resp << endl;

    return 0;
};