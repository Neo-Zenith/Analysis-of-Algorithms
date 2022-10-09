#include <stdio.h>
#include <stdlib.h>

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