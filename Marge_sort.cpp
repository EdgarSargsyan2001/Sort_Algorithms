#include <iostream>
#include <vector>

void Merge(std::vector<int> &arr, int left, int mid, int right)
{
  std::vector<int> tmpArr(right - left + 1);
  int i = left;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= right)
  {
    if (arr[i] < arr[j])
    {
      tmpArr[k++] = arr[i++];
    }
    else
    {
      tmpArr[k++] = arr[j++];
    }
  }

  while (i <= mid)
  {
    tmpArr[k++] = arr[i++];
  }

  while (j <= right)
  {
    tmpArr[k++] = arr[j++];
  }

  for (int i = left, v = 0; i <= right; ++i, ++v)
  {
    arr[i] = tmpArr[v];
  }
}

void MergeSort(std::vector<int> &arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
  }
}

int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  MergeSort(arr, 0, arr.size() - 1);
}

// Time Complexity:
//  Best/Average/Worst case: O(n log n) (due to dividing the array into halves).

// Space Complexity:
//  Space complexity: O(n) (additional space is required to store the temporary arrays).

// Stability:
//  Stable: Equal elements retain their original relative order.