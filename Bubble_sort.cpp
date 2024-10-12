#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &arr)
{
  int n = arr.size();
  bool swapped;

  for (int i = 0; i < n - 1; ++i)
  {
    swapped = false;

    for (int j = 0; j < n - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
    {
      break;
    }
  }
}

int main()
{
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  BubbleSort(arr);
}

// Time Complexity:
//  Best case (O(n)):       This occurs when the array is already sorted,
//                          and the algorithm breaks out early (no swaps are made).

//  Average case (O(n^2)):  This happens when the array elements are randomly ordered,
//                          and we need to perform the full set of comparisons and swaps.

//  Worst case (O(n^2)):    This occurs when the array is sorted in reverse order,
//                          and the algorithm needs to compare and swap every element in each pass.

// Space Complexity:
//  The space complexity is O(1) since bubble sort is an in-place sorting algorithm.
//  It only uses a constant amount of additional memory.

// Bubble sort is stable:
//  It preserves the relative order of equal elements.
//  This is because the swap only happens when the element on the left is strictly greater
//  than the one on the right. Equal elements are not swapped, ensuring stability.