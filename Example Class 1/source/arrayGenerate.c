#include <stdio.h>
#include <stdlib.h>

int *arrayGenerate(int size, int max)
{
    int *randArray = (int *) malloc(sizeof(int) * size);

    for (int j = 0; j < size; j ++)
    {
        randArray[j] = rand() % max;   //Generate number between 0 to 99
    }

    return randArray;
}