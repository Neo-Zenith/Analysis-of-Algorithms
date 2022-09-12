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
    writeFile("mergeInsertionSortPart2b.csv", "Threshold Size,Key comparisons,Execution time \n");

    int sizeOfArray = 100000;
    for (int i = 1; i <= sizeOfArray; i *= 2)
    {  
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);
        Arr = arrayGenerate(sizeOfArray, MAX_SIZE); 

        clock_t begin = clock();

        mergeInsertionSort(&Arr, 0, sizeOfArray - 1, i, &keyComparisons);
        //mergeSort(&Arr, 0, sizeOfArray - 1, &keyComparisons);

        clock_t end = clock();
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        writeIntOutput("mergeInsertionSortPart2b.csv", i, ",");
        writeLongOutput("mergeInsertionSortPart2b.csv", keyComparisons, ",");
        writeDoubleOutput("mergeInsertionSortPart2b.csv", time_spent, "\n");

        printf("Threshold size: %d; \tTime taken: %lf\n", i, time_spent);
    }
}