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

TEST(queue pointersTest, src/util/queue.c, src/error.c){
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

    cell_location_t* output = dequeue(&que);
    printf("output: %d", output);
    if (output->x == 5 && output->y==5){
        return TEST_SUCCESS;
    }
    else{
        return TEST_FAIL;
    }
}