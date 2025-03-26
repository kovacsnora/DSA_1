//
// Created by norik on 3/20/2025.
//

#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void createStack(int capacity, Stack_t* stack){
    stack->capacity = capacity;
    stack->top = -1; //helytelen pozicio ezert azt jelenti h ures az elem
    stack->elements = (int *)calloc(stack->capacity, sizeof(int));

    if(!(stack->elements)){
        printf("error");
        exit(-1);
    }
}

void destroyStack(Stack_t* stack){
    stack->capacity=0;
    stack->top=-1;
    free(stack->elements);
    stack = NULL;
}

bool isFull(Stack_t stack){
    if(stack.top==stack.capacity - 1){
        return true;
    }
    return false;
}

bool isEmpty(Stack_t stack){
    if (stack.top == -1)
    {
        return true;
    }
    return false;
}

//ha nincs tele a verem behelyezunk egy uj erteket
void push(Stack_t* stack, int item){
    if(isFull(*stack)){
        printf("A verem tele van");
        return;
    }
    stack->elements[++stack->top]= item;
}

//kivenni a verem legfelso elemet
int pop(Stack_t* stack){
    if(isEmpty(*stack)){
        printf("A verem ures");
        return -1;
    }
    return stack->elements[stack->top--];
}

//vissszateritunk de nem valtoztatjuk meg
int peek(Stack_t stack){
    if(isEmpty(stack)){
        printf("A verem ures");
        return -1;
    }
    return stack.elements[stack.top];
}

//jelenleg hany elem van benne
int size(Stack_t stack) {
    return stack.top + 1;
}

int calculateResult(int number2, int number1, char *token) {
    char operation = token[0];
    switch (operation) {
        case '+': return number2 + number1;
        case '-': return number2 - number1;
        case '*': return number2 * number1;
        case '/': return number2 / number1;
        case '%': return number2 % number1;
        default: return 1;
    }
}