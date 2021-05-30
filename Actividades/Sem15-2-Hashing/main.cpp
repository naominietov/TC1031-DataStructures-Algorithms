/*
* Sem15-2 Implementación individual de operaciones sobre conjuntos 
* 19/04/2021 19:22:37
* Heap.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/

#include <iostream>
#include "Hash.h"

using namespace std;


void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void hashing(int table[], int tsize, int arr[], int N) {
  for (int i = 0; i < N; i++) {
    int hv = arr[i] % tsize;

    if (table[hv] == -1)
      table[hv] = arr[i];
    else {
      for (int j = 0; j < tsize; j++) {
        int t = (hv + j * j) % tsize;
        if (table[t] == -1) {
          table[t] = arr[i];
          break;
        }
      }
    }
  }
  printArray(table, N);
}

int main() {
  // Prueba chain 
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  Hash h(7); // 7 is count of buckets in hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);
  h.deleteItem(12);

  cout << "Prueba desborde por encadenamiento: \n";
  h.displayHash();
 
  cout << endl << endl;
  int arr[] = {50, 700, 76, 85, 92, 73, 101};
  int N = 7;

  int L = 7;
  int hash_table[7];

  for (int i = 0; i < L; i++) {
    hash_table[i] = -1;
  }
  cout << "Prueba desborde por sondeo cuadrático: \n";
  // Quadratic probing
  hashing(hash_table, L, arr, N);
  return 0;

}