#include "calculator.h"
#include "queue.h"

// Define functions here

void
clearQueue (Queue *queue)
{
    queue->head = 0;
    queue->tail = -1;
}

bool
isFullQueue (Queue *queue)
{
    if (queue->tail == MAX_CAPACITY - 1) {
        return true;
    } else return false;
}

bool
isEmptyQueue (Queue *queue)
{
    if (queue->head > queue->tail) {
        return true;
    } else return false;
}

const char*
dequeue (Queue *queue)
{
    int i;

    const char *temp = queue->collection[queue->head];
    (queue->head)++;

    return temp;
}

void
enqueue (Queue *queue, char* item)
{
    // Note: Tail points to index of last added element
    (queue->tail)++; // incrementing to avoid overwriting previous element
    strcpy (queue->collection[queue->tail], item);
}

char*
peekQueue (Queue *queue)
{
    return queue->collection[queue->tail];
}