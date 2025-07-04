#include <stdio.h>
#include <stdlib.h>

/*
Problem Statement

Implement a FIFO ring queue of integers using an array
Add code for rq_init,rq_enqueue and rq_dequeue
All functions should return -1 if error occurs otherwise 0 if successful

you will need to add the members to below structure

*/

#define MAX_QUEUE_LEN 64

typedef struct ring_queue
{

    int value[MAX_QUEUE_LEN];
    int rear;
    int front;

} rq_t;

// init ring queue
int rq_init(rq_t *q)
{

    q->front = -1;
    q->rear = -1;
    return 0;
}

// add value at end of ring queue
int rq_enqueue(rq_t *q, int value)
{
    if ((q->rear + 1) % MAX_QUEUE_LEN == q->front)
    {
        printf("queue is full\n");
        return -1;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }
    printf("rear is at:%d\n", q->rear);

    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    q->value[q->rear] = value;

    printf("value enqueued:%d\n", q->value[q->rear]);
    printf("rear is at:%d\n", q->rear);
    printf("--------------------------\n");
    return 1;
}

// remove value
int rq_dequeue(rq_t *q)
{
    if (q->front == -1)
    {
        printf("queue is empty\n");
        return -1;
    }
    printf("front is at:%d\n", q->front);

    int val = q->value[q->front];
    printf("dequed value:%d\n", val);

    // single element dequeued
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX_QUEUE_LEN;
        printf("front is at:%d\n", q->front);
        printf("----------------------------------\n");
    }

    return 0;
}

int main()
{

    rq_t q;
    rq_init(&q);
    rq_enqueue(&q, 3);
    rq_enqueue(&q, 5);
    rq_enqueue(&q, 6);

    rq_dequeue(&q);  // 3 dequeued

    rq_enqueue(&q, 10);

    rq_dequeue(&q); // 5
    rq_dequeue(&q); // 6
    rq_dequeue(&q); // 10
    rq_dequeue(&q);// empty
    rq_dequeue(&q);//empty
}