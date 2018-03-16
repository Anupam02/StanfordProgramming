/** program to implement stack in C with linked list 
    -Last in , firs out (LIFO)
    -Support three constant-time operations
	-Push(x) : inserts x into the stack
	-Pop()   : removes the newest item
	-Top()	 : returns the newest item
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct stackNode {
	int item;
	struct stackNode * next;
};

struct stackNode* new_node(int item) {
	/** Function to create a new node for the stack.
	    it would act as a helping function for Push operation in stack.
	    as we need to create a new node before pushing elements to a stack.
	*/
	struct stackNode* new_node = (struct stackNode *) malloc(sizeof(struct stackNode));
	new_node->item = item;
	new_node->next = NULL;
	return new_node;
}

void push(struct stackNode ** stack_top , int item ) {
	/** Function to push an item to a stack.
	*/
	struct stackNode * insert_node = new_node(item);
	insert_node->next = *stack_top;
	*stack_top = insert_node;
	printf("%d is pushed to the linked list\n",item);
}

bool is_empty(struct stackNode *stack_top) {
	/** Function to check if stack is empty
	    it would also act as a helper function for Pop operation
	    as we can't perform Pop operation if there is no element in the stack
	*/
	return !stack_top;
	/** If top of stack is NULL (no element) it would return true , else false */

}	

void pop(struct stackNode ** stack_top) {
	/** Function to remove the top of stack element */
	if( is_empty(*stack_top) ) {
		printf("is empty %d", INT_MIN);
		return ;
	}
	struct stackNode * temp_to_remove = *stack_top;
	printf("%p\n",(*stack_top)->next);
	*stack_top = (*stack_top)->next;
	int popped = temp_to_remove->item;
	free(temp_to_remove);

}

int top(struct stackNode * stack_top) {
	/** Function to return the top of stack */
	if ( is_empty(stack_top)) {
		return INT_MIN;
	}
	return stack_top->item;
}
	

	
int main( int argc, char** argv ) {
	struct stackNode * tos = NULL;
	
	push(&tos, 5);
	push(&tos, 10);
	push(&tos, 15);
	printf("tos = %d\n",top(tos));
	pop(&tos);
	printf("tos = %d\n",top(tos));
	return 0;	

}
