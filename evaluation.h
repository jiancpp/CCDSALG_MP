#ifndef EVALUATION_H
#define EVALUATION_H

#include "stack.h"
#include "queue.h"
#include "conversion.h"
#include "calculator.h"

// Declare functions here
void        tokenizePostfix      (String256 postfix, Queue* postfixQueue);    
int         parseToInt           (String256 number);
int         evaluatePostfix      (Queue postfix);

#endif