/*
 * queue.test.c
 */ 

#include <testing.h>
#include <error.h>

#include "queue.h"
#include "../types/types.h"


/*
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
}*/

TEST(initializationCheck, src/util/queue.c, src/error.c){
    queue que;
    que.head =1;
    que.tail = 1;
    init(&que);

    if (que.head == 0 && que.tail == 0){
        return TEST_SUCCESS;
    }
    else {
        return TEST_FAIL;
    }
}

TEST(pointersAddedToQueue, src/util/queue.c, src/error.c){
    queue que;
    que.size = 5;
    que.head = 0;
    que.tail = 0;

    cell_location_t one;
    one.x = 1;
    one.y = 1;

    cell_location_t two;
    two.x=2;
    two.y=2;

    cell_location_t three;
    three.x=3;
    three.y=3;

    cell_location_t four;
    four.x=4;
    four.x=4;

    cell_location_t five;
    five.x=5;
    five.y=5;

    enqueue(&que, &one);
    
    enqueue(&que, &two);
    enqueue(&que, &three);
    enqueue(&que, &four);
    enqueue(&que, &five);
    
    if (empty(&que) == 0 && que.head == 0 && que.tail == 5 && full(&que) == 1){
        return TEST_SUCCESS;
    }
    else{
        return TEST_FAIL;
    }
}

TEST(dequeueValidation, src/util/queue.c, src/error.c){
    queue que2;
    que2.size = 5;
    que2.head = 0;
    que2.tail = 0;

    cell_location_t one;
    one.x = 1;
    one.y = 1;

    cell_location_t two;
    two.x=2;
    two.y=2;

    cell_location_t three;
    three.x=3;
    three.y=3;

    cell_location_t four;
    four.x=4;
    four.x=4;

    cell_location_t five;
    five.x=5;
    five.y=5;

    enqueue(&que2, &one);
    enqueue(&que2, &two);
    enqueue(&que2, &three);
    enqueue(&que2, &four);
    enqueue(&que2, &five);

    cell_location_t* removedFirst = dequeue(&que2);
    cell_location_t* removedSecond = dequeue(&que2);
    if ((removedFirst->x)==1 && (removedFirst->y)==1){
        if ((removedSecond->x) == 2 && (removedSecond->y)==2){
            if (que2.head == 2){

                return TEST_SUCCESS;
            }
        }
    }
    else {
        return TEST_FAIL;
    }
}