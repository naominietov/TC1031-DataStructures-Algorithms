// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 21/03/2021 17:54:01
// File name:   main.cpp
// Title:       Act-Integradora-1 Algoritmos fundamentales
// --------------------------------------------------------
#include "Data.h"
#include <vector>
#include <chrono>
#include <fstream>

/* This function is part of the quickSort function and it
basically takes the last element to its correct position in 
the sorted array, then place all the smaller elements than 
pivot in the left and the greater elements in the right 

It receives a Data type vector, low and high integers are the
starting and ending index, then it returns the partitioning 
index */

int partition(std::vector<Data *> &arr, int low, int high){
  int pivot = arr[high]->getKey();
  int i = (low - 1);
  for (int j = low; j <= high-1; j++) { 
    if (arr[j]->getKey() <= pivot) { 
      i++; 
      // swap arr[i] with arr[j]
      std::swap(arr[i], arr[j]);
    } 
  }
  // swap arr[i+1] with arr[high] 
  std::swap(arr[i+1], arr[high]);
  return i + 1; 
}

/* This is the quickSort algorithm, it basically helps us to
sort the "bitacora.txt" file by date and time. This algorithm 
has an average time complexity of O(n log n) and worst space 
complexity of O(log n)See reference: https://www.bigocheatsheet.com/ 

It receives a data type vector, start and end index and finally
it returns the sorted vector */

void quickSort(std::vector<Data *> &arr, int low, int high) {
  if (low < high) {
    //pi es el indice de la partición, arr[pi] esta en su lugar correcto
    int pi = partition(arr,low,high);
    //ordenar las dos particiones
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

/* This function helps us to search the starting and ending
date of the query so that we can compare their keys later.
It receives a T type vector and the requested search value, 
then it returns the position of that value. O(log n) complexity */

template <class T>
int binarySearchSorted(std::vector<T> &arr, int value){  
  int l = 0;
  int r = arr.size()-1;
  int m;
  int mValue;
  while (l <= r) {
    m = (l + r)/2;
    mValue = arr[m]->getKey();
    if (value == mValue) {
      return m;
    }
    else if (value < mValue) {
      r = m-1;
    }
    else {
      l = m+1;
    }
  }
  return l;
}

/* Main fuction, here is where read and write the file, also 
we call the functions described above and we ask the user to 
input the date and hour of the start and the end */

int main() {
  std::ifstream datos; 
  std::string month;
  std::string day;
  std::string hour;
  std::string min;
  std::string sec;
  std::string ipAddress;
  std::string errorMsg;
  std::vector<Data *> log;

  datos.open("bitacora.txt"); 

  while(datos.good()) {
      getline(datos,month,' ');
      getline(datos,day,' ');
      getline(datos,hour,':');
      getline(datos,min,':');
      getline(datos,sec,' ');
      getline(datos,ipAddress,' ');
      getline(datos,errorMsg);
      log.push_back(new Data(month, day, hour, min, sec, ipAddress, errorMsg));
  }
  datos.close(); 

  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();

  quickSort(log, 0,int(log.size()-1));

  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  std::cout << "Tiempo de ejecución del ordenamiento en ms: " << totalTime/std::chrono::milliseconds(1) << "\n";

  std::ofstream miArchivo("sortedData.txt");
  for (int i = 0; i < log.size(); i++) { // <
      miArchivo << log[i]->getMonth() << " ";
      miArchivo << log[i]->getDay() << " ";
      miArchivo << log[i]->getHour() << ":";
      miArchivo << log[i]->getMins() << ":";
      miArchivo << log[i]->getSecs() << " ";
      miArchivo << log[i]->getIpAddress() << " ";
      miArchivo << log[i]->getErrorMsg() << "\n";
  }
  miArchivo.close();

  std::cout<<"======================================================="<<std::endl;
  std::string monthStart;
  std::string dayStart;
  std::string hourStart;
  std::string minStart;
  std::string secStart;
  std::string monthEnd;
  std::string dayEnd;
  std::string hourEnd;
  std::string minEnd;
  std::string secEnd;

  std::cout << "Ingrese la fecha de inicio para buscar: " << std::endl;
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
  std::cout<<"======================================================="<<std::endl;
  std::cout << "Ingrese la fecha de fin para buscar: " << std::endl;
  std::cout << "Month (Ex: Jun, Jul, Aug, Sep, Oct): ";
  std::cin >> monthEnd;
  std::cout << "Day (Ex: 22): ";
  std::cin >> dayEnd;
  std::cout << "Hour (Ex: 04): ";
  std::cin >> hourEnd;
  std::cout << "Minutes (Ex: 17): ";
  std::cin >> minEnd;
  std::cout << "Seconds (Ex: 34): ";
  std::cin >> secEnd;
  Data busqFin(monthEnd, dayEnd, hourEnd, minEnd, secEnd, "***", "***");
  std::cout<<"======================================================="<<std::endl;
  std::cout << "Resultados de la búsqueda" << std::endl;
  int start = binarySearchSorted(log, busqIn.getKey());
  int end = binarySearchSorted(log, busqFin.getKey());

  std::ofstream busqArchivo("queryResults.txt");
  for (int i = start; i <= end; i++) {
    if (log[i]->getKey() <= busqFin.getKey()) {
      log[i]->print();
      busqArchivo << log[i]->getMonth() << " ";
      busqArchivo << log[i]->getDay() << " ";
      busqArchivo << log[i]->getHour() << ":";
      busqArchivo << log[i]->getMins() << ":";
      busqArchivo << log[i]->getSecs() << " ";
      busqArchivo << log[i]->getIpAddress() << " ";
      busqArchivo << log[i]->getErrorMsg() << "\n";
    }
  }
  busqArchivo.close();
  return 0;
} 
