// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 24/04/2021 14:06:56
// File name:   main.cpp
// Title:       Act-Integradora-3
// --------------------------------------------------------
#include <vector>
#include <chrono>
#include <fstream>

#include "Data.h"
#include "Heap.h"

/* Main fuction, here is where read and write the file, also 
we call the functions heapSort to order the IP addresses and 
then it prints the top 5 IP Addresses by times accessed */

int main() {
  Heap<Data> data = Heap<Data>();
  std::ifstream datos;
  std::string month, day, hour, min, sec, ipAddress, port, errorMsg;
  std::string monthStart, dayStart, hourStart, minStart, secStart;
  std::string monthEnd, dayEnd, hourEnd, minEnd, secEnd;
  int n = 0, contAcceso = 1, r = 0;

  datos.open("bitacoraHeap.txt"); 
  while(datos.good()) {
    getline(datos,month,' ');
    getline(datos,day,' ');
    getline(datos,hour,':');
    getline(datos,min,':');
    getline(datos,sec,' ');
    getline(datos,ipAddress,':');
    getline(datos,port,' ');
    getline(datos,errorMsg);
    data.bitacora.push_back(Data(month, day, hour, min, sec, ipAddress, port, errorMsg));
    n+=1;
  }
  datos.close();

  data.heapSort(data.bitacora, n);
  
  std::ofstream sortedFile("sortedData.txt");
  for (int i = 0; i < n; ++i) { 
		sortedFile << data.bitacora[i].valor << "\n";
  }
  sortedFile.close();

  std::ofstream results("timesAccessedPerIP.txt");
  for (int i = 0; i < n; i++) {
    while (i < n - 1 && data.bitacora[i].getKey() == data.bitacora[i+1].getKey()) {
      i++;
      contAcceso++;
    }
    Data temp = data.bitacora[i];
    temp.access = contAcceso;
    data.push(temp);
    results << temp.getIpAddress() << "\t\t\t" << contAcceso << "\n";
    contAcceso = 1;
    r++;
  }
  results.close();
  std::cout << "\n";
  std::cout << "***** Results - Top 5 IP Addresses *****\n";
  std::cout << "════════════════════════════════════════\n";
  std::cout << "#\tIP Address\t\tTimes accessed\n";
  std::cout << "════════════════════════════════════════\n";
  for (int i = 0; i < 5; i++) {
    std::cout << "[" << i+1 << "]\t" << data.top().getIpAddress() << "\t\t" << data.top().access << "\n";
    data.extractMax();
    r--;
  }
  return 0;
} /* End main */