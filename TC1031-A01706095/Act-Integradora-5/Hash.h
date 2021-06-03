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
  protected:
  const static unsigned int size_max = 15000;
  string keys[size_max];
  Node values[size_max];
  unsigned int hash(const string&);
  int findIndex(const string&, bool);

  public:
  Map();
  Map(string);
  void findAdjacencies(const string&);
  void find(const string&, string);  
  void insert(const string&, const Node&);
  void print(ofstream &);
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

int Map::findIndex(const string& key, bool override_duplicate_key = true) {     
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
  int index = findIndex(key);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }
  keys[index] = key;
  values[index] = value;
}

void Map::find(const string& key, string ip2) {
  int index = findIndex(key);
  if (index != -1) {
    values[index].addAdjacency(ip2);
  }
  return;
}

void Map::findAdjacencies(const string& key) {
  int index = findIndex(key);
  if (index != -1) {
    values[index].print();
  }
  return;
}

void Map::print(ofstream &results) {
  for (int i = 0; i < size_max; i++) {
    if (!keys[i].empty()) {
      results << keys[i] << "\t" << values[i].size << "\n";
    }
  }
}

#endif /* Hash_h */