#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"

int main() {
    String256 infix;
    String256 postfix;
    int answer;

    while (scanf("%s", infix) == 1 && strcmp(infix, "QUIT") != 0) {
        postfix[0] = '\0';

        convertToPostfix(infix, postfix);

        printf("%s\n", infix);
        printf("%s\n", postfix);

        if (evaluatePostfix(postfix))
            printf("%d\n\n", answer);
        else
            printf("Division by zero error!\n\n");
    }
}
