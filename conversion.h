#ifndef CONVERSION_H
#define CONVERSION_H

#include "stack.h"
#include "queue.h"

// Declare functions here
typedef struct
{
    char operator[3];
    int precedence
} Operator;

Operator    setOperator             (char* operator, int precedence);
void        initStoredOperators     (Operator storedOperators[18]);
int         getOperatorIdx          (char* operator, Operator storedOperators[18]);

#endif