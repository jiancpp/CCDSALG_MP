#include "calculator.h"
#include "evaluation.h"

void sortPostfix(String postfix) 
{
    Stack operands;
    Stack operators;
    int cur, idxNumber;
    String number, op;

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
            push(stack, number);
        }
                    
        if(postfix[cur] != '/n' && postfix[cur] != '/0')
        {
            op[0] = postfix[cur];
            op[1] = '/0';
            push(stack, op);
            cur++;
        } else 
            cur++;
    }
}
