#include <stdio.h>
#include <stdbool.h>

#include "headers/simple_queue.h"
#include "headers/circular_queue.h"

int main() {
    Simple_Queue_t carQueue;
    createQueue(6, &carQueue);
    bool ok = true;

    while (ok) {
        printf("Choose from the following options:"
               "\n\t- Check if queue is empty: 1"
               "\n\t- Check if queue is full: 2"
               "\n\t- Add a new car to the queue: 3"
               "\n\t- Remove a car from the queue: 4"
               "\n\t- Display the cars waiting in the queue: 5"
               "\n\t- Exit: 0"
               "\n\nChoose an option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf(isEmpty(carQueue) ? "The queue is empty.\n" : "The queue is not empty.\n");
                break;
            }

            case 2: {
                printf(isFull(carQueue) ? "The queue is full.\n" : "The queue is not full.\n");
                break;
            }

            case 3: {
                char rendszam[4];
                printf("Give the rendszam: ");
                scanf("%s", rendszam);
                enqueue(&carQueue, rendszam);
                break;
            }
            case 4: {
                dequeue(&carQueue);
                break;
            }

            case 5: { //itt hiba van
                display(carQueue);
                break;
            }

            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;

}



/*
int main(void)
{

 //1.	Egy kezdetben üres, maximum 4 kapacitású körkörös sorba próbáljuk elhelyezni, ebben a sorrendben, a 1, 2, 3, 4 számokat.
 //2.	Vegyünk ki két értéket, majd próbáljuk betenni, ebben a sorrendben, az 5, 6 és 7 számokat.
 //3.	Utána vegyünk ki 1 értéket.
 //4.	Melyik szám lesz a sor elején a leírt műveletek elvégzése után?
 //5.	Mennyi lesz a sorban található elemek összege a leírt műveletek elvégzése után?
 //Megjegyzes: A sort nem szabad bejárni, csak a megfelelő műveleteket használhatod!

    CircularQueue_t queue;

    createCircularQueue(4, &queue); //letrehozzuk a sort

    enqueueCircular(&queue, 1);
    enqueueCircular(&queue, 2);
    enqueueCircular(&queue, 3);
    enqueueCircular(&queue, 4); //szamok behelyezese

    dequeueCircular(&queue);
    dequeueCircular(&queue); //ket ertek kivetele

    enqueueCircular(&queue, 5);
    enqueueCircular(&queue, 6);
    enqueueCircular(&queue, 7); //3 ertek betetele

    dequeueCircular(&queue); //egy ertek kivetele

    printf("peek :%d \n",peekCircular(queue)); //sor elejenek kiiratasa


    displayCircular(queue); //kiiratjuk a sort ellenorzes celjabol

    int temp = 0;
    int i = queue.front;

    while (true) {
        temp += queue.elements[i];
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }

    printf("A sorban levo elemek osszege: %d\n", temp);

    return 0;
}
*/

/*

int main(void)
{

//1.	Egy kezdetben üres, maximum 5 kapacitású sorba próbáljuk elhelyezni, ebben a sorrendben, a 10, 20, 30, 40, 50 számokat.
//2.	Vegyünk ki két értéket, majd próbáljuk betenni, ebben a sorrendben, a 60, 70 és 80 számokat.
//3.	Utána vegyünk ki 1 értéket.
//4.	Melyik szám lesz a sor elején a leírt műveletek elvégzése után?
//5.  Mennyi lesz a sorban található elemek összege a leírt műveletek elvégzése után?
//Megjegyzes: A sort nem szabad bejárni, csak a megfelelő műveleteket használhatod.

    Simple_Queue_t queue;
    int capacity=5;
    createQueue(capacity, &queue);
    for (int i = 0; i < capacity; i++) {
        enqueue(&queue, (i+1)*10);
    }
    display(queue);
    printf("%i", dequeue(&queue));
    printf(" %i ", dequeue(&queue));

    printf("\n%i ", dequeue(&queue));
    printf(" %i\n",peek(queue));
    display(queue);
    int sum = 0;
    for (int i = 0; i <2;i++) {
        sum=sum+dequeue(&queue);
    }
    printf("Sum is %i\n", sum);
    return 0;
}

*/