/** Program for queue implementation of queue using linked list
 * First in , first out (FIFO)
 * Supports three constant-time operations
 * 	- Enqueue(x) : insert x into the queue
 * 	- Dequeue()  : removes the oldest item
 * 	- Front()    : returns the oldest item
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limit.h>

struct Queue {
	int key;
	struct Queue *next;
	struct Queue *front , *rear;
};

struct Queue* create_queue() {
	struct Queue *queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

void enqueue(struct Queue *q , int k) {
/** Notice here that we can't make a good program for queue by single Queue 
 * struct as we need a Node to be created dynamically everytime we call this
 * hence , we don't need this.
 */
		
