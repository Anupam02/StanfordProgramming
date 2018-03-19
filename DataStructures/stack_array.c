/** Program to implement stack in C using arrays
    here basic operations are push , pop and top 
    but we are creating some more functions as helper to help
    initialize and to check for constraints (boundary conditions)
    create_stack , is_empty, is_full etc.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Stack {
	int top;
	unsigned int capacity;
	int * array;
}; 

struct Stack* create_stack(unsigned int capacity) {
	/** Function to create a default stack of a given capacity.
	    It is like constructor in OOP
	    its size would be zero in this initialization as 
	    there won't be any elements and top would be -1 (nothing in stack)
	*/
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	// here notice we have to dynamically allocate once the Stack 
	// its not like linked list implementation where we have to do it for every new element
	// now assigning the values for Stack structure
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)(malloc(sizeof(int)*stack->capacity));
	return stack;
}

bool is_full(struct Stack* stack) {
	/** Function to check wheather stack is full with its predefined
	 *  allocated size, which is equivalent to capacity-1 index wise
	 */
	return stack->top == stack->capacity - 1;
}

bool is_empty(struct  Stack* stack) {
	/** Function to check whether stack is empty or not
	 */
	return stack->top == -1;
}

void push(struct Stack* stack , int item) {
	/** Function to push item on top of stack */
	// checking if stack is  full
	if ( is_full(stack) ) {
		printf("Stack is already full of its capacity\n");
		return ;
	}
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n",item);
}

void pop(struct Stack* stack) {
	/** Function to pop item from top of stack */
	// checking if stack is empty
	if ( is_empty(stack) ) {
		printf("Stack is empty\n");
		return ;
	}
	stack->top--;
}

int top(struct Stack* stack) {
	/** Function to return the top of stack
	 *  no change in state of the stack
	 */
	// checking if stack is empty
	if ( is_empty( stack ) ) {
		printf("Stack is empty\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}

int main() {
	struct Stack* stack = create_stack(10);

	push(stack,5);
	printf("top of stack item = %d\n",top(stack));
	push(stack,10);
	push(stack,20);
	printf("top of stack item = %d\n",top(stack));
	pop(stack);
	printf("top of stack item = %d\n",top(stack));
	return 0;
}

