#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Helper functions
int *arrayGenerate(int size, int max);
void writeFile(char *name, char *header);
int writeDoubleOutput(char *name, double text, char *character);
int writeStringOutput(char *name, char *text, char *character);
int writeIntOutput(char *name, int text, char *character);
int writeLongOutput(char *name, long long text, char *character);

// Sorting algorithms
void insertionSort(int **Arr, int start, int end, long long *keyComparisons);
void mergeInsertionSort(int **Arr, int start, int end, int S, long long *keyComparisons);
void merge(int **Arr, int start, int end, int pivot, long long *keyComparisons);
void swap(int **Arr, int i, int j);
void mergeSort(int **Arr, int start, int end, long long *keyComparisons);

// Benchmark tools
void benchmarkDifArraySize();
void benchmarkDifArraySizeMerge();
void benchmarkDifThreshSize1();
void benchmarkDifThreshSize2();
void benchmarkDifThresArraySize1();
void benchmarkDifThresArraySize2();
void benchmarkFinal(int S);

int main()
{
    benchmarkDifArraySize();
    //benchmarkDifArraySizeMerge();
    //benchmarkDifThreshSize1();
    //benchmarkDifThreshSize2();
    //benchmarkDifThresArraySize1();
    //benchmarkDifThresArraySize2();
    //benchmarkFinal(log(10000000) / log(2));
}


// Benchmark the hybrid algorithm with fixed S = 16 for different array sizes
void benchmarkDifArraySize()
{
    printf("Executing task: Generate sample for varying array size with fixed S value = 16\n");
    printf("Algorithm: Hyrbid Merge Insertion-Sort Algorithm\n");

    writeFile("../datasets/VaryingArraySize.csv", "Array Size,Key Comparisons,Elapsed Time\n");
    // Set the initial threshold value to 16
    int S = 43;

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
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput("../datasets/VaryingArraySize.csv", i, ",");
        writeLongOutput("../datasets/VaryingArraySize.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/VaryingArraySize.csv", time_spent, "\n");

        // Print for debug
        printf("Array size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the merge sort algorithm for different array sizes
void benchmarkDifArraySizeMerge()
{
    printf("Executing task: Generate sample for varying array size with fixed S value = 16\n");
    printf("Algorithm: Merge Sort Algorithm\n");

    writeFile("../datasets/VaryingArraySizeMerge.csv", "Array Size,Key Comparisons,Elapsed Time\n");

    // Iterate through multiple arrays with incrementing sizes. The size increments in multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {  
        // Intialising variables
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate the random array
        Arr = arrayGenerate(i, i); 

        clock_t begin = clock();    // Function to keep track of CPU time (start)
        mergeSort(&Arr, 0, i - 1, &keyComparisons);
        clock_t end = clock();      // Function to keep track of CPU time (end)
        free(Arr);
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent
        
        // Write the output to file
        writeIntOutput("../datasets/VaryingArraySizeMerge.csv", i, ",");
        writeLongOutput("../datasets/VaryingArraySizeMerge.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/VaryingArraySizeMerge.csv", time_spent, "\n");

        // Print for debug
        printf("Array size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm with fixed array size = 10 mil for different threshold value
// Threshold value increments by 1
void benchmarkDifThreshSize1()
{
    printf("Executing task: Generate sample for varying threshold size (+= 1) with fixed array value = 10 mil\n");
    printf("Algorithm: Hyrbid Merge-Insertion Sort Algorithm\n");

    writeFile("../datasets/VaryingThresholdSize1.csv", "Threshold Size,Key Comparisons,Elapsed Time\n");

    // Set the size of array to 10 mil
    int sizeOfArray = 10000000;

    // Iterate through different values of threshold S
    for (int i = 1; i <= 100; i += 1)
    {  
        long long keyComparisons = 0;
        int *Arr = (int *) malloc(sizeof(int) * i);

        // Generate the random array
        Arr = arrayGenerate(sizeOfArray, sizeOfArray); 

        clock_t begin = clock();            // Function to keep track of CPU time (start)
        mergeInsertionSort(&Arr, 0, sizeOfArray - 1, i, &keyComparisons);
        clock_t end = clock();              // Function to keep track of CPU time (end)
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;         // Get time spent
        
        // Write the output to file
        writeIntOutput("../datasets/VaryingThresholdSize1.csv", i, ",");
        writeLongOutput("../datasets/VaryingThresholdSize1.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/VaryingThresholdSize1.csv", time_spent, "\n");

        // Print for debug
        printf("Threshold size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm with fixed array size = 10 mil for different threshold value
// Threshold value increments by multples of 2
void benchmarkDifThreshSize2()
{
    printf("Executing task: Generate sample for varying threshold size (*= 2) with fixed array value = 10 mil\n");
    printf("Algorithm: Hyrbid Merge-Insertion Sort Algorithm\n");

    writeFile("../datasets/VaryingThresholdSize2.csv", "Threshold Size,Key Comparisons,Elapsed Time\n");

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
        clock_t end = clock();              // Function to keep track of CPU time (end)
        free(Arr);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;         // Get time spent
        
        // Write the output to file
        writeIntOutput("../datasets/VaryingThresholdSize2.csv", i, ",");
        writeLongOutput("../datasets/VaryingThresholdSize2.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/VaryingThresholdSize2.csv", time_spent, "\n");

        // Print for debug
        printf("Threshold size: %d;\t", i);
        printf("Key comparisons: %ld;\t", keyComparisons);
        printf("Time elapsed: %lf\n", time_spent);
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm for different array size and different threshold value
// Threshold value increments by 1
void benchmarkDifThresArraySize1()
{
    printf("Executing task: Generate sample for varying threshold size (+= 1) with varying array value (*= 10)\n");
    printf("Algorithm: Hyrbid Merge-Insertion Sort Algorithm\n");

    writeFile("../datasets/VaryingThresholdArraySize1.csv", "Array Size,Threshold Size,Key Comparisons,Elapsed Time\n");

    // Iterate through different values of array size with multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {   
        printf("Array size: %d\n", i);

        // Iterate through different values of threshold S
        for (int j = 1; j <= 100; j += 1)
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
            
            writeIntOutput("../datasets/VaryingThresholdArraySize1.csv", i, ",");
            writeIntOutput("../datasets/VaryingThresholdArraySize1.csv", j, ",");
            writeLongOutput("../datasets/VaryingThresholdArraySize1.csv", keyComparisons, ",");
            writeDoubleOutput("../datasets/VaryingThresholdArraySize1.csv", time_spent, "\n");

            // Print for debug
            printf("Threshold size: %d;\t", j);
            printf("Key comparisons: %ld;\t", keyComparisons);
            printf("Time elapsed: %lf\n", time_spent);
        }
    }

    printf("Execution complete... \n\n");
}

// Benchmark the hybrid algorithm for different array size and different threshold value
// Threshold value increments by multiples of 2
void benchmarkDifThresArraySize2()
{
    printf("Executing task: Generate sample for varying threshold size (*= 2) with varying array value (*= 10)\n");
    printf("Algorithm: Hyrbid Merge-Insertion Sort Algorithm\n");

    writeFile("../datasets/VaryingThresholdArraySize2.csv", "Array Size,Threshold Size,Key Comparisons,Elapsed Time\n");

    // Iterate through different values of array size with multiples of 10
    for (int i = 1000; i <= 10000000; i *= 10)
    {   
        printf("Array size: %d\n", i);

        // Iterate through different values of threshold S
        for (int j = 1; j <= 1000; j *= 2)
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
            
            writeIntOutput("../datasets/VaryingThresholdArraySize2.csv", i, ",");
            writeIntOutput("../datasets/VaryingThresholdArraySize2.csv", j, ",");
            writeLongOutput("../datasets/VaryingThresholdArraySize2.csv", keyComparisons, ",");
            writeDoubleOutput("../datasets/VaryingThresholdArraySize2.csv", time_spent, "\n");

            // Print for debug
            printf("Threshold size: %d;\t", j);
            printf("Key comparisons: %ld;\t", keyComparisons);
            printf("Time elapsed: %lf\n", time_spent);
        }
    }

    printf("Execution complete... \n\n");
}

// Final benchmark for the hybrid algorithm with optimum threshold value
// int S == optimal threshold value
void benchmarkFinal(int S)
{
    printf("Executing task: Generate 20 sample for Hybrid Merge-Insertion Sort using optimal S\n");
    printf("Algorithm: Hyrbid Merge-Insertion Sort Algorithm\n");

    writeFile("../datasets/OptimalSBenchmark.csv", "Algorithm,Key Comparisons,Elapsed Time\n");

    for (int i = 0; i < 20; i ++)
    {
        long long keyComparisons = 0;
        long long arraySize = 10000000;

        int *Arr1 = (int *) malloc(sizeof(int) * arraySize);
        Arr1 = arrayGenerate(arraySize, arraySize); 

        clock_t begin = clock();
        mergeInsertionSort(&Arr1, 0, arraySize - 1, S, &keyComparisons);
        clock_t end = clock();
        free(Arr1);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        writeStringOutput("../datasets/OptimalSBenchmark.csv", "Merge-Insertion Sort", ",");
        writeLongOutput("../datasets/OptimalSBenchmark.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/OptimalSBenchmark.csv", time_spent, "\n");
    }

    printf("Execution complete... \n\n");

    printf("Executing task: Generate 20 sample for Merge Sort\n");
    printf("Algorithm: Merge Sort Algorithm\n");
    for (int i = 0; i < 20; i ++)
    {
        long long keyComparisons = 0;
        long long arraySize = 10000000;

        int *Arr1 = (int *) malloc(sizeof(int) * arraySize);
        Arr1 = arrayGenerate(arraySize, arraySize); 

        clock_t begin = clock();
        mergeSort(&Arr1, 0, arraySize - 1, &keyComparisons);
        clock_t end = clock();
        free(Arr1);
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        writeStringOutput("../datasets/OptimalSBenchmark.csv", "Merge Sort", ",");
        writeLongOutput("../datasets/OptimalSBenchmark.csv", keyComparisons, ",");
        writeDoubleOutput("../datasets/OptimalSBenchmark.csv", time_spent, "\n");
    }

    printf("Execution complete... \n\n");
}

// Generate an array with n == size and filled with random integers from 0 to max
int *arrayGenerate(int size, int max)
{
    // Dynamically allocate an array with the input size
    int *randArray = (int *) malloc(sizeof(int) * size);

    // Seed to generate different arrays on each run
    srand (time(0));

    // Fill the array with random numbers
    for (int j = 0; j < size; j ++)
    {
        randArray[j] = rand() % max;   //Generate number between 0 to max
    }

    return randArray;
}

// Hybrid Merge Insertion Sort algorithm
// int **Arr == Array to be sorted
// int start == starting index
// int end == ending index
// int S == threshold value
// long long *keyComparisons == a pointer that points to the integer storing the total number of key comparisons
void mergeInsertionSort(int **Arr, int start, int end, int S, long long *keyComparisons)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;

    if (end - start > S)
    {
        mergeInsertionSort(Arr, start, pivot, S, keyComparisons);
        mergeInsertionSort(Arr, pivot + 1, end, S, keyComparisons);

        merge(Arr, start, end, pivot, keyComparisons);
    }

    else
    {
        insertionSort(Arr, start, end, keyComparisons);
    }
}

// Merge function
// int **Arr == Array to be sorted
// int start == starting index
// int end == ending index
// int pivot == mid point of the Array which marks the split between the two subarrays
// long long *keyComparisons == a pointer that points to the integer storing the total number of key comparisons
void merge(int **Arr, int start, int end, int pivot, long long *keyComparisons)
{
    int *sortedArray = (int *) malloc(sizeof(int) * ((end - start) + 1));

    int i = start;
    int j = pivot + 1;
    int k = 0;

    while (i <= pivot && j <= end)
    {
        (*keyComparisons) ++;
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

    free(sortedArray);
}


// Insertion Sort algorithm
// int **Arr == Array to be sorted
// int start == starting index
// int end == ending index
// long long *keyComparisons == a pointer that points to the integer storing the total number of key comparisons
void insertionSort(int **Arr, int start, int end, long long *keyComparisons)
{
    for (int i = start + 1; i <= end; i ++)
    {
        for (int j = i; j > start; j --)
        {
            (*keyComparisons) ++;
            if ((*Arr)[j] < (*Arr)[j - 1])
            {
                swap(Arr, j, j - 1);
            }
            else
            {
                break;
            }
        }
    }
}


// Swap the element at index i and index j
// int **Arr == Array to be sorted
// int i, int j == indexes of the elements to be swapped
void swap(int **Arr, int i, int j)
{
    int temp = (*Arr)[i];
    (*Arr)[i] = (*Arr)[j];
    (*Arr)[j] = temp;
}

// Merge Sort algorithm
// int **Arr == Array to be sorted
// int start == starting index
// int end == ending index
// long long *keyComparisons == a pointer that points to the integer storing the total number of key comparisons
void mergeSort(int **Arr, int start, int end, long long *keyComparisons)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (start + end) / 2;

    mergeSort(Arr, start, pivot, keyComparisons);
    mergeSort(Arr, pivot + 1, end, keyComparisons);

    merge(Arr, start, end, pivot, keyComparisons);
}

// Create a file to be written
// char *name == name of the file
// char *header == header of the file
void writeFile(char *name, char *header)
{
    FILE *f = fopen(name, "a");
    fprintf(f, header);
    fclose(f);
}

// Write a string to the output file
// char *name == name of the file
// char *text == text to be written
// char *character == escape character of the line
int writeStringOutput(char *name, char *text, char *character)
{
    FILE *f = fopen(name, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%s%s", text, character);

    fclose(f);

    return 1;
}

// Write an integer to the output file
// char *name == name of the file
// int text == text to be written
// char *character == escape character of the line
int writeIntOutput(char *name, int text, char *character)
{
    FILE *f = fopen(name, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%d%s", text, character);

    fclose(f);

    return 1;
}

// Write a long integer to the output file
// char *name == name of the file
// long long text == text to be written
// char *character == escape character of the line
int writeLongOutput(char *name, long long text, char *character)
{
    FILE *f = fopen(name, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%lld%s", text, character);

    fclose(f);

    return 1;
}

// Write a long float to the output file
// char *name == name of the file
// double text == text to be written
// char *character == escape character of the line
int writeDoubleOutput(char *name, double text, char *character)
{
    FILE *f = fopen(name, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%lf%s", text, character);

    fclose(f);

    return 1;
}