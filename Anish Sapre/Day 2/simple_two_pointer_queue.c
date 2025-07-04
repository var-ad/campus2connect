//
// Created by Anish Sapre on 04/07/25.
//
#define MAX_QUEUE_LEN 64

typedef struct ring_queue {
    int value[MAX_QUEUE_LEN];
}