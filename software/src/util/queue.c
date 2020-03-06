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
	if (s->tail == 256){
		s->tail = 0;
	}
}

cell_location_t* dequeue(queue* s)
{
    s->count--;
	if (s->head + 1 == 256) {
		int lastPlace = (int)s->head;
		s->head = 0;
		return s->q[(lastPlace)];
	} 
	else{
		return s->q[(s->head)++];
	}
}

int full(queue* s)
{
	//0 when not full, 1 when full
    return s->tail == s->size;
}

int empty(queue* s)
{
	//0 when not empty, 1 when empty
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