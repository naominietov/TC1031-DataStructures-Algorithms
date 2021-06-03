/*
* Sem15-2 Implementación de operaciones sobre conjuntos 
* 19/04/2021 19:22:37
* Hash.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/
#ifndef Hash_h
#define Hash_h

#include <iostream>
#include <string>
#include <queue>

#include "Node.h"

using namespace std;

class Map {
public:
  Map();
  Map(string filename);
  void findPrint(const string& key);
  void find(const string& key, string ip2);  
  void insert(const string& key, const Node& value);
  void print(ofstream &miArchivo);
protected:
  unsigned int hash(const string& key);
  int find_index(const string& key, bool override_duplicated_key);
  const static unsigned int size_max = 14000;
  string keys[size_max];
  Node values[size_max];
};

Map::Map() {
  for (int i = 0; i < size_max; i++) {
    keys[i] = string();
    values[i] = Node();
  }
}

unsigned int Map::hash(const string& k) {
  unsigned int value = 0 ;
  for (int i = 0; i < k.length(); i++)
    value = 37*value + k[i];
  return value;
}

void Map::print(ofstream &results) {
  for (int i = 0; i < size_max; i++)
    if (!keys[i].empty())
      results << keys[i] << ",\t" << values[i].size << "\n";
}

int Map::find_index(const string& key, bool override_duplicate_key = true) {     
  unsigned int h = hash(key) % size_max, offset = 0, index;
  while (offset < size_max) {
    index = (h + offset) % size_max;
    if (keys[index].empty() || (override_duplicate_key && keys[index] == key))
      return index;
    offset++;
  }
  return -1;
}

void Map::insert(const string& key, const Node& value) {
  int index = find_index(key);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }
  keys[index] = key;
  values[index] = value;
}

void Map::find(const string& key, string ip2) {
  int index = find_index(key);
  if (index != -1) {
    values[index].addAdjacency(ip2);
  }
  return;
}

void Map::findPrint(const string& key) {
  int index = find_index(key);
  if (index != -1) {
    values[index].printList();
  }
  return;
}

#endif /* Hash_h */