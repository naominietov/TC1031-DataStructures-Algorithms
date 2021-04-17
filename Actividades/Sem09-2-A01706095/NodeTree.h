/* 
* Sem09-2 Binary Search Tree (BST) - Operaciones avanzadas
* 14/04/2021 20:46:44
* NodeTree.h
* A01706095 Naomi Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/
#ifndef NodeTree_h
#define NodeTree_h

#include <iostream>

template <class T>
class NodeTree { 
public: 
  T data; 
  NodeTree<T> * left;
  NodeTree<T> * right;
  NodeTree();
  NodeTree(T);
}; 

template<class T>
NodeTree<T>::NodeTree() {
  left = nullptr;
  right = nullptr;
}
template<class T>
NodeTree<T>::NodeTree(T val) {
  data = val;
  left = nullptr;
  right = nullptr;
}

#endif // NodeTree_h