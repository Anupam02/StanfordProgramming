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

void insert_node(struct MinHeap ** min_heap, int v) {
	(*min_heap)->heaps[++(*min_heap)->size] = v;
// 	printf("inserting = %d at index = %d\n",(*min_heap)->heaps[(*min_heap)->size] , (*min_heap)->size);
	unsigned int k ;
	for(k = (*min_heap)->size; k > 1;  k = k/2) {
// 		printf("for k = %d, k/2 = %d\n", k , k/2);
// 		printf("value at arr[k] = %d , and arr[k/2] = %d\n",(*min_heap)->heaps[k], (*min_heap)->heaps[k/2]);	
		if((*min_heap)->heaps[k] > (*min_heap)->heaps[k/2]) {
			int temp = (*min_heap)->heaps[k];
			(*min_heap)->heaps[k] = (*min_heap)->heaps[k/2];
			(*min_heap)->heaps[k/2] = temp;
		}
		else
			break;
	}
// 	for (unsigned int i = 1 ; i <= (*min_heap)->size ; i++) 
// 		printf("%d => ",(*min_heap)->heaps[i]);
// 	printf("\n");

}
//	(*min_heap)->size ++;

//void swap(int &a , int &b) {
//	int temp  = a;
//	a = b;
//	b = temp;
//}

void heapify( int A[] ,int size, int i) {
	int l = 2*i;
	int r = 2*i+1;
	int greatest = i;
	
// 	printf(" size of passed array = %u\n",sizeof(A));
	if ( l < size && A[l] > A[i]) {
	   greatest = l;
	}
	if ( r < size && A[r] > A[greatest] ) {
		greatest = r;
	}
	if ( i != greatest ) {
		int temp = A[i];
		A[i] = A[greatest];
		A[greatest] = temp;
		heapify(A, size, greatest);
	}
		//heapify(A , 	
}
	 
void remove_top(struct MinHeap ** min_heap) {
	unsigned int top = (*min_heap)->heaps[1];
	(*min_heap)->heaps[1] = (*min_heap)->heaps[(*min_heap)->size];
	heapify( (*min_heap)->heaps ,(*min_heap)->size, 1);
	--(*min_heap)->size;

}
int top( struct MinHeap * min_heap) {
	return min_heap->heaps[1];
}

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
		insert_node(&mh, A[i]);
// 		traverse(mh);
	}
	traverse(mh);
	for( i = 1; i <= n; i++) {
// 		remove_top(&mh);
		printf("top element is = %d\n", top(mh));
		remove_top(&mh);
		traverse(mh);
	}
// 	remove_top(&mh);
// 	traverse(mh);
	return 0;
}	
