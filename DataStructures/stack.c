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
	    here one thing to notice is that every time we are dynamically creating a new stackNode from new_node.
	    we are pointing the next pointer of the newly created node to top of stack pointer aka *stack_top
	    insert_node->next = *stack_top;
	    hence after the above operation whatever top of stack (top) we passed in push(&tos) is becoming the next
	    pointer for newly created stackNode ( insert_node)
	    
	    and top of stack pointer (*stack_top) is made points to the newly created node
	    *stack_top = insert_node;
	    hence every node we insert or push becomes the top of stack and others becomes its subsequent or next
	    nodes.
	    as stack is LIFO last in first out , the element or stackNode we push automatically can be accessed through
	    tos (top of stack pointer) , and it would be helpful for deletion as well.
	*/
	struct stackNode * insert_node = new_node(item);
	insert_node->next = *stack_top;
	// printf("insert node = %p, *stack_top = %p  \n",insert_node,*stack_top);
	*stack_top = insert_node;
	// printf("stack top item = %d , stack top pointer = %p\n",(*stack_top)->item,(*stack_top)->next);
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
	/** Function to remove the top of stack element 
	    here we create a temporary stackNode which stores the top of stack element which has to be deleted.
	    and we can use the temporary stackNode to release the allocated memory for stackNode.
	    struct stackNode * temp_to_remove = *stack_top;
	    here we copy *stack_top to *temp_to_remove  hence address has been copied.
	    now its time to make tos(top of stack points to the next node
	    *stack_top = (*stack_top)->next;
	    now top is stack points to the next node and top of stack (*stack_top here) contains the next Node address.
	    we can deallocate the memory allocated for previously top stackNode by free(temp_to_remove) from heap memory aready.
            Now tos (top of stack is not pointing to previousy top stackNode anymore and we have technically deleted or popped it. 
	*/
	if( is_empty(*stack_top) ) {
		printf("stack is empty %d\n", INT_MIN);
		printf("stack is empty\n");
		return ;
	}
	struct stackNode * temp_to_remove = *stack_top;
	// printf("%p\n",(*stack_top)->next);
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
	pop(&tos);
	printf("tos = %d\n",top(tos));
	pop(&tos);
	pop(&tos);
	return 0;	

}
