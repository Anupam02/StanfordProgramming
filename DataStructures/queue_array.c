#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
	int front, rear, size;
	unsigned int capacity;
	int * array;
};

/** the thing to be noted here  , whatever I am going to implement from array
 * I am not going to shift when i do delete - i mean whatever we are doing here
 * for enqueue and deque we are playing with front and rear and not doing any 
 * proper deletion to be precise or shifting of elements for any insertion or 
 * deletion .*
 * this is incomplete will have to do next time */


