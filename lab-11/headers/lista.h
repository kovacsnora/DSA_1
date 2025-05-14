//
// Created by norik on 5/8/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "barat.h"

typedef struct Node{
    Barat data;
    struct Node* next;
}Node;

void printList(Node *head);
Node *newNode(Barat new_data);
bool isEmpty(Node *head);
void insertAtEnd(Node **head_ref, Barat new_data);
int readFromFile(const char* filename, Node** head);
void destroy_list(Node** head);
void countSuitableBarat(Node *head, int *count);

#endif //LISTA_H
