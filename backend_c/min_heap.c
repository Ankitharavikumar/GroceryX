#include <stdio.h>
#include <string.h>
#include "min_heap.h"

void initHeap(MinHeap *h) {
    h->size = 0;
}

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *h, int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (h->heap[parent].expiry_days > h->heap[index].expiry_days) {
        swap(&h->heap[parent], &h->heap[index]);
        heapifyUp(h, parent);
    }
}

void insertHeap(MinHeap *h, HeapNode item) {
    if (h->size == MAX) {
        printf("Heap full\n");
        return;
    }

    h->heap[h->size] = item;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode getMin(MinHeap *h) {
    return h->heap[0];
}
