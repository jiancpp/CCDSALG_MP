#ifndef STACK_H
#define STACK_H

typedef struct {
    int *collection;
    int capacity;
    int size;
} Stack;

Stack*  createStack     (int capacity);
void    destroyStack    (Stack *stack);
bool    isFull          (Stack *stack);
bool    isEmpty         (Stack *stack);
bool    pop             (Stack *stack, int *item);
bool    push            (Stack *stack, int *item);
bool    peek            (Stack *stack, int *item);

#endif