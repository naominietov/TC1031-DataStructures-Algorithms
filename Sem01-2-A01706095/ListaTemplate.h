//  Naomi Estefanía Nieto Vega A01706095
//  ListaTemplate.h
//  Actividad individual 1 - TC1031
//  Semestre Febrero-Junio 2021

#ifndef ListaTemplate_h
#define ListaTemplate_h
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <class T>

class Lista {
    private:
    vector<T> data;
    const int MAX = 100;
    int size;

    public:
    Lista();
    T getData(int);
    int getSize();
    void insert(T);
    void erase();
    void print();
};

#endif /* ListaTemplate_h */