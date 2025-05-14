#include <stdio.h>
#include "headers/lista.h"

//ket szam osszeadasa
int main() {
    int num1 = 234;
    int num2 = 987;

    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* result_head = NULL;

    //szamjegyek beszurasa hatulrol elore a listaba
    if (num1 == 0) insertAtEnd(&head1, 0);
    while (num1 > 0) {
        insertAtEnd(&head1, num1 % 10);
        num1 /= 10;
    }

    if (num2 == 0) insertAtEnd(&head2, 0);
    while (num2 > 0) {
        insertAtEnd(&head2, num2 % 10);
        num2 /= 10;
    }

    printf("Elso lista: ");
    printList(head1);
    printf("\nMasodik lista: ");
    printList(head2);

    //ket lista osszeadasa
    result_head = szamjegyekOsszead(head1, head2);
    printf("\nOsszeg lista: ");
    printList(result_head);

    //lista atalakitasa szamma
    int result = listToNumber(result_head);
    printf("\nOsszeg egesz szamkent: %d\n", result);

    insertZeroAfterEven(&result_head);
    printf("Paros utan 0: ");
    printList(result_head);

    //1es beszurasa a lista elejere es vegere
    insertAtBeginning(&result_head, 1);
    insertAtEnd(&result_head, 1);
    printf("\nBeszuras utan: ");
    printList(result_head);

    //elem keresese es torlese a listabol
    int keresett = 0;
    if (searchNode(result_head, keresett)) {
        deleteNode(&result_head, keresett);
        printf("\nTorles utan: ");
        printList(result_head);
    } else {
        printf("Nincs ilyen elem.\n");
    }

    //lista rendezese novekvo sorrendbe
    sortLinkedList(&result_head);
    printf("\nRendezett lista: ");
    printList(result_head);




}


//alapok
// int main() {
//     int  num1=3, num2=2;
//     Node *head1 = NULL;
//     head1 = newNode(num1);
//     insertAtEnd(&head1, num2);
//
//     int num3 = 5;
//     insertAtBeginning(&head1, num3);
//
//     int num4 = 6;
//     Node* temp = head1;
//     while (temp != NULL && temp->data != 5) { //az 5os utan akarom beszurni az ujat
//         temp = temp->next;
//     }
//
//     if (temp != NULL) {
//         insertAfter(temp, num4);
//     }
//
//     printList(head1);
//     return 0;
// }
