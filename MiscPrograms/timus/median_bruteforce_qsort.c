#include <stdio.h>
#include <stdlib.h>

int A[2500001];

int cmpfunc ( const void *a , const void *b) {
	return ( *(unsigned int *)a - *(unsigned int*)b);
}

int main(int argc, char **argv) {
	int n,i;
	double median;
	scanf("%d\n",&n);
	for( i = 0; i < n; i++)
		scanf("%d",&A[i]);
	qsort(A,n,sizeof(int), cmpfunc);
	median = ( n%2 == 0) ? ( A[n/2 - 1]*1.0 + A[n/2]*1.0 )/2.0 : A[n/2]/1.0 ;
	printf("%0.1lf\n",median);
	return 0;
}
	
