/** Program to implement priority queue by heap-> by array implementation */
#include <stdio.h>
#include <stdlib.h>

//	unsigned int size, capacity;
//	int *heap;
//
//
//int * create_heap(unsigned int capacity) {
//	struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(int)*capacity);
//
struct MinHeap {
	unsigned int capacity, size;
	int *heaps;
};

struct MinHeap * create_minheap(unsigned int capacity) {
	struct MinHeap * min_heap = (struct MinHeap *)malloc(2*sizeof(unsigned int)
			+ capacity*sizeof(int));
	min_heap->capacity = capacity;
	min_heap->size = 0;
	min_heap->heaps = (int *)malloc(sizeof(int)*min_heap->capacity);
}
void heap_push(struct heap *h, int value)
{
	int index, parent;
 
	// Resize the heap if it is too small to hold all the data
	if (h->count == h->size)
	{
		h->size += 1;
		h->heaparr = realloc(h->heaparr, sizeof(int) * h->size);
		if (!h->heaparr) exit(-1); // Exit if the memory allocation fails
	}
 	
 	index = h->count++; // First insert at last of array

 	// Find out where to put the element and put it
	for(;index; index = parent)
	{
		parent = (index - 1) / 2;
		if (h->heaparr[parent] >= value) break;
		h->heaparr[index] = h->heaparr[parent];
	}
	h->heaparr[index] = value;
}
void insert_node(struct MinHeap ** min_heap, int v) {
	(*min_heap)->heaps[++(*min_heap)->size] = v;
	printf("inserting %d at index %d\n",(*min_heap)->heaps[(*min_heap)->size] , (*min_heap)->size);
	unsigned int k ;
	for(k = (*min_heap)->size; k > 1;  k = k/2) {
		printf("for k = %d, k/2 = %d\n", k , k/2);
	
		if((*min_heap)->heaps[k] < (*min_heap)->heaps[k/2]) {
			int temp = (*min_heap)->heaps[k];
			(*min_heap)->heaps[k] = (*min_heap)->heaps[k/2];
			(*min_heap)->heaps[k/2] = temp;
		}
		break;
	}
}
//	(*min_heap)->size ++;


void traverse(struct MinHeap * min_heap) {
	unsigned int i  ;
	for ( i = 1; i <= min_heap->size; i++) {
		printf("%d -> ",min_heap->heaps[i]);
	}
	printf("\n");
}
int main(int argc , char ** argv) {
	int n,i;
	scanf("%d",&n);
	int A[n+1];
	for( i = 1; i <= n; i++)
		scanf("%d",&A[i]);
	struct MinHeap * mh = create_minheap(10);
	
	for ( i = 1; i <= n; i++) {
		//insert_node(&mh, A[i]);
		heap_push(&mh,A[i]);
		traverse(mh);
	}
	traverse(mh);
	return 0;
}
