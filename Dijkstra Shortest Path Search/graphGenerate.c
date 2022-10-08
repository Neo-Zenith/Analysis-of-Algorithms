#include <math.h>
#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

// helper function to shuffle the array
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

// generate a unique spanning tree from vertex 1 to vertex
// seed != -1 guarantees the same spanning tree during same runtime window
// seed = -1 generates unique spanning tree each time the function is called
void generateSpanningTree(int vertex, int *spanningTree, int seed)
{
    if (seed == -1)     srand(time(0));
    else                srand(0);

    shuffle(spanningTree, vertex + 1);
}


/*
    function to generate a connected graph with the following properties:
        1. We can traverse from any vertex to any vertex
        2. Each vertex has edge edges
        3. Each edge has max maxEdgeSize
*/
void generateConnectedGraph(int vertex, int edge, int maxEdgeSize, int **randGraph)
{
    int *spanningTree = (int *) malloc(sizeof(int) * (vertex + 1));
    for (int i = 1; i <= vertex; i ++)
    {
        spanningTree[i] = i;
    }

    // first generate the spanning tree
    generateSpanningTree(vertex, spanningTree, -1);

    // initialize default value of the graph (all nodes are disconnected)
    for (int i = 0; i <= vertex; i ++)
    {
        randGraph[i] = (int *) malloc(sizeof(int) * (vertex + 1));
        for (int j = 0; j <= vertex; j ++)
        {
            randGraph[i][j] = -1;
        }
    }

    // connect the nodes in the spanning tree in 2-ways
    /* 
        connecting in 2-ways is important as it guarantees that we will visit all nodes
        regardless where we start!!
    */
    srand(time(0));
    for (int i = 1; i < vertex; i ++)
    {
        randGraph[spanningTree[i + 1]][spanningTree[i]] = rand() % maxEdgeSize;;
        randGraph[spanningTree[i]][spanningTree[i + 1]] = rand() % maxEdgeSize;;
    }

    // remember to connect the first and last vertex in the spanning tree (since they have only 1 neighbour)
    randGraph[spanningTree[1]][spanningTree[vertex]] = rand() % maxEdgeSize;;
    randGraph[spanningTree[vertex]][spanningTree[1]] = rand() % maxEdgeSize;;


    // populate the vertices with edge - 2 edges
    // -2 as we already connected each node with left and right neighbours in the spanning tree
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
                if (fullCount == vertex)    break;      // prevent infinite loop
            }
            // exit if the current vertex is connected to all other vertices
            if (fullCount == vertex)    break;
            int weight = rand() % maxEdgeSize;
            randGraph[i][loc] = weight;

            remainder --;
        }
    }
}