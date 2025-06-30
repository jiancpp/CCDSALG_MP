#ifndef CONVERSION_H
#define CONVERSION_H

// Declare functions here
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
void        tokenizeInfix           (String256 infix, Queue* infixQueue);
char*       convertToPostfix        (String256 infix, Queue* postfixQueue);

#endif