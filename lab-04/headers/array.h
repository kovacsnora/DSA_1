//
// Created by norik on 3/13/2025.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "constants.h";


typedef struct{
  int capacity; //elemek maximalis szama
  int size; //elemek aktualis szama
  int *elements; //nem lehet elements[100] ezert pointerkent kell kezelni
}IntArray; //int-eket tartalmazo array

void createIntArray(int capacity, IntArray* pArray);
bool isFull(IntArray array);
bool isEmpty(IntArray array);
void printArray(IntArray array);
void insertFirst(IntArray* pArray, int item);
int getItemAt(IntArray array, int position);
void insertLast(IntArray* pArray, int item);
void insertAt(IntArray* pArray, int position, int item);
void deleteItemAt(IntArray* pArray, int position);
int search(IntArray *pArray, int item);
bool update(IntArray* pArray, int position, int newItem);
void deallocateIntArray(IntArray *pArray);


#endif //ARRAY_H
