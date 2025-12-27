#ifndef QUEUE_H
#define QUEUE_H

#define QSIZE 50

typedef struct {
    char items[QSIZE][50];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, char item[]);
void dequeue(Queue *q);
void displayQueue(Queue *q);

#endif
