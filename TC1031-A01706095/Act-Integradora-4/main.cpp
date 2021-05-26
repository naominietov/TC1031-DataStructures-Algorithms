/*--------------------------------------------------------
ID:          A01706095 
Name:        Naomi Estefanía Nieto Vega 
Last update: 24/04/2021 14:06:56
File name:   Data.h
Title:       Act-Integradora-4
--------------------------------------------------------*/
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>

#include "Heap.h"
#include "Node.h"
#include "Data.h"

/* Main fuction, here is where read and write the file, also 
we call the functions heapSort to order the IP addresses and 
then it prints the top 5 IP Addresses by its adjacencies */

int main() {
  Heap<Node> heapData = Heap<Node>();

  int nodes, incidence, cont = 0;
  std::string aux, firstIp, secondIp;
  map<std::string, Node> map;
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
      std::stringstream string2int2(incidencia);
      string2int2 >> incidence;
      cont+=1;
    }
    do {
      getline(bitacora,aux);
      map.insert({aux,Node(aux)});
      cont+=1;
    } while (cont < nodes);
    
    do {
      getline(bitacora,aux,' ');
      getline(bitacora,aux,' ');
      getline(bitacora,aux,' ');
      getline(bitacora,firstIp,':');
      getline(bitacora,aux,' ');
      getline(bitacora,secondIp,':');
      if ( auto it{map.find(firstIp)}; it != std::end(map)){
        auto[key, value] {*it};
        it->second.addAdjacency(secondIp);
      }
      getline(bitacora,aux,' ');
      getline(bitacora,aux);
      cont+=1;
    } while (cont < incidence + nodes);
  }
  bitacora.close();

  for (auto const& [key, val]:map){
    heapData.heapLog.push_back(val);
  }

  heapData.heapSort(heapData.heapLog, heapData.heapLog.size());

  std::ofstream sortedIPAdjacencies("IPsOrdenadasPorAdjacencia.csv");
  sortedIPAdjacencies << "IP Address," << "Number of Adjacencies" << "\n";
  for (int i = heapData.heapLog.size()-1; i < heapData.heapLog.size(); i--) {
    sortedIPAdjacencies << heapData.heapLog[i].nativeIpAddress << "," << heapData.heapLog[i].size;
    sortedIPAdjacencies << "\n";
  }
  sortedIPAdjacencies.close();

  std::ofstream results("Results.txt");
  std::cout << "\n";
  std::cout << "*** Results: IP with the most adjacencies ***\n";
  std::cout << "═════════════════════════════════════════════\n";
  std::cout << "#\tIP Address\tNumber of Adjacencies\n" << "\n";
  int contador = 1;
  results << "The IP Addresses with the most adjacencies are: " << "\n";
  for (int i = heapData.heapLog.size()-1; i > heapData.heapLog.size()-6; i--) {
    results << heapData.heapLog[i].nativeIpAddress << "\t" << heapData.heapLog[i].size << "\n";
    std::cout << "[" << contador << "]" << "\t" << heapData.heapLog[i].nativeIpAddress 
    << "\t\t" << heapData.heapLog[i].size << "\n";
    contador++;
  }  
  std::cout << "═════════════════════════════════════════════\n";
  std::cout << "\n";

  results.close();

  return 0; 
}
