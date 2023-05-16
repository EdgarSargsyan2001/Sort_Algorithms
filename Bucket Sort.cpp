#include <algorithm>
#include <iostream>
#include <vector>

void bucket_sort(float *arr, int N) {

  std::vector<float> b[N];//create N buckets

  //push elemetns in deferetn bukets
  for (int i = 0; i < N; ++i) {
    int index = arr[i] * N;
    b[index].push_back(arr[i]);
  }

  // sort each bucket
  for (int i = 0; i < N; ++i)
    std::sort(b[i].begin(), b[i].end());

  int k = 0;
  // combine all buckets together
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < b[i].size(); ++j)
      arr[k++] = b[i][j];
}

int main() {

  int const N = 10;
  float arr[N] = {0.2, 0.5, 0.12, 0.45, 0.66, 0.124, 0.77, 0.88, 0.4, 0.29};
  //if we use this sort algorithm, our array must be in the range [0 1)
  //time complexity is O(n + k)  k-> is buckets count
  bucket_sort(arr, N);
  for (int i = 0; i < N; ++i) {
    std::cout << arr[i] << " ";
  }
}