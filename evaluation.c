#include "calculator.h"
#include "evaluation.h"

void convertPostfixToQueue(String postfix, Queue* postfixQueue)
{
    int cur, idxNumber;
    String number, symbol;

    cur = 0;

    while(strlen(postfix) != 0)
    {
        while(postfix[cur] >= '0' && postfix[cur] <= 9)
        {
            number[idxNumber] = postfix[cur];
            idxNumber++;
            cur++;
        }

        if(idxNumber != 0)
        {
            number[idxNumber] = '/0';
            idxNumber = 0;
            enqueue(postfixQueue, number);
        }
                    
        if(postfix[cur] != '/n' && postfix[cur] != '/0')
        {
            symbol[0] = postfix[cur];
            symbol[1] = '/0';
            enqueue(postfixQueue, symbol);
            cur++;
        } else 
            cur++;
    }
}

int parseToInt(String number)
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

int compute_postfix(Queue postfix) {
    Stack operands;
    String token
    int cur, op1, op2;
    
    for(cur = 0; cur <= postfix.tail; cur++)
    {
        token = postfix.collection[cur];

        if(postfix.collection[cur][0] >= '0' && postfix.collection[cur][0] <= '9')
            push(operands, postfix.collection[cur]);
        else
        {
            op1 = parseToInt(pop(operands));
            op2 = parseToInt(pop(operands));
        }
    }
        
    for i = 1 to n {
        token = Postfix[i]
        if token is a value {
             push(S,token)
        } else {
            op2 = pop(S)
            op1 = pop(S)
            push(S,perform operation of token on op1 and op2)
        }
    }

    return pop(S)
}
