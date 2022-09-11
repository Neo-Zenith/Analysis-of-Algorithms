#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main()
{
    writeFile("dataForC(i).csv");

    int S = 16;
    for (int i = 1000; i <= 1000000; i += 1000)
    {  
        int keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);
        Arr = arrayGenerate(i, MAX_SIZE); 

        clock_t begin = clock();

        mergeInsertionSort(&Arr, 0, i - 1, S, &keyComparisons);

        clock_t end = clock();
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        int time_spent_ms = time_spent * 1000;
        
        writeIntOutput("dataForC(i).csv", i, ",");
        writeIntOutput("dataForC(i).csv", keyComparisons, ",");
        writeIntOutput("dataForC(i).csv", time_spent_ms, "\n");

        printf("Array size: %d; \tTime taken: %d\n", i, time_spent_ms);
    }
}