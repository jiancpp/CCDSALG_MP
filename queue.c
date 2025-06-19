#include "calculator.h"
#include "queue.h"

// Define functions here

void
clearQueue (Queue *queue)
{
    queue->tail = -1;
}

bool
isFullQueue (Queue *queue)
{
    if (queue->tail == 254) {
        return true;
    } else return false;
}

bool
isEmptyQueue (Queue *queue)
{
    if (queue->tail == -1) {
        return true;
    } else return false;
}

char*
dequeue (Queue *queue)
{
    int i;
    String temp;

    strcpy (temp, queue->collection[0]);

    for (i = 0; i < (queue->tail) - 1; i++)
    {
        strcpy(queue->collection[i], queue->collection[i + 1]);
    }
        
    (queue->tail)--;

    return temp;
}

void
enqueue (Queue *queue, char* item)
{
    strcpy (queue->collection[queue->tail], item);
    (queue->tail)++;
}

char*
peekQueue (Queue *queue)
{
    return queue->collection[queue->tail];
}