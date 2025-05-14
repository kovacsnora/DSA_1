//
// Created by norik on 3/27/2025.
//
#include "simple_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void createQueue(int capacity, Simple_Queue_t* queue){
    queue->capacity=capacity;
    queue->rear=queue->front=-1; //kezdetben -1 mindketto
    queue->elements=(Car*)malloc(capacity * sizeof(Car));
    if (!queue->elements)
    {
        printf("Memory allocation error");
        exit(-1);
    }
    for (int i = 0; i < capacity; i++) {
        queue->elements[i]->plate = (Car*)malloc(MAX_LENGTH * sizeof(Car));
    }
}

void destroyQueue(Simple_Queue_t* queue){
    free(queue->elements);
    queue->elements = NULL;
    queue->front = queue->rear = -1;
    queue->capacity = 0;
}

bool isFull(Simple_Queue_t queue){
    return queue.rear == queue.capacity - 1;
}

bool isEmpty(Simple_Queue_t queue) {
    return queue.front == -1;
}

void enqueue(Simple_Queue_t* queue, int item){
    if (isFull(*queue)) {
        printf("The queue is full\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front++; //az elso elem beszurasanal mindketto novekszik
    }
    queue->elements[++queue->rear] = item;
}

int dequeue(Simple_Queue_t* queue) {
    if (isEmpty(*queue))
    {
        printf("The queue is empty");
        exit(-3);
    }
    int save=queue->elements[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear=-1;
    }
    else {
        queue->front++;
    }

    return save;
}

void display(Simple_Queue_t queue){
    if (isEmpty(queue)) {
        printf("The queue is empty");
        exit(-3);
    }
    printf("the cars in the queue:\n");
    for (int i=queue.front; i<=queue.rear; i++) {
        printf("%s", queue.elements[i]); //itt most stringet kell kiirasson
    }
    printf("\n");
}

int peek(Simple_Queue_t queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty\n");
        exit(-3);
    }
    return queue.elements[queue.front];
}

