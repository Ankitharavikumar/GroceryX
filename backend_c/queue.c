#include <stdio.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int isFull(Queue *q) {
    return q->rear == QSIZE - 1;
}

void enqueue(Queue *q, char item[]) {
    if (isFull(q)) {
        printf("Shopping list is full\n");
        return;
    }
    q->rear++;
    strcpy(q->items[q->rear], item);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Shopping list is empty\n");
        return;
    }
    printf("Purchased item: %s\n", q->items[q->front]);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Shopping list is empty\n");
        return;
    }

    printf("Shopping List:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->items[i]);
    }
}
