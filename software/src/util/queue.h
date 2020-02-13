/*
 * File   : queue.h
 * Author : zentut.com
 * Purpose: stack header file
 */


#ifndef QUEUE_H_
#define QUEUE_H_

void init(int *head, int *tail);
void enqueue(int *q,int *tail, int element);
int dequeue(int *q,int *head);
int empty(int head,int tail);
int full(int tail,const int size);
void display(int *q,int head,int tail);

#endif /* QUEUE_H_ */
