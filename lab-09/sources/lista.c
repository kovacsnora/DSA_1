//
// Created by norik on 4/17/2025.
//

#include "../headers/lista.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//szamjegyek osszeadasa ket listabol
Node* szamjegyekOsszead(Node* l1, Node* l2) {
    Node* result = NULL;
    int carry = 0; //maradek

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        insertAtEnd(&result, sum % 10);
        carry = sum / 10;
    }

    return result;
}

//listat egesz szamma alakitja
int listToNumber(Node* head) {
    int result = 0;
    while (head != NULL) {
        result = result * 10 + head->data;
        head = head->next;
    }
    return result;
}

//paros szamok utan 0 beillesztese
void insertZeroAfterEven(Node** head_ref) {
    //a current pointerrel lepkedunk a listan
    //a head_ref egy mutato a lista elejere
    Node* current = *head_ref;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            insertAfter(current, 0);
            current = current->next; // tovabblepunk a nullara
        }
        current = current->next;//megint tovabblepunk a kovetkezo elemre
    }
}


Node *newNode(int new_data) {
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

//azert ** mert megvaltozik a head
void insertAtBeginning(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    Node *new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


void insertAtEnd(Node **head_ref, int new_data) {
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

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

//azert ** mert ha csak 1 elem van es az a fej akkor megvaltozik a head
void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION_ERROR_MESSAGE");
        return;
    }

    Node* last = *head_ref, *prev;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

void deleteNode(Node **head_ref, int key) {
    Node *temp = *head_ref;
    Node *prev;

    //ha az elso node a keresett
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Kereses a listaban
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Ha nem talaltuk meg
    if (temp == NULL) return;

    //kivesszuk
    prev->next = temp->next;
    free(temp);
}

bool searchNode(Node *head_ref, int key) {
    Node* current = head_ref;
    while (current != NULL) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}


//buborekos rendezes
void sortLinkedList(Node **head_ref) {
    Node *p = *(head_ref);
    Node *q;

    while (p->next != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                int aux = p->data;
                p->data = q->data;
                q->data = aux;
            }
            q = q->next;
        }
        p = p->next;
    }
}
