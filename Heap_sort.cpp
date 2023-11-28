#include <iostream>

void heapify(int *arr, int N, int i)
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

void heap_sort(int arr[], int N) // O( nlogn)
{

  // sort heap  time complexity O( logn )
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

  int const N = 10;
  int arr[N] = {1, 8, -8, 60, 10, 5, 55, 67, 80, 12};

  heap_sort(arr, N);

  for (int i = 0; i < N; ++i)
    std::cout << arr[i] << " ";
}