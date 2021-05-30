/* 
* Actividad Sem14.  
* main.cpp
* Naomi Estefania Nieto Vega A01706095
* Ramsés Herrera Santiago A01283687
*/
#include <iostream>
#include <fstream>
#include <vector>

#include "Dijkstra.h"
#include "TopologicalSort.h"
#include "Bipartite.h"
using namespace std;

int main() {
  
  cout << "Cargando..." << endl;
  cout << "Dijkstra Algorithm " << endl;
  Node* a = new Node('a');
  Node* b = new Node('b');
  Node* c = new Node('c');
  Node* d = new Node('d');
  Node* e = new Node('e');
  Node* f = new Node('f');
  Node* g = new Node('g');

  Edge* e1 = new Edge(a, c, 1);
  Edge* e2 = new Edge(a, d, 2);
  Edge* e3 = new Edge(b, c, 2);
  Edge* e4 = new Edge(c, d, 1);
  Edge* e5 = new Edge(b, f, 3);
  Edge* e6 = new Edge(c, e, 3);
  Edge* e7 = new Edge(e, f, 2);
  Edge* e8 = new Edge(d, g, 1);
  Edge* e9 = new Edge(g, f, 1);

  a->distanceFromStart = 0;  // set start node
  Dijkstras();
  PrintShortestRouteTo(f);

  cout << endl;

  cout << "Topological Sorting" << endl;
  Graph topo(6);
    topo.addEdge(5, 2);
    topo.addEdge(5, 0);
    topo.addEdge(4, 0);
    topo.addEdge(4, 1);
    topo.addEdge(2, 3);
    topo.addEdge(3, 1);
 
    topo.topologicalSort();

    cout << endl << endl << "Is the graph Bipartite?" << endl;
    Graph g1(6);
    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);
    Bipartite bipartite(g1);
    if (bipartite.isBi()) {
      cout << bipartite.isBi() << endl;
      cout<<"The graph is Bipartite"<<endl;
    }
    else {
      cout << bipartite.isBi() << endl;
      cout<<"The graph is not Bipartite"<<endl;
    }
    cout << endl;
  return 0;
};
