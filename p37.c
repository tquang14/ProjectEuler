#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool check_Primes(int n);
bool Truncatable_primes(int n);

int main(void) {
	clock_t begin = clock();
	int num_of_primes = 0, i = 10, sum = 0;
	while(true) {
		if (i % 2 != 0 || i % 5 != 0) { // by doing this reduce ~ 5s time process
			if (Truncatable_primes(i)) {
				num_of_primes++;
				printf("%d\n", i);
				sum += i;
			}
		}
		i++;
		if (num_of_primes == 11) {
			break;
		}
	}
	printf("%d\n", sum);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;// time_spent in second
	printf("%f\n", time_spent);
	return 0;
}

bool check_Primes(int n) {
	if(n < 2)
		return false;
	for (int i = 2; i <= n/2; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool Truncatable_primes(int n) {
	int temp = n;

	while(temp > 0) {
		if ( !check_Primes(temp) )
			return false;
		temp /= 10;
	}
	int i = 10;
	while(n > temp) {
		temp = n % i;
		i *= 10;
		if ( !check_Primes(temp) )
			return false;
	}
	return true;	
}