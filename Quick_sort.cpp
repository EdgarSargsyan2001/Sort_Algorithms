#include <iostream>
#include <cstdlib> // for rand() function
#include <vector>
#include <time.h>

int generateRandomNumber(int min, int max)
{
  srand(time(0));
  return min + rand() % (max - min + 1);
}

int partition(std::vector<int> &arr, int low, int high)
{
  std::swap(arr[generateRandomNumber(low, high)], arr[high]);
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j < high; ++j)
  {
    if (arr[j] <= pivot)
    {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void QuickSort(std::vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}

int main()
{
  std::vector<int> arr = {10, 7, 8, 9, 1, 5};
  QuickSort(arr, 0, arr.size() - 1);
}

// Time Complexity:
//  Best/Average case: O(n log n) (balanced partitions).
//  Worst case: O(n^2) (highly unbalanced partitions, e.g., when array is already sorted).

// Space Complexity:
//  Space complexity: O(log n) (due to recursion stack in balanced partitions).

// Stability:
//  Not stable: The relative order of equal elements can change.