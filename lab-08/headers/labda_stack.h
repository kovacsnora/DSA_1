//
// Created by norik on 4/5/2025.
//

#ifndef LABDA_STACK_H
#define LABDA_STACK_H

typedef enum {
    RED,
    WHITE,
    BLACK,
    YELLOW,
    OTHER
}Szinek;

typedef struct {
    int atmero;
    Szinek szin;
    bool ala_irt;
}Labda;

typedef struct{
    int capacity, top;
    Labda *elements;
}LabdaStack;

extern int alairt_piros;
extern int alairt_feher;
extern int alairt_egyeb;

void createStack(int capacity, LabdaStack* stack);
void destroyStack(LabdaStack* stack);
bool isFullStack(LabdaStack stack);
bool isEmptyStack(LabdaStack stack);
void push(LabdaStack *stack, Labda item);
Labda pop(LabdaStack *stack);
Labda peek(LabdaStack stack) ;
int size(LabdaStack stack);
void printStack(LabdaStack stack, const char* stackName);
void readBallsFromFile(LabdaStack* redStack, LabdaStack* whiteStack, LabdaStack* otherStack);
const char *getColorTextStack(Szinek szin) ;
Szinek stringToEnumStack(const char *szin);
int countLabdak(LabdaStack *stack);
void legnagyobb_atmero_top(LabdaStack redStack, LabdaStack whiteStack, LabdaStack otherStack);
int kivenni_labdak(LabdaStack* stack);
#endif //LABDA_STACK_H
