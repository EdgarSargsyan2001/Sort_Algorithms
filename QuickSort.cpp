#include <iostream>

int partition(int arr[], int start, int end) {
  int pivot = arr[end];
  int j = start - 1;
  
  for (int i = start; i < end; ++i) {
    if (arr[i] < pivot) {
      j++;
      std::swap(arr[j], arr[i]);
    }
  }
  
  std::swap(arr[j + 1], arr[end]);
  return j + 1;
}

void quickSort(int arr[], int start, int end) {

  if (start < end) {
    int pivot = partition(arr, start, end);
    quickSort(arr, pivot + 1, end);
    quickSort(arr, start, pivot - 1);
  }
}

int main() {

  int arr[10] = {88, 9, 4, 5, 6, 11, 20, 50, 40,-1};

  quickSort(arr, 0, 9);
  for (int i = 0; i < 10; ++i) {
    std::cout << arr[i] << " ";
  }

  return 0;
}