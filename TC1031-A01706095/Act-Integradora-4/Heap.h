/*
* Sem10-2 Árbol Heap: Fila priorizada
* 19/04/2021 19:22:37
* Heap.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramses Herrera Santiago
*/
#ifndef Heap_h
#define Heap_h
#include <vector>

using namespace std;

template <class T>
class Heap {
  public:
  vector<T> heapLog;
  T H[5000];
  int Size;
  // Methods
  Heap();
  bool empty();
  void getSize();
  int parent(int);
  int leftChild(int);
  int rightChild(int);
  void shiftUp(int);
  void shiftDown(int);
  void push(T); 
  T extractMax();
  void changePriority(int, T);
  T top();
  void pop(int);
  void heapify(vector<T> &, int, int);
  void heapSort(vector<T> &, int);
};

template <typename T> 
Heap<T>::Heap(){
  Size = -1;
}

template <typename T> 
void Heap<T>::heapify(vector<T> &arr, int n, int i) {
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2;

	if (l < n && arr[l].size > arr[largest].size)
		largest = l;
    
	if (r < n && arr[r].size > arr[largest].size)
		largest = r;

	if (largest != i) {
    T t = arr[i];
    arr[i] = arr[largest];
    arr[largest] = t;
		heapify(arr, n, largest);
	}
}

template <typename T> 
void Heap<T>::heapSort(vector<T> &arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
    T t = arr[0];
    arr[0] = arr[i];
    arr[i] = t;
		heapify(arr, i, 0);
	}
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
int Heap<T>::parent(int i) {
  return (i - 1) / 2;
}

template <typename T> 
int Heap<T>::leftChild(int i) {
  return ((2 * i) + 1);
}

template <typename T> 
int Heap<T>::rightChild(int i) {
  return ((2 * i) + 2);
}

template <typename T> 
void Heap<T>::shiftUp(int i) {
  while (i > 0 && H[parent(i)].size < H[i].size) {
    T t = H[parent(i)];
    H[parent(i)] = H[i];
    H[i] = t;
    i = parent(i);
  }
}

template <typename T> 
void Heap<T>::shiftDown(int i) {
  int maxIndex = i;
  int l = leftChild(i);
  if (l <= Size && H[l].size > H[maxIndex].size) {
    maxIndex = l;
  }
  int r = rightChild(i);
  if (r <= Size && H[r].size > H[maxIndex].size) {
    maxIndex = r;
  }
  if (i != maxIndex) {
    T t = H[i];
    H[i] = H[maxIndex];
    H[maxIndex] = t;
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
  H[i] = this->top();
  shiftUp(i);
  extractMax();
}

#endif /* Heap_h */