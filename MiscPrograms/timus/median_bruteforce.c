#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long int A[250001];

void sort(long long int * arr , int n) {
	long long int i ,j,min,pos,temp;
	for(i = 0; i < n ; i++) {
		min = A[i];pos = i;
		for ( j = i+1; j < n; j++) {
			if( A[j] < min) {
				min = A[j];
				pos = j;
			}
		}
		temp = A[i];
		A[i] = min;
		A[pos] = temp;	
	}
}
int main(int argc, char **argv) {
	int n,i;
	double median;
	scanf("%d",&n);
	median = 0;
	//printf("%u\n",INT_MAX);
	//printf("%lld\n",(long long int)2.0*INT_MAX);
	//printf("%f\n",2.0*INT_MAX);
	for( i = 0; i < n; i++)
		scanf("%lld",&A[i]);
	sort(A,n);
	//for( i = 0; i < n; i++)
	//	printf("%lld ",A[i]);
	//printf("\n");
	median = (n % 2 == 0)?((long long int)A[n/2 - 1]*1.0 + (long long int)A[n/2]*1.0)/2.0 : A[n/2]*1.0;
	//printf("%f    %f\n",A[n/2 -1]*1.0, A[n/2]*1.0);
	//printf("%lf\n",(A[n/2-1]+A[n/2])/2.0);
	printf("%0.1lf\n",median);
	return 0;
}
		
