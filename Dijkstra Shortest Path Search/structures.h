#ifndef STRUCTURES_H_
#define STRUCTURES_H_
#define MAX 10000
#define MAX_DIST 10000

typedef struct graphNode
{
    int vertex;
    int weight;
    struct graphNode *next;
}   GraphNode;

typedef struct graph
{
    int **adjMatrix;
    GraphNode **adjList;
    int V;
    int E;
}   Graph;

typedef struct queueNode
{
    int vertex;
    int dist;
}   QueueNode;
#endif
