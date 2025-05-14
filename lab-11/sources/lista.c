//
// Created by norik on 5/8/2025.
//

#include "../headers/lista.h"
#include "../headers/barat.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printList(Node *head) {
    while (head) {
        Barat b = head->data;
        printf("%-20s\t%04d-%02d-%02d\t%c\t%d\n", b.nev,
               b.szuletesiDatum.ev, b.szuletesiDatum.honap, b.szuletesiDatum.nap,
               b.nem, b.bulizas);
        head = head->next;
    }
}

Node *newNode(Barat new_data) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = new_data;
    node->next = NULL;
    return node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtEnd(Node **head_ref, Barat new_data) {
    Node *new_node = newNode(new_data);

    Node *last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last -> next;
    last->next = new_node;
}

int readFromFile(const char* filename, Node** head) {
    FILE* fin = fopen(filename, "r");
    if (!fin) {
        perror("nem lehet megnyitni a fajlt!");
        return 0;
    }

    char sor[256];

    while (fgets(sor, sizeof(sor), fin)) {
        if (sor[0] == '\n' || sor[0] == '\0')
            break;

        Barat b;

        if (sscanf(sor, "%[^;];%d;%d;%d;%c;%d",
                   b.nev, &b.szuletesiDatum.ev, &b.szuletesiDatum.honap,
                   &b.szuletesiDatum.nap, &b.nem, &b.bulizas) == 6) {
            insertAtEnd(head, b);
                   }
    }

    fclose(fin);
    return 1;
}

void destroy_list(Node **head) {
    while (head) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}

void countSuitableBarat(Node *head, int *count) {
    Node *temp = head;
    *count = 0;
    int evszam = 2025;

    while (temp != NULL) {
        int kor = evszam - temp->data.szuletesiDatum.ev;
        if (kor >= 20 && temp->data.bulizas >= 5) {
            (*count)++;
        }
        temp = temp->next;
    }

    int c = (*count);

    if (c >= 10) {
        printf("Van elegendo barat a bulihoz:\n");
        temp = head;
        while (temp != NULL) {
            int kor = evszam - temp->data.szuletesiDatum.ev;
            if (kor >= 20 && temp->data.bulizas >= 5) {
                printf("%s\n", temp->data.nev);
            }
            temp = temp->next;
        }
    }
    else {
        printf("Nincs elegendo barat a bulihoz!");
    }
}
