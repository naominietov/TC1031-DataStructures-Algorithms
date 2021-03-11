// Sem03-2 Buscando el caracter único
// main.cpp
// Naomi Estefanía Nieto Vega - A01706095 - Campus Querétaro
// Lunes 1 marzo de 2021

#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

string busquedaSecuencial(string s) {
  int cuenta = 0; // cuenta las comparaciones
  int size = s.length(); // cantidad de cuadritos en vector
  string resultado, espacio = " ";
  //cout << "size: " << size << endl;

  int i; // contador 
  for (i = 0; i < size-2; i+=2) {
    if (s[i] == s[i+1]) {
      cuenta = cuenta + 1;
    }
    else {
      cuenta = cuenta + 1;
      resultado = s[i] + espacio + to_string(cuenta);
      return resultado;
    }
  }
  if (i == (size-1)) { // o (i != size)
    return s[size-1] + espacio + to_string(cuenta);
  }
  return " ";
}

string busquedaBinaria(string s) {
  int l = 0; // posicion a la izquierda
  int r = s.length()-1; // posicion a la derecha
  string resultado, espacio = " ";
  int cuenta = 0;

  while (l <= r) {
    cuenta += 1; // cuenta las comparaciones
    int m = (l+r)/2;
    if (m % 2 != 0) {
      m = m + 1;
    }
    if (s[m] == s[m-1]) {
      r = m - 1;
    }
    else if (s[m] == s[m+1]) {
      l = m + 1;
    }
    else {
      resultado = s[m] + espacio + to_string(cuenta);
      return resultado;
    }
  }
  return " ";
}

int main() {

  int num_strings = 0;
  string datos = "";
  vector<string> cadenas;

  cout << endl;
  cout << "Hola! Bienvenido" << endl;
  cout << "Ingrese la cantidad de strings: ";
  cin >> num_strings;
  cout << "Ingrese los strings: " << endl;
  for (int i = 0; i < num_strings; i++) {
    cin >> datos;
    cadenas.push_back(datos);
  }
  cout << endl;
  // Inicio conteo de tiempo de ejecución
  auto startTime = std::chrono::high_resolution_clock::now();

  cout << "\tBúsqueda Secuencial" << " " << "\tBúsqueda Binaria" << endl;
  cout << "\t-------------------" << " " << "\t------------------" << endl;

  for (int i = 0; i < num_strings; i++) {
    cout << "\t" << busquedaSecuencial(cadenas[i]) << "\t\t\t\t\t\t" << busquedaBinaria(cadenas[i]) << endl;
    cout << endl;
  }
  // Termina conteo de tiempo de ejecución 
  auto endTime = std::chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;

  return 0;
}

/* Caso de prueba 
INPUT:
4
AACCZZTTVXX 
AAB
CCAAXWWTT
XXYYZZAAC

OUTPUT:
V 5 V 2
B 1 B 1
X 3 X 1
C 4 C 3
*/