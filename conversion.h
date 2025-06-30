#ifndef CONVERSION_H
#define CONVERSION_H

// Declare functions here
#include "stack.h"
#include "queue.h"
#include "calculator.h"

typedef struct
{
    char operator[3];
    int precedence;
} Operator;

Operator    setOperator             (char* operator, int precedence);
void        initStoredOperators     (Operator storedOperators[18]);
int         getOperatorIdx          (char* operator, Operator storedOperators[18]);
bool        isLowerPrecedence       (char* operator1, char* operator2, Operator storedOperators[18]);
bool        isNumber                (char c);
bool        isOperand               (char* string);
void        concatToPostfix         (char* postfix, char* op);
void        tokenizeInfix           (char* infix, Queue* infixQueue, Operator storedOperators[]);
void        convertToPostfix        (char* infix, Queue* postfixQueue, char* postfix);

#endif