#include <iostream>

void selection(int *arr, int n) // O(n^2)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
            std::swap(arr[i], arr[min]);
    }
}
int main()
{
    int arr[] = {6, -1, 9, 0};

    int N = sizeof(arr) / sizeof(arr[0]);
    selection(arr, N);
}