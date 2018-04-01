#include <stdio.h>

int A[100001];

int main(int argc, char **argv) {
	int n,i,sum;
	scanf("%d",&n);
	sum = 0;
	for( i = 0; i < n; i++)
		scanf("%d",&A[i]);
	for( i = 0; i < n; i++)
		sum += A[i];
	printf("%d\n",sum/n + 1);
	return 0;
}	
