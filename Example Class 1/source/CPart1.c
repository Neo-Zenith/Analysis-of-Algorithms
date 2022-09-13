#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include "mergeSort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main()
{
    writeFile("CPart1-Merge.csv", "Array Size,Key comparisons,Execution time\n");

    int S = 16;
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);
        Arr = arrayGenerate(i, MAX_SIZE); 

        clock_t begin = clock();
        //mergeInsertionSort(&Arr, 0, i - 1, S, &keyComparisons);
        mergeSort(&Arr, 0, i - 1, &keyComparisons);
        clock_t end = clock();
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        writeIntOutput("CPart1-Merge.csv", i, ",");
        writeLongOutput("CPart1-Merge.csv", keyComparisons, ",");
        writeDoubleOutput("CPart1-Merge.csv", time_spent, "\n");

        printf("Array size: %d; \tTime taken: %lf\n", i, time_spent);
    }
}