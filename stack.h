#ifndef STACK_H
#define STACK_H

#define CAPACITY (256);

typedef struct {
    String collection[256];
    int top;
} Stack;

Stack*  createStack     (Stack *stack);
void    clearStack      (Stack *stack);
bool    isFullStack     (Stack *stack);
bool    isEmptyStack    (Stack *stack);
char*   popStack        (Stack *stack);
void    pushStack       (Stack *stack, char* item);
char*   topStack        (Stack *stack);

#endif