// main.cpp
// Actividad Sem13-2
// Naomi Estefania Nieto Vega A01706095
// Ramsés Herrera Santiago A01283687

#include <iostream>
#include <fstream>
#include <vector>
#include "GraphMatrix.h"
#include "Graph.h"
 
using namespace std;

int main() {
  ifstream graph("grafo.txt");

  Graph g;
  cout << "Cragando..." << endl;
  g.loadGraphList(cin);
  cout << "=== Lista de adyacencia ===" << endl;
  cout << g.printAdjList();
  cout << "=== BFS starting from vertex 0 ===\n";
  g.BFS(0);
  cout << endl;
  cout << "=== DFS starting from vertex 0 ===\n";
  g.DFS(0);
  cout << "\n";

  GraphMatrix h(5);
  cout << "Cragando..." << endl;
  h.loadGraphList(graph);
  cout << "=== Matriz ===" << endl;
  h.printMatrix();
  h.AdjMatrixBFS(0);
  h.AdjMatrixDFSInitialize(0);
  return 0;
};

/* See reference:
* https://www.geeksforgeeks.org/graph-and-its-representations/
* https://www.programmersought.com/article/95747275426/
* https://www.srcmake.com/home/cpp-bfs-dfs
*/