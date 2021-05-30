/*
* Sem15-2 Implementación individual de operaciones sobre conjuntos 
* 19/04/2021 19:22:37
* Heap.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/

#ifndef Hash_h
#define Hash_h

#include<bits/stdc++.h>

using namespace std;

class Hash {
  public:
	int BUCKET; // No. of buckets
	list<int> *table; // Pointer to an array containing buckets
	Hash(int V); // Constructor
	void insertItem(int); 	// inserts a key into hash table
	void deleteItem(int); // deletes a key from hash table
  void displayHash();
	int hashFunction(int); // hash function to map values to key
  void hashing(int table[], int tsize, int arr[], int N);
  void printArray(int arr[], int n);

};

int Hash::hashFunction(int x) {
  return (x % BUCKET);
}
Hash::Hash(int b) {
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key) {
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key) {
  int index = hashFunction(key);
  list <int> :: iterator i;
  for (i = table[index].begin();
      i != table[index].end(); i++) {
    if (*i == key)
    break;
  }
  if (i != table[index].end())
    table[index].erase(i);
}

void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
    cout << " --> " << x;
    cout << endl;
  }
}

void Hash::printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void Hash::hashing(int table[], int tsize, int arr[], int N) {
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

#endif /* Hash_h */