/*
 * File   : queue.h
 * Author : zentut.com
 * Purpose: stack header file
 */


#ifndef QUEUE_H_
#define QUEUE_H_

#include "../types/cell_location.h"





typedef struct queue{
    int head;
    int tail;
    int count;
    int size;
    cell_location_t* q[256]; //this should be 256
}queue;



void init(queue * s);
void enqueue(queue * s, cell_location_t* element);
cell_location_t* dequeue(queue* s);
int empty(queue * s);
int full(queue * s);
//void display(queue * s);

#endif /* QUEUE_H_ */
