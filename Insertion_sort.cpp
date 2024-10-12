#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 1; i < n; ++i)
  {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6};
  InsertionSort(arr);
}

// Time Complexity:
//  Best case (O(n)):       The array is already sorted.
//  Average case (O(n^2)):  Randomly ordered array.
//  Worst case (O(n^2)):    Array is in reverse order.

// Space Complexity:
//  Space complexity: O(1) (in-place sorting).

// Stability:
//  Stable: Equal elements retain their original relative order.