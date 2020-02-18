/*
 * File   : queue.c
 * Author : zentut.com
 * Purpose: stack header file
 */


//make more abstract. add struct passed in with 
//head, tail, and queue (array?)



#include <stdio.h>
#include "queue.h"

/*
    initialize queue pointers
*/


/*
void init(int *head, int *tail)
{
    *head = 0; 
    *tail = 0;
}
*/

void init(queue* s)
{
    s->head = 0; 
    s->tail = 0;
}
 
/*
   enqueue an element
   precondition: the queue is not full
*/

/*
void enqueue(int *q,int *tail, int element)
{
    q[(*tail)++] = element;
}
*/

void enqueue(queue* s, int element)
{
    s->count++;
    s->q[(s->tail)++] = element;
}
 
/*
    dequeue an element
    precondition: queue is not empty
*/
/*
int dequeue(int *q,int *head)
{
    return q[(*head)++];
}
*/

int dequeue(queue* s)
{
    s->count--;
    return s->q[(s->head)++];
}
 
/*
    return 1 if queue is full, otherwise return 0
*/
/*
int full(int tail,const int size)
{
    return tail == size;
}
*/

int full(queue* s)
{
    return s->tail == s->size;
}
 
/*
  return 1 if the queue is empty, otherwise return 0
*/
/*
int empty(int head, int tail)
{
    return tail == head;
}
*/

int empty(queue* s)
{
    return (s->tail) == (s->head);
}
 
/*
  display queue content
*/
/*
void display(int *q,int head,int tail)
{
    int i = tail - 1;
    while(i >= head)
        printf("%d ",q[i--]);
    printf("\n");
}
*/

void display(queue* s)
{
    int i = s->tail - 1;
    while(i >= s->head)
        printf("%d ",s->q[i--]);
    printf("\n");
}