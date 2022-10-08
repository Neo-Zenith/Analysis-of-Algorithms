#include <stdbool.h>
#include "structures.h"

void swap(QueueNode *a, QueueNode *b);
void heapify(QueueNode queue[MAX], int *tail, int root, bool maxMin);
void heapSort(QueueNode queue[MAX], int *tail, bool maxMin);
void buildMaxHeap(QueueNode queue[MAX], int *tail);
void buildMinHeap(QueueNode queue[MAX], int *tail);


// function to transform an array-based tree into a heap
/*  Algorithm (for maxHeap)
        1. Starting at root, compare its value with its children
        2. If root is already largest, then we are done
        3. Otherwise we swap root with largest child
        4. Then recursively perform heapify with the subtree that has the root as root
        5. Returns when we hit the leaf

    Time Complexity: O(log n)
*/  
void heapify(QueueNode queue[MAX], int *tail, int root, bool maxMin)
{
    int extrema = root;
    int left = 2 * root + 1;    // 0-index based, so a +1 transform is required
    int right = 2 * root + 2;

    // compare with left child
    if (left <= *tail && (maxMin ? queue[left].dist > queue[extrema].dist: queue[left].dist < queue[extrema].dist))
    {
        extrema = left;
    }

    // compare with right child
    if (right <= *tail && (maxMin ? queue[right].dist > queue[extrema].dist: queue[right].dist < queue[extrema].dist))
    {
        extrema = right;
    }

    // root is not largest
    if (extrema != root)
    {
        swap(&queue[extrema], &queue[root]);        // swap root with largest
        heapify(queue, tail, extrema, maxMin);      // heapify the subtree
    }
}

// helper function to swap two queuenodes
void swap(QueueNode *a, QueueNode *b)
{
    QueueNode temp = *a;
    *a = *b;
    *b = temp;
}

// function to build a maximum heap
/*  Algorithm
        1. Starting with the rightmost node with children (i.e. rightmost node at level height - 1)
        2. Perform heapify process on that tree
        3. Recursively do heapify process on the nodes before it until we reach the root
    
    Time Complexity: O(n log n)
*/
void buildMaxHeap(QueueNode queue[MAX], int *tail)
{
    int start = *tail / 2;
    for (int i = start; i >= 0; i --)
    {
        heapify(queue, tail, i, true);
    }
}

// similar to building a max heap except we use minimum as extrema
void buildMinHeap(QueueNode queue[MAX], int *tail)
{
    int start = *tail / 2;
    for (int i = start; i >= 0; i --)
    {
        heapify(queue, tail, i, false);
    }
}

// heapsort algorithm to sort an array 
/*  Algorithm:
        1. We first build a heap from the array
        2. We swap the root and last element of the array (i.e. deleting root and swapping last to root)
        3. We heapify this new tree with n - 1 nodes
        4. We keep doing 2 and 3 until we have no more nodes in the heap
        5. We then have a sorted array
    
    Time Complexity: O(n log n)
*/
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