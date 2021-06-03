// --------------------------------------------------------
// ID:          A01706095 
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 02/06/2021 20:48:26
// File name:   main.cpp
// Title:       Act-Integradora-5
// --------------------------------------------------------
#ifndef Node_h
#define Node_h

#include <vector>
#include <string>

class Node {
  public:
  int ipValue;
  int size;
  std::string IpAddress;
  std::vector<std::string> adj;
  Node();
  Node(std::string);
  Node(std::string, int);
  void addAdjacency(std::string);
  void print();
};

Node::Node() {
  IpAddress = "";
  size = 0;
  ipValue = 0;
}

Node::Node(std::string ip) {
  IpAddress = ip;
  size = 0;
}

Node::Node(std::string ip, int ipValor) {
  IpAddress = ip;
  ipValue = ipValor;
  size = 0;
}

void Node::addAdjacency(std::string a) {
  adj.push_back(a);
  size++;
}

void Node::print() {
  std::cout << "Requested IP: " << IpAddress << "\n";
  std::cout << "\n";
  std::cout << "Adjacent IP Addresses: " << "\n";
  for (int i = 0; i < adj.size(); i++) {
    std::cout << "[" << i+1 << "]" << "- " << adj[i] << "\n";
  }
}

#endif /* Node_h */