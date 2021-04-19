/* 
* Sem09-2 Binary Search Tree (BST) - Operaciones básicas
* 14/04/2021 20:46:44
* NodeTreeTree.h
* A01706095 Naomi Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/

#ifndef Trunk_h
#define Trunk_h

#include "NodeTree.h"
#include <string>

using namespace std;

template <class T>  
class Trunk {   
    public:
    Trunk<T> *prev;
    string str;
    Trunk<T>(Trunk<T> *, string);
};

template <class T>  
Trunk<T>::Trunk(Trunk<T> *prev, string str) {
    this->prev = prev;
    this->str = str;
}



#endif // Trunk_h