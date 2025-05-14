//
// Created by norik on 4/5/2025.
//

#include "labda_stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CAPACITY 20

int alairt_piros=0;
int alairt_feher=0;
int alairt_egyeb=0;

const char *getColorTextStack(Szinek szin) {
    switch (szin) {
        case RED:
            return "RED";
        case WHITE:
            return "WHITE";
        case BLACK:
            return "BLACK";
        case YELLOW:
            return "YELLOW";
        default:
            return "OTHER";
    }
}

Szinek stringToEnumStack(const char *szin) {
    if (strcmp(szin, "RED") == 0) return RED;
    if (strcmp(szin, "YELLOW") == 0) return YELLOW;
    if (strcmp(szin, "WHITE") == 0) return WHITE;
    if (strcmp(szin, "BLACK") == 0) return BLACK;
    return OTHER;
}


void createStack(int capacity, LabdaStack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (Labda*) calloc(stack->capacity, sizeof(Labda));
    if (!stack->elements) {
        printf("memory allocation error");
        exit(-1);
    }
}

bool isFullStack(LabdaStack stack) {
    return stack.top == stack.capacity-1;
}

bool isEmptyStack(LabdaStack stack) {
    return stack.top == -1;
}

//verem tetejen levo elem visszateritese, de nem valtoztatjuk!!
Labda peek(LabdaStack stack) {
    if (isEmptyStack(stack)) {
        Labda ures = {-1, OTHER, 0};
        printf("the stack is empty");
        return ures;
    }
    return stack.elements[stack.top];
}

//uj elem behelyezese
void push(LabdaStack *stack, Labda item) {
    if (isFullStack(*stack)) {
        printf("the stack is full");
        exit(-4);
    }
    stack->elements[++stack->top] = item;
}

//legfelso elem kivevese
Labda pop(LabdaStack *stack) {
    if (isEmptyStack(*stack)) {
        printf("the stack is empty");
        exit(-3);
    }
    return stack->elements[stack->top--];
}

int size(LabdaStack stack) {
    return stack.top + 1;
}

void destroyStack(LabdaStack* stack){
    stack->capacity=0;
    stack->top=-1;
    if (stack->elements) {
        free(stack->elements);
        stack->elements = NULL;
    }
}

void readBallsFromFile(LabdaStack* redStack, LabdaStack* whiteStack, LabdaStack* otherStack) {
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("Nem sikerult megnyitni a fajlt\n");
        exit(1);
    }

    Labda labda;
    char colorText[20];

    while (fscanf(f, "%d %s %d", &labda.atmero, colorText, &labda.ala_irt) != EOF ) {
        labda.szin = stringToEnumStack(colorText);

        switch (labda.szin) {
            case RED:
                if (!isFullStack(*redStack)) {
                    push(redStack, labda);
                    if (labda.ala_irt == 1){
                        alairt_piros++; //amikor rakom be a labdakat egybol szamolom is
                    }
                }
            break;
            case WHITE:
                if (!isFullStack(*whiteStack)) {
                    push(whiteStack, labda);
                    if (labda.ala_irt == 1){
                        alairt_feher++; //amikor rakom be a labdakat egybol szamolom is
                    }
                }

            break;
            default:
                if (!isFullStack(*otherStack)) {
                    push(otherStack, labda);
                    if (labda.ala_irt == 1){
                        alairt_egyeb++; //amikor rakom be a labdakat egybol szamolom is
                    }
                }
            break;
        }
    }
    fclose(f);
}


void printStack(LabdaStack stack, const char* stackName) {
    printf("=== %s STACK ===\n", stackName);
    if (isEmptyStack(stack)) {
        printf("the stack is empty\n");
        return;
    }

    for (int i = stack.top; i >= 0; i--) {
        Labda l = stack.elements[i];
        printf("%d, %s, %s\n", l.atmero, getColorTextStack(l.szin),(l.ala_irt ? "YES" : "NO"));
    }
    printf("\n");
}
//Melyik láda tetején van a legnagyobb átmérőjű labda?
void legnagyobb_atmero_top(LabdaStack redStack, LabdaStack whiteStack, LabdaStack otherStack) {
    Labda piros_top, feher_top, egyeb_top;
    piros_top = peek(redStack);
    feher_top = peek(whiteStack);
    egyeb_top = peek(otherStack);

    Labda maxLabda = piros_top;
    char *maxStackName = "PIROS";

    if (feher_top.atmero > maxLabda.atmero) {
        maxLabda = feher_top;
        maxStackName = "FEHER";
    }

    if (egyeb_top.atmero > maxLabda.atmero) {
        maxLabda = egyeb_top;
        maxStackName = "EGYEB";
    }

    printf("melyik lada tetejen van a legnagyobb atmeroju labda: %s (%d)\n", maxStackName, maxLabda.atmero);

}

//Vegyünk ki addig labdákat mindhárom ládából, amíg mindenik láda tetején
//aláírt labda lesz, vagy üresek nem lesznek a ládák. Mennyi labda maradt külön-külön
//a három ládában, illetve hányat vettünk ki az egyes ládákból?
int kivenni_labdak(LabdaStack* stack){
    if (isEmptyStack(*stack)) {
        printf("the stack is empty");
        return 0;
    }

    int count = 0;
    while (!isEmptyStack(*stack)) {
        if (peek(*stack).ala_irt == 0) {
            pop(stack);
            count++;
        }
        else break;
    }
    return count;
}




