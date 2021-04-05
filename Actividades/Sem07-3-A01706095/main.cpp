/* 
* Actividad: Sem07-1 Listas encadenadas
* 25 marzo 2021 11:50:52
* main.cpp
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera
*/
#include "Node.h"
#include "LinkedList.h"
#include "OutOfRangeException.h"
#include <iostream>
#include <stdlib.h>
 
using namespace std;

int main(int argc, const char * argv[]) {
  int opcion;
  int switchOption;
  int tipoDato;
  int tipoLista;
  int size;
  
  cout << "Hola!! Bienvenido." << endl;
  cout << "=====================================================\n";
  cout << "a) Elige un tipo de dato para las listas: " << endl;
  cout << "\t1. Entero \n";
  cout << "\t2. Char \n";
  cout << "=====================================================\n";
  cout << "Opción: ";
  cin >> tipoDato;
  cout << "=====================================================\n";
  cout << "b) Tipos de lista a generar disponibles: " << endl;
  cout << "\t1. Generar lista aleatoria \n";
  cout << "\t2. Generar lista manualmente \n";
  cout << "=====================================================\n";
  cout << "Opción: ";
  cin >> tipoLista;
  cout << "=====================================================\n";
  cout << "c) Introduce el tamaño de la lista: ";
  cin >> size;
  cout << "\n";

  if (tipoDato == 1) { // Lista de enteros
    LinkedList<int> lista = LinkedList<int>();
    LinkedList<int> lista2 = LinkedList<int>();

    if (tipoLista == 1) {  // Generar aleatorios
      cout << "Cool! Elegiste crear una listas aleatorias de tipo int!\n" << "Lista 1: "; 
      lista.newRandomList(tipoDato, size);
      cout << "Lista 2: "; 
      lista2.newRandomList(tipoDato, size);
    }
    else if (tipoLista == 2) { // Generar manual
      cout << "Cool! Elegiste crear una listas manuales de tipo int!\n" << "Lista 1: "; 
      lista.newManualList(tipoDato, size);
      cout << "\n";
      cout << "*IMPORTANTE:\n" << "Esta segunda lista sólo se usa para la sobrecarga del '='\n\n";
      cout << "Lista 2:  "; 
      lista2.newManualList(tipoDato, size);
    }
    else { 
      cout << "Introduce una opción válida (1-2)" << endl;
    }
    cout << "Listas creadas con éxito!\n" << "\n";
    lista.menuOpciones(lista, tipoDato, lista2);
  }

  else if (tipoDato == 2) { // Lista de chars
    LinkedList<char> lista = LinkedList<char>();
    LinkedList<char> lista2 = LinkedList<char>();

    if (tipoLista == 1) { // Generar aleatorios
      cout << "Cool! Elegiste crear una listas aleatorias de tipo char!\n" << "Lista 1: "; 
      lista.newRandomList(tipoDato, size);
      cout << "Lista 2: "; 
      lista2.newRandomList(tipoDato, size);
    }
    else if (tipoLista == 2) { // Generar manual
      cout << "Cool! Elegiste crear una listas manuales de tipo char!\n" <<"Lista 1: "; 
      lista.newManualList(tipoDato, size);
      cout << "\n";
      cout << "*IMPORTANTE:" << "Esta segunda lista sólo se usa para la sobrecarga del '='\n\n";
      cout << "Lista 2: "; 
      lista2.newManualList(tipoDato, size);
    }
    else {
      cout << "Introduce una opción válida (1-2)" << endl;
    }
    cout << "Listas creadas con éxito!\n" << "\n";
    lista.menuOpciones(lista, tipoDato, lista2);
  }
  return 0;
}; /* End main */