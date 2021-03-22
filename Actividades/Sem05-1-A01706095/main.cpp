// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Date:        01/03/2021
// File name:   main.cpp
// Title:       Sem05-1 Algoritmos de ordenamiento
// Description: Implementation of the sort and search 
//              algorithms
// --------------------------------------------------------
#include <iostream>
#include <chrono>
#include <string>
#include "Algoritmos.h"

int dataType = 1;               // arr de ints, floats, 
int busqOpc = 0;                // busq secuencial o binaria
int sortOpc = 0;                // opcion para algoritmos de ordenamiento

int main() {
  
  while (dataType != 5) {
    std::cout << "\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "Ingrese el tipo de dato (1-4) o 5 para salir :)\n";
    std::cout << "\t1) Integer \n";
    std::cout << "\t2) Float\n";
    std::cout << "\t3) Char\n";
    std::cout << "\t4) Double\n";
    std::cout << "\t5) Exit\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "Opción: ";
    std::cin >> dataType;
    std::cout << "\n";

    if (dataType == 5) {
      std::cout << "Gracias por utilizar nuestra app. ¡Hasta pronto!\n";
      break;
    }
    else if (dataType < 1 || dataType > 5){
      std::cout << "\nOpción inválida. Por favor introduzca una opción válida (1-5).\n";
      break;
    }

    std::cout << "*************** Algoritmos de búsqueda **************\n";
    std::cout << "\t1) sequencialSearch\n";
    std::cout << "\t2) binarySearch\n";
    std::cout << "\t3) Exit\n";
    std::cout << "*****************************************************\n";
    std::cout << "Opción: ";
    std::cin >> busqOpc;
    std::cout << "\n";

    if (busqOpc == 3) {
      std::cout << "Gracias por utilizar nuestra app. ¡Hasta pronto!\n";
      break;
    }
    else if (busqOpc < 1 || busqOpc > 3) {
      std::cout << "\nOpción inválida. Por favor introduzca una opción válida (1-3).\n";
      break;
    }

    std::cout << "************ Algoritmos de ordenamiento *************\n";
    std::cout << "\t1) swapSort\n";
    std::cout << "\t2) selectionSort\n";
    std::cout << "\t3) bubbleSort\n";
    std::cout << "\t4) insertionSort\n";
    std::cout << "\t5) mergeSort\n";
    std::cout << "\t6) quickSort\n";
    std::cout << "\t7) Exit\n";
    std::cout << "****************************************************\n";
    std::cout << "Opción: ";
    std::cin >> sortOpc;
    std::cout << "\n";

    if (sortOpc == 7) {
      std::cout << "Gracias por utilizar nuestra app. ¡Hasta pronto!\n";
      break;
    }
    else if (sortOpc < 1 || sortOpc > 7) {
      std::cout << "\nOpción inválida. Por favor introduzca una opción válida (1-7).\n";
      break;
    }
    
    if (dataType == 1) {
      Algoritmos<int> algo1(dataType, busqOpc, sortOpc);
      algo1.print("Arreglo ordenado ");
    }
    else if (dataType == 2) {
      Algoritmos<float> algo2(dataType, busqOpc, sortOpc);
      algo2.print("Arreglo ordenado ");
    }
    else if (dataType == 3) {
      Algoritmos<char> algo3(dataType, busqOpc, sortOpc);
      algo3.print("Arreglo ordenado ");
    }
    else if (dataType == 4) {
      Algoritmos<double> algo4(dataType, busqOpc, sortOpc);
      algo4.print("Arreglo ordenado ");
    }

  } /* End while */
 return 0;
}; /* End main */