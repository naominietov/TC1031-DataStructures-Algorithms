/* 
* Actividad: Sem07-1 Listas encadenadas
* 25 marzo 2021 11:50:52
* Node.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera
*/
#ifndef Node_h
#define Node_h

template <class T>
class Node {
  private:
  T value;
  Node<T> * next;
  Node<T> * prev;

  public:
  T getValue();
  void setValue(T);
  void setNext();
  Node<T> * getNext();
  void setNext(Node<T>*);
  Node<T> * getPrevious();
  void setPrevious(Node<T>*);
  Node(T, Node<T>*, Node<T>*);
  Node();
};

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

template <typename T>
Node<T>::Node(T value, Node<T> * next, Node<T> * prev){
  this->value = value;
  this->next = next;
  this->prev = prev;
}
template <typename T>
Node<T>::Node(){
  this->value;
  this->next = nullptr;
  this->prev = nullptr;
}

#endif /* Node_h */