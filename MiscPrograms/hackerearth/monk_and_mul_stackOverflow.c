#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int *arr, int i, int n) {
	//int i = *pos;
	int left = 2*i;
	int right = 2*i + 1;
	//int largest = i;
	int largest;
	if( left <= n && arr[left] > arr[i])
	    largest = left;
	else
		largest = i;
	if ( right <= n && arr[ right ] > arr[ largest ])
		largest = right;
	if ( largest != i) {
		int temp = arr[i];
		arr [i] = arr[ largest];
		arr[ largest ] = temp;
		maxHeapify( arr, largest,n);
	}
}

void BuildMaxHeap(int * arr, int n) {
	int i;
	for( i = n/2; i >= 1; i--)
		maxHeapify(arr, i,n);
}


int main( int argc, char ** argv) {
	int n,i;
	scanf("%d",&n);
	int A[n+1];
	for ( i = 1; i <= n ;i++) {
		scanf("%d",&A[i]);
	}

	for ( i = 1; i <= n; i++) {
		if ( i == 1 || i == 2) {
			printf("-1\n");
			BuildMaxHeap(A,i);
			for(int j = 1; j <= i; j++)
				printf("%d -> ",A[j]);
			printf("\n");

		} else {
			BuildMaxHeap(A, i);
			for( int j = 1; j <= i; j++)
				printf("%d ->  ",A[j]);
			printf("\n");
			printf("%d\n",A[1]*A[2]*A[3]);
		}
	}
	return 0;
}

		
