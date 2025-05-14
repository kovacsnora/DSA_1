//
// Created by norik on 4/8/2025.
//

#ifndef LABDA_SIMPLE_H
#define LABDA_SIMPLE_H

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

const char *getColorText(Szinek szin);
Szinek stringToEnum(const char *szin);
void readLabda(Labda *labda);
void printLabda(Labda labda);

#endif //LABDA_SIMPLE_H
