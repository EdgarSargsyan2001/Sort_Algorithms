#include <iostream>

void insertion(int *arr, int n) // O(n^2)
{
  for (int i = 1; i < n; ++i)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  int arr[] = {6, -1, 9, 0};

  int N = sizeof(arr) / sizeof(arr[0]);
  insertion(arr, N);
}