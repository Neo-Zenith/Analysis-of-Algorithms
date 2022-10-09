#include "structures.h"

// insert into a min heap priority queue
// queue[] is an array-representation of a min heap
// *tail is a variable passed by reference for the last valid index in the queue
// vertex is the vertex to be added into queue
// dist is the distance of the vertex from start
void insert(QueueNode queue[MAX], int *tail, int vertex, int dist)
{
    (*tail) ++;             // increments the size of queue by 1

    // add the vertex to the queue
    queue[*tail].vertex = vertex;       
    queue[*tail].dist = dist;

    buildMinHeap(queue, tail);      // build a min heap from the queue based off dist values
}

// deletes the root (minimum) from the min heap priority queue
void delete(QueueNode queue[MAX], int *tail)
{
    // since the priority queue is a min heap, the first index is the vertex with lowest dist value
    // remove first index will suffice
    for (int i = 0; i < *tail; i ++)
    {
        queue[i] = queue[i + 1];    
    }

    (*tail) --;         // decrement queue size
}

// returns the vertex with the lowest dist value from the min heap priority queue
int getFront(QueueNode queue[MAX])
{
    return queue[0].vertex;
}

// check if the priority queue is empty
int isEmptyQueue(QueueNode queue[MAX], int *tail)
{
    if (*tail < 0)
    {
        return 1;
    }
    return 0;
}


// same as peek for custom data structure priority queue
// except this is for vanilla array
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