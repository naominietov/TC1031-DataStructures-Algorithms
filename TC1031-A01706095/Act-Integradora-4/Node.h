/*--------------------------------------------------------
ID:          A01706095 
Name:        Naomi Estefanía Nieto Vega 
Last update: 24/04/2021 14:06:56
File name:   Node.h
Title:       Act-Integradora-4
--------------------------------------------------------*/
#ifndef Node_h
#define Node_h

#include <vector>
#include <string>

class Node {
  public:
  int ipValue;
  int size;
  std::string nativeIpAddress;
  std::vector<std::string> adj;
  Node();
  Node(std::string);
  Node(std::string, int);
  void addAdjacency(std::string);
};

Node::Node() {
  nativeIpAddress = "";
  size = 0;
  ipValue = 0;
}

Node::Node(std::string ip) {
  nativeIpAddress = ip;
  size = 0;
}

Node::Node(std::string ip, int ipValor) {
  nativeIpAddress = ip;
  ipValue = ipValor;
  size = 0;
}

void Node::addAdjacency(std::string a) {
  this->adj.push_back(a);
  this->size++;
}

#endif /* Node_h */