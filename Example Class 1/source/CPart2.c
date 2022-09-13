#include "arrayGenerate.c"
#include "mergeInsertionSort.c"
#include "writeOutput.c"
#include "mergeSort.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    writeFile("CPart2-Hybrid-2.csv", "Threshold Size,Key Comparisons,Execution Time\n");

    // Set the size of array to 10 mil
    int sizeOfArray = 10000000;

    // Iterate through different values of threshold S
    for (int i = 1; i <= 1000; i *= 2)
    {  
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate the random array
        Arr = arrayGenerate(sizeOfArray, sizeOfArray); 

        clock_t begin = clock();            // Function to keep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, sizeOfArray - 1, i, &keyComparisons);
        //mergeSort(&Arr, 0, sizeOfArray - 1, &keyComparisons);
        clock_t end = clock();              // Function to keep track of CPU time (end)
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;         // Get time spent
        
        // Write the output to file
        writeIntOutput("CPart2-Hybrid-2.csv", i, ",");
        writeLongOutput("CPart2-Hybrid-2.csv", keyComparisons, ",");
        writeDoubleOutput("CPart2-Hybrid-2.csv", time_spent, "\n");

        // Print for debug
        printf("Threshold size: %d; \tTime taken: %lf\n", i, time_spent);
    }
}