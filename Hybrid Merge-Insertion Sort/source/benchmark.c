#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.c"
#include "output.c"
#include "arrayGenerate.c"

// Benchmark the hybrid algorithm with fixed S value for different array sizes
// int S == threshold size
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void CPart1(int S, char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge-Insertion Sort\n");
    printf("Performing Merge-Insertion Sort on different array sizes with S = %d", S);
    printf("\n=======================================\n");

    writeFile(file, "Array Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple arrays with incrementing sizes. 
    //The size increments in multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        // Intialising variables
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate a random array each time
        Arr = arrayGenerate(i, i, -1); 

        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, i - 1, S, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Array size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the pure merge sort algorithm for different array sizes
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void CPart1Merge(char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge Sort\n");
    printf("Performing Merge Sort on different array sizes");
    printf("\n=======================================\n");

    writeFile(file, "Array Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple arrays with incrementing sizes. 
    //The size increments in multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        // Intialising variables
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate a random array each time
        Arr = arrayGenerate(i, i, -1); 

        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeSort(&Arr, 0, i - 1, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Array size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm with fixed array size for different S values (*= 2)
// int size == size of the array
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void CPart2a(int size, char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge-Insertion Sort\n");
    printf("Performing Merge-Insertion Sort with different threshold sizes on array size = %d", size);
    printf("\n=======================================\n");

    writeFile(file, "Threshold Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple thresholds values. 
    // The size increments by multiples of 2
    for (int i = 1; i <= 10000; i *= 2)
    {  
        // Intialising variables
        long long keyComparisons = 0;

        int *Arr = (int *) malloc(sizeof(int) * size);
        // Generate a random array of length size
        Arr = arrayGenerate(size, size, 1); 
        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, size - 1, i, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Threshold size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm with fixed array size for different S values (+= 1)
// int size == size of the array
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void CPart2b(int size, char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge-Insertion Sort\n");
    printf("Performing Merge-Insertion Sort with different threshold sizes on array size = %d", size);
    printf("\n=======================================\n");

    writeFile(file, "Threshold Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple thresholds values. 
    // The size increments by multiples of 2
    for (int i = 1; i <= 100; i += 1)
    {  
        // Intialising variables
        long long keyComparisons = 0;

        int *Arr = (int *) malloc(sizeof(int) * size);
        // Generate a random array of length size
        Arr = arrayGenerate(size, size, 1); 
        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, size - 1, i, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Threshold size: %d;\t", i);
        printf("Key comparisons: %lld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm for different S values (+= 1) and different array sizes
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void CPart3(char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge-Insertion Sort\n");
    printf("Performing Merge-Insertion Sort with different threshold sizes on different array size");
    printf("\n=======================================\n");

    writeFile(file, "Array Size,Threshold Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple array sizes. 
    // The size increments by multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        for (int j = 1; j <= 100; j += 1)
        {
            // Intialising variables
            long long keyComparisons = 0;

            int *Arr = (int *) malloc(sizeof(int) * i);
            // Generate a random array of length i
            Arr = arrayGenerate(i, i, 1); 
            
            clock_t begin = clock();    // FKeep track of CPU time (start)
            mergeInsertionSort(&Arr, 0, i - 1, j, &keyComparisons);
            clock_t end = clock();      // Keep track of CPU time (end)
            free(Arr);
            float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
            
            // Write the output to file
            writeIntOutput(file, i, ",");
            writeIntOutput(file, j, ",");
            writeLongOutput(file, keyComparisons, ",");
            writeDoubleOutput(file, time_spent, "\n");

            // Print for debug
            printf("Array size: %d;\t", i);
            printf("Threshold size: %d;\t", j);
            printf("Key comparisons: %lld;\t", keyComparisons);
            printf("Time elapsed: %lf\n", time_spent);
        }
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm with optimal S value obtained for array size of 10 mil
// int S == optimal S value
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void benchmarkD(int S, char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge-Insertion Sort\n");
    printf("Performing Merge-Insertion Sort with optimal threshold size of %d on array size = 10 mil for 20 trials", S);
    printf("\n=======================================\n");

    writeFile(file, "Trial,Key Comparisons,Elapsed Time\n");

    for (int i = 0; i < 20; i ++)
    {
        // Intialising variables
        long long keyComparisons = 0;

        int *Arr = (int *) malloc(sizeof(int) * i);
        // Generate a random array of length i
        Arr = arrayGenerate(10000000, 10000000, -1); 
        
        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, 10000000 - 1, 23, &keyComparisons);
        //mergeSort(&Arr, 0, 10000000 - 1, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeStringOutput(file, "#", "");
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Trial: #%d;\t", i);
        printf("Key comparisons: %lld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }
}

// Benchmark the pure merge sort algorithm for array size of 10 mil
// int S == optimal S value
// char *file == file path (ex: "../datasets/<FILENAME>" will save the file to the folder 
// "datasets" in the same directory as the current file's parent directory)
void benchmarkDMerge(char *file)
{
    printf("\n=======================================\n");
    printf("Algorithm: Merge Sort\n");
    printf("Performing Merge Sort on array size = 10 mil for 20 trials");
    printf("\n=======================================\n");

    writeFile(file, "Trial,Key Comparisons,Elapsed Time\n");

    for (int i = 0; i < 20; i ++)
    {
        // Intialising variables
        long long keyComparisons = 0;

        int *Arr = (int *) malloc(sizeof(int) * i);
        // Generate a random array of length i
        Arr = arrayGenerate(10000000, 10000000, -1); 
        
        clock_t begin = clock();    // FKeep track of CPU time (start)
        mergeSort(&Arr, 0, 10000000 - 1, &keyComparisons);
        clock_t end = clock();      // Keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeStringOutput(file, "#", "");
        writeIntOutput(file, i, ",");
        writeLongOutput(file, keyComparisons, ",");
        writeDoubleOutput(file, time_spent, "\n");

        // Print for debug
        printf("Trial: #%d;\t", i);
        printf("Key comparisons: %lld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }
}