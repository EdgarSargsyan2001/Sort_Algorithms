#include <iostream>

void bubble(int *arr, int n) // O(n^2)
{
  for (int i = 0; i < n; ++i)
  {
    bool isSwaped = false;
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j + 1], arr[j]);
        isSwaped = true;
      }
    }
    if (!isSwaped)
      break;
  }
}

void printArray(int p[], int size)
{

  for (int i = 0; i < size; i++)
  {
    std::cout << p[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  const int N = 5;
  int arr[N] = {4, 8, 9, 7, 2};
  printArray(arr, N);
  bubble(arr, N);
  printArray(arr, N);
}