/** Program to implement priority queue by simple array implementation
 *  Each element in a PQ has a priority value.
 *  Three basic operations:
 *    > Insert (x, p): inserts x into the PQ , whose priority is p
 *    > RemoveTop() : removes the element with the highest priority
 *    > Top(): returns the element with the highest priority
 */
/** this program is incomplete */
#include <stdio.h>
#include <stdlib.h>

struct Item {
	int item;
	int priority;
};

struct PriorityQueue {
	unsigned int capacity, size;
	struct Item * items;
};

struct PriorityQueue* create_priority_queue( unsigned int capacity) {
	struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
	pq->capacity = capacity;
	pq->size = 0;
	pq->items = (struct Item *)malloc(sizeof(struct Item ) * capacity);
	return pq;
}

void insert(struct PriorityQueue ** pq, int x , int p) {
	(*pq)->items[(*pq)->size].item = x;
	(*pq)->items[(*pq)->size].priority = p;
	(*pq)->size++;
}

void display(struct PriorityQueue *pq) {
	unsigned int i = 0;
	for ( i = 0; i < pq->size ; i++) {
		printf("%d %d\n",pq->items[i].item , pq->items[i].priority);
	}
}
int main(int argc , char **argv) {
	struct PriorityQueue *pq = create_priority_queue(10);
	insert(&pq, 6, 1);
	insert(&pq, 7, 2);
	display(pq);
	return 0;
}
	
