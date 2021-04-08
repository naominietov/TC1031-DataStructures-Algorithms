/* 
* Actividad: Sem08-2 Listas doblemente encadenadas
* 5 febrero 2021 11:24:52
* Node.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
*/

#ifndef Node_h
#define Node_h

template <class T>
class Node {
  private:
  //T value;
  
  public:
  Node<T> * next;
  Node<T> * prev;
  T value;
  Node();
  Node(T val);
  Node(T, Node<T>*, Node<T>*);
  T getValue();
  void setValue(T);
  void setNext();
  Node<T> * getNext();
  void setNext(Node<T>*);
  Node<T> * getPrevious();
  void setPrevious(Node<T>*);
};

template<class T>
Node<T>::Node(T value){
  this->value = value;
  this->next = nullptr;
  this->prev = nullptr;
}

template <typename T>
Node<T>::Node(){
  this->value;
  this->next = nullptr;
  this->prev = nullptr;
}

template <typename T>
Node<T>::Node(T value, Node<T> * next, Node<T> * prev){
  this->value = value;
  this->next = next;
  this->prev = prev;
}

template <typename T>
T Node<T>::getValue() {
  return this->value;
}

template <typename T>
void Node<T>::setValue(T value) {
  this->value = value;
}

template <typename T>
Node<T> * Node<T>::getNext() {
  return this->next;
}

template <typename T>
void Node<T>::setNext(Node<T> * next) {
  this->next = next;
}

template <typename T>
Node<T> * Node<T>::getPrevious() {
  return this->prev;
}

template <typename T>
void Node<T>::setPrevious(Node<T> * prev) {
  this->prev = prev;
}

#endif /* Node_h */