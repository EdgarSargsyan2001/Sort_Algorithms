#include <climits>
#include <vector>
#include <iostream>

void CountiogSort(int *arr, int N)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    min = std::abs(min);

    int sizeCountArr = min + max + 1;
    std::vector<int> countArr(sizeCountArr, 0);

    for (int i = 0; i < N; ++i)
    {
        countArr[arr[i] + min]++;
    }

    for (int i = 1; i < sizeCountArr; ++i)
    {
        countArr[i] += countArr[i - 1];
    }

    std::vector<int> output(N);
    for (int i = N - 1; i >= 0; --i)
    {
        output[countArr[arr[i] + min] - 1] = arr[i];
        countArr[arr[i] + min]--;
    }

    for (int i = 0; i < N; ++i)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {6, -1, 9, -99, 4, 8, 9, 0, 11, 5454, 0};

    int N = sizeof(arr) / sizeof(arr[0]);
    CountiogSort(arr, N);
}