#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    String256 collection[256];
    int tail; // index of last added element
    int head; // index of first added element
} Queue;

void        initQueue       (Queue *queue);
void        clearQueue      (Queue *queue);
bool        isFullQueue     (Queue *queue);
bool        isEmptyQueue    (Queue *queue);
void        enqueue         (Queue *queue, char* item);
const char* dequeue         (Queue *queue);
char*       peekQueue       (Queue *queue);

// Declare functions here

#endif