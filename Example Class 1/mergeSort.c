#include <stdio.h>
#include <stdlib.h>

void mergeSort(int **Arr, int start, int end);
void merge(int **Arr, int start, int end, int pivot);

int main()
{
    int n;
    scanf("%d", &n);

    int *Arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &Arr[i]);
    }

    mergeSort(&Arr, 0, n - 1);

    for (int i = 0; i < n; i ++)
    {
        printf("%d ", Arr[i]);
    }
}

void mergeSort(int **Arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;

    mergeSort(Arr, start, pivot);
    mergeSort(Arr, pivot + 1, end);

    merge(Arr, start, end, pivot);
}

void merge(int **Arr, int start, int end, int pivot)
{
    int *sortedArray = (int *) malloc(sizeof(int) * ((end - start) + 1));

    int i = start;
    int j = pivot + 1;
    int k = 0;

    while (i <= pivot && j <= end)
    {
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