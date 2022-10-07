#include "structures.h"

// insert into a min heap priority queue
// queue[] is an array-representation of a min heap
// *tail is a variable passed by reference for the last valid index in the queue
// vertex is the vertex to be added into queue
// dist is the distance of the vertex from start
void insert(QueueNode queue[MAX], int *tail, int vertex, int dist)
{
    if (*tail >= MAX)       // prevent buffer overflow and segfault by restricting access beyond MAX
    {
        return;
    }

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

// returns the vertex with the lowest dist value from an array
// *index is a variable passed by reference for the index of the vertex to be deleted in the array
// this function is only called by dequeue to prevent double accessing array just to obtain the vertex
int peek(QueueNode queue[MAX], int *tail, int *index)
{
    int highestPriority = MAX_DIST;   
    int highestPriorityVertex = -1; 

    for (int i = 0; i <= *tail; i ++)
    {
        if (queue[i].dist < highestPriority)
        {
            highestPriority = queue[i].dist;  
            highestPriorityVertex = queue[i].vertex;
            *index = i;
        }
    }

    return highestPriorityVertex;
}

// enqueue adds a vertex into the priority queue array
void enqueue(QueueNode queue[MAX], int *tail, int vertex, int dist)
{
    if (*tail >= MAX)
    {
        return;
    }

    (*tail) ++;
    queue[*tail].vertex = vertex;
    queue[*tail].dist = dist;
}

// dequeue removes and returns the vertex with lowest dist value
int dequeue(QueueNode queue[MAX], int *tail)
{
    int index;      // get the location of the vertex to be removed
    int vertex = peek(queue, tail, &index);     // vertex to be removed

    for (int i = index; i <= *tail; i ++)
    {
        queue[i] = queue[i + 1];            // remove the vertex
    }
    (*tail) --;         // decrement queue size by 1

    return vertex;
}