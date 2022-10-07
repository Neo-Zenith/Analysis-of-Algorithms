#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.c"
#include "queue.c"
#include "graph.c"
#include "pathSearch.c"
#include "output.c"

void benchmarkPartA()
{
    printf("===== Benchmarking Dijkstra's Shortest Path Algorithm =====\n");
    printf("Parameters:\n");
    printf("Graph: \tAdjacency Matrix\n");
    printf("Priority Queue: \tVanilla Array");
    printf("\n===== Initialization =====\n");
    char *file = "./datasets/PartA.csv";
    writeFile(file, "Vertices,Edges,Start Vertex,Elapsed Time\n");
    printf("Initialization Completed!\n");

    for (int i = 100; i <= 5000; i += 100)
    {
        printf("\n===== Epoch Size %d =====\n", i);
        Graph *g = (Graph *) malloc(sizeof(Graph));
        buildGraph(g, i);
        //printAdjMatrix(g);    //  for debug
        //printAdjList(g);      //  for debug
        float sumOfTime = 0;
        for (int j = 1; j <= i; j ++)
        {
            int *visited = (int *) malloc(sizeof(int) * (g->V + 1));
            int *dist = (int *) malloc(sizeof(int) * (g->V + 1));
            int *parent = (int *) malloc(sizeof(int) * (g->V + 1));
            
            clock_t begin = clock();    // FKeep track of CPU time (start)
            ArrayPathSearch(g, j, visited, dist, parent);
            clock_t end = clock();    // FKeep track of CPU time (start)
            sumOfTime += ((float)(end - begin) / CLOCKS_PER_SEC);     // Get time spent

            free(visited);
            free(parent);
            free(dist);
        }

        free(g->adjList);
        free(g->adjMatrix);
        free(g);

        float avgTime = sumOfTime / i;
        writeIntOutput(file, g->V, ",");
        writeIntOutput(file, g->E, ",");
        writeDoubleOutput(file, avgTime, "\n");
        printf("===== Epoch Completed! =====\n");
        printf("Block runtime: %.4fs\n", avgTime);
        printf("\tTotal runtime: %.4fs\n", sumOfTime);
    }
    printf("\n Benchmark Completed!\n");
    
}

void benchmarkPartB()
{
    for (int i = 100; i <= 5000; i += 100)
    {
        Graph *g = (Graph *) malloc(sizeof(Graph));
        buildGraph(g, i);
        //printAdjMatrix(g);    //  for debug
        //printAdjList(g);      //  for debug
        
        printf("\n===== Initialization =====\n");
        char *file = "./datasets/PartB.csv";
        writeFile(file, "Vertices,Edges,Elapsed Time\n");
        int *visited = (int *) malloc(sizeof(int) * (g->V + 1));
        int *dist = (int *) malloc(sizeof(int) * (g->V + 1));
        int *parent = (int *) malloc(sizeof(int) * (g->V + 1));
        printf("\nInitialization Completed!\n");
    
        printf("\n===== Benchmarking Dijkstra's Shortest Path Algorithm =====\n");
        printf("Parameters:\n");
        printf("Graph: \tAdjacency List\n");
        printf("Priority Queue: \tMin Heap");
        clock_t begin = clock();    // FKeep track of CPU time (start)
        MinHeapPathSearch(g, 2, visited, dist, parent);
        clock_t end = clock();    // FKeep track of CPU time (start)
        float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;     // Get time spent

        writeIntOutput(file, g->V, ",");
        writeIntOutput(file, g->E, ",");
        writeDoubleOutput(file, time_spent, "\n");
        printf("\n Benchmark Completed!\n");

        free(g->adjList);
        free(g->adjMatrix);
        free(g);
        free(visited);
        free(parent);
        free(dist);
    }
}