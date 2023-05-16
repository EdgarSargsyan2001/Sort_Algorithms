#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    bool swapper = false;
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapper = true;
      }
    }
    if (!swapper)
      break;
  }
}

void printArray(int p[], int size) {

  for (int i = 0; i < size; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}

int main() {
  const int N = 5;
  int arr[N] = {4, 8, 9, 7, 2};
  printArray(arr, N);
  bubbleSort(arr, N);
  printArray(arr, N);
}