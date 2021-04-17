/* 
* Actividad: Sem08-2 Listas doblemente encadenadas
* 5 febrero 2021 11:24:52
* main.cpp
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/

#include "Node.h"
#include "DoublyLinkedList.h"
#include "OutOfRangeException.h"
#include <iostream>
#include <stdlib.h>
 
using namespace std;

int main(int argc, const char * argv[]) {
  int opcion, switchOption, tipoDato, tipoLista, size;
  
  cout << "Hola!! Bienvenido.\n";
  cout << "═════════════════════════════════════════════════════\n";
  cout << "a) Elige un tipo de dato para las listas:\n";
  cout << "\t1. Entero [int]\n\t2. Char [char]\n";
  cout << "═════════════════════════════════════════════════════\nOpción: ";
  cin >> tipoDato;
  cout << "═════════════════════════════════════════════════════\n";
  cout << "b) Tipos de lista a generar disponibles:\n";
  cout << "\t1. Generar lista aleatoria\n\t2. Generar lista manualmente\n";
  cout << "═════════════════════════════════════════════════════\nOpción: ";
  cin >> tipoLista;
  cout << "═════════════════════════════════════════════════════\n";
  cout << "c) Introduce el tamaño de la lista: ";
  cin >> size;
  cout << "═════════════════════════════════════════════════════\n\n";

  if (tipoDato == 1) { // Lista de enteros
    DoublyLinkedList<int> lista = DoublyLinkedList<int>();
    DoublyLinkedList<int> lista2 = DoublyLinkedList<int>();

    if (tipoLista == 1) {  // Generar aleatorios
      cout << "Elegiste crear una listas aleatorias de tipo int!\n" << "Lista 1: "; 
      lista.newRandomList(tipoDato, size);
      cout << "Lista 2: "; 
      lista2.newRandomList(tipoDato, size);
    }
    else if (tipoLista == 2) { // Generar manual
      cout << "Elegiste crear una listas manuales de tipo int!\n" << "Lista 1: "; 
      lista.newManualList(tipoDato, size);
      cout << "\n";
      cout << "*IMPORTANTE:\n" << "Esta segunda lista sólo se usa para la sobrecarga del '='\n\n";
      cout << "Lista 2:  "; 
      lista2.newManualList(tipoDato, size);
    }
    else { 
      cout << "ERROR: Introduce una opción válida (1-2)" << endl;
    }
    cout << "Listas creadas con éxito!\n" << "\n";
    lista.menuOpciones(lista, tipoDato, lista2);
  }

  else if (tipoDato == 2) { // Lista de chars
    DoublyLinkedList<char> lista = DoublyLinkedList<char>();
    DoublyLinkedList<char> lista2 = DoublyLinkedList<char>();

    if (tipoLista == 1) { // Generar aleatorios
      cout << "Elegiste crear una listas aleatorias de tipo char!\n" << "Lista 1: "; 
      lista.newRandomList(tipoDato, size);
      cout << "Lista 2: "; 
      lista2.newRandomList(tipoDato, size);
    }
    else if (tipoLista == 2) { // Generar manual
      cout << "Elegiste crear una listas manuales de tipo char!\n" <<"Lista 1: "; 
      lista.newManualList(tipoDato, size);
      cout << "\n";
      cout << "*IMPORTANTE:" << "Esta segunda lista sólo se usa para la sobrecarga del '='\n\n";
      cout << "Lista 2: "; 
      lista2.newManualList(tipoDato, size);
    }
    else { 
      cout << "ERROR: Introduce una opción válida (1-2)" << endl;
    }
    cout << "Listas creadas con éxito!\n" << "\n";
    lista.menuOpciones(lista, tipoDato, lista2);
  }
  else { 
    cout << "ERROR: Introduce una opción válida (1-2)" << endl;
  }
  return 0;
}; /* End main */