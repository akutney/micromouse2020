/*
 * queue.test.c
 */ 

#include <testing.h>
#include <error.h>

#include "queue.h"

TEST(queue counter, src/util/queue.c, src/error.c) {
    queue que;
    que.size = 10;
    que.head = 0;
    que.tail=0;

    que.count = 0;

    init(&que);

    enqueue(&que, 3);
    enqueue(&que, 2);
    enqueue(&que, 1);

    dequeue(&que);

    if(que.count == 2){
        return TEST_SUCCESS;
    }else
    {
        return TEST_FAIL;
    }
    
}


TEST(queue2 compiles, src/util/queue.c, src/error.c) {

   queue que;

   que.size = 10;
   que.head = 0;
   que.tail= 0;

    int element = 0;

	init(&que);

    while(!full(&que)){
        enqueue(&que, element++);
    }
 
   while(!empty(&que)){
       dequeue(&que);
   }

	if(empty(&que) == 1){
		return TEST_SUCCESS;
	}else{
		return TEST_FAIL;
	}
}
