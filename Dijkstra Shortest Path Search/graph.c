#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "graphGenerate.c"


// helper function when building adjacency list
// basically a linked list insert to the end function
void enqueueGraphNode(GraphNode **head, int vertex, int weight)
{
    GraphNode *newNode = (GraphNode *) malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

// build adj list from adj matrix
void buildAdjList(Graph g)
{
    for (int i = 1; i <= g.V; i ++)
    {
        for (int j = 1; j <= g.V; j ++)
        {
            if (g.adjMatrix[i][j] != -1)
            {
                enqueueGraphNode(&(g.adjList[i]), j, g.adjMatrix[i][j]);
            }
        }
    }
}

// driver function to build graph with size vertices and out edges for each vertex
void buildGraph(Graph *g, int size, int out)
{
    printf("===== Building Graph with %d Edges=====\n", out);
    g->E = out * size;
    g->V = size;

    g->adjMatrix = (int **) malloc(sizeof(int *) * (g->V + 1));
    g->adjList= (GraphNode **) malloc(sizeof(GraphNode *) * (g->V + 1));

    // generate the graph in matrix form
    generateConnectedGraph(size, out, 100, g->adjMatrix);

    for (int i = 0; i <= g->V; i ++)
    {
        g->adjList[i] = NULL;
    }

    // build the adjacency list
    buildAdjList(*g);
    printf("Graph Compiled!\n");
}
