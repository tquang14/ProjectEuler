#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkPrimes(int n) {
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return false;	

	return true;
}

bool check_circular_primes(int n, int length_of_n) {
	// n : number you want to rotate
	int result;
	if (!checkPrimes(n))
		return false;
	// do the rotate and check prime
	for (int j = 1; j < length_of_n ; j++) {
		int temp = n / pow(10.0, length_of_n - 1);
		float a = pow(10.0, length_of_n - 1);
		int b = a;
		n = n % b;
		n = n *10 + temp;
		if (!checkPrimes(n))
			return false;
	}
	return true;
}

int main(void) {

	int nDigits; // find the length of n
	int count = 13 ; // there is 13 Circular primes < 100
	for (int i = 100; i < 1000000; ++i) {
		nDigits = floor(log10(abs(i))) +1 ;
		if (check_circular_primes(i, nDigits))
			count++;
	}
	printf("%d\n",count);
	return 0;
}