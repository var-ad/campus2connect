#include <stdio.h>

#define MAX_QUEUE_SIZE 64

// Ring Queue struct
typedef struct ring_queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} RingQueue;

// Initialize 
int rq_init(RingQueue *queue) {
    if (queue == NULL) return -1;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    return 0;
}

// Enqueue 
int rq_enqueue(RingQueue *queue, int element) {
    if (queue == NULL || queue->size == MAX_QUEUE_SIZE) return -1;
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
    return 0;
}

// dequeue 
int rq_dequeue(RingQueue *queue, int *element) {
    if (queue == NULL || queue->size == 0) return -1;
    *element = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return 0;
}


int main() {
    RingQueue q;
    rq_init(&q);

    int choice, num, result;

    while (1) {
        printf("\n--- Ring Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number to enqueue: ");
            scanf("%d", &num);
            result = rq_enqueue(&q, num);
            if (result == 0)
                printf("Enqueued %d\n", num);
            else
                printf("Queue is full! Cannot enqueue.\n");
             break;

        case 2:
            result = rq_dequeue(&q, &num);
               if (result == 0)
                  printf("Dequeued: %d\n", num);
            else
                printf("Queue is empty! Cannot dequeue.\n");
            break;

        case 3:
               printf("Exiting...\n");
            return 0;

        default:
              printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
