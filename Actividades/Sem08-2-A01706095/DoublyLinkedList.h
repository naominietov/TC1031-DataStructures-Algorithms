/* 
* Actividad: Sem08-2 Listas doblemente encadenadas
* 5 febrero 2021 11:24:52
* DoublyLinkedList.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "OutOfRangeException.h"
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList {
  private:
  Node<T> * head;
  Node<T> * tail;
  int size = 0;
  int menuOption;
  
  public:
  DoublyLinkedList();
  int getSize();
  void setSize(int);
  Node<T> * getHead();
  Node<T> * getTail();
  void setHead(Node<T>*);
  void setTail(Node<T>*);
  void printList();
  void menuOpciones(DoublyLinkedList<T> &, int, DoublyLinkedList<T> &);
  void newRandomList(int, int);
  void newManualList(int, int);
  void addFirst(T);
  void addLast(T data);
  void deleteData(T);
  bool deleteAt(int);
  T getData(int);
  void updateData(T, T);
  void updateAt(int, T);
  void findData(T);
  Node<T>* operator[](const int&);
  DoublyLinkedList<T>* operator=(const DoublyLinkedList<T>&);
  // new options
  void clear();
  void swap(T* a, T* b);
  Node<T> * lastNode(Node<T> *root);
  Node<T> * partition( Node<T>  *left,  Node<T>  *right);
  void sort(Node<T> *left, Node<T> *right);
  void duplicate();
  void deleteNode(Node<T>** , Node<T>* );
  void removeDuplicates();
};
///////////////////// util functions //////////////////////////
template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
  this->size = 0;
}
template <typename T> int DoublyLinkedList<T>::getSize() {
  return this->size;
}
template <typename T> void DoublyLinkedList<T>::setSize(int size) {
  this->size = size;
}
template <typename T> Node<T> * DoublyLinkedList<T>::getHead() {
  return this->head;
}
template <typename T> Node<T> * DoublyLinkedList<T>::getTail() {
  return this->tail;
}
template <typename T> void DoublyLinkedList<T>::setHead(Node<T> * head) {
  this->head = head;
}
template <typename T> void DoublyLinkedList<T>::setTail(Node<T> * tail) {
  this->tail = tail;
}
template <typename T> void DoublyLinkedList<T>::printList() {
  int bandera = 0;
  Node<T> * elemento = this->head;
  cout << " [";
  while (bandera < this->getSize()) {
    cout << " " << elemento->getValue() << " ";
    elemento = elemento->getNext();
    bandera++;
  }
  cout << "] ";
  cout << endl;
}
template <typename T> void DoublyLinkedList<T>::menuOpciones(DoublyLinkedList<T> &lista, int type, DoublyLinkedList<T> &lista2) {
  int opcion2, datoInputInt, nuevoDatoInt, posicionDato;
  char datoInputChar, nuevoDatoChar;
  while (menuOption != 12) {
    cout << "═════════════════════════════════════════════════════\n";
    cout << "d) Opciones disponibles para realizar: " << endl;
    cout << "\t1. Insertar un elemento\n";
    cout << "\t2. Borrar un elemento\n";
    cout << "\t3. Leer el valor de un dato (getData)\n";
    cout << "\t4. Actualizar un elemento\n";
    cout << "\t5. Encontrar un elemento dado (findData)\n";
    cout << "\t6. Leer y/o actualizar elemento ([])\n";
    cout << "\t7. Actualizar lista con base en otra lista (=)\n";
    cout << "\t8. Eliminar todos los elementos de una lista\n";
    cout << "\t9. Ordenar una lista\n";
    cout << "\t10. Duplicar cada elemento de la lista\n";
    cout << "\t11. Eliminar todos los elementos duplicados\n";
    cout << "\t12. Exit\n";
    cout << "═════════════════════════════════════════════════════\n";
    cout << "Opción: ";
    cin >> menuOption;
    if (menuOption == 1) {
      cout << "\t1. Al principio de la lista (addFirst)\n" << "\t2. Al final de la lista(addLast)\nOpción: ";
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
      cout << "\t1. Borrar un elemento dado (deleteData)\n" << "\t2. Borrar un elemento en una posición (deleteAt)\nOpción: ";
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
      cout << "\t1. Actualizar un elemento dado (updateData)\n" << "\t2. Actualizar un elemento en una posición (updateAt)\nOpción: ";
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
    else if (menuOption == 8) { // clear
      cout << "Los nodos de la lista a borrar son: " << endl;
      lista.clear(); cout << endl;
      cout << "Lista vacía:";
      lista.printList();
    }
    else if (menuOption == 9) { // sort
      cout << "La lista desordenada es: \n";
      lista.printList();
      cout << "La lista ordenada es: \n";
      lista.sort(lista.head, lista.lastNode(head));
      lista.printList();
    }
    else if (menuOption == 10) { // duplicate
      cout << "Lista original:\n";
      lista.printList();
      cout << "Lista duplicada:\n";
      lista.duplicate();
      cout<< "All nodes were duplicated successfully.\n";
    }
    else if (menuOption == 11) { //remove duplicates
      cout << "Lista original:\n";
      lista.duplicate();
      cout << "Lista sin elementos duplicados:\n";
      lista.removeDuplicates();
      lista.printList();
    }
    else if (menuOption == 12) { //EXIT
      cout << "Gracias por usar nuestra app. ¡Hasta pronto!\n";
      break;
    }
    else {
      cout << "ERROR: Por favor, introduzca una opción válida (1-8)\n";
    }
  } // End while
}
///////////////////// new lists //////////////////////////
template <typename T> void DoublyLinkedList<T>::newRandomList(int type, int sizeInt) {
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
template <typename T> void DoublyLinkedList<T>::newManualList(int type, int sizeInt) {
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
///////////////////// menu options //////////////////////////
template <typename T> void DoublyLinkedList<T>::addFirst(T value) {
  
  Node<T> *ptr = new Node<T>(value);
  if (head == nullptr && tail == nullptr) {
    head = ptr;
    tail = ptr;
  }
  ptr->setNext(head);
  ptr->setPrevious(NULL);      
  if (head != NULL) {
     head->setPrevious(ptr); 
  }
  head = ptr;
  size++;
}

template <typename T> void DoublyLinkedList<T>::addLast(T value) {
   if(this->head) { //Lista con nodos
    Node<T> * temp = head;
    while (temp->getNext()) {
      temp = temp->getNext();
    } 
    Node<T> * nuevo = new Node<T>(value,nullptr,temp);
    temp->setNext(nuevo);
    this->setTail(nuevo);
    this->size++;                     
  }
  else { //Lista sin nodos
    Node<T> * nuevo = new Node<T>(value,nullptr,nullptr);
    this->setHead(nuevo);
    this->setTail(nuevo);
    this->size++;
  }
}

template <typename T> void DoublyLinkedList<T>::deleteData(T dato) {
  Node<T> * nodo=this->head;
  Node<T> * erase;
  int bandera = 0;
  if (this->head) {
    do {
      
      if(nodo->value == dato){
          if (nodo->value == head->value) {
            this->setHead(nodo->getNext());
          }
          erase = nodo;
          nodo->getNext()->setPrevious(nullptr); 
          delete(erase);
          size-=1;
          bandera = 1;
          return;
      }
      nodo=nodo->getNext();
      if(nodo->value == dato){
          
          if (nodo->value == tail->value) {
            tail = tail->getPrevious();
          }
          erase = nodo;
          nodo->getPrevious()->setNext(erase->getNext()); 
          delete(erase);
          size-=1;
          bandera = 1;
          return;
      }
    } while(nodo!=this->head && nodo->getNext() != nullptr);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
    }
  } else { 
    cout<<"Lista vacia"<<endl;
  }

}
template <typename T> bool DoublyLinkedList<T>::deleteAt(int pos) {
  Node<T> * nodo=this->head;
  Node<T> * erase;
  int bandera = 0;
  int counter = 1;
  if (this->head) {
    do {
      if(counter == pos && nodo != nullptr){
          if (nodo->value == head->value) {
            this->setHead(nodo->getNext());
          }
          erase = nodo;
          nodo->getNext()->setPrevious(nullptr); 
          delete(erase);
          size-=1;
          bandera = 1;
          return true;
      }
      counter++;
      nodo=nodo->getNext();
      if(counter == pos && nodo != nullptr){
          
          if (nodo->value == tail->value) {
            tail = tail->getPrevious();
          }
          erase = nodo;
          nodo->getPrevious()->setNext(erase->getNext()); 
          delete(erase);
          size-=1;
          bandera = 1;
          return true;
      }
    } while(nodo!=this->head && nodo->getNext() != nullptr && counter != pos);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
    }
  } 
  else { 
    cout<<"Lista vacia"<<endl;
  }
  return false;
}
template <typename T> T DoublyLinkedList<T>::getData(int pos) {
  if(this->head) {
    Node<T> * elem=this->head;
    int bandera = 0;
    int counter = 1;
    do {
      if (counter == pos && elem != nullptr) {
        cout<<"El elemento "<<"["<<elem->getValue()<<"]"<<" se encuentra en la posicion "<<"["<<counter<<"]"<<endl;
        bandera = 1;
        return elem->getValue();
      }
      counter++;
      elem = elem->getNext();
      if (counter == pos && elem != nullptr) {
        cout<<"El elemento "<<elem->getValue()<<" se encuentra en la posicion "<<"["<<counter<<"]"<<endl;
        bandera = 1;
        return elem->getValue();
      }
    } while(elem != this->head && elem->getNext() != nullptr && counter != pos);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range"); 
    }
  } 
  else {
    throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range");
  }
  return this->head->getValue();

}
template <typename T> void DoublyLinkedList<T>::updateData(T elemento, T nuevoV) {
  Node<T> * nodo=this->head;
  int bandera = 0;
  if (this->head) {
    do {
      if(nodo->getValue()==elemento){
          nodo->setValue(nuevoV);
          bandera = 1;
          return;
      }
      nodo=nodo->getNext();
      if(nodo->getValue()==elemento){
          nodo->setValue(nuevoV);
          bandera = 1;
          return;
      }
    } while(nodo!=this->head && nodo->getNext() != nullptr);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
    }
  } else { 
    cout<<"Lista vacia"<<endl;
  }
}
template <typename T> void DoublyLinkedList<T>::updateAt(int pos, T nuevoV) {
  Node<T> * nodo=this->head;
  int bandera = 0;
  int counter = 1;
  if (this->head) {
    do {
      if(counter == pos && nodo != nullptr){
          nodo->setValue(nuevoV);
          bandera = 1;
          return;
      }
      counter++;
      nodo=nodo->getNext();
      if(counter == pos && nodo != nullptr){
          nodo->setValue(nuevoV);
          bandera = 1;
          return;
      }
    } while(nodo!=this->head && nodo->getNext() != nullptr && counter != pos);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a actualizar no se encuentra: Out_Of_Range");
    }
  } 
  else { 
    cout<<"Lista vacia"<<endl;
  }
  return;
}
template <typename T> void DoublyLinkedList<T>::findData(T value){
  if(this->head) {
    Node<T> * elem=this->head;
    int i = 1;
    int bandera = 0;
    do {
      if (elem->getValue() == value) {
        cout<<"El elemento "<<"["<<elem->getValue()<<"]"<<" se encuentra en la posicion "<<"["<<i<<"]"<<endl;
        bandera = 1;
        return;
      }
      elem = elem->getNext();
      i++;
      if (elem->getValue() == value) {
        cout<<"El elemento "<<"["<<elem->getValue()<<"]"<<" se encuentra en la posicion "<<"["<<i<<"]"<<endl;
        bandera = 1;
        return;
      }
    } while(elem != this->head && elem->getNext() != nullptr);
    if (bandera == 0) {
      throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range"); 
    }
  } 
  else {
    throw std::out_of_range("El elemento a buscar no se encuentra: Out_Of_Range");
  }
}

template <class T> Node<T>* DoublyLinkedList<T>::operator[](const int &position) {
  Node<T> *current = head;
  int counter = 1;
  if(position > getSize() || position < 1 || head == nullptr) {
    throw std::out_of_range("Out_Of_Range");
  }
  if(position == 1) {
    return current;
  }
  while(counter < position) {
    current = current->getNext();
    counter++;
  }
  return current;
}
template <class T> DoublyLinkedList<T>* DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& list) {
  Node<T>* currentList = this->head;
  Node<T>* currentInput = list.head;
  int updateN = 0;
  if (currentInput == nullptr) { 
    head = nullptr;
    tail = nullptr;
    return this;
  }
  Node<T> * elemento = this->head;
  Node<T> * elemento2 = elemento->getNext();
  int bandera = 0;
  while (bandera != 1) {
    if (elemento2->getPrevious() != nullptr && elemento2->getNext() != nullptr) {
      this->setHead(elemento->getNext());
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      
      elemento2 = elemento2->getNext();
      elemento = elemento2->getPrevious();
    }
    if (elemento2->getNext() == nullptr) {
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      elemento = elemento2;
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      bandera++;
    }
  }
  this->setHead(currentInput);
  this->setSize(list.size);
  return this;
}
// clear: elimina todos los elementos de la lista
template <typename T> void DoublyLinkedList<T>::clear() {
  Node<T> * elemento = this->head;
  Node<T> * elemento2 = elemento->getNext();
  int bandera = 0;
  while (bandera != 1) {
    if (elemento2->getPrevious() != nullptr && elemento2->getNext() != nullptr) {
      this->setHead(elemento->getNext());
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      
      elemento2 = elemento2->getNext();
      elemento = elemento2->getPrevious();
    }
    if (elemento2->getNext() == nullptr) {
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      elemento = elemento2;
      cout << "Elemento por borrar: " << elemento->getValue() << endl;
      delete(elemento);
      bandera++;
    }
  }
  this->setSize(0);
  cout<<"\nAll nodes were deleted successfully." << endl;
}
/* A utility function to swap two elements */
template <typename T> void DoublyLinkedList<T>::swap(T* a, T* b) { 
  T t = *a;
  cout << *a << endl;
  *a = *b; 
  cout << *a << endl;
  cout << endl;
  *b = t; 
}  
template <typename T> Node<T> * DoublyLinkedList<T>::lastNode(Node<T> *root) {  
  Node<T> * current = root;
  int bandera = 0;
  while (bandera < this->getSize()-1) { 
    bandera++; 
    current = current->getNext(); 
  }
  return current;
}  

template <typename T> Node<T> * DoublyLinkedList<T>::partition( Node<T>  *left,  Node<T>  *right){
  Node<T> *pivot = right;
  Node<T> *i = left->getPrevious();
  for ( Node<T> *ptr = left; ptr != right; ptr = ptr->getNext()) {
    if (ptr->value <= pivot->value)
    {
      i = (i == NULL ? left : i->getNext());
      T temp = i->value;
      i->value = ptr->value;
      ptr->value = temp;
    }
  }
  i = (i == NULL ? left : i->getNext());
  T temp = i->value;
  i->value = pivot->value;
  pivot->value = temp;
  return i;
}
template <typename T> void DoublyLinkedList<T>::sort(Node<T> *left, Node<T> *right) {
  if (right != NULL && left != right && left != right->getNext())
  {
    Node<T> *p = partition(left, right);
    sort(left, p->getPrevious());
    sort(p->getNext(), right);
  }
}
// duplicate
template <typename T> void DoublyLinkedList<T>::duplicate() {
  for (auto elemento = this->head; elemento; elemento = elemento->getNext()) {
    elemento->setNext(new Node<T>(elemento->value, elemento->getNext(), elemento));
    elemento = elemento->getNext(); 
    size++;
  }
  this->printList();
}

template <typename T> void DoublyLinkedList<T>::deleteNode(Node<T>** head_ref, Node<T>* del) {
  if (*head_ref == NULL || del == NULL) {
    return;
  }
  if (*head_ref == del) {
    *head_ref = del->getNext();
  }
  if (del->getNext() != NULL) {
    del->next->prev = del->prev;
    
  }
  if (del->getPrevious() != NULL) {
    del->prev->next = del->next;
  }
  free(del);
  size--;
}

// remove duplicates
template <typename T> void DoublyLinkedList<T>::removeDuplicates() {
  Node<T> ** elemento = &(this->head);
  Node<T> *ptr1, *ptr2;
  if ((*elemento) == NULL || (*elemento)->getNext() == NULL) {
    return;
  }
  for (ptr1 = *elemento; ptr1 != NULL; ptr1 = ptr1->getNext()) {
    ptr2 = ptr1->getNext();
    while (ptr2 != NULL) {
      if (ptr1->value == ptr2->value) {
        Node<T>* next = ptr2->getNext();
        deleteNode(elemento, ptr2);
        ptr2 = next;
      }
      else {
        ptr2 = ptr2->getNext();
      }
    }
  }
}

#endif /* DoublyLinkedList.h */