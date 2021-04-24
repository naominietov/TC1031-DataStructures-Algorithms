/*
* Sem10-2 Árbol Heap: Fila priorizada
* 19/04/2021 19:22:37
* main.cpp
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/
#include <iostream>
#include "Heap.h"

using namespace std;

/*         
            45
        /      \
        31      14
      /  \    /  \
      13  20  7   11
    /  \
    12   7
  Create a priority queue shown in
  example in a binary max heap form.
  Queue will be represented in the
  form of array as:
  
  45 31 14 13 20 7 11 12 7 
*/

int main() {
  Heap<int> fila;

  fila.push(45);
  fila.push(20);
  fila.push(14);
  fila.push(12);
  fila.push(31);
  fila.push(7);
  fila.push(11);
  fila.push(13);
  fila.push(7);

  cout << "═════════════════════════════════════════════════════\n";
  cout << "                      Test cases                     \n";
  cout << "═════════════════════════════════════════════════════\n";
  cout << "a) Priority Queue: ";
  int i = 0;
  while (i <= fila.Size) {
    cout << fila.H[i] << " ";
    i++;
  }
  cout << "\n";

  cout << "b) Highest priority element: " << fila.extractMax() << "\n";

  fila.changePriority(2, 49);
  cout << "c) Priority queue after priority change:\n ";
  int k = 0;
  cout << "\t";
  while (k <= fila.Size) {
    cout << fila.H[k] << " ";
    k++;
  }
  cout << "\n";

  fila.pop(3);
  cout << "d) Priority queue after removing the element:\n ";
  int l = 0;
  cout << "\t";
  while (l <= fila.Size) {
    cout << fila.H[l] << " ";
    l++;
  }
  cout << "\n";

  cout << "e) Priority queue isEmpty() = ";
  cout << fila.empty() << "\n";

  cout << "f) Priority queue size = ";
  fila.getSize();
  cout << "═════════════════════════════════════════════════════\n";

  return 0;
}