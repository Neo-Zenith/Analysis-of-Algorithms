#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include "mergeSort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    writeFile("CPart3-Hybrid-1.csv", "Array Size,Threshold Size,Key Comparisons,Execution Time\n");

    // Iterate through different values of array size with multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {   
        printf("Array length: %d\n", i);

        // Iterate through different values of threshold S
        for (int j = 1; j <= 100; j += 5)
        {
            long long keyComparisons = 0;
            int *Arr = (int *) malloc(sizeof(int) * i);
            Arr = arrayGenerate(i, i);

            clock_t begin = clock();
            mergeInsertionSort(&Arr, 0, i - 1, j, &keyComparisons);
            //mergeSort(&Arr, 0, sizeOfArray - 1, &keyComparisons);
            clock_t end = clock();
            free(Arr);
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            
            writeIntOutput("CPart3-Hybrid-1.csv", i, ",");
            writeIntOutput("CPart3-Hybrid-1.csv", j, ",");
            writeLongOutput("CPart3-Hybrid-1.csv", keyComparisons, ",");
            writeDoubleOutput("CPart3-Hybrid-1.csv", time_spent, "\n");

            printf("Threshold size: %d; \tTime taken: %lf\n", j, time_spent);
        }
    }
}