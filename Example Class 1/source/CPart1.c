#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include "mergeSort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Write to the specified csv file
    writeFile("CPart1-Hybrid.csv", "Array Size,Key Comparisons,Execution Time\n");

    // Set the initial threshold value to 16
    int S = 16;

    // Iterate through multiple arrays with incrementing sizes. The size increments in multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        // Intialising variables
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate the random array
        Arr = arrayGenerate(i, i); 

        
        clock_t begin = clock();    // Function to keep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, i - 1, S, &keyComparisons);
        //mergeSort(&Arr, 0, i - 1, &keyComparisons);
        clock_t end = clock();      // Function to keep track of CPU time (end)
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput("CPart1-Hybrid.csv", i, ",");
        writeLongOutput("CPart1-Hybrid.csv", keyComparisons, ",");
        writeDoubleOutput("CPart1-Hybrid.csv", time_spent, "\n");

        // Print for debug
        printf("Array size: %d; \tTime taken: %lf\n", i, time_spent);
    }
}