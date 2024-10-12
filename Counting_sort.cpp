#include <iostream>
#include <vector>
#include <algorithm>

void CountiogSort(std::vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return;

    // Find the minimum and maximum values in the array
    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    // Calculate the range of the count array
    int range = maxVal - minVal + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(n);

    // Count occurrences of each element, shifted by minVal
    for (int num : arr)
    {
        count[num - minVal]++;
    }

    // Update the count array to hold actual positions
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Copy the sorted elements back to the original array
    arr = output;
}

int main()
{
    std::vector<int> arr = {4, -2, 2, 8, 3, -3, 1};
    CountiogSort(arr);
}

// Time Complexity:
//  Best, Average, Worst case: O(n + k) (where n is the number of elements and k is the range of the input values).

// Space Complexity:
//  Space complexity: O(k) (additional space is required for the count array).

// Stability:
//  Stable: Counting sort preserves the relative order of equal elements.