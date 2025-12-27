#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define MAX 100

typedef struct {
    int expiry_days;
    char name[50];
} HeapNode;

typedef struct {
    HeapNode heap[MAX];
    int size;
} MinHeap;

void initHeap(MinHeap *h);
void insertHeap(MinHeap *h, HeapNode item);
HeapNode getMin(MinHeap *h);
void heapifyUp(MinHeap *h, int index);

#endif
