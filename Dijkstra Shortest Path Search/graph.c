#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "graphGenerate.c"

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

void buildGraph(Graph *g, int size)
{
    printf("===== Building Graph =====\n");
    g->E = 0;
    g->V = size;

    g->adjMatrix = (int **) malloc(sizeof(int *) * (g->V + 1));
    g->adjList= (GraphNode **) malloc(sizeof(GraphNode *) * (g->V + 1));

    graphGenerate(size, 10, 0, g->adjMatrix);

    for (int i = 0; i <= g->V; i ++)
    {
        g->adjList[i] = NULL;
    }

    for (int i = 1; i <= g->V; i ++)
    {
        for (int j = 1; j <= g->V; j ++)
        {
            if (g->adjMatrix[i][j] != -1)
            {
                g->E ++;
            }
        }
    }

    buildAdjList(*g);
    printf("Graph Compiled!\n");
}
