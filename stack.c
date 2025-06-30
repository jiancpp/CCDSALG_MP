#include <stdbool.h>
#include <string.h>

#include "calculator.h"
#include "stack.h"

/*
    This function is used to initialize an empty dynamically allocated stack.

    @param capacity - the maximum size to be allocated to the stack
*/

void
clearStack (Stack *stack)
{
    stack->top = -1;
}

bool
isFullStack (Stack *stack)
{
    if (stack->top == 254) {
        return true;
    } else return false;
}

bool
isEmptyStack (Stack *stack)
{
    if (stack->top == -1) {
        return true;
    } else return false;
}

const char*
popStack (Stack *stack)
{
    const char *temp = stack->collection[stack->top];
    (stack->top)--;
    
    return temp;
}

void
pushStack (Stack *stack, char* item)
{
    (stack->top)++;
    strcpy(stack->collection[stack->top], item);
}

char*
peekStack (Stack *stack)
{
    return stack->collection[stack->top];
}
