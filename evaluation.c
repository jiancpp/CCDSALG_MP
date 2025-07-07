#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"
#include "stack.h"
#include "queue.h"

/**
 * This function parses a number stored as a string into an integer.
 * 
 * @param number string containing the number to be parsed
 * @return integer form of the number
 */
int 
parseToInt(String256 number)
{
    int i, size, power, integer;

    size = strlen(number);
    power = 1;
    integer = 0;

    // Reads each digit of the number from right to left
    for(i = size - 1; i >= 0; i--)
    {
        switch(number[i]) 
        {
            case '1': 
                integer = integer + power * 1;
                break;
            case '2': 
                integer = integer + power * 2;
                break;
            case '3': 
                integer = integer + power * 3;
                break;
            case '4': 
                integer = integer + power * 4;
                break;
            case '5': 
                integer = integer + power * 5;
                break;
            case '6': 
                integer = integer + power * 6;
                break;
            case '7': 
                integer = integer + power * 7;
                break;
            case '8': 
                integer = integer + power * 8;
                break;
            case '9': 
                integer = integer + power * 9;
                break;
            case '-':
                integer = 0  - integer;
        }

        if (number[i] != '-')
            // Increase the place value of each digit by 1
            power *= 10;
    }

    return integer;
}

/**
 * This function takes an operator and applies the corresponding operation  
 * on one or two operands, depending on the type of operation.
 * 
 * @param operand1 integer on the left side of the operation.
 * @param operand1 integer on the right side of the operation
 * @return integer form of the answer
 */
int
solve(int operand1, int operand2, char* operator) {
    if (strcmp(operator, "+") == 0) {
        return operand1 + operand2;
    } else if (strcmp(operator, "-") == 0) {
        return operand1 - operand2;
    } else if (strcmp(operator, "*") == 0) {
        return operand1 * operand2;
    } else if (strcmp(operator, "/") == 0) {
        return operand1 / operand2;
    } else if (strcmp(operator, "^") == 0) {
        return (int)pow(operand1, operand2);   
    } else if (strcmp(operator, "%") == 0) {
        return operand1 % operand2;
    } else if (strcmp(operator, ">") == 0) {
        return operand1 > operand2;
    } else if (strcmp(operator, "<") == 0) {
        return operand1 < operand2;
    } else if (strcmp(operator, ">=") == 0) {
        return operand1 >= operand2;
    } else if (strcmp(operator, "<=") == 0) {
        return operand1 <= operand2;
    } else if (strcmp(operator, "!=") == 0) {
        return operand1 != operand2;
    } else if (strcmp(operator, "==") == 0) {
        return operand1 == operand2;
    } else if (strcmp(operator, "!") == 0) {
        return !operand1;
    } else if (strcmp(operator, "&&") == 0) {
        return operand1 && operand2;
    } else
        return operand1 || operand2;
}

/**
 * This function takes a postfix queue and evaluates its contents.
 * It reads the queue, stacks the operands, and computes once an
 * operator is encountered.
 * 
 * @param postfix queue containing postfix tokens
 * @param result integer that stores the evaluated value
 * @return (a) true if the evaluation is successful;
 *         (b) false otherwise.
 */
bool 
evaluatePostfix(Queue postfix, int* result) {
    Stack operands;

    String256 token, ans;
    int operand1, operand2;
    bool isEvaluated;

    // Initialize
    clearStack(&operands);
    isEvaluated = true;
    operands.top = 0;

    
    // Read each token in the queue
    while (!isEmptyQueue(&postfix))
    {
        // Store the new token in a variable
        strcpy(token, dequeue(&postfix));

        // Initialize operands
        operand1 = 0;
        operand2 = 0;

        if(isOperand(token) && !isFullStack(&operands))
            // Push an operand into the stack
            pushStack(&operands, token);
        else
        {
            // Check for a unary operator
            if (strcmp(token, "!") == 0) {
                operand1 = parseToInt(popStack(&operands));
                sprintf(ans, "%d", solve(operand1, operand2, token));
                // Push the answer into the stack
                if (!isFullStack(&operands))
                    pushStack(&operands, ans);
            } else {
                operand2 = parseToInt(popStack(&operands));
                operand1 = parseToInt(popStack(&operands));

                // Check for division by 0 error
                if (!((strcmp(token, "/") == 0 || strcmp(token, "%") == 0) && operand2 == 0)) {
                    sprintf(ans, "%d", solve(operand1, operand2, token));
                    if (!isFullStack(&operands))
                        pushStack(&operands, ans); 
                } else
                    isEvaluated = false;
            }
        }
    }

    // Set evaluated value if the evaluation is successful
    if (isEvaluated && !isEmptyStack(&operands))
        *result = parseToInt(popStack(&operands));

    return isEvaluated;
}
