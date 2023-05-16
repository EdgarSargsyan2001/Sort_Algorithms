#include <iostream>
using namespace std;


void merge(int arr[], int l, int m, int r) {
  const int n1 = m - l + 1;
  const int n2 = r - m;
  int *L = new int[n1];
  int *R = new int[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[m + i + 1];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }

  delete[] L;
  delete[] R;
}

void mergeSort(int arr[], int l, int r) {

  if (l < r) {
    int m = (r + l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  const int size = 7;
  int arr[size] = {55, 1, 0, 88, 2, 6, 33};
  printArr(arr, size);
  mergeSort(arr, 0, size - 1);
  cout << endl;
  printArr(arr, size);
}