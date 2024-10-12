#include <iostream>
#include <vector>
#include <algorithm>

void CountingSortForRadix(std::vector<int> &arr, int exp)
{
    const int N = arr.size();
    const int K = 19; // The range of the digits being considered
    int count[K] = {0};
    std::vector<int> output(N);

    // Count occurrences of each digit
    for (int i = 0; i < N; ++i)
    {
        int index = ((arr[i] / exp) % 10) + (K / 2); // Get the digit's index
        count[index]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < K; ++i)
    {
        count[i] += count[i - 1]; // Cumulative sum to get the position of elements
    }

    // Build the output vector
    for (int i = N - 1; i >= 0; --i)
    {
        int index = ((arr[i] / exp) % 10) + (K / 2); // Get the digit's index
        output[--count[index]] = arr[i];             // Place elements in output vector
    }

    // Copy sorted elements back to original array
    arr = output;
}

void RadixSort(std::vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());

    // Apply counting sort for each digit
    for (int exp = 1; (maxVal / exp) > 0; exp *= 10)
    {
        CountingSortForRadix(arr, exp);
    }
}

int main()
{
    std::vector<int> arr = {6, -1, 9, -99, 4, 8, 9, 0, 11, 5454, 0};
    RadixSort(arr);

    for (auto el : arr)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl; // To ensure proper output format
}

// Time Complexity:
//  Best, Average, Worst case: O(n * k) (where n is the number of elements and k is the number of digits in the largest number).

// Space Complexity:
//  Space complexity: O(n + k) (additional space for the output and count arrays).

// Stability:
//  Stable: Radix sort preserves the relative order of equal elements.