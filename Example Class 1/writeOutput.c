#include <stdio.h>
#include <stdlib.h>

int writeStringOutput(char *text)
{
    FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, text);

    fclose(f);

    return 1;
}

int writeIntOutput(int text)
{
    FILE *f = fopen("file.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%d ", text);

    fclose(f);

    return 1;
}