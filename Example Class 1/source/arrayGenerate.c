#include <stdio.h>
#include <stdlib.h>

// Function to generate an array with n == size and filled with random integers from 0 to max
int *arrayGenerate(int size, int max)
{
    // Dynamically allocate an array with the input size
    int *randArray = (int *) malloc(sizeof(int) * size);

    // Fill the array with random numbers
    for (int j = 0; j < size; j ++)
    {
        randArray[j] = rand() % max;   //Generate number between 0 to max
    }

    return randArray;
}