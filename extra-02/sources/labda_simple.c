//
// Created by norik on 4/8/2025.
//

#include "../headers/labda_simple.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char *getColorText(Szinek szin) {
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

Szinek stringToEnum(const char *szin) {
    if (strcmp(szin, "RED") == 0) return RED;
    if (strcmp(szin, "YELLOW") == 0) return YELLOW;
    if (strcmp(szin, "WHITE") == 0) return WHITE;
    if (strcmp(szin, "BLACK") == 0) return BLACK;
    return OTHER;
}


void readLabda(Labda *labda) {
    char szin[20];

    scanf("%d", &labda->atmero);

    scanf("%s", szin);
    labda->szin = stringToEnum(szin);

    scanf(" %d", &labda->ala_irt);
}

void printLabda(Labda labda) {
    printf("%d %s %d", labda.atmero, getColorText(labda.szin), labda.ala_irt);
}