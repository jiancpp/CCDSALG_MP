#ifndef EVALUATION_H
#define EVALUATION_H

// Declare functions here
#include "stack.h"
#include "queue.h"

void        tokenizePostfix      (String256 postfix, Queue* postfixQueue);    
int         parseToInt           (String256 number);
int         evaluatePostfix      (Queue postfix);

#endif