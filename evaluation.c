#include <stdbool.h>
#include <string.h>

#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"
#include "stack.h"
#include "queue.h"

void 
tokenizePostfix(String256 postfix, Queue* postfixQueue)
{
    int cur, operandIdx, operatorIdx;
    String256 operand, operator;

    cur = 0;

    while (strlen(postfix) > cur)
    {
        if (postfix[cur] == ' ')
            cur++;

        memset(operand, 0, sizeof(operand));
        memset(operand, 0, sizeof(operator));
        operandIdx = 0;
        operatorIdx = 0;

        while (isNumber(postfix[cur]))
        {
            operand[operandIdx] = postfix[cur];
            operandIdx++;
            cur++;
        }

        if (operandIdx != 0)
        {
            operand[operandIdx] = '\0';
            printf("\n%s", operand);
            enqueue(postfixQueue, operand);
        }
                    
        while (postfix[cur] != ' ' && postfix[cur] != '\0')
        {
            operator[operatorIdx] = postfix[cur];
            operatorIdx++;
            cur++;
        }

        if (operatorIdx != 0)
        {
            operator[operatorIdx] = '\0';
            printf("\n%s", operator);
            enqueue(postfixQueue, operator);
        }
    }
}

int 
parseToInt(String256 number)
{
    int i, size, power, integer;

    size = strlen(number);
    power = 1;
    integer = 0;

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
        }

        power *= 10;
    }

    return integer;
}

int
solve(int op1, int op2, char* operator) {
    if (strcmp(operator, "+") == 0) {
        return op1 + op2;
    } else if (strcmp(operator, "-") == 0) {
        return op1 - op2;
    } else if (strcmp(operator, "*") == 0) {
        return op1 * op2;
    } else if (strcmp(operator, "/") == 0) {
        return op1 / op2;
    } else if (strcmp(operator, "^") == 0) {
        int ans = 1;

        if (op2 == 0)
            return ans;

        for (int i = 0; i < op2; i++)
            ans *= op1;

        return ans;    
    } else if (strcmp(operator, "%") == 0) {
        return op1 % op2;
    } else if (strcmp(operator, ">") == 0) {
        return op1 > op2;
    } else if (strcmp(operator, "<") == 0) {
        return op1 < op2;
    } else if (strcmp(operator, ">=") == 0) {
        return op1 >= op2;
    } else if (strcmp(operator, "<=") == 0) {
        return op1 <= op2;
    } else if (strcmp(operator, "!=") == 0) {
        return op1 != op2;
    } else if (strcmp(operator, "==") == 0) {
        return op1 == op2;
    } else if (strcmp(operator, "!") == 0) {
        return !op1;
    } else if (strcmp(operator, "&&") == 0) {
        return op1 && op2;
    } else if (strcmp(operator, "||") == 0) {
        return op1 || op2;
    }
}

int 
evaluatePostfix(Queue postfix) {
    Stack operands;
    String256 token, ans;
    int cur, op1, op2;

    operands.top = 0;
    
    for(cur = 0; cur <= postfix.tail; cur++)
    {
        strcpy(token, dequeue(&postfix));
        op1 = 0;
        op2 = 0;

        if(isOperand(token))
            pushStack(&operands, token);
        else
        {
            if (strcmp(token, "!") == 0) {
                op1 = parseToInt(popStack(&operands));
                sprintf(ans, "%d", solve(op1, op2, token));
                pushStack(&operands, ans);
            } else {
                op2 = parseToInt(popStack(&operands));
                op1 = parseToInt(popStack(&operands));
                sprintf(ans, "%d", solve(op1, op2, token));
                pushStack(&operands, ans);
            }
        }
    }

    return parseToInt(ans);
}
