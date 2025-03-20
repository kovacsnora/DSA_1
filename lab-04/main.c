#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "constants.h"

int main() {
    IntArray array;
    createIntArray(10 , &array);
    printArray(array);

    printf("\nElements:\n");
    insertFirst(&array, 1);
    printArray(array);

    /*
    int x;
    printf("which position (x): ");
    scanf("%i", &x);
    printf("the item at position x: %d ", getItemAt(array, x));
    */

    insertLast(&array , 2);
    printArray(array);

    insertAt(&array, 1, 10);
    printArray(array);

    deleteItemAt(&array, 1);
    printArray(array);

    printf("%d\n", search(&array, 1));

    update(&array, 0, 5);
    printArray(array);



}
