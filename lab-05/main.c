#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


//postfix
//3+6 = 9
//5*9 = 45
//2*45=90
//90/15 = 6
//6-2 = 4


int main() {
    char t[]="2 5 3 6 + * * 15 / 2 -";
    Stack_t stack;
    createStack(strlen(t), &stack);

    printf("Stack is %s\n", (isEmpty(stack)) ? ("empty") : ("not empty"));
    printf("Stack is %s\n", (isFull(stack)) ? ("full") : ("not full"));

    printf("size of stack is %i\n", size(stack));

    const char separators[2] = " ";
    char *token = strtok(t, separators);

    const char operators[]="+-*/%";

    while (token != NULL) {
        if (strstr(operators, token)) {
            int number1 = pop(&stack); //kivesszuk a legfelso elemet
            int number2 = pop(&stack); //kivesszuk a kovetkezot is
            int result = calculateResult(number2, number1, token);
            push(&stack, result); //visszatesszuk a stackbe az eredmenyt
        }
        else {
            int number = atoi(token);
            push(&stack, number); //berakjuk a szamot a stackbe
        }
        token = strtok(NULL, separators);
    }
    int finalResult = pop(&stack); //a vegso eredmeny a stack legfelso eleme

    //ha a muveletek vegen ures a verem akkor minden jo
    if (!isEmpty(stack)) {
        printf("helytelen muvelet");
    }
    else {
        printf("the final result is %i", finalResult);
    }




    destroyStack(&stack);
}


