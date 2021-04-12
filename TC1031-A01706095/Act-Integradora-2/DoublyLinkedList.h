/* 
* Actividad: Sem08-2 Listas doblemente encadenadas
* 5 febrero 2021 11:24:52
* DoublyLinkedList.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/
#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Node.h"
#include "Data.h"
#include <iostream>

template <class T> 
class DoublyLinkedList {
  private:
  Node<T> * head;
  Node<T> * tail;
  int size = 0;
  
  public:
  DoublyLinkedList();
  int getSize();
  void setSize(int);
  Node<T> * getHead();
  Node<T> * getTail();
  void setHead(Node<T>*);
  void setTail(Node<T>*);
  void printList();
  void addLast(T);
  int findData(T);
  Node<T> * partition(Node<T>*, Node<T>*);
  Node<T>* operator[](const int&);
  void quickSortIterative(DoublyLinkedList<T> &,int,int);
  int binarySearchSorted(DoublyLinkedList<T> &,int,int);
};

/* The following lines are constructors, getters and setters of the class
primarily used as utility functions in other class methods */
template <typename T> 
DoublyLinkedList<T>::DoublyLinkedList() {
  Node<T>* primero;
  this->head = primero;
  this->tail = primero;
  this->size = 0;
}

template <typename T> 
int DoublyLinkedList<T>::getSize() {
  return this->size;
}

template <typename T> 
void DoublyLinkedList<T>::setSize(int size) {
  this->size = size;
}

template <typename T> 
Node<T> * DoublyLinkedList<T>::getHead() {
  return this->head;
}

template <typename T> 
Node<T> * DoublyLinkedList<T>::getTail() {
  return this->tail;
}

template <typename T> 
void DoublyLinkedList<T>::setHead(Node<T> * head) {
  this->head = head;
}

template <typename T> 
void DoublyLinkedList<T>::setTail(Node<T> * tail) {
  this->tail = tail;
}

/* This function helps to print the Linked List, it doesnt 
receive any parameters and it returns the printed list */

template <typename T> 
void DoublyLinkedList<T>::printList() {
  int bandera = 0;
  Node<T> * elemento = this->head;
  std::cout << " [";
  while (bandera < this->getSize()) {
    std::cout << " " << elemento->getValue() << " ";
    elemento = elemento->getNext();
    bandera++;
  }
  std::cout << "] ";
  std::cout << std::endl;
}

/* This function add and element at the end in the Linked List, 
it receives the value to insert and it add it to the linked list
The complexity of this function is O(1) because we have a tail
in other case it would be O(n) */ 

template <typename T> 
void DoublyLinkedList<T>::addLast(T value) {
  if(size == 0) {
    Node<T> * head = new Node<T>(value);
    this->setHead(head);
    head->setNext(NULL);
    tail = head;
    size++;
  }
  else {
    Node<T> *ptr = new Node<T>(value);
    tail->setNext(ptr);
    ptr->setPrevious(tail);
    this->setTail(ptr);
    size++;
  }
}

/* This function look up for one data value in the linked list
it receives the type T value and it returns the position in the 
linked list where it is located, else it throws and exception */

template <typename T> int DoublyLinkedList<T>::findData(T value){
  int i = 1;
  if (this->head) {
    Node<T> * elem = this->head;
    int bandera = 0;
    do {
      if (elem->getValue() == value) {
        bandera = 1;
        return i;
      }
      elem = elem->getNext();
      i++;
      if (elem->getValue() == value) {
        bandera = 1;
        return i;
      }
    } while(elem != this->head && elem->getNext() != nullptr);
    if (bandera == 0) {
      throw std::out_of_range("Out_Of_Range"); 
    }
    return i;
  }
  return i;
}

/* This function is part of the quickSort function and it
basically takes the last element to its correct position in 
the sorted array, then place all the smaller elements than 
pivot in the left and the greater elements in the right 

It receives a Data type vector, low and high integers are the
starting and ending index, then it returns the partitioning 
index */

template <typename T> 
Node<T> * DoublyLinkedList<T>::partition(Node<T>  *left, Node<T>  *right) {
  Node<T> *pivot = right;
  Node<T> *i = left->getPrevious();
  
  for ( Node<T> *ptr = left; ptr != right ; ptr = ptr->getNext() ) {
    if (ptr->value->getKey() <= pivot->value->getKey()) {
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
/* This function is the overload of the [] operator to look
up for data in one position of the LinkedList. It is an
utility function */

template <class T> Node<T>* DoublyLinkedList<T>::operator[](const int &position) {
  Node<T> *current = this->head;
  int counter = 1;
  if(position > this->getSize() || position < 1 || head == nullptr) {
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

/* This is the quickSort algorithm, it basically helps us to
sort the "bitacora.txt" file by date and time. This algorithm 
has an average time complexity of O(n log n) and worst space 
complexity of O(log n)
See reference: https://www.bigocheatsheet.com/ 
It receives a data type vector, start and end index and finally
it returns the sorted vector */

template <typename T> 
void DoublyLinkedList<T>::quickSortIterative(DoublyLinkedList<T> &log, int l, int h) {
  int stack[h - l + 1];
  int top = -1;
  stack[++top] = l;
  stack[++top] = h;

  while (top >= 0) {
    h = stack[top--];
    l = stack[top--];
  
    Node<T> * left, *right;
    left = log[l];
    right = log[h];
    Node<T> * p = partition(left, right);
    T pValue = p->value;
    int pos = this->findData(pValue);
  
    if (pos - 1 > l) {
      stack[++top] = l;
      stack[++top] = pos - 1;
    }

    if (pos + 1 < h) {
      stack[++top] = pos + 1;
      stack[++top] = h;
    }
  }
}

/* This function helps us to search the starting and ending
date of the query so that we can compare their keys later.
It receives a T type vector and the requested search value, 
then it returns the position of that value. O(log n) complexity */

template <class T>
int DoublyLinkedList<T>::binarySearchSorted(DoublyLinkedList<T> &log, int value, int lim) {  
  int l = 1;
  int r = this->getSize();
  int m, mValue;
  Node<T> * current = this->head;

  while (l <= r) {
    m = (int) (l + r)/2;
    if (value == log[m]->value->getKey()) {
      return m;
    }
    else if (value < log[m]->value->getKey()) {
      r = m-1;
    }
    else {
      l = m+1;
    }
  }
  if (value < log[m]->value->getKey() && lim == 1) {
    return m-1;
  }
  else if (value > log[m]->value->getKey() && lim == 0) {
    return m+1;
  }
  return m;
}
#endif /* DoublyLinkedList.h */