#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"

void 
tokenizePostfix(String256 postfix, Queue* postfixQueue)
{
    int cur, operandIdx, operatorIdx;
    String256 operand, operator;

    cur = 0;
    operandIdx = 0;
    operatorIdx = 0;

    while (strlen(postfix) > cur)
    {
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
            operandIdx = 0;
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
            operatorIdx = 0;
            enqueue(postfixQueue, operator);
        }
        
        if (postfix[cur] == ' ')
            cur++;
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
evaluatePostfix(Queue postfix) {
    Stack operands;
    String256 token;
    int cur, op1, op2;
    
    for(cur = 0; cur <= postfix.tail; cur++)
    {
        strcpy(token, postfix.collection[cur]);

        if(isOperand(postfix.collection[cur][0]))
            pushStack(&operands, postfix.collection[cur]);
        else
        {
            op1 = parseToInt(popStack(&operands));
            op2 = parseToInt(popStack(&operands));
        }
    }
        
    // for i = 1 to n {
    //     token = Postfix[i]
    //     if token is a value {
    //          push(S,token)
    //     } else {
    //         op2 = pop(S)
    //         op1 = pop(S)
    //         push(S,perform operation of token on op1 and op2)
    //     }
    // }

    // return pop(S)
}