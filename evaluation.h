#ifndef EVALUATION_H
#define EVALUATION_H

#include "stack.h"
#include "queue.h"
#include "conversion.h"
#include "calculator.h"

// Declare functions here
void        tokenizePostfix      (String256 postfix, Queue* postfixQueue);    
int         parseToInt           (String256 number);
int         solve                (int operand1, int operand2, char* operator);
bool        evaluatePostfix      (Queue postfix, int* result);

#endif