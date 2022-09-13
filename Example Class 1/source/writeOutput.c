#include <stdio.h>
#include <stdlib.h>

void writeFile(char *name, char *header)
{
    FILE *f = fopen(name, "a");
    fprintf(f, header);
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