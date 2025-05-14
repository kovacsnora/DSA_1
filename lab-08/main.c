#include <stdio.h>

#include "labda_stack.h"

#define MAX_CAPACITY 20
int main() {
    LabdaStack redStack, whiteStack, otherStack;

    createStack(MAX_CAPACITY, &redStack);
    createStack(MAX_CAPACITY, &whiteStack);
    createStack(MAX_CAPACITY, &otherStack);

    readBallsFromFile(&redStack, &whiteStack, &otherStack);

    printStack(redStack, "PIROS");
    printStack(whiteStack, "FEHER");
    printStack(otherStack, "EGYEB");

    printf("alairt prios: %d\n", alairt_piros);
    printf("alairt feher: %d\n", alairt_feher);
    printf("alairt egyeb: %d\n", alairt_egyeb);


    legnagyobb_atmero_top(redStack, whiteStack, otherStack);

    int piros_ossz = size(redStack);
    int feher_ossz = size(whiteStack);

    int kivett_piros=0, kivett_feher=0, kivett_egyeb=0;
    kivett_piros = kivenni_labdak(&redStack);
    kivett_feher = kivenni_labdak(&whiteStack);
    kivett_egyeb = kivenni_labdak(&otherStack);

    printf("kivett pirosak szama: %d\n", kivett_piros);
    printf("hany piros labda maradt a ladaban: %d\n", piros_ossz-kivett_piros );

    printf("kivett feherek szama: %d\n", kivett_feher);
    printf("hany feher labda maradt a ladaban: %d\n", feher_ossz-kivett_feher );

    //printStack(redStack, "PIROS");

    destroyStack(&redStack);
    destroyStack(&whiteStack);
    destroyStack(&otherStack);
}
