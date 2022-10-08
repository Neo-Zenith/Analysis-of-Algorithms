#include <math.h>
#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = (rand() % i) + 1;
        
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void generateSpanningTree(int vertex, int *spanningTree, int seed)
{
    if (seed == -1)     srand(time(0));
    else                srand(0);

    shuffle(spanningTree, vertex + 1);
}


void generateConnectedGraph(int vertex, int edge, int maxEdgeSize, int **randGraph)
{
    int *spanningTree = (int *) malloc(sizeof(int) * (vertex + 1));
    for (int i = 1; i <= vertex; i ++)
    {
        spanningTree[i] = i;
    }

    generateSpanningTree(vertex, spanningTree, -1);


    for (int i = 0; i <= vertex; i ++)
    {
        randGraph[i] = (int *) malloc(sizeof(int) * (vertex + 1));
        for (int j = 0; j <= vertex; j ++)
        {
            randGraph[i][j] = -1;
        }
    }

    srand(time(0));
    for (int i = 1; i < vertex; i ++)
    {
        randGraph[spanningTree[i + 1]][spanningTree[i]] = rand() % maxEdgeSize;;
        randGraph[spanningTree[i]][spanningTree[i + 1]] = rand() % maxEdgeSize;;
    }

    randGraph[spanningTree[1]][spanningTree[vertex]] = rand() % maxEdgeSize;;
    randGraph[spanningTree[vertex]][spanningTree[1]] = rand() % maxEdgeSize;;

    srand(time(0));
    for (int i = 1; i <= vertex; i ++)
    {
        int remainder = edge - 2;
        while (remainder > 0)
        {
            int loc = (rand() % (vertex - 1)) + 1;
            int fullCount = 0;
            while (randGraph[i][loc] != -1)     
            {
                loc = (rand() % (vertex - 1)) + 1;
                fullCount ++;
                if (fullCount == vertex)    break;
            }
            if (fullCount == vertex)    break;
            int weight = rand() % maxEdgeSize;
            randGraph[i][loc] = weight;

            remainder --;
        }
    }
}