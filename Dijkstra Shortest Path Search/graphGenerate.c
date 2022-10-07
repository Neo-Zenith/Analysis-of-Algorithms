#include <math.h>
#include <stdlib.h>


void graphGenerate(int maxVertices, int maxEdgeSize, int seed, int **randGraph)
{
    if (seed == -1)   srand (time(0));
    else              srand (1);

    for (int i = 0; i <= maxVertices; i ++)
    {
        randGraph[i] = (int *) malloc(sizeof(int *) * (maxVertices + 1));
        if (i > 0)
        {
            int flag = 0;
            for (int j = 1; j <= maxVertices; j ++)
            {
                if (flag)
                {
                    randGraph[i][j] = (rand() % maxEdgeSize) - 1;
                }
                else
                {
                    randGraph[i][j] = rand() % maxEdgeSize;
                }
                
                if (randGraph[i][j] != -1 && i != j)  
                {
                    flag = 1;
                }
            }
        }
    }
}