//
// Created by Anish Sapre on 04/07/25.
//
#define MAX_QUEUE_LEN 64

typedef struct ring_queue{
    int front;
    int rear;
    int size;
    int value[MAX_QUEUE_LEN];
} rq_t;


int rq_init(rq_t *q) {
    if(q == NULL){
        return -1;
    }
    (*q).front = 0;
    (*q).rear = 0;
    (*q).size = 0;
    return 0;
}

int rq_enqueue(rq_t *q, int value) {
    if ((*q).size == MAX_QUEUE_LEN || (*q).size == MAX_QUEUE_LEN) {
        return -1;
    }
    (*q).value[(*q).rear] = value;
    (*q).rear = ((*q).rear + 1) % MAX_QUEUE_LEN;
    (*q).size++;
    printf("ENQUEUED: %d\n",value);
    return 0;
}

int rq_dequeue(rq_t *q, int value){
    if ((*q).size == 0 || q == NULL) {
        return -1;
    }
    (*q).value[(*q).front] = value;
    (*q).front = ((*q).front + 1) % MAX_QUEUE_LEN;
    (*q).size--;
    printf("DEQUEUED: %d\n",value);
    return 0;
}

int main() {
    rq_t q;
    rq_init(&q);
    rq_enqueue(&q, 1);
    rq_enqueue(&q, 2);
    return 0;
}