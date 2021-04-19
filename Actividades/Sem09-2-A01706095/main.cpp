/* 
* Sem09-2 Binary Search Tree (BST) - Operaciones avanzadas
* 14/04/2021 20:46:44
* main.cpp
* A01706095 Naomi Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/
#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
  BinarySearchTree<int> bst;
  bst.insert(10);
  bst.insert(20);
  bst.insert(30);
  bst.insert(15);
  bst.insert(5);
  bst.insert(115);
  bst.insert(3);
  
  bst.menu(bst);
}