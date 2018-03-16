/** program to calculate gcd of two numbers a and b 
    Some facts :
	> gcd(a, b) = gcd(a, b-a) or gcd(b, a-b)
	> gcd(a, 0) = a
	> gcd(a, b) is the smallest positive number in { a*x + b*y | x,y belongs to Z }
	
	> here we can conclude that gcd(a,b) = gcd(a, b-a) or gcd(b, a-b) is 
	  equivalent to gcd(a,b) = gcd(a, b-k*a) or gcd(b , a-k*b) where k is 
	  any Integer. because we can do it multiple times , and for the first
	  time gcd(a,b-k*a) , k is 1.
	Example :
		gcd(65,15) = gcd(15,65-15)=>gcd(15,50)
			     gcd(15,50-15)=>gcd(15,35)
			     gcd(15,35-15)=>gcd(15,20)
			     gcd(15,20-15)=>gcd(15,5)
			     **== all above 4 steps are equivalent to 	
				   gcd(15,65 - 4*15) => gcd(15,5)
		gcd(15,5) = gcd(5,15 - 3*5) => gcd(5,0)
			   ** == by gcd(a,0) = a
			  = 5
*/
#include<stdio.h>
#include<stdlib.h>

int gcd(int a , int b) {
	/** running time - O(log(a+b)) **/
	while (b) {
		printf("a = %d , b = %d\n",a,b);
		int r = a % b; 
		a = b;
		b = r;
	}
	return a;
}
int main(int argc, char** argv ) {
	int a,b;

	if ( argc < 2) {
		printf("Please provide two command line arguments : a b\n");
		exit(0);
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n",gcd(a,b));
	return 0;
}	
		
