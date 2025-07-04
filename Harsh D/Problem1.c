
#include<stdio.h>

#define MAX_QUEUE_LEN 64

typedef struct ring_queue {

    int front;
    int rear;
    int value[MAX_QUEUE_LEN];

} rq_t;

int enqueue(int data , rq_t *rq);
int dequeue(rq_t *rq);
void printData(rq_t *rq);
int init(rq_t *rq);

#define CHECK(ret_val, msg)              \
    do {                                 \
        if ((ret_val) == 0) {                \
            printf("Error: %s\n", msg);  \
            return 0;                    \
        }                                \
    } while(0)

int init(rq_t *rq) {
    if(rq == NULL) {
        return 0;
    }
    rq->front = -1;
    rq->rear = -1;

    return 1;
}

int enqueue(int data , rq_t *rq) {

    if((rq->rear + 1) % MAX_QUEUE_LEN == rq->front) {
        return 0;
    }

    if(rq->front == -1 && rq->rear == -1) {
        rq->front = 0;
        rq->rear = 0;
    }
    else {
        rq->rear = (rq->rear + 1) % MAX_QUEUE_LEN;
    }

    rq->value[rq->rear] = data;

    return 1;
}

int dequeue(rq_t *rq) {
    if(rq->front == -1 && rq->rear == -1) {
        return 0;
    }
    else if(rq->front == rq->rear) {
        rq->front = -1;
        rq->rear = -1;
        return 0;
    }
    else {
        rq->front = (rq->front + 1) % MAX_QUEUE_LEN;
    }

    return 1;
}

void printData(rq_t *rq) {
    if(rq->front == -1 && rq->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = rq->front;
    while (1) {
        printf("%d ", rq->value[i]);
        if (i == rq->rear) {
            break;
        }
        i = (i + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
}

int main() {
    rq_t rq;
    init(&rq);
    CHECK(enqueue(1, &rq), "enqueue failed");
    CHECK(enqueue(2, &rq), "enqueue failed");
    CHECK(enqueue(3, &rq), "enqueue failed");
    CHECK(enqueue(4, &rq), "enqueue failed");
    CHECK(enqueue(5, &rq), "enqueue failed");
    printData(&rq);
    CHECK(dequeue(&rq), "dequeue failed");
    printData(&rq);
    CHECK(dequeue(&rq), "dequeue failed");
    printData(&rq);
    return 0;
}
