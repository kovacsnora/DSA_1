//
// Created by norik on 3/27/2025.
//

#include "circular_queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void createCircularQueue(int capacity, CircularQueue_t *queue) {
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->elements = (int*)malloc(capacity*sizeof(int));
    if (!queue->elements) {perror("Memory allocation error!"); exit(-1);}
}

void destroyCircularQueue(CircularQueue_t *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->capacity = 0;
    queue->front = queue->rear = -1;
}

bool isCircularFull(CircularQueue_t queue){
    return (queue.front == (queue.rear + 1) % queue.capacity);
}

bool isCircularEmpty(CircularQueue_t queue) {
    return (queue.front == -1);
}

void enqueueCircular(CircularQueue_t *queue, int item) {
    if (isCircularFull(*queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isCircularEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
}

int dequeueCircular(CircularQueue_t *queue) {
    if (isCircularEmpty(*queue)) {
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    int temp = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return temp;
}

void displayCircular(CircularQueue_t queue) {
    if (isCircularEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue.front;
    while (true) {
        printf("%d ", queue.elements[i]);
        if (i == queue.rear) break;
        i = (i + 1) % queue.capacity;
    }
    printf("\n");
}

int peekCircular(CircularQueue_t queue) {
    if (isCircularEmpty(queue)) {
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    return queue.elements[queue.front];
}
