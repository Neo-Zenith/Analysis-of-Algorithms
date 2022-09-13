#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include "mergeSort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main()
{
    writeFile("CPart3-Hybrid.csv", "Array Size,Threshold Size,Key comparisons,Execution time\n");

    for (int i = 1000; i <= 10000000; i *= 10)
    {   
        printf("Array length: %d\n", i);
        for (int j = 1; j <= 100; j += 5)
        {
            long long keyComparisons = 0;
            int *Arr = (int *) malloc(sizeof(int) * i);
            Arr = arrayGenerate(i, MAX_SIZE);

            clock_t begin = clock();
            mergeInsertionSort(&Arr, 0, i - 1, j, &keyComparisons);
            //mergeSort(&Arr, 0, sizeOfArray - 1, &keyComparisons);
            clock_t end = clock();
            free(Arr);
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            
            writeIntOutput("CPart3-Hybrid.csv", i, ",");
            writeIntOutput("CPart3-Hybrid.csv", j, ",");
            writeLongOutput("CPart3-Hybrid.csv", keyComparisons, ",");
            writeDoubleOutput("CPart3-Hybrid.csv", time_spent, "\n");

            printf("Threshold size: %d; \tTime taken: %lf\n", j, time_spent);
        }
    }
}