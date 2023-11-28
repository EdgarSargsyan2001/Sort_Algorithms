#include <iostream>
#include <cstdlib> // for rand() function
#include <time.h>

int generateRandomNumber(int min, int max)
{
  srand(time(0));
  return min + rand() % (max - min + 1);
}

int partition(int *arr, int s, int e)
{
  std::swap(arr[generateRandomNumber(s, e)], arr[e]);
  int pivot = arr[e];
  int i = s - 1;

  for (int j = s; j < e; ++j)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[e]);

  return i + 1;
}

void quickSort(int *arr, int left, int right)
{
  if (left < right)
  {
    int pivot = partition(arr, left, right);
    quickSort(arr, pivot + 1, right);
    quickSort(arr, left, pivot - 1);
  }
}

int main()
{

  int arr[10] = {88, 9, 4, 5, 6, 11, 20, 50, 40, -1};

  quickSort(arr, 0, 9);
  for (int i = 0; i < 10; ++i)
  {
    std::cout << arr[i] << " ";
  }

  return 0;
}