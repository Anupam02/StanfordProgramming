/* Recursive computation of a^n:
			{ 1        ,      n = 0
			{ a 	   ,      n = 1
	a^n      =      { (a^n/2)^2  ,    n is even
			{ a*(a^(n-1)/2)^2 n is odd

	complexity is log n with base 2 as it is dividing into two each time
*/

#include<stdio.h>
#include<stdlib.h>

double power(double a, int n) {
	/** function to calculate the powerer of number a with n 
	    complexity for this function is log n with base 2 
	*/
	if ( n == 0 ) return 1;
	if ( n == 1 ) return a;
	double val = power(a, n/2);
	return val*val*power(a,n%2);
}

int main(int argc, char** argv) {
	double num;
	int pow;

	if ( argc < 2 ) {
		printf("Please provide two command line arguments : number powerer\n");
		printf("Usage : %s number power\n", argv[0]);
		printf("This is %s() from %s, line %d\n", __FUNCTION__, __FILE__, __LINE__);
		exit(0);
	}
	
	num = atof(argv[1]);
	pow = atoi(argv[2]);
	double res = power(num,pow);
	printf("%lf\n",power(num,pow));
	printf("%lf\n",res);
	return 0;
}
