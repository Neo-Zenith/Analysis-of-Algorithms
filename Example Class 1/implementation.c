#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#define MAX_SIZE 1000

int main()
{
    int S = 10;
    for (int i = 10; i < 10000; i *= 10)
    {
        int keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);
        Arr = arrayGenerate(i, MAX_SIZE);

        mergeSort(&Arr, 0, i - 1, S, &keyComparisons);

        writeStringOutput("[");
        for (int j = 0; j < i; j ++)
        {
            writeIntOutput(Arr[j]);
        }
        writeStringOutput("]\n");

        printf("KeyComparisons for Array of length %d is %d\n", i, keyComparisons);
    }
}