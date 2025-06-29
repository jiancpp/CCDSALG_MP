#include "calculator.h"
#include "stack.h"
#include "queue.h"

/*

- Tokenize by operator
- Push operand to postfix queue
- Check if operator at the top of the stack is of higher precedence. If no, push to stack. If yes, push all 
  operators in the stack to the postfix queue
- Do until infix is done

*/

/*
    getPostfix -> queue

    getOperands -> queue

    getOperators -> stack

    storeOperators -> stack

*/