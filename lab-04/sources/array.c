//
// Created by norik on 3/13/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

//lefoglalja
//pointer mert valtozni fog az elem
void createIntArray(int capacity, IntArray *pArray){
    pArray -> capacity = capacity;
    pArray -> size = 0; //amikor lefoglaljuk akkor meg nincs benne elem
    pArray -> elements = (int *) malloc(pArray -> capacity * sizeof (int));
    if(!(pArray -> elements)){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

bool isFull(IntArray array) {
    if (array.size == array.capacity) {
        return true;
    }
    else return false;
}

bool isEmpty(IntArray array) {
    if (array.size == 0) {
        return true;
    }
    else return false;
}

void printArray(IntArray array) {
    if (isEmpty(array)) {
        printf("the array is empty");
        return;
    }
    for (int  i= 0;  i < array.size; ++i) {
        printf("%i ", array.elements[i]);
    }
    printf("\n");
}

//pointer mert a size is valtozik es maga a tomb is
//item = mit szurunk be
void insertFirst(IntArray *pArray, int item) {
    if (isFull(*pArray)) {
        printf("the array is full");
        return;
    }

    for (int i = pArray->size ; i > 0 ; i++) {
        pArray->elements[i] = pArray->elements[i-1]; //eltologatjuk az elemeket
    }

    pArray -> elements[0] = item;
    pArray->size++; //novelodik a meret
}

int getItemAt(IntArray array, int position) {
    for (int i=0;i<array.size;i++) {
        if (i == position) {
            return array.elements[i];
        }
    }
}

void insertLast(IntArray *pArray, int item) {
    if (isFull(*pArray)) {
        printf("the array is full");
        return;
    }

    pArray -> elements[pArray->size] = item;
    pArray -> size++;

}

void insertAt(IntArray* pArray, int position, int item) {
    if (isFull(*pArray)) {
        printf("the array is full");
        return;
    }

    for (int i = pArray->size ; i > position ; i--) {
        pArray->elements[i] = pArray->elements[i-1]; //eltologatjuk az elemeket
    }

    pArray -> elements[position] = item;
    pArray -> size++;

}

void deleteItemAt(IntArray *pArray, int position) {
    if (isEmpty(*pArray)) {
        printf("the array is empty");
        return;
    }

    for (int i = 0; i < pArray->size ; i++) {
        if (i == position) {
            for (i=position;i<pArray->size;i++) {
                pArray->elements[i] = pArray->elements[i+1]; //eltologatjuk az elemeket
            }
        }
    }

    pArray -> elements[position];
    pArray -> size--;

}

int search(IntArray *pArray, int item) {
    if (isEmpty(*pArray)) {
        printf("the array is empty");
        return;
    }

    for (int i = 0; i < pArray->size ; i++) {
        if (pArray -> elements[i] == item) {
            return i;
        }
    }

}

bool update(IntArray *pArray, int position, int newItem) {
    if (position < 0 || position >= pArray->size) {
        printf("Invalid position\n");
        return false;
    }

    pArray -> elements[position] = newItem;
    return true;
}

void deallocateIntArray(IntArray *pArray) {
    free(pArray -> elements);
    pArray = NULL;
}

