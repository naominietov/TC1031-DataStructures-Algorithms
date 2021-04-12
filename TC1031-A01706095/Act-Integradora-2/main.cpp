// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 01/04/2021 17:00:01
// File name:   main.cpp
// Title:       Act-Integradora-2 Estructuras datos lineales
// --------------------------------------------------------
#include <vector>
#include <chrono>
#include <fstream>

#include "Data.h"
#include "DoublyLinkedList.h"

/* Main fuction, here is where read and write the file, also 
we call the functions described above and we ask the user to 
input the date and hour of the start and the end */

int main() {
  std::ifstream datos; 
  std::string month, day, hour, min, sec, ipAddress, errorMsg;
  DoublyLinkedList<Data*> bitacora = DoublyLinkedList<Data*>();
  
  datos.open("bitacora.txt"); 
  while(datos.good()) {
    getline(datos,month,' ');
    getline(datos,day,' ');
    getline(datos,hour,':');
    getline(datos,min,':');
    getline(datos,sec,' ');
    getline(datos,ipAddress,' ');
    getline(datos,errorMsg);
    bitacora.addLast(new Data(month, day, hour, min, sec, ipAddress, errorMsg));
  }
  datos.close();

  auto startTime = std::chrono::high_resolution_clock::now();
  
  bitacora.quickSortIterative(bitacora, 1, bitacora.getSize());

  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  std::cout << "=======================================================" << std::endl;
  std::cout << "Tiempo de ejecución del ordenamiento en ms: " << totalTime/std::chrono::milliseconds(1) << "\n";
  
  std::ofstream miArchivo("bitacora_ordenada.txt");
  for (int i = 1; i < bitacora.getSize()+1; i++) { 
    miArchivo << bitacora[i]->value->valor;
    if (i != bitacora.getSize()) {
      miArchivo << std::endl;
    }
  }
  std::string monthStart, dayStart, hourStart, minStart, secStart;
  std::string monthEnd, dayEnd, hourEnd, minEnd, secEnd;
  miArchivo.close();
  std::cout << "=======================================================" << std::endl;
  std::cout << "Enter the start date to search: " << std::endl;
  std::cout << "Month (Ex: Jun, Jul, Aug, Sep, Oct): ";
  std::cin >> monthStart;
  std::cout << "Day (Ex: 22): ";
  std::cin >> dayStart;
  std::cout << "Hour (Ex: 04): ";
  std::cin >> hourStart;
  std::cout << "Minutes (Ex: 17): ";
  std::cin >> minStart;
  std::cout << "Seconds (Ex: 34): ";
  std::cin >> secStart;
  Data busqIn(monthStart, dayStart, hourStart, minStart, secStart, "***", "***");
  std::cout << "=======================================================" << std::endl;
  std::cout << "Enter the end date to search: " << std::endl;
  std::cout << "Month (Ex: Jun, Jul, Aug, Sep, Oct): "; 
  std::cin >> monthEnd;
  std::cout << "Day (Ex: 24): "; 
  std::cin >> dayEnd;
  std::cout << "Hour (Ex: 04): "; 
  std::cin >> hourEnd;
  std::cout << "Minutes (Ex: 17): "; 
  std::cin >> minEnd;
  std::cout << "Seconds (Ex: 34): "; 
  std::cin >> secEnd;
  Data busqFin(monthEnd, dayEnd, hourEnd, minEnd, secEnd, "***", "***");
  std::cout << "=======================================================" << std::endl;
  std::cout << "Search results: " << std::endl;

  int start = bitacora.binarySearchSorted(bitacora, busqIn.getKey(), 0);
  int end = bitacora.binarySearchSorted(bitacora, busqFin.getKey(), 1);
  
  std::ofstream busqArchivo("resultado_busqueda.txt");
  for (int i = start; i <= end; i++) {
    if (bitacora[i]->value->getKey() <= busqFin.getKey()) {
      bitacora[i]->value->print();
      busqArchivo << bitacora[i]->value->valor;
      if (i != end) {
       busqArchivo << std::endl;
      }
    }
  }
  busqArchivo.close();
  return 0;
}
