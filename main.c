#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main.h"
#include "conversion.h"
#include "evaluation.h"
#include "queue.h"

int main() {
    // Declare variables
    String256 infix;
    int answer;

    Queue postfix;

    while (scanf("%s", infix) == 1 && strcmp(infix, "QUIT") != 0) {
        clearQueue(&postfix);

        convertToPostfix(infix, &postfix);

        // Display infix expression
        printf("%s\n", infix);
        
        // Display postfix expression
        displayPostfix(postfix);

        // Display answer after evaluation
        if (evaluatePostfix(postfix, &answer))
            printf("%d\n\n", answer);
        else
            printf("Division by zero error!\n\n");
    }
}
