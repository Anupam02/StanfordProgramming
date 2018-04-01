#include <stdio.h>

unsigned long long int min(unsigned long long int a, unsigned long long int b) {
	return (a<b)?a:b;
	/** if ( a < b) 
	{	printf("inside if %lld",a);
		return a;
	}
	printf("outside if %lld\n",b);
	return b;
	*/
}

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
	while(b) {
		unsigned long long int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, char ** argv) {
	unsigned long long int a,b,_gcd,count,i;
	count = _gcd = 0;
	// scanf("%lld,%lld",&a,&b); - check for this
	scanf("%lld%lld",&a,&b);
	//printf("a = %lld, b = %lld\n",a,b);
//	min_val = min(a,b);
//	printf("%lld\n",gcd(a,b));
	//printf("min value = %lld\n",min_val);
/**	for( i=1; i <= min_val ; i++) {
		if (a%i == 0 && b%i == 0) {
			count++;
		}
	}
	*/
	_gcd = gcd(a,b);	
	for ( i = 1; i*i < _gcd ; i++) {
		if( _gcd%i == 0) {
			count += 2;
		}
	}
	if(i*i == _gcd)
		count++;

/**	for(i = 1; i <= _gcd; i++) {
		if(_gcd%i == 0) {
			count++;
		}
	}
	*/
	printf("%lld\n",count);

	return 0;
}
