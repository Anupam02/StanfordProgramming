#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
	unsigned int capacity, size;
	int *heaps;
};

struct MaxHeap * create_maxheap(unsigned int capacity) {
	struct MaxHeap * max_heap = (struct MaxHeap *)malloc(2*sizeof(unsigned int)
			+ capacity*sizeof(int));
	max_heap->capacity = capacity;
	max_heap->size = 0;
	max_heap->heaps = (int *)malloc(sizeof(int)*max_heap->capacity);
}

void insert_node(struct MaxHeap ** max_heap, int v) {
	(*max_heap)->heaps[++(*max_heap)->size] = v;
//	printf("inserting %d at index %d\n",(*max_heap)->heaps[(*max_heap)->size] , (*max_heap)->size);
	unsigned int k ;
	for(k = (*max_heap)->size; k > 1;  k = k/2) {
//		printf("for k = %d, k/2 = %d\n", k , k/2);
	
		if((*max_heap)->heaps[k] > (*max_heap)->heaps[k/2]) {
			int temp = (*max_heap)->heaps[k];
			(*max_heap)->heaps[k] = (*max_heap)->heaps[k/2];
			(*max_heap)->heaps[k/2] = temp;
		}
		else
			break;
	}
}
//	(*max_heap)->size ++;


void traverse(struct MaxHeap * max_heap) {
	unsigned int i  ;
	for ( i = 1; i <= max_heap->size; i++) {
		printf("%d -> ",max_heap->heaps[i]);
	}
	printf("\n");
}
//void monk_and_mul(struct MaxHeap * mh) {
//

//int search(struct MaxHeap * mh, int key) {
//	unsigned int i;
//	int prod = 1;
//	for ( i = mh->size; i > 1 ; i = i/2) {
//		if ( mh->heaps[i] == key) {
//			prod = mh-heaps[
//			
//	}
//	return -1;
//}
void show_top_three(struct MaxHeap * mh,int k) {

	

int main(int argc , char ** argv) {
	int n,i;
	scanf("%d",&n);
	int A[n+1];
	for( i = 1; i <= n; i++)
		scanf("%d",&A[i]);
	struct MaxHeap * mh = create_maxheap(10);
	
	for ( i = 1; i <= n; i++) {
		insert_node(&mh, A[i]);
		if ( i == 1 || i == 2) {
			printf("-1\n");
		} else {
			int k = i;
			while(k != 1)
				k = k/2;
			show_top_three(mh, k);
		}
	}

//		traverse(mh);
//	}
//	if ( n < 3) {
//		printf("-1/n-1/n");
//	} else {
//		printf("-1/n-1/n");
//		for( i = 3; i <= n; i++) {
//			int pos = search(A[i]);
//			int ans = A[
//	traverse(mh);
	return 0;
}	
