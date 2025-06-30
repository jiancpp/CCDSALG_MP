#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "calculator.h"
#include "conversion.h"
#include "evaluation.h"
#include "queue.h"

int main() {
    String256 infix;
    String256 postfix;
    int answer;

    Queue postfixQueue;

    while (scanf("%s", infix) == 1 && strcmp(infix, "QUIT") != 0) {
        postfix[0] = '\0';

        convertToPostfix(infix, postfix);

        printf("%s\n", infix);
        printf("%s\n", postfix);

        if (evaluatePostfix(postfixQueue, &answer))
            printf("%d\n\n", answer);
        else
            printf("Division by zero error!\n\n");
    }
}
