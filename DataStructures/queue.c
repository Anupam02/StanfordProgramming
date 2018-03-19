#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QNode {
	int key;
	struct QNode *next;
};

struct Queue {
	struct QNode *front , *rear;
};

struct QNode* new_node(int k) {
	struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue* create_queue() {
	struct Queue * q  = (struct Queue *)malloc(sizeof(struct Queue));
	q-> front = NULL;
	q-> rear = NULL;
	return q;
}


void enqueue(struct Queue * queue , int key) {
	struct QNode *qnode = new_node(key);

	if (queue->rear == NULL) {
		queue->front = qnode;
		queue->rear = qnode;
		return ;
	} 
	queue->rear->next = qnode;
	queue->rear = qnode;
}

void dequeue(struct Queue * queue) {
	if ( queue->front == NULL) {
		printf("Queue is empty\n");
		return ;
	}

	struct QNode *temp_to_remove = queue->front;
	queue->front = queue->front->next;

	if ( queue->front == NULL) {
		queue->rear = NULL;
	}
	free(temp_to_remove);
}

void traverse(struct Queue * queue) {
	if ( queue->rear == NULL) {
		printf("Sorry , there is no element in the queue\n");
	}
	struct QNode *pointer = queue->front;
	while (pointer != queue->rear) {
		printf("key = %d\n",pointer->key);
		pointer = pointer->next;
	}
	printf("key = %d",queue->rear->key);
	printf("\n");
}

int main() {
	struct Queue *q = create_queue();
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	traverse(q);
	dequeue(q);
	traverse(q);
	dequeue(q);
	traverse(q);
	return 0;
}

	

