#include <stdbool.h>
#include "structures.h"


void swap(QueueNode *a, QueueNode *b);
void heapify(QueueNode queue[MAX], int *tail, int root, bool maxMin);
void heapSort(QueueNode queue[MAX], int *tail, bool maxMin);
void buildMaxHeap(QueueNode queue[MAX], int *tail);
void buildMinHeap(QueueNode queue[MAX], int *tail);

void heapify(QueueNode queue[MAX], int *tail, int root, bool maxMin)
{
    int extrema = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left <= *tail && (maxMin ? queue[left].dist > queue[extrema].dist: queue[left].dist < queue[extrema].dist))
    {
        extrema = left;
    }

    if (right <= *tail && (maxMin ? queue[right].dist > queue[extrema].dist: queue[right].dist < queue[extrema].dist))
    {
        extrema = right;
    }

    if (extrema != root)
    {
        swap(&queue[extrema], &queue[root]);
        heapify(queue, tail, extrema, maxMin);
    }
}

void swap(QueueNode *a, QueueNode *b)
{
    QueueNode temp = *a;
    *a = *b;
    *b = temp;
}

void buildMaxHeap(QueueNode queue[MAX], int *tail)
{
    int start = *tail / 2;
    for (int i = start; i >= 0; i --)
    {
        heapify(queue, tail, i, true);
    }
}

void buildMinHeap(QueueNode queue[MAX], int *tail)
{
    int start = *tail / 2;
    for (int i = start; i >= 0; i --)
    {
        heapify(queue, tail, i, false);
    }
}

void heapSort(QueueNode queue[MAX], int *tail, bool maxMin)
{
    maxMin ? buildMinHeap(queue, tail): buildMaxHeap(queue, tail);

    for (int i = *tail; i >= 0; i --)
    {
        swap(&queue[i], &queue[0]);
        int j = i - 1;
        heapify(queue, &j, 0, maxMin);
    }
}