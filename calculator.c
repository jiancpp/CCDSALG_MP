#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"

int main() {
    // Declare variables
    String256 infix;
    String256 postfix;
    int answer;

    while (scanf("%s", infix) == 1 && strcmp(infix, "QUIT") != 0) {
        postfix[0] = '\0'; // Clear postfix string

        convertToPostfix(infix, postfix);

        // Display infix and postfix expressions
        printf("%s\n", infix);
        printf("%s\n", postfix);

        // Display answer after evaluation
        if (evaluatePostfix(postfix, &answer))
            printf("%d\n\n", answer);
        else
            printf("Division by zero error!\n\n");
    }
}
