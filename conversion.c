#include "calculator.h"
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
 * initStoredOperators() initializes the operators that can be used   
 */
void 
initStoredOperators (Operator storedOperators[18]) 
{
    storedOperators[0]  = setOperator("(", 6); // highest precedence (grouping symbol)
    storedOperators[1]  = setOperator(")", 6); 
    storedOperators[2]  = setOperator("!", 5); 
    storedOperators[3]  = setOperator("^", 4); 
    storedOperators[4]  = setOperator("*", 3);
    storedOperators[5]  = setOperator("/", 3);
    storedOperators[6]  = setOperator("%", 3);
    storedOperators[7]  = setOperator("+", 2);
    storedOperators[8]  = setOperator("-", 2);
    storedOperators[9]  = setOperator("<", 1);
    storedOperators[10] = setOperator("<=", 1);
    storedOperators[11] = setOperator(">", 1);
    storedOperators[12] = setOperator(">=", 1);
    storedOperators[13] = setOperator("==", 1);
    storedOperators[14] = setOperator("!=", 1);
    storedOperators[15] = setOperator("&&", 0); 
    storedOperators[16] = setOperator("||", -1);
    storedOperators[17] = setOperator("=", -2); // lowest precedence (assignment)
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
        if (strcmp(operator, storedOperators[i].operator))
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

// For implementation @jia
void
tokenizeInfix(String256 infix, Queue* infixQueue) {
    // int cur = 0;
    // char temp[2];
    // temp[1] = '\0';

    // Queue tempQueue;

    // while (infix[cur] != '\0') {
    //     if (isNumber(infix[cur])) {
    //         temp[0] = infix[cur];
    //         enqueue(&tempQueue, temp);
    //     }
    // }
}

/**
 * converToPostfix() translates an infix expression to a postfix expression. The function
 * updates and returns a postfix queue and string
 * 
 * @param infix string containing an infix expression
 * @param postfixQueue queue to store tokenized postfix 
 * @return string in postfix
 */
char*
convertToPostfix (String256 infix, Queue* postfixQueue) 
{
    Operator operators[18];
    String256 temp;
    String256 postfix = "";

    Queue infixQueue;
    Stack operatorStack;

    // Initialize Variables
    clearQueue(&infixQueue);
    clearStack(&operatorStack);
    initStoredOperators(operators);

    tokenizeInfix(infix, &infixQueue);

    while (isEmptyQueue(&infixQueue) == false) {
        // Store first element in queue to temp
        strcpy(temp, dequeue(&infixQueue));

        // Check if temp stores an operand or an operator
        if (isOperand(temp)) {
            enqueue(postfixQueue, temp);
            concatToPostfix(postfix, temp);
        }
        else {
            // Check if operator stack is empty or top element of stack is of lower precedence than temp
            if (isEmptyStack(&operatorStack) || 
                isLowerPrecedence(peekStack(&operatorStack), temp, operators)) {
                pushStack(&operatorStack, temp);
            }
            else {
                // Pop operator stack until top element is lower precedence
                while (!isLowerPrecedence(peekStack(&operatorStack), temp, operators)) {
                    char* operatorTemp = popStack(&operatorStack);
                    enqueue(postfixQueue, operatorTemp);
                    concatToPostfix(postfix, operatorTemp);
                }
                pushStack(&operatorStack, temp);
            }
        }
    }

    // Flush operators in operator stack
    while (!isEmptyStack(&operatorStack)) {
        char* operatorTemp = popStack(&operatorStack);
        enqueue(postfixQueue, operatorTemp);
        concatToPostfix(postfix, operatorTemp);
    }

    return postfix;
}