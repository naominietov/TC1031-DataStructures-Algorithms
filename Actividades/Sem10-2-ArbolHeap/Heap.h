/*
* Sem10-2 Árbol Heap: Fila priorizada
* 19/04/2021 19:22:37
* Heap.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/
#ifndef Heap_h
#define Heap_h

using namespace std;

template <class T>
class Heap {
  public:
  T H[50];
  int Size;
  // Métodos
  Heap();
  void swap(T* , T* ); 
  bool empty(); //empty
  void getSize(); //size
  T parent(int);
  T leftChild(int);
  T rightChild(int);
  void shiftUp(int);
  void shiftDown(int);
  void push(T); //push
  T extractMax();
  void changePriority(int, T);
  T top();  //top
  void pop(int); //pop
};

template <typename T> 
Heap<T>::Heap(){
  Size = -1;
}

template <typename T> 
void Heap<T>::swap(T* a, T* b) {
  T t = *a;
  *a = *b;
  *b = t;
}

template <typename T> 
bool Heap<T>::empty() {
  if (Size < 0) {
    return true;
  }
  return false;
}

template <typename T> 
void Heap<T>::getSize() {
  cout << Size << "\n";
} 

template <typename T> 
T Heap<T>::parent(int i) {
  return (i - 1) / 2;
}

template <typename T> 
T Heap<T>::leftChild(int i) {
  return ((2 * i) + 1);
}

template <typename T> 
T Heap<T>::rightChild(int i) {
  return ((2 * i) + 2);
}

template <typename T> 
void Heap<T>::shiftUp(int i) {
  while (i > 0 && H[parent(i)] < H[i]) {
    swap(&H[parent(i)], &H[i]);
    i = parent(i);
  }
}

template <typename T> 
void Heap<T>::shiftDown(int i) {
  int maxIndex = i;
  int l = leftChild(i);
  if (l <= Size && H[l] > H[maxIndex]) {
    maxIndex = l;
  }
  int r = rightChild(i);
  if (r <= Size && H[r] > H[maxIndex]) {
    maxIndex = r;
  }
  if (i != maxIndex) {
    swap(&H[i], &H[maxIndex]);
    shiftDown(maxIndex);
  }
}

template <typename T> 
void Heap<T>::push(T p) {
  Size = Size + 1;
  H[Size] = p;
  shiftUp(Size);
}
 
template <typename T> 
T Heap<T>::extractMax() {
  T result = H[0];
  H[0] = H[Size];
  Size = Size - 1;
  shiftDown(0);
  return result;
}

template <typename T> 
void Heap<T>::changePriority(int i, T p) {
  T oldp = H[i];
  H[i] = p;
  if (p > oldp) {
    shiftUp(i);
  }
  else {
    shiftDown(i);
  }
}

template <typename T> 
T Heap<T>::top() {
  return H[0];
}

template <typename T> 
void Heap<T>::pop(int i) {
  H[i] = top() + 1;
  shiftUp(i);
  extractMax();
}

#endif // Heap_h