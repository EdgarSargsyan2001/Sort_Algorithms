#include <iostream>

void Marge(int *arr, int l, int m, int r)
{
  int *tmpArr = new int[r - l + 1];
  int i = l;
  int j = m + 1;
  int k = 0;

  while (i <= m && j <= r)
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

  while (i <= m)
  {
    tmpArr[k++] = arr[i++];
  }

  while (j <= r)
  {
    tmpArr[k++] = arr[j++];
  }

  for (int i = l, v = 0; i <= r; ++i, ++v)
  {
    arr[i] = tmpArr[v];
  }

  delete[] tmpArr;
}

void MargeSort(int *arr, int s, int e)
{
  if (s < e)
  {
    int m = (s + e) / 2;
    MargeSort(arr, s, m);
    MargeSort(arr, m + 1, e);
    Marge(arr, s, m, e);
  }
}

void printArr(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  const int size = 7;
  int arr[size] = {55, 1, 0, 88, 2, 6, 33};
  printArr(arr, size);
  MargeSort(arr, 0, size - 1);
  std::cout << std::endl;
  printArr(arr, size);
}