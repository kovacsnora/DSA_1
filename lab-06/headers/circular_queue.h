//
// Created by norik on 3/27/2025.
//

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H


typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}CircularQueue_t;

void createCircularQueue(int capacity, CircularQueue_t *queue);
/**
 * Deallocates the elements array -> free
 * @param queue
 */
void destroyCircularQueue(CircularQueue_t* queue);
/**
 * Checks whether the queue is full or not
 * @param queue
 * @return true/false
 */
bool isCircularFull(CircularQueue_t queue);
/**
 * Checks whether the queue is empty or not
 * @param queue
 * @return true/false
 */
bool isCircularEmpty(CircularQueue_t queue);
/**
 * Adds a new item to the end of the queue
 * @param queue
 * @param item
 */
void enqueueCircular(CircularQueue_t* queue, int item);
/**
 * Removes the first item from the queue
 * @param queue
 * @return
 */
int dequeueCircular(CircularQueue_t* queue);
/**
 * Prints all items of the queue
 * @param queue
 */
void displayCircular(CircularQueue_t queue);
/**
 * Returns the element in the front
 * @param queue
 * @return the element in the front
 */
int peekCircular(CircularQueue_t queue);

#endif //CIRCULAR_QUEUE_H
