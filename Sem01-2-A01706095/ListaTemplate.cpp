//  Naomi Estefanía Nieto Vega A01706095
//  ListaTemplate.cpp
//  Actividad individual 1 - TC1031
//  Semestre Febrero-Junio 2021

#include <stdio.h>
#include <iostream>
#include <vector>
#include "ListaTemplate.h"

using namespace std;

template <class T>
Lista<T>::Lista(){
    size = 0;
}

template <class T> 
void Lista<T>::insert(T valorInsertar) {
    if (size < MAX) {
        data.push_back(valorInsertar);
        size++;
    }   
}

template <class T>
void Lista<T>::erase() {
    if (size >= 1) {
        cout << "Elemento a borrar: " << endl;
        cout << data[size-1] << endl;
        data.pop_back();
        size--;
    }
    else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <class T>
T Lista<T>::getData(int posicion) {
    T aux;
    if (posicion >= 0 && posicion < size) {
        aux = data[posicion];
    }
    return aux;
}

template <class T>
int Lista<T>::getSize() {
    return size;
}

template <class T>
void Lista<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]" << " - " << data[i] << endl;
    }
}
