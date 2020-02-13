/*
 * queue.test.c
 */ 

#include <testing.h>
#include <error.h>

#include "queue.h"

TEST(queue compiles, src/util/queue.c, src/error.c) {
	return TEST_SUCCESS;
}


TEST(queue2 compiles, src/util/queue.c, src/error.c) {

	const int SIZE = 10; // queue's size 
    int head, tail, element;
    int queue[SIZE];

	init(&head,&tail);
 
    printf("--Enqueue elements--\n");
    // push elements into stack 
    while(!full(tail,SIZE))
    {
        printf("Enter a number to enqueue:");
        scanf("%d",&element);
 
        enqueue(queue,&tail,element);
 
        display(queue,head,tail);
    }
    printf("Queue is full\n\n");
 
    printf("--Dequeue elements --\n");
    while(!empty(head,tail))
    {
        element = dequeue(queue,&head);
        printf("dequeue element %d \n",element);
 
        display(queue,head,tail);
    }
    printf("Queue is empty\n");

	if(empty(head, tail) == 1){
		return TEST_SUCCESS;
	}else{
		return TEST_FAIL;
	}

}
