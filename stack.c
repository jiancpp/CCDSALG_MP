#include "calculator.h"

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

/*
    This function is used to initialize an empty dynamically allocated stack.

    @param capacity - the maximum size to be allocated to the stack
*/
Stack 
*createStack(int capacity) {

}

