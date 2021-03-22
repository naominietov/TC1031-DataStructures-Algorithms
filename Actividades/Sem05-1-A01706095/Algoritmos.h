// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Date:        01/03/2021
// File name:   Algoritmos.h
// Title:       Sem05-1 Algoritmos de ordenamiento
// Description: Implementation of the sort and search 
//              algorithms
// --------------------------------------------------------
#ifndef Algoritmos_h
#define Algoritmos_h

#include <iostream>
#include <stdio.h>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <ctime>

template <class T>
class Algoritmos {
  private:
    std::vector<T> arr;         // vector generado aleatoriamente
    T keyValue;                 // dato a buscar
    const int numMax = 10;      // número máximo de elementos en el vector
    int dataType;               // arr de ints, floats, 
    int busqOpc;                // busq secuencial o binaria
    int sortOpc;                // opcion para algoritmos de ordenamiento
    int compara = 0;            // comparaciones realizadas
    int comparaBusq = 0;        // comparaciones de busqueda
    int swap = 0;               // intercambios realizados
    int indiceBusq;             // indice para las busquedas
    int finalTotalTime;         // tiempo de los algoritmos de ordenamiento

  public:
    Algoritmos(int, int, int);
    // Funciones de utilidad
    void busqueda();
    void ordenamiento();
    void print(std::string);
    // Algoritmos de búsqueda
    int sequencialSearch(std::vector<T>&, T key);
    int binarySearch(std::vector<T>&, T key);
    // Utility functions for merge and quick sort
    void merge(std::vector<T> &, int, int, int);
    int partition(std::vector<T>&, int, int);
    // Algoritmos de ordenamiento
    void swapSort(std::vector<T>&); 
    void selectionSort(std::vector<T>&);
    void bubbleSort(std::vector<T>&);
    void insertionSort(std::vector<T>&);
    void mergeSort(std::vector<T> &, int, int);
    void quickSort(std::vector<T>&, int, int);
};

template <class T>
Algoritmos<T>::Algoritmos(int tipoDatoInput, int opcionBusquedaInput, int opcionOrdenaInput) {
    dataType = tipoDatoInput;
    busqOpc = opcionBusquedaInput;
    sortOpc = opcionOrdenaInput;

  if (dataType == 1) { // Vector int
    std::cout << "Cool! Elegiste un vector de tipo int" << "\n";
    std::cout << "\nCreando lista de datos tipo int...";
    std::cout << "\nLista creada con éxito!" << std::endl;
    for (int i = 0; i < numMax; i++) {
        int b = (rand() % 50) + 1;
        arr.push_back(b);
    }
  }
  else if (dataType == 2) { // Vector float
    std::cout << "Cool! Elegiste un vector de tipo float" << "\n";
    std::cout << "\nCreando lista de datos tipo float...";
    std::cout << "\nLista creada con éxito!" << std::endl;
    for (int i = 0; i < numMax; i++) {
        float b = ((float)rand()/(float)(RAND_MAX)) * 50.0;
        arr.push_back(b);
    }
  }
  else if (dataType == 3) { // Vector char
    std::cout << "Cool! Elegiste un vector de tipo char" << "\n";
    std::cout << "\nCreando lista de datos tipo char...";
    std::cout << "\nLista creada con éxito!" << std::endl;
    for (int i = 0; i < numMax; i++) {
        char b = (rand() % 26) + 'A';
        arr.push_back(b);
    }
  }
  else if (dataType == 4) { // Vector double
    std::cout << "Cool! Elegiste un vector de tipo double" << "\n";
    std::cout << "\nCreando lista de datos tipo double...";
    std::cout << "\nLista creada con éxito!" << std::endl;
    for (int i = 0; i < numMax; i++) {
      std::setprecision(3);
      double b = ((double)rand()/(double)(RAND_MAX)) * 50.0;
      arr.push_back(b);
    }
  }
  else {
    std::cout << "Opción inválida" << std::endl;
  }
  this -> print("Arreglo desordenado ");
  this -> busqueda();
  this -> ordenamiento();
}

template <class T>
void Algoritmos<T>::ordenamiento() {
  if (sortOpc != 7) {
    if (sortOpc == 1) {
      std::cout << "Has seleccionado swapSort como algoritmo de ordenamiento\n";
      this -> swapSort(arr);
    }
    else if (sortOpc == 2) {
      std::cout << "Has seleccionado selectionSort como algoritmo de ordenamiento\n";
      this -> selectionSort(arr);
    }
    else if (sortOpc == 3) {
      std::cout << "Has seleccionado bubbleSort como algoritmo de ordenamiento\n";
      this -> bubbleSort(arr);
    }
    else if (sortOpc == 4) {
      std::cout << "Has seleccionado insertionSort como algoritmo de ordenamiento\n";
      this -> insertionSort(arr);
    }
    else if (sortOpc == 5) {
      std::cout << "Has seleccionado mergeSort como algoritmo de ordenamiento\n";
      this -> mergeSort(arr,0,int(arr.size()-1));
    }
    else if (sortOpc == 6) {
      std::cout << "Has seleccionado quickSort como algoritmo de ordenamiento\n";
      this -> quickSort(arr,0,int(arr.size()-1));
    }
    else {
      std::cout << "Opción inválida" << std::endl;
    }
  }
}

template <class T>
void Algoritmos<T>::busqueda() {
  if (busqOpc != 3) {
    std::string tipoElegido = dataType == 1 ? "int" : dataType == 2 ? "float" : dataType == 3 ? "char" : dataType == 4 ? "double" : "";
    std::cout << "Introduce el key a buscar: ";
    std::cin >> keyValue;
    std::cout << "\n";
    if (busqOpc == 1) 
      std::cout << "Has seleccionado búsqueda secuencial\n";
      this -> sequencialSearch(arr, keyValue);
    if (busqOpc == 2)
      std::cout << "Has seleccionado búsqueda binaria\n";
      this -> binarySearch(arr, keyValue);
  }
}

template <class T>
void Algoritmos<T>::print(std::string type) {
  std::cout << "\n";
  std::cout << type << "[ ";
  for(int i = 0; i < arr.size(); i++) {
    std::cout << " " << arr[i] << " ";
  }
  std::cout << " ]" << "\n";

  if(type == "Arreglo ordenado ") {
    std::cout << "=====================================================\n";
    if(sortOpc != 7) {
      if(sortOpc == 1){std::cout << "Resultados Swap Sort: " << "\n";}
      else if (sortOpc == 2) {std::cout << "Resultados Selection Sort: " << "\n";}
      else if(sortOpc == 3){std::cout << "Resultados Bubble Sort: " << "\n";}
      else if (sortOpc == 4) {std::cout << "Resultados Insertion Sort: " << "\n";}
      else if(sortOpc == 5){std::cout << "Resultados Merge Sort: " << "\n";}
      else if (sortOpc == 6) {std::cout << "Resultados Quick Sort: " << "\n";}
      std::cout << "Comparaciones: " << compara << "\n";
      std::cout << "Swaps: " << swap << "\n";
    }
    std::cout << "Tiempo de ejecución del ordenamiento en ms: " << finalTotalTime << "\n";

    if(busqOpc != 3){
      std::cout << "=====================================================\n";
      if(busqOpc == 1){ std::cout << "Resultados Búsqueda Secuencial: " << "\n";}
      else if (busqOpc == 2) {std::cout << "Resultados Búsqueda Binaria: " << "\n";}
      std::cout << "Comparaciones: " << comparaBusq << "\n";
      if (indiceBusq > -1) {
        std::cout << "El índice de " << keyValue << " es: " << indiceBusq << "\n";
      }
      else {
        std::cout << "No está la llave " << keyValue << " en el vector" << "\n";
      }
      std::cout << "Tiempo de ejecución de la búsqueda en ms: " << finalTotalTime << "\n";
    }
    std::cout << "=====================================================\n";
  } // fin if de arreglo ordenado
} // fin funcion principal

//  Busqueda secuencial
template <class T>
int Algoritmos<T>::sequencialSearch(std::vector<T>&arr, T key) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < arr.size(); i++) {
    comparaBusq++;
    if (key == arr[i]) {
      i = indiceBusq;
      indiceBusq = i;
      return indiceBusq;
      break;
    }
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
  return -1;
}

//  Busqueda binaria
template <class T>
int Algoritmos<T>::binarySearch(std::vector<T>&arr, T key) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  int l = 0;
  int tam = arr.size();
  int r = tam-1;

  while (l <= r) {
    int mid = l + (r-l)/2;
    comparaBusq++;
    if (arr[mid] == key){
      indiceBusq = mid;
      return indiceBusq;
      break;
    }
    else if (arr[mid] < key) {
      l = mid + 1;
    }
    else if (arr[mid] > key) {
      r = mid - 1;
    }
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
  return 0;
}

// swapSort
template <class T>
void Algoritmos<T>::swapSort(std::vector<T> &arr) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  int i, j, aux;
  int var;
  var = arr.size();

  for (i = 0; i < (var-1); i++) {
    for (j = i + 1; j < var; j++) {
      compara++;
      if (arr[i] > arr[j]) {
        swap++;
        // intercambiar arr[i] y a[j]
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
      }
    }
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
}

// selectionSort
template <class T>
void Algoritmos<T>::selectionSort(std::vector<T> &arr) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  int i, j;
  int var;
  var = arr.size();
  for (i = 0; i < (var-1); i++) {
    int min = i;
    for (j = i + 1; j < var; j++) {
        compara++;// esta bien aqui?
        if (arr[j] < arr[min]) {
          min = j;
        }
    }
    swap++;
    T aux = arr[min];
    arr[min] = arr[i];
    arr[i] = aux;
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
}

//ordenaBurbuja
template <class T>
void Algoritmos<T>::bubbleSort(std::vector<T> &arr) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  int i, j;
  for (i = 0; i < arr.size()-1; i++) {
    int swap = 0;
      for (j = 0; j < arr.size()-i-1; j++) {
          compara++;
          if (arr[j] > arr[j+1]) {
              swap++;
              T aux = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = aux;
          }
      }
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
}

//insertion sort
template <class T>
void Algoritmos<T>::insertionSort(std::vector<T> &arr) {
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();
  int i, j;
  for (i = 1; i < arr.size(); i++) {
      int key;
      key = arr[i];
      j = i - 1;
      compara++;
      while (j >= 0 && arr[j] > key) {
          swap++; 
          arr[j+1] = arr[j];
          j = j - 1;
      }
      arr[j+1] = key;
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  finalTotalTime = totalTime/std::chrono::milliseconds(1);
}

// merge
template <class T>
void Algoritmos<T>::merge(std::vector<T> &arr, int l, int m, int r) {
    // Calcula el tamaño de los subarreglos a fusionar
    int n1 = m - l + 1;
    int n2 = r - m;
    // arreglos temporales
    // int L[n1], R[n2];
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    // copiar datos en subarreglos temporales
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    // fusiona los subarreglos
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        compara++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // copia los elementos restantes si existen
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// merge sort
template <class T>
void Algoritmos<T>::mergeSort(std::vector<T> &arr, int l, int r) {
    // Inicio conteo de tiempo de ejecución
    auto startTime = std::chrono::high_resolution_clock::now();
    if(l >= r){
		  return;
	  }
    // Encontrar el punto medio
	  int m = l + (r-l)/2;
    // Ordenar la primera y segunda mitad
	  mergeSort(arr,l,m);
	  mergeSort(arr,m+1,r);
    // Fusionar ambas mitades
	  merge(arr,l,m,r);
    // Termina conteo de tiempo de ejecución 
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    finalTotalTime = totalTime/std::chrono::milliseconds(1);
}

// partition
template <class T>
int Algoritmos<T>::partition(std::vector<T> &arr, int low, int high){
    int pivot = arr[high]; // pivot 
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) { 
        (compara)++;
        if (arr[j] <= pivot) { 
            i++; 
            // intercambiar arr[i] con arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        } 
    }
    //intercambiar arr[i+1] con arr[high] 
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp; 
    return i + 1; 
}

//quick sort
template <class T>
void Algoritmos<T>::quickSort(std::vector<T>& arr, int low, int high) {
    // Inicio conteo de tiempo de ejecución
    auto startTime = std::chrono::high_resolution_clock::now();
    if (low < high) {
        //pi es el indice de la partición, arr[pi] esta en su lugar correcto
        int pi = partition(arr,low,high);
        //ordenar las dos particiones
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    // Termina conteo de tiempo de ejecución 
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    finalTotalTime = totalTime/std::chrono::milliseconds(1);
}


#endif /* Algoritmos_h */