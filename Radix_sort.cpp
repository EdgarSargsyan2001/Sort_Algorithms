#include <iostream>
#include <vector>

void countsort(int *arr, int N, int exp)
{
    const int K = 19;
    int count[K] = {0};

    std::vector<int> output(N);

    for (int i = 0; i < N; ++i)
    {
        count[(arr[i] / exp) % K + K / 2]++;
    }

    for (int i = 1; i < K; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        output[--count[(arr[i] / exp) % K + K / 2]] = arr[i];
    }

    for (int i = 0; i < N; ++i)
    {
        arr[i] = output[i];
    }
}

void radixsort(int *arr, int N)
{
    int max = arr[0];
    for (int i = 1; i < N; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int exp = 1; (max / exp) > 0; exp *= 10)
    {
        countsort(arr, N, exp);
    }
}

int main()
{
    int arr[] = {6, -1, 9, -99, 4, 8, 9, 0, 11, 5454, 0};

    int N = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, N);
}