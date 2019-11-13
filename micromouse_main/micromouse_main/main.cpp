/*
 * micromouse_main.cpp
 *
 * Created: 11/12/2019 5:12:01 PM
 * Author : Dylan Staatz
 */ 


#include "sam.h"


int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    /* Replace with your application code */
    while (1) 
    {
		
		// Calculate the total from 0-99
		int total = 0;
		for (int i = 0; i < 100; i++) {
			total += i;
		}
		
		int x = 0;
		x = five(x);
		
		
    }
	
	int Add5 (int x)
	{
		int y = x + 5;
		return y;	
	}
}

int five(int x){
	return x + 5;
}
