#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> arr = {64, 25, 12, 22, 11};
    SelectionSort(arr);
}


// Time Complexity:
//  Best, Average, Worst case: O(n^2) (since the entire array is iterated over for every element).

// Space Complexity:
//  Space complexity: O(1) (in-place sorting).

// Stability:
//  Not stable: Selection sort can change the relative order of equal elements.