// --------------------------------------------------------
// ID:          A01706095 
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 02/06/2021 20:48:26
// File name:   main.cpp
// Title:       Act-Integradora-5
// --------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Node.h"
#include "Data.h"
#include "Hash.h"

int main() {
  Map map;
  int nodes, incidence, cont = 0;
  int value1, value2, value3, value4, uniqueID, index;
  std::string aux, firstIp, secondIp;
  std::string intValue1, intValue2, intValue3, intValue4;
  std::string requestedIp;
  
  std::ifstream bitacora;
  bitacora.open("bitacoraGrafos.txt"); 

  while(bitacora.good()) {
    if (cont == 0) {
      getline(bitacora,aux,' ');
      std::string node(aux);
      std::stringstream string2int(node);
      string2int >> nodes;
      getline(bitacora,aux);
      std::string incidencia(aux);
      std::stringstream string2intValue2(incidencia);
      string2intValue2 >> incidence;
      cont+=1;
    }
    do {
      getline(bitacora,intValue4,'.');
      getline(bitacora,intValue3,'.');
      getline(bitacora,intValue2,'.');
      getline(bitacora,intValue1);
      firstIp = intValue4 + "." + intValue3 + "." + intValue2 + "." + intValue1;
      value1 = std::stoi(intValue4)*16 + (255*2+1) + (255*4+1) + (255*8+1);
      value2 = std::stoi(intValue3)*8 + (255*2+1) + (255*4+1);
      value3 = std::stoi(intValue2)*4 + (255*2+1);
      value4 = std::stoi(intValue1)*2;
      uniqueID = value1 + value2 + value3 + value4;
      Node a(firstIp, uniqueID);
      map.insert(firstIp, a);
      cont+=1;
    } while (cont < nodes);
    
    do {
      getline(bitacora,aux,' ');
      getline(bitacora,aux,' ');
      getline(bitacora,aux,' ');
      getline(bitacora,intValue4,'.');
      getline(bitacora,intValue3,'.');
      getline(bitacora,intValue2,'.');
      getline(bitacora,intValue1,':');
      getline(bitacora,aux,' ');
      getline(bitacora,secondIp,':');
      getline(bitacora,aux);
      firstIp = intValue4 + "." + intValue3 + "." + intValue2 + "." + intValue1;
      value1 = std::stoi(intValue4)*16 + (255*2+1) + (255*4+1) + (255*8+1);
      value2 = std::stoi(intValue3)*8 + (255*2+1) + (255*4+1);
      value3 = std::stoi(intValue2)*4 + (255*2+1);
      value4 = std::stoi(intValue1)*2;
      uniqueID = value1 + value2 + value3 + value4;
      map.find(firstIp, secondIp);
      cont+=1;
    } while (cont < incidence + nodes);
  }
  bitacora.close();

  std::ofstream sortedIPAdjacencies("sortedAdjacencyIP.txt");
  sortedIPAdjacencies << "IP Address" << "\t" << "Number of Adjacencies" << "\n";
  map.print(sortedIPAdjacencies);
  sortedIPAdjacencies.close();
  
  std::cout << "\n";
  std::cout << "Welcome!" << "\n";
  std::cout << "═════════════════════════════════════════════\n";
  std::cout << "Enter a valid IP Address: ";
  std::cin >> requestedIp;
  std::cout << "═════════════════════════════════════════════\n";
  map.findAdjacencies(requestedIp);
  std::cout << "═════════════════════════════════════════════\n";
  std::cout << "Thanks for using our app. " << "\n";
  return 0;
}