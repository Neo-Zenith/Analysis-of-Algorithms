#include <math.h>
#include <stdlib.h>

// Generate an array with n == size and filled with random integers from 0 to max
int *arrayGenerate(int size, int max, int seed)
{
    // Dynamically allocate an array with the input size
    int *randArray = (int *) malloc(sizeof(int) * size);

    // Seed to generate different arrays on each run
    if (seed == -1)   srand (time(0));
    else              srand (1);

    // Fill the array with random numbers
    for (int j = 0; j < size; j ++)
    {
        randArray[j] = rand() % max;   //Generate number between 0 to max
    }

    return randArray;
}
