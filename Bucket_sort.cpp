#include <iostream>
#include <vector>
#include <algorithm>

void BucketSort(std::vector<float> &arr)
{
  const int N = arr.size();
  std::vector<std::vector<float>> buckets(N);

  // Distribute the input array elements into buckets
  for (float num : arr)
  {
    int index = num * N; // Assuming the elements are in range [0, 1)
    buckets[index].push_back(num);
  }

  // Sort individual buckets and concatenate
  for (auto &bucket : buckets)
  {
    std::sort(bucket.begin(), bucket.end());
  }

  // Concatenate all buckets into the output array
  arr.clear();
  for (const auto &bucket : buckets)
  {
    arr.insert(arr.end(), bucket.begin(), bucket.end());
  }
}

int main()
{
  std::vector<float> arr = {0.2, 0.5, 0.12, 0.45, 0.66, 0.124, 0.77, 0.88, 0.4, 0.29};

  BucketSort(arr);

  for (float num : arr)
  {
    std::cout << num << " ";
  }
}

// Time Complexity:
//  Best, Average case:   O(n + k) (where k is the number of buckets, assuming elements are evenly distributed).

//  Worst case:           O(n^2) (when all elements are placed in a single bucket).

// Space Complexity:
//  Space complexity:     O(n + k) (additional space for the buckets).

// Stability:
//  Stable: Bucket sort preserves the relative order of equal elements.