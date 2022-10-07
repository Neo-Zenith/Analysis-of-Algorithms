#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


void MinHeapPathSearch(Graph *g, int start, int *visited, int *parent, int *dist)
{
    QueueNode pQueue[MAX];
    int tail = -1;

    for (int i = 1; i <= g->V; i ++)
    {
        visited[i] = 0;
        dist[i] = MAX_DIST;
        parent[i] = -1;
    }

    GraphNode *ptr = g->adjList[start];
    
    while (ptr != NULL)
    {
        if (ptr->weight != -1) 
        {
            insert(pQueue, &tail, ptr->vertex, ptr->weight);
            dist[ptr->vertex] = ptr->weight;
            parent[ptr->vertex] = start;
        }
        ptr = ptr->next;
    }

    visited[start] = 1;
    dist[start] = 0;

    while (! isEmptyQueue(pQueue, &tail))
    {
        int target = getFront(pQueue);
        visited[target] = 1;
        delete(pQueue, &tail);

        GraphNode *ptr = g->adjList[target];
        while (ptr != NULL)
        {
            if (visited[ptr->vertex] != 1 && ptr->weight != -1 && ptr->weight + dist[target] < dist[ptr->vertex]) 
            {
                dist[ptr->vertex] = ptr->weight + dist[target];
                insert(pQueue, &tail, ptr->vertex, dist[ptr->vertex]);
                parent[ptr->vertex] = target;
            }
            ptr = ptr->next;
        }
    }

    // printf("\n");
    // for (int i = 1; i <= g->V; i ++)
    // {
    //     printf("%d ", parent[i]);
    // }
    free(ptr);
}

void ArrayPathSearch(Graph *g, int start, int *visited, int *dist, int *parent)
{
    QueueNode pQueue[MAX];
    int tail = -1;

    for (int i = 1; i <= g->V; i ++)
    {
        visited[i] = 0;
        dist[i] = MAX_DIST;
        parent[i] = -1;
    
        if (g->adjMatrix[start][i] != -1) 
        {
            enqueue(pQueue, &tail, i, g->adjMatrix[start][i]);
            dist[i] = g->adjMatrix[start][i];
            parent[i] = start;
        }
    }

    visited[start] = 1;
    dist[start] = 0;

    while (! isEmptyQueue(pQueue, &tail))
    {
        int target = dequeue(pQueue, &tail);
        visited[target] = 1;
        
        for (int i = 1; i <= g->V; i ++)
        {
            
            if (visited[i] != 1 && g->adjMatrix[target][i] != -1 && g->adjMatrix[target][i] + dist[target] < dist[i]) 
            {
                dist[i] = g->adjMatrix[target][i] + dist[target];
                enqueue(pQueue, &tail, i, dist[i]);
                parent[i] = target;
            }
        }
    }

    // printf("\n");
    // for (int i = 1; i <= g->V; i ++)
    // {
    //     printf("%d ", parent[i]);
    // }
}

void printAdjMatrix(Graph *g)
{
    printf("\n===== Printing Adjacency Matrix =====\n");
    for (int i = 1; i <= g->V; i ++)
    {
        for (int j = 1; j <= g->V; j ++)
        {
            (g->adjMatrix[i][j] != -1) ? printf("%d\t", g->adjMatrix[i][j]): printf("#\t");
        }
        printf("\n");
    }
    printf("\nDone!\n");
}

void printAdjList(Graph *g)
{
    printf("\n===== Printing Adjacency List =====\n");
    for (int i = 1; i <= g->V; i ++)
    {
        GraphNode *ptr = g->adjList[i];
        printf("%d", i);
        while (ptr != NULL)
        {
            printf(" [--(%d)-->%d]", ptr->weight, ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
    printf("\nDone!\n");
}
