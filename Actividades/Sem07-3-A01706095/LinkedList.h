/* 
* Actividad: Sem07-1 Listas encadenadas
* 25 marzo 2021 11:50:52
* LinkedList.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/

#ifndef LinkedList_h
#define LinkedList_h

#include "OutOfRangeException.h"
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
  private:
  Node<T> * head;
  int size = 0;
  int menuOption;
  
  public:
  // utility functions
  LinkedList();
  int getSize();
  void setSize(int);
  Node<T> * getHead();
  void setHead(Node<T>*);
  void menuOpciones(LinkedList<T> &, int, LinkedList<T> &);
  // generate new list functions
  void newRandomList(int, int);
  void newManualList(int, int);
  // menu options
  void addFirst(T);
  void addLast(T);
  void printList();
  void findData(T);
  void updateData(T, T);
  void deleteData(T);
  T getData(int);
  void addEmptyList(T); 
  bool deleteAt(int);
  void updateAt(int, T);
  Node<T>* operator[](const int&);
  LinkedList<T>* operator=(const LinkedList<T>&);
};

template <typename T>
void LinkedList<T>::menuOpciones(LinkedList<T> &lista, int type, LinkedList<T> &lista2) {
  int opcion2, datoInputInt, nuevoDatoInt, posicionDato;
  char datoInputChar, nuevoDatoChar;
  while (menuOption != 8) {
    cout << "═════════════════════════════════════════════════════\n";
    cout << "d) Opciones disponibles para realizar: " << endl;
    cout << "\t1. Insertar un elemento\n";
    cout << "\t2. Borrar un elemento\n";
    cout << "\t3. Leer el valor de un dato (getData)\n";
    cout << "\t4. Actualizar un elemento\n";
    cout << "\t5. Encontrar un elemento dado (findData)\n";
    cout << "\t6. Leer y/o actualizar elemento (uso [])\n";
    cout << "\t7. Actualizar lista con base en otra lista (uso =)\n";
    cout << "\t8. Exit\n";
    cout << "═════════════════════════════════════════════════════\n";
    cout << "Opción: ";
    cin >> menuOption;
    if (menuOption == 1) {
      cout << "\t1. Al principio de la lista (addFirst)\n\t2. Al final de la lista (addLast)\nOpción: ";
      cin >> opcion2;
      cout << "Introduzca el valor del elemento a insertar: ";
      if (opcion2 == 1) { // ADD FIRST
        if (type == 1) { //int
          cin >> datoInputInt;
          lista.addFirst(datoInputInt);
        }
        else if (type == 2) { // char
          cin >> datoInputChar;
          lista.addFirst(datoInputChar);
        }
      }
      else if (opcion2 == 2) { // ADD LAST
        if (type == 1) { //int
          cin >> datoInputInt;
          lista.addLast(datoInputInt);
        }
        else if (type == 2) { // char
          cin >> datoInputChar;
          lista.addLast(datoInputChar);
        }
      }
      cout << "Los elementos de la lista actual son: \n";
      lista.printList();
    } 

    else if (menuOption == 2) { //DELETE 
      cout << "\t1. Borrar un elemento dado (deleteData)\n\t2. Borrar un elemento en una posición (deleteAt)\nOpción: ";
      cin >> opcion2;
      if (opcion2 == 1) { // DELETE DATA
      cout << "Introduzca el valor del elemento a borrar: ";
        if (type == 1) { //int
          cin >> datoInputInt;
          lista.deleteData(datoInputInt);
        }
        else if (type == 2) { // char
          cin >> datoInputChar;
          lista.deleteData(datoInputChar);
        }
      }
      else if (opcion2 == 2) { // DELETE AT
      cout << "Introduzca la posición del elemento a borrar: ";
      cin >> posicionDato;
      lista.deleteAt(posicionDato);
      }
      cout << "Los elementos de la lista actual son: \n";
      lista.printList();
    }

    else if (menuOption == 3) { // READ
      cout << "Introduzca la posición del elemento que desea leer: ";
      cin >> posicionDato;
      lista.getData(posicionDato);
    }

    else if (menuOption == 4) { // UPDATE 
      cout << "\t1. Actualizar un elemento dado (updateData)\n\t2. Actualizar un elemento en una posición (updateAt)\nOpción: ";
      cin >> opcion2; 
      if (opcion2 == 1) { //updateData
      cout << "Introduzca el valor elemento a actualizar: ";
        if (type == 1) { //int
          cin >> datoInputInt;
          cout << "Introduzca el nuevo valor del elemento: ";
          cin >> nuevoDatoInt;
          lista.updateData(datoInputInt, nuevoDatoInt);
        }
        else if (type == 2) { // char
          cin >> datoInputChar;
          cout << "Introduzca el nuevo valor del elemento: ";
          cin >> nuevoDatoChar;
          lista.updateData(datoInputChar, nuevoDatoChar);
        }
      }
      else if (opcion2 == 2) { //updateAt
      cout << "Introduzca la posición del elemento a actualizar: ";
      cin >> posicionDato;
        if (type == 1) { //int
          cout << "Introduzca el nuevo valor del elemento: ";
          cin >> nuevoDatoInt;
          lista.updateAt(posicionDato, nuevoDatoInt);
        }
        else if (type == 2) { // char
          cout << "Introduzca el nuevo valor del elemento: ";
          cin >> nuevoDatoChar;
          lista.updateAt(posicionDato, nuevoDatoChar);
        }
      }
      cout << "Los elementos de la lista actual son: \n";
      lista.printList();
    }
    else if (menuOption == 5) { // FIND 
      cout << "Introduzca el valor del elemento a buscar: ";
      if (type == 1) {
        cin >> nuevoDatoInt;
        lista.findData(nuevoDatoInt);
      }
      else if (type == 2) {
        cin >> nuevoDatoChar;
        lista.findData(nuevoDatoChar);
      }
    }
    else if (menuOption == 6) { // Sobrecarga []
      cout << "Introduzca la posición del elemento a actualizar: ";
      cin >> posicionDato;
      cout << "Introduzca el valor del nuevo elemento: ";
      if (type == 1) {
        cin >> nuevoDatoInt;
        lista[posicionDato]->setValue(nuevoDatoInt);
      }
      else if (type == 2) {
        cin >> nuevoDatoChar;
        lista[posicionDato]->setValue(nuevoDatoChar);
      }
      cout << "Los elementos de la lista actual son: \n";
      lista.printList();
    }
    else if (menuOption == 7) { // Sobrecarga =
      cout << "Lista 1: ";
      lista.printList();
      cout << "Lista 2: ";
      lista2.printList();
      lista = lista2;
      cout << "Nueva lista 1: ";
      lista.printList();
    }
    else if (menuOption == 8) {
      cout << "Gracias por usar nuestra app. ¡Hasta pronto!\n";
      break;
    }
    else {
      cout << "ERROR: Por favor, introduzca una opción válida (1-8)\n";
    }
  } // End while
} // End menuOpciones()

template <typename T>
void LinkedList<T>::newRandomList(int type, int sizeInt) {
  if (type == 1) {
    for (int i = 0; i < sizeInt; i++) {
      int datoInt = rand() % 100 + 1;
      this->addLast(datoInt);
    }
  }
  else if (type == 2) {
    for (int i = 0; i < sizeInt; i++) {
      char datoChar = rand() % 26 + 'A';
      this->addLast(datoChar);
    }
  }
  this->printList();
}

template <typename T>
void LinkedList<T>::newManualList(int type, int sizeInt) {
  if (type == 1) {
    cout << "Introduzca los valores a insertar: " << endl;
    for (int i = 0; i < sizeInt; i++) {  
      int datoInt; 
      cout << "Dato[" << i+1 << "]: ";
      cin >> datoInt;
      this->addLast(datoInt);
    }
  }
  else if (type == 2) {
    cout << "Introduzca los valores a insertar: " << endl;
    for (int i = 0; i < sizeInt; i++) { 
      char datoChar; 
      cout << "Dato[" << i+1 << "]: "; 
      cin >> datoChar;
      this->addLast(datoChar);
    }
  }
  this->printList();
}

template <typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  this->size = 0;
}
template <typename T>
int LinkedList<T>::getSize() {
  return this->size;
}
template <typename T>
void LinkedList<T>::setSize(int size) {
  this->size = size;
}
template <typename T>
Node<T> * LinkedList<T>::getHead() {
  return this->head;
}
template <typename T>
void LinkedList<T>::setHead(Node<T> * head) {
  this->head = head;
}
template <typename T>
T LinkedList<T>::getData(int pos) {
  Node<T> * nodo=this->head;
  T value;
  int bandera = 0;
  if (this->head) {
    do {
      bandera = bandera + 1;
      if (bandera == pos){
        value = nodo->getValue();
          cout << "El elemento que se encuentra en la posicion "<< "[" << pos << "]" << " es " << value <<endl;
        return value;
      }
      nodo = nodo->getNext();
    } while (bandera != pos);
  } else if (pos < this->getSize()){ 
    throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range");
  }
  return value;
}

template <typename T>
bool LinkedList<T>::deleteAt(int pos) {
  Node<T> *current, *erase;
  current = this->head;
  int bandera = 1;
  if (pos == 1) {
    this->setHead(current->getNext());
    delete(current);
    size-=1;
    return true;
  }
  while (bandera != pos) {
    bandera++;
    current = current->getNext();
  }
  erase = current;
  current->setNext(erase->getNext()); 
  cout << "Valor a borrar: " << erase->getValue()<< endl;
  delete(erase);
  size-=1;
  if (pos > this->getSize()+1 || pos < this->getSize()+1) { 
    throw std::out_of_range("El elemento a eliminar no se encuentra: Out_Of_Range");
    return false;
  }
  return true;
}


template <typename T>
void LinkedList<T>::updateAt(int pos, T valorN) {
  Node<T> * nodo = this->head;
  T value;
  int bandera = 0;
  if (this->head) {
    do {
      bandera++;
      if (bandera == pos) {
        nodo->setValue(valorN);
      }
      nodo = nodo->getNext();
    } while(bandera != pos);
  } 
  else if (pos < this->getSize()) { 
    throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
  }
}

template <typename T>
void LinkedList<T>::addEmptyList(T value) {
  Node<T> * nuevo = new Node<T>(value, nullptr, nullptr);
  nuevo->setNext(nuevo);
  nuevo->setPrevious(nuevo);
  this->head=nuevo;
}

template <typename T>
void LinkedList<T>::addFirst(T value) {
  if(this->head) { //Lista con nodos
    Node<T> * nuevo = new Node<T>(value,this->head,nullptr);
    head->setPrevious(nuevo);
    this->setHead(nuevo);
    this->size++;                     
  }
  else { //Lista sin nodos
    Node<T> * nuevo = new Node<T>(value,nullptr,nullptr);
    this->setHead(nuevo);
    this->size++;
  }
}

template <typename T>
void LinkedList<T>::addLast(T value) {
  if(this->head) { //Lista con nodos
    Node<T> * temp = head;
    while (temp->getNext()) {
      temp = temp->getNext();
    } 
    Node<T> * nuevo = new Node<T>(value,nullptr,temp);
    temp->setNext(nuevo);
    this->size++;                     
  }
  else { //Lista sin nodos
    Node<T> * nuevo = new Node<T>(value,nullptr,nullptr);
    this->setHead(nuevo);
    this->size++;
  }
}

template <typename T>
void LinkedList<T>::printList(){
  Node<T> * elemento = this->head;
  int bandera = 0;
  cout << " [ ";
  while (bandera < this->getSize()) {
    cout << " " << elemento->getValue() << " ";
    elemento = elemento->getNext();
    bandera++;
  }
  cout << " ]";
  cout << endl;
}

template <typename T>
void LinkedList<T>::findData(T value){
  Node<T> * elem=this->head;
  int bandera = 0;
  int i = 1;
  if(this->head) {
    while (elem != nullptr) {
      if (elem->getValue() == value) {
        cout<<"El elemento "<<elem->getValue()<<" se encuentra en la posicion "<<"["<<i<<"]"<<endl;
        bandera = 1;
      }
      elem = elem->getNext();
      i++;
    }
    if (bandera == 0) {
      throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range");
    }
  }
  else {
    cout<<"Lista vacía"<<endl;
  }
}

template <typename T>
void LinkedList<T>::updateData(T elemento, T nuevoV){
  Node<T> * nodo=this->head;
  int bandera = 0;
  if (this->head) {
    do {
      if(nodo->getValue()==elemento) {
        nodo->setValue(nuevoV);
        bandera = 1;
      }
      nodo=nodo->getNext();
    } while(nodo != nullptr);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
    }
  } else { 
    cout<<"Lista vacia"<<endl;
  }
}

template <typename T>
void LinkedList<T>::deleteData(T value){
  Node<T> *current, *erase;
  current = this->head;
  if(current->getValue() == value) {
    this->setHead(current->getNext());
    delete(current);
    size-=1;
    return;
  }
  
  while(current->getNext() != nullptr && (current->getNext())->getValue() != value) {
    current = current->getNext();
  }
  erase = current->getNext();
  current->setNext(erase->getNext()); 
  delete(erase);
  size-=1;
  return;
}

template <class T> 
Node<T>* LinkedList<T>::operator[](const int &position){
  Node<T> *current = head;
  int counter = 1;
  if(position > getSize() || position < 1 || head == nullptr){
    throw std::out_of_range("Out_Of_Range");
  }
  if(position == 1){
    return current;
  }
  while(counter < position){
    current = current->getNext();
    counter++;
  }
  return current;
}

template <class T> 
LinkedList<T>* LinkedList<T>::operator=(const LinkedList<T>& list){
  Node<T>* currentList = this->head;
  Node<T>* currentInput = list.head;
  int updateN = 0;
  if (currentInput == nullptr) { 
    head = nullptr;
    return this;
  }
  
  Node<T> * elemento = this->head;
  Node<T> * elemento2 = elemento->getNext();
  int bandera = 0;
  
  while (bandera < this->getSize()) {
    this->setHead(elemento2);
    cout << "Elemento por borrar: " << elemento->getValue() << endl;
    delete(elemento);
    elemento = elemento2;
    if (elemento2->getNext() != nullptr) {
      elemento2 = elemento2->getNext();
    }
    bandera++;
  }

  this->setHead(currentInput);
  
  this->setSize(list.size);
  return this;
}
#endif /* LinkedList.h */