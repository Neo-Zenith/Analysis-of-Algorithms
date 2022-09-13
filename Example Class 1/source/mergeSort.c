#include <stdio.h>
#include <stdlib.h>

void mergeSort(int **Arr, int start, int end, long long *keyComparisons);
void merge(int **Arr, int start, int end, int pivot, long long *keyComparisons);


void mergeSort(int **Arr, int start, int end, long long *keyComparisons)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;

    mergeSort(Arr, start, pivot, keyComparisons);
    mergeSort(Arr, pivot + 1, end, keyComparisons);

    merge(Arr, start, end, pivot, keyComparisons);
}