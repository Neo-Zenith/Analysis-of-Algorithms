#include "structures.h"

// insert into a min heap priority queue
// queue[] is an array-representation of a min heap
// *tail is a variable passed by reference for the last valid index in the queue
// vertex is the vertex to be added into queue
// dist is the distance of the vertex from start
void enqueue(QueueNode queue[MAX], int *tail, int vertex, int dist)
{
    insert(queue, tail, vertex, dist);
}

// deletes and returns the root (minimum) from the min heap priority queue
int dequeue(QueueNode queue[MAX], int *tail)
{
    return extractMin(queue, tail);
}

// check if the min heap priority queue is empty
int isEmptyQueue(QueueNode queue[MAX], int *tail)
{
    if (*tail < 0)
    {
        return 1;
    }
    return 0;
}


// we use the existing dist array to find the extrema
int findExtrema(int *dist, int *visited, int vertex, bool maxMin)
{
    int highestPriority;
    int highestPriorityIndex = -1;
    if (maxMin)     
    {
        highestPriority = -1;
        for (int i = 1; i <= vertex; i ++)
        {
            if (dist[i] > highestPriority && ! visited[i])
            {
                highestPriority = dist[i];
                highestPriorityIndex = i;
            }
        }
    }
    else
    {
        highestPriority = MAX_DIST;
        for (int i = 1; i <= vertex; i ++)
        {
            if (dist[i] < highestPriority && ! visited[i])
            {
                highestPriority = dist[i];
                highestPriorityIndex = i;
            }
        }
    }

    return highestPriorityIndex;
}