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
    writeFile(file, "Vertices,Edges,Elapsed Time\n");
    printf("Initialization Completed!\n");

    for (int i = 100; i <= 2500; i += 100)
    {
        printf("\n===== Epoch Size %d =====\n", i);
        for (int j = 1; j < i - 1; j *= 2)
        {
            Graph *g = (Graph *) malloc(sizeof(Graph));
            buildGraph(g, i, j);
            //printAdjMatrix(g);    //  for debug
            //printAdjList(g);      //  for debug
            float sumOfTime = 0;
            for (int k = 1; k <= i; k ++)
            {
                int *visited = (int *) malloc(sizeof(int) * (g->V + 1));
                int *dist = (int *) malloc(sizeof(int) * (g->V + 1));
                int *parent = (int *) malloc(sizeof(int) * (g->V + 1));
                
                clock_t begin = clock();    // FKeep track of CPU time (start)
                ArrayPathSearch(g, k, visited, dist, parent);
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
            printf("Total runtime: %.4fs\n", sumOfTime);
        }
    }
    printf("\n Benchmark Completed!\n");
    
}

void benchmarkPartB()
{
    printf("===== Benchmarking Dijkstra's Shortest Path Algorithm =====\n");
    printf("Parameters:\n");
    printf("Graph: \tAdjacency List\n");
    printf("Priority Queue: \tMin Heap");
    printf("\n===== Initialization =====\n");
    char *file = "./datasets/PartB.csv";
    writeFile(file, "Vertices,Edges,Elapsed Time\n");
    printf("Initialization Completed!\n");

    for (int i = 100; i <= 2500; i += 100)
    {
        int edgeList[5] = {1, (i - 1) / 4, (i - 1) / 2, 3*(i - 1)/4, i - 1};
        printf("\n===== Epoch Size %d =====\n", i);
        for (int j = 0; j < 5; j ++)
        {
            Graph *g = (Graph *) malloc(sizeof(Graph));
            buildGraph(g, i, edgeList[j]);
            //printAdjMatrix(g);    //  for debug
            //printAdjList(g);      //  for debug
            float sumOfTime = 0;
            for (int k = 1; k <= i; k ++)
            {
                int *visited = (int *) malloc(sizeof(int) * (g->V + 1));
                int *dist = (int *) malloc(sizeof(int) * (g->V + 1));
                int *parent = (int *) malloc(sizeof(int) * (g->V + 1));
                
                clock_t begin = clock();    // FKeep track of CPU time (start)
                MinHeapPathSearch(g, k, visited, dist, parent);
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
            printf("Total runtime: %.4fs\n", sumOfTime);
        }
    }
    printf("\n Benchmark Completed!\n");
    
}
