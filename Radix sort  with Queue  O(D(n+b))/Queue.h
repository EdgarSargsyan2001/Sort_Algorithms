#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename T> class Queue {
public:
  Queue(int n);
  Queue(const Queue &q);
  ~Queue();
  Queue &operator=(const Queue &q);
  bool empty();
  T fromt();
  void enqueue(T obj);
  void dequeue();
  void print_queue();

private:
  int size;
  int front_index;
  int rear_index;
  int capacity;
  T *data_array;
};


template <typename T>
Queue<T>::Queue(int n) : size(0), front_index(0), rear_index(-1) {
  if (n <= 0) {
    n = 100;
  }
  capacity = n;
  data_array = new T[capacity];
}
template <typename T> Queue<T>::Queue(const Queue &q) {
  capacity = q.capacity;
  size = q.size;
  front_index = 0;
  rear_index = size - 1;
  data_array = new T[capacity];
  
  int k = 0;
  int i = q.front_index;
  while (i != q.rear_index) {
    data_array[k++] = q.data_array[i];
    i = (i + 1) % q.capacity;
  }
  data_array[k++] = q.data_array[i];
}

template <typename T> Queue<T>::~Queue() { delete[] data_array; }

template <typename T> Queue<T> &Queue<T>::operator=(const Queue &q) {
  if (this == &q) {
    return *this;
  }
  capacity = q.capacity;
  delete[] data_array;
  size = q.size;
  front_index = 0;
  rear_index = size - 1;
  data_array = new T[capacity];
  
  int k = 0;
  int i = q.front_index;
  while (i != q.rear_index) {
    data_array[k++] = q.data_array[i];
    i = (i + 1) % q.capacity;
  }
  data_array[k++] = q.data_array[i];
  return *this;
}

template <typename T> bool Queue<T>::empty() { return size == 0; }

template <typename T> T Queue<T>::fromt() { return data_array[front_index]; }

template <typename T> void Queue<T>::enqueue(T obj) {
  if (size == capacity) {
    throw(1);
  }
  ++rear_index;
  if (rear_index == capacity) {
    rear_index = 0;
  }
  data_array[rear_index] = obj;
  size++;
}

template <typename T> void Queue<T>::dequeue() {
  if (empty()) {
    // throw(2);
    return;
  }
  size--;
  ++front_index;
  if (front_index == capacity) {
    front_index = 0;
  }
}

template <typename T> void Queue<T>::print_queue() {
  for (int i = front_index; i <= rear_index; i++) {
    std::cout<<data_array[i]<<" ";
    
  }
  std::cout<<"\n";
}

#endif