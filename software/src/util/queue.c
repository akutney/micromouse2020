/*
 * File   : queue.c
 * Author : zentut.com
 * Purpose: stack header file
 */


//make more abstract. add struct passed in with 
//head, tail, and queue (array?)



#include <stdio.h>
#include "queue.h"
#include "../types/types.h"

void init(queue* s)
{
    s->head = 0; 
    s->tail = 0;
}

void enqueue(queue* s, cell_location_t* element)
{
    s->count++;
    s->q[(s->tail)++] = element;
}

cell_location_t* dequeue(queue* s)
{
    s->count--;
    return s->q[(s->head)++];
}

int full(queue* s)
{
    return s->tail == s->size;
}

int empty(queue* s)
{
    return (s->tail) == (s->head);
}
 
/*
//code from 2019, need to test
template<typename T> void swap(T& a, T& b){
	T c = a;
	*a = b;
	b* = a
}

void display(queue* s)
{
    int i = s->tail - 1;
    while(i >= s->head)
        printf("%d ",s->q[i--]);
    printf("\n");
}*/