/*
 * File   : queue.h
 * Author : zentut.com
 * Purpose: stack header file
 */


#ifndef QUEUE_H_
#define QUEUE_H_

/*
void init(int *head, int *tail);
void enqueue(int *q,int *tail, int element);
int dequeue(int *q,int *head);
int empty(int head,int tail);
int full(int tail,const int size);
void display(int *q,int head,int tail);
*/

    typedef struct queue{
        int head;
        int tail;
        int count;
        int size;
        int q[256]; //this should be 256
    }queue;


void init(queue * s);
void enqueue(queue * s, int element);
int dequeue(queue * s);
int empty(queue * s);
int full(queue * s);
void display(queue * s);

#endif /* QUEUE_H_ */
