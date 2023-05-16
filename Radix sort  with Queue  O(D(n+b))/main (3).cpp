#include <iostream>
using namespace std;
#include "Queue.h"

int oneDigit(int x, int d) {
  int lastDig = x / d % 10;
  if ((x / d) == 0) {
    return -1;
  }
  return lastDig;
}

int main() {
  const int N = 1000;
  int arr[N];
  Queue<int> *Qarr[10];
  bool isFull[10] = {false};

  for (int i = 0; i < N; i++) {
    arr[i] = 0 + rand() % N;
    cout << arr[i] << " ";
  }
  cout << endl;

  int d = 1;
  while (1) {
    int breakCount = 0;
    for (int i = 0; i < N; i++) {
      int QPlase = oneDigit(arr[i], d);
      if (QPlase == -1) {
        breakCount++;
        if (!isFull[0]) {
          Qarr[0] = new Queue<int>(N);
          isFull[0] = true;
        }
        Qarr[0]->enqueue(arr[i]);
        continue;
      }
      if (!isFull[QPlase]) {
        Qarr[QPlase] = new Queue<int>(N);
        isFull[QPlase] = true;
      }
      Qarr[QPlase]->enqueue(arr[i]);
    }
    if (breakCount == N)
      break;

    int k = 0;
    for (int i = 0; i < 10; i++) {
      if (!isFull[i]) {
        continue;
      }
      while (!Qarr[i]->empty()) {
        arr[k++] = Qarr[i]->fromt();
        Qarr[i]->dequeue();
      }
    }
    d *= 10;
  }

  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }

  for (int i = 0; i < 10; i++) {
    if (isFull[i]) {
      delete Qarr[i];
    }
  }
}