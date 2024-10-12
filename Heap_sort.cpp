#include <iostream>
#include <vector>

void heapify(std::vector<int> &arr, int N, int i)
{

  int largist = i;   // parent index
  int l = i * 2 + 1; // left child index
  int r = i * 2 + 2; // right child index

  // find index the largest of the three
  if (l < N && arr[l] > arr[largist])
    largist = l;

  if (r < N && arr[r] > arr[largist])
    largist = r;

  if (largist != i)
  {
    std::swap(arr[i], arr[largist]); // move the largest to the top
    heapify(arr, N, largist);
  }
}

void HeapSort(std::vector<int> &arr)
{
  int N = arr.size();

  // sort heap  time complexity O(logn)
  for (int i = N / 2 - 1; i >= 0; --i)
  {
    heapify(arr, N, i);
  }

  // sort arr time complexity O(n * logn)
  for (int i = N - 1; i >= 0; --i)
  {
    std::swap(arr[0], arr[i]); // the largest element is always first
    heapify(arr, i, 0);
  }
}

int main()
{
  std::vector<int> arr = {12, 11, 13, 5, 6, 7};
  HeapSort(arr);
}

// Time Complexity:
//  Best/Average/Worst case: O(n log n) (due to heapification process).

// Space Complexity:
//  Space complexity: O(1) (in-place sorting).

// Stability:
//  Not stable: Heap sort does not preserve the relative order of equal elements.