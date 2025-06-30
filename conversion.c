#include <stdbool.h>
#include <string.h>

#include "conversion.h"

/**
 * setOperator() sets the operator and precedence of an Operator
 * struct with the given input.
 * 
 * @param operator string containing operator
 * @param precedence number representing precedence of the operator
 * @returns Operator struct
 */
Operator
setOperator (char* operator, int precedence) 
{
    Operator temp;
    strcpy(temp.operator, operator);
    temp.precedence = precedence;
    return temp;
}

/**
 * initStoredOperators()  a predefined set of operator symbols 
 * and their corresponding precedence levels into the 
 * storedOperators array.   
 * 
 * @param storeOperators array where operators are stored
 */
void 
initStoredOperators (Operator storedOperators[18]) 
{
    storedOperators[0]  = setOperator("(", 8); // highest precedence (grouping symbol)
    storedOperators[1]  = setOperator(")", 8); 
    storedOperators[2]  = setOperator("!", 7); 
    storedOperators[3]  = setOperator("^", 6); 
    storedOperators[4]  = setOperator("*", 5);
    storedOperators[5]  = setOperator("/", 5);
    storedOperators[6]  = setOperator("%", 5);
    storedOperators[7]  = setOperator("+", 4);
    storedOperators[8]  = setOperator("-", 4);
    storedOperators[9]  = setOperator("<", 3);
    storedOperators[10] = setOperator("<=", 3);
    storedOperators[11] = setOperator(">", 3);
    storedOperators[12] = setOperator(">=", 3);
    storedOperators[13] = setOperator("==", 3);
    storedOperators[14] = setOperator("!=", 3);
    storedOperators[15] = setOperator("&&", 2); 
    storedOperators[16] = setOperator("||", 1); // lowest precedence (OR)
}

/**
 * getOperatorIdx() searches for the given operator in the array of stored operators
 * 
 * @param operator string containing operator
 * @param storedOperators array of initialized Operators
 * @return index if found, otherwise return -1
 */
int
getOperatorIdx (char* operator, Operator storedOperators[18]) 
{
    for (int i = 0; i < 18; i++)
        if (strcmp(operator, storedOperators[i].operator) == 0)
            return i;
    
    return -1;
}

/**
 * isLowerPrecedence() checks if operator1 is of lower precedence with
 * operator2
 * 
 * @param operator1
 * @param operator2
 * @returns true if operator1 has lower precedence than operator2, and
 * false if operator1 has a higher or equal precedence with operator2.
 * 
 * @note operator1 and operator2 must be found within the storedOperators
 */
bool
isLowerPrecedence (char* operator1, char* operator2, Operator storedOperators[18]) 
{
    int idx1 = getOperatorIdx(operator1, storedOperators); 
    int idx2 = getOperatorIdx(operator2, storedOperators);

    return storedOperators[idx1].precedence < storedOperators[idx2].precedence;
}

/**
 * isNumber() determines whether given char variable contains a number
 * 
 * @param c character variable to be checked
 * @return true if number, otherwise false
 */
bool
isNumber (char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

/**
 * isNumber() determines whether given string variable is an operand
 * 
 * @param string string to be checked
 * @return true if string contains only numbers, otherwise false
 */
bool 
isOperand (char* string) {
    int pos = strspn(string, "0123456789");
    return strlen(string) == pos;
}

/**
 * concatToPostfix() concatenates an operator or operand to postfix string
 * 
 * @param postfix destination string
 * @param op source string containing either operand or operator 
 */
void
concatToPostfix(char* postfix, char* op) 
{
    // Destination is empty
    if (strlen(postfix) == 0) {
        strcpy(postfix, op);
    }
    // Destination is not empty
    else {
        strcat(postfix, " ");
        strcat(postfix, op);
    }
}

/**
 * tokenizeInfix() splits an infix expression by operands and operators. This
 * function stores each token in the given infixQueue
 * 
 * @param infix string containing infix expression
 * @param infixQueue queue for storing tokens
 */
void
tokenizeInfix(char* infix, Queue* infixQueue, Operator storedOperators[]) {
    int cur = 0, tempCur;
    String256 temp;

    // Read infix until null operator is reached
    while (infix[cur] != '\0') {
        tempCur = 0;

        if (isNumber(infix[cur])) {
            temp[tempCur++] = infix[cur];
            cur++;

            // Read while character is a number
            while (infix[cur] != '\0' && isNumber(infix[cur])) {
                temp[tempCur++] = infix[cur++];
            }

            temp[tempCur] = '\0';
            enqueue(infixQueue, temp);
        }
        else {
            bool isOperator = false;
            // Check two-char operators
            if (infix[cur+1] != '\0') {
                char twoCharOperator[3];
                twoCharOperator[0] = infix[cur];
                twoCharOperator[1] = infix[cur+1];
                twoCharOperator[2] = '\0';

                if (getOperatorIdx(twoCharOperator, storedOperators) != -1) {
                     strcpy(temp, twoCharOperator);
                     cur += 2;
                     isOperator = true;
                }
            }

            // Assuming infix string is valid, current char is a one-char operator
            if (!isOperator) {
                temp[0] = infix[cur];
                temp[1] = '\0';
                cur++;
            }
            enqueue(infixQueue, temp);
        }
    }
}

/**
 * converToPostfix() translates an infix expression to a postfix expression.
 * 
 * @param infix string containing an infix expression
 * @param postfix string to contain resulting postfix expression 
 */
void
convertToPostfix (char* infix, char* postfix) 
{
    Operator operators[18];
    String256 temp;

    Queue infixQueue;
    Stack operatorStack;

    // Initialize Variables
    clearQueue(&infixQueue);
    clearStack(&operatorStack);
    initStoredOperators(operators);

    tokenizeInfix(infix, &infixQueue, operators);

    while (isEmptyQueue(&infixQueue) == false) {
        // Store first element in queue to temp
        strcpy(temp, dequeue(&infixQueue));

        // Check if temp stores an operand or an operator
        if (isOperand(temp)) {
            concatToPostfix(postfix, temp);
        }

        // Special handling for grouping symbol
        else if (strcmp(temp, "(") == 0) {
            pushStack(&operatorStack, temp);
        } 
        else if (strcmp(temp, ")") == 0){
            while (!isEmptyStack(&operatorStack) && strcmp(peekStack(&operatorStack), "(") != 0) {
                char* operator = popStack(&operatorStack);
                concatToPostfix(postfix, operator);
            }

            popStack(&operatorStack); // discard "("
        }

        // Handling for other operators
        else {
            // Check if operator stack is empty or top element of stack is of lower precedence than temp
            if (isEmptyStack(&operatorStack) || 
                isLowerPrecedence(peekStack(&operatorStack), temp, operators)) {
                pushStack(&operatorStack, temp);
            }
            else {
                // Pop operator stack until top element is lower precedence and is not a grouping symbol
                while (strcmp(peekStack(&operatorStack), "(") != 0 && 
                       !isLowerPrecedence(peekStack(&operatorStack), temp, operators)) {
                    char* operatorTemp = popStack(&operatorStack);
                    concatToPostfix(postfix, operatorTemp);
                }
                pushStack(&operatorStack, temp);
            }
        }
    }

    // Flush operators in operator stack
    while (!isEmptyStack(&operatorStack)) {
        char* operatorTemp = popStack(&operatorStack);
        if (strcmp(operatorTemp, "(") != 0) {
            concatToPostfix(postfix, operatorTemp);
        }
    }
}