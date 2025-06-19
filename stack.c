#include "calculator.h"
#include "stack.h"

/*
    This function is used to initialize an empty dynamically allocated stack.

    @param capacity - the maximum size to be allocated to the stack
*/

Stack*
createStack (Stack *stack)
{
    stack->top = -1;
}

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

char*
popStack (Stack *stack)
{
    (stack->top)--;
    return stack->collection[stack->top + 1];
}

char*
topStack (Stack *stack)
{
    return stack->collection[stack->top];
}

void
pushStack (Stack *stack, char* item)
{
    (stack->top)++;
    strcpy(stack->collection[stack->top], item);
}
