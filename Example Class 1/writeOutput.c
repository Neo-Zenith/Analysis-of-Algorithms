#include <stdio.h>
#include <stdlib.h>

void writeFile(char *name)
{
    FILE *f = fopen(name, "a");
    fprintf(f,"Array Size,Key comparisons,Execution time \n");
    fclose(f);
}

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