#include <stdio.h>
#include <stdlib.h>

void mergeSort(int **Arr, int start, int end, int *keyComparisons);
void merge(int **Arr, int start, int end, int pivot, int *keyComparisons);


void mergeSort(int **Arr, int start, int end, int *keyComparisons)
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

void merge(int **Arr, int start, int end, int pivot, int *keyComparisons)
{
    int *sortedArray = (int *) malloc(sizeof(int) * ((end - start) + 1));

    int i = start;
    int j = pivot + 1;
    int k = 0;

    while (i <= pivot && j <= end)
    {
        (*keyComparisons) ++;
        if ((*Arr)[i] < (*Arr)[j])
        {
            sortedArray[k ++] = (*Arr)[i ++];
        }
        else if ((*Arr)[i] > (*Arr)[j])
        {
            sortedArray[k ++] = (*Arr)[j ++];
        }
        else
        {
            sortedArray[k ++] = (*Arr)[i ++];
            sortedArray[k ++] = (*Arr)[j ++];
        }
    }
    
    while (i <= pivot)
    {
        sortedArray[k ++] = (*Arr)[i ++];
    }
    
    while (j <= end)
    {
        sortedArray[k ++] = (*Arr)[j ++];
    }

    k = 0;
    for (int i = start; i <= end; i ++)
    {
        (*Arr)[i] = sortedArray[k ++];
    }
}