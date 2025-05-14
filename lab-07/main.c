#include <stdio.h>

#include "labda_tomb.h"

int main() {
    LabdaArray array;
    createArray(20, &array);

    //EGY LABDA ADATAINAK KIIRASA
    /*
    Labda labda1;
    readLabda(&labda1);
    printLabda(labda1);
    */
    
    readOsszesLabda(&array);

    printOsszesLabda(&array);

    //Vegyük le a polcról a 15 cm átmérőnél nagyobb labdákat, majd ismét írjuk
    //ki a polc tartalmát.
    labda_torol(&array);

    printf("\nszures utan: \n");

    printOsszesLabda(&array);

    printf("\nalairt labdak szama: %d\n", szamol_alairt(array));

    printf("\nrendezes utan:\n");

    qsort(array.elements, 20, sizeof(Labda), compare);

    printOsszesLabda(&array);

    deallocateArray(&array);
    return 0;
}

